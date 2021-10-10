/*
	initialize
		lazyseg(vec<type>) は type -> Monoid の変換さえ書いてあれば好きなtype使っていい
		そのために Monoid のコンストラクタを増やすのもありですね

	S query(a,b)
		return v[a] + .. v[b-1]
	void apply(a,b, f)
		v[i] = f(v[i])
	void assign(i, x)
		v[i] = x
	assignに限らず一点になにかするだけならやりたい放題(まあquery(i,i+1)で取得して外で計算してassignすればいいと思う)

	にぶたんしたいなら諦めてACL!w
		https://atcoder.github.io/ac-library/master/document_ja/lazysegtree.html
	verify
		test_oj/segtree/range_affine_range_sum.test.cpp
*/
template<class D>
struct lazyseg{
	using S = typename D::Monoid;
	using F = typename D::Action;
	int N;
	vector<S> val;
	vector<F> act;
	lazyseg(){}
	lazyseg(int n){
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,D::e());
		act.assign(N*2,D::id());
	}
	template<class Slike>
	lazyseg(const vector<Slike>& val_){
		int n = val_.size();
		N=1;
		while(N<n) N*=2;
		val .assign(N*2,D::e());
		rep(i,n) val[i+N] = S(val_[i]);
		for(int i=N-1;i>0;i--) val[i] = D::op(val[i*2],val[i*2+1]);
		act.assign(N*2,D::id());
	}

	S query(int a,int b){
		return query(a,b,0,N,1);
	}
	void apply(int i, F f){
		apply(i,i+1,f);
	}
	void apply(int a,int b, F f){
		apply(a,b,f,0,N,1);
	}
	void assign(int i, S x){
		return assign(i,i+1,x,0,N,1);
	}

	private:
	S query(int a,int b,int l,int r,int k){
		if(b<=l || r<=a) return D::e();
		if(a<=l && r<=b) return val[k];
		propagate(l,r,k);
		return D::op(query(a,b,l,(l+r)/2,k*2) , query(a,b,(l+r)/2,r,k*2+1));
	}
	void apply(int a,int b,const F& f,int l,int r,int k){
		if(b<=l || r<=a) return;
		if(a<=l && r<=b){
			addlazy(k,f);
			return;
		}
		propagate(l,r,k);
		apply(a,b,f,l,(l+r)/2,k*2);
		apply(a,b,f,(l+r)/2,r,k*2+1);
		val[k] = D::op(val[k*2] , val[k*2+1]);
	}
	void assign(int a,int b,const S& x, int l,int r,int k){
		if(b<=l || r<=a) return;
		if(a<=l && r<=b){
			// l = i, r = i+1
			val[k] = x;
			act[k] = D::id();
			return;
		}
		propagate(l,r,k);
		assign(a,b,x,l,(l+r)/2,k*2);
		assign(a,b,x,(l+r)/2,r,k*2+1);
		val[k] = D::op(val[k*2] , val[k*2+1]);
	}
	void addlazy(int k, const F& f){
		act[k] = D::composite(f,act[k]);		// 上の階層の lazy ( = f) のほうがよりあと
		val[k] = D::act(f,val[k]);				// val は常に正しく
	}

	void propagate(int l,int r,int k){
		addlazy(k*2  , act[k]);
		addlazy(k*2+1, act[k]);
		act[k] = D::id();
	}
};

/*
	書くもの:
		Monoid の型
		Action の型

		Monoid の単位元 e()
		Monoid op(Monoid, Monoid)

		Action の単位元 id()
		Action composite(Action f, Action g) ( = f*g) g やって f

		Monoid act(Action, Monoid)
*/
/*
struct StarrySky{
	const ll inf = TEN(18);
	struct Monoid{
		ll mn;
		Monoid(){ *this = e(); }
		Monoid(ll mn_):mn(mn_){}
	};
	struct Action{
		ll add;
		Action(){ *this = id(); }
		Action(ll add_):add(add_){}
	};
	const static Monoid e(){
		return Monoid(TEN(18));
	}
	const static Monoid op(const Monoid& x, const Monoid& y){
		return Monoid(min(x.mn,y.mn));
	}

	const static Action id(){
		return Action(0);
	}
	const static Action composite(const Action& f, const Action& g){
		// f \times g
		return Action(f.add + g.add);
	}

	const static Monoid act(const Action& f, const Monoid& x){
		if(x.mn == inf) return x;
		return Monoid(x.mn + f.add);
	}
};


struct D{
	struct Monoid{
		mint sm;
		int sz;
		Monoid(){ *this = e(); }
		Monoid(mint v):sm(v),sz(1){}
		Monoid(mint sm_, int sz_):sm(sm_),sz(sz_){}
	};
	struct Action{
		mint a,b;	// x -> ax+b
		Action(){ *this = id(); }
		Action(mint a_, mint b_):a(a_),b(b_){}
	};
	const static Monoid e(){
		return Monoid(0,0);
	}
	const static Monoid op(const Monoid& x, const Monoid& y){
		Monoid z;
		z.sm = x.sm + y.sm;
		z.sz = x.sz + y.sz;
		return z;
	}

	const static Action id(){
		return Action(1,0);
	}
	const static Action composite(const Action& f, const Action& g){
		// f \times g
		Action h;
		h.a = f.a * g.a;
		h.b = f.a * g.b + f.b;
		return h;
	}

	const static Monoid act(const Action& f, const Monoid& x){
		Monoid z;
		z.sz = x.sz;
		z.sm = x.sm * f.a + f.b * x.sz;
		return z;
	}
};
*/