/*
使わないこと！！！！！！！！！！！！！！



modは2^m+1 しかもprime?
原始根を求める必要がある
*/
typedef long long ll;
typedef vector<ll> poly;
ll mod;
ll ex(ll x,ll p){
	ll a=1;
	while(p){
		if(p%2) a=a*x%mod;
		x=x*x%mod;
		p/=2;
	}
	return a;
}
void FFT(poly a,int n,ll w){			//←魔剤！？
	mod=n+1;
	for(int m=n;m>=2;m/=2){
		int mh=m/2;
		ll b=1;
		rep(i,mh){
			for(int j=i;j<n;j+=m){
				int k=j+mh;
				ll x=(a[j]-a[k])%mod;
				a[j]=(a[j]+a[k])%mod;
				a[k]=b*x%mod;
			}
			b=b*w%mod;
		}
		w=w*w%mod;
	}
	int i=0;
	for(int j=1;j<n-1;j++){
		for(int k=n/2;k>(i^=k);k/=2);
		if(j<i) swap(a[i],a[j]);
	}
}
poly pro(poly a,poly b){
	int m=a.size()+b.size();
	int n=1;
	while(n<m) n*=2;
	mod=n+1;
	ll w;
	for(int i=2;;i++){
		if(ex(i,n/2)!=1){
			w=i;
			break;
		}
	}
	a.resize(n);
	b.resize(n);
	FFT(a,n,w);
	FFT(b,n,w);
	rep(i,n) a[i]=a[i]*b[i]%mod;
	FFT(a,n,ex(w,n-1));
	rep(i,n) C[i]=C[i]*n%mod;
	return C;
}