/*
	struct TreeDP を用意すれば使える
	細かいことは 下にある TreeDP の具体例とコメントを参照

	- StaticTopTree<TreeDP> STT(tree, vertices)
		初期化. TreeDP::Vertex の情報と、Rootedtree tree を入力
	- Point all_prod()
		tree.root の上に仮想の vertex がある、というような point cluster を返す
	Path STT.path_prod(int u)
		root,u を border とする path cluster を返す
		この結果を見れば u まわりの情報がわかったりするので、頂点 u まわりのクエリに答えられる
	verify
		ABC351G Hash on Tree
			https://atcoder.jp/contests/abc351/submissions/76422714
		ABC460F
			https://atcoder.jp/contests/abc460/submissions/76435656
			直径的なDP
		ABC460G
			https://atcoder.jp/contests/abc460/submissions/76468509
			path_prod verify

	ref:
		https://atcoder.jp/contests/abc351/editorial/9868
		https://github.com/yosupo06/yosupo-library/blob/main/src/yosupo/toptree.hpp
*/

#include "ds/rooted_tree.hpp"

template <class T>
concept monoid = requires(T t, const typename T::S& s) {
	requires std::same_as<decltype(t.e), typename T::S>;
	{ t.op(s, s) } -> std::same_as<typename T::S>;
};

template <class _S, class OP>
	requires requires(OP op, const _S& a, const _S& b) {
		{ op(a, b) } -> std::same_as<_S>;
	}
struct Monoid {
	using S = _S;
	S e;
	OP op;
	explicit Monoid(S _e, const OP& _op = OP()) : e(_e), op(_op) {}
};
template <class S> using Sum = Monoid<S, std::plus<S>>;
template <class S> using Prod = Monoid<S, std::multiplies<S>>;
template <class _S> struct Max {
	using S = _S;
	Max(S _e = std::numeric_limits<S>::min()) : e(_e) {}
	S op(const S& a, const S& b) const { return std::max(a, b); }
	S e;
};
template <class _S> struct Min {
	using S = _S;
	Min(S _e = std::numeric_limits<S>::max()) : e(_e) {}
	S op(const S& a, const S& b) const { return std::min(a, b); }
	S e;
};

