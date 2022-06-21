/*
	2021/04/14 大幅変更
	poly 基本, MultipointEval, Interpolate
*/
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
using mint = ModInt<998244353>;
//using mint = ModInt<1000000007>;

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

// inplace_fmt (without bit rearranging)
// fft:
// 		a[rev(i)] <- \sum_j \zeta^{ij} a[j]
// invfft:
//		a[i] <- (1/n) \sum_j \zeta^{-ij} a[rev(j)]
// These two are inversions.


// !!! CHANGE IF MOD is unusual !!!
const int ORDER_2_MOD_MINUS_1 = 23;	// ord_2 (mod-1)
const mint PRIMITIVE_ROOT = 3; // primitive root of (Z/pZ)*

void fft(V<mint>& a){
	static constexpr uint mod = mint::mod;
	static constexpr uint mod2 = mod + mod;
	static const int H = ORDER_2_MOD_MINUS_1;
	static const mint root = PRIMITIVE_ROOT;
	static mint magic[H-1];

	int n = si(a);
	assert(!(n & (n-1))); assert(n >= 1); assert(n <= 1<<H);	// n should be power of 2

	if(!magic[0]){		// precalc
		rep(i,H-1){
			mint w = -root.pow(((mod-1)>>(i+2))*3);
			magic[i] = w;
		}
	}
	int m = n;
	if(m >>= 1){
		rep(i,m){
			uint v = a[i+m].v;					// < M
			a[i+m].v = a[i].v + mod - v;		// < 2M
			a[i].v += v;						// < 2M
		}
	}
	if(m >>= 1){
		mint p = 1;
		for(int h=0,s=0; s<n; s += m*2){
			for(int i=s;i<s+m;i++){
				uint v = (a[i+m] * p).v;		// < M
				a[i+m].v = a[i].v + mod - v;	// < 3M
				a[i].v += v;					// < 3M
			}
			p *= magic[__builtin_ctz(++h)];
		}
	}
	while(m){
		if(m >>= 1){
			mint p = 1;
			for(int h=0,s=0; s<n; s += m*2){
				for(int i=s;i<s+m;i++){
					uint v = (a[i+m] * p).v;		// < M
					a[i+m].v = a[i].v + mod - v;	// < 4M
					a[i].v += v;					// < 4M
				}
				p *= magic[__builtin_ctz(++h)];
			}
		}
		if(m >>= 1){
			mint p = 1;
			for(int h=0,s=0; s<n; s += m*2){
				for(int i=s;i<s+m;i++){
					uint v = (a[i+m] * p).v;								// < M
					a[i].v = (a[i].v >= mod2) ? a[i].v - mod2 : a[i].v;	// < 2M
					a[i+m].v = a[i].v + mod - v;							// < 3M
					a[i].v += v;											// < 3M
				}
				p *= magic[__builtin_ctz(++h)];
			}
		}
	}
	rep(i,n){
		a[i].v = (a[i].v >= mod2) ? a[i].v - mod2 : a[i].v;		// < 2M
		a[i].v = (a[i].v >= mod) ? a[i].v - mod : a[i].v;		// < M
	}
	// finally < mod !!
}
void invfft(V<mint>& a){
	static constexpr uint mod = mint::mod;
	static constexpr uint mod2 = mod + mod;
	static const int H = ORDER_2_MOD_MINUS_1;
	static const mint root = PRIMITIVE_ROOT;
	static mint magic[H-1];

	int n = si(a);
	assert(!(n & (n-1))); assert(n >= 1); assert(n <= 1<<H);	// n should be power of 2

	if(!magic[0]){		// precalc
		rep(i,H-1){
			mint w = -root.pow(((mod-1)>>(i+2))*3);
			magic[i] = w.inv();
		}
	}
	int m = 1;
	if(m < n>>1){
		mint p = 1;
		for(int h=0,s=0; s<n; s += m*2){
			for(int i=s;i<s+m;i++){
				ull x = a[i].v + mod - a[i+m].v;	// < 2M
				a[i].v += a[i+m].v;					// < 2M
				a[i+m].v = (p.v * x) % mod;			// < M
			}
			p *= magic[__builtin_ctz(++h)];
		}
		m <<= 1;
	}
	for(;m < n>>1; m <<= 1){
		mint p = 1;
		for(int h=0,s=0; s<n; s+= m*2){
			for(int i=s;i<s+(m>>1);i++){
				ull x = a[i].v + mod2 - a[i+m].v;	// < 4M
				a[i].v += a[i+m].v;					// < 4M
				a[i].v = (a[i].v >= mod2) ? a[i].v - mod2 : a[i].v;	// < 2M
				a[i+m].v = (p.v * x) % mod;		// < M
			}
			for(int i=s+(m>>1); i<s+m; i++){
				ull x = a[i].v + mod - a[i+m].v;	// < 2M
				a[i].v += a[i+m].v;	// < 2M
				a[i+m].v = (p.v * x) % mod;	// < M
			}
			p *= magic[__builtin_ctz(++h)];
		}
	}
	if(m < n){
		rep(i,m){
			uint x = a[i].v + mod2 - a[i+m].v;	// < 4M
			a[i].v += a[i+m].v;	// < 4M
			a[i+m].v = x;	// < 4M
		}
	}
	const mint in = mint(n).inv();
	rep(i,n) a[i] *= in;	// < M
	// finally < mod !!
}

