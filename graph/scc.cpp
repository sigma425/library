/*
    SCC O(M+N)
    id[v] = v の 連結成分の id
    groups[i] : i番目の連結成分, トポロジカル順
*/
template <class E>
struct SCC{
	V<int> id;
	VV<int> groups;

	int N;
	VV<E> G;
	V<int> ord,low;
	V<bool> inS;
	V<int> st;
    int I=0;

	void dfs(int v){
		ord[v] = low[v] = I;
		st.pb(v); inS[v] = true;
		for(auto e: G[v]){
			int u = e.to;
			if(ord[u] == -1){
				dfs(u);
				chmin(low[v],low[u]);
			}else if(inS[u]){
				chmin(low[v],ord[u]);
			}
		}
		if(low[v] == ord[v]){
			V<int> group;
			while(true){
				int w = st.back(); st.pop_back();
				inS[w] = false;
				group.pb(w);
				if(w == v) break;
			}
			groups.pb(group);
		}
	}
	SCC(const VV<E>& G_) : N(G_.size()), G(G_), ord(N,-1), low(N), inS(N){
        id = V<int>(N);
		rep(i,N) if(ord[i] == -1) dfs(i);
		reverse(all(groups));
		rep(i,groups.size()){
			for(int v: groups[i]) id[v] = i;
		}
	}
};