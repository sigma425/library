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


# :warning: data structure/segtree/segtree_lazy.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ae8524dc43a549526bf4130058d83666">data structure/segtree</a>
* <a href="{{ site.github.repository_url }}/blob/master/data structure/segtree/segtree_lazy.cpp">View this file on GitHub</a>
    - Last commit date: 2019-09-09 20:50:34+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(int)N;i++)
#define show(x) cout << #x << " = " << x << endl
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
/*
遅延評価segtree
データの型 val_t と操作の型 opr_t がある
opr_t の結合律が必要

いろいろ柔軟に書き換えていく必要がありそう(ex.propagateで等差数列を足すときにopr_t型だと右側では初項がずれる,これにはl,rも必要)
それぞれ書くべきなのは、handler内の
 - val_tのdefと+
 - opr_tのdef
 - getfg (setg2fg)
 - act
 - 外側においてあるconst static e の実体

 あと、actにl,rを渡す必要があるとかそういったことで内側を書き換える(引数増やすだけ)

2018/07/11変更
	lazyかけるタイミングでvalも変更させちゃったほうが良さそうなので実装を変えた, unittestは通った
*/
template<class Handler>
struct segtree_lazy{
	using val_t = typename Handler::val_t;
	using opr_t = typename Handler::opr_t;
	int N;
	vector<val_t> val;
	vector<opr_t> lazy;
	segtree_lazy(){}
	segtree_lazy(int n){init(n);}
	segtree_lazy(const vector<val_t>& vc){init(vc);}
	void init(int n){
		N=1;
		while(N<n) N*=2;
		val .assign(N*2,val_t::e());
		lazy.assign(N*2,opr_t::e());
	}
	void init(const vector<val_t>& vc){
		int n = vc.size();
		N=1;
		while(N<n) N*=2;
		val .assign(N*2,val_t::e());
		rep(i,n) val[i+N] = vc[i];
		for(int i=N-1;i>0;i--) val[i] = val[i*2] + val[i*2+1];
		lazy.assign(N*2,opr_t::e());
	}

	val_t query(int a,int b,int l=0,int r=-1,int k=1){	//query_calc
		if(r==-1) r=N;
		if(b<=l||r<=a) return val_t::e();
		if(a<=l&&r<=b) return val[k];
		propagate(l,r,k);
		return query(a,b,l,(l+r)/2,k*2) + query(a,b,(l+r)/2,r,k*2+1);
	}
	void addlazy(int k,const opr_t &f){
		Handler::setg2fg(f,lazy[k]);
		val[k] = Handler::act(f,val[k]);
	}

	void update(int a,int b,const opr_t &f,int l=0,int r=-1,int k=1){	//query_update
		if(r==-1) r=N;
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b){
			addlazy(k,f);
			return;
		}
		propagate(l,r,k);
		update(a,b,f,l,(l+r)/2,k*2);
		update(a,b,f,(l+r)/2,r,k*2+1);
		val[k] = val[k*2] + val[k*2+1];
	}
	void propagate(int l,int r,int k){	//opr_child -> opr_parent * opr_child		parent after child
		addlazy(k*2  ,lazy[k]);
		addlazy(k*2+1,lazy[k]);
		lazy[k] = opr_t::e();
	}
};

struct handler1{
	/*
		range assign 0以上
		range max

		val_t = int,max			val[k]=max
		opr_t(x) : y -> x		lazy[k]=assign

		今回の場合opr_t::eはない(assignに単位元はない)
		このようなときは、適当な値を単位元に設定にしておき、getfg/setg2fg/ act!! で合成しないよう処理しておけば良い
		考えにくいけどval_tも同様.
		最悪option型みたいにbool値をもたせれば良さそう
	*/
	struct val_t{
		int x;
		val_t(){*this = e();}
		val_t(int x):x(x){}

		const static val_t e(){
			return val_t(0);
		}
		val_t operator+(const val_t &r) const {
			return val_t(max(x,r.x));
		}
		friend ostream& operator<<(ostream& o,const val_t& d){return o<<d.x;}
	};

	struct opr_t{
		int x;
		opr_t(){*this = e();}
		opr_t(int x):x(x){}

