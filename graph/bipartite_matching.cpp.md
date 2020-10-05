---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/bipartite_matching.cpp\"\nstruct Bipartite_matching{\n\
    \tint V;\n\tvector< vector<int> > G;\n\tvector<int> match;\n\tvector<bool> used;\n\
    \tvoid init(int N){\n\t\tV=N;\n\t\tG.assign(V,vector<int>());\n\t\tmatch.assign(V,0);\n\
    \t\tused.assign(V,false);\n\t}\n\tvoid add_edge(int v,int u){\n\t\tG[v].pb(u);\n\
    \t\tG[u].pb(v);\n\t}\n\tbool dfs(int v){\n\t\tused[v]=true;\n\t\trep(i,G[v].size()){\n\
    \t\t\tint u=G[v][i],w=match[u];\n\t\t\tif(w<0 || (!used[w] && dfs(w))){\n\t\t\t\
    \tmatch[v]=u;\n\t\t\t\tmatch[u]=v;\n\t\t\t\treturn true;\n\t\t\t}\n\t\t}\n\t\t\
    return false;\n\t}\n\tint max_matching(){\n\t\tint res=0;\n\t\tfill(all(match),-1);\n\
    \t\trep(v,V){\n\t\t\tif(match[v]<0){\n\t\t\t\tfill(all(used),false);\n\t\t\t\t\
    if(dfs(v)) res++;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "struct Bipartite_matching{\n\tint V;\n\tvector< vector<int> > G;\n\tvector<int>\
    \ match;\n\tvector<bool> used;\n\tvoid init(int N){\n\t\tV=N;\n\t\tG.assign(V,vector<int>());\n\
    \t\tmatch.assign(V,0);\n\t\tused.assign(V,false);\n\t}\n\tvoid add_edge(int v,int\
    \ u){\n\t\tG[v].pb(u);\n\t\tG[u].pb(v);\n\t}\n\tbool dfs(int v){\n\t\tused[v]=true;\n\
    \t\trep(i,G[v].size()){\n\t\t\tint u=G[v][i],w=match[u];\n\t\t\tif(w<0 || (!used[w]\
    \ && dfs(w))){\n\t\t\t\tmatch[v]=u;\n\t\t\t\tmatch[u]=v;\n\t\t\t\treturn true;\n\
    \t\t\t}\n\t\t}\n\t\treturn false;\n\t}\n\tint max_matching(){\n\t\tint res=0;\n\
    \t\tfill(all(match),-1);\n\t\trep(v,V){\n\t\t\tif(match[v]<0){\n\t\t\t\tfill(all(used),false);\n\
    \t\t\t\tif(dfs(v)) res++;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/bipartite_matching.cpp
  requiredBy: []
  timestamp: '2017-04-09 15:11:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bipartite_matching.cpp
layout: document
redirect_from:
- /library/graph/bipartite_matching.cpp
- /library/graph/bipartite_matching.cpp.html
title: graph/bipartite_matching.cpp
---
