// floor(a^(1/k))
// by risjiroh, hos

template <class T, class Op = multiplies<>>
constexpr T power(T a, uint64_t n, T init = 1, Op op = Op{}) {
	while (n) {
		if (n & 1) init = op(init, a);
		if (n >>= 1) a = op(a, a);
	}
	return init;
}
uint64_t floorKthRoot(uint64_t a, uint64_t k) {
	assert(k);
	if (a == 0 or k == 1) return a;
	if (k >= 64) return 1;
	if (k == 2) return sqrtl(a);
	static constexpr uint64_t inf = -1;
	static auto mul = [](auto x, auto y) { return x <= inf / y ? x * y : inf; };
	a -= a == inf;
	uint64_t ok = pow(a, (1 - 1e-15) / k), ng = pow(a, (1 + 1e-15) / k) + 1;
	while (ng - ok > 1) {
		auto mid = (ok + ng) / 2;
		(power<uint64_t>(mid, k, 1, mul) <= a ? ok : ng) = mid;
	}
	return ok;
}
/*
void unittest() {
	// k = 2
	for (unsigned long long x = 0; x < 1000; ++x) {
		for (unsigned long long a = x * x; a < (x + 1) * (x + 1); ++a) {
			assert(floorKthRoot(a, 2) == x);
		}
	}
	for (unsigned long long x = 4294967295ULL - 1000; x <= 4294967295ULL; ++x) {
		for (unsigned long long a = x * x - 1000; a < x * x; ++a) {
			assert(floorKthRoot(a, 2) == x - 1);
		}
		for (unsigned long long a = x * x; a < x * x + 1000; ++a) {
			assert(floorKthRoot(a, 2) == x);
		}
	}
	for (unsigned long long b = 1; b <= 1000; ++b) {
		assert(floorKthRoot(-b, 2) == 4294967295ULL);
	}

	// general
	for (unsigned long long x = 2; x < 1000; ++x) {
		unsigned long long a = x;
		for (int k = 1; ; ++k) {
			assert(floorKthRoot(a - 1, k) == x - 1);
			assert(floorKthRoot(a, k) == x);
			if (a > ~0ULL / x) break;
			a *= x;
		}
	}
}
*/