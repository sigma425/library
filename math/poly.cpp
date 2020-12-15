/*

メモ： constructor (int n) を入れると Poly<mint>({2}) とかで破壊される
initializer list? 
 Poly() {}
  explicit Poly(int n) : vector<Mint>(n) {}
  Poly(const vector<Mint> &vec) : vector<Mint>(vec) {}
  Poly(std::initializer_list<Mint> il) : vector<Mint>(il) {}

わかんね
めもおわり

依存関係 : mint,fft(ntt)


多項式.
shrink()でleading-0を取り除き,常にこの意味での正規系を値として持つ.
その意味でintとmint以外はまあまあまずいかな
でも+-とか簡単なのは出来る(いるか?)

割り算も O(NlogN) だがNが小さい時遅いので分割統治みたいなことをするときは注意

inv(N),exp(N),log(N),sqrt(N) : N次までを返す
diff / intg : 微積

verified: ありすぎて忘れた
	https://codeforces.com/contest/438/problem/E (sqrt,inv)
	https://official.contest.yandex.com/ptz-winter-2019/contest/11818/problems/G1/ (exp,log)

計測:
	-O2

	fft2 *
	- N = 100000
	141 [ms]
	- N = 200000
	279 [ms]
	- N = 500000
	595 [ms]
	- N = 1000000
	1186 [ms]

	fft2 N % N/4 くらい 割る側の次数はこれくらいが一番遅い気がする
	- N = 10000
	44 [ms]
	- N = 100000
	643 [ms]
	- N = 200000
	1340 [ms]
	- N = 500000
	3033 [ms]
	- N = 1000000
	5875 [ms]

	ntt * 
	- N = 1000000
	231 [ms]

	ntt N % N/4
	- N = 200000
	147 [ms]
	- N = 500000
	310 [ms]
	- N = 1000000
	646 [ms]

*/

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << (x) << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;

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
	ll extgcd(ll a,ll b,ll &x,ll &y) const{
		ll p[]={a,1,0},q[]={b,0,1};
		while(*q){
			ll t=*p/ *q;
			rep(i,3) swap(p[i]-=t*q[i],q[i]);
		}
		if(p[0]<0) rep(i,3) p[i]=-p[i];
		x=p[1],y=p[2];
		return p[0];
	}
	ModInt inv() const {
		ll x,y;
		extgcd(v,mod,x,y);
		return make(normS(x+mod));
	}
	ModInt pow(ll p) const {
		ModInt a = 1;
		ModInt x = *this;
		while(p){
			if(p&1) a *= x;
			x *= x;
			p >>= 1;
		}
		return a;
	}
	bool operator==(const ModInt& b) const { return v==b.v;}
	bool operator!=(const ModInt& b) const { return v!=b.v;}
	friend istream& operator>>(istream &o,ModInt& x){
		ll tmp;
		o>>tmp;
		x=ModInt(tmp);
		return o;
	}
	friend ostream& operator<<(ostream &o,const ModInt& x){ return o<<x.v;}
};
using mint = ModInt<998244353>;

int bsr(int x) { return 31 - __builtin_clz(x); }
void ntt(bool type, V<mint>& c) {
	const mint G = 3;	//primitive root

	int N = int(c.size());
	int s = bsr(N);
	assert(1 << s == N);

	V<mint> a = c, b(N);
	rep1(i,s){
		int W = 1 << (s - i);
		mint base = G.pow((mint::mod - 1)>>i);
		if(type) base = base.inv();
		mint now = 1;
		for(int y = 0; y < N / 2; y += W) {
			for (int x = 0; x < W; x++) {
				auto l = a[y << 1 | x];
				auto r = now * a[y << 1 | x | W];
				b[y | x] = l + r;
				b[y | x | N >> 1] = l - r;
			}
			now *= base;
		}
		swap(a, b);
	}
	c = a;
}

