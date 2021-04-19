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
  bundledCode: "#line 1 \"math/garner.cpp\"\n/*\n\t!!ACL\u3092\u4F7F\u3046!!\n\n\t\
    x % rm[i].sc = rm[i].fs\n\t\u3092\u307F\u305F\u3059\u975E\u8CA0\u6574\u6570\u306E\
    \u3046\u3061\u6700\u5C0F\u306E\u3082\u306E%mod \u3092\u6C42\u3081\u308B\n\t0\u3092\
    \u306E\u305E\u304F\u306A\u3089,\u51680\u306E\u3068\u304D\u306E\u307Fas[N-1]\u3092\
    \u8FD4\u305B\u3070\u826F\u3044\n\t\n\t!!! rm[i].sc,mod\u306Fpairwise relatively\
    \ prime !!!\n\t\u7D20\u30D9\u30AD\u306B\u5206\u89E3\u3059\u308B -> \u5404\u7D20\
    \u6570\u3054\u3068\u306B\u77DB\u76FE\u3057\u306A\u3044\u304B\u78BA\u304B\u3081\
    \u308B -> garner\n\n\tbarcelona2017/5s/G.cpp\n*/\ntypedef long long ll;\ntypedef\
    \ pair<ll,ll> P;\t\t//val,mod;\nll inv(ll a,ll m){\n\tll b=m,u=1,v=0;\n\twhile(b){\n\
    \t\tll t=a/b;\n\t\tswap(a-=t*b,b);\n\t\tswap(u-=t*v,v);\n\t}\n\tu%=m;\n\tif(u<0)\
    \ u+=m;\n\treturn u;\n}\n/*\n\trm \u306F rem,mod\n\t\u6700\u5F8C\u306Bmod\u3092\
    \u53D6\u308B\u5FC5\u8981\u304C\u7121\u3044\u5834\u5408\u306F\u5F15\u6570\u7121\
    \u3057\u3067\u547C\u3093\u3067\u3088\u3044\n*/\nll garner(vector<P> rm,ll mod\
    \ = -1){\n\trm.pb(P(0,mod));\n\tint N=rm.size();\n\tvector<ll> as(N,1);\t\t//coefficients\n\
    \tvector<ll> bs(N,0);\t\t//constants\n\trep(i,N-1){\n\t\tll v=(rm[i].fs-bs[i])*inv(as[i],rm[i].sc)%rm[i].sc;\n\
    \t\tif(v<0) v+=rm[i].sc;\n\t\tfor(int j=i+1;j<N;j++){\n\t\t\tif(rm[j].sc != -1){\n\
    \t\t\t\t(bs[j]+=as[j]*v)%=rm[j].sc;\n\t\t\t\t(as[j]*=rm[i].sc)%=rm[j].sc;\n\t\t\
    \t}else{\n\t\t\t\tbs[j] += as[j]*v;\n\t\t\t\tas[j] *= rm[i].sc;\n\t\t\t}\n\t\t\
    }\n\t}\n\treturn bs[N-1];\n}\n"
  code: "/*\n\t!!ACL\u3092\u4F7F\u3046!!\n\n\tx % rm[i].sc = rm[i].fs\n\t\u3092\u307F\
    \u305F\u3059\u975E\u8CA0\u6574\u6570\u306E\u3046\u3061\u6700\u5C0F\u306E\u3082\
    \u306E%mod \u3092\u6C42\u3081\u308B\n\t0\u3092\u306E\u305E\u304F\u306A\u3089,\u5168\
    0\u306E\u3068\u304D\u306E\u307Fas[N-1]\u3092\u8FD4\u305B\u3070\u826F\u3044\n\t\
    \n\t!!! rm[i].sc,mod\u306Fpairwise relatively prime !!!\n\t\u7D20\u30D9\u30AD\u306B\
    \u5206\u89E3\u3059\u308B -> \u5404\u7D20\u6570\u3054\u3068\u306B\u77DB\u76FE\u3057\
    \u306A\u3044\u304B\u78BA\u304B\u3081\u308B -> garner\n\n\tbarcelona2017/5s/G.cpp\n\
    */\ntypedef long long ll;\ntypedef pair<ll,ll> P;\t\t//val,mod;\nll inv(ll a,ll\
    \ m){\n\tll b=m,u=1,v=0;\n\twhile(b){\n\t\tll t=a/b;\n\t\tswap(a-=t*b,b);\n\t\t\
    swap(u-=t*v,v);\n\t}\n\tu%=m;\n\tif(u<0) u+=m;\n\treturn u;\n}\n/*\n\trm \u306F\
    \ rem,mod\n\t\u6700\u5F8C\u306Bmod\u3092\u53D6\u308B\u5FC5\u8981\u304C\u7121\u3044\
    \u5834\u5408\u306F\u5F15\u6570\u7121\u3057\u3067\u547C\u3093\u3067\u3088\u3044\
    \n*/\nll garner(vector<P> rm,ll mod = -1){\n\trm.pb(P(0,mod));\n\tint N=rm.size();\n\
    \tvector<ll> as(N,1);\t\t//coefficients\n\tvector<ll> bs(N,0);\t\t//constants\n\
    \trep(i,N-1){\n\t\tll v=(rm[i].fs-bs[i])*inv(as[i],rm[i].sc)%rm[i].sc;\n\t\tif(v<0)\
    \ v+=rm[i].sc;\n\t\tfor(int j=i+1;j<N;j++){\n\t\t\tif(rm[j].sc != -1){\n\t\t\t\
    \t(bs[j]+=as[j]*v)%=rm[j].sc;\n\t\t\t\t(as[j]*=rm[i].sc)%=rm[j].sc;\n\t\t\t}else{\n\
    \t\t\t\tbs[j] += as[j]*v;\n\t\t\t\tas[j] *= rm[i].sc;\n\t\t\t}\n\t\t}\n\t}\n\t\
    return bs[N-1];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/garner.cpp
  requiredBy: []
  timestamp: '2020-12-16 01:47:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/garner.cpp
layout: document
redirect_from:
- /library/math/garner.cpp
- /library/math/garner.cpp.html
title: math/garner.cpp
---
