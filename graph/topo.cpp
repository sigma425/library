/*
self loopも not dag
visを0で初期化して,Gを作って、maketopo(頂点数)すると
topo[i]=i番目の頂点 になる
*/

const int MAX_V=;
int vis[MAX_V];		//0->yet,1->now,2->done
vector<int> topo;
vector<int> G[MAX_V];
bool visit(int v){
	if(vis[v]==2) return 1;
	if(vis[v]==1) return 0;
	vis[v]=1;
	for(int u:G[v]) if(!visit(u)) return 0;
	vis[v]=2;
	topo.pb(v);
	return 1;
}
bool maketopo(int V){
	rep(i,V) if(!visit(i)) return 0;
	reverse(all(topo));
	return 1;
}
