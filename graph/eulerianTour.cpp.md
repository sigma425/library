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
  bundledCode: "#line 1 \"graph/eulerianTour.cpp\"\n/*\n\t\u6709\u5411\u30B0\u30E9\
    \u30D5\u306E\u30AA\u30A4\u30E9\u30FC\u9589\u8DEF\n\t\u9023\u7D50\u304B\u3069\u3046\
    \u304B\u3082\u5224\u5B9A\n\t\u7A7A\u30B0\u30E9\u30D5\u3092\u533A\u5225\u3059\u308B\
    \u305F\u3081 bool,V<int> \u3092\u8FD4\u3057\u3066\u3044\u308B\n\tO(N+M)\n*/\n\
    template<class E> pair<bool,V<int>> eulerianTour(const VV<E>& G){\n\tint N = G.size();\n\
    \tint s = -1;\n\trep(i,N) if(!G[i].empty()) s = i;\n\tif(s == -1){\n\t\treturn\
    \ make_pair(true,V<int>());\n\t}\n\tV<int> indeg(N),outdeg(N);\n\trep(i,N) for(auto\
    \ e: G[i]){\n\t\tint j = e.to;\n\t\toutdeg[i]++, indeg[j]++;\n\t}\n\trep(i,N)\
    \ if(indeg[i] != outdeg[i]){\n\t\treturn make_pair(false,V<int>());\n\t}\n\t//\
    \ using P = pair<int,int>;\n\t// map<int,P> mp;\n\t// rep(i,N) for(auto e: G[i]){\n\
    \t// \tmp[e.id] = P(i,e.to);\n\t// }\n\tint M = 0;\n\trep(i,N) M += G[i].size();\n\
    \tV<int> it(N);\n\tV<int> euler;\n\tauto dfs = [&](auto&& self, int v) -> void\
    \ {\n\t\twhile(it[v] != si(G[v])){\n\t\t\tauto e = G[v][it[v]];\n\t\t\tit[v]++;\n\
    \t\t\tself(self,e.to);\n\t\t\teuler.eb(e.id);\n\t\t}\n\t};\n\tdfs(dfs,s);\n\t\
    reverse(all(euler));\n\tif(si(euler) != M) return make_pair(false,V<int>());\n\
    \t// rep(i,M) assert(mp[euler[i]].sc == mp[euler[(i+1)%M]].fs);\n\treturn make_pair(true,euler);\n\
    }\n\nstruct Edge{\n\tint to,id;\n\tEdge(int to_, int id_):to(to_),id(id_){}\n\
    };\n"
  code: "/*\n\t\u6709\u5411\u30B0\u30E9\u30D5\u306E\u30AA\u30A4\u30E9\u30FC\u9589\u8DEF\
    \n\t\u9023\u7D50\u304B\u3069\u3046\u304B\u3082\u5224\u5B9A\n\t\u7A7A\u30B0\u30E9\
    \u30D5\u3092\u533A\u5225\u3059\u308B\u305F\u3081 bool,V<int> \u3092\u8FD4\u3057\
    \u3066\u3044\u308B\n\tO(N+M)\n*/\ntemplate<class E> pair<bool,V<int>> eulerianTour(const\
    \ VV<E>& G){\n\tint N = G.size();\n\tint s = -1;\n\trep(i,N) if(!G[i].empty())\
    \ s = i;\n\tif(s == -1){\n\t\treturn make_pair(true,V<int>());\n\t}\n\tV<int>\
    \ indeg(N),outdeg(N);\n\trep(i,N) for(auto e: G[i]){\n\t\tint j = e.to;\n\t\t\
    outdeg[i]++, indeg[j]++;\n\t}\n\trep(i,N) if(indeg[i] != outdeg[i]){\n\t\treturn\
    \ make_pair(false,V<int>());\n\t}\n\t// using P = pair<int,int>;\n\t// map<int,P>\
    \ mp;\n\t// rep(i,N) for(auto e: G[i]){\n\t// \tmp[e.id] = P(i,e.to);\n\t// }\n\
    \tint M = 0;\n\trep(i,N) M += G[i].size();\n\tV<int> it(N);\n\tV<int> euler;\n\
    \tauto dfs = [&](auto&& self, int v) -> void {\n\t\twhile(it[v] != si(G[v])){\n\
    \t\t\tauto e = G[v][it[v]];\n\t\t\tit[v]++;\n\t\t\tself(self,e.to);\n\t\t\teuler.eb(e.id);\n\
    \t\t}\n\t};\n\tdfs(dfs,s);\n\treverse(all(euler));\n\tif(si(euler) != M) return\
    \ make_pair(false,V<int>());\n\t// rep(i,M) assert(mp[euler[i]].sc == mp[euler[(i+1)%M]].fs);\n\
    \treturn make_pair(true,euler);\n}\n\nstruct Edge{\n\tint to,id;\n\tEdge(int to_,\
    \ int id_):to(to_),id(id_){}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/eulerianTour.cpp
  requiredBy: []
  timestamp: '2023-11-14 00:07:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/eulerianTour.cpp
layout: document
redirect_from:
- /library/graph/eulerianTour.cpp
- /library/graph/eulerianTour.cpp.html
title: graph/eulerianTour.cpp
---
