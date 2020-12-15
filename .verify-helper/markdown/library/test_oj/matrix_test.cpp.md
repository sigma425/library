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


# :warning: test_oj/matrix_test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#d917bfc2afe503d9009ff5d8d6b2e2c3">test_oj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test_oj/matrix_test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-21 23:33:53+09:00




## Depends on

* :warning: <a href="../math/matrix/matrix.cpp.html">math/matrix/matrix.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// #define PROBLEM https://judge.yosupo.jp/problem/suffixarray

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

#ifdef LOCAL
#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x) true
#endif

#include "../math/matrix/matrix.cpp"

template<unsigned int mod_>
struct ModInt{
	using uint = unsigned int;
	using ll = long long;
	using ull = unsigned long long;

	constexpr static uint mod = mod_;

	uint v;
	ModInt():v(0){}
	ModInt(ll _v):v(normS(_v%mod+mod)){}
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
	ModInt& operator++(int){ return *this=*this+1;}
	ModInt& operator--(int){ return *this=*this-1;}
	ll extgcd(ll a,ll b,ll &x,ll &y) const{
		ll p[]={a,1,0},q[]={b,0,1};
		while(*q){
			ll t=*p/ *q;
			rep(i,3) swap(p[i]-=t*q[i],q[i]);
		}
		if(p[0]<0) rep(i,3) p[i]=-p[i];
		x=p[1],y=p[2];
		return p[0];
	}
	ModInt inv() const {
		ll x,y;
		extgcd(v,mod,x,y);
		return make(normS(x+mod));
	}
	ModInt pow(ll p) const {
		if(p<0) return inv().pow(-p);
		ModInt a = 1;
		ModInt x = *this;
		while(p){
			if(p&1) a *= x;
			x *= x;
			p >>= 1;
		}
		return a;
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
using mint = ModInt<998244353>;
bool iszero(mint x){return x==0;}
bool isone(mint x){return x==1;}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	using Mat = Matrix<mint>;	
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test_oj/matrix_test.cpp"
// #define PROBLEM https://judge.yosupo.jp/problem/suffixarray

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

#ifdef LOCAL
#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x) true
#endif

#line 1 "math/matrix/matrix.cpp"
/*
	行列の基本演算, 連立一次方程式の解, 逆行列 とか
	template 引数 T は体である必要がある
	+,-,*,/, unary -
	の他に, zero, one, iszero(), isone() がいる
	浮動小数点とかのためにiszeroとかは==zeroを避けている

	usage:
		field class (mintとか) を用意する
		zero,one,iszero(),isone()を書く

	solveLinearEquationに0個の式を入れると横幅が取得できず[0].size() で segfault ので注意

	complexity:
		sweep系はすべて O(rank * H * W)
		rankが小さいと勝手に計算量は減る

	verified at http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624 (solveLinearEquarion mod 2)
	verified at https://official.contest.yandex.ru/opencupXIX/contest/9262/problems/K (sLE on Rationals)

*/

template<class T>
struct Matrix{
	int H,W;
	VV<T> a;

	Matrix() : H(0),W(0){}
	Matrix(int H,int W) : H(H),W(W),a( VV<T>(H,V<T>(W)) ){}
	Matrix(const VV<T>& v) : H(v.size()), W(v[0].size()), a(v){}

	static Matrix E(int n){
		Matrix a(n,n);
		rep(i,n) a.set(i,i,1);
		return a;
	}

	T at(int i,int j) const {
		return a[i][j];
	}
	void set(int i,int j,T v){
		a[i][j] = v;
	}

	Matrix operator+(const Matrix& r) const {
		assert(H==r.H && W==r.W);
		VV<T> v(H,V<T>(W));
		rep(i,H) rep(j,W) v[i][j] = a[i][j] + r.a[i][j];
		return Matrix(v);
	}
	Matrix operator-(const Matrix& r) const {
		assert(H==r.H && W==r.W);
		VV<T> v(H,V<T>(W));
		rep(i,H) rep(j,W) v[i][j] = a[i][j] - r.a[i][j];
		return Matrix(v);
	}
	Matrix operator*(const Matrix& r) const {
		assert(W==r.H);
		VV<T> v(H,V<T>(r.W));
		rep(i,H) rep(k,W) rep(j,r.W) v[i][j] += a[i][k] * r.a[k][j];
		return Matrix(v);
	}
	Matrix& operator+=(const Matrix& r){return (*this)=(*this)+r;}
	Matrix& operator-=(const Matrix& r){return (*this)=(*this)-r;}
	Matrix& operator*=(const Matrix& r){return (*this)=(*this)*r;}

	Matrix pow(ll p) const {
		assert(H == W);
		Matrix a = E(H);
		Matrix x = *this;
		while(p){
			if(p&1) a *= x;
			x *= x;
			p >>= 1;
		}
		return a;
	}

	friend ostream& operator<<(ostream &o,const Matrix& A){
		rep(i,A.H){
			rep(j,A.W) o<<A.a[i][j]<<" ";
			o<<endl;
		}
		return o;
	}

	/*
		副作用がある, 基本的に自分でこれを呼ぶことはない
		掃き出し法をする
		左からvar列が掃き出す対象で、それより右は同時に値を変更するだけ(e.g. 逆行列は右に単位行列おいてから掃き出す)
		行swap, 列swap は行わない

		rank を返す
	*/
	int sweep(int var){
		int rank = 0;
		vector<bool> used(H);
		rep(j,var){
			int i=0;
			while(i<H && (used[i]||iszero(a[i][j]))) i++;
			if(i==H) continue;
			used[i] = true;
			rank++;
			T t = a[i][j];
			rep(k,W) a[i][k] = a[i][k]/t;
			rep(k,H) if(k!=i){
				T t = a[k][j];
				rep(l,W) a[k][l] = a[k][l]-a[i][l]*t;
			}
		}
		return rank;
	}

};

/*
	逆行列を返す
	なければ0*0行列
*/
template<class T>
Matrix<T> inv(const Matrix<T>& A){
	assert(A.H==A.W);
	int N = A.H;
	Matrix<T> X(N,2*N);
	rep(i,N) rep(j,N) X.set(i,j,A.at(i,j));
	rep(i,N) X.set(i,i+N,one);
	int rank = X.sweep(N);
	if(rank < N) return Matrix<T>();
	Matrix<T> B(N,N);
	rep(i,N){
		rep(j,N){
			B.set(i,j,X.at(i,j+N));
		}
	}
	return B;
}

/*
	Ax = b を解く
	pair(解空間の次元, 解のうちひとつ) を返す
	解が存在しないなら(-1,{})

	解を複数得たい → ランダムな式を追加?
*/
template<class T>
pair< int, vector<T> > solveLinearEquation(const Matrix<T>& A, vector<T> b){
	assert(A.H==(int)b.size());
	int H = A.H, W = A.W;

	Matrix<T> X(H,W+1);
	rep(i,H) rep(j,W) X.set(i,j,A.at(i,j));
	rep(i,H) X.set(i,W,b[i]);
	int rank = X.sweep(W);
	rep(i,H){
		bool allzero = true;
		rep(j,W) if(!iszero(X.at(i,j))) allzero = false;
		if(allzero){
			if(!iszero(X.at(i,W))){		//0x + 0y + 0z = non0
				return pair<int,vector<T> >(-1,vector<T>());
			}
		}
	}
	vector<bool> done(H);
	vector<T> x(W);
	rep(j,W){
		int c0 = 0, c1 = 0;
		int I = -1;
		rep(i,H){
			if(iszero(X.at(i,j))) c0++;
			else if(isone(X.at(i,j))) c1++,I=i;
		}
		if(c0==H-1 && c1==1 && !done[I]){
			x[j] = X.at(I,W);
			done[I] = true;
		}
	}
	return pair<int,vector<T> >(W-rank,x);
}

/*
	determinant
*/
template<class T>
T det(Matrix<T> A){
	assert(A.H==A.W);
	int N = A.H;
	int rank = A.sweep(N);
	if(rank < N) return zero;
	T d = one;
	vector<int> to(N);
	rep(i,N){
		rep(j,N){
			if(!iszero(A.at(i,j))){
				to[i] = j;
				d *= A.at(i,j);
			}
		}
	}
	vector<bool> done(N);
	rep(i,N) if(!done[i]){
		int x = i;
		bool odd = 1;
		while(!done[x]){
			done[x] = 1;
			x = to[x];
			odd = !odd;
		}
		if(odd) d = -d;
	}
	return d;
}

/*
	rank
*/
template<class T>
int getrank(Matrix<T> A){
	return A.sweep(A.W);
}
#line 34 "test_oj/matrix_test.cpp"

template<unsigned int mod_>
struct ModInt{
	using uint = unsigned int;
	using ll = long long;
	using ull = unsigned long long;

	constexpr static uint mod = mod_;

	uint v;
	ModInt():v(0){}
	ModInt(ll _v):v(normS(_v%mod+mod)){}
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
	ModInt& operator++(int){ return *this=*this+1;}
	ModInt& operator--(int){ return *this=*this-1;}
	ll extgcd(ll a,ll b,ll &x,ll &y) const{
		ll p[]={a,1,0},q[]={b,0,1};
		while(*q){
			ll t=*p/ *q;
			rep(i,3) swap(p[i]-=t*q[i],q[i]);
		}
		if(p[0]<0) rep(i,3) p[i]=-p[i];
		x=p[1],y=p[2];
		return p[0];
	}
	ModInt inv() const {
		ll x,y;
		extgcd(v,mod,x,y);
		return make(normS(x+mod));
	}
	ModInt pow(ll p) const {
		if(p<0) return inv().pow(-p);
		ModInt a = 1;
		ModInt x = *this;
		while(p){
			if(p&1) a *= x;
			x *= x;
			p >>= 1;
		}
		return a;
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
using mint = ModInt<998244353>;
bool iszero(mint x){return x==0;}
bool isone(mint x){return x==1;}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	using Mat = Matrix<mint>;	
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

