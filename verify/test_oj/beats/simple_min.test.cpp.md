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


# :heavy_check_mark: test_oj/beats/simple_min.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#da5752032400ace5c0bf7d28b0708d19">test_oj/beats</a>
* <a href="{{ site.github.repository_url }}/blob/master/test_oj/beats/simple_min.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 23:25:43+09:00


* see: <a href="https://judge.yosupo.jp/problem/staticrmq">https://judge.yosupo.jp/problem/staticrmq</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data structure/segtree/segbeats.cpp.html">data structure/segtree/segbeats.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifdef __clang__
#define IGNORE
#else
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#endif

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

#ifdef LOCAL
#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x) true
#endif

#include "../../data structure/segtree/segbeats.cpp"

struct D{
	static const int inf = 2e9;
	int mn=0;
	D(int v=inf){mn=v;}
	static D merge(D l,D r){
		return D(min(l.mn,r.mn));
	}
	void push(D& x,D& y){
	}
	int getmin(){
		return mn;
	}
};


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	int N,Q; cin >> N >> Q;
	V<int> a(N); rep(i,N) cin >> a[i];
	segbeats<D> seg(a);
	while(Q--){
		int l,r; cin >> l >> r;
		cout << seg.get(l,r,&D::getmin,[&](int x,int y){return min(x,y);},D::inf) << endl;
	}
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test_oj/beats/simple_min.test.cpp"
#ifdef __clang__
#define IGNORE
#else
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#endif

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

#ifdef LOCAL
#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x) true
#endif

#line 1 "data structure/segtree/segbeats.cpp"
/*
	simple,lazy,beats どれもこれで書ける

	コンストラクタ:
		segbeats(n)
		segbeats(vec) 型が違ってもキャストできればOK

	change クエリ:
		seg.ch(l,r,&D::set,x)

	get クエリ:
		seg.get(l,r,&D::getsum,[](ll x,ll y){return x+y;},0LL)
		型しっかりかかないと怒られるので注意

	findl クエリ:


	注意:
		point クエリも range と全く同じように書いていい、どうせ外から (i,i+1) でしか呼ばないなら関数が適用されるのもサイズ1のノードだけだから、好き勝手やっていい


	struct D{
		コンストラクタ:
			D() が単位元になる必要がある

		merge(l,r):
			l,rのlazy系はidだと仮定して良い
		
		push(x,y):
			this -> x
			this -> y
			this_lazy.clear()
			lazyをかけたタイミングでvalを正しい値に変える

		ch系:
			bool set(int x) とか
			early return していいなら true
			つまりbeatsじゃなければ全部true
		
		get系:
			取り出したい情報を取り出すだけ

		find系:
			このノード内にある → true
	}

	beats: https://yukicoder.me/submissions/386293
	findl: https://codeforces.com/contest/1037/submission/61831108
*/

template<class N>
struct segbeats{
	V<N> x;
	int s;

	segbeats(int n){
		s = 1;
		while(s<n) s *= 2;
		x.resize(s*2);
		for(int i=s-1;i>0;i--) upd(i);
	}
	template<class T>
	segbeats(const V<T>& a){
		int n = a.size();
		s = 1;
		while(s<n) s *= 2;
		x.resize(s*2);
		rep(i,n) x[s+i] = N(a[i]);
		for(int i=s-1;i>0;i--) upd(i);
	}

	template<class F,class... Args>
	void ch(int a,int b,F f,Args... args){
		ch_(a,b,0,s,1,f,args...);
	}

	template<class F,class G,class H>
	auto get(int a,int b,F f,G g,H h){
		return get_(a,b,0,s,1,f,g,h);
	}

	N getNode(int a,int b){
		return getNode_(a,b,0,s,1);
	}

	template<class F,class... Args>
	pair<int,N> findl(int a,int b,F f,Args&... args){
		return findl_(a,b,0,s,1,f,args...);
	}

	private:

	void push(int i){
		x[i].push(x[i*2],x[i*2+1]);
	}
	void upd(int i){
		x[i] = N::merge(x[i*2],x[i*2+1]);
	}

