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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: data structure/unionfind/quickfind.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c2dde45cf8b056fa1d016e48f1da538e">data structure/unionfind</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/unionfind/quickfind.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
quickfind
使うことあるかなあ
verified by どこか(忘れたけど何回か使ってる)
*/
struct quickfind{
	vector<int> i2g;
	vector<vector<int> > g2i;
	void init(int n){
		i2g.resize(n);
		g2i.resize(n);
		rep(i,n){
			i2g[i]=i;
			g2i[i].assign(1,i);
		}
	}
	void unite(int ia,int ib){
		if(g2i[i2g[ia]].size() < g2i[i2g[ib]].size()) swap(ia,ib);
		int ga=i2g[ia],gb=i2g[ib];
		for(auto v:g2i[gb]) i2g[i]=ga;
		g2i[ga].insert(g2i[ga].end(),all(g2i[gb]));
	}
	bool same(int ia,int ib){
		return i2g[ia]==i2g[ib];
	}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/unionfind/quickfind.cpp"
/*
quickfind
使うことあるかなあ
verified by どこか(忘れたけど何回か使ってる)
*/
struct quickfind{
	vector<int> i2g;
	vector<vector<int> > g2i;
	void init(int n){
		i2g.resize(n);
		g2i.resize(n);
		rep(i,n){
			i2g[i]=i;
			g2i[i].assign(1,i);
		}
	}
	void unite(int ia,int ib){
		if(g2i[i2g[ia]].size() < g2i[i2g[ib]].size()) swap(ia,ib);
		int ga=i2g[ia],gb=i2g[ib];
		for(auto v:g2i[gb]) i2g[i]=ga;
		g2i[ga].insert(g2i[ga].end(),all(g2i[gb]));
	}
	bool same(int ia,int ib){
		return i2g[ia]==i2g[ib];
	}
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

