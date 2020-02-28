/*
	g = gcd(a, b) >= 0
	ax + by = g
*/
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
/*
	xz + md? = g
*/
ll inv_mod(ll x, ll md) {
	auto z = ext_gcd(x, md).x;
	return (z % md + md) % md;
}

/*
	(rem,mod) 0 <= rem < mod
	mod が互いに素である必要はない
	no -> (0,-1)
	verify: CF/724(IntelCodeFinal)/C.cpp
	TODO: garner の mods 自由バージョン
*/
pair<ll,ll> crt(const V<ll>& rs, const V<ll>& ms){
	int N = rs.size();
	ll r = 0, m = 1;
	rep(i,N){
		ll ri = rs[i], mi = ms[i];
		// assert(0 <= ri && ri < mi);
		auto e = ext_gcd(m,mi);
		ll g = e.g, m_inv = e.x;
		if((ri-r)%g) return {0,-1};
		ll tmp = (ri-r)/g * m_inv % (mi/g);
		r += m * tmp;
		m *= mi / g;
	}
	return {(r%m+m)%m,m};
}

// binary gcd
int bsf(ll x) { return __builtin_ctzll(x); } 
ll gcd(ll a, ll b){
	a = abs(a), b = abs(b);
	if(a==0) return b;
	if(b==0) return a;
	int shift = bsf(a|b);
	a >>= bsf(a);
	do{
		b >>= bsf(b);
		if(a>b) swap(a,b);
		b -= a;
	}while(b);
	return a<<shift;
}


//↓非再帰 extgcd
ll extgcd(ll a,ll b,ll &x,ll &y){
	ll u[]={a,1,0},v[]={b,0,1};
	while(*v){
		ll t=*u/ *v;
		rep(i,3) swap(u[i]-=t*v[i],v[i]);
	}
	if(u[0]<0) rep(i,3) u[i]=-u[i];
	x=u[1],y=u[2];
	return u[0];
}