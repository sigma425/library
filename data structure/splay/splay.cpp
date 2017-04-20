/*
SplayTree

変える必要があるのは
Nodeの定義+コンストラクタ
update
あとはクエリ
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

struct SplayTree{
	using D = long long;
	struct Node;
	using NP = Node*;
	static NP nil;

	struct Node{
		NP p,l,r;			//parent,left child,right child
		int sz;
		D v,sm;				//infos
		Node(D v) :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v){}
		Node() : p(nullptr),l(nullptr),r(nullptr),sz(0),v(0),sm(0){}						//単位元!!
		int pos(){			//親の左の子か,右の子か,それとも根(or nil)か
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
			if(l->sz) sm+=l->sm;	//if(l) だとnilでも呼ぶ羽目になりそう
			if(r->sz) sm+=r->sm;
			return this;
		}

	};
	NP n;
	static NP merge(NP l,NP r){			//return mergeした根
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
		まあでも基本的にsplitの第一引数はrootなので大丈夫
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
	static NP built(int sz,D vs[]){				//init
		if(!sz) return nil;
		int md=sz/2;
		NP x= new Node(vs[md]);
		x->l = built(md,vs);
		x->l->p=x;
		x->r=built(sz-(md+1),vs+md+1);
		x->r->p=x;
		return x->update();
	}
	static NP built(int sz,const vector<D>& vs,int off){				//init
		if(!sz) return nil;
		int md=sz/2;
		NP x= new Node(vs[off+md]);
		x->l = built(md,vs,off);
		x->l->p=x;
		x->r=built(sz-(md+1),vs,off+md+1);
		x->r->p=x;
		return x->update();
	}

	SplayTree() : n(nil){}
	SplayTree(NP n) : n(n){}
	SplayTree(int sz,D vs[]){
		n=built(sz,vs);
	}
	SplayTree(int sz,vector<D> vs){
		n=built(sz,vs,0);
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
	D sum(int l,int r){			//[l,r)
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
};
SplayTree::NP SplayTree::nil = new SplayTree::Node();

int main(){
	int N;
//	long long vs[100];
	vector<long long> vs;
	cin>>N;
	vs.assign(N,0);
	rep(i,N) cin>>vs[i];
	SplayTree ST(N,vs);

	rep(i,N) show(ST.get(i));
	while(true){
		long long x;
		cin>>x;
		show(ST.lower_bound(x));
		show(ST.upper_bound(x));
	}
}
