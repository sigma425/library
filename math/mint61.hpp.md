---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://contest.ucup.ac/submission/555578
  bundledCode: "#line 1 \"math/mint61.hpp\"\n/*\n\tmint mod 2^61 - 1\n\t\u3060\u3044\
    \u305F\u3044 rolling hash \u7528\n\tveryfy: ucup3-9 A https://contest.ucup.ac/submission/555578\n\
    */\nstruct ModInt61 {\n\tusing mint = ModInt61;\n\n\tstatic constexpr long long\
    \ mod = (1ULL << 61) - 1;\n\n\tunsigned long long v;\n\n\tModInt61() : v(0) {}\n\
    \tModInt61(ll v_) {\n\t\tv_ %= mod;\n\t\tif (v_ < 0) v_ += mod;\n\t\tv = v_;\n\
    \t}\n\n\texplicit operator bool() const {return v!=0;}\n\n\tmint& operator++()\
    \ {\n\t\tv++;\n\t\tif (v == umod()) v = 0;\n\t\treturn *this;\n\t}\n\tmint& operator--()\
    \ {\n\t\tif (v == 0) v = umod();\n\t\tv--;\n\t\treturn *this;\n\t}\n\tmint operator++(int)\
    \ {\n\t\tmint result = *this;\n\t\t++*this;\n\t\treturn result;\n\t}\n\tmint operator--(int)\
    \ {\n\t\tmint result = *this;\n\t\t--*this;\n\t\treturn result;\n\t}\n\n\tmint&\
    \ operator+=(const mint& rhs) {\n\t\tv += rhs.v;\n\t\tif (v >= umod()) v -= umod();\n\
    \t\treturn *this;\n\t}\n\tmint& operator-=(const mint& rhs) {\n\t\tv -= rhs.v;\n\
    \t\tif (v >= umod()) v += umod();\n\t\treturn *this;\n\t}\n\tmint& operator*=(const\
    \ mint& rhs) {\n\t\t__uint128_t t = (__uint128_t) v * rhs.v;\n\n\t\tv = (unsigned\
    \ long long)((t >> 61) + (t & umod()));\n\t\tv = (v >= umod()) ? v - umod() :\
    \ v;\n\n\t\treturn *this;\n\t}\n\tmint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n\n\tmint operator+() const { return *this; }\n\tmint\
    \ operator-() const { return mint() - *this; }\n\n\tmint pow(ll n) const {\n\t\
    \tif(n < 0) return inv().pow(-n);\n\t\tmint x = *this, r = 1;\n\t\twhile (n) {\n\
    \t\t\tif (n & 1) r *= x;\n\t\t\tx *= x;\n\t\t\tn >>= 1;\n\t\t}\n\t\treturn r;\n\
    \t}\n\tmint inv() const {\n\t\tassert(v);\n\t\treturn pow(umod() - 2);\n\t}\n\n\
    \ttemplate<class T> friend mint operator+(T a, const mint& b){ return (mint(a)\
    \ += b);}\n\ttemplate<class T> friend mint operator-(T a, const mint& b){ return\
    \ (mint(a) -= b);}\n\ttemplate<class T> friend mint operator*(T a, const mint&\
    \ b){ return (mint(a) *= b);}\n\ttemplate<class T> friend mint operator/(T a,\
    \ const mint& b){ return (mint(a) /= b);}\n\tfriend bool operator==(const mint&\
    \ lhs, const mint& rhs) { return lhs.v == rhs.v; }\n\tfriend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return lhs.v != rhs.v; }\n\tfriend bool operator<(const\
    \ mint& lhs, const mint& rhs) { return lhs.v < rhs.v; }\n\n\tfriend istream& operator>>(istream\
    \ &i, mint& x){\n\t\tll tmp; i >> tmp;\n\t\tx = mint(tmp);\n\t\treturn i;\n\t\
    }\n\tfriend ostream& operator<<(ostream &o,const mint& x){ return o<<x.v;}\n\n\
    \tstatic constexpr unsigned long long umod() { return mod; }\n};\n"
  code: "/*\n\tmint mod 2^61 - 1\n\t\u3060\u3044\u305F\u3044 rolling hash \u7528\n\
    \tveryfy: ucup3-9 A https://contest.ucup.ac/submission/555578\n*/\nstruct ModInt61\
    \ {\n\tusing mint = ModInt61;\n\n\tstatic constexpr long long mod = (1ULL << 61)\
    \ - 1;\n\n\tunsigned long long v;\n\n\tModInt61() : v(0) {}\n\tModInt61(ll v_)\
    \ {\n\t\tv_ %= mod;\n\t\tif (v_ < 0) v_ += mod;\n\t\tv = v_;\n\t}\n\n\texplicit\
    \ operator bool() const {return v!=0;}\n\n\tmint& operator++() {\n\t\tv++;\n\t\
    \tif (v == umod()) v = 0;\n\t\treturn *this;\n\t}\n\tmint& operator--() {\n\t\t\
    if (v == 0) v = umod();\n\t\tv--;\n\t\treturn *this;\n\t}\n\tmint operator++(int)\
    \ {\n\t\tmint result = *this;\n\t\t++*this;\n\t\treturn result;\n\t}\n\tmint operator--(int)\
    \ {\n\t\tmint result = *this;\n\t\t--*this;\n\t\treturn result;\n\t}\n\n\tmint&\
    \ operator+=(const mint& rhs) {\n\t\tv += rhs.v;\n\t\tif (v >= umod()) v -= umod();\n\
    \t\treturn *this;\n\t}\n\tmint& operator-=(const mint& rhs) {\n\t\tv -= rhs.v;\n\
    \t\tif (v >= umod()) v += umod();\n\t\treturn *this;\n\t}\n\tmint& operator*=(const\
    \ mint& rhs) {\n\t\t__uint128_t t = (__uint128_t) v * rhs.v;\n\n\t\tv = (unsigned\
    \ long long)((t >> 61) + (t & umod()));\n\t\tv = (v >= umod()) ? v - umod() :\
    \ v;\n\n\t\treturn *this;\n\t}\n\tmint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n\n\tmint operator+() const { return *this; }\n\tmint\
    \ operator-() const { return mint() - *this; }\n\n\tmint pow(ll n) const {\n\t\
    \tif(n < 0) return inv().pow(-n);\n\t\tmint x = *this, r = 1;\n\t\twhile (n) {\n\
    \t\t\tif (n & 1) r *= x;\n\t\t\tx *= x;\n\t\t\tn >>= 1;\n\t\t}\n\t\treturn r;\n\
    \t}\n\tmint inv() const {\n\t\tassert(v);\n\t\treturn pow(umod() - 2);\n\t}\n\n\
    \ttemplate<class T> friend mint operator+(T a, const mint& b){ return (mint(a)\
    \ += b);}\n\ttemplate<class T> friend mint operator-(T a, const mint& b){ return\
    \ (mint(a) -= b);}\n\ttemplate<class T> friend mint operator*(T a, const mint&\
    \ b){ return (mint(a) *= b);}\n\ttemplate<class T> friend mint operator/(T a,\
    \ const mint& b){ return (mint(a) /= b);}\n\tfriend bool operator==(const mint&\
    \ lhs, const mint& rhs) { return lhs.v == rhs.v; }\n\tfriend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return lhs.v != rhs.v; }\n\tfriend bool operator<(const\
    \ mint& lhs, const mint& rhs) { return lhs.v < rhs.v; }\n\n\tfriend istream& operator>>(istream\
    \ &i, mint& x){\n\t\tll tmp; i >> tmp;\n\t\tx = mint(tmp);\n\t\treturn i;\n\t\
    }\n\tfriend ostream& operator<<(ostream &o,const mint& x){ return o<<x.v;}\n\n\
    \tstatic constexpr unsigned long long umod() { return mod; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/mint61.hpp
  requiredBy: []
  timestamp: '2024-09-14 08:22:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mint61.hpp
layout: document
redirect_from:
- /library/math/mint61.hpp
- /library/math/mint61.hpp.html
title: math/mint61.hpp
---
