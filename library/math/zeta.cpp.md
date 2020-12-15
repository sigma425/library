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


# :warning: math/zeta.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/zeta.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/* zeta
S:(subset of N) -> f(S) から
g(S)=sigma f(T) for all T>S を求める
g(10010) = sigma f(1**1*)
*/
void zeta(int* f,int N){
	rep(i,N) rep(j,1<<N) if(0==(j&1<<i)) f[j]+=f[j|(1<<i)];
}
/*
T<Sの和
g(10010) = sigma f(*00*0)
*/
void zeta(int *f,int N){
	rep(i,N) for(int j=(1<<N)-1;j>=0;j--) if((j>>i)&1) f[j]+=f[j^(1<<i)];
}

/*逆変換(Mebius)
gからfを求める
*/
void mebius(int *g,int N){
	rep(i,N) for(int j=(1<<N)-1;j>=0;j--) if(0==(j&1<<i)) g[j]-=g[j^(1<<i)];
}
/*T<Sバージョン*/
void mebius(int *g,int N){
	rep(i,N) rep(j,1<<N) if(j&(1<<i)) g[j]-=g[j^(1<<i)];
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/zeta.cpp"
/* zeta
S:(subset of N) -> f(S) から
g(S)=sigma f(T) for all T>S を求める
g(10010) = sigma f(1**1*)
*/
void zeta(int* f,int N){
	rep(i,N) rep(j,1<<N) if(0==(j&1<<i)) f[j]+=f[j|(1<<i)];
}
/*
T<Sの和
g(10010) = sigma f(*00*0)
*/
void zeta(int *f,int N){
	rep(i,N) for(int j=(1<<N)-1;j>=0;j--) if((j>>i)&1) f[j]+=f[j^(1<<i)];
}

/*逆変換(Mebius)
gからfを求める
*/
void mebius(int *g,int N){
	rep(i,N) for(int j=(1<<N)-1;j>=0;j--) if(0==(j&1<<i)) g[j]-=g[j^(1<<i)];
}
/*T<Sバージョン*/
void mebius(int *g,int N){
	rep(i,N) rep(j,1<<N) if(j&(1<<i)) g[j]-=g[j^(1<<i)];
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

