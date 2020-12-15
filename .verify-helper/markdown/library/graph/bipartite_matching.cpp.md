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


# :warning: graph/bipartite_matching.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/bipartite_matching.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct Bipartite_matching{
	int V;
	vector< vector<int> > G;
	vector<int> match;
	vector<bool> used;
	void init(int N){
		V=N;
		G.assign(V,vector<int>());
		match.assign(V,0);
		used.assign(V,false);
	}
	void add_edge(int v,int u){
		G[v].pb(u);
		G[u].pb(v);
	}
	bool dfs(int v){
		used[v]=true;
		rep(i,G[v].size()){
			int u=G[v][i],w=match[u];
			if(w<0 || (!used[w] && dfs(w))){
				match[v]=u;
				match[u]=v;
				return true;
			}
		}
		return false;
	}
	int max_matching(){
		int res=0;
		fill(all(match),-1);
		rep(v,V){
			if(match[v]<0){
				fill(all(used),false);
				if(dfs(v)) res++;
			}
		}
		return res;
	}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/bipartite_matching.cpp"
struct Bipartite_matching{
	int V;
	vector< vector<int> > G;
	vector<int> match;
	vector<bool> used;
	void init(int N){
		V=N;
		G.assign(V,vector<int>());
		match.assign(V,0);
		used.assign(V,false);
	}
	void add_edge(int v,int u){
		G[v].pb(u);
		G[u].pb(v);
	}
	bool dfs(int v){
		used[v]=true;
		rep(i,G[v].size()){
			int u=G[v][i],w=match[u];
			if(w<0 || (!used[w] && dfs(w))){
				match[v]=u;
				match[u]=v;
				return true;
			}
		}
		return false;
	}
	int max_matching(){
		int res=0;
		fill(all(match),-1);
		rep(v,V){
			if(match[v]<0){
				fill(all(used),false);
				if(dfs(v)) res++;
			}
		}
		return res;
	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

