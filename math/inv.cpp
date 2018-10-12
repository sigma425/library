vector<mint> fac,ifac,inv;
void precalc(int N){	//[0,N]
	N++;
	fac.resize(N);
	ifac.resize(N);
	inv.resize(N);
	fac[0]=1;
	rep1(i,N-1) fac[i] = fac[i-1] * i;

	const int mod = 1e9+7;
	inv[1]=1;
	for(int i=2;i<=N-1;i++) inv[i] = -inv[mod%i] * (mod/i);

	ifac[0]=1;
	rep1(i,N-1) ifac[i] = ifac[i-1] *inv[i];
}
mint Binom(int x,int y){
	if(y<0 || x<y) return 0;
	return fac[x] * ifac[y] * ifac[x-y];
}
