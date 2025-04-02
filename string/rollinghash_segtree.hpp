/*
	segtree に乗せる用の rolling hash
	query(l,r) = s[l] + s[l+1] * base + .. + s[r-1] * base^(r-l-1)

	verify: ucup 3-21 M https://contest.ucup.ac/submission/825668
*/

#pragma once

#include "math/mint61.hpp"
#include "misc/rand.hpp"
#include "atcoder/segtree"

using mint = ModInt61;
using Hash = pair<mint, int>;
const mint base = rng(mint::mod);
vector<mint> pw = {1};

Hash op(Hash a, Hash b){
	while(a.sc >= (int)pw.size()) pw.emplace_back(pw.back() * base);
	return {a.fs + b.fs * pw[a.sc], a.sc + b.sc};
}
Hash e() {return {0,0};}

template<class Str>
struct RollingHashSegtree {
	int n;
	atcoder::segtree<Hash, op, e> seg;

	RollingHashSegtree() : n(0) {}
	RollingHashSegtree(const Str& s) : n(s.size()) {
		vector<Hash> init(n);
		for(int i=0;i<n;i++) init[i] = {s[i], 1};
		seg = atcoder::segtree<Hash, op, e>(init);
	}
	
	template<class Value>
	void update(int i, const Value& x){
		seg.set(i, {x, 1});
	}

	Hash query(int l, int r){
		return seg.prod(l, r);
	}
};