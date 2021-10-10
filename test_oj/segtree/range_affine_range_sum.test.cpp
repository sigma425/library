/*
	push と affine の両方で op*op みたいなのを書く羽目になっているが、これはしょうがない
	クエリをわざわざopr_tの形に落とさなくてもいいというのがbeatsのメリットだから、逆にそのままみたいなときは冗長になる
*/
#ifdef __clang__
#define IGNORE
#else
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#endif

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
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
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

#ifdef LOCAL
#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x) true
#endif

#include "../../data structure/segtree/segtree_lazy.cpp"

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

struct D{
	struct Monoid{
		mint sm;
		int sz;
		Monoid(){ *this = e(); }
		Monoid(mint v):sm(v),sz(1){}
		Monoid(mint sm_, int sz_):sm(sm_),sz(sz_){}
	};
	struct Action{
		mint a,b;	// x -> ax+b
		Action(){ *this = id(); }
		Action(mint a_, mint b_):a(a_),b(b_){}
	};
	const static Monoid e(){
		return Monoid(0,0);
	}
	const static Monoid op(const Monoid& x, const Monoid& y){
		Monoid z;
		z.sm = x.sm + y.sm;
		z.sz = x.sz + y.sz;
		return z;
	}

	const static Action id(){
		return Action(1,0);
	}
	const static Action composite(const Action& f, const Action& g){
		// f \times g
		Action h;
		h.a = f.a * g.a;
		h.b = f.a * g.b + f.b;
		return h;
	}

	const static Monoid act(const Action& f, const Monoid& x){
		Monoid z;
		z.sz = x.sz;
		z.sm = x.sm * f.a + f.b * x.sz;
		return z;
	}
};
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	int N,Q; cin >> N >> Q;
	V<mint> A(N); rep(i,N) cin >> A[i];
	lazyseg<D> seg(A);
	using F = D::Action;
	while(Q--){
		int t; cin >> t;
		if(t == 0){
			int l,r,a,b; cin >> l >> r >> a >> b;
			seg.apply(l,r,F(a,b));
		}else{
			int l,r; cin >> l >> r;
			cout << seg.query(l,r).sm << endl;
		}
	}
}
