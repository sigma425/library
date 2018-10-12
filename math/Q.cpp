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

struct F{
	ll x,y;		// x/y
	F():x(0),y(1){}
	F(ll x):x(x),y(1){}
	F(ll x,ll y):x(x),y(y){}

	F norm(ll x,ll y) const {
		ll g = gcd(x,y);
		x /= g, y /= g;
		if(y<0){
			x = -x;
			y = -y;
		}
		return F(x,y);
	}

	F operator+(const F& r) const {
		ll X = x * r.y + y * r.x;
		ll Y = y * r.y;
		return norm(X,Y);
	}
	F operator-(const F& r) const {
		ll X = x * r.y - y * r.x;
		ll Y = y * r.y;
		return norm(X,Y);
	}
	F operator*(const F& r) const {
		ll X = x * r.x;
		ll Y = y * r.y;
		return norm(X,Y);
	}
	F operator/(const F& r) const {
		ll X = x * r.y;
		ll Y = y * r.x;
		return norm(X,Y);
	}
	bool operator==(const F& r) const {
		return x == r.x && y == r.y;
	}
	friend ostream& operator<<(ostream &o,const F& x){
		return o<<x.x<<"/"<<x.y;
	}
};
