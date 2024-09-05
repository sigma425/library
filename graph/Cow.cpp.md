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
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2633
  bundledCode: "#line 1 \"graph/Cow.cpp\"\n/*\n\t\u725B\u30B2\u30FC\n\tx_t - x_s <=\
    \ const \u306A\u308B\u5F0F\u304C\u3044\u3063\u3071\u3044\u3042\u3063\u3066\u3001\
    \u6761\u4EF6\u3092\u307F\u305F\u3059\u3088\u3046\u306B\u5272\u308A\u632F\u308C\
    \u308B\u304B?\n\tinitializer Cow(\u9802\u70B9\u6570(\u5909\u6570\u6570))\n\tsatisfiable()\
    \ \u304C 1 \u3092\u8FD4\u3057\u3066\u304D\u305F\u3089 vector<D> d \u304C\u6761\
    \u4EF6\u3092\u6E80\u305F\u3059\u5272\u5F53\u306B\u306A\u3063\u3066\u3044\u308B\
    \n\n\tx_v <= 3 \u307F\u305F\u3044\u306A\u306E\u306F\u9802\u70B9Z (=0) \u3092\u4F5C\
    \u3063\u3066\u3001\u59CB\u70B9\u3092Z\u306B\u3059\u308B\u3068\u3088\u3044\n\n\t\
    verified at http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2633 (Cellular\
    \ Automaton)\n\n*/\nstruct Cow{\n\tusing D = ll;\n\tconst D inf = 1e18;\n\tstruct\
    \ Edge{\n\t\tint to;\n\t\tD cost;\n\t};\n\tint N,M;\n\tvector<vector<Edge>> G;\n\
    \tvector<D> d;\n\n\tCow(int N_):N(N_),G(N_),d(N,inf){}\n\n\t// correspond to t-s\
    \ <= c\n\tvoid add_edge(int t,int s,D c){\n\t\tG[s].pb({t,c});\n\t}\n\t// clow\
    \ <= t-s <= chigh\n\tvoid add_edge(int t,int s,D clow,D chigh){\n\t\tadd_edge(t,s,chigh);\n\
    \t\tadd_edge(s,t,-clow);\n\t}\n\t/*\n\t\treturn the inequalities have a valid\
    \ assignment\n\t\tif satisfiable, minimize d[T]-d[S]\n\n\t\tnegative cycle   \
    \ <=> unsatisfiable\n\t\td[T] - d[S] = inf <=> feasible unboundedly\n\n\t\td[S]=0\n\
    \n\t\tT\u306B\u3088\u3089\u306A\u304F\u306A\u3044?(\u6C17\u3065\u304D)\n\t\tS\u304B\
    \u3089\u5230\u9054\u3067\u304D\u306A\u3044\u90E8\u5206\u3067\u8CA0\u9589\u8DEF\
    \u304C\u3042\u3063\u305F\u3068\u3057\u3066\u3082\u3061\u3083\u3093\u3068\u691C\
    \u51FA\u3055\u308C\u308B\n\t*/\n\tbool satisfiable(int S = 0){\n\t\tvector<int>\
    \ prev(N);\n\t\td[S] = 0;\n\t\trep(ph,N){\n\t\t\tbool update = 0;\n\t\t\tint v\
    \ = -1;\n\t\t\trep(s,N) for(auto e:G[s]){\n\t\t\t\tint t = e.to;\n\t\t\t\tD cost\
    \ = e.cost;\n\t\t\t\tif(d[s]+cost < d[t]){\n\t\t\t\t\tupdate=1;\n\t\t\t\t\tv =\
    \ t;\n\t\t\t\t\td[t] = d[s]+cost;\n\t\t\t\t\tprev[t] = s;\n\t\t\t\t}\n\t\t\t}\n\
    \t\t\tif(ph == N-1 && update){\n\t\t\t\t// vector<int> path;\n\t\t\t\t// path.pb(v);\n\
    \t\t\t\t// int u = v;\n\t\t\t\t// do{\n\t\t\t\t// \tshow(u);\n\t\t\t\t// \tu =\
    \ prev[u];\n\t\t\t\t// \tpath.pb(u);\n\t\t\t\t// }while(u!=v);\n\t\t\t\t// reverse(all(path));\n\
    \t\t\t\t// show(path);\n\t\t\t\treturn 0;\n\t\t\t}\n\t\t\tif(!update) break;\n\
    \t\t}\n\t\treturn 1;\n\t}\n};\n"
  code: "/*\n\t\u725B\u30B2\u30FC\n\tx_t - x_s <= const \u306A\u308B\u5F0F\u304C\u3044\
    \u3063\u3071\u3044\u3042\u3063\u3066\u3001\u6761\u4EF6\u3092\u307F\u305F\u3059\
    \u3088\u3046\u306B\u5272\u308A\u632F\u308C\u308B\u304B?\n\tinitializer Cow(\u9802\
    \u70B9\u6570(\u5909\u6570\u6570))\n\tsatisfiable() \u304C 1 \u3092\u8FD4\u3057\
    \u3066\u304D\u305F\u3089 vector<D> d \u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\
    \u5272\u5F53\u306B\u306A\u3063\u3066\u3044\u308B\n\n\tx_v <= 3 \u307F\u305F\u3044\
    \u306A\u306E\u306F\u9802\u70B9Z (=0) \u3092\u4F5C\u3063\u3066\u3001\u59CB\u70B9\
    \u3092Z\u306B\u3059\u308B\u3068\u3088\u3044\n\n\tverified at http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2633\
    \ (Cellular Automaton)\n\n*/\nstruct Cow{\n\tusing D = ll;\n\tconst D inf = 1e18;\n\
    \tstruct Edge{\n\t\tint to;\n\t\tD cost;\n\t};\n\tint N,M;\n\tvector<vector<Edge>>\
    \ G;\n\tvector<D> d;\n\n\tCow(int N_):N(N_),G(N_),d(N,inf){}\n\n\t// correspond\
    \ to t-s <= c\n\tvoid add_edge(int t,int s,D c){\n\t\tG[s].pb({t,c});\n\t}\n\t\
    // clow <= t-s <= chigh\n\tvoid add_edge(int t,int s,D clow,D chigh){\n\t\tadd_edge(t,s,chigh);\n\
    \t\tadd_edge(s,t,-clow);\n\t}\n\t/*\n\t\treturn the inequalities have a valid\
    \ assignment\n\t\tif satisfiable, minimize d[T]-d[S]\n\n\t\tnegative cycle   \
    \ <=> unsatisfiable\n\t\td[T] - d[S] = inf <=> feasible unboundedly\n\n\t\td[S]=0\n\
    \n\t\tT\u306B\u3088\u3089\u306A\u304F\u306A\u3044?(\u6C17\u3065\u304D)\n\t\tS\u304B\
    \u3089\u5230\u9054\u3067\u304D\u306A\u3044\u90E8\u5206\u3067\u8CA0\u9589\u8DEF\
    \u304C\u3042\u3063\u305F\u3068\u3057\u3066\u3082\u3061\u3083\u3093\u3068\u691C\
    \u51FA\u3055\u308C\u308B\n\t*/\n\tbool satisfiable(int S = 0){\n\t\tvector<int>\
    \ prev(N);\n\t\td[S] = 0;\n\t\trep(ph,N){\n\t\t\tbool update = 0;\n\t\t\tint v\
    \ = -1;\n\t\t\trep(s,N) for(auto e:G[s]){\n\t\t\t\tint t = e.to;\n\t\t\t\tD cost\
    \ = e.cost;\n\t\t\t\tif(d[s]+cost < d[t]){\n\t\t\t\t\tupdate=1;\n\t\t\t\t\tv =\
    \ t;\n\t\t\t\t\td[t] = d[s]+cost;\n\t\t\t\t\tprev[t] = s;\n\t\t\t\t}\n\t\t\t}\n\
    \t\t\tif(ph == N-1 && update){\n\t\t\t\t// vector<int> path;\n\t\t\t\t// path.pb(v);\n\
    \t\t\t\t// int u = v;\n\t\t\t\t// do{\n\t\t\t\t// \tshow(u);\n\t\t\t\t// \tu =\
    \ prev[u];\n\t\t\t\t// \tpath.pb(u);\n\t\t\t\t// }while(u!=v);\n\t\t\t\t// reverse(all(path));\n\
    \t\t\t\t// show(path);\n\t\t\t\treturn 0;\n\t\t\t}\n\t\t\tif(!update) break;\n\
    \t\t}\n\t\treturn 1;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/Cow.cpp
  requiredBy: []
  timestamp: '2024-09-05 20:32:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/Cow.cpp
layout: document
redirect_from:
- /library/graph/Cow.cpp
- /library/graph/Cow.cpp.html
title: graph/Cow.cpp
---
