/*
	V<ll> treeKnapsack(VV<int> G, V<Item> items, int W)

	input:
		G: 木 N 頂点
		items: (w,p,n) が N 個
		W: 重さの上限
	output:
		dp[w] = ちょうど重み w のときの価値の最大値

	頂点 v には重さ w, 価値 p のものが n 個おいてあり、n 個全て使い切らない限り部分木は使えない
	O(NW)
	長さ W+1 のvector を N 回生成してるとこがもっと重そうだが、消し方がわからねえ
	verify: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1631
*/

namespace SlideMax{
	using D = ll;
	const int X = 1000000;
	D a[X];
	int idx[X];
	int L,R,I,num_del;
	void clear(){
		L = R = I = num_del = 0;
	}
	void add(D v){
		while(L<R && v>a[R-1]) R--;			// D-D comparison v<a[R-1]
		a[R] = v;
		idx[R] = I;
		R++,I++;
	}
	void del(){
		if(L<R && idx[L] == num_del) L++;
		num_del++;
	}
	D getmax(){
		assert(L<R);
		return a[L];
	}
	int getargmax(){
		assert(L<R);
		return idx[L];
	}
}
const ll inf = TEN(18);
struct Item{
	// 重さw, 価値p の物体が n個
	// n個全部使い切ると下の頂点を使えるようになる
	int w; ll p; int n;
	friend ostream& operator<<(ostream &o,const Item& x){ return o<<"("<<x.w<<","<<x.p<<" * " << x.n << ")";}
};
void slide(V<ll>& f, int w, ll p, int n){
	int W = si(f)-1;
	rep(r,w){
		SlideMax::clear();
		if(r > W) break;
		for(int i=0,x=r;x<=W;i++,x+=w){
			SlideMax::add(f[x]-i*p);
			f[x] = SlideMax::getmax() + i*p;
			if(f[x] < -inf/2) f[x] = -inf;
			if(i >= n) SlideMax::del();
		}
	}
}

V<ll> treeKnapsack(VV<int> G, V<Item> items, int W){
	assert(si(G) == si(items));
	auto rec = [&](auto& self, int v, int p, V<ll>& dp_init)->void{
		V<ll> dp(W+1,-inf);
		auto& f = items[v];
		for(ll i=0; i+ll(f.w)*f.n<=W; i++){
			if(dp_init[i] != -inf) dp[i+f.w*f.n] = dp_init[i] + f.p * f.n;
		}
		for(int u: G[v]) if(u != p){
			self(self,u,v,dp);
		}
		slide(dp_init,f.w,f.p,f.n);	// <= n
		rep(i,W+1) chmax(dp[i], dp_init[i]);
		dp_init = dp;
	};
	V<ll> dp(W+1,-inf); dp[0] = 0;
	rec(rec,0,-1,dp); return dp;
}
