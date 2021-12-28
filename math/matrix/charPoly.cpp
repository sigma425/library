/*
	T: field
		charPoly(VV<T> a):
			det( xI - a )
			O(n^3)
		detPoly(VV<T> a, VV<T> b):
			det( a + xb )
			O(n^3)
		detPoly(vector<VV<T>> a):
			det( a0 + a1x + ..)
			O(n^3k^3)
			https://ac.nowcoder.com/acm/contest/view-submission?submissionId=48446911

	T: commutative ring
		charPoly_divfree(VV<T> a):
			det( xI - a )
			O(n^4)

	T: field
		resultant(V<T> f, V<T> g)
		ProdSumOfRoots(V<T> f, V<T> g)
		ProdSumOfRootsWithout0(V<T> f, V<T> g)
*/

template<class T>
vector<T> charPoly(vector<vector<T>> a){
	int n = si(a);
	rep(j,n-2){
		for(int i=j+1;i<n;i++) if(a[i][j]){
			swap(a[j+1],a[i]);
			rep(k,n) swap(a[k][j+1],a[k][i]);
			break;
		}
		if(a[j+1][j]){
			const T r = T(1) / a[j+1][j];
			for(int i=j+2;i<n;i++){
				const T s = r * a[i][j];
				for(int k=j;k<n;k++) a[i][k] -= s * a[j+1][k];
				rep(k,n) a[k][j+1] += s * a[k][i];
			}
		}
	}
	vector<vector<T>> f(n+1);
	f[0] = {1};
	rep(i,n){
		f[i+1] = vector<T>(i+2);
		rep(j,i+1) f[i+1][j+1] = f[i][j];
		rep(j,i+1) f[i+1][j] -= a[i][i] * f[i][j];
		T beta = 1;
		per(j,i){
			beta *= a[j+1][j];
			const T s = beta * -a[j][i];
			rep(k,j+1) f[i+1][k] += s * f[j][k];
		}
	}
	return f[n];
}

/*
	https://github.com/noshi91/n91lib_rs/blob/master/src/algorithm/division_free_determinant.rs
	verifyはしてない、使ってないから(?)
	O(N^4)
*/
template<class T>
T divfree_determinant(VV<T> a){
	int N = si(a);
	VV<T> dp(N+1,V<T>(N+1,T::zero()));
	rep(i,N+1) dp[i][i] = T::one();
	rep(_,N){
		VV<T> nx(N+1,V<T>(N+1,T::zero()));
		rep(h,N){
			for(int c=h;c<N;c++){
				for(int v=h+1;v<N;v++){
					nx[h][v] -= dp[h][c] * a[c][v];
				}
				auto t = dp[h][c] * a[c][h];
				for(int v=h+1;v<N+1;v++){
					nx[v][v] += t;
				}
			}
		}
		dp = nx;
	}
	return dp[N][N];
}


/*
	T: field

	定義:
		空でない*数列* f = [a_0 , .. , a_m], g = [b_0 , .. , b_n] に対して次のように定義される
					|a2 a1 a0      |
					|   a2 a1 a0   |
		Res(f,g) = 	|	   a2 a1 a0|
					|b3 b2 b1 b0   |
					|   b3 b2 b1 b0|

	性質:
		Res(g,f) = Res(f,g) * (-1)^(mn)
		Res(cf,g) = Res(f,g) * c^n
		Res(f,dg) = Res(f,g) * d^m
		Res(f%g,g) = Res(f,g%f) = Res(f,g)	数列として見てるので行列のサイズは変わらないことに注意
		m > 0 かつ a_m = 0 のとき、a_mを削ると、
			Res(f,g) = Res([a_0 , .. , a_{m-1}], [b_0 , .. , b_n]) * b_n * (-1)^n

		☆ a_m \neq 0 かつ b_n \neq 0 のとき、
		f = a_0 + a_1 x + .. a_m x^m
		g = b_0 + b_1 x + .. b_n x^n
		f の根を α1,..,αm, g の根を β1,..,βn とする
		Res(f,g) = a_m^n * b_n^m * \prod_{i,j} (αi - βj)

	O(mn) fとgの互除法みたいな感じで計算する

	verify:
		XX Zhejiang K https://official.contest.yandex.ru/opencupXX/contest/17333/run-report/63224090/
		xmas 2021 H https://atcoder.jp/contests/xmascon21/submissions/28183908
*/
template<class T>
T resultant(vector<T> f, vector<T> g){
	T res = 1;
	int m = si(f)-1, n = si(g)-1;
	while(true){
		while(m>=0 && f[m]==0) m--;
		while(n>=0 && g[n]==0) n--;
		if(m < 0 or n < 0){
			res = 0; break;
		}
		if(m <= 0 or n <= 0){
			res *= f[m].pow(n) * g[n].pow(m);
			break;
		}
		if(m > n){
			if(m&n&1) res *= -1;
			swap(m,n);
			swap(f,g);
		}
		res *= f[m].pow(n);
		const T r = f[m].inv();
		for(int i=0;i<=m;i++) f[i] *= r;
		for(int j=n;j>=m;j--){
			for(int i=0;i<m;i++) g[j-m+i] -= f[i] * g[j];
			g[j] = 0;
		}
	}
	return res;
}
/*
	f = (x-α0)(x-α1)..
	g = (x-β0)(x-β1)..
	f,g should be monic
	
	output: \prod_{i,j} (αi + βj)
*/
template<class T>
T prodSumOfRoots(vector<T> f, vector<T> g){
	int m = si(f)-1, n = si(g)-1;
	assert(m >= 0);
	assert(n >= 0);
	assert(f[m] == 1);
	assert(g[n] == 1);

	// for non-monic
	// while(!f[m]) m--;
	// while(!g[n]) n--;
	// {
	// 	const T r = f[m].inv();
	// 	rep(i,m+1) f[i] *= r;
	// }
	// {
	// 	const T r = g[n].inv();
	// 	rep(i,n+1) g[i] *= r;
	// }

	for(int i=n-1;i>=0;i-=2) g[i] *= -1;
	return resultant(f,g);
}

/*
	α0 = β0 = 0
	f = x(x-α1)..
	g = x(x-β1)..
	f,g should be monic

	output: \prod_{i,j, i+j>0} (αi + βj)

	\prod_{i,j, i+j>0} (αi + βj)
	 = \prod_{i >= 0, j > 0} (αi + βj) * \prod_{i > 0} αi
	 = prodSumOfRoots(f,g/x) * [x]f * (-1)^(m-1)
*/
template<class T>
T prodSumOfRootsWithout0(vector<T> f, vector<T> g){
	int m = si(f)-1, n = si(g)-1;
	assert(m >= 1);
	assert(n >= 1);
	assert(f[0] == 0);
	assert(g[0] == 0);
	assert(f[m] == 1);
	assert(g[n] == 1);

	vector<T> gs(n); rep(i,n) gs[i] = g[i+1];
	return prodSumOfRoots(f,gs) * f[1] * mint(-1).pow(m-1);
}