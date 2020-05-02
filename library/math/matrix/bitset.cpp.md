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


# :warning: math/matrix/bitset.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a9839e7477a4d9c748aee996b52a14d5">math/matrix</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/matrix/bitset.cpp">View this file on GitHub</a>
    - Last commit date: 2018-09-18 03:14:42+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	x[a][b]= (can go from a to b ?) のかけざん
	bitsetはやい
	ちょうどN取るのは無理なので注意(テンプレート引数なのでconstじゃないとダメ)
	あとswapが出来ない(12行目のとこ)
*/
const int MAX_N=;
typedef bitset<MAX_N> Bs;
typedef array<Bs,MAX_N> mat;
mat pro(mat x,mat y,int N){
	rep(i,N) rep(j,i){
		bool tmp=y[i][j];
		y[i][j]=y[j][i];
		y[j][i]=tmp;
	}
	mat z;
	rep(i,N) rep(j,N) z[i][j]=(x[i]&y[j]).any();
	return z;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/matrix/bitset.cpp"
/*
	x[a][b]= (can go from a to b ?) のかけざん
	bitsetはやい
	ちょうどN取るのは無理なので注意(テンプレート引数なのでconstじゃないとダメ)
	あとswapが出来ない(12行目のとこ)
*/
const int MAX_N=;
typedef bitset<MAX_N> Bs;
typedef array<Bs,MAX_N> mat;
mat pro(mat x,mat y,int N){
	rep(i,N) rep(j,i){
		bool tmp=y[i][j];
		y[i][j]=y[j][i];
		y[j][i]=tmp;
	}
	mat z;
	rep(i,N) rep(j,N) z[i][j]=(x[i]&y[j]).any();
	return z;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

