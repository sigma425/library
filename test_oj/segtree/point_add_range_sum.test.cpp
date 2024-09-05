#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "template.hpp"
#include "ds/segtree/segtree_simple.hpp"

struct D{
	ll v;
	D(){ *this = e(); }
	D(ll v_):v(v_){}
	static D op(const D& x,const D& y){
		return D(x.v+y.v);
	}
	const static D e(){
		return D(0);
	}
	friend ostream& operator<<(ostream& o,const D& d){return o<<d.v;}
};

int main(){
	int N,Q; cin >> N >> Q;
	V<ll> A(N); rep(i,N) cin >> A[i];
	Segtree<D> seg(A);
	while(Q--){
		int t; cin >> t;
		if(t == 0){
			int i,x; cin >> i >> x;
			seg.add(i,x);
		}else{
			int l,r; cin >> l >> r;
			cout << seg.query(l,r) << endl;
		}
	}
}