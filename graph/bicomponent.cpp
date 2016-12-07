/*
二重連結成分分解 各成分はどの頂点を消しても連結なままになるような極大なもの
同じ成分⇔その二辺を含むサイクルがある
biedgesに辺集合たちが入る
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

typedef pair<int,int> P;
const int MV=100000;
vector<int> G[MV];
int ord[MV],low[MV];
int I;

stack<P> st;
typedef vector<P> VP;
vector<VP> biedges;

void dfs(int v,int p){
	ord[v]=++I;
	low[v]=ord[v];
	for(int u:G[v]) if(u!=p){
		if(ord[u]<ord[v]) st.push(P(v,u));
		if(ord[u]) chmin(low[v],ord[u]);	//back edge
		else{
			dfs(u,v);
			chmin(low[v],low[u]);

			if(low[u]>=ord[v]){
				vector<P> vp;
				while(true){
					P p=st.top();st.pop();
					vp.pb(p);
					if(p.fs==v && p.sc==u) break;
				}
				biedges.pb(vp);
			}
		}
	}
}
void arti(int N){
	rep(i,N) if(ord[i]==0){
		while(!st.empty()) st.pop();
		dfs(i,-1);
	}
}


int N,M,K;

int main(){
	precalc();
	cin>>N>>M>>K;
	rep(i,M){
		int a,b;
		cin>>a>>b;
		a--,b--;
		G[a].pb(b);
		G[b].pb(a);
	}
	arti(N);

	for(VP& vp : biedges){
		set<int> st;
		for(P p : vp){
			st.insert(p.fs);
			st.insert(p.sc);
		}
		int n=st.size(),m=vp.size();
		if(n==1){
			assert(m==0);
		}else if(n==m){	//cycle
		}else{		//free
			assert(n<m);
		}
	}
	cout<<ans<<endl;
}
