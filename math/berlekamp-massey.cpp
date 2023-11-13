/*
	linear_reccurence
	Berlekamp-Massey
	体K上のn+1項間線形漸化式から生成される数列の,はじめ2n項を渡すと,その線形漸化式(というか最小多項式)を求めてくれる
	例えばfibなら4項必要.
	input を u , N項 として output を c とすると
	for all j < N-K,
	c_0 * u_j + c_1 * u_{j+1} + .. + c_K * u_{j+K} = 0
	となる.
	O(n^2)

	K項目を求めたかったら x^K を最小多項式で割るみたいなのがいる
	polyライブラリにある: linearReccurenceAt
*/

template<class D>
vector<D> linearReccurence(const vector<D> &u){
	int N = u.size();
	vector<D> b = {D(-1)}, c = {D(-1)};
	D y = D(1);
	rep1(n,N){
		int L = c.size(), M = b.size();
		D x = 0; rep(i,L) x += c[i] * u[n-L+i];
		b.pb(0);
		M++;
		if(!x) continue;
		D coef = x/y;
		if(L<M){
			auto tmp = c;
			c.insert(begin(c),M-L,D(0));
			rep(i,M) c[M-1-i] -= coef*b[M-1-i];
			b=tmp;
			y=x;
		}else{
			rep(i,M) c[L-1-i] -= coef*b[M-1-i];
		}
	}
	return c;
}