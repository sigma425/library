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


# :warning: DP/Helvetic_O.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e2fca8135c2fadca093abd79a6b1c0d2">DP</a>
* <a href="{{ site.github.repository_url }}/blob/master/DP/Helvetic_O.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
N個の列をK個の連続列に分解する場合,愚直DPだとO(N^2K)になる
CHTとかを使って貰うDPの遷移をO(NK)にできる

区間K個に分割する時,「K個」の条件をなくした後, 各区間のコストに + c して解く
求めたいものがKに関して凸なら、+cをにぶたんしてちょうどK個になるところを答えとする
*/

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
typedef long long ll;
int N,K;
const int MN = 500000;
ll a[MN],b[MN];
ll ans;
int agmn(ll off){
	priority_queue<ll> usea;
	priority_queue<ll,vector<ll>,greater<ll>> leftb;
	ll sum = 0;
	for(int i=N-1;i>=0;i--){
		leftb.push(b[i]);
		ll X = 0;	//dont use
		ll Y = a[i]-off + leftb.top();	//make pair
		ll Z = usea.empty() ? 1e10 : a[i]-usea.top();	//reconnect
		if(X<=Y&&X<=Z){
			sum+=X;
		}else if(Y<=X&&Y<=Z){
			sum+=Y;
			usea.push(a[i]);
			leftb.pop();
		}else{
			sum+=Z;
			usea.pop();
			usea.push(a[i]);
		}
	}
	int agmn = usea.size();
	if(agmn<=K){
		ans = sum + off*agmn;
	}
	return agmn;
}
int main(){
	cin>>N>>K;
	rep(i,N) cin>>a[i];
	rep(i,N) cin>>b[i];
	ll ub = 2e9, lb = 0;
	while(ub-lb>1){
		ll m = (ub+lb)/2;
		if(agmn(m)<=K) lb = m;
		else ub = m;
	}
	cout<<ans<<endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DP/Helvetic_O.cpp"
/*
N個の列をK個の連続列に分解する場合,愚直DPだとO(N^2K)になる
CHTとかを使って貰うDPの遷移をO(NK)にできる

区間K個に分割する時,「K個」の条件をなくした後, 各区間のコストに + c して解く
求めたいものがKに関して凸なら、+cをにぶたんしてちょうどK個になるところを答えとする
*/

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
typedef long long ll;
int N,K;
const int MN = 500000;
ll a[MN],b[MN];
ll ans;
int agmn(ll off){
	priority_queue<ll> usea;
	priority_queue<ll,vector<ll>,greater<ll>> leftb;
	ll sum = 0;
	for(int i=N-1;i>=0;i--){
		leftb.push(b[i]);
		ll X = 0;	//dont use
		ll Y = a[i]-off + leftb.top();	//make pair
		ll Z = usea.empty() ? 1e10 : a[i]-usea.top();	//reconnect
		if(X<=Y&&X<=Z){
			sum+=X;
		}else if(Y<=X&&Y<=Z){
			sum+=Y;
			usea.push(a[i]);
			leftb.pop();
		}else{
			sum+=Z;
			usea.pop();
			usea.push(a[i]);
		}
	}
	int agmn = usea.size();
	if(agmn<=K){
		ans = sum + off*agmn;
	}
	return agmn;
}
int main(){
	cin>>N>>K;
	rep(i,N) cin>>a[i];
	rep(i,N) cin>>b[i];
	ll ub = 2e9, lb = 0;
	while(ub-lb>1){
		ll m = (ub+lb)/2;
		if(agmn(m)<=K) lb = m;
		else ub = m;
	}
	cout<<ans<<endl;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

