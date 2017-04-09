struct Bipartite_matching{
	int V;
	vector< vector<int> > G;
	vector<int> match;
	vector<bool> used;
	void init(int N){
		V=N;
		G.assign(V,vector<int>());
		match.assign(V,0);
		used.assign(V,false);
	}
	void add_edge(int v,int u){
		G[v].pb(u);
		G[u].pb(v);
	}
	bool dfs(int v){
		used[v]=true;
		rep(i,G[v].size()){
			int u=G[v][i],w=match[u];
			if(w<0 || (!used[w] && dfs(w))){
				match[v]=u;
				match[u]=v;
				return true;
			}
		}
		return false;
	}
	int max_matching(){
		int res=0;
		fill(all(match),-1);
		rep(v,V){
			if(match[v]<0){
				fill(all(used),false);
				if(dfs(v)) res++;
			}
		}
		return res;
	}
};