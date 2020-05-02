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


# :warning: geom/argsort.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#dd992be5859bfc12e59d4c15b4c17cf8">geom</a>
* <a href="{{ site.github.repository_url }}/blob/master/geom/argsort.cpp">View this file on GitHub</a>
    - Last commit date: 2018-09-18 03:14:42+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
ロバストな偏角ソート (0,0)を渡すな
(0,+)が最小,同じ角度は適当

二周するのが必要な時(ex.各点から180度以内の点を探す)とかはかなり面倒な気がする
二週目ですか?っていうboolをもって,pair<P,bool>にして、shoの返り値を0~7にする
+pi とかもちょっと面倒なため、普通にdoubleでやっても良さそう
ちなみにわざわざ0~2piにすることはなくて、atan2(y,x)の返り値-pi~piを直接使うほうが楽そう

*/
inline int sho(P p){
	int x=p.fs,y=p.sc;
	if(x>0&&y>=0) return 0;
	if(x<=0&&y>0) return 1;
	if(x<0&&y<=0) return 2;
	if(x>=0&&y<0) return 3;
	assert(false);
}
bool comp(P p,P q){
	int s=sho(p),t=sho(q);
	if(s!=t) return s<t;
	ll a=p.fs,b=p.sc,c=q.fs,d=q.sc;
	return b*c<a*d;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "geom/argsort.cpp"
/*
ロバストな偏角ソート (0,0)を渡すな
(0,+)が最小,同じ角度は適当

二周するのが必要な時(ex.各点から180度以内の点を探す)とかはかなり面倒な気がする
二週目ですか?っていうboolをもって,pair<P,bool>にして、shoの返り値を0~7にする
+pi とかもちょっと面倒なため、普通にdoubleでやっても良さそう
ちなみにわざわざ0~2piにすることはなくて、atan2(y,x)の返り値-pi~piを直接使うほうが楽そう

*/
inline int sho(P p){
	int x=p.fs,y=p.sc;
	if(x>0&&y>=0) return 0;
	if(x<=0&&y>0) return 1;
	if(x<0&&y<=0) return 2;
	if(x>=0&&y<0) return 3;
	assert(false);
}
bool comp(P p,P q){
	int s=sho(p),t=sho(q);
	if(s!=t) return s<t;
	ll a=p.fs,b=p.sc,c=q.fs,d=q.sc;
	return b*c<a*d;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

