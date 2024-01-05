#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template.hpp"
#include "../../math/poly.cpp"
#include "../../math/online_convolution.cpp"

void test(Poly<mint> f, Poly<mint> g){
	int n = si(f);
	assert(g[0]);
	auto h = f * g.inv(n);
	Online_Division<mint> X;
	rep(i,n){
		assert(X.query(i,f[i],g[i]) == h[i]);
	}
}
void TEST(){
	test({0},{2});
	test({3},{2});
	test({0,0},{9,0});
	test({0,2},{9,3});
	for(int N: {2,3,4,(1<<18)-1,(1<<18),(1<<18)+1}){
		Poly<mint> f(N),g(N);
		rep(i,N) f[i] = rnd(mint::mod);
		rep(i,N) g[i] = rnd(mint::mod);
		test(f,g);
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	TEST();

	int a,b; cin >> a >> b; cout << a+b << endl;
}
