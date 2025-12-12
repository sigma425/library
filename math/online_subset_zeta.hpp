/*
	f[0], f[1], .., f[(1<<n)-1] が順番にオンラインで与えられるので、
	f[i] が与えられたタイミングで ζ(f)[i] = Σ_{j ⊆ i} f[j] を計算するアルゴリズム

	onlinesubset_zeta.png も参照

	全体 O(n * 2^n)

	verify: ARC198-E https://atcoder.jp/contests/arc198/submissions/66227424
*/

#include "misc/highbit.hpp"

template<class T>
struct OnlineSubsetZeta {
	int n;
	int p = 0;
	vector<T> F;
	OnlineSubsetZeta(int n_) : n(n_), F(1 << n) {}

	/*
		f[i] = f_i として、ζ(f)[i] := Σ_{j ⊆ i} f[j] を返す。
		O(2^lowbit(p)) なので、全体で O(n * 2^n)
	*/
	T query(int i, T f_i){
		assert(p == i);
		T res = assume(i, f_i);
		F[p++] = f_i;
		const int K = lowbit(p);
		rep(k, K){
			for(int j = p - (1<<k); j < p; j++) F[j] += F[j - (1<<k)];
		}
		return res;
	}

	/*
		仮に f[i] = f_i として、ζ(f)[i] を返す。実際に set はしない。
		O(n)
	*/
	T assume(int i, T f_i){
		assert(p == i);
		T ans = f_i;
		rep(k, n) if(i & 1<<k) ans += F[i ^ 1<<k];
		return ans;
	}
};

/*
	f[0], f[1], .., f[(1<<n)-1] が順番にオンラインで与えられるので、
	f[i] が与えられたタイミングで μ(f)[i] = Σ_{j ⊆ i} (-1)^pc(i-j) * f[j] を計算するアルゴリズム

	全体 O(n * 2^n)
*/

template<class T>
struct OnlineSubsetMebius {
	int n;
	int p = 0;
	vector<T> F;
	OnlineSubsetMebius(int n_) : n(n_), F(1 << n) {}

	/*
		f[i] = f_i として、ζ(f)[i] := Σ_{j ⊆ i} (-1)^pc(i-j) * f[j] を返す。
		O(2^lowbit(p)) なので、全体で O(n * 2^n)
	*/
	T query(int i, T f_i){
		assert(p == i);
		T res = assume(i, f_i);
		F[p++] = f_i;
		const int K = lowbit(p);
		rep(k, K){
			for(int j = p - (1<<k); j < p; j++) F[j] -= F[j - (1<<k)];
		}
		return res;
	}

	/*
		仮に f[i] = f_i として、ζ(f)[i] を返す。実際に set はしない。
		O(n)
	*/
	T assume(int i, T f_i){
		assert(p == i);
		T ans = f_i;
		rep(k, n) if(i & 1<<k) ans -= F[i ^ 1<<k];
		return ans;
	}
};