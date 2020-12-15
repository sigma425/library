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


# :warning: data structure/splay/L.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a139cdef544a41bbe9de0547a0bc58bb">data structure/splay</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/splay/L.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	これなんだっけ?
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

namespace SuffixArray{
	template<class T>
	void induce(int N,const T s[],bool is[],int sa[],int lbase[],int K){
		int it[K+1];
		copy_n(lbase,K+1,it);
		rep(i,N+1){
			if(sa[i]>=1&&!is[sa[i]-1]){
				int c=s[sa[i]-1];
				sa[it[c]++]=sa[i]-1;
			}
		}
		copy_n(lbase,K+1,it);
		for(int i=N;i>0;i--){
			if(sa[i]>=1&&is[sa[i]-1]){
				int c=s[sa[i]-1];
				sa[--it[c+1]]=sa[i]-1;
			}
		}
	}
	template<class T>
	void SA(int N,const T s[],int sa[],int K){
		bool is[N+1];		//stype?
		int lcnt[K+1]={},scnt[K+1]={};
		is[N]=1;
		for(int i=N-1;i>=0;i--){
			if(i==N-1||s[i]>s[i+1]) is[i]=0;
			else if(s[i]<s[i+1]) is[i]=1;
			else is[i]=is[i+1];
			if(!is[i]) lcnt[(int)s[i]]++;
			else scnt[(int)s[i]]++;
		}
		vector<int> v;		//LMSs
		int lms[N+1];
		fill_n(lms,N+1,-1);
		int c=0;
		rep1(i,N-1){
			if(!is[i-1]&&is[i]){
				lms[i]=c++;
				v.pb(i);
			}
		}
		int lbase[K+1],sbase[K+1];
		lbase[0]=1,sbase[0]=1+lcnt[0];
		rep1(i,K){
			lbase[i]=sbase[i-1]+scnt[i-1];
			sbase[i]=lbase[i]+lcnt[i];
		}
		if(!v.empty()){
			vector<int> v2=v;
			int it[K+1];			//iterate
			copy_n(sbase,K+1,it);
			fill_n(sa,N+1,-1);
			sa[0]=N;
			rep(i,v.size()){
				int c=s[v[i]];
				sa[it[c]++]=v[i];
			}
			induce(N,s,is,sa,lbase,K);
			int c=0;
			rep1(i,N) if(lms[sa[i]]>=0) v[c++]=sa[i];
			int s2[v.size()],sa2[v.size()+1];
			c=0;
			s2[lms[v[0]]]=0;
			for(int i=1;i<(int)v.size();i++){
				int l=v[i-1],r=v[i];
				while(true){
					if(s[l]!=s[r]){
						c++;
						break;
					}
					l++,r++;
					if(lms[l]>=0||lms[r]>=0){
						if(lms[l]<0||lms[r]<0) c++;
						break;
					}
				}
				s2[lms[v[i]]]=c;
			}
			SA(v.size(),s2,sa2,c);
			rep1(i,v.size()) v[i-1]=v2[sa2[i]];
		}
		int it[K+1];
		copy_n(sbase,K+1,it);
		fill_n(sa,N+1,-1);
		sa[0]=N;
		rep(i,v.size()){
			int c=s[v[i]];
			sa[it[c]++]=v[i];
		}
		induce(N,s,is,sa,lbase,K);
	}
}


