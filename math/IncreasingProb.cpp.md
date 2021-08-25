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
    - https://atcoder.jp/contests/arc113/submissions/25330348
  bundledCode: "#line 1 \"math/IncreasingProb.cpp\"\n/*\n\tx_i \\in [l_i,r_i] \u3092\
    \ random \u306B\u53D6\u3063\u3066\u304D\u305F\u3068\u304D\u306B x_0 < x_1 < ..\
    \ < x_{N-1} \u3068\u306A\u308B\u78BA\u7387\u3092\u6C42\u3081\u308B\n\tinput:\n\
    \t\tmint(l_i) \u3068\u304B\u3060\u3051\u898B\u3066\u3082\u9806\u5E8F\u304C\u308F\
    \u304B\u3089\u306A\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u306E\u3067\u3001\
    \n\t\tval[N][2]: mint\u3067\u306E\u5024\n\t\torder_[N][2]: \u5B9F\u969B\u306E\u9806\
    \u5E8F\u304C\u5165\u3063\u305F\u306A\u306B\u304B\u3001\u5148\u306B\u5EA7\u5727\
    \u3057\u305F\u3082\u306E\u3092\u6E21\u3057\u3066\u3082\u3044\u3044\u3057double\u3068\
    \u304BFrac\u3068\u304B\u3067\u6E21\u3057\u3066\u3082\u3044\u3044\n\n\t\u3042\u3068\
    \ l_i = r_i \u306B\u306F\u5BFE\u5FDC\u3057\u3066\u3044\u306A\u3044\u3000\u3053\
    \u3046\u3044\u3046i\u3067\u5206\u5272\u3057\u3066\u305D\u308C\u305E\u308C\u3067\
    \u89E3\u304F\u3057\u304B\u306A\u3044\u304B\uFF1F\n\n\tcomplexity: O(N^3)\n\tverify:\
    \ https://atcoder.jp/contests/arc113/submissions/25330348\n*/\ntemplate<class\
    \ Ord>\nmint IncreasingProb(VV<mint> val, VV<Ord> order_){\n\tint N = si(val);\n\
    \tassert(si(invs) >= N+2);\n\tauto ord = Vec<int>(N,2);\n\t{\n\t\tV<Ord> os;\n\
    \t\trep(i,N) rep(j,2) os.pb(order_[i][j]);\n\t\tmkuni(os);\n\t\trep(i,N) rep(j,2)\
    \ ord[i][j] = lwb(os,order_[i][j]);\n\t}\n\trep(i,N){\n\t\tassert(ord[i][0] <\
    \ ord[i][1]);\t// L_i >= R_i \u7981\u6B62! \u5B9F\u969B\u306F\u4E00\u70B9\u306E\
    \u5834\u5408\u306F\u5B9A\u7FA9\u3067\u304D\u308B\u304C\u9762\u5012\u306A\u306E\
    \u3067\u4EEE\u5B9A\n\t}\n\tint K = 1;\n\trep(i,N) rep(j,2) chmax(K,ord[i][j]+1);\n\
    \tV<mint> xs(K);\n\trep(i,N) rep(j,2) xs[ord[i][j]] = val[i][j];\n\n\tauto is\
    \ = Vec<bool>(N,K-1);\n\trep(i,N){\n\t\tfor(int j=ord[i][0];j<ord[i][1];j++) is[i][j]\
    \ = true;\n\t}\n\n\tauto dp = Vec<mint>(K,N+1);\n\tdp[0][0] = 1;\n\trep(k,K-1){\n\
    \t\trep(i,N+1) if(dp[k][i]){\n\t\t\tmint tmp = 1;\n\t\t\tfor(int ni=i;ni<=N;ni++){\n\
    \t\t\t\tdp[k+1][ni] += dp[k][i] * tmp;\n\t\t\t\tif(ni != N){\n\t\t\t\t\tif(!is[ni][k])\
    \ break;\n\t\t\t\t\ttmp *= (xs[k+1]-xs[k]) * invs[ni+1-i];\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\t}\n\tmint prob = dp[K-1][N];\n\trep(i,N) prob /= val[i][1]-val[i][0];\n\
    \treturn prob;\n}\n"
  code: "/*\n\tx_i \\in [l_i,r_i] \u3092 random \u306B\u53D6\u3063\u3066\u304D\u305F\
    \u3068\u304D\u306B x_0 < x_1 < .. < x_{N-1} \u3068\u306A\u308B\u78BA\u7387\u3092\
    \u6C42\u3081\u308B\n\tinput:\n\t\tmint(l_i) \u3068\u304B\u3060\u3051\u898B\u3066\
    \u3082\u9806\u5E8F\u304C\u308F\u304B\u3089\u306A\u3044\u53EF\u80FD\u6027\u304C\
    \u3042\u308B\u306E\u3067\u3001\n\t\tval[N][2]: mint\u3067\u306E\u5024\n\t\torder_[N][2]:\
    \ \u5B9F\u969B\u306E\u9806\u5E8F\u304C\u5165\u3063\u305F\u306A\u306B\u304B\u3001\
    \u5148\u306B\u5EA7\u5727\u3057\u305F\u3082\u306E\u3092\u6E21\u3057\u3066\u3082\
    \u3044\u3044\u3057double\u3068\u304BFrac\u3068\u304B\u3067\u6E21\u3057\u3066\u3082\
    \u3044\u3044\n\n\t\u3042\u3068 l_i = r_i \u306B\u306F\u5BFE\u5FDC\u3057\u3066\u3044\
    \u306A\u3044\u3000\u3053\u3046\u3044\u3046i\u3067\u5206\u5272\u3057\u3066\u305D\
    \u308C\u305E\u308C\u3067\u89E3\u304F\u3057\u304B\u306A\u3044\u304B\uFF1F\n\n\t\
    complexity: O(N^3)\n\tverify: https://atcoder.jp/contests/arc113/submissions/25330348\n\
    */\ntemplate<class Ord>\nmint IncreasingProb(VV<mint> val, VV<Ord> order_){\n\t\
    int N = si(val);\n\tassert(si(invs) >= N+2);\n\tauto ord = Vec<int>(N,2);\n\t\
    {\n\t\tV<Ord> os;\n\t\trep(i,N) rep(j,2) os.pb(order_[i][j]);\n\t\tmkuni(os);\n\
    \t\trep(i,N) rep(j,2) ord[i][j] = lwb(os,order_[i][j]);\n\t}\n\trep(i,N){\n\t\t\
    assert(ord[i][0] < ord[i][1]);\t// L_i >= R_i \u7981\u6B62! \u5B9F\u969B\u306F\
    \u4E00\u70B9\u306E\u5834\u5408\u306F\u5B9A\u7FA9\u3067\u304D\u308B\u304C\u9762\
    \u5012\u306A\u306E\u3067\u4EEE\u5B9A\n\t}\n\tint K = 1;\n\trep(i,N) rep(j,2) chmax(K,ord[i][j]+1);\n\
    \tV<mint> xs(K);\n\trep(i,N) rep(j,2) xs[ord[i][j]] = val[i][j];\n\n\tauto is\
    \ = Vec<bool>(N,K-1);\n\trep(i,N){\n\t\tfor(int j=ord[i][0];j<ord[i][1];j++) is[i][j]\
    \ = true;\n\t}\n\n\tauto dp = Vec<mint>(K,N+1);\n\tdp[0][0] = 1;\n\trep(k,K-1){\n\
    \t\trep(i,N+1) if(dp[k][i]){\n\t\t\tmint tmp = 1;\n\t\t\tfor(int ni=i;ni<=N;ni++){\n\
    \t\t\t\tdp[k+1][ni] += dp[k][i] * tmp;\n\t\t\t\tif(ni != N){\n\t\t\t\t\tif(!is[ni][k])\
    \ break;\n\t\t\t\t\ttmp *= (xs[k+1]-xs[k]) * invs[ni+1-i];\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\t}\n\tmint prob = dp[K-1][N];\n\trep(i,N) prob /= val[i][1]-val[i][0];\n\
    \treturn prob;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/IncreasingProb.cpp
  requiredBy: []
  timestamp: '2021-08-25 19:44:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/IncreasingProb.cpp
layout: document
redirect_from:
- /library/math/IncreasingProb.cpp
- /library/math/IncreasingProb.cpp.html
title: math/IncreasingProb.cpp
---
