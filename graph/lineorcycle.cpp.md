---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"graph/lineorcycle.cpp\"\ntemplate<class E>\nvoid solve(const\
    \ VV<int>& G){\n\tint N = G.size();\n\tauto do_isolated = [&](int v){\n\n\t};\n\
    \tauto do_line = [&](V<int> vs){\n\n\t};\n\tauto do_cycle = [&](V<int> vs){\n\n\
    \t};\n\tV<bool> used(N);\n\trep(i,N) if(!used[i]){\n\t\tassert(si(G[i])<=2);\n\
    \t\tif(si(G[i]) == 0){\n\t\t\tdo_isolated(i);\n\t\t\tused[i] = true;\n\t\t\tcontinue;\n\
    \t\t}\n\t\tint v = i;\n\t\tint p = G[v][0];\n\t\twhile(si(G[v]) == 2){\n\t\t\t\
    int nv = G[v][0]^G[v][1]^p;\n\t\t\tp = v; v = nv;\n\t\t\tif(v == i) break;\n\t\
    \t}\n\t\tif(si(G[v]) == 1){\t//line\n\t\t\tvector<int> vs;\n\t\t\tvs.pb(v); used[v]=1;\n\
    \t\t\tint p = v;\n\t\t\tv = G[v][0];\n\t\t\twhile(si(G[v]) == 2){\n\t\t\t\tvs.pb(v);\
    \ used[v]=1;\n\t\t\t\tint nv = G[v][0]^G[v][1]^p;\n\t\t\t\tp = v; v = nv;\n\t\t\
    \t}\n\t\t\tvs.pb(v);used[v]=1;\n\t\t\tdo_line(vs);\n\t\t}else{\t\t\t\t//cycle\n\
    \t\t\tvector<int> vs;\n\t\t\tint p = G[v][0];\n\t\t\twhile(!used[v]){\n\t\t\t\t\
    vs.pb(v);used[v]=1;\n\t\t\t\tint nv = G[v][0]^G[v][1]^p;\n\t\t\t\tp = v; v = nv;\n\
    \t\t\t}\n\t\t\tdo_cycle(vs);\n\t\t}\n\t}\n}\n"
  code: "template<class E>\nvoid solve(const VV<int>& G){\n\tint N = G.size();\n\t\
    auto do_isolated = [&](int v){\n\n\t};\n\tauto do_line = [&](V<int> vs){\n\n\t\
    };\n\tauto do_cycle = [&](V<int> vs){\n\n\t};\n\tV<bool> used(N);\n\trep(i,N)\
    \ if(!used[i]){\n\t\tassert(si(G[i])<=2);\n\t\tif(si(G[i]) == 0){\n\t\t\tdo_isolated(i);\n\
    \t\t\tused[i] = true;\n\t\t\tcontinue;\n\t\t}\n\t\tint v = i;\n\t\tint p = G[v][0];\n\
    \t\twhile(si(G[v]) == 2){\n\t\t\tint nv = G[v][0]^G[v][1]^p;\n\t\t\tp = v; v =\
    \ nv;\n\t\t\tif(v == i) break;\n\t\t}\n\t\tif(si(G[v]) == 1){\t//line\n\t\t\t\
    vector<int> vs;\n\t\t\tvs.pb(v); used[v]=1;\n\t\t\tint p = v;\n\t\t\tv = G[v][0];\n\
    \t\t\twhile(si(G[v]) == 2){\n\t\t\t\tvs.pb(v); used[v]=1;\n\t\t\t\tint nv = G[v][0]^G[v][1]^p;\n\
    \t\t\t\tp = v; v = nv;\n\t\t\t}\n\t\t\tvs.pb(v);used[v]=1;\n\t\t\tdo_line(vs);\n\
    \t\t}else{\t\t\t\t//cycle\n\t\t\tvector<int> vs;\n\t\t\tint p = G[v][0];\n\t\t\
    \twhile(!used[v]){\n\t\t\t\tvs.pb(v);used[v]=1;\n\t\t\t\tint nv = G[v][0]^G[v][1]^p;\n\
    \t\t\t\tp = v; v = nv;\n\t\t\t}\n\t\t\tdo_cycle(vs);\n\t\t}\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/lineorcycle.cpp
  requiredBy: []
  timestamp: '2020-05-17 22:45:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/lineorcycle.cpp
layout: document
redirect_from:
- /library/graph/lineorcycle.cpp
- /library/graph/lineorcycle.cpp.html
title: graph/lineorcycle.cpp
---
