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
    - https://ac.nowcoder.com/acm/contest/11258/A
    - https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h
  bundledCode: "#line 1 \"math/subset_poly.cpp\"\n/*\n\tS\u306Esubset\u306B\u5BFE\u3057\
    \u3066\u5024\u304C\u7D10\u4ED8\u3051\u3089\u308C\u3066\u3044\u308B\u6642\u3001\
    \ f = a_00 + a_01 x_1 + a_10 x_0 + a_11 x_0 x_1 \u307F\u305F\u3044\u306A\u3082\
    \u306E\u3092\u6271\u3046\n\t\u57FA\u672C\u306F subset_convolution\n\t\t\u96C6\u5408\
    \u30922\u3064\u306B\u5206\u5272\u3057\u305F\u7A4D\u306E\u548C\n\t\tpoly \u3060\
    \u3068\u8003\u3048\u308B\u3068 mod x_i^2 \u3092\u53D6\u3063\u3066\u3044\u308B\u3053\
    \u3068\u306B\u306A\u3063\u3066\u3001\u7D50\u5C40\u6B21\u6570\u3082\u30AD\u30FC\
    \u306B\u6301\u3063\u3066zeta/mebius\u3057\u3066\u8FBB\u8904\u304C\u5408\u3046\u3068\
    \u3053\u3060\u3051\u53D6\u3063\u3066\u304F\u308C\u3070\u3088\u3044\n\t\tO(2^n\
    \ n^2)\n\t\u3088\u308A\u4E00\u822C\u306B\u3001subset poly \u540C\u58EB\u3067\u6F14\
    \u7B97\u3057\u305F\u3044\u6642\u3001\u305D\u306E\u6F14\u7B97\u3092FPS\u3060\u3068\
    \u8003\u3048\u308C\u3070FPS\u4E0A\u306E+,*\u306B\u5E30\u7740\u3067\u304D\u3001\
    zeta\u3057\u305F\u3042\u3068\u5404\u70B9\u3067\u306E\u6F14\u7B97\u306B\u5E30\u7740\
    \u3055\u308C\u308B\n\t\u4ECA\u30B5\u30A4\u30BA\u3082\u60C5\u5831\u3068\u3057\u3066\
    \u6301\u3063\u3066\u3044\u308B (y\u306E\u6B21\u6570\u3068\u3057\u3066\u6301\u3063\
    \u3066y\u306EFPS\u3068\u601D\u3046)\u306E\u3067\u3001\u7D50\u5C40\u5404\u70B9\u3067\
    \u306E\u6F14\u7B97\u306Fy\u306EFPS\u540C\u58EB\u306E\u6F14\u7B97\u306B\u306A\u308B\
    \n\n\tFPS OPERATION \u3063\u3066\u304B\u3044\u3066\u3042\u308B\u3068\u3053\u308D\
    \u3067mult,div,exp,log,sqrt,pow\u306A\u3069\u597D\u304D\u306A\u6F14\u7B97\u3092\
    O(n^2)\u3068\u304B\u3067\u3084\u308B\u3068\u3088\u3044\n\tg = e^f -> g' = f'g\
    \ -> g\u306E\u7DDA\u5F62\u6F38\u5316\u5F0F \u307F\u305F\u3044\u306A\n\n\t\u5B9F\
    \u88C5\u4E0A\u306E\u6CE8\u610F:\n\t\tVV<mint> (1<<N,N+1) \u3092\u5185\u90E8\u3067\
    \u53D6\u308B\u3068\u58CA\u308C\u308B\u306E\u3067\u30B0\u30ED\u30FC\u30D0\u30EB\
    \u306B\u304A\u3044\u3066\u3044\u308B\n\n\tverified:\n\t\thttps://ac.nowcoder.com/acm/contest/11258/A\
    \ div\n\t\thttps://atcoder.jp/contests/xmascon20/tasks/xmascon20_h\n*/\n\ntemplate<class\
    \ T, class ZT>\nvoid zeta(T& a, ZT& za){\n\tint n = __lg(si(a));\n\tassert(si(a)==(1<<n));\n\
    \n\trep(s,1<<n){\n\t\trep(i,n+1) za[s][i] = 0;\t\t// clean up\n\t\tza[s][__builtin_popcount(s)]\
    \ = a[s];\n\t}\n\trep(i,n) rep(s,1<<n) if(!(s&1<<i)){\n\t\trep(k,n+1) za[s|1<<i][k]\
    \ += za[s][k];\n\t}\n}\ntemplate<class T, class ZT>\nvoid mebius(T& a, ZT& za){\n\
    \tint n = __lg(si(a));\n\tassert(si(a)==(1<<n));\n\n\trep(i,n) rep(s,1<<n) if(!(s&1<<i)){\n\
    \t\trep(k,n+1) za[s|1<<i][k] -= za[s][k];\n\t}\n\trep(s,1<<n){\n\t\ta[s] = za[s][__builtin_popcount(s)];\n\
    \t}\n}\n\nconst int MAXN = 20;\nmint za[1<<MAXN][MAXN+1];\nmint zb[1<<MAXN][MAXN+1];\n\
    template<class T>\nV<T> subset_div(V<T> a, V<T> b){\n\tshow(a);show(b);\n\tassert(si(a)\
    \ == si(b));\n\tint s = si(a);\n\tint n = __lg(s);\n\tassert(s==(1<<n));\n\n\t\
    zeta(a,za);\n\tzeta(b,zb);\n\n\trep(s,1<<n){\n\t\tauto f = za[s], g = zb[s];\n\
    \t\t// DO FPS OPERATION HERE\n\t\t// h = f/g\n\t\tmint g0inv = mint(1)/g[0];\n\
    \t\tV<mint> h(n+1);\n\t\trep(i,n+1){\n\t\t\tmint tmp = f[i];\n\t\t\trep(j,i) tmp\
    \ -= h[j] * g[i-j];\n\t\t\th[i] = tmp * g0inv;\n\t\t}\n\t\t// UNTIL HERE\n\t\t\
    rep(i,n+1) za[s][i] = h[i];\n\t}\n\n\tmebius(a,za);\n\tshow(a);\n\treturn a;\n\
    }\n"
  code: "/*\n\tS\u306Esubset\u306B\u5BFE\u3057\u3066\u5024\u304C\u7D10\u4ED8\u3051\
    \u3089\u308C\u3066\u3044\u308B\u6642\u3001 f = a_00 + a_01 x_1 + a_10 x_0 + a_11\
    \ x_0 x_1 \u307F\u305F\u3044\u306A\u3082\u306E\u3092\u6271\u3046\n\t\u57FA\u672C\
    \u306F subset_convolution\n\t\t\u96C6\u5408\u30922\u3064\u306B\u5206\u5272\u3057\
    \u305F\u7A4D\u306E\u548C\n\t\tpoly \u3060\u3068\u8003\u3048\u308B\u3068 mod x_i^2\
    \ \u3092\u53D6\u3063\u3066\u3044\u308B\u3053\u3068\u306B\u306A\u3063\u3066\u3001\
    \u7D50\u5C40\u6B21\u6570\u3082\u30AD\u30FC\u306B\u6301\u3063\u3066zeta/mebius\u3057\
    \u3066\u8FBB\u8904\u304C\u5408\u3046\u3068\u3053\u3060\u3051\u53D6\u3063\u3066\
    \u304F\u308C\u3070\u3088\u3044\n\t\tO(2^n n^2)\n\t\u3088\u308A\u4E00\u822C\u306B\
    \u3001subset poly \u540C\u58EB\u3067\u6F14\u7B97\u3057\u305F\u3044\u6642\u3001\
    \u305D\u306E\u6F14\u7B97\u3092FPS\u3060\u3068\u8003\u3048\u308C\u3070FPS\u4E0A\
    \u306E+,*\u306B\u5E30\u7740\u3067\u304D\u3001zeta\u3057\u305F\u3042\u3068\u5404\
    \u70B9\u3067\u306E\u6F14\u7B97\u306B\u5E30\u7740\u3055\u308C\u308B\n\t\u4ECA\u30B5\
    \u30A4\u30BA\u3082\u60C5\u5831\u3068\u3057\u3066\u6301\u3063\u3066\u3044\u308B\
    \ (y\u306E\u6B21\u6570\u3068\u3057\u3066\u6301\u3063\u3066y\u306EFPS\u3068\u601D\
    \u3046)\u306E\u3067\u3001\u7D50\u5C40\u5404\u70B9\u3067\u306E\u6F14\u7B97\u306F\
    y\u306EFPS\u540C\u58EB\u306E\u6F14\u7B97\u306B\u306A\u308B\n\n\tFPS OPERATION\
    \ \u3063\u3066\u304B\u3044\u3066\u3042\u308B\u3068\u3053\u308D\u3067mult,div,exp,log,sqrt,pow\u306A\
    \u3069\u597D\u304D\u306A\u6F14\u7B97\u3092O(n^2)\u3068\u304B\u3067\u3084\u308B\
    \u3068\u3088\u3044\n\tg = e^f -> g' = f'g -> g\u306E\u7DDA\u5F62\u6F38\u5316\u5F0F\
    \ \u307F\u305F\u3044\u306A\n\n\t\u5B9F\u88C5\u4E0A\u306E\u6CE8\u610F:\n\t\tVV<mint>\
    \ (1<<N,N+1) \u3092\u5185\u90E8\u3067\u53D6\u308B\u3068\u58CA\u308C\u308B\u306E\
    \u3067\u30B0\u30ED\u30FC\u30D0\u30EB\u306B\u304A\u3044\u3066\u3044\u308B\n\n\t\
    verified:\n\t\thttps://ac.nowcoder.com/acm/contest/11258/A div\n\t\thttps://atcoder.jp/contests/xmascon20/tasks/xmascon20_h\n\
    */\n\ntemplate<class T, class ZT>\nvoid zeta(T& a, ZT& za){\n\tint n = __lg(si(a));\n\
    \tassert(si(a)==(1<<n));\n\n\trep(s,1<<n){\n\t\trep(i,n+1) za[s][i] = 0;\t\t//\
    \ clean up\n\t\tza[s][__builtin_popcount(s)] = a[s];\n\t}\n\trep(i,n) rep(s,1<<n)\
    \ if(!(s&1<<i)){\n\t\trep(k,n+1) za[s|1<<i][k] += za[s][k];\n\t}\n}\ntemplate<class\
    \ T, class ZT>\nvoid mebius(T& a, ZT& za){\n\tint n = __lg(si(a));\n\tassert(si(a)==(1<<n));\n\
    \n\trep(i,n) rep(s,1<<n) if(!(s&1<<i)){\n\t\trep(k,n+1) za[s|1<<i][k] -= za[s][k];\n\
    \t}\n\trep(s,1<<n){\n\t\ta[s] = za[s][__builtin_popcount(s)];\n\t}\n}\n\nconst\
    \ int MAXN = 20;\nmint za[1<<MAXN][MAXN+1];\nmint zb[1<<MAXN][MAXN+1];\ntemplate<class\
    \ T>\nV<T> subset_div(V<T> a, V<T> b){\n\tshow(a);show(b);\n\tassert(si(a) ==\
    \ si(b));\n\tint s = si(a);\n\tint n = __lg(s);\n\tassert(s==(1<<n));\n\n\tzeta(a,za);\n\
    \tzeta(b,zb);\n\n\trep(s,1<<n){\n\t\tauto f = za[s], g = zb[s];\n\t\t// DO FPS\
    \ OPERATION HERE\n\t\t// h = f/g\n\t\tmint g0inv = mint(1)/g[0];\n\t\tV<mint>\
    \ h(n+1);\n\t\trep(i,n+1){\n\t\t\tmint tmp = f[i];\n\t\t\trep(j,i) tmp -= h[j]\
    \ * g[i-j];\n\t\t\th[i] = tmp * g0inv;\n\t\t}\n\t\t// UNTIL HERE\n\t\trep(i,n+1)\
    \ za[s][i] = h[i];\n\t}\n\n\tmebius(a,za);\n\tshow(a);\n\treturn a;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/subset_poly.cpp
  requiredBy: []
  timestamp: '2021-08-10 05:57:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/subset_poly.cpp
layout: document
redirect_from:
- /library/math/subset_poly.cpp
- /library/math/subset_poly.cpp.html
title: math/subset_poly.cpp
---
