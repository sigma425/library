/*
	lazyseg とほぼ同じAPIになっている
	一つ違うのは、 Node(l,r) を呼んだとき D::e() を返してはいけない(それはそう、例えばサイズは r-l) ため、
	D の中に initialize(l,r) という関数を作る必要がある
	初期状態での a[l] + .. + a[r-1] を返せばいい

	メモリがやばい可能性が高い。その場合:
		- Node の l,r を可能なら int に
		- ちゃんと delete をする (しないほうが実行時間は速そう) 標準ではしている
		- うしろに貼ってある lazyseg_dynamic_pool を使う
	pool, そんなに使いづらくないけど配列の長さを指定したりする必要があってほんの少し面倒

	verify
		https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2377 ThreeRooks
*/
template<class D>
struct lazyseg_dynamic{
	using S = typename D::Monoid;
	using F = typename D::Action;

	struct Node;
	using NP = Node*;
	struct Node{
		S val;
		F act;
		ll l,r;				// 10^9 でメモリ減らしたいならintに変える
		NP lch,rch;
		Node(ll l_,ll r_):act(D::id()),l(l_),r(r_),lch(nullptr),rch(nullptr){
			// should initialize val for [l,r)
			// ex. val = l + .. + r-1
			// ex. val.sz = r-l
			val = D::initialize(l,r);
		}
		Node(ll l_,ll r_,S val_):val(val_),act(D::id()),l(l_),r(r_),lch(nullptr),rch(nullptr){
			// OK. initlized with val (act = D::id())
		}
		~Node(){
			delete lch;
			delete rch;
		}
	};

	NP root;
	lazyseg_dynamic(){}
	lazyseg_dynamic(ll N){
		ll n2 = 1;
		while(n2 < N) n2 *= 2;
		root = new Node(0,n2);
	}
	~lazyseg_dynamic(){
		delete root;
	}

	S query(ll a, ll b){
		return query(a,b,root);
	}
	void apply(ll i, F f){
		apply(i,i+1,f);
	}
	void apply(ll a, ll b, F f){
		apply(a,b,f,root);
	}
	void assign(ll i, S x){
		assign(i,i+1,x,root);
	}
	private:
	S query(ll a, ll b, NP n){
		ll l = n->l, r = n->r;
		if(b<=l || r<=a) return D::e();
		if(a<=l && r<=b) return n->val;
		if(!n->lch) n->lch = new Node(l,(l+r)/2);
		if(!n->rch) n->rch = new Node((l+r)/2,r);
		propagate(l,r,n);
		return D::op(query(a,b,n->lch) , query(a,b,n->rch));
	}
	void apply(ll a, ll b, const F& f, NP n){
		ll l = n->l, r = n->r;
		if(b<=l || r<=a) return;
		if(a<=l && r<=b){
			addlazy(n,f);
			return;
		}
		if(!n->lch) n->lch = new Node(l,(l+r)/2);
		if(!n->rch) n->rch = new Node((l+r)/2,r);
		propagate(l,r,n);
		apply(a,b,f,n->lch);
		apply(a,b,f,n->rch);
		n->val = D::op(n->lch->val , n->rch->val);
	}
	void assign(ll a, ll b, const S& x, NP n){
		ll l = n->l, r = n->r;
		if(b<=l || r<=a) return;
		if(a<=l && r<=b){
			// l = i, r = i+1
			n->val = x;
			n->act = D::id();
			return;
		}
		if(!n->lch) n->lch = new Node(l,(l+r)/2);
		if(!n->rch) n->rch = new Node((l+r)/2,r);
		propagate(l,r,n);
		assign(a,b,x,n->lch);
		assign(a,b,x,n->rch);
		n->val = D::op(n->lch->val , n->rch->val);
	}
	void addlazy(NP n, const F& f){
		n->act = D::composite(f,n->act);		// 上の階層の lazy ( = f) のほうがよりあと
		n->val = D::act(f,n->val);				// val は常に正しく
	}

	void propagate(ll l, ll r, NP n){
		addlazy(n->lch, n->act);
		addlazy(n->rch, n->act);
		n->act = D::id();
	}
};

struct D{
	struct Monoid{
		mint s,ss;
		mint len;
		Monoid(){ *this = e(); }
		Monoid(mint v):s(v),ss(0),len(1){}
		Monoid(mint s_,mint ss_,mint len_):s(s_),ss(ss_),len(len_){}
		friend ostream& operator<<(ostream &o,const Monoid& x){ return o<<"{"<<x.s<<","<<x.ss<<","<<x.len<<"}";}
	};
	using Action = mint;
	const static Monoid e(){
		return Monoid(0,0,0);
	}
	const static Monoid op(const Monoid& x, const Monoid& y){
		Monoid z;
		z.s = x.s + y.s;
		z.ss = x.ss + x.s*y.len + y.ss;
		z.len = x.len + y.len;
		return z;
	}

	const static Action id(){
		return Action(0);
	}
	const static Action composite(const Action& f, const Action& g){
		// f \times g
		return f+g;
	}

	const static Monoid act(const Action& f, const Monoid& x){
		Monoid z;
		z.s = x.s + f * x.len;
		z.ss = x.ss + f * Choose(x.len,2);
		z.len = x.len;
		return z;
	}

