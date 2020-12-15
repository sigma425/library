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


# :warning: data structure/splay/LCTree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a139cdef544a41bbe9de0547a0bc58bb">data structure/splay</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/splay/LCTree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-05 22:29:51+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	Link Cut Tree
	根付き森を扱うデータ構造
	
	使い方
		pathに対する query,lazy query
		link : v(親なし) の親を p に設定する
		cut : v を 親から切り離す
		evert: 根を変更する
		これらが全て O(log N) で可能.

		外側では各頂点vに対して, NP n[v] を持つ(外でこれをいじる必要はない)
		逆に内側で NP から v を復元したいときはHandlerに頂点を追加しておけば良い?

		より変な操作(v-u間rotate)とかになったらsplay(int k) とかをsplay_lazy から持ってくる必要がありそう


	動作原理?
		動的 HL decomposition みたいな雰囲気
		各pathをsplay tree で表現する、根に近い方がleft
		expose(v): (根付き木での)vからrootを一つのpathにする, ついでにvをその"splay木の"根にする)
			これに含まれるHLdecompの各pathではある点から上全てを見ることになるので、
			splayの言葉でいうとleft child を残す
			v-root間がvを根とする一つのsplayになるので、何も考えずにvにクエリ飛ばせばいい
		evert(v): (根付き木での)rootをvに変える
			exposeしたあとはsplay的にはreverseに対応する

		smとかは各splay内で完結していることに注意!
		例えば、linkで p = r としたときに r->update() しなくていいのは、これが splay tree の edge ではないから

	参考
		http://yosupo.hatenablog.com/entry/2014/12/26/001414 (古いのでrevの持ち方とか微妙)
		http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1675225 (みじかい)
		https://github.com/yosupo06/Algorithm/blob/master/datastructure/linkcuttree.h#L36 (かなり信頼できる)
		https://www.slideshare.net/iwiwi/2-12188845 (iwiwiさんのいつものやつ)

	verified
		do use segment tree
			バグらせたとこ: actの時長さが引数にいる, 引数はsmはszでいいけどvは1
		spaceships
			lcaのverifyになったね
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
struct LCNode{
	using NP = LCNode*;
	static NP nil;

	using D = typename Handler::val_t;	//data
	using A = typename Handler::opr_t;	//action


