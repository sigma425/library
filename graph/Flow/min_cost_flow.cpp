/*
	F回dijkstra O(FElogV)

	負のコストについて:
		負閉路:
			やべ～
			コストスケーリング系なら行けるという噂があります
		負辺:
			気にせずに貼ってはじめにBellman Ford (min_cost_flow 関数のはじめのコメントを参照)

	最小流量制限について:
		1) -BIGを足して負辺だと思う
			グラフの形によってはこれで十分、Fがでかくなるのでやや計算量は怪しい
		2) なんか超頂点つくるやつ
			むずいねんな
			普通にS->t, s->T だと思うとまずい
			https://snuke.hatenablog.com/entry/2016/07/10/043918
		3) b-flow
			すべてを解決するが遅いときもある
*/
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
		// if G has negative edge && has no negative loop
		// Bellman Ford O(MN)
		// rep(v,N){
		// 	for(auto& e: G[v]){
		// 		if(e.cap > 0) chmin(h[e.to],h[v]+e.cost);
		// 	}
		// }
		
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
