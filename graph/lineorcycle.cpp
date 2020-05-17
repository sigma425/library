template<class E>
void solve(const VV<int>& G){
	int N = G.size();
	auto do_isolated = [&](int v){

	};
	auto do_line = [&](V<int> vs){

	};
	auto do_cycle = [&](V<int> vs){

	};
	V<bool> used(N);
	rep(i,N) if(!used[i]){
		assert(si(G[i])<=2);
		if(si(G[i]) == 0){
			do_isolated(i);
			used[i] = true;
			continue;
		}
		int v = i;
		int p = G[v][0];
		while(si(G[v]) == 2){
			int nv = G[v][0]^G[v][1]^p;
			p = v; v = nv;
			if(v == i) break;
		}
		if(si(G[v]) == 1){	//line
			vector<int> vs;
			vs.pb(v); used[v]=1;
			int p = v;
			v = G[v][0];
			while(si(G[v]) == 2){
				vs.pb(v); used[v]=1;
				int nv = G[v][0]^G[v][1]^p;
				p = v; v = nv;
			}
			vs.pb(v);used[v]=1;
			do_line(vs);
		}else{				//cycle
			vector<int> vs;
			int p = G[v][0];
			while(!used[v]){
				vs.pb(v);used[v]=1;
				int nv = G[v][0]^G[v][1]^p;
				p = v; v = nv;
			}
			do_cycle(vs);
		}
	}
}