V<mint> multiply_ntt(const V<mint>& a, const V<mint>& b) {
	int A = int(a.size()), B = int(b.size());
	if (!A || !B) return {};
	int lg = 0;
	while ((1 << lg) < A + B - 1) lg++;
	int N = 1 << lg;
	V<mint> ac(N), bc(N);
	for (int i = 0; i < A; i++) ac[i] = a[i];
	for (int i = 0; i < B; i++) bc[i] = b[i];
	ntt(false, ac);
	ntt(false, bc);
	for (int i = 0; i < N; i++) {
		ac[i] *= bc[i];
	}
	ntt(true, ac);
	V<mint> c(A + B - 1);
	mint iN = mint(N).inv();
	for (int i = 0; i < A + B - 1; i++) {
		c[i] = ac[i] * iN;
	}
	return c;
}

template<class D>
struct Poly{
	vector<D> v;
	int size() const{ return v.size();}	//deg+1
	Poly(){}
	Poly(vector<D> _v) : v(_v){shrink();}

	Poly& shrink(){
		while(!v.empty()&&v.back()==D(0)) v.pop_back();
		return *this;
	}
	D& operator[](int i){return v[i];}
	const D& operator[](int i) const {return v[i];}
	D at(int i) const{
		return (i<size())?v[i]:D(0);
	}
	void set(int i,const D& x){		//v[i] := x
		if(i>=size() && !x) return;
		while(i>=size()) v.push_back(D(0));
		v[i]=x;
		shrink();
		return;
	}
	D operator()(D x) const {
		D res = 0;
		int n = size();
		D a = 1;
		rep(i,n){
			res += a*v[i];
			a *= x;
		}
		return res;
	}

	Poly operator+(const Poly &r) const{
		int N=max(size(),r.size());
		vector<D> ret(N);
		rep(i,N) ret[i]=at(i)+r.at(i);
		return Poly(ret);
	}
	Poly operator-(const Poly &r) const{
		int N=max(size(),r.size());
		vector<D> ret(N);
		rep(i,N) ret[i]=at(i)-r.at(i);
		return Poly(ret);
	}
	Poly operator-() const{
		int N=size();
		vector<D> ret(N);
		rep(i,N) ret[i] = -at(i);
		return Poly(ret);
	}
	Poly operator*(const Poly &r) const{
		if(size()==0||r.size()==0) return Poly();
		return mul_ntt(r);									// FFT or NTT ?
	}
	Poly operator*(const D &r) const{
		int N=size();
		vector<D> ret(N);
		rep(i,N) ret[i]=v[i]*r;
		return Poly(ret);
	}
	Poly operator/(const D &r) const{
		return *this * r.inv();
	}
	Poly operator/(const Poly &y) const{
		return div_fast(y);
	}
	Poly operator%(const Poly &y) const{
		return rem_fast(y);
//		return rem_naive(y);
	}
	Poly operator<<(const int &n) const{	// *=x^n
		assert(n>=0);
		int N=size();
		vector<D> ret(N+n);
		rep(i,N) ret[i+n]=v[i];
		return Poly(ret);
	}
	Poly operator>>(const int &n) const{	// /=x^n
		assert(n>=0);
		int N=size();
		if(N<=n) return Poly();
		vector<D> ret(N-n);
		rep(i,N-n) ret[i]=v[i+n];
		return Poly(ret);
	}
	bool operator==(const Poly &y) const{
		return v==y.v;
	}
	bool operator!=(const Poly &y) const{
		return v!=y.v;
	}

	Poly& operator+=(const Poly &r) {return *this = *this+r;}
	Poly& operator-=(const Poly &r) {return *this = *this-r;}
	Poly& operator*=(const Poly &r) {return *this = *this*r;}
	Poly& operator*=(const D &r) {return *this = *this*r;}
	Poly& operator/=(const Poly &r) {return *this = *this/r;}
	Poly& operator/=(const D &r) {return *this = *this/r;}
	Poly& operator%=(const Poly &y) {return *this = *this%y;}
	Poly& operator<<=(const int &n) {return *this = *this<<n;}
	Poly& operator>>=(const int &n) {return *this = *this>>n;}