template <class T>
concept static_top_tree_dp = requires(T t,
									  const typename T::Path& path,
									  const typename T::Point& point,
									  const typename T::Vertex& v) {
	requires monoid<decltype(T::path)>;
	requires monoid<decltype(T::point)>;
	requires std::same_as<typename T::Path, typename decltype(T::path)::S>;
	requires std::same_as<typename T::Point, typename decltype(T::point)::S>;
	{ t.add_vertex(point, v) } -> std::same_as<typename T::Path>;
	{ t.add_edge(path) } -> std::same_as<typename T::Point>;
};
template <static_top_tree_dp TreeDP> struct StaticTopTree {
	using Point = typename TreeDP::Point;
	using Path = typename TreeDP::Path;
	using Vertex = typename TreeDP::Vertex;

	int n;

	StaticTopTree(const RootedTree& tree,
				  std::vector<Vertex> _vertices,
				  const TreeDP& _dp = TreeDP())
		: n(tree.n),
		  vertices(std::move(_vertices)),
		  dp(_dp),
		  points(n + 1, dp.point.e),
		  node_ids(n, {n, -1, -1}) {
		std::vector<int> heavy_child(n, -1);
		std::vector<ull> mask(n);

		std::vector<std::pair<int, Node<Path>>> b;
		b.reserve(n);
		auto build_compress = [&](int u) {
			b.clear();
			auto merge_last = [&]() {
				auto y = b.back();
				b.pop_back();
				auto x = b.back();
				b.pop_back();
				b.push_back({std::max(x.first, y.first) + 1,
							 merge<false>(x.second, y.second, compressed)});
			};
			while (u != -1) {
				b.push_back({std::countr_zero(std::bit_ceil(mask[u])),
							 {dp.add_vertex(points[u], vertices[u]),
							  &node_ids[u].c_id}});
				while (true) {
					int len = int(b.size());
					if (len >= 3 && (b[len - 3].first == b[len - 2].first ||
									 b[len - 3].first <= b[len - 1].first)) {
						auto last = b.back();
						b.pop_back();
						merge_last();
						b.push_back(last);
					} else if (len >= 2 &&
							   b[len - 2].first <= b[len - 1].first) {
						merge_last();
					} else {
						break;
					}
				}
				u = heavy_child[u];
			}
			while (b.size() != 1) {
				merge_last();
			}
			return b.back().second.p;
		};

		compressed.reserve(n - 1);
		raked.reserve(n - 1);

		const int MAX_H = 128;
		std::array<Node<Point>, MAX_H> q;
		std::bitset<MAX_H> has = {};
		for (int u : tree.topo | std::ranges::views::reverse) {
			ull sum_rake = 0;
			for (int v : tree.children.at(u)) {
				sum_rake += std::bit_ceil(mask[v]) << 1;
			}
			mask[u] = std::bit_ceil(sum_rake);
			for (int v : tree.children.at(u)) {
				int d = std::countr_zero(
					std::bit_ceil(sum_rake - (std::bit_ceil(mask[v]) << 1)));
				ull s =
					((mask[v] + (ull(1) << d) - 1) >> d << d) + (ull(1) << d);
				if (s <= mask[u]) {
					mask[u] = s;
					heavy_child[u] = v;
				}
			}

			for (int v : tree.children.at(u)) {
				if (v == heavy_child[u]) continue;
				int d = std::countr_zero(
					std::bit_ceil(sum_rake - (std::bit_ceil(mask[v]) << 1)));
				Point point = dp.add_edge(build_compress(v));
				Node<Point> data = {point, &node_ids[v].r_id};
				while (has.test(d)) {
					has.reset(d);
					data = merge<true>(q[d], data, raked);
					d++;
				}
				q[d] = data;
				has.set(d);
			}
			int d = int(has._Find_first());
			if (d == int(has.size())) continue;

			Node data = q[d];
			has.reset(d);
			while (true) {
				d = int(has._Find_first());
				if (d == int(has.size())) break;
				has.reset(d);
				data = merge<true>(q[d], data, raked);
			}
			points[u] = data.p;

			for (int v0 : tree.children.at(u)) {
				if (v0 == heavy_child[u]) continue;
				int v = v0;
				while (v != -1) {
					node_ids[v].h_par = u;
					node_ids[v].r_id = node_ids[v0].r_id;
					v = heavy_child[v];
				}
			}
		}
		points[n] = dp.add_edge(build_compress(tree.root));
	}

	Vertex get_vertex(int u) { return vertices[u]; }
	void update(int u, Vertex vertex) {
		vertices[u] = vertex;
		auto up_compress = [&](int id, auto p) {
			while (id >= 0) {
				if (id % 2 == 0) {
					compressed[id / 2].d.first = p;
				} else {
					compressed[id / 2].d.second = p;
				}
				p = dp.path.op(compressed[id / 2].d.first,
							   compressed[id / 2].d.second);
				id = compressed[id / 2].par;
			}
			return p;
		};
		auto up_rake = [&](int id, auto p) {
			while (id >= 0) {
				if (id % 2 == 0) {
					raked[id / 2].d.first = p;
				} else {
					raked[id / 2].d.second = p;
				}
				p = dp.point.op(raked[id / 2].d.first, raked[id / 2].d.second);
				id = raked[id / 2].par;
			}
			return p;
		};
		while (u != n) {
			auto [h_par, c_id, r_id] = node_ids[u];
			Point p = dp.add_edge(
				up_compress(c_id, dp.add_vertex(points[u], vertices[u])));
			points[h_par] = up_rake(r_id, p);
			u = h_par;
		}
	}

	Point all_prod() { return points[n]; }

	Path path_prod(int u) {
		Path path = dp.path.e;
		Point point = points[u];
		while (true) {
			auto [h_par, c_id, r_id] = node_ids[u];
			Path l = dp.path.e, r = dp.path.e;
			{
				int id = c_id;
				while (id >= 0) {
					if (id % 2 == 0) {
						r = dp.path.op(r, compressed[id / 2].d.second);
					} else {
						l = dp.path.op(compressed[id / 2].d.first, l);
					}
					id = compressed[id / 2].par;
				}
			}
			point = dp.point.op(point, dp.add_edge(r));
			path = dp.path.op(
				l, dp.path.op(dp.add_vertex(point, vertices[u]), path));
			if (h_par == n) return path;
			point = dp.point.e;
			{
				int id = r_id;
				while (id >= 0) {
					if (id % 2 == 0) {
						point = dp.point.op(point, raked[id / 2].d.second);
					} else {
						point = dp.point.op(raked[id / 2].d.first, point);
					}
					id = raked[id / 2].par;
				}
			}
			u = h_par;
		}
	}

  private:
	std::vector<Vertex> vertices;
	TreeDP dp;

	// compress / rake
	template <class D> struct Inner {
		std::pair<D, D> d;
		int par;
	};
	std::vector<Inner<Path>> compressed;
	std::vector<Inner<Point>> raked;

	// compress / rake / leaf
	template <class D> struct Node {
		D p;
		int* par;
	};
	template <bool RAKE, class D>
	Node<D> merge(const Node<D>& l,
				  const Node<D>& r,
				  std::vector<Inner<D>>& nodes) {
		int id = int(nodes.size());
		*l.par = 2 * id;
		*r.par = 2 * id + 1;
		nodes.push_back({{l.p, r.p}, -1});
		if constexpr (RAKE) {
			return {dp.point.op(l.p, r.p), &nodes[id].par};
		} else {
			return {dp.path.op(l.p, r.p), &nodes[id].par};
		}
	}

	std::vector<Point> points;
	struct ID {
		int h_par, c_id, r_id;
	};
	std::vector<ID> node_ids;
};

