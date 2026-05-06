/*
	必要:
		linearRecurrence (Berlekamp_massey.cpp)
		rnd()
		こんなの書くくらいならすべてをinclude形式にしたほうがいいのは間違いないだろうな


	行列の最小多項式
	f[i] = c * A^i * v というスカラーの列にしてから linearRecurrence を求めれば良い
	sparse matrix は {i,j,val} の形で渡す (i,j) が unique じゃなくてもいい
	Nは行列のサイズ と見せかけて最小多項式の次数以上ならなんでもよい
	O(N^2 + N * mat.size)

	verify:
		https://qoj.ac/problem/5244
		https://judge.yosupo.jp/problem/sparse_matrix_det
*/

#include "misc/rand.hpp"
#include "math/berlekamp_massey.hpp"

template<class mint>
vector<mint> sparseMinPoly(int N, vector<tuple<int,int,mint>> mat){
	vector<mint> f(N+N+5);
	vector<mint> c(N), v(N);
	rep(i,N) c[i] = rng(mint::mod);
	rep(i,N) v[i] = rng(mint::mod);
	rep(k,N+N+5){
		rep(i,N) f[k] += c[i] * v[i];
		V<mint> vv(N);
		for(auto&& [i,j,x]: mat) vv[j] += x * v[i];
		v = vv;
	}
	auto p = find_linear_reccurence(f);
	reverse(all(p));	// A^i の係数は p_i であるべきなので漸化式の文脈と逆
	return p;
}

/*
	疎行列の行列式
	(modがでかければ) ランダムな対角行列をかけるとcharpolyに重解がなくなるので、minpolyと一致する
	N は行列のサイズ
	O(N^2 + N * mat.size)
	https://yukicoder.me/wiki/black_box_linear_algebra
*/
template<class mint>
mint sparseDet(int N, vector<tuple<int,int,mint>> mat){
	vector<mint> d(N,1); rep(i,N) d[i] = rng(mint::mod);
	for(auto&& [i,j,x]: mat) x *= d[i];
	auto f = sparseMinPoly(N, mat);
	if(si(f) != N+1) return mint(0);
	mint det = f[0]/f[N];
	if(N&1) det *= -1;
	rep(i,N) det /= d[i];
	return det;
}
template<class mint>
mint sparseDet(VV<mint> A){
	int N = si(A);
	vector<tuple<int,int,mint>> mat;
	rep(i,N) rep(j,N) if(A[i][j]){
		mat.pb({i,j,A[i][j]});
	}
	return sparseDet(N,mat);
}