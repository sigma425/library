struct P{
	using D = int;
	D x, y;
	int id;
	P() : x(0), y(0) {}
	P(D x_, D y_) : x(x_), y(y_) {}

	P& operator+=(const P &p) { x += p.x; y += p.y; return *this; }
	P& operator-=(const P &p) { x -= p.x; y -= p.y; return *this; }
	P& operator*=(const P &p) { return *this = *this * p;}
	P& operator*=(D d) { x *= d; y *= d; return *this; }

	P operator+(const P &p) const { return P(x+p.x, y+p.y); }
	P operator-(const P &p) const { return P(x-p.x, y-p.y); }
	P operator*(const P &p) const { return P(x*p.x - y*p.y, x*p.y + y*p.x); }
	P operator-() const { return P(-x, -y); }
	P operator*(D d) const { return P(x*d, y*d); }

	bool operator==(const P &p) const { return x==p.x && y==p.y; }
	bool operator!=(const P &p) const { return x!=p.x || y!=p.y; }
	bool operator<(const P &p) const { return x!=p.x ? x<p.x : y<p.y; }

	friend istream& operator>>(istream &i, P &p) { return i >> p.x >> p.y; }
	friend ostream& operator<<(ostream &o, const P &p) { return o << "(" << p.x << "," << p.y << ")"; }
};
