---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/enumTrees.cpp\"\n\n// labeled unrooted N^{N-2}\n//\
    \ N = 1..9 \u304F\u3089\u3044\u3067\u9650\u754C \u624B\u5143\u5B9F\u9A13\u7528\
    \u304B\u306A?\n// unlabeled\u306F\u3082\u3063\u3068\u5C11\u306A\u3044\u304B\u3089\
    \u3001\u5225\u306B\u7528\u610F\u3057\u305F\u3044\u3068\u3044\u3046\u6C17\u6301\
    \u3061\u306F\u3042\u308B\nV<VV<int>> enumTrees(int N){\n\tassert(N >= 1);\n\t\
    V<VV<int>> trees;\n\tif(N == 1){\n\t\tVV<int> T(N);\n\t\ttrees.pb(T);\n\t\treturn\
    \ trees;\n\t}\n\tV<int> prufer(N-2);\n\tauto dfs = [&](auto self,int t)->void{\n\
    \t\tif(t == N-2){\n\t\t\tVV<int> T(N);\n\t\t\tV<int> deg(N,1);\n\t\t\tfor(int\
    \ v: prufer) deg[v]++;\n\t\t\trep(k,N-2){\n\t\t\t\trep(v,N) if(deg[v] == 1){\n\
    \t\t\t\t\tT[v].pb(prufer[k]);\n\t\t\t\t\tT[prufer[k]].pb(v);\n\t\t\t\t\tdeg[v]--;\
    \ deg[prufer[k]]--;\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\tV<int> vs;\n\t\
    \t\trep(v,N) if(deg[v]) vs.pb(v);\n\t\t\tassert(si(vs) == 2);\n\t\t\tT[vs[0]].pb(vs[1]);\n\
    \t\t\tT[vs[1]].pb(vs[0]);\n\t\t\ttrees.pb(T);\n\t\t\treturn;\n\t\t}\n\t\trep(i,N){\n\
    \t\t\tprufer[t] = i;\n\t\t\tself(self,t+1);\n\t\t}\n\t};\n\tdfs(dfs,0);\n\treturn\
    \ trees;\n}\n"
  code: "\n// labeled unrooted N^{N-2}\n// N = 1..9 \u304F\u3089\u3044\u3067\u9650\
    \u754C \u624B\u5143\u5B9F\u9A13\u7528\u304B\u306A?\n// unlabeled\u306F\u3082\u3063\
    \u3068\u5C11\u306A\u3044\u304B\u3089\u3001\u5225\u306B\u7528\u610F\u3057\u305F\
    \u3044\u3068\u3044\u3046\u6C17\u6301\u3061\u306F\u3042\u308B\nV<VV<int>> enumTrees(int\
    \ N){\n\tassert(N >= 1);\n\tV<VV<int>> trees;\n\tif(N == 1){\n\t\tVV<int> T(N);\n\
    \t\ttrees.pb(T);\n\t\treturn trees;\n\t}\n\tV<int> prufer(N-2);\n\tauto dfs =\
    \ [&](auto self,int t)->void{\n\t\tif(t == N-2){\n\t\t\tVV<int> T(N);\n\t\t\t\
    V<int> deg(N,1);\n\t\t\tfor(int v: prufer) deg[v]++;\n\t\t\trep(k,N-2){\n\t\t\t\
    \trep(v,N) if(deg[v] == 1){\n\t\t\t\t\tT[v].pb(prufer[k]);\n\t\t\t\t\tT[prufer[k]].pb(v);\n\
    \t\t\t\t\tdeg[v]--; deg[prufer[k]]--;\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\
    \t\tV<int> vs;\n\t\t\trep(v,N) if(deg[v]) vs.pb(v);\n\t\t\tassert(si(vs) == 2);\n\
    \t\t\tT[vs[0]].pb(vs[1]);\n\t\t\tT[vs[1]].pb(vs[0]);\n\t\t\ttrees.pb(T);\n\t\t\
    \treturn;\n\t\t}\n\t\trep(i,N){\n\t\t\tprufer[t] = i;\n\t\t\tself(self,t+1);\n\
    \t\t}\n\t};\n\tdfs(dfs,0);\n\treturn trees;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/enumTrees.cpp
  requiredBy: []
  timestamp: '2020-11-28 04:24:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/enumTrees.cpp
layout: document
redirect_from:
- /library/graph/enumTrees.cpp
- /library/graph/enumTrees.cpp.html
title: graph/enumTrees.cpp
---
