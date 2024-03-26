/*
	# (directed spanning tree rooted at r)
	 = det (-e[i][j] の対角成分にindeg[i] 足したやつ、 の (r,r) 除いた小行列)
	非連結だと当然 0 になる
	オイラー閉路の数を数えるのに使える:
		BEST Theorem
		ec(G) = #dirSpt * \prod_v (deg[v]-1)!
	オイラー閉路は孤立点があっても存在する ↓のコードは内部で除いてるので注意

	検索用: 有向全域木 行列木定理
*/
mint countDirSpt(VV<int> e, int r){
	int N = si(e);
	V<int> indeg(N),outdeg(N);
	rep(i,N) rep(j,N){
		indeg[j] += e[i][j];
		outdeg[i] += e[i][j];
	}
	{
		bool hase = false;
		rep(i,N) if(indeg[i]) hase = true;
	}
	rep(i,N) if(indeg[i] != outdeg[i]) return 0;
	if(indeg[r] == 0) return 0;

	V<int> id(N,-1);
	int I = 0;
	rep(i,N){
		if(indeg[i] && i != r){
			id[i] = I++;
		}
	}
	VV<mint> A(I,V<mint>(I));

	rep(i,N) if(id[i] != -1) rep(j,N) if(id[j] != -1){
		if(i != j){
			A[id[i]][id[j]] = -e[i][j];
		}else{
			A[id[i]][id[i]] = indeg[i] - e[i][i];
		}
	}
	show(A);
	mint res = det(A);
	rep(i,N) if(indeg[i]) res *= fact[indeg[i]-1];
	return res;
}
