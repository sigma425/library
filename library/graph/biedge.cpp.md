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


# :warning: graph/biedge.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/biedge.cpp">View this file on GitHub</a>
    - Last commit date: 2016-12-08 00:51:38+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
biedge connected component
bsにbridge,ccに二重辺連結成分が入る
!!! 多重辺があるときはelse if(u!=p) のとこで u-pに多重辺があるなら戻っても良い
else if( (u!=p&&inS[u]) || (u==p&&mp[P(min(v,p),max(v,p)]>=2) )
mpはmultimapじゃなくてmap<P,int>
*/
typedef vector<int> vi;
typedef pair<int,int> P;
const int MN=;
vector<int> G[MN];
int ord[MN];
bool inS[MN];
stack<int> roots,S;
vector<vi> cc;
vector<P> bs;
int cnt;
/*
int cmp[MN];
vector<int> cG[MN];
*/
void vis(int v,int p){
	ord[v]=++cnt;
	S.push(v);
	inS[v]=true;
	roots.push(v);
	for(int u:G[v]){
		if(ord[u]==0){
			vis(u,v);
		}else if(u!=p&&inS[u]){
			while(ord[roots.top()]>ord[u]) roots.pop();
		}
	}
	if(v==roots.top()){
		bs.pb(P(p,v));
		vector<int> vc;
		while(true){
			int w=S.top();S.pop();
			inS[w]=false;
			vc.pb(w);
//			cmp[w]=cc.size();
			if(v==w) break;
		}
		roots.pop();
		cc.pb(vc);
	}
}
void bridge(int N){
	rep(i,N) if(ord[i]==0){
		vis(i,-1);
		bs.pop_back();	//P(-1,hoge)
	}
/*	for(P p:bs){
		int x=cmp[p.fs],y=cmp[p.sc];
		cG[x].pb(y),cG[y].pb(x);
	}*/
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/biedge.cpp"
/*
biedge connected component
bsにbridge,ccに二重辺連結成分が入る
!!! 多重辺があるときはelse if(u!=p) のとこで u-pに多重辺があるなら戻っても良い
else if( (u!=p&&inS[u]) || (u==p&&mp[P(min(v,p),max(v,p)]>=2) )
mpはmultimapじゃなくてmap<P,int>
*/
typedef vector<int> vi;
typedef pair<int,int> P;
const int MN=;
vector<int> G[MN];
int ord[MN];
bool inS[MN];
stack<int> roots,S;
vector<vi> cc;
vector<P> bs;
int cnt;
/*
int cmp[MN];
vector<int> cG[MN];
*/
void vis(int v,int p){
	ord[v]=++cnt;
	S.push(v);
	inS[v]=true;
	roots.push(v);
	for(int u:G[v]){
		if(ord[u]==0){
			vis(u,v);
		}else if(u!=p&&inS[u]){
			while(ord[roots.top()]>ord[u]) roots.pop();
		}
	}
	if(v==roots.top()){
		bs.pb(P(p,v));
		vector<int> vc;
		while(true){
			int w=S.top();S.pop();
			inS[w]=false;
			vc.pb(w);
//			cmp[w]=cc.size();
			if(v==w) break;
		}
		roots.pop();
		cc.pb(vc);
	}
}
void bridge(int N){
	rep(i,N) if(ord[i]==0){
		vis(i,-1);
		bs.pop_back();	//P(-1,hoge)
	}
/*	for(P p:bs){
		int x=cmp[p.fs],y=cmp[p.sc];
		cG[x].pb(y),cG[y].pb(x);
	}*/
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

