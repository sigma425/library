/*
	f^n の [x^0], .., [x^(m-1)] を返す
	fの非0要素が k 個のとき O(mk)
		cf. FFTでやると O(m log m log n) とか

	! いま実装がだるいからkの代わりに次数で抑えてる、いや実装そんな変わらないから出たら書いて（ごめん！ｗ）

	https://codeforces.com/blog/entry/76447
	Mifafa テク

	verify : https://official.contest.yandex.com/ptz-winter-2020/contest/17020/run-report/35151613/
		コーナーケースは知らね〜

	定数倍 : 
		10^7 回くらいmintの割り算したら3sかかったから、やめようね！ (ちゃんとinvsを計算しておく)
		↑したら、md <= 5e7 で 1s くらい ちょい遅いな
*/

V<mint> Exp(V<mint> f,ll n,int m){
	V<mint> g(m);
	if(m == 0) return g;
	if(n == 0){
		g[0] = 1;	// 0^0 = 1
		return g;
	}
	if(f.empty()){
		return g;
	}
	if(f[0] == 0){
		int k = si(f);
		int s=0;
		while(s<k && f[s]==0) s++;
		if(s == k) return V<mint>();	// f = 0
		// f   = f_s * x^s + ...
		// f^n = x^ns * (const + ...)
		// if(n*s >= m) return V<mint>();
		if(n >= (m+s-1)/s) return V<mint>();
		V<mint> nf(k-s); rep(i,k-s) nf[i] = f[i+s];
		auto tmp = Exp(nf,n,m-n*s);
		rep(i,m-n*s) g[n*s+i] = tmp[i];
		return g;
	}
	g[0] = f[0].pow(n);		// mintじゃなかったら定義してないかも
	mint if0 = f[0].inv();
	rep(i,m-1){
		// (i+1) g_{i+1} f_0 + i g_i f_1 + .. +           (i+1-d) g_{i+1-d} f_d
		// = 			      n (g_i f_1 + 2 g_{i-1} f_2 + .. + d g_{i+1-d} f_d)
		int d = si(f)-1;
		mint res = 0;
		rep1(j,min(d,i+1)) res += g[i+1-j] * f[j] * (mint(n)*j - (i+1-j));
		g[i+1] = res * if0 * invs[i+1];
	}
	return g;
}
