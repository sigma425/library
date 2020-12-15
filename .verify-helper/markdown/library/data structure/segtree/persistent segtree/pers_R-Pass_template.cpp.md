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


# :warning: data structure/segtree/persistent segtree/pers_R-Pass_template.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#804b46389e12899b5eab90f4bea5a2e6">data structure/segtree/persistent segtree</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/segtree/persistent segtree/pers_R-Pass_template.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	point assign,range ほげ(+)
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
	D(){}
	D(int x):x(x){}
	const static D e;
	D operator+(const D& r) const {
		return D(x+r.x);
	}
	friend ostream& operator<<(ostream& o,const D& d){return o<<d.x;}
};
const D D::e = D(0);

template<class D>
struct segtree{
	int update(int ver,int x,D v){				//変更クエリ version ver のa[x]をvに変えて,新しいversionのroot idを返す
		root[++R]=update(root[ver],x,0,N,v);
		return R;
	}
	int update_(int ver,int x,D v){
		root[R]=update(root[ver],x,0,N,v);
		return R;
	}
	D query(int ver,int a,int b){				//回答クエリ version verの[a,b)を求める
		return query(a,b,0,N,root[ver]);
	}
	static const int N=11;			//配列の長さ,2ベキじゃなくてよい
	static const int MX=1000000;		//nodeの数 変更クエリの数* segtreeの深さ くらい
	static const int MR=1000000;		//rootの数 普通,変更クエリの数+1だと思う
	struct Node;
	typedef Node* NP;
	struct Node{
		NP lch,rch;
		D v;
		Node(NP l,NP r,D v):lch(l),rch(r),v(v){}
		Node(){}
	};
	Node pool[MX];
	NP root[MR];
	NP nil;
	int I,R;
	NP news(NP lch,NP rch,D v){
		return &(pool[I++]=Node(lch,rch,v));
	}
	NP news(NP lch,NP rch){
		return &(pool[I++]=Node(lch,rch,lch->v+rch->v));
	}
	NP update(NP x,int pos,int l,int r,D v){		//a[pos]:=v. 今x以下を処理している 新しいバージョンのxに対応する部分を返す
/*		NP tmp;
		if(r-l==1) tmp=news(nil,nil,v);			//addならここを変える
		else{
			int m=(l+r)/2;
			if(pos<m) tmp=news(update(x->lch,pos,l,m,v),x->rch);
			else tmp=news(x->lch,update(x->rch,pos,m,r,v));
		}

		printf("pos,l,r=(%d,%d,%d)\n",pos,l,r);
		show(v);
		showtree(tmp);
		puts("");
		return tmp;*/
		if(r-l==1) return news(nil,nil,v);			//addならここを変える
		int m=(l+r)/2;
		if(pos<m) return news(update(x->lch,pos,l,m,v),x->rch);
		else return news(x->lch,update(x->rch,pos,m,r,v));
	}
	D query(int a,int b,int l,int r,NP x){			//range query
		if(x==nil) return D::e;					//初期値が変な場合はここを変える!!
		if(b<=l||r<=a) return D::e;
		if(a<=l&&r<=b) return x->v;
		int m=(l+r)/2;
		return query(a,b,l,m,x->lch)+query(a,b,m,r,x->rch);
	}
	void showtree(int r){
		showtree(root[r]);
	}
	void showtree(NP x){
		if(x==nil){
			cout<<"nil";
			return;
		}
		printf("(");
		showtree(x->lch);
		cout<<","<<x->v<<",";	//Dに<<が定義されてればOK
		showtree(x->rch);
		printf(")");
	}
	segtree(){
		I=0,R=0;
		nil=news(0,0,D::e);
		nil->lch=nil,nil->rch=nil;
		root[0]=nil;
	}
};
segtree<D> seg;
int main(){
	int Q;
	cin>>Q;
	int r=0;
	rep(i,Q){
		char c;
		cin>>c;
		if(c=='c'){
			int x,v,ver;
			cin>>x>>v>>ver;
			r=seg.update(ver,x,D(v));
			show(r);
			seg.showtree(r);
			puts("");
		}else{
			int x,y;
			cin>>x>>y;
			show(seg.query(r,x,y));
		}
	}
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/segtree/persistent segtree/pers_R-Pass_template.cpp"
/*
	point assign,range ほげ(+)
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
	D(){}
	D(int x):x(x){}
	const static D e;
	D operator+(const D& r) const {
		return D(x+r.x);
	}
	friend ostream& operator<<(ostream& o,const D& d){return o<<d.x;}
};
const D D::e = D(0);

template<class D>
struct segtree{
	int update(int ver,int x,D v){				//変更クエリ version ver のa[x]をvに変えて,新しいversionのroot idを返す
		root[++R]=update(root[ver],x,0,N,v);
		return R;
	}
	int update_(int ver,int x,D v){
		root[R]=update(root[ver],x,0,N,v);
		return R;
	}
	D query(int ver,int a,int b){				//回答クエリ version verの[a,b)を求める
		return query(a,b,0,N,root[ver]);
	}
	static const int N=11;			//配列の長さ,2ベキじゃなくてよい
	static const int MX=1000000;		//nodeの数 変更クエリの数* segtreeの深さ くらい
	static const int MR=1000000;		//rootの数 普通,変更クエリの数+1だと思う
	struct Node;
	typedef Node* NP;
	struct Node{
		NP lch,rch;
		D v;
		Node(NP l,NP r,D v):lch(l),rch(r),v(v){}
		Node(){}
	};
	Node pool[MX];
	NP root[MR];
	NP nil;
	int I,R;
	NP news(NP lch,NP rch,D v){
		return &(pool[I++]=Node(lch,rch,v));
	}
	NP news(NP lch,NP rch){
		return &(pool[I++]=Node(lch,rch,lch->v+rch->v));
	}
	NP update(NP x,int pos,int l,int r,D v){		//a[pos]:=v. 今x以下を処理している 新しいバージョンのxに対応する部分を返す
/*		NP tmp;
		if(r-l==1) tmp=news(nil,nil,v);			//addならここを変える
		else{
			int m=(l+r)/2;
			if(pos<m) tmp=news(update(x->lch,pos,l,m,v),x->rch);
			else tmp=news(x->lch,update(x->rch,pos,m,r,v));
		}

		printf("pos,l,r=(%d,%d,%d)\n",pos,l,r);
		show(v);
		showtree(tmp);
		puts("");
		return tmp;*/
		if(r-l==1) return news(nil,nil,v);			//addならここを変える
		int m=(l+r)/2;
		if(pos<m) return news(update(x->lch,pos,l,m,v),x->rch);
		else return news(x->lch,update(x->rch,pos,m,r,v));
	}
	D query(int a,int b,int l,int r,NP x){			//range query
		if(x==nil) return D::e;					//初期値が変な場合はここを変える!!
		if(b<=l||r<=a) return D::e;
		if(a<=l&&r<=b) return x->v;
		int m=(l+r)/2;
		return query(a,b,l,m,x->lch)+query(a,b,m,r,x->rch);
	}
	void showtree(int r){
		showtree(root[r]);
	}
	void showtree(NP x){
		if(x==nil){
			cout<<"nil";
			return;
		}
		printf("(");
		showtree(x->lch);
		cout<<","<<x->v<<",";	//Dに<<が定義されてればOK
		showtree(x->rch);
		printf(")");
	}
	segtree(){
		I=0,R=0;
		nil=news(0,0,D::e);
		nil->lch=nil,nil->rch=nil;
		root[0]=nil;
	}
};
segtree<D> seg;
int main(){
	int Q;
	cin>>Q;
	int r=0;
	rep(i,Q){
		char c;
		cin>>c;
		if(c=='c'){
			int x,v,ver;
			cin>>x>>v>>ver;
			r=seg.update(ver,x,D(v));
			show(r);
			seg.showtree(r);
			puts("");
		}else{
			int x,y;
			cin>>x>>y;
			show(seg.query(r,x,y));
		}
	}
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

