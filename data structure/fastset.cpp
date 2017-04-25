/*
	g++11 -O3
	fastset 198[ms]
	set 4164[ms]
	よさそう
*/
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}

struct FastSet{	//[0,N)
	using ull = unsigned long long;
	int N,D;
	vector<vector<ull>> seg;
	FastSet(int N):N(N){
		while(N>1){
			N = (N+63)>>6;
			seg.pb(vector<ull>(N));
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

	vector<int> qs,qs2;
	int T = 1e7;
	rep(i,T){
		qs.pb(rand()%(N));
	}
	rep(i,T){
		qs2.pb(rand()%N);
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
		}
		rep(i,T){
			st.erase(qs[i]);
		}
		printf("fastset %d[ms]\n",tm.ms());
	}
	{
		Timer tm;
		tm.start();
		set<int> st;
		st.insert(N);
		rep(i,T){
			st.insert(qs[i]);
			int v = *st.lower_bound(qs2[i]);
			ans2.pb(v);
		}
		rep(i,T){
			st.erase(qs[i]);
		}
		printf("set %d[ms]\n",tm.ms());
	}
	assert(ans == ans2);
}
int main(){
	unittest();
}