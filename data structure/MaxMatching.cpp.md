---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://uoj.ac/problem/79
    - https://min-25.hatenablog.com/entry/2016/11/21/222625
    - https://official.contest.yandex.com/ptz-winter-2019/contest/11818/problems
    - https://www.spoj.com/problems/ADABLOOM/
  bundledCode: "#line 1 \"data structure/MaxMatching.cpp\"\n/*\r\n\t\u591A\u91CD\u8FBA\
    \u3001\u81EA\u5DF1\u30EB\u30FC\u30D7\u3082\u5927\u4E08\u592B\r\n\r\n\tMaxMatching(N)\
    \ -> add_edge(x,y) -> maxMatching()\r\n\tmate[v] = u or -1\r\n\r\n\tN = 500, M\
    \ <= N Choose 2 \u3067 200 ms\r\n\r\n\thttps://min-25.hatenablog.com/entry/2016/11/21/222625\r\
    \n\r\n\tN = M = 100000 \u306A\u3089\u591A\u5206\u901A\u308B\r\n\r\n\tverified\
    \ at:\r\n\t\thttp://uoj.ac/problem/79\r\n\t\thttps://www.spoj.com/problems/ADABLOOM/\r\
    \n\t\thttps://official.contest.yandex.com/ptz-winter-2019/contest/11818/problems\r\
    \n\r\n*/\r\n\r\nstruct MaxMatching{\r\n\tint N;\r\n\tVV<int> G;\r\n\r\n\tV<int>\
    \ mate;\r\n\r\n\tvoid add_edge(int a,int b){\r\n\t\tif(a == b) return;\r\n\t\t\
    G[a].pb(b);\r\n\t\tG[b].pb(a);\r\n\t}\r\n\r\n\tMaxMatching(int _N):N(_N),G(N){}\r\
    \n\r\n\tusing P = pair<int,int>;\r\n\r\n\tint maxMatching(){\r\n\t\tmate = V<int>(N+1,N);\r\
    \n\t\tV<int> first(N+1,N),que(N);\r\n\t\tV<P> label(N+1,P(-1,-1));\r\n\t\tint\
    \ qh = 0, qt = 0;\r\n\r\n\t\tauto enqueue = [&](int v){\r\n\t\t\tque[qt++] = v;\r\
    \n\t\t};\r\n\t\tauto dequeue = [&](){\r\n\t\t\treturn que[qh++];\r\n\t\t};\r\n\
    \r\n\t\tfunction<void(int,int)> rematch = [&](int a, int b){\r\n\t\t\tint c =\
    \ mate[a];\r\n\t\t\tmate[a] = b;\r\n\t\t\tif(mate[c] != a) return;\r\n\t\t\tif(label[a].sc\
    \ == -1){\r\n\t\t\t\tmate[c] = label[a].fs;\r\n\t\t\t\trematch(mate[c],c);\r\n\
    \t\t\t}else{\r\n\t\t\t\tint x,y;\r\n\t\t\t\ttie(x,y) = label[a];\r\n\t\t\t\trematch(x,y);\r\
    \n\t\t\t\trematch(y,x);\r\n\t\t\t}\r\n\t\t};\r\n\t\tauto relabel = [&](int a,\
    \ int b){\r\n\t\t\tfunction<int(int)> findFirst = [&](int v){\r\n\t\t\t\tif(label[first[v]].fs\
    \ < 0) return first[v];\r\n\t\t\t\treturn first[v] = findFirst(first[v]);\r\n\t\
    \t\t};\r\n\t\t\tint x = findFirst(a), y = findFirst(b);\r\n\t\t\tif(x == y) return;\r\
    \n\t\t\tP h(~a,b);\r\n\t\t\tlabel[x] = label[y] = h;\r\n\t\t\tint join = -1;\r\
    \n\t\t\twhile(true){\r\n\t\t\t\tif(y != N) swap(x,y);\r\n\t\t\t\tx = findFirst(label[mate[x]].fs);\r\
    \n\t\t\t\tif(label[x] == h){\r\n\t\t\t\t\tjoin = x;\r\n\t\t\t\t\tbreak;\r\n\t\t\
    \t\t}else{\r\n\t\t\t\t\tlabel[x] = h;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tfor(int\
    \ v: {first[a],first[b]}){\r\n\t\t\t\tfor(;v != join; v = first[label[mate[v]].fs]){\r\
    \n\t\t\t\t\tlabel[v] = P(a,b);\r\n\t\t\t\t\tfirst[v] = join;\r\n\t\t\t\t\tenqueue(v);\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t};\r\n\t\tauto augment = [&](int s){\r\n\t\t\tlabel[s]\
    \ = P(N,-1);\r\n\t\t\tfirst[s] = N;\r\n\t\t\tqh = qt = 0;\r\n\t\t\tenqueue(s);\r\
    \n\t\t\twhile(qh != qt){\r\n\t\t\t\tint a = dequeue();\r\n\t\t\t\tfor(int b: G[a]){\r\
    \n\t\t\t\t\tif(mate[b] == N && b != s){\r\n\t\t\t\t\t\tmate[b] = a;\r\n\t\t\t\t\
    \t\trematch(a,b);\r\n\t\t\t\t\t\treturn true;\r\n\t\t\t\t\t}else if(label[b].fs\
    \ >= 0){\r\n\t\t\t\t\t\trelabel(a,b);\r\n\t\t\t\t\t}else if(label[mate[b]].fs\
    \ == -1){\r\n\t\t\t\t\t\tlabel[mate[b]].fs = a;\r\n\t\t\t\t\t\tfirst[mate[b]]\
    \ = b;\r\n\t\t\t\t\t\tenqueue(mate[b]);\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\
    }\r\n\t\t\treturn false;\r\n\t\t};\r\n\r\n\t\tint numMatch = 0;\r\n\t\trep(v,N){\r\
    \n\t\t\tif(mate[v]<N || !augment(v)) continue;\r\n\t\t\tnumMatch++;\r\n\t\t\t\
    rep(i,qt){\t\t// including popped !!\r\n\t\t\t\tint v = que[i];\r\n\t\t\t\tlabel[v]\
    \ = label[mate[v]] = P(-1,-1);\r\n\t\t\t}\r\n\t\t\tlabel[N] = P(-1,-1);\r\n\t\t\
    }\r\n\t\tmate.pop_back();\r\n\t\trep(i,N) if(mate[i] == N) mate[i] = -1;\r\n\t\
    \treturn numMatch;\r\n\t}\r\n};\r\n"
  code: "/*\r\n\t\u591A\u91CD\u8FBA\u3001\u81EA\u5DF1\u30EB\u30FC\u30D7\u3082\u5927\
    \u4E08\u592B\r\n\r\n\tMaxMatching(N) -> add_edge(x,y) -> maxMatching()\r\n\tmate[v]\
    \ = u or -1\r\n\r\n\tN = 500, M <= N Choose 2 \u3067 200 ms\r\n\r\n\thttps://min-25.hatenablog.com/entry/2016/11/21/222625\r\
    \n\r\n\tN = M = 100000 \u306A\u3089\u591A\u5206\u901A\u308B\r\n\r\n\tverified\
    \ at:\r\n\t\thttp://uoj.ac/problem/79\r\n\t\thttps://www.spoj.com/problems/ADABLOOM/\r\
    \n\t\thttps://official.contest.yandex.com/ptz-winter-2019/contest/11818/problems\r\
    \n\r\n*/\r\n\r\nstruct MaxMatching{\r\n\tint N;\r\n\tVV<int> G;\r\n\r\n\tV<int>\
    \ mate;\r\n\r\n\tvoid add_edge(int a,int b){\r\n\t\tif(a == b) return;\r\n\t\t\
    G[a].pb(b);\r\n\t\tG[b].pb(a);\r\n\t}\r\n\r\n\tMaxMatching(int _N):N(_N),G(N){}\r\
    \n\r\n\tusing P = pair<int,int>;\r\n\r\n\tint maxMatching(){\r\n\t\tmate = V<int>(N+1,N);\r\
    \n\t\tV<int> first(N+1,N),que(N);\r\n\t\tV<P> label(N+1,P(-1,-1));\r\n\t\tint\
    \ qh = 0, qt = 0;\r\n\r\n\t\tauto enqueue = [&](int v){\r\n\t\t\tque[qt++] = v;\r\
    \n\t\t};\r\n\t\tauto dequeue = [&](){\r\n\t\t\treturn que[qh++];\r\n\t\t};\r\n\
    \r\n\t\tfunction<void(int,int)> rematch = [&](int a, int b){\r\n\t\t\tint c =\
    \ mate[a];\r\n\t\t\tmate[a] = b;\r\n\t\t\tif(mate[c] != a) return;\r\n\t\t\tif(label[a].sc\
    \ == -1){\r\n\t\t\t\tmate[c] = label[a].fs;\r\n\t\t\t\trematch(mate[c],c);\r\n\
    \t\t\t}else{\r\n\t\t\t\tint x,y;\r\n\t\t\t\ttie(x,y) = label[a];\r\n\t\t\t\trematch(x,y);\r\
    \n\t\t\t\trematch(y,x);\r\n\t\t\t}\r\n\t\t};\r\n\t\tauto relabel = [&](int a,\
    \ int b){\r\n\t\t\tfunction<int(int)> findFirst = [&](int v){\r\n\t\t\t\tif(label[first[v]].fs\
    \ < 0) return first[v];\r\n\t\t\t\treturn first[v] = findFirst(first[v]);\r\n\t\
    \t\t};\r\n\t\t\tint x = findFirst(a), y = findFirst(b);\r\n\t\t\tif(x == y) return;\r\
    \n\t\t\tP h(~a,b);\r\n\t\t\tlabel[x] = label[y] = h;\r\n\t\t\tint join = -1;\r\
    \n\t\t\twhile(true){\r\n\t\t\t\tif(y != N) swap(x,y);\r\n\t\t\t\tx = findFirst(label[mate[x]].fs);\r\
    \n\t\t\t\tif(label[x] == h){\r\n\t\t\t\t\tjoin = x;\r\n\t\t\t\t\tbreak;\r\n\t\t\
    \t\t}else{\r\n\t\t\t\t\tlabel[x] = h;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tfor(int\
    \ v: {first[a],first[b]}){\r\n\t\t\t\tfor(;v != join; v = first[label[mate[v]].fs]){\r\
    \n\t\t\t\t\tlabel[v] = P(a,b);\r\n\t\t\t\t\tfirst[v] = join;\r\n\t\t\t\t\tenqueue(v);\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t};\r\n\t\tauto augment = [&](int s){\r\n\t\t\tlabel[s]\
    \ = P(N,-1);\r\n\t\t\tfirst[s] = N;\r\n\t\t\tqh = qt = 0;\r\n\t\t\tenqueue(s);\r\
    \n\t\t\twhile(qh != qt){\r\n\t\t\t\tint a = dequeue();\r\n\t\t\t\tfor(int b: G[a]){\r\
    \n\t\t\t\t\tif(mate[b] == N && b != s){\r\n\t\t\t\t\t\tmate[b] = a;\r\n\t\t\t\t\
    \t\trematch(a,b);\r\n\t\t\t\t\t\treturn true;\r\n\t\t\t\t\t}else if(label[b].fs\
    \ >= 0){\r\n\t\t\t\t\t\trelabel(a,b);\r\n\t\t\t\t\t}else if(label[mate[b]].fs\
    \ == -1){\r\n\t\t\t\t\t\tlabel[mate[b]].fs = a;\r\n\t\t\t\t\t\tfirst[mate[b]]\
    \ = b;\r\n\t\t\t\t\t\tenqueue(mate[b]);\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\
    }\r\n\t\t\treturn false;\r\n\t\t};\r\n\r\n\t\tint numMatch = 0;\r\n\t\trep(v,N){\r\
    \n\t\t\tif(mate[v]<N || !augment(v)) continue;\r\n\t\t\tnumMatch++;\r\n\t\t\t\
    rep(i,qt){\t\t// including popped !!\r\n\t\t\t\tint v = que[i];\r\n\t\t\t\tlabel[v]\
    \ = label[mate[v]] = P(-1,-1);\r\n\t\t\t}\r\n\t\t\tlabel[N] = P(-1,-1);\r\n\t\t\
    }\r\n\t\tmate.pop_back();\r\n\t\trep(i,N) if(mate[i] == N) mate[i] = -1;\r\n\t\
    \treturn numMatch;\r\n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data structure/MaxMatching.cpp
  requiredBy: []
  timestamp: '2019-02-13 23:01:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/MaxMatching.cpp
layout: document
redirect_from:
- /library/data structure/MaxMatching.cpp
- /library/data structure/MaxMatching.cpp.html
title: data structure/MaxMatching.cpp
---
