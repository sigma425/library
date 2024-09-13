/*
	mint mod 2^61 - 1
	だいたい rolling hash 用
	veryfy: ucup3-9 A https://contest.ucup.ac/submission/555578
*/
struct ModInt61 {
	using mint = ModInt61;

	static constexpr long long mod = (1ULL << 61) - 1;

	unsigned long long v;

	ModInt61() : v(0) {}
	ModInt61(ll v_) {
		v_ %= mod;
		if (v_ < 0) v_ += mod;
		v = v_;
	}

	explicit operator bool() const {return v!=0;}

	mint& operator++() {
		v++;
		if (v == umod()) v = 0;
		return *this;
	}
	mint& operator--() {
		if (v == 0) v = umod();
		v--;
		return *this;
	}
	mint operator++(int) {
		mint result = *this;
		++*this;
		return result;
	}
	mint operator--(int) {
		mint result = *this;
		--*this;
		return result;
	}

	mint& operator+=(const mint& rhs) {
		v += rhs.v;
		if (v >= umod()) v -= umod();
		return *this;
	}
	mint& operator-=(const mint& rhs) {
		v -= rhs.v;
		if (v >= umod()) v += umod();
		return *this;
	}
	mint& operator*=(const mint& rhs) {
		__uint128_t t = (__uint128_t) v * rhs.v;

		v = (unsigned long long)((t >> 61) + (t & umod()));
		v = (v >= umod()) ? v - umod() : v;

		return *this;
	}
	mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

	mint operator+() const { return *this; }
	mint operator-() const { return mint() - *this; }

	mint pow(ll n) const {
		if(n < 0) return inv().pow(-n);
		mint x = *this, r = 1;
		while (n) {
			if (n & 1) r *= x;
			x *= x;
			n >>= 1;
		}
		return r;
	}
	mint inv() const {
		assert(v);
		return pow(umod() - 2);
	}

	template<class T> friend mint operator+(T a, const mint& b){ return (mint(a) += b);}
	template<class T> friend mint operator-(T a, const mint& b){ return (mint(a) -= b);}
	template<class T> friend mint operator*(T a, const mint& b){ return (mint(a) *= b);}
	template<class T> friend mint operator/(T a, const mint& b){ return (mint(a) /= b);}
	friend bool operator==(const mint& lhs, const mint& rhs) { return lhs.v == rhs.v; }
	friend bool operator!=(const mint& lhs, const mint& rhs) { return lhs.v != rhs.v; }
	friend bool operator<(const mint& lhs, const mint& rhs) { return lhs.v < rhs.v; }

	friend istream& operator>>(istream &i, mint& x){
		ll tmp; i >> tmp;
		x = mint(tmp);
		return i;
	}
	friend ostream& operator<<(ostream &o,const mint& x){ return o<<x.v;}

	static constexpr unsigned long long umod() { return mod; }
};