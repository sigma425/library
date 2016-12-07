/*
押し戻せる系 クエリが多いならdinicよりこっちのが多分はやい
!!! dfsの前にusedを0にすること !!!
*/
const int MAX_V=,inf=;
map<int,int> G[MAX_V];
bool used[MAX_V];
void add_edge(int from, int to, int cap){
	G[from][to]=G[to][from]=cap;
}
void erase_edge(int from,int to){
	G[from].erase(to);
	G[to].erase(from);
}
int dfs(int v,int t,int f){
	if(v==t) return f;
	used[v]=true;
	for(auto &e:G[v]){
		if(!used[e.fs] && e.sc>0){
			int d=dfs(e.fs,t,min(f,e.sc));
			if(d>0){
				e.sc-=d;
				G[e.fs][v]+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t){
	int flow=0;
	while(true){
		memset(used,0,sizeof(used));
		int f=dfs(s,t,inf);
		if(f==0) return flow;
		flow+=f;
	}
}