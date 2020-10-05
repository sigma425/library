---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/MinimalCycle.cpp\"\n/*\r\n    minimal \u306A ( <=>\
    \ induced graph \u3082 cycle, chordless?) cycle \u3092\u4E00\u3064\u8FD4\u3059\
    \u3001\u306A\u3051\u308C\u3070 {}\r\n    Undirected / Directed\r\n    O(V+E)\r\
    \n    verified\r\n        Undirected : CF594 F\r\n        Directed : ABC142 F\
    \ (\u3067\u3082\u3001\u5618(Down1\u500B)\u304C\u901A\u3063\u305F\u306E\u3067\u307E\
    \u3068\u3082\u306Averify\u3067\u306F\u306A\u3044\u30FB\u30FB\u30FB)\r\n\r\n  \
    \  undirected \u306A\u3089 dfs tree \u306E Up \u306E\u3046\u3061\u6700\u77ED\u3092\
    \u53D6\u308C\u3070\u304A\u308F\u308A\r\n    directed \u306A\u3089\u305D\u306E\u30B5\
    \u30A4\u30AF\u30EB\u5185\u3067 Down \u3092\u4F7F\u3044\u307E\u304F\u308B\u5FC5\
    \u8981\u304C\u3042\u3063\u3066\u3001\u305D\u306E\u9802\u70B9\u304B\u3089\u8CAA\
    \u6B32\u306B\u6700\u9577\u3092\u53D6\u308C\u3070\u3044\u3044\r\n*/\r\nV<int> getMinimalCycleUndirected(const\
    \ VV<int>& G){\r\n\tusing P = pair<int,int>;\r\n\tint N = G.size();\r\n\tV<int>\
    \ vis(N);\t//0:yet 1:now 2:done\r\n\tV<int> par(N,-1);\r\n\tV<int> d(N);\r\n\r\
    \n\tP U(-1,-1);\t// min distance backward edge\r\n\r\n\tfunction<void(int,int)>\
    \ dfs = [&](int v,int p){\r\n\t\tvis[v] = 1;\r\n\t\tfor(int u: G[v]) if(u != p){\r\
    \n\t\t\tif(vis[u] == 0){\t// dfs edge\r\n\t\t\t\tpar[u] = v;\r\n\t\t\t\td[u] =\
    \ d[v]+1;\r\n\t\t\t\tdfs(u,v);\r\n\t\t\t}else if(vis[u] == 1){\t// up\r\n\t\t\t\
    \tif(U.fs == -1 || d[U.fs] - d[U.sc] > d[v] - d[u]){\r\n\t\t\t\t\tU = P(v,u);\r\
    \n\t\t\t\t}\r\n\t\t\t}else{}\t// down\r\n\t\t}\r\n\t\tvis[v] = 2;\r\n\t};\r\n\t\
    rep(v,N) if(vis[v] == 0){\r\n\t\tdfs(v,-1);\r\n\t}\r\n\tif(U.fs == -1) return\
    \ {};\r\n\tV<int> c;\r\n\t{\r\n\t\tint v = U.fs;\r\n\t\twhile(true){\r\n\t\t\t\
    c.pb(v);\r\n\t\t\tif(v == U.sc) break;\r\n\t\t\tv = par[v];\r\n\t\t}\r\n\t}\r\n\
    \treturn c;\r\n}\r\n\r\nV<int> getMinimalCycleDirected(const VV<int>& G){\r\n\t\
    using P = pair<int,int>;\r\n\tint N = G.size();\r\n\tV<int> vis(N);\t//0:yet 1:now\
    \ 2:done\r\n\tV<int> par(N,-1);\r\n\tV<int> d(N);\r\n\r\n\tP U(-1,-1);\t// min\
    \ distance backward edge\r\n\r\n\tfunction<void(int)> dfs = [&](int v){\r\n\t\t\
    vis[v] = 1;\r\n\t\tfor(int u: G[v]){\r\n\t\t\tif(vis[u] == 0){\t// dfs edge\r\n\
    \t\t\t\tpar[u] = v;\r\n\t\t\t\td[u] = d[v]+1;\r\n\t\t\t\tdfs(u);\r\n\t\t\t}else\
    \ if(vis[u] == 1){\t// up\r\n\t\t\t\tif(U.fs == -1 || d[U.fs] - d[U.sc] > d[v]\
    \ - d[u]){\r\n\t\t\t\t\tU = P(v,u);\r\n\t\t\t\t}\r\n\t\t\t}else{}\t// left, down\r\
    \n\t\t}\r\n\t\tvis[v] = 2;\r\n\t};\r\n\trep(v,N) if(vis[v] == 0){\r\n\t\tdfs(v);\r\
    \n\t}\r\n\tif(U.fs == -1) return {};\r\n\tV<bool> in_cycle(N);\r\n\tV<int> c;\r\
    \n\t{\r\n\t\tint v = U.fs;\r\n\t\twhile(true){\r\n\t\t\tc.pb(v); in_cycle[v] =\
    \ true;\r\n\t\t\tif(v == U.sc) break;\r\n\t\t\tv = par[v];\r\n\t\t}\r\n\t}\r\n\
    \treverse(all(c));\r\n\tV<int> nc;\r\n\t{\r\n\t\tint v = c[0];\r\n\t\twhile(true){\r\
    \n\t\t\tnc.pb(v);\r\n\t\t\tif(v == c.back()) break;\r\n\t\t\tint nxt = v;\r\n\t\
    \t\tfor(int u: G[v]) if(in_cycle[u] && d[u] > d[nxt]) nxt = u;\r\n\t\t\tv = nxt;\r\
    \n\t\t}\r\n\t}\r\n\treturn nc;\r\n}\r\n"
  code: "/*\r\n    minimal \u306A ( <=> induced graph \u3082 cycle, chordless?) cycle\
    \ \u3092\u4E00\u3064\u8FD4\u3059\u3001\u306A\u3051\u308C\u3070 {}\r\n    Undirected\
    \ / Directed\r\n    O(V+E)\r\n    verified\r\n        Undirected : CF594 F\r\n\
    \        Directed : ABC142 F (\u3067\u3082\u3001\u5618(Down1\u500B)\u304C\u901A\
    \u3063\u305F\u306E\u3067\u307E\u3068\u3082\u306Averify\u3067\u306F\u306A\u3044\
    \u30FB\u30FB\u30FB)\r\n\r\n    undirected \u306A\u3089 dfs tree \u306E Up \u306E\
    \u3046\u3061\u6700\u77ED\u3092\u53D6\u308C\u3070\u304A\u308F\u308A\r\n    directed\
    \ \u306A\u3089\u305D\u306E\u30B5\u30A4\u30AF\u30EB\u5185\u3067 Down \u3092\u4F7F\
    \u3044\u307E\u304F\u308B\u5FC5\u8981\u304C\u3042\u3063\u3066\u3001\u305D\u306E\
    \u9802\u70B9\u304B\u3089\u8CAA\u6B32\u306B\u6700\u9577\u3092\u53D6\u308C\u3070\
    \u3044\u3044\r\n*/\r\nV<int> getMinimalCycleUndirected(const VV<int>& G){\r\n\t\
    using P = pair<int,int>;\r\n\tint N = G.size();\r\n\tV<int> vis(N);\t//0:yet 1:now\
    \ 2:done\r\n\tV<int> par(N,-1);\r\n\tV<int> d(N);\r\n\r\n\tP U(-1,-1);\t// min\
    \ distance backward edge\r\n\r\n\tfunction<void(int,int)> dfs = [&](int v,int\
    \ p){\r\n\t\tvis[v] = 1;\r\n\t\tfor(int u: G[v]) if(u != p){\r\n\t\t\tif(vis[u]\
    \ == 0){\t// dfs edge\r\n\t\t\t\tpar[u] = v;\r\n\t\t\t\td[u] = d[v]+1;\r\n\t\t\
    \t\tdfs(u,v);\r\n\t\t\t}else if(vis[u] == 1){\t// up\r\n\t\t\t\tif(U.fs == -1\
    \ || d[U.fs] - d[U.sc] > d[v] - d[u]){\r\n\t\t\t\t\tU = P(v,u);\r\n\t\t\t\t}\r\
    \n\t\t\t}else{}\t// down\r\n\t\t}\r\n\t\tvis[v] = 2;\r\n\t};\r\n\trep(v,N) if(vis[v]\
    \ == 0){\r\n\t\tdfs(v,-1);\r\n\t}\r\n\tif(U.fs == -1) return {};\r\n\tV<int> c;\r\
    \n\t{\r\n\t\tint v = U.fs;\r\n\t\twhile(true){\r\n\t\t\tc.pb(v);\r\n\t\t\tif(v\
    \ == U.sc) break;\r\n\t\t\tv = par[v];\r\n\t\t}\r\n\t}\r\n\treturn c;\r\n}\r\n\
    \r\nV<int> getMinimalCycleDirected(const VV<int>& G){\r\n\tusing P = pair<int,int>;\r\
    \n\tint N = G.size();\r\n\tV<int> vis(N);\t//0:yet 1:now 2:done\r\n\tV<int> par(N,-1);\r\
    \n\tV<int> d(N);\r\n\r\n\tP U(-1,-1);\t// min distance backward edge\r\n\r\n\t\
    function<void(int)> dfs = [&](int v){\r\n\t\tvis[v] = 1;\r\n\t\tfor(int u: G[v]){\r\
    \n\t\t\tif(vis[u] == 0){\t// dfs edge\r\n\t\t\t\tpar[u] = v;\r\n\t\t\t\td[u] =\
    \ d[v]+1;\r\n\t\t\t\tdfs(u);\r\n\t\t\t}else if(vis[u] == 1){\t// up\r\n\t\t\t\t\
    if(U.fs == -1 || d[U.fs] - d[U.sc] > d[v] - d[u]){\r\n\t\t\t\t\tU = P(v,u);\r\n\
    \t\t\t\t}\r\n\t\t\t}else{}\t// left, down\r\n\t\t}\r\n\t\tvis[v] = 2;\r\n\t};\r\
    \n\trep(v,N) if(vis[v] == 0){\r\n\t\tdfs(v);\r\n\t}\r\n\tif(U.fs == -1) return\
    \ {};\r\n\tV<bool> in_cycle(N);\r\n\tV<int> c;\r\n\t{\r\n\t\tint v = U.fs;\r\n\
    \t\twhile(true){\r\n\t\t\tc.pb(v); in_cycle[v] = true;\r\n\t\t\tif(v == U.sc)\
    \ break;\r\n\t\t\tv = par[v];\r\n\t\t}\r\n\t}\r\n\treverse(all(c));\r\n\tV<int>\
    \ nc;\r\n\t{\r\n\t\tint v = c[0];\r\n\t\twhile(true){\r\n\t\t\tnc.pb(v);\r\n\t\
    \t\tif(v == c.back()) break;\r\n\t\t\tint nxt = v;\r\n\t\t\tfor(int u: G[v]) if(in_cycle[u]\
    \ && d[u] > d[nxt]) nxt = u;\r\n\t\t\tv = nxt;\r\n\t\t}\r\n\t}\r\n\treturn nc;\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/MinimalCycle.cpp
  requiredBy: []
  timestamp: '2019-10-24 04:12:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/MinimalCycle.cpp
layout: document
redirect_from:
- /library/graph/MinimalCycle.cpp
- /library/graph/MinimalCycle.cpp.html
title: graph/MinimalCycle.cpp
---
