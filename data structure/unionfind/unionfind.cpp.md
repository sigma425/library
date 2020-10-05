---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data structure/unionfind/unionfind.cpp\"\n/*\n\u305F\u3060\
    \u306Eunionfind\nverified by \u3044\u308D\u3093\u306A\u3068\u3053\u308D\n\u4ED8\
    \u52A0\u60C5\u5831\u3092\u6301\u3064\u3068\u304D\u306Bunite\u306Econtinue\u3092\
    \u5FD8\u308C\u306A\u3044\u3053\u3068\n*/\nstruct UnionFind{\n\tvector<int> par;\n\
    \tUnionFind(int N){\n\t\tpar.assign(N,0);\n\t\trep(i,N) par[i]=i;\n\t}\n\tint\
    \ find(int x){\n\t\tif(par[x]==x) return x;\n\t\treturn par[x]=find(par[x]);\n\
    \t}\n\tbool same(int x,int y){\n\t\treturn find(x)==find(y);\n\t}\n\tvoid unite(int\
    \ x,int y){\n\t\tx=find(x),y=find(y);\n\t\tif(x==y) return;\n\t\tpar[y]=x;\n\t\
    }\n};\nstruct UnionFind{\n\tvector<int> par,rank;\n\tUnionFind(int N){\n\t\tpar.assign(N,0);\n\
    \t\trank.assign(N,0);\n\t\trep(i,N) par[i]=i;\n\t}\n\tint find(int x){\n\t\tif(par[x]==x)\
    \ return x;\n\t\treturn par[x]=find(par[x]);\n\t}\n\tbool same(int x,int y){\n\
    \t\treturn find(x)==find(y);\n\t}\n\tvoid unite(int x,int y){\n\t\tx=find(x),y=find(y);\n\
    \t\tif(x==y) return;\n\t\tif(rank[x]<rank[y]) swap(x,y);\n\n\t\t//x becomes root\n\
    \t\tpar[y]=x;\n\t\tif(rank[x]==rank[y]) rank[x]++;\n\t}\n};\n"
  code: "/*\n\u305F\u3060\u306Eunionfind\nverified by \u3044\u308D\u3093\u306A\u3068\
    \u3053\u308D\n\u4ED8\u52A0\u60C5\u5831\u3092\u6301\u3064\u3068\u304D\u306Bunite\u306E\
    continue\u3092\u5FD8\u308C\u306A\u3044\u3053\u3068\n*/\nstruct UnionFind{\n\t\
    vector<int> par;\n\tUnionFind(int N){\n\t\tpar.assign(N,0);\n\t\trep(i,N) par[i]=i;\n\
    \t}\n\tint find(int x){\n\t\tif(par[x]==x) return x;\n\t\treturn par[x]=find(par[x]);\n\
    \t}\n\tbool same(int x,int y){\n\t\treturn find(x)==find(y);\n\t}\n\tvoid unite(int\
    \ x,int y){\n\t\tx=find(x),y=find(y);\n\t\tif(x==y) return;\n\t\tpar[y]=x;\n\t\
    }\n};\nstruct UnionFind{\n\tvector<int> par,rank;\n\tUnionFind(int N){\n\t\tpar.assign(N,0);\n\
    \t\trank.assign(N,0);\n\t\trep(i,N) par[i]=i;\n\t}\n\tint find(int x){\n\t\tif(par[x]==x)\
    \ return x;\n\t\treturn par[x]=find(par[x]);\n\t}\n\tbool same(int x,int y){\n\
    \t\treturn find(x)==find(y);\n\t}\n\tvoid unite(int x,int y){\n\t\tx=find(x),y=find(y);\n\
    \t\tif(x==y) return;\n\t\tif(rank[x]<rank[y]) swap(x,y);\n\n\t\t//x becomes root\n\
    \t\tpar[y]=x;\n\t\tif(rank[x]==rank[y]) rank[x]++;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data structure/unionfind/unionfind.cpp
  requiredBy: []
  timestamp: '2017-11-27 15:40:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/unionfind/unionfind.cpp
layout: document
redirect_from:
- /library/data structure/unionfind/unionfind.cpp
- /library/data structure/unionfind/unionfind.cpp.html
title: data structure/unionfind/unionfind.cpp
---
