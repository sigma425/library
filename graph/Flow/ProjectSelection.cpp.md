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
    - http://pjselection.com/
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1410
    - https://noshi91.hatenablog.com/entry/2021/06/29/044225
  bundledCode: "#line 1 \"graph/Flow/ProjectSelection.cpp\"\n/*\n\tProject Selection\
    \ Problem, \u3044\u308F\u3086\u308B\u71C3\u3084\u3059\u57CB\u3081\u308B\n\tx:true\
    \ \u304B\u3064 y:false \u306A\u3089\u30B3\u30B9\u30C8\u304C\u304B\u304B\u308B\
    \ \u3068\u3044\u3046\u554F\u984C\u304C\u89E3\u3051\u308B\n\t\u4E00\u822C\u306B\
    \u306F \u9069\u5207\u306B\u5909\u6570\u3092flip\u3059\u308B\u3053\u3068\u3067\u2191\
    \u306E\u95A2\u4FC2\u304C\u4E8C\u90E8\u30B0\u30E9\u30D5\u306A\u3089OK\n\t\u3053\
    \u306E\u30E9\u30A4\u30D6\u30E9\u30EA\u3067\u306Fflip\u306F\u6C17\u306B\u305B\u305A\
    \u306B\u4F7F\u3048\u308B\u3002\u6700\u5F8C\u306Bbipartite\u3058\u3083\u306A\u304B\
    \u3063\u305F\u3089assert\u3057\u3066\u308B\n\tV<bool> sol(N) \u306B\u5FA9\u5143\
    \u3082\u3057\u3066\u3042\u308B\n\n\t\u5909\u6570\u306E\u6570\u3067\u521D\u671F\
    \u5316\n\t - addCost(int id, bool f, D cost): \u5909\u6570 id \u304C f \u3060\u3068\
    \ \u30B3\u30B9\u30C8 cost\n\t \tcost < 0 \u3067\u3082\u3088\u3044\n\t - addCost2(int\
    \ x,bool fx, int y,bool fy, D cost): \u5909\u6570 x \u304C fx \u3067 \u5909\u6570\
    \ y \u304C fy \u3060\u3068 \u30B3\u30B9\u30C8 cost\n\t \tcost >= 0 \u3067\u306A\
    \u3044\u3068\u30C0\u30E1\n\t\n\t\u4E00\u822C\u5316\u306B\u3064\u3044\u3066:\n\t\
    \t\u9762\u5012\u3060\u304B\u3089\u3084\u3063\u3066\u306A\u3044\u3051\u3069\u307B\
    \u3093\u3068\u306F\u5024\u304C\u8CA0\u3068\u304B\u3067\u306F\u306A\u304F\u3061\
    \u3083\u3093\u3068\u3057\u305F\u6761\u4EF6\u304C\u3042\u308A\u3001 \u4E00\u822C\
    \u306Bk\u5024\u3067\u3001i \u304C p \u3067 j \u304C q \u306E\u3068\u304D\u306E\
    \u30B3\u30B9\u30C8 f_{i,j}(p,q) \u304C \u52A3\u30E2\u306A\u3089\u3088\u3044 \n\
    \t\tcf: https://noshi91.hatenablog.com/entry/2021/06/29/044225\n\n\tverify:\n\t\
    \thttps://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1410\n\t\thttp://pjselection.com/\n\
    */\ntemplate<class capType>\nstruct MaxFlow{\n\tusing D = capType;\n\tconst D\
    \ inf = 1e9;\n\tstruct edge{\n\t\tint to;\n\t\tD cap;\n\t\tint rev;\n\t\tedge(int\
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
    \ == -1) which[i] = 1;\n\t\tassert(which[t] == 1);\n\t\treturn which;\n\t}\n};\n\
    struct UnionFind{\n\tvector<int> par;\n\tUnionFind(int N){\n\t\tpar.assign(N,0);\n\
    \t\trep(i,N) par[i]=i;\n\t}\n\tint find(int x){\n\t\tif(par[x]==x) return x;\n\
    \t\treturn par[x]=find(par[x]);\n\t}\n\tbool same(int x,int y){\n\t\treturn find(x)==find(y);\n\
    \t}\n\tvoid unite(int x,int y){\n\t\tx=find(x),y=find(y);\n\t\tif(x==y) return;\n\
    \t\tpar[y]=x;\n\t}\n};\ntemplate<class costType>\nstruct ProjectSelection{\n\t\
    using D = costType;\n\tint N;\n\tvector<D> trueCost, falseCost;\n\tMaxFlow<D>\
    \ MF;\n\tUnionFind UF;\n\tvector<bool> sol;\n\n\tProjectSelection(int varnum):N(varnum),\
    \ trueCost(N), falseCost(N), MF(N+2), UF(N+N), sol(N){\n\t}\n\tvoid addCost(int\
    \ id, bool f, D cost){\t\t// ok for cost < 0\n\t\tassert(0 <= id && id < N);\n\
    \t\t(f ? trueCost : falseCost)[id] += cost;\n\t}\n\tstruct Waf{\n\t\tint x;bool\
    \ fx;int y;bool fy;D cost;\n\t};\n\tvector<Waf> memo;\n\tvoid addCost2(int x,bool\
    \ fx, int y,bool fy, D cost){\n\t\t// x:fx  and  y:fy  =>  ans += cost\n\t\tassert(0\
    \ <= x && x < N); assert(0 <= y && y < N);\n\t\tif(fx == fy) UF.unite(x,y+N),\
    \ UF.unite(y,x+N);\n\t\telse UF.unite(x,y), UF.unite(x+N,y+N);\n\t\tmemo.push_back({x,fx,y,fy,cost});\n\
    \t}\n\tD minCost(){\n\t\tbool isBipartite = true;\n\t\trep(i,N) if(UF.same(i,i+N))\
    \ isBipartite = false;\n\t\tassert(isBipartite);\n\t\tV<int> which(N,-1);\t\t\
    // which[i] = 0 <=> i:true iff i: left(S) side <=> i:true iff cut off i->T\n\t\
    \trep(i,N){\n\t\t\tint r1 = UF.find(i), r2 = UF.find(i+N);\n\t\t\twhich[i] = (r1\
    \ < r2 ? 0 : 1);\n\t\t}\n\t\tint S = N, T = N+1;\n\t\tD off = 0;\n\t\trep(i,N){\n\
    \t\t\tD mn = min(trueCost[i], falseCost[i]);\n\t\t\ttrueCost[i] -= mn, falseCost[i]\
    \ -= mn;\n\t\t\toff += mn;\n\t\t\tif(which[i] == 0){\n\t\t\t\tMF.add_edge(i,T,trueCost[i]);\n\
    \t\t\t\tMF.add_edge(S,i,falseCost[i]);\n\t\t\t}else{\n\t\t\t\tMF.add_edge(i,T,falseCost[i]);\n\
    \t\t\t\tMF.add_edge(S,i,trueCost[i]);\n\t\t\t}\n\t\t}\n\t\tfor(auto e: memo){\n\
    \t\t\tbool xisS = (e.fx ^ which[e.x]);\n\t\t\tbool yisS = (e.fy ^ which[e.y]);\n\
    \t\t\tassert(xisS != yisS);\n\t\t\tif(xisS) MF.add_edge(e.x,e.y,e.cost);\n\t\t\
    \telse MF.add_edge(e.y,e.x,e.cost);\n\t\t}\n\t\tD flow = MF.max_flow(S,T) + off;\n\
    \t\tauto isT = MF.calcCut(S,T);\n\t\trep(i,N) sol[i] = !(isT[i] ^ which[i]);\n\
    \t\treturn flow;\n\t}\n};\n"
  code: "/*\n\tProject Selection Problem, \u3044\u308F\u3086\u308B\u71C3\u3084\u3059\
    \u57CB\u3081\u308B\n\tx:true \u304B\u3064 y:false \u306A\u3089\u30B3\u30B9\u30C8\
    \u304C\u304B\u304B\u308B \u3068\u3044\u3046\u554F\u984C\u304C\u89E3\u3051\u308B\
    \n\t\u4E00\u822C\u306B\u306F \u9069\u5207\u306B\u5909\u6570\u3092flip\u3059\u308B\
    \u3053\u3068\u3067\u2191\u306E\u95A2\u4FC2\u304C\u4E8C\u90E8\u30B0\u30E9\u30D5\
    \u306A\u3089OK\n\t\u3053\u306E\u30E9\u30A4\u30D6\u30E9\u30EA\u3067\u306Fflip\u306F\
    \u6C17\u306B\u305B\u305A\u306B\u4F7F\u3048\u308B\u3002\u6700\u5F8C\u306Bbipartite\u3058\
    \u3083\u306A\u304B\u3063\u305F\u3089assert\u3057\u3066\u308B\n\tV<bool> sol(N)\
    \ \u306B\u5FA9\u5143\u3082\u3057\u3066\u3042\u308B\n\n\t\u5909\u6570\u306E\u6570\
    \u3067\u521D\u671F\u5316\n\t - addCost(int id, bool f, D cost): \u5909\u6570 id\
    \ \u304C f \u3060\u3068 \u30B3\u30B9\u30C8 cost\n\t \tcost < 0 \u3067\u3082\u3088\
    \u3044\n\t - addCost2(int x,bool fx, int y,bool fy, D cost): \u5909\u6570 x \u304C\
    \ fx \u3067 \u5909\u6570 y \u304C fy \u3060\u3068 \u30B3\u30B9\u30C8 cost\n\t\
    \ \tcost >= 0 \u3067\u306A\u3044\u3068\u30C0\u30E1\n\t\n\t\u4E00\u822C\u5316\u306B\
    \u3064\u3044\u3066:\n\t\t\u9762\u5012\u3060\u304B\u3089\u3084\u3063\u3066\u306A\
    \u3044\u3051\u3069\u307B\u3093\u3068\u306F\u5024\u304C\u8CA0\u3068\u304B\u3067\
    \u306F\u306A\u304F\u3061\u3083\u3093\u3068\u3057\u305F\u6761\u4EF6\u304C\u3042\
    \u308A\u3001 \u4E00\u822C\u306Bk\u5024\u3067\u3001i \u304C p \u3067 j \u304C q\
    \ \u306E\u3068\u304D\u306E\u30B3\u30B9\u30C8 f_{i,j}(p,q) \u304C \u52A3\u30E2\u306A\
    \u3089\u3088\u3044 \n\t\tcf: https://noshi91.hatenablog.com/entry/2021/06/29/044225\n\
    \n\tverify:\n\t\thttps://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1410\n\
    \t\thttp://pjselection.com/\n*/\ntemplate<class capType>\nstruct MaxFlow{\n\t\
    using D = capType;\n\tconst D inf = 1e9;\n\tstruct edge{\n\t\tint to;\n\t\tD cap;\n\
    \t\tint rev;\n\t\tedge(int to_,D cap_,int rev_):to(to_),cap(cap_),rev(rev_){}\n\
    \t};\n\n\tint N;\n\tvector<vector<edge>> G;\n\tvector<int> level,iter;\n\n\tMaxFlow(int\
    \ N_):N(N_){\n\t\tG = vector<vector<edge>>(N);\n\t\tlevel = vector<int>(N);\n\t\
    \titer = vector<int>(N);\n\t}\n\n\tvoid add_edge(int from, int to, D cap){\n\t\
    \tedge e1(to,cap,(int)G[to].size());\n\t\tedge e2(from,0,(int)G[from].size());\n\
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
    \ == -1) which[i] = 1;\n\t\tassert(which[t] == 1);\n\t\treturn which;\n\t}\n};\n\
    struct UnionFind{\n\tvector<int> par;\n\tUnionFind(int N){\n\t\tpar.assign(N,0);\n\
    \t\trep(i,N) par[i]=i;\n\t}\n\tint find(int x){\n\t\tif(par[x]==x) return x;\n\
    \t\treturn par[x]=find(par[x]);\n\t}\n\tbool same(int x,int y){\n\t\treturn find(x)==find(y);\n\
    \t}\n\tvoid unite(int x,int y){\n\t\tx=find(x),y=find(y);\n\t\tif(x==y) return;\n\
    \t\tpar[y]=x;\n\t}\n};\ntemplate<class costType>\nstruct ProjectSelection{\n\t\
    using D = costType;\n\tint N;\n\tvector<D> trueCost, falseCost;\n\tMaxFlow<D>\
    \ MF;\n\tUnionFind UF;\n\tvector<bool> sol;\n\n\tProjectSelection(int varnum):N(varnum),\
    \ trueCost(N), falseCost(N), MF(N+2), UF(N+N), sol(N){\n\t}\n\tvoid addCost(int\
    \ id, bool f, D cost){\t\t// ok for cost < 0\n\t\tassert(0 <= id && id < N);\n\
    \t\t(f ? trueCost : falseCost)[id] += cost;\n\t}\n\tstruct Waf{\n\t\tint x;bool\
    \ fx;int y;bool fy;D cost;\n\t};\n\tvector<Waf> memo;\n\tvoid addCost2(int x,bool\
    \ fx, int y,bool fy, D cost){\n\t\t// x:fx  and  y:fy  =>  ans += cost\n\t\tassert(0\
    \ <= x && x < N); assert(0 <= y && y < N);\n\t\tif(fx == fy) UF.unite(x,y+N),\
    \ UF.unite(y,x+N);\n\t\telse UF.unite(x,y), UF.unite(x+N,y+N);\n\t\tmemo.push_back({x,fx,y,fy,cost});\n\
    \t}\n\tD minCost(){\n\t\tbool isBipartite = true;\n\t\trep(i,N) if(UF.same(i,i+N))\
    \ isBipartite = false;\n\t\tassert(isBipartite);\n\t\tV<int> which(N,-1);\t\t\
    // which[i] = 0 <=> i:true iff i: left(S) side <=> i:true iff cut off i->T\n\t\
    \trep(i,N){\n\t\t\tint r1 = UF.find(i), r2 = UF.find(i+N);\n\t\t\twhich[i] = (r1\
    \ < r2 ? 0 : 1);\n\t\t}\n\t\tint S = N, T = N+1;\n\t\tD off = 0;\n\t\trep(i,N){\n\
    \t\t\tD mn = min(trueCost[i], falseCost[i]);\n\t\t\ttrueCost[i] -= mn, falseCost[i]\
    \ -= mn;\n\t\t\toff += mn;\n\t\t\tif(which[i] == 0){\n\t\t\t\tMF.add_edge(i,T,trueCost[i]);\n\
    \t\t\t\tMF.add_edge(S,i,falseCost[i]);\n\t\t\t}else{\n\t\t\t\tMF.add_edge(i,T,falseCost[i]);\n\
    \t\t\t\tMF.add_edge(S,i,trueCost[i]);\n\t\t\t}\n\t\t}\n\t\tfor(auto e: memo){\n\
    \t\t\tbool xisS = (e.fx ^ which[e.x]);\n\t\t\tbool yisS = (e.fy ^ which[e.y]);\n\
    \t\t\tassert(xisS != yisS);\n\t\t\tif(xisS) MF.add_edge(e.x,e.y,e.cost);\n\t\t\
    \telse MF.add_edge(e.y,e.x,e.cost);\n\t\t}\n\t\tD flow = MF.max_flow(S,T) + off;\n\
    \t\tauto isT = MF.calcCut(S,T);\n\t\trep(i,N) sol[i] = !(isT[i] ^ which[i]);\n\
    \t\treturn flow;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/Flow/ProjectSelection.cpp
  requiredBy: []
  timestamp: '2021-10-18 03:39:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/Flow/ProjectSelection.cpp
layout: document
redirect_from:
- /library/graph/Flow/ProjectSelection.cpp
- /library/graph/Flow/ProjectSelection.cpp.html
title: graph/Flow/ProjectSelection.cpp
---
