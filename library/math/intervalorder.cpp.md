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


# :warning: math/intervalorder.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/intervalorder.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
長さが正の区間がM個与えられたときに、端点の順序(=もありうる)を全列挙する
区間iの左端がi,右端がi+M
各VIが同じ座標を表している

ordsの大きさは 1, 13, 409, 23917, 2244361, 308682013
M=5までしか使えない

SRM710

各区間グラフが何個あるかが求めたいなら、左端を忘れて右端の順をキーに持ってDP
*/
bool B(int x,int i){return (x>>i)&1;}

typedef vector<int> VI;
typedef vector<VI> VV;

int M;
vector<VV> ords;
int cnt;

void dfs(int usel, int user, VV& ord){
//	show(usel);
//	show(user);
	if(usel==(1<<M)-1 && user==(1<<M)-1){
//		ords.pb(ord);
		cnt++;
		return;
	}
	int prev=-1;
	if(!ord.back().empty()) prev = ord.back().back();
	rep(i,M){
		if(!B(usel,i)){
			if(prev>=i) continue;
			ord.back().pb(i);
			dfs(usel|(1<<i),user,ord);
			ord.back().pop_back();
		}else if(!B(user,i)){
			if(prev>=i+M) continue;
			bool len0=0;
			for(int x:ord.back()) if(x==i) len0=1;
			if(len0) continue;
			ord.back().pb(i+M);
			dfs(usel,user|(1<<i),ord);
			ord.back().pop_back();
		}else{
			;
		}
	}
	if(!ord.back().empty()){
		ord.pb({});
		dfs(usel,user,ord);
		ord.pop_back();
	}
}

void enumorder(int M){
	::M = M;
	VV st(1,VI());
	dfs(0,0,st);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/intervalorder.cpp"
/*
長さが正の区間がM個与えられたときに、端点の順序(=もありうる)を全列挙する
区間iの左端がi,右端がi+M
各VIが同じ座標を表している

ordsの大きさは 1, 13, 409, 23917, 2244361, 308682013
M=5までしか使えない

SRM710

各区間グラフが何個あるかが求めたいなら、左端を忘れて右端の順をキーに持ってDP
*/
bool B(int x,int i){return (x>>i)&1;}

typedef vector<int> VI;
typedef vector<VI> VV;

int M;
vector<VV> ords;
int cnt;

void dfs(int usel, int user, VV& ord){
//	show(usel);
//	show(user);
	if(usel==(1<<M)-1 && user==(1<<M)-1){
//		ords.pb(ord);
		cnt++;
		return;
	}
	int prev=-1;
	if(!ord.back().empty()) prev = ord.back().back();
	rep(i,M){
		if(!B(usel,i)){
			if(prev>=i) continue;
			ord.back().pb(i);
			dfs(usel|(1<<i),user,ord);
			ord.back().pop_back();
		}else if(!B(user,i)){
			if(prev>=i+M) continue;
			bool len0=0;
			for(int x:ord.back()) if(x==i) len0=1;
			if(len0) continue;
			ord.back().pb(i+M);
			dfs(usel,user|(1<<i),ord);
			ord.back().pop_back();
		}else{
			;
		}
	}
	if(!ord.back().empty()){
		ord.pb({});
		dfs(usel,user,ord);
		ord.pop_back();
	}
}

void enumorder(int M){
	::M = M;
	VV st(1,VI());
	dfs(0,0,st);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

