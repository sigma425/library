/*
	point assign
	range min
	int/long long/double
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

	int N;
	vector<D> val;

	segtree(){}
	segtree(int n){
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,inf);
	}
	segtree(const vector<D>& ds){
		int n = ds.size();
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,inf);
		rep(i,n) val[i+N] = ds[i];
		for(int i=N-1;i>0;i--) val[i] = min(val[i*2],val[i*2+1]);
	}
	void assign(int k,D d){
		k+=N;
		val[k]=d;
		k/=2;
		while(k){
			val[k] = min(val[k*2],val[k*2+1]);
			k/=2;
		}
	}
	D getmin(int a,int b){
		D res = inf;
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
	vector<long long> vc = {1,2,3,4};
	segtree seg(vc);
	assert(seg.getmin(2,4) == 3);
	seg.assign(0,-100);
	assert(seg.getmin(0,3) == -100);
}