	template<class F,class... Args>
	void ch_(int a,int b,int l,int r,int i,F f,Args... args){
		if(b<=l || r<=a){
			return;
		}
		if(a<=l && r<=b && (x[i].*f)(args...)){    //f : put_tag, early_break
			return;
		}
		push(i);
		int m = (l+r)/2;
		ch_(a,b,l,m,i*2  ,f,args...);
		ch_(a,b,m,r,i*2+1,f,args...);
		upd(i);
	}
	template<class F,class G,class H>
	auto get_(int a,int b,int l,int r,int i,F f,G g,H h){
		if(b<=l || r<=a){
			return h;
		}
		if(a<=l && r<=b){
			return (x[i].*f)();
		}
		push(i);
		int m = (l+r)/2;
		return g(get_(a,b,l,m,i*2,f,g,h),get_(a,b,m,r,i*2+1,f,g,h));
	}
	N getNode_(int a,int b,int l,int r,int i){
		if(b<=l || r<=a){
			return N();
		}
		if(a<=l && r<=b){
			return x[i];
		}
		push(i);
		int m = (l+r)/2;
		return N::merge(getNode_(a,b,l,m,i*2),getNode_(a,b,m,r,i*2+1));
	}
	template<class F,class... Args>
	pair<int,N> findl_(int a,int b,int l,int r,int i,F f,Args&... args){
		if(b<=l || r<=a){
			return {b,N()};
		}
		if(a<=l && r<=b){
			if(!(x[i].*f)(args...)) return {b,N()};
			if(r-l == 1) return {l,x[i]};
		}
		push(i);
		int m = (l+r)/2;
		auto x = findl_(a,b,l,m,i*2,f,args...);
		if(x.fs < b) return x;
		return findl_(a,b,m,r,i*2+1,f,args...);
	}

	// template<class F,class... Args>
	// pair<int,N> findr_(int a,int b,int l,int r,int i,F f,Args&... args){
	// 	if(b<=l || r<=a){
	// 		return {a-1,N()};
	// 	}
	// 	if(a<=l && r<=b){
	// 		if(!(x[i].*f)(args...)) return {a-1,N()};
	// 		if(r-l == 1) return {l,x[i]};
	// 	}
	// 	push(i);
	// 	int m = (l+r)/2;
	// 	auto y = findr_(a,b,m,r,i*2+1,f,args...);
	// 	if(y.fs >= a) return y;
	// 	return findr_(a,b,l,m,i*2,f,args...);
	// }

};

/*
    yukicoder 880
    range x_i = a
    range x_i = gcd(x_i,a)
    range max
    range sum

struct D{
	int sz=1;
	ll sm=0,mx=-1;
	ll L=0;
	D(ll v=1){sm=mx=L=v;}
	static D merge(D l,D r){
		D z;
		z.sz = l.sz + r.sz;
		z.sm = l.sm + r.sm;
		z.mx = max(l.mx,r.mx);
		z.L = lcm(l.L,r.L);
		return z;
	}
	void push(D& x,D& y){
		if(mx * sz == sm){
			x.set(mx);
			y.set(mx);
		}
	}
	bool set(ll x){
		sm = x * sz;
		mx = L = x;
		return true;
	}
	bool gcd(ll x){
		if(x % L == 0) return true;	// break_condition
		if(mx * sz == sm){		// put_tag_condition
			set(__gcd(mx,x));
			return true;
		}
		return false;
	}
	ll getmax(){
		return mx;
	}
	ll getsum(){
		return sm;
	}
};


CF 1037 (Manthan 18) H
struct D{
	int x,y,z;	// min sa, min lcp, min sa+lcp
	D(int l=inf):x(inf),y(l),z(inf){}
	static D merge(D l,D r){
		D m;
		m.x = min(l.x,r.x);
		m.y = min(l.y,r.y);
		m.z = min({l.z,r.z,l.y+r.x});
		return m;
	}
	void push(D& x,D& y){
	}
	bool set(int v){
		x = v;
		return true;
	}
	bool find(int& mn, int r){
		if(z < r) return true;
		if(mn+x < r) return true;
		chmin(mn,y);
		return false;
	}
};

*/
#line 38 "test_oj/beats/simple_min.test.cpp"

struct D{
	static const int inf = 2e9;
	int mn=0;
	D(int v=inf){mn=v;}
	static D merge(D l,D r){
		return D(min(l.mn,r.mn));
	}
	void push(D& x,D& y){
	}
	int getmin(){
		return mn;
	}
};


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	int N,Q; cin >> N >> Q;
	V<int> a(N); rep(i,N) cin >> a[i];
	segbeats<D> seg(a);
	while(Q--){
		int l,r; cin >> l >> r;
		cout << seg.get(l,r,&D::getmin,[&](int x,int y){return min(x,y);},D::inf) << endl;
	}
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

