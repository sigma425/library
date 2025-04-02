
/*
	[l,r) たちの union を保持
	segs に [l,r) たちが入っている
	add(l,r) : [l,r) を追加
	find(x) : x を含む区間を返す 存在しない場合は no = P(0,0)

	double でも動くように書いたつもりだが verify はしてない
*/
template<class T = int>
struct SegmentUnion {
	using P = pair<T,T>;
	static constexpr P no = P(0,0);
	set<P> segs;
	SegmentUnion() {}

	void add(T l, T r) {
		if(l >= r) return;
		auto it = segs.lower_bound(P(l,numeric_limits<T>::min()));
		if(it != segs.begin()) {
			it--;
			if(l <= it->sc){
				l = it->fs;
				r = max(r,it->sc);
				it = segs.erase(it);
			}else{
				it++;
			}
		}
		while(it != segs.end() && it->fs <= r) {
			r = max(r,it->sc);
			it = segs.erase(it);
		}
		segs.insert(P(l,r));
	}

	/*
		x を含む区間を返す 存在しない場合は no = P(0,0)
	*/
	P find(T x) {
		auto it = segs.lower_bound(P(x,numeric_limits<T>::max()));
		if(it == segs.begin()) return no;
		it--;
		if(it->fs <= x && x < it->sc) return *it;
		return no;
	}
};