#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite"

#include "template.hpp"
#include "math/mint.hpp"
#include "ds/splay/link_cut.hpp"

template<class T>
struct Affine {
	T a,b;
	Affine() {}
	Affine(T a_, T b_):a(a_),b(b_){}
	static Affine op(Affine g, Affine f){
		return Affine(g.a*f.a, g.a*f.b+g.b);
	}
	static Affine e(){
		return Affine(1,0);
	}
};
template<class Monoid>
struct ReversibleMonoid {
	Monoid a, b;
	ReversibleMonoid() {}
	ReversibleMonoid(Monoid a_): a(a_),b(a_){}
	ReversibleMonoid(Monoid a_, Monoid b_): a(a_),b(b_){}
	static ReversibleMonoid op(ReversibleMonoid l, ReversibleMonoid r){
		return ReversibleMonoid(Monoid::op(l.a,r.a), Monoid::op(r.b,l.b));
	}
	static ReversibleMonoid e(){
		return ReversibleMonoid(Monoid::e(), Monoid::e());
	}
	static ReversibleMonoid rev(ReversibleMonoid v){
		return ReversibleMonoid(v.b, v.a);
	}
};

using T = ReversibleMonoid<Affine<mint>>;

int main(){
	int N,Q; cin >> N >> Q;
	vector<T> vs(N);
	rep(i,N){
		mint a,b; cin >> a >> b;
		vs[i] = T(Affine<mint>(a,b));
	}
	LinkCutTree<T, T::op, T::rev, false> lct(vs);
	rep(i,N-1){
		int x,y; cin >> x >> y;
		lct.link(x,y);
	}
	while(Q--){
		int t; cin >> t;
		if(t == 0){
			int x,y,z,w; cin >> x >> y >> z >> w;
			lct.cut(x,y);
			lct.link(z,w);
		}
		if(t == 1){
			int v; mint a,b; cin >> v >> a >> b;
			lct.set_vertex(v, T(Affine<mint>(a,b)));
		}
		if(t == 2){
			int x,y; mint c; cin >> x >> y >> c;
			auto f = lct.get_path(x,y).b;
			cout << f.a*c+f.b << endl;
		}
	}
}