template<class T>
struct SplayTree{
	struct Node;
	typedef Node* NP;
	static NP nil;
	struct Node{
		NP p,l,r;			//parent,left child,right child
		int sz;
		int v;
		Node(int v) :p(nullptr),l(nil),r(nil),sz(1),v(v){}
		Node() : p(nullptr),l(nullptr),r(nullptr),sz(0),v(0){}						//単位元!!
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
			//assert(0<=k&&k<sz);
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
		//assert(0<=k&&k<=x->sz);
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
	void insert(int v){
		int k=lower_bound(v);
		insert(k,v);
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
	int get(int k){			//kth info
		auto a=split(n,k);
		auto b=split(a.sc,1);
		int ret=b.fs->v;
		n=merge(merge(a.fs,b.fs),b.sc);
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
	int upper_bound(int x){		//xより大で一番小さいとこのidを返す
		NP p=n;
		int ret=0;
		while(p!=nil){
			if(x<p->v) p=p->l;
			else ret+=(p->l->sz)+1,p=p->r;
		}
		return ret;
	}
};
template<class T>
typename SplayTree<T>::NP SplayTree<T>::nil = new SplayTree<T>::Node();
struct segtree{
	int N;
	SplayTree<int> seg[1<<17];
	segtree(int n){
		int p2=1;
		while(p2<n) p2*=2;
		N=p2;
	}
	void add(int x,int y){			//add P(x,y)
		x+=N;
		while(x){
			seg[x].insert(y);
			x/=2;
		}
	}
	int count(int a,int b,int ya,int yb,int l,int r,int k){		//[a,b) * [ya,yb)
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return seg[k].lower_bound(yb)-seg[k].lower_bound(ya);
		return count(a,b,ya,yb,l,(l+r)/2,k*2)+count(a,b,ya,yb,(l+r)/2,r,k*2+1);
	}
	int count(int a,int b,int ya,int yb){
//		printf("[%d,%d)*[%d,%d)\n",a,b,ya,yb);
		return count(a,b,ya,yb,0,N,1);
	}
};

int lo(int *sa,string& s,string& t){
	int N=s.size()+1;
	int l=-1,r=N+1;
	while(r-l>1){
		int m=(r+l)/2;
		if(s.compare(sa[m],t.length(),t)<0) l=m;
		else r=m;
	}
	return r;
}
int hi(int *sa,string& s,string& t){
	int N=s.size()+1;
	int l=-1,r=N+1;
	while(r-l>1){
		int m=(r+l)/2;
		if(s.compare(sa[m],t.length(),t)<=0) l=m;
		else r=m;
	}
	return r;
}
int main(){
	int N,Q,sa[100001];
	string s;
	cin>>s>>Q;
	N=s.size();
	SuffixArray::SA(N,s.c_str(),sa,256);
	segtree seg(N+1);
	rep(i,N+1){
		seg.add(sa[i],i);
	}
	rep(tt,Q){
		int l,r;
		string t;
		cin>>l>>r>>t;
		r++;
		int K=t.size();
		if(r-l<K){
			puts("0");
			continue;
		}
		int ya=lo(sa,s,t);
		int yb=hi(sa,s,t);
		if(ya>=yb){
			puts("0");
			continue;
		}
		cout<<seg.count(l,r-K+1,ya,yb)<<endl;
	}
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/splay/L.cpp"
/*
	これなんだっけ?
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

namespace SuffixArray{
	template<class T>
	void induce(int N,const T s[],bool is[],int sa[],int lbase[],int K){
		int it[K+1];
		copy_n(lbase,K+1,it);
		rep(i,N+1){
			if(sa[i]>=1&&!is[sa[i]-1]){
				int c=s[sa[i]-1];
				sa[it[c]++]=sa[i]-1;
			}
		}
		copy_n(lbase,K+1,it);
		for(int i=N;i>0;i--){
			if(sa[i]>=1&&is[sa[i]-1]){
				int c=s[sa[i]-1];
				sa[--it[c+1]]=sa[i]-1;
			}
		}
	}
	template<class T>
	void SA(int N,const T s[],int sa[],int K){
		bool is[N+1];		//stype?
		int lcnt[K+1]={},scnt[K+1]={};
		is[N]=1;
		for(int i=N-1;i>=0;i--){
			if(i==N-1||s[i]>s[i+1]) is[i]=0;
			else if(s[i]<s[i+1]) is[i]=1;
			else is[i]=is[i+1];
			if(!is[i]) lcnt[(int)s[i]]++;
			else scnt[(int)s[i]]++;
		}
		vector<int> v;		//LMSs
		int lms[N+1];
		fill_n(lms,N+1,-1);
		int c=0;
		rep1(i,N-1){
			if(!is[i-1]&&is[i]){
				lms[i]=c++;
				v.pb(i);
			}
		}
		int lbase[K+1],sbase[K+1];
		lbase[0]=1,sbase[0]=1+lcnt[0];
		rep1(i,K){
			lbase[i]=sbase[i-1]+scnt[i-1];
			sbase[i]=lbase[i]+lcnt[i];
		}
		if(!v.empty()){
			vector<int> v2=v;
			int it[K+1];			//iterate
			copy_n(sbase,K+1,it);
			fill_n(sa,N+1,-1);
			sa[0]=N;
			rep(i,v.size()){
				int c=s[v[i]];
				sa[it[c]++]=v[i];
			}
			induce(N,s,is,sa,lbase,K);
			int c=0;
			rep1(i,N) if(lms[sa[i]]>=0) v[c++]=sa[i];
			int s2[v.size()],sa2[v.size()+1];
			c=0;
			s2[lms[v[0]]]=0;
			for(int i=1;i<(int)v.size();i++){
				int l=v[i-1],r=v[i];
				while(true){
					if(s[l]!=s[r]){
						c++;
						break;
					}
					l++,r++;
					if(lms[l]>=0||lms[r]>=0){
						if(lms[l]<0||lms[r]<0) c++;
						break;
					}
				}
				s2[lms[v[i]]]=c;
			}
			SA(v.size(),s2,sa2,c);
			rep1(i,v.size()) v[i-1]=v2[sa2[i]];
		}
		int it[K+1];
		copy_n(sbase,K+1,it);
		fill_n(sa,N+1,-1);
		sa[0]=N;
		rep(i,v.size()){
			int c=s[v[i]];
			sa[it[c]++]=v[i];
		}
		induce(N,s,is,sa,lbase,K);
	}
}


template<class T>
struct SplayTree{
	struct Node;
	typedef Node* NP;
	static NP nil;
	struct Node{
		NP p,l,r;			//parent,left child,right child
		int sz;
		int v;
		Node(int v) :p(nullptr),l(nil),r(nil),sz(1),v(v){}
		Node() : p(nullptr),l(nullptr),r(nullptr),sz(0),v(0){}						//単位元!!
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
			//assert(0<=k&&k<sz);
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
		//assert(0<=k&&k<=x->sz);
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
	void insert(int v){
		int k=lower_bound(v);
		insert(k,v);
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
	int get(int k){			//kth info
		auto a=split(n,k);
		auto b=split(a.sc,1);
		int ret=b.fs->v;
		n=merge(merge(a.fs,b.fs),b.sc);
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
	int upper_bound(int x){		//xより大で一番小さいとこのidを返す
		NP p=n;
		int ret=0;
		while(p!=nil){
			if(x<p->v) p=p->l;
			else ret+=(p->l->sz)+1,p=p->r;
		}
		return ret;
	}
};
template<class T>
typename SplayTree<T>::NP SplayTree<T>::nil = new SplayTree<T>::Node();
struct segtree{
	int N;
	SplayTree<int> seg[1<<17];
	segtree(int n){
		int p2=1;
		while(p2<n) p2*=2;
		N=p2;
	}
	void add(int x,int y){			//add P(x,y)
		x+=N;
		while(x){
			seg[x].insert(y);
			x/=2;
		}
	}
	int count(int a,int b,int ya,int yb,int l,int r,int k){		//[a,b) * [ya,yb)
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return seg[k].lower_bound(yb)-seg[k].lower_bound(ya);
		return count(a,b,ya,yb,l,(l+r)/2,k*2)+count(a,b,ya,yb,(l+r)/2,r,k*2+1);
	}
	int count(int a,int b,int ya,int yb){
//		printf("[%d,%d)*[%d,%d)\n",a,b,ya,yb);
		return count(a,b,ya,yb,0,N,1);
	}
};

int lo(int *sa,string& s,string& t){
	int N=s.size()+1;
	int l=-1,r=N+1;
	while(r-l>1){
		int m=(r+l)/2;
		if(s.compare(sa[m],t.length(),t)<0) l=m;
		else r=m;
	}
	return r;
}
int hi(int *sa,string& s,string& t){
	int N=s.size()+1;
	int l=-1,r=N+1;
	while(r-l>1){
		int m=(r+l)/2;
		if(s.compare(sa[m],t.length(),t)<=0) l=m;
		else r=m;
	}
	return r;
}
int main(){
	int N,Q,sa[100001];
	string s;
	cin>>s>>Q;
	N=s.size();
	SuffixArray::SA(N,s.c_str(),sa,256);
	segtree seg(N+1);
	rep(i,N+1){
		seg.add(sa[i],i);
	}
	rep(tt,Q){
		int l,r;
		string t;
		cin>>l>>r>>t;
		r++;
		int K=t.size();
		if(r-l<K){
			puts("0");
			continue;
		}
		int ya=lo(sa,s,t);
		int yb=hi(sa,s,t);
		if(ya>=yb){
			puts("0");
			continue;
		}
		cout<<seg.count(l,r-K+1,ya,yb)<<endl;
	}
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

