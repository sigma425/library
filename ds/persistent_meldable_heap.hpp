/*
	永続 meldable heap
	ひとつの NP (=Node*) がひとつの heap を表す 外側の型自体はインターフェースみたいな感じでグローバルに一つ置く
		PersistentMeldableHeapWithOffset<ll> heap;
		using NP = decltype(heap)::NP;
	じゃあ外側いる？という話だが、Node を pool したりするのにこうすると便利ということで (あと nullptr->push とかを避けれる)
	永続なのでどの操作も破壊的でないこと、特に heap.pop(a) と書いても a は変わらないことに注意 (a = ~ とすべき)

	- T top(a): heap a の top を返す O(1)
	- NP pop(a): heap a から pop した heap を返す O(log)
	- NP push(a,v): heap a に v を push した heap を返す O(log)
	- NP merge(a,b): heap a,b をマージした heap を返す O(log)
	- bool empty(a): heap a が empty かどうか返す O(1)

	- NP newnode(): 空の heap を返す
	- NP newnode(v): {v} からなる heap を返す

	- vector<T> enumerate(NP a): heap a の中身を全て返す O(size)

	verify: hu_tucker
*/

template<class T, class F = less<T>>
struct PersistentMeldableHeap{
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
		return merge(a->l, a->r);
	}
	NP push(NP a, T v){
		return merge(a,newnode(v));
	}
	NP merge(NP a, NP b){
		if(!a && !b) return nullptr;
		if(!a) return clone(b);
		if(!b) return clone(a);
		// F がデフォルトの less の場合: a 側が小さいときは、swap すべき (a が上になるので、大きい方が上)
		if(comp(a->val, b->val)) swap(a,b);
		return newnode(a->val, a->l, merge(a->r,b));
	}
	bool empty(NP a){
		return !a;
	}
	NP newnode(){
		return nullptr;
	}
	NP newnode(T v){
		assert(I < pool_size);
		pool[I] = {v, nullptr, nullptr, 1};
		return &pool[I++];
	}
	NP newnode(T v, NP l, NP r){
		assert(I < pool_size);
		if(depth(l) < depth(r)) swap(l,r);
		pool[I] = {v, l, r, depth(r)+1};
		return &pool[I++];
	}
	NP clone(NP a){
		assert(I < pool_size);
		pool[I] = *a;
		return &pool[I++];
	}
	int depth(NP a){
		return a ? a->s : 0;
	}
	vector<T> enumerate(NP a){
		if(!a) return {};
		vector<T> res = {a->val};
		auto vl = enumerate(a->l);
		auto vr = enumerate(a->r);
		res.insert(res.end(),all(vl));
		res.insert(res.end(),all(vr));
		return res;
	}
};
// PersistentMeldableHeapWithOffset<ll> heap;
// using NP = decltype(heap)::NP;