	Poly diff() const {
		int n = size();
		if(n == 0) return Poly();
		V<D> u(n-1);
		rep(i,n-1) u[i] = at(i+1) * (i+1);
		return Poly(u);
	}
	Poly intg() const {
		int n = size();
		V<D> u(n+1);
		rep(i,n) u[i+1] = at(i) / (i+1);
		return Poly(u);
	}

	Poly pow(long long n, int L) const {		// f^n, ignoring x^L,x^{L+1},..
		Poly a({1});
		Poly x = *this;
		while(n){
			if(n&1){
				a *= x;
				a = a.strip(L);
			}
			x *= x;
			x = x.strip(L);
			n /= 2;
		}
		return a;
	}

	/*
		[x^0~n] exp(f) = 1 + f + f^2 / 2 + f^3 / 6 + ..
		f(0) should be 0

		O((N+n) log n)	(N = size())
		NTT, -O3
		- N = n = 100000 : 200 [ms]
		- N = n = 200000 : 400 [ms]
		- N = n = 500000 : 1000 [ms]
	*/
	Poly exp(int n) const {
		assert(at(0) == 0);
		Poly f({1}), g({1});
		for(int i=1;i<=n;i*=2){
			g = (g*2 - f*g*g).strip(i);
			Poly q = (this->diff()).strip(i-1);
			Poly w = (q + g * (f.diff() - f*q)) .strip(2*i-1);
			f = (f + f * (*this - w.intg()).strip(2*i)) .strip(2*i);
		}
		return f.strip(n+1);
	}

	/*
		[x^0~n] log(f) = log(1-(1-f)) = - (1-f) - (1-f)^2 / 2 - (1-f)^3 / 3 - ...
		f(0) should be 1
		O(n log n)

		NTT, -O3
		1e5 : 140 [ms]
		2e5 : 296 [ms]
		5e5 : 640 [ms]
		1e6 : 1343 [ms]
	*/
	Poly log(int n) const {
		assert(at(0) == 1);
		auto f = strip(n+1);
		return (f.diff() * f.inv(n)).strip(n).intg();
	}

	/*
		[x^0~n] sqrt(f)
		f(0) should be 1
		いや平方剰余なら何でもいいと思うけど探すのがめんどくさいので
		+- 2通りだけど 定数項が 1 の方
		O(n log n)

		NTT, -O3
		1e5 : 234 [ms]
		2e5 : 484 [ms]
		5e5 : 1000 [ms]
		1e6 : 2109 [ms]
	*/
	Poly sqrt(int n) const {
		assert(at(0) == 1);
		Poly f = strip(n+1);
		Poly g({1});
		for(int i=1; i<=n; i*=2){
			g = (g + f.strip(2*i)*g.inv(2*i-1)) / 2;
		}
		return g.strip(n+1);
	}

	/*
		[x^0~n] f^-1 = (1-(1-f))^-1 = (1-f) + (1-f)^2 + ...
		f * f.inv(n) = 1 + x^n * poly
		f(0) should be non0
		O(n log n)
	*/
	Poly inv(int n) const {
		assert(at(0) != 0);
		Poly f = strip(n+1);
		Poly g({at(0).inv()});
		for(int i=1; i<=n; i*=2){		//need to strip!!
			g *= (Poly({2}) - f.strip(2*i)*g).strip(2*i);
		}
		return g.strip(n+1);
	}	

	Poly exp_naive(int n) const {
		assert(at(0) == 0);
		Poly res;
		Poly fk({1});
		rep(k,n+1){
			res += fk;
			fk *= *this;
			fk = fk.strip(n+1) / (k+1);
		}
		return res;
	}
	Poly log_naive(int n) const {
		assert(at(0) == 1);
		Poly res;
		Poly g({1});
		rep1(k,n){
			g *= (Poly({1}) - *this);
			g = g.strip(n+1);
			res -= g / k;
		}
		return res;
	}


