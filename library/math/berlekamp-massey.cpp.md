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


# :warning: math/berlekamp-massey.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/berlekamp-massey.cpp">View this file on GitHub</a>
    - Last commit date: 2018-09-18 03:14:42+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
Berlekamp-Massey
体K上のn+1項間線形漸化式から生成される数列の,はじめ2n項を渡すと,その線形漸化式(というか最小多項式)を求めてくれる
例えばfibなら4項必要.
input を u , N項 として output を c とすると
for all j < N-K,
c_0 * u_j + c_1 * u_{j+1} + .. + c_K * u_{j+K} = 0
となる.
O(N^2)

fft,poly,mint とかがいる
main関数より下にまるごと貼ってあるのでmintで使うときはこっからコピーする
!! mod の値を変える !!

N項目を求めたいときは、x^N を この多項式で割る
まあtypicalDP/T.cpp とかにあるんですけど, 一般的な処理は
	vector<mint> vals = {0,1,1,2};
	auto mod = berlekamp_massey(vals);

	Poly<mint> a = vector<mint>{1};
	Poly<mint> x = vector<mint>{0,1};

	long long N;
	cin>>N;
	while(N){
		if(N%2) (a*=x)%=mod;
		x*=x;
		x%=mod;
		N/=2;
	}
	mint ans=0;
	int K = mod.size();
	rep(i,K) ans+=a.at(i)*vals[i];
	cout<<ans<<endl;

	です

*/
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}


template<class D>
Poly<D> berlekamp_massey(const vector<D> &u){
	int N = u.size();
	vector<D> b = {D(-1)}, c = {D(-1)};
	D y = D(1);
	rep1(n,N){
		int L = c.size(), M = b.size();
		D x = 0;
		rep(i,L) x += c[i]*u[n-L+i];
		b.pb(0);
		M++;
		if(!x) continue;
		D coef = x/y;
		if(L<M){
			auto tmp = c;
			c.insert(begin(c),M-L,D(0));
			rep(i,M) c[M-1-i] -= coef*b[M-1-i];
			b=tmp;
			y=x;
		}else{
			rep(i,M) c[L-1-i] -= coef*b[M-1-i];
		}
	}
	return Poly<D>(c);
}

int main(){
	vector<int> fib({0,1,1,2,3,5,8});
	//0,1,1,2 までは必要
	vector<int> hoge({0,1,2,-1,5,-2,5,3});	//		2 a_i + a_i+1 - a_i+2 - a_i+3 = 0
	//-2までは必要
	auto c = berlekamp_massey(hoge);	// return	2 x^0 +   x^1 -   x^2 -   x^3
	show(c);
}


template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
template<unsigned int mod_>
struct ModInt{
	using uint = unsigned int;
	using ll = long long;
	using ull = unsigned long long;

	constexpr static uint mod = mod_;

