#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "template.hpp"
#include "ds/segtree/segbeats.hpp"

struct D{
	static const int inf = 2e9;
	int mn;
	D(int v=inf){mn=v;}
	static D merge(D l,D r){ return D(min(l.mn,r.mn)); }
	void push(D& x,D& y){}
	int getmin(){ return mn; }
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
		cout << seg.get(l,r,&D::getmin,[&](int x,int y){return min(x,y);},D::inf) << endl;
	}
}
