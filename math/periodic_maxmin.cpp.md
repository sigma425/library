---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"math/periodic_maxmin.cpp\"\n/*\n\ta[i] = sin(2pi*i/N) \u307F\
    \u305F\u3044\u306B\u3001\n\t- \u5468\u671F\u7684\u3067\u3042\u3063\u3066\n\t-\
    \ \u9069\u5F53\u306A\u5834\u6240\u304B\u3089\u898B\u308B\u3068 up down \u3092\u4E00\
    \u5EA6\u3059\u308B\n\n\ta \u3068\u3044\u3046\u914D\u5217\u304C\u3042\u3063\u3066\
    \u3001\u305D\u308C\u3092\u30AF\u30A8\u30EA\u3067\u53D6\u5F97\u3067\u304D\u308B\
    \u6642\u306B\u3001log\u56DE\u547C\u3073\u51FA\u3057\u3067argmax,argmin\u3092\u7279\
    \u5B9A\u3059\u308B\n\n\t\u524D\u63D0: \u9023\u7D9A\u3059\u308B\u4E8C\u7B87\u6240\
    \u3067=\u306B\u306A\u3063\u3066\u306F\u3044\u3051\u306A\u3044\n\n\t\u4F8B: \u51F8\
    \u591A\u89D2\u5F62\u306E\u5404\u9802\u70B9\u3068\u76F4\u7DDA\u3068\u306E\u8DDD\
    \u96E2\n\t    \u51F8\u591A\u89D2\u5F62\u3068\u70B9\u304C\u4E0E\u3048\u3089\u308C\
    \u3066\u3001\u70B9\u304B\u3089\u3069\u306E\u9802\u70B9\u9054\u304C\u898B\u3048\
    \u308B\u304B(\u504F\u89D2)\n*/\n#include <bits/stdc++.h>\n#define rep(i,N) for(int\
    \ i=0;i<(int)(N);i++)\n#define rep1(i,N) for(int i=1;i<=(int)(N);i++)\n#define\
    \ show(x) cout<<#x<<\" = \"<<x<<endl\n#define all(c) c.begin(),c.end()\n#define\
    \ chmin(x,y) x = min(x,y)\n#define chmax(x,y) x = max(x,y)\n#define pb push_back\n\
    using namespace std;\n\nD query(int i,int N){\n\ti%=N;\n\t//\n}\n\ntemplate<class\
    \ D>\nint getArgmax(int N){\n\tif(N==1) return 0;\n\n\tD h = query(0);\n\tbool\
    \ up = h < query(1);\n\n\tint lb = 0, ub = N;\n\twhile(ub-lb>1){\n\t\tint m =\
    \ (ub+lb)/2;\n\t\tif(query(m) < h){\n\t\t\tif(up) ub = m;\n\t\t\telse lb = m;\n\
    \t\t}else{\n\t\t\tD a = query(m);\n\t\t\tD b = query(m+1);\n\t\t\tif(a<b) lb =\
    \ m;\n\t\t\telse ub = m;\n\t\t}\n\t}\n\treturn query(lb)<query(ub) ? ub : lb;\n\
    }\n\ntemplate<class D>\nint getArgmin(int N){\n\tif(N==1) return 0;\n\n\tD h =\
    \ query(0);\n\tbool up = h < query(1);\n\n\tint lb = 0, ub = N;\n\twhile(ub-lb>1){\n\
    \t\tint m = (ub+lb)/2;\n\t\tif(query(m) > h){\n\t\t\tif(up) lb = m;\n\t\t\telse\
    \ ub = m;\n\t\t}else{\n\t\t\tD a = query(m);\n\t\t\tD b = query(m+1);\n\t\t\t\
    if(a>b) lb = m;\n\t\t\telse ub = m;\n\t\t}\n\t}\n\treturn query(lb)<query(ub)\
    \ ? lb : ub;\n}\n\n"
  code: "/*\n\ta[i] = sin(2pi*i/N) \u307F\u305F\u3044\u306B\u3001\n\t- \u5468\u671F\
    \u7684\u3067\u3042\u3063\u3066\n\t- \u9069\u5F53\u306A\u5834\u6240\u304B\u3089\
    \u898B\u308B\u3068 up down \u3092\u4E00\u5EA6\u3059\u308B\n\n\ta \u3068\u3044\u3046\
    \u914D\u5217\u304C\u3042\u3063\u3066\u3001\u305D\u308C\u3092\u30AF\u30A8\u30EA\
    \u3067\u53D6\u5F97\u3067\u304D\u308B\u6642\u306B\u3001log\u56DE\u547C\u3073\u51FA\
    \u3057\u3067argmax,argmin\u3092\u7279\u5B9A\u3059\u308B\n\n\t\u524D\u63D0: \u9023\
    \u7D9A\u3059\u308B\u4E8C\u7B87\u6240\u3067=\u306B\u306A\u3063\u3066\u306F\u3044\
    \u3051\u306A\u3044\n\n\t\u4F8B: \u51F8\u591A\u89D2\u5F62\u306E\u5404\u9802\u70B9\
    \u3068\u76F4\u7DDA\u3068\u306E\u8DDD\u96E2\n\t    \u51F8\u591A\u89D2\u5F62\u3068\
    \u70B9\u304C\u4E0E\u3048\u3089\u308C\u3066\u3001\u70B9\u304B\u3089\u3069\u306E\
    \u9802\u70B9\u9054\u304C\u898B\u3048\u308B\u304B(\u504F\u89D2)\n*/\n#include <bits/stdc++.h>\n\
    #define rep(i,N) for(int i=0;i<(int)(N);i++)\n#define rep1(i,N) for(int i=1;i<=(int)(N);i++)\n\
    #define show(x) cout<<#x<<\" = \"<<x<<endl\n#define all(c) c.begin(),c.end()\n\
    #define chmin(x,y) x = min(x,y)\n#define chmax(x,y) x = max(x,y)\n#define pb push_back\n\
    using namespace std;\n\nD query(int i,int N){\n\ti%=N;\n\t//\n}\n\ntemplate<class\
    \ D>\nint getArgmax(int N){\n\tif(N==1) return 0;\n\n\tD h = query(0);\n\tbool\
    \ up = h < query(1);\n\n\tint lb = 0, ub = N;\n\twhile(ub-lb>1){\n\t\tint m =\
    \ (ub+lb)/2;\n\t\tif(query(m) < h){\n\t\t\tif(up) ub = m;\n\t\t\telse lb = m;\n\
    \t\t}else{\n\t\t\tD a = query(m);\n\t\t\tD b = query(m+1);\n\t\t\tif(a<b) lb =\
    \ m;\n\t\t\telse ub = m;\n\t\t}\n\t}\n\treturn query(lb)<query(ub) ? ub : lb;\n\
    }\n\ntemplate<class D>\nint getArgmin(int N){\n\tif(N==1) return 0;\n\n\tD h =\
    \ query(0);\n\tbool up = h < query(1);\n\n\tint lb = 0, ub = N;\n\twhile(ub-lb>1){\n\
    \t\tint m = (ub+lb)/2;\n\t\tif(query(m) > h){\n\t\t\tif(up) lb = m;\n\t\t\telse\
    \ ub = m;\n\t\t}else{\n\t\t\tD a = query(m);\n\t\t\tD b = query(m+1);\n\t\t\t\
    if(a>b) lb = m;\n\t\t\telse ub = m;\n\t\t}\n\t}\n\treturn query(lb)<query(ub)\
    \ ? lb : ub;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: math/periodic_maxmin.cpp
  requiredBy: []
  timestamp: '2018-09-18 03:14:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/periodic_maxmin.cpp
layout: document
redirect_from:
- /library/math/periodic_maxmin.cpp
- /library/math/periodic_maxmin.cpp.html
title: math/periodic_maxmin.cpp
---
