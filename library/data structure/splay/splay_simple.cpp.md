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


# :warning: data structure/splay/splay_simple.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a139cdef544a41bbe9de0547a0bc58bb">data structure/splay</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/splay/splay_simple.cpp">View this file on GitHub</a>
    - Last commit date: 2017-10-19 00:06:21+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}

/*
	smなしバージョン(ただの列を扱うだけ(get,insert,erase,lower_bound とか))
	D 同士の演算/単位元 は定義されて無くて大丈夫 だけど, Node()の定義のvに何を入れるか微妙(とりあえず0を入れているけど)
	なのでintをそのまま突っ込んだりも出来る(まあnilの実体は書く必要があるけど)
*/
template<class D>
struct SplayTree{
	struct Node;
	using NP = Node*;
	static NP nil;

	struct Node{
		NP p,l,r;
		int sz;
		D v;
		Node(D v) :p(nullptr),l(nil),r(nil),sz(1),v(v){}
		Node() : p(nullptr),l(nullptr),r(nullptr),sz(0),v(0){}		//!!!
		int pos(){			//親の左の子か,右の子か,それとも根(or nil)か
			if(p&&p->l == this) return -1;
			if(p&&p->r == this) return 1;
			return 0;
		}
		void rot(){				//rootで呼ぶと死
			NP pp=p->p;
			int pps=p->pos();
			if(p->l==this){
				p->l=r,r->p=p,r=p,p->p=this;
			}else{
				p->r=l,l->p=p,l=p,p->p=this;
			}
			p->update();
//			update();	zig,zig-zag,zig-zigともにどうせ次でupdateがよばれるのでいらない(最後根はいる←これ実はmerge/splitでちゃんとupdateしてるから書かなくていいんだよね)
			p=pp;
			if(pps==0) return;
			if(pps==-1) pp->l=this;
			else pp->r=this;
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
			update();			//merge/split以外から呼ばれるかもしれないので一応つけておく
		}
		NP splay(int k){			//この区間の左からkth(0-indexed)をrootにもってきてそのポインタを返す
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
			return this;
		}

		void showtree(){
			cout<<"[";
			if(l->sz) l->showtree();
			cout<<v;
			if(r->sz) r->showtree();
			cout<<"]";
		}

	};
	NP n;

	/*
		(r!=nilなら)rの左端が根になる
		その左の子がl
	*/
	static NP merge(NP l,NP r){
		if(r==nil) return l;
		r=r->splay(0);
		r->l=l;
		l->p=r;
		return r->update();
	}
	/*
		kthでsplit(k=0ならfs=null)
		とりあえずk個目を持ってきて、pair(それ未満,それ以上)を返す.上につながっているのは(それ以上)の方,というかk
		基本的にsplitの第一引数はrootなので?そんなに気にしなくていいかな
		全区間をsplitしてく ([1,2,3,4] -> [1,2][3,4] -> [1][2][3,4]) ぶんには常にrootなため
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
	static NP build(int sz,D vs[]){				//init
		if(!sz) return nil;
		int md=sz/2;
		NP x= new Node(vs[md]);
		x->l = build(md,vs);
		x->l->p=x;
		x->r=build(sz-(md+1),vs+md+1);
		x->r->p=x;
		return x->update();
	}
	static NP build(const vector<D>& vs){
		return build(vs.size(),vs,0);
	}
	static NP build(int sz,const vector<D>& vs,int off){				//init
		if(!sz) return nil;
		int md=sz/2;
		NP x= new Node(vs[off+md]);
		x->l = build(md,vs,off);
		x->l->p=x;
		x->r=build(sz-(md+1),vs,off+md+1);
		x->r->p=x;
		return x->update();
	}

	SplayTree() : n(nil){}
	SplayTree(NP n) : n(n){}
	SplayTree(int sz,D vs[]){
		n=build(sz,vs);
	}
	SplayTree(vector<D> vs){
		n=build(vs);
	}

	void insert(int k,D v){
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
	D get(int k){			//kth info
		auto a=split(n,k);
		auto b=split(a.sc,1);
		D ret=b.fs->v;
		n=merge(merge(a.fs,b.fs),b.sc);
		return ret;
	}
	void assign(int k,D d){
		auto a = split(n,k);
		auto b = split(a.sc,1);
		n = merge(merge(a.fs,new Node(d)),b.sc);
	}

	/*
		search
		平衡二分木としての役目を思い出せ
		なんか列をくっつけたりわけたりできるとだけ思っとけば基本いいけど
		持ってるデータに順序付いてるときにはちゃんと二分木として使える
		D に operator< と operator<= が必要
	*/
	int lower_bound(D x){		//x以上で一番小さいとこのidを返す
		NP p=n;
		int ret=0;
		while(p!=nil){
			if(x<=p->v) p=p->l;
			else ret+=(p->l->sz)+1,p=p->r;
		}
		return ret;
	}
	int upper_bound(D x){		//xより大で一番小さいとこのidを返す
		NP p=n;
		int ret=0;
		while(p!=nil){
			if(x<p->v) p=p->l;
			else ret+=(p->l->sz)+1,p=p->r;
		}
		return ret;
	}

	/*
		debug
		struct D に << がないとだめ
	*/
	void showtree(){
		n->showtree();
		cout<<endl;
	}
};

