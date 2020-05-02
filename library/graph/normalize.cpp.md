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


# :warning: graph/normalize.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/normalize.cpp">View this file on GitHub</a>
    - Last commit date: 2017-04-11 17:24:41+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	無向グラフをdfsしたときに,各vに対しG[v]の中で親を一番最後に持ってくる
	rotateしてるので親以外の相対順序は変わらないけど、
	順序木(ex.二次元平面上に頂点があって,親方向から時計回りに子を見ていく必要がある) とかだと変えないとまずい
*/
namespace Normalize{
	template<class E>
	void dfs(vector<vector<E>>& G, int v,int p=-1){
		int K = G[v].size();
		rep(i,K){
			if(G[v][i].to==p){
				rotate(G[v].begin()+i,G[v].begin()+i+1,G[v].end());
			}else{
				dfs(G,G[v][i].to,v);
			}
		}
	}
	template<class E>
	void normalize(vector<vector<E>>& G, int r=0){
		dfs(G,r);
	}
}

struct edge{
	int to;
};
int main(){
	int N,M;
	cin>>N>>M;
	vector<vector<edge>> G(N);
	rep(i,M){
		int x,y;
		cin>>x>>y;
		G[x].pb(edge{y});
		G[y].pb(edge{x});
	}
	Normalize::normalize(G);
	rep(v,N){
		printf("G[%d]={",v);
		for(edge e:G[v]) printf("%d, ",e.to);
		printf("}\n");
	}
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/normalize.cpp"
/*
	無向グラフをdfsしたときに,各vに対しG[v]の中で親を一番最後に持ってくる
	rotateしてるので親以外の相対順序は変わらないけど、
	順序木(ex.二次元平面上に頂点があって,親方向から時計回りに子を見ていく必要がある) とかだと変えないとまずい
*/
namespace Normalize{
	template<class E>
	void dfs(vector<vector<E>>& G, int v,int p=-1){
		int K = G[v].size();
		rep(i,K){
			if(G[v][i].to==p){
				rotate(G[v].begin()+i,G[v].begin()+i+1,G[v].end());
			}else{
				dfs(G,G[v][i].to,v);
			}
		}
	}
	template<class E>
	void normalize(vector<vector<E>>& G, int r=0){
		dfs(G,r);
	}
}

struct edge{
	int to;
};
int main(){
	int N,M;
	cin>>N>>M;
	vector<vector<edge>> G(N);
	rep(i,M){
		int x,y;
		cin>>x>>y;
		G[x].pb(edge{y});
		G[y].pb(edge{x});
	}
	Normalize::normalize(G);
	rep(v,N){
		printf("G[%d]={",v);
		for(edge e:G[v]) printf("%d, ",e.to);
		printf("}\n");
	}
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

