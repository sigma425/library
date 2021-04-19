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
  bundledCode: "#line 1 \"graph/articulation.cpp\"\n/*\n\t\u95A2\u7BC0\u70B9\n\tord[v]:\
    \ dfs\u68EE\u3067\u306Eid\n\tlow[v]: lowlink, dfs\u6728\u3067\u5B50\u306B\u3044\
    \u304F + \u4E00\u56DE\u3060\u3051\u5F8C\u9000\u8FBA\u3067\u4E0A\u306B\u4E0A\u304C\
    \u308C\u308B \u3068\u304D\u306B\u305F\u3069\u308A\u3064\u3051\u308Bord \u306E\
    min\n\tv\u304C\u95A2\u7BC0\u70B9\u21D4\n\tv\u304Cdfs\u6728\u306Eroot \u304B\u3064\
    \ \u6B21\u6570\u304C2\u4EE5\u4E0A or\n\tv\u304Cdfs\u6728\u306Eroot\u3067\u306A\
    \u3044 \u304B\u3064 \u3042\u308B\u5B50u\u304C\u5B58\u5728\u3057, ord[v]<=low[u]\n\
    \tord[v]=low[u]\u3067\u3082\u95A2\u7BC0\u70B9(\u81EA\u5206\u306B\u30B5\u30A4\u30AF\
    \u30EB\u304C\u623B\u3063\u3066\u304D\u305F\u3068\u3057\u3066\u3082\u4E0A\u306B\
    \u306F\u3044\u3051\u306A\u3044\u306E\u3067\u307E\u3060\u95A2\u7BC0\u70B9\u306A\
    \u307E\u307E) \u306A\u3053\u3068\u306B\u6CE8\u610F\n\n\t\u4E8C\u91CD(\u9802\u70B9\
    )\u9023\u7D50\u6210\u5206\n\t\u6A4B\u306B\u5BFE\u3059\u308B\u4E8C\u91CD\u8FBA\u9023\
    \u7D50\u6210\u5206\u306E\u3088\u3046\u306B\u3001\u4E8C\u91CD\u9023\u7D50\u6210\
    \u5206\u304C\u5B9A\u7FA9\u3055\u308C\u308B\u3002\n\t\u8FBA\u96C6\u5408E\u304C\u4E8C\
    \u91CD\u9023\u7D50\u21D4E\u3067\u8A98\u5C0E\u3055\u308C\u308B\u30B0\u30E9\u30D5\
    \u304C\u95A2\u7BC0\u70B9\u3092\u6301\u305F\u306A\u3044\n\n\n\t\u4E8C\u91CD\u8FBA\
    \u9023\u7D50\u6210\u5206\u5206\u89E3\u304C\u6728\u3092\u4F5C\u308B\u3088\u3046\
    \u306B\u3001\u95A2\u7BC0\u70B9\u3068\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\
    \u3092\u9802\u70B9\u3068\u3057\u3066\u6301\u3064\u6728\u307F\u305F\u3044\u306A\
    \u306E\u3092\u4F5C\u308C\u308B\n\tjoi/spring/12/sokoban.cpp \u5C71\u6912\n\n\t\
    \u591A\u91CD\u8FBA\u306F\u5BFE\u5FDC\u3057\u3066\u3044\u306A\u3044\u3001\u591A\
    \u91CD\u8FBA\u304C\u3042\u3063\u3066\u3082\u95A2\u7BC0\u70B9\u304B\u3069\u3046\
    \u304B\u306B\u306F\u95A2\u308F\u308A\u304C\u306A\u3044\u3002\n\t\u5BFE\u5FDC\u3057\
    \u305F\u3044\u306A\u3089Edge\u306Bid\u307F\u305F\u3044\u306A\u306E\u3092\u6301\
    \u305F\u305B\u3066\u304A\u3044\u3066if\u6587\u306E\u5224\u5B9A\u3092\u305D\u308C\
    \u3067\u3084\u308B\n\n\tArticulation Art(G);\n\tArt.constructCompressedGraph();\n\
    \tVV<int> H = Art.H;\n\t\n\tH\u306F\u6728\u3067\u3042\u3063\u3066\u3001\n\t\t\
    - \u3082\u3068\u306E\u9802\u70B9 v \u304C v \u306B\u5BFE\u5FDC\n\t\t- biedges[i]\
    \ \u304C N+i \u306B\u5BFE\u5FDC\n\t\t\u4E8C\u90E8\u30B0\u30E9\u30D5\u306B\u306A\
    \u308B\u3001\u95A2\u7BC0\u70B9\u3067\u306A\u3044\u9802\u70B9\u304CH\u306E\u8449\
    \u306B\u306A\u308B\n*/\ntemplate<class E>\nstruct Articulation{\n\tusing P = pair<int,E>;\n\
    \n\t//in\n\tVV<E> G;\n\n\t//out\n\tV<int> arts;\n\tVV<P> biedges;\n\n\t//out(constructCompressedGraph)\n\
    \tVV<int> H;\n\n\n\t//tmp\n\tV<int> ord,low;\n\tint I;\n\tstack<P> st;\n\n\tArticulation(const\
    \ VV<E>& G_):G(G_){\t//calc arts,biedges\n\t\tint N = G.size();\n\t\tord = low\
    \ = V<int>(N);\n\t\tI = 0;\n\n\t\trep(i,N) if(ord[i]==0){\n\t\t\twhile(!st.empty())\
    \ st.pop();\n\t\t\tdfs(i);\n\t\t}\n\t}\n\n\tvoid constructCompressedGraph(){\n\
    \t\tint N = G.size();\n\t\tint B = biedges.size();\t\t//[N,N+B)\n\n\t\tH = VV<int>(N+B);\n\
    \n\t\trep(b,B){\n\t\t\tV<int> vc;\n\t\t\tfor(P p:biedges[b]){\n\t\t\t\tint from\
    \ = p.fs;\n\t\t\t\tint to = p.sc.to;\n\t\t\t\tvc.pb(from);\n\t\t\t\tvc.pb(to);\n\
    \t\t\t}\n\t\t\tmkuni(vc);\n\t\t\tfor(int v:vc){\n\t\t\t\tH[N+b].pb(v);\n\t\t\t\
    \tH[v].pb(N+b);\n\t\t\t}\n\t\t}\n\t}\n\n\tvoid dfs(int v,int p = -1){\n\t\tord[v]=++I;\n\
    \t\tlow[v]=ord[v];\n\t\tint c=0;\n\t\tbool isart=0;\n\t\tfor(auto& e:G[v]) if(e.to!=p){\n\
    \t\t\tint u = e.to;\n\t\t\tif(ord[u]<ord[v]) st.push(P(v,e));\n\t\t\tif(ord[u])\
    \ chmin(low[v],ord[u]);\t//back edge\n\t\t\telse{\n\t\t\t\tdfs(u,v);\n\t\t\t\t\
    c++;\n\t\t\t\tchmin(low[v],low[u]);\n\t\t\t\tif(low[u]>=ord[v]){\n\t\t\t\t\tisart\
    \ = 1;\n\t\t\t\t\tvector<P> vp;\n\t\t\t\t\twhile(true){\n\t\t\t\t\t\tP p=st.top();st.pop();\n\
    \t\t\t\t\t\tvp.pb(p);\n\t\t\t\t\t\tif(p.fs==v && p.sc.to==u) break;\n\t\t\t\t\t\
    }\n\t\t\t\t\tbiedges.pb(vp);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif(p<0) isart=(c>1);\n\
    \t\tif(isart) arts.pb(v);\n\t}\n\t\n};\nstruct Edge{\n\tint to;\n\tfriend ostream&\
    \ operator<<(ostream& o,const Edge& e){return o<<e.to;}\n};\n"
  code: "/*\n\t\u95A2\u7BC0\u70B9\n\tord[v]: dfs\u68EE\u3067\u306Eid\n\tlow[v]: lowlink,\
    \ dfs\u6728\u3067\u5B50\u306B\u3044\u304F + \u4E00\u56DE\u3060\u3051\u5F8C\u9000\
    \u8FBA\u3067\u4E0A\u306B\u4E0A\u304C\u308C\u308B \u3068\u304D\u306B\u305F\u3069\
    \u308A\u3064\u3051\u308Bord \u306Emin\n\tv\u304C\u95A2\u7BC0\u70B9\u21D4\n\tv\u304C\
    dfs\u6728\u306Eroot \u304B\u3064 \u6B21\u6570\u304C2\u4EE5\u4E0A or\n\tv\u304C\
    dfs\u6728\u306Eroot\u3067\u306A\u3044 \u304B\u3064 \u3042\u308B\u5B50u\u304C\u5B58\
    \u5728\u3057, ord[v]<=low[u]\n\tord[v]=low[u]\u3067\u3082\u95A2\u7BC0\u70B9(\u81EA\
    \u5206\u306B\u30B5\u30A4\u30AF\u30EB\u304C\u623B\u3063\u3066\u304D\u305F\u3068\
    \u3057\u3066\u3082\u4E0A\u306B\u306F\u3044\u3051\u306A\u3044\u306E\u3067\u307E\
    \u3060\u95A2\u7BC0\u70B9\u306A\u307E\u307E) \u306A\u3053\u3068\u306B\u6CE8\u610F\
    \n\n\t\u4E8C\u91CD(\u9802\u70B9)\u9023\u7D50\u6210\u5206\n\t\u6A4B\u306B\u5BFE\
    \u3059\u308B\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u306E\u3088\u3046\u306B\
    \u3001\u4E8C\u91CD\u9023\u7D50\u6210\u5206\u304C\u5B9A\u7FA9\u3055\u308C\u308B\
    \u3002\n\t\u8FBA\u96C6\u5408E\u304C\u4E8C\u91CD\u9023\u7D50\u21D4E\u3067\u8A98\
    \u5C0E\u3055\u308C\u308B\u30B0\u30E9\u30D5\u304C\u95A2\u7BC0\u70B9\u3092\u6301\
    \u305F\u306A\u3044\n\n\n\t\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
    \u304C\u6728\u3092\u4F5C\u308B\u3088\u3046\u306B\u3001\u95A2\u7BC0\u70B9\u3068\
    \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u3092\u9802\u70B9\u3068\u3057\u3066\
    \u6301\u3064\u6728\u307F\u305F\u3044\u306A\u306E\u3092\u4F5C\u308C\u308B\n\tjoi/spring/12/sokoban.cpp\
    \ \u5C71\u6912\n\n\t\u591A\u91CD\u8FBA\u306F\u5BFE\u5FDC\u3057\u3066\u3044\u306A\
    \u3044\u3001\u591A\u91CD\u8FBA\u304C\u3042\u3063\u3066\u3082\u95A2\u7BC0\u70B9\
    \u304B\u3069\u3046\u304B\u306B\u306F\u95A2\u308F\u308A\u304C\u306A\u3044\u3002\
    \n\t\u5BFE\u5FDC\u3057\u305F\u3044\u306A\u3089Edge\u306Bid\u307F\u305F\u3044\u306A\
    \u306E\u3092\u6301\u305F\u305B\u3066\u304A\u3044\u3066if\u6587\u306E\u5224\u5B9A\
    \u3092\u305D\u308C\u3067\u3084\u308B\n\n\tArticulation Art(G);\n\tArt.constructCompressedGraph();\n\
    \tVV<int> H = Art.H;\n\t\n\tH\u306F\u6728\u3067\u3042\u3063\u3066\u3001\n\t\t\
    - \u3082\u3068\u306E\u9802\u70B9 v \u304C v \u306B\u5BFE\u5FDC\n\t\t- biedges[i]\
    \ \u304C N+i \u306B\u5BFE\u5FDC\n\t\t\u4E8C\u90E8\u30B0\u30E9\u30D5\u306B\u306A\
    \u308B\u3001\u95A2\u7BC0\u70B9\u3067\u306A\u3044\u9802\u70B9\u304CH\u306E\u8449\
    \u306B\u306A\u308B\n*/\ntemplate<class E>\nstruct Articulation{\n\tusing P = pair<int,E>;\n\
    \n\t//in\n\tVV<E> G;\n\n\t//out\n\tV<int> arts;\n\tVV<P> biedges;\n\n\t//out(constructCompressedGraph)\n\
    \tVV<int> H;\n\n\n\t//tmp\n\tV<int> ord,low;\n\tint I;\n\tstack<P> st;\n\n\tArticulation(const\
    \ VV<E>& G_):G(G_){\t//calc arts,biedges\n\t\tint N = G.size();\n\t\tord = low\
    \ = V<int>(N);\n\t\tI = 0;\n\n\t\trep(i,N) if(ord[i]==0){\n\t\t\twhile(!st.empty())\
    \ st.pop();\n\t\t\tdfs(i);\n\t\t}\n\t}\n\n\tvoid constructCompressedGraph(){\n\
    \t\tint N = G.size();\n\t\tint B = biedges.size();\t\t//[N,N+B)\n\n\t\tH = VV<int>(N+B);\n\
    \n\t\trep(b,B){\n\t\t\tV<int> vc;\n\t\t\tfor(P p:biedges[b]){\n\t\t\t\tint from\
    \ = p.fs;\n\t\t\t\tint to = p.sc.to;\n\t\t\t\tvc.pb(from);\n\t\t\t\tvc.pb(to);\n\
    \t\t\t}\n\t\t\tmkuni(vc);\n\t\t\tfor(int v:vc){\n\t\t\t\tH[N+b].pb(v);\n\t\t\t\
    \tH[v].pb(N+b);\n\t\t\t}\n\t\t}\n\t}\n\n\tvoid dfs(int v,int p = -1){\n\t\tord[v]=++I;\n\
    \t\tlow[v]=ord[v];\n\t\tint c=0;\n\t\tbool isart=0;\n\t\tfor(auto& e:G[v]) if(e.to!=p){\n\
    \t\t\tint u = e.to;\n\t\t\tif(ord[u]<ord[v]) st.push(P(v,e));\n\t\t\tif(ord[u])\
    \ chmin(low[v],ord[u]);\t//back edge\n\t\t\telse{\n\t\t\t\tdfs(u,v);\n\t\t\t\t\
    c++;\n\t\t\t\tchmin(low[v],low[u]);\n\t\t\t\tif(low[u]>=ord[v]){\n\t\t\t\t\tisart\
    \ = 1;\n\t\t\t\t\tvector<P> vp;\n\t\t\t\t\twhile(true){\n\t\t\t\t\t\tP p=st.top();st.pop();\n\
    \t\t\t\t\t\tvp.pb(p);\n\t\t\t\t\t\tif(p.fs==v && p.sc.to==u) break;\n\t\t\t\t\t\
    }\n\t\t\t\t\tbiedges.pb(vp);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif(p<0) isart=(c>1);\n\
    \t\tif(isart) arts.pb(v);\n\t}\n\t\n};\nstruct Edge{\n\tint to;\n\tfriend ostream&\
    \ operator<<(ostream& o,const Edge& e){return o<<e.to;}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/articulation.cpp
  requiredBy: []
  timestamp: '2020-02-15 12:19:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/articulation.cpp
layout: document
redirect_from:
- /library/graph/articulation.cpp
- /library/graph/articulation.cpp.html
title: graph/articulation.cpp
---
