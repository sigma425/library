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
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2387
  bundledCode: "#line 1 \"math/SumFloor.cpp\"\n/*\n\treturn sum_{ i \\in [0,n) } floor((a*i+b)/m)\n\
    \n\tO(log(m))\n\t\u8A08\u7B97\u9014\u4E2D\u3067 max(a,b,m,n)^3 \u304F\u3089\u3044\
    \u306E\u5927\u304D\u3055\u306B\u306F\u306A\u308B\u306E\u3067\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u306B\u6CE8\u610F\n\t\u6E21\u3059\u5024\u306F long long\n\
    \t\u8FD4\u308A\u5024\u306E\u578B\u3092 template \u306B\u3057\u3066\u3044\u3066\
    \u3001\n\t\t- \u5927\u4E08\u592B\u306A\u6642\u306F\u666E\u901A\u306B ll / __int128\n\
    \t\t- \u554F\u984C\u306B\u3088\u3063\u3066\u306F mint\n\t\t- \u9014\u4E2D\u3067\
    \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3059\u308B\u304B\u3082\u3060\u3051\
    \u3069\u6700\u7D42\u7684\u306B\u306Fll, \u307F\u305F\u3044\u306A\u30B1\u30FC\u30B9\
    \u3067\u306F ull \u3092\u6307\u5B9A\u3059\u308B\u3068\u5B89\u5168\n\n\tverify:\n\
    \t\thttps://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2387\n*/\n\ntemplate<class\
    \ D>\nD sumFloor(ll a, ll b, ll m, ll n){\n\tassert(m > 0);\n\tassert(n >= 0);\n\
    \tassert(a >= 0);\t\t\t// \u30B5\u30DC\u308A\n\t// assert(b >= 0);\t\t// OK!\n\
    \n\tif(n == 0) return 0;\n\n\tD res = 0;\n\t{\t// a %= m\n\t\tll p = a/m;\n\t\t\
    if(n%2 == 0) res += D(n/2) * (n-1) * p;\t\t\t// big!!\n\t\telse res += D((n-1)/2)\
    \ * n * p;\n\t\ta %= m;\n\t}\n\t{\t// b %= m;\n\t\tll p = divFloor(b,m);\n\t\t\
    res += D(n) * p;\n\t\tb -= p*m;\n\t}\n\tif(a == 0) return res;\n\tll top = (__int128(a)*(n-1)+b)/m;\t\
    \t\t// overflow?\n\tres += D(top) * n;\n\tll h = (b+m)/m;\n\tif(h <= top) res\
    \ -= sumFloor<D>(m,m*h-(b+1),a,top-h+1) + top-h+1;\n\treturn res;\n}\n\n// i \\\
    in [l,r)\ntemplate<class D>\nD sumFloor(ll a, ll b, ll m, ll l, ll r){\n\treturn\
    \ sumFloor<D>(a,b,m,r) - sumFloor<D>(a,b,m,l);\n}\n"
  code: "/*\n\treturn sum_{ i \\in [0,n) } floor((a*i+b)/m)\n\n\tO(log(m))\n\t\u8A08\
    \u7B97\u9014\u4E2D\u3067 max(a,b,m,n)^3 \u304F\u3089\u3044\u306E\u5927\u304D\u3055\
    \u306B\u306F\u306A\u308B\u306E\u3067\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\
    \u306B\u6CE8\u610F\n\t\u6E21\u3059\u5024\u306F long long\n\t\u8FD4\u308A\u5024\
    \u306E\u578B\u3092 template \u306B\u3057\u3066\u3044\u3066\u3001\n\t\t- \u5927\
    \u4E08\u592B\u306A\u6642\u306F\u666E\u901A\u306B ll / __int128\n\t\t- \u554F\u984C\
    \u306B\u3088\u3063\u3066\u306F mint\n\t\t- \u9014\u4E2D\u3067\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u3059\u308B\u304B\u3082\u3060\u3051\u3069\u6700\u7D42\
    \u7684\u306B\u306Fll, \u307F\u305F\u3044\u306A\u30B1\u30FC\u30B9\u3067\u306F ull\
    \ \u3092\u6307\u5B9A\u3059\u308B\u3068\u5B89\u5168\n\n\tverify:\n\t\thttps://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2387\n\
    */\n\ntemplate<class D>\nD sumFloor(ll a, ll b, ll m, ll n){\n\tassert(m > 0);\n\
    \tassert(n >= 0);\n\tassert(a >= 0);\t\t\t// \u30B5\u30DC\u308A\n\t// assert(b\
    \ >= 0);\t\t// OK!\n\n\tif(n == 0) return 0;\n\n\tD res = 0;\n\t{\t// a %= m\n\
    \t\tll p = a/m;\n\t\tif(n%2 == 0) res += D(n/2) * (n-1) * p;\t\t\t// big!!\n\t\
    \telse res += D((n-1)/2) * n * p;\n\t\ta %= m;\n\t}\n\t{\t// b %= m;\n\t\tll p\
    \ = divFloor(b,m);\n\t\tres += D(n) * p;\n\t\tb -= p*m;\n\t}\n\tif(a == 0) return\
    \ res;\n\tll top = (__int128(a)*(n-1)+b)/m;\t\t\t// overflow?\n\tres += D(top)\
    \ * n;\n\tll h = (b+m)/m;\n\tif(h <= top) res -= sumFloor<D>(m,m*h-(b+1),a,top-h+1)\
    \ + top-h+1;\n\treturn res;\n}\n\n// i \\in [l,r)\ntemplate<class D>\nD sumFloor(ll\
    \ a, ll b, ll m, ll l, ll r){\n\treturn sumFloor<D>(a,b,m,r) - sumFloor<D>(a,b,m,l);\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/SumFloor.cpp
  requiredBy: []
  timestamp: '2021-10-10 08:47:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/SumFloor.cpp
layout: document
redirect_from:
- /library/math/SumFloor.cpp
- /library/math/SumFloor.cpp.html
title: math/SumFloor.cpp
---
