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
  bundledCode: "#line 1 \"graph/FunctionalGraph.cpp\"\n/*\n\tFunctionalGraph \u306E\
    \ cycle\u5217\u6319, \u9006\u30B0\u30E9\u30D5(\u30B5\u30A4\u30AF\u30EB\u8FBA\u9664\
    \u304F)\u306E\u69CB\u6210\n\n\tverified at AGC008/E Next or Nextnext\n*/\n\nstruct\
    \ FunctionalGraph{\n\t//output\n\tvector<vector<int>> cycles;\n\tvector<vector<int>>\
    \ G;\t//a^-1 cycle\u306E\u8FBA\u306F\u9664\u304F\n\n\n\tvector<bool> vis;\n\t\
    void setvis(int v){\n\t\tvis[v] = 1;\n\t\tfor(int u:G[v]) setvis(u);\n\t}\n\t\n\
    \tFunctionalGraph(vector<int> a){\n\t\tint N = a.size();\n\t\tvis.resize(N);\n\
    \t\tG.resize(N);\n\t\trep(i,N) G[a[i]].pb(i);\n\t\trep(i,N) if(!vis[i]){\n\t\t\
    \tint v = i;\n\t\t\twhile(!vis[v]){\n\t\t\t\tvis[v] = 1;\n\t\t\t\tv = a[v];\n\t\
    \t\t}\n\t\t\tvector<int> cycle;\n\t\t\tint s = v;\n\t\t\tdo{\n\t\t\t\tcycle.pb(v);\n\
    \t\t\t\tv = a[v];\n\t\t\t}while(v!=s);\n\t\t\tcycles.pb(cycle);\n\n\t\t\tint L\
    \ = cycle.size();\n\t\t\trep(j,L){\n\t\t\t\tint v = cycle[j];\n\t\t\t\trep(k,G[a[v]].size())\
    \ if(G[a[v]][k] == v){\n\t\t\t\t\tG[a[v]].erase(G[a[v]].begin()+k);\n\t\t\t\t\t\
    break;\n\t\t\t\t}\n\t\t\t}\n\t\t\trep(j,L){\n\t\t\t\tint v = cycle[j];\n\t\t\t\
    \tsetvis(v);\n\t\t\t}\n\t\t}\n\n\t}\n};\n"
  code: "/*\n\tFunctionalGraph \u306E cycle\u5217\u6319, \u9006\u30B0\u30E9\u30D5\
    (\u30B5\u30A4\u30AF\u30EB\u8FBA\u9664\u304F)\u306E\u69CB\u6210\n\n\tverified at\
    \ AGC008/E Next or Nextnext\n*/\n\nstruct FunctionalGraph{\n\t//output\n\tvector<vector<int>>\
    \ cycles;\n\tvector<vector<int>> G;\t//a^-1 cycle\u306E\u8FBA\u306F\u9664\u304F\
    \n\n\n\tvector<bool> vis;\n\tvoid setvis(int v){\n\t\tvis[v] = 1;\n\t\tfor(int\
    \ u:G[v]) setvis(u);\n\t}\n\t\n\tFunctionalGraph(vector<int> a){\n\t\tint N =\
    \ a.size();\n\t\tvis.resize(N);\n\t\tG.resize(N);\n\t\trep(i,N) G[a[i]].pb(i);\n\
    \t\trep(i,N) if(!vis[i]){\n\t\t\tint v = i;\n\t\t\twhile(!vis[v]){\n\t\t\t\tvis[v]\
    \ = 1;\n\t\t\t\tv = a[v];\n\t\t\t}\n\t\t\tvector<int> cycle;\n\t\t\tint s = v;\n\
    \t\t\tdo{\n\t\t\t\tcycle.pb(v);\n\t\t\t\tv = a[v];\n\t\t\t}while(v!=s);\n\t\t\t\
    cycles.pb(cycle);\n\n\t\t\tint L = cycle.size();\n\t\t\trep(j,L){\n\t\t\t\tint\
    \ v = cycle[j];\n\t\t\t\trep(k,G[a[v]].size()) if(G[a[v]][k] == v){\n\t\t\t\t\t\
    G[a[v]].erase(G[a[v]].begin()+k);\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\t\
    rep(j,L){\n\t\t\t\tint v = cycle[j];\n\t\t\t\tsetvis(v);\n\t\t\t}\n\t\t}\n\n\t\
    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/FunctionalGraph.cpp
  requiredBy: []
  timestamp: '2018-03-30 16:44:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/FunctionalGraph.cpp
layout: document
redirect_from:
- /library/graph/FunctionalGraph.cpp
- /library/graph/FunctionalGraph.cpp.html
title: graph/FunctionalGraph.cpp
---
