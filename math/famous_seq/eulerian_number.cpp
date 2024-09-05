/*
	Eulerian number A(n,k)
		= 1,..,n の順列で ascent が k 個なものの個数
		= [0,1] 乱数を n 個足したときの floor が k な確率 * n!

	特徴
		A(n,k) = \sum_{i=0}^k (-1)^i * Choose(n+1,i) * (k+1-i)^n
		A(n,k) = (n-k) * A(n-1,k-1) + (k+1) * A(n-1,k)
		Stirling2 と本質的に同じだったな、そういえば
		Worpitzky's identity: x^n を C(x+k,n) の和で表すときの係数にAが出てくる
*/

/*
	return [A(n,0), .. , A(n,k)]
	A(n,k) = \sum_{i=0}^k (-1)^i * Choose(n+1,i) * (k+1-i)^n

	O(k logk + k logn)
	k が無駄に大きくても 0 を埋めて返してくれる
*/
V<mint> eulerian_n$(int n, int k){
	V<mint> f(k+1); rep(i,k+1) f[i] = Choose(n+1,i) * (i&1?-1:1);
	V<mint> g(k+1); rep(i,k+1) g[i] = mint(i+1).pow(n);
	auto h = multiply(f,g);
	h.resize(k+1);
	return h;
}

/*
	A(n,k) = (n-k) * A(n-1,k-1) + (k+1) * A(n-1,k)
*/
VV<mint> E;
void initEulerian(int n, int k = -1){
	if(k == -1) k = n;
	E = VV<mint>(n+1,k+1);
	E[0][0] = 1;
	rep1(i,n){
		rep(j,k+1) E[i][j] = (j ? (i-j) * E[i-1][j-1] : 0) + (j+1) * E[i-1][j];
	}
}