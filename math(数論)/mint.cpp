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
struct mint{
	const static ll mod=2;
	ll a;
	mint():a(0){}
	mint(ll a):a((a%mod+mod)%mod){}
	mint operator+=(const mint& b){ if((a+=b.a)>=mod) a-=mod; return *this;}
	mint operator-=(const mint& b){ if((a+=mod-b.a)>=mod) a-=mod; return *this;}
	mint operator*=(const mint& b){ (a*=b.a)%=mod; return *this;}
	mint operator+(const mint& b){ return mint(*this)+=b;}
	mint operator-(const mint& b){ return mint(*this)-=b;}
	mint operator*(const mint& b){ return mint(*this)*=b;}
	mint operator-(){ return mint(-a); }
	int extgcd(int a,int b,int &x,int &y) const{
		int u[]={a,1,0},v[]={b,0,1};
		while(*v){
			int t=*u/ *v;
			rep(i,3) swap(u[i]-=t*v[i],v[i]);
		}
		if(u[0]<0) rep(i,3) u[i]=-u[i];
		x=u[1],y=u[2];
		return u[0];
	}
	mint inv() const{
		int x,y;
		extgcd(a,mod,x,y);
		if(x<0) x+=mod;
		return mint(x);
	}
	mint operator/=(const mint& b){ (*this)*=b.inv(); return *this; }
	mint operator/(const mint& b){ return mint(*this)/=b;}
	bool operator==(const mint& b) const { return a==b.a;}
	friend ostream& operator<<(ostream &o,const mint& x){ return o<<x.a;}
};
int main(){
	while(true){
		int a,b;
		char c;
		cin>>a>>c>>b;
		mint x(a),y(b);
		cout<<" = ";
		if(c=='+') cout<<x+y;
		if(c=='-') cout<<x-y;
		if(c=='*') cout<<x*y;
		if(c=='/') cout<<x/y;
		cout<<endl;
	}
}
