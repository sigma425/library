/*
永続segtree
書いてる途中

verified by https://judge.npca.jp/problems/view/97
			http://codeforces.com/contest/484/problem/E
*/


#include <iostream>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int MX=200000*19;
struct node{
	node *lch,*rch;
	int sum;
	node(node *l,node *r,int s):lch(l),rch(r),sum(s){}
	node(node *l,node *r){
		lch=l,rch=r,sum=lch->sum+rch->sum;
	}
	node(){}
};
node pool[MX];
node* root[200001];
node* nil;
int SI;
node* news(node *lch,node *rch,int sum){
	return &(pool[SI++]=node(lch,rch,sum));
}
node* news(node *lch,node *rch){
	return &(pool[SI++]=node(lch,rch));
}
node* update(node *x,int pos,int l,int r){
//	printf("pos,l,r=(%d,%d,%d)\n",pos,l,r);
	if(r-l==1){
		return news(nil,nil,x->sum);
	}
	int m=(l+r)/2;
	if(pos<m){
		return news(fix(x->lch,pos,l,m),x->rch);
	}else{
		return news(x->lch,fix(x->rch,pos,m,r));
	}
}
int getsum(int a,int b,int l,int r,node *x){
	if(x==nil) return 0;		//初期値が変なのならここを変える
	if(b<=l||r<=a) return 0;
	if(a<=l&&r<=b) return x->sum;
	int m=(l+r)/2;
	return getsum(a,b,l,m,x->lch)+getsum(a,b,m,r,x->rch);
}
void showtree(node *x){
	if(x==nil) return;
	cout<<"(";
	showtree(x->lch);
	cout<<x->sum;
	showtree(x->rch);
	cout<<")";
}
int N,l[200000],r[200000];
int main(){
	nil=news(0,0,0);
	nil->lch=nil->rch=nil;
	cin>>N;
	rep(i,N) cin>>l[i];
	rep(i,N) cin>>r[i];
	int x=0;
	root[0]=nil;
	rep(i,N){
//		showtree(root[i]);puts("");
		root[i+1]=fix(root[i],x,0,N);
		int cnt=getsum(l[i],r[i],0,N,root[x+1]);
		x=((long long)cnt*l[i]+r[i])%(i+2);
	}
	cout<<x<<endl;
}