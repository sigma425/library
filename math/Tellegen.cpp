/*
	Tellegen 転置
	https://paper.dropbox.com/doc/Tellegen--B14rtYTHEo3_HNE_alGHKuF~Ag-rfmOzvP8OswA8Vug7Dn5H

	FFT -> FFT
	iFFT -> iFFT
	 *= f -> middle product
	 multieval -> \sum_j b_j/(1-a_jx)
	 など
*/


/*
	MultipointEval
		fix : x_0 , .. , x_{n-1}	n 点
		in : a_0 , .. , a_d			d 次式
		out : b_0 , .. , b_{n-1}	n 点
			b_i = a(x_i)
	の転置
		fix : x_0 , .. , x_{n-1}	n 点
		in : p_0 , .. , p_{n-1}		n 点
		out : q_0 , .. , q_d		d 次式
			q(y) = \sum_j p_j/(1 - x_j y) を d 次までとったもの
*/
V<mint> TransposedMultipointEval(V<mint> p, V<mint> x, int d){
	using poly = Poly<mint>;
	assert(si(p) == si(x));
	int n = si(p);
	auto rec = [&](auto&& self, int l, int r) -> pair<poly,poly> {
		if(r-l == 1){
			return make_pair(poly({p[l]}),poly({1,-x[l]}));
		}
		int m = (l+r)/2;
		auto fl = self(self,l,m);
		auto fr = self(self,m,r);
		poly numer = fl.fs * fr.sc + fr.fs * fl.sc;
		poly denom = fl.sc * fr.sc;
		return make_pair(numer,denom);
	};
	auto f = rec(rec,0,n);
	return (f.fs * f.sc.inv(d+1)).low(d+1);
}

/*
	多項式の積 ( *= f)
		fix: f_0 , .. , f_d			d 次式
		in: a_0 , .. , a_n			n 次式
		out: b_0 , .. , b_{n+d}		n+d 次式
			b = a*f
	転置 (middle product)
		fix: f_0 , .. , f_d			d 次式
		in: p_0 , .. , p_{n+d}		n+d 次式
		out: q_0 , .. , q_n			n 次式
			q = rev(f) * p の [d,n+d] 次を取り出したもの
		note :
			例えば p も n 次までしか考えない場合(つまりp_{n+1} 以降を捨てる場合)、そこを0で埋めたと思えばよい
			(値を捨てる場合 を参考)
*/
V<mint> MiddleProduct(V<mint> p, V<mint> f, int n, int d){
	assert(si(f) == d+1);
	assert(si(p) == n+d+1);
	reverse(all(f));
	auto z = multiply(f,p);
	V<mint> q(n+1); rep(i,n+1) q[i] = z.at(d+i);
	return q;
}

/*
	順問題
		in: p_0 , .. , p_{n-1}
		out: q_0, .. , q_n
			p_0(x+b_0) + p_1(x+b_0)(x+b_1) + .. + p_{n-1}(x+b_0)..(x+b_{n-1})
			の [0,n] 次
*/
V<mint> solve2(V<mint> q, V<mint> b, int n){
	assert(si(q) == n+1);
	assert(si(b) == n);
	V<mint> p(n);
	auto rec = [&](auto&& self, int l, int r, V<mint> f) -> V<mint> {
		assert(si(f) == r-l+1);
		if(r-l == 1){
			p[l] = f[0] * b[l] + f[1];
			return {b[l],1};
		}
		int m = (l+r)/2;
		V<mint> fl,fr;
		fl = V<mint>(f.begin(),f.begin()+m-l+1);
		auto zl = self(self,l,m,fl);
		fr = MiddleProduct(f,zl,r-m,m-l);
		auto zr = self(self,m,r,fr);
		return multiply(zl,zr);
	};
	rec(rec,0,n,q);
	return p;
}