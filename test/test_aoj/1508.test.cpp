#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"
#include "template.hpp"
#include "ds/splay/splay.hpp"

int main(){
	int N, Q; cin >> N >> Q;
	V<int> vs(N); cin >> vs;
	using STree = SplayTree<int, [](int a, int b){ return min(a,b); }, [](){ return INT_MAX;}>;
	STree st(vs);
	auto split = [&](STree::NP x, int k){
		return STree::split(x, k);
	};
	auto merge = [&](STree::NP x, STree::NP y){
		return STree::merge(x, y);
	};
	while(Q--){
		int t; cin >> t;
		if(t == 0){
			int l, r; cin >> l >> r;
			// [l..r-1][r] -> [r][l..r-1]
			auto a = split(st.n, l);		// [0..l-1][l..N-1]
			auto b = split(a.sc, r-l+1);	// [l..r][r+1..N-1]
			auto c = split(b.fs, r-l);		// [l..r-1][r]
			st.n = merge(merge(a.fs, c.sc), merge(c.fs, b.sc));
		}
		if(t == 1){
			int l, r; cin >> l >> r; r++;
			cout << st.query(l, r) << endl;
		}
		if(t == 2){
			int k, x; cin >> k >> x;
			st.assign(k, x);
		}
	}
}