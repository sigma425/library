/*
lca(u,v)をクエリO(logN)で求める
前処理O(NlogN)
pとdepthがうまってれば一個目のgenlcaだけでいいけど,一般にグラフGがある状況だと
下のdfs+genlcaしなきゃダメ

pathに分解するときは[u,z) + [v,z) + z みたいにするか, 片方を閉区間にする(depth-1持ち上げる)とok

*/
const int MAX_V=;
const int LOGV=;
int par[MAX_V][LOGV],depth[MAX_V];
void dfs(int v,int p){
	if(p<0) depth[v]=0;
	else depth[v]=depth[p]+1;
	par[v][0]=p;
	for(int u:G[v]){
		if(u!=p) dfs(u,v);
	}
}
void genlca(){
	dfs(0,-1);
	for(int i=1;i<LOGV;i++){
		rep(v,N){
			if(par[v][i-1]==-1) par[v][i]=-1;
			else par[v][i]=par[par[v][i-1]][i-1];
		}
	}
}
int lca(int u,int v){
	if(depth[u]<depth[v]){
		swap(u,v);
	}
	int d=depth[u]-depth[v];
	rep(i,LOGV){
		if((d>>i)&1) u=par[u][i];
	}
	if(u==v) return u;
	for(int i=LOGV-1;i>=0;i--){
		if(par[u][i]!=par[v][i]){
			u=par[u][i];
			v=par[v][i];
		}
	}
	return par[v][0];
}