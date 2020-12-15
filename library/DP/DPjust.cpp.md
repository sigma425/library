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


# :warning: DP/DPjust.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e2fca8135c2fadca093abd79a6b1c0d2">DP</a>
* <a href="{{ site.github.repository_url }}/blob/master/DP/DPjust.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
N個中K個選んでできるものの和を列挙(総和をSとする)
O(NS)
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
const int MAX_N=600,MAX_S=100000,inf=1e9;
int N,K,a[MAX_N];
int dp0[MAX_N][MAX_S+1];
int dp1[MAX_N][MAX_S+1];
int main(){
	cin>>N>>K;
	rep(i,N) cin>>a[i];
	int S=accumulate(a,a+N,0);
	for(int j=K;j<=N;j++) rep(s,S+1) dp0[j][s]=dp1[j][s]=inf;
	dp0[K][accumulate(a,a+K,0)]=0;
	for(int j=K;j<=N;j++){
		rep(s,S+1){
			if(dp1[j][s]==inf) continue;
			chmin(dp1[j+1][s],dp1[j][s]);
			int l=dp1[j][s],r=K;
			if(j>K) chmin(r,dp1[j-1][s]);
			for(int i=l;i<r;i++) chmin(dp0[j][s-a[i]],i+1);
		}
		rep(s,S+1){
			if(dp0[j][s]==inf) continue;
			chmin(dp0[j+1][s],dp0[j][s]);
			chmin(dp1[j+1][s+a[j]],dp0[j][s]);
		}
	}
	rep(s,S+1) if(dp0[N][s]!=inf) cout<<s<<" ";
	puts("");
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DP/DPjust.cpp"
/*
N個中K個選んでできるものの和を列挙(総和をSとする)
O(NS)
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
const int MAX_N=600,MAX_S=100000,inf=1e9;
int N,K,a[MAX_N];
int dp0[MAX_N][MAX_S+1];
int dp1[MAX_N][MAX_S+1];
int main(){
	cin>>N>>K;
	rep(i,N) cin>>a[i];
	int S=accumulate(a,a+N,0);
	for(int j=K;j<=N;j++) rep(s,S+1) dp0[j][s]=dp1[j][s]=inf;
	dp0[K][accumulate(a,a+K,0)]=0;
	for(int j=K;j<=N;j++){
		rep(s,S+1){
			if(dp1[j][s]==inf) continue;
			chmin(dp1[j+1][s],dp1[j][s]);
			int l=dp1[j][s],r=K;
			if(j>K) chmin(r,dp1[j-1][s]);
			for(int i=l;i<r;i++) chmin(dp0[j][s-a[i]],i+1);
		}
		rep(s,S+1){
			if(dp0[j][s]==inf) continue;
			chmin(dp0[j+1][s],dp0[j][s]);
			chmin(dp1[j+1][s+a[j]],dp0[j][s]);
		}
	}
	rep(s,S+1) if(dp0[N][s]!=inf) cout<<s<<" ";
	puts("");
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

