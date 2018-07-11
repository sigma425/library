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

struct LinkCutTree{
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
		bool rev;
		Node(D v,A a) :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v),lz(a),rev(false){}
		Node(D v) :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v),lz(A::e()),rev(false){}
		Node() : p(nullptr),l(nullptr),r(nullptr),sz(0),v(D::e()),sm(D::e()),lz(A::e()),rev(false){}

		int pos(){			//親の左の子か,右の子か,それとも根(or nil)か
			if(p&&p->l == this) return -1;
			if(p&&p->r == this) return 1;
			return 0;
		}
		void rot(){				//rootで呼ぶと死
			NP pp=p->p;
			assert(pp != nullptr);
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
			pp->update();	//これもいらんかも
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
			根付き木において、thisからrまでのpathを1つのsplay treeにする
			ついでにthisを(splay tree の意味で)rootに持ってくる
			実際の木の根を変えるevertとは違うので注意!
		*/
		void expose(){
			NP v = this;
			while(v){
				v->splay();
				v = v->p;	//LinkCutのparent(別のsplaytreeに移動する)
			}
			v = this;
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

			//非可換ならなんか書いて
			//e.g. swap(lsm,rsm);
		}
		void push(){
			if(rev){
				if(l->sz) l->revdata();
				if(r->sz) r->revdata();
				rev = false;
			}
			if(l->sz) Handler::setg2fg(lz,l->lz);
			if(r->sz) Handler::setg2fg(lz,r->lz);
			v = Handler::act(lz,v);
			lz = A::e();
		}
		void pushdown(){	//from root to this
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

}


int main(){

}