/*
add_edgeでグラフを作る
cmpにnew idが入る
0,1,2...がtopological order
*/
const int MAX_V=;
vector<int> G[MAX_V],rG[MAX_V],vs;
bool used[MAX_V];
int cmp[MAX_V];
void add_edge(int from,int to){
	G[from].push_back(to);
	rG[to].push_back(from);
}
void dfs(int v){
	used[v]=true;
	rep(i,G[v].size()){
		if(!used[G[v][i]]) dfs(G[v][i]);
	}
	vs.push_back(v);
}
void rdfs(int v,int k){
	used[v]=true;
	cmp[v]=k;
	rep(i,rG[v].size()){
		if(!used[rG[v][i]]) rdfs(rG[v][i],k);
	}
}
vector<int> cG[MAX_V];
int scc(int N){
	memset(used,0,sizeof(used));
	vs.clear();
	rep(v,N) if(!used[v]) dfs(v);
	memset(used,0,sizeof(used));
	int k=0;
	for(int i=vs.size()-1;i>=0;i--){
		if(!used[vs[i]]) rdfs(vs[i],k++);
	}
	//compressed Graphを作るときはON
	rep(i,N) for(int j:G[i]){
		if(cmp[i]!=cmp[j]) cG[cmp[i]].pb(cmp[j]);
	}
	rep(i,K) sort(all(cG[i])),cG[i].erase(unique(all(cG[i])),cG[i].end());
	return k;
}