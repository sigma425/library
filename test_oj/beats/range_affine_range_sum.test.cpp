/*
	これくらいなら当然 lazy で書いたほうがいいね (composition と apply を 2箇所に書く羽目になっている)
*/
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "template.hpp"
#include "ds/segtree/segbeats.hpp"
#include "math/mint.hpp"

struct D{
	// val
	int sz;
	mint sm;

	// lazy
	mint a,b;

	D(): sz(0), sm(0), a(1), b(0) {}
	D(mint v): sz(1), sm(v), a(1), b(0){}

	static D merge(D l,D r){
		D z;
		z.sz = l.sz+r.sz;
		z.sm = l.sm+r.sm;
		return z;
	}
	void push_1(D& x){
		mint c = x.a, d = x.b;
		x.a = a*c; x.b = d*a + b;	// composition
		x.sm = x.sm*a + x.sz*b;		// apply
	}
	void push(D& x, D& y){
		push_1(x); push_1(y);
		a=1, b=0;					// clear_lazy
	}
	bool affine(mint c,mint d){
		a = a*c; b = b*c+d;			// composition
		sm = sm*c + sz*d;			// apply
		return true;
	}
	mint getsum(){
		return sm;
	}
};


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	int N,Q; cin >> N >> Q;
	V<int> a(N); rep(i,N) cin >> a[i];
	segbeats<D> seg(a);
	while(Q--){
		int t; cin >> t;
		if(t == 0){
			int l,r,a,b; cin >> l >> r >> a >> b;
			seg.ch(l,r,&D::affine,a,b);
		}else{
			int l,r; cin >> l >> r;
			cout << seg.get(l,r,&D::getsum,[&](mint x,mint y){return x+y;},mint(0)) << endl;
		}
	}
}
