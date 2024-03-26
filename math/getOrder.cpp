/*
	x,p が与えられて、x^r = 1 mod p を満たす最小の正整数 r を返す
	p: fix で x が大量に来るケースを想定

	前計算: p-1 の素因数 q_i を列挙
	クエリ:
		x^(p-1) = 1 はわかってるので、指数をどんどん q_i で割っていく
		O(log p * (p-1の素因数の個数))
	p が素数じゃない場合は、p-1 じゃなくて phi(m) で同じことをやればいい
*/

template <class T, class Op = multiplies<>>
constexpr T power(T a, uint64_t n, T init = 1, Op op = Op{}) {
	while (n) {
		if (n & 1) init = op(init, a);
		if (n >>= 1) a = op(a, a);
	}
	return init;
}

ll getOrder(ll x){
	auto pw = [&](ll x, ll r){
		return power<ll>(x,r,1,[&](ll a,ll b){return ll(__int128(a)*b%p);});
	};
	ll r = p-1;
	// ps: p-1 (or phi(m)) を割る素数の集合 前計算
	for(ll q: ps){
		while(r%q==0 && pw(x,r/q) == 1) r /= q;
	}
	return r;
};