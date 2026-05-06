/*
	segtree beats
	気持ち的には lazy segtree のように モノイド X と 作用モノイド A を持っているが、様々な理由から実装はそうなっていない
	https://www.notion.so/segtree-beats-1f4178eea61c8049a8cfcb1a688fdd70 参照
	X 的要素を val, A 的要素を laz と呼ぶ

	乗せる struct N は次の条件を満たす必要がある
		- N() が単位元(val, laz ともに)を返す
		- static N merge(N l, N r) は、{l.val + r.val, A::id()} を返す
			l.laz とかが id であるとは限らないが、無視しなければいけないことに注意
			例えば、if(l.val == X::e()) return r; は駄目 (res.laz = r.laz が残ってしまっている)
		- void push(N& x, N& y)
			this の laz を 子ノード x, y に push する
			laz -> x
			laz -> y
			laz = A::id()
			この laz -> x は、(lazyseg でいう) X apply(A,X) と A composite(A,A) を両方行う必要がある
		- ch に乗せるやつ
			bool set(int x) とか
			区間への作用に成功したら true を返す
			false を返すときは何もしない
		- get に乗せるやつ
			ll getsum(){ return sm; } とか
			これ(F)で N から必要な情報を取り出し、G で accumulate して、H は G の単位元、というふうに呼ぶ
		- find に乗せるやつ
			区間にあるなら true を返す

	segbeats 自体の使い方
		- change:
			seg.ch(l, r, &N::set, xとか)
		- get:
			seg.get(l, r, &N::getsum, [](ll x,ll y){return x+y;}, 0LL)
		- findl:
			seg.findl(l, r, &N::find, xとか)

		- set_point(int i, N v)
			一点更新
		- N get_point(int i)
			N の一点取得
		- N get_range(int l, int r)
			merge(x[l], ..., x[r-1]) を返す
		
		- debug()
			全ノードそのまま出力 つまり get_point(i) の列を返しているわけではない
			N に operator<< が必要

	beats: https://yukicoder.me/submissions/386293
	findl: https://codeforces.com/contest/1037/submission/61831108
*/

template<class N>
struct segbeats{
	vector<N> x;
	int n, log, s;

	segbeats() {}
	segbeats(int n_): n(n_){
		log = 0; while((1 << log) < n) log++;
		s = 1 << log;
		x.resize(s*2);
	}
	template<class Nlike>
	segbeats(const vector<Nlike>& v): n(v.size()){
		log = 0; while((1 << log) < n) log++;
		s = 1 << log;
		x.resize(s*2);
		rep(i,n) x[s+i] = N(v[i]);
		per1(i,s-1) upd(i);
	}

	template<class F, class... Args>
	void ch(int l, int r, F f, Args... args){
		ch_(l,r,0,s,1,f,args...);
	}

	template<class F, class G, class H>
	auto get(int l, int r, F f, G g, H h){
		return get_(l,r,0,s,1,f,g,h);
	}

	N get_range(int l, int r){
		return get_range_(l,r,0,s,1);
	}
	N get_point(int i){
		assert(0 <= i && i < n);
		i += s;
		per1(h,log) push(i >> h);
		return x[i];
	}
	void set_point(int i, N v){
		assert(0 <= i && i < n);
		i += s;
		per1(h,log) push(i >> h);
		x[i] = v;
		rep1(h,log) upd(i >> h);
	}

	template<class F,class... Args>
	pair<int,N> findl(int l, int r, F f, Args&... args){
		return findl_(l,r,0,s,1,f,args...);
	}

	void debug(){
		cerr << "-------- segbeats debug --------" << endl;
		rep1(k,s*2-1){
			cerr << k << ": " << x[k] << endl;
		}
		cerr << "-------- debug end --------" << endl;
	}

	private:

	void push(int k){
		x[k].push(x[k*2], x[k*2+1]);
	}
	void upd(int k){
		x[k] = N::merge(x[k*2], x[k*2+1]);
	}

	template<class F, class... Args>
	void ch_(int a, int b, int l, int r, int k, F f, Args... args){
		if(b<=l || r<=a) return;
		if(a<=l && r<=b && (x[k].*f)(args...)) return;
		push(k);
		int m = (l+r)/2;
		ch_(a,b,l,m,k*2  ,f,args...);
		ch_(a,b,m,r,k*2+1,f,args...);
		upd(k);
	}
	template<class F, class G, class H>
	auto get_(int a, int b, int l, int r, int k, F f, G g, H h){
		if(b<=l || r<=a) return h;
		if(a<=l && r<=b) return (x[k].*f)();
		push(k);
		int m = (l+r)/2;
		return g(get_(a,b,l,m,k*2,f,g,h), get_(a,b,m,r,k*2+1,f,g,h));
	}
	N get_range_(int a, int b, int l, int r, int k){
		if(b<=l || r<=a) return N();
		if(a<=l && r<=b) return x[k];
		push(k);
		int m = (l+r)/2;
		return N::merge(get_range_(a,b,l,m,k*2), get_range_(a,b,m,r,k*2+1));
	}
	template<class F, class... Args>
	pair<int,N> findl_(int a, int b, int l, int r, int k, F f, Args&... args){
		if(b<=l || r<=a){
			return {b, N()};
		}
		if(a<=l && r<=b){
			if(!(x[k].*f)(args...)) return {b, N()};
			if(r-l == 1) return {l, x[k]};
		}
		push(k);
		int m = (l+r)/2;
		auto res = findl_(a,b,l,m,k*2,f,args...);
		if(res.fs < b) return res;
		return findl_(a,b,m,r,k*2+1,f,args...);
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