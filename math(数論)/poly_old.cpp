/*
これは カスです(みればわかる)

多項式
常に次数maxまで持っとく方が楽そう
0の次数は-1
あと<を定義しても>は(rel_opsしても) 元のやつが呼ばれるので注意
minも元のやつを呼ぶので #define min(x,y) (x<y)?x:y とかすればOK 闇
*/
typedef long long ll;
typedef vector<ll> poly;
const int MX;			//max deg
int deg(poly x){
	for(int i=MX;i>=0;i--) if(x[i]!=0) return i;
	return -1;
}
void showpoly(poly x){
	int N=deg(x);
	if(N==-1){
		puts("0");
		return;
	}
	for(int i=N;i>=0;i--){
		if(x[i]==0) continue;
		if(i!=N&&x[i]>0) cout<<"+";
		if(x[i]==-1) cout<<"-";
		else if(x[i]!=1) cout<<x[i];
		if(i==0){
			if(x[i]==1||x[i]==-1) cout<<"1";
		}else if(i==1){
			cout<<"x";
		}else{
			cout<<"x^"<<i;
		}
	}
	puts("");
}
bool operator<(poly x,poly y){				//辞書順だけど,普通にデータ逆に持つだけで良くないこれ
	for(int i=MX;i>=0;i--){
		if(x[i]<y[i]) return 1;
		if(x[i]>y[i]) return 0;
	}
	return 0;
}
bool operator>(poly x,poly y){return (y<x);}
poly operator+(poly x,poly y){
	rep(i,MX+1) x[i]+=y[i];
	return x;
}
poly operator-(poly x,poly y){
	rep(i,MX+1) x[i]-=y[i];
	return x;
}
void operator+=(poly &x,poly y){
	rep(i,MX+1) x[i]+=y[i];
}
void operator-=(poly &x,poly y){
	rep(i,MX+1) x[i]-=y[i];
}
poly operator*(poly x,poly y){
	poly z(MX+1,0);
	rep(i,MX+1) rep(j,MX+1-i) z[i+j]+=x[i]*y[j];
	return z;
}
poly operator*(int x,poly y){
	rep(i,MX+1) y[i]*=x;
	return y;
}