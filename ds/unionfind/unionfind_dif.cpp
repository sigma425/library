template<class D>
struct UnionFindWithDiff{
	vector<int> par;
	vector<D> d;

	UnionFindWithDiff(){}
	UnionFindWithDiff(int N):par(N),d(N){
		for(int i=0;i<N;i++) par[i] = i;
	}

	int find(int x){
		if(x == par[x]) return x;
		int r = find(par[x]);
		d[x] += d[par[x]];
		return par[x] = r;
	}
	/*
		w[x] - w[y] = z という条件を追加
		破綻したら false を返す
	*/
	bool unite(int x, int y, D z){
		int rx = find(x), ry = find(y);
		if(rx == ry){
			if(diff(x,y) != z) return false;
			return true;
		}
		d[ry] = d[x] - d[y] - z;
		par[ry] = rx;
		return true;
	}
	/*
		w[x] - w[y] を返す
		不定の場合は未定義、不定かどうかの判定が必要なら same でしておく
	*/
	D diff(int x, int y){
		find(x), find(y);
		return d[x] - d[y];
	}
	bool same(int x, int y) { return find(x)==find(y); }
};