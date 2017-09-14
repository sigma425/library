/*
	point assign
	range leftmost argmin
	int/long long/(double)
	double なら 比較関数を変える
*/
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;

struct segtree{
	using D = long long;
	D inf = 1e18;
	using P = pair<D,int>;

	int N;
	vector<P> val;
	
	segtree(){}
	segtree(int n){
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,P(inf,-1));
		rep(i,n) val[i+N].sc = i;
		for(int i=N-1;i>0;i--) val[i] = min(val[i*2],val[i*2+1]);
	}
	segtree(const vector<D>& ds){
		int n = ds.size();
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,P(inf,-1));
		rep(i,n) val[i+N] = P(ds[i],i);
		for(int i=N-1;i>0;i--) val[i] = min(val[i*2],val[i*2+1]);
	}
	void assign(int k,D d){
		k+=N;
		val[k]=P(d,k-N);
		k/=2;
		while(k){
			val[k] = min(val[k*2],val[k*2+1]);
			k/=2;
		}
	}
	P getmina(int a,int b){	//P(min,leftmost argmin)
		P res = P(inf,-1);
		a+=N,b+=N;
		while(a<b){
			if(a&1) chmin(res,val[a++]);
			if(b&1) chmin(res,val[--b]);
			a/=2,b/=2;
		}
		return res;
	}
};

int main(){
	vector<long long> vc = {3,2,3,4};
	segtree seg(vc);
	using P = pair<long long,int>;
	assert(seg.getmina(0,3) == P(2,1));
	seg.assign(1,100);
	assert(seg.getmina(0,3) == P(3,0));
}