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


# :warning: graph/FunctionalGraph.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/FunctionalGraph.cpp">View this file on GitHub</a>
    - Last commit date: 2018-03-30 16:44:12+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	FunctionalGraph の cycle列挙, 逆グラフ(サイクル辺除く)の構成

	verified at AGC008/E Next or Nextnext
*/

struct FunctionalGraph{
	//output
	vector<vector<int>> cycles;
	vector<vector<int>> G;	//a^-1 cycleの辺は除く


	vector<bool> vis;
	void setvis(int v){
		vis[v] = 1;
		for(int u:G[v]) setvis(u);
	}
	
	FunctionalGraph(vector<int> a){
		int N = a.size();
		vis.resize(N);
		G.resize(N);
		rep(i,N) G[a[i]].pb(i);
		rep(i,N) if(!vis[i]){
			int v = i;
			while(!vis[v]){
				vis[v] = 1;
				v = a[v];
			}
			vector<int> cycle;
			int s = v;
			do{
				cycle.pb(v);
				v = a[v];
			}while(v!=s);
			cycles.pb(cycle);

			int L = cycle.size();
			rep(j,L){
				int v = cycle[j];
				rep(k,G[a[v]].size()) if(G[a[v]][k] == v){
					G[a[v]].erase(G[a[v]].begin()+k);
					break;
				}
			}
			rep(j,L){
				int v = cycle[j];
				setvis(v);
			}
		}

	}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/FunctionalGraph.cpp"
/*
	FunctionalGraph の cycle列挙, 逆グラフ(サイクル辺除く)の構成

	verified at AGC008/E Next or Nextnext
*/

struct FunctionalGraph{
	//output
	vector<vector<int>> cycles;
	vector<vector<int>> G;	//a^-1 cycleの辺は除く


	vector<bool> vis;
	void setvis(int v){
		vis[v] = 1;
		for(int u:G[v]) setvis(u);
	}
	
	FunctionalGraph(vector<int> a){
		int N = a.size();
		vis.resize(N);
		G.resize(N);
		rep(i,N) G[a[i]].pb(i);
		rep(i,N) if(!vis[i]){
			int v = i;
			while(!vis[v]){
				vis[v] = 1;
				v = a[v];
			}
			vector<int> cycle;
			int s = v;
			do{
				cycle.pb(v);
				v = a[v];
			}while(v!=s);
			cycles.pb(cycle);

			int L = cycle.size();
			rep(j,L){
				int v = cycle[j];
				rep(k,G[a[v]].size()) if(G[a[v]][k] == v){
					G[a[v]].erase(G[a[v]].begin()+k);
					break;
				}
			}
			rep(j,L){
				int v = cycle[j];
				setvis(v);
			}
		}

	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

