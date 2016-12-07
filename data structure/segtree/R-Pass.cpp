/*
	point assign, range なんらか(operator +)
*/
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
using namespace std;
/*
	point assign,range ほげ
	書くものは
	D op()	(演算)
	D e		(単位元)
*/
struct segtree{
	static const int N=1<<;
	D seg[N*2],e=;
	segtree(vector<D>& vc){
		rep(i,N) seg[i+N]=e;
		rep(i,vc.size()) seg[i+N]=vc[i];
		for(int i=N-1;i>0;i--) seg[i]=op(seg[i*2],seg[i*2+1]);
	}
	D op(const D& x,const D& y){

	}
	void update(int k,D val){
		k+=N;
		seg[k]=val;
		k/=2;
		while(k){
			seg[k]=op(seg[k*2],seg[k*2+1]);
			k/=2;
		}
	}
	D calc(int a,int b,int l=0,int r=N,int k=1){
		if(b<=l||r<=a) return e;
		if(a<=l&&r<=b) return seg[k];
		return op(calc(a,b,l,(l+r)/2,k*2),calc(a,b,(l+r)/2,r,k*2+1));
	}
};
int main(){
	
}