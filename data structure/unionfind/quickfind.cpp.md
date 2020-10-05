---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data structure/unionfind/quickfind.cpp\"\n/*\nquickfind\n\
    \u4F7F\u3046\u3053\u3068\u3042\u308B\u304B\u306A\u3042\nverified by \u3069\u3053\
    \u304B(\u5FD8\u308C\u305F\u3051\u3069\u4F55\u56DE\u304B\u4F7F\u3063\u3066\u308B\
    )\n*/\nstruct quickfind{\n\tvector<int> i2g;\n\tvector<vector<int> > g2i;\n\t\
    void init(int n){\n\t\ti2g.resize(n);\n\t\tg2i.resize(n);\n\t\trep(i,n){\n\t\t\
    \ti2g[i]=i;\n\t\t\tg2i[i].assign(1,i);\n\t\t}\n\t}\n\tvoid unite(int ia,int ib){\n\
    \t\tif(g2i[i2g[ia]].size() < g2i[i2g[ib]].size()) swap(ia,ib);\n\t\tint ga=i2g[ia],gb=i2g[ib];\n\
    \t\tfor(auto v:g2i[gb]) i2g[i]=ga;\n\t\tg2i[ga].insert(g2i[ga].end(),all(g2i[gb]));\n\
    \t}\n\tbool same(int ia,int ib){\n\t\treturn i2g[ia]==i2g[ib];\n\t}\n};\n"
  code: "/*\nquickfind\n\u4F7F\u3046\u3053\u3068\u3042\u308B\u304B\u306A\u3042\nverified\
    \ by \u3069\u3053\u304B(\u5FD8\u308C\u305F\u3051\u3069\u4F55\u56DE\u304B\u4F7F\
    \u3063\u3066\u308B)\n*/\nstruct quickfind{\n\tvector<int> i2g;\n\tvector<vector<int>\
    \ > g2i;\n\tvoid init(int n){\n\t\ti2g.resize(n);\n\t\tg2i.resize(n);\n\t\trep(i,n){\n\
    \t\t\ti2g[i]=i;\n\t\t\tg2i[i].assign(1,i);\n\t\t}\n\t}\n\tvoid unite(int ia,int\
    \ ib){\n\t\tif(g2i[i2g[ia]].size() < g2i[i2g[ib]].size()) swap(ia,ib);\n\t\tint\
    \ ga=i2g[ia],gb=i2g[ib];\n\t\tfor(auto v:g2i[gb]) i2g[i]=ga;\n\t\tg2i[ga].insert(g2i[ga].end(),all(g2i[gb]));\n\
    \t}\n\tbool same(int ia,int ib){\n\t\treturn i2g[ia]==i2g[ib];\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data structure/unionfind/quickfind.cpp
  requiredBy: []
  timestamp: '2016-12-08 00:51:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/unionfind/quickfind.cpp
layout: document
redirect_from:
- /library/data structure/unionfind/quickfind.cpp
- /library/data structure/unionfind/quickfind.cpp.html
title: data structure/unionfind/quickfind.cpp
---
