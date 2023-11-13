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
  bundledCode: "#line 1 \"math/berlekamp-massey.cpp\"\n/*\n\tlinear_reccurence\n\t\
    Berlekamp-Massey\n\t\u4F53K\u4E0A\u306En+1\u9805\u9593\u7DDA\u5F62\u6F38\u5316\
    \u5F0F\u304B\u3089\u751F\u6210\u3055\u308C\u308B\u6570\u5217\u306E,\u306F\u3058\
    \u30812n\u9805\u3092\u6E21\u3059\u3068,\u305D\u306E\u7DDA\u5F62\u6F38\u5316\u5F0F\
    (\u3068\u3044\u3046\u304B\u6700\u5C0F\u591A\u9805\u5F0F)\u3092\u6C42\u3081\u3066\
    \u304F\u308C\u308B\n\t\u4F8B\u3048\u3070fib\u306A\u30894\u9805\u5FC5\u8981.\n\t\
    input \u3092 u , N\u9805 \u3068\u3057\u3066 output \u3092 c \u3068\u3059\u308B\
    \u3068\n\tfor all j < N-K,\n\tc_0 * u_j + c_1 * u_{j+1} + .. + c_K * u_{j+K} =\
    \ 0\n\t\u3068\u306A\u308B.\n\tO(n^2)\n\n\tK\u9805\u76EE\u3092\u6C42\u3081\u305F\
    \u304B\u3063\u305F\u3089 x^K \u3092\u6700\u5C0F\u591A\u9805\u5F0F\u3067\u5272\u308B\
    \u307F\u305F\u3044\u306A\u306E\u304C\u3044\u308B\n\tpoly\u30E9\u30A4\u30D6\u30E9\
    \u30EA\u306B\u3042\u308B: linearReccurenceAt\n*/\n\ntemplate<class D>\nvector<D>\
    \ linearReccurence(const vector<D> &u){\n\tint N = u.size();\n\tvector<D> b =\
    \ {D(-1)}, c = {D(-1)};\n\tD y = D(1);\n\trep1(n,N){\n\t\tint L = c.size(), M\
    \ = b.size();\n\t\tD x = 0; rep(i,L) x += c[i] * u[n-L+i];\n\t\tb.pb(0);\n\t\t\
    M++;\n\t\tif(!x) continue;\n\t\tD coef = x/y;\n\t\tif(L<M){\n\t\t\tauto tmp =\
    \ c;\n\t\t\tc.insert(begin(c),M-L,D(0));\n\t\t\trep(i,M) c[M-1-i] -= coef*b[M-1-i];\n\
    \t\t\tb=tmp;\n\t\t\ty=x;\n\t\t}else{\n\t\t\trep(i,M) c[L-1-i] -= coef*b[M-1-i];\n\
    \t\t}\n\t}\n\treturn c;\n}\n"
  code: "/*\n\tlinear_reccurence\n\tBerlekamp-Massey\n\t\u4F53K\u4E0A\u306En+1\u9805\
    \u9593\u7DDA\u5F62\u6F38\u5316\u5F0F\u304B\u3089\u751F\u6210\u3055\u308C\u308B\
    \u6570\u5217\u306E,\u306F\u3058\u30812n\u9805\u3092\u6E21\u3059\u3068,\u305D\u306E\
    \u7DDA\u5F62\u6F38\u5316\u5F0F(\u3068\u3044\u3046\u304B\u6700\u5C0F\u591A\u9805\
    \u5F0F)\u3092\u6C42\u3081\u3066\u304F\u308C\u308B\n\t\u4F8B\u3048\u3070fib\u306A\
    \u30894\u9805\u5FC5\u8981.\n\tinput \u3092 u , N\u9805 \u3068\u3057\u3066 output\
    \ \u3092 c \u3068\u3059\u308B\u3068\n\tfor all j < N-K,\n\tc_0 * u_j + c_1 * u_{j+1}\
    \ + .. + c_K * u_{j+K} = 0\n\t\u3068\u306A\u308B.\n\tO(n^2)\n\n\tK\u9805\u76EE\
    \u3092\u6C42\u3081\u305F\u304B\u3063\u305F\u3089 x^K \u3092\u6700\u5C0F\u591A\u9805\
    \u5F0F\u3067\u5272\u308B\u307F\u305F\u3044\u306A\u306E\u304C\u3044\u308B\n\tpoly\u30E9\
    \u30A4\u30D6\u30E9\u30EA\u306B\u3042\u308B: linearReccurenceAt\n*/\n\ntemplate<class\
    \ D>\nvector<D> linearReccurence(const vector<D> &u){\n\tint N = u.size();\n\t\
    vector<D> b = {D(-1)}, c = {D(-1)};\n\tD y = D(1);\n\trep1(n,N){\n\t\tint L =\
    \ c.size(), M = b.size();\n\t\tD x = 0; rep(i,L) x += c[i] * u[n-L+i];\n\t\tb.pb(0);\n\
    \t\tM++;\n\t\tif(!x) continue;\n\t\tD coef = x/y;\n\t\tif(L<M){\n\t\t\tauto tmp\
    \ = c;\n\t\t\tc.insert(begin(c),M-L,D(0));\n\t\t\trep(i,M) c[M-1-i] -= coef*b[M-1-i];\n\
    \t\t\tb=tmp;\n\t\t\ty=x;\n\t\t}else{\n\t\t\trep(i,M) c[L-1-i] -= coef*b[M-1-i];\n\
    \t\t}\n\t}\n\treturn c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/berlekamp-massey.cpp
  requiredBy: []
  timestamp: '2023-11-14 00:01:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/berlekamp-massey.cpp
layout: document
redirect_from:
- /library/math/berlekamp-massey.cpp
- /library/math/berlekamp-massey.cpp.html
title: math/berlekamp-massey.cpp
---
