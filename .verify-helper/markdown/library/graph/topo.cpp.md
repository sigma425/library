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


# :warning: graph/topo.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/topo.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
self loopも not dag
visを0で初期化して,Gを作って、maketopo(頂点数)すると
topo[i]=i番目の頂点 になる
*/

const int MAX_V=;
int vis[MAX_V];		//0->yet,1->now,2->done
vector<int> topo;
vector<int> G[MAX_V];
bool visit(int v){
	if(vis[v]==2) return 1;
	if(vis[v]==1) return 0;
	vis[v]=1;
	for(int u:G[v]) if(!visit(u)) return 0;
	vis[v]=2;
	topo.pb(v);
	return 1;
}
bool maketopo(int V){
	rep(i,V) if(!visit(i)) return 0;
	reverse(all(topo));
	return 1;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/topo.cpp"
/*
self loopも not dag
visを0で初期化して,Gを作って、maketopo(頂点数)すると
topo[i]=i番目の頂点 になる
*/

const int MAX_V=;
int vis[MAX_V];		//0->yet,1->now,2->done
vector<int> topo;
vector<int> G[MAX_V];
bool visit(int v){
	if(vis[v]==2) return 1;
	if(vis[v]==1) return 0;
	vis[v]=1;
	for(int u:G[v]) if(!visit(u)) return 0;
	vis[v]=2;
	topo.pb(v);
	return 1;
}
bool maketopo(int V){
	rep(i,V) if(!visit(i)) return 0;
	reverse(all(topo));
	return 1;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

