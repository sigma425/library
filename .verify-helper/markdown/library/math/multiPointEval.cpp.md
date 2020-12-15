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


# :warning: math/multiPointEval.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/multiPointEval.cpp">View this file on GitHub</a>
    - Last commit date: 2019-02-01 16:59:45+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
    f: N次多項式
    a_1,..,a_Q : 値 のときに、
    f(a_i) をすべて求める O( NlogN + Qlog^2(Q) )

    f % (x-a)(x-b)(x-c)(x-d) % (x-c)(x-d) % (x-c) みたいな感じで再帰するだけ

    と思いきや本質は途中から愚直に代入して計算することだった、
    d次まで減らすとそっからは全体で O(dQ) で、fft/ntt が小さい n で遅いことを考えると
    O(dQ) が TL を許す限り d を増やすのがいい気がする

    ntt で N = 10^5 のときは 1024 が最善でした (2500ms -O3)

    verified at Petrozavodsk(19w)/1/I
*/
using P = pair<int,int>;
map<pair<int,int>,Poly<mint>> qs;
Poly<mint> calcq(int l,int r,V<mint>& a){
	if(r-l==1){
		return qs[P(l,r)] = Poly<mint>(V<mint>{-a[l],1});
	}
	return qs[P(l,r)] = calcq(l,(l+r)/2,a) * calcq((l+r)/2,r,a);
}
void calc(int l,int r,Poly<mint> f, V<mint>& a, V<mint>& res){
	f %= qs[P(l,r)];
	if(r-l<=1024){
		for(int i=l;i<r;i++) res[i] = f.eval(a[i]);
		return;
	}
	calc(l,(l+r)/2,f,a,res);
	calc((l+r)/2,r,f,a,res);
}
V<mint> multiPointEval(Poly<mint>& f,V<mint> a){    //return {f(a_i)}
    int N = a.size();
	V<mint> res(N);
	calcq(0,N,a);
	calc(0,N,f,a,res);
	return res;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/multiPointEval.cpp"
/*
    f: N次多項式
    a_1,..,a_Q : 値 のときに、
    f(a_i) をすべて求める O( NlogN + Qlog^2(Q) )

    f % (x-a)(x-b)(x-c)(x-d) % (x-c)(x-d) % (x-c) みたいな感じで再帰するだけ

    と思いきや本質は途中から愚直に代入して計算することだった、
    d次まで減らすとそっからは全体で O(dQ) で、fft/ntt が小さい n で遅いことを考えると
    O(dQ) が TL を許す限り d を増やすのがいい気がする

    ntt で N = 10^5 のときは 1024 が最善でした (2500ms -O3)

    verified at Petrozavodsk(19w)/1/I
*/
using P = pair<int,int>;
map<pair<int,int>,Poly<mint>> qs;
Poly<mint> calcq(int l,int r,V<mint>& a){
	if(r-l==1){
		return qs[P(l,r)] = Poly<mint>(V<mint>{-a[l],1});
	}
	return qs[P(l,r)] = calcq(l,(l+r)/2,a) * calcq((l+r)/2,r,a);
}
void calc(int l,int r,Poly<mint> f, V<mint>& a, V<mint>& res){
	f %= qs[P(l,r)];
	if(r-l<=1024){
		for(int i=l;i<r;i++) res[i] = f.eval(a[i]);
		return;
	}
	calc(l,(l+r)/2,f,a,res);
	calc((l+r)/2,r,f,a,res);
}
V<mint> multiPointEval(Poly<mint>& f,V<mint> a){    //return {f(a_i)}
    int N = a.size();
	V<mint> res(N);
	calcq(0,N,a);
	calc(0,N,f,a,res);
	return res;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