	Poly mul_naive(const Poly &r) const{
		int N=size(),M=r.size();
		vector<D> ret(N+M-1);
		rep(i,N) rep(j,M) ret[i+j]+=at(i)*r.at(j);
		return Poly(ret);
	}
	Poly mul_ntt(const Poly &r) const{
		return Poly(multiply_ntt(v,r.v));
	}
	Poly mul_fft(const Poly &r) const{
		return Poly(multiply_fft(v,r.v));
	}

	Poly div_fast_with_inv(const Poly &inv, int B) const {
		return (*this * inv)>>(B-1);
	}
	Poly div_fast(const Poly &y) const{
		if(size()<y.size()) return Poly();
		int n = size();
		return div_fast_with_inv(y.inv_div(n-1),n);
	}
	Poly rem_naive(const Poly &y) const{
		Poly x = *this;
		while(y.size()<=x.size()){
			int N=x.size(),M=y.size();
			D coef = x.v[N-1]/y.v[M-1];
			x -= (y<<(N-M))*coef;
		}
		return x;
	}
	Poly rem_fast(const Poly &y) const{
		return *this - y * div_fast(y);
	}
	Poly strip(int n) const {	//ignore x^n , x^n+1,...
		vector<D> res = v;
		res.resize(min(n,size()));
		return Poly(res);
	}
	Poly rev(int n = -1) const {	//ignore x^n ~  ->  return x^(n-1) * f(1/x)
		vector<D> res = v;
		if(n!=-1) res.resize(n);
		reverse(all(res));
		return Poly(res);
	}

	/*
		f.inv_div(n) = x^n / f
		f should be non0
		O((N+n) log n)

		for division
	*/
	Poly inv_div(int n) const {
		n++;
		int d = size() - 1;
		assert(d != -1);
		if(n < d) return Poly();
		Poly a = rev();
		Poly g({at(d).inv()});
		for(int i=1; i+d<=n; i*=2){		//need to strip!!
			g *= (Poly({2})-a.strip(2*i)*g).strip(2*i);
		}
		return g.rev(n-d);
	}


	friend ostream& operator<<(ostream &o,const Poly& x){
		if(x.size()==0) return o<<0;
		rep(i,x.size()) if(x.v[i]!=D(0)){
			o<<x.v[i]<<"x^"<<i;
			if(i!=x.size()-1) o<<" + ";
		}
		return o;
	}
};


/*
	↓ test
*/

template<class T>
T rnd(T l,T r){	//[l,r)
	using D = uniform_int_distribution<T>;
	static random_device rd;
	static mt19937 gen(rd());
	return D(l,r-1)(gen);
}
template<class T>
T rnd(T n){	//[0,n)
	return rnd(0,n);
}
struct Timer{
	clock_t st;
	void start(){
		st = clock();
	}
	int ms(){
		return (clock()-st)*1000 / CLOCKS_PER_SEC;
	}
}timer;


void unittest(){
	vector<int> Ns = {2,10,100,1000,10000,100000,200000,500000,1000000};
	for(int N: Ns){
		Poly<mint> f,g;
		rep(i,N) f.set(i,rnd<int>(mint::mod));
		rep(i,N) g.set(i,rnd<int>(mint::mod));
		timer.start();
		auto h = f*g;
		cerr << "- N = " << N << endl;
		cerr << "  " << timer.ms() << " [ms]" << endl;
	}
}
void invtest(){
	while(true){
		int N,n;
		cin >> N >> n;
		Poly<mint> f;
		f.set(0,1);
		rep1(i,N-1) f.set(i,rnd<int>(mint::mod));
		timer.start();
		auto g = f.sqrt(n);
		show((f-g*g).strip(n+1));
		auto h = f.inv(n);
		show((f*h).strip(n+1));
		cerr << "  " << timer.ms() << " [ms]" << endl;
	}
}
void Catalan(){
	int N;
	cin >> N;
	auto f = ((Poly<mint>({1}) - Poly<mint>({1,-4}).sqrt(N)) / Poly<mint>({0,2})) . strip(N+1);
	show(f);
}

int main(){
//	unittest();
//	invtest();
	Catalan();
}
