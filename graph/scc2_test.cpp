#include <bits/stdc++.h>
#define chmin(x,y) x=min(x,y)
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define show(x) cout<<#x<<" "<<x<<endl
using namespace std;
const int MAX_V=100;
//scc
typedef vector<int> vi;
int ord[MAX_V],low[MAX_V];
bool inS[MAX_V];
vector<int> G[MAX_V];
stack<int> S;
int cnt;
vector<vi> scc;
int N,M;
void vis(int v){
	ord[v]=low[v]=++cnt;
	S.push(v);
	inS[v]=true;
	for(int u:G[v]){
		if(ord[u]==0){
			vis(u);
			chmin(low[v],low[u]);
		}else if(inS[u]){
			chmin(low[v],ord[u]);
		}
	}
	if(low[v]==ord[v]){
		vector<int> vc;
		while(true){
			int w=S.top();S.pop();
			inS[w]=false;
			vc.pb(w);
			if(v==w) break;
		}
		scc.pb(vc);
	}
}
void makescc(){
	rep(i,N) if(ord[i]==0) vis(i);
}
int main(){
	cin>>N>>M;
	rep(i,M){
		int a,b;
		cin>>a>>b;
		G[a].pb(b);
	}
	makescc();
	show(scc.size());
	rep(i,scc.size()){
		printf("No.%d   ",i);
		rep(j,scc[i].size()) cout<<scc[i][j]<<" ";
		puts("");
	}
}