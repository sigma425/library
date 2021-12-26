using m1 = ModInt<998244353>;
using m2 = ModInt<1000000007>;

using Hash2 = pair<m1,m2>;
Hash2 operator+(const Hash2& a, const Hash2& b){
	return {a.fs+b.fs,a.sc+b.sc};
}
Hash2 operator-(const Hash2& a, const Hash2& b){
	return {a.fs-b.fs,a.sc-b.sc};
}
Hash2 operator*(const Hash2& a, const Hash2& b){
	return {a.fs*b.fs,a.sc*b.sc};
}
const Hash2 base = {31415,27182};
// pow_base / ipow_base

using Hash = Hash2;