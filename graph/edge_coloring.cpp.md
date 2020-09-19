---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://codeforces.com/blog/entry/75431
    - https://codeforces.com/contest/600/problem/F
    - https://github.com/koosaga/olympiad/blob/master/Library/codes/graph_etc/edgecolor_vizing.cpp
  bundledCode: "#line 1 \"graph/edge_coloring.cpp\"\n/*\r\n\t\u3053\u3053\u306B\u5168\
    \u3066\u3042\u308B https://codeforces.com/blog/entry/75431\r\n\r\n\t- maxdeg +0/1\
    \ \u5F69\u8272 O(NM)\r\n\t\thttps://github.com/koosaga/olympiad/blob/master/Library/codes/graph_etc/edgecolor_vizing.cpp\r\
    \n\t\t\u5B9F\u88C5\u304C\u9762\u5012\u306B\u306A\u3063\u305F\u3001\u3053\u3063\
    \u304B\u3089\u3068\u3063\u3066\u304F\u308B\r\n\t\tVizing\r\n\r\n\t- bipartite\
    \ edge coloring\r\n\t\t\u591A\u91CD\u8FBA\u3082OK \u4E8C\u90E8\u3078\u306E\u5206\
    \u5272\u304C\u4E0E\u3048\u3089\u308C\u3066\u3044\u308B\u5FC5\u8981\u3082\u306A\
    \u3044\r\n\t\tO(NM) \u3067\u5341\u5206\u3067\u3057\u3087\u3046\u3001D-regular\
    \ \u306A\u3089 DN^2\r\n\r\n\t\tverified https://codeforces.com/contest/600/problem/F\r\
    \n*/\r\n\r\nV<int> bipartite_edge_coloring(int N, V<pair<int,int>> es){\r\n\t\
    using P = pair<int,int>;\r\n\tint M = es.size();\r\n\tint D = 0;\r\n\t{\r\n\t\t\
    V<int> d(N);\r\n\t\tfor(P e:es) d[e.fs]++,d[e.sc]++;\r\n\t\trep(i,N) chmax(D,d[i]);\r\
    \n\t}\r\n\tVV<int> vc2e(N,V<int>(D,-1));\r\n\tV<int> col(M,-1);\r\n\tauto color\
    \ = [&](int e,int c){\r\n\t\tint x = es[e].fs, y = es[e].sc;\r\n\t\tif(col[e]\
    \ != -1){\r\n\t\t\tvc2e[x][col[e]] = -1;\r\n\t\t\tvc2e[y][col[e]] = -1;\r\n\t\t\
    }\r\n\t\tcol[e] = c;\r\n\t\tvc2e[x][c] = e, vc2e[y][c] = e;\r\n\t};\r\n\tV<int>\
    \ buf(M);\r\n\trep(t,M){\r\n\t\tint x = es[t].fs, y = es[t].sc;\r\n\t\tint c0\
    \ = 0, c1 = 0;\r\n\t\twhile(vc2e[x][c0] != -1) c0++;\r\n\t\twhile(vc2e[y][c1]\
    \ != -1) c1++;\r\n\t\tif(c0 == c1){\r\n\t\t\tcolor(t,c0);\r\n\t\t\tcontinue;\r\
    \n\t\t}\r\n\t\tint v = x, c = c1, I = 0;\r\n\t\twhile(vc2e[v][c] != -1){\r\n\t\
    \t\tint e = vc2e[v][c];\r\n\t\t\tv ^= es[e].fs^es[e].sc;\r\n\t\t\tc ^= c0^c1;\r\
    \n\t\t\tbuf[I++] = e;\r\n\t\t}\r\n\t\tv = x;\r\n\t\trep(i,I){\r\n\t\t\tint e =\
    \ buf[i];\r\n\t\t\tcol[e] ^= c0^c1;\r\n\t\t\tswap(vc2e[v][c0],vc2e[v][c1]);\r\n\
    \t\t\tv ^= es[e].fs^es[e].sc;\r\n\t\t}\r\n\t\tswap(vc2e[v][c0],vc2e[v][c1]);\r\
    \n\t\tcolor(t,c1);\r\n\t}\r\n\treturn col;\r\n}\r\n"
  code: "/*\r\n\t\u3053\u3053\u306B\u5168\u3066\u3042\u308B https://codeforces.com/blog/entry/75431\r\
    \n\r\n\t- maxdeg +0/1 \u5F69\u8272 O(NM)\r\n\t\thttps://github.com/koosaga/olympiad/blob/master/Library/codes/graph_etc/edgecolor_vizing.cpp\r\
    \n\t\t\u5B9F\u88C5\u304C\u9762\u5012\u306B\u306A\u3063\u305F\u3001\u3053\u3063\
    \u304B\u3089\u3068\u3063\u3066\u304F\u308B\r\n\t\tVizing\r\n\r\n\t- bipartite\
    \ edge coloring\r\n\t\t\u591A\u91CD\u8FBA\u3082OK \u4E8C\u90E8\u3078\u306E\u5206\
    \u5272\u304C\u4E0E\u3048\u3089\u308C\u3066\u3044\u308B\u5FC5\u8981\u3082\u306A\
    \u3044\r\n\t\tO(NM) \u3067\u5341\u5206\u3067\u3057\u3087\u3046\u3001D-regular\
    \ \u306A\u3089 DN^2\r\n\r\n\t\tverified https://codeforces.com/contest/600/problem/F\r\
    \n*/\r\n\r\nV<int> bipartite_edge_coloring(int N, V<pair<int,int>> es){\r\n\t\
    using P = pair<int,int>;\r\n\tint M = es.size();\r\n\tint D = 0;\r\n\t{\r\n\t\t\
    V<int> d(N);\r\n\t\tfor(P e:es) d[e.fs]++,d[e.sc]++;\r\n\t\trep(i,N) chmax(D,d[i]);\r\
    \n\t}\r\n\tVV<int> vc2e(N,V<int>(D,-1));\r\n\tV<int> col(M,-1);\r\n\tauto color\
    \ = [&](int e,int c){\r\n\t\tint x = es[e].fs, y = es[e].sc;\r\n\t\tif(col[e]\
    \ != -1){\r\n\t\t\tvc2e[x][col[e]] = -1;\r\n\t\t\tvc2e[y][col[e]] = -1;\r\n\t\t\
    }\r\n\t\tcol[e] = c;\r\n\t\tvc2e[x][c] = e, vc2e[y][c] = e;\r\n\t};\r\n\tV<int>\
    \ buf(M);\r\n\trep(t,M){\r\n\t\tint x = es[t].fs, y = es[t].sc;\r\n\t\tint c0\
    \ = 0, c1 = 0;\r\n\t\twhile(vc2e[x][c0] != -1) c0++;\r\n\t\twhile(vc2e[y][c1]\
    \ != -1) c1++;\r\n\t\tif(c0 == c1){\r\n\t\t\tcolor(t,c0);\r\n\t\t\tcontinue;\r\
    \n\t\t}\r\n\t\tint v = x, c = c1, I = 0;\r\n\t\twhile(vc2e[v][c] != -1){\r\n\t\
    \t\tint e = vc2e[v][c];\r\n\t\t\tv ^= es[e].fs^es[e].sc;\r\n\t\t\tc ^= c0^c1;\r\
    \n\t\t\tbuf[I++] = e;\r\n\t\t}\r\n\t\tv = x;\r\n\t\trep(i,I){\r\n\t\t\tint e =\
    \ buf[i];\r\n\t\t\tcol[e] ^= c0^c1;\r\n\t\t\tswap(vc2e[v][c0],vc2e[v][c1]);\r\n\
    \t\t\tv ^= es[e].fs^es[e].sc;\r\n\t\t}\r\n\t\tswap(vc2e[v][c0],vc2e[v][c1]);\r\
    \n\t\tcolor(t,c1);\r\n\t}\r\n\treturn col;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/edge_coloring.cpp
  requiredBy: []
  timestamp: '2020-05-14 22:19:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/edge_coloring.cpp
layout: document
redirect_from:
- /library/graph/edge_coloring.cpp
- /library/graph/edge_coloring.cpp.html
title: graph/edge_coloring.cpp
---
