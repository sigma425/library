/*
	素因数分解 1 <= n <= 10^18
	pollard_rho's algorithm
	O(n^0.25 polylog(n)) くらいらしい
*/

template<class T>
T gcd(T a,T b){
	a = abs(a), b = abs(b);
	if(b==0) return a;
	return gcd(b,a%b);
}
template<class T, class U>
T pow_mod(T x, U p, T mod){
	assert(p>=0);
	x %= mod;
	T a = 1 % mod;
	while(p){
		if(p&1) a = a*x%mod;
		x = x*x%mod;
		p >>= 1;
	}
	return a;
}
using ll = long long;
bool isprime(ll n){
	if(n<=1) return 0;
	if(n==2) return 1;
	if(n%2==0) return 0;
	ll d = n-1;
	while(d%2==0) d/=2;
	static const vector<ll> alist{2,3,5,7,11,13,17,19,23,29,31,37};
	for(ll a: alist){
		if(n<=a) break;
		ll t = d;
		ll y = pow_mod<__int128>(a,t,n);
		while(t!=n-1 && y!=1 && y!=n-1){
			y = __int128(y)*y%n;
			t<<=1;
		}
		if(y!=n-1 && t%2==0) return 0;
	}
	return 1;
}

ll pollard_single(ll n){
	if(isprime(n)) return n;
	if(!(n&1)) return 2;
	ll ph,x,y,p;
	auto f = [&](ll x, ll n){ return (__int128(x)*x+ph)%n; };
	for(ph=1;;ph++){
		x=ph; y=f(x,n); p=gcd(y-x,n);
		while(p==1){
			x=f(x,n); y=f(f(y,n),n); p=gcd((y-x+n)%n,n)%n;
		}
		if(p==0 || p==n) continue;
		return p;
	}
	assert(0);
}

vector<ll> pollard(ll n){
	if(n==1) return {};
	ll x = pollard_single(n);
	if(x==n) return {x};
	vector<ll> le = pollard(x);
	vector<ll> ri = pollard(n/x);
	for(ll d: ri) le.push_back(d);
	sort(all(le));
	return le;
}

ll totient(ll n){
	auto v = pollard(n);
	map<ll,int> mp; for(ll p: v) mp[p]++;
	ll phi = 1;
	for(auto [p,r]: mp){
		for(int _=0;_<r-1;_++) phi *= p;
		phi *= p-1;
	}
	return phi;
}
