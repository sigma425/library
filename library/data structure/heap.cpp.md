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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: data structure/heap.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#37305dfb5e3ae8ec66b10a691aedead8">data structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/heap.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




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
const int MAX_N=10000000;
struct heap{
	int pool[MAX_N];
	int sz;
	heap(){sz=0;}
	void insert(int x){
		int v=sz++;
		pool[v]=x;
		while(v){
			int p=(v-1)/2;
			if(pool[p]<=pool[v]) break;
			swap(pool[p],pool[v]);
			v=p;
		}
	}
	int deletemin(){
		assert(sz);
		sz--;
		int ret=pool[0];
		pool[0]=pool[sz];
		int v=0;
		while(true){
			int l=v*2+1,r=v*2+2;
			if(sz<=l) break;
			int mn=l;
			if(r<sz&&pool[l]>pool[r]) mn=r;
			if(pool[mn]>pool[v]) break;
			swap(pool[mn],pool[v]);
			v=mn;
		}
		return ret;
	}
} h;
int main(){
	srand((unsigned)time(NULL));
	int Ns[4]={1000000,2000000,4000000,8000000};
	rep(tt,4){
		int N=Ns[tt];
		clock_t start=clock();
		rep(i,N){
			int x=rand()%1000000000;
			h.insert(x);
		}
	//	rep(i,h.sz) cout<<h.pool[i]<<" ";
	//	puts("");
	//	rep(i,N) cout<<h.deletemin()<<" ";
		rep(i,N) h.deletemin();
		clock_t end=clock();
		printf("N=%8d    time=%.0f ms\n",N,(end-start)/(double)CLOCKS_PER_SEC*1000);
	}
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/heap.cpp"
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
const int MAX_N=10000000;
struct heap{
	int pool[MAX_N];
	int sz;
	heap(){sz=0;}
	void insert(int x){
		int v=sz++;
		pool[v]=x;
		while(v){
			int p=(v-1)/2;
			if(pool[p]<=pool[v]) break;
			swap(pool[p],pool[v]);
			v=p;
		}
	}
	int deletemin(){
		assert(sz);
		sz--;
		int ret=pool[0];
		pool[0]=pool[sz];
		int v=0;
		while(true){
			int l=v*2+1,r=v*2+2;
			if(sz<=l) break;
			int mn=l;
			if(r<sz&&pool[l]>pool[r]) mn=r;
			if(pool[mn]>pool[v]) break;
			swap(pool[mn],pool[v]);
			v=mn;
		}
		return ret;
	}
} h;
int main(){
	srand((unsigned)time(NULL));
	int Ns[4]={1000000,2000000,4000000,8000000};
	rep(tt,4){
		int N=Ns[tt];
		clock_t start=clock();
		rep(i,N){
			int x=rand()%1000000000;
			h.insert(x);
		}
	//	rep(i,h.sz) cout<<h.pool[i]<<" ";
	//	puts("");
	//	rep(i,N) cout<<h.deletemin()<<" ";
		rep(i,N) h.deletemin();
		clock_t end=clock();
		printf("N=%8d    time=%.0f ms\n",N,(end-start)/(double)CLOCKS_PER_SEC*1000);
	}
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

