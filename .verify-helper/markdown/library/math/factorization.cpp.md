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


# :warning: math/factorization.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/factorization.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	素因数分解 1 <= n <= 10^18
	isprime.cpp が必要
	pollard_rho's algorithm
	O(n^0.25 polylog(n)) くらいらしい
*/
#include<bits/stdc++.h>
using namespace std;

template<class T>
T gcd(T a,T b){
	a = abs(a), b = abs(b);
	if(b==0) return a;
	return gcd(b,a%b);
}
template<class T, class U>
T pow_mod(T x, U p, T mod){
	assert(p>=0);
	x %= mod;
	T a = 1 % mod;
	while(p){
		if(p&1) a = a*x%mod;
		x = x*x%mod;
		p >>= 1;
	}
	return a;
}
using ll = long long;
bool isprime(ll n){
	if(n<=1) return 0;
	if(n==2) return 1;
	if(n%2==0) return 0;
	ll d = n-1;
	while(d%2==0) d/=2;
	static const vector<ll> alist{2,3,5,7,11,13,17,19,23,29,31,37};
	for(ll a: alist){
		if(n<=a) break;
		ll t = d;
		ll y = pow_mod<__int128>(a,t,n);
		while(t!=n-1 && y!=1 && y!=n-1){
			y = __int128(y)*y%n;
			t<<=1;
		}
		if(y!=n-1 && t%2==0) return 0;
	}
	return 1;
}

ll f(ll x,ll n){ return (__int128(x)*x+1)%n;}
ll pollard_single(ll n){
	if(isprime(n)) return n;
	if(!(n&1)) return 2;
	ll i,x,y,p;
	for(i=1;;i++){
		x=i; y=f(x,n); p=gcd(y-x,n);
		while(p==1){
			x=f(x,n); y=f(f(y,n),n); p=gcd((y-x+n)%n,n)%n;
		}
		if(p==0 || p==n) continue;
		return p;
	}
	assert(0);
}

vector<ll> pollard(ll n){
	if(n==1) return {};
	ll x = pollard_single(n);
	if(x==n) return {x};
	vector<ll> le = pollard(x);
	vector<ll> ri = pollard(n/x);
	for(ll d: ri) le.push_back(d);
	return le;
}

int main(){
	while(true){
		ll n;
		cin>>n;
		vector<ll> ps = pollard(n);
		printf("factors:  ");
		for(ll p:ps) cout<<p<<" ";
		puts("");
	}
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/factorization.cpp"
/*
	素因数分解 1 <= n <= 10^18
	isprime.cpp が必要
	pollard_rho's algorithm
	O(n^0.25 polylog(n)) くらいらしい
*/
#include<bits/stdc++.h>
using namespace std;

template<class T>
T gcd(T a,T b){
	a = abs(a), b = abs(b);
	if(b==0) return a;
	return gcd(b,a%b);
}
template<class T, class U>
T pow_mod(T x, U p, T mod){
	assert(p>=0);
	x %= mod;
	T a = 1 % mod;
	while(p){
		if(p&1) a = a*x%mod;
		x = x*x%mod;
		p >>= 1;
	}
	return a;
}
using ll = long long;
bool isprime(ll n){
	if(n<=1) return 0;
	if(n==2) return 1;
	if(n%2==0) return 0;
	ll d = n-1;
	while(d%2==0) d/=2;
	static const vector<ll> alist{2,3,5,7,11,13,17,19,23,29,31,37};
	for(ll a: alist){
		if(n<=a) break;
		ll t = d;
		ll y = pow_mod<__int128>(a,t,n);
		while(t!=n-1 && y!=1 && y!=n-1){
			y = __int128(y)*y%n;
			t<<=1;
		}
		if(y!=n-1 && t%2==0) return 0;
	}
	return 1;
}

ll f(ll x,ll n){ return (__int128(x)*x+1)%n;}
ll pollard_single(ll n){
	if(isprime(n)) return n;
	if(!(n&1)) return 2;
	ll i,x,y,p;
	for(i=1;;i++){
		x=i; y=f(x,n); p=gcd(y-x,n);
		while(p==1){
			x=f(x,n); y=f(f(y,n),n); p=gcd((y-x+n)%n,n)%n;
		}
		if(p==0 || p==n) continue;
		return p;
	}
	assert(0);
}

vector<ll> pollard(ll n){
	if(n==1) return {};
	ll x = pollard_single(n);
	if(x==n) return {x};
	vector<ll> le = pollard(x);
	vector<ll> ri = pollard(n/x);
	for(ll d: ri) le.push_back(d);
	return le;
}

int main(){
	while(true){
		ll n;
		cin>>n;
		vector<ll> ps = pollard(n);
		printf("factors:  ");
		for(ll p:ps) cout<<p<<" ";
		puts("");
	}
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

