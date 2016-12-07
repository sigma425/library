/*
ただのunionfind
verified by いろんなところ
付加情報を持つときにuniteのcontinueを忘れないこと
*/
struct unionfind{
	int par[];
	void init(int N){rep(i,N) par[i]=i;}
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