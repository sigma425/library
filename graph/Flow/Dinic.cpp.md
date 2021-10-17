---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1427/submission/95526148
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1410
  bundledCode: "#line 1 \"graph/Flow/Dinic.cpp\"\n/*\n\t\u3082\u3046ACL\u4F7F\u3044\
    \u307E\u3057\u3087\u3046\n\thttps://codeforces.com/contest/1427/submission/95526148\
    \ \u3053\u308C\u306F\u6D41\u3057\u623B\u3057\u3068\u304B\u3082\u3084\u3063\u3066\
    \u308B\u4F8B\n*/\n\n/*\n\tDinic\n\tinf\u3092\u66F8\u304D\u63DB\u3048\u308B\n\t\
    \u521D\u671F\u5316\u306F\u9802\u70B9\u6570\n\tmax_flow(s,t) \u306E\u3042\u3068\
    \ calcCut(s,t) \u3092\u547C\u3076\u3053\u3068\u3067\u3001which[v] = minCut\u3067\
    \u9802\u70B9v\u304CS\u5074 ? 0 : 1 \u3092\u5F97\u3089\u308C\u308B\n\tverify: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1410\n\
    */\ntemplate<class capType>\nstruct MaxFlow{\n\tusing D = capType;\n\tconst D\
    \ inf = ;\n\tstruct edge{\n\t\tint to;\n\t\tD cap;\n\t\tint rev;\n\t\tedge(int\
    \ to_,D cap_,int rev_):to(to_),cap(cap_),rev(rev_){}\n\t};\n\n\tint N;\n\tvector<vector<edge>>\
    \ G;\n\tvector<int> level,iter;\n\n\tMaxFlow(int N_):N(N_){\n\t\tG = vector<vector<edge>>(N);\n\
    \t\tlevel = vector<int>(N);\n\t\titer = vector<int>(N);\n\t}\n\n\tvoid add_edge(int\
    \ from, int to, D cap){\n\t\tedge e1(to,cap,(int)G[to].size());\n\t\tedge e2(from,0,(int)G[from].size());\n\
    \t\tG[from].push_back(e1);\n\t\tG[to].push_back(e2);\n\t}\n\tvoid bfs(int s){\n\
    \t\tlevel = vector<int>(N,-1);\n\n\t\tqueue<int> que;\n\t\tlevel[s]=0;\n\t\tque.push(s);\n\
    \t\twhile(!que.empty()){\n\t\t\tint v=que.front();\n\t\t\tque.pop();\n\t\t\tfor(int\
    \ i=0;i<(int)G[v].size();i++){\n\t\t\t\tedge &e=G[v][i];\n\t\t\t\tif(e.cap>0 &&\
    \ level[e.to]<0){\n\t\t\t\t\tlevel[e.to]=level[v]+1;\n\t\t\t\t\tque.push(e.to);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tD dfs(int v,int t,D f){\n\t\tif(v==t) return\
    \ f;\n\t\tfor(int &i=iter[v];i<(int)G[v].size();i++){\n\t\t\tedge &e=G[v][i];\n\
    \t\t\tif(e.cap>0 && level[v]<level[e.to]){\n\t\t\t\tD d = dfs(e.to,t,min(f,e.cap));\n\
    \t\t\t\tif(d>0){\n\t\t\t\t\te.cap-=d;\n\t\t\t\t\tG[e.to][e.rev].cap+=d;\n\t\t\t\
    \t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\tD max_flow(int\
    \ s,int t){\n\t\tD flow=0;\n\t\twhile(true){\n\t\t\tbfs(s);\n\t\t\tif(level[t]<0)\
    \ return flow;\n\t\t\titer = vector<int>(N,0);\n\t\t\tD f;\n\t\t\twhile( (f=dfs(s,t,inf))>0\
    \ ) flow+=f;\n\t\t}\n\t}\n\n\tvector<int> calcCut(int s,int t){\n\t\tvector<int>\
    \ which(N,-1);\t\t\t// 0: S, 1: T\n\t\tauto dfs2 = [&](auto& self, int v) -> void{\n\
    \t\t\tif(which[v] != -1) return;\n\t\t\twhich[v] = 0;\n\t\t\tfor(auto e: G[v])\
    \ if(e.cap>0) self(self,e.to);\n\t\t};\n\t\tdfs2(dfs2,s);\n\t\trep(i,N) if(which[i]\
    \ == -1) which[i] = 1;\n\t\tassert(which[t] == 1);\n\t\treturn which;\n\t}\n};\n"
  code: "/*\n\t\u3082\u3046ACL\u4F7F\u3044\u307E\u3057\u3087\u3046\n\thttps://codeforces.com/contest/1427/submission/95526148\
    \ \u3053\u308C\u306F\u6D41\u3057\u623B\u3057\u3068\u304B\u3082\u3084\u3063\u3066\
    \u308B\u4F8B\n*/\n\n/*\n\tDinic\n\tinf\u3092\u66F8\u304D\u63DB\u3048\u308B\n\t\
    \u521D\u671F\u5316\u306F\u9802\u70B9\u6570\n\tmax_flow(s,t) \u306E\u3042\u3068\
    \ calcCut(s,t) \u3092\u547C\u3076\u3053\u3068\u3067\u3001which[v] = minCut\u3067\
    \u9802\u70B9v\u304CS\u5074 ? 0 : 1 \u3092\u5F97\u3089\u308C\u308B\n\tverify: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1410\n\
    */\ntemplate<class capType>\nstruct MaxFlow{\n\tusing D = capType;\n\tconst D\
    \ inf = ;\n\tstruct edge{\n\t\tint to;\n\t\tD cap;\n\t\tint rev;\n\t\tedge(int\
    \ to_,D cap_,int rev_):to(to_),cap(cap_),rev(rev_){}\n\t};\n\n\tint N;\n\tvector<vector<edge>>\
    \ G;\n\tvector<int> level,iter;\n\n\tMaxFlow(int N_):N(N_){\n\t\tG = vector<vector<edge>>(N);\n\
    \t\tlevel = vector<int>(N);\n\t\titer = vector<int>(N);\n\t}\n\n\tvoid add_edge(int\
    \ from, int to, D cap){\n\t\tedge e1(to,cap,(int)G[to].size());\n\t\tedge e2(from,0,(int)G[from].size());\n\
    \t\tG[from].push_back(e1);\n\t\tG[to].push_back(e2);\n\t}\n\tvoid bfs(int s){\n\
    \t\tlevel = vector<int>(N,-1);\n\n\t\tqueue<int> que;\n\t\tlevel[s]=0;\n\t\tque.push(s);\n\
    \t\twhile(!que.empty()){\n\t\t\tint v=que.front();\n\t\t\tque.pop();\n\t\t\tfor(int\
    \ i=0;i<(int)G[v].size();i++){\n\t\t\t\tedge &e=G[v][i];\n\t\t\t\tif(e.cap>0 &&\
    \ level[e.to]<0){\n\t\t\t\t\tlevel[e.to]=level[v]+1;\n\t\t\t\t\tque.push(e.to);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tD dfs(int v,int t,D f){\n\t\tif(v==t) return\
    \ f;\n\t\tfor(int &i=iter[v];i<(int)G[v].size();i++){\n\t\t\tedge &e=G[v][i];\n\
    \t\t\tif(e.cap>0 && level[v]<level[e.to]){\n\t\t\t\tD d = dfs(e.to,t,min(f,e.cap));\n\
    \t\t\t\tif(d>0){\n\t\t\t\t\te.cap-=d;\n\t\t\t\t\tG[e.to][e.rev].cap+=d;\n\t\t\t\
    \t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\tD max_flow(int\
    \ s,int t){\n\t\tD flow=0;\n\t\twhile(true){\n\t\t\tbfs(s);\n\t\t\tif(level[t]<0)\
    \ return flow;\n\t\t\titer = vector<int>(N,0);\n\t\t\tD f;\n\t\t\twhile( (f=dfs(s,t,inf))>0\
    \ ) flow+=f;\n\t\t}\n\t}\n\n\tvector<int> calcCut(int s,int t){\n\t\tvector<int>\
    \ which(N,-1);\t\t\t// 0: S, 1: T\n\t\tauto dfs2 = [&](auto& self, int v) -> void{\n\
    \t\t\tif(which[v] != -1) return;\n\t\t\twhich[v] = 0;\n\t\t\tfor(auto e: G[v])\
    \ if(e.cap>0) self(self,e.to);\n\t\t};\n\t\tdfs2(dfs2,s);\n\t\trep(i,N) if(which[i]\
    \ == -1) which[i] = 1;\n\t\tassert(which[t] == 1);\n\t\treturn which;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/Flow/Dinic.cpp
  requiredBy: []
  timestamp: '2021-10-18 03:25:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/Flow/Dinic.cpp
layout: document
redirect_from:
- /library/graph/Flow/Dinic.cpp
- /library/graph/Flow/Dinic.cpp.html
title: graph/Flow/Dinic.cpp
---
