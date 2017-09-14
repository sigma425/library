/*
	point assign
	range sum
	int/long long/double
*/
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
#define chmax(x,y) x=max(x,y)
using namespace std;

struct segtree{
	using D = long long;

	int N;
	vector<D> val;

	segtree(){}
	segtree(int n){
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,0);
	}
	segtree(const vector<D>& ds){
		int n = ds.size();
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,0);
		rep(i,n) val[i+N] = ds[i];
		for(int i=N-1;i>0;i--) val[i] = val[i*2] + val[i*2+1];
	}
	void assign(int k,D d){
		k+=N;
		val[k]=d;
		k/=2;
		while(k){
			val[k] = val[k*2] + val[k*2+1];
			k/=2;
		}
	}
	D sum(int a,int b){		//non-commutative & unrecursive
		D res = 0;
		a+=N,b+=N;
		while(a<b){
			if(a&1) res += val[a++];
			if(b&1) res += val[--b];
			a/=2,b/=2;
		}
		return res;
	}
};

int main(){
	vector<long long> vc = {1,2,3,4};
	segtree seg(vc);
	assert(seg.sum(2,4) == 7);
	seg.assign(0,-100);
	assert(seg.sum(0,3) == -95);
}