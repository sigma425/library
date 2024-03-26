/*
	kmp[i] = 長さ i の prefix の longest border
	s : aabaabaaa
	k : _010123452

	はじめての文字の比較 			i -> A[i] (前ループのjなので、今のiからみるとA[i])
	文字が一致した場所(終了した箇所)	i -> A[i+1]-1 (まあみればわかる)
	片方から片方は簡単に導ける.両方とも根付き木でかなり性質が良い.
	計算量解析は、黒辺を下る回数が、とか思ったけど+1があるので普通にA[i]の値の遷移を考えたほうがいいか.

	string, vector<hoge> どっちでも使える

	getBorder: [1,N] のうち borderの長さ を昇順に返す
		特に N は常に含まれていることに注意

*/


template<class Str>
vector<int> getKMP(Str s){
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

template<class Str>
V<int> getBorder(Str s){
	int N = s.size();
	auto kmp = getKMP(s);
	V<int> res;
	for(int b=N;b>0;b=kmp[b]) res.eb(b);
	reverse(all(res));
	return res;
}
