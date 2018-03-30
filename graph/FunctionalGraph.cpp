/*
	FunctionalGraph の cycle列挙, 逆グラフ(サイクル辺除く)の構成

	verified at AGC008/E Next or Nextnext
*/

struct FunctionalGraph{
	//output
	vector<vector<int>> cycles;
	vector<vector<int>> G;	//a^-1 cycleの辺は除く


	vector<bool> vis;
	void setvis(int v){
		vis[v] = 1;
		for(int u:G[v]) setvis(u);
	}
	
	FunctionalGraph(vector<int> a){
		int N = a.size();
		vis.resize(N);
		G.resize(N);
		rep(i,N) G[a[i]].pb(i);
		rep(i,N) if(!vis[i]){
			int v = i;
			while(!vis[v]){
				vis[v] = 1;
				v = a[v];
			}
			vector<int> cycle;
			int s = v;
			do{
				cycle.pb(v);
				v = a[v];
			}while(v!=s);
			cycles.pb(cycle);

			int L = cycle.size();
			rep(j,L){
				int v = cycle[j];
				rep(k,G[a[v]].size()) if(G[a[v]][k] == v){
					G[a[v]].erase(G[a[v]].begin()+k);
					break;
				}
			}
			rep(j,L){
				int v = cycle[j];
				setvis(v);
			}
		}

	}
};
