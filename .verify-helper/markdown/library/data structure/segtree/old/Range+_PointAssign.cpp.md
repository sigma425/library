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


# :warning: data structure/segtree/old/Range+_PointAssign.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#fd751f78534902643f339bc0ff029c45">data structure/segtree/old</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/segtree/old/Range+_PointAssign.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	point assign,range +
	semigroup D でのsegtree

	変えるべきところは,
	- Dのメンバ変数
	- Dのコンストラクタ
	- operator+
	- structの外のD::eのinitialize
	- (あとお好みでoperator<<)

	外から使うのは
	- update(0-indexed)
	- calc(0-indexed 半開区間)
	- あとinit

	20161209
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
	int N;

	T e=T::e;
	vector<T> seg;
	segtree(){}
	segtree(int n){
		init(n);
	}
	segtree(vector<T>& vc){
		init(vc);
	}
	void init(int n){
		N=1;
		while(N<n) N*=2;
		seg.assign(N*2,e);
	}
	void init(vector<T>& vc){
		N=1;
		int n=vc.size();
		while(N<n) N*=2;
		seg.assign(N*2,e);
		rep(i,vc.size()) seg[i+N]=vc[i];
		for(int i=N-1;i>0;i--) seg[i]=seg[i*2]+seg[i*2+1];
	}
	void update(int x,T val){
		x+=N;
		seg[x]=val;
		x/=2;
		while(x){
			seg[x]=seg[x*2]+seg[x*2+1];
			x/=2;
		}
	}
	T calc(int a,int b,int l=0,int r=-1,int k=1){
		if(r==-1) r=N;
		if(b<=l||r<=a) return e;
		if(a<=l&&r<=b) return seg[k];
		return calc(a,b,l,(l+r)/2,k*2)+calc(a,b,(l+r)/2,r,k*2+1);
	}
};
segtree<D> seg;
int main(){
	int N;
	cin>>N;
	vector<D> vc;
	rep(i,N){
		int x;
		cin>>x;
		vc.push_back(D(x));
	}
	seg=segtree<D>(vc);
	while(true){
		int l,r;
		cin>>l>>r;
		r++;
		cout<<"ans="<<seg.calc(l,r)<<endl;
	}
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/segtree/old/Range+_PointAssign.cpp"
/*
	point assign,range +
	semigroup D でのsegtree

	変えるべきところは,
	- Dのメンバ変数
	- Dのコンストラクタ
	- operator+
	- structの外のD::eのinitialize
	- (あとお好みでoperator<<)

	外から使うのは
	- update(0-indexed)
	- calc(0-indexed 半開区間)
	- あとinit

	20161209
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
	int N;

	T e=T::e;
	vector<T> seg;
	segtree(){}
	segtree(int n){
		init(n);
	}
	segtree(vector<T>& vc){
		init(vc);
	}
	void init(int n){
		N=1;
		while(N<n) N*=2;
		seg.assign(N*2,e);
	}
	void init(vector<T>& vc){
		N=1;
		int n=vc.size();
		while(N<n) N*=2;
		seg.assign(N*2,e);
		rep(i,vc.size()) seg[i+N]=vc[i];
		for(int i=N-1;i>0;i--) seg[i]=seg[i*2]+seg[i*2+1];
	}
	void update(int x,T val){
		x+=N;
		seg[x]=val;
		x/=2;
		while(x){
			seg[x]=seg[x*2]+seg[x*2+1];
			x/=2;
		}
	}
	T calc(int a,int b,int l=0,int r=-1,int k=1){
		if(r==-1) r=N;
		if(b<=l||r<=a) return e;
		if(a<=l&&r<=b) return seg[k];
		return calc(a,b,l,(l+r)/2,k*2)+calc(a,b,(l+r)/2,r,k*2+1);
	}
};
segtree<D> seg;
int main(){
	int N;
	cin>>N;
	vector<D> vc;
	rep(i,N){
		int x;
		cin>>x;
		vc.push_back(D(x));
	}
	seg=segtree<D>(vc);
	while(true){
		int l,r;
		cin>>l>>r;
		r++;
		cout<<"ans="<<seg.calc(l,r)<<endl;
	}
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

