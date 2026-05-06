#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template.hpp"
#include "math/poly.cpp"

void test(){
	vector<Poly<mint>> gs = {
		{1},
		{2},
		{1,0,0},
		{2,-1,1},
		{3,1,4,1,5,9,2,6,5,3,5}
	};
	for(ll L: {0LL,1LL,2LL,1LL<<30,1LL<<60}){
		for(auto g: gs){
			auto me = invAtRanges(g, L, L+30);
			rep(i,30+1){
				if(me[i] != divAt({1}, g, L+i)){
					cerr << "g: " << g << " L: " << L << " i: " << i << endl;
					cerr << "me: " << me[i] << endl;
					cerr << "div: " << divAt({1}, g, L+i) << endl;
					assert(false);
				}
			}
		}
	}
	cerr << "passed!" << endl;
}

int main(){
	test();
	int a,b; cin >> a >> b; cout << a+b << endl;
}