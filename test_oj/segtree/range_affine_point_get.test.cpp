#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include "template.hpp"
#include "ds/segtree/segtree_dual.hpp"
#include "math/mint.cpp"

struct A{
	// x -> ax + b
	mint a,b;
	A(){ *this = e(); }
	A(mint a_, mint b_):a(a_),b(b_){}
	// f*g: gやってf
	static A op(const A& f,const A& g){
		return A(f.a*g.a, f.b+f.a*g.b);
	}
	const static A e(){
		return A(1,0);
	}
	friend ostream& operator<<(ostream& o,const A& v){return o<<v.a<<"x+"<<v.b;}
};

int main(){
	int N,Q; cin >> N >> Q;
	V<mint> xs(N); rep(i,N) cin >> xs[i];
	SegtreeDual<A> seg(N);
	while(Q--){
		int t; cin >> t;
		if(t == 0){
			int l,r; mint a,b; cin >> l >> r >> a >> b;
			seg.apply(l,r,A(a,b));
		}else{
			int i; cin >> i;
			auto f = seg.get(i);
			cout << f.a * xs[i] + f.b << endl;
		}
	}
}