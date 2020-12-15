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


# :warning: data structure/MaxMatching.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#37305dfb5e3ae8ec66b10a691aedead8">data structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/MaxMatching.cpp">View this file on GitHub</a>
    - Last commit date: 2019-02-15 14:02:44+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	多重辺、自己ループも大丈夫

	MaxMatching(N) -> add_edge(x,y) -> maxMatching()
	mate[v] = u or -1

	N = 500, M <= N Choose 2 で 200 ms

	https://min-25.hatenablog.com/entry/2016/11/21/222625

	N = M = 100000 なら多分通る

	verified at:
		http://uoj.ac/problem/79
		https://www.spoj.com/problems/ADABLOOM/
		https://official.contest.yandex.com/ptz-winter-2019/contest/11818/problems

*/

struct MaxMatching{
	int N;
	VV<int> G;

	V<int> mate;

	void add_edge(int a,int b){
		if(a == b) return;
		G[a].pb(b);
		G[b].pb(a);
	}

	MaxMatching(int _N):N(_N),G(N){}

	using P = pair<int,int>;

	int maxMatching(){
		mate = V<int>(N+1,N);
		V<int> first(N+1,N),que(N);
		V<P> label(N+1,P(-1,-1));
		int qh = 0, qt = 0;

		auto enqueue = [&](int v){
			que[qt++] = v;
		};
		auto dequeue = [&](){
			return que[qh++];
		};

		function<void(int,int)> rematch = [&](int a, int b){
			int c = mate[a];
			mate[a] = b;
			if(mate[c] != a) return;
			if(label[a].sc == -1){
				mate[c] = label[a].fs;
				rematch(mate[c],c);
			}else{
				int x,y;
				tie(x,y) = label[a];
				rematch(x,y);
				rematch(y,x);
			}
		};
		auto relabel = [&](int a, int b){
			function<int(int)> findFirst = [&](int v){
				if(label[first[v]].fs < 0) return first[v];
				return first[v] = findFirst(first[v]);
			};
			int x = findFirst(a), y = findFirst(b);
			if(x == y) return;
			P h(~a,b);
			label[x] = label[y] = h;
			int join = -1;
			while(true){
				if(y != N) swap(x,y);
				x = findFirst(label[mate[x]].fs);
				if(label[x] == h){
					join = x;
					break;
				}else{
					label[x] = h;
				}
			}
			for(int v: {first[a],first[b]}){
				for(;v != join; v = first[label[mate[v]].fs]){
					label[v] = P(a,b);
					first[v] = join;
					enqueue(v);
				}
			}
		};
		auto augment = [&](int s){
			label[s] = P(N,-1);
			first[s] = N;
			qh = qt = 0;
			enqueue(s);
			while(qh != qt){
				int a = dequeue();
				for(int b: G[a]){
					if(mate[b] == N && b != s){
						mate[b] = a;
						rematch(a,b);
						return true;
					}else if(label[b].fs >= 0){
						relabel(a,b);
					}else if(label[mate[b]].fs == -1){
						label[mate[b]].fs = a;
						first[mate[b]] = b;
						enqueue(mate[b]);
					}
				}
			}
			return false;
		};

		int numMatch = 0;
		rep(v,N){
			if(mate[v]<N || !augment(v)) continue;
			numMatch++;
			rep(i,qt){		// including popped !!
				int v = que[i];
				label[v] = label[mate[v]] = P(-1,-1);
			}
			label[N] = P(-1,-1);
		}
		mate.pop_back();
		rep(i,N) if(mate[i] == N) mate[i] = -1;
		return numMatch;
	}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/MaxMatching.cpp"
/*
	多重辺、自己ループも大丈夫

	MaxMatching(N) -> add_edge(x,y) -> maxMatching()
	mate[v] = u or -1

	N = 500, M <= N Choose 2 で 200 ms

	https://min-25.hatenablog.com/entry/2016/11/21/222625

	N = M = 100000 なら多分通る

	verified at:
		http://uoj.ac/problem/79
		https://www.spoj.com/problems/ADABLOOM/
		https://official.contest.yandex.com/ptz-winter-2019/contest/11818/problems

*/

struct MaxMatching{
	int N;
	VV<int> G;

	V<int> mate;

	void add_edge(int a,int b){
		if(a == b) return;
		G[a].pb(b);
		G[b].pb(a);
	}

	MaxMatching(int _N):N(_N),G(N){}

	using P = pair<int,int>;

	int maxMatching(){
		mate = V<int>(N+1,N);
		V<int> first(N+1,N),que(N);
		V<P> label(N+1,P(-1,-1));
		int qh = 0, qt = 0;

		auto enqueue = [&](int v){
			que[qt++] = v;
		};
		auto dequeue = [&](){
			return que[qh++];
		};

		function<void(int,int)> rematch = [&](int a, int b){
			int c = mate[a];
			mate[a] = b;
			if(mate[c] != a) return;
			if(label[a].sc == -1){
				mate[c] = label[a].fs;
				rematch(mate[c],c);
			}else{
				int x,y;
				tie(x,y) = label[a];
				rematch(x,y);
				rematch(y,x);
			}
		};
		auto relabel = [&](int a, int b){
			function<int(int)> findFirst = [&](int v){
				if(label[first[v]].fs < 0) return first[v];
				return first[v] = findFirst(first[v]);
			};
			int x = findFirst(a), y = findFirst(b);
			if(x == y) return;
			P h(~a,b);
			label[x] = label[y] = h;
			int join = -1;
			while(true){
				if(y != N) swap(x,y);
				x = findFirst(label[mate[x]].fs);
				if(label[x] == h){
					join = x;
					break;
				}else{
					label[x] = h;
				}
			}
			for(int v: {first[a],first[b]}){
				for(;v != join; v = first[label[mate[v]].fs]){
					label[v] = P(a,b);
					first[v] = join;
					enqueue(v);
				}
			}
		};
		auto augment = [&](int s){
			label[s] = P(N,-1);
			first[s] = N;
			qh = qt = 0;
			enqueue(s);
			while(qh != qt){
				int a = dequeue();
				for(int b: G[a]){
					if(mate[b] == N && b != s){
						mate[b] = a;
						rematch(a,b);
						return true;
					}else if(label[b].fs >= 0){
						relabel(a,b);
					}else if(label[mate[b]].fs == -1){
						label[mate[b]].fs = a;
						first[mate[b]] = b;
						enqueue(mate[b]);
					}
				}
			}
			return false;
		};

		int numMatch = 0;
		rep(v,N){
			if(mate[v]<N || !augment(v)) continue;
			numMatch++;
			rep(i,qt){		// including popped !!
				int v = que[i];
				label[v] = label[mate[v]] = P(-1,-1);
			}
			label[N] = P(-1,-1);
		}
		mate.pop_back();
		rep(i,N) if(mate[i] == N) mate[i] = -1;
		return numMatch;
	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

