/*
	score^M の総和を求めよ (M <= 200) みたいな問題が出たときに、
	\sum_{x \in states} x^M から \sum_{x \in states} (x+a)^M を求める みたいな遷移をしたいことがよくある
	あるいはマージ: \sum_{x \in states1} x^M と \sum_{y \in states2} y^M から \sum_{x,y} (x+y)^M を求める

	このとき \sum_x x^0, \sum_x x^1, ... \sum_x x^M をすべて持っておけば畳み込みで出来る
	が、\sum C(x,0), \sum C(x,1), ... \sum C(x,M) を持っておくと都合がいいことが多い
		- \sum C(x+a,M) = \sum C(x,M)*C(a,0) + \sum C(x,M-1)*C(a,1) + ... + \sum C(x,0)*C(a,M)
			a が小さい時後ろの方の項が消えるので、O(Ma) で愚直に畳み込める
		- \sum C(x+y,M) = \sum C(x,M) * \sum C(y,0) + \sum C(x,M-1) * \sum C(y,1) + ... + \sum C(x,0) * \sum C(y,M)
	
	x が小さいうちは後ろの方の項が0になっている、というのが嬉しいポイントかも
	
	使用例 ucup-3-32 B https://contest.ucup.ac/submission/937037
	検索用: 下降冪 累乗の和
*/

/*
	a[i] = \sum_x C(x,i) たちから、 b[i] = \sum_x C(x+1,i) たちを求める
	M より大きいところは捨てる

	O(sz)
*/
template<class mint>
void add_1(vector<mint>& a, const int M){
	assert(si(a) <= M+1);
	if(si(a) <= M) a.pb(0);
	per1(i,si(a)-1) a[i] += a[i-1];
};

/*
	a[i] = \sum_x C(x,i) と、 b[j] = \sum_y C(y,j) から、 c[k] = \sum_{x,y} C(x+y,k) を求める
	M より大きいところは捨てる

	O(sz*sz)
*/
template<class mint>
vector<mint> conv(const vector<mint>& a, const vector<mint>& b, const int M){
	int A = si(a), B = si(b);
	assert(A <= M+1 && B <= M+1);
	vector<mint> c(min(A+B-1,M+1));
	for(int i=0;i<A;i++) for(int j=0;j<B&&i+j<=M;j++){
		c[i+j] += a[i] * b[j];
	}
	return c;
}


/*
	initialize S([0,n],[0,k])
	O(nk)
*/
VV<mint> S2;
void initStirling2(int n, int k = -1){
	if(k == -1) k = n;
	S2.resize(n+1); rep(i,n+1) S2[i].resize(min(i+1,k+1));
	S2[0][0] = 1;
	rep1(i,n){
		rep1(j,min(i-1,k)) S2[i][j] = S2[i-1][j-1] + j * S2[i-1][j];
		if(i <= k) S2[i][i] = 1;
	}
}

/*
	a[i] = \sum_x C(x,i) たちから、 \sum_x x^M を求める

	x^M = \sum_{0<=i<=M} S2(M,i)*i! C(x,i)
*/
template<class mint>
mint calc_powsum(V<mint>& a, const int M){
	mint res = 0;
	rep(i,si(a)) res += S2[M][i] * fact[i] * a[i];
	return res;
}
