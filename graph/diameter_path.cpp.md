---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/diameter_path.cpp\"\n// \u6728\u306E\u76F4\u5F84\u306E\
    path\u3092\u8FD4\u3059\n// verify: hitachi2020/F.cpp\n\nV<int> getPath(const VV<int>&\
    \ G){\n\tint N = si(G);\n\tV<int> d(N),par(N);\n\tauto dfs = [&](auto self,int\
    \ v,int p)->void{\n\t\tif(p == -1) d[v] = 0, par[v] = -1;\n\t\tfor(int u: G[v])\
    \ if(u != p){\n\t\t\td[u] = d[v]+1, par[u] = v;\n\t\t\tself(self,u,v);\n\t\t}\n\
    \t};\n\tdfs(dfs,0,-1);\n\tint s = max_element(all(d)) - d.begin();\n\tdfs(dfs,s,-1);\n\
    \tint t = max_element(all(d)) - d.begin();\n\tV<int> path;\n\twhile(t != s){\n\
    \t\tpath.pb(t);\n\t\tt = par[t];\n\t}\n\tpath.pb(s);\n\treturn path;\n};\n"
  code: "// \u6728\u306E\u76F4\u5F84\u306Epath\u3092\u8FD4\u3059\n// verify: hitachi2020/F.cpp\n\
    \nV<int> getPath(const VV<int>& G){\n\tint N = si(G);\n\tV<int> d(N),par(N);\n\
    \tauto dfs = [&](auto self,int v,int p)->void{\n\t\tif(p == -1) d[v] = 0, par[v]\
    \ = -1;\n\t\tfor(int u: G[v]) if(u != p){\n\t\t\td[u] = d[v]+1, par[u] = v;\n\t\
    \t\tself(self,u,v);\n\t\t}\n\t};\n\tdfs(dfs,0,-1);\n\tint s = max_element(all(d))\
    \ - d.begin();\n\tdfs(dfs,s,-1);\n\tint t = max_element(all(d)) - d.begin();\n\
    \tV<int> path;\n\twhile(t != s){\n\t\tpath.pb(t);\n\t\tt = par[t];\n\t}\n\tpath.pb(s);\n\
    \treturn path;\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/diameter_path.cpp
  requiredBy: []
  timestamp: '2020-12-16 01:54:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/diameter_path.cpp
layout: document
redirect_from:
- /library/graph/diameter_path.cpp
- /library/graph/diameter_path.cpp.html
title: graph/diameter_path.cpp
---
