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


# :warning: math/BaseP.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/BaseP.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	base-10のstringをp進表記にしたのを返す ret[0]が1の位
	O(L^2)
*/
vector<ll> Basep(string s,ll p){
	int L=s.size();
	int up=4000;
	vector<ll> ret(up,0);
	int N=0;
	rep(i,L){
		rep(j,N) ret[j]*=10;
		ret[0]+=s[i]-'0';
		int j=0;
		while(j<N-1||ret[j]>=p){
			ret[j+1]+=ret[j]/p;
			ret[j]%=p;
			j++;
		}
		N=j+1;
	}
	ret.erase(ret.begin()+N,ret.end());
	return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/BaseP.cpp"
/*
	base-10のstringをp進表記にしたのを返す ret[0]が1の位
	O(L^2)
*/
vector<ll> Basep(string s,ll p){
	int L=s.size();
	int up=4000;
	vector<ll> ret(up,0);
	int N=0;
	rep(i,L){
		rep(j,N) ret[j]*=10;
		ret[0]+=s[i]-'0';
		int j=0;
		while(j<N-1||ret[j]>=p){
			ret[j+1]+=ret[j]/p;
			ret[j]%=p;
			j++;
		}
		N=j+1;
	}
	ret.erase(ret.begin()+N,ret.end());
	return ret;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

