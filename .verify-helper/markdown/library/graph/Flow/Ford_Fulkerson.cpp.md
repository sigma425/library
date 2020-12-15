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


# :warning: graph/Flow/Ford_Fulkerson.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c1b32428735d2269ee124b3a330cfcaa">graph/Flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/Flow/Ford_Fulkerson.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct edge {int to,cap,rev;};
const int MAX_V=,INF=;
vector<edge> G[MAX_V];
bool used[MAX_V];
void add_edge(int from, int to, int cap){
	//directed
	edge e1={to,cap,G[to].size()};
	edge e2={from,0,G[from].size()};
	G[from].push_back(e1);
	G[to].push_back(e2);
}
int dfs(int v,int t,int f){
	if(v==t) return f;
	used[v]=true;
	for(int i=0;i<G[v].size();i++){
		edge &e=G[v][i];
		if(!used[e.to] && e.cap>0){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t){
	int flow=0;
	while(true){
		memset(used,0,sizeof(used));
		int f=dfs(s,t,INF);
		if(f==0) return flow;
		flow+=f;
	}
}
int main(){
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/Flow/Ford_Fulkerson.cpp"
struct edge {int to,cap,rev;};
const int MAX_V=,INF=;
vector<edge> G[MAX_V];
bool used[MAX_V];
void add_edge(int from, int to, int cap){
	//directed
	edge e1={to,cap,G[to].size()};
	edge e2={from,0,G[from].size()};
	G[from].push_back(e1);
	G[to].push_back(e2);
}
int dfs(int v,int t,int f){
	if(v==t) return f;
	used[v]=true;
	for(int i=0;i<G[v].size();i++){
		edge &e=G[v][i];
		if(!used[e.to] && e.cap>0){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t){
	int flow=0;
	while(true){
		memset(used,0,sizeof(used));
		int f=dfs(s,t,INF);
		if(f==0) return flow;
		flow+=f;
	}
}
int main(){

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

