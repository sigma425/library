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
    - https://beta.atcoder.jp/contests/ddcc2016-qual/tasks/ddcc_2016_qual_d
    - https://beta.atcoder.jp/contests/yahoo-procon2018-final/tasks/yahoo_procon2018_final_c)
  bundledCode: "#line 1 \"graph/Centroid Decomposition.cpp\"\n/*\n\t\u91CD\u5FC3\u5206\
    \u89E3\n\tlog \u6BB5\u3067\u7D42\u308F\u308B\u3001\u5404\u6BB5\u3067\u5168\u4F53\
    \u3067O(N)\u304B\u3051\u3066\u3082\u3044\u3044\u306E\u3067\u3001\u4ECA\u898B\u3066\
    \u308B\u90E8\u5206\u6728\u306E\u9802\u70B9\u3092\u5168\u63A2\u7D22\u3059\u308B\
    \u3001\u3068\u304B\u306F\u53EF\u80FD\n\t\u57FA\u672C\u64CD\u4F5C\u3068\u3057\u3066\
    \ enumeratePaths : \u4ECA\u898B\u3066\u308B\u6728\u306E centroid r \u304B\u3089\
    \u306E(dist,v) \u3092\u5217\u6319\n\n\t\u4F8B1. \u8DDD\u96E2K\u306E\u30DA\u30A2\
    \u306F\u3044\u304F\u3064?\n\t\u4F8B2. \u30AF\u30A8\u30EA v_i \u3068\u8DDD\u96E2\
    \ d_i \u306A\u9802\u70B9\u306E\u500B\u6570\u306F? (https://beta.atcoder.jp/contests/yahoo-procon2018-final/tasks/yahoo_procon2018_final_c)\n\
    \t\u4F8B3. camypaper \u306E\u3084\u3064(\u554F\u984C\u5FD8\u308C\u305F) https://beta.atcoder.jp/contests/ddcc2016-qual/tasks/ddcc_2016_qual_d\n\
    \t\u4F8B4. camp/6/1/K d(a,b)=d(b,c)=d(c,a) \u306A\u308B a,b,c \u306E\u500B\u6570\
    \ \u3053\u308C\u306FenumeratePaths\u3082\u3044\u3058\u308B\u5FC5\u8981\u304C\u3042\
    \u308B\n*/\n\ntemplate<class E>\nstruct CentroidDecomposition{\n\n\tusing D =\
    \ ll;\t//type of length of the longest path\n\n\tint N;\n\tVV<E> G;\n\tV<bool>\
    \ centroid;\n\tV<int> sz;\n\n\tCentroidDecomposition(const VV<E>& _G):G(_G){\n\
    \t\tN = (int)G.size();\n\t\tcentroid = V<bool>(N,false);\n\t\tsz = V<int>(N,0);\n\
    \t}\n\n\tint computeSubtreeSize(int v,int p){\n\t\tsz[v] = 1;\n\t\tfor(const auto&\
    \ e: G[v]){\n\t\t\tint u = e.to;\n\t\t\tif(u==p || centroid[u]) continue;\n\t\t\
    \tsz[v] += computeSubtreeSize(u,v);\n\t\t}\n\t\treturn sz[v];\n\t}\n\tpair<int,int>\
    \ searchCentroid(int v,int p,int t){\t\n\t\tpair<int,int> res(1e9,-1);\n\t\tint\
    \ s=1,m=0;\n\t\tfor(const auto& e: G[v]){\n\t\t\tint u = e.to;\n\t\t\tif(u==p\
    \ || centroid[u]) continue;\n\t\t\tchmin(res,searchCentroid(u,v,t));\n\t\t\tchmax(m,sz[u]);\n\
    \t\t\ts += sz[u];\n\t\t}\n\t\tchmax(m,t-s);\n\t\tchmin(res,(pair<int,int>(m,v)));\n\
    \t\treturn res;\n\t}\n\n\tvoid enumeratePaths(int v, int p, D d, vector<pair<D,int>>&\
    \ dvs){\n\t\tdvs.pb(pair<D,int>(d,v));\n\t\tfor(const auto& e: G[v]){\n\t\t\t\
    int u = e.to;\n\t\t\tif(u==p || centroid[u]) continue;\n\t\t\tenumeratePaths(u,v,d+e.dist,dvs);\t\
    //unweighted: d+1\n\t\t}\n\t}\n\n\t/*\n\t\t\u4ECAv\u3092\u542B\u3080\u90E8\u5206\
    \u6728\u5185\u3067centroid s \u3092\u63A2\u3057\u3066\u89E3\u304F\n\t*/\n\n\t\
    void dfs(int v){\n\t\tcomputeSubtreeSize(v,-1);\n\t\tint r = searchCentroid(v,-1,sz[v]).sc;\n\
    \t\tcentroid[r]=true;\n\n\t\tfor(auto e: G[r]){\n\t\t\tint u = e.to;\n\t\t\tif(centroid[u])\
    \ continue;\n\t\t\tdfs(u);\n\t\t}\n\t\t\n\t\t//solve subproblem here\n\t\tvector<pair<D,int>>\
    \ dvs;\t// s \u304B\u3089\u306E\u8DDD\u96E2\u306E\u96C6\u5408(s\u542B\u3080)\n\
    \t\tdvs.pb(pair<D,int>(0,r));\n\t\tmap<int,int> cnt;\n\t\tcnt[0]++;\n\n\t\tfor(auto\
    \ e: G[r]){\n\t\t\tint u = e.to;\n\t\t\tif(centroid[u]) continue;\n\t\t\tvector<pair<D,int>>\
    \ _dvs;\t//\u5404 r \u306E\u5B50 u \u3060\u3051\u8003\u3048\u305F\u6642\u306E\
    \ dvs \u3060\u3044\u305F\u3044ds^2 - \\sigma _ds^2 \u307F\u305F\u3044\u306A\u611F\
    \u3058\u3067\u30DA\u30A2\u8A08\u7B97\u3059\u308B\n\t\t\tenumeratePaths(u,r,e.dist,_dvs);\n\
    \t\t\t\n\t\t\t// map<int,int> _cnt;\n\t\t\t// for(auto dv: _dvs){\n\t\t\t// \t\
    _cnt[dv.fs]++;\n\t\t\t// \tcnt[dv.fs]++;\n\t\t\t// }\n\t\t\t// for(auto dv: _dvs){\n\
    \t\t\t// \tint v = dv.sc;\n\t\t\t// \tint d = dv.fs;\n\t\t\t// \tfor(auto query:\
    \ v2qs[v]){\n\t\t\t// \t\tint q = query.fs;\n\t\t\t// \t\tint k = query.sc;\n\t\
    \t\t// \t\tans[q] -= _cnt[k-d];\n\t\t\t// \t}\n\t\t\t// }\n\n\t\t\tdvs.insert(dvs.end(),all(_dvs));\n\
    \t\t}\n\n\t\t// for(auto dv: dvs){\n\t\t// \tint v = dv.sc;\n\t\t// \tint d =\
    \ dv.fs;\n\t\t// \tfor(auto query: v2qs[v]){\n\t\t// \t\tint q = query.fs;\n\t\
    \t// \t\tint k = query.sc;\n\t\t// \t\tans[q] += cnt[k-d];\n\t\t// \t}\n\t\t//\
    \ }\n\n\t\tcentroid[r]=false;\n\t}\n\n\tVV<pair<int,int>> v2qs;\t//id,dist\n\t\
    V<int> ans;\n\n\tvoid solve(int Q){\n\t\tv2qs.resize(N);\n\t\tans.resize(Q);\n\
    \t\trep(q,Q){\n\t\t\tint v,k;\n\t\t\tcin>>v>>k;\n\t\t\tv--;\n\t\t\tv2qs[v].pb(pair<int,int>(q,k));\n\
    \t\t}\n\t\tdfs(0);\n\t\trep(q,Q) cout << ans[q] << endl;\n\t}\n};\n\nstruct edge{\n\
    \tint to;\n\tstatic const int dist = 1;\n};\n\nint main(){\n\tint N,Q;\n\tcin\
    \ >> N >> Q;\n\tVV<edge> G(N);\n\trep(i,N-1){\n\t\tint x,y;\n\t\tcin>>x>>y;\n\t\
    \tx--,y--;\n\t\tG[x].pb({y});\n\t\tG[y].pb({x});\n\t}\n\tCentroidDecomposition<edge>\
    \ CD(G);\n\tCD.solve(Q);\n}\n"
  code: "/*\n\t\u91CD\u5FC3\u5206\u89E3\n\tlog \u6BB5\u3067\u7D42\u308F\u308B\u3001\
    \u5404\u6BB5\u3067\u5168\u4F53\u3067O(N)\u304B\u3051\u3066\u3082\u3044\u3044\u306E\
    \u3067\u3001\u4ECA\u898B\u3066\u308B\u90E8\u5206\u6728\u306E\u9802\u70B9\u3092\
    \u5168\u63A2\u7D22\u3059\u308B\u3001\u3068\u304B\u306F\u53EF\u80FD\n\t\u57FA\u672C\
    \u64CD\u4F5C\u3068\u3057\u3066 enumeratePaths : \u4ECA\u898B\u3066\u308B\u6728\
    \u306E centroid r \u304B\u3089\u306E(dist,v) \u3092\u5217\u6319\n\n\t\u4F8B1.\
    \ \u8DDD\u96E2K\u306E\u30DA\u30A2\u306F\u3044\u304F\u3064?\n\t\u4F8B2. \u30AF\u30A8\
    \u30EA v_i \u3068\u8DDD\u96E2 d_i \u306A\u9802\u70B9\u306E\u500B\u6570\u306F?\
    \ (https://beta.atcoder.jp/contests/yahoo-procon2018-final/tasks/yahoo_procon2018_final_c)\n\
    \t\u4F8B3. camypaper \u306E\u3084\u3064(\u554F\u984C\u5FD8\u308C\u305F) https://beta.atcoder.jp/contests/ddcc2016-qual/tasks/ddcc_2016_qual_d\n\
    \t\u4F8B4. camp/6/1/K d(a,b)=d(b,c)=d(c,a) \u306A\u308B a,b,c \u306E\u500B\u6570\
    \ \u3053\u308C\u306FenumeratePaths\u3082\u3044\u3058\u308B\u5FC5\u8981\u304C\u3042\
    \u308B\n*/\n\ntemplate<class E>\nstruct CentroidDecomposition{\n\n\tusing D =\
    \ ll;\t//type of length of the longest path\n\n\tint N;\n\tVV<E> G;\n\tV<bool>\
    \ centroid;\n\tV<int> sz;\n\n\tCentroidDecomposition(const VV<E>& _G):G(_G){\n\
    \t\tN = (int)G.size();\n\t\tcentroid = V<bool>(N,false);\n\t\tsz = V<int>(N,0);\n\
    \t}\n\n\tint computeSubtreeSize(int v,int p){\n\t\tsz[v] = 1;\n\t\tfor(const auto&\
    \ e: G[v]){\n\t\t\tint u = e.to;\n\t\t\tif(u==p || centroid[u]) continue;\n\t\t\
    \tsz[v] += computeSubtreeSize(u,v);\n\t\t}\n\t\treturn sz[v];\n\t}\n\tpair<int,int>\
    \ searchCentroid(int v,int p,int t){\t\n\t\tpair<int,int> res(1e9,-1);\n\t\tint\
    \ s=1,m=0;\n\t\tfor(const auto& e: G[v]){\n\t\t\tint u = e.to;\n\t\t\tif(u==p\
    \ || centroid[u]) continue;\n\t\t\tchmin(res,searchCentroid(u,v,t));\n\t\t\tchmax(m,sz[u]);\n\
    \t\t\ts += sz[u];\n\t\t}\n\t\tchmax(m,t-s);\n\t\tchmin(res,(pair<int,int>(m,v)));\n\
    \t\treturn res;\n\t}\n\n\tvoid enumeratePaths(int v, int p, D d, vector<pair<D,int>>&\
    \ dvs){\n\t\tdvs.pb(pair<D,int>(d,v));\n\t\tfor(const auto& e: G[v]){\n\t\t\t\
    int u = e.to;\n\t\t\tif(u==p || centroid[u]) continue;\n\t\t\tenumeratePaths(u,v,d+e.dist,dvs);\t\
    //unweighted: d+1\n\t\t}\n\t}\n\n\t/*\n\t\t\u4ECAv\u3092\u542B\u3080\u90E8\u5206\
    \u6728\u5185\u3067centroid s \u3092\u63A2\u3057\u3066\u89E3\u304F\n\t*/\n\n\t\
    void dfs(int v){\n\t\tcomputeSubtreeSize(v,-1);\n\t\tint r = searchCentroid(v,-1,sz[v]).sc;\n\
    \t\tcentroid[r]=true;\n\n\t\tfor(auto e: G[r]){\n\t\t\tint u = e.to;\n\t\t\tif(centroid[u])\
    \ continue;\n\t\t\tdfs(u);\n\t\t}\n\t\t\n\t\t//solve subproblem here\n\t\tvector<pair<D,int>>\
    \ dvs;\t// s \u304B\u3089\u306E\u8DDD\u96E2\u306E\u96C6\u5408(s\u542B\u3080)\n\
    \t\tdvs.pb(pair<D,int>(0,r));\n\t\tmap<int,int> cnt;\n\t\tcnt[0]++;\n\n\t\tfor(auto\
    \ e: G[r]){\n\t\t\tint u = e.to;\n\t\t\tif(centroid[u]) continue;\n\t\t\tvector<pair<D,int>>\
    \ _dvs;\t//\u5404 r \u306E\u5B50 u \u3060\u3051\u8003\u3048\u305F\u6642\u306E\
    \ dvs \u3060\u3044\u305F\u3044ds^2 - \\sigma _ds^2 \u307F\u305F\u3044\u306A\u611F\
    \u3058\u3067\u30DA\u30A2\u8A08\u7B97\u3059\u308B\n\t\t\tenumeratePaths(u,r,e.dist,_dvs);\n\
    \t\t\t\n\t\t\t// map<int,int> _cnt;\n\t\t\t// for(auto dv: _dvs){\n\t\t\t// \t\
    _cnt[dv.fs]++;\n\t\t\t// \tcnt[dv.fs]++;\n\t\t\t// }\n\t\t\t// for(auto dv: _dvs){\n\
    \t\t\t// \tint v = dv.sc;\n\t\t\t// \tint d = dv.fs;\n\t\t\t// \tfor(auto query:\
    \ v2qs[v]){\n\t\t\t// \t\tint q = query.fs;\n\t\t\t// \t\tint k = query.sc;\n\t\
    \t\t// \t\tans[q] -= _cnt[k-d];\n\t\t\t// \t}\n\t\t\t// }\n\n\t\t\tdvs.insert(dvs.end(),all(_dvs));\n\
    \t\t}\n\n\t\t// for(auto dv: dvs){\n\t\t// \tint v = dv.sc;\n\t\t// \tint d =\
    \ dv.fs;\n\t\t// \tfor(auto query: v2qs[v]){\n\t\t// \t\tint q = query.fs;\n\t\
    \t// \t\tint k = query.sc;\n\t\t// \t\tans[q] += cnt[k-d];\n\t\t// \t}\n\t\t//\
    \ }\n\n\t\tcentroid[r]=false;\n\t}\n\n\tVV<pair<int,int>> v2qs;\t//id,dist\n\t\
    V<int> ans;\n\n\tvoid solve(int Q){\n\t\tv2qs.resize(N);\n\t\tans.resize(Q);\n\
    \t\trep(q,Q){\n\t\t\tint v,k;\n\t\t\tcin>>v>>k;\n\t\t\tv--;\n\t\t\tv2qs[v].pb(pair<int,int>(q,k));\n\
    \t\t}\n\t\tdfs(0);\n\t\trep(q,Q) cout << ans[q] << endl;\n\t}\n};\n\nstruct edge{\n\
    \tint to;\n\tstatic const int dist = 1;\n};\n\nint main(){\n\tint N,Q;\n\tcin\
    \ >> N >> Q;\n\tVV<edge> G(N);\n\trep(i,N-1){\n\t\tint x,y;\n\t\tcin>>x>>y;\n\t\
    \tx--,y--;\n\t\tG[x].pb({y});\n\t\tG[y].pb({x});\n\t}\n\tCentroidDecomposition<edge>\
    \ CD(G);\n\tCD.solve(Q);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/Centroid Decomposition.cpp
  requiredBy: []
  timestamp: '2019-02-12 17:43:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/Centroid Decomposition.cpp
layout: document
redirect_from:
- /library/graph/Centroid Decomposition.cpp
- /library/graph/Centroid Decomposition.cpp.html
title: graph/Centroid Decomposition.cpp
---
