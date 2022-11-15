/*
	非不偏ゲームを数とみなせる場合がある
	再帰的に left選択肢のうちmax < right選択肢のうちmin が成り立ってればそうなる
	このときの値は、(lmax,rmin) のうち最も単純な数
	特に、right選択肢がない場合は(lmax,\infty) のうち・・・

	単純:
		整数は絶対値が小さい方が単純
		整数を含まない区間なら、m/2べき と表したときの冪数が少ないものが単純

	例
	{|} = 0, {0|} = 1, {2|} = 3, {-2|} = 0
	{-3 | -2} = -5/2

	{0|0} = * nimの1 数ではない

	x/2^30 の形で持つ　実験用のライブラリということで

	le = -inf, ri = inf;
	for(l: le_cand) chmax(le,l)
	for(r: ri_cand) chmin(ri,r)
	return getNum(le,ri)
*/
using Num = ll;
const int H = 30;
const ll B = 1LL<<H;
const Num inf = 1LL<<60;

Num getNum(Num l, Num r){
	assert(l < r);			// if so, this is not a number
	ll l0 = divFloor(l,B)*B+B;
	ll r0 = divCeil(r,B)*B-B;
	if(l0 <= r0){
		if(l0 <= 0 && 0 <= r0) return 0;
		if(0 <= l0) return l0;
		if(r0 <= 0) return r0;
	}
	per(h,H){
		ll b = 1LL<<h;
		ll lh = divFloor(l,b)*b+b;
		ll rh = divCeil(r,b)*b-b;
		if(lh <= rh){
			assert(lh == rh);
			return lh;
		}
	}
	assert(0);
};
void showNum(Num x){
	ll g = __gcd(abs(x),B);
	cerr << x/g << "/" << B/g;
}