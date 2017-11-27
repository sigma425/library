/*
ただのunionfind
verified by いろんなところ
付加情報を持つときにuniteのcontinueを忘れないこと
*/
struct UnionFind{
	vector<int> par;
	UnionFind(int N){
		par.assign(N,0);
		rep(i,N) par[i]=i;
	}
	int find(int x){
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	void unite(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return;
		par[y]=x;
	}
};
struct UnionFind{
	vector<int> par,rank;
	UnionFind(int N){
		par.assign(N,0);
		rank.assign(N,0);
		rep(i,N) par[i]=i;
	}
	int find(int x){
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	void unite(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return;
		if(rank[x]<rank[y]) swap(x,y);

		//x becomes root
		par[y]=x;
		if(rank[x]==rank[y]) rank[x]++;
	}
};