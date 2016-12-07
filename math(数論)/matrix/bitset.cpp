/*
	x[a][b]= (can go from a to b ?) のかけざん
	bitsetはやい
	ちょうどN取るのは無理なので注意(テンプレート引数なのでconstじゃないとダメ)
	あとswapが出来ない(12行目のとこ)
*/
const int MAX_N=;
typedef bitset<MAX_N> Bs;
typedef array<Bs,MAX_N> mat;
mat pro(mat x,mat y,int N){
	rep(i,N) rep(j,i){
		bool tmp=y[i][j];
		y[i][j]=y[j][i];
		y[j][i]=tmp;
	}
	mat z;
	rep(i,N) rep(j,N) z[i][j]=(x[i]&y[j]).any();
	return z;
}