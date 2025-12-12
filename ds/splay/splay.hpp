/*
	splay tree (simple)
	モノイド (S, op, e) の列をつなげたり切ったりするデータ構造
	S に順序がついている場合は、(range sum 機能のついた) 二分探索木のように使うことも可能
		(lower_bound, upper_bound, insert_val, erase_val)
	verify:
		test_aoj/1508.test.cpp		(列をつなげたり切ったりする例)
		ARC033 C https://atcoder.jp/contests/arc033/submissions/65383618	(平衡二分探索木としての例)
		TUPC2024 B https://atcoder.jp/contests/tupc2024/submissions/65388177	(絶対的な位置 k にモノイドをinsert, みたいな使い方)
*/

template<class S, auto op, auto e>
struct SplayTree {
	// static_assert(is_convertible_v<decltype(op), function<S(S, S)>>,
	// 				"op must work as S(S, S)");
	// static_assert(is_convertible_v<decltype(e), function<S()>>,
	// 				"e must work as S()");

	struct Node;
	using NP = Node*;
	struct Node{
		NP p = nullptr, l = nullptr, r = nullptr;
		int sz = 1;
		S v, sm;
		Node(S v_): v(v_), sm(v_) {}

		inline int pos(){
			if (p && p->l == this) return -1;
			if (p && p->r == this) return 1;
			return 0;
		}
		void rot(){
			assert(p);
			NP pp = p->p;
			int pps = p->pos();
			if(pps == -1) pp->l = this;
			if(pps == 1) pp->r = this;
			if (p->l == this){
				p->l = r;
				if (r) r->p = p;
				r = p;
			}else{
				p->r = l;
				if (l) l->p = p;
				l = p;
			}
			p->p = this;
			p->update();
			update();
			p = pp;
			if(pp) pp->update();
		}
		void splay(){
			int ps;
			while((ps = pos())){
				int pps = p->pos();
				if(pps == 0){			//zig
					rot();
				}else if(ps == pps){	//zigzig
					p->rot(); rot();
				}else{					//zigzag
					rot(); rot();
				}
			}
		}

		// この区間の左からkth(0-indexed)をrootにもってきてそのポインタを返す
		NP splay(int k){
			assert(0 <= k && k < sz);
			int lsz = l ? l->sz : 0;
			if(k < lsz){
				return l->splay(k);
			}else if(k == lsz){
				splay();
				return this;
			}else{
				return r->splay(k-(lsz+1));
			}
		}
		NP update(){
			sz = 1 + (l ? l->sz : 0) + (r ? r->sz : 0);
			sm = v;
			if(l) sm = op(l->sm, sm);
			if(r) sm = op(sm, r->sm);
			return this;
		}

		void showtree(){
			cout << "[";
			if(l) l->showtree();
			cout << v;
			if(r) r->showtree();
			cout << "]";
		}

	};
	NP n;

	/*
		(r != nullptrなら) r の左端が根になる
		その左の子が l
	*/
	static NP merge(NP l, NP r){
		if(!r) return l;
		r = r->splay(0);
		r->l = l;
		if(l) l->p = r;
		return r->update();
	}
	/*
		kthでsplit(k=0ならfs=null)
		とりあえずk個目を持ってきて、pair(それ未満,それ以上)を返す.上につながっているのは(それ以上)の方,というかk
		基本的にsplitの第一引数はrootなので?そんなに気にしなくていいかな
		全区間をsplitしてく ([1,2,3,4] -> [1,2][3,4] -> [1][2][3,4]) ぶんには常にrootなため
	*/
	static pair<NP,NP> split(NP x, int k){
		if(!x) return {nullptr, nullptr};
		assert(0 <= k && k <= x->sz);
		if(k == x->sz) return {x, nullptr};
		x = x->splay(k);
		NP l = x->l;
		if(l) l->p = nullptr;
		x->l = nullptr;
		return {l, x->update()};
	}

	static NP build(const vector<S>& vs){
		return build(vs.size(), vs, 0);
	}
	static NP build(int sz, const vector<S>& vs, int off){
		if(!sz) return nullptr;
		int md = sz/2;
		NP x = new Node(vs[off+md]);
		x->l = build(md, vs, off);
		if(x->l) x->l->p = x;
		x->r = build(sz-(md+1), vs, off+md+1);
		if(x->r) x->r->p = x;
		return x->update();
	}

	SplayTree() : n(nullptr){}
	SplayTree(NP n_) : n(n_){}
	SplayTree(vector<S> vs){
		n = build(vs);
	}

	void insert(int k, S v){
		auto u = split(n, k);
		n = merge(merge(u.fs, new Node(v)), u.sc);
	}
	void erase(int k){
		auto u = split(n,k);
		n = merge(u.fs, split(u.sc, 1).sc);
	}
	void merge(SplayTree t){
		n = merge(n,t.n);
	}
	int size(){
		return n->sz;
	}
	// k番目の要素を返す
	S get(int k){
		auto a = split(n,k);
		auto b = split(a.sc,1);
		S res = b.fs->v;
		n = merge(merge(a.fs, b.fs), b.sc);
		return res;
	}
	void assign(int k, S d){
		auto a = split(n, k);
		auto b = split(a.sc, 1);
		n = merge(merge(a.fs, new Node(d)), b.sc);
	}
	// op(l-th, (l+1)-th, ..., (r-1)-th)
	S query(int l, int r){
		auto b = split(n, r);
		auto a = split(b.fs, l);
		S res = a.sc->sm;
		n = merge(merge(a.fs, a.sc), b.sc);
		return res;
	}
	S query_all(){
		return (n ? n->sm : e());
	}

	/*
		S に順序があるとき用の関数群
		単に平衡二分探索木 + range sum として使いたいときとか
		lower_bound は <= を、 upper_bound は < を要求する
		(x <= val な最小の val の index. ないなら sz)
	*/
	int lower_bound(S x){
		NP p = n;
		int idx = 0;
		while(p){
			if(x <= p->v) p = p->l;
			else idx += (p->l ? p->l->sz : 0) + 1, p = p->r;
		}
		return idx;
	}
	int upper_bound(S x){
		NP p = n;
		int idx = 0;
		while(p){
			if(x < p->v) p = p->l;
			else idx += (p->l ? p->l->sz : 0) + 1, p = p->r;
		}
		return idx;
	}
	/*
		S に順序があるとき位置を指定せずに insert,erase (std::set みたいに)
		map みたいにしたいときは (key,value) のペアを S にするしかない
	*/
	void insert_val(S x){
		int k = lower_bound(x);
		insert(k, x);
	}
	void erase_val(S x){
		int k = lower_bound(x);
		// とりあえず絶対あるということにして lower_bound を消している
		erase(k);
	}

	void showtree(){
		if(!n) cout << "null";
		else n->showtree();
		cout << endl;
	}
};