// A,B = 500000 -> 70ms
// verify https://judge.yosupo.jp/submission/44937
V<mint> multiply(V<mint> a, V<mint> b) {
	int A = si(a), B = si(b);
	if (!A || !B) return {};
	int n = A+B-1;
	int s = 1; while(s<n) s*=2;
	if(a == b){			// # of fft call : 3 -> 2
		a.resize(s); fft(a);
		rep(i,s) a[i] *= a[i];
	}else{
		a.resize(s); fft(a);
		b.resize(s); fft(b);
		rep(i,s) a[i] *= b[i];
	}
	invfft(a); a.resize(n);
	return a;
}

/*
	係数アクセス
		f[i] でいいが、 配列外参照する可能性があるなら at/set
	
*/

template<class mint>
struct Poly: public V<mint>{
	template<class...Args>
	Poly(Args...args) : V<mint>(args...){}
	Poly(initializer_list<mint> li) : V<mint>(li){}

	int size() const { return V<mint>::size(); }
	mint at(int i) const {
		return i<size() ? (*this)[i] : 0;
	}
	void set(int i, mint x){
		if(i>=size() && !x) return;
		while(i>=size()) this->pb(0);
		(*this)[i] = x;
		return;
	}
	mint operator()(mint x) const {		// eval
		mint res = 0;
		int n = size();
		mint a = 1;
		rep(i,n){
			res += a * (*this)[i];
			a *= x;
		}
		return res;
	}
	Poly low(int n) const {		// ignore x^n (take first n), but not empty
		return Poly(this->begin(), this->begin()+min(max(n,1),size()));
	}
	Poly rev() const {
		return Poly(this->rbegin(), this->rend());
	}
	friend ostream& operator<<(ostream &o,const Poly& f){
		o << "[";
		rep(i,f.size()){
			o << f[i];
			if(i != f.size()-1) o << ",";
		}
		o << "]";
		return o;
	}

	Poly operator-() const {
		Poly res = *this;
		for(auto& v: res) v = -v;
		return res;
	}
	template<class T>
	Poly& operator+=(T c){
		(*this)[0] += c;
		return *this;
	}
	template<class T>
	Poly& operator-=(T c){
		(*this)[0] -= c;
		return *this;
	}
	template<class T>
	Poly& operator*=(T c){
		for(auto& v: *this) v *= c;
		return *this;
	}
	template<class T>
	Poly& operator/=(T c){
		return *this *= mint(1)/mint(c);
	}
	Poly& operator+=(const Poly& r){
		if(size() < r.size()) this->resize(r.size(),0);
		rep(i,r.size()) (*this)[i] += r[i];
		return *this;
	}
	Poly& operator-=(const Poly& r){
		if(size() < r.size()) this->resize(r.size(),0);
		rep(i,r.size()) (*this)[i] -= r[i];
		return *this;
	}
	Poly& operator*=(const Poly& r){
		return *this = multiply(*this,r);
	}

