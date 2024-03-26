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
  bundledCode: "#line 1 \"math/famous_seq/Stirling.cpp\"\n/*\n\treturn {s(n,0), ..,\
    \ s(n,k)}\n\t\u7B26\u53F7\u306A\u3057. \u7B26\u53F7\u4ED8\u304D\u306B\u3057\u305F\
    \u304B\u3063\u305F\u3089 (-1)^{n-k} \u3092\u304B\u3051\u308B\n\tO(k log k log\
    \ n) \u305F\u3060\u3057\u3001k = n \u306E\u3068\u304D\u306F O(n log n)\n*/\nV<mint>\
    \ Stirling1_n$(int n, int k){\n\t// s(n,k) = [x^k] x(x+1)..(x+n-1)\n\tauto rec\
    \ = [&](auto&& self, int n_) -> Poly<mint> {\n\t\tif(n_ == 0){\n\t\t\treturn Poly<mint>({1});\n\
    \t\t} \n\t\tauto f = self(self,n_/2);\n\t\tf = (f * f.shift(n_/2)).low(k+1);\n\
    \t\tif(n_&1){\n\t\t\t// *= (x+n_-1)\n\t\t\tint S = si(f); f.eb(0);\n\t\t\tper(i,S){\n\
    \t\t\t\tf[i+1] += f[i];\n\t\t\t\tf[i] *= (n_-1);\n\t\t\t}\n\t\t\tif(S == k+1)\
    \ f.pop_back();\n\t\t}\n\t\treturn f;\n\t};\n\treturn rec(rec,n);\n}\n\n/*\n\t\
    initialize s([0,n],[0,k])\n\tO(nk)\n*/\nVV<mint> s1;\nvoid initStirling1(int n,\
    \ int k = -1){\n\tif(k == -1) k = n;\n\ts1.resize(n+1); rep(i,n+1) s1[i].resize(min(i+1,k+1));\n\
    \ts1[0][0] = 1;\n\trep1(i,n){\n\t\trep1(j,min(i-1,k)) s1[i][j] = s1[i-1][j-1]\
    \ + (i-1) *s1[i-1][j];\n\t\tif(i <= k) s1[i][i] = 1;\n\t}\n}\n\n/*\n\treturn {S(n,0),\
    \ .., S(n,k)}\n\tO(k log n + k log k)\n*/\nV<mint> Stirling2_n$(int n, int k){\n\
    \t// S(n,k) = 1/k! \\sum_{i=0}^k C(k,i)(-1)^{k-i} i^n\n\tV<mint> f(k+1); rep(i,k+1)\
    \ f[i] = ifact[i] * mint(i).pow(n);\n\tV<mint> g(k+1); rep(i,k+1) g[i] = (i&1\
    \ ? -ifact[i] : ifact[i]);\n\tauto S = multiply(f,g);\n\tS.resize(k+1);\n\treturn\
    \ S;\n}\n\nmint Stirling2_nk(int n, int k){\n\tmint res = 0;\n\trep(i,k+1) res\
    \ += Choose(k,i) * mint(i).pow(n) * ((k-i)&1 ? -1 : 1);\n\treturn res * ifact[k];\n\
    }\n\n/*\n\tinitialize S([0,n],[0,k])\n\tO(nk)\n*/\nVV<mint> S2;\nvoid initStirling2(int\
    \ n, int k = -1){\n\tif(k == -1) k = n;\n\tS2.resize(n+1); rep(i,n+1) S2[i].resize(min(i+1,k+1));\n\
    \tS2[0][0] = 1;\n\trep1(i,n){\n\t\trep1(j,min(i-1,k)) S2[i][j] = S2[i-1][j-1]\
    \ + j * S2[i-1][j];\n\t\tif(i <= k) S2[i][i] = 1;\n\t}\n}\n"
  code: "/*\n\treturn {s(n,0), .., s(n,k)}\n\t\u7B26\u53F7\u306A\u3057. \u7B26\u53F7\
    \u4ED8\u304D\u306B\u3057\u305F\u304B\u3063\u305F\u3089 (-1)^{n-k} \u3092\u304B\
    \u3051\u308B\n\tO(k log k log n) \u305F\u3060\u3057\u3001k = n \u306E\u3068\u304D\
    \u306F O(n log n)\n*/\nV<mint> Stirling1_n$(int n, int k){\n\t// s(n,k) = [x^k]\
    \ x(x+1)..(x+n-1)\n\tauto rec = [&](auto&& self, int n_) -> Poly<mint> {\n\t\t\
    if(n_ == 0){\n\t\t\treturn Poly<mint>({1});\n\t\t} \n\t\tauto f = self(self,n_/2);\n\
    \t\tf = (f * f.shift(n_/2)).low(k+1);\n\t\tif(n_&1){\n\t\t\t// *= (x+n_-1)\n\t\
    \t\tint S = si(f); f.eb(0);\n\t\t\tper(i,S){\n\t\t\t\tf[i+1] += f[i];\n\t\t\t\t\
    f[i] *= (n_-1);\n\t\t\t}\n\t\t\tif(S == k+1) f.pop_back();\n\t\t}\n\t\treturn\
    \ f;\n\t};\n\treturn rec(rec,n);\n}\n\n/*\n\tinitialize s([0,n],[0,k])\n\tO(nk)\n\
    */\nVV<mint> s1;\nvoid initStirling1(int n, int k = -1){\n\tif(k == -1) k = n;\n\
    \ts1.resize(n+1); rep(i,n+1) s1[i].resize(min(i+1,k+1));\n\ts1[0][0] = 1;\n\t\
    rep1(i,n){\n\t\trep1(j,min(i-1,k)) s1[i][j] = s1[i-1][j-1] + (i-1) *s1[i-1][j];\n\
    \t\tif(i <= k) s1[i][i] = 1;\n\t}\n}\n\n/*\n\treturn {S(n,0), .., S(n,k)}\n\t\
    O(k log n + k log k)\n*/\nV<mint> Stirling2_n$(int n, int k){\n\t// S(n,k) = 1/k!\
    \ \\sum_{i=0}^k C(k,i)(-1)^{k-i} i^n\n\tV<mint> f(k+1); rep(i,k+1) f[i] = ifact[i]\
    \ * mint(i).pow(n);\n\tV<mint> g(k+1); rep(i,k+1) g[i] = (i&1 ? -ifact[i] : ifact[i]);\n\
    \tauto S = multiply(f,g);\n\tS.resize(k+1);\n\treturn S;\n}\n\nmint Stirling2_nk(int\
    \ n, int k){\n\tmint res = 0;\n\trep(i,k+1) res += Choose(k,i) * mint(i).pow(n)\
    \ * ((k-i)&1 ? -1 : 1);\n\treturn res * ifact[k];\n}\n\n/*\n\tinitialize S([0,n],[0,k])\n\
    \tO(nk)\n*/\nVV<mint> S2;\nvoid initStirling2(int n, int k = -1){\n\tif(k == -1)\
    \ k = n;\n\tS2.resize(n+1); rep(i,n+1) S2[i].resize(min(i+1,k+1));\n\tS2[0][0]\
    \ = 1;\n\trep1(i,n){\n\t\trep1(j,min(i-1,k)) S2[i][j] = S2[i-1][j-1] + j * S2[i-1][j];\n\
    \t\tif(i <= k) S2[i][i] = 1;\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/famous_seq/Stirling.cpp
  requiredBy: []
  timestamp: '2024-03-26 11:07:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/famous_seq/Stirling.cpp
layout: document
redirect_from:
- /library/math/famous_seq/Stirling.cpp
- /library/math/famous_seq/Stirling.cpp.html
title: math/famous_seq/Stirling.cpp
---
