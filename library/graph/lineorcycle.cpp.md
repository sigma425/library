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
    - Last commit date: 2017-05-02 16:58:27+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
無向グラフで高々次数が2のもの はlineとcycleにわけられる.これをdfsして全部見つける
自己ループ,多重辺もちゃんとcycleで感知できる.
普通,孤立点の場合でもcalclineに投げれば良さそう.
line,cycleをなす頂点集合をまともな順で(lineは端から)vectorにいれたものをcalcline,cycleに投げている.
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
const int MN=100;
int N,M;
vector<int> G[MN];
bool used[MN];

void calcline(vector<int> vs){
	printf("line  :");
	for(int v:vs) cout<<v<<" ";
	puts("");
}
void calccycle(vector<int> vs){
	printf("cycle :");
	for(int v:vs) cout<<v<<" ";
	puts("");
}
void solve(){
	rep(i,N) if(!used[i]){
		int v=i;
		assert(G[v].size()<=2);
		int p=G[v][0];
		while(G[v].size()==2){
			int nv=G[v][0]^G[v][1]^p;
			p=v;
			v=nv;
			if(v==i) break;
		}
		if(G[v].size()==0){			//isolated point
			//?
		}else if(G[v].size()==1){	//line
			vector<int> vs;
			vs.pb(v);used[v]=1;
			int p=v;
			v=G[v][0];
			while(G[v].size()==2){
				vs.pb(v);used[v]=1;
				int nv=G[v][0]^G[v][1]^p;
				p=v;
				v=nv;
			}
			vs.pb(v);used[v]=1;
			calcline(vs);
		}else{
			vector<int> vs;
			int p=G[v][0];
			while(!used[v]){
				vs.pb(v);used[v]=1;
				int nv=G[v][0]^G[v][1]^p;
				p=v;
				v=nv;
			}
			calccycle(vs);
		}
	}
}
int main(){
	cin>>N>>M;
	rep(i,M){
		int x,y;
		cin>>x>>y;
		G[x].pb(y);
		G[y].pb(x);
	}
	solve();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/lineorcycle.cpp"
/*
無向グラフで高々次数が2のもの はlineとcycleにわけられる.これをdfsして全部見つける
自己ループ,多重辺もちゃんとcycleで感知できる.
普通,孤立点の場合でもcalclineに投げれば良さそう.
line,cycleをなす頂点集合をまともな順で(lineは端から)vectorにいれたものをcalcline,cycleに投げている.
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
const int MN=100;
int N,M;
vector<int> G[MN];
bool used[MN];

void calcline(vector<int> vs){
	printf("line  :");
	for(int v:vs) cout<<v<<" ";
	puts("");
}
void calccycle(vector<int> vs){
	printf("cycle :");
	for(int v:vs) cout<<v<<" ";
	puts("");
}
void solve(){
	rep(i,N) if(!used[i]){
		int v=i;
		assert(G[v].size()<=2);
		int p=G[v][0];
		while(G[v].size()==2){
			int nv=G[v][0]^G[v][1]^p;
			p=v;
			v=nv;
			if(v==i) break;
		}
		if(G[v].size()==0){			//isolated point
			//?
		}else if(G[v].size()==1){	//line
			vector<int> vs;
			vs.pb(v);used[v]=1;
			int p=v;
			v=G[v][0];
			while(G[v].size()==2){
				vs.pb(v);used[v]=1;
				int nv=G[v][0]^G[v][1]^p;
				p=v;
				v=nv;
			}
			vs.pb(v);used[v]=1;
			calcline(vs);
		}else{
			vector<int> vs;
			int p=G[v][0];
			while(!used[v]){
				vs.pb(v);used[v]=1;
				int nv=G[v][0]^G[v][1]^p;
				p=v;
				v=nv;
			}
			calccycle(vs);
		}
	}
}
int main(){
	cin>>N>>M;
	rep(i,M){
		int x,y;
		cin>>x>>y;
		G[x].pb(y);
		G[y].pb(x);
	}
	solve();
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

