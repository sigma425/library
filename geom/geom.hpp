namespace geom {
	using D = double;

	const D inf = 1e50;
	const D eps = 1e-9;
	const D pi = 3.14159265358979323846;


	struct Point {
		D x, y;
		Point() : x(0), y(0) {}
		Point(D x_) : x(x_), y(0) {}
		Point(D x_, D y_) : x(x_), y(y_) {}

		Point& operator+=(const Point &p) { x += p.x; y += p.y; return *this; }
		Point& operator-=(const Point &p) { x -= p.x; y -= p.y; return *this; }
		Point& operator*=(const Point &p) { return *this = *this * p;}
		Point& operator/=(const Point &p) { return *this = *this / p;}
		Point& operator*=(D d) { x *= d; y *= d; return *this; }
		Point& operator/=(D d) { x /= d; y /= d; return *this; }

		Point operator+(const Point &p) const { return Point(x+p.x, y+p.y); }
		Point operator-(const Point &p) const { return Point(x-p.x, y-p.y); }
		Point operator*(const Point &p) const { return Point(x*p.x - y*p.y, x*p.y + y*p.x); }
		Point operator/(const Point &p) const { return Point(x*p.x + y*p.y, y*p.x - x*p.y) / p.abs2(); }
		Point operator-() const { return Point(-x, -y); }
		Point operator*(D d) const { return Point(x*d, y*d); }
		Point operator/(D d) const { return Point(x/d, y/d); }

		bool operator==(const Point &p) const { return x==p.x && y==p.y; }
		bool operator!=(const Point &p) const { return x!=p.x || y!=p.y; }
		bool operator<(const Point &p) const { return x!=p.x ? x<p.x : y<p.y; }

		D dot(const Point &p) const { return x*p.x + y*p.y; }
		D cro(const Point &p) const { return x*p.y - y*p.x; }
		D abs2() const { return x*x + y*y; }
		D abs() const { return sqrt(abs2()); }

		Point rot90() const { return Point(-y, x); }

		friend istream& operator>>(istream &i, Point &p) { return i >> p.x >> p.y; }
		friend ostream& operator<<(ostream &o, const Point &p) { return o << "(" << p.x << "," << p.y << ")"; }
	};

	struct Line {
		Point a, b;
		Line() : a(), b() {}
		Line(Point a_, Point b_) : a(a_), b(b_) {}
	};

	using Segment = Line;	// 線分 ab
	using Ray = Line;		// 半直線 ab

	struct Circle {
		Point p;
		D r;
		Circle() : p(), r(0) {}
		Circle(Point p_, D r_) : p(p_), r(r_) {}
	};

	int sgn(D a) { return abs(a) < eps ? 0 : (a < 0 ? -1 : 1); }
	int sgn(D a, D b) { return sgn(a - b); }
	D dot(Point a, Point b) { return a.dot(b); }
	D cro(Point a, Point b) { return a.cro(b); }

	int sgncro(Point a, Point b) { return sgn(cro(a,b)); }
	int sgncro(Point o, Point a, Point b) { return sgn(cro(a-o,b-o)); }

	// oa から見て b がどっち側にあるか ccw = 1, cw = -1, on = 0, front(b-o-a) = -2, back(o-a-b) = 2
	int ccw(Point o, Point a, Point b){
		a -= o, b -= o;
		int s = sgncro(a,b);
		if(s) return s;
		if(!sgn(a.abs()) || !sgn((a-b).abs())) return 0;	// endpoint -> on
		if(dot(a,b) < 0) return 2;
		if(dot(-a, b-a) < 0) return -2;
		return 0;
	}

	// ベクトル a を ベクトル b に射影したベクトル
	Point proj(Point a, Point b) { return b * dot(a,b) / b.abs2(); }
	// 垂線の足
	Point perp(Line l, Point p) {
		D t = dot(p-l.a, l.a-l.b) / (l.a-l.b).abs2();
		return l.a + (l.a-l.b) * t;
	}
	// 線分 (a,b) の垂直二等分線
	Line perp_bisect(Point a, Point b) {
		Point m = (a + b) / 2;
		Point d = (b - a).rot90();
		return Line(m, m + d);
	}

	// 線対称な点
	Point refl(Line l, Point p) { return perp(l,p) * 2 - p; }
	// 2直線が平行か
	bool ispal(Line a, Line b) { return sgn(cro(a.a-a.b, b.a-b.b)) == 0; }
	// 2直線が同じ直線か
	bool sameLL(Line a, Line b) { return ispal(a,b) && sgn(cro(a.a-a.b, b.a-a.b)) == 0; }
	// 2直線が交わる or 一致するか
	bool iLL(Line a, Line b) { return !ispal(a,b) || sameLL(a,b); }
	// 直線と線分が交わるか
	bool iLS(Line l, Segment s) { return sgncro(l.a,l.b,s.a) * sgncro(l.a,l.b,s.b) <= 0; }
	// 直線と線分が交わるか 端点のみで交わるケースは false 線分が直線に乗ってるなら true
	bool iLSex(Line l, Segment s) {
		int as = sgncro(l.a,l.b,s.a), bs = sgncro(l.a,l.b,s.b);
		if(as == 0 && bs == 0) return true;	// 線分が直線に乗ってる
		return as * bs < 0;
	}
	// 点が直線の上にあるか
	bool onL(Line l, Point p) { return sgncro(l.a,l.b,p) == 0; }
	// 2線分が交わるか
	bool iSS(Segment a, Segment b) {
		return ccw(a.a,a.b,b.a) * ccw(a.a,a.b,b.b) <= 0 && ccw(b.a,b.b,a.a) * ccw(b.a,b.b,a.b) <= 0;
	}
	// 点が線分の上にあるか
	bool onS(Segment s, Point p) { return ccw(s.a,s.b,p) == 0; }

	D dLP(Line l, Point p) { return (perp(l,p)-p).abs(); }
	D dLS(Line l, Segment s) { return iLS(l,s) ? 0 : min(dLP(l,s.a),dLP(l,s.b)); }
	D dSP(Segment s, Point p) {
		Point q = perp(s,p);
		D res = min((p-s.a).abs(),(p-s.b).abs());
		if(onS(s,q)) res = min(res,(p-q).abs());
		return res;
	}
	D dSS(Segment a, Segment b) {
		if(iSS(a,b)) return 0;
		return min({dSP(a,b.a),dSP(a,b.b),dSP(b,a.a),dSP(b,a.b)});
	}
	Point intLL(Line a, Line b) {
		D t = cro(a.b-a.a, a.b-b.a) / cro(a.b-a.a, b.b-b.a);
		return b.a + (b.b-b.a) * t;
	}

	// 外心
	Point circumcenter(Point a, Point b, Point c) {
		Line l1 = perp_bisect(a, b);
		Line l2 = perp_bisect(a, c);
		return intLL(l1, l2);
	}
}