/*
	もうACL使いましょう
	https://codeforces.com/contest/1427/submission/95526148 これは流し戻しとかもやってる例
*/

/*
	Dinic
	infを書き換える
	初期化は頂点数
	max_flow(s,t) のあと calcCut(s,t) を呼ぶことで、which[v] = minCutで頂点vがS側 ? 0 : 1 を得られる
	verify: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1410
*/
template<class capType>
struct MaxFlow{
	using D = capType;
	const D inf = ;
	struct edge{
		int to;
		D cap;
		int rev;
		edge(int to_,D cap_,int rev_):to(to_),cap(cap_),rev(rev_){}
	};

	int N;
	vector<vector<edge>> G;
	vector<int> level,iter;

	MaxFlow(int N_):N(N_){
		G = vector<vector<edge>>(N);
		level = vector<int>(N);
		iter = vector<int>(N);
	}

	void add_edge(int from, int to, D cap){
		edge e1(to,cap,(int)G[to].size());
		edge e2(from,0,(int)G[from].size());
		G[from].push_back(e1);
		G[to].push_back(e2);
	}
	void bfs(int s){
		level = vector<int>(N,-1);

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
			iter = vector<int>(N,0);
			D f;
			while( (f=dfs(s,t,inf))>0 ) flow+=f;
		}
	}

	vector<int> calcCut(int s,int t){
		vector<int> which(N,-1);			// 0: S, 1: T
		auto dfs2 = [&](auto& self, int v) -> void{
			if(which[v] != -1) return;
			which[v] = 0;
			for(auto e: G[v]) if(e.cap>0) self(self,e.to);
		};
		dfs2(dfs2,s);
		rep(i,N) if(which[i] == -1) which[i] = 1;
		assert(which[t] == 1);
		return which;
	}
};