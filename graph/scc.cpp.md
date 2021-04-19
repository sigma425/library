---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_oj/scc.test.cpp
    title: test_oj/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/scc.cpp\"\n/*\r\n    SCC O(M+N)\r\n    id[v] = v \u306E\
    \ \u9023\u7D50\u6210\u5206\u306E id\r\n    groups[i] : i\u756A\u76EE\u306E\u9023\
    \u7D50\u6210\u5206, \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\r\n*/\r\ntemplate\
    \ <class E>\r\nstruct SCC{\r\n\tV<int> id;\r\n\tVV<int> groups;\r\n\r\n\tint N;\r\
    \n\tVV<E> G;\r\n\tV<int> ord,low;\r\n\tV<bool> inS;\r\n\tV<int> st;\r\n    int\
    \ I=0;\r\n\r\n\tvoid dfs(int v){\r\n\t\tord[v] = low[v] = I++;\r\n\t\tst.pb(v);\
    \ inS[v] = true;\r\n\t\tfor(auto e: G[v]){\r\n\t\t\tint u = e.to;\r\n\t\t\tif(ord[u]\
    \ == -1){\r\n\t\t\t\tdfs(u);\r\n\t\t\t\tchmin(low[v],low[u]);\r\n\t\t\t}else if(inS[u]){\r\
    \n\t\t\t\tchmin(low[v],ord[u]);\r\n\t\t\t}\r\n\t\t}\r\n\t\tif(low[v] == ord[v]){\r\
    \n\t\t\tV<int> group;\r\n\t\t\twhile(true){\r\n\t\t\t\tint w = st.back(); st.pop_back();\r\
    \n\t\t\t\tinS[w] = false;\r\n\t\t\t\tgroup.pb(w);\r\n\t\t\t\tif(w == v) break;\r\
    \n\t\t\t}\r\n\t\t\tgroups.pb(group);\r\n\t\t}\r\n\t}\r\n\tSCC(const VV<E>& G_)\
    \ : N(G_.size()), G(G_), ord(N,-1), low(N), inS(N){\r\n        id = V<int>(N);\r\
    \n\t\trep(i,N) if(ord[i] == -1) dfs(i);\r\n\t\treverse(all(groups));\r\n\t\trep(i,groups.size()){\r\
    \n\t\t\tfor(int v: groups[i]) id[v] = i;\r\n\t\t}\r\n\t}\r\n};\n"
  code: "/*\r\n    SCC O(M+N)\r\n    id[v] = v \u306E \u9023\u7D50\u6210\u5206\u306E\
    \ id\r\n    groups[i] : i\u756A\u76EE\u306E\u9023\u7D50\u6210\u5206, \u30C8\u30DD\
    \u30ED\u30B8\u30AB\u30EB\u9806\r\n*/\r\ntemplate <class E>\r\nstruct SCC{\r\n\t\
    V<int> id;\r\n\tVV<int> groups;\r\n\r\n\tint N;\r\n\tVV<E> G;\r\n\tV<int> ord,low;\r\
    \n\tV<bool> inS;\r\n\tV<int> st;\r\n    int I=0;\r\n\r\n\tvoid dfs(int v){\r\n\
    \t\tord[v] = low[v] = I++;\r\n\t\tst.pb(v); inS[v] = true;\r\n\t\tfor(auto e:\
    \ G[v]){\r\n\t\t\tint u = e.to;\r\n\t\t\tif(ord[u] == -1){\r\n\t\t\t\tdfs(u);\r\
    \n\t\t\t\tchmin(low[v],low[u]);\r\n\t\t\t}else if(inS[u]){\r\n\t\t\t\tchmin(low[v],ord[u]);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\tif(low[v] == ord[v]){\r\n\t\t\tV<int> group;\r\n\t\t\
    \twhile(true){\r\n\t\t\t\tint w = st.back(); st.pop_back();\r\n\t\t\t\tinS[w]\
    \ = false;\r\n\t\t\t\tgroup.pb(w);\r\n\t\t\t\tif(w == v) break;\r\n\t\t\t}\r\n\
    \t\t\tgroups.pb(group);\r\n\t\t}\r\n\t}\r\n\tSCC(const VV<E>& G_) : N(G_.size()),\
    \ G(G_), ord(N,-1), low(N), inS(N){\r\n        id = V<int>(N);\r\n\t\trep(i,N)\
    \ if(ord[i] == -1) dfs(i);\r\n\t\treverse(all(groups));\r\n\t\trep(i,groups.size()){\r\
    \n\t\t\tfor(int v: groups[i]) id[v] = i;\r\n\t\t}\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/scc.cpp
  requiredBy: []
  timestamp: '2019-10-21 15:19:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_oj/scc.test.cpp
documentation_of: graph/scc.cpp
layout: document
redirect_from:
- /library/graph/scc.cpp
- /library/graph/scc.cpp.html
title: graph/scc.cpp
---
