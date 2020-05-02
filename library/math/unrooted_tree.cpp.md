---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: math/unrooted_tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/unrooted_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-29 03:37:23+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/unrooted_tree.cpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

