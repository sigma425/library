/*
	各品物が無限にあり、品物の重さ <= W, 価値でかい、重さ容量でかい、のとき、
	W^2 までをDPすればあとは価値/重さが一番大きいやつを取れば良い、という有名なやつがある
	これは O(NW^2) でできる
	が、実は O(W^2logW) に落ちる

	initialize:
		- items: (w,v) たち
	query(w):
		- 重みの総和 w 以下の価値の最大

	ref: https://www.sciencedirect.com/science/article/pii/S002200002100088X
	verify: https://atcoder.jp/contests/ndpc/submissions/75808550
*/
struct Knapsack{
	vector<pair<int,ll>> items;
	V<ll> dp;
	int X;
	Knapsack(vector<pair<int,ll>> _items): items(_items){
		int W = 0;
		for(auto [w,v]: items) chmax(W,w);
		sort(all(items),[&](auto x, auto y){
			// return x.sc/x.fs > y.sc/y.fs
			return x.sc * y.fs > y.sc * x.fs;
		});
		X = W*W;
		dp.resize(X+1);
		rep1(j,X){
			int try_num = min(divCeil(3*W*W,j), si(items));
			rep(i,try_num) if(j >= items[i].fs) chmax(dp[j], dp[j-items[i].fs] + items[i].sc);
		}
	}
	ll query(ll w){
		if(w <= X) return dp[w];
		ll w0 = items[0].fs, v0 = items[0].sc;
		ll n0 = divCeil(w-X,w0);
		return dp[w-n0*w0] + n0 * v0;
	}
};