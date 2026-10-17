/*
	A回dijkstra O(K + VE + A(V + ElogE))
	V: 頂点数, E: 元の辺数, K: 線分数の総和, A: 増加路を流す回数
	初期残余辺がすべて非負なら Bellman Ford の VE は不要
	空間 O(V + E + K)

	辺に x 流したときのコストが凸な区分線形関数の場合の最小費用流
	各線分を (dx,dy/dx) で与える
	例: {{2,3},{4,5}} なら
		0 <= x <= 2 で 3x
		2 <= x <= 6 で 6+5(x-2)
	傾きは単調非減少でなければならない

	各辺の流量がどの線分にあるかを持つ
	順方向はまだ使っていない最小の傾き、逆方向は使った最大の傾きの符号反転
	現在の傾きと、その傾きで流せる残余容量の取得は O(1)
	増加路ではどの辺も線分の境界を越えない量だけ流すので、更新も各辺 O(1)
	線分数が増えても、Dijkstra が走査する残余辺は各辺につき順逆の2本だけ

	負の傾きも使える
	ただし正の容量を持つ負閉路がある場合は扱えない
*/
struct MinCostFlowConv{
	using C = ll;		// capacity
	using D = ll;		// cost (distance)
	using Segment = pair<C,D>;	// (dx,dy/dx)
	const D inf = 1e18;	// max distance

	struct cost_function{
		V<Segment> segments;
		int pos = 0;	// 順方向で次に使う線分 (全部使ったら segments.size())
		C used = 0;	// segments[pos] の使用量

		Segment residual(bool rev) const{
			if(!rev){
				if(pos == (int)segments.size()) return {0,0};
				return {segments[pos].first-used,segments[pos].second};
			}
			if(used > 0) return {used,-segments[pos].second};
			if(pos == 0) return {0,0};
			return {segments[pos-1].first,-segments[pos-1].second};
		}

		void push(C f,bool rev){
			assert(0 < f && f <= residual(rev).first);
			if(!rev){
				used += f;
				if(used == segments[pos].first){
					pos++;
					used = 0;
				}
			}else{
				if(used == 0){
					pos--;
					used = segments[pos].first;
				}
				used -= f;
			}
		}
	};

	struct edge{
		int to,id;
		bool rev;
		edge(int to_,int id_,bool rev_):to(to_),id(id_),rev(rev_){}
	};

	int N;
	VV<edge> G;
	V<cost_function> functions;
	V<D> h;
	V<D> dist;
	V<int> prevv,preve;
	MinCostFlowConv(int N_):N(N_){
		G.resize(N);
		h.resize(N);
		dist.resize(N);
		prevv.resize(N);
		preve.resize(N);
	}

	// linear cost: cost*x (0 <= x <= cap)
	void add_edge(int from,int to,C cap,D cost){
		add_edge(from,to,V<Segment>{{cap,cost}});
	}

	// convex piecewise linear cost: segments = {(dx,dy/dx)}
	void add_edge(int from,int to,const V<Segment>& segments){
		cost_function func;
		for(auto [cap,cost]:segments){
			assert(cap >= 0);
			if(cap == 0) continue;
			if(!func.segments.empty()) assert(func.segments.back().second <= cost);
			func.segments.emplace_back(cap,cost);
		}
		int id = functions.size();
		functions.push_back(move(func));
		G[from].emplace_back(to,id,false);
		G[to].emplace_back(from,id,true);
	}

	// 負辺があるときの初期potentialをBellman Fordで求める
	// ない場合は early return
	void init_potential(){
		h = V<D>(N);
		bool has_negative_edge = false;
		for(auto& es:G) for(auto& e:es){
			auto [cap,cost] = functions[e.id].residual(e.rev);
			if(cap > 0 && cost < 0) has_negative_edge = true;
		}
		if(!has_negative_edge) return;

		rep(_,N){
			bool update = false;
			rep(v,N) for(auto& e:G[v]){
				auto [cap,cost] = functions[e.id].residual(e.rev);
				if(cap > 0 && h[e.to] > h[v]+cost){
					h[e.to] = h[v]+cost;
					update = true;
				}
			}
			if(!update) break;
			assert(_+1 < N); // negative loop
		}
	}

	bool dijkstra(int s,int t){
		using P = pair<D,int>;
		priority_queue<P,vector<P>,greater<P>> que;
		dist = V<D>(N,inf);
		dist[s] = 0;
		que.push(P(0,s));
		while(!que.empty()){
			P p = que.top();
			que.pop();
			int v = p.second;
			if(dist[v] < p.first) continue;
			for(int i=0;i<(int)G[v].size();i++){
				edge& e = G[v][i];
				auto [cap,cost] = functions[e.id].residual(e.rev);
				if(cap == 0) continue;
				D nd = dist[v]+cost+h[v]-h[e.to];
				if(dist[e.to] > nd){
					dist[e.to] = nd;
					prevv[e.to] = v;
					preve[e.to] = i;
					que.push(P(dist[e.to],e.to));
				}
			}
		}
		if(dist[t] == inf) return false;
		rep(v,N) if(dist[v] < inf) h[v] += dist[v];
		return true;
	}

	D min_cost_flow(int s,int t,C f){
		assert(s != t && f >= 0);
		D res = 0;
		init_potential();
		while(f > 0){
			if(!dijkstra(s,t)) return -1;
			C d = f;
			for(int v=t;v!=s;v=prevv[v]){
				edge& e = G[prevv[v]][preve[v]];
				chmin(d,functions[e.id].residual(e.rev).first);
			}
			f -= d;
			res += d*(h[t]-h[s]);
			for(int v=t;v!=s;v=prevv[v]){
				edge& e = G[prevv[v]][preve[v]];
				functions[e.id].push(d,e.rev);
			}
		}
		return res;
	}

	/*
		流量を横軸に、コストを縦軸に取ったときのグラフ
		各線分の (dx,dy/dx) の vector を返す
	*/
	V<Segment> min_cost_flow_slopes(int s,int t){
		assert(s != t);
		V<Segment> res;
		init_potential();
		while(dijkstra(s,t)){
			C f = inf;
			for(int v=t;v!=s;v=prevv[v]){
				edge& e = G[prevv[v]][preve[v]];
				chmin(f,functions[e.id].residual(e.rev).first);
			}
			D slope = h[t]-h[s];
			if(!res.empty() && res.back().second == slope) res.back().first += f;
			else res.emplace_back(f,slope);
			for(int v=t;v!=s;v=prevv[v]){
				edge& e = G[prevv[v]][preve[v]];
				functions[e.id].push(f,e.rev);
			}
		}
		return res;
	}
};
