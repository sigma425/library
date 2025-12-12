#define PROBLEM "https://judge.yosupo.jp/problem/sparse_matrix_det"

#include "template.hpp"
#include "math/mint.hpp"
#include "math/sparseDet.cpp"

int main(){
	int N,K; cin >> N >> K;
	vector<tuple<int,int,mint>> mat;
	rep(i,K){
		int a,b; mint c; cin >> a >> b >> c;
		mat.eb(a,b,c);
	}
	cout << sparseDet(N,mat) << endl;
}
