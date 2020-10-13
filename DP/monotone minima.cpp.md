---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/appini/submissions/11754773
  bundledCode: "#line 1 \"DP/monotone minima.cpp\"\n/*\r\n\tf(x,y) \u306E row maxima\
    \ (rightmost) \u304C \u8B1B\u7FA9\u5358\u8ABF\u5897\u52A0\u306A\u3068\u304D\u3001\
    \ O(H + W logH) \u56DE\u306E f() call \u3067 row maxima(\u306Eindex) \u3092\u3059\
    \u3079\u3066\u6C42\u3081\u308B\r\n\tmaxima / minima , leftmost / rightmost \u3067\
    4\u901A\u308A\u3042\u308B\u3051\u3069\u30B3\u30E1\u30F3\u30C8\u3042\u308B\u884C\
    \u306E\u4E0D\u7B49\u53F7\u5909\u3048\u308B\u3060\u3051\u3067\u53EF\u80FD\u3001\
    \u4E00\u8CAB\u6027\u306F\u306A\u3044\u3068\u3044\u3051\u306A\u3044\u3053\u3068\
    \u306B\u6CE8\u610F\r\n\t\u7279\u306BDP\u3067\u4F7F\u3046\u3068\u304D\u3001row\u304C\
    \u5168\u90E8inf\u3060\u304B\u3089\u521D\u624B\u3067\u53F3\u7AEF\u306B\u306A\u3063\
    \u3066\u3057\u307E\u3063\u3066\u58CA\u308C\u308B\u3001\u307F\u305F\u3044\u306A\
    \u306E\u306B\u5341\u5206\u6CE8\u610F\u3059\u308B\u3053\u3068\r\n\tverified at:\r\
    \n\t\thttps://atcoder.jp/contests/appini/submissions/11754773\r\n\t\tCF/868/F.cpp\r\
    \n*/\r\n\r\ntemplate<class F> V<int> row_maxima(F f,int H,int W){\r\n\tusing D\
    \ = typename result_of<F(int,int)>::type;\r\n\tV<int> res(H);\r\n\tauto sub =\
    \ [&](auto self,int l,int r,int lb,int ub)->void{\r\n\t\tif(l >= r) return;\r\n\
    \t\tint x = (l+r)/2;\r\n\t\tD best = f(x,lb);\r\n\t\tint argy = lb;\r\n\t\tfor(int\
    \ y=lb+1;y<=ub;y++){\r\n\t\t\tD val = f(x,y);\r\n\t\t\tif(val >= best){\t\t\t\t\
    //maxima (rightmost)\r\n\t\t\t\tbest = val;\r\n\t\t\t\targy = y;\r\n\t\t\t}\r\n\
    \t\t}\r\n\t\tres[x] = argy;\r\n\t\tself(self,l,x,lb,argy);\r\n\t\tself(self,x+1,r,argy,ub);\r\
    \n\t};\r\n\tsub(sub,0,H,0,W-1);\r\n\treturn res;\r\n}\n"
  code: "/*\r\n\tf(x,y) \u306E row maxima (rightmost) \u304C \u8B1B\u7FA9\u5358\u8ABF\
    \u5897\u52A0\u306A\u3068\u304D\u3001 O(H + W logH) \u56DE\u306E f() call \u3067\
    \ row maxima(\u306Eindex) \u3092\u3059\u3079\u3066\u6C42\u3081\u308B\r\n\tmaxima\
    \ / minima , leftmost / rightmost \u30674\u901A\u308A\u3042\u308B\u3051\u3069\u30B3\
    \u30E1\u30F3\u30C8\u3042\u308B\u884C\u306E\u4E0D\u7B49\u53F7\u5909\u3048\u308B\
    \u3060\u3051\u3067\u53EF\u80FD\u3001\u4E00\u8CAB\u6027\u306F\u306A\u3044\u3068\
    \u3044\u3051\u306A\u3044\u3053\u3068\u306B\u6CE8\u610F\r\n\t\u7279\u306BDP\u3067\
    \u4F7F\u3046\u3068\u304D\u3001row\u304C\u5168\u90E8inf\u3060\u304B\u3089\u521D\
    \u624B\u3067\u53F3\u7AEF\u306B\u306A\u3063\u3066\u3057\u307E\u3063\u3066\u58CA\
    \u308C\u308B\u3001\u307F\u305F\u3044\u306A\u306E\u306B\u5341\u5206\u6CE8\u610F\
    \u3059\u308B\u3053\u3068\r\n\tverified at:\r\n\t\thttps://atcoder.jp/contests/appini/submissions/11754773\r\
    \n\t\tCF/868/F.cpp\r\n*/\r\n\r\ntemplate<class F> V<int> row_maxima(F f,int H,int\
    \ W){\r\n\tusing D = typename result_of<F(int,int)>::type;\r\n\tV<int> res(H);\r\
    \n\tauto sub = [&](auto self,int l,int r,int lb,int ub)->void{\r\n\t\tif(l >=\
    \ r) return;\r\n\t\tint x = (l+r)/2;\r\n\t\tD best = f(x,lb);\r\n\t\tint argy\
    \ = lb;\r\n\t\tfor(int y=lb+1;y<=ub;y++){\r\n\t\t\tD val = f(x,y);\r\n\t\t\tif(val\
    \ >= best){\t\t\t\t//maxima (rightmost)\r\n\t\t\t\tbest = val;\r\n\t\t\t\targy\
    \ = y;\r\n\t\t\t}\r\n\t\t}\r\n\t\tres[x] = argy;\r\n\t\tself(self,l,x,lb,argy);\r\
    \n\t\tself(self,x+1,r,argy,ub);\r\n\t};\r\n\tsub(sub,0,H,0,W-1);\r\n\treturn res;\r\
    \n}"
  dependsOn: []
  isVerificationFile: false
  path: DP/monotone minima.cpp
  requiredBy: []
  timestamp: '2020-10-14 02:40:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/monotone minima.cpp
layout: document
redirect_from:
- /library/DP/monotone minima.cpp
- /library/DP/monotone minima.cpp.html
title: DP/monotone minima.cpp
---
