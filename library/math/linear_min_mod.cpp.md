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


# :warning: math/linear_min_mod.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/linear_min_mod.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-18 18:18:32+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	lw <= ax mod b <= up なる x に対し、
	getAXmodB : ax を返す
	getMin : xを返す

	verified : 手元
*/

/*
	!!! return ax mod b !!! where x is
	min x>=0 s.t. lw <= ax mod b <= up
	no -> -1

	gcdと完全に一緒、上限ll,O(log)
*/
ll getAXmodB(ll a,ll b,ll lw,ll up){
	if(lw == 0) return 0;
	if(a == 0) return -1;
	ll p = (lw+a-1)/a*a;
	if(lw<=p && p<=up) return p;
	ll res = getAXmodB(b%a,a,p-up,p-lw);
	if(res == -1) return -1;
	return p-res;
}
struct EG { ll g, x, y; };
EG ext_gcd(ll a, ll b) {
	if(b == 0){
		if (a >= 0) return EG{a, 1, 0};
		else return EG{-a, -1, 0};
	}else{
		auto e = ext_gcd(b, a % b);
		return EG{e.g, e.y, e.x - a / b * e.y};
	}
}
ll inv_mod(ll x, ll md) {
	auto z = ext_gcd(x, md).x;
	return (z % md + md) % md;
}

/*
	!!! return x !!! where x is
	min x>=0 s.t. lw <= ax mod b <= up
	no -> -1

	gcdと完全に一緒、上限ll,O(log)

	getaxmodbの2.5倍くらい遅いから、ほしいときだけこっち
*/
ll getMin(ll a,ll b,ll lw,ll up){
	assert(a >= 0 && b > 0 && 0 <= lw && lw <= up && up < b);
	ll ax = getAXmodB(a,b,lw,up);
	if(ax == -1) return -1;
	auto e = ext_gcd(a,b);
	ll g = e.g;
	a/=g,ax/=g,b/=g;
	return __int128((e.x+b)%b)*ax%b;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/linear_min_mod.cpp"
/*
	lw <= ax mod b <= up なる x に対し、
	getAXmodB : ax を返す
	getMin : xを返す

	verified : 手元
*/

/*
	!!! return ax mod b !!! where x is
	min x>=0 s.t. lw <= ax mod b <= up
	no -> -1

	gcdと完全に一緒、上限ll,O(log)
*/
ll getAXmodB(ll a,ll b,ll lw,ll up){
	if(lw == 0) return 0;
	if(a == 0) return -1;
	ll p = (lw+a-1)/a*a;
	if(lw<=p && p<=up) return p;
	ll res = getAXmodB(b%a,a,p-up,p-lw);
	if(res == -1) return -1;
	return p-res;
}
struct EG { ll g, x, y; };
EG ext_gcd(ll a, ll b) {
	if(b == 0){
		if (a >= 0) return EG{a, 1, 0};
		else return EG{-a, -1, 0};
	}else{
		auto e = ext_gcd(b, a % b);
		return EG{e.g, e.y, e.x - a / b * e.y};
	}
}
ll inv_mod(ll x, ll md) {
	auto z = ext_gcd(x, md).x;
	return (z % md + md) % md;
}

/*
	!!! return x !!! where x is
	min x>=0 s.t. lw <= ax mod b <= up
	no -> -1

	gcdと完全に一緒、上限ll,O(log)

	getaxmodbの2.5倍くらい遅いから、ほしいときだけこっち
*/
ll getMin(ll a,ll b,ll lw,ll up){
	assert(a >= 0 && b > 0 && 0 <= lw && lw <= up && up < b);
	ll ax = getAXmodB(a,b,lw,up);
	if(ax == -1) return -1;
	auto e = ext_gcd(a,b);
	ll g = e.g;
	a/=g,ax/=g,b/=g;
	return __int128((e.x+b)%b)*ax%b;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

