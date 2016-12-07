// http://koj.miz-miz.biz/view_problem/0040
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
int inf=1e9+7;
struct node{		//node of segtree
	node(int l_,int r_,node *p_){
		l=l_,r=r_,p=p_;
		val=inf;
		lch=0,rch=0;
	}
	int val,l,r;
	node *p,*lch,*rch;
};
node pool[2000000];
node news()
void update(int pos,int val,node *x=root){
	int l=x->l,r=x->r;
	if(pos<l||r<=pos) return;
	if(l==pos&&r==pos+1){
		x->val=val;
		return;
	}
	if(x->lch==0){
		x->lch = new node((l+r)/2,r,x);
	}
	if(x->rch==0){
		x->rch = new node(l,(l+r)/2,x);
	}
	update(pos,val,x->lch);
	update(pos,val,x->rch);
	x->val=min(x->lch->val,x->rch->val);
}
int getmin(int a,int b,node *x=root){
	int l=x->l,r=x->r;
	if(b<=l||r<=a) return inf;
	if(a<=l&&r<=b) return x->val;
	if(x->lch==0){
		x->lch = new node((l+r)/2,r,x);
	}
	if(x->rch==0){
		x->rch = new node(l,(l+r)/2,x);
	}
	return min(getmin(a,b,x->lch),getmin(a,b,x->rch));
}
int main(){
	int N,Q;
	cin>>N>>Q;
	rep(i,N){
		int a;
		cin>>a;
		update(i,a);
	}
	rep(i,Q){
		int t,a,b;
		cin>>t>>a>>b;
		if(t==1){
			cout<<getmin(a-1,b)<<endl;
		}else{
			update(a-1,b);
		}
	}
}