	NP p,l,r;
	int sz;
	D v,sm;
	A lz;
	bool rev;
	LCNode(D v,A a) :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v),lz(a),rev(false){}
	LCNode(D v) :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v),lz(A::e()),rev(false){}
	LCNode() : p(nullptr),l(nullptr),r(nullptr),sz(0),v(D::e()),sm(D::e()),lz(A::e()),rev(false){}

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
		update();//	zig,zig-zag,zig-zigともにどうせ次でupdateがよばれるのでいらない(最後根はいる←これ実はmerge/splitでちゃんとupdateしてるから書かなくていいんだよね)
		p=pp;
		if(pps==0) return;
		if(pps==-1) pp->l=this;
		else pp->r=this;
		if(pp->sz) pp->update();	//これもいらんかも
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
	/*
		expose
		根付き木において、thisからrまでのpathを1つのsplay treeにする(下はちゃんと切る)
		ついでにthisを(splay tree の意味で)rootに持ってくる
		実際の木の根を変えるevertとは違うので注意!
	*/
	void expose(){
		NP v = this, vr = nil;

		while(true){
			v->splay();
			v->r = vr;	//first: cut right
			v->update();
			vr = v;		//next vr
			v = v->p;	//LinkCutのparent(別のsplaytreeに移動する)
			if(v==nullptr) break;
		}
		v = this;
		v->r = nil;	//cut
		v->update();

		while(v->p){
			v->p->r = v;
			v = v->p;
			v->update();
		}
		splay();
	}
	NP update(){		//情報更新(子が正しい時に呼ばないとダメ) (最後にupdateしてreturnするのに楽なのでNPを返す)
		sz=1+l->sz+r->sz;
		sm = v;
		if(l->sz) sm = l->sm + sm;	//if(l) だとnilでも呼ぶ羽目になりそう
		if(r->sz) sm = sm + r->sm;
		return this;
	}
	/*
		reverse

		revを扱うときは全てrevdata()をよぶ、個のタイミングでもうswap(l,r)もしちゃう

		reverse機能はlazy splayの機構の内側で扱ってもいいかと思ったけど、LCTree の Node に別の情報として持たせることにした
		1. 今持ってる data sm (a+b+..+c) から、sm.reverse (c+..+b+a)が簡単に計算できる場合
			revdata() の中にそれをかけばおわり
		2. できない場合
			sm と revsm (必要ならlz も同様?) をNodeに両方持って頑張る
			と思ったけどそれよりはHandlerに2つ持たせたほうが楽そう
		lzも変わっちゃう場合に根本的に対応できてない気がしてきた、普通そうならんしむずそうなので諦め

		ちなみにreverseは、evert(根変更クエリ)のために使います
		(現root - root 間のpathの向きだけ逆にするという操作になって、各splay木で左が元の根付き木での上に対応することを思い出すと)
	*/
	void revdata(){
		rev ^= true;
		swap(l,r);
		sm.revdata();
	}
	void addlazy(const A& f){
		Handler::setg2fg(f,lz);
		v = Handler::act(f,v,1);
		sm = Handler::act(f,sm,sz);
	}
	void push(){
		if(rev){
			if(l->sz) l->revdata();
			if(r->sz) r->revdata();
			rev = false;
		}
		if(l->sz) l->addlazy(lz);
		if(r->sz) r->addlazy(lz);
		lz = A::e();
	}
	void pushdown(){	//from root to this
		if(pos()) p->pushdown();
		push();
	}

	/*
		link:
			thisに対応する根付き木の頂点の親 を rに対応する根付き木の頂点 にする
			( つまり、外からはn[v].link(n[r]) )
	*/
	void link(NP r){
		expose();
		r->expose();
		p = r;
	}
	/*
		cut:
			thisに対応する根付き木の頂点 と その親 を切る
			( つまり、外からはn[v].cut() )
			vの親ってのはsplayでいうとexpose(v)したあとのv->l
	*/
	void cut(){
		expose();
		l->p = nullptr;
		l = nil;
		update();
	}
	void evert(){
		expose();
		revdata();
	}

	/*
		query for [this, x] 
	*/
	D query(NP x){
		evert();
		x->expose();
//		x->showtree();puts("");
		return x->sm;
	}
	void query_update(NP x,const A& f){
		evert();
		x->expose();
		x->addlazy(f);
	}

	/*
		parent:
			expose(v) したあとは一つ左に行ってそっから右に行き続けたところ
			ちゃんとアクセスしたらexposeしないと計算量壊れるので最後にexposeする
	*/
	NP parent(){
		expose();
		NP v = this->l;
		if(v == nil) return nil;
		while(v->r != nil){
			v = v->r;
		}
		v->expose();
		return v;
	}

	NP root(){
		expose();
		NP v = this;
		while(v->l != nil){
			v = v->l;
		}
		v->expose();
		return v;
	}

	NP lca(NP x){
		x->expose();
		expose();
		NP w = x;
		while(x->p != nullptr){
			if(!x->pos()) w = x->p;
			x = x->p;
		}
		return (this == x) ? w : nullptr;
	}

	/*
		thisからそのsplay木内だけ
	*/
	void showtree(){
		cout<<" [ ";
		if(l->sz) l->showtree();
		cout<<v;
		if(r->sz) r->showtree();
		cout<<" ] ";
	}
};

using ll = long long;
const ll inf = 1e17;

struct handler{
	/*
		range assign
		range subseqsummax
	*/
	struct val_t{
		ll sm,lmx,rmx,mx;
		val_t(){*this = e();}
		val_t(ll x){
			sm = lmx = rmx = mx = x;
		}
		val_t(ll sm,ll lmx,ll rmx,ll mx):sm(sm),lmx(lmx),rmx(rmx),mx(mx){}

		const static val_t e(){
			return val_t(0,-inf,-inf,-inf);
		}
		val_t operator+(const val_t &r) const {
			return val_t(sm+r.sm, max(lmx,sm+r.lmx), max(r.rmx,r.sm+rmx), max(max(mx,r.mx),rmx+r.lmx));
		}

