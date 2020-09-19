---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://codeforces.com/blog/entry/70247
  bundledCode: "#line 1 \"mult_CF.cpp\"\n/*\n    int128\u304C\u5165\u3063\u3066\u306A\
    \u3044\u3084\u3093\uFF01\u7528\n     - md \u304C\u5C0F\u3055\u3044\u6642\u5546\
    \u304C long double \u3067\u6C42\u3081\u3089\u308C\u308B\u304B\uFF1F\n    \u306A\
    \u3069\u3001\u4E0D\u660E\u70B9\u304C\u591A\u3044\u3067\u3059\u306D\n    https://codeforces.com/blog/entry/70247\n\
    \    gym102361 H.cpp\n*/\ninline ll mul(ll a,ll b,ll md){\n\tll s=a*b-ll((long\
    \ double)a/md*b+0.5)*md;\n\treturn (s<0) ? (s+md) : (s>=md ? s-md : s);\n}\n"
  code: "/*\n    int128\u304C\u5165\u3063\u3066\u306A\u3044\u3084\u3093\uFF01\u7528\
    \n     - md \u304C\u5C0F\u3055\u3044\u6642\u5546\u304C long double \u3067\u6C42\
    \u3081\u3089\u308C\u308B\u304B\uFF1F\n    \u306A\u3069\u3001\u4E0D\u660E\u70B9\
    \u304C\u591A\u3044\u3067\u3059\u306D\n    https://codeforces.com/blog/entry/70247\n\
    \    gym102361 H.cpp\n*/\ninline ll mul(ll a,ll b,ll md){\n\tll s=a*b-ll((long\
    \ double)a/md*b+0.5)*md;\n\treturn (s<0) ? (s+md) : (s>=md ? s-md : s);\n}"
  dependsOn: []
  isVerificationFile: false
  path: mult_CF.cpp
  requiredBy: []
  timestamp: '2020-02-13 22:29:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mult_CF.cpp
layout: document
redirect_from:
- /library/mult_CF.cpp
- /library/mult_CF.cpp.html
title: mult_CF.cpp
---
