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
    - https://atcoder.jp/contests/appini/submissions/11754773
  bundledCode: "#line 1 \"DP/monotone minima.cpp\"\n/*\r\n\tf(x,y) \u306E row maxima\
    \ (rightmost) \u304C \u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\u306A\u3068\u304D\u3001\
    \ O(H + W logH) \u56DE\u306E f() call \u3067 row maxima(\u306Eindex) \u3092\u3059\
    \u3079\u3066\u6C42\u3081\u308B\r\n\tmaxima / minima , leftmost / rightmost \u3067\
    4\u901A\u308A\u3042\u308B\u3051\u3069\u30B3\u30E1\u30F3\u30C8\u3042\u308B\u884C\
    \u306E\u4E0D\u7B49\u53F7\u5909\u3048\u308B\u3060\u3051\u3067\u53EF\u80FD\u3001\
    \u4E00\u8CAB\u6027\u306F\u306A\u3044\u3068\u3044\u3051\u306A\u3044\u3053\u3068\
    \u306B\u6CE8\u610F\r\n\r\n\t\u5178\u578B\u4F8B\r\n\t\t[0,N] \u3092 K \u500B\u306E\
    \u533A\u9593\u306B\u308F\u3051\u3066\u533A\u9593\u306E\u30B3\u30B9\u30C8\u306E\
    \u548C\u6700\u5927/\u6700\u5C0F\u5316\r\n\t\t\u611A\u76F4\u306B\u306FO(KN^2)\r\
    \n\r\n\t\t\tdp[0][0] = 0, rep1(i,N) dp[0][i] = -inf;\r\n\t\t\trep(k,K) rep(i,N+1){\r\
    \n\t\t\t\trep(j,i) chmax(dp[k+1][i],dp[k][j]+cost[j][i])\r\n\t\t\t}\r\n\r\n\t\t\
    \u3053\u308C\u3092 (k:fix\u3057\u3066) f(i,j) = dp[k][j]+cost[j][i] \u3068\u3057\
    \u3066\u6761\u4EF6\u3092\u6E80\u305F\u3059\u3068\u3059\u308C\u3070\r\n\r\n\t\t\
    \tdp[0][0] = 0, rep1(i,N) dp[0][i] = -inf;\r\n\t\t\trep(k,K){\r\n\t\t\t\tauto\
    \ f = [&](int i,int j){\r\n\t\t\t\t\tif(j > i) return -inf; \r\n\t\t\t\t\treturn\
    \ dp[k][j] + cost[j][i];\r\n\t\t\t\t};\r\n\t\t\t\tauto w = row_maxima(f,N+1,N+1);\t\
    // w[i] = i\u3067\u306E\u6700\u9069\u306Aj\r\n\t\t\t\trep(i,N+1) dp[k+1][i] =\
    \ dp[k][w[i]] + cost[w[i]][i];\r\n\t\t\t}\r\n\r\n\t\t\u3068\u5909\u5F62\u3067\u304D\
    \u308B O(KNlogN)\r\n\t\t\u6761\u4EF6\u306F\u3001\"\u3088\u308A\u53F3\u307E\u3067\
    \u3092k\u500B\u3067\u5206\u3051\u308B\u3068\u304D\u3001\u76F4\u8FD1\u3067\u5207\
    \u3063\u305F\u5834\u6240\u306F\u3088\u308A\u53F3\u306B\u306A\u308B\"\r\n\t\tk\
    \ \u304C\u3042\u308B\u305F\u3081\u306B f(j,i) \u307F\u305F\u3044\u306A\u306E\u3092\
    \u9806\u5E8F\u3092\u7121\u8996\u3057\u3066\u8A55\u4FA1\u3067\u304D\u308B\u306E\
    \u3067\u3001\u4F7F\u3048\u308B\r\n\t\t\u5F53\u7136\u4E0B\u4E09\u89D2 (j<=i) \u306E\
    \u307F\u307E\u3068\u3082\u306A\u5024\u304C\u5165\u3063\u3066\u3044\u308B\u3068\
    \u3057\u3066\u3044\u3044\u304C\u3001dp[k+1][i] = -inf \u306E\u3068\u304D\u6700\
    \u9069rightmost\u304Cj=N\u307F\u305F\u3044\u306B\u306A\u308A\u3046\u308B\u306E\
    \u3067\u3001\u305D\u308C\u306F\u6CE8\u610F\u3059\u308B\u3053\u3068\r\n\t\t\u306A\
    \u3093\u304Bleftmost\u306E\u65B9\u304C\u5B89\u5168\u305D\u3046\u3060\u306A\r\n\
    \t\t\u7121\u99C4\u306B\u5207\u3063\u3066\u3044\u3044\u304B( <=> k++\u3057\u3066\
    \u3044\u3044\u304B <=> j=i \u304C\u8A31\u3055\u308C\u308B\u304B)\u3082\u6CE8\u610F\
    \r\n\r\n\tverified at:\r\n\t\tUniversalCup 1 day3 I\r\n\t\thttps://atcoder.jp/contests/appini/submissions/11754773\r\
    \n\t\tCF/868/F.cpp\r\n*/\r\n\r\ntemplate<class F> V<int> row_maxima(F f,int H,int\
    \ W){\r\n\tusing D = typename result_of<F(int,int)>::type;\r\n\tV<int> res(H);\r\
    \n\tauto sub = [&](auto self,int l,int r,int lb,int ub)->void{\r\n\t\tif(l >=\
    \ r) return;\r\n\t\tint x = (l+r)/2;\r\n\t\tD best = f(x,lb);\r\n\t\tint argy\
    \ = lb;\r\n\t\tfor(int y=lb+1;y<=ub;y++){\r\n\t\t\tD val = f(x,y);\r\n\t\t\tif(val\
    \ >= best){\t\t\t\t//maxima (rightmost)\r\n//\t\t\tif(val > best){\t\t\t\t\t//maxima\
    \ (leftmost)\r\n//\t\t\tif(val <= best){\t\t\t\t//minima (rightmost)\r\n//\t\t\
    \tif(val < best){\t\t\t\t\t//minima (leftmost)\r\n\t\t\t\tbest = val;\r\n\t\t\t\
    \targy = y;\r\n\t\t\t}\r\n\t\t}\r\n\t\tres[x] = argy;\r\n\t\tself(self,l,x,lb,argy);\r\
    \n\t\tself(self,x+1,r,argy,ub);\r\n\t};\r\n\tsub(sub,0,H,0,W-1);\r\n\treturn res;\r\
    \n}\n"
  code: "/*\r\n\tf(x,y) \u306E row maxima (rightmost) \u304C \u5E83\u7FA9\u5358\u8ABF\
    \u5897\u52A0\u306A\u3068\u304D\u3001 O(H + W logH) \u56DE\u306E f() call \u3067\
    \ row maxima(\u306Eindex) \u3092\u3059\u3079\u3066\u6C42\u3081\u308B\r\n\tmaxima\
    \ / minima , leftmost / rightmost \u30674\u901A\u308A\u3042\u308B\u3051\u3069\u30B3\
    \u30E1\u30F3\u30C8\u3042\u308B\u884C\u306E\u4E0D\u7B49\u53F7\u5909\u3048\u308B\
    \u3060\u3051\u3067\u53EF\u80FD\u3001\u4E00\u8CAB\u6027\u306F\u306A\u3044\u3068\
    \u3044\u3051\u306A\u3044\u3053\u3068\u306B\u6CE8\u610F\r\n\r\n\t\u5178\u578B\u4F8B\
    \r\n\t\t[0,N] \u3092 K \u500B\u306E\u533A\u9593\u306B\u308F\u3051\u3066\u533A\u9593\
    \u306E\u30B3\u30B9\u30C8\u306E\u548C\u6700\u5927/\u6700\u5C0F\u5316\r\n\t\t\u611A\
    \u76F4\u306B\u306FO(KN^2)\r\n\r\n\t\t\tdp[0][0] = 0, rep1(i,N) dp[0][i] = -inf;\r\
    \n\t\t\trep(k,K) rep(i,N+1){\r\n\t\t\t\trep(j,i) chmax(dp[k+1][i],dp[k][j]+cost[j][i])\r\
    \n\t\t\t}\r\n\r\n\t\t\u3053\u308C\u3092 (k:fix\u3057\u3066) f(i,j) = dp[k][j]+cost[j][i]\
    \ \u3068\u3057\u3066\u6761\u4EF6\u3092\u6E80\u305F\u3059\u3068\u3059\u308C\u3070\
    \r\n\r\n\t\t\tdp[0][0] = 0, rep1(i,N) dp[0][i] = -inf;\r\n\t\t\trep(k,K){\r\n\t\
    \t\t\tauto f = [&](int i,int j){\r\n\t\t\t\t\tif(j > i) return -inf; \r\n\t\t\t\
    \t\treturn dp[k][j] + cost[j][i];\r\n\t\t\t\t};\r\n\t\t\t\tauto w = row_maxima(f,N+1,N+1);\t\
    // w[i] = i\u3067\u306E\u6700\u9069\u306Aj\r\n\t\t\t\trep(i,N+1) dp[k+1][i] =\
    \ dp[k][w[i]] + cost[w[i]][i];\r\n\t\t\t}\r\n\r\n\t\t\u3068\u5909\u5F62\u3067\u304D\
    \u308B O(KNlogN)\r\n\t\t\u6761\u4EF6\u306F\u3001\"\u3088\u308A\u53F3\u307E\u3067\
    \u3092k\u500B\u3067\u5206\u3051\u308B\u3068\u304D\u3001\u76F4\u8FD1\u3067\u5207\
    \u3063\u305F\u5834\u6240\u306F\u3088\u308A\u53F3\u306B\u306A\u308B\"\r\n\t\tk\
    \ \u304C\u3042\u308B\u305F\u3081\u306B f(j,i) \u307F\u305F\u3044\u306A\u306E\u3092\
    \u9806\u5E8F\u3092\u7121\u8996\u3057\u3066\u8A55\u4FA1\u3067\u304D\u308B\u306E\
    \u3067\u3001\u4F7F\u3048\u308B\r\n\t\t\u5F53\u7136\u4E0B\u4E09\u89D2 (j<=i) \u306E\
    \u307F\u307E\u3068\u3082\u306A\u5024\u304C\u5165\u3063\u3066\u3044\u308B\u3068\
    \u3057\u3066\u3044\u3044\u304C\u3001dp[k+1][i] = -inf \u306E\u3068\u304D\u6700\
    \u9069rightmost\u304Cj=N\u307F\u305F\u3044\u306B\u306A\u308A\u3046\u308B\u306E\
    \u3067\u3001\u305D\u308C\u306F\u6CE8\u610F\u3059\u308B\u3053\u3068\r\n\t\t\u306A\
    \u3093\u304Bleftmost\u306E\u65B9\u304C\u5B89\u5168\u305D\u3046\u3060\u306A\r\n\
    \t\t\u7121\u99C4\u306B\u5207\u3063\u3066\u3044\u3044\u304B( <=> k++\u3057\u3066\
    \u3044\u3044\u304B <=> j=i \u304C\u8A31\u3055\u308C\u308B\u304B)\u3082\u6CE8\u610F\
    \r\n\r\n\tverified at:\r\n\t\tUniversalCup 1 day3 I\r\n\t\thttps://atcoder.jp/contests/appini/submissions/11754773\r\
    \n\t\tCF/868/F.cpp\r\n*/\r\n\r\ntemplate<class F> V<int> row_maxima(F f,int H,int\
    \ W){\r\n\tusing D = typename result_of<F(int,int)>::type;\r\n\tV<int> res(H);\r\
    \n\tauto sub = [&](auto self,int l,int r,int lb,int ub)->void{\r\n\t\tif(l >=\
    \ r) return;\r\n\t\tint x = (l+r)/2;\r\n\t\tD best = f(x,lb);\r\n\t\tint argy\
    \ = lb;\r\n\t\tfor(int y=lb+1;y<=ub;y++){\r\n\t\t\tD val = f(x,y);\r\n\t\t\tif(val\
    \ >= best){\t\t\t\t//maxima (rightmost)\r\n//\t\t\tif(val > best){\t\t\t\t\t//maxima\
    \ (leftmost)\r\n//\t\t\tif(val <= best){\t\t\t\t//minima (rightmost)\r\n//\t\t\
    \tif(val < best){\t\t\t\t\t//minima (leftmost)\r\n\t\t\t\tbest = val;\r\n\t\t\t\
    \targy = y;\r\n\t\t\t}\r\n\t\t}\r\n\t\tres[x] = argy;\r\n\t\tself(self,l,x,lb,argy);\r\
    \n\t\tself(self,x+1,r,argy,ub);\r\n\t};\r\n\tsub(sub,0,H,0,W-1);\r\n\treturn res;\r\
    \n}"
  dependsOn: []
  isVerificationFile: false
  path: DP/monotone minima.cpp
  requiredBy: []
  timestamp: '2023-11-13 23:56:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/monotone minima.cpp
layout: document
redirect_from:
- /library/DP/monotone minima.cpp
- /library/DP/monotone minima.cpp.html
title: DP/monotone minima.cpp
---
