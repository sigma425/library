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


# :warning: data structure/segtree/old/tests/starryskytree_test.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#1640c839eda6cc5d1d5d19f7d1867e25">data structure/segtree/old/tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/segtree/old/tests/starryskytree_test.cpp">View this file on GitHub</a>
    - Last commit date: 2017-04-22 20:47:35+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
/*
	range add,range min
	http://code-festival-2015-final-open.contest.atcoder.jp/tasks/codefestival_2015_final_d
*/
int inf=1e9;
struct starryskytree{
	static const int N=1<<17;
	int mx[N*2],ad[N*2];
	starryskytree(){
		rep(i,N*2) mx[i]=0,ad[i]=0;
	}
	void add(int a,int b,int v,int l=0,int r=N,int k=1){
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b){
			ad[k]+=v;
			return;
		}
		add(a,b,v,l,(l+r)/2,k*2);
		add(a,b,v,(l+r)/2,r,k*2+1);
		mx[k]=max(mx[k*2]+ad[k*2],mx[k*2+1]+ad[k*2+1]);
	}
	int getmax(int a,int b,int l=0,int r=N,int k=1){
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return mx[k]+ad[k];
		return ad[k]+max(getmax(a,b,l,(l+r)/2,k*2),getmax(a,b,(l+r)/2,r,k*2+1));
	}
}seg;
int a[100000],b[100000];
int main(){
	int N;
	cin>>N;
	rep(i,N){
		cin>>a[i]>>b[i];
		seg.add(a[i],b[i],1);
	}
	int ans=N-1;
	rep(i,N){
		seg.add(a[i],b[i],-1);
		int tmp=seg.getmax(0,seg.N);
		chmin(ans,tmp);
		seg.add(a[i],b[i],1);
	}
	cout<<ans<<endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/segtree/old/tests/starryskytree_test.cpp"
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
/*
	range add,range min
	http://code-festival-2015-final-open.contest.atcoder.jp/tasks/codefestival_2015_final_d
*/
int inf=1e9;
struct starryskytree{
	static const int N=1<<17;
	int mx[N*2],ad[N*2];
	starryskytree(){
		rep(i,N*2) mx[i]=0,ad[i]=0;
	}
	void add(int a,int b,int v,int l=0,int r=N,int k=1){
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b){
			ad[k]+=v;
			return;
		}
		add(a,b,v,l,(l+r)/2,k*2);
		add(a,b,v,(l+r)/2,r,k*2+1);
		mx[k]=max(mx[k*2]+ad[k*2],mx[k*2+1]+ad[k*2+1]);
	}
	int getmax(int a,int b,int l=0,int r=N,int k=1){
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return mx[k]+ad[k];
		return ad[k]+max(getmax(a,b,l,(l+r)/2,k*2),getmax(a,b,(l+r)/2,r,k*2+1));
	}
}seg;
int a[100000],b[100000];
int main(){
	int N;
	cin>>N;
	rep(i,N){
		cin>>a[i]>>b[i];
		seg.add(a[i],b[i],1);
	}
	int ans=N-1;
	rep(i,N){
		seg.add(a[i],b[i],-1);
		int tmp=seg.getmax(0,seg.N);
		chmin(ans,tmp);
		seg.add(a[i],b[i],1);
	}
	cout<<ans<<endl;
}

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

