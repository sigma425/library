// http://koj.miz-miz.biz/view_problem/0042
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
			mn=l+1,mx=r;
			lch=0,rch=0;
		}
		int mn,mx,l,r;
		node *p,*lch,*rch;
	};
	node *root=new node(0,1<<30,0);
	void update(int pos,int val,node *x=root){
		int l=x->l,r=x->r;
		if(pos<l||r<=pos) return;
		if(l==pos&&r==pos+1){
			x->mn=val;
			x->mx=val;
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
		x->mn=min(x->lch->mn,x->rch->mn);
		x->mx=max(x->lch->mx,x->rch->mx);
	}
	int getmin(int a,int b,node *x=root){
		int l=x->l,r=x->r;
		if(b<=l||r<=a) return inf;
		if(a<=l&&r<=b) return x->mn;
		if(x->lch==0){
			x->lch = new node((l+r)/2,r,x);
		}
		if(x->rch==0){
			x->rch = new node(l,(l+r)/2,x);
		}
		return min(getmin(a,b,x->lch),getmin(a,b,x->rch));
	}
	int getmax(int a,int b,node *x=root){
		int l=x->l,r=x->r;
		if(b<=l||r<=a) return -inf;
		if(a<=l&&r<=b) return x->mx;
		if(x->lch==0){
			x->lch = new node((l+r)/2,r,x);
		}
		if(x->rch==0){
			x->rch = new node(l,(l+r)/2,x);
		}
		return max(getmax(a,b,x->lch),getmax(a,b,x->rch));
	}
int main(){
	int N,Q;
	cin>>N>>Q;
	rep(i,Q){
		int t,a,b;
		cin>>t>>a>>b;
		if(t==1) cout<<getmin(a-1,b)<<endl;
		if(t==2) cout<<getmax(a-1,b)<<endl;
		if(t==3) update(a-1,b);
	}
}