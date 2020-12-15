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


# :warning: graph/topo_test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/topo_test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
const int MAX_V=10;
int vis[MAX_V];		//0->yet,1->now,2->done
vector<int> topo;
vector<int> G[MAX_V];
bool visit(int v){
	if(vis[v]==2) return 1;
	if(vis[v]==1) return 0;
	vis[v]=1;
	for(int u:G[v]) if(!visit(u)) return 0;
	vis[v]=2;
	topo.pb(v);
	return 1;
}
bool maketopo(int V){
	rep(i,V) if(!visit(i)) return 0;
	reverse(all(topo));
	return 1;
}
int main(){
	int N,M;
	cin>>N>>M;
	rep(i,M){
		int a,b;
		cin>>a>>b;
		G[a].pb(b);
	}
	if(maketopo(N)){
		rep(i,N) cout<<topo[i]<<" ";
		puts("");
	}else{
		puts("not dag");
	}
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/topo_test.cpp"
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
const int MAX_V=10;
int vis[MAX_V];		//0->yet,1->now,2->done
vector<int> topo;
vector<int> G[MAX_V];
bool visit(int v){
	if(vis[v]==2) return 1;
	if(vis[v]==1) return 0;
	vis[v]=1;
	for(int u:G[v]) if(!visit(u)) return 0;
	vis[v]=2;
	topo.pb(v);
	return 1;
}
bool maketopo(int V){
	rep(i,V) if(!visit(i)) return 0;
	reverse(all(topo));
	return 1;
}
int main(){
	int N,M;
	cin>>N>>M;
	rep(i,M){
		int a,b;
		cin>>a>>b;
		G[a].pb(b);
	}
	if(maketopo(N)){
		rep(i,N) cout<<topo[i]<<" ";
		puts("");
	}else{
		puts("not dag");
	}
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

