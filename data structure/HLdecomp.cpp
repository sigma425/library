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

template<class segtree>	//simple or lazy
struct HLdecomp{
	const bool OnEdge;		//値が辺にある	!!未実装!!
	const bool OnVertex;	//値が頂点にある

	const bool canflip;		//a*b*..*c*d -> d*c*..*b*a が簡単に計算できるか(出来ない場合はのぼりとくだり両方持つ(!!未実装!!))

	vector<vector<int>> G;
	using P = pair<int,int>;
	vector<P> id;				//id[v] = P(chain_id,pos_on_chain)
	vector<int> sz;				//sz[v] = subtree_size
	vector<int> dep;
	vector<int> top;			//chains[v]の
	vector<segtree> chains;


	HLdecomp(const vector<vector<int>>& G, int r = 0, bool e = false, bool v = true):G(G),OnEdge(e),OnVertex(v){
		int N = G.size();
		id.assign(N,P(0,0));
		sz.assign(N,0);
		dep.assign(N,0);
		dfs_base(r);

	}
	void dfs_base(int v,int p=-1){
		sz[v]=1;
		if(p==-1) dep[v] = 0;
		else dep[v] = dep[p] + 1;
		for(const auto& e:G[v]){
			int u = e.to;
			if(u==p) continue;
			dfs_base(u,v);
			sz[v] += sz[u];
		}
	}
	int lca(int a,int b){
		while(id[a].fs != id[b].fs){

		}
	}
}

int main(){
	
}
