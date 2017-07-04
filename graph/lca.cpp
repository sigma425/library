/*
verified by AOJ GRL 5C

lca(u,v)をクエリO(logN)で求める
前処理O(NlogN)
pとdepthがうまってれば一個目のgenlcaだけでいいけど,一般にグラフGがある状況だと
下のdfs+genlcaしなきゃダメ

pathに分解するときは[u,z) + [v,z) + z みたいにするか, 片方を閉区間にする(depth-1持ち上げる)とok

*/

int bsr(int x){	//4~7 -> 2
	if(x==0) return -1;
	return 31 ^ __builtin_clz(x);
}
struct LCA{
	int N,n;
	vector<int> depth;
	vector<vector<int>> par;

	void dfs(int v,int p,const vector<vector<int>>& G){
		if(p<0) depth[v]=0;
		else depth[v]=depth[p]+1;
		par[v][0]=p;
		for(int u:G[v]){
			if(u!=p) dfs(u,v,G);
		}
	}

	LCA(const vector<vector<int>>& G){
		N = G.size();
		n = bsr(N);
		depth = vector<int>(N,0);
		par = vector<vector<int>>(N,vector<int>(n+1,0));

		dfs(0,-1,G);
		rep1(i,n){
			rep(v,N){
				if(par[v][i-1]==-1){
					par[v][i]=-1;
				}else{
					par[v][i]=par[par[v][i-1]][i-1];
				}
			}
		}
	}

	int lca(int u,int v){
		if(depth[u]<depth[v]){
			swap(u,v);
		}
		int d=depth[u]-depth[v];
		rep(i,n+1){
			if((d>>i)&1) u=par[u][i];
		}
		if(u==v) return u;
		for(int i=n;i>=0;i--){
			if(par[u][i]!=par[v][i]){
				u=par[u][i];
				v=par[v][i];
			}
		}
		return par[v][0];
	}

	int distance(int u,int v){
		return depth[u] + depth[v] - 2*depth[lca(u,v)];
	}
};