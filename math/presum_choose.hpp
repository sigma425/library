/*
	f(x,y) := C(x,0) + .. + C(x,y) を返す
		y > x の場合でもちゃんと 2^x を返す
		y < 0 の場合でもちゃんと 0 を返す

	C(x+1,0) + .. + C(x+1,y) = 2 * (C(x,0)+..+C(x,y)) - C(x,y) を使って x++, x-- をするが、この時 y > x とかでもこの式が壊れないことに注意
	前回読んだ (x,y) から O(|x-tx| + |y-ty|) で計算する。mo で使ったり、単調なことが分かってる時にこれ読んでサボるなど

	verify: ARC224F https://atcoder.jp/contests/arc224/submissions/77557996
*/

struct presumChoose{
	int x,y;
	mint sum;

	presumChoose():x(0),y(0),sum(1){}

	// C(tx,0) + ... + C(tx,ty)
	mint f(int tx, int ty){
		if(ty < 0) return 0;
		while(x < tx){
			sum = sum*2 - Choose(x,y);
			x++;
		}
		while(x > tx){
			x--;
			sum = (sum + Choose(x,y)) * invs[2];
		}
		while(y < ty){
			y++;
			sum += Choose(x,y);
		}
		while(y > ty){
			sum -= Choose(x,y);
			y--;
		}
		return sum;
	}
};
