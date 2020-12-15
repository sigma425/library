---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :warning: data structure/segtree/persistent segtree/pers.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#804b46389e12899b5eab90f4bea5a2e6">data structure/segtree/persistent segtree</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/segtree/persistent segtree/pers.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/segtree/persistent segtree/pers.cpp"
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

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

