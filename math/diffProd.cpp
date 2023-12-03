/*
	差積 \prod_{i<j} (A_j-A_i)

	O(Nlog^2N) MultipointEval がいる

	f_0 := 1, f_1 := (x-A_0), .. , f_N := (x-A_0)..(x-A_{N-1}) として
	ans = \prod_{i} f_i(A_i)

	N = 100000 で 3s 遅すぎ
	俺の MultiPointEval がそもそも 1s くらいだからね
*/
mint diffProd(V<mint> A){
	int N = si(A);
	int s = 1, h = 0; while(s < N) {s *= 2; h++;}
	V<Poly<mint>> g(s+s,{1});
	rep(i,N) g[s+i] = {-A[i],1};
	for(int i=s-1;i>0;i--) g[i] = g[i*2] * g[i*2+1];
	mint res = 1;
	rep(k,h+1){
		rep(i,1<<k) if(!(i&1)){
			int y = (i+1)<<(h-k), z = (i+2)<<(h-k);
			V<mint> ps;
			for(int p=y;p<min(z,N);p++) ps.eb(A[p]);
			int id = (1<<k)+i;
			auto qs = MultipointEval<mint>(g[id],ps);
			for(auto q: qs) res *= q;
		}
	}
	return res;
}
mint diffProdBrute(V<mint> A){
	int N = si(A);
	mint res = 1;
	rep(j,N) rep(i,j) res *= A[j]-A[i];
	return res;
}

void diffProdTest(){
	rep(N,17){
		rep(t,100){
			V<mint> A(N);
			rep(i,N) A[i] = rnd(201)-100;
			assert(diffProd(A) == diffProdBrute(A));
		}
	}
	cerr << "diffProdTest: passed" << endl;
}