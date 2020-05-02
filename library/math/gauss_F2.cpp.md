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


# :warning: math/gauss_F2.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/gauss_F2.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:53:45+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
    F2 ^ Dの基底持つ / 更新するやつ
    add が O(D)
    merge は add を D回、 O(D^2)

    given a に対し、 min(max){a^v | v \in space} は上の桁からxorするかしないか貪欲に選べばいい

    (normalize)
        部分空間を状態として持ちたいときはBを正規化する必要がある
        上の桁から見て辞書順最小にする
        O(D^2)
    
    subspace の数は {1, 2, 5, 16, 67, 374, 2825, 29212, 417199, 8283458}
    そもそも個数が少ないのでN回dpを更新する代わりに同じsubspaceになるやつはまとめて、とかもありうる
        https://codeforces.com/contest/1299/problem/D

    D <= 6 なら貼る空間を 2^D bit で持った方が楽か? 計算量悪くなるが

    とにかく状態が少なくて計算する回数が多いなら、はじめに全部生成してから演算表(merge,add)を作りましょう
    1299/D.cpp 参照
*/

const int D = 64;
V<ull> B(D);

void add(ull x){
    for(int i=D-1;i>=0;i--){
        if(B[i] == 0 && x&1ULL<<i){ // add to base
            B[i] = x;
            return;
        }else if(x&1ULL<<i){
            x ^= B[i];
        }
    }
    // don't add to base
    // (dependent)
}

void normalize(){
    for(int i=D-1;i>=0;i--) if(B[i]){
        for(int j=i-1;j>=0;j--) chmin(B[i],B[i]^B[j]);
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/gauss_F2.cpp"
/*
    F2 ^ Dの基底持つ / 更新するやつ
    add が O(D)
    merge は add を D回、 O(D^2)

    given a に対し、 min(max){a^v | v \in space} は上の桁からxorするかしないか貪欲に選べばいい

    (normalize)
        部分空間を状態として持ちたいときはBを正規化する必要がある
        上の桁から見て辞書順最小にする
        O(D^2)
    
    subspace の数は {1, 2, 5, 16, 67, 374, 2825, 29212, 417199, 8283458}
    そもそも個数が少ないのでN回dpを更新する代わりに同じsubspaceになるやつはまとめて、とかもありうる
        https://codeforces.com/contest/1299/problem/D

    D <= 6 なら貼る空間を 2^D bit で持った方が楽か? 計算量悪くなるが

    とにかく状態が少なくて計算する回数が多いなら、はじめに全部生成してから演算表(merge,add)を作りましょう
    1299/D.cpp 参照
*/

const int D = 64;
V<ull> B(D);

void add(ull x){
    for(int i=D-1;i>=0;i--){
        if(B[i] == 0 && x&1ULL<<i){ // add to base
            B[i] = x;
            return;
        }else if(x&1ULL<<i){
            x ^= B[i];
        }
    }
    // don't add to base
    // (dependent)
}

void normalize(){
    for(int i=D-1;i>=0;i--) if(B[i]){
        for(int j=i-1;j>=0;j--) chmin(B[i],B[i]^B[j]);
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

