int bsr(unsigned int x){
	if(x==0) return -1;
	return 31 ^ __builtin_clz(x);
}

struct SparseTable{
	using D = int;												//type
	VV<D> d;
	int lg;

	SparseTable(){}
	SparseTable(const vector<D>& v){
		int N = v.size();
		assert(N > 0);

		lg = bsr(N)+1;
		d.resize(lg);
		d[0] = v;
		for(int t=1;t<lg;t++){
			int len = 1<<t;
			d[t].resize(N-len+1);
			rep(i,N-len+1){
				d[t][i] = max(d[t-1][i] , d[t-1][i+len/2]);		//op
			}
		}
	}
	D query(int l, int r) const {
		if(l>=r) return -1;										//e
		int u = bsr(r-l);
		return max(d[u][l] , d[u][r-(1<<u)]);					//op
	}
};
