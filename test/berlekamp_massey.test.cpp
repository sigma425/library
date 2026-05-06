#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template.hpp"
#include "math/berlekamp_massey.hpp"
#include "math/mint.hpp"

void test(){
	while(true){
		int n; cin >> n;
		V<mint> a(n); rep(i,n) cin >> a[i];
		auto c = find_linear_reccurence(a);
		show(c);
		int m = si(c);
		for(int i=m-1;i<n;i++){
			mint s = 0;
			rep(j,m) s += c[j] * a[i-j];
			assert(s == 0);
		}
	}
	cerr << "passed!" << endl;
}

int main(){
	test();
	int a,b; cin >> a >> b; cout << a+b << endl;
}