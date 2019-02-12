/*
	重心分解
	log 段で終わる、各段で全体でO(N)かけてもいいので、今見てる部分木の頂点を全探索する、とかは可能
	基本操作として enumeratePaths : 今見てる木の centroid r からの(dist,v) を列挙

	例1. 距離Kのペアはいくつ?
	例2. クエリ v_i と距離 d_i な頂点の個数は? (https://beta.atcoder.jp/contests/yahoo-procon2018-final/tasks/yahoo_procon2018_final_c)
	例3. camypaper のやつ(問題忘れた) https://beta.atcoder.jp/contests/ddcc2016-qual/tasks/ddcc_2016_qual_d
	例4. camp/6/1/K d(a,b)=d(b,c)=d(c,a) なる a,b,c の個数 これはenumeratePathsもいじる必要がある
*/

template<class E>
struct CentroidDecomposition{

	using D = ll;	//type of length of the longest path

	int N;
	VV<E> G;
	V<bool> centroid;
	V<int> sz;

	CentroidDecomposition(const VV<E>& _G):G(_G){
		N = (int)G.size();
		centroid = V<bool>(N,false);
		sz = V<int>(N,0);
	}

	int computeSubtreeSize(int v,int p){
		sz[v] = 1;
		for(const auto& e: G[v]){
			int u = e.to;
			if(u==p || centroid[u]) continue;
			sz[v] += computeSubtreeSize(u,v);
		}
		return sz[v];
	}
	pair<int,int> searchCentroid(int v,int p,int t){	
		pair<int,int> res(1e9,-1);
		int s=1,m=0;
		for(const auto& e: G[v]){
			int u = e.to;
			if(u==p || centroid[u]) continue;
			chmin(res,searchCentroid(u,v,t));
			chmax(m,sz[u]);
			s += sz[u];
		}
		chmax(m,t-s);
		chmin(res,(pair<int,int>(m,v)));
		return res;
	}

	void enumeratePaths(int v, int p, D d, vector<pair<D,int>>& dvs){
		dvs.pb(pair<D,int>(d,v));
		for(const auto& e: G[v]){
			int u = e.to;
			if(u==p || centroid[u]) continue;
			enumeratePaths(u,v,d+e.dist,dvs);	//unweighted: d+1
		}
	}

	/*
		今vを含む部分木内でcentroid s を探して解く
	*/

	void dfs(int v){
		computeSubtreeSize(v,-1);
		int r = searchCentroid(v,-1,sz[v]).sc;
		centroid[r]=true;

		for(auto e: G[r]){
			int u = e.to;
			if(centroid[u]) continue;
			dfs(u);
		}
		
		//solve subproblem here
		vector<pair<D,int>> dvs;	// s からの距離の集合(s含む)
		dvs.pb(pair<D,int>(0,r));
		map<int,int> cnt;
		cnt[0]++;

		for(auto e: G[r]){
			int u = e.to;
			if(centroid[u]) continue;
			vector<pair<D,int>> _dvs;	//各 r の子 u だけ考えた時の dvs だいたいds^2 - \sigma _ds^2 みたいな感じでペア計算する
			enumeratePaths(u,r,e.dist,_dvs);
			
			// map<int,int> _cnt;
			// for(auto dv: _dvs){
			// 	_cnt[dv.fs]++;
			// 	cnt[dv.fs]++;
			// }
			// for(auto dv: _dvs){
			// 	int v = dv.sc;
			// 	int d = dv.fs;
			// 	for(auto query: v2qs[v]){
			// 		int q = query.fs;
			// 		int k = query.sc;
			// 		ans[q] -= _cnt[k-d];
			// 	}
			// }

			dvs.insert(dvs.end(),all(_dvs));
		}

		// for(auto dv: dvs){
		// 	int v = dv.sc;
		// 	int d = dv.fs;
		// 	for(auto query: v2qs[v]){
		// 		int q = query.fs;
		// 		int k = query.sc;
		// 		ans[q] += cnt[k-d];
		// 	}
		// }

		centroid[r]=false;
	}

	VV<pair<int,int>> v2qs;	//id,dist
	V<int> ans;

	void solve(int Q){
		v2qs.resize(N);
		ans.resize(Q);
		rep(q,Q){
			int v,k;
			cin>>v>>k;
			v--;
			v2qs[v].pb(pair<int,int>(q,k));
		}
		dfs(0);
		rep(q,Q) cout << ans[q] << endl;
	}
};

struct edge{
	int to;
	static const int dist = 1;
};

int main(){
	int N,Q;
	cin >> N >> Q;
	VV<edge> G(N);
	rep(i,N-1){
		int x,y;
		cin>>x>>y;
		x--,y--;
		G[x].pb({y});
		G[y].pb({x});
	}
	CentroidDecomposition<edge> CD(G);
	CD.solve(Q);
}