		const static opr_t e(){
			return opr_t(-1);
		}
		friend ostream& operator<<(ostream& o,const opr_t& d){return o<<d.x;}
	};

//	static opr_t getfg(const opr_t &f, const opr_t &g){
//
//	}
	/*
		もしコピーコストとかが気になって,しかも楽に書けるならsetg2fgを直接書く
		そうじゃないなら g = getfg(f,g)
	*/
	static void setg2fg(const opr_t &f, opr_t &g){	//g -> fg		f after g
		if(f.x != -1) g.x = f.x;
	}
	static val_t act(const opr_t &f, const val_t &v){		//maxがv っていう状態のところにfを作用させるとmaxは何になりますか?
		if(f.x == -1) return v;
		return val_t(f.x);
	}
};


struct handler2{
	/*
		range assign 0以上
		range sum

		val_t = int,+			val[k]= +
		opr_t(x) : y -> x		lazy[k]=assign

		assignは一緒なので、opr_t,getfgは変えなくていい
		気づいたんですが,actとかにl,rが必要なケースが多すぎる(sum系とかほぼ確実に必要)ので、もうこういうのはval_tにl,rを置くことにします
		と思ったが、やっぱりやめて、lとrを頑張ってactに渡すことにした
		getfgとかにも必要になると絶望感が増しそう

	*/
	struct val_t{
		int x;
		val_t(){*this = e();}
		val_t(int x):x(x){}

		const static val_t e(){
			return val_t(0);
		}
		val_t operator+(const val_t &r) const {
			return val_t(x+r.x);
		}
		friend ostream& operator<<(ostream& o,const val_t& d){return o<<d.x;}
	};

	struct opr_t{
		int x;
		opr_t(){*this = e();}
		opr_t(int x):x(x){}

		const static opr_t e(){
			return opr_t(-1);
		}
		friend ostream& operator<<(ostream& o,const opr_t& d){return o<<d.x;}
	};

	static void getfg(const opr_t &f, const opr_t &g){
		
	}
	/*
		もしコピーコストとかが気になって,しかも楽に書けるならsetg2fgを直接書く
		そうじゃないなら g = getfg(f,g)
	*/
	static void setg2fg(const opr_t &f, opr_t &g){	//g -> fg		f after g
		if(f.x != -1) g.x = f.x;
	}
	static val_t act(const opr_t &f, const val_t &v,int k,int l,int r){	//assign f.x -> sum = 
		if(f.x == -1) return v;
		return val_t(f.x*(r-l));
	}
};


struct handler3{
	using ll = long long;
	/*
		range assign
		range add
		point val

		val_t = int
		opr_t(x) : assign x or add y

		(assign x)(assign y) = (assign x)
		(assign x)(add y) = (assign x)
		(add x)(assign y) = (assign y+x)
		(add x)(add y) = (add x+y)
		(assign or add)が閉じているので、この形をopr_tとして持てば良い.
		区間getがないとかなり考えやすいなあ
		というか、val_t同士の演算がいらなくて、opr_tだけでできてるなこれ
		とはいえとりあえず用意してる(単位元との合成は行われる)ので、矛盾がないようにしないとまずい(ので+とe=0にした)
		verified at atcoder/dwango2015/qual/E_lazy.cpp 花火

	*/
	struct val_t{
		ll x;
		val_t(){*this = e();}
		val_t(ll x):x(x){}

		const static val_t e(){
			return val_t(0);
		}
		val_t operator+(const val_t &r) const {
			return val_t(x+r.x);
		}
		friend ostream& operator<<(ostream& o,const val_t& d){return o<<d.x;}
	};

	struct opr_t{
		bool is_add;
		ll x;
		opr_t(){*this = e();}
		opr_t(bool b,ll x):is_add(b),x(x){}

		const static opr_t e(){
			return opr_t(true,0);	//add 0
		}
		friend ostream& operator<<(ostream& o,const opr_t& d){return o<<(d.is_add?"add":"assign")<<" "<<d.x;}
	};

	static opr_t getfg(const opr_t &f, const opr_t &g){
		if(f.is_add){
			if(g.is_add) return opr_t(true,f.x+g.x);
			else return opr_t(false,f.x+g.x);
		}else{
			return f;
		}
	}
	static void setg2fg(const opr_t &f, opr_t &g){	//g -> fg		f after g
		g = getfg(f,g);
	}
	static val_t act(const opr_t &f, const val_t &v,int k,int l,int r){	//assign f.x -> sum = 
		if(f.is_add) return val_t(v+f.x);
		else return val_t(f.x);
	}
};

