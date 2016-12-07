//https://judge.npca.jp/problems/view/97
#include <iostream>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int MX=200000*19;
struct node{
	node *lch,*rch;
	int num;
	node(node *l,node *r,int n){
		lch=l,rch=r,num=n;
	}
	node(node *l,node *r){
		lch=l,rch=r,num=lch->num+rch->num;
	}
	node(){}
};
node pool[MX];
node *root[200001];
node *nil;
int sit;
node *news(node *lch,node *rch,int num){
	return &(pool[sit++]=node(lch,rch,num));
}
node *news(node *lch,node *rch){
	return &(pool[sit++]=node(lch,rch));
}
node *fix(node *x,int pos,int l,int r){
//	printf("pos,l,r=(%d,%d,%d)\n",pos,l,r);
	if(r-l==1){
		return news(nil,nil,x->num+1);
	}
	int m=(l+r)/2;
	if(pos<m){
		return news(fix(x->lch,pos,l,m),x->rch);
	}else{
		return news(x->lch,fix(x->rch,pos,m,r));
	}
}
int getnum(int a,int b,int l,int r,node *x){
	if(x==nil) return 0;
	if(b<=l||r<=a) return 0;
	if(a<=l&&r<=b) return x->num;
	int m=(l+r)/2;
	return getnum(a,b,l,m,x->lch)+getnum(a,b,m,r,x->rch);
}
void showtree(node *x){
	if(x==nil) return;
	cout<<"(";
	showtree(x->lch);
	cout<<x->num;
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
		int cnt=getnum(l[i],r[i],0,N,root[x+1]);
		x=((long long)cnt*l[i]+r[i])%(i+2);
	}
	cout<<x<<endl;
}