/*
	point.op (rake): point * point -> point
		同じ virtual な root を持つ部分木 DP の情報をマージ
		子として x, y が横に並んでいることをイメージ

	path.op (compress): path * path -> path
		HL の heavy path 上でのマージに対応。 x が root 側
		木が一本のパス(root->leaf)であるときにどう segtree に乗せるかをイメージ
		直径DPみたいに、border が 2個ある cluster をマージ みたいに思うほうがわかりやすいかも?
		「x の t が y の s の親」 は多分常に正しい x.t == y.s ではないので、直径などの辺属性のDPのときは注意

	add_vertex: point * vertex -> path
		point cluster x の virtual root に data v である頂点を追加して (長さ0の) path cluster にする
		部分木 DP をして最後に頂点を追加するイメージ
		v は index じゃなくて、頂点が持つ情報そのもの。これを STT 側で update するので、
		TreeDP 側では index が～とかは考えずに、データとして point cluster に vertex を追加したらどうなるかを考えれば良い

	add_edge: path -> point
		path cluster を、もう横にマージするだけの point cluster とみなす
		この後縦に繋がることを考慮しなくてよくなるので、Path で持っていた情報をいくつか落として Point にするイメージ
		Path の単位元に対して add_edge が呼ばれることもあるので注意
		Point の単位元を返せばいいと思う、多分
*/

/*
Hash on Tree

struct TreeDP{
	using Point = mint;
	inline static const auto point = Prod<mint>(mint(1));

	struct Path{
		// 下に hash x がつくと、a * x + b になる
		mint a,b;
	};
	inline static const auto path = Monoid(
		Path{mint(1), mint(0)},
		[](const Path& x, const Path& y) -> Path {
			return {x.a * y.a, x.b + x.a * y.b};
		}
	);

	using Vertex = mint;

	Path add_vertex(Point x, Vertex v){
		return {x, v};
	}
	Point add_edge(Path x){
		return x.a + x.b;
	}
};
*/

/*
頂点が黒か白で塗られていて、黒の直径を求める

struct TreeDP{
	static const int inf = 1e8;
	struct Point{
		// d: 黒の直径, ds: border s からの距離
		int d, ds;
	};
	
	inline static const auto point = Monoid(
		Point{-inf,-inf},
		[](const Point& x, const Point& y){
			return Point{
				max({x.d, y.d, x.ds + y.ds}),
				max(x.ds, y.ds)
			};
		}
	);

	struct Path{
		// d: 直径, ds: border s からの距離, dt: border t からの距離, dst: stの距離
		// s が root 側
		int d, ds, dt, dst;
	};
	inline static const auto path = Monoid(
		Path{-inf,-inf,-inf, 0},
		[](const Path& a, const Path& b){
			return Path{
				max({a.d, b.d, a.dt + b.ds + 1}),
				max({a.ds, a.dst + b.ds + 1}),
				max({b.dt, b.dst + a.dt + 1}),
				a.dst + b.dst + 1
			};
		 }
	);

	using Vertex = bool;	// is_black

	Path add_vertex(Point x, Vertex v){
		if(v){
			return {
				max({x.d, x.ds, 0}),
				max(x.ds, 0),
				max(x.ds, 0),
				0
			};
		}else{
			return {
				x.d,
				x.ds,
				x.ds,
				0
			};
		}
	}
	Point add_edge(Path x){
		return {x.d, x.ds + 1};
	}
};
*/

/*
頂点の色が0/1, 頂点 v から同じ色を辿って到達できる頂点に対する重みの和

struct TreeDP{
	struct Point{
		ll w0, w1;
	};
	
	inline static const auto point = Monoid(
		Point{0,0},
		[](const Point& x, const Point& y){
			return Point{
				x.w0 + y.w0,
				x.w1 + y.w1
			};
		}
	);

	struct Path{
		int cs, ct;		// border s,t の color. s が root 側
		bool connected;	// s-t 間が全て同色かどうか
		ll ws, wt;		// s,t から同色で辿れる頂点の重みの和
	};
	inline static const auto path = Monoid(
		Path{-1, -1, false, 0, 0},
		[](const Path& a, const Path& b){
			if(a.cs == -1) return b;
			if(b.cs == -1) return a;
				return Path{
					a.cs,
					b.ct,
					a.connected && b.connected && a.ct == b.cs,
					(a.connected && a.ct == b.cs) ? a.ws + b.ws : a.ws,
					(b.connected && a.ct == b.cs) ? b.wt + a.wt : b.wt
				};
			 }
		);

	struct Vertex{
		int c;
		ll w;
	};

	Path add_vertex(Point x, Vertex v){
		ll nw = v.w + (v.c == 0 ? x.w0 : x.w1);
		return {v.c, v.c, true, nw, nw};
	}
	Point add_edge(Path x){
		// assert(x.cs != -1);
		// Path の単位元に add_edge が呼ばれることもあるので注意
		// Point の単位元を返せばいいと思う、多分
		if(x.cs == -1) return point.e;
		return {
			x.cs == 0 ? x.ws : 0,
			x.cs == 1 ? x.ws : 0
		};
	}
};
*/