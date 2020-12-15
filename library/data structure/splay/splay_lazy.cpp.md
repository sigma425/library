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


# :warning: data structure/splay/splay_lazy.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a139cdef544a41bbe9de0547a0bc58bb">data structure/splay</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/splay/splay_lazy.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
SplayTree(lazy ver) revはなし
lazy_segtreeの上位互換.query(l,r), assign(x,d)は同じ使い方が出来る.
区間addlazyはupdate(l,r,f)
unittestを見ると使い方がわかりそう

2018/07/12 unittest OK

*/

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

template<class Handler>
struct SplayTree{
	using D = typename Handler::val_t;	//data
	using A = typename Handler::opr_t;	//action

	struct Node;
	using NP = Node*;
	static NP nil;

	struct Node{
		NP p,l,r;
		int sz;
		D v,sm;
		A lz;
		Node(D v,A a) :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v),lz(a){}
		Node(D v) :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v),lz(A::e()){}
		Node() : p(nullptr),l(nullptr),r(nullptr),sz(0),v(D::e()),sm(D::e()),lz(A::e()){}
		int pos(){			//親の左の子か,右の子か,それとも根(or nil)か
			if(p&&p->l == this) return -1;
			if(p&&p->r == this) return 1;
			return 0;
		}
		void rot(){				//rootで呼ぶと死
			assert(p != nullptr);
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
			pushdown();
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
			sm = v;
			if(l->sz) sm = l->sm + sm;	//if(l) だとnilでも呼ぶ羽目になりそう
			if(r->sz) sm = sm + r->sm;
			return this;
		}
		void addlazy(const A& f){
			Handler::setg2fg(f,lz);
			v = Handler::act(f,v);
			sm = Handler::act(f,sm);
		}
		void push(){
			if(l->sz) l->addlazy(lz);
			if(r->sz) r->addlazy(lz);
			lz = A::e();
		}
		void pushdown(){	//from root to v
			if(pos()) p->pushdown();
			push();
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
	D query(int l,int r){			//[l,r)
		auto b=split(n,r);
		auto a=split(b.fs,l);
		D ret=a.sc->sm;
		n=merge(merge(a.fs,a.sc),b.sc);
		return ret;
	}
	void update(int l,int r,const A& f){
		auto b=split(n,r);
		auto a=split(b.fs,l);
		a.sc->addlazy(f);
		n=merge(merge(a.fs,a.sc),b.sc);
		return;
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


struct handler{
	/*
		range assign 0以上
		range max

		val_t = int,max			val[k]=max
		opr_t(x) : y -> x		lazy[k]=assign

		今回の場合opr_t::eはない(assignに単位元はない)
		このようなときは、適当な値を単位元に設定にしておき、getfg/setg2fg/ act!! で合成しないよう処理しておけば良い
		考えにくいけどval_tも同様.
		最悪option型みたいにbool値をもたせれば良さそう
	*/
	struct val_t{
		int x;
		val_t(){*this = e();}
		val_t(int x):x(x){}

		const static val_t e(){
			return val_t(0);
		}
		val_t operator+(const val_t &r) const {
			return val_t(max(x,r.x));
		}
		friend ostream& operator<<(ostream& o,const val_t& d){return o<<d.x;}
	};

	struct opr_t{
		int x;
		opr_t(){*this = e();}
		opr_t(int x):x(x){}

		const static opr_t e(){
			return opr_t(-1);
		}
		friend ostream& operator<<(ostream& o,const opr_t& d){return o<<d.x;}
	};

	static void setg2fg(const opr_t &f, opr_t &g){	//g -> fg		f after g
		if(f.x != -1) g.x = f.x;
	}
	static val_t act(const opr_t &f, const val_t &v){		//maxがv っていう状態のところにfを作用させるとmaxは何になりますか?
		if(f.x == -1) return v;
		return val_t(f.x);
	}
};
template<>
SplayTree<handler>::NP SplayTree<handler>::nil = new SplayTree<handler>::Node();

void unittest(){
	int N = 1000, Q = 1000;
	using D = handler::val_t;
	using A = handler::opr_t;

	vector<int> a(N);
	rep(i,N) a[i] = rand()%1000+1;

	vector<D> a_(N);
	rep(i,N) a_[i] = a[i];
	SplayTree<handler> st(a_);

	rep(q,Q){
		if(q%3 == 0){
			int l = rand()%N, r = rand()%N;
			if(l>r) swap(l,r);
			r++;

			int brute = 0;
			for(int i=l;i<r;i++) chmax(brute,a[i]);

			int res = st.query(l,r).x;

			assert(brute == res);
		}
		if(q%3 == 1){
			int l = rand()%N, r = rand()%N;
			if(l>r) swap(l,r);
			r++;
			int x = rand()%1000;

			for(int i=l;i<r;i++) a[i] = x;

			st.update(l,r,A(x));
		}
		if(q%3 == 2){	//[0,..,L)[L,..,N) -> [L,..,N)[0,..,L)
			int L = rand()%(N+1);

			rotate(a.begin(),a.begin()+L,a.end());

			auto m = st.split(st.n,L);
			st.n = st.merge(m.sc,m.fs);
		}
	}
}

int main(){
	srand((unsigned)time(NULL));
	unittest();
	puts("OK");

// 	int N,Q;	//AOJ1508
// 	vector<D> vs;
// 	cin>>N>>Q;
// 	rep(i,N){
// 		int x;
// 		cin>>x;
// 		vs.pb(D(x));
// 	}
// 	SplayTree<D> st(vs);
// 	rep(qt,Q){
// 		int x,y,z;
// 		cin>>x>>y>>z;
// 		if(x==0){	//[y..z-1][z] -> [z][y..z-1]
// 			auto a = split(st.n,y);	//[0..y-1][y..N-1]
// 			auto b = split(a.sc,z-y+1);	//[y..z][~]
// 			auto c = split(b.fs,z-y);		//[y..z-1][z]
// 			st.n = merge(merge(a.fs,c.sc),merge(c.fs,b.sc));
// 		}
// 		if(x==1){
// 			cout<<st.query(y,z+1).x<<endl;
// 		}
// 		if(x==2){
// 			st.assign(y,z);
// 		}
// //		st.showtree();
// 	}
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/splay/splay_lazy.cpp"
/*
SplayTree(lazy ver) revはなし
lazy_segtreeの上位互換.query(l,r), assign(x,d)は同じ使い方が出来る.
区間addlazyはupdate(l,r,f)
unittestを見ると使い方がわかりそう

2018/07/12 unittest OK

*/

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

template<class Handler>
struct SplayTree{
	using D = typename Handler::val_t;	//data
	using A = typename Handler::opr_t;	//action

	struct Node;
	using NP = Node*;
	static NP nil;

	struct Node{
		NP p,l,r;
		int sz;
		D v,sm;
		A lz;
		Node(D v,A a) :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v),lz(a){}
		Node(D v) :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v),lz(A::e()){}
		Node() : p(nullptr),l(nullptr),r(nullptr),sz(0),v(D::e()),sm(D::e()),lz(A::e()){}
		int pos(){			//親の左の子か,右の子か,それとも根(or nil)か
			if(p&&p->l == this) return -1;
			if(p&&p->r == this) return 1;
			return 0;
		}
		void rot(){				//rootで呼ぶと死
			assert(p != nullptr);
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
			pushdown();
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
			sm = v;
			if(l->sz) sm = l->sm + sm;	//if(l) だとnilでも呼ぶ羽目になりそう
			if(r->sz) sm = sm + r->sm;
			return this;
		}
		void addlazy(const A& f){
			Handler::setg2fg(f,lz);
			v = Handler::act(f,v);
			sm = Handler::act(f,sm);
		}
		void push(){
			if(l->sz) l->addlazy(lz);
			if(r->sz) r->addlazy(lz);
			lz = A::e();
		}
		void pushdown(){	//from root to v
			if(pos()) p->pushdown();
			push();
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
	D query(int l,int r){			//[l,r)
		auto b=split(n,r);
		auto a=split(b.fs,l);
		D ret=a.sc->sm;
		n=merge(merge(a.fs,a.sc),b.sc);
		return ret;
	}
	void update(int l,int r,const A& f){
		auto b=split(n,r);
		auto a=split(b.fs,l);
		a.sc->addlazy(f);
		n=merge(merge(a.fs,a.sc),b.sc);
		return;
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


struct handler{
	/*
		range assign 0以上
		range max

		val_t = int,max			val[k]=max
		opr_t(x) : y -> x		lazy[k]=assign

		今回の場合opr_t::eはない(assignに単位元はない)
		このようなときは、適当な値を単位元に設定にしておき、getfg/setg2fg/ act!! で合成しないよう処理しておけば良い
		考えにくいけどval_tも同様.
		最悪option型みたいにbool値をもたせれば良さそう
	*/
	struct val_t{
		int x;
		val_t(){*this = e();}
		val_t(int x):x(x){}

		const static val_t e(){
			return val_t(0);
		}
		val_t operator+(const val_t &r) const {
			return val_t(max(x,r.x));
		}
		friend ostream& operator<<(ostream& o,const val_t& d){return o<<d.x;}
	};

	struct opr_t{
		int x;
		opr_t(){*this = e();}
		opr_t(int x):x(x){}

		const static opr_t e(){
			return opr_t(-1);
		}
		friend ostream& operator<<(ostream& o,const opr_t& d){return o<<d.x;}
	};

	static void setg2fg(const opr_t &f, opr_t &g){	//g -> fg		f after g
		if(f.x != -1) g.x = f.x;
	}
	static val_t act(const opr_t &f, const val_t &v){		//maxがv っていう状態のところにfを作用させるとmaxは何になりますか?
		if(f.x == -1) return v;
		return val_t(f.x);
	}
};
template<>
SplayTree<handler>::NP SplayTree<handler>::nil = new SplayTree<handler>::Node();

void unittest(){
	int N = 1000, Q = 1000;
	using D = handler::val_t;
	using A = handler::opr_t;

	vector<int> a(N);
	rep(i,N) a[i] = rand()%1000+1;

	vector<D> a_(N);
	rep(i,N) a_[i] = a[i];
	SplayTree<handler> st(a_);

	rep(q,Q){
		if(q%3 == 0){
			int l = rand()%N, r = rand()%N;
			if(l>r) swap(l,r);
			r++;

			int brute = 0;
			for(int i=l;i<r;i++) chmax(brute,a[i]);

			int res = st.query(l,r).x;

			assert(brute == res);
		}
		if(q%3 == 1){
			int l = rand()%N, r = rand()%N;
			if(l>r) swap(l,r);
			r++;
			int x = rand()%1000;

			for(int i=l;i<r;i++) a[i] = x;

			st.update(l,r,A(x));
		}
		if(q%3 == 2){	//[0,..,L)[L,..,N) -> [L,..,N)[0,..,L)
			int L = rand()%(N+1);

			rotate(a.begin(),a.begin()+L,a.end());

			auto m = st.split(st.n,L);
			st.n = st.merge(m.sc,m.fs);
		}
	}
}

int main(){
	srand((unsigned)time(NULL));
	unittest();
	puts("OK");

// 	int N,Q;	//AOJ1508
// 	vector<D> vs;
// 	cin>>N>>Q;
// 	rep(i,N){
// 		int x;
// 		cin>>x;
// 		vs.pb(D(x));
// 	}
// 	SplayTree<D> st(vs);
// 	rep(qt,Q){
// 		int x,y,z;
// 		cin>>x>>y>>z;
// 		if(x==0){	//[y..z-1][z] -> [z][y..z-1]
// 			auto a = split(st.n,y);	//[0..y-1][y..N-1]
// 			auto b = split(a.sc,z-y+1);	//[y..z][~]
// 			auto c = split(b.fs,z-y);		//[y..z-1][z]
// 			st.n = merge(merge(a.fs,c.sc),merge(c.fs,b.sc));
// 		}
// 		if(x==1){
// 			cout<<st.query(y,z+1).x<<endl;
// 		}
// 		if(x==2){
// 			st.assign(y,z);
// 		}
// //		st.showtree();
// 	}
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

