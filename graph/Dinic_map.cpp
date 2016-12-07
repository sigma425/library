//押し戻しとかやるときに辺をeraseできるようにしたもの
//map[s][t]にedgeの情報(普通capだけ)がある
//Dinicを元にしている
///!!! 押し戻す or 再度流すときにbfs(始点)のあとにdfsをすること(このためちょっと遅い) !!!
const int MAX_V=,inf=;
map<int,int> G[MAX_V];
int level[MAX_V];
map<int,int>::iterator iter[MAX_V];
void add_edge(int from, int to, int cap){
	G[from][to]=G[to][from]=cap;
}
void erase_edge(int from, int to){
	G[from].erase(to);
	G[to].erase(from);
}
void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();
		que.pop();
		for(auto e:G[v]){
			if(e.sc>0 && level[e.fs]<0){
				level[e.fs]=level[v]+1;
				que.push(e.fs);
			}
		}
	}
}
int dfs(int v,int t,int f){
	if(v==t) return f;
	for(;iter[v]!=G[v].end();iter[v]++){
		int u=iter[v]->fs;
		if(G[v][u]>0 && level[v]<level[u]){
			int d=dfs(u,t,min(f,G[v][u]));
			if(d>0){
				G[v][u]-=d;
				G[u][v]+=d;
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
		rep(i,MAX_V) iter[i]=G[i].begin();
		int f;
		while( (f=dfs(s,t,inf))>0 ) flow+=f;
	}
}