		void revdata(){
			swap(lmx,rmx);
		}

		friend ostream& operator<<(ostream& o,const val_t& d){return o<<d.sm;}
	};

	struct opr_t{
		ll x;
		opr_t(){*this = e();}
		opr_t(ll x):x(x){}

		const static opr_t e(){
			return opr_t(inf);
		}
		friend ostream& operator<<(ostream& o,const opr_t& d){return o<<d.x;}
	};

	static void setg2fg(const opr_t &f, opr_t &g){	//g -> fg		f after g
		if(f.x != inf) g.x = f.x;
	}
	static val_t act(const opr_t &f, const val_t &v,int len){
		if(f.x == inf) return v;
		ll a = f.x*len;
		ll b = max(a,f.x);
		return val_t(a,b,b,b);
	}
};
template<>
LCNode<handler>::NP LCNode<handler>::nil = new LCNode();


using D = handler::val_t;
using A = handler::opr_t;
using NP = LCNode<handler>*;

int N,Q;
vector<vector<int>> G;
vector<NP> tree;

void dfs(int v,int p=-1){
	if(p!=-1){
		tree[v]->link(tree[p]);
	}
	for(int u:G[v]) if(u!=p) dfs(u,v);
}

D query(int a,int b){
	return tree[a]->query(tree[b]);
}
void update(int a,int b,const A& f){
	return tree[a]->query_update(tree[b],f);
}

