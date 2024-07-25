/*
	Project Selection Problem, いわゆる燃やす埋める
	x:true かつ y:false ならコストがかかる という問題が解ける
	一般には 適切に変数をflipすることで↑の関係が二部グラフならOK
	このライブラリではflipは気にせずに使える。最後にbipartiteじゃなかったらassertしてる
	V<bool> sol(N) に復元もしてある

	変数の数で初期化
	 - addCost(int id, bool f, D cost): 変数 id が f だと コスト cost
	 	cost < 0 でもよい
	 - addCost2(int x,bool fx, int y,bool fy, D cost): 変数 x が fx で 変数 y が fy だと コスト cost
	 	cost >= 0 でないとダメ
	
	一般化について:
		面倒だからやってないけどほんとは値が負とかではなくちゃんとした条件があり、 一般にk値で、i が p で j が q のときのコスト f_{i,j}(p,q) が 劣モならよい 
		cf: https://noshi91.hatenablog.com/entry/2021/06/29/044225

	verify:
		https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1410
		http://pjselection.com/
*/
template<class capType>
struct MaxFlow{
	using D = capType;
	const D inf = 1e9;
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
		auto dfs2 = [&](auto& self, int v) -> void {
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
struct UnionFind{
	vector<int> par;
	UnionFind(int N){
		par.assign(N,0);
		rep(i,N) par[i]=i;
	}
	int find(int x){
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	void unite(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return;
		par[y]=x;
	}
};
template<class costType>
struct ProjectSelection{
	using D = costType;
	int N;
	vector<D> trueCost, falseCost;
	MaxFlow<D> MF;
	UnionFind UF;
	vector<bool> sol;

	ProjectSelection(int varnum):N(varnum), trueCost(N), falseCost(N), MF(N+2), UF(N+N), sol(N){
	}
	void addCost(int id, bool f, D cost){		// ok for cost < 0
		assert(0 <= id && id < N);
		(f ? trueCost : falseCost)[id] += cost;
	}
	struct Waf{
		int x;bool fx;int y;bool fy;D cost;
	};
	vector<Waf> memo;
	void addCost2(int x,bool fx, int y,bool fy, D cost){
		// x:fx  and  y:fy  =>  ans += cost
		assert(0 <= x && x < N); assert(0 <= y && y < N);
		if(fx == fy) UF.unite(x,y+N), UF.unite(y,x+N);
		else UF.unite(x,y), UF.unite(x+N,y+N);
		memo.push_back({x,fx,y,fy,cost});
	}
	D minCost(){
		bool isBipartite = true;
		rep(i,N) if(UF.same(i,i+N)) isBipartite = false;
		assert(isBipartite);
		V<int> which(N,-1);		// which[i] = 0 <=> i:true iff i: left(S) side <=> i:true iff cut off i->T
		rep(i,N){
			int r1 = UF.find(i), r2 = UF.find(i+N);
			which[i] = (r1 < r2 ? 0 : 1);
		}
		int S = N, T = N+1;
		D off = 0;
		rep(i,N){
			D mn = min(trueCost[i], falseCost[i]);
			trueCost[i] -= mn, falseCost[i] -= mn;
			off += mn;
			if(which[i] == 0){
				MF.add_edge(i,T,trueCost[i]);
				MF.add_edge(S,i,falseCost[i]);
			}else{
				MF.add_edge(i,T,falseCost[i]);
				MF.add_edge(S,i,trueCost[i]);
			}
		}
		for(auto e: memo){
			bool xisS = (e.fx ^ which[e.x]);
			bool yisS = (e.fy ^ which[e.y]);
			assert(xisS != yisS);
			if(xisS) MF.add_edge(e.x,e.y,e.cost);
			else MF.add_edge(e.y,e.x,e.cost);
		}
		D flow = MF.max_flow(S,T) + off;
		auto isT = MF.calcCut(S,T);
		rep(i,N) sol[i] = !(isT[i] ^ which[i]);
		return flow;
	}
};