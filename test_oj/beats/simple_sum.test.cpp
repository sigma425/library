#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "template.hpp"
#include "ds/segtree/segbeats.hpp"

struct D{
	ll sm;
	D(ll v=0): sm(v){}
	static D merge(D l, D r){ return D(l.sm+r.sm); }
	void push(D& x, D& y){}
	ll getsum(){ return sm; }
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	int N,Q; cin >> N >> Q;
	V<int> a(N); rep(i,N) cin >> a[i];
	segbeats<D> seg(a);
	while(Q--){
		int l,r; cin >> l >> r;
		cout << seg.get(l,r,&D::getsum,[&](ll x,ll y){return x+y;},0LL) << endl;
	}
}