int main(){
	cin>>N>>Q;
	G.resize(N);
	tree.resize(N);
	rep(i,N){
		int w;
		cin>>w;
		tree[i] = new LCNode<handler>(D(w));
	}
	rep(i,N-1){
		int x,y;
		cin>>x>>y;
		x--,y--;
		G[x].pb(y);
		G[y].pb(x);
	}
	dfs(0);

	rep(q,Q){
//		printf("----- %d times end-----\n",q);
		int t,a,b,c;
		cin>>t>>a>>b>>c;
		a--,b--;
		if(t==1){
			update(a,b,A(c));
		}else{
			D v = query(a,b);
//			show(v.sm);
//			show(v.lmx);
//			show(v.rmx);
//			show(v.mx);
			cout<<v.mx<<endl;
		}
	}
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/splay/LCTree.cpp"
/*
	Link Cut Tree
	根付き森を扱うデータ構造
	
	使い方
		pathに対する query,lazy query
		link : v(親なし) の親を p に設定する
		cut : v を 親から切り離す
		evert: 根を変更する
		これらが全て O(log N) で可能.

		外側では各頂点vに対して, NP n[v] を持つ(外でこれをいじる必要はない)
		逆に内側で NP から v を復元したいときはHandlerに頂点を追加しておけば良い?

		より変な操作(v-u間rotate)とかになったらsplay(int k) とかをsplay_lazy から持ってくる必要がありそう


	動作原理?
		動的 HL decomposition みたいな雰囲気
		各pathをsplay tree で表現する、根に近い方がleft
		expose(v): (根付き木での)vからrootを一つのpathにする, ついでにvをその"splay木の"根にする)
			これに含まれるHLdecompの各pathではある点から上全てを見ることになるので、
			splayの言葉でいうとleft child を残す
			v-root間がvを根とする一つのsplayになるので、何も考えずにvにクエリ飛ばせばいい
		evert(v): (根付き木での)rootをvに変える
			exposeしたあとはsplay的にはreverseに対応する

		smとかは各splay内で完結していることに注意!
		例えば、linkで p = r としたときに r->update() しなくていいのは、これが splay tree の edge ではないから

	参考
		http://yosupo.hatenablog.com/entry/2014/12/26/001414 (古いのでrevの持ち方とか微妙)
		http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1675225 (みじかい)
		https://github.com/yosupo06/Algorithm/blob/master/datastructure/linkcuttree.h#L36 (かなり信頼できる)
		https://www.slideshare.net/iwiwi/2-12188845 (iwiwiさんのいつものやつ)

	verified
		do use segment tree
			バグらせたとこ: actの時長さが引数にいる, 引数はsmはszでいいけどvは1
		spaceships
			lcaのverifyになったね
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
struct LCNode{
	using NP = LCNode*;
	static NP nil;

	using D = typename Handler::val_t;	//data
	using A = typename Handler::opr_t;	//action


	NP p,l,r;
	int sz;
	D v,sm;
	A lz;
	bool rev;
	LCNode(D v,A a) :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v),lz(a),rev(false){}
	LCNode(D v) :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v),lz(A::e()),rev(false){}
	LCNode() : p(nullptr),l(nullptr),r(nullptr),sz(0),v(D::e()),sm(D::e()),lz(A::e()),rev(false){}

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
		update();//	zig,zig-zag,zig-zigともにどうせ次でupdateがよばれるのでいらない(最後根はいる←これ実はmerge/splitでちゃんとupdateしてるから書かなくていいんだよね)
		p=pp;
		if(pps==0) return;
		if(pps==-1) pp->l=this;
		else pp->r=this;
		if(pp->sz) pp->update();	//これもいらんかも
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
	/*
		expose
		根付き木において、thisからrまでのpathを1つのsplay treeにする(下はちゃんと切る)
		ついでにthisを(splay tree の意味で)rootに持ってくる
		実際の木の根を変えるevertとは違うので注意!
	*/
	void expose(){
		NP v = this, vr = nil;

		while(true){
			v->splay();
			v->r = vr;	//first: cut right
			v->update();
			vr = v;		//next vr
			v = v->p;	//LinkCutのparent(別のsplaytreeに移動する)
			if(v==nullptr) break;
		}
		v = this;
		v->r = nil;	//cut
		v->update();

		while(v->p){
			v->p->r = v;
			v = v->p;
			v->update();
		}
		splay();
	}
	NP update(){		//情報更新(子が正しい時に呼ばないとダメ) (最後にupdateしてreturnするのに楽なのでNPを返す)
		sz=1+l->sz+r->sz;
		sm = v;
		if(l->sz) sm = l->sm + sm;	//if(l) だとnilでも呼ぶ羽目になりそう
		if(r->sz) sm = sm + r->sm;
		return this;
	}
	/*
		reverse

		revを扱うときは全てrevdata()をよぶ、個のタイミングでもうswap(l,r)もしちゃう

		reverse機能はlazy splayの機構の内側で扱ってもいいかと思ったけど、LCTree の Node に別の情報として持たせることにした
		1. 今持ってる data sm (a+b+..+c) から、sm.reverse (c+..+b+a)が簡単に計算できる場合
			revdata() の中にそれをかけばおわり
		2. できない場合
			sm と revsm (必要ならlz も同様?) をNodeに両方持って頑張る
			と思ったけどそれよりはHandlerに2つ持たせたほうが楽そう
		lzも変わっちゃう場合に根本的に対応できてない気がしてきた、普通そうならんしむずそうなので諦め

		ちなみにreverseは、evert(根変更クエリ)のために使います
		(現root - root 間のpathの向きだけ逆にするという操作になって、各splay木で左が元の根付き木での上に対応することを思い出すと)
	*/
	void revdata(){
		rev ^= true;
		swap(l,r);
		sm.revdata();
	}
	void addlazy(const A& f){
		Handler::setg2fg(f,lz);
		v = Handler::act(f,v,1);
		sm = Handler::act(f,sm,sz);
	}
	void push(){
		if(rev){
			if(l->sz) l->revdata();
			if(r->sz) r->revdata();
			rev = false;
		}
		if(l->sz) l->addlazy(lz);
		if(r->sz) r->addlazy(lz);
		lz = A::e();
	}
	void pushdown(){	//from root to this
		if(pos()) p->pushdown();
		push();
	}

	/*
		link:
			thisに対応する根付き木の頂点の親 を rに対応する根付き木の頂点 にする
			( つまり、外からはn[v].link(n[r]) )
	*/
	void link(NP r){
		expose();
		r->expose();
		p = r;
	}
	/*
		cut:
			thisに対応する根付き木の頂点 と その親 を切る
			( つまり、外からはn[v].cut() )
			vの親ってのはsplayでいうとexpose(v)したあとのv->l
	*/
	void cut(){
		expose();
		l->p = nullptr;
		l = nil;
		update();
	}
	void evert(){
		expose();
		revdata();
	}

	/*
		query for [this, x] 
	*/
	D query(NP x){
		evert();
		x->expose();
//		x->showtree();puts("");
		return x->sm;
	}
	void query_update(NP x,const A& f){
		evert();
		x->expose();
		x->addlazy(f);
	}

	/*
		parent:
			expose(v) したあとは一つ左に行ってそっから右に行き続けたところ
			ちゃんとアクセスしたらexposeしないと計算量壊れるので最後にexposeする
	*/
	NP parent(){
		expose();
		NP v = this->l;
		if(v == nil) return nil;
		while(v->r != nil){
			v = v->r;
		}
		v->expose();
		return v;
	}

	NP root(){
		expose();
		NP v = this;
		while(v->l != nil){
			v = v->l;
		}
		v->expose();
		return v;
	}

	NP lca(NP x){
		x->expose();
		expose();
		NP w = x;
		while(x->p != nullptr){
			if(!x->pos()) w = x->p;
			x = x->p;
		}
		return (this == x) ? w : nullptr;
	}

	/*
		thisからそのsplay木内だけ
	*/
	void showtree(){
		cout<<" [ ";
		if(l->sz) l->showtree();
		cout<<v;
		if(r->sz) r->showtree();
		cout<<" ] ";
	}
};

