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


# :heavy_check_mark: test_oj/beats/range_chmin_chmax_add_range_sum.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#da5752032400ace5c0bf7d28b0708d19">test_oj/beats</a>
* <a href="{{ site.github.repository_url }}/blob/master/test_oj/beats/range_chmin_chmax_add_range_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 23:25:43+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum">https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data structure/segtree/segbeats.cpp.html">data structure/segtree/segbeats.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	sz=1 (1敗)
	mx2,mn2 更新忘れ (1敗)
*/
#ifdef __clang__
#define IGNORE
#else
#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#endif

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
#define rep(i,n) for(int i=0;i<int(n);i++)
#define rep1(i,n) for(int i=1;i<=int(n);i++)
#define per(i,n) for(int i=int(n)-1;i>=0;i--)
#define per1(i,n) for(int i=int(n);i>0;i--)
#define all(c) c.begin(),c.end()
#define si(x) int(x.size())
#define pb emplace_back
#define fs first
#define sc second
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
template<class T,class U> void chmax(T& x, U y){if(x<y) x=y;}
template<class T,class U> void chmin(T& x, U y){if(y<x) x=y;}
template<class T> void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

#ifdef LOCAL
#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
void dmpr(ostream& os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ~ ";
	dmpr(os,args...);
}
#define shows(...) cerr << "LINE" << __LINE__ << " : ";dmpr(cerr,##__VA_ARGS__)
#define dump(x) cerr << "LINE" << __LINE__ << " : " << #x << " = {";  \
	for(auto v: x) cerr << v << ","; cerr << "}" << endl;
#else
#define show(x) void(0)
#define dump(x) void(0)
#define shows(...) void(0)
#endif

#include "../../data structure/segtree/segbeats.cpp"

