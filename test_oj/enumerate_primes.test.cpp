#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include "template.hpp"
#include "math/prime.hpp"

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	int N,A,B; cin >> N >> A >> B;
	linear_sieve(N);
	V<int> ans;
	for(int i=B;i<si(pr);i+=A) ans.pb(pr[i]);
	cout << si(pr) << " " << si(ans) << endl;
	for(int v: ans) cout << v << " ";
	cout << endl;
}
