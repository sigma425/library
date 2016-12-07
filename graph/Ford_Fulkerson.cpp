struct edge {int to,cap,rev;};
const int MAX_V=,INF=;
vector<edge> G[MAX_V];
bool used[MAX_V];
void add_edge(int from, int to, int cap){
	//directed
	edge e1={to,cap,G[to].size()};
	edge e2={from,0,G[from].size()};
	G[from].push_back(e1);
	G[to].push_back(e2);
}
int dfs(int v,int t,int f){
	if(v==t) return f;
	used[v]=true;
	for(int i=0;i<G[v].size();i++){
		edge &e=G[v][i];
		if(!used[e.to] && e.cap>0){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
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
		int f=dfs(s,t,INF);
		if(f==0) return flow;
		flow+=f;
	}
}
int main(){