/*
	q-カタラン数 この定義の他にもそう呼ばれるものがあるので注意
	Area generating function として (二項係数みたいに)
		左下:(0,0) -> 右上:(n,n) まで、左上領域を通らず移動する方法は Cat(n) 通りある
		各 dyck path について、q^(path の右下にあるマスの個数) を足し合わせたものを Cat_q(n) と定義する
	括弧列として
		長さ 2n の括弧列に対して、q^(inversion) を足し合わせたもの

	例: Cat_q(3) = q^0 + q^1 + 2q^2 + q^3

	Cat_q(0), .., Cat_q(N) を返す関数 O(Nlog^2N)

	Cat_q(n) := \sum_{0<=i<=n-1} Cat_q(i) * Cat_q(n-1-i) * q^-i

	ちなみに q^0,..,q^{n(n-1)/2} を逆順に並べたほうが式が簡単になる:
		f_q(n) := \sum_{0<=i<=n-1} f_q(i) * f_q(n-1-i) * q^i
		のでこっち経由で計算している、そのために割り算は必要

	f_n = \sum_{0<=i<=n-1} f_i * f_{n-1-i} * q^-i
	C_n = f_n *  q^(n(n-1)/2)

	https://oeis.org/A129176

	verify: ucup-4-15 F: Set of Intervals 2 https://contest.ucup.ac/submission/2027748
*/
V<mint> q_catalan(int N, mint q){
	V<mint> f(N+1); f[0] = 1;
	Online_Convolution<mint> X;
	mint qinv = q.inv();	// 注意
	mint pw = 1;
	rep(i,N){
		f[i+1] = X.query(i, f[i], f[i] * pw);
		pw *= qinv;
	}
	rep(i,N+1) f[i] *= q.pow(ll(i)*(i-1)/2);
	return f;
}