---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://hitonanode.github.io/cplib-cpp/number/nimber.hpp
    - https://natsugiri.hatenablog.com/entry/2020/03/29/073605
  bundledCode: "#line 1 \"math/nimber.cpp\"\n// https://hitonanode.github.io/cplib-cpp/number/nimber.hpp\n\
    struct Nimber {\n\tusing ull = unsigned long long;\n\tull v;\n\tconst static std::array<std::array<unsigned,\
    \ 256>, 256> small_table;\n\tconst static std::array<std::array<std::array<ull,\
    \ 256>, 8>, 8> precalc;\n\n\texplicit operator bool() const { return v != 0; }\n\
    \tNimber(ull val = 0) : v(val) {}\n\tNimber operator+(const Nimber &x) const {\
    \ return Nimber(v ^ x.v); }\n\tNimber operator-(const Nimber &x) const { return\
    \ Nimber(v ^ x.v); }\n\tNimber operator-() const { return *this; }\n\tNimber &operator+=(const\
    \ Nimber &x) { return *this = *this + x; }\n\tNimber &operator-=(const Nimber\
    \ &x) { return *this = *this + x; }\n\ttemplate <class IStream> friend IStream\
    \ &operator>>(IStream &is, Nimber &x) {\n\t\tull v;\n\t\treturn is >> v, x = Nimber(v),\
    \ is;\n\t}\n\ttemplate <class OStream> friend OStream &operator<<(OStream &os,\
    \ const Nimber &x) {\n\t\treturn os << x.v;\n\t}\n\tbool operator==(const Nimber\
    \ &x) const { return v == x.v; }\n\tbool operator!=(const Nimber &x) const { return\
    \ v != x.v; }\n\tbool operator<(const Nimber &x) const { return v < x.v; }\n\n\
    \tstatic ull _rec(ull x, ull y) {\n\t\tif (x == 0 or y == 0) return 0;\n\t\tif\
    \ (x < y) x ^= y, y ^= x, x ^= y; // Make x >= y\n\t\tif (y == 1) return x;\n\t\
    \tfor (int shift = 64 / 2;; shift >>= 1) {\n\t\t\tull mask = (1ULL << shift) -\
    \ 1;\n\t\t\tif (y >> shift) {\n\t\t\t\tull v00 = _rec(x & mask, y & mask);\n\t\
    \t\t\tull v01 = _rec(x & mask, y >> shift);\n\t\t\t\tull v10 = _rec(x >> shift,\
    \ y & mask);\n\t\t\t\tull v11 = _rec(x >> shift, y >> shift);\n\t\t\t\treturn\
    \ v00 ^ ((v01 ^ v10 ^ v11) << shift) ^ _rec(v11, 1ULL << (shift - 1));\n\t\t\t\
    } else if (x >> shift) {\n\t\t\t\treturn (_rec(x >> shift, y) << shift) ^ _rec(x\
    \ & mask, y);\n\t\t\t}\n\t\t}\n\t}\n\tNimber operator*(const Nimber &x) const\
    \ {\n\t\tull ret = 0;\n\t\tfor (int d = 0; d < 8; ++d) {\n\t\t\tfor (int e = 0;\
    \ e < 8; ++e) {\n\t\t\t\tret ^= precalc[d][e][small_table[(v >> (d * 8)) & 255][(x.v\
    \ >> (e * 8)) & 255]];\n\t\t\t}\n\t\t}\n\t\treturn Nimber(ret);\n\t}\n\tNimber\
    \ &operator*=(const Nimber &x) { return *this = *this * x; }\n\tNimber operator/(const\
    \ Nimber &x) const {\n\t\t// TODO x^{2^64-2}\n\t\t// faster: https://natsugiri.hatenablog.com/entry/2020/03/29/073605\n\
    \t\tassert(false);\n\t\treturn x;\n\t}\n\tNimber &operator/=(const Nimber &x)\
    \ { return *this = *this / x; }\n\t\n};\n\nconst std::array<std::array<unsigned,\
    \ 256>, 256> Nimber::small_table = []() {\n\tstd::array<std::array<unsigned, 256>,\
    \ 256> ret;\n\tfor (int i = 0; i < 256; ++i) {\n\t\tfor (int j = 0; j < 256; ++j)\
    \ ret[i][j] = _rec(i, j);\n\t}\n\treturn ret;\n}();\nconst std::array<std::array<std::array<unsigned\
    \ long long, 256>, 8>, 8> Nimber::precalc = []() {\n\tstd::array<std::array<std::array<unsigned\
    \ long long, 256>, 8>, 8> ret;\n\tfor (int d = 0; d < 8; ++d) {\n\t\tfor (int\
    \ e = 0; e < 8; ++e) {\n\t\t\tull p = _rec(1ULL << (8 * d), 1ULL << (8 * e));\n\
    \t\t\tfor (int i = 0; i < 256; ++i) ret[d][e][i] = _rec(p, i);\n\t\t}\n\t}\n\t\
    return ret;\n}();\n"
  code: "// https://hitonanode.github.io/cplib-cpp/number/nimber.hpp\nstruct Nimber\
    \ {\n\tusing ull = unsigned long long;\n\tull v;\n\tconst static std::array<std::array<unsigned,\
    \ 256>, 256> small_table;\n\tconst static std::array<std::array<std::array<ull,\
    \ 256>, 8>, 8> precalc;\n\n\texplicit operator bool() const { return v != 0; }\n\
    \tNimber(ull val = 0) : v(val) {}\n\tNimber operator+(const Nimber &x) const {\
    \ return Nimber(v ^ x.v); }\n\tNimber operator-(const Nimber &x) const { return\
    \ Nimber(v ^ x.v); }\n\tNimber operator-() const { return *this; }\n\tNimber &operator+=(const\
    \ Nimber &x) { return *this = *this + x; }\n\tNimber &operator-=(const Nimber\
    \ &x) { return *this = *this + x; }\n\ttemplate <class IStream> friend IStream\
    \ &operator>>(IStream &is, Nimber &x) {\n\t\tull v;\n\t\treturn is >> v, x = Nimber(v),\
    \ is;\n\t}\n\ttemplate <class OStream> friend OStream &operator<<(OStream &os,\
    \ const Nimber &x) {\n\t\treturn os << x.v;\n\t}\n\tbool operator==(const Nimber\
    \ &x) const { return v == x.v; }\n\tbool operator!=(const Nimber &x) const { return\
    \ v != x.v; }\n\tbool operator<(const Nimber &x) const { return v < x.v; }\n\n\
    \tstatic ull _rec(ull x, ull y) {\n\t\tif (x == 0 or y == 0) return 0;\n\t\tif\
    \ (x < y) x ^= y, y ^= x, x ^= y; // Make x >= y\n\t\tif (y == 1) return x;\n\t\
    \tfor (int shift = 64 / 2;; shift >>= 1) {\n\t\t\tull mask = (1ULL << shift) -\
    \ 1;\n\t\t\tif (y >> shift) {\n\t\t\t\tull v00 = _rec(x & mask, y & mask);\n\t\
    \t\t\tull v01 = _rec(x & mask, y >> shift);\n\t\t\t\tull v10 = _rec(x >> shift,\
    \ y & mask);\n\t\t\t\tull v11 = _rec(x >> shift, y >> shift);\n\t\t\t\treturn\
    \ v00 ^ ((v01 ^ v10 ^ v11) << shift) ^ _rec(v11, 1ULL << (shift - 1));\n\t\t\t\
    } else if (x >> shift) {\n\t\t\t\treturn (_rec(x >> shift, y) << shift) ^ _rec(x\
    \ & mask, y);\n\t\t\t}\n\t\t}\n\t}\n\tNimber operator*(const Nimber &x) const\
    \ {\n\t\tull ret = 0;\n\t\tfor (int d = 0; d < 8; ++d) {\n\t\t\tfor (int e = 0;\
    \ e < 8; ++e) {\n\t\t\t\tret ^= precalc[d][e][small_table[(v >> (d * 8)) & 255][(x.v\
    \ >> (e * 8)) & 255]];\n\t\t\t}\n\t\t}\n\t\treturn Nimber(ret);\n\t}\n\tNimber\
    \ &operator*=(const Nimber &x) { return *this = *this * x; }\n\tNimber operator/(const\
    \ Nimber &x) const {\n\t\t// TODO x^{2^64-2}\n\t\t// faster: https://natsugiri.hatenablog.com/entry/2020/03/29/073605\n\
    \t\tassert(false);\n\t\treturn x;\n\t}\n\tNimber &operator/=(const Nimber &x)\
    \ { return *this = *this / x; }\n\t\n};\n\nconst std::array<std::array<unsigned,\
    \ 256>, 256> Nimber::small_table = []() {\n\tstd::array<std::array<unsigned, 256>,\
    \ 256> ret;\n\tfor (int i = 0; i < 256; ++i) {\n\t\tfor (int j = 0; j < 256; ++j)\
    \ ret[i][j] = _rec(i, j);\n\t}\n\treturn ret;\n}();\nconst std::array<std::array<std::array<unsigned\
    \ long long, 256>, 8>, 8> Nimber::precalc = []() {\n\tstd::array<std::array<std::array<unsigned\
    \ long long, 256>, 8>, 8> ret;\n\tfor (int d = 0; d < 8; ++d) {\n\t\tfor (int\
    \ e = 0; e < 8; ++e) {\n\t\t\tull p = _rec(1ULL << (8 * d), 1ULL << (8 * e));\n\
    \t\t\tfor (int i = 0; i < 256; ++i) ret[d][e][i] = _rec(p, i);\n\t\t}\n\t}\n\t\
    return ret;\n}();"
  dependsOn: []
  isVerificationFile: false
  path: math/nimber.cpp
  requiredBy: []
  timestamp: '2023-11-14 00:07:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/nimber.cpp
layout: document
redirect_from:
- /library/math/nimber.cpp
- /library/math/nimber.cpp.html
title: math/nimber.cpp
---
