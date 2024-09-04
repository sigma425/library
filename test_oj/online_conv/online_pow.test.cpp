#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include "template.hpp"
#include "math/poly.cpp"
#include "math/online_convolution.cpp"

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	InitFact(2e6);

	int N; ll M; cin >> N >> M;

	Online_Pow<mint> X(M);
	rep(i,N){
		mint a; cin >> a;
		cout << X.query(i, a) << " ";
	}
	cout << endl;
}
