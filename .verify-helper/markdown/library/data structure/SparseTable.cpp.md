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


# :warning: data structure/SparseTable.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#37305dfb5e3ae8ec66b10a691aedead8">data structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/SparseTable.cpp">View this file on GitHub</a>
    - Last commit date: 2019-02-15 14:02:44+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
int bsr(unsigned int x){
	if(x==0) return -1;
	return 31 ^ __builtin_clz(x);
}

struct SparseTable{
	using D = int;												//type
	VV<D> d;
	int lg;

	SparseTable(){}
	SparseTable(const vector<D>& v){
		int N = v.size();
		assert(N > 0);

		lg = bsr(N)+1;
		d.resize(lg);
		d[0] = v;
		for(int t=1;t<lg;t++){
			int len = 1<<t;
			d[t].resize(N-len+1);
			rep(i,N-len+1){
				d[t][i] = max(d[t-1][i] , d[t-1][i+len/2]);		//op
			}
		}
	}
	D query(int l, int r) const {
		if(l>=r) return -1;										//e
		int u = bsr(r-l);
		return max(d[u][l] , d[u][r-(1<<u)]);					//op
	}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/SparseTable.cpp"
int bsr(unsigned int x){
	if(x==0) return -1;
	return 31 ^ __builtin_clz(x);
}

struct SparseTable{
	using D = int;												//type
	VV<D> d;
	int lg;

	SparseTable(){}
	SparseTable(const vector<D>& v){
		int N = v.size();
		assert(N > 0);

		lg = bsr(N)+1;
		d.resize(lg);
		d[0] = v;
		for(int t=1;t<lg;t++){
			int len = 1<<t;
			d[t].resize(N-len+1);
			rep(i,N-len+1){
				d[t][i] = max(d[t-1][i] , d[t-1][i+len/2]);		//op
			}
		}
	}
	D query(int l, int r) const {
		if(l>=r) return -1;										//e
		int u = bsr(r-l);
		return max(d[u][l] , d[u][r-(1<<u)]);					//op
	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

