//↓非再帰 extgcd
ll extgcd(ll a,ll b,ll &x,ll &y){
	ll u[]={a,1,0},v[]={b,0,1};
	while(*v){
		ll t=*u/ *v;
		rep(i,3) swap(u[i]-=t*v[i],v[i]);
	}
	if(u[0]<0) rep(i,3) u[i]=-u[i];
	x=u[1],y=u[2];
	return u[0];
}
ll inv(ll a){
	ll x,y;
	extgcd(a,mod,x,y);
	if(x<0) x+=mod;
	return x;
}


int extgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	int g=extgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return g;
}
int inv(int a){
	int x,y;
	extgcd(a,mod,x,y);
	return x;
}
ll ex(ll a,ll x){
	ll ret=1;
	while(x){
		if(x%2) ret=ret*a%mod;
		a=a*a%mod;
		x/=2;
	}
	return ret;
}
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
ll extgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	ll g=extgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return g;
}
ll inv(ll a){
	ll x,y;
	extgcd(a,mod,x,y);
	return x;
}
//↓非再帰 extgcd
ll extgcd(ll a,ll b,ll &x,ll &y){
	ll u[]={a,1,0},v[]={b,0,1};
	while(*v){
		ll t=*u/ *v;
		rep(i,3) swap(u[i]-=t*v[i],v[i]);
	}
	if(u[0]<0) rep(i,3) u[i]=-u[i];
	x=u[1],y=u[2];
	return u[0];
}