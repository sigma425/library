---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test_oj/enumerate_primes.test.cpp
    title: test_oj/enumerate_primes.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/prime.cpp\"\nV<bool> isp;\nV<int> pr;\nV<int> sf; //smallest\
    \ factor, sf[9*5*11] = 3\nV<int> mu;\t//[1,-1,0,0,...]\nV<int> tot;\t//[1,p-1,(p-1)p,(p-1)p^2,..]\n\
    V<int> sig;\t// [1,1+p,1+p+p^2,...]\nvoid linear_sieve(int X){\t\t// <= X\n\t\
    isp = V<bool>(X+1,true); isp[0] = isp[1] = false;\n\tsf = V<int>(X+1);\n\tpr.clear();\n\
    \tfor(int i=2;i<=X;i++){\n\t\tif(isp[i]){\n\t\t\tpr.pb(i);\n\t\t\tsf[i] = i;\n\
    \t\t}\n\t\tfor(int j=0;i*pr[j]<=X;j++){\n\t\t\tisp[i*pr[j]] = false;\n\t\t\tsf[i*pr[j]]\
    \ = pr[j];\n\t\t\tif(i%pr[j] == 0) break;\n\t\t}\n\t}\n\tmu = V<int>(X+1);\n\t\
    mu[1] = 1;\n\tfor(int i=2;i<=X;i++){\n\t\tint p = sf[i];\n\t\tif(i/p%p == 0) mu[i]\
    \ = 0;\n\t\telse mu[i] = -mu[i/p];\n\t}\n\ttot = V<int>(X+1);\n\ttot[1] = 1;\n\
    \tfor(int i=2;i<=X;i++){\n\t\tint p = sf[i];\n\t\tif(i/p%p == 0) tot[i] = tot[i/p]\
    \ * p;\n\t\telse tot[i] = tot[i/p] * (p-1);\n\t}\n\tsig = V<int>(X+1);\n\tsig[1]\
    \ = 1;\n\tfor(int i=2;i<=X;i++){\n\t\tint p = sf[i];\n\t\tint x = i;\n\t\tint\
    \ w = 1;\n\t\twhile(x%p == 0){\n\t\t\tx /= p; w = w*p+1;\n\t\t}\n\t\tsig[i] =\
    \ sig[x] * w;\n\t}\n}\n"
  code: "V<bool> isp;\nV<int> pr;\nV<int> sf; //smallest factor, sf[9*5*11] = 3\n\
    V<int> mu;\t//[1,-1,0,0,...]\nV<int> tot;\t//[1,p-1,(p-1)p,(p-1)p^2,..]\nV<int>\
    \ sig;\t// [1,1+p,1+p+p^2,...]\nvoid linear_sieve(int X){\t\t// <= X\n\tisp =\
    \ V<bool>(X+1,true); isp[0] = isp[1] = false;\n\tsf = V<int>(X+1);\n\tpr.clear();\n\
    \tfor(int i=2;i<=X;i++){\n\t\tif(isp[i]){\n\t\t\tpr.pb(i);\n\t\t\tsf[i] = i;\n\
    \t\t}\n\t\tfor(int j=0;i*pr[j]<=X;j++){\n\t\t\tisp[i*pr[j]] = false;\n\t\t\tsf[i*pr[j]]\
    \ = pr[j];\n\t\t\tif(i%pr[j] == 0) break;\n\t\t}\n\t}\n\tmu = V<int>(X+1);\n\t\
    mu[1] = 1;\n\tfor(int i=2;i<=X;i++){\n\t\tint p = sf[i];\n\t\tif(i/p%p == 0) mu[i]\
    \ = 0;\n\t\telse mu[i] = -mu[i/p];\n\t}\n\ttot = V<int>(X+1);\n\ttot[1] = 1;\n\
    \tfor(int i=2;i<=X;i++){\n\t\tint p = sf[i];\n\t\tif(i/p%p == 0) tot[i] = tot[i/p]\
    \ * p;\n\t\telse tot[i] = tot[i/p] * (p-1);\n\t}\n\tsig = V<int>(X+1);\n\tsig[1]\
    \ = 1;\n\tfor(int i=2;i<=X;i++){\n\t\tint p = sf[i];\n\t\tint x = i;\n\t\tint\
    \ w = 1;\n\t\twhile(x%p == 0){\n\t\t\tx /= p; w = w*p+1;\n\t\t}\n\t\tsig[i] =\
    \ sig[x] * w;\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime.cpp
  requiredBy: []
  timestamp: '2023-11-14 00:04:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_oj/enumerate_primes.test.cpp
documentation_of: math/prime.cpp
layout: document
redirect_from:
- /library/math/prime.cpp
- /library/math/prime.cpp.html
title: math/prime.cpp
---
