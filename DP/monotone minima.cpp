/*
	f(x,y) の row maxima (rightmost) が 広義単調増加なとき、 O(H + W logH) 回の f() call で row maxima(のindex) をすべて求める
	maxima / minima , leftmost / rightmost で4通りあるけどコメントある行の不等号変えるだけで可能、一貫性はないといけないことに注意

	典型例
		[0,N] を K 個の区間にわけて区間のコストの和最大/最小化
		愚直にはO(KN^2)

			dp[0][0] = 0, rep1(i,N) dp[0][i] = -inf;
			rep(k,K) rep(i,N+1){
				rep(j,i) chmax(dp[k+1][i],dp[k][j]+cost[j][i])
			}

		これを (k:fixして) f(i,j) = dp[k][j]+cost[j][i] として条件を満たすとすれば

			dp[0][0] = 0, rep1(i,N) dp[0][i] = -inf;
			rep(k,K){
				auto f = [&](int i,int j){
					if(j > i) return -inf; 
					return dp[k][j] + cost[j][i];
				};
				auto w = row_maxima(f,N+1,N+1);	// w[i] = iでの最適なj
				rep(i,N+1) dp[k+1][i] = dp[k][w[i]] + cost[w[i]][i];
			}

		と変形できる O(KNlogN)
		条件は、"より右までをk個で分けるとき、直近で切った場所はより右になる"
		k があるために f(j,i) みたいなのを順序を無視して評価できるので、使える
		当然下三角 (j<=i) のみまともな値が入っているとしていいが、dp[k+1][i] = -inf のとき最適rightmostがj=Nみたいになりうるので、それは注意すること
		なんかleftmostの方が安全そうだな
		無駄に切っていいか( <=> k++していいか <=> j=i が許されるか)も注意

	verified at:
		UniversalCup 1 day3 I
		https://atcoder.jp/contests/appini/submissions/11754773
		CF/868/F.cpp
*/

template<class F> V<int> row_maxima(F f,int H,int W){
	using D = typename result_of<F(int,int)>::type;
	V<int> res(H);
	auto sub = [&](auto self,int l,int r,int lb,int ub)->void{
		if(l >= r) return;
		int x = (l+r)/2;
		D best = f(x,lb);
		int argy = lb;
		for(int y=lb+1;y<=ub;y++){
			D val = f(x,y);
			if(val >= best){				//maxima (rightmost)
//			if(val > best){					//maxima (leftmost)
//			if(val <= best){				//minima (rightmost)
//			if(val < best){					//minima (leftmost)
				best = val;
				argy = y;
			}
		}
		res[x] = argy;
		self(self,l,x,lb,argy);
		self(self,x+1,r,argy,ub);
	};
	sub(sub,0,H,0,W-1);
	return res;
}