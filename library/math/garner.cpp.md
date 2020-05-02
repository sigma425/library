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


# :warning: math/garner.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/garner.cpp">View this file on GitHub</a>
    - Last commit date: 2018-09-18 03:35:42+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	x % rm[i].sc = rm[i].fs
	をみたす非負整数のうち最小のもの%mod を求める
	0をのぞくなら,全0のときのみas[N-1]を返せば良い
	
	!!! rm[i].sc,modはpairwise relatively prime !!!
	素ベキに分解する -> 各素数ごとに矛盾しないか確かめる -> garner

	barcelona2017/5s/G.cpp
*/
typedef long long ll;
typedef pair<ll,ll> P;		//val,mod;
ll inv(ll a,ll m){
	ll b=m,u=1,v=0;
	while(b){
		ll t=a/b;
		swap(a-=t*b,b);
		swap(u-=t*v,v);
	}
	u%=m;
	if(u<0) u+=m;
	return u;
}
/*
	rm は rem,mod
	最後にmodを取る必要が無い場合は引数無しで呼んでよい
*/
ll garner(vector<P> rm,ll mod = -1){
	rm.pb(P(0,mod));
	int N=rm.size();
	vector<ll> as(N,1);		//coefficients
	vector<ll> bs(N,0);		//constants
	rep(i,N-1){
		ll v=(rm[i].fs-bs[i])*inv(as[i],rm[i].sc)%rm[i].sc;
		if(v<0) v+=rm[i].sc;
		for(int j=i+1;j<N;j++){
			if(rm[j].sc != -1){
				(bs[j]+=as[j]*v)%=rm[j].sc;
				(as[j]*=rm[i].sc)%=rm[j].sc;
			}else{
				bs[j] += as[j]*v;
				as[j] *= rm[i].sc;
			}
		}
	}
	return bs[N-1];
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/garner.cpp"
/*
	x % rm[i].sc = rm[i].fs
	をみたす非負整数のうち最小のもの%mod を求める
	0をのぞくなら,全0のときのみas[N-1]を返せば良い
	
	!!! rm[i].sc,modはpairwise relatively prime !!!
	素ベキに分解する -> 各素数ごとに矛盾しないか確かめる -> garner

	barcelona2017/5s/G.cpp
*/
typedef long long ll;
typedef pair<ll,ll> P;		//val,mod;
ll inv(ll a,ll m){
	ll b=m,u=1,v=0;
	while(b){
		ll t=a/b;
		swap(a-=t*b,b);
		swap(u-=t*v,v);
	}
	u%=m;
	if(u<0) u+=m;
	return u;
}
/*
	rm は rem,mod
	最後にmodを取る必要が無い場合は引数無しで呼んでよい
*/
ll garner(vector<P> rm,ll mod = -1){
	rm.pb(P(0,mod));
	int N=rm.size();
	vector<ll> as(N,1);		//coefficients
	vector<ll> bs(N,0);		//constants
	rep(i,N-1){
		ll v=(rm[i].fs-bs[i])*inv(as[i],rm[i].sc)%rm[i].sc;
		if(v<0) v+=rm[i].sc;
		for(int j=i+1;j<N;j++){
			if(rm[j].sc != -1){
				(bs[j]+=as[j]*v)%=rm[j].sc;
				(as[j]*=rm[i].sc)%=rm[j].sc;
			}else{
				bs[j] += as[j]*v;
				as[j] *= rm[i].sc;
			}
		}
	}
	return bs[N-1];
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

