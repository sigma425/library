//AOJ1508
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cstring>
#include <functional>
#include <cmath>
#include <utility>
#include <complex>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define all(c) (c).begin(),(c).end()
#define fs first
#define sc second
#define pb push_back
#define show(x) cout << #x << " " << x << endl
#define chmin(x,y) x=min(x,y);
int inf=1e9;
unsigned int xor128(){
	static unsigned int x=123456789,y=362436069,z=521288629,w=88675123;
	unsigned int t;
	t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) );
}
struct node{	//node of RBST
	int val,mn,size;
	node *lch,*rch;
	node(int v){
		val=mn=v;
		size=1;
		lch=0,rch=0;
	}
};
typedef pair<node*,node*> Pnn;
node *root;
//すべての関数は操作した後の木の親のポインタを返す
node *update(node *x){
	x->size=1;
	x->mn=x->val;
	if(x->lch){
		x->size+=x->lch->size;
		chmin(x->mn,x->lch->mn);
	}
	if(x->rch){
		x->size+=x->rch->size;
		chmin(x->mn,x->rch->mn);
	}
	return x;
}
node *merge(node *x,node *y){
	if(x==0) return y;
	if(y==0) return x;
	int m=x->size,n=y->size;
	if(xor128()%(m+n)<m){
		x->rch=merge(x->rch,y);
		return update(x);
	}else{
		y->lch=merge(x,y->lch);
		return update(y);
	}
}
int count(node *x){
	if(x==0) return 0;
	return x->size;
}
Pnn split(node *x,int pos){		//[,pos),[pos,)
	if(x==0) return Pnn(0,0);
	if(pos<=count(x->lch)){
		Pnn tmp=split(x->lch,pos);
		x->lch=tmp.sc;
		return Pnn(tmp.fs,update(x));
	}else{
		Pnn tmp=split(x->rch,pos-count(x->lch)-1);
		x->rch=tmp.fs;
		return Pnn(update(x),tmp.sc);
	}
}
node *insert(node *x,int pos,int val){
	node *p = new node(val);
	Pnn tmp=split(x,pos);
	node *l=merge(tmp.fs,p),*r=tmp.sc;
	return merge(l,r);
}
node *erase(node *x,int pos){
	Pnn tmp=split(x,pos);
	node *l=tmp.fs,*r=split(tmp.sc,1).sc;
	return merge(l,r);
}
void showtree(node *c){
	if(!c) return;
	cout<<"(";
	showtree(c->lch);
	cout<<"-"<< c->val <<"-";
	showtree(c->rch);
	cout<<")";
}
void query0(int b,int c){
	Pnn x=split(root,c);
	Pnn y=split(x.fs,b);
	Pnn z=split(x.sc,1);
//	show(count(z.sc));
	node *t=merge(y.fs,z.fs);
	node *s=merge(y.sc,z.sc);
//	showtree(t);puts("");
//	showtree(s);puts("");
	root=merge(t,s);
}
void query1(int b,int c){
	Pnn x=split(root,b);
	Pnn y=split(x.sc,c+1-b);
//	show(count(y.fs));
	cout<<y.fs->mn<<endl;
	root=merge(x.fs,merge(y.fs,y.sc));
}
void query2(int b,int c){
	root=erase(root,b);
	root=insert(root,b,c);
}
int main(){
	int N,Q;
	cin>>N>>Q;
	rep(i,N){
		int a;
		scanf("%d",&a);
		root=insert(root,i,a);
	}
//	show(count(root));
//	showtree(root);puts("");
	rep(i,Q){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==0) query0(b,c);
		if(a==1) query1(b,c);
		if(a==2) query2(b,c);
//		showtree(root);puts("");
	}
}