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


# :warning: graph/Flow/Dinic_lowlimit.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c1b32428735d2269ee124b3a330cfcaa">graph/Flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/Flow/Dinic_lowlimit.cpp">View this file on GitHub</a>
    - Last commit date: 2019-03-14 23:15:20+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	maxflowに,最小流量制約が加わったもの
	max_flow(s,t) = -1 \Leftrightarrow 制約を満たすフローが存在しない.

	add_edge_lowhigh(from,to,lowcap,highcap) で辺を張った後、(普通のadd_edgeと一緒に使っても大丈夫)
	t->s にINFを張って,そのあとS->Tにflowを流す.
	この時にsum 最小流量制限 以上流れればOK,流れなければ-1

	もう一度先ほど同様にグラフを再構築する.(G[i].clear()だけでOK)
	今度はS->s,t->TにINFを張って,S->Tに流す.
	この値-sum 最小流量制限 が元のグラフでのmax_flowである.

	verified at SRM694 hard

	TODO : 復元は自明な方法ではできない、すぬけのブログを観ること！

*/

struct MaxFlow_lowlim{
	using D = int;
	const D inf = 1e9;
	struct edge{
		int to;
		D cap;
		int rev;
		edge(int to,D cap,int rev):to(to),cap(cap),rev(rev){}
	};

	int V;
	int S,T;
	D lowsum;
	vector<vector<edge>> G,G_copy;
	vector<int> level,iter;

	MaxFlow_lowlim(int N):S(N),T(N+1),V(N+2){
		G = vector<vector<edge>>(V);
		level = vector<int>(V);
		iter = vector<int>(V);
		lowsum = 0;
	}

	void add_edge(int from, int to, D cap){
		edge e1(to,cap,(int)G[to].size());
		edge e2(from,0,(int)G[from].size());
		G[from].push_back(e1);
		G[to].push_back(e2);
	}
	void add_edge_lowhigh(int from, int to, D lowcap,D highcap){
		assert(lowcap<=highcap);
		lowsum += lowcap;
		add_edge(S,to,lowcap);
		add_edge(from,T,lowcap);
		add_edge(from,to,highcap-lowcap);
	}
	void bfs(int s){
		level = vector<int>(V,-1);

		queue<int> que;
		level[s]=0;
		que.push(s);
		while(!que.empty()){
			int v=que.front();
			que.pop();
			for(int i=0;i<(int)G[v].size();i++){
				edge &e=G[v][i];
				if(e.cap>0 && level[e.to]<0){
					level[e.to]=level[v]+1;
					que.push(e.to);
				}
			}
		}
	}
	D dfs(int v,int t,D f){
		if(v==t) return f;
		for(int &i=iter[v];i<(int)G[v].size();i++){
			edge &e=G[v][i];
			if(e.cap>0 && level[v]<level[e.to]){
				D d = dfs(e.to,t,min(f,e.cap));
				if(d>0){
					e.cap-=d;
					G[e.to][e.rev].cap+=d;
					return d;
				}
			}
		}
		return 0;
	}
	D max_flow_sub(int s,int t){
		D flow=0;
		while(true){
			bfs(s);
			if(level[t]<0) return flow;
			iter = vector<int>(V,0);
			D f;
			while( (f=dfs(s,t,inf))>0 ) flow+=f;
		}
	}

	D max_flow(int s,int t){
		G_copy = G;
		add_edge(t,s,inf);
		D f = max_flow_sub(S,T);
		if(f < lowsum) return -1;

		G = G_copy;
		add_edge(S,s,inf);
		add_edge(t,T,inf);
		f = max_flow_sub(S,T);
		assert(f >= lowsum);
		return f-lowsum;
	}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/Flow/Dinic_lowlimit.cpp"
/*
	maxflowに,最小流量制約が加わったもの
	max_flow(s,t) = -1 \Leftrightarrow 制約を満たすフローが存在しない.

	add_edge_lowhigh(from,to,lowcap,highcap) で辺を張った後、(普通のadd_edgeと一緒に使っても大丈夫)
	t->s にINFを張って,そのあとS->Tにflowを流す.
	この時にsum 最小流量制限 以上流れればOK,流れなければ-1

	もう一度先ほど同様にグラフを再構築する.(G[i].clear()だけでOK)
	今度はS->s,t->TにINFを張って,S->Tに流す.
	この値-sum 最小流量制限 が元のグラフでのmax_flowである.

	verified at SRM694 hard

	TODO : 復元は自明な方法ではできない、すぬけのブログを観ること！

*/

struct MaxFlow_lowlim{
	using D = int;
	const D inf = 1e9;
	struct edge{
		int to;
		D cap;
		int rev;
		edge(int to,D cap,int rev):to(to),cap(cap),rev(rev){}
	};

	int V;
	int S,T;
	D lowsum;
	vector<vector<edge>> G,G_copy;
	vector<int> level,iter;

	MaxFlow_lowlim(int N):S(N),T(N+1),V(N+2){
		G = vector<vector<edge>>(V);
		level = vector<int>(V);
		iter = vector<int>(V);
		lowsum = 0;
	}

	void add_edge(int from, int to, D cap){
		edge e1(to,cap,(int)G[to].size());
		edge e2(from,0,(int)G[from].size());
		G[from].push_back(e1);
		G[to].push_back(e2);
	}
	void add_edge_lowhigh(int from, int to, D lowcap,D highcap){
		assert(lowcap<=highcap);
		lowsum += lowcap;
		add_edge(S,to,lowcap);
		add_edge(from,T,lowcap);
		add_edge(from,to,highcap-lowcap);
	}
	void bfs(int s){
		level = vector<int>(V,-1);

		queue<int> que;
		level[s]=0;
		que.push(s);
		while(!que.empty()){
			int v=que.front();
			que.pop();
			for(int i=0;i<(int)G[v].size();i++){
				edge &e=G[v][i];
				if(e.cap>0 && level[e.to]<0){
					level[e.to]=level[v]+1;
					que.push(e.to);
				}
			}
		}
	}
	D dfs(int v,int t,D f){
		if(v==t) return f;
		for(int &i=iter[v];i<(int)G[v].size();i++){
			edge &e=G[v][i];
			if(e.cap>0 && level[v]<level[e.to]){
				D d = dfs(e.to,t,min(f,e.cap));
				if(d>0){
					e.cap-=d;
					G[e.to][e.rev].cap+=d;
					return d;
				}
			}
		}
		return 0;
	}
	D max_flow_sub(int s,int t){
		D flow=0;
		while(true){
			bfs(s);
			if(level[t]<0) return flow;
			iter = vector<int>(V,0);
			D f;
			while( (f=dfs(s,t,inf))>0 ) flow+=f;
		}
	}

	D max_flow(int s,int t){
		G_copy = G;
		add_edge(t,s,inf);
		D f = max_flow_sub(S,T);
		if(f < lowsum) return -1;

		G = G_copy;
		add_edge(S,s,inf);
		add_edge(t,T,inf);
		f = max_flow_sub(S,T);
		assert(f >= lowsum);
		return f-lowsum;
	}
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

