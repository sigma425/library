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


# :heavy_check_mark: test_oj/scc.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#d917bfc2afe503d9009ff5d8d6b2e2c3">test_oj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test_oj/scc.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-10 02:28:11+09:00


* see: <a href="https://judge.yosupo.jp/problem/scc">https://judge.yosupo.jp/problem/scc</a>


## Depends on

* :heavy_check_mark: <a href="../../library/graph/scc.cpp.html">graph/scc.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

#ifdef LOCAL
#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x) true
#endif

#include "../graph/scc.cpp"

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);
	
   int N,M;
   cin >> N >> M;
   struct E{int to;};
   VV<E> G(N);
   rep(i,M){
       int x,y;
       cin >> x >> y;
       G[x].pb({y});
   }
   auto scc = SCC<E>(G);
   auto& groups = scc.groups;
   cout << groups.size() << endl;
   for(auto g: groups){
       cout << g.size();
       for(int v: g) cout << " " << v;
       cout << endl;
   }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test_oj/scc.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

#ifdef LOCAL
#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x) true
#endif

#line 1 "graph/scc.cpp"
/*
    SCC O(M+N)
    id[v] = v の 連結成分の id
    groups[i] : i番目の連結成分, トポロジカル順
*/
template <class E>
struct SCC{
	V<int> id;
	VV<int> groups;

	int N;
	VV<E> G;
	V<int> ord,low;
	V<bool> inS;
	V<int> st;
    int I=0;

	void dfs(int v){
		ord[v] = low[v] = I++;
		st.pb(v); inS[v] = true;
		for(auto e: G[v]){
			int u = e.to;
			if(ord[u] == -1){
				dfs(u);
				chmin(low[v],low[u]);
			}else if(inS[u]){
				chmin(low[v],ord[u]);
			}
		}
		if(low[v] == ord[v]){
			V<int> group;
			while(true){
				int w = st.back(); st.pop_back();
				inS[w] = false;
				group.pb(w);
				if(w == v) break;
			}
			groups.pb(group);
		}
	}
	SCC(const VV<E>& G_) : N(G_.size()), G(G_), ord(N,-1), low(N), inS(N){
        id = V<int>(N);
		rep(i,N) if(ord[i] == -1) dfs(i);
		reverse(all(groups));
		rep(i,groups.size()){
			for(int v: groups[i]) id[v] = i;
		}
	}
};
#line 34 "test_oj/scc.test.cpp"

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);
	
   int N,M;
   cin >> N >> M;
   struct E{int to;};
   VV<E> G(N);
   rep(i,M){
       int x,y;
       cin >> x >> y;
       G[x].pb({y});
   }
   auto scc = SCC<E>(G);
   auto& groups = scc.groups;
   cout << groups.size() << endl;
   for(auto g: groups){
       cout << g.size();
       for(int v: g) cout << " " << v;
       cout << endl;
   }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

