---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_oj/enumerate_primes.test.cpp
    title: test_oj/enumerate_primes.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"math/prime.cpp\"\n\nV<bool> isp;\nV<int> pr;\nV<int> sf;\
    \ //smallest factor, sf[9*5*11] = 3\nvoid linear_sieve(int X){\t\t// <= X\n\t\
    isp = V<bool>(X+1,true); isp[0] = isp[1] = false;\n\tsf = V<int>(X+1);\n\tfor(int\
    \ i=2;i<=X;i++){\n\t\tif(isp[i]){\n\t\t\tpr.pb(i);\n\t\t\tsf[i] = i;\n\t\t}\n\t\
    \tfor(int j=0;i*pr[j]<=X;j++){\n\t\t\tisp[i*pr[j]] = false;\n\t\t\tsf[i*pr[j]]\
    \ = pr[j];\n\t\t\tif(i%pr[j] == 0) break;\n\t\t}\n\t}\n}\n"
  code: "\nV<bool> isp;\nV<int> pr;\nV<int> sf; //smallest factor, sf[9*5*11] = 3\n\
    void linear_sieve(int X){\t\t// <= X\n\tisp = V<bool>(X+1,true); isp[0] = isp[1]\
    \ = false;\n\tsf = V<int>(X+1);\n\tfor(int i=2;i<=X;i++){\n\t\tif(isp[i]){\n\t\
    \t\tpr.pb(i);\n\t\t\tsf[i] = i;\n\t\t}\n\t\tfor(int j=0;i*pr[j]<=X;j++){\n\t\t\
    \tisp[i*pr[j]] = false;\n\t\t\tsf[i*pr[j]] = pr[j];\n\t\t\tif(i%pr[j] == 0) break;\n\
    \t\t}\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/prime.cpp
  requiredBy: []
  timestamp: '2020-09-20 08:06:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_oj/enumerate_primes.test.cpp
documentation_of: math/prime.cpp
layout: document
redirect_from:
- /library/math/prime.cpp
- /library/math/prime.cpp.html
title: math/prime.cpp
---
