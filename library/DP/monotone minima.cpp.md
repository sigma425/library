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


# :warning: DP/monotone minima.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e2fca8135c2fadca093abd79a6b1c0d2">DP</a>
* <a href="{{ site.github.repository_url }}/blob/master/DP/monotone minima.cpp">View this file on GitHub</a>
    - Last commit date: 2018-07-11 09:30:23+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*


monotone minima
H*W の配列aがあって, a[0] の最小を取る場所 <= a[1] の最小を取る場所 <= a[2] の最小を取る場所 ...
となっている時に、これらの場所をすべて求める

O(W log H)

ex.
H = 3, W = 5
3 2 4 3 5
3 4 1 2 2
1 1 0 1 0

Monge->totally monotone なので、

logつけるだけで一般化出来るからこっちが主流かなあ(mongeわかりにくいし)

重要な例:

dp[k][x]: k回切って今場所x

rep(k,K){
	rep(x,N+1){
		rep(y,x) chmin(dp[k+1][x],dp[k][y] + cost(y,x));
	}
}

っていうのがある時に、k,xでの最適yをA[k][x] とおいた時に A[k][x] <= A[k][x+1] が成り立つなら、これが適用できる
(kがないと、xを順番に計算せざるを得ないので無理?)

rep(k,K){
	minima(0,N+1,0,N+1); (内側でdp[k-1]を使う)
}

verified by CF/868/F.cpp

*/

using D = ll;
void minima(int lx,int rx,int ly,int ry){	//[lx,rx) について bestpos[x] を求める 調べる範囲は[ly,ry)でよい
	if(lx >= rx) return;
	int x = (lx+rx)/2;
	D best = ?;
	int besty = -1;
	for(int y = ly; y<ry; y++){
		D val = f(x,y)
//		D val = dp[k-1][y] + cost(y,m);
		if(best ? val){
			best = val;
			besty = y;
		}
	}

//	opt[x] = y
	
	minima(k,lx,m,ly,besty+1);
	minima(k,m+1,rx,besty,ry);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DP/monotone minima.cpp"
/*


monotone minima
H*W の配列aがあって, a[0] の最小を取る場所 <= a[1] の最小を取る場所 <= a[2] の最小を取る場所 ...
となっている時に、これらの場所をすべて求める

O(W log H)

ex.
H = 3, W = 5
3 2 4 3 5
3 4 1 2 2
1 1 0 1 0

Monge->totally monotone なので、

logつけるだけで一般化出来るからこっちが主流かなあ(mongeわかりにくいし)

重要な例:

dp[k][x]: k回切って今場所x

rep(k,K){
	rep(x,N+1){
		rep(y,x) chmin(dp[k+1][x],dp[k][y] + cost(y,x));
	}
}

っていうのがある時に、k,xでの最適yをA[k][x] とおいた時に A[k][x] <= A[k][x+1] が成り立つなら、これが適用できる
(kがないと、xを順番に計算せざるを得ないので無理?)

rep(k,K){
	minima(0,N+1,0,N+1); (内側でdp[k-1]を使う)
}

verified by CF/868/F.cpp

*/

using D = ll;
void minima(int lx,int rx,int ly,int ry){	//[lx,rx) について bestpos[x] を求める 調べる範囲は[ly,ry)でよい
	if(lx >= rx) return;
	int x = (lx+rx)/2;
	D best = ?;
	int besty = -1;
	for(int y = ly; y<ry; y++){
		D val = f(x,y)
//		D val = dp[k-1][y] + cost(y,m);
		if(best ? val){
			best = val;
			besty = y;
		}
	}

//	opt[x] = y
	
	minima(k,lx,m,ly,besty+1);
	minima(k,m+1,rx,besty,ry);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

