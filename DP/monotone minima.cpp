/*


monotone minima
H*W の配列aがあって, a[0] の最小を取る場所 <= a[1] の最小を取る場所 <= a[2] の最小を取る場所 ...
となっている時に、これらの場所をすべて求める

O(W log H)

ex.
H = 3, W = 5
3 2 4 3 5
3 4 1 2 2
1 1 0 1 0

Monge->totally monotone なので、

logつけるだけで一般化出来るからこっちが主流かなあ(mongeわかりにくいし)

重要な例:

dp[k][x]: k回切って今場所x

rep(k,K){
	rep(x,N+1){
		rep(y,x) chmin(dp[k+1][x],dp[k][y] + cost(y,x));
	}
}

っていうのがある時に、k,xでの最適yをA[k][x] とおいた時に A[k][x] <= A[k][x+1] が成り立つなら、これが適用できる
(kがないと、xを順番に計算せざるを得ないので無理?)

rep(k,K){
	minima(0,N+1,0,N+1); (内側でdp[k-1]を使う)
}

verified by CF/868/F.cpp

*/

using D = ll;
void minima(int lx,int rx,int ly,int ry){	//[lx,rx) について bestpos[x] を求める 調べる範囲は[ly,ry)でよい
	if(lx >= rx) return;

	int m = (lx+rx)/2;
	D best = 1e18;
	int bestpos = -1;
	for(int y = ly; y<ry; y++){
//		D val = f(x,y)
//		D val = dp[k-1][y] + cost(y,m);
		if(best>val){
			best = val;
			bestpos = y;
		}
	}

	dp[k][m] = best;
	
	minima(k,lx,m,ly,bestpos+1);

	minima(k,m+1,rx,bestpos,ry);
}

