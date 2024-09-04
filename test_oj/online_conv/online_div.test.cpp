#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include "template.hpp"
#include "math/poly.cpp"
#include "math/online_convolution.cpp"

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	Online_Division<mint> X;
	int N; cin >> N;
	rep(i,N){
		mint a; cin >> a;
		cout << X.query(i, i==0, a) << " ";
	}
	cout << endl;
}
