#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include "template.hpp"
#include "math/prime_sum.hpp"

int main(){
	ll N; cin >> N;
	PrimeSum<ll> ps(N, [](ll n){ return n; });
	cout << ps(N) << endl;
}