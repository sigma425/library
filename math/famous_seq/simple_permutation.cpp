/*
	simple permutation
	https://oeis.org/A111111
	perm tree の深さ1の頂点たちを考えると、
		i) sz >= 3 で、外側がsimple perm 中はなんでも
			ex. [4][89][312][567]
	ii) sz = 2 で、(uniqueにするため)左側はindecomposable 
			ex. [4213][65978] 65の後でもきれるが、このような左端での分解
	というわけで長さ2は特殊(あとs_3 = 0)なので
	s := 2x^4 + 6x^5 + .. (simple perm)
	p := x + 2x^2 + 6x^3 + .. (perm)
	i := (indecomposable)
	i+ip = p, p = x + 2ip + s(p) より
	s(p) = p(1-p)/(1+p) - x
	-s(p) + p(1-p)/(1+p) = x
	pの合成逆からsは求まる
	合成逆は一般にはO(N^2), あるいは一係数だけならラグランジュでO(NlogN)だが・・・

	f = x + 2x^2 + 6x^3 + .. , g(f) = x とする
	f(g(x)) = x を微分して f'(g(x)) g'(x) = 1 これに
	f' = (1-x)f/x^2 - 1/x を使うと、
	(x - (1+x)g)g' = g^2 を得る
		(g1+g2	g2+g3	g3+g4		g4+g5)
	*	(1g1	2g2		3g3			4g4)
	=	-(g1^2	2g1g2	2g1g3+g2^2	2g1g4+2g2g3)
		i (>=0) 項目を見れば g_{i+2} がわかる
	online_convでやる

	verify: https://official.contest.yandex.com/ptz-mirror/contest/42061/problems/M
*/

// x + 2x^2 + 6x^3 + .. の合成逆
// https://oeis.org/A059372
V<mint> composite_inv_of_factorial(int N){
	V<mint> g(N+1); g[1] = 1;
	Online_Convolution<mint> X;	// X := g/x * g/x
	Online_Division<mint> Y;	// Y := -X / g'
	rep(i,N-1){
		mint X_i = X.query(i,g[i+1],g[i+1]);
		mint Y_i = Y.query(i,-X_i,g[i+1]*(i+1));
		g[i+2] = Y_i - g[i+1];

	}
	return g;
}

// https://oeis.org/A111111
// s[1] = s[2] = 0 としている
// 定義では s[1] = 1, s[2] = 2 で、そうしたければ for(int i=1;..) にする
V<mint> simple_permutation(int N){
	auto g = composite_inv_of_factorial(N);
	V<mint> s(N+1); // s = x(1-x)/(1+x) - g
	for(int i=4;i<=N;i++){
		if(i == 1) s[i] = 1;
		else if(i == 2) s[i] = 2;
		else s[i] = (i%2 == 0 ? -2 : 2) - g[i];
	}
	return s;
}

// x + 2x^2 + 6x^3 + .. + m!x^m の合成逆 (m >= 1)
// ( x-(1+x)g + (m+1)!g^{m+1} ) g' = g^2
V<mint> composite_inv_of_partial_factorial(int N, int m){
	V<mint> g(N+1); g[1] = 1;
	Online_Convolution<mint> X;	// X := g/x * g/x
	Online_Division<mint> Y;	// Y := -X / g'
	Online_Pow<mint> Z(m+1);	// Z := (g/x)^{m+1}
	rep(i,N-1){
		mint X_i = X.query(i,g[i+1],g[i+1]);
		mint Y_i = Y.query(i,-X_i,g[i+1]*(i+1));
		g[i+2] = Y_i - g[i+1] + (i>=m-1 ? Z.query(i-m+1,g[i-m+2])*fact[m+1] : 0);
	}
	return g;
}