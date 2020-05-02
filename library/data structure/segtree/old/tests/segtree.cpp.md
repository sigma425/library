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
<script type="text/javascript" src="../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../assets/css/copy-button.css" />


# :warning: data structure/segtree/old/tests/segtree.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#1640c839eda6cc5d1d5d19f7d1867e25">data structure/segtree/old/tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/segtree/old/tests/segtree.cpp">View this file on GitHub</a>
    - Last commit date: 2017-04-22 20:47:35+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	point assign, range なんらか(operator +)
*/
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
using namespace std;
/*
	point assign,range ほげ
	書くものは
	D op()	(演算)
	D e		(単位元)
*/
typedef pair<int,int> D;
struct segtree{
	static const int N=1<<16;
	D seg[N*2],e=;
	segtree(vector<D>& vc){
		rep(i,N) seg[i+N]=e;
		rep(i,vc.size()) seg[i+N]=vc[i];
		for(int i=N-1;i>0;i--) seg[i]=op(seg[i*2],seg[i*2+1]);
	}
	D op(const D& x,const D& y){

	}
	void update(int k,D val){
		k+=N;
		seg[k]=val;
		k/=2;
		while(k){
			seg[k]=op(seg[k*2],seg[k*2+1]);
			k/=2;
		}
	}
	P calc(int a,int b,int l=0,int r=N,int k=1){
		if(b<=l||r<=a) return e;
		if(a<=l&&r<=b) return seg[k];
		return op(calc(a,b,l,(l+r)/2,k*2),calc(a,b,(l+r)/2,r,k*2+1));
	}
};
int main(){
	
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/segtree/old/tests/segtree.cpp"
/*
	point assign, range なんらか(operator +)
*/
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
using namespace std;
/*
	point assign,range ほげ
	書くものは
	D op()	(演算)
	D e		(単位元)
*/
typedef pair<int,int> D;
struct segtree{
	static const int N=1<<16;
	D seg[N*2],e=;
	segtree(vector<D>& vc){
		rep(i,N) seg[i+N]=e;
		rep(i,vc.size()) seg[i+N]=vc[i];
		for(int i=N-1;i>0;i--) seg[i]=op(seg[i*2],seg[i*2+1]);
	}
	D op(const D& x,const D& y){

	}
	void update(int k,D val){
		k+=N;
		seg[k]=val;
		k/=2;
		while(k){
			seg[k]=op(seg[k*2],seg[k*2+1]);
			k/=2;
		}
	}
	P calc(int a,int b,int l=0,int r=N,int k=1){
		if(b<=l||r<=a) return e;
		if(a<=l&&r<=b) return seg[k];
		return op(calc(a,b,l,(l+r)/2,k*2),calc(a,b,(l+r)/2,r,k*2+1));
	}
};
int main(){
	
}

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

