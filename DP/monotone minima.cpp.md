---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DP/monotone minima.cpp\"\n/*\r\n\r\n\r\nmonotone minima\r\
    \nH*W \u306E\u914D\u5217a\u304C\u3042\u3063\u3066, a[0] \u306E\u6700\u5C0F\u3092\
    \u53D6\u308B\u5834\u6240 <= a[1] \u306E\u6700\u5C0F\u3092\u53D6\u308B\u5834\u6240\
    \ <= a[2] \u306E\u6700\u5C0F\u3092\u53D6\u308B\u5834\u6240 ...\r\n\u3068\u306A\
    \u3063\u3066\u3044\u308B\u6642\u306B\u3001\u3053\u308C\u3089\u306E\u5834\u6240\
    \u3092\u3059\u3079\u3066\u6C42\u3081\u308B\r\n\r\nO(W log H)\r\n\r\nex.\r\nH =\
    \ 3, W = 5\r\n3 2 4 3 5\r\n3 4 1 2 2\r\n1 1 0 1 0\r\n\r\nMonge->totally monotone\
    \ \u306A\u306E\u3067\u3001\r\n\r\nlog\u3064\u3051\u308B\u3060\u3051\u3067\u4E00\
    \u822C\u5316\u51FA\u6765\u308B\u304B\u3089\u3053\u3063\u3061\u304C\u4E3B\u6D41\
    \u304B\u306A\u3042(monge\u308F\u304B\u308A\u306B\u304F\u3044\u3057)\r\n\r\n\u91CD\
    \u8981\u306A\u4F8B:\r\n\r\ndp[k][x]: k\u56DE\u5207\u3063\u3066\u4ECA\u5834\u6240\
    x\r\n\r\nrep(k,K){\r\n\trep(x,N+1){\r\n\t\trep(y,x) chmin(dp[k+1][x],dp[k][y]\
    \ + cost(y,x));\r\n\t}\r\n}\r\n\r\n\u3063\u3066\u3044\u3046\u306E\u304C\u3042\u308B\
    \u6642\u306B\u3001k,x\u3067\u306E\u6700\u9069y\u3092A[k][x] \u3068\u304A\u3044\
    \u305F\u6642\u306B A[k][x] <= A[k][x+1] \u304C\u6210\u308A\u7ACB\u3064\u306A\u3089\
    \u3001\u3053\u308C\u304C\u9069\u7528\u3067\u304D\u308B\r\n(k\u304C\u306A\u3044\
    \u3068\u3001x\u3092\u9806\u756A\u306B\u8A08\u7B97\u305B\u3056\u308B\u3092\u5F97\
    \u306A\u3044\u306E\u3067\u7121\u7406?)\r\n\r\nrep(k,K){\r\n\tminima(0,N+1,0,N+1);\
    \ (\u5185\u5074\u3067dp[k-1]\u3092\u4F7F\u3046)\r\n}\r\n\r\nverified by CF/868/F.cpp\r\
    \n\r\n*/\r\n\r\nusing D = ll;\r\nvoid minima(int lx,int rx,int ly,int ry){\t//[lx,rx)\
    \ \u306B\u3064\u3044\u3066 bestpos[x] \u3092\u6C42\u3081\u308B \u8ABF\u3079\u308B\
    \u7BC4\u56F2\u306F[ly,ry)\u3067\u3088\u3044\r\n\tif(lx >= rx) return;\r\n\tint\
    \ x = (lx+rx)/2;\r\n\tD best = ?;\r\n\tint besty = -1;\r\n\tfor(int y = ly; y<ry;\
    \ y++){\r\n\t\tD val = f(x,y)\r\n//\t\tD val = dp[k-1][y] + cost(y,m);\r\n\t\t\
    if(best ? val){\r\n\t\t\tbest = val;\r\n\t\t\tbesty = y;\r\n\t\t}\r\n\t}\r\n\r\
    \n//\topt[x] = y\r\n\t\r\n\tminima(k,lx,m,ly,besty+1);\r\n\tminima(k,m+1,rx,besty,ry);\r\
    \n}\r\n"
  code: "/*\r\n\r\n\r\nmonotone minima\r\nH*W \u306E\u914D\u5217a\u304C\u3042\u3063\
    \u3066, a[0] \u306E\u6700\u5C0F\u3092\u53D6\u308B\u5834\u6240 <= a[1] \u306E\u6700\
    \u5C0F\u3092\u53D6\u308B\u5834\u6240 <= a[2] \u306E\u6700\u5C0F\u3092\u53D6\u308B\
    \u5834\u6240 ...\r\n\u3068\u306A\u3063\u3066\u3044\u308B\u6642\u306B\u3001\u3053\
    \u308C\u3089\u306E\u5834\u6240\u3092\u3059\u3079\u3066\u6C42\u3081\u308B\r\n\r\
    \nO(W log H)\r\n\r\nex.\r\nH = 3, W = 5\r\n3 2 4 3 5\r\n3 4 1 2 2\r\n1 1 0 1 0\r\
    \n\r\nMonge->totally monotone \u306A\u306E\u3067\u3001\r\n\r\nlog\u3064\u3051\u308B\
    \u3060\u3051\u3067\u4E00\u822C\u5316\u51FA\u6765\u308B\u304B\u3089\u3053\u3063\
    \u3061\u304C\u4E3B\u6D41\u304B\u306A\u3042(monge\u308F\u304B\u308A\u306B\u304F\
    \u3044\u3057)\r\n\r\n\u91CD\u8981\u306A\u4F8B:\r\n\r\ndp[k][x]: k\u56DE\u5207\u3063\
    \u3066\u4ECA\u5834\u6240x\r\n\r\nrep(k,K){\r\n\trep(x,N+1){\r\n\t\trep(y,x) chmin(dp[k+1][x],dp[k][y]\
    \ + cost(y,x));\r\n\t}\r\n}\r\n\r\n\u3063\u3066\u3044\u3046\u306E\u304C\u3042\u308B\
    \u6642\u306B\u3001k,x\u3067\u306E\u6700\u9069y\u3092A[k][x] \u3068\u304A\u3044\
    \u305F\u6642\u306B A[k][x] <= A[k][x+1] \u304C\u6210\u308A\u7ACB\u3064\u306A\u3089\
    \u3001\u3053\u308C\u304C\u9069\u7528\u3067\u304D\u308B\r\n(k\u304C\u306A\u3044\
    \u3068\u3001x\u3092\u9806\u756A\u306B\u8A08\u7B97\u305B\u3056\u308B\u3092\u5F97\
    \u306A\u3044\u306E\u3067\u7121\u7406?)\r\n\r\nrep(k,K){\r\n\tminima(0,N+1,0,N+1);\
    \ (\u5185\u5074\u3067dp[k-1]\u3092\u4F7F\u3046)\r\n}\r\n\r\nverified by CF/868/F.cpp\r\
    \n\r\n*/\r\n\r\nusing D = ll;\r\nvoid minima(int lx,int rx,int ly,int ry){\t//[lx,rx)\
    \ \u306B\u3064\u3044\u3066 bestpos[x] \u3092\u6C42\u3081\u308B \u8ABF\u3079\u308B\
    \u7BC4\u56F2\u306F[ly,ry)\u3067\u3088\u3044\r\n\tif(lx >= rx) return;\r\n\tint\
    \ x = (lx+rx)/2;\r\n\tD best = ?;\r\n\tint besty = -1;\r\n\tfor(int y = ly; y<ry;\
    \ y++){\r\n\t\tD val = f(x,y)\r\n//\t\tD val = dp[k-1][y] + cost(y,m);\r\n\t\t\
    if(best ? val){\r\n\t\t\tbest = val;\r\n\t\t\tbesty = y;\r\n\t\t}\r\n\t}\r\n\r\
    \n//\topt[x] = y\r\n\t\r\n\tminima(k,lx,m,ly,besty+1);\r\n\tminima(k,m+1,rx,besty,ry);\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/monotone minima.cpp
  requiredBy: []
  timestamp: '2018-07-11 09:30:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/monotone minima.cpp
layout: document
redirect_from:
- /library/DP/monotone minima.cpp
- /library/DP/monotone minima.cpp.html
title: DP/monotone minima.cpp
---
