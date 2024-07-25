/*
	数列 A, B が与えられる
	!!!! B !!!! は concave (上に凸)
	C_k = max_{k=i+j} A_i + B_j を出力
	O(|A|+|B|)

	例えば knapsack で同じ w についてまとめたものを B とすると mod w ごとにこれを呼ぶことになる
	B が convex (下に凸) の minplus_convolution は select の中身だけ変えればよい

	https://codeforces.com/blog/entry/98663

	verify:
		https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary
*/

#include "smawk.hpp"

template<class T, bool is_max>
vector<T> maxplus_conv(const vector<T>& a, const vector<T>& b){
	int A = a.size(), B = b.size();
	auto f = [&](int i, int j){
		return a[j] + b[i-j];
	};
	auto select = [&](int i, int j1, int j2){
		if(i < j2) return false;
		if(i-j1 >= B) return true;
		// max plus convolution, b: concave
		if(is_max) return f(i,j1) <= f(i,j2);
		// min plus convolution, b: convex
		else return f(i,j1) >= f(i,j2);
	};
	vector<int> amax = smawk(A+B-1, A, select);
	vector<T> c(A+B-1);
	rep(i,A+B-1) c[i] = f(i, amax[i]);
	return c;
}