/*
	素数判定 n <= 10^18
	この範囲なら37以下の素数を使って素数テストすれば十分らしい
	オーバーフロー注意
*/
#include<bits/stdc++.h>
using namespace std;

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

int main(){
	while(true){
		ll n;
		cin>>n;
		if(isprime(n)) puts("prime");
		else puts("composite");
	}
}