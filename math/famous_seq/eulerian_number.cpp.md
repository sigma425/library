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
  bundledCode: "#line 1 \"math/famous_seq/eulerian_number.cpp\"\n/*\n\tEulerian number\
    \ A(n,k)\n\t\t= 1,..,n \u306E\u9806\u5217\u3067 ascent \u304C k \u500B\u306A\u3082\
    \u306E\u306E\u500B\u6570\n\t\t= [0,1] \u4E71\u6570\u3092 n \u500B\u8DB3\u3057\u305F\
    \u3068\u304D\u306E floor \u304C k \u306A\u78BA\u7387 * n!\n\n\t\u7279\u5FB4\n\t\
    \tA(n,k) = \\sum_{i=0}^k (-1)^i * Choose(n+1,i) * (k+1-i)^n\n\t\tA(n,k) = (n-k)\
    \ * A(n-1,k-1) + (k+1) * A(n-1,k)\n\t\tStirling2 \u3068\u672C\u8CEA\u7684\u306B\
    \u540C\u3058\u3060\u3063\u305F\u306A\u3001\u305D\u3046\u3044\u3048\u3070\n\t\t\
    Worpitzky's identity: x^n \u3092 C(x+k,n) \u306E\u548C\u3067\u8868\u3059\u3068\
    \u304D\u306E\u4FC2\u6570\u306BA\u304C\u51FA\u3066\u304F\u308B\n*/\n\n/*\n\treturn\
    \ [A(n,0), .. , A(n,k)]\n\tA(n,k) = \\sum_{i=0}^k (-1)^i * Choose(n+1,i) * (k+1-i)^n\n\
    \n\tO(k logk + k logn)\n\tk \u304C\u7121\u99C4\u306B\u5927\u304D\u304F\u3066\u3082\
    \ 0 \u3092\u57CB\u3081\u3066\u8FD4\u3057\u3066\u304F\u308C\u308B\n*/\nV<mint>\
    \ eulerian_n$(int n, int k){\n\tV<mint> f(k+1); rep(i,k+1) f[i] = Choose(n+1,i)\
    \ * (i&1?-1:1);\n\tV<mint> g(k+1); rep(i,k+1) g[i] = mint(i+1).pow(n);\n\tauto\
    \ h = multiply(f,g);\n\th.resize(k+1);\n\treturn h;\n}\n\n/*\n\tA(n,k) = (n-k)\
    \ * A(n-1,k-1) + (k+1) * A(n-1,k)\n*/\nVV<mint> E;\nvoid initEulerian(int n, int\
    \ k = -1){\n\tif(k == -1) k = n;\n\tE = VV<mint>(n+1,k+1);\n\tE[0][0] = 1;\n\t\
    rep1(i,n){\n\t\trep(j,k+1) E[i][j] = (j ? (i-j) * E[i-1][j-1] : 0) + (j+1) * E[i-1][j];\n\
    \t}\n}\n"
  code: "/*\n\tEulerian number A(n,k)\n\t\t= 1,..,n \u306E\u9806\u5217\u3067 ascent\
    \ \u304C k \u500B\u306A\u3082\u306E\u306E\u500B\u6570\n\t\t= [0,1] \u4E71\u6570\
    \u3092 n \u500B\u8DB3\u3057\u305F\u3068\u304D\u306E floor \u304C k \u306A\u78BA\
    \u7387 * n!\n\n\t\u7279\u5FB4\n\t\tA(n,k) = \\sum_{i=0}^k (-1)^i * Choose(n+1,i)\
    \ * (k+1-i)^n\n\t\tA(n,k) = (n-k) * A(n-1,k-1) + (k+1) * A(n-1,k)\n\t\tStirling2\
    \ \u3068\u672C\u8CEA\u7684\u306B\u540C\u3058\u3060\u3063\u305F\u306A\u3001\u305D\
    \u3046\u3044\u3048\u3070\n\t\tWorpitzky's identity: x^n \u3092 C(x+k,n) \u306E\
    \u548C\u3067\u8868\u3059\u3068\u304D\u306E\u4FC2\u6570\u306BA\u304C\u51FA\u3066\
    \u304F\u308B\n*/\n\n/*\n\treturn [A(n,0), .. , A(n,k)]\n\tA(n,k) = \\sum_{i=0}^k\
    \ (-1)^i * Choose(n+1,i) * (k+1-i)^n\n\n\tO(k logk + k logn)\n\tk \u304C\u7121\
    \u99C4\u306B\u5927\u304D\u304F\u3066\u3082 0 \u3092\u57CB\u3081\u3066\u8FD4\u3057\
    \u3066\u304F\u308C\u308B\n*/\nV<mint> eulerian_n$(int n, int k){\n\tV<mint> f(k+1);\
    \ rep(i,k+1) f[i] = Choose(n+1,i) * (i&1?-1:1);\n\tV<mint> g(k+1); rep(i,k+1)\
    \ g[i] = mint(i+1).pow(n);\n\tauto h = multiply(f,g);\n\th.resize(k+1);\n\treturn\
    \ h;\n}\n\n/*\n\tA(n,k) = (n-k) * A(n-1,k-1) + (k+1) * A(n-1,k)\n*/\nVV<mint>\
    \ E;\nvoid initEulerian(int n, int k = -1){\n\tif(k == -1) k = n;\n\tE = VV<mint>(n+1,k+1);\n\
    \tE[0][0] = 1;\n\trep1(i,n){\n\t\trep(j,k+1) E[i][j] = (j ? (i-j) * E[i-1][j-1]\
    \ : 0) + (j+1) * E[i-1][j];\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/famous_seq/eulerian_number.cpp
  requiredBy: []
  timestamp: '2024-09-05 20:44:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/famous_seq/eulerian_number.cpp
layout: document
redirect_from:
- /library/math/famous_seq/eulerian_number.cpp
- /library/math/famous_seq/eulerian_number.cpp.html
title: math/famous_seq/eulerian_number.cpp
---
