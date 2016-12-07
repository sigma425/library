/*
	x % rm[i].sc = rm[i].fs
	をみたす非負整数のうち最小のもの%mod を求める
	0をのぞくなら,全0のときのみas[N-1]を返せば良い
	rm[i].sc,modはpairwise relatively prime
*/
typedef long long ll;
typedef pair<ll,ll> P;		//val,mod;
ll inv(ll a,ll m){
	ll b=m,u=1,v=0;
	while(b){
		ll t=a/b;
		swap(a-=t*b,b);
		swap(u-=t*v,v);
	}
	u%=m;
	if(u<0) u+=m;
	return u;
}
ll garner(vector<P> rm,ll mod){		//remainder,mod
	rm.pb(P(0,mod));
	int N=rm.size();
	vector<ll> as(N,1);		//coefficients
	vector<ll> bs(N,0);		//constants
	rep(i,N-1){
		ll v=(rm[i].fs-bs[i])*inv(as[i],rm[i].sc)%rm[i].sc;
		if(v<0) v+=rm[i].sc;
		for(int j=i+1;j<N;j++){
			(bs[j]+=as[j]*v)%=rm[j].sc;
			(as[j]*=rm[i].sc)%=rm[j].sc;
		}
	}
	return bs[N-1];
}
