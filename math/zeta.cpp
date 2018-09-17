/* zeta
S:(subset of N) -> f(S) から
g(S)=sigma f(T) for all T>S を求める
g(10010) = sigma f(1**1*)
*/
void zeta(int* f,int N){
	rep(i,N) rep(j,1<<N) if(0==(j&1<<i)) f[j]+=f[j|(1<<i)];
}
/*
T<Sの和
g(10010) = sigma f(*00*0)
*/
void zeta(int *f,int N){
	rep(i,N) for(int j=(1<<N)-1;j>=0;j--) if((j>>i)&1) f[j]+=f[j^(1<<i)];
}

/*逆変換(Mebius)
gからfを求める
*/
void mebius(int *g,int N){
	rep(i,N) for(int j=(1<<N)-1;j>=0;j--) if(0==(j&1<<i)) g[j]-=g[j^(1<<i)];
}
/*T<Sバージョン*/
void mebius(int *g,int N){
	rep(i,N) rep(j,1<<N) if(j&(1<<i)) g[j]-=g[j^(1<<i)];
}
