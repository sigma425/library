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


# :warning: graph/Flow/min_cost_flow.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c1b32428735d2269ee124b3a330cfcaa">graph/Flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/Flow/min_cost_flow.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:56:13+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct MinCostFlow{
	using C = ll;		// capacity
	using D = ll;		// cost (distance)
	const D inf = 1e18;	// max distance

	struct edge{
		int to;
		C cap;
		D cost;
		int rev;
		edge(int to_,C cap_, D cost_, int rev_):to(to_),cap(cap_),cost(cost_),rev(rev_){}
	};
	
	int N;
	VV<edge> G;
	V<D> h;
	V<D> dist;
	V<int> prevv,preve;
	MinCostFlow(int N_):N(N_){
		G.resize(N);
		h.resize(N);
		dist.resize(N);
		prevv.resize(N);
		preve.resize(N);
	}

	void add_edge(int from, int to, C cap, D cost){
		show(cap);
		show(cost);
		edge e1(to,cap,cost,(int)G[to].size());
		edge e2(from,0,-cost,(int)G[from].size());
		G[from].push_back(e1);
		G[to].push_back(e2);
	}
	D min_cost_flow(int s, int t, C f){
		D res = 0;
		h = V<D>(N);
		while(f > 0){
			using P = pair<D,int>;
			priority_queue< P,vector<P>,greater<P> > que;
			dist = V<D>(N,inf);
			dist[s] = 0;
			que.push(P(0,s));
			while(!que.empty()){
				P p = que.top();
				que.pop();
				int v = p.second;
				if(dist[v] < p.first) continue;
				for(int i=0;i<(int)G[v].size();i++){
					edge &e = G[v][i];
					if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
						dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
						prevv[e.to]=v;
						preve[e.to]=i;
						que.push(P(dist[e.to],e.to));
					}
				}
			}
			if(dist[t]==inf) return -1;
			rep(v,N) h[v]+=dist[v];
			C d = f;
			for(int v=t;v!=s;v=prevv[v]){
				chmin(d,G[prevv[v]][preve[v]].cap);
			}
			f -= d;
			res += d*h[t];
			for(int v=t;v!=s;v=prevv[v]){
				edge &e=G[prevv[v]][preve[v]];
				e.cap-=d;
				G[v][e.rev].cap+=d;
			}
		}
		return res;
	}

	/*
		流量を横軸に、コストを縦軸に取ったときのグラフ
		各線分の (dx,dy/dx) の vector を返す
		CF621 G 
	*/
	V<pair<C,D>> min_cost_flow_slopes(int s, int t){		// {(x,tan)}
		V<pair<C,D>> res;
		h = V<D>(N);
		while(true){
			using P = pair<D,int>;
			priority_queue< P,vector<P>,greater<P> > que;
			dist = V<D>(N,inf);
			dist[s] = 0;
			que.push(P(0,s));
			while(!que.empty()){
				P p = que.top();
				que.pop();
				int v = p.second;
				if(dist[v] < p.first) continue;
				for(int i=0;i<(int)G[v].size();i++){
					edge &e = G[v][i];
					if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
						dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
						prevv[e.to]=v;
						preve[e.to]=i;
						que.push(P(dist[e.to],e.to));
					}
				}
			}
			if(dist[t]==inf) break;
			rep(v,N) h[v]+=dist[v];
			C f = inf;
			for(int v=t;v!=s;v=prevv[v]){
				chmin(f,G[prevv[v]][preve[v]].cap);
			}
			res.pb(f,h[t]);				// x, tan
			for(int v=t;v!=s;v=prevv[v]){
				edge &e=G[prevv[v]][preve[v]];
				e.cap-=f;
				G[v][e.rev].cap+=f;
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
#line 1 "graph/Flow/min_cost_flow.cpp"
struct MinCostFlow{
	using C = ll;		// capacity
	using D = ll;		// cost (distance)
	const D inf = 1e18;	// max distance

	struct edge{
		int to;
		C cap;
		D cost;
		int rev;
		edge(int to_,C cap_, D cost_, int rev_):to(to_),cap(cap_),cost(cost_),rev(rev_){}
	};
	
	int N;
	VV<edge> G;
	V<D> h;
	V<D> dist;
	V<int> prevv,preve;
	MinCostFlow(int N_):N(N_){
		G.resize(N);
		h.resize(N);
		dist.resize(N);
		prevv.resize(N);
		preve.resize(N);
	}

	void add_edge(int from, int to, C cap, D cost){
		show(cap);
		show(cost);
		edge e1(to,cap,cost,(int)G[to].size());
		edge e2(from,0,-cost,(int)G[from].size());
		G[from].push_back(e1);
		G[to].push_back(e2);
	}
	D min_cost_flow(int s, int t, C f){
		D res = 0;
		h = V<D>(N);
		while(f > 0){
			using P = pair<D,int>;
			priority_queue< P,vector<P>,greater<P> > que;
			dist = V<D>(N,inf);
			dist[s] = 0;
			que.push(P(0,s));
			while(!que.empty()){
				P p = que.top();
				que.pop();
				int v = p.second;
				if(dist[v] < p.first) continue;
				for(int i=0;i<(int)G[v].size();i++){
					edge &e = G[v][i];
					if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
						dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
						prevv[e.to]=v;
						preve[e.to]=i;
						que.push(P(dist[e.to],e.to));
					}
				}
			}
			if(dist[t]==inf) return -1;
			rep(v,N) h[v]+=dist[v];
			C d = f;
			for(int v=t;v!=s;v=prevv[v]){
				chmin(d,G[prevv[v]][preve[v]].cap);
			}
			f -= d;
			res += d*h[t];
			for(int v=t;v!=s;v=prevv[v]){
				edge &e=G[prevv[v]][preve[v]];
				e.cap-=d;
				G[v][e.rev].cap+=d;
			}
		}
		return res;
	}

	/*
		流量を横軸に、コストを縦軸に取ったときのグラフ
		各線分の (dx,dy/dx) の vector を返す
		CF621 G 
	*/
	V<pair<C,D>> min_cost_flow_slopes(int s, int t){		// {(x,tan)}
		V<pair<C,D>> res;
		h = V<D>(N);
		while(true){
			using P = pair<D,int>;
			priority_queue< P,vector<P>,greater<P> > que;
			dist = V<D>(N,inf);
			dist[s] = 0;
			que.push(P(0,s));
			while(!que.empty()){
				P p = que.top();
				que.pop();
				int v = p.second;
				if(dist[v] < p.first) continue;
				for(int i=0;i<(int)G[v].size();i++){
					edge &e = G[v][i];
					if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
						dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
						prevv[e.to]=v;
						preve[e.to]=i;
						que.push(P(dist[e.to],e.to));
					}
				}
			}
			if(dist[t]==inf) break;
			rep(v,N) h[v]+=dist[v];
			C f = inf;
			for(int v=t;v!=s;v=prevv[v]){
				chmin(f,G[prevv[v]][preve[v]].cap);
			}
			res.pb(f,h[t]);				// x, tan
			for(int v=t;v!=s;v=prevv[v]){
				edge &e=G[prevv[v]][preve[v]];
				e.cap-=f;
				G[v][e.rev].cap+=f;
			}
		}
		return res;
	}
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

