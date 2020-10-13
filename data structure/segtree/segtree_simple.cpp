template<class D>
struct segtree{
	int N;
	vector<D> val;

	segtree(){}
	segtree(int n){
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,D());
	}
	segtree(const vector<D>& ds){
		int n = ds.size();
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,D());
		rep(i,n) val[i+N] = ds[i];
		for(int i=N-1;i>0;i--) val[i] = op(val[i*2],val[i*2+1]);
	}
	void assign(int k,D d){
		k+=N;
		val[k]=d;
		k/=2;
		while(k){
			val[k] = op(val[k*2],val[k*2+1]);
			k/=2;
		}
	}
	D query(int a,int b){		//non-commutative & unrecursive
		D L = D() , R = D();
		a+=N,b+=N;
		while(a<b){
			if(a&1) L = op(L,val[a++]);
			if(b&1) R = op(val[--b],R);
			a/=2,b/=2;
		}
		return op(L,R);
	}
};

struct D{
	int s=0;
	D(){} // should be unit
	D(int s_):s(s_){}
	static D op(const D& x,const D& y){
		D z;
		z.s = x.s + y.s;
	}
//	friend ostream& operator<<(ostream& o,const D& d){return o<<d.s;}
};
