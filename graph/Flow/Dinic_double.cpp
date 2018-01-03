struct edge {
	int to;
	D cap;
	int rev;
	edge(int to,D cap,int rev) :to(to),cap(cap),rev(rev){}
};
const int MAX_V=;
const D inf=,eps=;
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];
void add_edge(int from, int to, D cap){
	edge e1(to,cap,G[to].size()),e2(from,0,G[from].size());
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
			if(e.cap>eps && level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}
D dfs(int v,int t,D f){
	if(v==t) return f;
	for(int &i=iter[v];i<G[v].size();i++){
		edge &e=G[v][i];
		if(e.cap>eps && level[v]<level[e.to]){
			D d=dfs(e.to,t,min(f,e.cap));
			if(d>eps){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
D max_flow(int s,int t){
	D flow=0;
	while(true){
		bfs(s);
		if(level[t]<0) return flow;
		memset(iter,0,sizeof(iter));
		D f;
		while( (f=dfs(s,t,inf))>eps ) flow+=f;
	}
}