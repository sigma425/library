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


# :warning: graph/treeDP/treeDP_old.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#30966a17a4c6c7e53deee3e83490106f">graph/treeDP</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/treeDP/treeDP_old.cpp">View this file on GitHub</a>
    - Last commit date: 2017-04-11 17:24:41+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
Data dp[MN];
SubData init;
SubData merge(SubData val,Data v);
Data term(SubData val);
void dfs(int v,int p){
	for(int u:G[v]) if(u!=p) dfs(u,v);
	SubData val=init;
	for(int u:G[v]) if(u!=p) val=merge(val,dp[u]);
	dp[v]=term(val);
}
これをオーダーを変えずに全方向にする
mergeに順序が関係ない とかが必要(実はうまくやれば適切な順なら出来ると思う(ex.頂点id小さい順)けどそんなエグいのは出ないと思う)

merge2が計算量的に間に合わない場合は無理だと思う(例えば,knapsackで何か荷物を追加する はO(K)で出来ても,今のdpの状況 どうしを追加するのにはO(NK)かかる)
その場合は逆元で子を消すタイプのやつをやればよさそう(ls,rsがいらなくて,nottermedから子を一つ引く感じ)


How To Use
Gつくる

Data,SubData,init,merge,merge2を定義する(上の普通の木DPを参照)

Dataは答えだけじゃなくて,再帰的に計算するときに必要な値は保持する(ex.sizeとか)

merge2は,SubData同士の演算
Data=SubData,merge=merge2に出来ることも多そう?(ただの積とか)


calcDPをよぶ
DP[]を使う(dpではない!!!!)

debugのために元となるrootを変えられるようにしてある(初期化とかはいらない) calcDP(N,r)

verified by https://csacademy.com/contest/round-11/#task/connected-tree-subgraphs
AGC06 black radius

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

typedef long long ll;
ll mod=1e9+7;
void add(ll &x,ll y){
	x+=y;
	x%=mod;
}
ll extgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	ll g=extgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return g;
}
ll inv(ll a){
	ll x,y;
	extgcd(a,mod,x,y);
	if(x<0) x+=mod;
	return x;
}

typedef pair<ll,int> Data;
typedef pair<ll,int> SubData;

const int MN=100000;
ll f[MN+1],g[MN+1];

