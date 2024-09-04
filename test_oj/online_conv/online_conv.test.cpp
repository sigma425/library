#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "template.hpp"
#include "math/poly.cpp"
#include "math/online_convolution.cpp"

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	int A,B; cin >> A >> B;
	V<mint> a(A),b(B);
	rep(i,A) cin >> a[i];
	rep(i,B) cin >> b[i];
	int C = A+B-1;
	a.resize(C); b.resize(C);
	Online_Convolution<mint> X;
	rep(i,C){
		cout << X.query(i,a[i],b[i]) << " ";
	}
	cout << endl;
}
