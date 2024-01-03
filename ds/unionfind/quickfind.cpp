/*
quickfind
使うことあるかなあ
verified by どこか(忘れたけど何回か使ってる)
*/
struct quickfind{
	vector<int> i2g;
	vector<vector<int> > g2i;
	void init(int n){
		i2g.resize(n);
		g2i.resize(n);
		rep(i,n){
			i2g[i]=i;
			g2i[i].assign(1,i);
		}
	}
	void unite(int ia,int ib){
		if(g2i[i2g[ia]].size() < g2i[i2g[ib]].size()) swap(ia,ib);
		int ga=i2g[ia],gb=i2g[ib];
		for(auto v:g2i[gb]) i2g[i]=ga;
		g2i[ga].insert(g2i[ga].end(),all(g2i[gb]));
	}
	bool same(int ia,int ib){
		return i2g[ia]==i2g[ib];
	}
};