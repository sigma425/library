/*
	x_i \in [l_i,r_i] を random に取ってきたときに x_0 < x_1 < .. < x_{N-1} となる確率を求める
	input:
		mint(l_i) とかだけ見ても順序がわからない可能性があるので、
		val[N][2]: mintでの値
		order_[N][2]: 実際の順序が入ったなにか、先に座圧したものを渡してもいいしdoubleとかFracとかで渡してもいい

	あと l_i = r_i には対応していない　こういうiで分割してそれぞれで解くしかないか？

	complexity: O(N^3)
	verify: https://atcoder.jp/contests/arc113/submissions/25330348
*/
template<class Ord>
mint IncreasingProb(VV<mint> val, VV<Ord> order_){
	int N = si(val);
	assert(si(invs) >= N+2);
	auto ord = Vec<int>(N,2);
	{
		V<Ord> os;
		rep(i,N) rep(j,2) os.pb(order_[i][j]);
		mkuni(os);
		rep(i,N) rep(j,2) ord[i][j] = lwb(os,order_[i][j]);
	}
	rep(i,N){
		assert(ord[i][0] < ord[i][1]);	// L_i >= R_i 禁止! 実際は一点の場合は定義できるが面倒なので仮定
	}
	int K = 1;
	rep(i,N) rep(j,2) chmax(K,ord[i][j]+1);
	V<mint> xs(K);
	rep(i,N) rep(j,2) xs[ord[i][j]] = val[i][j];

	auto is = Vec<bool>(N,K-1);
	rep(i,N){
		for(int j=ord[i][0];j<ord[i][1];j++) is[i][j] = true;
	}

	auto dp = Vec<mint>(K,N+1);
	dp[0][0] = 1;
	rep(k,K-1){
		rep(i,N+1) if(dp[k][i]){
			mint tmp = 1;
			for(int ni=i;ni<=N;ni++){
				dp[k+1][ni] += dp[k][i] * tmp;
				if(ni != N){
					if(!is[ni][k]) break;
					tmp *= (xs[k+1]-xs[k]) * invs[ni+1-i];
				}
			}
		}
	}
	mint prob = dp[K-1][N];
	rep(i,N) prob /= val[i][1]-val[i][0];
	return prob;
}