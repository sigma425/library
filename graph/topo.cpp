/*
self loopも not dag
visを0で初期化して,Gを作って、maketopo(頂点数)すると
topo[i]=i番目の頂点 になる
*/

bool visit(int v,const vector<vector<int>>& G, vector<int>& topo, vector<int>& vis){
	if(vis[v]==2) return 1;
	if(vis[v]==1) return 0;
	vis[v]=1;
	for(int u:G[v]) if(!visit(u,G,topo,vis)) return 0;
	vis[v]=2;
	topo.pb(v);
	return 1;
}
vector<int> maketopo(const vector<vector<int>>& G){
	int N = G.size();
	vector<int> topo;
	vector<int> vis(N);
	rep(i,N) if(!visit(i,G,topo,vis)) return {};
	reverse(all(topo));
	return topo;
}
