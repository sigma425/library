/*
	(x[i], y[i]) からなる列に対して、
	- (区間) max y[i]
	- (区間) a >= 0 に対し、 y[i] := y[i] + a * x[i]
	- (区間) b に対し、y[i] := y[i] + b
	を segbeats に乗せる用の struct
	verify:
		https://atcoder.jp/contests/jsc2024-final/submissions/65805225
		https://contest.ucup.ac/submission/1056867 (indexつき、TLE放棄)
*/

template<class T = ll>
struct Kinetic {
	using P = pair<T,T>;
	P mx;			// max y をもつ (x,y)
	T t;			// そのノード以下のどこかでmaxが切り替わる次のタイミング
	T lza, lzb;		// lazy a,b

	static constexpr T MX = numeric_limits<T>::max();
	static constexpr P no = P(MX, MX);						// no とは一切の演算をしていないのでなんでもよい
	Kinetic() : mx(no), t(MX), lza(0), lzb(0) {}
	Kinetic(T x, T y) : mx(P(x,y)), t(MX), lza(0), lzb(0) {}
	Kinetic(P xy) : mx(xy), t(MX), lza(0), lzb(0) {}
	Kinetic(P mx_, T t_) : mx(mx_), t(t_), lza(0), lzb(0) {}

	static Kinetic merge(const Kinetic& l, const Kinetic& r){
		if(l.mx == no) return {r.mx, r.t};					// lazy が残ってはいけないので、return r はダメ
		if(r.mx == no) return {l.mx, l.t};
		P a = l.mx, b = r.mx;
		if(a.sc < b.sc) swap(a,b);
		Kinetic res;
		res.mx = a;
		res.t = min(l.t, r.t);
		if(a.fs < b.fs) chmin(res.t, (a.sc-b.sc) / (b.fs-a.fs));	// 入れ替わるタイミング
		return res;
	}
	void push(Kinetic& l, Kinetic& r){
		l.add_ax(lza); l.add_b(lzb);
		r.add_ax(lza); r.add_b(lzb);
		lza = lzb = 0;
	}
	bool add_ax(T a){
		assert(a >= 0);
		if(mx == no) return true;
		if(t < a) return false;		// むずい
		mx.sc += a * mx.fs;
		lza += a;
		t -= a;
		return true;
	}
	bool add_b(T b){
		if(mx == no) return true;
		mx.sc += b;
		lzb += b;
		return true;
	}

	T getmaxy() const { return mx.sc; }
};