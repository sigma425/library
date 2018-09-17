/*
	kmp[i] = 長さ i の prefix の longest border
	s : aabaabaaa
	k : _010123452

	はじめての文字の比較 			i -> A[i] (前ループのjなので、今のiからみるとA[i])
	文字が一致した場所(終了した箇所)	i -> A[i+1]-1 (まあみればわかる)
	片方から片方は簡単に導ける.両方とも根付き木でかなり性質が良い.
	計算量解析は、黒辺を下る回数が、とか思ったけど+1があるので普通にA[i]の値の遷移を考えたほうがいいか.

	border列挙

	vector<int> res;
	int X = kmp[N];
	while(X>0){
		res.pb(X);
		X = A[X];
	}
	return res;
*/


vector<int> getKMP(string s){
	int N = s.size();
	vector<int> A(N+1);
	A[0] = -1;
	int j = -1;
	rep(i,N){
		while(j>=0 && s[i]!=s[j]) j = A[j];
		j++;
		A[i+1] = j;
	}
	return A;
}