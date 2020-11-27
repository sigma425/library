
// labeled unrooted N^{N-2}
// N = 1..9 くらいで限界 手元実験用かな?
// unlabeledはもっと少ないから、別に用意したいという気持ちはある
V<VV<int>> enumTrees(int N){
	assert(N >= 1);
	V<VV<int>> trees;
	if(N == 1){
		VV<int> T(N);
		trees.pb(T);
		return trees;
	}
	V<int> prufer(N-2);
	auto dfs = [&](auto self,int t)->void{
		if(t == N-2){
			VV<int> T(N);
			V<int> deg(N,1);
			for(int v: prufer) deg[v]++;
			rep(k,N-2){
				rep(v,N) if(deg[v] == 1){
					T[v].pb(prufer[k]);
					T[prufer[k]].pb(v);
					deg[v]--; deg[prufer[k]]--;
					break;
				}
			}
			V<int> vs;
			rep(v,N) if(deg[v]) vs.pb(v);
			assert(si(vs) == 2);
			T[vs[0]].pb(vs[1]);
			T[vs[1]].pb(vs[0]);
			trees.pb(T);
			return;
		}
		rep(i,N){
			prufer[t] = i;
			self(self,t+1);
		}
	};
	dfs(dfs,0);
	return trees;
}