/*
	lw <= ax mod b <= up なる x に対し、
	getAXmodB : ax を返す
	getMin : xを返す

	verified : 手元
*/

/*
	!!! return ax mod b !!! where x is
	min x>=0 s.t. lw <= ax mod b <= up
	no -> -1

	gcdと完全に一緒、上限ll,O(log)
*/
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
ll inv_mod(ll x, ll md) {
	auto z = ext_gcd(x, md).x;
	return (z % md + md) % md;
}

/*
	!!! return x !!! where x is
	min x>=0 s.t. lw <= ax mod b <= up
	no -> -1

	gcdと完全に一緒、上限ll,O(log)

	getaxmodbの2.5倍くらい遅いから、ほしいときだけこっち
*/
ll getMin(ll a,ll b,ll lw,ll up){
	assert(a >= 0 && b > 0 && 0 <= lw && lw <= up && up < b);
	ll ax = getAXmodB(a,b,lw,up);
	if(ax == -1) return -1;
	auto e = ext_gcd(a,b);
	ll g = e.g;
	a/=g,ax/=g,b/=g;
	return __int128((e.x+b)%b)*ax%b;
}
