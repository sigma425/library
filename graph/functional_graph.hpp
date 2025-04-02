/*
	FunctionalGraph (outdeg = 1) に限らず、 outdeg <= 1 な有向グラフをうまく扱う struct

	constructor:
		- vector<int> f
			outdeg(v) = 1 なら f[v] が行き先の頂点、 outdeg = 0 なら f[v] = -1

	output:
		- vector<int> con_id(N)
			con_id[v] : v が属する連結成分の ID
		- vector<vector<int>> cons(K)
			cons[k] : k 番目の連結成分に含まれる頂点の集合
		- vector<vector<int>> cycles(K)
			cycles[k] : k 番目の連結成分に含まれるサイクルの頂点の集合 (a->f[a]->.. の順で並んでいる)
			1 頂点 (f[v] = v) の場合も cycles[k] = {v} になる
			その連結成分が木の場合 (f[v] = -1) の場合は empty
		- vector<vector<int>> G(N)
			各頂点から出ている辺の行き先 (サイクルの辺は除外されている)

		- is_tree(k) : k 番目の連結成分が木かどうか


	verified: ABC399-E https://atcoder.jp/contests/abc399/submissions/64421121
*/

struct FunctionalGraph{
	//output
	vector<int> con_id;
	vector<vector<int>> cons;
	vector<vector<int>> cycles;
	vector<vector<int>> G;

	bool is_tree(int k){
		assert(0 <= k && k < si(cons));
		return cycles[k].empty();
	}
	
	FunctionalGraph(vector<int> f){
		int N = f.size();
		vector<bool> vis(N);
		vector<bool> is_root(N);
		con_id.resize(N);
		G.resize(N);
		rep(v,N) if(f[v] == -1){
			is_root[v] = true;
			f[v] = v;
		}
		rep(v,N) G[f[v]].pb(v);
		rep(i,N) if(!vis[i]){
			int x = i;
			while(!vis[x]){
				vis[x] = 1;
				x = f[x];
			}
			vector<int> cycle;
			int s = x;
			do{
				cycle.pb(x);
				x = f[x];
			}while(x != s);

			int L = cycle.size();
			rep(j,L){
				int v = cycle[j];
				erase_if(G[f[v]], [&](int z){ return z == v; });
			}
			queue<int> que;
			rep(j,L) que.push(cycle[j]);
			int k = cycles.size();
			vector<int> con;
			while(!que.empty()){
				int v = que.front(); que.pop();
				vis[v] = true; con_id[v] = k; con.push_back(v);
				for(int u: G[v]) que.push(u);
			}
			cons.push_back(con);
			if(is_root[cycle[0]]) cycle.clear();	// 木の場合は cycles[k] = empty
			cycles.push_back(cycle);
		}
	}
};