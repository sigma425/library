/*
	デバッグ用にターミナルに出力する文字の色を変える
	https://qiita.com/PruneMazui/items/8a023347772620025ad6
	COLOR("4?")で、
	0 1 2 3 4 5 6 7
	黒赤緑黃青紫水灰

	グリッド塗り分けとかに使うといいかも
*/
#include "../template.hpp"

#define COLOR(s) ("\x1b[" s "m")


void ANDGrid(){
	auto printc = [&](int c){
		if(c == 0) cout << COLOR("47")<<' '<<COLOR();
		if(c == 1) cout << COLOR("41")<<'A'<<COLOR();
		if(c == 2) cout << COLOR("44")<<'B'<<COLOR();
		if(c == 3) cout << COLOR("45")<<'X'<<COLOR();
	};
	int H,W; cin>>H>>W;
	V<string> s(H),a(H),b(H);
	rep(i,H) cin>>s[i];
	rep(i,H){
		if(i%2==0){
			a[i]=string(W-1,'#')+".";
			b[i]=string(W-1,'.')+"#";
		}else{
			a[i]="#"+string(W-1,'.');
			b[i]="."+string(W-1,'#');
		}
	}
	rep(i,H) rep(j,W) if(s[i][j]=='#') a[i][j]=b[i][j]='#';
	rep(i,H) cout<<a[i]<<endl;
	puts("");
	rep(i,H) cout<<b[i]<<endl;
	puts("");
	rep(i,H){
		rep(j,W) printc((a[i][j]=='#')*2 + (b[i][j]=='#'));
		cout << endl;
	}
}

int main(){

}