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


# :warning: DP/monge/ATC002C.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d960fa802d50288c7dd865c652257d89">DP/monge</a>
* <a href="{{ site.github.repository_url }}/blob/master/DP/monge/ATC002C.cpp">View this file on GitHub</a>
    - Last commit date: 2016-12-08 00:51:38+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// http://atc002.contest.atcoder.jp/tasks/atc002_c
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmax(x,y) x=max(x,y)
template<class S,class T> bool chmin(S& x,T y){
	if(x>y){x=y;return 1;}
	return 0;
}
using namespace std;

/*
刺身系
w:monge & monotone の時
dp[l][r]=min(dp[l][i]+dp[i+1][r])+w[l][r]
		l<=i<r

d=r-lが短い順に埋める
initialize
dp[i][i]=0

をO(N^2)で解く
*/
typedef long long ll;
typedef pair<ll,int> P;
const int MAX_N=3000;
ll a[MAX_N],asum[MAX_N+1];
ll cost(int l,int r){		//[l,r)
	return asum[r]-asum[l];
}
ll dp[MAX_N][MAX_N+1];
int ar[MAX_N][MAX_N+1];
ll inf=1e17;
ll monge(int N){
	rep(i,N) rep(j,N+1) dp[i][j]=inf;
	rep(i,N) dp[i][i+1]=cost(i,i+1),ar[i][i+1]=i;
	for(int d=2;d<=N;d++){
		rep(l,N+1-d){
			int r=l+d;
			int L=ar[l][r-1];
			int R=ar[l+1][r];
			for(int i=L;i<=R;i++){
				if(chmin(dp[l][r],dp[l][i]+dp[i][r])) ar[l][r]=i;
			}
			dp[l][r]+=cost(l,r);
		}
	}
	return dp[0][N];
}


int main(){
	int N;
	cin>>N;
	rep(i,N) cin>>a[i],asum[i+1]=asum[i]+a[i];
	cout<<monge(N)-asum[N]<<endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DP/monge/ATC002C.cpp"
// http://atc002.contest.atcoder.jp/tasks/atc002_c
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmax(x,y) x=max(x,y)
template<class S,class T> bool chmin(S& x,T y){
	if(x>y){x=y;return 1;}
	return 0;
}
using namespace std;

/*
刺身系
w:monge & monotone の時
dp[l][r]=min(dp[l][i]+dp[i+1][r])+w[l][r]
		l<=i<r

d=r-lが短い順に埋める
initialize
dp[i][i]=0

をO(N^2)で解く
*/
typedef long long ll;
typedef pair<ll,int> P;
const int MAX_N=3000;
ll a[MAX_N],asum[MAX_N+1];
ll cost(int l,int r){		//[l,r)
	return asum[r]-asum[l];
}
ll dp[MAX_N][MAX_N+1];
int ar[MAX_N][MAX_N+1];
ll inf=1e17;
ll monge(int N){
	rep(i,N) rep(j,N+1) dp[i][j]=inf;
	rep(i,N) dp[i][i+1]=cost(i,i+1),ar[i][i+1]=i;
	for(int d=2;d<=N;d++){
		rep(l,N+1-d){
			int r=l+d;
			int L=ar[l][r-1];
			int R=ar[l+1][r];
			for(int i=L;i<=R;i++){
				if(chmin(dp[l][r],dp[l][i]+dp[i][r])) ar[l][r]=i;
			}
			dp[l][r]+=cost(l,r);
		}
	}
	return dp[0][N];
}


int main(){
	int N;
	cin>>N;
	rep(i,N) cin>>a[i],asum[i+1]=asum[i]+a[i];
	cout<<monge(N)-asum[N]<<endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

