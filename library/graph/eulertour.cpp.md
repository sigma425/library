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


# :warning: graph/eulertour.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/eulertour.cpp">View this file on GitHub</a>
    - Last commit date: 2017-07-04 20:23:14+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	- in のみ
	- in out のみ
	- 訪れるたび
	の3通り

	subtree	: inのみ で十分
	path	: in out
	lca		: 訪れるたび

	eulertour
	w=lca(a,b)として,2つのpathにわける.wa,wb,をやったあとwwを引くのも手.
	更新は add(v2id[w][0],v2id[a][0]+1,*) の形 +1に注意
	クエリも同様なんだけど,点クエリが勘違いしやすくて,ちゃんとval(v2id[v][0])-val(v2id[v][1]) と差分を取ること.

	verified by https://www.codechef.com/LTIME37/problems/TRAVTREE
*/
struct EulerTour{		//in + out version
	int I = 0;
	vector<int> id,in,out;

	EulerTour(const vector<vector<int>>& G, int r = 0){
		int N = G.size();
		id.assign(2*N,0);
		in.assign(N,0);
		out.assign(N,0);
		traverse(r,-1,G);
	}

	void traverse(int v,int p,const vector<vector<int>>& G){
		id[I]=v,in[v]=I,I++;
		for(int u:G[v]) if(u!=p) traverse(u,v,G);
		id[I]=v,out[v]=I,I++;
	}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/eulertour.cpp"
/*
	- in のみ
	- in out のみ
	- 訪れるたび
	の3通り

	subtree	: inのみ で十分
	path	: in out
	lca		: 訪れるたび

	eulertour
	w=lca(a,b)として,2つのpathにわける.wa,wb,をやったあとwwを引くのも手.
	更新は add(v2id[w][0],v2id[a][0]+1,*) の形 +1に注意
	クエリも同様なんだけど,点クエリが勘違いしやすくて,ちゃんとval(v2id[v][0])-val(v2id[v][1]) と差分を取ること.

	verified by https://www.codechef.com/LTIME37/problems/TRAVTREE
*/
struct EulerTour{		//in + out version
	int I = 0;
	vector<int> id,in,out;

	EulerTour(const vector<vector<int>>& G, int r = 0){
		int N = G.size();
		id.assign(2*N,0);
		in.assign(N,0);
		out.assign(N,0);
		traverse(r,-1,G);
	}

	void traverse(int v,int p,const vector<vector<int>>& G){
		id[I]=v,in[v]=I,I++;
		for(int u:G[v]) if(u!=p) traverse(u,v,G);
		id[I]=v,out[v]=I,I++;
	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

