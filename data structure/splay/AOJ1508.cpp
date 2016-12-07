//point rewrite, range min, range rotate

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
int inf=1e9;
struct SplayTree{
	struct Node;
	typedef Node* NP;
	static NP nil;
	struct Node{
		NP p,l,r;			//parent,left child,right child
		int sz;
		int v,mn;				//infos
		Node(int v) :p(nullptr),l(nil),r(nil),sz(1),v(v),mn(v){}
		Node() : l(nullptr),r(nullptr),sz(0),v(0),mn(inf){}						//単位元!!
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
			mn=std::min(v,std::min(l->mn,r->mn));
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
	static NP built(int sz,int vs[]){				//init
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
	SplayTree(int sz,int vs[]){
		n=built(sz,vs);
	}
	void insert(int k,int v){
		auto u=split(n,k);
		n=merge(merge(u.fs,new Node(v)),u.sc);
	}
	void erase(int k){
		auto u=split(n,k);
		n=merge(u.fs,split(u.sc,1).sc);
	}
	void rewrite(int k,int v){
		auto a=split(n,k);
		auto b=split(a.sc,1);
		b.fs->v=b.fs->mn=v;
		n=merge(merge(a.fs,b.fs),b.sc);
	}
	void merge(SplayTree t){
		n=merge(n,t.n);
	}
	int sz(){
		return n->sz;
	}
	int get(int k){			//kth info
		auto a=split(n,k);
		auto b=split(a.sc,1);
		int ret=b.fs->v;
		n=merge(merge(a.fs,b.fs),b.sc);
		return ret;
	}
	int min(int l,int r){		//[l,r)
		auto b=split(n,r);
		auto a=split(b.fs,l);
		int ret=a.sc->mn;
		n=merge(merge(a.fs,a.sc),b.sc);
		return ret;
	}
	/*
		search
		平衡二分木としての役目を思い出せ
		なんか列をくっつけたりわけたりできるとだけ思っとけば基本いいけど
		持ってるデータに順序付いてるときにはちゃんと二分木として使える
	*/
	int lower_bound(int x){		//x以上で一番小さいとこのidを返す
		NP p=n;
		int ret=0;
		while(p!=nil){
			if(x<=p->v) p=p->l;
			else ret+=(p->l->sz)+1,p=p->r;
		}
		return ret;
	}
	int upper_bound(int x){		//x以上で一番小さいとこのidを返す
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
	int N,Q,a[200000];
	cin>>N>>Q;
	rep(i,N) cin>>a[i];
	SplayTree ST(N,a);
	rep(i,Q){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x==0){
			auto p=SplayTree::split(ST.n,y);
			auto q=SplayTree::split(p.sc,z-y);
			auto r=SplayTree::split(q.sc,1);
			ST.n=SplayTree::merge(SplayTree::merge(p.fs,r.fs),SplayTree::merge(q.fs,r.sc));
		}
		if(x==1){
			cout<<ST.min(y,z+1)<<endl;
		}
		if(x==2){
			ST.rewrite(y,z);
		}
	}
//	rep(i,N) show(ST.get(i));
}
