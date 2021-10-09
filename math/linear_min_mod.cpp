/*
	x = min{ 0 <= i | l <= a*i%m <= r}
	ax = a*x % m
	ないなら-1
	m > 0
	a,m,l,r <= 10^18 くらいまでOK
	O(log m)
	verify: ストレステスト
*/

/*
	x = min{ 0 <= i | l <= a*i%m <= r}
	ax = a*x % m
	ないなら-1
	m > 0
	a,m,l,r <= 10^18 くらいまでOK
	O(log m)
	verified: ストレステスト
*/

struct firstHitRem{
	ll x,ax;
	firstHitRem(ll a,ll m,ll l,ll r){
		assert(m > 0);
		chmax(l,0); chmin(r,m-1);
		if(l > r){
			x = ax = -1; return;
		}
		a = ((a%m)+m)%m;
		
		ax = getAXmodB(a,m,l,r);
		if(ax == -1){
			x = ax = -1; return;
		}
		auto e = ext_gcd(a,m);
		ll g = e.g;
		a/=g, ax/=g, m/=g;
		x = __int128((e.x+m)%m)*ax%m;
		ax *= g;
	}
	
	ll getAXmodB(ll a,ll b,ll lw,ll up){
		if(lw == 0) return 0;
		if(a == 0) return -1;
		ll p = (lw+a-1)/a*a;
		if(lw<=p && p<=up) return p;
		ll res = getAXmodB(b%a,a,p-up,p-lw);
		if(res == -1) return -1;
		return p-res;
	}
	struct EG { ll g, x, y; };
	EG ext_gcd(ll a, ll b) {
		if(b == 0){
			if (a >= 0) return EG{a, 1, 0};
			else return EG{-a, -1, 0};
		}else{
			auto e = ext_gcd(b, a % b);
			return EG{e.g, e.y, e.x - a / b * e.y};
		}
	}
	ll inv_mod(ll v, ll md) {
		auto z = ext_gcd(v, md).x;
		return (z % md + md) % md;
	}
};


/*
	S = {  ai%m | 1 <= i <= n }
	T = { -ai%m | 1 <= i <= n }

	x = S の最小値をとる i (のうち最小)
	y = T の最小値をとる i (のうち最小)
	l = min S, r = min T

	円環に等差数列っぽく点を置いていったときの 0 からの左右への距離と、そのindexみたいな

	O(log)
	verify: ストレステスト
*/
struct minMaxRem{
	ll x,y,l,r;
	minMaxRem(ll a,ll m,ll n){
		assert(m > 0); assert(n > 0);
		a = (a%m+m)%m;
		x = 1, y = 1, l = a, r = m-a;
		for(ll k;;){
			if(l == 0){ y = x; r = l; return; }
			k = r/l;
			if(chmin(k,(n-y)/x)) { y += k*x; r -= k*l; return;}
			y += k*x; r -= k*l;
			if(!r){ x = y; l = r; return; }
			k = l/r;
			if(chmin(k,(n-x)/y)) { x += k*y; l -= k*r; return;}
			x += k*y; l -= k*r;
		}
	}
};


/*
	three-gap theorem
	0, a%m, .. , (n-1)a%m を円環上に置き、各 x\in [0,n) に対して、その点から次の点までの距離を求める d[x]とする
	実は d[0], .. , d[n-1] は p,..,p, p+q,..,p+q, q,..,q みたいな形をしている 特に、たかだか3種類
	{num,val} の vector を返す
		- num > 0
		- 同じvalは連続しない
		- \sum num = n
		- \sum val = m

	一周して0をふむとき、　つまり n-1 >= m/gcd(a,m) の時は呼んじゃだめ！！！ assertしている

	O(log)
	verify: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2387
*/
V<pair<ll,ll>> threegap(ll a,ll m,ll n){
	using P = pair<ll,ll>;
	assert(m > 0); assert(n >= 1);
	a = (a%m+m)%m;
	assert(n-1 < m/__gcd(a,m));				// shouldn't have two points on the same place
	if(n == 1){
		return {P(1,m)};
	}
	auto f = minMaxRem(a,m,n-1);
	ll x = f.x, y = f.y, l = f.l, r = f.r;
	P pre(n-x,l);
	P mid(n-(n-x)-(n-y),l+r);
	P suf(n-y,r);
	V<P> res;
	for(P p: {pre,mid,suf}) if(p.fs){
		if(!res.empty() && res.back().sc == p.sc) res.back().fs += p.fs;
		else res.pb(p);
	}
	return res;
}



// おまけ

void test_firstHitRem(){
	auto brute = [&](ll a,ll m,ll l,ll r){
		for(int i=0;;i++){
			int v = (i*a%m+m)%m;
			if(i>0 && v==0) return pair<ll,ll>(-1,-1);
			if(l<=v && v<=r) return pair<ll,ll>(i,v);
		}
		assert(0);
	};
	int X = 50;
	rep1(m,X){
		for(int a=-X;a<=X;a++){
			for(int l=-X;l<=X;l++){
				for(int r=-X;r<=X;r++){
					auto f = firstHitRem(a,m,l,r);
					auto god = brute(a,m,l,r);
					assert(f.x == god.fs && f.ax == god.sc);
				}
			}
		}
	}
}

// O(log^2)
ll getMinLinearMod(ll a,ll m,ll n){
	assert(n > 0);
	assert(m > 0);
	a = (a%m+m)%m;

	if(m/gcd(a,m) <= n) return m/gcd(a,m);
	ll lb = 0, ub = m;
	while(ub-lb>1){
		ll mid = (ub+lb)/2;
		ll x = FirstHitMod(a,m,1,mid);
		if(x != -1 && x <= n) ub = mid;
		else lb = mid;
	}
	// ax = ub
	return FirstHitMod(a,m,1,ub);
}