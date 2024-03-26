/*
	Convex Hull Trick (追加する直線の傾きが単調なバージョン)

	初期化:
		calc_min: true なら min, false なら max を計算
		T: a,b,x,y などの型
		a*b くらいの値が一箇所だけ出てくる オーバーフローに注意
	add(a,b):
		直線 y = ax+b を追加
		aは広義単調増加あるいは広義単調減少 勝手に判断してくれる
	get(x):
		min (あるいはmax) {ax+b}
		初期化時にtemplate引数でminかmaxか指定
		O(log N)
	get_incr / get_decr
		getのクエリに単調性がある場合 amortized O(1)
		嫌だと思うんだけど、CHT_old を使ってほしい ごめん

	verify:
		https://contest.ucup.ac/submission/364008
*/

template<bool calc_min, typename T>
struct ConvexHullTrick{
	using P = pair<T,T>;
	deque<P> q;
	ConvexHullTrick() {}
	void add(T a, T b){
		if(!calc_min) a = -a, b = -b;
		P p(a,b);
		if(q.empty()){
			q.push_back(p); return;
		}
		if(q.back().fs >= a){
			if(a == q.back().fs){
				if(q.back().sc <= b) return;
				q.pop_back();
			}
			while(si(q) >= 2 && !necessary(q[si(q)-2],q.back(),p)){
				q.pop_back();
			}
			q.push_back(p);
		}else if(a >= q.front().fs){
			if(a == q.front().fs){
				if(q.front().sc <= b) return;
				q.pop_front();
			}
			while(si(q) >= 2 && !necessary(p,q.front(),q[1])){
				q.pop_front();
			}
			q.push_front(p);
		}else{
			assert(false); // aが単調でない
		}
	}
	bool necessary(P l, P m, P r){
		// m が最小値を取ることがあるか?
		// assume: 傾き la > ma > ra
		assert(l.fs > m.fs && m.fs > r.fs);
		// (mb-lb)/(la-ma) < (rb-mb)/(ma-ra) 分母は共に正
		// 通分すると a*b くらいの値が登場する オーバーフローに注意
		// int128にすら入らなければ帯分数みたいにやるのもあり
		return (m.sc-l.sc) * (m.fs-r.fs) < (r.sc-m.sc) * (l.fs-m.fs);
	}
	T get(T x){
		assert(!q.empty());
		auto f_i = [&](int i){ return q[i].fs * x + q[i].sc; };
		int l = 0, r = si(q);
		while(r-l > 1){
			int m = (l+r)/2;
			if(f_i(m-1) <= f_i(m)) r = m;
			else l = m;
		}
		return f_i(l) * (calc_min ? 1 : -1);
	}
};