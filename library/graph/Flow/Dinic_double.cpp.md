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


# :warning: graph/Flow/Dinic_double.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c1b32428735d2269ee124b3a330cfcaa">graph/Flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/Flow/Dinic_double.cpp">View this file on GitHub</a>
    - Last commit date: 2018-01-03 22:55:44+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct edge {
	int to;
	D cap;
	int rev;
	edge(int to,D cap,int rev) :to(to),cap(cap),rev(rev){}
};
const int MAX_V=;
const D inf=,eps=;
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];
void add_edge(int from, int to, D cap){
	edge e1(to,cap,G[to].size()),e2(from,0,G[from].size());
	G[from].push_back(e1);
	G[to].push_back(e2);
}
void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();
		que.pop();
		for(int i=0;i<G[v].size();i++){
			edge &e=G[v][i];
			if(e.cap>eps && level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}
D dfs(int v,int t,D f){
	if(v==t) return f;
	for(int &i=iter[v];i<G[v].size();i++){
		edge &e=G[v][i];
		if(e.cap>eps && level[v]<level[e.to]){
			D d=dfs(e.to,t,min(f,e.cap));
			if(d>eps){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
D max_flow(int s,int t){
	D flow=0;
	while(true){
		bfs(s);
		if(level[t]<0) return flow;
		memset(iter,0,sizeof(iter));
		D f;
		while( (f=dfs(s,t,inf))>eps ) flow+=f;
	}
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/Flow/Dinic_double.cpp"
struct edge {
	int to;
	D cap;
	int rev;
	edge(int to,D cap,int rev) :to(to),cap(cap),rev(rev){}
};
const int MAX_V=;
const D inf=,eps=;
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];
void add_edge(int from, int to, D cap){
	edge e1(to,cap,G[to].size()),e2(from,0,G[from].size());
	G[from].push_back(e1);
	G[to].push_back(e2);
}
void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();
		que.pop();
		for(int i=0;i<G[v].size();i++){
			edge &e=G[v][i];
			if(e.cap>eps && level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}
D dfs(int v,int t,D f){
	if(v==t) return f;
	for(int &i=iter[v];i<G[v].size();i++){
		edge &e=G[v][i];
		if(e.cap>eps && level[v]<level[e.to]){
			D d=dfs(e.to,t,min(f,e.cap));
			if(d>eps){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
D max_flow(int s,int t){
	D flow=0;
	while(true){
		bfs(s);
		if(level[t]<0) return flow;
		memset(iter,0,sizeof(iter));
		D f;
		while( (f=dfs(s,t,inf))>eps ) flow+=f;
	}
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

