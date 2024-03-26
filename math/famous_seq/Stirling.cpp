/*
	return {s(n,0), .., s(n,k)}
	符号なし. 符号付きにしたかったら (-1)^{n-k} をかける
	O(k log k log n) ただし、k = n のときは O(n log n)
*/
V<mint> Stirling1_n$(int n, int k){
	// s(n,k) = [x^k] x(x+1)..(x+n-1)
	auto rec = [&](auto&& self, int n_) -> Poly<mint> {
		if(n_ == 0){
			return Poly<mint>({1});
		} 
		auto f = self(self,n_/2);
		f = (f * f.shift(n_/2)).low(k+1);
		if(n_&1){
			// *= (x+n_-1)
			int S = si(f); f.eb(0);
			per(i,S){
				f[i+1] += f[i];
				f[i] *= (n_-1);
			}
			if(S == k+1) f.pop_back();
		}
		return f;
	};
	return rec(rec,n);
}

/*
	initialize s([0,n],[0,k])
	O(nk)
*/
VV<mint> s1;
void initStirling1(int n, int k = -1){
	if(k == -1) k = n;
	s1.resize(n+1); rep(i,n+1) s1[i].resize(min(i+1,k+1));
	s1[0][0] = 1;
	rep1(i,n){
		rep1(j,min(i-1,k)) s1[i][j] = s1[i-1][j-1] + (i-1) *s1[i-1][j];
		if(i <= k) s1[i][i] = 1;
	}
}

/*
	return {S(n,0), .., S(n,k)}
	O(k log n + k log k)
*/
V<mint> Stirling2_n$(int n, int k){
	// S(n,k) = 1/k! \sum_{i=0}^k C(k,i)(-1)^{k-i} i^n
	V<mint> f(k+1); rep(i,k+1) f[i] = ifact[i] * mint(i).pow(n);
	V<mint> g(k+1); rep(i,k+1) g[i] = (i&1 ? -ifact[i] : ifact[i]);
	auto S = multiply(f,g);
	S.resize(k+1);
	return S;
}

mint Stirling2_nk(int n, int k){
	mint res = 0;
	rep(i,k+1) res += Choose(k,i) * mint(i).pow(n) * ((k-i)&1 ? -1 : 1);
	return res * ifact[k];
}

/*
	initialize S([0,n],[0,k])
	O(nk)
*/
VV<mint> S2;
void initStirling2(int n, int k = -1){
	if(k == -1) k = n;
	S2.resize(n+1); rep(i,n+1) S2[i].resize(min(i+1,k+1));
	S2[0][0] = 1;
	rep1(i,n){
		rep1(j,min(i-1,k)) S2[i][j] = S2[i-1][j-1] + j * S2[i-1][j];
		if(i <= k) S2[i][i] = 1;
	}
}