/*
	segtree beats
	新たな実装を試みたが一旦放棄
	lazy segtree みたいにしようと思ったが、やっぱり "変なクエリ" をわざわざ A に乗せるような実装にするのが微妙すぎる
	例えば、 bool changeHoge(int x) という変更クエリを考えるとして、これが 区間 add に帰着できるまで再帰する
	みたいな segbeats を考えたときに、この changeHoge を 作用モノイドに乗せる必要が本当にあるか？

	ということを色々考えたメモ: https://www.notion.so/segtree-beats-1f4178eea61c8049a8cfcb1a688fdd70
*/

template<class N>
struct segbeats{
	using X = typename N::X;
	using A = typename N::A;
	int n, log, s;
	vector<X> dat;
	vector<A> laz;

	segbeats() {}
	segbeats(int n_): n(n_){
		log = 0; while((1 << log) < n) log++;
		s = 1 << log;
		dat.assign(s*2, N::e());
		laz.assign(s*2, N::id());
	}
	template<class Xlike>
	segbeats(const vector<Xlike>& v): n(v.size()){
		log = 0; while((1 << log) < n) log++;
		s = 1 << log;
		dat.assign(s*2, N::e());
		laz.assign(s*2, N::id());
		rep(i,n) dat[s+i] = X(v[i]);
		per1(i,s-1) update(i);
	}

	template<class F, class... Args>
	void change(int l, int r, F f, Args... args){
		change_(l, r, 0, s, 1, f, args...);
	}
	template<class F, class G, class H>
	auto get(int l, int r, F f, G g, H h){
		return get_(l, r, 0, s, 1, f, g, h);
	}
	template<class F, class... Args>
	pair<int, X> findl(int l, int r, F f, Args&... args){
		return findl_(l, r, 0, s, 1, f, args...);
	}

	void set_point(int i, X x){
		assert(0 <= i && i < n);
		i += s;
		per1(h, log) push(i >> h);
		dat[i] = x;
		rep1(h, log) update(i >> h);
	}
	X get_point(int i){
		assert(0 <= i && i < n);
		i += s;
		per1(h, log) push(i >> h);
		return dat[i];
	}
	X get_range(int l, int r){
		assert(0 <= l && l <= r && r <= n);
		return get(l, r, &N::X::self, N::op, N::e());
	}

	private:

	void apply_at(int k, A a){
		dat[k] = N::apply(dat[k], a);
		if(k < s) laz[k] = N::composition(a, laz[k]); 	// (a (laz[k] x))
	}
	void push(int k){
		if(laz[k] == N::id()) return;
		apply_at(2*k, laz[k]);
		apply_at(2*k+1, laz[k]);
		laz[k] = N::id();
	}
	void update(int k){
		dat[k] = N::op(dat[k*2], dat[k*2+1]);
	}

	template<class F, class... Args>
	void change_(int a, int b, int l, int r, int k, F f, Args... args){
		if(b<=l || r<=a) return;
		if(a<=l && r<=b && (dat[k].*f)(args...)) return;		// lazy 完了
		push(k);
		int m = (l+r)/2;
		change_(a,b,l,m,k*2  ,f,args...);
		change_(a,b,m,r,k*2+1,f,args...);
		update(k);
	}
	template<class F, class G, class H>
	auto get_(int a, int b, int l, int r, int k, F f, G g, H h){
		if(b<=l || r<=a) return h;
		if(a<=l && r<=b) return (dat[k].*f)();
		push(k);
		int m = (l+r)/2;
		return g(get_(a,b,l,m,k*2,f,g,h), get_(a,b,m,r,k*2+1,f,g,h));
	}
	template<class F, class... Args>
	pair<int, X> findl_(int a, int b, int l, int r, int k, F f, Args&... args){
		if(b<=l || r<=a){
			return {b, N()};
		}
		if(a<=l && r<=b){
			if(!(dat[k].*f)(args...)) return {b, N::e()};
			if(r-l == 1) return {l, dat[k]};
		}
		push(k);
		int m = (l+r)/2;
		auto res = findl_(a,b,l,m,k*2,f,args...);
		if(res.fs < b) return res;
		return findl_(a,b,m,r,k*2+1,f,args...);
	}
};
