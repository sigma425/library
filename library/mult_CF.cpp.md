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
<script type="text/javascript" src="../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../assets/css/copy-button.css" />


# :warning: mult_CF.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/mult_CF.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-13 22:29:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
    int128が入ってないやん！用
     - md が小さい時商が long double で求められるか？
    など、不明点が多いですね
    https://codeforces.com/blog/entry/70247
    gym102361 H.cpp
*/
inline ll mul(ll a,ll b,ll md){
	ll s=a*b-ll((long double)a/md*b+0.5)*md;
	return (s<0) ? (s+md) : (s>=md ? s-md : s);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "mult_CF.cpp"
/*
    int128が入ってないやん！用
     - md が小さい時商が long double で求められるか？
    など、不明点が多いですね
    https://codeforces.com/blog/entry/70247
    gym102361 H.cpp
*/
inline ll mul(ll a,ll b,ll md){
	ll s=a*b-ll((long double)a/md*b+0.5)*md;
	return (s<0) ? (s+md) : (s>=md ? s-md : s);
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

