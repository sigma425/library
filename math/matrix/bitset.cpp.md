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
  bundledCode: "#line 1 \"math/matrix/bitset.cpp\"\n/*\n\tx[a][b]= (can go from a\
    \ to b ?) \u306E\u304B\u3051\u3056\u3093\n\tbitset\u306F\u3084\u3044\n\t\u3061\
    \u3087\u3046\u3069N\u53D6\u308B\u306E\u306F\u7121\u7406\u306A\u306E\u3067\u6CE8\
    \u610F(\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u5F15\u6570\u306A\u306E\u3067const\u3058\
    \u3083\u306A\u3044\u3068\u30C0\u30E1)\n\t\u3042\u3068swap\u304C\u51FA\u6765\u306A\
    \u3044(12\u884C\u76EE\u306E\u3068\u3053)\n*/\nconst int MAX_N=;\ntypedef bitset<MAX_N>\
    \ Bs;\ntypedef array<Bs,MAX_N> mat;\nmat pro(mat x,mat y,int N){\n\trep(i,N) rep(j,i){\n\
    \t\tbool tmp=y[i][j];\n\t\ty[i][j]=y[j][i];\n\t\ty[j][i]=tmp;\n\t}\n\tmat z;\n\
    \trep(i,N) rep(j,N) z[i][j]=(x[i]&y[j]).any();\n\treturn z;\n}\n"
  code: "/*\n\tx[a][b]= (can go from a to b ?) \u306E\u304B\u3051\u3056\u3093\n\t\
    bitset\u306F\u3084\u3044\n\t\u3061\u3087\u3046\u3069N\u53D6\u308B\u306E\u306F\u7121\
    \u7406\u306A\u306E\u3067\u6CE8\u610F(\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u5F15\
    \u6570\u306A\u306E\u3067const\u3058\u3083\u306A\u3044\u3068\u30C0\u30E1)\n\t\u3042\
    \u3068swap\u304C\u51FA\u6765\u306A\u3044(12\u884C\u76EE\u306E\u3068\u3053)\n*/\n\
    const int MAX_N=;\ntypedef bitset<MAX_N> Bs;\ntypedef array<Bs,MAX_N> mat;\nmat\
    \ pro(mat x,mat y,int N){\n\trep(i,N) rep(j,i){\n\t\tbool tmp=y[i][j];\n\t\ty[i][j]=y[j][i];\n\
    \t\ty[j][i]=tmp;\n\t}\n\tmat z;\n\trep(i,N) rep(j,N) z[i][j]=(x[i]&y[j]).any();\n\
    \treturn z;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/bitset.cpp
  requiredBy: []
  timestamp: '2018-09-18 03:14:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix/bitset.cpp
layout: document
redirect_from:
- /library/math/matrix/bitset.cpp
- /library/math/matrix/bitset.cpp.html
title: math/matrix/bitset.cpp
---