vector<int> G[MN];
Data dp[MN];			//0-rooted dp[v]=term(merge(dp[u1],dp[u2],...))
SubData dp_nottermed[MN];	//0-rooted merge(dp[u1],...)
Data up[MN];			//up[v]= 0-rootedでのvの親をpとして, v->p方向のdpの値 term(merge(up[p],dp[v's bro1],dp[v's bro1],...))
Data DP[MN];			//DP[v]: ans for v-rooted tree
vector<SubData> ls,rs;		//ls/rs[i] = 0-rootedで見てvのchildrenを左/右からi個mergeしたもの(各vで使い回す)
SubData init(1,0);
SubData merge(SubData val,Data v){
	return SubData(val.fs*v.fs%mod*g[v.sc]%mod,val.sc+v.sc);
}
SubData merge2(SubData x,SubData y){
	return SubData(x.fs*y.fs%mod,x.sc+y.sc);
}
Data term(SubData val){
	return Data(val.fs*f[val.sc]%mod,val.sc+1);
}
void dfs(int v,int p=-1){
	SubData val=init;
	for(int u:G[v]) if(u!=p){
		dfs(u,v);
		val=merge(val,dp[u]);
	}
	dp_nottermed[v]=val;
	dp[v]=term(val);
//	cout<<"dp["<<v<<"]="<<dp[v]<<endl;
}
void ufs(int v,int p=-1){		//0-rootedでupwardな部分を計算
	vector<int> ch;	//children
	for(int u:G[v]) if(u!=p) ch.pb(u);
	int K=ch.size();
	ls.resize(K+1);
	rs.resize(K+1);
	ls[0]=init;
	rs[0]=init;
	rep(i,K){
		ls[i+1]=merge(ls[i],dp[ch[i]]);
		rs[i+1]=merge(rs[i],dp[ch[K-1-i]]);
	}
//	if(p==-1) rep1(i,K) show(ls[i]),show(rs[i]);
	rep(i,K){
		int u=ch[i];
		SubData val=merge2(ls[i],rs[K-1-i]);
		if(p>=0) val=merge(val,up[v]);
		up[u]=term(val);
//		cout<<"up["<<u<<"]="<<up[u]<<endl;
	}
	rep(i,K) ufs(ch[i],v);
}
void calcDP(int N,int r=0){
	dfs(r);
//	up[r]=e			//Dataの単位元(≠init)が必要で面倒なので回避
	ufs(r);
	rep(v,N){
		SubData val=dp_nottermed[v];
		if(v!=r) val=merge(val,up[v]);
		DP[v]=term(val);
	}
}
int main(){
	int N;
	cin>>N;
	f[0]=1;
	rep1(i,N) f[i]=f[i-1]*i%mod;
	rep(i,N+1) g[i]=inv(f[i]);
	rep(i,N-1){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		G[x].pb(y);G[y].pb(x);
	}
	calcDP(N);
	ll ans=0;
	rep(i,N) add(ans,DP[i].fs);
	cout<<ans<<endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/treeDP/treeDP_old.cpp"
/*
Data dp[MN];
SubData init;
SubData merge(SubData val,Data v);
Data term(SubData val);
void dfs(int v,int p){
	for(int u:G[v]) if(u!=p) dfs(u,v);
	SubData val=init;
	for(int u:G[v]) if(u!=p) val=merge(val,dp[u]);
	dp[v]=term(val);
}
これをオーダーを変えずに全方向にする
mergeに順序が関係ない とかが必要(実はうまくやれば適切な順なら出来ると思う(ex.頂点id小さい順)けどそんなエグいのは出ないと思う)

merge2が計算量的に間に合わない場合は無理だと思う(例えば,knapsackで何か荷物を追加する はO(K)で出来ても,今のdpの状況 どうしを追加するのにはO(NK)かかる)
その場合は逆元で子を消すタイプのやつをやればよさそう(ls,rsがいらなくて,nottermedから子を一つ引く感じ)


How To Use
Gつくる

Data,SubData,init,merge,merge2を定義する(上の普通の木DPを参照)

Dataは答えだけじゃなくて,再帰的に計算するときに必要な値は保持する(ex.sizeとか)

merge2は,SubData同士の演算
Data=SubData,merge=merge2に出来ることも多そう?(ただの積とか)


calcDPをよぶ
DP[]を使う(dpではない!!!!)

debugのために元となるrootを変えられるようにしてある(初期化とかはいらない) calcDP(N,r)

verified by https://csacademy.com/contest/round-11/#task/connected-tree-subgraphs
AGC06 black radius

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

typedef long long ll;
ll mod=1e9+7;
void add(ll &x,ll y){
	x+=y;
	x%=mod;
}
ll extgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	ll g=extgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return g;
}
ll inv(ll a){
	ll x,y;
	extgcd(a,mod,x,y);
	if(x<0) x+=mod;
	return x;
}

typedef pair<ll,int> Data;
typedef pair<ll,int> SubData;

const int MN=100000;
ll f[MN+1],g[MN+1];

vector<int> G[MN];
Data dp[MN];			//0-rooted dp[v]=term(merge(dp[u1],dp[u2],...))
SubData dp_nottermed[MN];	//0-rooted merge(dp[u1],...)
Data up[MN];			//up[v]= 0-rootedでのvの親をpとして, v->p方向のdpの値 term(merge(up[p],dp[v's bro1],dp[v's bro1],...))
Data DP[MN];			//DP[v]: ans for v-rooted tree
vector<SubData> ls,rs;		//ls/rs[i] = 0-rootedで見てvのchildrenを左/右からi個mergeしたもの(各vで使い回す)
SubData init(1,0);
SubData merge(SubData val,Data v){
	return SubData(val.fs*v.fs%mod*g[v.sc]%mod,val.sc+v.sc);
}
SubData merge2(SubData x,SubData y){
	return SubData(x.fs*y.fs%mod,x.sc+y.sc);
}
Data term(SubData val){
	return Data(val.fs*f[val.sc]%mod,val.sc+1);
}
void dfs(int v,int p=-1){
	SubData val=init;
	for(int u:G[v]) if(u!=p){
		dfs(u,v);
		val=merge(val,dp[u]);
	}
	dp_nottermed[v]=val;
	dp[v]=term(val);
//	cout<<"dp["<<v<<"]="<<dp[v]<<endl;
}
void ufs(int v,int p=-1){		//0-rootedでupwardな部分を計算
	vector<int> ch;	//children
	for(int u:G[v]) if(u!=p) ch.pb(u);
	int K=ch.size();
	ls.resize(K+1);
	rs.resize(K+1);
	ls[0]=init;
	rs[0]=init;
	rep(i,K){
		ls[i+1]=merge(ls[i],dp[ch[i]]);
		rs[i+1]=merge(rs[i],dp[ch[K-1-i]]);
	}
//	if(p==-1) rep1(i,K) show(ls[i]),show(rs[i]);
	rep(i,K){
		int u=ch[i];
		SubData val=merge2(ls[i],rs[K-1-i]);
		if(p>=0) val=merge(val,up[v]);
		up[u]=term(val);
//		cout<<"up["<<u<<"]="<<up[u]<<endl;
	}
	rep(i,K) ufs(ch[i],v);
}
void calcDP(int N,int r=0){
	dfs(r);
//	up[r]=e			//Dataの単位元(≠init)が必要で面倒なので回避
	ufs(r);
	rep(v,N){
		SubData val=dp_nottermed[v];
		if(v!=r) val=merge(val,up[v]);
		DP[v]=term(val);
	}
}
int main(){
	int N;
	cin>>N;
	f[0]=1;
	rep1(i,N) f[i]=f[i-1]*i%mod;
	rep(i,N+1) g[i]=inv(f[i]);
	rep(i,N-1){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		G[x].pb(y);G[y].pb(x);
	}
	calcDP(N);
	ll ans=0;
	rep(i,N) add(ans,DP[i].fs);
	cout<<ans<<endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

