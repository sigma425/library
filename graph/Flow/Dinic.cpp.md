---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/Flow/Dinic.cpp\"\n/*\n\tDinic\n\tD\u3068inf\u3092\u66F8\
    \u304D\u63DB\u3048\u308B\n\t\u521D\u671F\u5316\u306F\u9802\u70B9\u6570\n*/\nstruct\
    \ MaxFlow{\n\tusing D = int;\n\tconst D inf = 1e9;\n\tstruct edge{\n\t\tint to;\n\
    \t\tD cap;\n\t\tint rev;\n\t\tedge(int to,D cap,int rev):to(to),cap(cap),rev(rev){}\n\
    \t};\n\n\tint V;\n\tvector<vector<edge>> G;\n\tvector<int> level,iter;\n\n\tMaxFlow(int\
    \ V):V(V){\n\t\tG = vector<vector<edge>>(V);\n\t\tlevel = vector<int>(V);\n\t\t\
    iter = vector<int>(V);\n\t}\n\n\tvoid add_edge(int from, int to, D cap){\n\t\t\
    edge e1(to,cap,(int)G[to].size());\n\t\tedge e2(from,0,(int)G[from].size());\n\
    \t\tG[from].push_back(e1);\n\t\tG[to].push_back(e2);\n\t}\n\tvoid bfs(int s){\n\
    \t\tlevel = vector<int>(V,-1);\n\n\t\tqueue<int> que;\n\t\tlevel[s]=0;\n\t\tque.push(s);\n\
    \t\twhile(!que.empty()){\n\t\t\tint v=que.front();\n\t\t\tque.pop();\n\t\t\tfor(int\
    \ i=0;i<(int)G[v].size();i++){\n\t\t\t\tedge &e=G[v][i];\n\t\t\t\tif(e.cap>0 &&\
    \ level[e.to]<0){\n\t\t\t\t\tlevel[e.to]=level[v]+1;\n\t\t\t\t\tque.push(e.to);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tD dfs(int v,int t,D f){\n\t\tif(v==t) return\
    \ f;\n\t\tfor(int &i=iter[v];i<(int)G[v].size();i++){\n\t\t\tedge &e=G[v][i];\n\
    \t\t\tif(e.cap>0 && level[v]<level[e.to]){\n\t\t\t\tD d = dfs(e.to,t,min(f,e.cap));\n\
    \t\t\t\tif(d>0){\n\t\t\t\t\te.cap-=d;\n\t\t\t\t\tG[e.to][e.rev].cap+=d;\n\t\t\t\
    \t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\tD max_flow(int\
    \ s,int t){\n\t\tD flow=0;\n\t\twhile(true){\n\t\t\tbfs(s);\n\t\t\tif(level[t]<0)\
    \ return flow;\n\t\t\titer = vector<int>(V,0);\n\t\t\tD f;\n\t\t\twhile( (f=dfs(s,t,inf))>0\
    \ ) flow+=f;\n\t\t}\n\t}\n};\n"
  code: "/*\n\tDinic\n\tD\u3068inf\u3092\u66F8\u304D\u63DB\u3048\u308B\n\t\u521D\u671F\
    \u5316\u306F\u9802\u70B9\u6570\n*/\nstruct MaxFlow{\n\tusing D = int;\n\tconst\
    \ D inf = 1e9;\n\tstruct edge{\n\t\tint to;\n\t\tD cap;\n\t\tint rev;\n\t\tedge(int\
    \ to,D cap,int rev):to(to),cap(cap),rev(rev){}\n\t};\n\n\tint V;\n\tvector<vector<edge>>\
    \ G;\n\tvector<int> level,iter;\n\n\tMaxFlow(int V):V(V){\n\t\tG = vector<vector<edge>>(V);\n\
    \t\tlevel = vector<int>(V);\n\t\titer = vector<int>(V);\n\t}\n\n\tvoid add_edge(int\
    \ from, int to, D cap){\n\t\tedge e1(to,cap,(int)G[to].size());\n\t\tedge e2(from,0,(int)G[from].size());\n\
    \t\tG[from].push_back(e1);\n\t\tG[to].push_back(e2);\n\t}\n\tvoid bfs(int s){\n\
    \t\tlevel = vector<int>(V,-1);\n\n\t\tqueue<int> que;\n\t\tlevel[s]=0;\n\t\tque.push(s);\n\
    \t\twhile(!que.empty()){\n\t\t\tint v=que.front();\n\t\t\tque.pop();\n\t\t\tfor(int\
    \ i=0;i<(int)G[v].size();i++){\n\t\t\t\tedge &e=G[v][i];\n\t\t\t\tif(e.cap>0 &&\
    \ level[e.to]<0){\n\t\t\t\t\tlevel[e.to]=level[v]+1;\n\t\t\t\t\tque.push(e.to);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tD dfs(int v,int t,D f){\n\t\tif(v==t) return\
    \ f;\n\t\tfor(int &i=iter[v];i<(int)G[v].size();i++){\n\t\t\tedge &e=G[v][i];\n\
    \t\t\tif(e.cap>0 && level[v]<level[e.to]){\n\t\t\t\tD d = dfs(e.to,t,min(f,e.cap));\n\
    \t\t\t\tif(d>0){\n\t\t\t\t\te.cap-=d;\n\t\t\t\t\tG[e.to][e.rev].cap+=d;\n\t\t\t\
    \t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\tD max_flow(int\
    \ s,int t){\n\t\tD flow=0;\n\t\twhile(true){\n\t\t\tbfs(s);\n\t\t\tif(level[t]<0)\
    \ return flow;\n\t\t\titer = vector<int>(V,0);\n\t\t\tD f;\n\t\t\twhile( (f=dfs(s,t,inf))>0\
    \ ) flow+=f;\n\t\t}\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/Flow/Dinic.cpp
  requiredBy: []
  timestamp: '2018-01-03 22:55:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/Flow/Dinic.cpp
layout: document
redirect_from:
- /library/graph/Flow/Dinic.cpp
- /library/graph/Flow/Dinic.cpp.html
title: graph/Flow/Dinic.cpp
---
