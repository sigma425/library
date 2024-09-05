/*
	折れ線を保つDP
	できること : 
		f'(x) := min_[x+l <= y <= x+r] f(y)
		f'(x) := f(x) + |x-a|
		given a -> compute f(a)
	f(a) の計算は O(N) で、これをlogにしようとするとBITを保つ必要が出てくる、やりたくない
	まあ普通はbottomが答えになる

	verified at 
		1228(CF588) F
		ARC70 E
*/

struct Slope{
	using D = ll;
	priority_queue<D> L;
	priority_queue<D,V<D>,greater<D>> R;
	D offL = 0, offR = 0;
	D bottom = 0;

	// initially f(x) = 0

	void Min(D l,D r){	// f'(x) := min_[x+l <= y <= x+r] f(y)
		assert(l <= r);
		offL -= r;
		offR -= l;
	}
	void Add(D s){		// f'(x) := f(x) + |x-s|
		offL -= s, offR -= s;
		if(L.empty()){
			L.push(0-offL); R.push(0-offR);
			offL += s, offR += s;
			return;
		}
		D le = L.top() + offL, ri = R.top() + offR;
		if(le <= 0 && 0 <= ri){
			L.push(0-offL); R.push(0-offR);
		}else if(ri < 0){
			bottom += -ri;
			L.push(ri-offL); R.pop();
			R.push(0-offR); R.push(0-offR);
		}else{
			bottom += le;
			R.push(le-offR); L.pop();
			L.push(0-offL); L.push(0-offL);
		}
		offL += s, offR += s;
	}
	void AddConst(D c){	// f'(x) = f(x) + c
		bottom += c;
	}
	D f(D s){		//O(N) :(
		offL -= s, offR -= s;
		D le = L.top() + offL, ri = R.top() + offR;
		D res = bottom;
		if(le <= 0 && 0 <= ri){
		}else if(ri < 0){
			auto cp = R;
			rep1(k,cp.size()){
				R.pop();
				D nri = R.empty() ? 0 : R.top() + offR;
				if(nri >= 0){
					R = cp;
					res += (-ri) * k;
					break;
				}
				res += (nri-ri) * k;
				ri = nri;
			}
		}else{
			auto cp = L;
			rep1(k,cp.size()){
				L.pop();
				D nle = L.empty() ? 0 : L.top() + offL;
				if(nle <= 0){
					L = cp;
					res += le * k;
					break;
				}
				res += (le-nle) * k;
				le = nle;
			}
		}
		offL += s, offR += s;
		return res;
	}
};