using ll = long long;
const ll inf = 1e17;

struct handler{
	/*
		range assign
		range subseqsummax
	*/
	struct val_t{
		ll sm,lmx,rmx,mx;
		val_t(){*this = e();}
		val_t(ll x){
			sm = lmx = rmx = mx = x;
		}
		val_t(ll sm,ll lmx,ll rmx,ll mx):sm(sm),lmx(lmx),rmx(rmx),mx(mx){}

		const static val_t e(){
			return val_t(0,-inf,-inf,-inf);
		}
		val_t operator+(const val_t &r) const {
			return val_t(sm+r.sm, max(lmx,sm+r.lmx), max(r.rmx,r.sm+rmx), max(max(mx,r.mx),rmx+r.lmx));
		}

		void revdata(){
			swap(lmx,rmx);
		}

		friend ostream& operator<<(ostream& o,const val_t& d){return o<<d.sm;}
	};

	struct opr_t{
		ll x;
		opr_t(){*this = e();}
		opr_t(ll x):x(x){}

		const static opr_t e(){
			return opr_t(inf);
		}
		friend ostream& operator<<(ostream& o,const opr_t& d){return o<<d.x;}
	};

	static void setg2fg(const opr_t &f, opr_t &g){	//g -> fg		f after g
		if(f.x != inf) g.x = f.x;
	}
	static val_t act(const opr_t &f, const val_t &v,int len){
		if(f.x == inf) return v;
		ll a = f.x*len;
		ll b = max(a,f.x);
		return val_t(a,b,b,b);
	}
};
template<>
LCNode<handler>::NP LCNode<handler>::nil = new LCNode();


using D = handler::val_t;
using A = handler::opr_t;
using NP = LCNode<handler>*;

int N,Q;
vector<vector<int>> G;
vector<NP> tree;

void dfs(int v,int p=-1){
	if(p!=-1){
		tree[v]->link(tree[p]);
	}
	for(int u:G[v]) if(u!=p) dfs(u,v);
}

D query(int a,int b){
	return tree[a]->query(tree[b]);
}
void update(int a,int b,const A& f){
	return tree[a]->query_update(tree[b],f);
}

int main(){
	cin>>N>>Q;
	G.resize(N);
	tree.resize(N);
	rep(i,N){
		int w;
		cin>>w;
		tree[i] = new LCNode<handler>(D(w));
	}
	rep(i,N-1){
		int x,y;
		cin>>x>>y;
		x--,y--;
		G[x].pb(y);
		G[y].pb(x);
	}
	dfs(0);

	rep(q,Q){
//		printf("----- %d times end-----\n",q);
		int t,a,b,c;
		cin>>t>>a>>b>>c;
		a--,b--;
		if(t==1){
			update(a,b,A(c));
		}else{
			D v = query(a,b);
//			show(v.sm);
//			show(v.lmx);
//			show(v.rmx);
//			show(v.mx);
			cout<<v.mx<<endl;
		}
	}
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

