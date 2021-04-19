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
  bundledCode: "#line 1 \"graph/normalize.cpp\"\n/*\n\t\u7121\u5411\u30B0\u30E9\u30D5\
    \u3092dfs\u3057\u305F\u3068\u304D\u306B,\u5404v\u306B\u5BFE\u3057G[v]\u306E\u4E2D\
    \u3067\u89AA\u3092\u4E00\u756A\u6700\u5F8C\u306B\u6301\u3063\u3066\u304F\u308B\
    \n\trotate\u3057\u3066\u308B\u306E\u3067\u89AA\u4EE5\u5916\u306E\u76F8\u5BFE\u9806\
    \u5E8F\u306F\u5909\u308F\u3089\u306A\u3044\u3051\u3069\u3001\n\t\u9806\u5E8F\u6728\
    (ex.\u4E8C\u6B21\u5143\u5E73\u9762\u4E0A\u306B\u9802\u70B9\u304C\u3042\u3063\u3066\
    ,\u89AA\u65B9\u5411\u304B\u3089\u6642\u8A08\u56DE\u308A\u306B\u5B50\u3092\u898B\
    \u3066\u3044\u304F\u5FC5\u8981\u304C\u3042\u308B) \u3068\u304B\u3060\u3068\u5909\
    \u3048\u306A\u3044\u3068\u307E\u305A\u3044\n*/\nnamespace Normalize{\n\ttemplate<class\
    \ E>\n\tvoid dfs(vector<vector<E>>& G, int v,int p=-1){\n\t\tint K = G[v].size();\n\
    \t\trep(i,K){\n\t\t\tif(G[v][i].to==p){\n\t\t\t\trotate(G[v].begin()+i,G[v].begin()+i+1,G[v].end());\n\
    \t\t\t}else{\n\t\t\t\tdfs(G,G[v][i].to,v);\n\t\t\t}\n\t\t}\n\t}\n\ttemplate<class\
    \ E>\n\tvoid normalize(vector<vector<E>>& G, int r=0){\n\t\tdfs(G,r);\n\t}\n}\n\
    \nstruct edge{\n\tint to;\n};\nint main(){\n\tint N,M;\n\tcin>>N>>M;\n\tvector<vector<edge>>\
    \ G(N);\n\trep(i,M){\n\t\tint x,y;\n\t\tcin>>x>>y;\n\t\tG[x].pb(edge{y});\n\t\t\
    G[y].pb(edge{x});\n\t}\n\tNormalize::normalize(G);\n\trep(v,N){\n\t\tprintf(\"\
    G[%d]={\",v);\n\t\tfor(edge e:G[v]) printf(\"%d, \",e.to);\n\t\tprintf(\"}\\n\"\
    );\n\t}\n}\n"
  code: "/*\n\t\u7121\u5411\u30B0\u30E9\u30D5\u3092dfs\u3057\u305F\u3068\u304D\u306B\
    ,\u5404v\u306B\u5BFE\u3057G[v]\u306E\u4E2D\u3067\u89AA\u3092\u4E00\u756A\u6700\
    \u5F8C\u306B\u6301\u3063\u3066\u304F\u308B\n\trotate\u3057\u3066\u308B\u306E\u3067\
    \u89AA\u4EE5\u5916\u306E\u76F8\u5BFE\u9806\u5E8F\u306F\u5909\u308F\u3089\u306A\
    \u3044\u3051\u3069\u3001\n\t\u9806\u5E8F\u6728(ex.\u4E8C\u6B21\u5143\u5E73\u9762\
    \u4E0A\u306B\u9802\u70B9\u304C\u3042\u3063\u3066,\u89AA\u65B9\u5411\u304B\u3089\
    \u6642\u8A08\u56DE\u308A\u306B\u5B50\u3092\u898B\u3066\u3044\u304F\u5FC5\u8981\
    \u304C\u3042\u308B) \u3068\u304B\u3060\u3068\u5909\u3048\u306A\u3044\u3068\u307E\
    \u305A\u3044\n*/\nnamespace Normalize{\n\ttemplate<class E>\n\tvoid dfs(vector<vector<E>>&\
    \ G, int v,int p=-1){\n\t\tint K = G[v].size();\n\t\trep(i,K){\n\t\t\tif(G[v][i].to==p){\n\
    \t\t\t\trotate(G[v].begin()+i,G[v].begin()+i+1,G[v].end());\n\t\t\t}else{\n\t\t\
    \t\tdfs(G,G[v][i].to,v);\n\t\t\t}\n\t\t}\n\t}\n\ttemplate<class E>\n\tvoid normalize(vector<vector<E>>&\
    \ G, int r=0){\n\t\tdfs(G,r);\n\t}\n}\n\nstruct edge{\n\tint to;\n};\nint main(){\n\
    \tint N,M;\n\tcin>>N>>M;\n\tvector<vector<edge>> G(N);\n\trep(i,M){\n\t\tint x,y;\n\
    \t\tcin>>x>>y;\n\t\tG[x].pb(edge{y});\n\t\tG[y].pb(edge{x});\n\t}\n\tNormalize::normalize(G);\n\
    \trep(v,N){\n\t\tprintf(\"G[%d]={\",v);\n\t\tfor(edge e:G[v]) printf(\"%d, \"\
    ,e.to);\n\t\tprintf(\"}\\n\");\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/normalize.cpp
  requiredBy: []
  timestamp: '2017-04-11 17:24:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/normalize.cpp
layout: document
redirect_from:
- /library/graph/normalize.cpp
- /library/graph/normalize.cpp.html
title: graph/normalize.cpp
---
