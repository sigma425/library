/*
SplayTree(かんたんver)
simple_segtreeの上位互換.query(l,r), assign(x,d)は同じ使い方が出来る.
verified by AOJ1508(circular RMQ)
列に分割するときは,split関数を外で定義しないとくっそ書きづらいのでそうする

SplayTree<Dmin>::NP merge(SplayTree<Dmin>::NP x, SplayTree<Dmin>::NP y){
	return SplayTree<Dmin>::merge(x,y);
}
pair<SplayTree<Dmin>::NP,SplayTree<Dmin>::NP> split(SplayTree<Dmin>::NP x, int k){
	return SplayTree<Dmin>::split(x,k);
}

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

template<class D>
struct SplayTree{
	struct Node;
	using NP = Node*;
	static NP nil;

	struct Node{
		NP p,l,r;
		int sz;
		D v,sm;
		Node(D v) :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v){}
		Node() : p(nullptr),l(nullptr),r(nullptr),sz(0),v(D::e()),sm(D::e()){}
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


struct Dmin{		//(int,min,inf)
	int x;
	Dmin(){}
	Dmin(int x):x(x){}
	static Dmin e(){
		return Dmin(1e9);
	}
	Dmin operator+(const Dmin& r) const {
		return Dmin(min(x,r.x));
	}
	friend ostream& operator<<(ostream& o,const Dmin& d){return o<<d.x;}
};
template<>
SplayTree<Dmin>::NP SplayTree<Dmin>::nil = new SplayTree<Dmin>::Node();

SplayTree<Dmin>::NP merge(SplayTree<Dmin>::NP x, SplayTree<Dmin>::NP y){
	return SplayTree<Dmin>::merge(x,y);
}
pair<SplayTree<Dmin>::NP,SplayTree<Dmin>::NP> split(SplayTree<Dmin>::NP x, int k){
	return SplayTree<Dmin>::split(x,k);
}

/*
struct Dmat{
	using T = int;
	using D = Dmat;
	const static int N = 5;
	using V = array<T,N>;
	using VV = array<V,N>;
	VV a;
	Dmat(){}
	Dmat(VV a):a(a){}
	const static D e(){
		VV a;
		rep(i,N) rep(j,N) a[i][j] = (i==j?1:0);
		return D(a);
	}
	D operator+(const D& r) const {
		VV c;
		rep(i,N) rep(j,N) c[i][j]=0;
		rep(i,N) rep(j,N) rep(k,N) c[i][j] += a[i][k] * r.a[k][j];
		return D(c);
	};
	bool operator==(const D& r) const {
		return a==r.a;
	}
};
template<>
SplayTree<Dmat>::NP SplayTree<Dmat>::nil = new SplayTree<Dmat>::Node();

*/

void unittest(){
	{
		using D = Dmin;
		vector<D> vc;
		int N = 100;
		rep(i,N) vc.pb(Dmin(rand()%1000));
		SplayTree<Dmin> Stree(vc);
		rep(l,N) for(int r=l;r<=N;r++){
			int mn = 1e9;
			for(int i=l;i<r;i++) chmin(mn,vc[i].x);
			assert( Stree.query(l,r).x == mn);
		}
	}
	{
		using D = Dmat;
		const int K = Dmat::N;
		using T = int;
		using V = array<T,K>;
		using VV = array<V,K>;

		vector<D> vs;
		int N = 100;
		rep(i,N){
			VV a;
			rep(x,K) rep(y,K) a[x][y] = rand()%201+100;
			vs.push_back(D(a));
		}
//		segtree_simple<D> seg(vs);
		SplayTree<D> Stree(vs);
		rep(qt,1000){
			if(rand()%2){
				VV a;
				rep(x,K) rep(y,K) a[x][y] = rand()%201+100;
				int idx = rand()%N;
				vs[idx] = D(a);
				Stree.assign(idx,D(a));
			}else{
				int l = rand()%100, r = rand()%100;
				if(l>r) swap(l,r);
				r++;
				D x = D::e();
				for(int i=l;i<r;i++) x = x+vs[i];
				assert( Stree.query(l,r) == x );
			}
		}
	}
}

int main(){
	srand((unsigned)time(NULL));
	unittest();

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
