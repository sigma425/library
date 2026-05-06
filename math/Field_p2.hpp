/*
	F_p^2 := F_p[x] / (x^2 - g)
	g は平方非剰余
	mint を setmodにするとかそういうのはやってない

	verify: Xmas Contest 2025 F https://atcoder.jp/contests/xmascon25/submissions/71939821
*/

template<unsigned int p, unsigned int g>
struct Field_p2 {
	// using mint = ModInt<p>;
	mint a, b; // a + bx

	Field_p2(): a(0), b(0) {}
	Field_p2(mint _a): a(_a), b(0) {}
	Field_p2(ll _a): a(_a), b(0) {}
	Field_p2(mint _a, mint _b): a(_a), b(_b) {}
	Field_p2(ll _a, ll _b): a(_a), b(_b) {}

	explicit operator bool() const { return a || b; }

	Field_p2 operator+(const Field_p2& x) const { return Field_p2(a + x.a, b + x.b); }
	Field_p2 operator-(const Field_p2& x) const { return Field_p2(a - x.a, b - x.b); }
	Field_p2 operator*(const Field_p2& r) const { return Field_p2(a * r.a + b * r.b * mint(g), a * r.b + b * r.a); }
	Field_p2 inv() const {
		// (a + bx)^-1 = (a - bx) / (a^2 - b^2 g)
		mint denom = a * a - b * b * mint(g);
		denom = denom.inv();
		return Field_p2(a * denom, -b * denom);
	}
	Field_p2 operator/(const Field_p2& r) const { return *this * r.inv(); }
	Field_p2 operator-() const { return Field_p2(-a, -b); }

	Field_p2& operator+=(const Field_p2& r){ return *this = *this + r; }
	Field_p2& operator-=(const Field_p2& r){ return *this = *this - r; }
	Field_p2& operator*=(const Field_p2& r){ return *this = *this * r; }
	Field_p2& operator/=(const Field_p2& r){ return *this = *this / r; }
	template<class T> friend Field_p2 operator+(T a, const Field_p2& r){ return (Field_p2(a) += r); }
	template<class T> friend Field_p2 operator-(T a, const Field_p2& r){ return (Field_p2(a) -= r); }
	template<class T> friend Field_p2 operator*(T a, const Field_p2& r){ return (Field_p2(a) *= r); }
	template<class T> friend Field_p2 operator/(T a, const Field_p2& r){ return (Field_p2(a) /= r); }

	Field_p2 pow(ll e) const {
		if(e<0) return inv().pow(-e);
		Field_p2 a = 1;
		Field_p2 x = *this;
		while(e){
			if(e&1) a *= x;
			x *= x;
			e >>= 1;
		}
		return a;
	}

	bool operator==(const Field_p2& x) const { return a == x.a && b == x.b; }
	bool operator!=(const Field_p2& x) const { return !(*this == x); }

	friend ostream& operator<<(ostream &o, const Field_p2& x){
		return o << x.a << "+" << x.b << "x";
	}
};