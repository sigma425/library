---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"interpolation.cpp\"\n/*\n\t\u591A\u9805\u5F0F\u88DC\u9593\
    \n\tLagrange interpolation\n\tO(N^2)\n\tN\u70B9(xs[i],ys[i])\u304C\u4E0E\u3048\
    \u3089\u308C\u305F\u6642\u306B\u305D\u308C\u3092\u901A\u308BN-1\u6B21\u591A\u9805\
    \u5F0F\u306Ex\u3067\u306E\u5024\u3092\u8FD4\u3059\n\txs[i]\u304Cpairwise distinct\u3058\
    \u3083\u306A\u3044\u3068\u30C0\u30E1\n\t\u3042\u3068xs[i]==x\u306B\u306A\u308B\
    \u3068\u304D\u306B\u3061\u3083\u3093\u3068\u51E6\u7406\u3059\u308B\u5FC5\u8981\
    \u304C\u3042\u308B double\u3068\u304B\u3067\u8AA4\u5DEE\u3067xs[i]==x+eps\u307F\
    \u305F\u3044\u306A\u306E\u306B\u6CE8\u610F\n\n\tZ/pZ\u3068\u304B\u306B\u3059\u308B\
    \u306A\u3089\u5272\u308A\u7B97\u3068\u304B\u3092\u3061\u3083\u3093\u3068\u66F8\
    \u304D\u63DB\u3048\u308B\u3053\u3068\n\n\n\t\u591A\u9805\u5F0F\u81EA\u4F53\u3092\
    \u6C42\u3081\u305F\u3044\u3068\u304D\u306F(x-xs[j])\u306E\u90E8\u5206\u304C\u591A\
    \u9805\u5F0F\u306E\u639B\u3051\u7B97\u306A\u306E\u3067\u3001\u5168\u4F53\u3067\
    O(N^3)\u306B\u306A\u308B,\n\t\u623B\u3059DP\u3063\u307D\u3044\u306E\u3092\u3084\
    \u308B\u3068O(N^2)\u3060\u304C\u9762\u5012\u305D\u3046\n\tNewton\u88DC\u9593\u4F7F\
    \u3063\u305F\u307B\u3046\u304C\u826F\u304F\u306A\u3044?\n\n\tOpenCup/1101/I.cpp\
    \ \u304Cmint,poly,interpolation\u3092\u8907\u5408\u3057\u3066\u4F7F\u3063\u3066\
    \u308B\u4F8B\n\n*/\n\ntemplate<class T>\nT interpolate(vector<T> xs,vector<T>\
    \ ys,T x){\n\tint N=xs.size();\n\trep(i,N){\n\t\tif(xs[i]==x) return ys[i];\n\t\
    }\n\tT ret=0;\n\trep(i,N){\n\t\tT a=ys[i];\n\t\trep(j,N) if(j!=i) a*=(x-xs[j])/(xs[i]-xs[j]);\n\
    \t\tret+=a;\n\t}\n\treturn ret;\n}\n\n/*\n\t\u591A\u9805\u5F0F\u81EA\u4F53\u3092\
    \u6C42\u3081\u308B O(N^3 log N)\n\tO(N^2 log N) \u3068\u304B\u306B\u3057\u305F\
    \u3044\u306A\u3089(x - x[i]) \u306E\u5DE6\u53F3\u304B\u3089\u306E\u7D2F\u7A4D\u7A4D\
    \u3092\u8A08\u7B97\u3057\u3066\u304A\u304F \u9762\u5012\u3060\u304B\u3089\u66F8\
    \u3044\u3066\u306A\u3044\u3051\u3069\n*/\nPoly<mint> interpolate(V<mint> x, V<mint>\
    \ y){\n\tassert(x.size() == y.size());\n\tint N = x.size();\n\tPoly<mint> f;\n\
    \trep(i,N){\n\t\tPoly<mint> g({y[i]});\n\t\tmint coef = 1;\n\t\trep(j,N) if(j!=i){\n\
    \t\t\tg *= Poly<mint>({-x[j],1});\n\t\t\tcoef *= (x[i]-x[j]);\n\t\t}\n\t\tg *=\
    \ coef.inv();\n\t\tf += g;\n\t}\n\treturn f;\n}\n"
  code: "/*\n\t\u591A\u9805\u5F0F\u88DC\u9593\n\tLagrange interpolation\n\tO(N^2)\n\
    \tN\u70B9(xs[i],ys[i])\u304C\u4E0E\u3048\u3089\u308C\u305F\u6642\u306B\u305D\u308C\
    \u3092\u901A\u308BN-1\u6B21\u591A\u9805\u5F0F\u306Ex\u3067\u306E\u5024\u3092\u8FD4\
    \u3059\n\txs[i]\u304Cpairwise distinct\u3058\u3083\u306A\u3044\u3068\u30C0\u30E1\
    \n\t\u3042\u3068xs[i]==x\u306B\u306A\u308B\u3068\u304D\u306B\u3061\u3083\u3093\
    \u3068\u51E6\u7406\u3059\u308B\u5FC5\u8981\u304C\u3042\u308B double\u3068\u304B\
    \u3067\u8AA4\u5DEE\u3067xs[i]==x+eps\u307F\u305F\u3044\u306A\u306E\u306B\u6CE8\
    \u610F\n\n\tZ/pZ\u3068\u304B\u306B\u3059\u308B\u306A\u3089\u5272\u308A\u7B97\u3068\
    \u304B\u3092\u3061\u3083\u3093\u3068\u66F8\u304D\u63DB\u3048\u308B\u3053\u3068\
    \n\n\n\t\u591A\u9805\u5F0F\u81EA\u4F53\u3092\u6C42\u3081\u305F\u3044\u3068\u304D\
    \u306F(x-xs[j])\u306E\u90E8\u5206\u304C\u591A\u9805\u5F0F\u306E\u639B\u3051\u7B97\
    \u306A\u306E\u3067\u3001\u5168\u4F53\u3067O(N^3)\u306B\u306A\u308B,\n\t\u623B\u3059\
    DP\u3063\u307D\u3044\u306E\u3092\u3084\u308B\u3068O(N^2)\u3060\u304C\u9762\u5012\
    \u305D\u3046\n\tNewton\u88DC\u9593\u4F7F\u3063\u305F\u307B\u3046\u304C\u826F\u304F\
    \u306A\u3044?\n\n\tOpenCup/1101/I.cpp \u304Cmint,poly,interpolation\u3092\u8907\
    \u5408\u3057\u3066\u4F7F\u3063\u3066\u308B\u4F8B\n\n*/\n\ntemplate<class T>\n\
    T interpolate(vector<T> xs,vector<T> ys,T x){\n\tint N=xs.size();\n\trep(i,N){\n\
    \t\tif(xs[i]==x) return ys[i];\n\t}\n\tT ret=0;\n\trep(i,N){\n\t\tT a=ys[i];\n\
    \t\trep(j,N) if(j!=i) a*=(x-xs[j])/(xs[i]-xs[j]);\n\t\tret+=a;\n\t}\n\treturn\
    \ ret;\n}\n\n/*\n\t\u591A\u9805\u5F0F\u81EA\u4F53\u3092\u6C42\u3081\u308B O(N^3\
    \ log N)\n\tO(N^2 log N) \u3068\u304B\u306B\u3057\u305F\u3044\u306A\u3089(x -\
    \ x[i]) \u306E\u5DE6\u53F3\u304B\u3089\u306E\u7D2F\u7A4D\u7A4D\u3092\u8A08\u7B97\
    \u3057\u3066\u304A\u304F \u9762\u5012\u3060\u304B\u3089\u66F8\u3044\u3066\u306A\
    \u3044\u3051\u3069\n*/\nPoly<mint> interpolate(V<mint> x, V<mint> y){\n\tassert(x.size()\
    \ == y.size());\n\tint N = x.size();\n\tPoly<mint> f;\n\trep(i,N){\n\t\tPoly<mint>\
    \ g({y[i]});\n\t\tmint coef = 1;\n\t\trep(j,N) if(j!=i){\n\t\t\tg *= Poly<mint>({-x[j],1});\n\
    \t\t\tcoef *= (x[i]-x[j]);\n\t\t}\n\t\tg *= coef.inv();\n\t\tf += g;\n\t}\n\t\
    return f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: interpolation.cpp
  requiredBy: []
  timestamp: '2020-11-28 05:52:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: interpolation.cpp
layout: document
redirect_from:
- /library/interpolation.cpp
- /library/interpolation.cpp.html
title: interpolation.cpp
---
