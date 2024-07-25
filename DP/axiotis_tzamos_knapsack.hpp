/*
	(w_i,v_i) と W が与えられるので sum = w での価値の最大 dp[w] を w \in [0,W] について求める
	不可能なら dp[w] = -inf. T (vのtype) によって inf を書き換えること
	v が負になる場合も動く. その場合は -inf + v がアンダーフローしないように注意

	O(W * (w_iの種類数))

	knapsack するときに、w が同じやつを集めて同時に遷移すると、mod w ごとに (max,+) convolution になる
	追加する側は v でソートすれば concave にできるので、これは線形で出来る
	これを使うために、「同じwのうちvが大きい方W/w個」みたいなのを外側で列挙することもある

	verify: https://contest.ucup.ac/submission/487402
*/

#include "maxplus_convolution_b_concave.hpp"

template<class T>
vector<T> knapsack(vector<pair<int,T>> items, int W){
	vector<vector<T>> w2vs(W+1);
	for(auto [w,v]: items){
		if(w > W) continue;
		w2vs[w].push_back(v);
	}
	const T inf = 1e18;
	vector<T> dp(W+1, -inf); dp[0] = 0;
	rep1(w,W) if(!w2vs[w].empty()){
		auto& vs = w2vs[w];
		sort(all(vs),greater<T>());
		int K = min(W/w, si(vs));
		V<T> b(K+1); rep(i,K) b[i+1] = b[i] + vs[i];
		rep(r,w){
			int n = (W-r)/w;
			V<T> a(n+1); rep(i,n+1) a[i] = dp[i*w+r];
			auto c = maxplus_conv<T,true>(a,b);
			rep(i,n+1) dp[i*w+r] = c[i];
		}
	}
	return dp;
}