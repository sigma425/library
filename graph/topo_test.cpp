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
const int MAX_V=10;
int vis[MAX_V];		//0->yet,1->now,2->done
vector<int> topo;
vector<int> G[MAX_V];
bool visit(int v){
	if(vis[v]==2) return 1;
	if(vis[v]==1) return 0;
	vis[v]=1;
	for(int u:G[v]) if(!visit(u)) return 0;
	vis[v]=2;
	topo.pb(v);
	return 1;
}
bool maketopo(int V){
	rep(i,V) if(!visit(i)) return 0;
	reverse(all(topo));
	return 1;
}
int main(){
	int N,M;
	cin>>N>>M;
	rep(i,M){
		int a,b;
		cin>>a>>b;
		G[a].pb(b);
	}
	if(maketopo(N)){
		rep(i,N) cout<<topo[i]<<" ";
		puts("");
	}else{
		puts("not dag");
	}
}
