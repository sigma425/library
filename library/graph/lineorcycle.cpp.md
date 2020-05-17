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


# :warning: graph/lineorcycle.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/lineorcycle.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-17 22:45:26+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<class E>
void solve(const VV<int>& G){
	int N = G.size();
	auto do_isolated = [&](int v){

	};
	auto do_line = [&](V<int> vs){

	};
	auto do_cycle = [&](V<int> vs){

	};
	V<bool> used(N);
	rep(i,N) if(!used[i]){
		assert(si(G[i])<=2);
		if(si(G[i]) == 0){
			do_isolated(i);
			used[i] = true;
			continue;
		}
		int v = i;
		int p = G[v][0];
		while(si(G[v]) == 2){
			int nv = G[v][0]^G[v][1]^p;
			p = v; v = nv;
			if(v == i) break;
		}
		if(si(G[v]) == 1){	//line
			vector<int> vs;
			vs.pb(v); used[v]=1;
			int p = v;
			v = G[v][0];
			while(si(G[v]) == 2){
				vs.pb(v); used[v]=1;
				int nv = G[v][0]^G[v][1]^p;
				p = v; v = nv;
			}
			vs.pb(v);used[v]=1;
			do_line(vs);
		}else{				//cycle
			vector<int> vs;
			int p = G[v][0];
			while(!used[v]){
				vs.pb(v);used[v]=1;
				int nv = G[v][0]^G[v][1]^p;
				p = v; v = nv;
			}
			do_cycle(vs);
		}
	}
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/lineorcycle.cpp"
template<class E>
void solve(const VV<int>& G){
	int N = G.size();
	auto do_isolated = [&](int v){

	};
	auto do_line = [&](V<int> vs){

	};
	auto do_cycle = [&](V<int> vs){

	};
	V<bool> used(N);
	rep(i,N) if(!used[i]){
		assert(si(G[i])<=2);
		if(si(G[i]) == 0){
			do_isolated(i);
			used[i] = true;
			continue;
		}
		int v = i;
		int p = G[v][0];
		while(si(G[v]) == 2){
			int nv = G[v][0]^G[v][1]^p;
			p = v; v = nv;
			if(v == i) break;
		}
		if(si(G[v]) == 1){	//line
			vector<int> vs;
			vs.pb(v); used[v]=1;
			int p = v;
			v = G[v][0];
			while(si(G[v]) == 2){
				vs.pb(v); used[v]=1;
				int nv = G[v][0]^G[v][1]^p;
				p = v; v = nv;
			}
			vs.pb(v);used[v]=1;
			do_line(vs);
		}else{				//cycle
			vector<int> vs;
			int p = G[v][0];
			while(!used[v]){
				vs.pb(v);used[v]=1;
				int nv = G[v][0]^G[v][1]^p;
				p = v; v = nv;
			}
			do_cycle(vs);
		}
	}
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

