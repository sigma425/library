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


# :warning: graph/treeDP/treeDP.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#30966a17a4c6c7e53deee3e83490106f">graph/treeDP</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/treeDP/treeDP.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-01 11:39:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*

全方位木DP.
Node の コンストラクタ, append_edge, +, finalize だけかけばいい. コンストラクタは子が0個の時どうしたいか考えるとわかりやすい?
pic.png参照

BidirectionalTreeDP<Node> treedp(G);
とすればよい
get(v)でvを根とするdpが、get(v,p)でvを根としてp方向を削った時のNodeが得られる

中でnormalizeよんでGが書き換わってることに注意
verified by http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=RitsCamp16Day1&pid=F

oldより使いやすいと思う.ただ、dataとsubdataを一緒くたにしたので、実は集合同士のmerge2と要素をひとつ追加するmergeで計算量が違う場合
oldを使ったほうが良さそう?でもそのときはoldでも遅いので気にしなくて良いね

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

namespace Normalize{
	template<class E>
	void dfs(vector<vector<E>>& G,vector<int>& ord, int v,int p=-1){
		ord.pb(v);
		int K = G[v].size();
		rep(i,K){
			if(G[v][i].to==p){
				rotate(G[v].begin()+i,G[v].begin()+i+1,G[v].end());
				K--;
				break;
			}
		}
		rep(i,K){
			dfs(G,ord,G[v][i].to,v);
		}
	}
	template<class E>
	vector<int> normalize_and_gettopord(vector<vector<E>>& G, int r=0){
		vector<int> ord;
		dfs(G,ord,r);
		return ord;
	}
}

/*
	Node + に可換は仮定しなくても大丈夫(足す順序は変えてない(ただしupを足す場所は適当なので注意))
*/
template<class N>
struct BidirectionalTreeDP{
	vector<N> dp;	//dp[v] <- u1,u2,... 			pを削ってvが根
	vector<N> up;	//up[v] <- v's brothers + pp 	vを削ってpが根
	vector<N> rp;	//dp[r] <- rを根とした時のこたえ

	vector<int> par;
	template<class E>
	BidirectionalTreeDP(vector<vector<E>>& G, int r=0){
		int V = G.size();
		dp.assign(V,N());
		up.assign(V,N());
		rp.assign(V,N());
		par.assign(V,0);

		vector<int> ord = Normalize::normalize_and_gettopord<E>(G,r);
		rep(t,V){
			int v = ord[t];
			if(v==r) par[v]=-1;
			else par[v]=G[v].back().to;
		}

		for(int t=V-1;t>=0;t--){	//dfs
			int v = ord[t];
			dp[v] = N();
			int K = G[v].size() - (v!=r);
			rep(i,K){
				const E& e = G[v][i];
				int u = e.to;
				dp[v] = dp[v] + dp[u].append_edge(v,e);
			}
			dp[v].finalize(v);
		}

		rep(t,V){					//ufs
			int v = ord[t];
			int K = G[v].size() - (v!=r);
			vector<N> ls(K+1),rs(K+1);
			rep(i,K){
				ls[i+1] = ls[i] + dp[G[v][i].to].append_edge(v,G[v][i]);
				rs[K-1-i] = dp[G[v][K-1-i].to].append_edge(v,G[v][K-1-i]) + rs[K-i];
			}
			rep(i,K){
				const E& e = G[v][i];
				int u = e.to;
				up[u] = ls[i] + rs[i+1];
				if(v!=r) up[u] = up[u] + up[v].append_edge(v,G[v].back());
				up[u].finalize(v);
			}
			rp[v] = ls[K];
			if(v!=r) rp[v] = rp[v] + up[v].append_edge(v,G[v].back());
			rp[v].finalize(v);
		}
	}

	N get(int v,int p=-1){	//pを削ってvが根
		if(p==-1) return rp[v];
		if(par[v]==p) return dp[v];
		return up[p];
	}
};

/*
	get(v,p) = (部分木の直径, 部分木のmax dist, 2nd max dist)
*/

struct Node{	//
	int dia;
	array<int,2> rd;
	Node(){
		dia=0;
		rd[0]=rd[1]=0;
	}

