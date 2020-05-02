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


# :warning: data structure/decomposing.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#37305dfb5e3ae8ec66b10a691aedead8">data structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/decomposing.cpp">View this file on GitHub</a>
    - Last commit date: 2017-09-14 22:43:03+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	decomposable problem
	データを複数個のデータに分けた後、それぞれにqueryを投げた後統合できる形ならできる
	query([a1,a2,a3,a4,a5]) = query([a1,a2]) * query([a3]) * query([a4,a5])

	countとかならerase用のを作って消す

	下の例はBIT(座標範囲制限なし) 愚直にsorted vectorにもつだけ
	vv[K-2] と vv[K-1] は一から作らなくてもmergeでいいため、計算量はO(NlogN)
*/

struct Decomposing{
	using D = int;
	vector<vector<D>> vv;

	Decomposing(){}

	void add(D x){
		vv.pb({x});
		while(true){
			int K = vv.size();
			if(K==1 || vv[K-1].size()!=vv[K-2].size()) break;
			vector<D> nv(vv[K-1].size()+vv[K-2].size());
			merge(all(vv[K-2]),all(vv[K-1]),nv.begin());	//reconstruct (with using vv[K-2],vv[K-1])
			vv.pop_back();vv.pop_back();
			vv.pb(nv);
		}
	}
	int get(int x){
		int res = 0;
		for(const auto& v:vv){	//calc query for each and combine them
			res += v.end() - lower_bound(all(v),x);
		}
		return res;
	}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/decomposing.cpp"
/*
	decomposable problem
	データを複数個のデータに分けた後、それぞれにqueryを投げた後統合できる形ならできる
	query([a1,a2,a3,a4,a5]) = query([a1,a2]) * query([a3]) * query([a4,a5])

	countとかならerase用のを作って消す

	下の例はBIT(座標範囲制限なし) 愚直にsorted vectorにもつだけ
	vv[K-2] と vv[K-1] は一から作らなくてもmergeでいいため、計算量はO(NlogN)
*/

struct Decomposing{
	using D = int;
	vector<vector<D>> vv;

	Decomposing(){}

	void add(D x){
		vv.pb({x});
		while(true){
			int K = vv.size();
			if(K==1 || vv[K-1].size()!=vv[K-2].size()) break;
			vector<D> nv(vv[K-1].size()+vv[K-2].size());
			merge(all(vv[K-2]),all(vv[K-1]),nv.begin());	//reconstruct (with using vv[K-2],vv[K-1])
			vv.pop_back();vv.pop_back();
			vv.pb(nv);
		}
	}
	int get(int x){
		int res = 0;
		for(const auto& v:vv){	//calc query for each and combine them
			res += v.end() - lower_bound(all(v),x);
		}
		return res;
	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

