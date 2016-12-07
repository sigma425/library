/*
	not verified
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
vector<int> cyc;
bool vis[200000],done;
bool visit(int v,int p){
	if(vis[v]){
		cyc.pb(v);
		return 1;
	}
	vis[v]=1;
	for(int u:G[v]) if(u!=p){
		if(dfs(u,v)){
			if(u==cyc[0]) done=1;
			if(!done) cyc.pb(u);
			return 1;
		}
	}
	return 0;
}
int main(){
	
}
