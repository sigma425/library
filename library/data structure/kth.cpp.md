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


# :warning: data structure/kth.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#37305dfb5e3ae8ec66b10a691aedead8">data structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/kth.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
ll sum(int a,int b,int l,int r,int k){
	if(r<=a||b<=l) return 0;
	if(a<=l&&r<=b) return seg[k];
	return sum(a,b,l,(l+r)/2,k*2+1,seg)+sum(a,b,(l+r)/2,r,k*2+2,seg);
}
void add(int x,int v){
	while(true){
		seg[x]+=v;
		if(x==0) break;
		x=(x-1)/2;
	}
}
int kth(int l,int r,int id,int k){
	if(l+1==r) return l;
	if(seg[2*id+1]>=k) return kth(l,(l+r)/2,id*2+1,k);
	else return kth((l+r)/2,r,id*2+2,k-seg[2*id+1]);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/kth.cpp"
ll sum(int a,int b,int l,int r,int k){
	if(r<=a||b<=l) return 0;
	if(a<=l&&r<=b) return seg[k];
	return sum(a,b,l,(l+r)/2,k*2+1,seg)+sum(a,b,(l+r)/2,r,k*2+2,seg);
}
void add(int x,int v){
	while(true){
		seg[x]+=v;
		if(x==0) break;
		x=(x-1)/2;
	}
}
int kth(int l,int r,int id,int k){
	if(l+1==r) return l;
	if(seg[2*id+1]>=k) return kth(l,(l+r)/2,id*2+1,k);
	else return kth((l+r)/2,r,id*2+2,k-seg[2*id+1]);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

