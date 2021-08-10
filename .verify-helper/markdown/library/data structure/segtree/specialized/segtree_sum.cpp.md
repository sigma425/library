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


# :warning: data structure/segtree/specialized/segtree_sum.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#2d26a1b1de5ccf32c90554b209fe486c">data structure/segtree/specialized</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/segtree/specialized/segtree_sum.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	point assign
	range sum
	int/long long/double
*/
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
#define chmax(x,y) x=max(x,y)
using namespace std;

struct segtree{
	using D = long long;

	int N;
	vector<D> val;

	segtree(){}
	segtree(int n){
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,0);
	}
	segtree(const vector<D>& ds){
		int n = ds.size();
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,0);
		rep(i,n) val[i+N] = ds[i];
		for(int i=N-1;i>0;i--) val[i] = val[i*2] + val[i*2+1];
	}
	void assign(int k,D d){
		k+=N;
		val[k]=d;
		k/=2;
		while(k){
			val[k] = val[k*2] + val[k*2+1];
			k/=2;
		}
	}
	D sum(int a,int b){		//non-commutative & unrecursive
		D res = 0;
		a+=N,b+=N;
		while(a<b){
			if(a&1) res += val[a++];
			if(b&1) res += val[--b];
			a/=2,b/=2;
		}
		return res;
	}
};

int main(){
	vector<long long> vc = {1,2,3,4};
	segtree seg(vc);
	assert(seg.sum(2,4) == 7);
	seg.assign(0,-100);
	assert(seg.sum(0,3) == -95);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/segtree/specialized/segtree_sum.cpp"
/*
	point assign
	range sum
	int/long long/double
*/
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
#define chmax(x,y) x=max(x,y)
using namespace std;

struct segtree{
	using D = long long;

	int N;
	vector<D> val;

	segtree(){}
	segtree(int n){
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,0);
	}
	segtree(const vector<D>& ds){
		int n = ds.size();
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,0);
		rep(i,n) val[i+N] = ds[i];
		for(int i=N-1;i>0;i--) val[i] = val[i*2] + val[i*2+1];
	}
	void assign(int k,D d){
		k+=N;
		val[k]=d;
		k/=2;
		while(k){
			val[k] = val[k*2] + val[k*2+1];
			k/=2;
		}
	}
	D sum(int a,int b){		//non-commutative & unrecursive
		D res = 0;
		a+=N,b+=N;
		while(a<b){
			if(a&1) res += val[a++];
			if(b&1) res += val[--b];
			a/=2,b/=2;
		}
		return res;
	}
};

int main(){
	vector<long long> vc = {1,2,3,4};
	segtree seg(vc);
	assert(seg.sum(2,4) == 7);
	seg.assign(0,-100);
	assert(seg.sum(0,3) == -95);
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
