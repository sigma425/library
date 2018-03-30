/*
	木の重心分解
	基本機能として、重心 s を根とする考えるべき部分木での s からの距離を列挙する enumerate_paths がある
	この部分木をぜんぶなめても合計 O(NlogN) であることに注意

	例1. 距離Kのペアはいくつ?	
	例2. クエリ v_i と距離 d_i な頂点の個数は? (https://beta.atcoder.jp/contests/yahoo-procon2018-final/tasks/yahoo_procon2018_final_c)
	例3. camypaper のやつ(問題忘れた) https://beta.atcoder.jp/contests/ddcc2016-qual/tasks/ddcc_2016_qual_d
	例4. camp/6/1/K d(a,b)=d(b,c)=d(c,a) なる a,b,c の個数 これはenumerate_pathsもいじる必要がある
*/
struct edge{int to,;};
vector<vector<edge>> G;
vector<bool> centroid;
vector<int> subtree_size;

int compute_subtree_size(int v,int p){
	int c=1;
	rep(i,G[v].size()){
		int w=G[v][i].to;
		if(w==p || centroid[w]) continue;
		c+=compute_subtree_size(w,v);
	}
	subtree_size[v]=c;
	return c;
}
P search_centroid(int v,int p,int t){	
	P res=P(1e9,-1);
	int s=1,m=0;
	rep(i,G[v].size()){
		int w=G[v][i].to;
		if(w==p || centroid[w]) continue;
		res=min(res,search_centroid(w,v,t));
		m=max(m,subtree_size[w]);
		s+=subtree_size[w];
	}
	m=max(m,t-s);
	res=min(res,P(m,v));
	return res;
}
void enumerate_paths(int v,int p,ll d,vector<int>& ds,vector<int>& vs){
	ds.pb(d);
	vs.pb(v);
	rep(i,G[v].size()){
		int w=G[v][i].to;
		if(w==p || centroid[w]) continue;
		enumerate_paths(w,v,d+1,ds,vs);
	}
}
void solve_subproblem(int v){
	compute_subtree_size(v,-1);
	int s=search_centroid(v,-1,subtree_size[v]).sc;
	centroid[s]=true;

	for(auto e: G[s]){
		int u = e.to;
		if(centroid[u]) continue;
		solve_subproblem(u);
	}
	
	//solve subproblem here
	vector<int> ds;	// s からの距離の集合(s含む)
	vector<int> vs; // 対応する頂点
	ds.pb(0);
	vs.pb(s);
	for(auto e: G[s]){
		int child = e.to;
		if(centroid[child]) continue;
		vector<int> _ds,_vs;	//各 s の子 child だけ考えた時の ds,vs だいたいds^2 - \sigma _ds^2 みたいな感じでペア計算する
		enumerate_paths(u,s,1,_ds,_vs);
		//
		ds.insert(ds.end(),all(_ds));
		vs.insert(vs.end(),all(_vs));
	}
	//

	centroid[s]=false;
}

int main(){
	G = vector<vector<edge>>(N);
	centroid = vector<bool>(N);
	subtree_size = vector<int>(N);
	solve_subproblem(0);
}