struct handler4{
	/*
		OpenCup/3192/E.cpp
		range add
		range max ただし、このクエリが投げられるまでの全ての時間の中でのmax

		val_t = その区間の、(今のmax,これまでのmax)	
		opr_t(l,m) = (今のlazy,これまでのlazyのmax)

		クエリをある一定の形でかけて、結合律が成り立つか?が重要
		今回はこの形で持つと合成できる
		とりあえず必要なものを持ち、結合できるように追加でデータを持つ

	*/
	using ll = long long;
	const static ll inf = 1e16;
	struct val_t{
		ll x,y;
		val_t(){*this = e();}
		val_t(ll x,ll y):x(x),y(y){}

		const static val_t e(){
			return val_t(-inf,-inf);
		}
		val_t operator+(const val_t &r) const {
			return val_t(max(x,r.x),max(y,r.y));
		}
//		friend ostream& operator<<(ostream& o,const val_t& d){return o<<"("<<d.x<<" "<<d.y<<")";}
	};

	struct opr_t{
		ll l,m;
		opr_t(){*this = e();}
		opr_t(ll l,ll m):l(l),m(m){}

		const static opr_t e(){
			return opr_t(0,-inf);
		}
//		friend ostream& operator<<(ostream& o,const opr_t& d){return o<<d.x;}
	};

	static opr_t getfg(const opr_t &f, const opr_t &g){
		return opr_t(f.l+g.l,max(g.m,f.m+g.l));
	}
	static void setg2fg(const opr_t &f, opr_t &g){	//g -> fg		f after g
		g = getfg(f,g);
	}
	static val_t act(const opr_t &f, const val_t &v,int k,int l,int r){	//assign f.x -> sum = 
		return val_t(v.x+f.l,max(v.y,v.x+f.m));
	}
};


struct handler5{
	/*
		verified at AOJ/RUPC/17/day2/I.cpp
		{0,1,2,..9} -> {0,1,2,..9}への写像が区間にかかる、質問は区間内のiの数
		写像だし、合成可能なのはあたりまえ。練習にちょうどよかった
		array使ったほうが速かったかもね
		
	*/
	struct val_t{
		int n[10];
		val_t(){*this = e();}
		val_t(vector<int> v){
//			show(v.size());
			rep(i,10) n[i]=v[i];
		}

		const static val_t e(){
			return val_t(vector<int>(10,0));
		}
		val_t operator+(const val_t &r) const {
			vector<int> v(10);
			rep(i,10) v[i] = n[i]+r.n[i];
			return val_t(v);
		}
	};
	struct opr_t{
		int f[10];
		opr_t(){*this = e();}
		opr_t(vector<int> v){
//			show(v.size());
			rep(i,10) f[i]=v[i];
		}
		const static opr_t e(){
			vector<int> vc(10);
			rep(i,10) vc[i]=i;
			return opr_t(vc);
		}
	};
	static opr_t getfg(const opr_t &f, const opr_t &g){
		vector<int> v(10);
		rep(i,10) v[i] = f.f[g.f[i]];
		return opr_t(v);
	}
	static void setg2fg(const opr_t &f, opr_t &g){
		g = getfg(f,g);
	}
	static val_t act(const opr_t &f, const val_t &v){
		vector<int> x(10);
		rep(i,10) x[f.f[i]]+=v.n[i];
		return val_t(x);
	}
};
/*
fortune_telling
AB
*/

void unittest(){
	{
		using val_t = handler1::val_t;
		using opr_t = handler1::opr_t;
		vector<val_t> st = {1,2,3,4,5,6,7,8,9,0};
		segtree_lazy<handler1> seg(st);
		int N = st.size();

		rep(qt,100){
			int l = rand()%N;
			int r = rand()%N + 1;
			int t = rand()%2;
			if(t==0){
				int x = rand()%10;
				seg.update(l,r,opr_t(x));

				for(int i = l;i<r;i++) st[i] = val_t(x);

			}else{
				val_t res;
				for(int i=l;i<r;i++) res = res + st[i];
				assert( seg.query(l,r).x == res.x );
			}
		}
	}
}


