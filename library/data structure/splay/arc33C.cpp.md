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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: data structure/splay/arc33C.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a139cdef544a41bbe9de0547a0bc58bb">data structure/splay</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/splay/arc33C.cpp">View this file on GitHub</a>
    - Last commit date: 2016-12-08 00:51:38+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//k-th set
//http://arc033.contest.atcoder.jp/submissions/521951 AC
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
typedef long long ll;
struct SplayTree{
	struct Node;
	using NP = Node*;
	static NP nil;

	struct Node{
		NP p,l,r;			//parent,left child,right child
		int sz;
		ll v,sm;				//infos
		Node(ll v) :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v){}
		Node() : l(nullptr),r(nullptr),sz(0),v(0),sm(0){}						//単位元!!
		int pos(){			//親の左の子か,右の子か,それとも根(or null)か
			if(p&&p->l == this) return -1;
			if(p&&p->r == this) return 1;
			return 0;
		}
		void rot(){				//rootで呼ぶと死
			NP pp=p->p;			//親の親
			int pps=p->pos();	//ppからみたpの左右
			if(p->l==this){		//pos()==-1
				p->l=r,r->p=p,r=p,p->p=this;
			}else{
				p->r=l,l->p=p,l=p,p->p=this;
			}
			//新しい木で下からupdate
			p->update();
			update();
			p=pp;
			if(pps==0) return;
			if(pps==-1) pp->l=this;
			else pp->r=this;
			pp->update();
		}
		void splay(){			//thisをrootにもってくる
			while(true){
				int ps=pos();
				if(ps==0) break;
				int pps=p->pos();
				if(pps==0){		//zig
					rot();
				}else if(ps==pps){		//zigzig
					p->rot();rot();
				}else{					//zigzag
					rot();rot();
				}
			}
		}
		NP splay(int k){			//この区間の左からkth(0-indexed)をrootにもってきてそのポインタを返す(szが必要)
			assert(0<=k&&k<sz);
			if(k<l->sz){
				return l->splay(k);
			}else if(k==l->sz){
				splay();
				return this;
			}else{
				return r->splay(k-(l->sz+1));
			}
		}
		NP update(){		//情報更新(子が正しい時に呼ばないとダメ) (最後にupdateしてreturnするのに楽なのでNPを返す)
			sz=1+l->sz+r->sz;
			if(l) sm+=l->sm;
			if(r) sm+=r->sm;
			return this;
		}

	};
	NP n;
	static NP merge(NP l,NP r){			//mergeした根
		if(r==nil) return l;
		r=r->splay(0);
		r->l=l;
		l->p=r;
		return r->update();
	}
	/*
		kthでsplit(k=0ならfs=null)
		lは完全に切り離されてるけれど
		rは上とつながっている?
	*/
	static pair<NP,NP> split(NP x,int k){
		assert(0<=k&&k<=x->sz);
		if(k==x->sz) return {x,nil};
		x=x->splay(k);
		NP l=x->l;
		l->p = nullptr;
		x->l = nil;
		return {l,x->update()};
	}
	static NP built(int sz,ll vs[]){				//init
		if(!sz) return nil;
		int md=sz/2;
		NP x= new Node(vs[md]);
		x->l = built(md,vs);
		x->l->p=x;
		x->r=built(sz-(md+1),vs+md+1);
		x->r->p=x;
		return x->update();
	}
	SplayTree() : n(nil){}
	SplayTree(NP n) : n(n){}
	SplayTree(int sz,ll vs[]){
		n=built(sz,vs);
	}
	void insert(int k,ll v){
		auto u=split(n,k);
		n=merge(merge(u.fs,new Node(v)),u.sc);
	}
	void erase(int k){
		auto u=split(n,k);
		n=merge(u.fs,split(u.sc,1).sc);
	}
	void merge(SplayTree t){
		n=merge(n,t.n);
	}
	int sz(){
		return n->sz;
	}
	ll get(int k){			//kth info
		auto a=split(n,k);
		auto b=split(a.sc,1);
		ll ret=b.fs->v;
		n=merge(merge(a.fs,b.fs),b.sc);
		return ret;
	}
	ll sum(int l,int r){
		auto b=split(n,r);
		auto a=split(b.fs,l);
		ll ret=a.sc->sm;
		n=merge(merge(a.fs,a.sc),b.sc);
		return ret;
	}
	/*
		search
		平衡二分木としての役目を思い出せ
		なんか列をくっつけたりわけたりできるとだけ思っとけば基本いいけど
		持ってるデータに順序付いてるときにはちゃんと二分木として使える
	*/
	int lower_bound(int x){
		NP p=n;
		int ret=0;
		while(p!=nil){
			if(x<=p->v) p=p->l;
			else ret+=(p->l->sz)+1,p=p->r;
		}
		return ret;
	}
};
SplayTree::NP SplayTree::nil = new SplayTree::Node();
int main(){
	int Q;
	cin>>Q;
	SplayTree ST;
	rep(tt,Q){
		int t,x;
		cin>>t>>x;
		if(t==1){
			int id=ST.lower_bound(x);
			ST.insert(id,x);
		}else{
			x--;
			cout<<ST.get(x)<<endl;
			ST.erase(x);
		}
	}
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/splay/arc33C.cpp"
//k-th set
//http://arc033.contest.atcoder.jp/submissions/521951 AC
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
typedef long long ll;
struct SplayTree{
	struct Node;
	using NP = Node*;
	static NP nil;

	struct Node{
		NP p,l,r;			//parent,left child,right child
		int sz;
		ll v,sm;				//infos
		Node(ll v) :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v){}
		Node() : l(nullptr),r(nullptr),sz(0),v(0),sm(0){}						//単位元!!
		int pos(){			//親の左の子か,右の子か,それとも根(or null)か
			if(p&&p->l == this) return -1;
			if(p&&p->r == this) return 1;
			return 0;
		}
		void rot(){				//rootで呼ぶと死
			NP pp=p->p;			//親の親
			int pps=p->pos();	//ppからみたpの左右
			if(p->l==this){		//pos()==-1
				p->l=r,r->p=p,r=p,p->p=this;
			}else{
				p->r=l,l->p=p,l=p,p->p=this;
			}
			//新しい木で下からupdate
			p->update();
			update();
			p=pp;
			if(pps==0) return;
			if(pps==-1) pp->l=this;
			else pp->r=this;
			pp->update();
		}
		void splay(){			//thisをrootにもってくる
			while(true){
				int ps=pos();
				if(ps==0) break;
				int pps=p->pos();
				if(pps==0){		//zig
					rot();
				}else if(ps==pps){		//zigzig
					p->rot();rot();
				}else{					//zigzag
					rot();rot();
				}
			}
		}
		NP splay(int k){			//この区間の左からkth(0-indexed)をrootにもってきてそのポインタを返す(szが必要)
			assert(0<=k&&k<sz);
			if(k<l->sz){
				return l->splay(k);
			}else if(k==l->sz){
				splay();
				return this;
			}else{
				return r->splay(k-(l->sz+1));
			}
		}
		NP update(){		//情報更新(子が正しい時に呼ばないとダメ) (最後にupdateしてreturnするのに楽なのでNPを返す)
			sz=1+l->sz+r->sz;
			if(l) sm+=l->sm;
			if(r) sm+=r->sm;
			return this;
		}

	};
	NP n;
	static NP merge(NP l,NP r){			//mergeした根
		if(r==nil) return l;
		r=r->splay(0);
		r->l=l;
		l->p=r;
		return r->update();
	}
	/*
		kthでsplit(k=0ならfs=null)
		lは完全に切り離されてるけれど
		rは上とつながっている?
	*/
	static pair<NP,NP> split(NP x,int k){
		assert(0<=k&&k<=x->sz);
		if(k==x->sz) return {x,nil};
		x=x->splay(k);
		NP l=x->l;
		l->p = nullptr;
		x->l = nil;
		return {l,x->update()};
	}
	static NP built(int sz,ll vs[]){				//init
		if(!sz) return nil;
		int md=sz/2;
		NP x= new Node(vs[md]);
		x->l = built(md,vs);
		x->l->p=x;
		x->r=built(sz-(md+1),vs+md+1);
		x->r->p=x;
		return x->update();
	}
	SplayTree() : n(nil){}
	SplayTree(NP n) : n(n){}
	SplayTree(int sz,ll vs[]){
		n=built(sz,vs);
	}
	void insert(int k,ll v){
		auto u=split(n,k);
		n=merge(merge(u.fs,new Node(v)),u.sc);
	}
	void erase(int k){
		auto u=split(n,k);
		n=merge(u.fs,split(u.sc,1).sc);
	}
	void merge(SplayTree t){
		n=merge(n,t.n);
	}
	int sz(){
		return n->sz;
	}
	ll get(int k){			//kth info
		auto a=split(n,k);
		auto b=split(a.sc,1);
		ll ret=b.fs->v;
		n=merge(merge(a.fs,b.fs),b.sc);
		return ret;
	}
	ll sum(int l,int r){
		auto b=split(n,r);
		auto a=split(b.fs,l);
		ll ret=a.sc->sm;
		n=merge(merge(a.fs,a.sc),b.sc);
		return ret;
	}
	/*
		search
		平衡二分木としての役目を思い出せ
		なんか列をくっつけたりわけたりできるとだけ思っとけば基本いいけど
		持ってるデータに順序付いてるときにはちゃんと二分木として使える
	*/
	int lower_bound(int x){
		NP p=n;
		int ret=0;
		while(p!=nil){
			if(x<=p->v) p=p->l;
			else ret+=(p->l->sz)+1,p=p->r;
		}
		return ret;
	}
};
SplayTree::NP SplayTree::nil = new SplayTree::Node();
int main(){
	int Q;
	cin>>Q;
	SplayTree ST;
	rep(tt,Q){
		int t,x;
		cin>>t>>x;
		if(t==1){
			int id=ST.lower_bound(x);
			ST.insert(id,x);
		}else{
			x--;
			cout<<ST.get(x)<<endl;
			ST.erase(x);
		}
	}
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

