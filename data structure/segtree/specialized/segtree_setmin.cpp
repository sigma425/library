/*
	point val
	set range min
*/
struct segtree2{
	using D = int;
	D inf = 1e9;

	int N;
	vector<D> val;

	segtree2(){}
	segtree2(int n){
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,inf);
	}
	segtree2(const vector<D>& ds){
		int n = ds.size();
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,inf);
		rep(i,n) val[i+N] = ds[i];
		for(int i=N-1;i>0;i--) val[i] = min(val[i*2],val[i*2+1]);
	}
	D getval(int k){
		D res = inf;
		k+=N;
		while(k){
			chmin(res,val[k]);
			k/=2;
		}
		return res;
	}
	void changemin(int a,int b,D d){
		a+=N,b+=N;
		while(a<b){
			if(a&1){
				chmin(val[a],d);
				a++;
			}
			if(b&1){
				--b;
				chmin(val[b],d);
			}
			a/=2,b/=2;
		}
	}
};
