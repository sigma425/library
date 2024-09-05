/*
	C := 	0	0	0	c_0
			1	0	0	c_1
			0	1	0	c_2
			0	0	1	c_{n-1}

	という n*n コンパニオン行列 C を考える
	C^m がどういう形になるかというと、
	v_0 := T^(1 0 0 0), v_i = C * v_{i-1} として、
	C^m = (v_m v_{m+1} ... v_{m+n-1})

	このライブラリは長さ n のベクトル v_m を返す。型は可換環であることしか要請しない
	O(n^2 log m)
	mint とかなら FFT で O(n logn logm)、というか x^m % (x^n - (a+bx+c^2)) を計算してください(後述)

	仕組み:
		v_0		v_1		v_2		v_3		v_4		...
		1		0		0		a		ac
		0		1		0		b		a+bc
		0		0		1		c		b+c^2

		1		x		x^2		a+bx+cx^2	...
		となる。v_m は、 x^m % (x^n - (a+bx+c^2)) と対応している

	使い道:
		- Toeplitz 行列の累乗がこれに帰着される
		- 一般の体での行列累乗を O(N^3 + N logN logK) でやるときにこれに帰着する
			行列 A は ちょうど一つのフロベニウス標準形に相似 (B = QAQ^-1)
			フロベニウス標準形は、(対角)ブロックごとにコンパニオン行列、みたいになってる
			https://codeforces.com/blog/entry/124815
			https://github.com/hos-lyric/libra/blob/master/algebra/matrix_frobenius.cpp
	verify:
		ucup-3-6 E https://contest.ucup.ac/submission/518580

*/

/*
	v_m -> v_{m+1}
	O(n)
*/
void shift(V<mint>& v, const V<mint>& c){
	int n = c.size();
	mint vn = v[n-1];
	per1(i,n-1) v[i] = v[i-1];
	v[0] = 0;
	rep(i,n) v[i] += vn * c[i];
}
/*
	f = v_p, g = v_q	-> v_{p+q}
	O(n^2)
*/
V<mint> mul(const V<mint>& f, const V<mint>& g, const V<mint>& c){
	int n = c.size();
	V<mint> h(n+n-1);
	rep(i,n) rep(j,n) h[i+j] += f[i] * g[j];
	for(int k=n+n-2;k>=n;k--){
		rep(i,n) h[k-n+i] += h[k] * c[i];
	}
	h.resize(n);
	return h;
}
// v_m を返す, O(n^2 log m)
V<mint> power_companion(const V<mint>& c, ll m){
	assert(m >= 0);
	int n = c.size();
	if(m == 0){
		V<mint> f(n); f[0] = 1;
		return f;
	}
	auto f = power_companion(c, m/2);
	f = mul(f,f,c);
	if(m&1) shift(f,c);
	return f;
}
