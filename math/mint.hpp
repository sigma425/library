template<unsigned int mod_>
struct ModInt{	
	using uint = unsigned int;
	using ll = long long;
	using ull = unsigned long long;

	constexpr static uint mod = mod_;

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

	bool operator==(const ModInt& b) const { return v==b.v;}
	bool operator!=(const ModInt& b) const { return v!=b.v;}
	bool operator<(const ModInt& b) const { return v<b.v;}
	friend istream& operator>>(istream &i, ModInt& x){
		ll v; i >> v;
		x = ModInt(v);
		return i;
	}
	friend ostream& operator<<(ostream &o, const ModInt& x){ return o<<x.v;}
	// friend ostream& operator<<(ostream &o,const ModInt& x){
	// 	for(int b=1;b<=1000;b++){
	// 		ModInt ib = ModInt(b).inv();
	// 		for(int a=-1000;a<=1000;a++){
	// 			if(ModInt(a) * ib == x){
	// 				return o << a << "/" << b;
	// 			}
	// 		}
	// 	}
	// 	return o<<x.v;
	// } 
};
using mint = ModInt<998244353>;
//using mint = ModInt<1000000007>;

V<mint> fact,ifact,invs;
// a,b >= 0 のみ
mint Choose(int a,int b){
	if(b<0 || a<b) return 0;
	return fact[a] * ifact[b] * ifact[a-b];
}

/*
// b >= 0 の範囲で、 Choose(a,b) = a(a-1)..(a-b+1) / b!
// verify: https://atcoder.jp/contests/arc212/submissions/72412595
mint Choose(int a,int b){
	assert(b >= 0);
	if(b == 0) return 1;

	if(a-b >= 0) return fact[a] * ifact[b] * ifact[a-b];
	if(a >= 0) return 0;
	return fact[-(a-b+1)] * ifact[b] * ifact[-(a+1)] * (b&1 ? -1 : 1);
}
*/

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