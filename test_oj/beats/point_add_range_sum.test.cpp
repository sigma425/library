#ifdef __clang__
#define IGNORE
#else
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
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

#include "../../data structure/segtree/segbeats.cpp"

struct D{
	int sz=1;
	ll sm=0,lz=0;
	D(ll v=0){sm=v;}
	static D merge(D l,D r){
		D z;
		z.sz = l.sz+r.sz;
		z.sm = l.sm+r.sm;
		return z;
	}
	void push(D& x,D& y){
		x.sm += lz * x.sz; x.lz += lz;
		y.sm += lz * y.sz; y.lz += lz;
		lz = 0;
	}
	bool add(ll v){
		assert(sz == 1);
		sm += v;
		return true;
	}
	ll getsum(){
		return sm;
	}
};


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	int N,Q; cin >> N >> Q;
	V<int> a(N); rep(i,N) cin >> a[i];
	segbeats<D> seg(a);
	while(Q--){
		int t; cin >> t;
		if(t == 0){
			int p,x; cin >> p >> x;
			seg.ch(p,p+1,&D::add,x);
		}else{
			int l,r; cin >> l >> r;
			cout << seg.get(l,r,&D::getsum,[&](ll x,ll y){return x+y;},0LL) << endl;
		}
	}
}
