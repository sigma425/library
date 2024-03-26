/*
	ファウルハーバー / Faulhaber
	res[0<=k<=n] = \sum_{0<=i<=a} i^k
	O(n log n)
	第一種スターリングの S(n,[n-a,n]) を求めるのにも使える
*/
V<mint> powsum(ll a, int n){
	Poly<mint> f(n+1),g(n+1);
	{
		mint p = 1;
		rep1(i,n+1){
			p *= a+1;
			f[i-1] = ifact[i] * p;
			g[i-1] = ifact[i];
		}
	}
	auto h = (f * g.inv(n+1)).low(n+1);
	rep(i,n+1) h[i] *= fact[i];
	return h;
}