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


# :warning: string/kmp.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/kmp.cpp">View this file on GitHub</a>
    - Last commit date: 2018-09-18 03:14:42+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	kmp[i] = 長さ i の prefix の longest border
	s : aabaabaaa
	k : _010123452

	はじめての文字の比較 			i -> A[i] (前ループのjなので、今のiからみるとA[i])
	文字が一致した場所(終了した箇所)	i -> A[i+1]-1 (まあみればわかる)
	片方から片方は簡単に導ける.両方とも根付き木でかなり性質が良い.
	計算量解析は、黒辺を下る回数が、とか思ったけど+1があるので普通にA[i]の値の遷移を考えたほうがいいか.

	border列挙

	vector<int> res;
	int X = kmp[N];
	while(X>0){
		res.pb(X);
		X = A[X];
	}
	return res;
*/


vector<int> getKMP(string s){
	int N = s.size();
	vector<int> A(N+1);
	A[0] = -1;
	int j = -1;
	rep(i,N){
		while(j>=0 && s[i]!=s[j]) j = A[j];
		j++;
		A[i+1] = j;
	}
	return A;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/kmp.cpp"
/*
	kmp[i] = 長さ i の prefix の longest border
	s : aabaabaaa
	k : _010123452

	はじめての文字の比較 			i -> A[i] (前ループのjなので、今のiからみるとA[i])
	文字が一致した場所(終了した箇所)	i -> A[i+1]-1 (まあみればわかる)
	片方から片方は簡単に導ける.両方とも根付き木でかなり性質が良い.
	計算量解析は、黒辺を下る回数が、とか思ったけど+1があるので普通にA[i]の値の遷移を考えたほうがいいか.

	border列挙

	vector<int> res;
	int X = kmp[N];
	while(X>0){
		res.pb(X);
		X = A[X];
	}
	return res;
*/


vector<int> getKMP(string s){
	int N = s.size();
	vector<int> A(N+1);
	A[0] = -1;
	int j = -1;
	rep(i,N){
		while(j>=0 && s[i]!=s[j]) j = A[j];
		j++;
		A[i+1] = j;
	}
	return A;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

