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


# :warning: graph/dijkstra.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2017-07-04 20:23:14+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	D によってinf の書き換え
	double なら = まわりを変える
*/
template<class D>
vector<D> dijkstra(const vector<vector<pair<int,D>>>& G, int s = 0){	//G:(v,cost)
	using P = pair<D,int>;
	priority_queue<P,vector<P>,greater<P> > que;
	int N = G.size();

	D inf = 1e18;
	vector<D> d(N,inf);
	d[s] = 0;
	que.push(P(0,s));

	while(!que.empty()){
		P p=que.top();
		que.pop();
		int v = p.sc;
		D c = p.fs;
		if(d[v]!=c) continue;
		for(auto p:G[v]){
			int to=p.fs;
			if(d[to]>d[v]+p.sc){
				d[to]=d[v]+p.sc;
				que.push(P(d[to],to));
			}
		}
	}

	return d;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/dijkstra.cpp"
/*
	D によってinf の書き換え
	double なら = まわりを変える
*/
template<class D>
vector<D> dijkstra(const vector<vector<pair<int,D>>>& G, int s = 0){	//G:(v,cost)
	using P = pair<D,int>;
	priority_queue<P,vector<P>,greater<P> > que;
	int N = G.size();

	D inf = 1e18;
	vector<D> d(N,inf);
	d[s] = 0;
	que.push(P(0,s));

	while(!que.empty()){
		P p=que.top();
		que.pop();
		int v = p.sc;
		D c = p.fs;
		if(d[v]!=c) continue;
		for(auto p:G[v]){
			int to=p.fs;
			if(d[to]>d[v]+p.sc){
				d[to]=d[v]+p.sc;
				que.push(P(d[to],to));
			}
		}
	}

	return d;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

