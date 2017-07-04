/*
	- in のみ
	- in out のみ
	- 訪れるたび
	の3通り

	subtree	: inのみ で十分
	path	: in out
	lca		: 訪れるたび

	eulertour
	w=lca(a,b)として,2つのpathにわける.wa,wb,をやったあとwwを引くのも手.
	更新は add(v2id[w][0],v2id[a][0]+1,*) の形 +1に注意
	クエリも同様なんだけど,点クエリが勘違いしやすくて,ちゃんとval(v2id[v][0])-val(v2id[v][1]) と差分を取ること.

	verified by https://www.codechef.com/LTIME37/problems/TRAVTREE
*/
struct EulerTour{		//in + out version
	int I = 0;
	vector<int> id,in,out;

	EulerTour(const vector<vector<int>>& G, int r = 0){
		int N = G.size();
		id.assign(2*N,0);
		in.assign(N,0);
		out.assign(N,0);
		traverse(r,-1,G);
	}

	void traverse(int v,int p,const vector<vector<int>>& G){
		id[I]=v,in[v]=I,I++;
		for(int u:G[v]) if(u!=p) traverse(u,v,G);
		id[I]=v,out[v]=I,I++;
	}
};