	const static Monoid initialize(ll l, ll r){
		return Monoid(0,0,r-l);
	}
};

// pool バージョン
// グローバルに Node<D> pool[] とかをおいているので定義順とかが微妙に違う


template<class D>
struct Node{
	using S = typename D::Monoid;
	using F = typename D::Action;
	S val;
	F act;
	int l,r;				// 10^9 でメモリ減らしたいならintに変える
	int lch,rch;
	Node(){}
	Node(ll l_,ll r_):act(D::id()),l(l_),r(r_),lch(-1),rch(-1){
		// should initialize val for [l,r)
		// ex. val = l + .. + r-1
		// ex. val.sz = r-l
		val = D::initialize(l,r);
	}
	Node(ll l_,ll r_,S val_):val(val_),act(D::id()),l(l_),r(r_),lch(-1),rch(-1){
		// OK. initlized with val (act = D::id())
	}
};
struct D{
	struct Monoid{
		mint s,ss;
		mint len;
		Monoid(){ *this = e(); }
		Monoid(mint v):s(v),ss(0),len(1){}
		Monoid(mint s_,mint ss_,mint len_):s(s_),ss(ss_),len(len_){}
		friend ostream& operator<<(ostream &o,const Monoid& x){ return o<<"{"<<x.s<<","<<x.ss<<","<<x.len<<"}";}
	};
	using Action = mint;
	const static Monoid e(){
		return Monoid(0,0,0);
	}
	const static Monoid op(const Monoid& x, const Monoid& y){
		Monoid z;
		z.s = x.s + y.s;
		z.ss = x.ss + x.s*y.len + y.ss;
		z.len = x.len + y.len;
		return z;
	}

	const static Action id(){
		return Action(0);
	}
	const static Action composite(const Action& f, const Action& g){
		// f \times g
		return f+g;
	}

	const static Monoid act(const Action& f, const Monoid& x){
		Monoid z;
		z.s = x.s + f * x.len;
		z.ss = x.ss + f * Choose(x.len,2);
		z.len = x.len;
		return z;
	}

	const static Monoid initialize(ll l, ll r){
		return Monoid(0,0,r-l);
	}
};


Node<D> pool[3000000];

template<class D>
struct lazyseg_dynamic{
	using S = typename D::Monoid;
	using F = typename D::Action;

	int I;
	template<class... Args>
	int makeNode(Args... args){
		pool[I] = Node<D>(args...);
		return I++;
	}

	int root;
	lazyseg_dynamic(){ I = 0; }
	lazyseg_dynamic(ll N){
		I = 0;
		ll n2 = 1;
		while(n2 < N) n2 *= 2;
		root = makeNode(0,n2);
	}

	S query(ll a, ll b){
		return query(a,b,root);
	}
	void apply(ll i, F f){
		apply(i,i+1,f);
	}
	void apply(ll a, ll b, F f){
		apply(a,b,f,root);
	}
	void assign(ll i, S x){
		assign(i,i+1,x,root);
	}
	private:
	S query(ll a, ll b, int n){
		ll l = pool[n].l, r = pool[n].r;
		if(b<=l || r<=a) return D::e();
		if(a<=l && r<=b) return pool[n].val;
		if(pool[n].lch == -1) pool[n].lch = makeNode(l,(l+r)/2);
		if(pool[n].rch == -1) pool[n].rch = makeNode((l+r)/2,r);
		propagate(l,r,n);
		return D::op(query(a,b,pool[n].lch) , query(a,b,pool[n].rch));
	}
	void apply(ll a, ll b, const F& f, int n){
		ll l = pool[n].l, r = pool[n].r;
		if(b<=l || r<=a) return;
		if(a<=l && r<=b){
			addlazy(n,f);
			return;
		}
		if(pool[n].lch == -1) pool[n].lch = makeNode(l,(l+r)/2);
		if(pool[n].rch == -1) pool[n].rch = makeNode((l+r)/2,r);
		propagate(l,r,n);
		apply(a,b,f,pool[n].lch);
		apply(a,b,f,pool[n].rch);
		pool[n].val = D::op(pool[pool[n].lch].val , pool[pool[n].rch].val);
	}
	void assign(ll a, ll b, const S& x, int n){
		ll l = pool[n].l, r = pool[n].r;
		if(b<=l || r<=a) return;
		if(a<=l && r<=b){
			// l = i, r = i+1
			pool[n].val = x;
			pool[n].act = D::id();
			return;
		}
		if(pool[n].lch == -1) pool[n].lch = makeNode(l,(l+r)/2);
		if(pool[n].rch == -1) pool[n].rch = makeNode((l+r)/2,r);
		propagate(l,r,n);
		assign(a,b,x,pool[n].lch);
		assign(a,b,x,pool[n].rch);
		pool[n].val = D::op(pool[pool[n].lch].val , pool[pool[n].rch].val);
	}
	void addlazy(int n, const F& f){
		pool[n].act = D::composite(f,pool[n].act);		// 上の階層の lazy ( = f) のほうがよりあと
		pool[n].val = D::act(f,pool[n].val);				// val は常に正しく
	}

	void propagate(ll l, ll r, int n){
		addlazy(pool[n].lch, pool[n].act);
		addlazy(pool[n].rch, pool[n].act);
		pool[n].act = D::id();
	}
};
