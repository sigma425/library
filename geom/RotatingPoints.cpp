#include "template.hpp"

/*
	概要:
		二次元平面の点集合を ax + by の順にソートする
		というのをいろんな (a,b) についてやりたい
		これはぐるっと一周させれば O(N^2 log) でできる
		実際は a,b を指定した上で色々クエリに答えるのでその情報を Point / Query に乗せる
		かなり定数倍が悪いという噂があります
	
	Point:
		x,y,id は必須
		(x,y) は distinct じゃないと動かない
	Query:
		a,b は必須
		(a,b) != (0,0) でないといけない

	RotatingPoints<Point,Query> RP(ps,qs) で呼んで、コンストラクタを直接書き換えて全てをやる
	EDIT って書いてある場所を問題ごとに変える

	verify:
		ABC344G https://atcoder.jp/contests/abc344/submissions/51711191
*/

struct Point{
	ll x,y;
	int id;
	Point(ll x_,ll y_,int id_):x(x_),y(y_),id(id_){}
};
struct Query{
	// ax+by+c >= 0 な (x,y) をカウント
	ll a,b,c;
	Query(ll a_,ll b_,ll c_):a(a_),b(b_),c(c_){}
};


template<class Point, class Query, class T = long long>
struct RotatingPoints{
	using P = pair<T,T>;
	using Pii = pair<int,int>;

	RotatingPoints(vector<Point> points, vector<Query> queries){
		int N = points.size();
		// 1 * x - eps * y の昇順
		sort(all(points),[&](Point& p, Point& q){
			if(p.x != q.x) return p.x < q.x;
			return p.y > q.y;
		});
		V<int> where(N);	// where[index] = current pos at points
		rep(i,N) where[points[i].id] = i;
		vector<Pii> events;
		rep(i,N) rep(j,N) if(i != j) events.eb(i, j);
		sort(all(events),[&](Pii l, Pii r){
			P lv,rv;
			Pii lswap,rswap;
			{
				int i = where[l.fs], j = where[l.sc];
				auto& pi = points[i], pj = points[j];
				lv = P(pi.y-pj.y, pj.x-pi.x);
				lswap = Pii(i,j);
			}
			{
				int i = where[r.fs], j = where[r.sc];
				auto& pi = points[i], pj = points[j];
				rv = P(pi.y-pj.y, pj.x-pi.x);
				rswap = Pii(i,j);
			}
			int cmp = compP(lv,rv);
			if(cmp != 0) return cmp < 0;
			return lswap < rswap;
		});

		/*
			(元の点集合での)index i,j の点 が i,j の順で並んでいるところが j,i に変わる
			この時点で points[ii], points[jj] がこれらの点を指していて、ii+1 == jj が保証される
		*/
		auto Swap = [&](int i, int j){
			int ii = where[i], jj = where[j];
			// debug 用
			// cerr << "current points: " << points << endl;
			// cerr << "swap points[" << ii << "] and points[" << jj << "]" << endl;
			assert(ii+1 == jj);
			/*
				EDIT
				swap によりなにかを再計算する場合はここに書く
			*/
			swap(points[ii],points[jj]); swap(where[i],where[j]);
		};

		/*
			クエリ (a,b) をソート
		*/
		sort(all(queries),[&](Query& l, Query& r){
			return compP(P(l.a,l.b), P(r.a,r.b)) < 0;
		});
		auto should = [&](Pii e, P ab){
			Point& pi = points[where[e.fs]], pj = points[where[e.sc]];
			P v(pi.y-pj.y, pj.x-pi.x);
			return compP(v,ab) <= 0;
		};
		
		ll ans = 0;

		int e = 0;
		for(auto& q: queries){
			while(e < si(events) && should(events[e],P(q.a,q.b))){
				auto [i,j] = events[e];
				Swap(i,j);
				e++;
			}
			/*
				EDIT
				ここで クエリ q に答える
				points が q.a * x + q.b * y の順にソートされていることが保証されている
				↓ 例: ax+by+c >= 0 な (x,y) の個数をカウント
			*/
			int lb = -1, ub = N;
			while(ub-lb>1){
				int m = (lb+ub)/2;
				auto& p = points[m];
				if(q.a*p.x + q.b*p.y + q.c >= 0) ub = m;
				else lb = m;
			}
			ans += N-ub;
		}

		cout << ans << endl;
	}

	int quad(P p){
		if(p.fs >  0 && p.sc >= 0) return 0;	// [0,pi/2)
		if(p.fs <= 0 && p.sc >  0) return 1;	// [pi/2,pi)
		if(p.fs <  0 && p.sc <= 0) return 2;	// [pi,3pi/2)
		if(p.fs >= 0 && p.sc <  0) return 3;	// [3pi/2,2pi)
		assert(false); // p shouldn't be (0,0)
	}
	// -1: left small, 1: right small, 0: equal
	int compP(P p, P q){
		int s=quad(p), t=quad(q);
		if(s!=t) return s<t ? -1 : 1;
		// オーバーフローに注意
		T le = p.sc * q.fs, ri = p.fs * q.sc;
		if(le == ri) return 0;
		return (le < ri ? -1 : 1);
	}
};