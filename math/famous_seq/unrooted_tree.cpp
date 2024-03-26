/*
	unlabeled rooted tree		https://oeis.org/A000081
	unlabeled unrooted tree		https://oeis.org/A000055
	列挙は graph/enumTrees.cpp 参照

	online_convolution がボトルネック O(N log^2N)
*/

#include "../../template.hpp"
#include "../../math/poly.cpp"
#include "../../math/online_convolution.cpp"

/*
	https://mathworld.wolfram.com/RootedTree.html
	f[i+1] = 1/i * \sum_{1<=j<=i} (\sum_{d|j} f[d]*d) * f[i-j+1]
*/
V<mint> unlabeledRootedTrees(int N){
	V<mint> f(N+1),g(N+1);
	Online_Convolution<mint> X;
	rep1(i,N){
		if(i == 1){
			f[i] = 1;
		}else{
			f[i] = X.query(i-2,f[i-1],g[i-1]) / (i-1);
		}
		for(int j=i;j<=N;j+=i) g[j] += f[i]*i;
	}
	return f;
}

/*
	https://mathworld.wolfram.com/RootedTree.html
		R: rooted tree の set
		U: unrooted tree の set
		A: unrooted tree の頂点のひとつに印をつけたものの set
		B: unrooted tree の辺のひとつに印をつけたものの set
		A = R, B = H(R, 2)
		同型 A + B = U + R^2 が作れる (どうやるんだっけ)
	よって: rooted + H(rooted, 2) = unrooted + rooted^2
*/
V<mint> unlabeledUnrootedTrees(int N){
	Poly<mint> f = unlabeledRootedTrees(N);
	Poly<mint> g(N+1); for(int i=0;i<=N;i+=2) g[i] = f[i/2];
	return (f - (f*f-g)/2).low(N+1);
}