int main(){
	unittest();
	puts("OK");
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data structure/segtree/segtree_lazy.cpp"
#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(int)N;i++)
#define show(x) cout << #x << " = " << x << endl
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
/*
遅延評価segtree
データの型 val_t と操作の型 opr_t がある
opr_t の結合律が必要

いろいろ柔軟に書き換えていく必要がありそう(ex.propagateで等差数列を足すときにopr_t型だと右側では初項がずれる,これにはl,rも必要)
それぞれ書くべきなのは、handler内の
 - val_tのdefと+
 - opr_tのdef
 - getfg (setg2fg)
 - act
 - 外側においてあるconst static e の実体

 あと、actにl,rを渡す必要があるとかそういったことで内側を書き換える(引数増やすだけ)

2018/07/11変更
	lazyかけるタイミングでvalも変更させちゃったほうが良さそうなので実装を変えた, unittestは通った
*/
template<class Handler>
struct segtree_lazy{
	using val_t = typename Handler::val_t;
	using opr_t = typename Handler::opr_t;
	int N;
	vector<val_t> val;
	vector<opr_t> lazy;
	segtree_lazy(){}
	segtree_lazy(int n){init(n);}
	segtree_lazy(const vector<val_t>& vc){init(vc);}
	void init(int n){
		N=1;
		while(N<n) N*=2;
		val .assign(N*2,val_t::e());
		lazy.assign(N*2,opr_t::e());
	}
	void init(const vector<val_t>& vc){
		int n = vc.size();
		N=1;
		while(N<n) N*=2;
		val .assign(N*2,val_t::e());
		rep(i,n) val[i+N] = vc[i];
		for(int i=N-1;i>0;i--) val[i] = val[i*2] + val[i*2+1];
		lazy.assign(N*2,opr_t::e());
	}

	val_t query(int a,int b,int l=0,int r=-1,int k=1){	//query_calc
		if(r==-1) r=N;
		if(b<=l||r<=a) return val_t::e();
		if(a<=l&&r<=b) return val[k];
		propagate(l,r,k);
		return query(a,b,l,(l+r)/2,k*2) + query(a,b,(l+r)/2,r,k*2+1);
	}
	void addlazy(int k,const opr_t &f){
		Handler::setg2fg(f,lazy[k]);
		val[k] = Handler::act(f,val[k]);
	}

	void update(int a,int b,const opr_t &f,int l=0,int r=-1,int k=1){	//query_update
		if(r==-1) r=N;
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b){
			addlazy(k,f);
			return;
		}
		propagate(l,r,k);
		update(a,b,f,l,(l+r)/2,k*2);
		update(a,b,f,(l+r)/2,r,k*2+1);
		val[k] = val[k*2] + val[k*2+1];
	}
	void propagate(int l,int r,int k){	//opr_child -> opr_parent * opr_child		parent after child
		addlazy(k*2  ,lazy[k]);
		addlazy(k*2+1,lazy[k]);
		lazy[k] = opr_t::e();
	}
};

struct handler1{
	/*
		range assign 0以上
		range max

		val_t = int,max			val[k]=max
		opr_t(x) : y -> x		lazy[k]=assign

		今回の場合opr_t::eはない(assignに単位元はない)
		このようなときは、適当な値を単位元に設定にしておき、getfg/setg2fg/ act!! で合成しないよう処理しておけば良い
		考えにくいけどval_tも同様.
		最悪option型みたいにbool値をもたせれば良さそう
	*/
	struct val_t{
		int x;
		val_t(){*this = e();}
		val_t(int x):x(x){}

		const static val_t e(){
			return val_t(0);
		}
		val_t operator+(const val_t &r) const {
			return val_t(max(x,r.x));
		}
		friend ostream& operator<<(ostream& o,const val_t& d){return o<<d.x;}
	};

	struct opr_t{
		int x;
		opr_t(){*this = e();}
		opr_t(int x):x(x){}

