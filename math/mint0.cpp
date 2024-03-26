/*
	任意 mod
	cin >> mod してから使う InitFact とかを先にしないように注意
*/

unsigned int mod = 1;
struct ModInt{
	using uint = unsigned int;
	using ll = long long;
	using ull = unsigned long long;

	uint v;
	ModInt():v(0){}
	ModInt(ll _v):v(normS(_v%mod+mod)){}
	explicit operator bool() const {return v!=0;}
	static uint normS(const uint &x){return (x<mod)?x:x-mod;}		// [0 , 2*mod-1] -> [0 , mod-1]
	static ModInt make(const uint &x){ModInt m; m.v=x; return m;}
	ModInt operator+(const ModInt& b) const { return make(normS(v+b.v));}
	ModInt operator-(const ModInt& b) const { return make(normS(v+mod-b.v));}
	ModInt operator-() const { return make(normS(mod-v)); }
	ModInt operator*(const ModInt& b) const { return make((ull)v*b.v%mod);}
	ModInt operator/(const ModInt& b) const { return *this*b.inv();}
	ModInt& operator+=(const ModInt& b){ return *this=*this+b;}
	ModInt& operator-=(const ModInt& b){ return *this=*this-b;}
	ModInt& operator*=(const ModInt& b){ return *this=*this*b;}
	ModInt& operator/=(const ModInt& b){ return *this=*this/b;}
	ModInt& operator++(int){ return *this=*this+1;}
	ModInt& operator--(int){ return *this=*this-1;}
	template<class T> friend ModInt operator+(T a, const ModInt& b){ return (ModInt(a) += b);}
	template<class T> friend ModInt operator-(T a, const ModInt& b){ return (ModInt(a) -= b);}
	template<class T> friend ModInt operator*(T a, const ModInt& b){ return (ModInt(a) *= b);}
	template<class T> friend ModInt operator/(T a, const ModInt& b){ return (ModInt(a) /= b);}
	ModInt pow(ll p) const {
		if(p<0) return inv().pow(-p);
		ModInt a = 1;
		ModInt x = *this;
		while(p){
			if(p&1) a *= x;
			x *= x;
			p >>= 1;
		}
		return a;
	}
	ModInt inv() const {		// should be prime
		return pow(mod-2);
	}
	// ll extgcd(ll a,ll b,ll &x,ll &y) const{
	// 	ll p[]={a,1,0},q[]={b,0,1};
	// 	while(*q){
	// 		ll t=*p/ *q;
	// 		rep(i,3) swap(p[i]-=t*q[i],q[i]);
	// 	}
	// 	if(p[0]<0) rep(i,3) p[i]=-p[i];
	// 	x=p[1],y=p[2];
	// 	return p[0];
	// }
	// ModInt inv() const {
	// 	ll x,y;
	// 	extgcd(v,mod,x,y);
	// 	return make(normS(x+mod));
	// }

	bool operator==(const ModInt& b) const { return v==b.v;}
	bool operator!=(const ModInt& b) const { return v!=b.v;}
	bool operator<(const ModInt& b) const { return v<b.v;}
	friend istream& operator>>(istream &o,ModInt& x){
		ll tmp;
		o>>tmp;
		x=ModInt(tmp);
		return o;
	}
	friend ostream& operator<<(ostream &o,const ModInt& x){ return o<<x.v;}
};
using mint = ModInt;

V<mint> fact,ifact,invs;
mint Choose(int a,int b){
	if(b<0 || a<b) return 0;
	return fact[a] * ifact[b] * ifact[a-b];
}
void InitFact(int N){	//[0,N]
	N++;
	fact.resize(N);
	ifact.resize(N);
	invs.resize(N);
	fact[0] = 1;
	rep1(i,N-1) fact[i] = fact[i-1] * i;
	ifact[N-1] = fact[N-1].inv();
	for(int i=N-2;i>=0;i--) ifact[i] = ifact[i+1] * (i+1);
	rep1(i,N-1) invs[i] = fact[i-1] * ifact[i];
}