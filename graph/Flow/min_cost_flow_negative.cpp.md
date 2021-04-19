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
  bundledCode: "#line 1 \"graph/Flow/min_cost_flow_negative.cpp\"\n/*\n\u8CA0\u9589\
    \u8DEF\u304C\u306A\u3044\u3068\u304D\u3060\u3051\n\n\u306F\u3058\u3081\u306BBellman\
    \ Ford\u3059\u308B\u3068\u3042\u3068\u306F\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\
    \u8FBC\u307F\u3067\u306F\u8CA0\u8FBA\u304C\u306A\u304F\u306A\u308B.\nO(EV + FElogV)\n\
    \nDAG\u306A\u3089 Bellman Ford \u3059\u3089\u3044\u3089\u306A\u304F\u3066\u3001\
    \u306F\u3058\u3081DP\u3059\u308C\u3070 O(E + FElogV)\u304B\u306A(\u3053\u3063\u3061\
    \u304C\u3044\u308B\u3053\u3068\u3042\u308B\u304B\u306A\u3042)\n\n\u8CA0\u9589\u8DEF\
    \u304C\u3042\u308B\u5834\u5408\u3001\u5148\u306B\u305D\u3053\u306B\u305D\u3063\
    \u3066\u76EE\u4E00\u676F\u6D41\u3057\u3066\u304A\u304F.\u2192\u305D\u306E\u3042\
    \u3068\u306B\u3053\u308C\n\n*/\ntypedef pair<int,int> P;\nstruct edge {int to,cap,cost,rev;};\n\
    const int MAX_V=,INF=;\nint V;\t\t\t//\u4EE3\u5165!!\nvector<edge> G[MAX_V];\n\
    int h[MAX_V];\nint dist[MAX_V];\nint prevv[MAX_V],preve[MAX_V];\nvoid add_edge(int\
    \ from, int to, int cap, int cost){\n\tedge e1={to,cap,cost,G[to].size()},e2={from,0,-cost,G[from].size()};\n\
    \tG[from].push_back(e1);\n\tG[to].push_back(e2);\n}\nint min_cost_flow(int s,\
    \ int t, int f){\n\tint res=0;\n\tfill(h,h+V,0);\n\trep(v,V){\n\t\tfor(edge e:G[v]){\n\
    \t\t\tif(e.cap>0) chmin(h[e.to],h[v]+e.cost);\n\t\t}\n\t}\n\twhile(f>0){\n\t\t\
    priority_queue< P,vector<P>,greater<P> > que;\n\t\tfill(dist,dist+V,INF);\n\t\t\
    dist[s]=0;\n\t\tque.push(P(0,s));\n\t\twhile(!que.empty()){\n\t\t\tP p=que.top();\n\
    \t\t\tque.pop();\n\t\t\tint v=p.second;\n\t\t\tif(dist[v]<p.first) continue;\n\
    \t\t\tfor(int i=0;i<G[v].size();i++){\n\t\t\t\tedge &e=G[v][i];\n\t\t\t\tif(e.cap>0\
    \ && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){\n\t\t\t\t\tdist[e.to]=dist[v]+e.cost+h[v]-h[e.to];\n\
    \t\t\t\t\tprevv[e.to]=v;\n\t\t\t\t\tpreve[e.to]=i;\n\t\t\t\t\tque.push(P(dist[e.to],e.to));\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif(dist[t]==INF) return -1;\n\t\tfor(int v=0;v<V;v++)\
    \ h[v]+=dist[v];\n\t\tint d=f;\n\t\tfor(int v=t;v!=s;v=prevv[v]){\n\t\t\td=min(d,G[prevv[v]][preve[v]].cap);\n\
    \t\t}\n\t\tf-=d;\n\t\tres+=d*h[t];\n\t\tfor(int v=t;v!=s;v=prevv[v]){\n\t\t\t\
    edge &e=G[prevv[v]][preve[v]];\n\t\t\te.cap-=d;\n\t\t\tG[v][e.rev].cap+=d;\n\t\
    \t}\n\t}\n\treturn res;\n}\n"
  code: "/*\n\u8CA0\u9589\u8DEF\u304C\u306A\u3044\u3068\u304D\u3060\u3051\n\n\u306F\
    \u3058\u3081\u306BBellman Ford\u3059\u308B\u3068\u3042\u3068\u306F\u30DD\u30C6\
    \u30F3\u30B7\u30E3\u30EB\u8FBC\u307F\u3067\u306F\u8CA0\u8FBA\u304C\u306A\u304F\
    \u306A\u308B.\nO(EV + FElogV)\n\nDAG\u306A\u3089 Bellman Ford \u3059\u3089\u3044\
    \u3089\u306A\u304F\u3066\u3001\u306F\u3058\u3081DP\u3059\u308C\u3070 O(E + FElogV)\u304B\
    \u306A(\u3053\u3063\u3061\u304C\u3044\u308B\u3053\u3068\u3042\u308B\u304B\u306A\
    \u3042)\n\n\u8CA0\u9589\u8DEF\u304C\u3042\u308B\u5834\u5408\u3001\u5148\u306B\u305D\
    \u3053\u306B\u305D\u3063\u3066\u76EE\u4E00\u676F\u6D41\u3057\u3066\u304A\u304F\
    .\u2192\u305D\u306E\u3042\u3068\u306B\u3053\u308C\n\n*/\ntypedef pair<int,int>\
    \ P;\nstruct edge {int to,cap,cost,rev;};\nconst int MAX_V=,INF=;\nint V;\t\t\t\
    //\u4EE3\u5165!!\nvector<edge> G[MAX_V];\nint h[MAX_V];\nint dist[MAX_V];\nint\
    \ prevv[MAX_V],preve[MAX_V];\nvoid add_edge(int from, int to, int cap, int cost){\n\
    \tedge e1={to,cap,cost,G[to].size()},e2={from,0,-cost,G[from].size()};\n\tG[from].push_back(e1);\n\
    \tG[to].push_back(e2);\n}\nint min_cost_flow(int s, int t, int f){\n\tint res=0;\n\
    \tfill(h,h+V,0);\n\trep(v,V){\n\t\tfor(edge e:G[v]){\n\t\t\tif(e.cap>0) chmin(h[e.to],h[v]+e.cost);\n\
    \t\t}\n\t}\n\twhile(f>0){\n\t\tpriority_queue< P,vector<P>,greater<P> > que;\n\
    \t\tfill(dist,dist+V,INF);\n\t\tdist[s]=0;\n\t\tque.push(P(0,s));\n\t\twhile(!que.empty()){\n\
    \t\t\tP p=que.top();\n\t\t\tque.pop();\n\t\t\tint v=p.second;\n\t\t\tif(dist[v]<p.first)\
    \ continue;\n\t\t\tfor(int i=0;i<G[v].size();i++){\n\t\t\t\tedge &e=G[v][i];\n\
    \t\t\t\tif(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){\n\t\t\t\t\tdist[e.to]=dist[v]+e.cost+h[v]-h[e.to];\n\
    \t\t\t\t\tprevv[e.to]=v;\n\t\t\t\t\tpreve[e.to]=i;\n\t\t\t\t\tque.push(P(dist[e.to],e.to));\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif(dist[t]==INF) return -1;\n\t\tfor(int v=0;v<V;v++)\
    \ h[v]+=dist[v];\n\t\tint d=f;\n\t\tfor(int v=t;v!=s;v=prevv[v]){\n\t\t\td=min(d,G[prevv[v]][preve[v]].cap);\n\
    \t\t}\n\t\tf-=d;\n\t\tres+=d*h[t];\n\t\tfor(int v=t;v!=s;v=prevv[v]){\n\t\t\t\
    edge &e=G[prevv[v]][preve[v]];\n\t\t\te.cap-=d;\n\t\t\tG[v][e.rev].cap+=d;\n\t\
    \t}\n\t}\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/Flow/min_cost_flow_negative.cpp
  requiredBy: []
  timestamp: '2018-01-03 22:55:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/Flow/min_cost_flow_negative.cpp
layout: document
redirect_from:
- /library/graph/Flow/min_cost_flow_negative.cpp
- /library/graph/Flow/min_cost_flow_negative.cpp.html
title: graph/Flow/min_cost_flow_negative.cpp
---
