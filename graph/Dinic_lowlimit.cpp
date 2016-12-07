/*
	maxflowに,最小流量制約が加わったもの
	add_edgelim(from,to,lowcap,highcap)

	まず,S,Tを新たな頂点として追加する(!!!グローバルにあるのでちゃんと代入すること!!!)
	そして,下限制約付きならadd_edgelimを使って張る.
	このあと,まずはt->s にINFを張って,そのあとS->Tにflowを流す.
	この時にsum 最小流量制限 以上流れればOK,流れなければ条件を満たすフローは存在しない.

	もう一度先ほど同様にグラフを再構築する.(G[i].clear()だけでOK)
	今度はS->s,t->TにINFを張って,S->Tに流す.
	この値-sum 最小流量制限 が元のグラフでのmax_flowである.

	動作原理は蟻本に少し間違って書いてある.

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

struct edge{int to,cap,rev;};
const int MAX_V=400;
int INF=1e9;
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];
void add_edge(int from,int to,int cap){
	G[from].pb((edge){to,cap,G[to].size()});
	G[to].pb((edge){from,0,G[from].size()-1});
}
int S,T;
void add_edgelim(int from,int to,int lowcap,int highcap){
	add_edge(S,to,lowcap);
	add_edge(from,T,lowcap);
	add_edge(from,to,highcap-lowcap);
}

void bfs(int s){
	memset(level, -1, sizeof(level));
	queue<int> que;
	level[s] = 0;
	que.push(s);
	while(!que.empty()){
		int v = que.front();
		que.pop();
		for(int i = 0; i < G[v].size(); ++i){
			edge &e = G[v][i];
			if(e.cap > 0 && level[e.to] < 0){
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}

int dfs(int v, int t, int f){
//	show(v);
	if(v == t) return f;
	for(int &i = iter[v]; i < G[v].size(); ++i){
		edge &e = G[v][i];
		if(e.cap > 0 && level[v] < level[e.to]){
			int d = dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap -=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t){
	int flow=0;
	for(;;){
		bfs(s);
		if(level[t]<0) return flow;
		memset(iter,0,sizeof(iter));
		int f;
		while((f=dfs(s,t,INF))>0){
			flow+=f;
		}
	}
}


class SRMDiv0Easy{
	public:
	int get(int N, vector <int> L, vector <int> R, vector <int> X, vector <int> Y){
		int Q=L.size();
		int s=0,t=N;
		S=N+1,T=N+2;
		int V=N+3;
		{
			rep(i,V) G[i].clear();
			int sum=0;
			rep(i,Q){
				add_edgelim(L[i],R[i]+1,X[i],Y[i]);
				sum+=X[i];
			}
			add_edge(t,s,INF);
			int tmp=max_flow(S,T);
			show(tmp);
			if(tmp<sum) return -1;
		}
		{
			rep(i,V) G[i].clear();
			int sum=0;
			rep(i,Q){
				add_edgelim(L[i],R[i]+1,X[i],Y[i]);
				sum+=X[i];
			}
			add_edge(S,s,INF);
			add_edge(t,T,INF);
			int tmp=max_flow(S,T);
			assert(tmp>=sum);
			return tmp-sum;
		}

	}
};
