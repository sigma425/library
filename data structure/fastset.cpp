/*
	g++11 -O3
	fastset 233[ms]
	set 7757[ms]
	よさそう
*/
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
#define dump(x) cerr << "LINE" << __LINE__ << " : " << #x << " = {";  \
	for(auto v: x) cerr << v << ","; cerr << "}" << endl;
#else
#define show(x) true
#define dump(x) true
#endif

struct FastSet{	//[0,N)
	using ull = unsigned long long;
	int N,D;
	vector<vector<ull>> seg;
	FastSet(int N_):N(N_){
		assert(N_ >= 1);
		if(N_ == 1) N_++;
		while(N_>1){
			N_ = (N_+63)>>6;
			seg.pb(vector<ull>(N_));
		}
		D = seg.size();
	}
	void insert(int x){
		rep(d,D){
			ull b = 1ull<<(x&63);
			x >>= 6;
			seg[d][x] |= b;
		}
	}
	void erase(int x){	//なくてもよんでいい
		rep(d,D){
			ull b = 1ull<<(x&63);
			x >>= 6;
			seg[d][x] &= ~b;
			if(seg[d][x]) break;
		}
	}
	int geq(int x){		//x<=res
		if(x >= N) return N;
		if(x < 0) x = 0;
		rep(d,D){
			int i = x>>6, r = x&63;
			if(i == (int)seg[d].size()) break;
			ull b = seg[d][i]>>r;
			if(b){
				x += bsf(b);
				while(d--){
					x = (x<<6)|bsf(seg[d][x]);
				}
				return x;
			}else{
				x = (x>>6)+1;
			}
		}
		return N;
	}
	int leq(int x){		//res<=x
		if(x < 0) return -1;
		if(x >= N) x = N-1;
		rep(d,D){
			if(x == -1) break;
			int i = x>>6, r = x&63;
			ull b = seg[d][i]<<(r^63);
			if(b){
				x -= bsr(b)^63;
				while(d--){
					x = (x<<6)|bsr(seg[d][x]);
				}
				return x;
			}
			x = (x>>6)-1;
		}
		return -1;
	}
	bool has(int x){
		if(x<0 || x>=N) return false;
		return (seg[0][x>>6]>>(x&63))&1;
	}

	int bsr(ull x){return __builtin_clzll(x)^63;}
	int bsf(ull x){return __builtin_ctzll(x);}

};


struct Timer{
	clock_t st;
	void start(){
		st = clock();
	}
	int ms(){
		return (clock()-st)*1000 / CLOCKS_PER_SEC;
	}
};

void unittest(){
	srand((unsigned)time(NULL));
	int N = 1e7;

	vector<int> qs,qs2,qs3;
	int T = 1e7;
	rep(i,T){
		qs.pb(rand()%(N));
	}
	rep(i,T){
		qs2.pb(rand()%N);
	}
	rep(i,T){
		qs3.pb(rand()%N);
	}

	vector<int> ans,ans2;
	{
		Timer tm;
		tm.start();
		FastSet st(N);
		rep(i,T){
			st.insert(qs[i]);
			int v = st.geq(qs2[i]);
			ans.pb(v);
			v = st.leq(qs2[i]);
			ans.pb(v);
			st.erase(qs3[i]);
		}
		printf("fastset %d[ms]\n",tm.ms());
	}
	{
		Timer tm;
		tm.start();
		set<int> st;
		st.insert(-1);
		st.insert(N);
		rep(i,T){
			st.insert(qs[i]);
			int v = *st.lower_bound(qs2[i]);
			ans2.pb(v);
			auto it = st.upper_bound(qs2[i]);
			it--;
			ans2.pb(*it);
			st.erase(qs3[i]);
		}
		printf("set %d[ms]\n",tm.ms());
	}
	assert(ans == ans2);
}
int main(){
	int N; cin >> N;
	FastSet st(N);
	while(true){
		string s; cin >> s;
		int x; cin >> x;
		if(s == "insert"){
			st.insert(x);
		}else if(s == "erase"){
			st.erase(x);
		}else if(s == "leq"){
			show(st.leq(x));
		}else if(s == "geq"){
			show(st.geq(x));
		}else if(s == "has"){
			show(st.has(x));
		}else{
			cerr << "waf" << endl;
		}
	}
	unittest();
}