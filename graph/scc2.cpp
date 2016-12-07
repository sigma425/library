/*scc
vector<vi> sccにtopologycalの逆順に連結成分viが入る
SCC()でループの上限は頂点数
*/
typedef vector<int> vi;
vector<int> G[MAX_V];
int ord[MAX_V],low[MAX_V];
bool inS[MAX_V];
stack<int> S;
int cnt;
vector<vi> scc;
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
void SCC(){
	rep(i,) if(ord[i]==0) vis(i);
}