/*
	note: mod 998 で高速に多項式自体の復元をしたい時は poly.cpp を参照！！ O(Nlog^2N)

	多項式補間
	Lagrange interpolation
	O(N^2)
	N点(xs[i],ys[i])が与えられた時にそれを通るN-1次多項式のxでの値を返す
	xs[i]がpairwise distinctじゃないとダメ

*/

template<class T>
T interpolate(V<T> xs, V<T> ys, T x){
	int N = xs.size();
	T res = 0;
	rep(i,N){
		T a = ys[i];
		rep(j,N) if(j!=i) a *= (x-xs[j]) / (xs[i]-xs[j]);
		res += a;
	}
	return res;
}

// O(N^2)
// verified: XXI GP of Tokyo A
template<class T>
V<T> interpolate(V<T> xs,V<T> ys){
	int N = xs.size();
	V<T> p(N+1); p[0] = 1; // \prod_i (x-xs[i])
	rep(i,N){
		per(j,i+1){
			p[j+1] += p[j];
			p[j] *= -xs[i];
		}
	}
	V<T> res(N);
	rep(i,N){
		// w_i := ys[i] / \prod_j(\neq i) (xs[i]-xs[j])
		T w = 1;
		rep(j,N) if(j!=i) w *= (xs[i]-xs[j]);
		w = ys[i] / w;
		// add w_i * p/(x-xs[i])
		T v = 1;
		per(j,N){
			res[j] += v * w;
			v = p[j] + v * xs[i];
		}
	}
	return res;
}