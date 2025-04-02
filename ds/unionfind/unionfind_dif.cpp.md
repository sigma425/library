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
  bundledCode: "#line 1 \"ds/unionfind/unionfind_dif.cpp\"\ntemplate<class D>\nstruct\
    \ UnionFindWithDiff{\n\tvector<int> par;\n\tvector<D> d;\n\n\tUnionFindWithDiff(){}\n\
    \tUnionFindWithDiff(int N):par(N),d(N){\n\t\tfor(int i=0;i<N;i++) par[i] = i;\n\
    \t}\n\n\tint find(int x){\n\t\tif(x == par[x]) return x;\n\t\tint r = find(par[x]);\n\
    \t\td[x] += d[par[x]];\n\t\treturn par[x] = r;\n\t}\n\t/*\n\t\tw[x] - w[y] = z\
    \ \u3068\u3044\u3046\u6761\u4EF6\u3092\u8FFD\u52A0\n\t\t\u7834\u7DBB\u3057\u305F\
    \u3089 false \u3092\u8FD4\u3059\n\t*/\n\tbool unite(int x, int y, D z){\n\t\t\
    int rx = find(x), ry = find(y);\n\t\tif(rx == ry){\n\t\t\tif(diff(x,y) != z) return\
    \ false;\n\t\t\treturn true;\n\t\t}\n\t\td[ry] = d[x] - d[y] - z;\n\t\tpar[ry]\
    \ = rx;\n\t\treturn true;\n\t}\n\t/*\n\t\tw[x] - w[y] \u3092\u8FD4\u3059\n\t\t\
    \u4E0D\u5B9A\u306E\u5834\u5408\u306F\u672A\u5B9A\u7FA9\u3001\u4E0D\u5B9A\u304B\
    \u3069\u3046\u304B\u306E\u5224\u5B9A\u304C\u5FC5\u8981\u306A\u3089 same \u3067\
    \u3057\u3066\u304A\u304F\n\t*/\n\tD diff(int x, int y){\n\t\tfind(x), find(y);\n\
    \t\treturn d[x] - d[y];\n\t}\n\tbool same(int x, int y) { return find(x)==find(y);\
    \ }\n};\n"
  code: "template<class D>\nstruct UnionFindWithDiff{\n\tvector<int> par;\n\tvector<D>\
    \ d;\n\n\tUnionFindWithDiff(){}\n\tUnionFindWithDiff(int N):par(N),d(N){\n\t\t\
    for(int i=0;i<N;i++) par[i] = i;\n\t}\n\n\tint find(int x){\n\t\tif(x == par[x])\
    \ return x;\n\t\tint r = find(par[x]);\n\t\td[x] += d[par[x]];\n\t\treturn par[x]\
    \ = r;\n\t}\n\t/*\n\t\tw[x] - w[y] = z \u3068\u3044\u3046\u6761\u4EF6\u3092\u8FFD\
    \u52A0\n\t\t\u7834\u7DBB\u3057\u305F\u3089 false \u3092\u8FD4\u3059\n\t*/\n\t\
    bool unite(int x, int y, D z){\n\t\tint rx = find(x), ry = find(y);\n\t\tif(rx\
    \ == ry){\n\t\t\tif(diff(x,y) != z) return false;\n\t\t\treturn true;\n\t\t}\n\
    \t\td[ry] = d[x] - d[y] - z;\n\t\tpar[ry] = rx;\n\t\treturn true;\n\t}\n\t/*\n\
    \t\tw[x] - w[y] \u3092\u8FD4\u3059\n\t\t\u4E0D\u5B9A\u306E\u5834\u5408\u306F\u672A\
    \u5B9A\u7FA9\u3001\u4E0D\u5B9A\u304B\u3069\u3046\u304B\u306E\u5224\u5B9A\u304C\
    \u5FC5\u8981\u306A\u3089 same \u3067\u3057\u3066\u304A\u304F\n\t*/\n\tD diff(int\
    \ x, int y){\n\t\tfind(x), find(y);\n\t\treturn d[x] - d[y];\n\t}\n\tbool same(int\
    \ x, int y) { return find(x)==find(y); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/unionfind/unionfind_dif.cpp
  requiredBy: []
  timestamp: '2025-04-03 01:56:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/unionfind/unionfind_dif.cpp
layout: document
redirect_from:
- /library/ds/unionfind/unionfind_dif.cpp
- /library/ds/unionfind/unionfind_dif.cpp.html
title: ds/unionfind/unionfind_dif.cpp
---
