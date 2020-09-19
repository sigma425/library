---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://official.contest.yandex.ru/opencupXIX/contest/9262/problems/K
  bundledCode: "#line 1 \"math/Q.cpp\"\n/*\r\n\t\u6709\u7406\u6570\u4F53\r\n\t\u4EFB\
    \u610F/\u6B63, gcd = 1 \u3067\u5E38\u306B\u6301\u3064\r\n\tverified at https://official.contest.yandex.ru/opencupXIX/contest/9262/problems/K\
    \ (Q\u4E0A\u3067\u9023\u7ACB\u65B9\u7A0B\u5F0F)\r\n*/\r\nint bsf(ll x) { return\
    \ __builtin_ctzll(x); } \r\nll gcd(ll a, ll b){\r\n\ta = abs(a), b = abs(b);\r\
    \n\tif(a==0) return b;\r\n\tif(b==0) return a;\r\n\tint shift = bsf(a|b);\r\n\t\
    a >>= bsf(a);\r\n\tdo{\r\n\t\tb >>= bsf(b);\r\n\t\tif(a>b) swap(a,b);\r\n\t\t\
    b -= a;\r\n\t}while(b);\r\n\treturn a<<shift;\r\n}\r\n\r\nstruct F{\r\n\tll x,y;\t\
    \t// x/y\r\n\tF():x(0),y(1){}\r\n\tF(ll x):x(x),y(1){}\r\n\tF(ll x,ll y):x(x),y(y){}\r\
    \n\r\n\tF norm(ll x,ll y) const {\r\n\t\tll g = gcd(x,y);\r\n\t\tx /= g, y /=\
    \ g;\r\n\t\tif(y<0){\r\n\t\t\tx = -x;\r\n\t\t\ty = -y;\r\n\t\t}\r\n\t\treturn\
    \ F(x,y);\r\n\t}\r\n\r\n\tF operator+(const F& r) const {\r\n\t\tll X = x * r.y\
    \ + y * r.x;\r\n\t\tll Y = y * r.y;\r\n\t\treturn norm(X,Y);\r\n\t}\r\n\tF operator-(const\
    \ F& r) const {\r\n\t\tll X = x * r.y - y * r.x;\r\n\t\tll Y = y * r.y;\r\n\t\t\
    return norm(X,Y);\r\n\t}\r\n\tF operator*(const F& r) const {\r\n\t\tll X = x\
    \ * r.x;\r\n\t\tll Y = y * r.y;\r\n\t\treturn norm(X,Y);\r\n\t}\r\n\tF operator/(const\
    \ F& r) const {\r\n\t\tll X = x * r.y;\r\n\t\tll Y = y * r.x;\r\n\t\treturn norm(X,Y);\r\
    \n\t}\r\n\tbool operator==(const F& r) const {\r\n\t\treturn x == r.x && y ==\
    \ r.y;\r\n\t}\r\n\tfriend ostream& operator<<(ostream &o,const F& x){\r\n\t\t\
    return o<<x.x<<\"/\"<<x.y;\r\n\t}\r\n};\r\n"
  code: "/*\r\n\t\u6709\u7406\u6570\u4F53\r\n\t\u4EFB\u610F/\u6B63, gcd = 1 \u3067\
    \u5E38\u306B\u6301\u3064\r\n\tverified at https://official.contest.yandex.ru/opencupXIX/contest/9262/problems/K\
    \ (Q\u4E0A\u3067\u9023\u7ACB\u65B9\u7A0B\u5F0F)\r\n*/\r\nint bsf(ll x) { return\
    \ __builtin_ctzll(x); } \r\nll gcd(ll a, ll b){\r\n\ta = abs(a), b = abs(b);\r\
    \n\tif(a==0) return b;\r\n\tif(b==0) return a;\r\n\tint shift = bsf(a|b);\r\n\t\
    a >>= bsf(a);\r\n\tdo{\r\n\t\tb >>= bsf(b);\r\n\t\tif(a>b) swap(a,b);\r\n\t\t\
    b -= a;\r\n\t}while(b);\r\n\treturn a<<shift;\r\n}\r\n\r\nstruct F{\r\n\tll x,y;\t\
    \t// x/y\r\n\tF():x(0),y(1){}\r\n\tF(ll x):x(x),y(1){}\r\n\tF(ll x,ll y):x(x),y(y){}\r\
    \n\r\n\tF norm(ll x,ll y) const {\r\n\t\tll g = gcd(x,y);\r\n\t\tx /= g, y /=\
    \ g;\r\n\t\tif(y<0){\r\n\t\t\tx = -x;\r\n\t\t\ty = -y;\r\n\t\t}\r\n\t\treturn\
    \ F(x,y);\r\n\t}\r\n\r\n\tF operator+(const F& r) const {\r\n\t\tll X = x * r.y\
    \ + y * r.x;\r\n\t\tll Y = y * r.y;\r\n\t\treturn norm(X,Y);\r\n\t}\r\n\tF operator-(const\
    \ F& r) const {\r\n\t\tll X = x * r.y - y * r.x;\r\n\t\tll Y = y * r.y;\r\n\t\t\
    return norm(X,Y);\r\n\t}\r\n\tF operator*(const F& r) const {\r\n\t\tll X = x\
    \ * r.x;\r\n\t\tll Y = y * r.y;\r\n\t\treturn norm(X,Y);\r\n\t}\r\n\tF operator/(const\
    \ F& r) const {\r\n\t\tll X = x * r.y;\r\n\t\tll Y = y * r.x;\r\n\t\treturn norm(X,Y);\r\
    \n\t}\r\n\tbool operator==(const F& r) const {\r\n\t\treturn x == r.x && y ==\
    \ r.y;\r\n\t}\r\n\tfriend ostream& operator<<(ostream &o,const F& x){\r\n\t\t\
    return o<<x.x<<\"/\"<<x.y;\r\n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/Q.cpp
  requiredBy: []
  timestamp: '2018-10-12 13:58:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Q.cpp
layout: document
redirect_from:
- /library/math/Q.cpp
- /library/math/Q.cpp.html
title: math/Q.cpp
---
