//http://codeforces.com/contest/484/problem/E
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
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define all(c) (c).begin(),(c).end()
#define fs first
#define sc second
#define pb push_back
#define show(x) cout << #x << " " << x << endl
#define chmax(x,y) x=max(x,y)
const int MX=2000000;
struct node{
	node *lch,*rch;
	int l,r,mx;
	bool all;
	node(node *lch_,node *rch_,int l_,int r_,int mx_,bool all_){
		lch=lch_,rch=rch_,l=l_,r=r_,mx=mx_,all=all_;
	}
	node(node *lch_,node *rch_){
		lch=lch_,rch=rch_;
		all=lch->all & rch->all;
		if(lch->all) l=lch->mx+rch->l;
		else l=lch->l;
		if(rch->all) r=rch->mx+lch->r;
		else r=rch->r;
		mx=max(lch->mx,rch->mx);
		chmax(mx,lch->r+rch->l);
	}
	node(){}
};
node pool[MX];
node *root[100001];
node *nil;
int sit;
node *news(node *lch,node *rch,int l,int r,int mx,bool all){
	return &(pool[sit++]=node(lch,rch,l,r,mx,all));
}
node *news(node *lch,node *rch){
	return &(pool[sit++]=node(lch,rch));
}
node *fix(node *x,int pos,int l,int r){		//0->1
//	printf("pos,l,r=(%d,%d,%d)\n",pos,l,r);
	if(r-l==1){
		return news(nil,nil,1,1,1,1);
	}
	int m=(l+r)/2;
	if(pos<m){
		return news(fix(x->lch,pos,l,m),x->rch);
	}else{
		return news(x->lch,fix(x->rch,pos,m,r));
	}
}
typedef pair<int,int> P;
int mx,cont;
void query(int a,int b,int l,int r,node *x){
	if(x==nil){
		cont=0;
		return;
	}
	if(b<=l||r<=a) return;
	if(a<=l&&r<=b){
		chmax(mx,x->mx);
		chmax(mx,cont+x->l);
		if(x->all) cont+=r-l;
		else cont=x->r;
		return;
	}
	int m=(l+r)/2;
	query(a,b,l,m,x->lch);
	query(a,b,m,r,x->rch);
}
void showtree(node *x){
	if(x==nil) return;
	cout<<"(";
	showtree(x->lch);
	printf("<%d,%d,%d>",x->l,x->mx,x->r);
	showtree(x->rch);
	cout<<")";
}
int n,q,x[100000];
vector<int> ash;
vector<int> val[100000];
int main(){
	nil=news(0,0,0,0,0,0);
	nil->lch=nil->rch=nil;
	root[0]=nil;
	cin>>n;
	rep(i,n) cin>>x[i];
	rep(i,n) ash.pb(x[i]);
	sort(all(ash));
	ash.erase(unique(all(ash)),ash.end());
	int m=ash.size();
	rep(i,n) x[i]=lower_bound(all(ash),x[i])-ash.begin();
	rep(i,n) val[x[i]].pb(i);
	rep(i,m){
		root[i+1]=root[i];
		for(int v:val[m-1-i]) root[i+1]=fix(root[i+1],v,0,n);
	}
/*	rep(i,m+1){
		printf("ver i:%d\n",i);
		showtree(root[i]);puts("");
	}*/
	cin>>q;
	rep(i,q){
		int l,r,w;
		cin>>l>>r>>w;
		l--;
		int ub=m,lb=0;
		while(ub-lb>1){
			mx=cont=0;
			int mid=(ub+lb)/2;
			query(l,r,0,n,root[mid]);
//			printf("ver,mx=(%d,%d)\n",mid,mx);
			if(w<=mx) ub=mid;
			else lb=mid;
		}
		cout<<ash[m-ub]<<endl;
	}
}