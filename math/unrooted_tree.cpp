/*
	ラベルなし根なしの木の数え上げ
	O(N^2logN)
	R + H(R,2) = U + R^2
	verify: OEIS
*/
int main(){
	int N; cin >> N;
	V<mint> dp(N+1),ndp(N+1);
	dp[1] = 1;

	// O(N^2 log N)
	rep1(d,N){			// use subtree size
		// now, dp[d] equals to the number of rooted tree with size d
		// use subtree with size d
		rep(s,N+1){		// now size
			mint h = 1;
			mint num = dp[d];
			rep(i,N+1){	// use i subtrees (with size d)
				int ns = s + d * i;
				if(ns > N) break;
//				ndp[ns] += dp[s] * H(dp[d],i);
				ndp[ns] += dp[s] * h;
				h *= num+i;
				h /= i+1;
			}
		}
		rep(s,N+1){
			dp[s] = ndp[s];
			ndp[s] = 0;
		}
	}
	shows("rooted:",dp);

	// R + H(R,2) = U + R^2

	V<mint> R = dp;
	V<mint> U(N+1);
	rep1(n,N){
		U[n] = R[n];	//R
		rep1(x,n/2){	//H(R,2)
			if(x+x == n){
				U[n] += (R[x]+1)*R[x] / 2;
			}else{
				U[n] += R[x] * R[n-x];
			}
		}
		rep1(x,n-1){	// - R^2
			U[n] -= R[x] * R[n-x];
		}
	}
	shows("unrooted:",U);
}
