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


# :warning: graph/cycle.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/cycle.cpp">View this file on GitHub</a>
    - Last commit date: 2018-01-03 23:14:20+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	(directed/undirected)サイクル検出
	ひとつ見つけてそれを返す ない場合{}
	自己loopがある場合それを返してしまう(長さ1のサイクルを返す) ← 適当に変えられる
	多重辺があっても無視する(長さ2のサイクルは返さない) ← pじゃなくてedge id で保存すると回避できる

	いまdirectedで、undirectedにしたいならpをもってdfscする

	verified at codefestival2016 final J (Neue Spiel)
*/

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
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}

bool dfsc(int v, const vector<vector<int>>& G, vector<int>& vis, vector<int>& cyc, bool& done){
	if(vis[v]==1){
		cyc.pb(v);
		return 1;
	}
	if(vis[v]==2) return 0;

	vis[v] = 1;
	for(int u:G[v]){
		if(dfsc(u,G,vis,cyc,done)){
			if(v==cyc[0]) done=1;
			if(!done) cyc.pb(v);
			return 1;
		}
	}
	vis[v] = 2;
	return 0;
}
vector<int> getcycle(const vector<vector<int>>& G){
	int N = G.size();
	vector<int> vis(N,0);	//0:yet 1:now 2:done
	bool done = 0;
	vector<int> cyc;
	rep(i,N) if(vis[i]==0){
		if(dfsc(i,G,vis,cyc,done)){
			reverse(all(cyc));
			return cyc;
		}
	}
	return {};
}

void unittest(){
	// vector<int> as = {2,3,2,4,2,6,2};
	// vector<int> bs = {6,4,3,2,1,5,5};
	// vector<int> as = {2};
	// vector<int> bs = {1};
	vector<int> as = {1,3,4,5,6,7,8,9};
	vector<int> bs = {2,1,3,6,7,8,5,8};
	rep(i,as.size()){
		G[as[i]].pb(bs[i]);
//		G[bs[i]].pb(as[i]);
	}

	vector<int> cyc = getcycle(7);
	show(cyc);
}

int main(){
	unittest();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/cycle.cpp"
/*
	(directed/undirected)サイクル検出
	ひとつ見つけてそれを返す ない場合{}
	自己loopがある場合それを返してしまう(長さ1のサイクルを返す) ← 適当に変えられる
	多重辺があっても無視する(長さ2のサイクルは返さない) ← pじゃなくてedge id で保存すると回避できる

	いまdirectedで、undirectedにしたいならpをもってdfscする

	verified at codefestival2016 final J (Neue Spiel)
*/

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
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}

bool dfsc(int v, const vector<vector<int>>& G, vector<int>& vis, vector<int>& cyc, bool& done){
	if(vis[v]==1){
		cyc.pb(v);
		return 1;
	}
	if(vis[v]==2) return 0;

	vis[v] = 1;
	for(int u:G[v]){
		if(dfsc(u,G,vis,cyc,done)){
			if(v==cyc[0]) done=1;
			if(!done) cyc.pb(v);
			return 1;
		}
	}
	vis[v] = 2;
	return 0;
}
vector<int> getcycle(const vector<vector<int>>& G){
	int N = G.size();
	vector<int> vis(N,0);	//0:yet 1:now 2:done
	bool done = 0;
	vector<int> cyc;
	rep(i,N) if(vis[i]==0){
		if(dfsc(i,G,vis,cyc,done)){
			reverse(all(cyc));
			return cyc;
		}
	}
	return {};
}

void unittest(){
	// vector<int> as = {2,3,2,4,2,6,2};
	// vector<int> bs = {6,4,3,2,1,5,5};
	// vector<int> as = {2};
	// vector<int> bs = {1};
	vector<int> as = {1,3,4,5,6,7,8,9};
	vector<int> bs = {2,1,3,6,7,8,5,8};
	rep(i,as.size()){
		G[as[i]].pb(bs[i]);
//		G[bs[i]].pb(as[i]);
	}

	vector<int> cyc = getcycle(7);
	show(cyc);
}

int main(){
	unittest();
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

