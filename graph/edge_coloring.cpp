/*
	ここに全てある https://codeforces.com/blog/entry/75431

	- maxdeg +0/1 彩色 O(NM)
		https://github.com/koosaga/olympiad/blob/master/Library/codes/graph_etc/edgecolor_vizing.cpp
		実装が面倒になった、こっからとってくる
		Vizing

	- bipartite edge coloring
		多重辺もOK 二部への分割が与えられている必要もない
		O(NM) で十分でしょう、D-regular なら DN^2

		verified https://codeforces.com/contest/600/problem/F
*/

V<int> bipartite_edge_coloring(int N, V<pair<int,int>> es){
	using P = pair<int,int>;
	int M = es.size();
	int D = 0;
	{
		V<int> d(N);
		for(P e:es) d[e.fs]++,d[e.sc]++;
		rep(i,N) chmax(D,d[i]);
	}
	VV<int> vc2e(N,V<int>(D,-1));
	V<int> col(M,-1);
	auto color = [&](int e,int c){
		int x = es[e].fs, y = es[e].sc;
		if(col[e] != -1){
			vc2e[x][col[e]] = -1;
			vc2e[y][col[e]] = -1;
		}
		col[e] = c;
		vc2e[x][c] = e, vc2e[y][c] = e;
	};
	V<int> buf(M);
	rep(t,M){
		int x = es[t].fs, y = es[t].sc;
		int c0 = 0, c1 = 0;
		while(vc2e[x][c0] != -1) c0++;
		while(vc2e[y][c1] != -1) c1++;
		if(c0 == c1){
			color(t,c0);
			continue;
		}
		int v = x, c = c1, I = 0;
		while(vc2e[v][c] != -1){
			int e = vc2e[v][c];
			v ^= es[e].fs^es[e].sc;
			c ^= c0^c1;
			buf[I++] = e;
		}
		v = x;
		rep(i,I){
			int e = buf[i];
			col[e] ^= c0^c1;
			swap(vc2e[v][c0],vc2e[v][c1]);
			v ^= es[e].fs^es[e].sc;
		}
		swap(vc2e[v][c0],vc2e[v][c1]);
		color(t,c1);
	}
	return col;
}
