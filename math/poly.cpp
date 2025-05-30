/*
	2021/04/14 大幅変更
	poly 基本, MultipointEval, Interpolate
*/

#include "math/mint.cpp"
#include "misc/highbit.hpp"

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
	using vector<mint>::vector;
	Poly() {}
	explicit Poly(int n) : V<mint>(n){}		// poly<mint> a; a = 2; shouldn't be [0,0]
	Poly(int n, mint c) : V<mint>(n,c){}
	Poly(const V<mint>& a) : V<mint>(a){}
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
	Poly& operator+=(const mint& c){
		if(this->empty()) this->eb(0);
		(*this)[0] += c;
		return *this;
	}
	Poly& operator-=(const mint& c){
		if(this->empty()) this->eb(0);
		(*this)[0] -= c;
		return *this;
	}
	Poly& operator*=(const mint& c){
		for(auto& v: *this) v *= c;
		return *this;
	}
	Poly& operator/=(const mint& c){
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

	Poly operator+(const mint& c) const {return Poly(*this) += c; }
	Poly operator-(const mint& c) const {return Poly(*this) -= c; }
	Poly operator*(const mint& c) const {return Poly(*this) *= c; }
	Poly operator/(const mint& c) const {return Poly(*this) /= c; }
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
		assert(!(p<0 and ord>0));	// 頑張ればできる
		if(p>0 and (s-1)/p < ord) return Poly(s);	// s <= p * ord
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

	// Taylor Shift
	// return f(x+c)
	// O(N logN)
	// verify: yosupo
	Poly shift(mint c){
		int n = size();
		assert(si(fact) >= n);	// please InitFact
		V<mint> f(n); rep(i,n) f[i] = (*this)[i] * fact[i];
		V<mint> g(n);
		mint cpow = 1;
		rep(i,n){g[i] = cpow * ifact[i]; cpow *= c;}
		reverse(all(g));
		V<mint> h = multiply(f,g);
		Poly res(n); rep(i,n) res[i] = h[n-1+i] * ifact[i];
		return res;
	}

	// 合成逆 mod x^s
	// O(s^2 + s^1.5 log s)
	// 方針: lagrange [x^i]g = (1/i [x^i-1](x/f)^i)
	// 		(x/f)^i = (x/f)^jL (x/f)^k とすれば前計算はs^1.5回FFT
	// 		2つの積の一箇所求めるだけなのでO(s)
	// z をかけまくったり z^L をかけまくったりするところはFFT消せるから高速化できる
	// verify: https://www.luogu.com.cn/problem/P5809
	Poly compositeInv(int s){
		assert(at(0) == 0);
		assert(at(1) != 0);
		int L = 0;
		while(L*L < s) L++;
		Poly z0(s); rep(i,s) z0[i] = at(i+1);
		Poly z = z0.inv(s);	// = x/f
		V<Poly> zi(L);	// z^i
		V<Poly>	ziL(L);	// z^iL
		zi[0] = {1};
		rep(i,L-1) zi[i+1] = (zi[i] * z).low(s);
		auto zL = (zi[L-1] * z).low(s);
		ziL[0] = {1};
		rep(i,L-1)  ziL[i+1] = (ziL[i] * zL).low(s);

		Poly res(s);
		rep1(k,s-1){
			int i = k/L, j = k%L;	// x^(iL+j)
			rep(_,k) res[k] += ziL[i].at(_) * zi[j].at(k-1-_);
			res[k] /= k;
		}
		return res;
	}
};

