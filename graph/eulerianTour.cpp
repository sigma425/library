/*
	有向グラフのオイラー閉路
	連結かどうかも判定
	空グラフを区別するため bool,V<int> を返している
	O(N+M)
*/
template<class E> pair<bool,V<int>> eulerianTour(const VV<E>& G){
	int N = G.size();
	int s = -1;
	rep(i,N) if(!G[i].empty()) s = i;
	if(s == -1){
		return make_pair(true,V<int>());
	}
	V<int> indeg(N),outdeg(N);
	rep(i,N) for(auto e: G[i]){
		int j = e.to;
		outdeg[i]++, indeg[j]++;
	}
	rep(i,N) if(indeg[i] != outdeg[i]){
		return make_pair(false,V<int>());
	}
	// using P = pair<int,int>;
	// map<int,P> mp;
	// rep(i,N) for(auto e: G[i]){
	// 	mp[e.id] = P(i,e.to);
	// }
	int M = 0;
	rep(i,N) M += G[i].size();
	V<int> it(N);
	V<int> euler;
	auto dfs = [&](auto&& self, int v) -> void {
		while(it[v] != si(G[v])){
			auto e = G[v][it[v]];
			it[v]++;
			self(self,e.to);
			euler.eb(e.id);
		}
	};
	dfs(dfs,s);
	reverse(all(euler));
	if(si(euler) != M) return make_pair(false,V<int>());
	// rep(i,M) assert(mp[euler[i]].sc == mp[euler[(i+1)%M]].fs);
	return make_pair(true,euler);
}

struct Edge{
	int to,id;
	Edge(int to_, int id_):to(to_),id(id_){}
};