template<>
SplayTree<int>::NP SplayTree<int>::nil = new SplayTree<int>::Node();


int main(){
	SplayTree<int> st;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/splay/splay_simple.cpp"
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
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}

/*
	smなしバージョン(ただの列を扱うだけ(get,insert,erase,lower_bound とか))
	D 同士の演算/単位元 は定義されて無くて大丈夫 だけど, Node()の定義のvに何を入れるか微妙(とりあえず0を入れているけど)
	なのでintをそのまま突っ込んだりも出来る(まあnilの実体は書く必要があるけど)
*/
template<class D>
struct SplayTree{
	struct Node;
	using NP = Node*;
	static NP nil;

	struct Node{
		NP p,l,r;
		int sz;
		D v;
		Node(D v) :p(nullptr),l(nil),r(nil),sz(1),v(v){}
		Node() : p(nullptr),l(nullptr),r(nullptr),sz(0),v(0){}		//!!!
		int pos(){			//親の左の子か,右の子か,それとも根(or nil)か
			if(p&&p->l == this) return -1;
			if(p&&p->r == this) return 1;
			return 0;
		}
		void rot(){				//rootで呼ぶと死
			NP pp=p->p;
			int pps=p->pos();
			if(p->l==this){
				p->l=r,r->p=p,r=p,p->p=this;
			}else{
				p->r=l,l->p=p,l=p,p->p=this;
			}
			p->update();
//			update();	zig,zig-zag,zig-zigともにどうせ次でupdateがよばれるのでいらない(最後根はいる←これ実はmerge/splitでちゃんとupdateしてるから書かなくていいんだよね)
			p=pp;
			if(pps==0) return;
			if(pps==-1) pp->l=this;
			else pp->r=this;
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
			update();			//merge/split以外から呼ばれるかもしれないので一応つけておく
		}
		NP splay(int k){			//この区間の左からkth(0-indexed)をrootにもってきてそのポインタを返す
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
			return this;
		}

		void showtree(){
			cout<<"[";
			if(l->sz) l->showtree();
			cout<<v;
			if(r->sz) r->showtree();
			cout<<"]";
		}

	};
	NP n;

	/*
		(r!=nilなら)rの左端が根になる
		その左の子がl
	*/
	static NP merge(NP l,NP r){
		if(r==nil) return l;
		r=r->splay(0);
		r->l=l;
		l->p=r;
		return r->update();
	}
	/*
		kthでsplit(k=0ならfs=null)
		とりあえずk個目を持ってきて、pair(それ未満,それ以上)を返す.上につながっているのは(それ以上)の方,というかk
		基本的にsplitの第一引数はrootなので?そんなに気にしなくていいかな
		全区間をsplitしてく ([1,2,3,4] -> [1,2][3,4] -> [1][2][3,4]) ぶんには常にrootなため
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
	static NP build(int sz,D vs[]){				//init
		if(!sz) return nil;
		int md=sz/2;
		NP x= new Node(vs[md]);
		x->l = build(md,vs);
		x->l->p=x;
		x->r=build(sz-(md+1),vs+md+1);
		x->r->p=x;
		return x->update();
	}
	static NP build(const vector<D>& vs){
		return build(vs.size(),vs,0);
	}
	static NP build(int sz,const vector<D>& vs,int off){				//init
		if(!sz) return nil;
		int md=sz/2;
		NP x= new Node(vs[off+md]);
		x->l = build(md,vs,off);
		x->l->p=x;
		x->r=build(sz-(md+1),vs,off+md+1);
		x->r->p=x;
		return x->update();
	}

	SplayTree() : n(nil){}
	SplayTree(NP n) : n(n){}
	SplayTree(int sz,D vs[]){
		n=build(sz,vs);
	}
	SplayTree(vector<D> vs){
		n=build(vs);
	}

	void insert(int k,D v){
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
	D get(int k){			//kth info
		auto a=split(n,k);
		auto b=split(a.sc,1);
		D ret=b.fs->v;
		n=merge(merge(a.fs,b.fs),b.sc);
		return ret;
	}
	void assign(int k,D d){
		auto a = split(n,k);
		auto b = split(a.sc,1);
		n = merge(merge(a.fs,new Node(d)),b.sc);
	}

	/*
		search
		平衡二分木としての役目を思い出せ
		なんか列をくっつけたりわけたりできるとだけ思っとけば基本いいけど
		持ってるデータに順序付いてるときにはちゃんと二分木として使える
		D に operator< と operator<= が必要
	*/
	int lower_bound(D x){		//x以上で一番小さいとこのidを返す
		NP p=n;
		int ret=0;
		while(p!=nil){
			if(x<=p->v) p=p->l;
			else ret+=(p->l->sz)+1,p=p->r;
		}
		return ret;
	}
	int upper_bound(D x){		//xより大で一番小さいとこのidを返す
		NP p=n;
		int ret=0;
		while(p!=nil){
			if(x<p->v) p=p->l;
			else ret+=(p->l->sz)+1,p=p->r;
		}
		return ret;
	}

	/*
		debug
		struct D に << がないとだめ
	*/
	void showtree(){
		n->showtree();
		cout<<endl;
	}
};

template<>
SplayTree<int>::NP SplayTree<int>::nil = new SplayTree<int>::Node();


int main(){
	SplayTree<int> st;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