// 合成 f○g mod x^s
// O(ns + sqrt(n)slogs)
// sを指定しないときはnm次全部返す O(n^2m)?
// \sum_k f_k g^k = \sum_k f_k g^iL+j = \sum_i g^iL * (\sum_j f_k g^j)
// verify: https://www.luogu.com.cn/problem/P5373
Poly<mint> composite(Poly<mint> f, Poly<mint> g, int s=-1){
	int n = si(f)-1, m = si(g)-1;
	if(s == -1) s = n*m+1;
	int L = 0;
	while(L*L <= n) L++;
	V<Poly<mint>> gi(L);	// g^i
	V<Poly<mint>> giL(L);	// g^iL
	gi[0] = {1};
	rep(i,L-1) gi[i+1] = (gi[i] * g).low(s);
	auto gL = (gi[L-1] * g).low(s);
	giL[0] = {1};
	rep(i,L-1)  giL[i+1] = (giL[i] * gL).low(s);

	Poly<mint> res(s);
	rep(i,L){
		Poly<mint> z;
		rep(j,L) if(i*L+j <= n) z += gi[j] * f[i*L+j];
		res += (z * giL[i]).low(s);
	}
	return res;
}

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
	auto g = (Poly<mint>(f.begin()+ord,f.end())/f[ord]).sqrt(n_) * mint(c0);
	Poly<mint> res(ord/2 + n_);
	rep(i,n_) res[ord/2 + i] = g[i];
	return res;
}

// Q log^2 Q ではある
// 高速なのはうまく subproduct tree を構築するらしい
// maroon https://judge.yosupo.jp/submission/3240 160ms
// verify: https://judge.yosupo.jp/submission/45006 950ms
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
		定数項 non0 な多項式 g
		0 <= L <= R
	output:
		[x^L, x^{L+1}, .., x^R] g^-1
	complexity:
		O(n log n log L + n(R-L))
	description:
		n := deg(g) かつ g[0] = 1 のとき、
		[x^k] g^-1 = [x^{n-1}] (x^{k+n-1} % rev(g))
		x^{L+n-1} % rev(g) を求めて、あとは x をかけていく kitamasa法
	
	verify: ucup-3-33 E https://contest.ucup.ac/submission/959600
*/
template<class T>
vector<T> invAtRanges(Poly<T> g, ll L, ll R){
	assert(g.at(0));
	while(g.back() == 0) g.pop_back();
	int n = si(g) - 1;
	T ig0 = g[0].inv();
	if(n == 0){
		vector<T> res(R-L+1);
		if(L == 0) res[0] = ig0;
		return res;
	}
	rep(i,n+1) g[i] *= ig0;
	auto rev = g.rev();

	// f -> f^2 % rev(g)
	// O(nlogn)
	// TODO: 毎回同じ mod を取っているので高速化できるはず Poly.quotient の rinv あたりを参照
	auto square = [&](vector<T>& f){
		assert(si(f) == n);
		f = Poly(f).square() % rev;
		f.resize(n);
	};
	// f -> xf % rev(g)
	// O(n)
	auto plus = [&](vector<T>& f){
		assert(si(f) == n);
		f.insert(f.begin(),0);
		rep(i,n) f[i] -= f[n] * rev[i];
		f.pop_back();
	};
	
	vector<T> f(n); f[0] = 1;
	if(L+n-1){
		int h = highbit(L+n-1);
		plus(f);
		per(i,h){
			square(f);
			if(((L+n-1)>>i)&1) plus(f);
		}
	}
	vector<T> res(R-L+1);
	res[0] = f[n-1];
	rep(t,R-L){
		plus(f);
		res[t+1] = f[n-1];
	}
	for(auto& v: res) v *= ig0;
	return res;
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

// return f(K+1)
// f[k] = 0^k + .. + n^k
// \sum_{k>=0} f[k] x^k/k! = e^0x + .. + e^nx = 1-e^(n+1)x / 1-e^x
// O(KlogK)
// 0^0 = 1
// keyword: faulhaber ファウルハーバー

vector<mint> SumOfPower(mint n, int K){
	assert(si(fact) > K);
	Poly<mint> a(K+1),b(K+1);
	mint pw = 1;
	rep1(i,K+1){
		pw *= n+1;
		a[i-1] = ifact[i];
		b[i-1] = ifact[i] * pw;
	}
	auto f = b*a.inv(K+1);
	V<mint> res(K+1);
	rep(k,K+1) res[k] = f[k] * fact[k];
	return res;
}
