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


# :warning: math/hadamard.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/hadamard.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	xor convolution
	rep(i,N) rep(j,N) h[i^j] += f[i]*g[j]
	rep(i,N) rep(j,N) h[i] += f[i^j]*g[j]	<-	これ一緒だけどわかりにくい

	hadamard変換に対応している
	xorなので逆元は自分自身、なので逆変換もただのtransform, ただしdet分のNで割る.

	verified: http://codeforces.com/problemset/problem/662/C
*/

using D = ll;
void transform(vector<D> &a, int l, int n) {
	if (n == 1) return;
	int m = l + n / 2;
	transform(a, l, n / 2);
	transform(a, m, n / 2);
	for (int i = 0; i < n / 2; i++) {
		D x = a[l + i], y = a[m + i];
		a[l + i] = x + y;
		a[m + i] = x - y;
	}
}

void transform(vector<D> &a) {	//size must be power of 2
	transform(a, 0, a.size());
}
vector<D> conv(vector<D> a,vector<D> b){
	assert(a.size()==b.size());
	int N = a.size();
	transform(a);
	transform(b);
	vector<D> c(N);
	rep(i,N) c[i] = a[i]*b[i];
	transform(c);
	rep(i,N) c[i]/=N;
	return c;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/hadamard.cpp"
/*
	xor convolution
	rep(i,N) rep(j,N) h[i^j] += f[i]*g[j]
	rep(i,N) rep(j,N) h[i] += f[i^j]*g[j]	<-	これ一緒だけどわかりにくい

	hadamard変換に対応している
	xorなので逆元は自分自身、なので逆変換もただのtransform, ただしdet分のNで割る.

	verified: http://codeforces.com/problemset/problem/662/C
*/

using D = ll;
void transform(vector<D> &a, int l, int n) {
	if (n == 1) return;
	int m = l + n / 2;
	transform(a, l, n / 2);
	transform(a, m, n / 2);
	for (int i = 0; i < n / 2; i++) {
		D x = a[l + i], y = a[m + i];
		a[l + i] = x + y;
		a[m + i] = x - y;
	}
}

void transform(vector<D> &a) {	//size must be power of 2
	transform(a, 0, a.size());
}
vector<D> conv(vector<D> a,vector<D> b){
	assert(a.size()==b.size());
	int N = a.size();
	transform(a);
	transform(b);
	vector<D> c(N);
	rep(i,N) c[i] = a[i]*b[i];
	transform(c);
	rep(i,N) c[i]/=N;
	return c;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

