---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc399/submissions/64421121
  bundledCode: "#line 1 \"graph/functional_graph.hpp\"\n/*\n\tFunctionalGraph (outdeg\
    \ = 1) \u306B\u9650\u3089\u305A\u3001 outdeg <= 1 \u306A\u6709\u5411\u30B0\u30E9\
    \u30D5\u3092\u3046\u307E\u304F\u6271\u3046 struct\n\n\tconstructor:\n\t\t- vector<int>\
    \ f\n\t\t\toutdeg(v) = 1 \u306A\u3089 f[v] \u304C\u884C\u304D\u5148\u306E\u9802\
    \u70B9\u3001 outdeg = 0 \u306A\u3089 f[v] = -1\n\n\toutput:\n\t\t- vector<int>\
    \ con_id(N)\n\t\t\tcon_id[v] : v \u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\
    \u306E ID\n\t\t- vector<vector<int>> cons(K)\n\t\t\tcons[k] : k \u756A\u76EE\u306E\
    \u9023\u7D50\u6210\u5206\u306B\u542B\u307E\u308C\u308B\u9802\u70B9\u306E\u96C6\
    \u5408\n\t\t- vector<vector<int>> cycles(K)\n\t\t\tcycles[k] : k \u756A\u76EE\u306E\
    \u9023\u7D50\u6210\u5206\u306B\u542B\u307E\u308C\u308B\u30B5\u30A4\u30AF\u30EB\
    \u306E\u9802\u70B9\u306E\u96C6\u5408 (a->f[a]->.. \u306E\u9806\u3067\u4E26\u3093\
    \u3067\u3044\u308B)\n\t\t\t1 \u9802\u70B9 (f[v] = v) \u306E\u5834\u5408\u3082\
    \ cycles[k] = {v} \u306B\u306A\u308B\n\t\t\t\u305D\u306E\u9023\u7D50\u6210\u5206\
    \u304C\u6728\u306E\u5834\u5408 (f[v] = -1) \u306E\u5834\u5408\u306F empty\n\t\t\
    - vector<vector<int>> G(N)\n\t\t\t\u5404\u9802\u70B9\u304B\u3089\u51FA\u3066\u3044\
    \u308B\u8FBA\u306E\u884C\u304D\u5148 (\u30B5\u30A4\u30AF\u30EB\u306E\u8FBA\u306F\
    \u9664\u5916\u3055\u308C\u3066\u3044\u308B)\n\n\t\t- is_tree(k) : k \u756A\u76EE\
    \u306E\u9023\u7D50\u6210\u5206\u304C\u6728\u304B\u3069\u3046\u304B\n\n\n\tverified:\
    \ ABC399-E https://atcoder.jp/contests/abc399/submissions/64421121\n*/\n\nstruct\
    \ FunctionalGraph{\n\t//output\n\tvector<int> con_id;\n\tvector<vector<int>> cons;\n\
    \tvector<vector<int>> cycles;\n\tvector<vector<int>> G;\n\n\tbool is_tree(int\
    \ k){\n\t\tassert(0 <= k && k < si(cons));\n\t\treturn cycles[k].empty();\n\t\
    }\n\t\n\tFunctionalGraph(vector<int> f){\n\t\tint N = f.size();\n\t\tvector<bool>\
    \ vis(N);\n\t\tvector<bool> is_root(N);\n\t\tcon_id.resize(N);\n\t\tG.resize(N);\n\
    \t\trep(v,N) if(f[v] == -1){\n\t\t\tis_root[v] = true;\n\t\t\tf[v] = v;\n\t\t\
    }\n\t\trep(v,N) G[f[v]].pb(v);\n\t\trep(i,N) if(!vis[i]){\n\t\t\tint x = i;\n\t\
    \t\twhile(!vis[x]){\n\t\t\t\tvis[x] = 1;\n\t\t\t\tx = f[x];\n\t\t\t}\n\t\t\tvector<int>\
    \ cycle;\n\t\t\tint s = x;\n\t\t\tdo{\n\t\t\t\tcycle.pb(x);\n\t\t\t\tx = f[x];\n\
    \t\t\t}while(x != s);\n\n\t\t\tint L = cycle.size();\n\t\t\trep(j,L){\n\t\t\t\t\
    int v = cycle[j];\n\t\t\t\terase_if(G[f[v]], [&](int z){ return z == v; });\n\t\
    \t\t}\n\t\t\tqueue<int> que;\n\t\t\trep(j,L) que.push(cycle[j]);\n\t\t\tint k\
    \ = cycles.size();\n\t\t\tvector<int> con;\n\t\t\twhile(!que.empty()){\n\t\t\t\
    \tint v = que.front(); que.pop();\n\t\t\t\tvis[v] = true; con_id[v] = k; con.push_back(v);\n\
    \t\t\t\tfor(int u: G[v]) que.push(u);\n\t\t\t}\n\t\t\tcons.push_back(con);\n\t\
    \t\tif(is_root[cycle[0]]) cycle.clear();\t// \u6728\u306E\u5834\u5408\u306F cycles[k]\
    \ = empty\n\t\t\tcycles.push_back(cycle);\n\t\t}\n\t}\n};\n"
  code: "/*\n\tFunctionalGraph (outdeg = 1) \u306B\u9650\u3089\u305A\u3001 outdeg\
    \ <= 1 \u306A\u6709\u5411\u30B0\u30E9\u30D5\u3092\u3046\u307E\u304F\u6271\u3046\
    \ struct\n\n\tconstructor:\n\t\t- vector<int> f\n\t\t\toutdeg(v) = 1 \u306A\u3089\
    \ f[v] \u304C\u884C\u304D\u5148\u306E\u9802\u70B9\u3001 outdeg = 0 \u306A\u3089\
    \ f[v] = -1\n\n\toutput:\n\t\t- vector<int> con_id(N)\n\t\t\tcon_id[v] : v \u304C\
    \u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E ID\n\t\t- vector<vector<int>>\
    \ cons(K)\n\t\t\tcons[k] : k \u756A\u76EE\u306E\u9023\u7D50\u6210\u5206\u306B\u542B\
    \u307E\u308C\u308B\u9802\u70B9\u306E\u96C6\u5408\n\t\t- vector<vector<int>> cycles(K)\n\
    \t\t\tcycles[k] : k \u756A\u76EE\u306E\u9023\u7D50\u6210\u5206\u306B\u542B\u307E\
    \u308C\u308B\u30B5\u30A4\u30AF\u30EB\u306E\u9802\u70B9\u306E\u96C6\u5408 (a->f[a]->..\
    \ \u306E\u9806\u3067\u4E26\u3093\u3067\u3044\u308B)\n\t\t\t1 \u9802\u70B9 (f[v]\
    \ = v) \u306E\u5834\u5408\u3082 cycles[k] = {v} \u306B\u306A\u308B\n\t\t\t\u305D\
    \u306E\u9023\u7D50\u6210\u5206\u304C\u6728\u306E\u5834\u5408 (f[v] = -1) \u306E\
    \u5834\u5408\u306F empty\n\t\t- vector<vector<int>> G(N)\n\t\t\t\u5404\u9802\u70B9\
    \u304B\u3089\u51FA\u3066\u3044\u308B\u8FBA\u306E\u884C\u304D\u5148 (\u30B5\u30A4\
    \u30AF\u30EB\u306E\u8FBA\u306F\u9664\u5916\u3055\u308C\u3066\u3044\u308B)\n\n\t\
    \t- is_tree(k) : k \u756A\u76EE\u306E\u9023\u7D50\u6210\u5206\u304C\u6728\u304B\
    \u3069\u3046\u304B\n\n\n\tverified: ABC399-E https://atcoder.jp/contests/abc399/submissions/64421121\n\
    */\n\nstruct FunctionalGraph{\n\t//output\n\tvector<int> con_id;\n\tvector<vector<int>>\
    \ cons;\n\tvector<vector<int>> cycles;\n\tvector<vector<int>> G;\n\n\tbool is_tree(int\
    \ k){\n\t\tassert(0 <= k && k < si(cons));\n\t\treturn cycles[k].empty();\n\t\
    }\n\t\n\tFunctionalGraph(vector<int> f){\n\t\tint N = f.size();\n\t\tvector<bool>\
    \ vis(N);\n\t\tvector<bool> is_root(N);\n\t\tcon_id.resize(N);\n\t\tG.resize(N);\n\
    \t\trep(v,N) if(f[v] == -1){\n\t\t\tis_root[v] = true;\n\t\t\tf[v] = v;\n\t\t\
    }\n\t\trep(v,N) G[f[v]].pb(v);\n\t\trep(i,N) if(!vis[i]){\n\t\t\tint x = i;\n\t\
    \t\twhile(!vis[x]){\n\t\t\t\tvis[x] = 1;\n\t\t\t\tx = f[x];\n\t\t\t}\n\t\t\tvector<int>\
    \ cycle;\n\t\t\tint s = x;\n\t\t\tdo{\n\t\t\t\tcycle.pb(x);\n\t\t\t\tx = f[x];\n\
    \t\t\t}while(x != s);\n\n\t\t\tint L = cycle.size();\n\t\t\trep(j,L){\n\t\t\t\t\
    int v = cycle[j];\n\t\t\t\terase_if(G[f[v]], [&](int z){ return z == v; });\n\t\
    \t\t}\n\t\t\tqueue<int> que;\n\t\t\trep(j,L) que.push(cycle[j]);\n\t\t\tint k\
    \ = cycles.size();\n\t\t\tvector<int> con;\n\t\t\twhile(!que.empty()){\n\t\t\t\
    \tint v = que.front(); que.pop();\n\t\t\t\tvis[v] = true; con_id[v] = k; con.push_back(v);\n\
    \t\t\t\tfor(int u: G[v]) que.push(u);\n\t\t\t}\n\t\t\tcons.push_back(con);\n\t\
    \t\tif(is_root[cycle[0]]) cycle.clear();\t// \u6728\u306E\u5834\u5408\u306F cycles[k]\
    \ = empty\n\t\t\tcycles.push_back(cycle);\n\t\t}\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/functional_graph.hpp
  requiredBy: []
  timestamp: '2025-04-03 01:58:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/functional_graph.hpp
layout: document
redirect_from:
- /library/graph/functional_graph.hpp
- /library/graph/functional_graph.hpp.html
title: graph/functional_graph.hpp
---
