/*
https://www.codechef.com/JULY16/problems/POLYEVAL
p=2^18 *3 +1
Z/pZ上の多項式の全点での値を計算
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
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
typedef long long ll;
ll mod=786433;
void NTT(vector<ll>& a,ll x){
	int N=a.size();
	if(N==3){
		ll y=x*x%mod;
		ll A=(a[0]+a[1]+a[2])%mod;
		ll B=(a[0]+a[1]*x+a[2]*y)%mod;
		ll C=(a[0]+a[1]*y+a[2]*y%mod*y)%mod;
		a[0]=A,a[1]=B,a[2]=C;
		return;
	}
	vector<ll> b(N/2),c(N/2);
	rep(i,N/2) b[i]=a[i*2],c[i]=a[i*2+1];
	NTT(b,x*x%mod);
	NTT(c,x*x%mod);
	ll w=1;
	rep(i,N/2){
		a[i]=(b[i]+w*c[i])%mod;
		a[i+N/2]=(b[i]-w*c[i])%mod;
		w=w*x%mod;
	}
}

vector<ll> a(mod-1),ans(mod);
int main(){
	int h=10;
	int N,Q;
	scanf("%d",&N);
	rep(i,N+1) scanf("%lld",&a[i]);
	ans[0]=a[0];
	NTT(a,h);
	rep(i,mod-1) if(a[i]<0) a[i]+=mod;
	ll x=1;
	rep(i,mod-1){
		ans[x]=a[i];
		x=x*h%mod;
	}
	scanf("%d",&Q);
	rep(t,Q){
		int x;
		scanf("%d",&x);
		printf("%lld\n",ans[x]);
	}
}
