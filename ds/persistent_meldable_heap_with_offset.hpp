/*
	永続 meldable heap with offset
	offset ない版とほぼ同じなので説明はそっちを参照

	- NP add_offset(a, off): heap a の要素全体に += off した heap を返す O(1)

	仕組み
		lazy みたいな感じで、heap a に入ってる値 v は、a から v に潜っていく間の val を足し合わせたもの になっている
	
	verify
		ucup 3-2 B https://contest.ucup.ac/submission/443812
*/

template<class T, class F = less<T>>
struct PersistentMeldableHeapWithOffset{
	struct Node{
		T val;
		Node *l, *r;
		int s;
	};
	using NP = Node*;
	static constexpr int pool_size = 900'000'000 / sizeof(Node);	// 0.9GB とる
	Node pool[pool_size];
	int I;	// currently used
	F comp = F();

	T top(NP a){
		assert(a);	// a: empty
		return a->val;
	}
	NP pop(NP a){
		assert(a);
		return merge(a->l, a->r, a->val, a->val);
	}
	NP push(NP a, T v){
		return merge(a,newnode(v));
	}
	NP merge(NP a, NP b, T aoff=0, T boff=0){
		if(!a && !b) return nullptr;
		if(!a) return add_offset(b,boff);
		if(!b) return add_offset(a, aoff);
		if(comp(a->val+aoff, b->val+boff)){
			// F がデフォルトの less の場合: a 側が小さいときは、swap すべき (a が上になるので、大きい方が上)
			swap(a,b); swap(aoff,boff);
		}
		return newnode(a->val+aoff, a->l, merge(a->r, b, 0, boff-(a->val+aoff)));
	}
	bool empty(NP a){
		return !a;
	}
	NP add_offset(NP a, T off){
		if(!a || off == 0) return a;
		NP b = clone(a);
		b->val += off;
		return b;
	}
	NP newnode(){
		return nullptr;
	}
	NP newnode(T v){
		pool[I] = {v, nullptr, nullptr, 1};
		return &pool[I++];
	}
	NP newnode(T v, NP l, NP r){
		if(depth(l) < depth(r)) swap(l,r);
		pool[I] = {v, l, r, depth(r)+1};
		return &pool[I++];
	}
	NP clone(NP a){
		pool[I] = *a;
		return &pool[I++];
	}
	int depth(NP a){
		return a ? a->s : 0;
	}
	vector<T> enumerate(NP a, T off=0){
		if(!a) return {};
		vector<T> res = {off+a->val};
		auto vl = enumerate(a->l, off+a->val);
		auto vr = enumerate(a->r, off+a->val);
		res.insert(res.end(),all(vl));
		res.insert(res.end(),all(vr));
		return res;
	}
};
// PersistentMeldableHeapWithOffset<ll> heap;
// using NP = decltype(heap)::NP;