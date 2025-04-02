/*
	f: 完全乗法的 に対し、G(n) = \sum_{p <= n} f(p) をみたす G を求める
	F が求まっている必要がある

	ただし大文字は対応する累積和を指す。
	また、"A が求まっている" とは、O(sqrt(N)) 個の n \in {[N/i}} に対して A(n) = a(1) + .. + a(n) が求まっていることをいう

	使い方:
		コンストラクタに N と F を渡す
		F は n \in {[N/i]} に F(n) でアクセスしたときに正しい値を返す必要がある
		ラムダ式を渡したり、他の累積和が "求まっている" ような struct を渡したり

	具体例:
	- 素数カウント: f(n) = 1, つまり F(n) = n を渡す
	- 素数sum: f(n) = n, つまり F(n) = n(n+1)/2 を渡す
	- mod 6 で 5 になる素数カウント: f(n) = (n%6 == 5) では乗法的ですらないのでダメ
		f は完全乗法的でなければならないので f(p) を決めれば決まる
		f(p) = 0 if p = 2,3
		f(p) = 1 if p mod 6 = 1
		f(p) = -1 if p mod 6 = 5
		と定義すれば、f(n) が n mod 6 = 1 なら 1, n mod 6 = 5 なら -1, それ以外なら 0 になるので、F を簡単に求められる
		これで (mod6 で 1 の個数) - (mod6 で 5 の個数) が求まるので、+ が普通の素数カウントなのと合わせると求まる
		一般には、Z/mZ の形式的和 (モノイド環) が value_type だと思ってやるとよい
			LOJ 6028: https://loj.ac/s/2216105

	計算量: O(N^{3/4}/logN) time, O(N^{1/2}) space
	N = 10^11: 0.4s, N = 10^12: 2s くらい (prime count, -O3)
*/

#include "math/prime.hpp"

template <class T>
struct PrimeSum {
	ll N,sq;
	vector<T> small,large;

	template <class Func>
	PrimeSum(ll N_, const Func F) : N(N_), sq(sqrtl(N_)) {
		linear_sieve(sq);
		small.resize(sq+1); large.resize(sq+1);
		rep1(n,sq) small[n] = F(n) - 1;
		rep1(n,sq) large[n] = F(N/n) - 1;
		for(ll p: pr){
			int R = min(sq, N/(p*p));
			int M = sq/p;
			T x = small[p-1];
			T fp = small[p] - small[p-1];
			rep1(n,M) large[n] -= fp * (large[n*p] - x);
			for(int n=M+1;n<=R;n++) large[n] -= fp * (small[N/(n*p)] - x);
			for(int n=sq;n>=p*p;n--) small[n] -= fp * (small[n/p] - x);
		}
	}

	T& operator()(ll n){
		return (n <= sq ? small[n] : large[N/n]);
	}
};