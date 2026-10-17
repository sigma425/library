#pragma once

/*
	update がないとき用の rolling hash
	mod 2^61-1 固定。 BASE_NUM を増やすと複数の base で hash を取る

	using RH = RollingHash<string>;       // RollingHash<string, 2> なら base 2個
	RH ah(a), bh(b);

	- get(l,r)
		[l,r) の hash s[l] + s[l+1] * base + .. + s[r-1] * base^(r-l-1) を返す
		O(1)
	- lcp(ah, bh, al, bl, ar=-1, br=-1)
		a[al,ar), b[bl,br) の LCP の長さを返す
		ar, br を省略すると、それぞれ文字列の末尾までを比較する
		RH::lcp(ah, bh, al, bl, ar, br) のように使う
		O(log)
	- strcmp(ah, bh, al, bl, ar=-1, br=-1)
		a[al,ar), b[bl,br) を辞書順比較して -1, 0, 1 のいずれかを返す
		ar, br を省略すると、それぞれ文字列の末尾までを比較する
		RH::strcmp(ah, bh, al, bl, ar, br) のように使う
		O(log)

	↓こっから先は suffix array も使った少し複雑なやつ。 build_sa を呼んでから使う

	- build_sa()
		find_occurrences, longest_prefix を使う ah に対してあらかじめ呼ぶ
		bh に対しては呼ばなくてよい
		sa[i] は辞書順 i 番目の suffix の開始位置、isa[i] は s[i,n) の SA 上の位置
		O(n)
	- find_occurrences(ah, bh, bl, br)
		b[bl,br) が prefix になる a の suffix の SA 上の区間 [l,r) を返す
		出現位置は ah.sa[l], ..., ah.sa[r-1] (重なっていても別に数える)
		空文字列に対しては [0,n+1) を返す
		O(log^2)
	- longest_prefix(ah, bh, bl)
		a の部分文字列として現れる b[bl,m) の prefix の最大長を返す
		O(log^2)

*/

#include "math/mint61.hpp"
#include "misc/rand.hpp"
#include "string/suffix_array.hpp"

template<class Str, int BASE_NUM = 1>
struct RollingHash {
	using mint = ModInt61;
	using Hash = array<mint, BASE_NUM>;

	static_assert(BASE_NUM > 0);

	inline static const Hash base = []{
		Hash res;
		for(int i=0;i<BASE_NUM;i++){
			res[i] = rng(mint::mod - 2) + 2;
		}
		return res;
	}();

	int n;
	Str s;
	vector<Hash> hash, pw;
	vector<int> sa, isa;

	RollingHash() : RollingHash(Str()) {}
	RollingHash(const Str& s) : n(s.size()), s(s), hash(n+1), pw(n+1) {
		for(int j=0;j<BASE_NUM;j++) pw[0][j] = 1;
		for(int i=0;i<n;i++) for(int j=0;j<BASE_NUM;j++){
			pw[i+1][j] = pw[i][j] * base[j];
		}
		for(int i=n-1;i>=0;i--) for(int j=0;j<BASE_NUM;j++){
			hash[i][j] = s[i] + hash[i+1][j] * base[j];
		}
	}

	Hash get(int l, int r) const {
		assert(0 <= l && l <= r && r <= n);
		Hash res;
		for(int j=0;j<BASE_NUM;j++){
			res[j] = hash[l][j] - hash[r][j] * pw[r-l][j];
		}
		return res;
	}

	void build_sa(){
		if(n == 0){
			sa = {0};
			isa = {0};
			return;
		}
		SuffixArray suffix_array(s);
		sa = move(suffix_array.sa);
		isa = move(suffix_array.isa);
	}

	static int lcp(const RollingHash& a, const RollingHash& b, int al, int bl,
			int ar = -1, int br = -1){
		if(ar == -1) ar = a.n;
		if(br == -1) br = b.n;
		assert(0 <= al && al <= ar && ar <= a.n);
		assert(0 <= bl && bl <= br && br <= b.n);
		return lcp_len(a, b, al, bl, min(ar-al, br-bl));
	}

	static int strcmp(const RollingHash& a, const RollingHash& b, int al, int bl,
			int ar = -1, int br = -1){
		if(ar == -1) ar = a.n;
		if(br == -1) br = b.n;
		assert(0 <= al && al <= ar && ar <= a.n);
		assert(0 <= bl && bl <= br && br <= b.n);

		int an = ar-al, bn = br-bl;
		int len = lcp_len(a, b, al, bl, min(an, bn));
		if(len == min(an, bn)) return (an > bn) - (an < bn);
		if(a.s[al+len] < b.s[bl+len]) return -1;
		return 1;
	}

	static pair<int,int> find_occurrences(const RollingHash& a, const RollingHash& b,
			int bl, int br){
		assert(!a.sa.empty());
		assert(0 <= bl && bl <= br && br <= b.n);
		int l = suffix_pattern_bound(a, b, bl, br, false);
		int r = suffix_pattern_bound(a, b, bl, br, true);
		return {l,r};
	}

	static int longest_prefix(const RollingHash& a, const RollingHash& b, int bl){
		assert(!a.sa.empty());
		assert(0 <= bl && bl <= b.n);

		int l = 0, r = a.sa.size();
		while(l < r){
			int mid = (l+r)/2;
			if(strcmp(a, b, a.sa[mid], bl) < 0) l = mid+1;
			else r = mid;
		}

		int res = 0;
		if(l < (int)a.sa.size()) res = max(res, lcp(a, b, a.sa[l], bl));
		if(l > 0) res = max(res, lcp(a, b, a.sa[l-1], bl));
		return res;
	}

	private:

	static int lcp_len(const RollingHash& a, const RollingHash& b,
			int al, int bl, int max_len){
		int ok = 0, ng = max_len+1;
		while(ng-ok > 1){
			int mid = (ok+ng)/2;
			if(a.get(al, al+mid) == b.get(bl, bl+mid)) ok = mid;
			else ng = mid;
		}
		return ok;
	}

	static int strcmp_suffix_pattern(const RollingHash& a, const RollingHash& b,
			int al, int bl, int br){
		int an = a.n-al, bn = br-bl;
		int len = lcp_len(a, b, al, bl, min(an, bn));
		if(len == bn) return 0;
		if(len == an) return -1;
		if(a.s[al+len] < b.s[bl+len]) return -1;
		return 1;
	}

	static int suffix_pattern_bound(const RollingHash& a, const RollingHash& b,
			int bl, int br, bool upper){
		int l = 0, r = a.sa.size();
		while(l < r){
			int mid = (l+r)/2;
			int cmp = strcmp_suffix_pattern(a, b, a.sa[mid], bl, br);
			if(cmp < 0 || (upper && cmp == 0)) l = mid+1;
			else r = mid;
		}
		return l;
	}
};
