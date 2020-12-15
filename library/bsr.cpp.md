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


# :warning: bsr.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/bsr.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
x       0  1  2  3  4  5  6  7  8  9
bsr(x) -1  0  1  1  2  2  2  2  3  3
最上位bit
*/
int bsr(uint x){
	if(x==0) return -1;
	return 31 ^ __builtin_clz(x);
}
int bsr(unsigned long long x){
	if(x==0) return -1;
	return 63 ^ __builtin_clzll(x);
}

/*
x       0  1  2  3  4  5  6  7  8  9
bsl(x) -1  0  1  0  2  0  1  0  3  0
最下位bit
*/
int bsl(uint x){
	if(x==0) return -1;
	return __builtin_ctz(x);
}
int bsl(unsigned long long x){
	if(x==0) return -1;
	return __builtin_ctzll(x);
}


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "bsr.cpp"
/*
x       0  1  2  3  4  5  6  7  8  9
bsr(x) -1  0  1  1  2  2  2  2  3  3
最上位bit
*/
int bsr(uint x){
	if(x==0) return -1;
	return 31 ^ __builtin_clz(x);
}
int bsr(unsigned long long x){
	if(x==0) return -1;
	return 63 ^ __builtin_clzll(x);
}

/*
x       0  1  2  3  4  5  6  7  8  9
bsl(x) -1  0  1  0  2  0  1  0  3  0
最下位bit
*/
int bsl(uint x){
	if(x==0) return -1;
	return __builtin_ctz(x);
}
int bsl(unsigned long long x){
	if(x==0) return -1;
	return __builtin_ctzll(x);
}


```
{% endraw %}

<a href="../index.html">Back to top page</a>