	uint v;
	ModInt():v(0){}
	ModInt(ll v):v(normS(v%mod+mod)){}
	explicit operator bool() const {return v!=0;}
	static uint normS(const uint &x){return (x<mod)?x:x-mod;}		// [0 , 2*mod-1] -> [0 , mod-1]
	static ModInt make(const uint &x){ModInt m; m.v=x; return m;}
	ModInt operator+(const ModInt& b) const { return make(normS(v+b.v));}
	ModInt operator-(const ModInt& b) const { return make(normS(v+mod-b.v));}
	ModInt operator-() const { return make(normS(mod-v)); }
	ModInt operator*(const ModInt& b) const { return make((ull)v*b.v%mod);}
	ModInt operator/(const ModInt& b) const { return *this*b.inv();}
	ModInt& operator+=(const ModInt& b){ return *this=*this+b;}
	ModInt& operator-=(const ModInt& b){ return *this=*this-b;}
	ModInt& operator*=(const ModInt& b){ return *this=*this*b;}
	ModInt& operator/=(const ModInt& b){ return *this=*this/b;}
	ll extgcd(ll a,ll b,ll &x,ll &y) const{
		ll u[]={a,1,0},v[]={b,0,1};
		while(*v){
			ll t=*u/ *v;
			rep(i,3) swap(u[i]-=t*v[i],v[i]);
		}
		if(u[0]<0) rep(i,3) u[i]=-u[i];
		x=u[1],y=u[2];
		return u[0];
	}
	ModInt inv() const{
		ll x,y;
		extgcd(v,mod,x,y);
		return make(normS(x+mod));
	}
	bool operator==(const ModInt& b) const { return v==b.v;}
	bool operator!=(const ModInt& b) const { return v!=b.v;}
	friend istream& operator>>(istream &o,ModInt& x){
		ll tmp;
		o>>tmp;
		x=ModInt(tmp);
		return o;
	}
	friend ostream& operator<<(ostream &o,const ModInt& x){ return o<<x.v;}
};
using mint = ModInt<>;

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
template<class Mint>
vector<Mint> multiply_fft2(const vector<Mint>& x,const vector<Mint>& y){
	const int B = 15;
	int S = x.size()+y.size()-1;
	int N = 2<<bsr(S-1);
	vector<Pc> a[2],b[2];
	rep(t,2){
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
	rep(t,3){
		fill_n(begin(c),N,Pc(0,0));
		for(int xt = max(t-1,0); xt<=min(1,t); xt++){
			int yt = t-xt;
			rep(i,N) c[i] += a[xt][i]*b[yt][i];
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
template<class Mint>
vector<Mint> multiply_fft(const vector<Mint>& x,const vector<Mint>& y){
	return multiply_fft2(x,y);
}


template<class D>
struct Poly{
	vector<D> v;
	int size() const{ return v.size();}	//deg+1
	Poly(int N=0) : v(vector<D>(N)){}
	Poly(vector<D> v) : v(v){shrink();}

	Poly& shrink(){
		while(!v.empty()&&v.back()==D(0)) v.pop_back();	//double? iszeroをglobalに用意したほうがいいかな
		return *this;
	}
	D at(int i) const{
		return (i<size())?v[i]:D(0);
	}
	void set(int i,const D& x){		//v[i] := x
		if(i>=size() && !x) return;
		while(i>=size()) v.push_back(D(0));
		v[i]=x;
		shrink();
		return;
	}
	
	Poly operator+(const Poly &r) const{
		int N=max(size(),r.size());
		vector<D> ret(N);
		rep(i,N) ret[i]=at(i)+r.at(i);
		return Poly(ret);
	}
	Poly operator-(const Poly &r) const{
		int N=max(size(),r.size());
		vector<D> ret(N);
		rep(i,N) ret[i]=at(i)-r.at(i);
		return Poly(ret);
	}
	Poly operator-() const{
		int N=size();
		vector<D> ret(N);
		rep(i,N) ret[i] = -at(i);
		return Poly(ret);
	}
	Poly operator*(const Poly &r) const{
		if(size()==0||r.size()==0) return Poly();
		return mul_fft(r);
	}
	Poly operator*(const D &r) const{
		int N=size();
		vector<D> ret(N);
		rep(i,N) ret[i]=v[i]*r;
		return Poly(ret);
	}
	Poly operator/(const Poly &y) const{
		return div_fast(y);
	}
	Poly operator%(const Poly &y) const{
		return rem_fast(y);
//		return rem_naive(y);
	}
	Poly operator<<(const int &n) const{	// *=x^n
		assert(n>=0);
		int N=size();
		vector<D> ret(N+n);
		rep(i,N) ret[i+n]=v[i];
		return Poly(ret);
	}
	Poly operator>>(const int &n) const{	// /=x^n
		assert(n>=0);
		int N=size();
		if(N<=n) return Poly();
		vector<D> ret(N-n);
		rep(i,N-n) ret[i]=v[i+n];
		return Poly(ret);
	}
	bool operator==(const Poly &y) const{
		return v==y.v;
	}
	bool operator!=(const Poly &y) const{
		return v!=y.v;
	}

	Poly& operator+=(const Poly &r) {return *this = *this+r;}
	Poly& operator-=(const Poly &r) {return *this = *this-r;}
	Poly& operator*=(const Poly &r) {return *this = *this*r;}
	Poly& operator*=(const D &r) {return *this = *this*r;}
	Poly& operator%=(const Poly &y) {return *this = *this%y;}
	Poly& operator<<=(const int &n) {return *this = *this<<n;}
	Poly& operator>>=(const int &n) {return *this = *this>>n;}


	Poly mul_naive(const Poly &r) const{
		int N=size(),M=r.size();
		vector<D> ret(N+M-1);
		rep(i,N) rep(j,M) ret[i+j]+=at(i)*r.at(j);
		return Poly(ret);
	}
	Poly mul_ntt(const Poly &r) const{
		return Poly(multiply_ntt(this->v,r.v));
	}
	Poly mul_fft(const Poly &r) const{
		vector<D> ret = multiply_fft(v,r.v);
		return Poly(ret);
	}

	Poly div_fast_with_inv(const Poly &inv, int B) const {
		return (*this * inv)>>(B-1);
	}
	Poly div_fast(const Poly &y) const{
		if(size()<y.size()) return Poly();
		int n = size();
		return div_fast_with_inv(y.inv(n),n);
	}
	Poly rem_naive(const Poly &y) const{
		Poly x = *this;
		while(y.size()<=x.size()){
			int N=x.size(),M=y.size();
			D coef = x.v[N-1]/y.v[M-1];
			x -= (y<<(N-M))*coef;
		}
		return x;
	}
	Poly rem_fast(const Poly &y) const{
		return *this - y * div_fast(y);
	}
	Poly strip(int n) const {	//ignore x^n , x^n+1,...
		vector<D> res = v;
		res.resize(min(n,size()));
		return Poly(res);
	}
	Poly rev(int n = -1) const {	//ignore x^n ~  ->  return x^(n-1) * f(1/x)
		vector<D> res = v;
		if(n!=-1) res.resize(n);
		reverse(all(res));
		return Poly(res);
	}
	Poly inv(int n) const{		// f * f.inv() = x^B + r(x) (B>=n)
		int N = size();
		assert(N>=1);		//f : non0
		assert(n>=N-1);		//f = .. + c_{N-1}x^{N-1}
		D coef = D(1)/at(N-1);
		Poly a = rev();
		Poly g(vector<D>(1,coef));
		for(int i=1; i+N-2<n; i*=2){		//need to strip!!
			g *= (Poly(vector<D>{2})-a*g).strip(2*i);
		}
		return g.rev(n+1-N);
	}

	friend ostream& operator<<(ostream &o,const Poly& x){
		if(x.size()==0) return o<<0;
		rep(i,x.size()) if(x.v[i]!=D(0)){
			o<<x.v[i]<<"x^"<<i;
			if(i!=x.size()-1) o<<" + ";
		}
		return o;
	}
};
template<class D>
Poly<D> berlekamp_massey(const vector<D> &u){
	int N = u.size();
	vector<D> b = {D(-1)}, c = {D(-1)};
	D y = D(1);
	rep1(n,N){
		int L = c.size(), M = b.size();
		D x = 0;
		rep(i,L) x += c[i]*u[n-L+i];
		b.pb(0);
		M++;
		if(!x) continue;
		D coef = x/y;
		if(L<M){
			auto tmp = c;
			c.insert(begin(c),M-L,D(0));
			rep(i,M) c[M-1-i] -= coef*b[M-1-i];
			b=tmp;
			y=x;
		}else{
			rep(i,M) c[L-1-i] -= coef*b[M-1-i];
		}
	}
	return Poly<D>(c);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/berlekamp-massey.cpp"
/*
Berlekamp-Massey
体K上のn+1項間線形漸化式から生成される数列の,はじめ2n項を渡すと,その線形漸化式(というか最小多項式)を求めてくれる
例えばfibなら4項必要.
input を u , N項 として output を c とすると
for all j < N-K,
c_0 * u_j + c_1 * u_{j+1} + .. + c_K * u_{j+K} = 0
となる.
O(N^2)

fft,poly,mint とかがいる
main関数より下にまるごと貼ってあるのでmintで使うときはこっからコピーする
!! mod の値を変える !!

N項目を求めたいときは、x^N を この多項式で割る
まあtypicalDP/T.cpp とかにあるんですけど, 一般的な処理は
	vector<mint> vals = {0,1,1,2};
	auto mod = berlekamp_massey(vals);

	Poly<mint> a = vector<mint>{1};
	Poly<mint> x = vector<mint>{0,1};

	long long N;
	cin>>N;
	while(N){
		if(N%2) (a*=x)%=mod;
		x*=x;
		x%=mod;
		N/=2;
	}
	mint ans=0;
	int K = mod.size();
	rep(i,K) ans+=a.at(i)*vals[i];
	cout<<ans<<endl;

	です

*/
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}


template<class D>
Poly<D> berlekamp_massey(const vector<D> &u){
	int N = u.size();
	vector<D> b = {D(-1)}, c = {D(-1)};
	D y = D(1);
	rep1(n,N){
		int L = c.size(), M = b.size();
		D x = 0;
		rep(i,L) x += c[i]*u[n-L+i];
		b.pb(0);
		M++;
		if(!x) continue;
		D coef = x/y;
		if(L<M){
			auto tmp = c;
			c.insert(begin(c),M-L,D(0));
			rep(i,M) c[M-1-i] -= coef*b[M-1-i];
			b=tmp;
			y=x;
		}else{
			rep(i,M) c[L-1-i] -= coef*b[M-1-i];
		}
	}
	return Poly<D>(c);
}

int main(){
	vector<int> fib({0,1,1,2,3,5,8});
	//0,1,1,2 までは必要
	vector<int> hoge({0,1,2,-1,5,-2,5,3});	//		2 a_i + a_i+1 - a_i+2 - a_i+3 = 0
	//-2までは必要
	auto c = berlekamp_massey(hoge);	// return	2 x^0 +   x^1 -   x^2 -   x^3
	show(c);
}


template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
template<unsigned int mod_>
struct ModInt{
	using uint = unsigned int;
	using ll = long long;
	using ull = unsigned long long;

	constexpr static uint mod = mod_;

	uint v;
	ModInt():v(0){}
	ModInt(ll v):v(normS(v%mod+mod)){}
	explicit operator bool() const {return v!=0;}
	static uint normS(const uint &x){return (x<mod)?x:x-mod;}		// [0 , 2*mod-1] -> [0 , mod-1]
	static ModInt make(const uint &x){ModInt m; m.v=x; return m;}
	ModInt operator+(const ModInt& b) const { return make(normS(v+b.v));}
	ModInt operator-(const ModInt& b) const { return make(normS(v+mod-b.v));}
	ModInt operator-() const { return make(normS(mod-v)); }
	ModInt operator*(const ModInt& b) const { return make((ull)v*b.v%mod);}
	ModInt operator/(const ModInt& b) const { return *this*b.inv();}
	ModInt& operator+=(const ModInt& b){ return *this=*this+b;}
	ModInt& operator-=(const ModInt& b){ return *this=*this-b;}
	ModInt& operator*=(const ModInt& b){ return *this=*this*b;}
	ModInt& operator/=(const ModInt& b){ return *this=*this/b;}
	ll extgcd(ll a,ll b,ll &x,ll &y) const{
		ll u[]={a,1,0},v[]={b,0,1};
		while(*v){
			ll t=*u/ *v;
			rep(i,3) swap(u[i]-=t*v[i],v[i]);
		}
		if(u[0]<0) rep(i,3) u[i]=-u[i];
		x=u[1],y=u[2];
		return u[0];
	}
	ModInt inv() const{
		ll x,y;
		extgcd(v,mod,x,y);
		return make(normS(x+mod));
	}
	bool operator==(const ModInt& b) const { return v==b.v;}
	bool operator!=(const ModInt& b) const { return v!=b.v;}
	friend istream& operator>>(istream &o,ModInt& x){
		ll tmp;
		o>>tmp;
		x=ModInt(tmp);
		return o;
	}
	friend ostream& operator<<(ostream &o,const ModInt& x){ return o<<x.v;}
};
using mint = ModInt<>;

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
template<class Mint>
vector<Mint> multiply_fft2(const vector<Mint>& x,const vector<Mint>& y){
	const int B = 15;
	int S = x.size()+y.size()-1;
	int N = 2<<bsr(S-1);
	vector<Pc> a[2],b[2];
	rep(t,2){
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
	rep(t,3){
		fill_n(begin(c),N,Pc(0,0));
		for(int xt = max(t-1,0); xt<=min(1,t); xt++){
			int yt = t-xt;
			rep(i,N) c[i] += a[xt][i]*b[yt][i];
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
template<class Mint>
vector<Mint> multiply_fft(const vector<Mint>& x,const vector<Mint>& y){
	return multiply_fft2(x,y);
}


template<class D>
struct Poly{
	vector<D> v;
	int size() const{ return v.size();}	//deg+1
	Poly(int N=0) : v(vector<D>(N)){}
	Poly(vector<D> v) : v(v){shrink();}

	Poly& shrink(){
		while(!v.empty()&&v.back()==D(0)) v.pop_back();	//double? iszeroをglobalに用意したほうがいいかな
		return *this;
	}
	D at(int i) const{
		return (i<size())?v[i]:D(0);
	}
	void set(int i,const D& x){		//v[i] := x
		if(i>=size() && !x) return;
		while(i>=size()) v.push_back(D(0));
		v[i]=x;
		shrink();
		return;
	}
	
	Poly operator+(const Poly &r) const{
		int N=max(size(),r.size());
		vector<D> ret(N);
		rep(i,N) ret[i]=at(i)+r.at(i);
		return Poly(ret);
	}
	Poly operator-(const Poly &r) const{
		int N=max(size(),r.size());
		vector<D> ret(N);
		rep(i,N) ret[i]=at(i)-r.at(i);
		return Poly(ret);
	}
	Poly operator-() const{
		int N=size();
		vector<D> ret(N);
		rep(i,N) ret[i] = -at(i);
		return Poly(ret);
	}
	Poly operator*(const Poly &r) const{
		if(size()==0||r.size()==0) return Poly();
		return mul_fft(r);
	}
	Poly operator*(const D &r) const{
		int N=size();
		vector<D> ret(N);
		rep(i,N) ret[i]=v[i]*r;
		return Poly(ret);
	}
	Poly operator/(const Poly &y) const{
		return div_fast(y);
	}
	Poly operator%(const Poly &y) const{
		return rem_fast(y);
//		return rem_naive(y);
	}
	Poly operator<<(const int &n) const{	// *=x^n
		assert(n>=0);
		int N=size();
		vector<D> ret(N+n);
		rep(i,N) ret[i+n]=v[i];
		return Poly(ret);
	}
	Poly operator>>(const int &n) const{	// /=x^n
		assert(n>=0);
		int N=size();
		if(N<=n) return Poly();
		vector<D> ret(N-n);
		rep(i,N-n) ret[i]=v[i+n];
		return Poly(ret);
	}
	bool operator==(const Poly &y) const{
		return v==y.v;
	}
	bool operator!=(const Poly &y) const{
		return v!=y.v;
	}

	Poly& operator+=(const Poly &r) {return *this = *this+r;}
	Poly& operator-=(const Poly &r) {return *this = *this-r;}
	Poly& operator*=(const Poly &r) {return *this = *this*r;}
	Poly& operator*=(const D &r) {return *this = *this*r;}
	Poly& operator%=(const Poly &y) {return *this = *this%y;}
	Poly& operator<<=(const int &n) {return *this = *this<<n;}
	Poly& operator>>=(const int &n) {return *this = *this>>n;}


	Poly mul_naive(const Poly &r) const{
		int N=size(),M=r.size();
		vector<D> ret(N+M-1);
		rep(i,N) rep(j,M) ret[i+j]+=at(i)*r.at(j);
		return Poly(ret);
	}
	Poly mul_ntt(const Poly &r) const{
		return Poly(multiply_ntt(this->v,r.v));
	}
	Poly mul_fft(const Poly &r) const{
		vector<D> ret = multiply_fft(v,r.v);
		return Poly(ret);
	}

	Poly div_fast_with_inv(const Poly &inv, int B) const {
		return (*this * inv)>>(B-1);
	}
	Poly div_fast(const Poly &y) const{
		if(size()<y.size()) return Poly();
		int n = size();
		return div_fast_with_inv(y.inv(n),n);
	}
	Poly rem_naive(const Poly &y) const{
		Poly x = *this;
		while(y.size()<=x.size()){
			int N=x.size(),M=y.size();
			D coef = x.v[N-1]/y.v[M-1];
			x -= (y<<(N-M))*coef;
		}
		return x;
	}
	Poly rem_fast(const Poly &y) const{
		return *this - y * div_fast(y);
	}
	Poly strip(int n) const {	//ignore x^n , x^n+1,...
		vector<D> res = v;
		res.resize(min(n,size()));
		return Poly(res);
	}
	Poly rev(int n = -1) const {	//ignore x^n ~  ->  return x^(n-1) * f(1/x)
		vector<D> res = v;
		if(n!=-1) res.resize(n);
		reverse(all(res));
		return Poly(res);
	}
	Poly inv(int n) const{		// f * f.inv() = x^B + r(x) (B>=n)
		int N = size();
		assert(N>=1);		//f : non0
		assert(n>=N-1);		//f = .. + c_{N-1}x^{N-1}
		D coef = D(1)/at(N-1);
		Poly a = rev();
		Poly g(vector<D>(1,coef));
		for(int i=1; i+N-2<n; i*=2){		//need to strip!!
			g *= (Poly(vector<D>{2})-a*g).strip(2*i);
		}
		return g.rev(n+1-N);
	}

	friend ostream& operator<<(ostream &o,const Poly& x){
		if(x.size()==0) return o<<0;
		rep(i,x.size()) if(x.v[i]!=D(0)){
			o<<x.v[i]<<"x^"<<i;
			if(i!=x.size()-1) o<<" + ";
		}
		return o;
	}
};
template<class D>
Poly<D> berlekamp_massey(const vector<D> &u){
	int N = u.size();
	vector<D> b = {D(-1)}, c = {D(-1)};
	D y = D(1);
	rep1(n,N){
		int L = c.size(), M = b.size();
		D x = 0;
		rep(i,L) x += c[i]*u[n-L+i];
		b.pb(0);
		M++;
		if(!x) continue;
		D coef = x/y;
		if(L<M){
			auto tmp = c;
			c.insert(begin(c),M-L,D(0));
			rep(i,M) c[M-1-i] -= coef*b[M-1-i];
			b=tmp;
			y=x;
		}else{
			rep(i,M) c[L-1-i] -= coef*b[M-1-i];
		}
	}
	return Poly<D>(c);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

