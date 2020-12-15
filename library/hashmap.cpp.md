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
<script type="text/javascript" src="../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../assets/css/copy-button.css" />


# :warning: hashmap.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/hashmap.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-14 11:30:19+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	https://codeforces.com/blog/entry/62393
*/
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
 
template<class t,class u>
using hashmap = gp_hash_table<t,u,custom_hash>;


/*
    https://codeforces.com/gym/102361/submission/61948583
	高速だけど、mod S でわけるかなりメチャクチャなハッシュなのでどうしてもってとき以外は使わない
	S は 最大mapsize より大きく設定
*/
struct HashMap{
	const int S = ;
    int N=0,fst[S];
	ll va[S]; int nxt[S],vb[S];
	void clear(){
		memset(fst,0,sizeof fst); N=0;
	}
	void add(ll x){
		int c=x%S; if(c<0) c=-c;
		for(int e=fst[c];e;e=nxt[e])
			if(va[e]==x) {++vb[e]; return;}
		++N; va[N]=x; vb[N]=1;
		nxt[N]=fst[c]; fst[c]=N;
	}
	int operator [] (ll x){
		int c=x%S; if(c<0) c=-c;
		for(int e=fst[c];e;e=nxt[e])
			if(va[e]==x) return vb[e];
		return 0;
	}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "hashmap.cpp"
/*
	https://codeforces.com/blog/entry/62393
*/
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
 
template<class t,class u>
using hashmap = gp_hash_table<t,u,custom_hash>;


/*
    https://codeforces.com/gym/102361/submission/61948583
	高速だけど、mod S でわけるかなりメチャクチャなハッシュなのでどうしてもってとき以外は使わない
	S は 最大mapsize より大きく設定
*/
struct HashMap{
	const int S = ;
    int N=0,fst[S];
	ll va[S]; int nxt[S],vb[S];
	void clear(){
		memset(fst,0,sizeof fst); N=0;
	}
	void add(ll x){
		int c=x%S; if(c<0) c=-c;
		for(int e=fst[c];e;e=nxt[e])
			if(va[e]==x) {++vb[e]; return;}
		++N; va[N]=x; vb[N]=1;
		nxt[N]=fst[c]; fst[c]=N;
	}
	int operator [] (ll x){
		int c=x%S; if(c<0) c=-c;
		for(int e=fst[c];e;e=nxt[e])
			if(va[e]==x) return vb[e];
		return 0;
	}
};

```
{% endraw %}

<a href="../index.html">Back to top page</a>

