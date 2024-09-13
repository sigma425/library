#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include "template.hpp"
#include "ds/cartesian_tree.hpp"

int main(){
	int N; cin >> N;
	V<int> A(N); rep(i,N) cin >> A[i];
	CartesianTree<int, true> Tree(A);
	rep(i,N){
		if(Tree.par[i] == -1) cout << i << " ";
		else cout << Tree.par[i] << " ";
	}
	cout << endl;
}
