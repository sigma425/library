#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "template.hpp"
#include "math/factorization.hpp"

int main(){
	int Q; cin >> Q;
	while(Q--){
		ll a; cin >> a;
		auto ps = pollard(a);
		cout << si(ps);
		for(ll p: ps) cout << " " << p;
		cout << endl;
	}
}