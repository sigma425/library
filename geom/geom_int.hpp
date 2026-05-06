namespace geom_int {
	using D = long long;

	struct Point {
		D x, y;
		int id;
		Point() : x(0), y(0) {}
		Point(D x_) : x(x_), y(0) {}
		Point(D x_, D y_) : x(x_), y(y_) {}
		Point(D x_, D y_, int id_) : x(x_), y(y_), id(id_) {}

		Point& operator+=(const Point &p) { x += p.x; y += p.y; return *this; }
		Point& operator-=(const Point &p) { x -= p.x; y -= p.y; return *this; }
		Point& operator*=(const Point &p) { return *this = *this * p;}
		Point& operator*=(D d) { x *= d; y *= d; return *this; }

		Point operator+(const Point &p) const { return Point(x+p.x, y+p.y); }
		Point operator-(const Point &p) const { return Point(x-p.x, y-p.y); }
		Point operator*(const Point &p) const { return Point(x*p.x - y*p.y, x*p.y + y*p.x); }
		Point operator-() const { return Point(-x, -y); }
		Point operator*(D d) const { return Point(x*d, y*d); }

		bool operator==(const Point &p) const { return x==p.x && y==p.y; }
		bool operator!=(const Point &p) const { return x!=p.x || y!=p.y; }
		bool operator<(const Point &p) const { return x!=p.x ? x<p.x : y<p.y; }

		D dot(const Point &p) const { return x*p.x + y*p.y; }
		D cro(const Point &p) const { return x*p.y - y*p.x; }
		D abs2() const { return x*x + y*y; }

		friend istream& operator>>(istream &i, Point &p) { return i >> p.x >> p.y; }
		friend ostream& operator<<(ostream &o, const Point &p) { return o << "(" << p.x << "," << p.y << ")"; }
	};

	struct Line {
		Point a, b;
		Line() : a(), b() {}
		Line(Point a_, Point b_) : a(a_), b(b_) {}
	};

	int sgn(D a) { return a == 0 ? 0 : (a < 0 ? -1 : 1); }
	D dot(Point a, Point b) { return a.dot(b); }
	D cro(Point a, Point b) { return a.cro(b); }

	int sgncro(Point a, Point b) { return sgn(cro(a,b)); }
	int sgncro(Point o, Point a, Point b) { return sgn(cro(a-o,b-o)); }

	// oa から見て b がどっち側にあるか ccw = 1, cw = -1, on = 0, front(b-o-a) = -2, back(o-a-b) = 2
	// 0, -2, 2 がどうでもいい場合は sgncro を直接使っても良い
	int ccw(Point o, Point a, Point b){
		a -= o, b -= o;
		int s = sgncro(a,b);
		if(s) return s;
		if(dot(a,b) < 0) return 2;
		if(dot(-a, b-a) < 0) return -2;
		return 0;
	}

	int quad(Point p){
		if(p.x > 0 && p.y >= 0) return 0;
		if(p.x <= 0 && p.y > 0) return 1;
		if(p.x < 0 && p.y <= 0) return 2;
		if(p.x >= 0 && p.y < 0) return 3;
		assert(false);
	}

	/*
		原点を中心として argsort するとき用の比較関数
		Point(0,0) を渡すと assert
	*/
	bool comp_arg(Point p, Point q){
		int s = quad(p), t = quad(q);
		if(s != t) return s < t;
		return cro(p,q) > 0;
	}

	vector<Point> conv(vector<Point> p){
		int n = p.size(), k = 0;
		sort(all(p));
		vector<Point> q(2*n);
		rep(i,n){
			while(k>=2 && sgncro(q[k-2], q[k-1], p[i]) <= 0) k--;
			q[k++] = p[i];
		}
		for(int i=n-2, t=k+1; i>=0; i--){
			while(k>=t && sgncro(q[k-2], q[k-1], p[i]) <= 0) k--;
			q[k++] = p[i];
		}
		q.resize(k-1);
		q.erase(unique(all(q)), q.end());
		return q;
	}
	
}
// using namespace geom_int;