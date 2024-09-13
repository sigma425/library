---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: misc/highbit.hpp
    title: misc/highbit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://contest.ucup.ac/submission/563208
  bundledCode: "#line 1 \"ds/bitset.hpp\"\n/*\n\t\u81EA\u524D bitset\n\tN \u3092\u6307\
    \u5B9A\u3067\u304D\u308B\u3001ull \u3092 bs.a \u3067\u53D6\u3063\u3066\u3053\u308C\
    \u308B \u306A\u3069\u306B\u3088\u308A\u4FBF\u5229\u306A\u3053\u3068\u304C\u3042\
    \u308B\n\tnext(i), prev(i) \u3084\u305D\u306E\u4ED6\u4FBF\u5229\u95A2\u6570\u306F\
    \u7D50\u69CB\u3042\u308A\u307E\u3059\n\tverify: ucup-3-9 https://contest.ucup.ac/submission/563208\
    \ sum_range \u7B49\n*/\n#line 1 \"misc/highbit.hpp\"\n/*\n\tx       0  1  2  3\
    \  4  5  6  7  8  9\n\tmsb(x) -1  0  1  1  2  2  2  2  3  3\n\t\u6700\u4E0A\u4F4D\
    bit\n*/\nint highbit(int x){\n\treturn 31 - countl_zero<uint>(x);\n}\nint highbit(uint\
    \ x){\n\treturn 31 - countl_zero<uint>(x);\n}\nint highbit(ll x){\n\treturn 63\
    \ - countl_zero<ull>(x);\n}\nint highbit(ull x){\n\treturn 63 - countl_zero<ull>(x);\n\
    }\n\n/*\n\tx       0  1  2  3  4  5  6  7  8  9\n\tlsb(x) 32  0  1  0  2  0  1\
    \  0  3  0\n\t\u6700\u4E0B\u4F4Dbit\n*/\nint lowbit(int x){\n\treturn countr_zero<uint>(x);\n\
    }\nint lowbit(uint x){\n\treturn countr_zero<uint>(x);\n}\nint lowbit(ll x){\n\
    \treturn countr_zero<ull>(x);\n}\nint lowbit(ull x){\n\treturn countr_zero<ull>(x);\n\
    }\n#line 8 \"ds/bitset.hpp\"\n\nstruct Bitset{\n\tint N;\n\tvector<ull> a;\n\n\
    \tBitset(int N_ = 0, bool init = false):N(N_){\n\t\tint sz = (N + 63) >> 6;\n\t\
    \ta.assign(sz, init ? -1 : 0);\n\t\tif(N) a.back() >>= (64 * a.size() - N);\n\t\
    }\n\n\tint size(){ return N; }\n\n\tBitset& operator&=(const Bitset& r){\n\t\t\
    assert(N == r.N);\n\t\trep(i,a.size()) a[i] &= r.a[i];\n\t\treturn *this;\n\t\
    }\n\tBitset& operator|=(const Bitset& r){\n\t\tassert(N == r.N);\n\t\trep(i,a.size())\
    \ a[i] |= r.a[i];\n\t\treturn *this;\n\t}\n\tBitset& operator^=(const Bitset&\
    \ r){\n\t\tassert(N == r.N);\n\t\trep(i,a.size()) a[i] ^= r.a[i];\n\t\treturn\
    \ *this;\n\t}\n\tBitset operator&(const Bitset& r) const { return Bitset(*this)\
    \ &= r; }\n\tBitset operator|(const Bitset& r) const { return Bitset(*this) |=\
    \ r; }\n\tBitset operator^(const Bitset& r) const { return Bitset(*this) ^= r;\
    \ }\n\tBitset operator~() const {\n\t\tBitset r = *this;\n\n\t}\n\n\t// std::bitset::reference\
    \ \u7684\u306A\u3084\u3064 bool \u304C 1 byte \u306A\u306E\u3067 bool& \u304C\
    ... \u307F\u305F\u3044\u306A\u306E\u3092\u89E3\u6D88\u3067\u304D\u308B\n\tstruct\
    \ Ref{\n\t\tull *p;\n\t\tint pos;\n\t\tRef(Bitset& b, int pos_){\n\t\t\tp = b.a.data()\
    \ + (pos_ >> 6);\n\t\t\tpos = pos_ & 63;\n\t\t}\n\t\toperator bool() const { return\
    \ (*p >> pos)&1; }\n\t\tRef& operator=(bool x){\n\t\t\tif(x) *p |= 1ULL << pos;\n\
    \t\t\telse *p &= ~(1ULL << pos);\n\t\t\treturn *this;\n\t\t}\n\t\tvoid flip(){\
    \ *p ^= 1ULL<<pos; }\n\t};\n\n\tRef operator[](int i){ return Ref(*this, i); }\n\
    \n\tvoid flip(int i){ (*this)[i].flip(); }\n\tvoid setall(bool init){\n\t\tint\
    \ sz = (N + 63) >> 6;\n\t\tfill(all(a), init ? -1 : 0);\n\t\tif(N) a.back() >>=\
    \ (64 * a.size() - N);\n\t}\n\n\t// >= i\n\tint next(int i){\n\t\tchmax(i, 0);\n\
    \t\tif(i >= N) return N;\n\t\tint k = i >> 6;\n\t\t\n\t\tull x = a[k];\n\t\tint\
    \ s = i & 63;\n\t\tx = (x >> s) << s;\n\t\tif(x) return (k << 6) | lowbit(x);\n\
    \t\tfor(int idx = k+1; idx < si(a); idx++) if(a[idx]){\n\t\t\treturn (idx << 6)\
    \ | lowbit(a[idx]);\n\t\t}\n\t\treturn N;\n\t}\n\t// <= i\n\tint prev(int i){\n\
    \t\tchmin(i, N-1);\n\t\tif(i <= -1) return -1;\n\t\tint k = i >> 6;\n\n\t\tif((i&63)\
    \ < 63){\n\t\t\tull x = a[k];\n\t\t\tint s = i & 63;\n\t\t\tx &= (1ULL << (s+1))\
    \ - 1;\n\t\t\tif(x) return (k << 6) | highbit(x);\n\t\t\tk--;\n\t\t}\n\t\tper(idx,k+1)\
    \ if(a[idx]){\n\t\t\treturn (idx << 6) | highbit(a[idx]);\n\t\t}\n\t\treturn -1;\n\
    \t}\n\n\tint count_range(int L, int R){\n\t\tassert(0 <= L && L <= R && R <= N);\n\
    \t\tint cnt = 0;\n\t\twhile((L<R) && (L&63)) cnt += (*this)[L++];\n\t\twhile((L<R)\
    \ && (R&63)) cnt += (*this)[--R];\n\t\tint l = L >> 6, r = R >> 6;\n\t\tfor(int\
    \ i=l;i<r;i++) cnt += popcount(a[i]);\n\t\treturn cnt;\n\t}\n\n\t// \\sum_{L <=\
    \ i < R} (b[i] ? i : 0)\n\tll sum_range(int L, int R){\n\t\tstatic int buf[1<<8]\
    \ = {};\n\t\tif(buf[2] == 0){\n\t\t\trep(s,1<<8){\n\t\t\t\trep(i,8) if(s&1<<i)\
    \ buf[s] += i;\n\t\t\t}\n\t\t}\n\n\t\tassert(0 <= L && L <= R && R <= N);\n\t\t\
    ll sum = 0;\n\t\twhile((L<R) && (L&63)) if((*this)[L++]) sum += L-1;\n\t\twhile((L<R)\
    \ && (R&63)) if((*this)[--R]) sum += R;\n\t\tint l = L >> 6, r = R >> 6;\n\t\t\
    for(int i=l;i<r;i++){\n\t\t\trep(k,8){\n\t\t\t\tsum += buf[(a[i] >> (k*8)) & 255]\
    \ + popcount<uint>((a[i] >> (k*8)) & 255) * (i << 6 | k << 3);\n\t\t\t}\n\t\t\
    }\n\t\treturn sum;\n\t}\n};\n"
  code: "/*\n\t\u81EA\u524D bitset\n\tN \u3092\u6307\u5B9A\u3067\u304D\u308B\u3001\
    ull \u3092 bs.a \u3067\u53D6\u3063\u3066\u3053\u308C\u308B \u306A\u3069\u306B\u3088\
    \u308A\u4FBF\u5229\u306A\u3053\u3068\u304C\u3042\u308B\n\tnext(i), prev(i) \u3084\
    \u305D\u306E\u4ED6\u4FBF\u5229\u95A2\u6570\u306F\u7D50\u69CB\u3042\u308A\u307E\
    \u3059\n\tverify: ucup-3-9 https://contest.ucup.ac/submission/563208 sum_range\
    \ \u7B49\n*/\n#include \"misc/highbit.hpp\"\n\nstruct Bitset{\n\tint N;\n\tvector<ull>\
    \ a;\n\n\tBitset(int N_ = 0, bool init = false):N(N_){\n\t\tint sz = (N + 63)\
    \ >> 6;\n\t\ta.assign(sz, init ? -1 : 0);\n\t\tif(N) a.back() >>= (64 * a.size()\
    \ - N);\n\t}\n\n\tint size(){ return N; }\n\n\tBitset& operator&=(const Bitset&\
    \ r){\n\t\tassert(N == r.N);\n\t\trep(i,a.size()) a[i] &= r.a[i];\n\t\treturn\
    \ *this;\n\t}\n\tBitset& operator|=(const Bitset& r){\n\t\tassert(N == r.N);\n\
    \t\trep(i,a.size()) a[i] |= r.a[i];\n\t\treturn *this;\n\t}\n\tBitset& operator^=(const\
    \ Bitset& r){\n\t\tassert(N == r.N);\n\t\trep(i,a.size()) a[i] ^= r.a[i];\n\t\t\
    return *this;\n\t}\n\tBitset operator&(const Bitset& r) const { return Bitset(*this)\
    \ &= r; }\n\tBitset operator|(const Bitset& r) const { return Bitset(*this) |=\
    \ r; }\n\tBitset operator^(const Bitset& r) const { return Bitset(*this) ^= r;\
    \ }\n\tBitset operator~() const {\n\t\tBitset r = *this;\n\n\t}\n\n\t// std::bitset::reference\
    \ \u7684\u306A\u3084\u3064 bool \u304C 1 byte \u306A\u306E\u3067 bool& \u304C\
    ... \u307F\u305F\u3044\u306A\u306E\u3092\u89E3\u6D88\u3067\u304D\u308B\n\tstruct\
    \ Ref{\n\t\tull *p;\n\t\tint pos;\n\t\tRef(Bitset& b, int pos_){\n\t\t\tp = b.a.data()\
    \ + (pos_ >> 6);\n\t\t\tpos = pos_ & 63;\n\t\t}\n\t\toperator bool() const { return\
    \ (*p >> pos)&1; }\n\t\tRef& operator=(bool x){\n\t\t\tif(x) *p |= 1ULL << pos;\n\
    \t\t\telse *p &= ~(1ULL << pos);\n\t\t\treturn *this;\n\t\t}\n\t\tvoid flip(){\
    \ *p ^= 1ULL<<pos; }\n\t};\n\n\tRef operator[](int i){ return Ref(*this, i); }\n\
    \n\tvoid flip(int i){ (*this)[i].flip(); }\n\tvoid setall(bool init){\n\t\tint\
    \ sz = (N + 63) >> 6;\n\t\tfill(all(a), init ? -1 : 0);\n\t\tif(N) a.back() >>=\
    \ (64 * a.size() - N);\n\t}\n\n\t// >= i\n\tint next(int i){\n\t\tchmax(i, 0);\n\
    \t\tif(i >= N) return N;\n\t\tint k = i >> 6;\n\t\t\n\t\tull x = a[k];\n\t\tint\
    \ s = i & 63;\n\t\tx = (x >> s) << s;\n\t\tif(x) return (k << 6) | lowbit(x);\n\
    \t\tfor(int idx = k+1; idx < si(a); idx++) if(a[idx]){\n\t\t\treturn (idx << 6)\
    \ | lowbit(a[idx]);\n\t\t}\n\t\treturn N;\n\t}\n\t// <= i\n\tint prev(int i){\n\
    \t\tchmin(i, N-1);\n\t\tif(i <= -1) return -1;\n\t\tint k = i >> 6;\n\n\t\tif((i&63)\
    \ < 63){\n\t\t\tull x = a[k];\n\t\t\tint s = i & 63;\n\t\t\tx &= (1ULL << (s+1))\
    \ - 1;\n\t\t\tif(x) return (k << 6) | highbit(x);\n\t\t\tk--;\n\t\t}\n\t\tper(idx,k+1)\
    \ if(a[idx]){\n\t\t\treturn (idx << 6) | highbit(a[idx]);\n\t\t}\n\t\treturn -1;\n\
    \t}\n\n\tint count_range(int L, int R){\n\t\tassert(0 <= L && L <= R && R <= N);\n\
    \t\tint cnt = 0;\n\t\twhile((L<R) && (L&63)) cnt += (*this)[L++];\n\t\twhile((L<R)\
    \ && (R&63)) cnt += (*this)[--R];\n\t\tint l = L >> 6, r = R >> 6;\n\t\tfor(int\
    \ i=l;i<r;i++) cnt += popcount(a[i]);\n\t\treturn cnt;\n\t}\n\n\t// \\sum_{L <=\
    \ i < R} (b[i] ? i : 0)\n\tll sum_range(int L, int R){\n\t\tstatic int buf[1<<8]\
    \ = {};\n\t\tif(buf[2] == 0){\n\t\t\trep(s,1<<8){\n\t\t\t\trep(i,8) if(s&1<<i)\
    \ buf[s] += i;\n\t\t\t}\n\t\t}\n\n\t\tassert(0 <= L && L <= R && R <= N);\n\t\t\
    ll sum = 0;\n\t\twhile((L<R) && (L&63)) if((*this)[L++]) sum += L-1;\n\t\twhile((L<R)\
    \ && (R&63)) if((*this)[--R]) sum += R;\n\t\tint l = L >> 6, r = R >> 6;\n\t\t\
    for(int i=l;i<r;i++){\n\t\t\trep(k,8){\n\t\t\t\tsum += buf[(a[i] >> (k*8)) & 255]\
    \ + popcount<uint>((a[i] >> (k*8)) & 255) * (i << 6 | k << 3);\n\t\t\t}\n\t\t\
    }\n\t\treturn sum;\n\t}\n};"
  dependsOn:
  - misc/highbit.hpp
  isVerificationFile: false
  path: ds/bitset.hpp
  requiredBy: []
  timestamp: '2024-09-14 08:32:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/bitset.hpp
layout: document
redirect_from:
- /library/ds/bitset.hpp
- /library/ds/bitset.hpp.html
title: ds/bitset.hpp
---
