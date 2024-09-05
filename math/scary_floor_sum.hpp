/*
	floor sum の一般化
	Monoid T の元 x,y と、 f(i) := floor((a*i + b) / m) が与えられたときに、
	y^f(0) x y^(f(1)-f(0)) x y^(f(2)-f(1)) x ... x y^(f(n)-f(n-1)) を計算する
		x が n 個。最初も最後も y の列が(一般には)ある

	y <= (ax+b)/m という範囲を、(0,0) から (n,[(an+b)/m]) までできるだけ y 方向に貪欲に移動する path を計算していると思える


	例えば floor sum は x したときのこれまでの y の個数 の和なので、Monoid{numx,numy,num(x..y)} をもてば計算可能

	O(log m)

	要請:
		Monoid T が T::e(), T::op(a,b), a.pow(p) を持つ
		an + b がオーバーフローしない

	verify:
		ARC183 F https://atcoder.jp/contests/arc183/submissions/57122721
		LOJ138 https://loj.ac/s/2146116
*/
template<class S = __int128, class T>
T underpath(S a, S b, S m, S n, T x, T y){
	assert(m > 0);
	assert(n >= 0);
	assert(a >= 0);
	assert(b >= 0);
	S c = (a*n+b)/m;
	T pre = T::e(), suf = T::e();
	while(true){
		S p = a/m; a %= m; x = T::op(x, y.pow(p));
		S q = b/m; b %= m; pre = T::op(pre, y.pow(q));
		c -= p*n + q;
		if(c == 0) break;
		S d = (m*c - b - 1) / a + 1;
		suf = T::op(T::op(y, x.pow(n-d)), suf);
		b = m-b-1+a; swap(m,a); n = c-1; c = d; swap(x,y);
	}
	return T::op(T::op(pre, x.pow(n)), suf);
}

/*
	scary floor sum に乗せるためのモノイド
	\sum_{0 <= x < N} x^[0,e1] * floor( (ax + b) / m )^[0,e2] を計算できる

	可変 mint みたいな感じで、使う前に set_e1_e2 を呼ぶ
*/
template<class T>
struct MonoidFloorSum{
	using X = MonoidFloorSum;
	static inline int e1,e2;
	static inline vector<vector<T>> comb;
	static void set_e1_e2(int e1_, int e2_){
		e1 = e1_, e2 = e2_;
		int e = max(e1,e2);
		comb = vector<vector<T>>(e+1,vector<T>(e+1));
		rep(i,e+1){
			comb[i][0] = comb[i][i] = T(1);
			rep1(j,i-1) comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
		}
	}

	MonoidFloorSum():dp(e1+1,vector<T>(e2+1)){}

	T dx, dy;
	vector<vector<T>> dp;

	static X op(X a, X b){
		vector<T> xpow(e1+1); xpow[0] = 1; rep(i,e1) xpow[i+1] = xpow[i] * a.dx;
		vector<T> ypow(e2+1); ypow[0] = 1; rep(i,e2) ypow[i+1] = ypow[i] * a.dy;

		rep(k1,e1+1) rep(k2,e2+1){
			rep(i1,k1+1) rep(i2,k2+1){
				a.dp[k1][k2] += b.dp[i1][i2] * comb[k1][i1] * xpow[k1-i1] * comb[k2][i2] * ypow[k2-i2];
			}
		}
		a.dx += b.dx, a.dy += b.dy;
		return a;
	}
	X pow(ll exp) const {
		X res = X::e();
		X pw = *this;
		while(exp){
			if(exp&1) res = op(res,pw);
			pw = op(pw,pw);
			exp /= 2;
		}
		return res;
	}
	static X to_x(){
		X x;
		x.dp[0][0] = 1; x.dx = 1;
		return x;
	}
	static X to_y(){
		X x;
		x.dy = 1;
		return x;
	}
	static X e(){
		return X();
	}
};

/*
	res[k1][k2] = \sum_{0 <= x < N} x^e1 * floor( (ax + b) / m )^e2

	要請: a >= 0, b >= 0, m > 0, N >= 0

	値の範囲は S. だいたい __int128?
	返り値は T. だいたい mint?
	https://loj.ac/p/138
*/
template<class S, class T>
vector<vector<T>> scary_floor_sum_simple(S N, S a, S b, S m, int e1, int e2){
	// {	// brute
	// 	vector<vector<T>> res(e1+1,vector<T>(e2+1));
	// 	for(S x = 0; x < N; x++){
	// 		S y = divFloor(a*x+b, m);
	// 		vector<T> xpow(e1+1); xpow[0] = 1; rep(i,e1) xpow[i+1] = xpow[i] * T(x);
	// 		vector<T> ypow(e2+1); ypow[0] = 1; rep(i,e2) ypow[i+1] = ypow[i] * T(y);
	// 		rep(k1,e1+1) rep(k2,e2+1){
	// 			res[k1][k2] += xpow[k1] * ypow[k2];
	// 		}
	// 	}
	// 	return res;
	// }

	using Data = MonoidFloorSum<T>;
	Data::set_e1_e2(e1,e2);
	auto f = underpath(a, b, m, N, Data::to_x(), Data::to_y());
	return f.dp;
}

/*
	res[k1][k2] = \sum_{L <= x < R} x^k1 * floor( (ax + b) / m )^k2
	0 <= k1 <= e1, 0 <= k2 <= e2

	要請は m > 0, floor の中身が [L,R) で non-negative

	値の範囲は S, mint で求めよ とかもあるので返り値は T
	https://loj.ac/p/138
*/
template<class S, class T>
vector<vector<T>> scary_floor_sum(S L, S R, S a, S b, S m, int e1, int e2){
	assert(L <= R);
	assert(m > 0);
	assert(e1 >= 0 && e2 >= 0);

	// {	// brute
	// 	vector<vector<T>> res(e1+1,vector<T>(e2+1));
	// 	for(S x = L; x < R; x++){
	// 		S y = divFloor(a*x+b, m);
	// 		vector<T> xpow(e1+1); xpow[0] = 1; rep(i,e1) xpow[i+1] = xpow[i] * T(x);
	// 		vector<T> ypow(e2+1); ypow[0] = 1; rep(i,e2) ypow[i+1] = ypow[i] * T(y);
	// 		rep(k1,e1+1) rep(k2,e2+1){
	// 			res[k1][k2] += xpow[k1] * ypow[k2];
	// 		}
	// 	}
	// 	return res;
	// }

	// a >= 0 に変形
	bool a_flipped = false;
	if(a < 0){
		a_flipped = true;
		R--;
		//  x^k1 * floor( (a * x + b) / m )^k2 						x \in [L,R]
		//	(-1)^k1 * (-x)^k1 * floor( (-a * -x + b) / m )^k2		-x \in [-R,-L]
		a = -a; swap(L,R); L = -L, R = -R;
		R++;
	}
	// L = 0 に変形
	// x \in [L,R) => x \in [0,R-L), (x+L)^k1...

	vector<vector<T>> res(e1+1,vector<T>(e2+1));

	auto f = scary_floor_sum_simple<S,T>(R-L, a, b+a*L, m, e1, e2);

	rep(k1,e1+1) rep(k2,e2+1){
		rep(i,k1+1) res[k1][k2] += f[i][k2] * T(L).pow(k1-i) * Choose(k1,i);
	}
	if(a_flipped){
		rep(k1,e1+1) if(k1&1) rep(k2,e2+1) res[k1][k2] *= -1;
	}
	return res;
}