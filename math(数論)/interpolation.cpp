/*
	多項式補間
	Lagrange interpolation
	O(N^2)
	N点(xs[i],ys[i])が与えられた時にそれを通るN-1次多項式のxでの値を返す
	xs[i]がpairwise distinctじゃないとダメ

	Z/pZとかにするなら割り算とかをちゃんと書き換えること
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
	T ret=0;
	rep(i,N){
		T a=ys[i];
		rep(j,N) if(j!=i) a*=(x-xs[j])/(xs[i]-xs[j]);
		ret+=a;
	}
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
