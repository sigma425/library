const int MX=;
ll f[MX+1],g[MX+1],inv[MX+1];
void precalc(){
	f[0]=1;
	rep1(i,MX) f[i]=f[i-1]*i%mod;
	inv[1]=1;
	for(int i=2;i<=MX;i++) inv[i]=mod-mod/i*inv[mod%i]%mod;
	g[0]=1;
	rep1(i,MX) g[i]=g[i-1]*inv[i]%mod;
}
ll C(int x,int y){
	if(y<0 || x<y) return 0;
	return f[x]*g[y]%mod*g[x-y]%mod;
}

mint f[MX],g[MX],inv[MX];
void precalc(){
	f[0]=1;
	rep1(i,MX-1) f[i] = f[i-1] * i;

	const int mod = 1e9+7;
	inv[1]=1;
	for(int i=2;i<=MX-1;i++) inv[i] = -inv[mod%i] * (mod/i);

	g[0]=1;
	rep1(i,MX-1) g[i] = g[i-1] *inv[i];
}
mint C(int x,int y){
	if(y<0 || x<y) return 0;
	return f[x]*g[y]*g[x-y];
}
