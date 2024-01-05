#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template.hpp"
#include "../../math/poly.cpp"
#include "../../math/online_convolution.cpp"

void test(Poly<mint> f, ll K){
	int n = si(f);
	assert(f[0]);
	auto g = f.pow(K,n);
	Online_Pow<mint> X(K);
	rep(i,n){
		mint waf = X.query(i,f[i]);
		if(g[i] != waf){
			show(f);show(K);
			show(g);
			show(i);
			show(waf);
			assert(0);
		}
	}
}
void TEST(){
	InitFact(TEN(6));

	while(true){
		for(ll K: V<ll>({0,1,2,-1,TEN(18),-TEN(18)})){
			test({1},K);
			test({314},K);
			for(int N: {2,3,4,(1<<15)-1,(1<<15),(1<<15)+1}){
				Poly<mint> f(N);
				rep(i,N) f[i] = rnd(mint::mod);
				test(f,K);
			}
		}
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	TEST();

	int a,b; cin >> a >> b; cout << a+b << endl;
}
