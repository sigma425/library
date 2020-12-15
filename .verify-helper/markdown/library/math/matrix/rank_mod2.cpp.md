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


# :warning: math/matrix/rank_mod2.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a9839e7477a4d9c748aee996b52a14d5">math/matrix</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/matrix/rank_mod2.cpp">View this file on GitHub</a>
    - Last commit date: 2019-09-30 14:20:31+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*Ax = b mod 2の解が何個あるかN変数で式がM個,つまり A:M*N, x:N, b:Mres = -1 -> 0個otherwise -> 2^(N-r)個ただrankを求めたい時(bがないとき) は bに関する部分を消せば良い.O(NM min(N,M) / 32)	(jのループがmin(N,M)回)verified: http://codeforces.com/contest/662/problem/C*/const int MN = ;typedef bitset<MN> Bs;typedef vector<Bs> mat;int getrank(mat A, vector<bool> b,int N){	assert(A.size() == b.size());	int M = b.size();	int res=0;	vector<bool> used(M,false);	rep(j,N){		int i = 0;		while( (i < M) && (used[i] || !A[i][j]) ) i++;		if(i == M) continue;		res++;		used[i] = 1;		rep(k,M) if(!used[k]&&A[k][j]){			A[k]^=A[i];			b[k]=b[k]^b[i];		}	}	rep(i,M) if(!used[i] && b[i] ) return -1;	return res;}typedef long long ll;bool B(ll x,int i){return (x>>i)&1;}int main(){	int N;	scanf("%d",&N);	ll o = 0;	vector<ll> vs;	rep(i,N){		ll x,y;		scanf("%lld%lld",&x,&y);		o ^= x;		vs.pb(x^y);	}	mat A(60);	rep(i,N){		rep(j,60){			A[j][i] = B(vs[i],j);		}	}	vector<bool> b(60);	rep(j,60) b[j] = B(o,j);	int r = getrank(A,b,N);	if(r == -1){		puts("1/1");		return 0;	}	cout << (1LL<<r)-1 << "/" << (1LL<<r) <<endl;}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/matrix/rank_mod2.cpp"
/*Ax = b mod 2の解が何個あるかN変数で式がM個,つまり A:M*N, x:N, b:Mres = -1 -> 0個otherwise -> 2^(N-r)個ただrankを求めたい時(bがないとき) は bに関する部分を消せば良い.O(NM min(N,M) / 32)	(jのループがmin(N,M)回)verified: http://codeforces.com/contest/662/problem/C*/const int MN = ;typedef bitset<MN> Bs;typedef vector<Bs> mat;int getrank(mat A, vector<bool> b,int N){	assert(A.size() == b.size());	int M = b.size();	int res=0;	vector<bool> used(M,false);	rep(j,N){		int i = 0;		while( (i < M) && (used[i] || !A[i][j]) ) i++;		if(i == M) continue;		res++;		used[i] = 1;		rep(k,M) if(!used[k]&&A[k][j]){			A[k]^=A[i];			b[k]=b[k]^b[i];		}	}	rep(i,M) if(!used[i] && b[i] ) return -1;	return res;}typedef long long ll;bool B(ll x,int i){return (x>>i)&1;}int main(){	int N;	scanf("%d",&N);	ll o = 0;	vector<ll> vs;	rep(i,N){		ll x,y;		scanf("%lld%lld",&x,&y);		o ^= x;		vs.pb(x^y);	}	mat A(60);	rep(i,N){		rep(j,60){			A[j][i] = B(vs[i],j);		}	}	vector<bool> b(60);	rep(j,60) b[j] = B(o,j);	int r = getrank(A,b,N);	if(r == -1){		puts("1/1");		return 0;	}	cout << (1LL<<r)-1 << "/" << (1LL<<r) <<endl;}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

