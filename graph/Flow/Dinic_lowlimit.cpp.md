---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/Flow/Dinic_lowlimit.cpp\"\n/*\n\tmaxflow\u306B,\u6700\
    \u5C0F\u6D41\u91CF\u5236\u7D04\u304C\u52A0\u308F\u3063\u305F\u3082\u306E\n\tmax_flow(s,t)\
    \ = -1 \\Leftrightarrow \u5236\u7D04\u3092\u6E80\u305F\u3059\u30D5\u30ED\u30FC\
    \u304C\u5B58\u5728\u3057\u306A\u3044.\n\n\tadd_edge_lowhigh(from,to,lowcap,highcap)\
    \ \u3067\u8FBA\u3092\u5F35\u3063\u305F\u5F8C\u3001(\u666E\u901A\u306Eadd_edge\u3068\
    \u4E00\u7DD2\u306B\u4F7F\u3063\u3066\u3082\u5927\u4E08\u592B)\n\tt->s \u306BINF\u3092\
    \u5F35\u3063\u3066,\u305D\u306E\u3042\u3068S->T\u306Bflow\u3092\u6D41\u3059.\n\
    \t\u3053\u306E\u6642\u306Bsum \u6700\u5C0F\u6D41\u91CF\u5236\u9650 \u4EE5\u4E0A\
    \u6D41\u308C\u308C\u3070OK,\u6D41\u308C\u306A\u3051\u308C\u3070-1\n\n\t\u3082\u3046\
    \u4E00\u5EA6\u5148\u307B\u3069\u540C\u69D8\u306B\u30B0\u30E9\u30D5\u3092\u518D\
    \u69CB\u7BC9\u3059\u308B.(G[i].clear()\u3060\u3051\u3067OK)\n\t\u4ECA\u5EA6\u306F\
    S->s,t->T\u306BINF\u3092\u5F35\u3063\u3066,S->T\u306B\u6D41\u3059.\n\t\u3053\u306E\
    \u5024-sum \u6700\u5C0F\u6D41\u91CF\u5236\u9650 \u304C\u5143\u306E\u30B0\u30E9\
    \u30D5\u3067\u306Emax_flow\u3067\u3042\u308B.\n\n\tverified at SRM694 hard\n\n\
    \tTODO : \u5FA9\u5143\u306F\u81EA\u660E\u306A\u65B9\u6CD5\u3067\u306F\u3067\u304D\
    \u306A\u3044\u3001\u3059\u306C\u3051\u306E\u30D6\u30ED\u30B0\u3092\u89B3\u308B\
    \u3053\u3068\uFF01\n\n*/\n\nstruct MaxFlow_lowlim{\n\tusing D = int;\n\tconst\
    \ D inf = 1e9;\n\tstruct edge{\n\t\tint to;\n\t\tD cap;\n\t\tint rev;\n\t\tedge(int\
    \ to,D cap,int rev):to(to),cap(cap),rev(rev){}\n\t};\n\n\tint V;\n\tint S,T;\n\
    \tD lowsum;\n\tvector<vector<edge>> G,G_copy;\n\tvector<int> level,iter;\n\n\t\
    MaxFlow_lowlim(int N):S(N),T(N+1),V(N+2){\n\t\tG = vector<vector<edge>>(V);\n\t\
    \tlevel = vector<int>(V);\n\t\titer = vector<int>(V);\n\t\tlowsum = 0;\n\t}\n\n\
    \tvoid add_edge(int from, int to, D cap){\n\t\tedge e1(to,cap,(int)G[to].size());\n\
    \t\tedge e2(from,0,(int)G[from].size());\n\t\tG[from].push_back(e1);\n\t\tG[to].push_back(e2);\n\
    \t}\n\tvoid add_edge_lowhigh(int from, int to, D lowcap,D highcap){\n\t\tassert(lowcap<=highcap);\n\
    \t\tlowsum += lowcap;\n\t\tadd_edge(S,to,lowcap);\n\t\tadd_edge(from,T,lowcap);\n\
    \t\tadd_edge(from,to,highcap-lowcap);\n\t}\n\tvoid bfs(int s){\n\t\tlevel = vector<int>(V,-1);\n\
    \n\t\tqueue<int> que;\n\t\tlevel[s]=0;\n\t\tque.push(s);\n\t\twhile(!que.empty()){\n\
    \t\t\tint v=que.front();\n\t\t\tque.pop();\n\t\t\tfor(int i=0;i<(int)G[v].size();i++){\n\
    \t\t\t\tedge &e=G[v][i];\n\t\t\t\tif(e.cap>0 && level[e.to]<0){\n\t\t\t\t\tlevel[e.to]=level[v]+1;\n\
    \t\t\t\t\tque.push(e.to);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tD dfs(int v,int t,D\
    \ f){\n\t\tif(v==t) return f;\n\t\tfor(int &i=iter[v];i<(int)G[v].size();i++){\n\
    \t\t\tedge &e=G[v][i];\n\t\t\tif(e.cap>0 && level[v]<level[e.to]){\n\t\t\t\tD\
    \ d = dfs(e.to,t,min(f,e.cap));\n\t\t\t\tif(d>0){\n\t\t\t\t\te.cap-=d;\n\t\t\t\
    \t\tG[e.to][e.rev].cap+=d;\n\t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\
    \treturn 0;\n\t}\n\tD max_flow_sub(int s,int t){\n\t\tD flow=0;\n\t\twhile(true){\n\
    \t\t\tbfs(s);\n\t\t\tif(level[t]<0) return flow;\n\t\t\titer = vector<int>(V,0);\n\
    \t\t\tD f;\n\t\t\twhile( (f=dfs(s,t,inf))>0 ) flow+=f;\n\t\t}\n\t}\n\n\tD max_flow(int\
    \ s,int t){\n\t\tG_copy = G;\n\t\tadd_edge(t,s,inf);\n\t\tD f = max_flow_sub(S,T);\n\
    \t\tif(f < lowsum) return -1;\n\n\t\tG = G_copy;\n\t\tadd_edge(S,s,inf);\n\t\t\
    add_edge(t,T,inf);\n\t\tf = max_flow_sub(S,T);\n\t\tassert(f >= lowsum);\n\t\t\
    return f-lowsum;\n\t}\n};\n"
  code: "/*\n\tmaxflow\u306B,\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u304C\u52A0\u308F\
    \u3063\u305F\u3082\u306E\n\tmax_flow(s,t) = -1 \\Leftrightarrow \u5236\u7D04\u3092\
    \u6E80\u305F\u3059\u30D5\u30ED\u30FC\u304C\u5B58\u5728\u3057\u306A\u3044.\n\n\t\
    add_edge_lowhigh(from,to,lowcap,highcap) \u3067\u8FBA\u3092\u5F35\u3063\u305F\u5F8C\
    \u3001(\u666E\u901A\u306Eadd_edge\u3068\u4E00\u7DD2\u306B\u4F7F\u3063\u3066\u3082\
    \u5927\u4E08\u592B)\n\tt->s \u306BINF\u3092\u5F35\u3063\u3066,\u305D\u306E\u3042\
    \u3068S->T\u306Bflow\u3092\u6D41\u3059.\n\t\u3053\u306E\u6642\u306Bsum \u6700\u5C0F\
    \u6D41\u91CF\u5236\u9650 \u4EE5\u4E0A\u6D41\u308C\u308C\u3070OK,\u6D41\u308C\u306A\
    \u3051\u308C\u3070-1\n\n\t\u3082\u3046\u4E00\u5EA6\u5148\u307B\u3069\u540C\u69D8\
    \u306B\u30B0\u30E9\u30D5\u3092\u518D\u69CB\u7BC9\u3059\u308B.(G[i].clear()\u3060\
    \u3051\u3067OK)\n\t\u4ECA\u5EA6\u306FS->s,t->T\u306BINF\u3092\u5F35\u3063\u3066\
    ,S->T\u306B\u6D41\u3059.\n\t\u3053\u306E\u5024-sum \u6700\u5C0F\u6D41\u91CF\u5236\
    \u9650 \u304C\u5143\u306E\u30B0\u30E9\u30D5\u3067\u306Emax_flow\u3067\u3042\u308B\
    .\n\n\tverified at SRM694 hard\n\n\tTODO : \u5FA9\u5143\u306F\u81EA\u660E\u306A\
    \u65B9\u6CD5\u3067\u306F\u3067\u304D\u306A\u3044\u3001\u3059\u306C\u3051\u306E\
    \u30D6\u30ED\u30B0\u3092\u89B3\u308B\u3053\u3068\uFF01\n\n*/\n\nstruct MaxFlow_lowlim{\n\
    \tusing D = int;\n\tconst D inf = 1e9;\n\tstruct edge{\n\t\tint to;\n\t\tD cap;\n\
    \t\tint rev;\n\t\tedge(int to,D cap,int rev):to(to),cap(cap),rev(rev){}\n\t};\n\
    \n\tint V;\n\tint S,T;\n\tD lowsum;\n\tvector<vector<edge>> G,G_copy;\n\tvector<int>\
    \ level,iter;\n\n\tMaxFlow_lowlim(int N):S(N),T(N+1),V(N+2){\n\t\tG = vector<vector<edge>>(V);\n\
    \t\tlevel = vector<int>(V);\n\t\titer = vector<int>(V);\n\t\tlowsum = 0;\n\t}\n\
    \n\tvoid add_edge(int from, int to, D cap){\n\t\tedge e1(to,cap,(int)G[to].size());\n\
    \t\tedge e2(from,0,(int)G[from].size());\n\t\tG[from].push_back(e1);\n\t\tG[to].push_back(e2);\n\
    \t}\n\tvoid add_edge_lowhigh(int from, int to, D lowcap,D highcap){\n\t\tassert(lowcap<=highcap);\n\
    \t\tlowsum += lowcap;\n\t\tadd_edge(S,to,lowcap);\n\t\tadd_edge(from,T,lowcap);\n\
    \t\tadd_edge(from,to,highcap-lowcap);\n\t}\n\tvoid bfs(int s){\n\t\tlevel = vector<int>(V,-1);\n\
    \n\t\tqueue<int> que;\n\t\tlevel[s]=0;\n\t\tque.push(s);\n\t\twhile(!que.empty()){\n\
    \t\t\tint v=que.front();\n\t\t\tque.pop();\n\t\t\tfor(int i=0;i<(int)G[v].size();i++){\n\
    \t\t\t\tedge &e=G[v][i];\n\t\t\t\tif(e.cap>0 && level[e.to]<0){\n\t\t\t\t\tlevel[e.to]=level[v]+1;\n\
    \t\t\t\t\tque.push(e.to);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tD dfs(int v,int t,D\
    \ f){\n\t\tif(v==t) return f;\n\t\tfor(int &i=iter[v];i<(int)G[v].size();i++){\n\
    \t\t\tedge &e=G[v][i];\n\t\t\tif(e.cap>0 && level[v]<level[e.to]){\n\t\t\t\tD\
    \ d = dfs(e.to,t,min(f,e.cap));\n\t\t\t\tif(d>0){\n\t\t\t\t\te.cap-=d;\n\t\t\t\
    \t\tG[e.to][e.rev].cap+=d;\n\t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\
    \treturn 0;\n\t}\n\tD max_flow_sub(int s,int t){\n\t\tD flow=0;\n\t\twhile(true){\n\
    \t\t\tbfs(s);\n\t\t\tif(level[t]<0) return flow;\n\t\t\titer = vector<int>(V,0);\n\
    \t\t\tD f;\n\t\t\twhile( (f=dfs(s,t,inf))>0 ) flow+=f;\n\t\t}\n\t}\n\n\tD max_flow(int\
    \ s,int t){\n\t\tG_copy = G;\n\t\tadd_edge(t,s,inf);\n\t\tD f = max_flow_sub(S,T);\n\
    \t\tif(f < lowsum) return -1;\n\n\t\tG = G_copy;\n\t\tadd_edge(S,s,inf);\n\t\t\
    add_edge(t,T,inf);\n\t\tf = max_flow_sub(S,T);\n\t\tassert(f >= lowsum);\n\t\t\
    return f-lowsum;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/Flow/Dinic_lowlimit.cpp
  requiredBy: []
  timestamp: '2019-03-14 23:15:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/Flow/Dinic_lowlimit.cpp
layout: document
redirect_from:
- /library/graph/Flow/Dinic_lowlimit.cpp
- /library/graph/Flow/Dinic_lowlimit.cpp.html
title: graph/Flow/Dinic_lowlimit.cpp
---