	/*
		根付き木→森
		e=(p -> this)を追加したものを返す
	*/
	template<class E>
	Node append_edge(int p,const E& e) const {
		Node n;
		n.rd[0] = rd[0] + e.dist;
		n.rd[1] = 0;
		n.dia = dia;
		return n;
	}
	Node operator+(const Node& r) const {
		Node n;
		vector<int> vc;
		rep(t,2) vc.pb(rd[t]),vc.pb(r.rd[t]);
		sort(all(vc),greater<int>());
		rep(t,2) n.rd[t]=vc[t];
		n.dia = max(dia,r.dia);
		return n;
	}
	void finalize(int r){
		chmax(dia,rd[0]+rd[1]);
	}
};

struct Edge{
	int to;
	int dist;
};

/*
	get(v,p) = vからのmax dist, 部分木v以下の葉の個数, 葉からの距離の総和
	"葉である" の判定のために finalize の引数にGを渡している

	http://ddcc2017-final.contest.atcoder.jp/tasks/ddcc2017_final_e
*/

struct Node{	//vから最も遠い頂点への距離
	int d;
	ll lnum;
	ll lsum;
	Node(){
		d=0;
		lnum=0;
		lsum=0;
	}

	/*
		根付き木→森
		e=(p -> this)を追加したものを返す
	*/
	template<class E>
	Node append_edge(int p,const E& e) const {
		Node n;
		n.d = d+1;
		n.lnum = lnum;
		n.lsum = lsum + lnum;
		return n;
	}
	Node operator+(const Node& r) const {
		Node n;
		n.d = max(d,r.d);
		n.lnum = lnum + r.lnum;
		n.lsum = lsum + r.lsum;
		return n;
	}
	template<class E>
	void finalize(int v,vector<vector<E>>& G){
		if(G[v].size() == 1) lnum++;
	}
};

struct Edge{
	int to;
};



