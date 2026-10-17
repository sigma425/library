#define PROBLEM "https://judge.yosupo.jp/problem/composition_of_formal_power_series_large"

#include "template.hpp"
#include "math/poly.cpp"

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	Poly<mint> f(N),g(N);
	cin >> f >> g;
	auto h = composite(f,g,N);
	rep(i,N) cout << h[i] << " \n"[i+1 == N];
}
