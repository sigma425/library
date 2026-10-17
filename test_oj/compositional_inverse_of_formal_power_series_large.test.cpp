#define PROBLEM "https://judge.yosupo.jp/problem/compositional_inverse_of_formal_power_series_large"

#include "template.hpp"
#include "math/poly.cpp"

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	Poly<mint> f(N);
	cin >> f;
	auto g = f.compositeInv(N);
	rep(i,N) cout << g[i] << " \n"[i+1 == N];
}
