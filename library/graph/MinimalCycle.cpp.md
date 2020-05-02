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


# :warning: graph/MinimalCycle.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/MinimalCycle.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-24 04:12:36+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
    minimal な ( <=> induced graph も cycle, chordless?) cycle を一つ返す、なければ {}
    Undirected / Directed
    O(V+E)
    verified
        Undirected : CF594 F
        Directed : ABC142 F (でも、嘘(Down1個)が通ったのでまともなverifyではない・・・)

    undirected なら dfs tree の Up のうち最短を取ればおわり
    directed ならそのサイクル内で Down を使いまくる必要があって、その頂点から貪欲に最長を取ればいい
*/
V<int> getMinimalCycleUndirected(const VV<int>& G){
	using P = pair<int,int>;
	int N = G.size();
	V<int> vis(N);	//0:yet 1:now 2:done
	V<int> par(N,-1);
	V<int> d(N);

	P U(-1,-1);	// min distance backward edge

	function<void(int,int)> dfs = [&](int v,int p){
		vis[v] = 1;
		for(int u: G[v]) if(u != p){
			if(vis[u] == 0){	// dfs edge
				par[u] = v;
				d[u] = d[v]+1;
				dfs(u,v);
			}else if(vis[u] == 1){	// up
				if(U.fs == -1 || d[U.fs] - d[U.sc] > d[v] - d[u]){
					U = P(v,u);
				}
			}else{}	// down
		}
		vis[v] = 2;
	};
	rep(v,N) if(vis[v] == 0){
		dfs(v,-1);
	}
	if(U.fs == -1) return {};
	V<int> c;
	{
		int v = U.fs;
		while(true){
			c.pb(v);
			if(v == U.sc) break;
			v = par[v];
		}
	}
	return c;
}

V<int> getMinimalCycleDirected(const VV<int>& G){
	using P = pair<int,int>;
	int N = G.size();
	V<int> vis(N);	//0:yet 1:now 2:done
	V<int> par(N,-1);
	V<int> d(N);

	P U(-1,-1);	// min distance backward edge

	function<void(int)> dfs = [&](int v){
		vis[v] = 1;
		for(int u: G[v]){
			if(vis[u] == 0){	// dfs edge
				par[u] = v;
				d[u] = d[v]+1;
				dfs(u);
			}else if(vis[u] == 1){	// up
				if(U.fs == -1 || d[U.fs] - d[U.sc] > d[v] - d[u]){
					U = P(v,u);
				}
			}else{}	// left, down
		}
		vis[v] = 2;
	};
	rep(v,N) if(vis[v] == 0){
		dfs(v);
	}
	if(U.fs == -1) return {};
	V<bool> in_cycle(N);
	V<int> c;
	{
		int v = U.fs;
		while(true){
			c.pb(v); in_cycle[v] = true;
			if(v == U.sc) break;
			v = par[v];
		}
	}
	reverse(all(c));
	V<int> nc;
	{
		int v = c[0];
		while(true){
			nc.pb(v);
			if(v == c.back()) break;
			int nxt = v;
			for(int u: G[v]) if(in_cycle[u] && d[u] > d[nxt]) nxt = u;
			v = nxt;
		}
	}
	return nc;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/MinimalCycle.cpp"
/*
    minimal な ( <=> induced graph も cycle, chordless?) cycle を一つ返す、なければ {}
    Undirected / Directed
    O(V+E)
    verified
        Undirected : CF594 F
        Directed : ABC142 F (でも、嘘(Down1個)が通ったのでまともなverifyではない・・・)

    undirected なら dfs tree の Up のうち最短を取ればおわり
    directed ならそのサイクル内で Down を使いまくる必要があって、その頂点から貪欲に最長を取ればいい
*/
V<int> getMinimalCycleUndirected(const VV<int>& G){
	using P = pair<int,int>;
	int N = G.size();
	V<int> vis(N);	//0:yet 1:now 2:done
	V<int> par(N,-1);
	V<int> d(N);

	P U(-1,-1);	// min distance backward edge

	function<void(int,int)> dfs = [&](int v,int p){
		vis[v] = 1;
		for(int u: G[v]) if(u != p){
			if(vis[u] == 0){	// dfs edge
				par[u] = v;
				d[u] = d[v]+1;
				dfs(u,v);
			}else if(vis[u] == 1){	// up
				if(U.fs == -1 || d[U.fs] - d[U.sc] > d[v] - d[u]){
					U = P(v,u);
				}
			}else{}	// down
		}
		vis[v] = 2;
	};
	rep(v,N) if(vis[v] == 0){
		dfs(v,-1);
	}
	if(U.fs == -1) return {};
	V<int> c;
	{
		int v = U.fs;
		while(true){
			c.pb(v);
			if(v == U.sc) break;
			v = par[v];
		}
	}
	return c;
}

V<int> getMinimalCycleDirected(const VV<int>& G){
	using P = pair<int,int>;
	int N = G.size();
	V<int> vis(N);	//0:yet 1:now 2:done
	V<int> par(N,-1);
	V<int> d(N);

	P U(-1,-1);	// min distance backward edge

	function<void(int)> dfs = [&](int v){
		vis[v] = 1;
		for(int u: G[v]){
			if(vis[u] == 0){	// dfs edge
				par[u] = v;
				d[u] = d[v]+1;
				dfs(u);
			}else if(vis[u] == 1){	// up
				if(U.fs == -1 || d[U.fs] - d[U.sc] > d[v] - d[u]){
					U = P(v,u);
				}
			}else{}	// left, down
		}
		vis[v] = 2;
	};
	rep(v,N) if(vis[v] == 0){
		dfs(v);
	}
	if(U.fs == -1) return {};
	V<bool> in_cycle(N);
	V<int> c;
	{
		int v = U.fs;
		while(true){
			c.pb(v); in_cycle[v] = true;
			if(v == U.sc) break;
			v = par[v];
		}
	}
	reverse(all(c));
	V<int> nc;
	{
		int v = c[0];
		while(true){
			nc.pb(v);
			if(v == c.back()) break;
			int nxt = v;
			for(int u: G[v]) if(in_cycle[u] && d[u] > d[nxt]) nxt = u;
			v = nxt;
		}
	}
	return nc;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

