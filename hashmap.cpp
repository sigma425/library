/*
	https://codeforces.com/blog/entry/62393
*/
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
 
template<class t,class u>
using hashmap = gp_hash_table<t,u,custom_hash>;


/*
    https://codeforces.com/gym/102361/submission/61948583
	高速だけど、mod S でわけるかなりメチャクチャなハッシュなのでどうしてもってとき以外は使わない
	S は 最大mapsize より大きく設定
*/
struct HashMap{
	const int S = ;
    int N=0,fst[S];
	ll va[S]; int nxt[S],vb[S];
	void clear(){
		memset(fst,0,sizeof fst); N=0;
	}
	void add(ll x){
		int c=x%S; if(c<0) c=-c;
		for(int e=fst[c];e;e=nxt[e])
			if(va[e]==x) {++vb[e]; return;}
		++N; va[N]=x; vb[N]=1;
		nxt[N]=fst[c]; fst[c]=N;
	}
	int operator [] (ll x){
		int c=x%S; if(c<0) c=-c;
		for(int e=fst[c];e;e=nxt[e])
			if(va[e]==x) return vb[e];
		return 0;
	}
};