int main(){
	int N;
	cin>>N;
	vector<vector<Edge>> G(N);
	rep(i,N-1){
		int x,y,d;
		cin>>x>>y>>d;
		G[x].pb({y,d});
		G[y].pb({x,d});
	}

	BidirectionalTreeDP<Node> treedp(G);
	rep(v,N){
		for(const Edge& e:G[v]){
			int u = e.to;
			printf("dia[%d] (par = %d)  = %d\n",v,u,treedp.get(v,u).dia);
		}
	}
	rep(v,N){
		printf("all[%d]=%d\n",v,treedp.get(v).dia);
	}
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/treeDP/treeDP.cpp"
/*

全方位木DP.
Node の コンストラクタ, append_edge, +, finalize だけかけばいい. コンストラクタは子が0個の時どうしたいか考えるとわかりやすい?
pic.png参照

BidirectionalTreeDP<Node> treedp(G);
とすればよい
get(v)でvを根とするdpが、get(v,p)でvを根としてp方向を削った時のNodeが得られる

中でnormalizeよんでGが書き換わってることに注意
verified by http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=RitsCamp16Day1&pid=F

oldより使いやすいと思う.ただ、dataとsubdataを一緒くたにしたので、実は集合同士のmerge2と要素をひとつ追加するmergeで計算量が違う場合
oldを使ったほうが良さそう?でもそのときはoldでも遅いので気にしなくて良いね

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

namespace Normalize{
	template<class E>
	void dfs(vector<vector<E>>& G,vector<int>& ord, int v,int p=-1){
		ord.pb(v);
		int K = G[v].size();
		rep(i,K){
			if(G[v][i].to==p){
				rotate(G[v].begin()+i,G[v].begin()+i+1,G[v].end());
				K--;
				break;
			}
		}
		rep(i,K){
			dfs(G,ord,G[v][i].to,v);
		}
	}
	template<class E>
	vector<int> normalize_and_gettopord(vector<vector<E>>& G, int r=0){
		vector<int> ord;
		dfs(G,ord,r);
		return ord;
	}
}

/*
	Node + に可換は仮定しなくても大丈夫(足す順序は変えてない(ただしupを足す場所は適当なので注意))
*/
template<class N>
struct BidirectionalTreeDP{
	vector<N> dp;	//dp[v] <- u1,u2,... 			pを削ってvが根
	vector<N> up;	//up[v] <- v's brothers + pp 	vを削ってpが根
	vector<N> rp;	//dp[r] <- rを根とした時のこたえ

	vector<int> par;
	template<class E>
	BidirectionalTreeDP(vector<vector<E>>& G, int r=0){
		int V = G.size();
		dp.assign(V,N());
		up.assign(V,N());
		rp.assign(V,N());
		par.assign(V,0);

		vector<int> ord = Normalize::normalize_and_gettopord<E>(G,r);
		rep(t,V){
			int v = ord[t];
			if(v==r) par[v]=-1;
			else par[v]=G[v].back().to;
		}

		for(int t=V-1;t>=0;t--){	//dfs
			int v = ord[t];
			dp[v] = N();
			int K = G[v].size() - (v!=r);
			rep(i,K){
				const E& e = G[v][i];
				int u = e.to;
				dp[v] = dp[v] + dp[u].append_edge(v,e);
			}
			dp[v].finalize(v);
		}

		rep(t,V){					//ufs
			int v = ord[t];
			int K = G[v].size() - (v!=r);
			vector<N> ls(K+1),rs(K+1);
			rep(i,K){
				ls[i+1] = ls[i] + dp[G[v][i].to].append_edge(v,G[v][i]);
				rs[K-1-i] = dp[G[v][K-1-i].to].append_edge(v,G[v][K-1-i]) + rs[K-i];
			}
			rep(i,K){
				const E& e = G[v][i];
				int u = e.to;
				up[u] = ls[i] + rs[i+1];
				if(v!=r) up[u] = up[u] + up[v].append_edge(v,G[v].back());
				up[u].finalize(v);
			}
			rp[v] = ls[K];
			if(v!=r) rp[v] = rp[v] + up[v].append_edge(v,G[v].back());
			rp[v].finalize(v);
		}
	}

	N get(int v,int p=-1){	//pを削ってvが根
		if(p==-1) return rp[v];
		if(par[v]==p) return dp[v];
		return up[p];
	}
};

/*
	get(v,p) = (部分木の直径, 部分木のmax dist, 2nd max dist)
*/

struct Node{	//
	int dia;
	array<int,2> rd;
	Node(){
		dia=0;
		rd[0]=rd[1]=0;
	}

	/*
		根付き木→森
		e=(p -> this)を追加したものを返す
	*/
	template<class E>
	Node append_edge(int p,const E& e) const {
		Node n;
		n.rd[0] = rd[0] + e.dist;
		n.rd[1] = 0;
		n.dia = dia;
		return n;
	}
	Node operator+(const Node& r) const {
		Node n;
		vector<int> vc;
		rep(t,2) vc.pb(rd[t]),vc.pb(r.rd[t]);
		sort(all(vc),greater<int>());
		rep(t,2) n.rd[t]=vc[t];
		n.dia = max(dia,r.dia);
		return n;
	}
	void finalize(int r){
		chmax(dia,rd[0]+rd[1]);
	}
};

struct Edge{
	int to;
	int dist;
};

/*
	get(v,p) = vからのmax dist, 部分木v以下の葉の個数, 葉からの距離の総和
	"葉である" の判定のために finalize の引数にGを渡している

	http://ddcc2017-final.contest.atcoder.jp/tasks/ddcc2017_final_e
*/

struct Node{	//vから最も遠い頂点への距離
	int d;
	ll lnum;
	ll lsum;
	Node(){
		d=0;
		lnum=0;
		lsum=0;
	}

	/*
		根付き木→森
		e=(p -> this)を追加したものを返す
	*/
	template<class E>
	Node append_edge(int p,const E& e) const {
		Node n;
		n.d = d+1;
		n.lnum = lnum;
		n.lsum = lsum + lnum;
		return n;
	}
	Node operator+(const Node& r) const {
		Node n;
		n.d = max(d,r.d);
		n.lnum = lnum + r.lnum;
		n.lsum = lsum + r.lsum;
		return n;
	}
	template<class E>
	void finalize(int v,vector<vector<E>>& G){
		if(G[v].size() == 1) lnum++;
	}
};

struct Edge{
	int to;
};



int main(){
	int N;
	cin>>N;
	vector<vector<Edge>> G(N);
	rep(i,N-1){
		int x,y,d;
		cin>>x>>y>>d;
		G[x].pb({y,d});
		G[y].pb({x,d});
	}

	BidirectionalTreeDP<Node> treedp(G);
	rep(v,N){
		for(const Edge& e:G[v]){
			int u = e.to;
			printf("dia[%d] (par = %d)  = %d\n",v,u,treedp.get(v,u).dia);
		}
	}
	rep(v,N){
		printf("all[%d]=%d\n",v,treedp.get(v).dia);
	}
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

