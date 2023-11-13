#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
#define rep(i,n) for(int i=0;i<int(n);i++)
#define rep1(i,n) for(int i=1;i<=int(n);i++)
#define per(i,n) for(int i=int(n)-1;i>=0;i--)
#define per1(i,n) for(int i=int(n);i>0;i--)
#define all(c) c.begin(),c.end()
#define si(x) int(x.size())
#define pb push_back
#define eb emplace_back
#define fs first
#define sc second
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
template<class T,class U> bool chmax(T& x, U y){
	if(x<y){ x=y; return true; }
	return false;
}
template<class T,class U> bool chmin(T& x, U y){
	if(y<x){ x=y; return true; }
	return false;
}
template<class T> void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}
template<class T> int lwb(const V<T>& v, const T& a){return lower_bound(all(v),a) - v.begin();}
template<class T>
V<T> Vec(size_t a) {
    return V<T>(a);
}
template<class T, class... Ts>
auto Vec(size_t a, Ts... ts) {
  return V<decltype(Vec<T>(ts...))>(a, Vec<T>(ts...));
}
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

#ifdef LOCAL
#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
void dmpr(ostream& os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ~ ";
	dmpr(os,args...);
}
#define shows(...) cerr << "LINE" << __LINE__ << " : ";dmpr(cerr,##__VA_ARGS__)
#define dump(x) cerr << "LINE" << __LINE__ << " : " << #x << " = {";  \
	for(auto v: x) cerr << v << ","; cerr << "}" << endl;
#else
#define show(x) void(0)
#define dump(x) void(0)
#define shows(...) void(0)
#endif

template<class D> D divFloor(D a, D b){
	return a / b - (((a ^ b) < 0 && a % b != 0) ? 1 : 0);
}
template<class D> D divCeil(D a, D b) {
	return a / b + (((a ^ b) > 0 && a % b != 0) ? 1 : 0);
}

template<class T>
T rnd(T l,T r){	//[l,r)
	using D = uniform_int_distribution<T>;
	static random_device rd;
	static mt19937 gen(rd());
	return D(l,r-1)(gen);
}
template<class T>
T rnd(T n){	//[0,n)
	return rnd(T(0),n);
}
#include "../../math/poly.cpp"
#include "../../math/online_convolution.cpp"

void test(Poly<mint> f, Poly<mint> g){
	int n = si(f);
	assert(g[0]);
	auto h = f * g.inv(n);
	Online_Division<mint> X;
	rep(i,n){
		assert(X.query(i,f[i],g[i]) == h[i]);
	}
}
void TEST(){
	test({0},{2});
	test({3},{2});
	test({0,0},{9,0});
	test({0,2},{9,3});
	for(int N: {2,3,4,(1<<18)-1,(1<<18),(1<<18)+1}){
		Poly<mint> f(N),g(N);
		rep(i,N) f[i] = rnd(mint::mod);
		rep(i,N) g[i] = rnd(mint::mod);
		test(f,g);
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	TEST();

	int a,b; cin >> a >> b; cout << a+b << endl;
}