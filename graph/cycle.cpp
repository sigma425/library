/*
	(directed/undirected)サイクル検出
	ひとつ見つけてそれを返す ない場合{}
	自己loopがある場合それを返してしまう(長さ1のサイクルを返す) ← 適当に変えられる
	多重辺があっても無視する(長さ2のサイクルは返さない) ← pじゃなくてedge id で保存すると回避できる
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
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}

const int MN = 100000;
vector<int> G[MN];
bool dfsc(int v, int p, vector<int>& vis, vector<int>& cyc, bool& done){
	if(vis[v]==1){
		cyc.pb(v);
		return 1;
	}
	if(vis[v]==2) return 0;

	vis[v] = 1;
	for(int u:G[v]) if(u!=p){
		if(dfsc(u,v,vis,cyc,done)){
			if(v==cyc[0]) done=1;
			if(!done) cyc.pb(v);
			return 1;
		}
	}
	vis[v] = 2;
	return 0;
}
vector<int> getcycle(int N){
	vector<int> vis(N,0);	//0:yet 1:now 2:done
	bool done = 0;
	vector<int> cyc;
	rep(i,N) if(vis[i]==0){
		if(dfsc(i,-1,vis,cyc,done)){
			reverse(all(cyc));
			return cyc;
		}
	}
	return {};
}

void unittest(){
	// vector<int> as = {2,3,2,4,2,6,2};
	// vector<int> bs = {6,4,3,2,1,5,5};
	// vector<int> as = {2};
	// vector<int> bs = {1};
	vector<int> as = {1,3,4,5,6,7,8,9};
	vector<int> bs = {2,1,3,6,7,8,5,8};
	rep(i,as.size()){
		G[as[i]].pb(bs[i]);
//		G[bs[i]].pb(as[i]);
	}

	vector<int> cyc = getcycle(7);
	show(cyc);
}

int main(){
	unittest();
}
