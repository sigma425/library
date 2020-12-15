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


# :warning: graph/Flow/min_cost_flow_negative.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c1b32428735d2269ee124b3a330cfcaa">graph/Flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/Flow/min_cost_flow_negative.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
負閉路がないときだけ

はじめにBellman Fordするとあとはポテンシャル込みでは負辺がなくなる.
O(EV + FElogV)

DAGなら Bellman Ford すらいらなくて、はじめDPすれば O(E + FElogV)かな(こっちがいることあるかなあ)

負閉路がある場合、先にそこにそって目一杯流しておく.→そのあとにこれ

*/
typedef pair<int,int> P;
struct edge {int to,cap,cost,rev;};
const int MAX_V=,INF=;
int V;			//代入!!
vector<edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];
void add_edge(int from, int to, int cap, int cost){
	edge e1={to,cap,cost,G[to].size()},e2={from,0,-cost,G[from].size()};
	G[from].push_back(e1);
	G[to].push_back(e2);
}
int min_cost_flow(int s, int t, int f){
	int res=0;
	fill(h,h+V,0);
	rep(v,V){
		for(edge e:G[v]){
			if(e.cap>0) chmin(h[e.to],h[v]+e.cost);
		}
	}
	while(f>0){
		priority_queue< P,vector<P>,greater<P> > que;
		fill(dist,dist+V,INF);
		dist[s]=0;
		que.push(P(0,s));
		while(!que.empty()){
			P p=que.top();
			que.pop();
			int v=p.second;
			if(dist[v]<p.first) continue;
			for(int i=0;i<G[v].size();i++){
				edge &e=G[v][i];
				if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
					dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
					prevv[e.to]=v;
					preve[e.to]=i;
					que.push(P(dist[e.to],e.to));
				}
			}
		}
		if(dist[t]==INF) return -1;
		for(int v=0;v<V;v++) h[v]+=dist[v];
		int d=f;
		for(int v=t;v!=s;v=prevv[v]){
			d=min(d,G[prevv[v]][preve[v]].cap);
		}
		f-=d;
		res+=d*h[t];
		for(int v=t;v!=s;v=prevv[v]){
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/Flow/min_cost_flow_negative.cpp"
/*
負閉路がないときだけ

はじめにBellman Fordするとあとはポテンシャル込みでは負辺がなくなる.
O(EV + FElogV)

DAGなら Bellman Ford すらいらなくて、はじめDPすれば O(E + FElogV)かな(こっちがいることあるかなあ)

負閉路がある場合、先にそこにそって目一杯流しておく.→そのあとにこれ

*/
typedef pair<int,int> P;
struct edge {int to,cap,cost,rev;};
const int MAX_V=,INF=;
int V;			//代入!!
vector<edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];
void add_edge(int from, int to, int cap, int cost){
	edge e1={to,cap,cost,G[to].size()},e2={from,0,-cost,G[from].size()};
	G[from].push_back(e1);
	G[to].push_back(e2);
}
int min_cost_flow(int s, int t, int f){
	int res=0;
	fill(h,h+V,0);
	rep(v,V){
		for(edge e:G[v]){
			if(e.cap>0) chmin(h[e.to],h[v]+e.cost);
		}
	}
	while(f>0){
		priority_queue< P,vector<P>,greater<P> > que;
		fill(dist,dist+V,INF);
		dist[s]=0;
		que.push(P(0,s));
		while(!que.empty()){
			P p=que.top();
			que.pop();
			int v=p.second;
			if(dist[v]<p.first) continue;
			for(int i=0;i<G[v].size();i++){
				edge &e=G[v][i];
				if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
					dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
					prevv[e.to]=v;
					preve[e.to]=i;
					que.push(P(dist[e.to],e.to));
				}
			}
		}
		if(dist[t]==INF) return -1;
		for(int v=0;v<V;v++) h[v]+=dist[v];
		int d=f;
		for(int v=t;v!=s;v=prevv[v]){
			d=min(d,G[prevv[v]][preve[v]].cap);
		}
		f-=d;
		res+=d*h[t];
		for(int v=t;v!=s;v=prevv[v]){
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

