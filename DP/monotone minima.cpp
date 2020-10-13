/*
	f(x,y) の row maxima (rightmost) が 講義単調増加なとき、 O(H + W logH) 回の f() call で row maxima(のindex) をすべて求める
	maxima / minima , leftmost / rightmost で4通りあるけどコメントある行の不等号変えるだけで可能、一貫性はないといけないことに注意
	特にDPで使うとき、rowが全部infだから初手で右端になってしまって壊れる、みたいなのに十分注意すること
	verified at:
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