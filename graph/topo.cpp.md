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
  bundledCode: "#line 1 \"graph/topo.cpp\"\n/*\nself loop\u3082 not dag\nvis\u3092\
    0\u3067\u521D\u671F\u5316\u3057\u3066,G\u3092\u4F5C\u3063\u3066\u3001maketopo(\u9802\
    \u70B9\u6570)\u3059\u308B\u3068\ntopo[i]=i\u756A\u76EE\u306E\u9802\u70B9 \u306B\
    \u306A\u308B\n*/\n\nconst int MAX_V=;\nint vis[MAX_V];\t\t//0->yet,1->now,2->done\n\
    vector<int> topo;\nvector<int> G[MAX_V];\nbool visit(int v){\n\tif(vis[v]==2)\
    \ return 1;\n\tif(vis[v]==1) return 0;\n\tvis[v]=1;\n\tfor(int u:G[v]) if(!visit(u))\
    \ return 0;\n\tvis[v]=2;\n\ttopo.pb(v);\n\treturn 1;\n}\nbool maketopo(int V){\n\
    \trep(i,V) if(!visit(i)) return 0;\n\treverse(all(topo));\n\treturn 1;\n}\n"
  code: "/*\nself loop\u3082 not dag\nvis\u30920\u3067\u521D\u671F\u5316\u3057\u3066\
    ,G\u3092\u4F5C\u3063\u3066\u3001maketopo(\u9802\u70B9\u6570)\u3059\u308B\u3068\
    \ntopo[i]=i\u756A\u76EE\u306E\u9802\u70B9 \u306B\u306A\u308B\n*/\n\nconst int\
    \ MAX_V=;\nint vis[MAX_V];\t\t//0->yet,1->now,2->done\nvector<int> topo;\nvector<int>\
    \ G[MAX_V];\nbool visit(int v){\n\tif(vis[v]==2) return 1;\n\tif(vis[v]==1) return\
    \ 0;\n\tvis[v]=1;\n\tfor(int u:G[v]) if(!visit(u)) return 0;\n\tvis[v]=2;\n\t\
    topo.pb(v);\n\treturn 1;\n}\nbool maketopo(int V){\n\trep(i,V) if(!visit(i)) return\
    \ 0;\n\treverse(all(topo));\n\treturn 1;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/topo.cpp
  requiredBy: []
  timestamp: '2016-12-08 00:51:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/topo.cpp
layout: document
redirect_from:
- /library/graph/topo.cpp
- /library/graph/topo.cpp.html
title: graph/topo.cpp
---
