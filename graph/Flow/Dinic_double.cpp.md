---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/Flow/Dinic_double.cpp\"\nstruct edge {\n\tint to;\n\
    \tD cap;\n\tint rev;\n\tedge(int to,D cap,int rev) :to(to),cap(cap),rev(rev){}\n\
    };\nconst int MAX_V=;\nconst D inf=,eps=;\nvector<edge> G[MAX_V];\nint level[MAX_V];\n\
    int iter[MAX_V];\nvoid add_edge(int from, int to, D cap){\n\tedge e1(to,cap,G[to].size()),e2(from,0,G[from].size());\n\
    \tG[from].push_back(e1);\n\tG[to].push_back(e2);\n}\nvoid bfs(int s){\n\tmemset(level,-1,sizeof(level));\n\
    \tqueue<int> que;\n\tlevel[s]=0;\n\tque.push(s);\n\twhile(!que.empty()){\n\t\t\
    int v=que.front();\n\t\tque.pop();\n\t\tfor(int i=0;i<G[v].size();i++){\n\t\t\t\
    edge &e=G[v][i];\n\t\t\tif(e.cap>eps && level[e.to]<0){\n\t\t\t\tlevel[e.to]=level[v]+1;\n\
    \t\t\t\tque.push(e.to);\n\t\t\t}\n\t\t}\n\t}\n}\nD dfs(int v,int t,D f){\n\tif(v==t)\
    \ return f;\n\tfor(int &i=iter[v];i<G[v].size();i++){\n\t\tedge &e=G[v][i];\n\t\
    \tif(e.cap>eps && level[v]<level[e.to]){\n\t\t\tD d=dfs(e.to,t,min(f,e.cap));\n\
    \t\t\tif(d>eps){\n\t\t\t\te.cap-=d;\n\t\t\t\tG[e.to][e.rev].cap+=d;\n\t\t\t\t\
    return d;\n\t\t\t}\n\t\t}\n\t}\n\treturn 0;\n}\nD max_flow(int s,int t){\n\tD\
    \ flow=0;\n\twhile(true){\n\t\tbfs(s);\n\t\tif(level[t]<0) return flow;\n\t\t\
    memset(iter,0,sizeof(iter));\n\t\tD f;\n\t\twhile( (f=dfs(s,t,inf))>eps ) flow+=f;\n\
    \t}\n}\n"
  code: "struct edge {\n\tint to;\n\tD cap;\n\tint rev;\n\tedge(int to,D cap,int rev)\
    \ :to(to),cap(cap),rev(rev){}\n};\nconst int MAX_V=;\nconst D inf=,eps=;\nvector<edge>\
    \ G[MAX_V];\nint level[MAX_V];\nint iter[MAX_V];\nvoid add_edge(int from, int\
    \ to, D cap){\n\tedge e1(to,cap,G[to].size()),e2(from,0,G[from].size());\n\tG[from].push_back(e1);\n\
    \tG[to].push_back(e2);\n}\nvoid bfs(int s){\n\tmemset(level,-1,sizeof(level));\n\
    \tqueue<int> que;\n\tlevel[s]=0;\n\tque.push(s);\n\twhile(!que.empty()){\n\t\t\
    int v=que.front();\n\t\tque.pop();\n\t\tfor(int i=0;i<G[v].size();i++){\n\t\t\t\
    edge &e=G[v][i];\n\t\t\tif(e.cap>eps && level[e.to]<0){\n\t\t\t\tlevel[e.to]=level[v]+1;\n\
    \t\t\t\tque.push(e.to);\n\t\t\t}\n\t\t}\n\t}\n}\nD dfs(int v,int t,D f){\n\tif(v==t)\
    \ return f;\n\tfor(int &i=iter[v];i<G[v].size();i++){\n\t\tedge &e=G[v][i];\n\t\
    \tif(e.cap>eps && level[v]<level[e.to]){\n\t\t\tD d=dfs(e.to,t,min(f,e.cap));\n\
    \t\t\tif(d>eps){\n\t\t\t\te.cap-=d;\n\t\t\t\tG[e.to][e.rev].cap+=d;\n\t\t\t\t\
    return d;\n\t\t\t}\n\t\t}\n\t}\n\treturn 0;\n}\nD max_flow(int s,int t){\n\tD\
    \ flow=0;\n\twhile(true){\n\t\tbfs(s);\n\t\tif(level[t]<0) return flow;\n\t\t\
    memset(iter,0,sizeof(iter));\n\t\tD f;\n\t\twhile( (f=dfs(s,t,inf))>eps ) flow+=f;\n\
    \t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/Flow/Dinic_double.cpp
  requiredBy: []
  timestamp: '2018-01-03 22:55:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/Flow/Dinic_double.cpp
layout: document
redirect_from:
- /library/graph/Flow/Dinic_double.cpp
- /library/graph/Flow/Dinic_double.cpp.html
title: graph/Flow/Dinic_double.cpp
---
