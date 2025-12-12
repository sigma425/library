#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum"

#include "template.hpp"
#include "ds/splay/link_cut.hpp"


int main(){
	int N,Q; cin >> N >> Q;
	V<ll> A(N); cin >> A;
	LinkCutTree<ll, [](ll a, ll b){ return a+b; }, [](ll x){ return x; }, false> lct(A);
	rep(i,N-1){
		int x,y; cin >> x >> y;
		lct.link(x,y);
	}
	while(Q--){
		int t; cin >> t;
		if(t == 0){
			int x,y,z,w; cin >> x >> y >> z >> w;
			lct.cut(x,y);
			lct.link(z,w);
		}
		if(t == 1){
			int v; ll x; cin >> v >> x;
			lct.add_vertex(v, x);
		}
		if(t == 2){
			int x,y; cin >> x >> y;
			cout << lct.get_path(x,y) << endl;
		}
	}
}