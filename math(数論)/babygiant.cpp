//g in group G, x in set X
//G,Xをclassでなくtypedefにするときは==の条件とかに注意
const int BN,GN;
X act(G g,X x){

}
G pro(G f,G g){

}
G ex(G g,int N){
	G e=;
	while(N){
		if(N%2) e=pro(g,e);
		g=pro(g,g);
		N>>=1;
	}
	return e;
}
ll solve2(G g,X s,X t){		//calc min k s.t.{g^n(s)=t}		if no ans, -1
	if(s==t) return 0;
	pair<X,int> babies[BN];
	rep(i,BN){	//0~BN-1
		babies[i]=mp(t,i);
		t=act(g,t);
	}
	sort(babies,babies+BN);
	g=ex(g,BN);	//g->g^BN
	rep1(i,GN){		//1~GN
		s=act(g,s);
		int pos=upper_bound(babies,babies+BN,mp(s,BN))-babies-1;
		if(pos>=0&&babies[pos].fs==s) return i*BN-babies[pos].sc;
	}
	return -1;
}
ll solve(G g,X s,X t){		//calc next some times
	if(s==t) return 0;
	rep1(i,){
		s=act(g,s);
		if(s==t) return i;
	}
	//処理
	ll tmp=solve2();
	if(tmp>=0) return tmp+;
	return -1;
}
ll brute(G g,X s,X t){
	if(s==t) return 0;
	rep(i,1000000){
		s=act(g,s);
		if(s==t) return i+1;
	}
	return -1;
}
int main(){
	
}