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


# :warning: interpolation.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/interpolation.cpp">View this file on GitHub</a>
    - Last commit date: 2019-02-01 17:29:47+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	多項式補間
	Lagrange interpolation
	O(N^2)
	N点(xs[i],ys[i])が与えられた時にそれを通るN-1次多項式のxでの値を返す
	xs[i]がpairwise distinctじゃないとダメ
	あとxs[i]==xになるときにちゃんと処理する必要がある doubleとかで誤差でxs[i]==x+epsみたいなのに注意

	Z/pZとかにするなら割り算とかをちゃんと書き換えること


	多項式自体を求めたいときは(x-xs[j])の部分が多項式の掛け算なので、全体でO(N^3)になる,
	戻すDPっぽいのをやるとO(N^2)だが面倒そう
	Newton補間使ったほうが良くない?

	OpenCup/1101/I.cpp がmint,poly,interpolationを複合して使ってる例

*/

template<class T>
T interpolate(vector<T> xs,vector<T> ys,T x){
	int N=xs.size();
	rep(i,N){
		if(xs[i]==x) return ys[i];
	}
	T ret=0;
	rep(i,N){
		T a=ys[i];
		rep(j,N) if(j!=i) a*=(x-xs[j])/(xs[i]-xs[j]);
		ret+=a;
	}
	return ret;
}

/*
	多項式自体を求める O(N^3 log N)
	O(N^2 log N) とかにしたいなら(x - x[i]) の左右からの累積積を計算しておく 面倒だから書いてないけど
*/
Poly<mint> interpolate(V<mint> x, V<mint> y){
	assert(x.size() == y.size())
	int N = x.size();
	Poly<mint> f;
	rep(i,N){
		Poly<mint> g({y[i]});
		mint coef = 1;
		rep(j,N) if(j!=i){
			g *= Poly<mint>({-x[j],1});
			coef *= (x[i]-x[j]);
		}
		g *= coef.inv();
		f += g;
	}
	return f;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "interpolation.cpp"
/*
	多項式補間
	Lagrange interpolation
	O(N^2)
	N点(xs[i],ys[i])が与えられた時にそれを通るN-1次多項式のxでの値を返す
	xs[i]がpairwise distinctじゃないとダメ
	あとxs[i]==xになるときにちゃんと処理する必要がある doubleとかで誤差でxs[i]==x+epsみたいなのに注意

	Z/pZとかにするなら割り算とかをちゃんと書き換えること


	多項式自体を求めたいときは(x-xs[j])の部分が多項式の掛け算なので、全体でO(N^3)になる,
	戻すDPっぽいのをやるとO(N^2)だが面倒そう
	Newton補間使ったほうが良くない?

	OpenCup/1101/I.cpp がmint,poly,interpolationを複合して使ってる例

*/

template<class T>
T interpolate(vector<T> xs,vector<T> ys,T x){
	int N=xs.size();
	rep(i,N){
		if(xs[i]==x) return ys[i];
	}
	T ret=0;
	rep(i,N){
		T a=ys[i];
		rep(j,N) if(j!=i) a*=(x-xs[j])/(xs[i]-xs[j]);
		ret+=a;
	}
	return ret;
}

/*
	多項式自体を求める O(N^3 log N)
	O(N^2 log N) とかにしたいなら(x - x[i]) の左右からの累積積を計算しておく 面倒だから書いてないけど
*/
Poly<mint> interpolate(V<mint> x, V<mint> y){
	assert(x.size() == y.size())
	int N = x.size();
	Poly<mint> f;
	rep(i,N){
		Poly<mint> g({y[i]});
		mint coef = 1;
		rep(j,N) if(j!=i){
			g *= Poly<mint>({-x[j],1});
			coef *= (x[i]-x[j]);
		}
		g *= coef.inv();
		f += g;
	}
	return f;
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

