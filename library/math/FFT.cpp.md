---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: math/FFT.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/FFT.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-03 23:44:21+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	FFT, NTT
	FFTした後の配列に入っている値は、本来入るべき値との相対誤差が2^-53 * log2(配列長)ぐらいらしい
	配列長N,値Xとすると, NXX >= 2^53 くらいになると絶対誤差が1くらいになりまずい
	なので, X=10^9 -> 死
	そこで, 値を3桁の1024進法との数みなして分割して筆算をする.筆算の各かけざんがFFTで,あとは普通に筆算のように足し算する.
	multiply_fft3 -> 3分割 1024進法		N*1024*1024 >= 2^53   <=>   N>=2^30 なので絶対大丈夫
	multiply_fft2 -> 2分割 2^15進法		N*(2^15)^2 >= 2^53   <=>   N>=2^23 なのでまあ大丈夫?

	B bit ごと K個に分割する の B,K が定数になっている、普通 B = 15, K = 2
*/


int bsr(int x) { return 31 - __builtin_clz(x); }
using D = double;
const D pi = acos(-1);
using Pc = complex<D>;

void fft(bool type, vector<Pc> &c){	//multiply : false -> mult -> true
	static vector<Pc> buf[30];
	int N = c.size();
	int s = bsr(N);
	assert(1<<s == N);
	if(buf[s].empty()){
		buf[s]=vector<Pc>(N);
		rep(i,N) buf[s][i] = polar<D>(1,i*2*pi/N);
	}
	vector<Pc> a(N),b(N);
	copy(begin(c),end(c),begin(a));
	rep1(i,s){
		int W = 1<<(s-i);
		for(int y=0;y<N/2;y+=W){
			Pc now = buf[s][y];
			if(type) now = conj(now);
			rep(x,W){
				auto l =       a[y<<1 | x];
				auto r = now * a[y<<1 | x | W];
				b[y | x]        = l+r;
				b[y | x | N>>1] = l-r;
			}
		}
		swap(a,b);
	}
	copy(begin(a),end(a),begin(c));
}


/*
	long long/mint 用
	最後roundしてキャストする
*/

template<class Mint>
vector<Mint> multiply_fft(const vector<Mint>& x,const vector<Mint>& y){
	if(x.empty() || y.empty()) return {};
	const int B = 15;
	const int K = 2;
	int S = x.size()+y.size()-1;
	int N = 1; while(N<S) N*=2;
	vector<Pc> a[K],b[K];
	rep(t,K){
		a[t] = vector<Pc>(N);
		b[t] = vector<Pc>(N);
		rep(i,x.size()) a[t][i] = Pc( (x[i].v >> (t*B)) & ((1<<B)-1) , 0 );
		rep(i,y.size()) b[t][i] = Pc( (y[i].v >> (t*B)) & ((1<<B)-1) , 0 );
		fft(false,a[t]);
		fft(false,b[t]);
	}
	vector<Mint> z(S);
	vector<Pc> c(N);
	Mint base = 1;
	rep(t,K+K-1){
		fill_n(begin(c),N,Pc(0,0));
		rep(xt,K){
			int yt = t-xt;
			if(0<=yt && yt<K){
				rep(i,N) c[i] += a[xt][i] * b[yt][i];
			}
		}
		fft(true,c);
		rep(i,S){
			c[i] *= 1.0/N;
			z[i] += Mint(ll(round(c[i].real()))) * base;
		}
		base *= 1<<B;
	}
	return z;
}

/*
	double 用
	かけざん
*/
template<class D>
vector<D> multiply_fft(const vector<D>& x,const vector<D>& y){
	if(x.empty() || y.empty()) return {};
	int S = x.size()+y.size()-1;
	int N = 1; while(N<S) N*=2;
	vector<Pc> a(N),b(N);
	rep(i,x.size()) a[i] = Pc( x[i] , 0 );
	rep(i,y.size()) b[i] = Pc( y[i] , 0 );
	fft(false,a);
	fft(false,b);

	vector<D> z(S);
	vector<Pc> c(N);
	rep(i,N) c[i] = a[i]*b[i];
	fft(true,c);
	rep(i,S){
		c[i] *= 1.0/N;
		z[i] = c[i].real();
	}
	return z;
}

