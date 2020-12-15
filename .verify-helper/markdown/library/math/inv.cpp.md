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


# :warning: math/inv.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/inv.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
vector<mint> fac,ifac,inv;
void precalc(int N){	//[0,N]
	N++;
	fac.resize(N);
	ifac.resize(N);
	inv.resize(N);
	fac[0]=1;
	rep1(i,N-1) fac[i] = fac[i-1] * i;

	const int mod = 1e9+7;
	inv[1]=1;
	for(int i=2;i<=N-1;i++) inv[i] = -inv[mod%i] * (mod/i);

	ifac[0]=1;
	rep1(i,N-1) ifac[i] = ifac[i-1] *inv[i];
}
mint Binom(int x,int y){
	if(y<0 || x<y) return 0;
	return fac[x] * ifac[y] * ifac[x-y];
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/inv.cpp"
vector<mint> fac,ifac,inv;
void precalc(int N){	//[0,N]
	N++;
	fac.resize(N);
	ifac.resize(N);
	inv.resize(N);
	fac[0]=1;
	rep1(i,N-1) fac[i] = fac[i-1] * i;

	const int mod = 1e9+7;
	inv[1]=1;
	for(int i=2;i<=N-1;i++) inv[i] = -inv[mod%i] * (mod/i);

	ifac[0]=1;
	rep1(i,N-1) ifac[i] = ifac[i-1] *inv[i];
}
mint Binom(int x,int y){
	if(y<0 || x<y) return 0;
	return fac[x] * ifac[y] * ifac[x-y];
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