	// 何回も同じrで割り算するなら毎回rinvを計算するのは無駄なので、呼び出し側で一回計算した後直接こっちを呼ぶと良い
	// 取るべきinvの長さに注意
	// 例えば mod r で色々計算したい時は、基本的に deg(r) * 2 長さの多項式を r で割ることになる
	// とはいえいったん rinv を長く計算したらより短い場合はprefix見るだけだし、 rinv としてムダに長いものを渡しても問題ないので
	// 割られる多項式として最大の次数を取ればよい

	Poly quotient(const Poly& r, const Poly& rinv){
		int m = r.size(); assert(r[m-1].v);
		int n = size();
		int s = n-m+1;
		if(s <= 0) return {0};
		return (rev().low(s)*rinv.low(s)).low(s).rev();
	}
	Poly& operator/=(const Poly& r){
		return *this = quotient(r,r.rev().inv(max(size()-r.size(),0)+1));
	}
	Poly& operator%=(const Poly& r){
		*this -= *this/r * r;
		return *this = low(r.size()-1);
	}

	
	template<class T> Poly operator+(T c) const {return Poly(*this) += c; }
	template<class T> Poly operator-(T c) const {return Poly(*this) -= c; }
	template<class T> Poly operator*(T c) const {return Poly(*this) *= c; }
	template<class T> Poly operator/(T c) const {return Poly(*this) /= c; }
	Poly operator+(const Poly& r) const {return Poly(*this) += r; }
	Poly operator-(const Poly& r) const {return Poly(*this) -= r; }
	Poly operator*(const Poly& r) const {return Poly(*this) *= r; }
	Poly operator/(const Poly& r) const {return Poly(*this) /= r; }
	Poly operator%(const Poly& r) const {return Poly(*this) %= r; }

	Poly diff() const {
		Poly g(max(size()-1,0));
		rep(i,g.size()) g[i] = (*this)[i+1] * (i+1);
		return g;
	}
	Poly intg() const {
		assert(si(invs) > size());
		Poly g(size()+1);
		rep(i,size()) g[i+1] = (*this)[i] * invs[i+1];
		return g;
	}
	Poly square() const {
		return multiply(*this,*this);
	}

	// 1/f(x) mod x^s
	// N = s = 500000 -> 90ms
	// inv は 5 回 fft(2n) を呼んでいるので、multiply が 3 回 fft(2n) を呼ぶのと比べると
	// だいたい multiply の 5/3 倍の時間がかかる
	// 導出: Newton
	// 		fg = 1 mod x^m
	// 		(fg-1)^2 = 0 mod x^2m
	// 		f(2g-fg^2) = 1 mod x^2m
	// verify: https://judge.yosupo.jp/submission/44938
	Poly inv(int s) const {
		Poly r(s);
		r[0] = mint(1)/at(0);
		for(int n=1;n<s;n*=2){			// 5 times fft : length 2n
			V<mint> f = low(2*n); f.resize(2*n);
			fft(f);
			V<mint> g = r.low(2*n); g.resize(2*n);
			fft(g);
			rep(i,2*n) f[i] *= g[i];
			invfft(f);
			rep(i,n) f[i] = 0;
			fft(f);
			rep(i,2*n) f[i] *= g[i];
			invfft(f);
			for(int i=n;i<min(2*n,s);i++) r[i] -= f[i];
		}
		return r;
	}

	// log f mod x^s
	// 導出: D log(f) = (D f) / f
	// 500000: 180ms
	// mult の 8/3 倍
	// verify: https://judge.yosupo.jp/submission/44962
	Poly log(int s) const {
		assert(at(0) == 1);
		if(s == 1) return {0};
		return (low(s).diff() * inv(s-1)).low(s-1).intg();
	}

