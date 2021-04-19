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
  bundledCode: "#line 1 \"graph/dijkstra.cpp\"\n/*\n\tD \u306B\u3088\u3063\u3066inf\
    \ \u306E\u66F8\u304D\u63DB\u3048\n\tdouble \u306A\u3089 = \u307E\u308F\u308A\u3092\
    \u5909\u3048\u308B\n*/\ntemplate<class D>\nvector<D> dijkstra(const vector<vector<pair<int,D>>>&\
    \ G, int s = 0){\t//G:(v,cost)\n\tusing P = pair<D,int>;\n\tpriority_queue<P,vector<P>,greater<P>\
    \ > que;\n\tint N = G.size();\n\n\tD inf = 1e18;\n\tvector<D> d(N,inf);\n\td[s]\
    \ = 0;\n\tque.push(P(0,s));\n\n\twhile(!que.empty()){\n\t\tP p=que.top();\n\t\t\
    que.pop();\n\t\tint v = p.sc;\n\t\tD c = p.fs;\n\t\tif(d[v]!=c) continue;\n\t\t\
    for(auto p:G[v]){\n\t\t\tint to=p.fs;\n\t\t\tif(d[to]>d[v]+p.sc){\n\t\t\t\td[to]=d[v]+p.sc;\n\
    \t\t\t\tque.push(P(d[to],to));\n\t\t\t}\n\t\t}\n\t}\n\n\treturn d;\n}\n"
  code: "/*\n\tD \u306B\u3088\u3063\u3066inf \u306E\u66F8\u304D\u63DB\u3048\n\tdouble\
    \ \u306A\u3089 = \u307E\u308F\u308A\u3092\u5909\u3048\u308B\n*/\ntemplate<class\
    \ D>\nvector<D> dijkstra(const vector<vector<pair<int,D>>>& G, int s = 0){\t//G:(v,cost)\n\
    \tusing P = pair<D,int>;\n\tpriority_queue<P,vector<P>,greater<P> > que;\n\tint\
    \ N = G.size();\n\n\tD inf = 1e18;\n\tvector<D> d(N,inf);\n\td[s] = 0;\n\tque.push(P(0,s));\n\
    \n\twhile(!que.empty()){\n\t\tP p=que.top();\n\t\tque.pop();\n\t\tint v = p.sc;\n\
    \t\tD c = p.fs;\n\t\tif(d[v]!=c) continue;\n\t\tfor(auto p:G[v]){\n\t\t\tint to=p.fs;\n\
    \t\t\tif(d[to]>d[v]+p.sc){\n\t\t\t\td[to]=d[v]+p.sc;\n\t\t\t\tque.push(P(d[to],to));\n\
    \t\t\t}\n\t\t}\n\t}\n\n\treturn d;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.cpp
  requiredBy: []
  timestamp: '2017-07-04 20:23:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dijkstra.cpp
layout: document
redirect_from:
- /library/graph/dijkstra.cpp
- /library/graph/dijkstra.cpp.html
title: graph/dijkstra.cpp
---
