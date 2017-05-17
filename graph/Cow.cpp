/*
	牛ゲー
	x_t - x_s <= const なる式がいっぱいあって、条件をみたすように割り振れるか?
	initializer Cow(頂点数(変数数))
	IsValidAssign が 1 を返してきたら vector<D> d が条件を満たす割当になっている

	x_v <= 3 みたいなのは頂点Z (=0) を作って、始点をZにするとよい

	verified at http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2633 (Cellular Automaton)

*/
struct Cow{
	using D = int;
	const D inf = 1e9;
	struct Edge{
		int to;
		D cost;
		Edge(int to,D cost):to(to),cost(cost){}
	};
	int N,M;
	vector<vector<Edge>> G;
	vector<D> d;
	Cow(int N):N(N){
		G.assign(N,vector<Edge>());
		d.assign(N,inf);
	}
	void add_edge(int t,int s,D c){	// correspond to t-s <= c
//		printf("%d->%d   :%d\n",t,s,c);
		G[s].pb(Edge(t,c));
	}
	void add_edge(int t,int s,D clow,D chigh){	// clow <= t-s <= chigh
		add_edge(t,s,chigh);
		add_edge(s,t,-clow);
	}
	/*
		return the inequalities have a valid assignment
		if satisfiable, minimize d[T]-d[S]

		negative cycle    <=> unsatisfiable
		d[T] - d[S] = inf <=> feasible unboundedly

		d[S]=0

		Tによらなくない?(気づき)
	*/
	bool IsValidAssign(int S = 0){
		vector<int> prev(N);
		d[S] = 0;
		rep(ph,N){
			bool update = 0;
			int v = -1;
			rep(s,N) for(auto e:G[s]){
				int t = e.to;
				D cost = e.cost;
				if(d[s]+cost < d[t]){
					update=1;
					v = t;
					d[t] = d[s]+cost;
					prev[t] = s;
				}
			}
			if(ph == N-1 && update){
				// vector<int> path;
				// path.pb(v);
				// int u = v;
				// do{
				// 	show(u);
				// 	u = prev[u];
				// 	path.pb(u);
				// }while(u!=v);
				// reverse(all(path));
				// show(path);
				return 0;
			}
			if(!update) break;
		}
		return 1;
	}
};
