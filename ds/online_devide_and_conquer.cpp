/*
	dp[0]: given
	dp[i] = \sum_{0<=j<i} f(j,i) * dp[j]
	dp[N] を求めよ みたいな状況はよくある
	[l,m) が正しく計算できている時 [l,m) -> [m,r) を行う を繰り返して全体を計算できる
*/

void TEST(int N){

	// [l,r) を正しく計算する。事前条件: [0,l) -> [l,r) の遷移がすでに終わっている
	auto calc = [&](auto&& self, int l, int r) -> void {
		if(r-l <= 1) return;
		int m = (l+r)/2;

		self(self, l, m);

		// 正しく求まっている [l,m) を用いて、[l,m) -> [m,r) の遷移をすべて行う
		for(int i=l;i<m;i++) for(int j=m;j<r;j++){
			cerr << i << " -> " << j << " | " << endl;
		}

		self(self, m, r);
	};
	calc(calc, 0, N+1);
}
