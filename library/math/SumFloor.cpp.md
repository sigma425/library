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


# :warning: math/SumFloor.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/SumFloor.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	return sum_{k=0~n-1} [ak/b]

	a>=0,b>0,n>=0
	O(log(max(a,b)))
	計算途中でmax(a,b,n)^2 くらいの大きさにはなるのでオーバーフローに注意

	verified at opencup/7836/F.cpp
*/
template<class D>
D sumFloor(D a,D b,D n){
	assert(b!=0);
	if(a==0 || n==0) return 0;
	D g = gcd(a,b);
	a/=g, b/=g;

	D res = 0;
	while(a!=0 && n!=0){
		if(a>=b){
			res += a/b * n*(n-1)/2;
			a %= b;
			if(a==0) break;
		}
		if(n>=b){
			res += (n/b)*(n/b-1)/2*a*b + (a-1)*(b-1)/2*(n/b) + (n/b)*a*(n%b);
			n %= b;
			if(n==0) break;
		}
		res += (b-1)*(a-1)/2 - (b-n)*(a*(n-1)/b);
		n = a-a*(n-1)/b;
		swap(a,b);
		res = -res;
	}
	res = abs(res);
	return res;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/SumFloor.cpp"
/*
	return sum_{k=0~n-1} [ak/b]

	a>=0,b>0,n>=0
	O(log(max(a,b)))
	計算途中でmax(a,b,n)^2 くらいの大きさにはなるのでオーバーフローに注意

	verified at opencup/7836/F.cpp
*/
template<class D>
D sumFloor(D a,D b,D n){
	assert(b!=0);
	if(a==0 || n==0) return 0;
	D g = gcd(a,b);
	a/=g, b/=g;

	D res = 0;
	while(a!=0 && n!=0){
		if(a>=b){
			res += a/b * n*(n-1)/2;
			a %= b;
			if(a==0) break;
		}
		if(n>=b){
			res += (n/b)*(n/b-1)/2*a*b + (a-1)*(b-1)/2*(n/b) + (n/b)*a*(n%b);
			n %= b;
			if(n==0) break;
		}
		res += (b-1)*(a-1)/2 - (b-n)*(a*(n-1)/b);
		n = a-a*(n-1)/b;
		swap(a,b);
		res = -res;
	}
	res = abs(res);
	return res;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

