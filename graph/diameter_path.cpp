// 木の直径のpathを返す
// verify: hitachi2020/F.cpp

V<int> getPath(const VV<int>& G){
	int N = si(G);
	V<int> d(N),par(N);
	auto dfs = [&](auto self,int v,int p)->void{
		if(p == -1) d[v] = 0, par[v] = -1;
		for(int u: G[v]) if(u != p){
			d[u] = d[v]+1, par[u] = v;
			self(self,u,v);
		}
	};
	dfs(dfs,0,-1);
	int s = max_element(all(d)) - d.begin();
	dfs(dfs,s,-1);
	int t = max_element(all(d)) - d.begin();
	V<int> path;
	while(t != s){
		path.pb(t);
		t = par[t];
	}
	path.pb(s);
	return path;
};