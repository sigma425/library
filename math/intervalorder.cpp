/*
長さが正の区間がM個与えられたときに、端点の順序(=もありうる)を全列挙する
区間iの左端がi,右端がi+M
各VIが同じ座標を表している

ordsの大きさは 1, 13, 409, 23917, 2244361, 308682013
M=5までしか使えない

SRM710

各区間グラフが何個あるかが求めたいなら、左端を忘れて右端の順をキーに持ってDP
*/
bool B(int x,int i){return (x>>i)&1;}

typedef vector<int> VI;
typedef vector<VI> VV;

int M;
vector<VV> ords;
int cnt;

void dfs(int usel, int user, VV& ord){
//	show(usel);
//	show(user);
	if(usel==(1<<M)-1 && user==(1<<M)-1){
//		ords.pb(ord);
		cnt++;
		return;
	}
	int prev=-1;
	if(!ord.back().empty()) prev = ord.back().back();
	rep(i,M){
		if(!B(usel,i)){
			if(prev>=i) continue;
			ord.back().pb(i);
			dfs(usel|(1<<i),user,ord);
			ord.back().pop_back();
		}else if(!B(user,i)){
			if(prev>=i+M) continue;
			bool len0=0;
			for(int x:ord.back()) if(x==i) len0=1;
			if(len0) continue;
			ord.back().pb(i+M);
			dfs(usel,user|(1<<i),ord);
			ord.back().pop_back();
		}else{
			;
		}
	}
	if(!ord.back().empty()){
		ord.pb({});
		dfs(usel,user,ord);
		ord.pop_back();
	}
}

void enumorder(int M){
	::M = M;
	VV st(1,VI());
	dfs(0,0,st);
}