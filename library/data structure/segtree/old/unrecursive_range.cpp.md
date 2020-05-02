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
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :warning: data structure/segtree/old/unrecursive_range.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#fd751f78534902643f339bc0ff029c45">data structure/segtree/old</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/segtree/old/unrecursive_range.cpp">View this file on GitHub</a>
    - Last commit date: 2017-04-22 20:47:35+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
int sum(int a,int b){
	int ret=0;
	a+=p2,b+=p2;
	while(a<b){
		if(a&1) ret+=seg[a++];
		if(b&1) ret+=seg[--b];
		a/=2,b/=2;
	}
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/segtree/old/unrecursive_range.cpp"
int sum(int a,int b){
	int ret=0;
	a+=p2,b+=p2;
	while(a<b){
		if(a&1) ret+=seg[a++];
		if(b&1) ret+=seg[--b];
		a/=2,b/=2;
	}
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

