/*
	有理数体
	任意/正, gcd = 1 で常に持つ
	verified at https://official.contest.yandex.ru/opencupXIX/contest/9262/problems/K (Q上で連立方程式)
*/
int bsf(ll x) { return __builtin_ctzll(x); } 
ll gcd(ll a, ll b){
	a = abs(a), b = abs(b);
	if(a==0) return b;
	if(b==0) return a;
	int shift = bsf(a|b);
	a >>= bsf(a);
	do{
		b >>= bsf(b);
		if(a>b) swap(a,b);
		b -= a;
	}while(b);
	return a<<shift;
}

struct Frac{
	ll x,y;		// x/y
	Frac(ll x_ = 0):x(x_),y(1){}
	Frac(ll x_,ll y_){
		ll g = gcd(x_,y_);
		if(y_ < 0) g = -g;
		x = x_ / g;
		y = y_ / g;
	}

	Frac operator-() const { return {-x,y}; }
	Frac operator+(const Frac& r) const { return {x * r.y + y * r.x, y * r.y}; }
	Frac operator-(const Frac& r) const { return *this + (-r); }
	Frac operator*(const Frac& r) const { return {x * r.x, y * r.y}; }
	Frac operator/(const Frac& r) const { return {x * r.y, y * r.x}; }
	Frac& operator+=(const Frac& r) { return *this = *this + r; }
	Frac& operator-=(const Frac& r) { return *this = *this - r; }
	Frac& operator*=(const Frac& r) { return *this = *this * r; }
	Frac& operator/=(const Frac& r) { return *this = *this / r; }
	template<class T> friend Frac operator+(T a, const Frac& b){ return (Frac(a) += b);}
	template<class T> friend Frac operator-(T a, const Frac& b){ return (Frac(a) -= b);}
	template<class T> friend Frac operator*(T a, const Frac& b){ return (Frac(a) *= b);}
	template<class T> friend Frac operator/(T a, const Frac& b){ return (Frac(a) /= b);}
	bool operator<(const Frac& r) const { return x * r.y < y * r.x; }
	bool operator>(const Frac& r) const { return r < *this; }
	bool operator<=(const Frac& r) const { return !(r < *this); }
	bool operator>=(const Frac& r) const { return !(*this < r); }
	bool operator==(const Frac& r) const { return x == r.x && y == r.y; }
	bool operator!=(const Frac& r) const { return !(*this == r); }
	explicit operator bool() const {return x!=0;}
	Frac inv() const {
		return Frac(y,x);
	}
	friend ostream& operator<<(ostream &o,const Frac& x){
		return o << x.x << "/" << x.y;
	}
};