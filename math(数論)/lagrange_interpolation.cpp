/*
	多項式補間
	Lagrange interpolation
	O(N^2)
	N点(xs[i],ys[i])が与えられた時にそれを通るN-1次多項式のxでの値を返す
	xs[i]がpairwise distinctじゃないとダメ
	あとxs[i]==xになるときにちゃんと処理する必要がある doubleとかで誤差でxs[i]==x+epsみたいなのに注意

	Z/pZとかにするなら割り算とかをちゃんと書き換えること


	多項式自体を求めたいときは(x-xs[j])の部分が多項式の掛け算なので、全体でO(N^3)になる,
	戻すDPっぽいのをやるとO(N^2)だが面倒そう
	Newton補間使ったほうが良くない?

	OpenCup/1101/I.cpp がmint,poly,interpolationを複合して使ってる例

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
template<class T>
T interpolate(vector<T> xs,vector<T> ys,T x){
	int N=xs.size();
	rep(i,N){
		if(xs[i]==x) return ys[i];
	}
	T ret=0;
	rep(i,N){
		T a=ys[i];
		rep(j,N) if(j!=i) a*=(x-xs[j])/(xs[i]-xs[j]);
		ret+=a;
	}
	return ret;
}
ll interpolate(vector<ll> xs,vector<ll> ys,ll x){
	int N=xs.size();
	rep(i,N){
		if(xs[i]==x) return ys[i];
	}
	ll ret=0;
	rep(i,N){
		ll a=ys[i];
		rep(j,N) if(j!=i) a=a*(x-xs[j])%mod*inv(xs[i]-xs[j])%mod;
		ret+=a;
	}
	ret=(ret%mod+mod)%mod;
	return ret;
}
int main(){
	int N;
	vector<double> xs,ys;
	cin>>N;
	rep(i,N){
		double x,y;
		cin>>x>>y;
		xs.pb(x);
		ys.pb(y);
	}
	while(true){
		double x;
		cin>>x;
		printf("%.12f\n",interpolate(xs,ys,x));
	}
}
