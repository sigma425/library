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
    - https://snuke.hatenablog.com/entry/2016/07/10/043918
  bundledCode: "#line 1 \"graph/Flow/min_cost_flow.cpp\"\n/*\n\tF\u56DEdijkstra O(FElogV)\n\
    \n\t\u8CA0\u306E\u30B3\u30B9\u30C8\u306B\u3064\u3044\u3066:\n\t\t\u8CA0\u9589\u8DEF\
    :\n\t\t\t\u3084\u3079\uFF5E\n\t\t\t\u30B3\u30B9\u30C8\u30B9\u30B1\u30FC\u30EA\u30F3\
    \u30B0\u7CFB\u306A\u3089\u884C\u3051\u308B\u3068\u3044\u3046\u5642\u304C\u3042\
    \u308A\u307E\u3059\n\t\t\u8CA0\u8FBA:\n\t\t\t\u6C17\u306B\u305B\u305A\u306B\u8CBC\
    \u3063\u3066\u306F\u3058\u3081\u306BBellman Ford (min_cost_flow \u95A2\u6570\u306E\
    \u306F\u3058\u3081\u306E\u30B3\u30E1\u30F3\u30C8\u3092\u53C2\u7167)\n\n\t\u6700\
    \u5C0F\u6D41\u91CF\u5236\u9650\u306B\u3064\u3044\u3066:\n\t\t1) -BIG\u3092\u8DB3\
    \u3057\u3066\u8CA0\u8FBA\u3060\u3068\u601D\u3046\n\t\t\t\u30B0\u30E9\u30D5\u306E\
    \u5F62\u306B\u3088\u3063\u3066\u306F\u3053\u308C\u3067\u5341\u5206\u3001F\u304C\
    \u3067\u304B\u304F\u306A\u308B\u306E\u3067\u3084\u3084\u8A08\u7B97\u91CF\u306F\
    \u602A\u3057\u3044\n\t\t2) \u306A\u3093\u304B\u8D85\u9802\u70B9\u3064\u304F\u308B\
    \u3084\u3064\n\t\t\t\u3080\u305A\u3044\u306D\u3093\u306A\n\t\t\t\u666E\u901A\u306B\
    S->t, s->T \u3060\u3068\u601D\u3046\u3068\u307E\u305A\u3044\n\t\t\thttps://snuke.hatenablog.com/entry/2016/07/10/043918\n\
    \t\t3) b-flow\n\t\t\t\u3059\u3079\u3066\u3092\u89E3\u6C7A\u3059\u308B\u304C\u9045\
    \u3044\u3068\u304D\u3082\u3042\u308B\n*/\nstruct MinCostFlow{\n\tusing C = ll;\t\
    \t// capacity\n\tusing D = ll;\t\t// cost (distance)\n\tconst D inf = 1e18;\t\
    // max distance\n\n\tstruct edge{\n\t\tint to;\n\t\tC cap;\n\t\tD cost;\n\t\t\
    int rev;\n\t\tedge(int to_,C cap_, D cost_, int rev_):to(to_),cap(cap_),cost(cost_),rev(rev_){}\n\
    \t};\n\t\n\tint N;\n\tVV<edge> G;\n\tV<D> h;\n\tV<D> dist;\n\tV<int> prevv,preve;\n\
    \tMinCostFlow(int N_):N(N_){\n\t\tG.resize(N);\n\t\th.resize(N);\n\t\tdist.resize(N);\n\
    \t\tprevv.resize(N);\n\t\tpreve.resize(N);\n\t}\n\n\tvoid add_edge(int from, int\
    \ to, C cap, D cost){\n\t\tshow(cap);\n\t\tshow(cost);\n\t\tedge e1(to,cap,cost,(int)G[to].size());\n\
    \t\tedge e2(from,0,-cost,(int)G[from].size());\n\t\tG[from].push_back(e1);\n\t\
    \tG[to].push_back(e2);\n\t}\n\tD min_cost_flow(int s, int t, C f){\n\t\t// if\
    \ G has negative edge && has no negative loop\n\t\t// Bellman Ford O(MN)\n\t\t\
    // rep(v,N){\n\t\t// \tfor(auto& e: G[v]){\n\t\t// \t\tif(e.cap > 0) chmin(h[e.to],h[v]+e.cost);\n\
    \t\t// \t}\n\t\t// }\n\t\t\n\t\tD res = 0;\n\t\th = V<D>(N);\n\t\twhile(f > 0){\n\
    \t\t\tusing P = pair<D,int>;\n\t\t\tpriority_queue< P,vector<P>,greater<P> > que;\n\
    \t\t\tdist = V<D>(N,inf);\n\t\t\tdist[s] = 0;\n\t\t\tque.push(P(0,s));\n\t\t\t\
    while(!que.empty()){\n\t\t\t\tP p = que.top();\n\t\t\t\tque.pop();\n\t\t\t\tint\
    \ v = p.second;\n\t\t\t\tif(dist[v] < p.first) continue;\n\t\t\t\tfor(int i=0;i<(int)G[v].size();i++){\n\
    \t\t\t\t\tedge &e = G[v][i];\n\t\t\t\t\tif(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){\n\
    \t\t\t\t\t\tdist[e.to]=dist[v]+e.cost+h[v]-h[e.to];\n\t\t\t\t\t\tprevv[e.to]=v;\n\
    \t\t\t\t\t\tpreve[e.to]=i;\n\t\t\t\t\t\tque.push(P(dist[e.to],e.to));\n\t\t\t\t\
    \t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(dist[t]==inf) return -1;\n\t\t\trep(v,N) h[v]+=dist[v];\n\
    \t\t\tC d = f;\n\t\t\tfor(int v=t;v!=s;v=prevv[v]){\n\t\t\t\tchmin(d,G[prevv[v]][preve[v]].cap);\n\
    \t\t\t}\n\t\t\tf -= d;\n\t\t\tres += d*h[t];\n\t\t\tfor(int v=t;v!=s;v=prevv[v]){\n\
    \t\t\t\tedge &e=G[prevv[v]][preve[v]];\n\t\t\t\te.cap-=d;\n\t\t\t\tG[v][e.rev].cap+=d;\n\
    \t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\t/*\n\t\t\u6D41\u91CF\u3092\u6A2A\u8EF8\
    \u306B\u3001\u30B3\u30B9\u30C8\u3092\u7E26\u8EF8\u306B\u53D6\u3063\u305F\u3068\
    \u304D\u306E\u30B0\u30E9\u30D5\n\t\t\u5404\u7DDA\u5206\u306E (dx,dy/dx) \u306E\
    \ vector \u3092\u8FD4\u3059\n\t\tCF621 G \n\t*/\n\tV<pair<C,D>> min_cost_flow_slopes(int\
    \ s, int t){\t\t// {(x,tan)}\n\t\tV<pair<C,D>> res;\n\t\th = V<D>(N);\n\t\twhile(true){\n\
    \t\t\tusing P = pair<D,int>;\n\t\t\tpriority_queue< P,vector<P>,greater<P> > que;\n\
    \t\t\tdist = V<D>(N,inf);\n\t\t\tdist[s] = 0;\n\t\t\tque.push(P(0,s));\n\t\t\t\
    while(!que.empty()){\n\t\t\t\tP p = que.top();\n\t\t\t\tque.pop();\n\t\t\t\tint\
    \ v = p.second;\n\t\t\t\tif(dist[v] < p.first) continue;\n\t\t\t\tfor(int i=0;i<(int)G[v].size();i++){\n\
    \t\t\t\t\tedge &e = G[v][i];\n\t\t\t\t\tif(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){\n\
    \t\t\t\t\t\tdist[e.to]=dist[v]+e.cost+h[v]-h[e.to];\n\t\t\t\t\t\tprevv[e.to]=v;\n\
    \t\t\t\t\t\tpreve[e.to]=i;\n\t\t\t\t\t\tque.push(P(dist[e.to],e.to));\n\t\t\t\t\
    \t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(dist[t]==inf) break;\n\t\t\trep(v,N) h[v]+=dist[v];\n\
    \t\t\tC f = inf;\n\t\t\tfor(int v=t;v!=s;v=prevv[v]){\n\t\t\t\tchmin(f,G[prevv[v]][preve[v]].cap);\n\
    \t\t\t}\n\t\t\tres.pb(f,h[t]);\t\t\t\t// x, tan\n\t\t\tfor(int v=t;v!=s;v=prevv[v]){\n\
    \t\t\t\tedge &e=G[prevv[v]][preve[v]];\n\t\t\t\te.cap-=f;\n\t\t\t\tG[v][e.rev].cap+=f;\n\
    \t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "/*\n\tF\u56DEdijkstra O(FElogV)\n\n\t\u8CA0\u306E\u30B3\u30B9\u30C8\u306B\
    \u3064\u3044\u3066:\n\t\t\u8CA0\u9589\u8DEF:\n\t\t\t\u3084\u3079\uFF5E\n\t\t\t\
    \u30B3\u30B9\u30C8\u30B9\u30B1\u30FC\u30EA\u30F3\u30B0\u7CFB\u306A\u3089\u884C\
    \u3051\u308B\u3068\u3044\u3046\u5642\u304C\u3042\u308A\u307E\u3059\n\t\t\u8CA0\
    \u8FBA:\n\t\t\t\u6C17\u306B\u305B\u305A\u306B\u8CBC\u3063\u3066\u306F\u3058\u3081\
    \u306BBellman Ford (min_cost_flow \u95A2\u6570\u306E\u306F\u3058\u3081\u306E\u30B3\
    \u30E1\u30F3\u30C8\u3092\u53C2\u7167)\n\n\t\u6700\u5C0F\u6D41\u91CF\u5236\u9650\
    \u306B\u3064\u3044\u3066:\n\t\t1) -BIG\u3092\u8DB3\u3057\u3066\u8CA0\u8FBA\u3060\
    \u3068\u601D\u3046\n\t\t\t\u30B0\u30E9\u30D5\u306E\u5F62\u306B\u3088\u3063\u3066\
    \u306F\u3053\u308C\u3067\u5341\u5206\u3001F\u304C\u3067\u304B\u304F\u306A\u308B\
    \u306E\u3067\u3084\u3084\u8A08\u7B97\u91CF\u306F\u602A\u3057\u3044\n\t\t2) \u306A\
    \u3093\u304B\u8D85\u9802\u70B9\u3064\u304F\u308B\u3084\u3064\n\t\t\t\u3080\u305A\
    \u3044\u306D\u3093\u306A\n\t\t\t\u666E\u901A\u306BS->t, s->T \u3060\u3068\u601D\
    \u3046\u3068\u307E\u305A\u3044\n\t\t\thttps://snuke.hatenablog.com/entry/2016/07/10/043918\n\
    \t\t3) b-flow\n\t\t\t\u3059\u3079\u3066\u3092\u89E3\u6C7A\u3059\u308B\u304C\u9045\
    \u3044\u3068\u304D\u3082\u3042\u308B\n*/\nstruct MinCostFlow{\n\tusing C = ll;\t\
    \t// capacity\n\tusing D = ll;\t\t// cost (distance)\n\tconst D inf = 1e18;\t\
    // max distance\n\n\tstruct edge{\n\t\tint to;\n\t\tC cap;\n\t\tD cost;\n\t\t\
    int rev;\n\t\tedge(int to_,C cap_, D cost_, int rev_):to(to_),cap(cap_),cost(cost_),rev(rev_){}\n\
    \t};\n\t\n\tint N;\n\tVV<edge> G;\n\tV<D> h;\n\tV<D> dist;\n\tV<int> prevv,preve;\n\
    \tMinCostFlow(int N_):N(N_){\n\t\tG.resize(N);\n\t\th.resize(N);\n\t\tdist.resize(N);\n\
    \t\tprevv.resize(N);\n\t\tpreve.resize(N);\n\t}\n\n\tvoid add_edge(int from, int\
    \ to, C cap, D cost){\n\t\tshow(cap);\n\t\tshow(cost);\n\t\tedge e1(to,cap,cost,(int)G[to].size());\n\
    \t\tedge e2(from,0,-cost,(int)G[from].size());\n\t\tG[from].push_back(e1);\n\t\
    \tG[to].push_back(e2);\n\t}\n\tD min_cost_flow(int s, int t, C f){\n\t\t// if\
    \ G has negative edge && has no negative loop\n\t\t// Bellman Ford O(MN)\n\t\t\
    // rep(v,N){\n\t\t// \tfor(auto& e: G[v]){\n\t\t// \t\tif(e.cap > 0) chmin(h[e.to],h[v]+e.cost);\n\
    \t\t// \t}\n\t\t// }\n\t\t\n\t\tD res = 0;\n\t\th = V<D>(N);\n\t\twhile(f > 0){\n\
    \t\t\tusing P = pair<D,int>;\n\t\t\tpriority_queue< P,vector<P>,greater<P> > que;\n\
    \t\t\tdist = V<D>(N,inf);\n\t\t\tdist[s] = 0;\n\t\t\tque.push(P(0,s));\n\t\t\t\
    while(!que.empty()){\n\t\t\t\tP p = que.top();\n\t\t\t\tque.pop();\n\t\t\t\tint\
    \ v = p.second;\n\t\t\t\tif(dist[v] < p.first) continue;\n\t\t\t\tfor(int i=0;i<(int)G[v].size();i++){\n\
    \t\t\t\t\tedge &e = G[v][i];\n\t\t\t\t\tif(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){\n\
    \t\t\t\t\t\tdist[e.to]=dist[v]+e.cost+h[v]-h[e.to];\n\t\t\t\t\t\tprevv[e.to]=v;\n\
    \t\t\t\t\t\tpreve[e.to]=i;\n\t\t\t\t\t\tque.push(P(dist[e.to],e.to));\n\t\t\t\t\
    \t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(dist[t]==inf) return -1;\n\t\t\trep(v,N) h[v]+=dist[v];\n\
    \t\t\tC d = f;\n\t\t\tfor(int v=t;v!=s;v=prevv[v]){\n\t\t\t\tchmin(d,G[prevv[v]][preve[v]].cap);\n\
    \t\t\t}\n\t\t\tf -= d;\n\t\t\tres += d*h[t];\n\t\t\tfor(int v=t;v!=s;v=prevv[v]){\n\
    \t\t\t\tedge &e=G[prevv[v]][preve[v]];\n\t\t\t\te.cap-=d;\n\t\t\t\tG[v][e.rev].cap+=d;\n\
    \t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\t/*\n\t\t\u6D41\u91CF\u3092\u6A2A\u8EF8\
    \u306B\u3001\u30B3\u30B9\u30C8\u3092\u7E26\u8EF8\u306B\u53D6\u3063\u305F\u3068\
    \u304D\u306E\u30B0\u30E9\u30D5\n\t\t\u5404\u7DDA\u5206\u306E (dx,dy/dx) \u306E\
    \ vector \u3092\u8FD4\u3059\n\t\tCF621 G \n\t*/\n\tV<pair<C,D>> min_cost_flow_slopes(int\
    \ s, int t){\t\t// {(x,tan)}\n\t\tV<pair<C,D>> res;\n\t\th = V<D>(N);\n\t\twhile(true){\n\
    \t\t\tusing P = pair<D,int>;\n\t\t\tpriority_queue< P,vector<P>,greater<P> > que;\n\
    \t\t\tdist = V<D>(N,inf);\n\t\t\tdist[s] = 0;\n\t\t\tque.push(P(0,s));\n\t\t\t\
    while(!que.empty()){\n\t\t\t\tP p = que.top();\n\t\t\t\tque.pop();\n\t\t\t\tint\
    \ v = p.second;\n\t\t\t\tif(dist[v] < p.first) continue;\n\t\t\t\tfor(int i=0;i<(int)G[v].size();i++){\n\
    \t\t\t\t\tedge &e = G[v][i];\n\t\t\t\t\tif(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){\n\
    \t\t\t\t\t\tdist[e.to]=dist[v]+e.cost+h[v]-h[e.to];\n\t\t\t\t\t\tprevv[e.to]=v;\n\
    \t\t\t\t\t\tpreve[e.to]=i;\n\t\t\t\t\t\tque.push(P(dist[e.to],e.to));\n\t\t\t\t\
    \t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(dist[t]==inf) break;\n\t\t\trep(v,N) h[v]+=dist[v];\n\
    \t\t\tC f = inf;\n\t\t\tfor(int v=t;v!=s;v=prevv[v]){\n\t\t\t\tchmin(f,G[prevv[v]][preve[v]].cap);\n\
    \t\t\t}\n\t\t\tres.pb(f,h[t]);\t\t\t\t// x, tan\n\t\t\tfor(int v=t;v!=s;v=prevv[v]){\n\
    \t\t\t\tedge &e=G[prevv[v]][preve[v]];\n\t\t\t\te.cap-=f;\n\t\t\t\tG[v][e.rev].cap+=f;\n\
    \t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/Flow/min_cost_flow.cpp
  requiredBy: []
  timestamp: '2021-10-09 05:33:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/Flow/min_cost_flow.cpp
layout: document
redirect_from:
- /library/graph/Flow/min_cost_flow.cpp
- /library/graph/Flow/min_cost_flow.cpp.html
title: graph/Flow/min_cost_flow.cpp
---
