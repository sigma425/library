/*
	自前 bitset
	N を指定できる、ull を bs.a で取ってこれる などにより便利なことがある
	next(i), prev(i) やその他便利関数は結構あります
	verify: ucup-3-9 https://contest.ucup.ac/submission/563208 sum_range 等
*/
#include "misc/highbit.hpp"

struct Bitset{
	int N;
	vector<ull> a;

	Bitset(int N_ = 0, bool init = false):N(N_){
		int sz = (N + 63) >> 6;
		a.assign(sz, init ? -1 : 0);
		if(N) a.back() >>= (64 * a.size() - N);
	}

	int size(){ return N; }

	Bitset& operator&=(const Bitset& r){
		assert(N == r.N);
		rep(i,a.size()) a[i] &= r.a[i];
		return *this;
	}
	Bitset& operator|=(const Bitset& r){
		assert(N == r.N);
		rep(i,a.size()) a[i] |= r.a[i];
		return *this;
	}
	Bitset& operator^=(const Bitset& r){
		assert(N == r.N);
		rep(i,a.size()) a[i] ^= r.a[i];
		return *this;
	}
	Bitset operator&(const Bitset& r) const { return Bitset(*this) &= r; }
	Bitset operator|(const Bitset& r) const { return Bitset(*this) |= r; }
	Bitset operator^(const Bitset& r) const { return Bitset(*this) ^= r; }
	Bitset operator~() const {
		Bitset r = *this;

	}

	// std::bitset::reference 的なやつ bool が 1 byte なので bool& が... みたいなのを解消できる
	struct Ref{
		ull *p;
		int pos;
		Ref(Bitset& b, int pos_){
			p = b.a.data() + (pos_ >> 6);
			pos = pos_ & 63;
		}
		operator bool() const { return (*p >> pos)&1; }
		Ref& operator=(bool x){
			if(x) *p |= 1ULL << pos;
			else *p &= ~(1ULL << pos);
			return *this;
		}
		void flip(){ *p ^= 1ULL<<pos; }
	};

	Ref operator[](int i){ return Ref(*this, i); }

	void flip(int i){ (*this)[i].flip(); }
	void setall(bool init){
		int sz = (N + 63) >> 6;
		fill(all(a), init ? -1 : 0);
		if(N) a.back() >>= (64 * a.size() - N);
	}

	// >= i
	int next(int i){
		chmax(i, 0);
		if(i >= N) return N;
		int k = i >> 6;
		
		ull x = a[k];
		int s = i & 63;
		x = (x >> s) << s;
		if(x) return (k << 6) | lowbit(x);
		for(int idx = k+1; idx < si(a); idx++) if(a[idx]){
			return (idx << 6) | lowbit(a[idx]);
		}
		return N;
	}
	// <= i
	int prev(int i){
		chmin(i, N-1);
		if(i <= -1) return -1;
		int k = i >> 6;

		if((i&63) < 63){
			ull x = a[k];
			int s = i & 63;
			x &= (1ULL << (s+1)) - 1;
			if(x) return (k << 6) | highbit(x);
			k--;
		}
		per(idx,k+1) if(a[idx]){
			return (idx << 6) | highbit(a[idx]);
		}
		return -1;
	}

	int count_range(int L, int R){
		assert(0 <= L && L <= R && R <= N);
		int cnt = 0;
		while((L<R) && (L&63)) cnt += (*this)[L++];
		while((L<R) && (R&63)) cnt += (*this)[--R];
		int l = L >> 6, r = R >> 6;
		for(int i=l;i<r;i++) cnt += popcount(a[i]);
		return cnt;
	}

	// \sum_{L <= i < R} (b[i] ? i : 0)
	ll sum_range(int L, int R){
		static int buf[1<<8] = {};
		if(buf[2] == 0){
			rep(s,1<<8){
				rep(i,8) if(s&1<<i) buf[s] += i;
			}
		}

		assert(0 <= L && L <= R && R <= N);
		ll sum = 0;
		while((L<R) && (L&63)) if((*this)[L++]) sum += L-1;
		while((L<R) && (R&63)) if((*this)[--R]) sum += R;
		int l = L >> 6, r = R >> 6;
		for(int i=l;i<r;i++){
			rep(k,8){
				sum += buf[(a[i] >> (k*8)) & 255] + popcount<uint>((a[i] >> (k*8)) & 255) * (i << 6 | k << 3);
			}
		}
		return sum;
	}
};