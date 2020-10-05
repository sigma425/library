---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/Flow/Ford_Fulkerson.cpp\"\nstruct edge {int to,cap,rev;};\n\
    const int MAX_V=,INF=;\nvector<edge> G[MAX_V];\nbool used[MAX_V];\nvoid add_edge(int\
    \ from, int to, int cap){\n\t//directed\n\tedge e1={to,cap,G[to].size()};\n\t\
    edge e2={from,0,G[from].size()};\n\tG[from].push_back(e1);\n\tG[to].push_back(e2);\n\
    }\nint dfs(int v,int t,int f){\n\tif(v==t) return f;\n\tused[v]=true;\n\tfor(int\
    \ i=0;i<G[v].size();i++){\n\t\tedge &e=G[v][i];\n\t\tif(!used[e.to] && e.cap>0){\n\
    \t\t\tint d=dfs(e.to,t,min(f,e.cap));\n\t\t\tif(d>0){\n\t\t\t\te.cap-=d;\n\t\t\
    \t\tG[e.to][e.rev].cap+=d;\n\t\t\t\treturn d;\n\t\t\t}\n\t\t}\n\t}\n\treturn 0;\n\
    }\nint max_flow(int s,int t){\n\tint flow=0;\n\twhile(true){\n\t\tmemset(used,0,sizeof(used));\n\
    \t\tint f=dfs(s,t,INF);\n\t\tif(f==0) return flow;\n\t\tflow+=f;\n\t}\n}\nint\
    \ main(){\n"
  code: "struct edge {int to,cap,rev;};\nconst int MAX_V=,INF=;\nvector<edge> G[MAX_V];\n\
    bool used[MAX_V];\nvoid add_edge(int from, int to, int cap){\n\t//directed\n\t\
    edge e1={to,cap,G[to].size()};\n\tedge e2={from,0,G[from].size()};\n\tG[from].push_back(e1);\n\
    \tG[to].push_back(e2);\n}\nint dfs(int v,int t,int f){\n\tif(v==t) return f;\n\
    \tused[v]=true;\n\tfor(int i=0;i<G[v].size();i++){\n\t\tedge &e=G[v][i];\n\t\t\
    if(!used[e.to] && e.cap>0){\n\t\t\tint d=dfs(e.to,t,min(f,e.cap));\n\t\t\tif(d>0){\n\
    \t\t\t\te.cap-=d;\n\t\t\t\tG[e.to][e.rev].cap+=d;\n\t\t\t\treturn d;\n\t\t\t}\n\
    \t\t}\n\t}\n\treturn 0;\n}\nint max_flow(int s,int t){\n\tint flow=0;\n\twhile(true){\n\
    \t\tmemset(used,0,sizeof(used));\n\t\tint f=dfs(s,t,INF);\n\t\tif(f==0) return\
    \ flow;\n\t\tflow+=f;\n\t}\n}\nint main(){"
  dependsOn: []
  isVerificationFile: false
  path: graph/Flow/Ford_Fulkerson.cpp
  requiredBy: []
  timestamp: '2018-01-03 22:55:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/Flow/Ford_Fulkerson.cpp
layout: document
redirect_from:
- /library/graph/Flow/Ford_Fulkerson.cpp
- /library/graph/Flow/Ford_Fulkerson.cpp.html
title: graph/Flow/Ford_Fulkerson.cpp
---
