/*
	Link-Cut Tree

	辺にモノイド (S,op,e) が乗っているバージョン

	- link(u, v, val): u, v を結ぶ値 val の辺を追加
	- cut(u, v): u, v を切る
	- set_edge(u, v, val): A[u-v] := val
	- get_edge(u, v): A[u-v] を取得
	- get_path(u, v): op(A[u-x], A[x-y], ..., A[z-v]) を取得。 u = v なら e を返す

	verify:
		ucup 3-35 F	https://contest.ucup.ac/submission/1006258
*/

#include "ds/splay/link_cut.hpp"

template<class S, auto op, auto e, auto rev>
struct LinkCutTreeEdge {
	static_assert(is_convertible_v<decltype(op), function<S(S, S)>>,
					"op must work as S(S, S)");
	static_assert(is_convertible_v<decltype(e), function<S()>>,
					"e must work as S()");
	static_assert(is_convertible_v<decltype(rev), function<S(S)>>,
					"rev must work as S(S)");

	LinkCutTree<S, op, rev> lct;
	int N;
	map<pair<int,int>, int> edge_id;
	set<int> vacant_id;

	LinkCutTreeEdge(int n): N(n), lct(n+n-1) {
		rep(i,N+N-1) lct.init_node(i, e());
		for(int i=N;i<N+N-1;i++) vacant_id.insert(i);
	}

	void link(int u, int v, S val){
		if(u > v) swap(u, v);
		int eid = *vacant_id.begin(); vacant_id.erase(eid); edge_id[{u,v}] = eid;
		lct.set_vertex(eid, val);
		lct.link(u, eid);
		lct.link(v, eid);
	}
	void cut(int u, int v){
		if(u > v) swap(u, v);
		assert(edge_id.count({u,v}));
		int eid = edge_id[{u,v}];
		lct.cut(eid, u);
		lct.cut(eid, v);
		vacant_id.insert(eid);
	}
	void set_edge(int u, int v, S val){
		if(u > v) swap(u, v);
		assert(edge_id.count({u,v}));
		int eid = edge_id[{u,v}];
		lct.set_vertex(eid, val);
	}
	S get_edge(int u, int v){
		if(u > v) swap(u, v);
		assert(edge_id.count({u,v}));
		int eid = edge_id[{u,v}];
		return lct.get_vertex(eid);
	}
	S get_path(int u, int v){
		return lct.get_path(u, v);
	}
};