#define PROBLEM "https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary"

#include "template.hpp"
#include "DP/maxplus_convolution_b_concave.hpp"

int main(){
	int A,B; cin >> A >> B;
	V<int> a(A); rep(i,A) cin >> a[i];
	V<int> b(B); rep(i,B) cin >> b[i];
	auto c = maxplus_conv<int,false>(b,a);
	rep(i,si(c)) cout << c[i] << " ";
	cout << endl;
}
