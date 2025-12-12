#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "template.hpp"
#include "ds/segtree/segbeats.hpp"
#include "math/mint.hpp"


struct D{
	mint a,b;
	D(): a(1),b(0){}
	D(mint a_, mint b_): a(a_),b(b_){}
	D(pair<int,int> p): a(p.fs),b(p.sc){}

	static D merge(D l,D r){
		return D(l.a*r.a,l.b*r.a+r.b);
	}
	void push(D& x,D& y){}
};


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	int N,Q; cin >> N >> Q;
	V<pair<int,int>> a(N); rep(i,N) cin >> a[i].fs >> a[i].sc;
	segbeats<D> seg(a);
	while(Q--){
		int t; cin >> t;
		if(t == 0){
			int p,c,d; cin >> p >> c >> d;
			seg.set_point(p, D(c,d));
		}else{
			int l,r; mint x; cin >> l >> r >> x;
			auto f = seg.get_range(l,r);
			cout << f.a*x+f.b << endl;
		}
	}
}
