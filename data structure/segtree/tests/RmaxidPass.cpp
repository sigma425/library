#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
using namespace std;
/*
	RmaxPassと似てるが,返すのはP(max,それを実現するidのうち最も左)
	(最も右,の場合はoperatorの定義でx.sc>y.scにする)
*/
typedef pair<int,int> P;
P operator+(const P& x,const P& y){
	if(x.fs>y.fs||(x.fs==y.fs&&x.sc<y.sc)) return x;
	else return y;
}
int inf=1e9;
struct segtree{
	static const int N=1<<16;
	P seg[N*2];
	
	void update(int k,int val){
		seg[k+N]=P(val,k);
		k+=N;
		k/=2;
		while(k){
			seg[k]=seg[k*2]+seg[k*2+1];
			k/=2;
		}
	}
	void init(){
		rep(i,N) seg[i+N]=P(-inf,i);
		for(int i=N-1;i>0;i--) seg[i]=seg[i*2]+seg[i*2+1];
	}
	P getmax(int a,int b,int l=0,int r=N,int k=1){
		if(b<=l||r<=a) return P(-inf,-1);
		if(a<=l&&r<=b) return seg[k];
		return getmax(a,b,l,(l+r)/2,k*2)+getmax(a,b,(l+r)/2,r,k*2+1);
	}
};
int main(){
	
}