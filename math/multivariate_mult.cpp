/*
	h[i1+j1][i2+j2]..[ik+jk] += f[i1][i2]..[ik] * g[i1][i2]..[ik] をする
	ただし 添字の範囲は 0 <= ip,jp < np で、足した結果一箇所でもはみ出た値は捨てる
	f,g は flatten されている (i1,i2,..,ik) が i1 + i2n1 + i3n1n2 + .. に対応する
	magicはcalc_magicで計算したのを使う

	O(knlogn + k^2n)
	まあ k は O(logn) なんで O(knlogn) っすね
	各次元を2倍にして愚直にやるとO(2^k nlogn) とかになるはずで、すげ～

	verify: https://yukicoder.me/problems/no/1783
*/
/*
	追加の雑なメモ
	multivariate_log するときに D log(f) = (D f) / f をどう解釈するか

	D log(f) = (D f) / f

	f = sum f[x][y] x^iy^j

	f[x] = sum f[x][*]

	(d/dx) log(f) = ((d/dx)f) / f

	l = log f
	g = ((d/dx)f) / f

	(d/dx) log(f) = ((d/dx)f) / f
	[x^i][y^j]

	(i+1) * l[i+1][j] = g[i][j]

	l[0][*] だけわからない

	l[*][0] だけわからない

	l[0][0] = 0

	gの計算　（割り算）がk回　おそい


	Dx = x(d/dx) とすると
	Dx log(f) = (Dx f) / f がなりたつ

	D = Dx + Dy
	D log(f) = (D f) / f がなりたつ

	[x^iy^jz^k] (1Dx + n1Dy + n1n2Dz) log(f) = [x^iy^j] (((1Dx + n1Dy + n1n2Dz) f) / f)


	l[i][j][k] = g[i][j][k] / (i+j*n1+k*n1n2)
		flattenしたindexをそのままかけてできる

	l[0][0][0] = 0
*/
V<int> calc_magic(const vector<int>& ns){
	int k = si(ns);
	if(k == 0) return {};
	int n = 1;
	for(int ni: ns) n *= ni;
	V<int> magic(n);
	rep(i,n){
		int x = i;
		rep(j,k){
			magic[i] += x;
			x /= ns[j];
		}
		magic[i] %= k;
	}
	return magic;
}
vector<mint> multivariate_mult(const vector<mint>& f, const vector<mint>& g, const vector<int>& ns, const vector<int>& magic){
	assert(si(f) == si(g));
	int n = si(f);
	int k = si(ns);
	if(k == 0){
		return {f[0]*g[0]};
	}
	int s = 1; while(s<n*2-1) s*=2;
	vector<mint> h(n);
	vector<vector<mint>> zf(k,vector<mint>(s));
	vector<vector<mint>> zg(k,vector<mint>(s));
	vector<vector<mint>> zh(k,vector<mint>(s));
	rep(i,n) zf[magic[i]][i] = f[i];
	rep(i,k) fft(zf[i]);
	rep(i,n) zg[magic[i]][i] = g[i];
	rep(i,k) fft(zg[i]);
	rep(a,k) rep(b,k){
		int c = (a+b)%k;
		rep(i,s) zh[c][i] += zf[a][i] * zg[b][i];
	}
	rep(i,k) invfft(zh[i]);
	rep(i,n) h[i] = zh[magic[i]][i];
	return h;
}
