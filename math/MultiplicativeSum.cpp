/*
	f: multiplicative
	F(n) := \sum_{1<=i<=n} f(n)
	k \in Q(n) := { [n/j] } に対して、F(k) を持っている k=0もOK(0)
	- Q(n) 列挙
		for(ll k=1;;k=N/(N/(k+1))){
			j \in ( n/(k+1) , n/k ] に対し n/j = k
			if(k == N) break;
		}
*/
template<class mint>
struct MultSum{
	ll N,r;
	V<mint> a,b;
	MultSum(ll N_):N(N_){
		r = sqrtl(N);
		a.resize(r+1); b.resize(r+1);
	}
	mint operator[](ll k) const { return k<=r ? a[k] : b[N/k]; }
	mint& operator[](ll k){ return k<=r ? a[k] : b[N/k]; }
};

/*
	return H s.t. f*g = h
	H(n) = \sum_{j \in Q(n)} ( F([n/j])-F([n/(j+1)]) ) * G(j)
	H(1),..,H(L) までは既に計算済みとする
		L = 0 なら O(N^{3/4})
		L = (N/(loglogN))^{2/3} とすることで O*(N^{2/3}) に
		実際は L = 10^7 くらいまで前計算？
	割り算を減らしたりdoubleの割り算に変える？ことでもうちょっと最適化できるかもね
	verify:
		してないぜ
*/
template<class mint>
void getH(const MultSum<mint>& F, const MultSum<mint>& G, MultSum<mint>& H, ll L){
	ll N = F.N;
	for(ll n=1;;n=N/(N/(n+1))){
		if(n > L){
			for(ll j=1;;j=n/(n/(j+1))){
				H[n] += (F[n/j] - F[n/(j+1)]) * G[j];
				if(j == n) break;
			}
		}
		if(n == N) break;
	}
}

/*
	compute G s.t. f*g = h
	H(n) = \sum_{j \in Q(n)} ( F([n/j])-F([n/(j+1)]) ) * G(j)
	G(1),..,G(L) までは既に計算済みとする
		L = 0 なら O(N^{3/4})
		L = (N/(loglogN))^{2/3} とすることで O*(N^{2/3}) に
		実際は L = 10^7 くらいまで前計算？
	割り算を減らしたりdoubleの割り算に変える？ことでもうちょっと最適化できるかもね
	verify:
		https://atcoder.jp/contests/xmascon19/submissions/38449904
		https://projecteuler.net/problem=415
*/
template<class mint>
void getG(const MultSum<mint>& F, MultSum<mint>& G, const MultSum<mint>& H, ll L){
	ll N = F.N;
	for(ll n=1;;n=N/(N/(n+1))){
		if(n > L){
			mint S = H[n];
			for(ll j=1;;j=n/(n/(j+1))){
				if(j < n){
					S -= (F[n/j] - F[n/(j+1)]) * G[j];
				}else{
					G[n] = S;
					break;
				}
			}
		}
		if(n == N) break;
	}	
}
