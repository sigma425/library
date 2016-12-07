const int MAX_V=;
int V;				//substitute!!
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];
void add_edge(int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
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
int nibu(){
	int res=0;
	memset(match,-1,sizeof(match));
	rep(v,V){
		if(match[v]<0){
			memset(used,0,sizeof(used));
			if(dfs(v)) res++;
		}
	}
	return res;
}