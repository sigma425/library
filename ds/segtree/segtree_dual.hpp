/*
	range apply + point get segtree

	lazy segtree の作用だけを持ってるやつ　ただ、単に 区間add + 点取得 みたいなのにも使える
	- 作用だけをもってる lazy segtree とみなす
		as[k] + q1 + q3 + q4 みたいに来たクエリ順に足していったものをちゃんと取得できる必要があり、そうなっている
		間違えて初期化で lazy segtree でいう D の方を与えないこと
		(例: x -> ax + b が range query で来るとして、初期値に x_i を与えるのはおかしい, 単に作用の単位元(1,0)が初期値)
	- 区間add + 点取得
		例えば単に区間に +=v, 点取得 だと作用という感じは全くしないが、これを使ってください
	
	- A get(int k)
	- void apply(int a, int b, A a)
*/
template<class A>
struct SegtreeDual{
	int N,lg;
	vector<A> lazy;

	SegtreeDual(){}
	SegtreeDual(int n){
		N = 1; while(N < n){N *= 2, lg++;}
		lazy.assign(N*2, A());
	}
	template<class Alike>
	SegtreeDual(const vector<Alike>& as){
		int n = as.size();
		N = 1; while(N < n){N *= 2, lg++;}
		lazy.assign(N*2, A());
		rep(i,n) lazy[i+N] = as[i];
	}
	A get(int i){
		i += N;
		for(int h=lg;h>=1;h--) push(i >> h);
		return lazy[i];
	}
	void apply(int l, int r, A a){
		l += N, r += N;
		for(int h = lg; h >= 1; h--){
			if(((l>>h)<<h) != l) push(l >> h);
			if(((r>>h)<<h) != r) push((r-1) >> h);
		}
		while(l < r){
			if(l&1) all_apply(l++, a);
			if(r&1) all_apply(--r, a);
			l >>= 1, r >>= 1;
		}
	}
	private:
	void push(int k){
		all_apply(k*2, lazy[k]); all_apply(k*2+1, lazy[k]);
		lazy[k] = A();
	}
	void all_apply(int k, A a){
		lazy[k] = A::op(a,lazy[k]);	// 上の階層の lazy (a) のほうがより後
	}
};

// struct D{
// 	int v;
// 	D(){ *this = e(); }
// 	D(int v_):v(v_){}
// 	static D op(const D& x,const D& y){
// 		return D(x.v+y.v);
// 	}
// 	const static D e(){
// 		return D(0);
// 	}
// //	friend ostream& operator<<(ostream& o,const D& d){return o<<d.v;}
// };