	// e^f mod x^s
	// f.log(s).exp(s) == [1,0,...,0]
	// 500000 : 440ms
	// TODO: 高速化！
	// 速い実装例 (hos): https://judge.yosupo.jp/submission/36732 150ms
	// 導出 Newton:
	//		g = exp(f)
	//		log(g) - f = 0
	//		g == g0 mod x^m
	//		g == g0 - (log(g0) - f) / (1/g0) mod x^2m
	// verify: yosupo
	Poly exp(int s) const {
		assert(at(0) == 0);
		Poly f({1}),g({1});
		for(int n=1;n<s;n*=2){
			g = (g*2-g.square().low(n)*f).low(n);
			Poly q = low(n).diff();
			q = q + g * (f.diff() - f*q).low(2*n-1);
			f = (f + f * (low(2*n)-q.intg()) ).low(2*n);
		}
		return f.low(s);
	}

	// f^p mod x^s
	// 500000: 600ms
	// 導出: f^p = e^(p log f)
	// log 1回、 exp 1回
	// Exp.cpp (Mifafa technique) も参照
	// 	c.f. (f の non0 coef の個数) * s
	// verify: https://judge.yosupo.jp/submission/44992
	Poly pow(ll p, int s) const {
		if(p == 0){
			return Poly(s) + 1;	// 0^0 is 1
		}
		int ord = 0;
		while(ord<s && !at(ord)) ord++;
		if((s-1)/p < ord) return Poly(s);	// s <= p * ord
		int off = p*ord;
		int s_ = s-off;
		const mint a0 = at(ord), ia0 = a0.inv(), ap = a0.pow(p);
		Poly f(s_); rep(i,s_) f[i] = at(i+ord) * ia0;
		f = (f.log(s_) * p).exp(s_);
		Poly res(s);
		rep(i,s_) res[i+off] = f[i] * ap;
		return res;
	}

	// f^(1/2) mod x^s
	// f[0] should be 1
	// 11/6
	// verify: https://judge.yosupo.jp/submission/44997
	Poly sqrt(int s) const {
		assert(at(0) == 1);
		static const mint i2 = mint(2).inv();
		V<mint> f{1},g{1},z{1};
		for(int n=1;n<s;n*=2){
			rep(i,n) z[i] *= z[i];
			invfft(z);
			V<mint> d(2*n);
			rep(i,n) d[n+i] = z[i] - at(i) - at(n+i);
			fft(d);
			V<mint> g2(2*n);
			rep(i,n) g2[i] = g[i];
			fft(g2);
			rep(i,n*2) d[i] *= g2[i];
			invfft(d);
			f.resize(n*2);
			for(int i=n;i<n*2;i++) f[i] = -d[i] * i2;
			if(n*2 >= s) break;
			z = f;
			fft(z);
			V<mint> eps = g2;
			rep(i,n*2) eps[i] *= z[i];
			invfft(eps);
			rep(i,n) eps[i] = 0;
			fft(eps);
			rep(i,n*2) eps[i] *= g2[i];
			invfft(eps);
			g.resize(n*2);
			for(int i=n;i<n*2;i++) g[i] -= eps[i];
		}
		f.resize(s);
		return f;
	}
};


ll norm_mod(ll a, ll m){
	a %= m; if(a < 0) a += m;
	return a;
}

//p: odd (not necessarily prime)
ll jacobi(ll a,ll p){
	a = norm_mod(a,p);
	auto sgn = [](ll x){ return x&1 ? -1 : 1; };
	if(a == 0) return p == 1;
	else if(a&1) return sgn(((p-1)&(a-1))>>1) * jacobi(p%a,a);
	else return sgn(((p&15)*(p&15)-1)/8) * jacobi(a/2,p);
}

// p : prime
// 0 <= a < p
// return smaller solution
// if no solution, -1
ll sqrt_mod(ll a,ll p){
	if(a == 0) return 0;
	if(p == 2) return 1;
	if(jacobi(a,p) == -1)return -1;
	ll b,c;
	for(b=0;;b++){
		c = norm_mod(b*b-a,p);
		if(jacobi(c,p) == -1) break;
	}
	auto mul = [&](pair<ll,ll> x, pair<ll,ll> y){
		return pair<ll,ll>(norm_mod(x.fs*y.fs+x.sc*y.sc%p*c,p),norm_mod(x.fs*y.sc+x.sc*y.fs,p));
	};
	pair<ll,ll> x(b,1),res(1,0);
	ll n = (p+1)/2;
	while(n){
		if(n&1) res = mul(res,x);
		x = mul(x,x);
		n >>= 1;
	}
	assert(res.sc == 0);
	return min(res.fs, p-res.fs);
}

