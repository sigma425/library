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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: graph/maximal_ind/maximal_independent.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#f52356fd59e70894433d4f82b2dfb2b1">graph/maximal_ind</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/maximal_ind/maximal_independent.cpp">View this file on GitHub</a>
    - Last commit date: 2016-12-08 00:51:38+09:00




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
int V;
const int MAX_V=40;
vector<int> G[MAX_V];
bool used[MAX_V];
int ord[MAX_V];
int cnt[MAX_V];		//cnt[v] = the num of selected verticies connected with v;
typedef long long ll;
set<ll> done;
void dfs(int it){
	if(it==V){
		ll x=0;
		rep(i,V) if(used[i]) x|=(1LL<<i);
		if(done.find(x)!=done.end()) return;
		done.insert(x);
		rep(i,V) cout<<used[i];
		puts("");
		return;
	}
	int v=ord[it];
	if(used[v]||cnt[v]){
		dfs(it+1);
		return;
	}
	//use v
	used[v]=1;
	for(int u:G[v]) cnt[u]++;
	dfs(it+1);
	used[v]=0;
	for(int u:G[v]) cnt[u]--;

	for(int u:G[v]) if(cnt[u]==0&&!used[u]){
		used[u]=1;
		for(int w:G[u]) cnt[w]++;
		dfs(it+1);
		used[u]=0;
		for(int w:G[u]) cnt[w]--;
	}
}
void enum_ind(int N){
	V=N;
	typedef pair<int,int> P;
	vector<P> tmp;
	rep(i,N) tmp.pb(P(G[i].size(),i));
	sort(all(tmp));
	rep(i,N) ord[i]=tmp[i].sc;
	rep(i,N) used[i]=0,cnt[i]=0;
	done.clear();
	dfs(0);
}
int main(){
	int N,M;
	cin>>N>>M;
	rep(i,M){
		int a,b;
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	enum_ind(N);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/maximal_ind/maximal_independent.cpp"
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
int V;
const int MAX_V=40;
vector<int> G[MAX_V];
bool used[MAX_V];
int ord[MAX_V];
int cnt[MAX_V];		//cnt[v] = the num of selected verticies connected with v;
typedef long long ll;
set<ll> done;
void dfs(int it){
	if(it==V){
		ll x=0;
		rep(i,V) if(used[i]) x|=(1LL<<i);
		if(done.find(x)!=done.end()) return;
		done.insert(x);
		rep(i,V) cout<<used[i];
		puts("");
		return;
	}
	int v=ord[it];
	if(used[v]||cnt[v]){
		dfs(it+1);
		return;
	}
	//use v
	used[v]=1;
	for(int u:G[v]) cnt[u]++;
	dfs(it+1);
	used[v]=0;
	for(int u:G[v]) cnt[u]--;

	for(int u:G[v]) if(cnt[u]==0&&!used[u]){
		used[u]=1;
		for(int w:G[u]) cnt[w]++;
		dfs(it+1);
		used[u]=0;
		for(int w:G[u]) cnt[w]--;
	}
}
void enum_ind(int N){
	V=N;
	typedef pair<int,int> P;
	vector<P> tmp;
	rep(i,N) tmp.pb(P(G[i].size(),i));
	sort(all(tmp));
	rep(i,N) ord[i]=tmp[i].sc;
	rep(i,N) used[i]=0,cnt[i]=0;
	done.clear();
	dfs(0);
}
int main(){
	int N,M;
	cin>>N>>M;
	rep(i,M){
		int a,b;
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	enum_ind(N);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

