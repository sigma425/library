---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/inv.cpp\"\nvector<mint> fac,ifac,inv;\nvoid precalc(int\
    \ N){\t//[0,N]\n\tN++;\n\tfac.resize(N);\n\tifac.resize(N);\n\tinv.resize(N);\n\
    \tfac[0]=1;\n\trep1(i,N-1) fac[i] = fac[i-1] * i;\n\n\tconst int mod = 1e9+7;\n\
    \tinv[1]=1;\n\tfor(int i=2;i<=N-1;i++) inv[i] = -inv[mod%i] * (mod/i);\n\n\tifac[0]=1;\n\
    \trep1(i,N-1) ifac[i] = ifac[i-1] *inv[i];\n}\nmint Binom(int x,int y){\n\tif(y<0\
    \ || x<y) return 0;\n\treturn fac[x] * ifac[y] * ifac[x-y];\n}\n"
  code: "vector<mint> fac,ifac,inv;\nvoid precalc(int N){\t//[0,N]\n\tN++;\n\tfac.resize(N);\n\
    \tifac.resize(N);\n\tinv.resize(N);\n\tfac[0]=1;\n\trep1(i,N-1) fac[i] = fac[i-1]\
    \ * i;\n\n\tconst int mod = 1e9+7;\n\tinv[1]=1;\n\tfor(int i=2;i<=N-1;i++) inv[i]\
    \ = -inv[mod%i] * (mod/i);\n\n\tifac[0]=1;\n\trep1(i,N-1) ifac[i] = ifac[i-1]\
    \ *inv[i];\n}\nmint Binom(int x,int y){\n\tif(y<0 || x<y) return 0;\n\treturn\
    \ fac[x] * ifac[y] * ifac[x-y];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/inv.cpp
  requiredBy: []
  timestamp: '2018-10-12 14:17:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/inv.cpp
layout: document
redirect_from:
- /library/math/inv.cpp
- /library/math/inv.cpp.html
title: math/inv.cpp
---
