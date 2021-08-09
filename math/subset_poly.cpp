/*
	Sのsubsetに対して値が紐付けられている時、 f = a_00 + a_01 x_1 + a_10 x_0 + a_11 x_0 x_1 みたいなものを扱う
	基本は subset_convolution
		集合を2つに分割した積の和
		poly だと考えると mod x_i^2 を取っていることになって、結局次数もキーに持ってzeta/mebiusして辻褄が合うとこだけ取ってくればよい
		O(2^n n^2)
	より一般に、subset poly 同士で演算したい時、その演算をFPSだと考えればFPS上の+,*に帰着でき、zetaしたあと各点での演算に帰着される
	今サイズも情報として持っている (yの次数として持ってyのFPSと思う)ので、結局各点での演算はyのFPS同士の演算になる

	FPS OPERATION ってかいてあるところでmult,div,exp,log,sqrt,powなど好きな演算をO(n^2)とかでやるとよい
	g = e^f -> g' = f'g -> gの線形漸化式 みたいな

	実装上の注意:
		VV<mint> (1<<N,N+1) を内部で取ると壊れるのでグローバルにおいている

	verified:
		https://ac.nowcoder.com/acm/contest/11258/A div
		https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h
*/

template<class T, class ZT>
void zeta(T& a, ZT& za){
	int n = __lg(si(a));
	assert(si(a)==(1<<n));

	rep(s,1<<n){
		rep(i,n+1) za[s][i] = 0;		// clean up
		za[s][__builtin_popcount(s)] = a[s];
	}
	rep(i,n) rep(s,1<<n) if(!(s&1<<i)){
		rep(k,n+1) za[s|1<<i][k] += za[s][k];
	}
}
template<class T, class ZT>
void mebius(T& a, ZT& za){
	int n = __lg(si(a));
	assert(si(a)==(1<<n));

	rep(i,n) rep(s,1<<n) if(!(s&1<<i)){
		rep(k,n+1) za[s|1<<i][k] -= za[s][k];
	}
	rep(s,1<<n){
		a[s] = za[s][__builtin_popcount(s)];
	}
}

const int MAXN = 20;
mint za[1<<MAXN][MAXN+1];
mint zb[1<<MAXN][MAXN+1];
template<class T>
V<T> subset_div(V<T> a, V<T> b){
	show(a);show(b);
	assert(si(a) == si(b));
	int s = si(a);
	int n = __lg(s);
	assert(s==(1<<n));

	zeta(a,za);
	zeta(b,zb);

	rep(s,1<<n){
		auto f = za[s], g = zb[s];
		// DO FPS OPERATION HERE
		// h = f/g
		mint g0inv = mint(1)/g[0];
		V<mint> h(n+1);
		rep(i,n+1){
			mint tmp = f[i];
			rep(j,i) tmp -= h[j] * g[i-j];
			h[i] = tmp * g0inv;
		}
		// UNTIL HERE
		rep(i,n+1) za[s][i] = h[i];
	}

	mebius(a,za);
	show(a);
	return a;
}