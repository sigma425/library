/*
	query(i): f_i, g_i を受け取って fg_i を返す
	O(n log^2)
	2^18: 300ms
	2^19: 700ms
	2^20: 1500ms

	[0] [12] [3456] [7..14] .. とわけてうまくやる
*/
template<class mint>
struct Online_Convolution{
	const int thresh = 3;
	V<mint> f,g,h;
	VV<mint> fft_f,fft_g;

	pair<V<mint>,V<mint>> calc_fft(int k){
		// 長さ 2^k の suffix を fft したものを返す
		int L = 1<<k;
		V<mint> f_suf(2*L), g_suf(2*L);
		rep(i,L){
			f_suf[i] = f[si(f)-L+i];
			g_suf[i] = g[si(g)-L+i];
		}
		if(k > thresh){
			fft(f_suf); fft(g_suf);
		}
		return {f_suf, g_suf};
	}
	void calc(int k){
		int L = 1<<k;
		auto [zf,zg] = calc_fft(k);
		V<mint> zh(L*2);
		bool fst = (k >= si(fft_f));
		if(fst){
			fft_f.eb(zf);
			fft_g.eb(zg);
		}
		if(k > thresh){
			if(fst){
				rep(i,L*2) zh[i] += zf[i] * zg[i];
				invfft(zh);
			}else{
				rep(i,L*2){
					zh[i] += zf[i] * fft_g[k][i];
					zh[i] += zg[i] * fft_f[k][i];
				}
				invfft(zh);
			}
		}else{
			if(fst){
				rep(i,L) rep(j,L) zh[i+j] += zf[i] * zg[j];
			}else{
				rep(i,L) rep(j,L) zh[i+j] += zf[i] * fft_g[k][j];
				rep(i,L) rep(j,L) zh[i+j] += zg[i] * fft_f[k][j];
			}
		}
		int off = si(f)-1;
		rep(i,L*2-1){
			if(si(h) <= off+i) h.eb(0);
			h[off + i] += zh[i];
		}
	}

	mint query(int i, mint f_i, mint g_i){
		assert(i == si(f));
		f.eb(f_i);
		g.eb(g_i);
		int K = __builtin_ctz(i+2) + (__builtin_popcount(i+2) > 1 ? 1 : 0);
		rep(k,K) calc(k);
		return h[i];
	}
};

/*
	query(i): f_i, g_i を受け取って (f/g)_i を返す
	g_0 != 0 を仮定
	O(n log^2)
*/
template<class mint>
struct Online_Division{
	V<mint> f,g,h;
	Online_Convolution<mint> X;
	mint ig0;

	mint query(int i, mint f_i, mint g_i){
		assert(i == si(f));
		f.eb(f_i);
		g.eb(g_i);
		if(i == 0){
			assert(g_i);
			ig0 = g_i.inv();
			h.eb(f_i * ig0);
		}else{
			h.eb( (f_i - X.query(i-1,g[i],h[i-1])) * ig0);
		}
		return h[i];
	}
};

/*
	query(i): f_i を受け取って (f^K)_i を返す
	f_0 != 0 を仮定 (頑張れば外せる)
	O(n log^2)
	g := f^K
	g'f = Kgf'
		f_0 g_1		f_0 2g_2 + f_1 g_1		f_0 3g_3 + f_1 2g_2 + f_2 g_1
	= K(f_1 g_0		2f_2 g_0 + f_1 g_1		3f_3 g_0 + 2f_2 g_1 + f_1 g_2
*/
template<class mint>
struct Online_Pow{
	Online_Pow(ll K_):K(K_){}

	V<mint> f,g;
	ll K;
	Online_Convolution<mint> X;		// (f-f0)/x * g'
	Online_Convolution<mint> Y;		// f' * g
	mint if0;

	mint query(int i, mint f_i){
		assert(i == si(f));
		f.eb(f_i);
		if(i == 0){
			assert(f_i);
			if0 = f_i.inv();
			g.eb(f_i.pow(K));
		}else{
			mint Y_i = Y.query(i-1,f[i]*i,g[i-1]);
			mint X_i = i == 1 ? 0 : X.query(i-2,f[i-1],g[i-1]*(i-1));
			assert(i < si(invs));
			g.eb( (Y_i*K - X_i) * if0 * invs[i]);
		}
		return g[i];
	}
};

/*
	FFT とは限らない時にオンラインで h[i+j] = f[i]*g[j] をしたいとき
	calc(a,b,c,d) で f[a,b) * g[c,d) を足し込む
*/
struct Online_Convolution_Any{
	void calc(int a,int b,int c,int d){
		// f[a,b) * g[c,d)
		for(int i=a;i<b;i++) for(int j=c;j<d;j++){
			cerr << "(" << i << " , " << j << ")" << endl;
		}
	}

	int SI = 0, GI = 0;
	void set_i(int i){
		cerr << "set " << i << endl;
		assert(SI == i); SI++;
	}
	void get_i(int i){
		cerr << "get " << i << endl;
		assert(GI == i); GI++;
		assert(i < SI);
		int K = __builtin_ctz(i+2) + (__builtin_popcount(i+2) > 1 ? 1 : 0);
		rep(k,K){
			int L = 1<<k;
			int a = L-1, b = L-1+1, c = i+1-L, d = i+1;
			calc(a,b,c,d);
			if(a != c) calc(c,d,a,b);
		}
	}
};