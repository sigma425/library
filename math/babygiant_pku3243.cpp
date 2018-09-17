//g in group G, x in set X
#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,N) for(int i=0;i<N;i++)
#define rep1(i,N) for(int i=1;i<=N;i++)
#define fs first
#define sc second
#define mp make_pair
using namespace std;
const int BN=32000,GN=32000;
typedef long long ll;
typedef ll G;
typedef ll X;
ll mod;
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
ll extgcd(ll a,ll b,ll &x,ll &y){
	ll g=a;
	x=1,y=0;
	if(b!=0) g=extgcd(b,a%b,y,x),y-=a/b*x;
	return g;
}
ll inv(ll a,ll mod){
	ll x,y;
	extgcd(a,mod,x,y);
	x%=mod;
	if(x<0) x+=mod;
	return x;
}

X act(G g,X x){
	return g*x%mod;
}
G pro(G f,G g){
	return f*g%mod;
}
G ex(G g,int N){
	G e=1;
	while(N){
		if(N%2) e=pro(g,e);
		g=pro(g,g);
		N>>=1;
	}
	return e;
}
int solve2(G g,X s,X t){		//calc min k s.t.{g^n(s)=t}		if no ans, -1
	s%=mod,t%=mod,g%=mod;
	if(s==t) return 0;
	pair<X,int> babies[BN];
	rep(i,BN){	//0~BN-1
		babies[i]=mp(t,i);
		t=act(g,t);
	}
	sort(babies,babies+BN);
	g=ex(g,BN);	//g->g^BN
	rep1(i,GN){		//1~GN
		s=act(g,s);
		int pos=upper_bound(babies,babies+BN,mp(s,BN))-babies-1;
		if(pos>=0&&babies[pos].fs==s) return i*BN-babies[pos].sc;
	}
	return -1;
}
int solve(G g,X s,X t){
	s%=mod,t%=mod,g%=mod;
	if(s==t) return 0;
	rep1(i,50){
		s=act(g,s);
		if(s==t) return i;
	}
	ll g1=gcd(s,mod),g2=gcd(t,mod);
	if(g1!=g2) return -1;
	mod/=g1;
	ll tmp=solve2(g,s,t);
	if(tmp>=0) return tmp+50;
	return -1;
}
int brute(G g,X s,X t){
	s%=mod,t%=mod,g%=mod;
	if(s==t) return 0;
	rep(i,1000000){
		s=act(g,s);
		if(s==t) return i+1;
	}
	return -1;
}
int main(){
	while(true){
		ll x,z,k;
		cin>>x>>z>>k;
		if(z==0) break;
		mod=z;
		ll tmp=solve(x,1,k);
		if(tmp>=0) cout<<tmp<<endl;
		else puts("No Solution");
	}
}