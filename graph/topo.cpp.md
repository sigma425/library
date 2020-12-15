---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/topo.cpp\"\n/*\nself loop\u3082 not dag\nvis\u3092\
    0\u3067\u521D\u671F\u5316\u3057\u3066,G\u3092\u4F5C\u3063\u3066\u3001maketopo(\u9802\
    \u70B9\u6570)\u3059\u308B\u3068\ntopo[i]=i\u756A\u76EE\u306E\u9802\u70B9 \u306B\
    \u306A\u308B\n*/\n\nbool visit(int v,const vector<vector<int>>& G, vector<int>&\
    \ topo, vector<int>& vis){\n\tif(vis[v]==2) return 1;\n\tif(vis[v]==1) return\
    \ 0;\n\tvis[v]=1;\n\tfor(int u:G[v]) if(!visit(u,G,topo,vis)) return 0;\n\tvis[v]=2;\n\
    \ttopo.pb(v);\n\treturn 1;\n}\nvector<int> maketopo(const vector<vector<int>>&\
    \ G){\n\tint N = G.size();\n\tvector<int> topo;\n\tvector<int> vis(N);\n\trep(i,N)\
    \ if(!visit(i,G,topo,vis)) return {};\n\treverse(all(topo));\n\treturn topo;\n\
    }\n"
  code: "/*\nself loop\u3082 not dag\nvis\u30920\u3067\u521D\u671F\u5316\u3057\u3066\
    ,G\u3092\u4F5C\u3063\u3066\u3001maketopo(\u9802\u70B9\u6570)\u3059\u308B\u3068\
    \ntopo[i]=i\u756A\u76EE\u306E\u9802\u70B9 \u306B\u306A\u308B\n*/\n\nbool visit(int\
    \ v,const vector<vector<int>>& G, vector<int>& topo, vector<int>& vis){\n\tif(vis[v]==2)\
    \ return 1;\n\tif(vis[v]==1) return 0;\n\tvis[v]=1;\n\tfor(int u:G[v]) if(!visit(u,G,topo,vis))\
    \ return 0;\n\tvis[v]=2;\n\ttopo.pb(v);\n\treturn 1;\n}\nvector<int> maketopo(const\
    \ vector<vector<int>>& G){\n\tint N = G.size();\n\tvector<int> topo;\n\tvector<int>\
    \ vis(N);\n\trep(i,N) if(!visit(i,G,topo,vis)) return {};\n\treverse(all(topo));\n\
    \treturn topo;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/topo.cpp
  requiredBy: []
  timestamp: '2020-12-16 01:39:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/topo.cpp
layout: document
redirect_from:
- /library/graph/topo.cpp
- /library/graph/topo.cpp.html
title: graph/topo.cpp
---
