#include "math/prime_sum.hpp"

/*
	1,..,N を頂点とする、1 を根とする以下のような根付き木を考える
	par[v] = v / (greatest factor of v) 逆に 1 から見ると 最小の素因数をかけていくことで v を作る
	 - 例えば 12 までの path は、 1 -> 2 -> 4 -> 12

	この木を探索する。ただし葉には直接アクセスしない(その親でそいつらを処理する)
	 - 例えば、v = 2*2*3*7 の子は v*7, v*11, v*13, .. v * ([N/v] 以下の最大の素数)
	 - v * p^2 > N ならば、v * p は葉になるので、v で処理すべき葉は、v * ( [sqrt(N/v)]+1 以上の最小の素数), v * prime, .. , v * ([N/v] 以下の最大の素数)
	 - ちょっと嘘で、例えばこの列挙の中に v*5 とか入ってたら、それは見ちゃダメなのでうまくやる
	結局、v で処理すべき値は
	 - v 自身
	 - v * { prime in (L,R] }
	 - ただし L = max([sqrt(N/v)], pr[l-1]) R = [N/v]
	 - L も R も 集合 {[N/i]} に含まれるので、各 x \in {[N/i]} について { v * p | p: prime <= x} について一気に処理できるようでなければいけない
		(L に関しては、L <= sqrt(N) なので含まれることがわかる)

	問題によってdfsの中でやることがまちまちなので、具体例をいくつか置いておいて直接いじるという形にしたいと思います
*/

/*
	例1: 指数列 (2 * 5^2 * 7 -> [1,2,1]) ごとに何かをする

	dfs で es を管理する
		直前に追加した値と比較したりでやや面倒

	doit(es, num) で es を num 個処理

	verify: ucup-3-20 F https://contest.ucup.ac/submission/807529
	10^9: 0.3s, 10^10: 2s
*/

void prime_factor_dfs(ll N){
	PrimeSum<ll> A(N, [](ll n){return n;});	// prime count

	vector<ll> cnt(20);
	auto doit = [&](vector<int> es, ll num){
		cnt[si(es)] += num;
	};

	/*
		今 v, 次 p[l] 以上を追加可能
	*/
	auto dfs = [&](auto& self, ll v, int l, vector<int>& es) -> void {
		// TODO: v について処理
		doit(es, 1);
		
		// TODO: v * {prime in (L,R]} について処理
		ll L = sqrtl(N/v), R = N/v;
		chmax(L, l == 0 ? 0 : pr[l-1]);
		ll pnum = A(R) - A(L);
		if(pnum){
			if(v != 1 && L < pr[l]){
				// 最後の素因数がもう一個増える
				es.back()++;
				doit(es, 1);
				pnum--;
				es.back()--;
			}
			es.emplace_back(1);
			doit(es, pnum);
			es.pop_back();
		}

		for(int i=l;i<si(pr);i++){
			ll p = pr[i];
			if(p > L) break;
			// v * p \in [pr[l], L] に遷移
			if(v != 1 && i == l){
				// 最後の素因数がもう一個増える
				es.back()++;
				self(self, v*p, i, es);
				es.back()--;
			}else{
				es.emplace_back(1);
				self(self, v*p, i, es);
				es.pop_back();
			}
		}
	};
	vector<int> es;
	dfs(dfs, 1, 0, es);

	mint ans = 1;
	rep1(i,si(cnt)-1) ans *= mint(i).pow(cnt[i]);
	cout << ans << endl;
}

/*
	例2: 素因数の個数(2^3 * 3^10 -> 13) の分布

	dfs では ecnt を持つだけ

	verify: Xmas Contest 2019 D,E https://atcoder.jp/contests/xmascon19/submissions/60620907
*/

void prime_factor_dfs(ll N){
	PrimeSum<ll> A(N, [](ll n){return n;});	// prime count

	vector<ll> cnt(40);
	auto doit = [&](int ecnt, ll num){
		cnt[ecnt] += num;
	};

	/*
		今 v, 次 p[l] 以上を追加可能
	*/
	auto dfs = [&](auto& self, ll v, int l, int ecnt) -> void {
		// TODO: v について処理
		doit(ecnt, 1);
		
		// TODO: v * {prime in (L,R]} について処理
		ll L = sqrtl(N/v), R = N/v;
		chmax(L, l == 0 ? 0 : pr[l-1]);
		ll pnum = A(R) - A(L);
		doit(ecnt+1, pnum);

		for(int i=l;i<si(pr);i++){
			ll p = pr[i];
			if(p > L) break;
			// v * p \in [pr[l], L] に遷移
			self(self, v*p, i, ecnt+1);
		}
	};
	dfs(dfs, 1, 0, 0);

	ll ans = 0;
	rep(i,si(cnt)) ans += i * cnt[i];
	cout << ans << endl;
}

/*
	例3: N 以下の正整数の和 (は?)
	N = 10^10: 0.3s, N = 10^11: 1.3s, N = 10^12: 7s
*/

void prime_factor_dfs(ll N){
	PrimeSum<mint> A(N, [](ll n){return (n+1)*n/2;});	// prime sum

	/*
		今 v, 次 p[l] 以上を追加可能
	*/
	mint ans = 0;
	auto dfs = [&](auto& self, ll v, int l) -> void {
		// TODO: v について処理
		ans += v;
		
		// TODO: v * {prime in (L,R]} について処理
		ll L = sqrtl(N/v), R = N/v;
		chmax(L, l == 0 ? 0 : pr[l-1]);
		mint sum = A(R) - A(L);
		ans += v * sum;

		for(int i=l;i<si(pr);i++){
			ll p = pr[i];
			if(p > L) break;
			// v * p \in [pr[l], L] に遷移
			self(self, v*p, i);
		}
	};
	dfs(dfs, 1, 0);
	cout << ans << endl;
}
