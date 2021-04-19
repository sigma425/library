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
  bundledCode: "#line 1 \"math/rand.cpp\"\n/*\n\trand\n\tT\u306F\u6574\u6570\u578B\
    \u306A\u3089\u306A\u3093\u3067\u3082\u3044\u3044\n\t\u5B9F\u6570\u306A\u3089uniform_real_distirbution\n\
    */\ntemplate<class T>\nT rnd(T l,T r){\t//[l,r)\n\tusing D = uniform_int_distribution<T>;\n\
    \tstatic random_device rd;\n\tstatic mt19937 gen(rd());\n\treturn D(l,r-1)(gen);\n\
    }\ntemplate<class T>\nT rnd(T n){\t//[0,n)\n\treturn rnd(0,n);\n}\n"
  code: "/*\n\trand\n\tT\u306F\u6574\u6570\u578B\u306A\u3089\u306A\u3093\u3067\u3082\
    \u3044\u3044\n\t\u5B9F\u6570\u306A\u3089uniform_real_distirbution\n*/\ntemplate<class\
    \ T>\nT rnd(T l,T r){\t//[l,r)\n\tusing D = uniform_int_distribution<T>;\n\tstatic\
    \ random_device rd;\n\tstatic mt19937 gen(rd());\n\treturn D(l,r-1)(gen);\n}\n\
    template<class T>\nT rnd(T n){\t//[0,n)\n\treturn rnd(0,n);\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/rand.cpp
  requiredBy: []
  timestamp: '2018-10-12 13:58:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/rand.cpp
layout: document
redirect_from:
- /library/math/rand.cpp
- /library/math/rand.cpp.html
title: math/rand.cpp
---
