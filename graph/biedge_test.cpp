#include <bits/stdc++.h>
#define chmin(x,y) x=min(x,y)
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define show(x) cout<<#x<<" "<<x<<endl
using namespace std;
const int MAX_V=100;
//二重辺連結成分分解
//biedge connected component
//bsにbridge,ccに二重連結成分が入る
typedef vector<int> vi;
typedef pair<int,int> P;
vector<int> G[MAX_V];
int ord[MAX_V];
bool inS[MAX_V];
stack<int> roots,S;
vector<vi> cc;
vector<P> bs;
int cnt;
int N,M;

int cmp[MAX_V];
vector<int> cG[MAX_V];

void vis(int v,int p){
	ord[v]=++cnt;
	S.push(v);
	inS[v]=true;
	roots.push(v);
	for(int u:G[v]){
		if(ord[u]==0){
			vis(u,v);
		}else if(u!=p&&inS[u]){
			while(ord[roots.top()]>ord[u]) roots.pop();
		}
	}
	if(v==roots.top()){
		bs.pb(P(p,v));
		vector<int> vc;
		while(true){
			int w=S.top();S.pop();
			inS[w]=false;
			vc.pb(w);
			cmp[w]=cc.size();
			if(v==w) break;
		}
		roots.pop();
		cc.pb(vc);
	}
}
void bridge(){
	rep(i,N) if(ord[i]==0){
		vis(i,-1);
		bs.pop_back();	//P(-1,hoge)
	}
	for(P p:bs){
		int x=cmp[p.first],y=cmp[p.second];
		cG[x].pb(y),cG[y].pb(x);
	}
}
int main(){
	cin>>N>>M;
	rep(i,M){
		int a,b;
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	bridge();
	show(cc.size());
	rep(i,cc.size()){
		printf("No.%d   ",i);
		rep(j,cc[i].size()) cout<<cc[i][j]<<" ";
		puts("");
	}
	rep(i,bs.size()){
		cout<<"("<<bs[i].first<<","<<bs[i].second<<")"<<endl;
	}
	rep(i,cc.size()){
		printf("i=%d   ",i);
		for(int u:cG[i]) cout<<u<<" ";
		puts("");
	}
}