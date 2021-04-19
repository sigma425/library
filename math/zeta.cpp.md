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
  bundledCode: "#line 1 \"math/zeta.cpp\"\n/* zeta\nS:(subset of N) -> f(S) \u304B\
    \u3089\ng(S)=sigma f(T) for all T>S \u3092\u6C42\u3081\u308B\ng(10010) = sigma\
    \ f(1**1*)\n*/\nvoid zeta(int* f,int N){\n\trep(i,N) rep(j,1<<N) if(0==(j&1<<i))\
    \ f[j]+=f[j|(1<<i)];\n}\n/*\nT<S\u306E\u548C\ng(10010) = sigma f(*00*0)\n*/\n\
    void zeta(int *f,int N){\n\trep(i,N) for(int j=(1<<N)-1;j>=0;j--) if((j>>i)&1)\
    \ f[j]+=f[j^(1<<i)];\n}\n\n/*\u9006\u5909\u63DB(Mebius)\ng\u304B\u3089f\u3092\u6C42\
    \u3081\u308B\n*/\nvoid mebius(int *g,int N){\n\trep(i,N) for(int j=(1<<N)-1;j>=0;j--)\
    \ if(0==(j&1<<i)) g[j]-=g[j^(1<<i)];\n}\n/*T<S\u30D0\u30FC\u30B8\u30E7\u30F3*/\n\
    void mebius(int *g,int N){\n\trep(i,N) rep(j,1<<N) if(j&(1<<i)) g[j]-=g[j^(1<<i)];\n\
    }\n"
  code: "/* zeta\nS:(subset of N) -> f(S) \u304B\u3089\ng(S)=sigma f(T) for all T>S\
    \ \u3092\u6C42\u3081\u308B\ng(10010) = sigma f(1**1*)\n*/\nvoid zeta(int* f,int\
    \ N){\n\trep(i,N) rep(j,1<<N) if(0==(j&1<<i)) f[j]+=f[j|(1<<i)];\n}\n/*\nT<S\u306E\
    \u548C\ng(10010) = sigma f(*00*0)\n*/\nvoid zeta(int *f,int N){\n\trep(i,N) for(int\
    \ j=(1<<N)-1;j>=0;j--) if((j>>i)&1) f[j]+=f[j^(1<<i)];\n}\n\n/*\u9006\u5909\u63DB\
    (Mebius)\ng\u304B\u3089f\u3092\u6C42\u3081\u308B\n*/\nvoid mebius(int *g,int N){\n\
    \trep(i,N) for(int j=(1<<N)-1;j>=0;j--) if(0==(j&1<<i)) g[j]-=g[j^(1<<i)];\n}\n\
    /*T<S\u30D0\u30FC\u30B8\u30E7\u30F3*/\nvoid mebius(int *g,int N){\n\trep(i,N)\
    \ rep(j,1<<N) if(j&(1<<i)) g[j]-=g[j^(1<<i)];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/zeta.cpp
  requiredBy: []
  timestamp: '2018-09-18 03:14:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/zeta.cpp
layout: document
redirect_from:
- /library/math/zeta.cpp
- /library/math/zeta.cpp.html
title: math/zeta.cpp
---
