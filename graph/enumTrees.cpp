/*
	unlabeled rooted trees with N vertices
	https://oeis.org/A000081
		f(10) = 719, f(15) = 87811, f(20) = 12826228
		n = 20 で 7s くらい
	辺の端点は根に近いほうが値が小さい 特に、根は常に0
*/
VV<P> enumUnlabeledRootedTrees(int N){
	using P = pair<int,int>;
	V<V<V<P>>> ts(N+1);
	rep1(n,N){
		V<V<V<P>>> sub(n+1); sub[1].pb(V<P>());
		rep1(m,n-1) for(auto t: ts[m]){
			per1(i,n-m){
				for(auto f: sub[i]){
					V<P> nf = f;
					for(int ni=i+m;ni<=n;ni+=m){
						int off = ni-m;
						for(auto& [x,y]: t) nf.eb(x+off,y+off);
						nf.eb(0,off);
						sub[ni].pb(nf);
					}
				}
			}
		}
		ts[n] = sub[n];
		// show("-------------"); show(n);
		// show(si(ts[n]));
		// for(auto t: ts[n]) cout << t << endl;
	}
	return ts[n];
}


/*
	labeled unrooted trees with N vertices
	f(N) = N^{N-2} N = 9 くらいで限界
*/
V<VV<int>> enumTrees(int N){
	assert(N >= 1);
	V<VV<int>> trees;
	if(N == 1){
		VV<int> T(N);
		trees.pb(T);
		return trees;
	}
	V<int> prufer(N-2);
	auto dfs = [&](auto self,int t) -> void {
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