		const static opr_t e(){
			return opr_t(-1);
		}
		friend ostream& operator<<(ostream& o,const opr_t& d){return o<<d.x;}
	};

//	static opr_t getfg(const opr_t &f, const opr_t &g){
//
//	}
	/*
		もしコピーコストとかが気になって,しかも楽に書けるならsetg2fgを直接書く
		そうじゃないなら g = getfg(f,g)
	*/
	static void setg2fg(const opr_t &f, opr_t &g){	//g -> fg		f after g
		if(f.x != -1) g.x = f.x;
	}
	static val_t act(const opr_t &f, const val_t &v){		//maxがv っていう状態のところにfを作用させるとmaxは何になりますか?
		if(f.x == -1) return v;
		return val_t(f.x);
	}
};


struct handler2{
	/*
		range assign 0以上
		range sum

		val_t = int,+			val[k]= +
		opr_t(x) : y -> x		lazy[k]=assign

		assignは一緒なので、opr_t,getfgは変えなくていい
		気づいたんですが,actとかにl,rが必要なケースが多すぎる(sum系とかほぼ確実に必要)ので、もうこういうのはval_tにl,rを置くことにします
		と思ったが、やっぱりやめて、lとrを頑張ってactに渡すことにした
		getfgとかにも必要になると絶望感が増しそう

	*/
	struct val_t{
		int x;
		val_t(){*this = e();}
		val_t(int x):x(x){}

		const static val_t e(){
			return val_t(0);
		}
		val_t operator+(const val_t &r) const {
			return val_t(x+r.x);
		}
		friend ostream& operator<<(ostream& o,const val_t& d){return o<<d.x;}
	};

	struct opr_t{
		int x;
		opr_t(){*this = e();}
		opr_t(int x):x(x){}

		const static opr_t e(){
			return opr_t(-1);
		}
		friend ostream& operator<<(ostream& o,const opr_t& d){return o<<d.x;}
	};

	static void getfg(const opr_t &f, const opr_t &g){
		
	}
	/*
		もしコピーコストとかが気になって,しかも楽に書けるならsetg2fgを直接書く
		そうじゃないなら g = getfg(f,g)
	*/
	static void setg2fg(const opr_t &f, opr_t &g){	//g -> fg		f after g
		if(f.x != -1) g.x = f.x;
	}
	static val_t act(const opr_t &f, const val_t &v,int k,int l,int r){	//assign f.x -> sum = 
		if(f.x == -1) return v;
		return val_t(f.x*(r-l));
	}
};


struct handler3{
	using ll = long long;
	/*
		range assign
		range add
		point val

		val_t = int
		opr_t(x) : assign x or add y

		(assign x)(assign y) = (assign x)
		(assign x)(add y) = (assign x)
		(add x)(assign y) = (assign y+x)
		(add x)(add y) = (add x+y)
		(assign or add)が閉じているので、この形をopr_tとして持てば良い.
		区間getがないとかなり考えやすいなあ
		というか、val_t同士の演算がいらなくて、opr_tだけでできてるなこれ
		とはいえとりあえず用意してる(単位元との合成は行われる)ので、矛盾がないようにしないとまずい(ので+とe=0にした)
		verified at atcoder/dwango2015/qual/E_lazy.cpp 花火

	*/
	struct val_t{
		ll x;
		val_t(){*this = e();}
		val_t(ll x):x(x){}

		const static val_t e(){
			return val_t(0);
		}
		val_t operator+(const val_t &r) const {
			return val_t(x+r.x);
		}
		friend ostream& operator<<(ostream& o,const val_t& d){return o<<d.x;}
	};

	struct opr_t{
		bool is_add;
		ll x;
		opr_t(){*this = e();}
		opr_t(bool b,ll x):is_add(b),x(x){}

		const static opr_t e(){
			return opr_t(true,0);	//add 0
		}
		friend ostream& operator<<(ostream& o,const opr_t& d){return o<<(d.is_add?"add":"assign")<<" "<<d.x;}
	};

	static opr_t getfg(const opr_t &f, const opr_t &g){
		if(f.is_add){
			if(g.is_add) return opr_t(true,f.x+g.x);
			else return opr_t(false,f.x+g.x);
		}else{
			return f;
		}
	}
	static void setg2fg(const opr_t &f, opr_t &g){	//g -> fg		f after g
		g = getfg(f,g);
	}
	static val_t act(const opr_t &f, const val_t &v,int k,int l,int r){	//assign f.x -> sum = 
		if(f.is_add) return val_t(v+f.x);
		else return val_t(f.x);
	}
};

