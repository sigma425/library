/*
	無向グラフをdfsしたときに,各vに対しG[v]の中で親を一番最後に持ってくる
	rotateしてるので親以外の相対順序は変わらないけど、
	順序木(ex.二次元平面上に頂点があって,親方向から時計回りに子を見ていく必要がある) とかだと変えないとまずい
*/
namespace Normalize{
	template<class E>
	void dfs(vector<vector<E>>& G, int v,int p=-1){
		int K = G[v].size();
		rep(i,K){
			if(G[v][i].to==p){
				rotate(G[v].begin()+i,G[v].begin()+i+1,G[v].end());
			}else{
				dfs(G,G[v][i].to,v);
			}
		}
	}
	template<class E>
	void normalize(vector<vector<E>>& G, int r=0){
		dfs(G,r);
	}
}

struct edge{
	int to;
};
int main(){
	int N,M;
	cin>>N>>M;
	vector<vector<edge>> G(N);
	rep(i,M){
		int x,y;
		cin>>x>>y;
		G[x].pb(edge{y});
		G[y].pb(edge{x});
	}
	Normalize::normalize(G);
	rep(v,N){
		printf("G[%d]={",v);
		for(edge e:G[v]) printf("%d, ",e.to);
		printf("}\n");
	}
}