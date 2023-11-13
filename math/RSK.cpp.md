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
  bundledCode: "#line 1 \"math/RSK.cpp\"\n/*\n\tRSK correspondence\n\tO(N^2)\n\tP:\
    \ \u6700\u7D42\u7684\u306ASYT\n\tQ: \u305D\u306E\u30DE\u30B9\u304C\u5897\u3048\
    \u305F\u30BF\u30A4\u30DF\u30F3\u30B0\t\n*/\npair<VV<int>,VV<int>> p2PQ(V<int>\
    \ p){\n\tint N = si(p);\n\tVV<int> P,Q;\n\trep(i,N){\n\t\tint v = p[i];\n\t\t\
    for(int h=0;;h++){\n\t\t\tif(si(P) == h){\n\t\t\t\tP.pb({});\n\t\t\t\tQ.pb({});\n\
    \t\t\t}\n\t\t\tif(P[h].empty() or P[h].back() < v){\n\t\t\t\tP[h].pb(v);\n\t\t\
    \t\tQ[h].pb(i);\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\trep(w,si(P[h])) if(P[h][w] > v){\n\
    \t\t\t\tswap(P[h][w],v);\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t}\n\treturn make_pair(P,Q);\n\
    }\nV<int> PQ2p(VV<int> P, VV<int> Q){\n\tusing pa = pair<int,int>;\n\tint N =\
    \ 0;\n\trep(i,si(P)) N += si(P[i]);\n\tV<pa> iQ(N);\n\trep(i,si(P)) rep(j,si(P[i])){\n\
    \t\tiQ[Q[i][j]] = pa(i,j);\n\t}\n\tV<int> p(N);\n\tconst int inf = 1e9;\n\tper(t,N){\n\
    \t\tint h = iQ[t].fs, w = iQ[t].sc;\n\t\tint v = P[h][w];\n\t\tP[h][w] = inf;\n\
    \t\th--;\n\t\tfor(;h>=0;h--){\n\t\t\trep(i,si(P[h])) if(P[h][i] < v){\n\t\t\t\t\
    w = i;\n\t\t\t}\n\t\t\tswap(P[h][w],v);\n\t\t}\n\t\tp[t] = v;\n\t}\n\treturn p;\n\
    }\nvoid showPQ(pair<VV<int>,VV<int>> pq){\n\tauto p = pq.fs, q = pq.sc;\n\tint\
    \ H = si(p), W = si(p[0]);\n\trep(i,H){\n\t\trep(j,W){\n\t\t\tif(j < si(p[i]))\
    \ printf(\"%2d \",p[i][j]);\n\t\t\telse printf(\"   \");\n\t\t}\n\t\tprintf(\"\
    | \");\n\t\trep(j,W){\n\t\t\tif(j < si(q[i])) printf(\"%2d \",q[i][j]);\n\t\t\t\
    else printf(\"   \");\n\t\t}\n\t\tprintf(\"\\n\");\n\t}\n\tprintf(\"\\n\");\n\
    }\n"
  code: "/*\n\tRSK correspondence\n\tO(N^2)\n\tP: \u6700\u7D42\u7684\u306ASYT\n\t\
    Q: \u305D\u306E\u30DE\u30B9\u304C\u5897\u3048\u305F\u30BF\u30A4\u30DF\u30F3\u30B0\
    \t\n*/\npair<VV<int>,VV<int>> p2PQ(V<int> p){\n\tint N = si(p);\n\tVV<int> P,Q;\n\
    \trep(i,N){\n\t\tint v = p[i];\n\t\tfor(int h=0;;h++){\n\t\t\tif(si(P) == h){\n\
    \t\t\t\tP.pb({});\n\t\t\t\tQ.pb({});\n\t\t\t}\n\t\t\tif(P[h].empty() or P[h].back()\
    \ < v){\n\t\t\t\tP[h].pb(v);\n\t\t\t\tQ[h].pb(i);\n\t\t\t\tbreak;\n\t\t\t}\n\t\
    \t\trep(w,si(P[h])) if(P[h][w] > v){\n\t\t\t\tswap(P[h][w],v);\n\t\t\t\tbreak;\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn make_pair(P,Q);\n}\nV<int> PQ2p(VV<int> P, VV<int>\
    \ Q){\n\tusing pa = pair<int,int>;\n\tint N = 0;\n\trep(i,si(P)) N += si(P[i]);\n\
    \tV<pa> iQ(N);\n\trep(i,si(P)) rep(j,si(P[i])){\n\t\tiQ[Q[i][j]] = pa(i,j);\n\t\
    }\n\tV<int> p(N);\n\tconst int inf = 1e9;\n\tper(t,N){\n\t\tint h = iQ[t].fs,\
    \ w = iQ[t].sc;\n\t\tint v = P[h][w];\n\t\tP[h][w] = inf;\n\t\th--;\n\t\tfor(;h>=0;h--){\n\
    \t\t\trep(i,si(P[h])) if(P[h][i] < v){\n\t\t\t\tw = i;\n\t\t\t}\n\t\t\tswap(P[h][w],v);\n\
    \t\t}\n\t\tp[t] = v;\n\t}\n\treturn p;\n}\nvoid showPQ(pair<VV<int>,VV<int>> pq){\n\
    \tauto p = pq.fs, q = pq.sc;\n\tint H = si(p), W = si(p[0]);\n\trep(i,H){\n\t\t\
    rep(j,W){\n\t\t\tif(j < si(p[i])) printf(\"%2d \",p[i][j]);\n\t\t\telse printf(\"\
    \   \");\n\t\t}\n\t\tprintf(\"| \");\n\t\trep(j,W){\n\t\t\tif(j < si(q[i])) printf(\"\
    %2d \",q[i][j]);\n\t\t\telse printf(\"   \");\n\t\t}\n\t\tprintf(\"\\n\");\n\t\
    }\n\tprintf(\"\\n\");\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/RSK.cpp
  requiredBy: []
  timestamp: '2023-11-14 00:07:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/RSK.cpp
layout: document
redirect_from:
- /library/math/RSK.cpp
- /library/math/RSK.cpp.html
title: math/RSK.cpp
---
