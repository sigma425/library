---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/cf17-final/tasks/cf17_final_j
  bundledCode: "#line 1 \"graph/voronoi_coloring.cpp\"\n/*\n\t\u8DDD\u96E2\u7A7A\u9593\
    \u4E0A\u306E\u70B9\u96C6\u5408\u304C\u4E0E\u3048\u3089\u308C\u305F\u6642\u306B\
    \u3001MST\n\t\u3053\u308C\u306F\u30DC\u30ED\u30CE\u30A4\u56F3\u3092\u4F5C\u3063\
    \u3066\u63A5\u3057\u3066\u308B\u8272\u3069\u3046\u3057\u306B\u98F2\u307F\u7DE8\
    \u3092\u5857\u308C\u3070\u826F\u3044\n\t\u305D\u306E\u305F\u3081\u306B\u3001\u591A\
    \u70B9\u30B9\u30BF\u30FC\u30C8\u306Edijkstra(\u3069\u306E\u70B9\u304B\u3089\u6765\
    \u305F\u304B\u3082\u6301\u3064)\u3092\u3057\u3066\u3001\u3053\u306E\u5834\u6240\
    \uFF08\u9802\u70B9\u3068\u306F\u9650\u3089\u306A\u3044\uFF09\u3067\u306F\u3069\
    \u306E\u8272\u3069\u3046\u3057\u304C\u63A5\u3057\u3066\u308B\u304B\u307F\u305F\
    \u3044\u306A\u306E\u3092\u6301\u3064\n\tTree MST, Water Bottle, \u899A\u3048\u3066\
    \u306A\u3044\u3051\u3069Snukezavodsk\u304B\u306A\u3093\u304B\u306E2^20\u72B6\u614B\
    \u306E\u3084\u3064 \u306A\u3069\u306F\u3053\u306E\u67A0\u7D44\u307F\u3067\u8003\
    \u3048\u3089\u308C\u308B\n\t\u3053\u306E\u5B9F\u88C5\u304C\u4F7F\u3048\u308B\u3068\
    \u306F\u9650\u3089\u306A\u3044\u3051\u3069\n\n\tinitial_color: \u305D\u306E\u9802\
    \u70B9\u304B\u3089\u51FA\u3066\u304F\u308B\u8272\u3001\u3064\u3044\u3066\u306A\
    \u3044\u306A\u3089-1\n\tpair<\u8DDD\u96E2vec,\u8272vec> \u3092\u8FD4\u3059\n\t\
    \n\tverified: https://atcoder.jp/contests/cf17-final/tasks/cf17_final_j\n*/\n\
    template<class D>\npair<vector<D>,vector<int>> dijkstra_coloring(const vector<vector<pair<int,D>>>&\
    \ G, V<int> initial_color){\t//G:(v,cost)\n\tusing P = pair<D,int>;\n\tpriority_queue<P,vector<P>,greater<P>\
    \ > que;\n\tint N = G.size();\n\n\tD inf = 1e18;\n\tvector<D> d(N,inf);\n\tV<int>\
    \ col(N,-1);;\n\trep(v,N) if(initial_color[v] != -1){\n\t\td[v] = 0;\n\t\tque.push(P(0,v));\n\
    \t\tcol[v] = initial_color[v];\n\t}\n\n\twhile(!que.empty()){\n\t\tP p = que.top();\
    \ que.pop();\n\t\tint v = p.sc;\n\t\tD c = p.fs;\n\t\tif(d[v]!=c) continue;\n\t\
    \tfor(auto p:G[v]){\n\t\t\tint to=p.fs;\n\t\t\tif(d[to]>d[v]+p.sc){\n\t\t\t\t\
    d[to]=d[v]+p.sc;\n\t\t\t\tque.push(P(d[to],to));\n\t\t\t\tcol[to] = col[v];\n\t\
    \t\t}\n\t\t}\n\t}\n\n\treturn make_pair(d,col);\n}\n"
  code: "/*\n\t\u8DDD\u96E2\u7A7A\u9593\u4E0A\u306E\u70B9\u96C6\u5408\u304C\u4E0E\u3048\
    \u3089\u308C\u305F\u6642\u306B\u3001MST\n\t\u3053\u308C\u306F\u30DC\u30ED\u30CE\
    \u30A4\u56F3\u3092\u4F5C\u3063\u3066\u63A5\u3057\u3066\u308B\u8272\u3069\u3046\
    \u3057\u306B\u98F2\u307F\u7DE8\u3092\u5857\u308C\u3070\u826F\u3044\n\t\u305D\u306E\
    \u305F\u3081\u306B\u3001\u591A\u70B9\u30B9\u30BF\u30FC\u30C8\u306Edijkstra(\u3069\
    \u306E\u70B9\u304B\u3089\u6765\u305F\u304B\u3082\u6301\u3064)\u3092\u3057\u3066\
    \u3001\u3053\u306E\u5834\u6240\uFF08\u9802\u70B9\u3068\u306F\u9650\u3089\u306A\
    \u3044\uFF09\u3067\u306F\u3069\u306E\u8272\u3069\u3046\u3057\u304C\u63A5\u3057\
    \u3066\u308B\u304B\u307F\u305F\u3044\u306A\u306E\u3092\u6301\u3064\n\tTree MST,\
    \ Water Bottle, \u899A\u3048\u3066\u306A\u3044\u3051\u3069Snukezavodsk\u304B\u306A\
    \u3093\u304B\u306E2^20\u72B6\u614B\u306E\u3084\u3064 \u306A\u3069\u306F\u3053\u306E\
    \u67A0\u7D44\u307F\u3067\u8003\u3048\u3089\u308C\u308B\n\t\u3053\u306E\u5B9F\u88C5\
    \u304C\u4F7F\u3048\u308B\u3068\u306F\u9650\u3089\u306A\u3044\u3051\u3069\n\n\t\
    initial_color: \u305D\u306E\u9802\u70B9\u304B\u3089\u51FA\u3066\u304F\u308B\u8272\
    \u3001\u3064\u3044\u3066\u306A\u3044\u306A\u3089-1\n\tpair<\u8DDD\u96E2vec,\u8272\
    vec> \u3092\u8FD4\u3059\n\t\n\tverified: https://atcoder.jp/contests/cf17-final/tasks/cf17_final_j\n\
    */\ntemplate<class D>\npair<vector<D>,vector<int>> dijkstra_coloring(const vector<vector<pair<int,D>>>&\
    \ G, V<int> initial_color){\t//G:(v,cost)\n\tusing P = pair<D,int>;\n\tpriority_queue<P,vector<P>,greater<P>\
    \ > que;\n\tint N = G.size();\n\n\tD inf = 1e18;\n\tvector<D> d(N,inf);\n\tV<int>\
    \ col(N,-1);;\n\trep(v,N) if(initial_color[v] != -1){\n\t\td[v] = 0;\n\t\tque.push(P(0,v));\n\
    \t\tcol[v] = initial_color[v];\n\t}\n\n\twhile(!que.empty()){\n\t\tP p = que.top();\
    \ que.pop();\n\t\tint v = p.sc;\n\t\tD c = p.fs;\n\t\tif(d[v]!=c) continue;\n\t\
    \tfor(auto p:G[v]){\n\t\t\tint to=p.fs;\n\t\t\tif(d[to]>d[v]+p.sc){\n\t\t\t\t\
    d[to]=d[v]+p.sc;\n\t\t\t\tque.push(P(d[to],to));\n\t\t\t\tcol[to] = col[v];\n\t\
    \t\t}\n\t\t}\n\t}\n\n\treturn make_pair(d,col);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/voronoi_coloring.cpp
  requiredBy: []
  timestamp: '2020-11-30 23:03:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/voronoi_coloring.cpp
layout: document
redirect_from:
- /library/graph/voronoi_coloring.cpp
- /library/graph/voronoi_coloring.cpp.html
title: graph/voronoi_coloring.cpp
---
