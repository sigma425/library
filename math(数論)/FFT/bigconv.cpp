/*
適当なmodたちで計算する→garner's algorithm
入力がvector<int>なら長さ2^22程度,値2^31で,各成分は2^22*(2^31)^2とかになるので3つでOK
N=2^20でNNT.conv()が4.5秒くらいかかるので,やばいかもしれない

2^23より大きく，primitive rootに3を持つもの
const int mods[] = { 1224736769, 469762049, 167772161, 595591169, 645922817, 897581057, 998244353 };

*/


#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;

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

struct NTT{
	const int mod,g;
	NTT(int mod,int g) :mod(mod),g(g){}
	ll ex(ll x,ll p){
		ll a=1;
		while(p){
			if(p%2) a=a*x%mod;
			x=x*x%mod;
			p/=2;
		}
		return a;
	}
	ll inv(ll a){
		ll b=mod,u=1,v=0;
		while(b){
			ll t=a/b;
			swap(a-=t*b,b);
			swap(u-=t*v,v);
		}
		u%=mod;
		if(u<0) u+=mod;
		return u;
	}
	void ntt(vector<ll>& a,ll h){
		int N=a.size();
		for(int m=N;m>=2;m/=2){
			int mh=m/2;
			ll w=1;
			rep(i,mh){
				for(int j=i;j<N;j+=m){
					int k=j+mh;
					ll x=(a[j]-a[k]);
					a[j]+=a[k];
					if(a[j]>=mod) a[j]-=mod;
					a[k]=w*x%mod;
					if(a[k]<0) a[k]+=mod;
				}
				w=w*h%mod;
			}
			h=h*h%mod;
		}
		int i=0;
		rep1(j,N-2){
			for(int k=N/2;k>(i^=k);k/=2);
			if(j<i) swap(a[i],a[j]);
		}
	}
	vector<ll> conv(vector<ll> a,vector<ll> b){		// (mod-1)%N==0でないとだめ!!
		for(auto& x:a) x%=mod;
		for(auto& x:b) x%=mod;
		int n=a.size()+b.size();
		int N=1;
		while(N<n) N*=2;
		a.resize(N),b.resize(N);
		assert((mod-1)%N==0);
		ll h=ex(g,(mod-1)/N);
		ntt(a,h),ntt(b,h);
		rep(i,N) (a[i]*=b[i])%=mod;
		h=inv(h);
		ntt(a,h);
		h=inv(N);
		rep(i,N) (a[i]*=h)%=mod;
		return a;
	}
};

vector<ll> ms={167772161,469762049,1224736769},gs={3,3,3}; 
vector<ll> bigconv(vector<ll> a,vector<ll> b,int mod){
	vector<ll> vs[3];
	rep(i,3) vs[i]=NTT(ms[i],gs[i]).conv(a,b);
	int N=vs[0].size();
	vector<ll> ret(N);
	rep(i,N){
		vector<P> rm;
		rep(j,3) rm.pb(P(vs[j][i],ms[j]));
		ret[i]=garner(rm,mod);
	}
	return ret;
}
int main(){
	int N,M,mod;
	cin>>N>>M>>mod;
	vector<ll> a(N),b(M);
	rep(i,N) cin>>a[i];
	rep(i,M) cin>>b[i];
	vector<ll> c=bigconv(a,b,mod);
	for(ll x:c) cout<<x<<" ";
	puts("");
}