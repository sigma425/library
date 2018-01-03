/*
	Dinic
	Dとinfを書き換える
	初期化は頂点数
*/
struct MaxFlow{
	using D = int;
	const D inf = 1e9;
	struct edge{
		int to;
		D cap;
		int rev;
		edge(int to,D cap,int rev):to(to),cap(cap),rev(rev){}
	};

	int V;
	vector<vector<edge>> G;
	vector<int> level,iter;

	MaxFlow(int V):V(V){
		G = vector<vector<edge>>(V);
		level = vector<int>(V);
		iter = vector<int>(V);
	}

	void add_edge(int from, int to, D cap){
		edge e1(to,cap,(int)G[to].size());
		edge e2(from,0,(int)G[from].size());
		G[from].push_back(e1);
		G[to].push_back(e2);
	}
	void bfs(int s){
		level = vector<int>(V,-1);

		queue<int> que;
		level[s]=0;
		que.push(s);
		while(!que.empty()){
			int v=que.front();
			que.pop();
			for(int i=0;i<(int)G[v].size();i++){
				edge &e=G[v][i];
				if(e.cap>0 && level[e.to]<0){
					level[e.to]=level[v]+1;
					que.push(e.to);
				}
			}
		}
	}
	D dfs(int v,int t,D f){
		if(v==t) return f;
		for(int &i=iter[v];i<(int)G[v].size();i++){
			edge &e=G[v][i];
			if(e.cap>0 && level[v]<level[e.to]){
				D d = dfs(e.to,t,min(f,e.cap));
				if(d>0){
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
			iter = vector<int>(V,0);
			D f;
			while( (f=dfs(s,t,inf))>0 ) flow+=f;
		}
	}
};