struct D{
	static const ll inf = TEN(13);
	ll sz=0,mx=-inf,mx2=-inf,mxn=0,mn=inf,mn2=inf,mnn=0,lz=0,sm=0;
	D(){}
	D(ll v){sz=1,mx=v,mxn=1,mn=v,mnn=1,sm=v;}
	static D merge(D l,D r){
		D z;
		z.sz = l.sz+r.sz;
		{
			z.mx = max(l.mx,r.mx);
			if(z.mx == l.mx) z.mxn += l.mxn;
			if(z.mx == r.mx) z.mxn += r.mxn;
			for(ll v:{l.mx,l.mx2,r.mx,r.mx2}){
				if(z.mx != v) chmax(z.mx2,v);
			}
		}
		{
			z.mn = min(l.mn,r.mn);
			if(z.mn == l.mn) z.mnn += l.mnn;
			if(z.mn == r.mn) z.mnn += r.mnn;
			for(ll v:{l.mn,l.mn2,r.mn,r.mn2}){
				if(z.mn != v) chmin(z.mn2,v);
			}
		}
		z.sm = l.sm+r.sm;
		return z;
	}
	void push(D& x,D& y){
		ll oldmx = max(x.mx,y.mx);
		ll oldmn = min(x.mn,y.mn);
		rep(_,2){
			D& z = (_ == 0 ? x : y);
			if(z.mn == z.mx){			//1
				if(z.mx == oldmx){
					z.sm += (mx-z.mx)*z.sz;
					z.mn = z.mx = mx;
				}else if(z.mn == oldmn){
					z.sm += (mn-z.mn)*z.sz;
					z.mn = z.mx = mn;
				}else{
					z.sm += lz*z.sz;
					z.mn = z.mx = z.mn+lz;
				}
			}else{
				if(z.mx == oldmx){
					z.sm += (mx-z.mx)*z.mxn;
					z.mx = mx;
				}else{
					z.sm += lz*z.mxn;
					z.mx += lz;
				}
				if(z.mn == oldmn){
					z.sm += (mn-z.mn)*z.mnn;
					z.mn = mn;
				}else{
					z.sm += lz*z.mnn;
					z.mn += lz;
				}
				ll others = z.sz - z.mxn - z.mnn;
				if(others){				// 3
					z.sm += lz * others;
					z.mx2 += lz; z.mn2 += lz;
				}else{					// 2
					z.mn2 = z.mx;
					z.mx2 = z.mn;
				}
			}
			z.lz += lz;
		}
		lz = 0;
	}
	bool changemin(ll v){
		if(v >= mx) return true;
		if(v > mx2){	//mx -> v
			ll oldmx = mx;
			sm += mxn * (v-mx);
			mx = v;
			if(oldmx == mn) mn = v;
			if(oldmx == mn2) mn2 = v;
			return true;
		}
		return false;
	}
	bool changemax(ll v){
		if(v <= mn) return true;
		if(v < mn2){	//mn -> v
			ll oldmn = mn;
			sm += mnn * (v-mn);
			mn = v;
			if(oldmn == mx) mx = v;
			if(oldmn == mx2) mx2 = v;
			return true;
		}
		return false;
	}
	bool add(ll v){
		mx += v;
		if(mx2 != -inf) mx2 += v;
		mn += v;
		if(mn2 != inf) mn2 += v;
		sm += v * sz;
		lz += v;
		return true;
	}
	ll getsum(){
		return sm;
	}
};


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	int N,Q; cin >> N >> Q;
	V<ll> a(N); rep(i,N) cin >> a[i];
	segbeats<D> seg(a);
	while(Q--){
		int t; cin >> t;
		if(t == 0){
			int l,r; ll v; cin >> l >> r >> v;
			seg.ch(l,r,&D::changemin,v);
		}
		if(t == 1){
			int l,r; ll v; cin >> l >> r >> v;
			seg.ch(l,r,&D::changemax,v);
		}
		if(t == 2){
			int l,r; ll v; cin >> l >> r >> v;
			seg.ch(l,r,&D::add,v);
		}
		if(t == 3){
			int l,r; cin >> l >> r;
			cout << seg.get(l,r,&D::getsum,[&](ll x,ll y){return x+y;},0LL) << endl;
		}
		// if(false){
		// 	cout << "seg: ";
		// 	rep(i,N){
		// 		auto v = seg.getNode(i,i+1);
		// 		shows(v.sm,v.mn,v.mn2,v.mnn,"---",v.mx,v.mx2,v.mxn,v.lz);
		// 		cout << seg.get(i,i+1,&D::getsum,[&](ll x,ll y){return x+y;},0LL) << " ";
		// 	}
		// 	cout << endl;
		// }
	}
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test_oj/beats/range_chmin_chmax_add_range_sum.test.cpp"
/*
	sz=1 (1敗)
	mx2,mn2 更新忘れ (1敗)
*/
#ifdef __clang__
#define IGNORE
#else
#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#endif

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
#define rep(i,n) for(int i=0;i<int(n);i++)
#define rep1(i,n) for(int i=1;i<=int(n);i++)
#define per(i,n) for(int i=int(n)-1;i>=0;i--)
#define per1(i,n) for(int i=int(n);i>0;i--)
#define all(c) c.begin(),c.end()
#define si(x) int(x.size())
#define pb emplace_back
#define fs first
#define sc second
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
template<class T,class U> void chmax(T& x, U y){if(x<y) x=y;}
template<class T,class U> void chmin(T& x, U y){if(y<x) x=y;}
template<class T> void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

#ifdef LOCAL
#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
void dmpr(ostream& os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ~ ";
	dmpr(os,args...);
}
#define shows(...) cerr << "LINE" << __LINE__ << " : ";dmpr(cerr,##__VA_ARGS__)
#define dump(x) cerr << "LINE" << __LINE__ << " : " << #x << " = {";  \
	for(auto v: x) cerr << v << ","; cerr << "}" << endl;
#else
#define show(x) void(0)
#define dump(x) void(0)
#define shows(...) void(0)
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
#line 58 "test_oj/beats/range_chmin_chmax_add_range_sum.test.cpp"

