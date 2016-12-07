/*
monotone minima
H*Wのmatrixで,行最小値のある場所(いっぱいあったら左(右でもいいけどどっちかで固定))が下に行くにつれて右に行く
ときmonotoneという
この時に全部の行の最小値の場所をO(NlogN)で求める
もちろん行列がもともとそのまま与えられてたらなんの意味もないけど,
得るのに計算量がかかる何らかの関数で与えられてたりしたら有用

Monge->totally monotone
で,この時頑張ればlogが取れる(SMAWK)んだけど,結構面倒
*/
int f(int x,int y){}
int mni[100];
void minima(int ia,int ib,int ja,int jb){	//[ia,ib]*[ja,jb]
	if(ia>ib) return;
	if(ia==ib){
		int mn=0,id=-1;
		for(int j=ja;j<=jb;j++){
			int tmp=f(ia,j);
			if(id<0||mn>tmp) id=j,mn=tmp;
		}
		mni[ia]=id;
		return;
	}
	int im=(ia+ib)/2;
	minima(im,im,ja,jb);
	minima(ia,im-1,ja,mni[im]);
	minima(im+1,ib,mni[im],jb);
}
