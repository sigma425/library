/*
	多項式補間
	Lagrange interpolation
	O(N^2)
	N点(xs[i],ys[i])が与えられた時にそれを通るN-1次多項式のxでの値を返す
	xs[i]がpairwise distinctじゃないとダメ
	あとxs[i]==xになるときにちゃんと処理する必要がある doubleとかで誤差でxs[i]==x+epsみたいなのに注意

	Z/pZとかにするなら割り算とかをちゃんと書き換えること


	多項式自体を求めたいときは(x-xs[j])の部分が多項式の掛け算なので、全体でO(N^3)になる,
	戻すDPっぽいのをやるとO(N^2)だが面倒そう
	Newton補間使ったほうが良くない?

	OpenCup/1101/I.cpp がmint,poly,interpolationを複合して使ってる例

*/

template<class T>
T interpolate(vector<T> xs,vector<T> ys,T x){
	int N=xs.size();
	rep(i,N){
		if(xs[i]==x) return ys[i];
	}
	T ret=0;
	rep(i,N){
		T a=ys[i];
		rep(j,N) if(j!=i) a*=(x-xs[j])/(xs[i]-xs[j]);
		ret+=a;
	}
	return ret;
}

/*
	多項式自体を求める O(N^3 log N)
	O(N^2 log N) とかにしたいなら(x - x[i]) の左右からの累積積を計算しておく 面倒だから書いてないけど
*/
Poly<mint> interpolate(V<mint> x, V<mint> y){
	assert(x.size() == y.size());
	int N = x.size();
	Poly<mint> f;
	rep(i,N){
		Poly<mint> g({y[i]});
		mint coef = 1;
		rep(j,N) if(j!=i){
			g *= Poly<mint>({-x[j],1});
			coef *= (x[i]-x[j]);
		}
		g *= coef.inv();
		f += g;
	}
	return f;
}
