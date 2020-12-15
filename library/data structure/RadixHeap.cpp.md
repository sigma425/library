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


# :warning: data structure/RadixHeap.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#37305dfb5e3ae8ec66b10a691aedead8">data structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/RadixHeap.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	RadixHeap
	Heapなんだけど条件として、
	 - 非負整数を入れる
	 - 最後に取り出した値より小さい値を入れられない!
	というのがある.
	後者は変な制約だが、例えばdijkstraはこの制約を満たす.
	入れる整数の大きさをDとすると操作はならしO(log D). 定数倍がクソ軽いらしい.
	このならしにはtopとかも含まれてるので、変な順だと遅いとかもない.
	この実装では中身をpair<uint,T> にしていて(uintがコスト,Tが状態),
	なのでdijkstraの
	priority_queue< pair<int,T> ,vector,greater > のかわりに
	
	RadixHeap<T> とすればよい.あとは全てそのまま.
	この実装だとコストとしてUINT_MAXまでは許される.

	下にULONGLONG版を作りました
	verified by http://nyc2015.contest.atcoder.jp/submissions/1089478
	(ちゃんとuint版では落ちてるのも確認済み)
*/

typedef unsigned int uint;
int bsr(uint x){
	if(x==0) return -1;
	return 31-__builtin_clz(x);
}
template<class T>
struct RadixHeap{
	typedef pair<uint,T> P;
	vector<P> v[33];
	uint last,sz;
	RadixHeap():last(0),sz(0){}
	void push(uint x,T t){
		assert(last<=x);
		sz++;
		v[bsr(x^last)+1].pb(P(x,t));
	}
	void push(P p){
		push(p.fs,p.sc);
	}
	P top(){
		return pop(false);
	}
	P pop(bool f = true){
		assert(sz);
		if(v[0].empty()){
			int i=1;
			while(v[i].empty()) i++;
			last = min_element(all(v[i]))->fs;
			for(P p:v[i]){
				v[bsr(p.fs^last)+1].pb(p);
			}
			v[i].clear();
		}
		P r=v[0].back();
		if(f){
			sz--;
			v[0].pop_back();
		}
		return r;
	}
	int size(){
		return sz;
	}
	bool empty(){
		return sz==0;
	}
	void clear(){
		last=sz=0;
		rep(i,33) v[i].clear();
	}
};


//ULONGLONG

typedef unsigned long long ull;
int bsr(ull x){
	if(x==0) return -1;
	return 63-__builtin_clzll(x);
}
template<class T>
struct RadixHeap{
	typedef pair<ull,T> P;
	vector<P> v[65];
	ull last,sz;
	RadixHeap():last(0),sz(0){}
	void push(ull x,T t){
		assert(last<=x);
		sz++;
		v[bsr(x^last)+1].pb(P(x,t));
	}
	void push(P p){
		push(p.fs,p.sc);
	}
	P top(){
		return pop(false);
	}
	P pop(bool f = true){
		assert(sz);
		if(v[0].empty()){
			int i=1;
			while(v[i].empty()) i++;
			last = min_element(all(v[i]))->fs;
			for(P p:v[i]){
				v[bsr(p.fs^last)+1].pb(p);
			}
			v[i].clear();
		}
		P r=v[0].back();
		if(f){
			sz--;
			v[0].pop_back();
		}
		return r;
	}
	int size(){
		return sz;
	}
	bool empty(){
		return sz==0;
	}
	void clear(){
		last=sz=0;
		rep(i,65) v[i].clear();
	}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/RadixHeap.cpp"
/*
	RadixHeap
	Heapなんだけど条件として、
	 - 非負整数を入れる
	 - 最後に取り出した値より小さい値を入れられない!
	というのがある.
	後者は変な制約だが、例えばdijkstraはこの制約を満たす.
	入れる整数の大きさをDとすると操作はならしO(log D). 定数倍がクソ軽いらしい.
	このならしにはtopとかも含まれてるので、変な順だと遅いとかもない.
	この実装では中身をpair<uint,T> にしていて(uintがコスト,Tが状態),
	なのでdijkstraの
	priority_queue< pair<int,T> ,vector,greater > のかわりに
	
	RadixHeap<T> とすればよい.あとは全てそのまま.
	この実装だとコストとしてUINT_MAXまでは許される.

	下にULONGLONG版を作りました
	verified by http://nyc2015.contest.atcoder.jp/submissions/1089478
	(ちゃんとuint版では落ちてるのも確認済み)
*/

typedef unsigned int uint;
int bsr(uint x){
	if(x==0) return -1;
	return 31-__builtin_clz(x);
}
template<class T>
struct RadixHeap{
	typedef pair<uint,T> P;
	vector<P> v[33];
	uint last,sz;
	RadixHeap():last(0),sz(0){}
	void push(uint x,T t){
		assert(last<=x);
		sz++;
		v[bsr(x^last)+1].pb(P(x,t));
	}
	void push(P p){
		push(p.fs,p.sc);
	}
	P top(){
		return pop(false);
	}
	P pop(bool f = true){
		assert(sz);
		if(v[0].empty()){
			int i=1;
			while(v[i].empty()) i++;
			last = min_element(all(v[i]))->fs;
			for(P p:v[i]){
				v[bsr(p.fs^last)+1].pb(p);
			}
			v[i].clear();
		}
		P r=v[0].back();
		if(f){
			sz--;
			v[0].pop_back();
		}
		return r;
	}
	int size(){
		return sz;
	}
	bool empty(){
		return sz==0;
	}
	void clear(){
		last=sz=0;
		rep(i,33) v[i].clear();
	}
};


//ULONGLONG

typedef unsigned long long ull;
int bsr(ull x){
	if(x==0) return -1;
	return 63-__builtin_clzll(x);
}
template<class T>
struct RadixHeap{
	typedef pair<ull,T> P;
	vector<P> v[65];
	ull last,sz;
	RadixHeap():last(0),sz(0){}
	void push(ull x,T t){
		assert(last<=x);
		sz++;
		v[bsr(x^last)+1].pb(P(x,t));
	}
	void push(P p){
		push(p.fs,p.sc);
	}
	P top(){
		return pop(false);
	}
	P pop(bool f = true){
		assert(sz);
		if(v[0].empty()){
			int i=1;
			while(v[i].empty()) i++;
			last = min_element(all(v[i]))->fs;
			for(P p:v[i]){
				v[bsr(p.fs^last)+1].pb(p);
			}
			v[i].clear();
		}
		P r=v[0].back();
		if(f){
			sz--;
			v[0].pop_back();
		}
		return r;
	}
	int size(){
		return sz;
	}
	bool empty(){
		return sz==0;
	}
	void clear(){
		last=sz=0;
		rep(i,65) v[i].clear();
	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

