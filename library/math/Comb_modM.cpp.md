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


# :warning: math/Comb_modM.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/Comb_modM.cpp">View this file on GitHub</a>
    - Last commit date: 2018-09-18 03:14:42+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	任意mod での a choose b
	mod はでかくてもいい
	X! までの各素数でのorder(acc_order_p)とそれ以外(other)の部分を前計算しておいてやる
	orderはX/p + X/p^2 + .. で求まるのでメモリ減らしたいなら前計算消した方がいいかも

	これでa,bもでかかったらLucas?

	純粋にさらにクエリを早くしたいなら、累乗を前計算

	verified at CF/896/D
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

unsigned int mod;

struct ModInt{
	using uint = unsigned int;
	using ll = long long;
	using ull = unsigned long long;

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
using mint = ModInt;

struct precalc_comb{
	using ll = long long;
	ll M;
	vector<ll> ps;

	vector<vector<int>> acc_order_p;
	vector<mint> acc_other;

	precalc_comb(){}

	precalc_comb(ll M,int X):M(M){	//X! まで
		mod = M;	//mint

		{	//factorize
			ll x = M;
			for(ll i=2;i*i<=x;i++) if(x%i==0){
				ps.pb(i);
				while(x%i==0) x/=i;
			}
			if(x>1) ps.pb(x);
		}

		int K = ps.size();

		acc_order_p = vector<vector<int>>(X+1,vector<int>(K,0));
		acc_other = vector<mint>(X+1);

		vector<int> n(X+1);
		rep(i,X+1) n[i] = i;

		rep(k,K){
			ll p = ps[k];
			for(ll x=p;x<=X;x+=p){
				while(n[x]%p==0){
					n[x]/=p;
					acc_order_p[x][k]++;
				}
			}
		}
		acc_other[0] = 1;
		rep(i,X) acc_other[i+1] = acc_other[i] * n[i+1];
		rep(k,K){
			rep(i,X) acc_order_p[i+1][k] += acc_order_p[i][k];
		}
	}

	mint ex(mint x,int p){
		mint a = 1;
		while(p){
			if(p%2) a*=x;
			x*=x;
			p/=2;
		}
		return a;
	}


	mint C(int x,int y){	//x choose y
		if(M==1) return 0;
		if(y<0 || y>x) return 0;
		int K = ps.size();
		mint c = acc_other[x] / (acc_other[y] * acc_other[x-y]);
		rep(k,K){
			int r = acc_order_p[x][k] - acc_order_p[y][k] - acc_order_p[x-y][k];
			c *= ex(ps[k],r);
		}
		return c;
	}
}PC;

// mint C(int x,int y){
// 	return PC.C(x,y);
// }

long long C[1001][1001];

int main(){
	long long M;
	cin>>M;
//	M = 2*3*5*7*11*13*17*19*23; //(223'093'870)
	rep(i,1001){
		C[i][0] = C[i][i] = 1%M;
		rep1(j,i-1) C[i][j] = (C[i-1][j-1]+C[i-1][j])%M;
	}
	PC = precalc_comb(M,200000);
	puts("done constructer");

	rep1(x,1000) rep(y,x+1){
		if(C[x][y] != (int)PC.C(x,y).v){
			show(x);
			show(y);
			show(C[x][y]);
			show(PC.C(x,y));
			assert(0);
		}
	}

	while(true){
		int x,y;
		cin>>x>>y;
		printf("%d choose %d = %d     mod %d\n",x,y,(int)PC.C(x,y).v,(int)M);
	}

}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/Comb_modM.cpp"
/*
	任意mod での a choose b
	mod はでかくてもいい
	X! までの各素数でのorder(acc_order_p)とそれ以外(other)の部分を前計算しておいてやる
	orderはX/p + X/p^2 + .. で求まるのでメモリ減らしたいなら前計算消した方がいいかも

	これでa,bもでかかったらLucas?

	純粋にさらにクエリを早くしたいなら、累乗を前計算

	verified at CF/896/D
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

unsigned int mod;

struct ModInt{
	using uint = unsigned int;
	using ll = long long;
	using ull = unsigned long long;

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
using mint = ModInt;

struct precalc_comb{
	using ll = long long;
	ll M;
	vector<ll> ps;

	vector<vector<int>> acc_order_p;
	vector<mint> acc_other;

	precalc_comb(){}

	precalc_comb(ll M,int X):M(M){	//X! まで
		mod = M;	//mint

		{	//factorize
			ll x = M;
			for(ll i=2;i*i<=x;i++) if(x%i==0){
				ps.pb(i);
				while(x%i==0) x/=i;
			}
			if(x>1) ps.pb(x);
		}

		int K = ps.size();

		acc_order_p = vector<vector<int>>(X+1,vector<int>(K,0));
		acc_other = vector<mint>(X+1);

		vector<int> n(X+1);
		rep(i,X+1) n[i] = i;

		rep(k,K){
			ll p = ps[k];
			for(ll x=p;x<=X;x+=p){
				while(n[x]%p==0){
					n[x]/=p;
					acc_order_p[x][k]++;
				}
			}
		}
		acc_other[0] = 1;
		rep(i,X) acc_other[i+1] = acc_other[i] * n[i+1];
		rep(k,K){
			rep(i,X) acc_order_p[i+1][k] += acc_order_p[i][k];
		}
	}

	mint ex(mint x,int p){
		mint a = 1;
		while(p){
			if(p%2) a*=x;
			x*=x;
			p/=2;
		}
		return a;
	}


	mint C(int x,int y){	//x choose y
		if(M==1) return 0;
		if(y<0 || y>x) return 0;
		int K = ps.size();
		mint c = acc_other[x] / (acc_other[y] * acc_other[x-y]);
		rep(k,K){
			int r = acc_order_p[x][k] - acc_order_p[y][k] - acc_order_p[x-y][k];
			c *= ex(ps[k],r);
		}
		return c;
	}
}PC;

// mint C(int x,int y){
// 	return PC.C(x,y);
// }

long long C[1001][1001];

int main(){
	long long M;
	cin>>M;
//	M = 2*3*5*7*11*13*17*19*23; //(223'093'870)
	rep(i,1001){
		C[i][0] = C[i][i] = 1%M;
		rep1(j,i-1) C[i][j] = (C[i-1][j-1]+C[i-1][j])%M;
	}
	PC = precalc_comb(M,200000);
	puts("done constructer");

	rep1(x,1000) rep(y,x+1){
		if(C[x][y] != (int)PC.C(x,y).v){
			show(x);
			show(y);
			show(C[x][y]);
			show(PC.C(x,y));
			assert(0);
		}
	}

	while(true){
		int x,y;
		cin>>x>>y;
		printf("%d choose %d = %d     mod %d\n",x,y,(int)PC.C(x,y).v,(int)M);
	}

}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

