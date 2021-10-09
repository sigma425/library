/*
	return sum_{ i \in [0,n) } floor((a*i+b)/m)

	O(log(m))
	計算途中で max(a,b,m,n)^3 くらいの大きさにはなるのでオーバーフローに注意
	渡す値は long long
	返り値の型を template にしていて、
		- 大丈夫な時は普通に ll / __int128
		- 問題によっては mint
		- 途中でオーバーフローするかもだけど最終的にはll, みたいなケースでは ull を指定すると安全

	verify:
		https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2387
*/

template<class D>
D sumFloor(ll a, ll b, ll m, ll n){
	assert(m > 0);
	assert(n >= 0);
	assert(a >= 0);			// サボり
	// assert(b >= 0);		// OK!

	if(n == 0) return 0;

	D res = 0;
	{	// a %= m
		ll p = a/m;
		if(n%2 == 0) res += D(n/2) * (n-1) * p;			// big!!
		else res += D((n-1)/2) * n * p;
		a %= m;
	}
	{	// b %= m;
		ll p = divFloor(b,m);
		res += D(n) * p;
		b -= p*m;
	}
	if(a == 0) return res;
	ll top = (__int128(a)*(n-1)+b)/m;			// overflow?
	res += D(top) * n;
	ll h = (b+m)/m;
	if(h <= top) res -= sumFloor<D>(m,m*h-(b+1),a,top-h+1) + top-h+1;
	return res;
}

// i \in [l,r)
template<class D>
D sumFloor(ll a, ll b, ll m, ll l, ll r){
	return sumFloor<D>(a,b,m,r) - sumFloor<D>(a,b,m,l);
}