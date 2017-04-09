/*
ロバストな偏角ソート (0,0)を渡すな
(0,+)が最小,同じ角度は適当

二周するのが必要な時(ex.各点から180度以内の点を探す)とかはかなり面倒な気がする
二週目ですか?っていうboolをもって,pair<P,bool>にして、shoの返り値を0~7にする
+pi とかもちょっと面倒なため、普通にdoubleでやっても良さそう
ちなみにわざわざ0~2piにすることはなくて、atan2(y,x)の返り値-pi~piを直接使うほうが楽そう

*/
inline int sho(P p){
	int x=p.fs,y=p.sc;
	if(x>0&&y>=0) return 0;
	if(x<=0&&y>0) return 1;
	if(x<0&&y<=0) return 2;
	if(x>=0&&y<0) return 3;
	assert(false);
}
bool comp(P p,P q){
	int s=sho(p),t=sho(q);
	if(s!=t) return s<t;
	ll a=p.fs,b=p.sc,c=q.fs,d=q.sc;
	return b*c<a*d;
}