/*
	NTT
	K=2 のFFTよりは圧倒的に速いのでまともmodなら絶対こっち
	原子根 G=3 を変えること！！(998244353 なら 3 でいい)
*/
int bsr(int x) { return 31 - __builtin_clz(x); }
void ntt(bool type, V<mint>& c) {
	const mint G = 3;	//primitive root

	int N = int(c.size());
	int s = bsr(N);
	assert(1 << s == N);

	V<mint> a = c, b(N);
	rep1(i,s){
		int W = 1 << (s - i);
		mint base = G.pow((mint::mod - 1)>>i);
		if(type) base = base.inv();
		mint now = 1;
		for(int y = 0; y < N / 2; y += W) {
			for (int x = 0; x < W; x++) {
				auto l = a[y << 1 | x];
				auto r = now * a[y << 1 | x | W];
				b[y | x] = l + r;
				b[y | x | N >> 1] = l - r;
			}
			now *= base;
		}
		swap(a, b);
	}
	c = a;
}

V<mint> multiply_ntt(const V<mint>& a, const V<mint>& b) {
	int A = int(a.size()), B = int(b.size());
	if (!A || !B) return {};
	int lg = 0;
	while ((1 << lg) < A + B - 1) lg++;
	int N = 1 << lg;
	V<mint> ac(N), bc(N);
	for (int i = 0; i < A; i++) ac[i] = a[i];
	for (int i = 0; i < B; i++) bc[i] = b[i];
	ntt(false, ac);
	ntt(false, bc);
	for (int i = 0; i < N; i++) {
		ac[i] *= bc[i];
	}
	ntt(true, ac);
	V<mint> c(A + B - 1);
	mint iN = mint(N).inv();
	for (int i = 0; i < A + B - 1; i++) {
		c[i] = ac[i] * iN;
	}
	return c;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/FFT.cpp"
/*
	FFT, NTT
	FFTした後の配列に入っている値は、本来入るべき値との相対誤差が2^-53 * log2(配列長)ぐらいらしい
	配列長N,値Xとすると, NXX >= 2^53 くらいになると絶対誤差が1くらいになりまずい
	なので, X=10^9 -> 死
	そこで, 値を3桁の1024進法との数みなして分割して筆算をする.筆算の各かけざんがFFTで,あとは普通に筆算のように足し算する.
	multiply_fft3 -> 3分割 1024進法		N*1024*1024 >= 2^53   <=>   N>=2^30 なので絶対大丈夫
	multiply_fft2 -> 2分割 2^15進法		N*(2^15)^2 >= 2^53   <=>   N>=2^23 なのでまあ大丈夫?

	B bit ごと K個に分割する の B,K が定数になっている、普通 B = 15, K = 2
*/


int bsr(int x) { return 31 - __builtin_clz(x); }
using D = double;
const D pi = acos(-1);
using Pc = complex<D>;

void fft(bool type, vector<Pc> &c){	//multiply : false -> mult -> true
	static vector<Pc> buf[30];
	int N = c.size();
	int s = bsr(N);
	assert(1<<s == N);
	if(buf[s].empty()){
		buf[s]=vector<Pc>(N);
		rep(i,N) buf[s][i] = polar<D>(1,i*2*pi/N);
	}
	vector<Pc> a(N),b(N);
	copy(begin(c),end(c),begin(a));
	rep1(i,s){
		int W = 1<<(s-i);
		for(int y=0;y<N/2;y+=W){
			Pc now = buf[s][y];
			if(type) now = conj(now);
			rep(x,W){
				auto l =       a[y<<1 | x];
				auto r = now * a[y<<1 | x | W];
				b[y | x]        = l+r;
				b[y | x | N>>1] = l-r;
			}
		}
		swap(a,b);
	}
	copy(begin(a),end(a),begin(c));
}


/*
	long long/mint 用
	最後roundしてキャストする
*/

template<class Mint>
vector<Mint> multiply_fft(const vector<Mint>& x,const vector<Mint>& y){
	if(x.empty() || y.empty()) return {};
	const int B = 15;
	const int K = 2;
	int S = x.size()+y.size()-1;
	int N = 1; while(N<S) N*=2;
	vector<Pc> a[K],b[K];
	rep(t,K){
		a[t] = vector<Pc>(N);
		b[t] = vector<Pc>(N);
		rep(i,x.size()) a[t][i] = Pc( (x[i].v >> (t*B)) & ((1<<B)-1) , 0 );
		rep(i,y.size()) b[t][i] = Pc( (y[i].v >> (t*B)) & ((1<<B)-1) , 0 );
		fft(false,a[t]);
		fft(false,b[t]);
	}
	vector<Mint> z(S);
	vector<Pc> c(N);
	Mint base = 1;
	rep(t,K+K-1){
		fill_n(begin(c),N,Pc(0,0));
		rep(xt,K){
			int yt = t-xt;
			if(0<=yt && yt<K){
				rep(i,N) c[i] += a[xt][i] * b[yt][i];
			}
		}
		fft(true,c);
		rep(i,S){
			c[i] *= 1.0/N;
			z[i] += Mint(ll(round(c[i].real()))) * base;
		}
		base *= 1<<B;
	}
	return z;
}

/*
	double 用
	かけざん
*/
template<class D>
vector<D> multiply_fft(const vector<D>& x,const vector<D>& y){
	if(x.empty() || y.empty()) return {};
	int S = x.size()+y.size()-1;
	int N = 1; while(N<S) N*=2;
	vector<Pc> a(N),b(N);
	rep(i,x.size()) a[i] = Pc( x[i] , 0 );
	rep(i,y.size()) b[i] = Pc( y[i] , 0 );
	fft(false,a);
	fft(false,b);

	vector<D> z(S);
	vector<Pc> c(N);
	rep(i,N) c[i] = a[i]*b[i];
	fft(true,c);
	rep(i,S){
		c[i] *= 1.0/N;
		z[i] = c[i].real();
	}
	return z;
}

/*
	NTT
	K=2 のFFTよりは圧倒的に速いのでまともmodなら絶対こっち
	原子根 G=3 を変えること！！(998244353 なら 3 でいい)
*/
int bsr(int x) { return 31 - __builtin_clz(x); }
void ntt(bool type, V<mint>& c) {
	const mint G = 3;	//primitive root

	int N = int(c.size());
	int s = bsr(N);
	assert(1 << s == N);

	V<mint> a = c, b(N);
	rep1(i,s){
		int W = 1 << (s - i);
		mint base = G.pow((mint::mod - 1)>>i);
		if(type) base = base.inv();
		mint now = 1;
		for(int y = 0; y < N / 2; y += W) {
			for (int x = 0; x < W; x++) {
				auto l = a[y << 1 | x];
				auto r = now * a[y << 1 | x | W];
				b[y | x] = l + r;
				b[y | x | N >> 1] = l - r;
			}
			now *= base;
		}
		swap(a, b);
	}
	c = a;
}

V<mint> multiply_ntt(const V<mint>& a, const V<mint>& b) {
	int A = int(a.size()), B = int(b.size());
	if (!A || !B) return {};
	int lg = 0;
	while ((1 << lg) < A + B - 1) lg++;
	int N = 1 << lg;
	V<mint> ac(N), bc(N);
	for (int i = 0; i < A; i++) ac[i] = a[i];
	for (int i = 0; i < B; i++) bc[i] = b[i];
	ntt(false, ac);
	ntt(false, bc);
	for (int i = 0; i < N; i++) {
		ac[i] *= bc[i];
	}
	ntt(true, ac);
	V<mint> c(A + B - 1);
	mint iN = mint(N).inv();
	for (int i = 0; i < A + B - 1; i++) {
		c[i] = ac[i] * iN;
	}
	return c;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

