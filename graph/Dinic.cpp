struct edge {int to,cap,rev;};
const int MAX_V=,inf=;
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];
void init(int V){
	rep(i,V) G[i].clear();
}
void add_edge(int from, int to, int cap){
	edge e1={to,cap,G[to].size()},e2={from,0,G[from].size()};
	G[from].push_back(e1);
	G[to].push_back(e2);
}
void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();
		que.pop();
		for(int i=0;i<G[v].size();i++){
			edge &e=G[v][i];
			if(e.cap>0 && level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}
int dfs(int v,int t,int f){
	if(v==t) return f;
	for(int &i=iter[v];i<G[v].size();i++){
		edge &e=G[v][i];
		if(e.cap>0 && level[v]<level[e.to]){
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
		bfs(s);
		if(level[t]<0) return flow;
		memset(iter,0,sizeof(iter));
		int f;
		while( (f=dfs(s,t,inf))>0 ) flow+=f;
	}
}