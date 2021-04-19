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
    - https://official.contest.yandex.ru/opencupXIX/contest/9262/problems/K
  bundledCode: "#line 1 \"math/Frac.cpp\"\n/*\r\n\t\u6709\u7406\u6570\u4F53\r\n\t\u4EFB\
    \u610F/\u6B63, gcd = 1 \u3067\u5E38\u306B\u6301\u3064\r\n\tverified at https://official.contest.yandex.ru/opencupXIX/contest/9262/problems/K\
    \ (Q\u4E0A\u3067\u9023\u7ACB\u65B9\u7A0B\u5F0F)\r\n*/\r\nint bsf(ll x) { return\
    \ __builtin_ctzll(x); } \r\nll gcd(ll a, ll b){\r\n\ta = abs(a), b = abs(b);\r\
    \n\tif(a==0) return b;\r\n\tif(b==0) return a;\r\n\tint shift = bsf(a|b);\r\n\t\
    a >>= bsf(a);\r\n\tdo{\r\n\t\tb >>= bsf(b);\r\n\t\tif(a>b) swap(a,b);\r\n\t\t\
    b -= a;\r\n\t}while(b);\r\n\treturn a<<shift;\r\n}\r\n\r\nstruct Frac{\r\n\tll\
    \ x,y;\t\t// x/y\r\n\tFrac(ll x_ = 0):x(x_),y(1){}\r\n\tFrac(ll x_,ll y_){\r\n\
    \t\tll g = gcd(x_,y_);\r\n\t\tif(y_ < 0) g = -g;\r\n\t\tx = x_ / g;\r\n\t\ty =\
    \ y_ / g;\r\n\t}\r\n\r\n\tFrac operator-() const { return {-x,y}; }\r\n\tFrac\
    \ operator+(const Frac& r) const { return {x * r.y + y * r.x, y * r.y}; }\r\n\t\
    Frac operator-(const Frac& r) const { return *this + (-r); }\r\n\tFrac operator*(const\
    \ Frac& r) const { return {x * r.x, y * r.y}; }\r\n\tFrac operator/(const Frac&\
    \ r) const { return {x * r.y, y * r.x}; }\r\n\tFrac& operator+=(const Frac& r)\
    \ { return *this = *this + r; }\r\n\tFrac& operator-=(const Frac& r) { return\
    \ *this = *this - r; }\r\n\tFrac& operator*=(const Frac& r) { return *this = *this\
    \ * r; }\r\n\tFrac& operator/=(const Frac& r) { return *this = *this / r; }\r\n\
    \tbool operator<(const Frac& r) const { return x * r.y < y * r.x; }\r\n\tbool\
    \ operator>(const Frac& r) const { return r < *this; }\r\n\tbool operator<=(const\
    \ Frac& r) const { return !(r < *this); }\r\n\tbool operator>=(const Frac& r)\
    \ const { return !(*this < r); }\r\n\tbool operator==(const Frac& r) const { return\
    \ x == r.x && y == r.y; }\r\n\tbool operator!=(const Frac& r) const { return !(*this\
    \ == r); }\r\n\tfriend ostream& operator<<(ostream &o,const Frac& x){\r\n\t\t\
    return o << x.x << \"/\" << x.y;\r\n\t}\r\n};\n"
  code: "/*\r\n\t\u6709\u7406\u6570\u4F53\r\n\t\u4EFB\u610F/\u6B63, gcd = 1 \u3067\
    \u5E38\u306B\u6301\u3064\r\n\tverified at https://official.contest.yandex.ru/opencupXIX/contest/9262/problems/K\
    \ (Q\u4E0A\u3067\u9023\u7ACB\u65B9\u7A0B\u5F0F)\r\n*/\r\nint bsf(ll x) { return\
    \ __builtin_ctzll(x); } \r\nll gcd(ll a, ll b){\r\n\ta = abs(a), b = abs(b);\r\
    \n\tif(a==0) return b;\r\n\tif(b==0) return a;\r\n\tint shift = bsf(a|b);\r\n\t\
    a >>= bsf(a);\r\n\tdo{\r\n\t\tb >>= bsf(b);\r\n\t\tif(a>b) swap(a,b);\r\n\t\t\
    b -= a;\r\n\t}while(b);\r\n\treturn a<<shift;\r\n}\r\n\r\nstruct Frac{\r\n\tll\
    \ x,y;\t\t// x/y\r\n\tFrac(ll x_ = 0):x(x_),y(1){}\r\n\tFrac(ll x_,ll y_){\r\n\
    \t\tll g = gcd(x_,y_);\r\n\t\tif(y_ < 0) g = -g;\r\n\t\tx = x_ / g;\r\n\t\ty =\
    \ y_ / g;\r\n\t}\r\n\r\n\tFrac operator-() const { return {-x,y}; }\r\n\tFrac\
    \ operator+(const Frac& r) const { return {x * r.y + y * r.x, y * r.y}; }\r\n\t\
    Frac operator-(const Frac& r) const { return *this + (-r); }\r\n\tFrac operator*(const\
    \ Frac& r) const { return {x * r.x, y * r.y}; }\r\n\tFrac operator/(const Frac&\
    \ r) const { return {x * r.y, y * r.x}; }\r\n\tFrac& operator+=(const Frac& r)\
    \ { return *this = *this + r; }\r\n\tFrac& operator-=(const Frac& r) { return\
    \ *this = *this - r; }\r\n\tFrac& operator*=(const Frac& r) { return *this = *this\
    \ * r; }\r\n\tFrac& operator/=(const Frac& r) { return *this = *this / r; }\r\n\
    \tbool operator<(const Frac& r) const { return x * r.y < y * r.x; }\r\n\tbool\
    \ operator>(const Frac& r) const { return r < *this; }\r\n\tbool operator<=(const\
    \ Frac& r) const { return !(r < *this); }\r\n\tbool operator>=(const Frac& r)\
    \ const { return !(*this < r); }\r\n\tbool operator==(const Frac& r) const { return\
    \ x == r.x && y == r.y; }\r\n\tbool operator!=(const Frac& r) const { return !(*this\
    \ == r); }\r\n\tfriend ostream& operator<<(ostream &o,const Frac& x){\r\n\t\t\
    return o << x.x << \"/\" << x.y;\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/Frac.cpp
  requiredBy: []
  timestamp: '2020-12-16 01:45:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Frac.cpp
layout: document
redirect_from:
- /library/math/Frac.cpp
- /library/math/Frac.cpp.html
title: math/Frac.cpp
---
