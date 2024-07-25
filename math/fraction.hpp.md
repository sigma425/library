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
    - https://official.contest.yandex.ru/opencupXIX/contest/9262/problems/K
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/fraction.hpp: line 9: #pragma once found in a non-first line\n"
  code: "/*\r\n\t\u6709\u7406\u6570\u4F53\r\n\t\u4EFB\u610F/\u6B63, gcd = 1 \u3067\
    \u5E38\u306B\u6301\u3064\r\n\tverified at https://official.contest.yandex.ru/opencupXIX/contest/9262/problems/K\
    \ (Q\u4E0A\u3067\u9023\u7ACB\u65B9\u7A0B\u5F0F)\r\n\r\n\tusing F = Frac<ll>;\r\
    \n*/\r\n\r\n#pragma once\r\n#include <ostream>\r\n\r\ntemplate<class Int>\r\n\
    struct Frac{\r\n\tInt x,y;\t\t// x/y\r\n\tFrac(Int x_ = 0):x(x_),y(1){}\r\n\t\
    Frac(Int x_,Int y_){\r\n\t\tInt g = __gcd((x_>=0?x_:-x_),(y_>=0?y_:-y_));\t//\
    \ int128\u3060\u3068gcd,abs\u3068\u304B\u304C\u4F7F\u3048\u306A\u3044\u306E\u3067\
    \r\n\t\tif(y_ < 0) g = -g;\r\n\t\tx = x_ / g;\r\n\t\ty = y_ / g;\r\n\t}\r\n\r\n\
    \tFrac operator-() const { return {-x,y}; }\r\n\tFrac operator+(const Frac& r)\
    \ const { return {x * r.y + y * r.x, y * r.y}; }\r\n\tFrac operator-(const Frac&\
    \ r) const { return *this + (-r); }\r\n\tFrac operator*(const Frac& r) const {\
    \ return {x * r.x, y * r.y}; }\r\n\tFrac operator/(const Frac& r) const { return\
    \ {x * r.y, y * r.x}; }\r\n\tFrac& operator+=(const Frac& r) { return *this =\
    \ *this + r; }\r\n\tFrac& operator-=(const Frac& r) { return *this = *this - r;\
    \ }\r\n\tFrac& operator*=(const Frac& r) { return *this = *this * r; }\r\n\tFrac&\
    \ operator/=(const Frac& r) { return *this = *this / r; }\r\n\ttemplate<class\
    \ T> friend Frac operator+(T a, const Frac& b){ return (Frac(a) += b);}\r\n\t\
    template<class T> friend Frac operator-(T a, const Frac& b){ return (Frac(a) -=\
    \ b);}\r\n\ttemplate<class T> friend Frac operator*(T a, const Frac& b){ return\
    \ (Frac(a) *= b);}\r\n\ttemplate<class T> friend Frac operator/(T a, const Frac&\
    \ b){ return (Frac(a) /= b);}\r\n\tbool operator<(const Frac& r) const { return\
    \ x * r.y < y * r.x; }\r\n\tbool operator>(const Frac& r) const { return r < *this;\
    \ }\r\n\tbool operator<=(const Frac& r) const { return !(r < *this); }\r\n\tbool\
    \ operator>=(const Frac& r) const { return !(*this < r); }\r\n\tbool operator==(const\
    \ Frac& r) const { return x == r.x && y == r.y; }\r\n\tbool operator!=(const Frac&\
    \ r) const { return !(*this == r); }\r\n\texplicit operator bool() const {return\
    \ x!=0;}\r\n\tFrac inv() const {\r\n\t\treturn Frac(y,x);\r\n\t}\r\n\tfriend std::ostream&\
    \ operator<<(std::ostream &o,const Frac& x){\r\n\t\treturn o << x.x << \"/\" <<\
    \ x.y;\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/fraction.hpp
  requiredBy: []
  timestamp: '2024-07-25 10:57:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fraction.hpp
layout: document
redirect_from:
- /library/math/fraction.hpp
- /library/math/fraction.hpp.html
title: math/fraction.hpp
---
