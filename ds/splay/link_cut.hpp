/*
	Link-Cut Tree

	森の頂点にモノイド (S,op) の元 A[v] が定まっている。
	A の一点変更, path にわたる和, 森の動的変更 が O(log) で可能
	辺に値が乗っている場合は倍加する (link_cut_edge.hpp)
	rev は op(a,b,c,d) を op(d,c,b,a) にうつすものなので、
		- S が可換なら [](auto a){return a;}
		- 非可換なら、S を (S,S*) の組にして swap みたいにするしかない
		verify の一個目と二個目の実装を参照

	- link(u, v): u, v を結ぶ
	- cut(u, v): u, v を切る
	- set_vertex(v, val): A[v] := val
	- add_vertex(v, val): A[v] = op(A[v], val)
	- get_vertex(v): A[v] を取得
	- get_path(u, v): op(A[u], ..., A[v]) を取得

	verify:
		dynamic_tree_vertex_add_path_sum.test.cpp			(可換モノイド)
		dynamic_tree_vertex_set_path_composite.test.cpp		(非可換)
*/

template<class S, auto op, auto rev>
struct LinkCutTree {
	static_assert(is_convertible_v<decltype(op), function<S(S, S)>>,
					"op must work as S(S, S)");
	static_assert(is_convertible_v<decltype(rev), function<S(S)>>,
					"rev must work as S(S)");
	
	struct Node;
	using NP = Node*;
	struct Node {
		NP p = nullptr, l = nullptr, r = nullptr;
		int sz = 1;
		S v, sm;
		bool reversed = false;
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
			push_all();
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
		void expose(){
			NP v = this, vr = nullptr;
			do{
				v->splay();
				v->r = vr;
				v->update();
				vr = v;
			}while((v = v->p));
			splay();
		}
		void revdata(){
			reversed ^= true;
			swap(l, r);
			sm = rev(sm);
		}
		void push(){
			if(reversed){
				if(l) l->revdata();
				if(r) r->revdata();
				reversed = false;
			}
		}
		void push_all(){
			if(pos()) p->push_all();
			push();
		}
		void update(){
			push();
			sz = 1 + (l ? l->sz : 0) + (r ? r->sz : 0);
			sm = v;
			if(l) sm = op(l->sm, sm);
			if(r) sm = op(sm, r->sm);
		}
		// 親を np にする
		void link(NP np){
			evert();
			np->expose();
			p = np;
		}
		// 親との辺を切る
		void cut(){
			expose();
			assert(l);
			l->p = nullptr;
			l = nullptr;
			update();
		}
		void evert(){
			expose();
			revdata();
		}
	};

	vector<NP> tree;

	LinkCutTree() {}
	LinkCutTree(int n): tree(n) {}
	LinkCutTree(vector<S> vs): tree(vs.size()) {
		for(int i = 0; i < vs.size(); i++) init_node(i, vs[i]);
	}

	void init_node(int v, S val){
		tree[v] = new Node(val);
	}
	void link(int u, int v){
		tree[u]->link(tree[v]);
	}
	void cut(int u, int v){
		tree[u]->evert();
		tree[v]->expose();
		assert(tree[u]->p == tree[v]);
		tree[u]->p = nullptr;
		tree[v]->l = nullptr;
		tree[v]->update();
	}
	void set_vertex(int v, S val){
		tree[v]->splay();
		tree[v]->v = val;
		tree[v]->update();
	}
	void add_vertex(int v, S val){
		set_vertex(v, op(tree[v]->v, val));
	}
	S get_vertex(int v){
		return tree[v]->v;
	}
	S get_path(int u, int v){
		tree[u]->evert();
		tree[v]->expose();
		return tree[v]->sm;
	}
};