struct D{
	static const ll inf = TEN(13);
	ll sz=0,mx=-inf,mx2=-inf,mxn=0,mn=inf,mn2=inf,mnn=0,lz=0,sm=0;
	D(){}
	D(ll v){sz=1,mx=v,mxn=1,mn=v,mnn=1,sm=v;}
	static D merge(D l,D r){
		D z;
		z.sz = l.sz+r.sz;
		{
			z.mx = max(l.mx,r.mx);
			if(z.mx == l.mx) z.mxn += l.mxn;
			if(z.mx == r.mx) z.mxn += r.mxn;
			for(ll v:{l.mx,l.mx2,r.mx,r.mx2}){
				if(z.mx != v) chmax(z.mx2,v);
			}
		}
		{
			z.mn = min(l.mn,r.mn);
			if(z.mn == l.mn) z.mnn += l.mnn;
			if(z.mn == r.mn) z.mnn += r.mnn;
			for(ll v:{l.mn,l.mn2,r.mn,r.mn2}){
				if(z.mn != v) chmin(z.mn2,v);
			}
		}
		z.sm = l.sm+r.sm;
		return z;
	}
	void push(D& x,D& y){
		ll oldmx = max(x.mx,y.mx);
		ll oldmn = min(x.mn,y.mn);
		rep(_,2){
			D& z = (_ == 0 ? x : y);
			if(z.mn == z.mx){			//1
				if(z.mx == oldmx){
					z.sm += (mx-z.mx)*z.sz;
					z.mn = z.mx = mx;
				}else if(z.mn == oldmn){
					z.sm += (mn-z.mn)*z.sz;
					z.mn = z.mx = mn;
				}else{
					z.sm += lz*z.sz;
					z.mn = z.mx = z.mn+lz;
				}
			}else{
				if(z.mx == oldmx){
					z.sm += (mx-z.mx)*z.mxn;
					z.mx = mx;
				}else{
					z.sm += lz*z.mxn;
					z.mx += lz;
				}
				if(z.mn == oldmn){
					z.sm += (mn-z.mn)*z.mnn;
					z.mn = mn;
				}else{
					z.sm += lz*z.mnn;
					z.mn += lz;
				}
				ll others = z.sz - z.mxn - z.mnn;
				if(others){				// 3
					z.sm += lz * others;
					z.mx2 += lz; z.mn2 += lz;
				}else{					// 2
					z.mn2 = z.mx;
					z.mx2 = z.mn;
				}
			}
			z.lz += lz;
		}
		lz = 0;
	}
	bool changemin(ll v){
		if(v >= mx) return true;
		if(v > mx2){	//mx -> v
			ll oldmx = mx;
			sm += mxn * (v-mx);
			mx = v;
			if(oldmx == mn) mn = v;
			if(oldmx == mn2) mn2 = v;
			return true;
		}
		return false;
	}
	bool changemax(ll v){
		if(v <= mn) return true;
		if(v < mn2){	//mn -> v
			ll oldmn = mn;
			sm += mnn * (v-mn);
			mn = v;
			if(oldmn == mx) mx = v;
			if(oldmn == mx2) mx2 = v;
			return true;
		}
		return false;
	}
	bool add(ll v){
		mx += v;
		if(mx2 != -inf) mx2 += v;
		mn += v;
		if(mn2 != inf) mn2 += v;
		sm += v * sz;
		lz += v;
		return true;
	}
	ll getsum(){
		return sm;
	}
};


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	int N,Q; cin >> N >> Q;
	V<ll> a(N); rep(i,N) cin >> a[i];
	segbeats<D> seg(a);
	while(Q--){
		int t; cin >> t;
		if(t == 0){
			int l,r; ll v; cin >> l >> r >> v;
			seg.ch(l,r,&D::changemin,v);
		}
		if(t == 1){
			int l,r; ll v; cin >> l >> r >> v;
			seg.ch(l,r,&D::changemax,v);
		}
		if(t == 2){
			int l,r; ll v; cin >> l >> r >> v;
			seg.ch(l,r,&D::add,v);
		}
		if(t == 3){
			int l,r; cin >> l >> r;
			cout << seg.get(l,r,&D::getsum,[&](ll x,ll y){return x+y;},0LL) << endl;
		}
		// if(false){
		// 	cout << "seg: ";
		// 	rep(i,N){
		// 		auto v = seg.getNode(i,i+1);
		// 		shows(v.sm,v.mn,v.mn2,v.mnn,"---",v.mx,v.mx2,v.mxn,v.lz);
		// 		cout << seg.get(i,i+1,&D::getsum,[&](ll x,ll y){return x+y;},0LL) << " ";
		// 	}
		// 	cout << endl;
		// }
	}
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

