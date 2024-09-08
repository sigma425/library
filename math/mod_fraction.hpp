/*
	整数をかけたり割ったりして最終的な値 mod M を求めるライブラリ
	例えば 1e9 choose 100 mod M とかに使える

	ModFraction::set_mod(mod) をしてから使う
		mint の mod と同じ値であるようにすること
	val() で mint としての値を返す
		整数でなかった場合assertをしているが、状況に応じて変える

	*= ll と /= ll しか実装してないけど、ModFraction どうしの乗除も当然出来る
*/
struct ModFraction{
	static inline ll mod;
	static inline vector<ll> ps;

	static void set_mod(ll mod_){
		mod = mod_;
		ps.clear();
		{	//factorize
			ll x = mod;
			for(ll i=2;i*i<=x;i++) if(x%i==0){
				ps.pb(i);
				while(x%i==0) x/=i;
			}
			if(x>1) ps.pb(x);
		}
	}

	// val = x * \prod p^e
	// x は Z/modZ
	vector<int> es;
	mint x;

	mint val(){
		if(x == 0) return 0;
		rep(i,si(ps)) if(es[i] < 0){
			// not an integer
			assert(false);
		}
		mint res = x;
		rep(i,si(ps)){
			// TODO: 高速化
			res *= mint(ps[i]).pow(es[i]);
		}
		return res;
	}

	ModFraction(ll v){
		rep(i,si(ps)){
			int e = 0;
			while(v%ps[i] == 0){
				v /= ps[i];
				e++;
			}
			es.eb(e);
		}
		x = v;
	}
	ModFraction& operator*=(ll v){
		rep(i,si(ps)){
			int e = 0;
			while(v%ps[i] == 0){
				v /= ps[i];
				e++;
			}
			es[i] += e;
		}
		x *= v;
		return *this;
	}
	ModFraction& operator/=(ll v){
		assert(v);	// div by 0
		rep(i,si(ps)){
			int e = 0;
			while(v%ps[i] == 0){
				v /= ps[i];
				e++;
			}
			es[i] -= e;
		}
		x /= v;
		return *this;
	}
};
using mfrac = ModFraction;