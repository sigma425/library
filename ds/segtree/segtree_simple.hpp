/*
	segtree
	point seg/add, range sum
*/
template<class D>
struct Segtree{
	int N;
	vector<D> val;

	Segtree(){}
	Segtree(int n){
		N = 1; while(N < n) N *= 2;
		val.assign(N*2, D());
	}
	template<class Dlike>
	Segtree(const vector<Dlike>& vs){
		int n = vs.size();
		N = 1; while(N < n) N *= 2;
		val.assign(N*2, D());
		rep(i,n) val[i+N] = vs[i];
		for(int i=N-1;i>0;i--) val[i] = D::op(val[i*2],val[i*2+1]);
	}
	void set(int k, D v){
		k += N;
		val[k] = v;
		k /= 2;
		while(k){
			val[k] = D::op(val[k*2],val[k*2+1]);
			k /= 2;
		}
	}
	void add(int k, D v){
		k += N;
		val[k] = D::op(val[k],v);
		k /= 2;
		while(k){
			val[k] = D::op(val[k*2],val[k*2+1]);
			k /= 2;
		}
	}
	D query(int a, int b){		//non-commutative & unrecursive
		D L = D() , R = D();
		a += N, b += N;
		while(a<b){
			if(a&1) L = D::op(L,val[a++]);
			if(b&1) R = D::op(val[--b],R);
			a /= 2, b /= 2;
		}
		return D::op(L,R);
	}
};

// struct D{
// 	int v;
// 	D(){ *this = e(); }
// 	D(int v_):v(v_){}
// 	static D op(const D& x,const D& y){
// 		return D(x.v+y.v);
// 	}
// 	const static D e(){
// 		return D(0);
// 	}
// //	friend ostream& operator<<(ostream& o,const D& d){return o<<d.v;}
// };