struct handler4{
	/*
		OpenCup/3192/E.cpp
		range add
		range max ただし、このクエリが投げられるまでの全ての時間の中でのmax

		val_t = その区間の、(今のmax,これまでのmax)	
		opr_t(l,m) = (今のlazy,これまでのlazyのmax)

		クエリをある一定の形でかけて、結合律が成り立つか?が重要
		今回はこの形で持つと合成できる
		とりあえず必要なものを持ち、結合できるように追加でデータを持つ

	*/
	using ll = long long;
	const static ll inf = 1e16;
	struct val_t{
		ll x,y;
		val_t(){*this = e();}
		val_t(ll x,ll y):x(x),y(y){}

		const static val_t e(){
			return val_t(-inf,-inf);
		}
		val_t operator+(const val_t &r) const {
			return val_t(max(x,r.x),max(y,r.y));
		}
//		friend ostream& operator<<(ostream& o,const val_t& d){return o<<"("<<d.x<<" "<<d.y<<")";}
	};

	struct opr_t{
		ll l,m;
		opr_t(){*this = e();}
		opr_t(ll l,ll m):l(l),m(m){}

		const static opr_t e(){
			return opr_t(0,-inf);
		}
//		friend ostream& operator<<(ostream& o,const opr_t& d){return o<<d.x;}
	};

	static opr_t getfg(const opr_t &f, const opr_t &g){
		return opr_t(f.l+g.l,max(g.m,f.m+g.l));
	}
	static void setg2fg(const opr_t &f, opr_t &g){	//g -> fg		f after g
		g = getfg(f,g);
	}
	static val_t act(const opr_t &f, const val_t &v,int k,int l,int r){	//assign f.x -> sum = 
		return val_t(v.x+f.l,max(v.y,v.x+f.m));
	}
};


struct handler5{
	/*
		verified at AOJ/RUPC/17/day2/I.cpp
		{0,1,2,..9} -> {0,1,2,..9}への写像が区間にかかる、質問は区間内のiの数
		写像だし、合成可能なのはあたりまえ。練習にちょうどよかった
		array使ったほうが速かったかもね
		
	*/
	struct val_t{
		int n[10];
		val_t(){*this = e();}
		val_t(vector<int> v){
//			show(v.size());
			rep(i,10) n[i]=v[i];
		}

		const static val_t e(){
			return val_t(vector<int>(10,0));
		}
		val_t operator+(const val_t &r) const {
			vector<int> v(10);
			rep(i,10) v[i] = n[i]+r.n[i];
			return val_t(v);
		}
	};
	struct opr_t{
		int f[10];
		opr_t(){*this = e();}
		opr_t(vector<int> v){
//			show(v.size());
			rep(i,10) f[i]=v[i];
		}
		const static opr_t e(){
			vector<int> vc(10);
			rep(i,10) vc[i]=i;
			return opr_t(vc);
		}
	};
	static opr_t getfg(const opr_t &f, const opr_t &g){
		vector<int> v(10);
		rep(i,10) v[i] = f.f[g.f[i]];
		return opr_t(v);
	}
	static void setg2fg(const opr_t &f, opr_t &g){
		g = getfg(f,g);
	}
	static val_t act(const opr_t &f, const val_t &v){
		vector<int> x(10);
		rep(i,10) x[f.f[i]]+=v.n[i];
		return val_t(x);
	}
};
/*
fortune_telling
AB
*/

void unittest(){
	{
		using val_t = handler1::val_t;
		using opr_t = handler1::opr_t;
		vector<val_t> st = {1,2,3,4,5,6,7,8,9,0};
		segtree_lazy<handler1> seg(st);
		int N = st.size();

		rep(qt,100){
			int l = rand()%N;
			int r = rand()%N + 1;
			int t = rand()%2;
			if(t==0){
				int x = rand()%10;
				seg.update(l,r,opr_t(x));

				for(int i = l;i<r;i++) st[i] = val_t(x);

			}else{
				val_t res;
				for(int i=l;i<r;i++) res = res + st[i];
				assert( seg.query(l,r).x == res.x );
			}
		}
	}
}


int main(){
	unittest();
	puts("OK");
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

