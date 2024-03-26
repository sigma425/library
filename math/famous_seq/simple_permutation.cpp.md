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
    - https://oeis.org/A059372
    - https://oeis.org/A111111
    - https://official.contest.yandex.com/ptz-mirror/contest/42061/problems/M
  bundledCode: "#line 1 \"math/famous_seq/simple_permutation.cpp\"\n/*\n\tsimple permutation\n\
    \thttps://oeis.org/A111111\n\tperm tree \u306E\u6DF1\u30551\u306E\u9802\u70B9\u305F\
    \u3061\u3092\u8003\u3048\u308B\u3068\u3001\n\t\ti) sz >= 3 \u3067\u3001\u5916\u5074\
    \u304Csimple perm \u4E2D\u306F\u306A\u3093\u3067\u3082\n\t\t\tex. [4][89][312][567]\n\
    \tii) sz = 2 \u3067\u3001(unique\u306B\u3059\u308B\u305F\u3081)\u5DE6\u5074\u306F\
    indecomposable \n\t\t\tex. [4213][65978] 65\u306E\u5F8C\u3067\u3082\u304D\u308C\
    \u308B\u304C\u3001\u3053\u306E\u3088\u3046\u306A\u5DE6\u7AEF\u3067\u306E\u5206\
    \u89E3\n\t\u3068\u3044\u3046\u308F\u3051\u3067\u9577\u30552\u306F\u7279\u6B8A\
    (\u3042\u3068s_3 = 0)\u306A\u306E\u3067\n\ts := 2x^4 + 6x^5 + .. (simple perm)\n\
    \tp := x + 2x^2 + 6x^3 + .. (perm)\n\ti := (indecomposable)\n\ti+ip = p, p = x\
    \ + 2ip + s(p) \u3088\u308A\n\ts(p) = p(1-p)/(1+p) - x\n\t-s(p) + p(1-p)/(1+p)\
    \ = x\n\tp\u306E\u5408\u6210\u9006\u304B\u3089s\u306F\u6C42\u307E\u308B\n\t\u5408\
    \u6210\u9006\u306F\u4E00\u822C\u306B\u306FO(N^2), \u3042\u308B\u3044\u306F\u4E00\
    \u4FC2\u6570\u3060\u3051\u306A\u3089\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u3067\
    O(NlogN)\u3060\u304C\u30FB\u30FB\u30FB\n\n\tf = x + 2x^2 + 6x^3 + .. , g(f) =\
    \ x \u3068\u3059\u308B\n\tf(g(x)) = x \u3092\u5FAE\u5206\u3057\u3066 f'(g(x))\
    \ g'(x) = 1 \u3053\u308C\u306B\n\tf' = (1-x)f/x^2 - 1/x \u3092\u4F7F\u3046\u3068\
    \u3001\n\t(x - (1+x)g)g' = g^2 \u3092\u5F97\u308B\n\t\t(g1+g2\tg2+g3\tg3+g4\t\t\
    g4+g5)\n\t*\t(1g1\t2g2\t\t3g3\t\t\t4g4)\n\t=\t-(g1^2\t2g1g2\t2g1g3+g2^2\t2g1g4+2g2g3)\n\
    \t\ti (>=0) \u9805\u76EE\u3092\u898B\u308C\u3070 g_{i+2} \u304C\u308F\u304B\u308B\
    \n\tonline_conv\u3067\u3084\u308B\n\n\tverify: https://official.contest.yandex.com/ptz-mirror/contest/42061/problems/M\n\
    */\n\n// x + 2x^2 + 6x^3 + .. \u306E\u5408\u6210\u9006\n// https://oeis.org/A059372\n\
    V<mint> composite_inv_of_factorial(int N){\n\tV<mint> g(N+1); g[1] = 1;\n\tOnline_Convolution<mint>\
    \ X;\t// X := g/x * g/x\n\tOnline_Division<mint> Y;\t// Y := -X / g'\n\trep(i,N-1){\n\
    \t\tmint X_i = X.query(i,g[i+1],g[i+1]);\n\t\tmint Y_i = Y.query(i,-X_i,g[i+1]*(i+1));\n\
    \t\tg[i+2] = Y_i - g[i+1];\n\n\t}\n\treturn g;\n}\n\n// https://oeis.org/A111111\n\
    // s[1] = s[2] = 0 \u3068\u3057\u3066\u3044\u308B\n// \u5B9A\u7FA9\u3067\u306F\
    \ s[1] = 1, s[2] = 2 \u3067\u3001\u305D\u3046\u3057\u305F\u3051\u308C\u3070 for(int\
    \ i=1;..) \u306B\u3059\u308B\nV<mint> simple_permutation(int N){\n\tauto g = composite_inv_of_factorial(N);\n\
    \tV<mint> s(N+1); // s = x(1-x)/(1+x) - g\n\tfor(int i=4;i<=N;i++){\n\t\tif(i\
    \ == 1) s[i] = 1;\n\t\telse if(i == 2) s[i] = 2;\n\t\telse s[i] = (i%2 == 0 ?\
    \ -2 : 2) - g[i];\n\t}\n\treturn s;\n}\n\n// x + 2x^2 + 6x^3 + .. + m!x^m \u306E\
    \u5408\u6210\u9006 (m >= 1)\n// ( x-(1+x)g + (m+1)!g^{m+1} ) g' = g^2\nV<mint>\
    \ composite_inv_of_partial_factorial(int N, int m){\n\tV<mint> g(N+1); g[1] =\
    \ 1;\n\tOnline_Convolution<mint> X;\t// X := g/x * g/x\n\tOnline_Division<mint>\
    \ Y;\t// Y := -X / g'\n\tOnline_Pow<mint> Z(m+1);\t// Z := (g/x)^{m+1}\n\trep(i,N-1){\n\
    \t\tmint X_i = X.query(i,g[i+1],g[i+1]);\n\t\tmint Y_i = Y.query(i,-X_i,g[i+1]*(i+1));\n\
    \t\tg[i+2] = Y_i - g[i+1] + (i>=m-1 ? Z.query(i-m+1,g[i-m+2])*fact[m+1] : 0);\n\
    \t}\n\treturn g;\n}\n"
  code: "/*\n\tsimple permutation\n\thttps://oeis.org/A111111\n\tperm tree \u306E\u6DF1\
    \u30551\u306E\u9802\u70B9\u305F\u3061\u3092\u8003\u3048\u308B\u3068\u3001\n\t\t\
    i) sz >= 3 \u3067\u3001\u5916\u5074\u304Csimple perm \u4E2D\u306F\u306A\u3093\u3067\
    \u3082\n\t\t\tex. [4][89][312][567]\n\tii) sz = 2 \u3067\u3001(unique\u306B\u3059\
    \u308B\u305F\u3081)\u5DE6\u5074\u306Findecomposable \n\t\t\tex. [4213][65978]\
    \ 65\u306E\u5F8C\u3067\u3082\u304D\u308C\u308B\u304C\u3001\u3053\u306E\u3088\u3046\
    \u306A\u5DE6\u7AEF\u3067\u306E\u5206\u89E3\n\t\u3068\u3044\u3046\u308F\u3051\u3067\
    \u9577\u30552\u306F\u7279\u6B8A(\u3042\u3068s_3 = 0)\u306A\u306E\u3067\n\ts :=\
    \ 2x^4 + 6x^5 + .. (simple perm)\n\tp := x + 2x^2 + 6x^3 + .. (perm)\n\ti := (indecomposable)\n\
    \ti+ip = p, p = x + 2ip + s(p) \u3088\u308A\n\ts(p) = p(1-p)/(1+p) - x\n\t-s(p)\
    \ + p(1-p)/(1+p) = x\n\tp\u306E\u5408\u6210\u9006\u304B\u3089s\u306F\u6C42\u307E\
    \u308B\n\t\u5408\u6210\u9006\u306F\u4E00\u822C\u306B\u306FO(N^2), \u3042\u308B\
    \u3044\u306F\u4E00\u4FC2\u6570\u3060\u3051\u306A\u3089\u30E9\u30B0\u30E9\u30F3\
    \u30B8\u30E5\u3067O(NlogN)\u3060\u304C\u30FB\u30FB\u30FB\n\n\tf = x + 2x^2 + 6x^3\
    \ + .. , g(f) = x \u3068\u3059\u308B\n\tf(g(x)) = x \u3092\u5FAE\u5206\u3057\u3066\
    \ f'(g(x)) g'(x) = 1 \u3053\u308C\u306B\n\tf' = (1-x)f/x^2 - 1/x \u3092\u4F7F\u3046\
    \u3068\u3001\n\t(x - (1+x)g)g' = g^2 \u3092\u5F97\u308B\n\t\t(g1+g2\tg2+g3\tg3+g4\t\
    \tg4+g5)\n\t*\t(1g1\t2g2\t\t3g3\t\t\t4g4)\n\t=\t-(g1^2\t2g1g2\t2g1g3+g2^2\t2g1g4+2g2g3)\n\
    \t\ti (>=0) \u9805\u76EE\u3092\u898B\u308C\u3070 g_{i+2} \u304C\u308F\u304B\u308B\
    \n\tonline_conv\u3067\u3084\u308B\n\n\tverify: https://official.contest.yandex.com/ptz-mirror/contest/42061/problems/M\n\
    */\n\n// x + 2x^2 + 6x^3 + .. \u306E\u5408\u6210\u9006\n// https://oeis.org/A059372\n\
    V<mint> composite_inv_of_factorial(int N){\n\tV<mint> g(N+1); g[1] = 1;\n\tOnline_Convolution<mint>\
    \ X;\t// X := g/x * g/x\n\tOnline_Division<mint> Y;\t// Y := -X / g'\n\trep(i,N-1){\n\
    \t\tmint X_i = X.query(i,g[i+1],g[i+1]);\n\t\tmint Y_i = Y.query(i,-X_i,g[i+1]*(i+1));\n\
    \t\tg[i+2] = Y_i - g[i+1];\n\n\t}\n\treturn g;\n}\n\n// https://oeis.org/A111111\n\
    // s[1] = s[2] = 0 \u3068\u3057\u3066\u3044\u308B\n// \u5B9A\u7FA9\u3067\u306F\
    \ s[1] = 1, s[2] = 2 \u3067\u3001\u305D\u3046\u3057\u305F\u3051\u308C\u3070 for(int\
    \ i=1;..) \u306B\u3059\u308B\nV<mint> simple_permutation(int N){\n\tauto g = composite_inv_of_factorial(N);\n\
    \tV<mint> s(N+1); // s = x(1-x)/(1+x) - g\n\tfor(int i=4;i<=N;i++){\n\t\tif(i\
    \ == 1) s[i] = 1;\n\t\telse if(i == 2) s[i] = 2;\n\t\telse s[i] = (i%2 == 0 ?\
    \ -2 : 2) - g[i];\n\t}\n\treturn s;\n}\n\n// x + 2x^2 + 6x^3 + .. + m!x^m \u306E\
    \u5408\u6210\u9006 (m >= 1)\n// ( x-(1+x)g + (m+1)!g^{m+1} ) g' = g^2\nV<mint>\
    \ composite_inv_of_partial_factorial(int N, int m){\n\tV<mint> g(N+1); g[1] =\
    \ 1;\n\tOnline_Convolution<mint> X;\t// X := g/x * g/x\n\tOnline_Division<mint>\
    \ Y;\t// Y := -X / g'\n\tOnline_Pow<mint> Z(m+1);\t// Z := (g/x)^{m+1}\n\trep(i,N-1){\n\
    \t\tmint X_i = X.query(i,g[i+1],g[i+1]);\n\t\tmint Y_i = Y.query(i,-X_i,g[i+1]*(i+1));\n\
    \t\tg[i+2] = Y_i - g[i+1] + (i>=m-1 ? Z.query(i-m+1,g[i-m+2])*fact[m+1] : 0);\n\
    \t}\n\treturn g;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/famous_seq/simple_permutation.cpp
  requiredBy: []
  timestamp: '2024-03-26 11:07:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/famous_seq/simple_permutation.cpp
layout: document
redirect_from:
- /library/math/famous_seq/simple_permutation.cpp
- /library/math/famous_seq/simple_permutation.cpp.html
title: math/famous_seq/simple_permutation.cpp
---
