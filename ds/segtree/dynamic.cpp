/*
	Range+_PointAssign の動的版
	新規にアクセスするとやっとノードを作る 範囲アクセスごとにlog N個のノードを作るので、計QlogN個. 時間計算量はクエリごとlogN.

	元からなんらかの値が入っているがサボれる場合
	ex. N=10^9で,はじめはa[i]=i,range sumとpoint assignがくる
	new Nodeするときにうまいことやればいいので、
	Nodeのコンストラクタ(int l,int r,NP p)で、valを書き換えれば良い(上の例だと、val=l+...+r-1にする)
	lとrさえあれば必要な情報はあるはずなのでこれで十分

	point assign,range +
	semigroup D でのsegtree

	変えるべきところは,
	- Dのメンバ変数
	- Dのコンストラクタ
	- operator+
	- structの外のD::eのinitialize
	- (あとお好みでoperator<<)

*/
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define show(x) cout<< #x <<" "<<x<<endl
using namespace std;

struct D{
	int x;
	D(){*this = e;}
	D(int x):x(x){}
	const static D e;
	D operator+(const D& r) const {
		return D(x+r.x);
	}
	friend ostream& operator<<(ostream& o,const D& d){return o<<d.x;}
};
const D D::e = D(0);

template<class T>
struct segtree{
	struct Node;
	using NP = Node*;

	struct Node{
		T val;
		int l,r;
		NP p,lch,rch;
		Node(int l,int r,NP p):val(),l(l),r(r),p(p),lch(nullptr),rch(nullptr){
//			val=T((r-l)*(r+l-1)/2);
		}
//		Node(int l,int r,NP p,T val=T::e):val(val),l(l),r(r),p(p),lch(nullptr),rch(nullptr){}
	};

	T e=T::e;
	NP root;
	segtree(){}
	segtree(int n){
		int N=1;
		while(n>N) N*=2;
		root = new Node(0,N,nullptr);
		root->lch = nullptr;
		root->rch = nullptr;
		root->val = e;
	}

	void update(int x,T val,NP n=nullptr){
		if(n==nullptr) n=root;
		int l=n->l,r=n->r;
		if(x<l||r<=x) return;
		if(l==x&&r-l==1){
			n->val=val;
			return;
		}
		if(n->lch == nullptr) n->lch = new Node(l,(l+r)/2,n);
		if(n->rch == nullptr) n->rch = new Node((l+r)/2,r,n);
		update(x,val,n->lch);
		update(x,val,n->rch);
		n->val = n->lch->val + n->rch->val ;
	}
	T calc(int a,int b,NP n=nullptr){
		if(n==nullptr) n=root;
		int l=n->l,r=n->r;
		if(b<=l||r<=a) return e;
		if(a<=l&&r<=b) return n->val;
		if(n->lch == nullptr) n->lch = new Node(l,(l+r)/2,n);
		if(n->rch == nullptr) n->rch = new Node((l+r)/2,r,n);
		return calc(a,b,n->lch)+calc(a,b,n->rch);
	}
};
segtree<D> seg;
int main(){
	int N;
	cin>>N;
	seg=segtree<D>(N);
	while(true){
		char c;
		cin>>c;
		if(c=='c'){	//change
			int x,v;
			cin>>x>>v;
			seg.update(x,D(v));
		}else{
			int l,r;
			cin>>l>>r;
			r++;
			cout<<"ans="<<seg.calc(l,r)<<endl;
		}
	}
}
