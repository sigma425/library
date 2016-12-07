/*
biedge connected component
bsにbridge,ccに二重辺連結成分が入る
!!! 多重辺があるときはelse if(u!=p) のとこで u-pに多重辺があるなら戻っても良い
else if( (u!=p&&inS[u]) || (u==p&&mp[P(min(v,p),max(v,p)]>=2) )
mpはmultimapじゃなくてmap<P,int>
*/
typedef vector<int> vi;
typedef pair<int,int> P;
const int MN=;
vector<int> G[MN];
int ord[MN];
bool inS[MN];
stack<int> roots,S;
vector<vi> cc;
vector<P> bs;
int cnt;
/*
int cmp[MN];
vector<int> cG[MN];
*/
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
//			cmp[w]=cc.size();
			if(v==w) break;
		}
		roots.pop();
		cc.pb(vc);
	}
}
void bridge(int N){
	rep(i,N) if(ord[i]==0){
		vis(i,-1);
		bs.pop_back();	//P(-1,hoge)
	}
/*	for(P p:bs){
		int x=cmp[p.fs],y=cmp[p.sc];
		cG[x].pb(y),cG[y].pb(x);
	}*/
}