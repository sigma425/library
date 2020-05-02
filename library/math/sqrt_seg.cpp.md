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


# :warning: math/sqrt_seg.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/sqrt_seg.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-03 21:50:24+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
    x \in [L,R] に対して N/x = v なる区間 [l,r] を列挙
    v の値が大きい順 (区間を左から順)
    !!! 全部閉区間 !!!
    {3,3,3,}
    {2,4,5,}
    {1,6,10,}
    {0,11,20,}
    O(種類数) = O(N/L - N/R)
*/
vector<array<ll,3>> get_vlr(ll L,ll R,ll N){     //[L,R]
    assert(1 <= L && L <= R);
    vector<array<ll,3>> res;
    for(ll i=L,j;i<=R;i=j+1){
        ll v = N/i;
        j = v == 0 ? R : N/v; chmin(j,R);
        res.emplace_back(array<ll,3>{v,i,j});
    }
    return res;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/sqrt_seg.cpp"
/*
    x \in [L,R] に対して N/x = v なる区間 [l,r] を列挙
    v の値が大きい順 (区間を左から順)
    !!! 全部閉区間 !!!
    {3,3,3,}
    {2,4,5,}
    {1,6,10,}
    {0,11,20,}
    O(種類数) = O(N/L - N/R)
*/
vector<array<ll,3>> get_vlr(ll L,ll R,ll N){     //[L,R]
    assert(1 <= L && L <= R);
    vector<array<ll,3>> res;
    for(ll i=L,j;i<=R;i=j+1){
        ll v = N/i;
        j = v == 0 ? R : N/v; chmin(j,R);
        res.emplace_back(array<ll,3>{v,i,j});
    }
    return res;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

