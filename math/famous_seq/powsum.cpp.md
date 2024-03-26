---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/famous_seq/powsum.cpp\"\n/*\n\t\u30D5\u30A1\u30A6\u30EB\
    \u30CF\u30FC\u30D0\u30FC / Faulhaber\n\tres[0<=k<=n] = \\sum_{0<=i<=a} i^k\n\t\
    O(n log n)\n\t\u7B2C\u4E00\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u306E S(n,[n-a,n])\
    \ \u3092\u6C42\u3081\u308B\u306E\u306B\u3082\u4F7F\u3048\u308B\n*/\nV<mint> powsum(ll\
    \ a, int n){\n\tPoly<mint> f(n+1),g(n+1);\n\t{\n\t\tmint p = 1;\n\t\trep1(i,n+1){\n\
    \t\t\tp *= a+1;\n\t\t\tf[i-1] = ifact[i] * p;\n\t\t\tg[i-1] = ifact[i];\n\t\t\
    }\n\t}\n\tauto h = (f * g.inv(n+1)).low(n+1);\n\trep(i,n+1) h[i] *= fact[i];\n\
    \treturn h;\n}\n"
  code: "/*\n\t\u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC / Faulhaber\n\tres[0<=k<=n]\
    \ = \\sum_{0<=i<=a} i^k\n\tO(n log n)\n\t\u7B2C\u4E00\u7A2E\u30B9\u30BF\u30FC\u30EA\
    \u30F3\u30B0\u306E S(n,[n-a,n]) \u3092\u6C42\u3081\u308B\u306E\u306B\u3082\u4F7F\
    \u3048\u308B\n*/\nV<mint> powsum(ll a, int n){\n\tPoly<mint> f(n+1),g(n+1);\n\t\
    {\n\t\tmint p = 1;\n\t\trep1(i,n+1){\n\t\t\tp *= a+1;\n\t\t\tf[i-1] = ifact[i]\
    \ * p;\n\t\t\tg[i-1] = ifact[i];\n\t\t}\n\t}\n\tauto h = (f * g.inv(n+1)).low(n+1);\n\
    \trep(i,n+1) h[i] *= fact[i];\n\treturn h;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/famous_seq/powsum.cpp
  requiredBy: []
  timestamp: '2024-03-26 11:07:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/famous_seq/powsum.cpp
layout: document
redirect_from:
- /library/math/famous_seq/powsum.cpp
- /library/math/famous_seq/powsum.cpp.html
title: math/famous_seq/powsum.cpp
---