// 辞書順最小
// no solution -> {}
Poly<mint> sqrt(Poly<mint> f){
	int n = f.size();
	int ord = 0;
	while(ord<n && !f[ord]) ord++;
	if(ord == n) return {0};
	if(ord&1) return {};
	ll c0 = sqrt_mod(f[ord].v,mint::mod);
	if(c0 == -1) return {};
	int n_ = n-ord;
	auto g = (Poly<mint>(f.begin()+ord,f.end())/f[ord]).sqrt(n_) * c0;
	Poly<mint> res(ord/2 + n_);
	rep(i,n_) res[ord/2 + i] = g[i];
	return res;
}

// Q log^2 Q ではある
// 高速なのはうまく subproduct tree を構築するらしい
// maroon https://judge.yosupo.jp/submission/3240 160ms
// verify: https://judge.yosupo.jp/submission/45006 950ms おせ～
template<class mint>
V<mint> MultipointEval(const Poly<mint>& f, V<mint> a){
	int Q = a.size();
	int s = 1; while(s < Q) s *= 2;
	V<Poly<mint>> g(s+s,{1});
	rep(i,Q) g[s+i] = {-a[i],1};
	for(int i=s-1;i>0;i--) g[i] = g[i*2] * g[i*2+1];
	g[1] = f % g[1];
	for(int i=2;i<s+Q;i++) g[i] = g[i>>1] % g[i];
	V<mint> res(Q);
	rep(i,Q) res[i] = g[s+i][0];
	return res;
}

// N log^2 N ではある
// 高速なのはうまく subうんぬん
template<class mint>
Poly<mint> interpolate(const V<mint>& x, const V<mint>& y){
	int n = si(x);
	int s = 1; while(s<n) s*=2;
	V<Poly<mint>> g(s+s,{1}), h(s+s);
	rep(i,n) g[s+i] = {-x[i],1};
	for(int i=s-1;i>0;i--) g[i] = g[i*2] * g[i*2+1];
	h[1] = g[1].diff();
	for(int i=2;i<s+n;i++) h[i] = h[i>>1] % g[i];
	rep(i,n) h[s+i] = {y[i] / h[s+i][0]};
	for(int i=s-1;i>0;i--) h[i] = h[i*2]*g[i*2+1] + h[i*2+1]*g[i*2];
	return h[1];
}

// [x^p] f/g
// O(n logn logp)
// O(f logf + g logg logn) (f が大きくてもややOK)
// verified: https://ac.nowcoder.com/acm/contest/11259/H
// hos,divAt : https://ac.nowcoder.com/acm/contest/view-submission?submissionId=48462458

template<class T>
T divAt(Poly<T> f, Poly<T> g, ll p){
	assert(g.at(0));
	while(p){
		auto gm = g;
		for(int i=1;i<si(g);i+=2) gm[i] = -gm[i];
		auto f2 = f*gm;
		auto g2 = g*gm;
		f.clear();g.clear();
		for(int i=p&1;i<si(f2);i+=2) f.set(i/2,f2[i]);
		for(int i=0;i<si(g2);i+=2) g.set(i/2,g2[i]);
		p /= 2;
	}
	return f.at(0)/g.at(0);
}

/*
	input:
		はじめ d 項: a_0, a_1, .., a_{d-1}
		d+1 項 reccurence: c_0 * a_{i+d} + .. + c_d * a_i = 0
		aを無駄に与えても良い(足りないと、カス)
		ll k
	output:
		a_k
	O(d logd logk)
	verified: https://judge.yosupo.jp/problem/find_linear_recurrence
*/
template<class T>
T linearRecurrenceAt(V<T> a, V<T> c, ll k){
	assert(!c.empty() && c[0]);
	int d = si(c) - 1;
	assert(si(a) >= d);
	return divAt((Poly<T>(a.begin(),a.begin()+d) * Poly<T>(c)).low(d), Poly<T>(c), k);
}
