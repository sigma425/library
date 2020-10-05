---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geom/argsort.cpp\"\n/*\n\u30ED\u30D0\u30B9\u30C8\u306A\u504F\
    \u89D2\u30BD\u30FC\u30C8 (0,0)\u3092\u6E21\u3059\u306A\n(0,+)\u304C\u6700\u5C0F\
    ,\u540C\u3058\u89D2\u5EA6\u306F\u9069\u5F53\n\n\u4E8C\u5468\u3059\u308B\u306E\u304C\
    \u5FC5\u8981\u306A\u6642(ex.\u5404\u70B9\u304B\u3089180\u5EA6\u4EE5\u5185\u306E\
    \u70B9\u3092\u63A2\u3059)\u3068\u304B\u306F\u304B\u306A\u308A\u9762\u5012\u306A\
    \u6C17\u304C\u3059\u308B\n\u4E8C\u9031\u76EE\u3067\u3059\u304B?\u3063\u3066\u3044\
    \u3046bool\u3092\u3082\u3063\u3066,pair<P,bool>\u306B\u3057\u3066\u3001sho\u306E\
    \u8FD4\u308A\u5024\u30920~7\u306B\u3059\u308B\n+pi \u3068\u304B\u3082\u3061\u3087\
    \u3063\u3068\u9762\u5012\u306A\u305F\u3081\u3001\u666E\u901A\u306Bdouble\u3067\
    \u3084\u3063\u3066\u3082\u826F\u3055\u305D\u3046\n\u3061\u306A\u307F\u306B\u308F\
    \u3056\u308F\u30560~2pi\u306B\u3059\u308B\u3053\u3068\u306F\u306A\u304F\u3066\u3001\
    atan2(y,x)\u306E\u8FD4\u308A\u5024-pi~pi\u3092\u76F4\u63A5\u4F7F\u3046\u307B\u3046\
    \u304C\u697D\u305D\u3046\n\n*/\ninline int sho(P p){\n\tint x=p.fs,y=p.sc;\n\t\
    if(x>0&&y>=0) return 0;\n\tif(x<=0&&y>0) return 1;\n\tif(x<0&&y<=0) return 2;\n\
    \tif(x>=0&&y<0) return 3;\n\tassert(false);\n}\nbool comp(P p,P q){\n\tint s=sho(p),t=sho(q);\n\
    \tif(s!=t) return s<t;\n\tll a=p.fs,b=p.sc,c=q.fs,d=q.sc;\n\treturn b*c<a*d;\n\
    }\n"
  code: "/*\n\u30ED\u30D0\u30B9\u30C8\u306A\u504F\u89D2\u30BD\u30FC\u30C8 (0,0)\u3092\
    \u6E21\u3059\u306A\n(0,+)\u304C\u6700\u5C0F,\u540C\u3058\u89D2\u5EA6\u306F\u9069\
    \u5F53\n\n\u4E8C\u5468\u3059\u308B\u306E\u304C\u5FC5\u8981\u306A\u6642(ex.\u5404\
    \u70B9\u304B\u3089180\u5EA6\u4EE5\u5185\u306E\u70B9\u3092\u63A2\u3059)\u3068\u304B\
    \u306F\u304B\u306A\u308A\u9762\u5012\u306A\u6C17\u304C\u3059\u308B\n\u4E8C\u9031\
    \u76EE\u3067\u3059\u304B?\u3063\u3066\u3044\u3046bool\u3092\u3082\u3063\u3066\
    ,pair<P,bool>\u306B\u3057\u3066\u3001sho\u306E\u8FD4\u308A\u5024\u30920~7\u306B\
    \u3059\u308B\n+pi \u3068\u304B\u3082\u3061\u3087\u3063\u3068\u9762\u5012\u306A\
    \u305F\u3081\u3001\u666E\u901A\u306Bdouble\u3067\u3084\u3063\u3066\u3082\u826F\
    \u3055\u305D\u3046\n\u3061\u306A\u307F\u306B\u308F\u3056\u308F\u30560~2pi\u306B\
    \u3059\u308B\u3053\u3068\u306F\u306A\u304F\u3066\u3001atan2(y,x)\u306E\u8FD4\u308A\
    \u5024-pi~pi\u3092\u76F4\u63A5\u4F7F\u3046\u307B\u3046\u304C\u697D\u305D\u3046\
    \n\n*/\ninline int sho(P p){\n\tint x=p.fs,y=p.sc;\n\tif(x>0&&y>=0) return 0;\n\
    \tif(x<=0&&y>0) return 1;\n\tif(x<0&&y<=0) return 2;\n\tif(x>=0&&y<0) return 3;\n\
    \tassert(false);\n}\nbool comp(P p,P q){\n\tint s=sho(p),t=sho(q);\n\tif(s!=t)\
    \ return s<t;\n\tll a=p.fs,b=p.sc,c=q.fs,d=q.sc;\n\treturn b*c<a*d;\n}"
  dependsOn: []
  isVerificationFile: false
  path: geom/argsort.cpp
  requiredBy: []
  timestamp: '2018-09-18 03:14:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geom/argsort.cpp
layout: document
redirect_from:
- /library/geom/argsort.cpp
- /library/geom/argsort.cpp.html
title: geom/argsort.cpp
---
