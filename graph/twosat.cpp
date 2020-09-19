/*
	2-SAT
	true,falseというよりかは a0 xor a1 (排反) みたいな気持ち
	sccに依存
	O(N+M)
	verify : ARC069 F
*/
struct twosat{
	struct E{int to;};
	int N;
	VV<E> G;

	twosat(int varnum):N(varnum),G(N+N){}

	void OR(int x,int xtype,int y,int ytype){
		// cerr << "add " << x << ":" << xtype << " or " << y << ":" << ytype << endl;
		x = x*2 + xtype, y = y*2 + ytype;
		G[x^1].push_back({y});
		G[y^1].push_back({x});
	}
	void THEN(int x,int xtype,int y,int ytype){
		OR(x,1-xtype,y,ytype);
	}
	void EQ(int x,int xtype,int y,int ytype){
		THEN(x,xtype,y,ytype);
		THEN(y,ytype,x,xtype);
	}
	/*
		こっちは 0_1 / 2_3 / .. N+N-2_N+N-1 がペア
	*/
	void OR(int x, int y){
		G[x^1].push_back({y});
		G[y^1].push_back({x});
	}
	void THEN(int x,int y){
		// cerr << "THEN:" << x << " -> " << y << endl;
		OR(x^1,y);
	}
	void EQ(int x,int y){
		THEN(x,y);
		THEN(y,x);
	}
	V<int> solve(){		// select which type
		SCC<E> scc(G);
		rep(i,N) if(scc.id[i*2] == scc.id[i*2+1]) return {};
		V<int> res(N,-1);
		per(k,scc.groups.size()){
			for(int v: scc.groups[k]){
				if(res[v/2] == -1) res[v/2] = v%2;
			}
		}
		return res;
	}
};
