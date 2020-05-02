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


# :warning: math/Q.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/Q.cpp">View this file on GitHub</a>
    - Last commit date: 2018-10-12 13:58:41+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	有理数体
	任意/正, gcd = 1 で常に持つ
	verified at https://official.contest.yandex.ru/opencupXIX/contest/9262/problems/K (Q上で連立方程式)
*/
int bsf(ll x) { return __builtin_ctzll(x); } 
ll gcd(ll a, ll b){
	a = abs(a), b = abs(b);
	if(a==0) return b;
	if(b==0) return a;
	int shift = bsf(a|b);
	a >>= bsf(a);
	do{
		b >>= bsf(b);
		if(a>b) swap(a,b);
		b -= a;
	}while(b);
	return a<<shift;
}

struct F{
	ll x,y;		// x/y
	F():x(0),y(1){}
	F(ll x):x(x),y(1){}
	F(ll x,ll y):x(x),y(y){}

	F norm(ll x,ll y) const {
		ll g = gcd(x,y);
		x /= g, y /= g;
		if(y<0){
			x = -x;
			y = -y;
		}
		return F(x,y);
	}

	F operator+(const F& r) const {
		ll X = x * r.y + y * r.x;
		ll Y = y * r.y;
		return norm(X,Y);
	}
	F operator-(const F& r) const {
		ll X = x * r.y - y * r.x;
		ll Y = y * r.y;
		return norm(X,Y);
	}
	F operator*(const F& r) const {
		ll X = x * r.x;
		ll Y = y * r.y;
		return norm(X,Y);
	}
	F operator/(const F& r) const {
		ll X = x * r.y;
		ll Y = y * r.x;
		return norm(X,Y);
	}
	bool operator==(const F& r) const {
		return x == r.x && y == r.y;
	}
	friend ostream& operator<<(ostream &o,const F& x){
		return o<<x.x<<"/"<<x.y;
	}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/Q.cpp"
/*
	有理数体
	任意/正, gcd = 1 で常に持つ
	verified at https://official.contest.yandex.ru/opencupXIX/contest/9262/problems/K (Q上で連立方程式)
*/
int bsf(ll x) { return __builtin_ctzll(x); } 
ll gcd(ll a, ll b){
	a = abs(a), b = abs(b);
	if(a==0) return b;
	if(b==0) return a;
	int shift = bsf(a|b);
	a >>= bsf(a);
	do{
		b >>= bsf(b);
		if(a>b) swap(a,b);
		b -= a;
	}while(b);
	return a<<shift;
}

struct F{
	ll x,y;		// x/y
	F():x(0),y(1){}
	F(ll x):x(x),y(1){}
	F(ll x,ll y):x(x),y(y){}

	F norm(ll x,ll y) const {
		ll g = gcd(x,y);
		x /= g, y /= g;
		if(y<0){
			x = -x;
			y = -y;
		}
		return F(x,y);
	}

	F operator+(const F& r) const {
		ll X = x * r.y + y * r.x;
		ll Y = y * r.y;
		return norm(X,Y);
	}
	F operator-(const F& r) const {
		ll X = x * r.y - y * r.x;
		ll Y = y * r.y;
		return norm(X,Y);
	}
	F operator*(const F& r) const {
		ll X = x * r.x;
		ll Y = y * r.y;
		return norm(X,Y);
	}
	F operator/(const F& r) const {
		ll X = x * r.y;
		ll Y = y * r.x;
		return norm(X,Y);
	}
	bool operator==(const F& r) const {
		return x == r.x && y == r.y;
	}
	friend ostream& operator<<(ostream &o,const F& x){
		return o<<x.x<<"/"<<x.y;
	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

