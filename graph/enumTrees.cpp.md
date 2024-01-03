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
    - https://oeis.org/A000081
  bundledCode: "#line 1 \"graph/enumTrees.cpp\"\n/*\n\tunlabeled rooted trees with\
    \ N vertices\n\thttps://oeis.org/A000081\n\t\tf(10) = 719, f(15) = 87811, f(20)\
    \ = 12826228\n\t\tn = 20 \u3067 7s \u304F\u3089\u3044\n\t\u8FBA\u306E\u7AEF\u70B9\
    \u306F\u6839\u306B\u8FD1\u3044\u307B\u3046\u304C\u5024\u304C\u5C0F\u3055\u3044\
    \ \u7279\u306B\u3001\u6839\u306F\u5E38\u306B0\n*/\nVV<P> enumUnlabeledRootedTrees(int\
    \ N){\n\tusing P = pair<int,int>;\n\tV<V<V<P>>> ts(N+1);\n\trep1(n,N){\n\t\tV<V<V<P>>>\
    \ sub(n+1); sub[1].pb(V<P>());\n\t\trep1(m,n-1) for(auto t: ts[m]){\n\t\t\tper1(i,n-m){\n\
    \t\t\t\tfor(auto f: sub[i]){\n\t\t\t\t\tV<P> nf = f;\n\t\t\t\t\tfor(int ni=i+m;ni<=n;ni+=m){\n\
    \t\t\t\t\t\tint off = ni-m;\n\t\t\t\t\t\tfor(auto& [x,y]: t) nf.eb(x+off,y+off);\n\
    \t\t\t\t\t\tnf.eb(0,off);\n\t\t\t\t\t\tsub[ni].pb(nf);\n\t\t\t\t\t}\n\t\t\t\t\
    }\n\t\t\t}\n\t\t}\n\t\tts[n] = sub[n];\n\t\t// show(\"-------------\"); show(n);\n\
    \t\t// show(si(ts[n]));\n\t\t// for(auto t: ts[n]) cout << t << endl;\n\t}\n\t\
    return ts[n];\n}\n\n\n/*\n\tlabeled unrooted trees with N vertices\n\tf(N) = N^{N-2}\
    \ N = 9 \u304F\u3089\u3044\u3067\u9650\u754C\n*/\nV<VV<int>> enumTrees(int N){\n\
    \tassert(N >= 1);\n\tV<VV<int>> trees;\n\tif(N == 1){\n\t\tVV<int> T(N);\n\t\t\
    trees.pb(T);\n\t\treturn trees;\n\t}\n\tV<int> prufer(N-2);\n\tauto dfs = [&](auto\
    \ self,int t) -> void {\n\t\tif(t == N-2){\n\t\t\tVV<int> T(N);\n\t\t\tV<int>\
    \ deg(N,1);\n\t\t\tfor(int v: prufer) deg[v]++;\n\t\t\trep(k,N-2){\n\t\t\t\trep(v,N)\
    \ if(deg[v] == 1){\n\t\t\t\t\tT[v].pb(prufer[k]);\n\t\t\t\t\tT[prufer[k]].pb(v);\n\
    \t\t\t\t\tdeg[v]--; deg[prufer[k]]--;\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\
    \t\tV<int> vs;\n\t\t\trep(v,N) if(deg[v]) vs.pb(v);\n\t\t\tassert(si(vs) == 2);\n\
    \t\t\tT[vs[0]].pb(vs[1]);\n\t\t\tT[vs[1]].pb(vs[0]);\n\t\t\ttrees.pb(T);\n\t\t\
    \treturn;\n\t\t}\n\t\trep(i,N){\n\t\t\tprufer[t] = i;\n\t\t\tself(self,t+1);\n\
    \t\t}\n\t};\n\tdfs(dfs,0);\n\treturn trees;\n}\n\n"
  code: "/*\n\tunlabeled rooted trees with N vertices\n\thttps://oeis.org/A000081\n\
    \t\tf(10) = 719, f(15) = 87811, f(20) = 12826228\n\t\tn = 20 \u3067 7s \u304F\u3089\
    \u3044\n\t\u8FBA\u306E\u7AEF\u70B9\u306F\u6839\u306B\u8FD1\u3044\u307B\u3046\u304C\
    \u5024\u304C\u5C0F\u3055\u3044 \u7279\u306B\u3001\u6839\u306F\u5E38\u306B0\n*/\n\
    VV<P> enumUnlabeledRootedTrees(int N){\n\tusing P = pair<int,int>;\n\tV<V<V<P>>>\
    \ ts(N+1);\n\trep1(n,N){\n\t\tV<V<V<P>>> sub(n+1); sub[1].pb(V<P>());\n\t\trep1(m,n-1)\
    \ for(auto t: ts[m]){\n\t\t\tper1(i,n-m){\n\t\t\t\tfor(auto f: sub[i]){\n\t\t\t\
    \t\tV<P> nf = f;\n\t\t\t\t\tfor(int ni=i+m;ni<=n;ni+=m){\n\t\t\t\t\t\tint off\
    \ = ni-m;\n\t\t\t\t\t\tfor(auto& [x,y]: t) nf.eb(x+off,y+off);\n\t\t\t\t\t\tnf.eb(0,off);\n\
    \t\t\t\t\t\tsub[ni].pb(nf);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tts[n]\
    \ = sub[n];\n\t\t// show(\"-------------\"); show(n);\n\t\t// show(si(ts[n]));\n\
    \t\t// for(auto t: ts[n]) cout << t << endl;\n\t}\n\treturn ts[n];\n}\n\n\n/*\n\
    \tlabeled unrooted trees with N vertices\n\tf(N) = N^{N-2} N = 9 \u304F\u3089\u3044\
    \u3067\u9650\u754C\n*/\nV<VV<int>> enumTrees(int N){\n\tassert(N >= 1);\n\tV<VV<int>>\
    \ trees;\n\tif(N == 1){\n\t\tVV<int> T(N);\n\t\ttrees.pb(T);\n\t\treturn trees;\n\
    \t}\n\tV<int> prufer(N-2);\n\tauto dfs = [&](auto self,int t) -> void {\n\t\t\
    if(t == N-2){\n\t\t\tVV<int> T(N);\n\t\t\tV<int> deg(N,1);\n\t\t\tfor(int v: prufer)\
    \ deg[v]++;\n\t\t\trep(k,N-2){\n\t\t\t\trep(v,N) if(deg[v] == 1){\n\t\t\t\t\t\
    T[v].pb(prufer[k]);\n\t\t\t\t\tT[prufer[k]].pb(v);\n\t\t\t\t\tdeg[v]--; deg[prufer[k]]--;\n\
    \t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\tV<int> vs;\n\t\t\trep(v,N) if(deg[v])\
    \ vs.pb(v);\n\t\t\tassert(si(vs) == 2);\n\t\t\tT[vs[0]].pb(vs[1]);\n\t\t\tT[vs[1]].pb(vs[0]);\n\
    \t\t\ttrees.pb(T);\n\t\t\treturn;\n\t\t}\n\t\trep(i,N){\n\t\t\tprufer[t] = i;\n\
    \t\t\tself(self,t+1);\n\t\t}\n\t};\n\tdfs(dfs,0);\n\treturn trees;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/enumTrees.cpp
  requiredBy: []
  timestamp: '2024-01-03 15:59:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/enumTrees.cpp
layout: document
redirect_from:
- /library/graph/enumTrees.cpp
- /library/graph/enumTrees.cpp.html
title: graph/enumTrees.cpp
---
