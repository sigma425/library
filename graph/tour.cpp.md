---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://gist.github.com/snuke/df5d66a2adb575228c96
  bundledCode: "#line 1 \"graph/tour.cpp\"\n/*\nhttps://gist.github.com/snuke/df5d66a2adb575228c96\n\
    \nA\u3068B\u306F\u5FC5\u305A\u540C\u3058\u30B5\u30A4\u30AF\u30EB\u306B\u542B\u307E\
    \u308C\u308B \u3067\u5206\u89E3\u3057\u305F\u3082\u306E \u3061\u3083\u3093\u3068\
    \u540C\u5024\u95A2\u4FC2\u306B\u306A\u3063\u3066\u3044\u308B\nA\u3092\u53D6\u308A\
    \u9664\u304F\u3068B\u304C\u6A4B \u3068\u540C\u5024\n\u6A4B\u691C\u51FA\u306E\u969B\
    \u306Eimos\u6CD5\u3063\u307D\u3044\u3053\u3068\u3092\u3084\u308B\u3068\u304D\u306B\
    \u3001\u8DB3\u3059\u5024\u3092\u4E71\u6570\u306B\u3057\u3066\u3001\u305D\u308C\
    \u304C\u4E00\u81F4\u3059\u308B\u3082\u306E\u304C\u540C\u3058\u30B0\u30EB\u30FC\
    \u30D7\nll\u3060\u3068\u5371\u967A\u305D\u3046?\n*/\n\nunsigned long long seed\
    \ = 1145141919810893ULL;\nunsigned long long xor_rand(){\n  seed = seed ^ (seed<<13);\n\
    \  seed = seed ^ (seed>>7);\n  seed = seed ^ (seed<<17);\n  return seed;\n}\n\n\
    \nclass ToursDecomposition {\n public:\n  struct Edge {\n    int u, v;\n    Edge()\
    \ {}\n    Edge(int u, int v) : u(u), v(v) {}\n  };\n  int n;\n  vector< vector<int>\
    \ > to;\n  vector<int> depth;\n  using ull = unsigned long long;\n  vector<ull>\
    \ hash;\n  map< ull, vector<Edge> > group;\n  ToursDecomposition() {}\n  ToursDecomposition(int\
    \ n) : n(n), to(n), depth(n, -1), hash(n) {}\n  void AddEdge(int u, int v) {\n\
    \    to[u].push_back(v);\n    to[v].push_back(u);\n  }\n  void Init() {\n    rep(i,n)\
    \ {\n      if (depth[i] != -1) continue;\n      depth[i] = 0;\n      dfs(i, -1);\n\
    \    }\n  }\n private:\n  void dfs(int v, int p) {\n    for (int u : to[v]) {\n\
    \      if (depth[u] == -1) {\n        depth[u] = depth[v] + 1;\n        dfs(u,\
    \ v);\n        hash[v] += hash[u];\n        group[hash[u]].push_back(Edge(u, v));\n\
    \      } else if (depth[u] < depth[v] && u != p) {\n        ull r = xor_rand();\n\
    \        group[r].push_back(Edge(u, v));\n        hash[v] += r;\n        hash[u]\
    \ -= r;\n      }\n    }\n  }\n};\n"
  code: "/*\nhttps://gist.github.com/snuke/df5d66a2adb575228c96\n\nA\u3068B\u306F\u5FC5\
    \u305A\u540C\u3058\u30B5\u30A4\u30AF\u30EB\u306B\u542B\u307E\u308C\u308B \u3067\
    \u5206\u89E3\u3057\u305F\u3082\u306E \u3061\u3083\u3093\u3068\u540C\u5024\u95A2\
    \u4FC2\u306B\u306A\u3063\u3066\u3044\u308B\nA\u3092\u53D6\u308A\u9664\u304F\u3068\
    B\u304C\u6A4B \u3068\u540C\u5024\n\u6A4B\u691C\u51FA\u306E\u969B\u306Eimos\u6CD5\
    \u3063\u307D\u3044\u3053\u3068\u3092\u3084\u308B\u3068\u304D\u306B\u3001\u8DB3\
    \u3059\u5024\u3092\u4E71\u6570\u306B\u3057\u3066\u3001\u305D\u308C\u304C\u4E00\
    \u81F4\u3059\u308B\u3082\u306E\u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\nll\u3060\
    \u3068\u5371\u967A\u305D\u3046?\n*/\n\nunsigned long long seed = 1145141919810893ULL;\n\
    unsigned long long xor_rand(){\n  seed = seed ^ (seed<<13);\n  seed = seed ^ (seed>>7);\n\
    \  seed = seed ^ (seed<<17);\n  return seed;\n}\n\n\nclass ToursDecomposition\
    \ {\n public:\n  struct Edge {\n    int u, v;\n    Edge() {}\n    Edge(int u,\
    \ int v) : u(u), v(v) {}\n  };\n  int n;\n  vector< vector<int> > to;\n  vector<int>\
    \ depth;\n  using ull = unsigned long long;\n  vector<ull> hash;\n  map< ull,\
    \ vector<Edge> > group;\n  ToursDecomposition() {}\n  ToursDecomposition(int n)\
    \ : n(n), to(n), depth(n, -1), hash(n) {}\n  void AddEdge(int u, int v) {\n  \
    \  to[u].push_back(v);\n    to[v].push_back(u);\n  }\n  void Init() {\n    rep(i,n)\
    \ {\n      if (depth[i] != -1) continue;\n      depth[i] = 0;\n      dfs(i, -1);\n\
    \    }\n  }\n private:\n  void dfs(int v, int p) {\n    for (int u : to[v]) {\n\
    \      if (depth[u] == -1) {\n        depth[u] = depth[v] + 1;\n        dfs(u,\
    \ v);\n        hash[v] += hash[u];\n        group[hash[u]].push_back(Edge(u, v));\n\
    \      } else if (depth[u] < depth[v] && u != p) {\n        ull r = xor_rand();\n\
    \        group[r].push_back(Edge(u, v));\n        hash[v] += r;\n        hash[u]\
    \ -= r;\n      }\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tour.cpp
  requiredBy: []
  timestamp: '2017-10-19 00:06:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tour.cpp
layout: document
redirect_from:
- /library/graph/tour.cpp
- /library/graph/tour.cpp.html
title: graph/tour.cpp
---
