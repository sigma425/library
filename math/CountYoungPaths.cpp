// 横n, 高さa[0],..,a[n-1] のヤング図形上で (0,0) から (n,0),..,(n,a[n-1]) への経路数
// a 以下の increasing sequence と言ってもいい
// O(N log^2 N) ただし N = n + a[n-1]
// multiply がいる InitFact(N) を呼び出すのを忘れないこと
// n >= 1, a: non-decreasing >= 0
// verify: https://codeforces.com/gym/102220/problem/I

V<mint> CountYoungPaths(V<int> a,int h = -1){
	assert(!a.empty());
	if(h == -1) h = a.back();
	auto parallel = [&](V<mint> x, int w){
		int h = si(x)-1;
		V<mint> f(h+1);
		rep(i,h+1) f[i] = Choose(w+i,w);
		auto g = multiply(x,f); g.resize(h+1);
		return g;
	};
	auto vertical = [&](V<mint> x, int w){
		int h = si(x)-1;
		rep(i,h+1) x[i] *= ifact[h-i];
		V<mint> f(h+w+1); rep(i,h+w+1) f[i] = fact[i];
		auto g = multiply(x,f); g.resize(h+1);
		V<mint> res(w+1);
		rep(i,w+1) res[i] = g[h+i] * ifact[i];
		return res;	
	};

	// 横n, 高さa[0],..,a[n-1] のヤング図形がある
	// for 0<=j<=a[n-1], res[j] = \sum_{0<=i<=n} [ (i,0) から (n,j) まで行く通り数 ] * s[i]
	// ヤング図形の下と右にひげが生えてて、そこがin/outだと思うとわかりやすいかも？
	// h は a[n-1] より大きいかもしれない
	// お気持ち → s: 累積前 res: 累積後
	// こっちを外から直接呼び出したいこともある気がするね(下の値たちsが与えられてるときとか)
	auto rec = [&](auto& self, V<int> a, int h, V<mint> s)->V<mint>{
		assert(si(a)+1 == si(s));
		int n = si(a);
		if(n <= 1 || h <= 1){
			V<mint> res(h+1);
			a.pb(h);
			rep(i,n+1){
				res[0] += s[i];
				rep(j,a[i]) res[j+1] += res[j];
			}
			return res;
		}
		int m = n/2;
		auto le = self(self,V<int>(a.begin(),a.begin()+m),a[m],V<mint>(s.begin(),s.begin()+m+1));
		V<mint> dw(s.begin()+m+1,s.end());
		V<mint> res(h+1);
		V<mint> up(n-m);
		{
			auto le2ri = parallel(le,n-m-1);
			rep(i,si(le2ri)) res[i] += le2ri[i];
		}
		{
			auto le2up = vertical(le,n-m-1);
			rep(i,si(le2up)) up[i] += le2up[i];
		}
		{
			auto dw2ri = vertical(dw,a[m]);
			rep(i,si(dw2ri)) res[i] += dw2ri[i];
		}
		{
			auto dw2up = parallel(dw,a[m]);
			rep(i,si(dw2up)) up[i] += dw2up[i];
		}
		V<int> na(a.begin()+m+1,a.end()); for(int& v: na) v -= a[m];
		per(i,n-m-1) up[i+1] -= up[i];
		auto ur = self(self,na,h-a[m],up);
		rep1(i,si(ur)-1) res[a[m]+i] += ur[i];
		return res;
	};
	V<mint> s(si(a)+1); s[0] = 1;
	return rec(rec,a,h,s);
}

V<int> ConjugateYoung(V<int> a){
	if(a.empty()) return a;
	int w = a.back();
	V<int> b(w);
	int i = 0;
	rep(j,w){
		while(i<si(a) && a[i] == j) i++;
		b[w-1-j] = si(a)-i;
	}
	return b;
}
