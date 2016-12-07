/*
	v,w in V について,v dominates w ⇔ Dominator Treeにおいてvからwへのpathがある
	vの親をidom[v]として根付き木(dominator tree)を作ればdominate関係(r->wに行くとき必ずvを通るか)がすべてわかる
	verified by AOJ294
*/


#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
const int MAX_V=100000;

int par[MAX_V];				//unionfind用 縮約した森の親を持つ
int m[MAX_V];				//unionfind用 縮約森を辿った時に正しい答えになるようにする くわしくは前のblogを見て
							//今回は最小値そのものではなく,semiが最小になるような頂点を持っている(あんまり変わらない)

int I;			//dfsのときにidつける用
int parent[MAX_V];			//parent[v] = dfs木Tでのvの親
int vertex[MAX_V];			//vertex[i] = dfs順がi番目の頂点
int semi[MAX_V];			//semi[v] = v			if vに対しstep2が行われる前
							//			sdom(v)のnumber		otherwise
int U[MAX_V];				//U[w] = wに対する,step3で求めるCor1のu
int idom[MAX_V];			//idom[v] = idom(v) ほしいもの
vector<int> bucket[MAX_V];		//bucket[v] = 現時点での「sdom(x)=v」なるxの集合(のうちstep3が終わってないもの)
vector<int> G[MAX_V],rG[MAX_V];		//もとのグラフと,それの辺を逆にしたもの

//unionfindここから
void init(int N){
	rep(i,N) par[i]=i,m[i]=i;
}
int find(int v){
	if(par[v]==v) return v;
	int r=find(par[v]);
	if(semi[m[v]]>semi[m[par[v]]]) m[v]=m[par[v]];
	return par[v]=r;
}
int EVAL(int v){					//sdom最小 になる頂点を返す.sdomを返すわけではない!
	find(v);
	return m[v];
}
void LINK(int x,int y){
	par[y]=x;
}
//unionfindここまで

void dfs(int v){			//dfs木
	semi[v]=I;
	vertex[I++]=v;
	for(int u:G[v]) if(semi[u]<0){
		parent[u]=v;
		dfs(u);
	}
}
void makedomtree(int N,int r){
	init(N);
	rep(i,N) semi[i]=-1;
	dfs(r);									//step1
	for(int i=N-1;i>0;i--){
		//step2
		int w=vertex[i];
		for(int v:rG[w]){
			int u=EVAL(v);
			chmin(semi[w],semi[u]);
		}
		bucket[vertex[semi[w]]].pb(w);		//bucketの更新
		//ここからstep3
		for(int v:bucket[parent[w]]) U[v]=EVAL(v);
		bucket[parent[w]].clear();			//step3が終わったらbucketから消す
		LINK(parent[w],w);					//辺の追加
	}
	//step4
	for(int i=1;i<N;i++){
		int w=vertex[i];
		int u=U[w];
		if(semi[w]==semi[u]) idom[w]=semi[w];
		else idom[w]=idom[u];
	}

	for(int i=1;i<N;i++){				//idom[w]の中身をvertex idから名前に変える
		int w=vertex[i];
		idom[w]=vertex[idom[w]];
	}
	idom[r]=-1;
}
int main(){
	int N,M,r;
	cin>>N>>M>>r;
	rep(i,M){
		int a,b;
		cin>>a>>b;
		G[a].pb(b);
		rG[b].pb(a);
	}
	makedomtree(N,r);
}
