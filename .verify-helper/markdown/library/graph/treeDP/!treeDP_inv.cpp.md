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


# :warning: graph/treeDP/!treeDP_inv.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#30966a17a4c6c7e53deee3e83490106f">graph/treeDP</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/treeDP/!treeDP_inv.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*

わかりにくいし,merge(左たち,右たち)に時間が掛かるなどの理由がない限りもう一方の方を使ったほうが良いと思う


全頂点を始点に(1頂点でがO(N)の)木DPをする O(N)
まず,childrenたちのマージの逆操作が無いとダメ 例えば mergeがただのsumとか
使う前に,Gに,逆辺同士が^1になるようにpushしておく
G[a].pb(P(b,I++)),G[b].pb(P(a,I++))

一般的にするために変更すべき部分は,
sum[v]=1			ここは初期化
add(sum[v],dfs)		2箇所とも同じ,mergeをかく
sum[v]*inv[v+1]		ここは子のmergeが終わった後に何か計算すべきことがあるならここにかく
sum[v]-mp[e^1]		ここはmergeの逆操作
荒削りだけど一応 SRM664d1m でverify

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
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N=1000000;
int I;
ll mp[MAX_N*2];
vector<P> G[MAX_N];		//to,id
ll sum[MAX_N];
P done[MAX_N];		//fs= -2:nothing yet , -1:all done , x>=0: only x left   sc=edgeid(v,done[v])
ll dfs(int v,int p,int e){		//v,p,edgeid(v,p)
	if(done[v].fs==-2){
		sum[v]=1;
		for(P q:G[v]) if(q.fs!=p) add(sum[v],dfs(q.fs,v,q.sc^1));
		done[v]=P(p,e);
		return mp[e]=sum[v]*inv[v+1]%mod;
	}else if(done[v].fs>=0){
		add(sum[v],dfs(done[v].fs,v,done[v].sc^1));
		done[v].fs=-1;
	}
	if(p==-1) return sum[v]*inv[v+1]%mod;
	else return mp[e]=((sum[v]-mp[e^1])*inv[v+1]%mod+mod)%mod;
}
int main(){
	rep(i,N) done[i]=P(-2,0);
	rep(i,N) dfs(i,-1,0);
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/treeDP/!treeDP_inv.cpp"
/*

わかりにくいし,merge(左たち,右たち)に時間が掛かるなどの理由がない限りもう一方の方を使ったほうが良いと思う


全頂点を始点に(1頂点でがO(N)の)木DPをする O(N)
まず,childrenたちのマージの逆操作が無いとダメ 例えば mergeがただのsumとか
使う前に,Gに,逆辺同士が^1になるようにpushしておく
G[a].pb(P(b,I++)),G[b].pb(P(a,I++))

一般的にするために変更すべき部分は,
sum[v]=1			ここは初期化
add(sum[v],dfs)		2箇所とも同じ,mergeをかく
sum[v]*inv[v+1]		ここは子のmergeが終わった後に何か計算すべきことがあるならここにかく
sum[v]-mp[e^1]		ここはmergeの逆操作
荒削りだけど一応 SRM664d1m でverify

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
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N=1000000;
int I;
ll mp[MAX_N*2];
vector<P> G[MAX_N];		//to,id
ll sum[MAX_N];
P done[MAX_N];		//fs= -2:nothing yet , -1:all done , x>=0: only x left   sc=edgeid(v,done[v])
ll dfs(int v,int p,int e){		//v,p,edgeid(v,p)
	if(done[v].fs==-2){
		sum[v]=1;
		for(P q:G[v]) if(q.fs!=p) add(sum[v],dfs(q.fs,v,q.sc^1));
		done[v]=P(p,e);
		return mp[e]=sum[v]*inv[v+1]%mod;
	}else if(done[v].fs>=0){
		add(sum[v],dfs(done[v].fs,v,done[v].sc^1));
		done[v].fs=-1;
	}
	if(p==-1) return sum[v]*inv[v+1]%mod;
	else return mp[e]=((sum[v]-mp[e^1])*inv[v+1]%mod+mod)%mod;
}
int main(){
	rep(i,N) done[i]=P(-2,0);
	rep(i,N) dfs(i,-1,0);
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

