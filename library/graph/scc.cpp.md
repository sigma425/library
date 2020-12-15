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


# :heavy_check_mark: graph/scc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/scc.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 20:23:38+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test_oj/scc.test.cpp.html">test_oj/scc.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
    SCC O(M+N)
    id[v] = v の 連結成分の id
    groups[i] : i番目の連結成分, トポロジカル順
*/
template <class E>
struct SCC{
	V<int> id;
	VV<int> groups;

	int N;
	VV<E> G;
	V<int> ord,low;
	V<bool> inS;
	V<int> st;
    int I=0;

	void dfs(int v){
		ord[v] = low[v] = I++;
		st.pb(v); inS[v] = true;
		for(auto e: G[v]){
			int u = e.to;
			if(ord[u] == -1){
				dfs(u);
				chmin(low[v],low[u]);
			}else if(inS[u]){
				chmin(low[v],ord[u]);
			}
		}
		if(low[v] == ord[v]){
			V<int> group;
			while(true){
				int w = st.back(); st.pop_back();
				inS[w] = false;
				group.pb(w);
				if(w == v) break;
			}
			groups.pb(group);
		}
	}
	SCC(const VV<E>& G_) : N(G_.size()), G(G_), ord(N,-1), low(N), inS(N){
        id = V<int>(N);
		rep(i,N) if(ord[i] == -1) dfs(i);
		reverse(all(groups));
		rep(i,groups.size()){
			for(int v: groups[i]) id[v] = i;
		}
	}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/scc.cpp"
/*
    SCC O(M+N)
    id[v] = v の 連結成分の id
    groups[i] : i番目の連結成分, トポロジカル順
*/
template <class E>
struct SCC{
	V<int> id;
	VV<int> groups;

	int N;
	VV<E> G;
	V<int> ord,low;
	V<bool> inS;
	V<int> st;
    int I=0;

	void dfs(int v){
		ord[v] = low[v] = I++;
		st.pb(v); inS[v] = true;
		for(auto e: G[v]){
			int u = e.to;
			if(ord[u] == -1){
				dfs(u);
				chmin(low[v],low[u]);
			}else if(inS[u]){
				chmin(low[v],ord[u]);
			}
		}
		if(low[v] == ord[v]){
			V<int> group;
			while(true){
				int w = st.back(); st.pop_back();
				inS[w] = false;
				group.pb(w);
				if(w == v) break;
			}
			groups.pb(group);
		}
	}
	SCC(const VV<E>& G_) : N(G_.size()), G(G_), ord(N,-1), low(N), inS(N){
        id = V<int>(N);
		rep(i,N) if(ord[i] == -1) dfs(i);
		reverse(all(groups));
		rep(i,groups.size()){
			for(int v: groups[i]) id[v] = i;
		}
	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

