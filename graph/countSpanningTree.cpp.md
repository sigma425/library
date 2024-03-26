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
  bundledCode: "#line 1 \"graph/countSpanningTree.cpp\"\n/*\n\t# (directed spanning\
    \ tree rooted at r)\n\t = det (-e[i][j] \u306E\u5BFE\u89D2\u6210\u5206\u306Bindeg[i]\
    \ \u8DB3\u3057\u305F\u3084\u3064\u3001 \u306E (r,r) \u9664\u3044\u305F\u5C0F\u884C\
    \u5217)\n\t\u975E\u9023\u7D50\u3060\u3068\u5F53\u7136 0 \u306B\u306A\u308B\n\t\
    \u30AA\u30A4\u30E9\u30FC\u9589\u8DEF\u306E\u6570\u3092\u6570\u3048\u308B\u306E\
    \u306B\u4F7F\u3048\u308B:\n\t\tBEST Theorem\n\t\tec(G) = #dirSpt * \\prod_v (deg[v]-1)!\n\
    \t\u30AA\u30A4\u30E9\u30FC\u9589\u8DEF\u306F\u5B64\u7ACB\u70B9\u304C\u3042\u3063\
    \u3066\u3082\u5B58\u5728\u3059\u308B \u2193\u306E\u30B3\u30FC\u30C9\u306F\u5185\
    \u90E8\u3067\u9664\u3044\u3066\u308B\u306E\u3067\u6CE8\u610F\n\n\t\u691C\u7D22\
    \u7528: \u6709\u5411\u5168\u57DF\u6728 \u884C\u5217\u6728\u5B9A\u7406\n*/\nmint\
    \ countDirSpt(VV<int> e, int r){\n\tint N = si(e);\n\tV<int> indeg(N),outdeg(N);\n\
    \trep(i,N) rep(j,N){\n\t\tindeg[j] += e[i][j];\n\t\toutdeg[i] += e[i][j];\n\t\
    }\n\t{\n\t\tbool hase = false;\n\t\trep(i,N) if(indeg[i]) hase = true;\n\t}\n\t\
    rep(i,N) if(indeg[i] != outdeg[i]) return 0;\n\tif(indeg[r] == 0) return 0;\n\n\
    \tV<int> id(N,-1);\n\tint I = 0;\n\trep(i,N){\n\t\tif(indeg[i] && i != r){\n\t\
    \t\tid[i] = I++;\n\t\t}\n\t}\n\tVV<mint> A(I,V<mint>(I));\n\n\trep(i,N) if(id[i]\
    \ != -1) rep(j,N) if(id[j] != -1){\n\t\tif(i != j){\n\t\t\tA[id[i]][id[j]] = -e[i][j];\n\
    \t\t}else{\n\t\t\tA[id[i]][id[i]] = indeg[i] - e[i][i];\n\t\t}\n\t}\n\tshow(A);\n\
    \tmint res = det(A);\n\trep(i,N) if(indeg[i]) res *= fact[indeg[i]-1];\n\treturn\
    \ res;\n}\n"
  code: "/*\n\t# (directed spanning tree rooted at r)\n\t = det (-e[i][j] \u306E\u5BFE\
    \u89D2\u6210\u5206\u306Bindeg[i] \u8DB3\u3057\u305F\u3084\u3064\u3001 \u306E (r,r)\
    \ \u9664\u3044\u305F\u5C0F\u884C\u5217)\n\t\u975E\u9023\u7D50\u3060\u3068\u5F53\
    \u7136 0 \u306B\u306A\u308B\n\t\u30AA\u30A4\u30E9\u30FC\u9589\u8DEF\u306E\u6570\
    \u3092\u6570\u3048\u308B\u306E\u306B\u4F7F\u3048\u308B:\n\t\tBEST Theorem\n\t\t\
    ec(G) = #dirSpt * \\prod_v (deg[v]-1)!\n\t\u30AA\u30A4\u30E9\u30FC\u9589\u8DEF\
    \u306F\u5B64\u7ACB\u70B9\u304C\u3042\u3063\u3066\u3082\u5B58\u5728\u3059\u308B\
    \ \u2193\u306E\u30B3\u30FC\u30C9\u306F\u5185\u90E8\u3067\u9664\u3044\u3066\u308B\
    \u306E\u3067\u6CE8\u610F\n\n\t\u691C\u7D22\u7528: \u6709\u5411\u5168\u57DF\u6728\
    \ \u884C\u5217\u6728\u5B9A\u7406\n*/\nmint countDirSpt(VV<int> e, int r){\n\t\
    int N = si(e);\n\tV<int> indeg(N),outdeg(N);\n\trep(i,N) rep(j,N){\n\t\tindeg[j]\
    \ += e[i][j];\n\t\toutdeg[i] += e[i][j];\n\t}\n\t{\n\t\tbool hase = false;\n\t\
    \trep(i,N) if(indeg[i]) hase = true;\n\t}\n\trep(i,N) if(indeg[i] != outdeg[i])\
    \ return 0;\n\tif(indeg[r] == 0) return 0;\n\n\tV<int> id(N,-1);\n\tint I = 0;\n\
    \trep(i,N){\n\t\tif(indeg[i] && i != r){\n\t\t\tid[i] = I++;\n\t\t}\n\t}\n\tVV<mint>\
    \ A(I,V<mint>(I));\n\n\trep(i,N) if(id[i] != -1) rep(j,N) if(id[j] != -1){\n\t\
    \tif(i != j){\n\t\t\tA[id[i]][id[j]] = -e[i][j];\n\t\t}else{\n\t\t\tA[id[i]][id[i]]\
    \ = indeg[i] - e[i][i];\n\t\t}\n\t}\n\tshow(A);\n\tmint res = det(A);\n\trep(i,N)\
    \ if(indeg[i]) res *= fact[indeg[i]-1];\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/countSpanningTree.cpp
  requiredBy: []
  timestamp: '2024-03-26 11:10:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/countSpanningTree.cpp
layout: document
redirect_from:
- /library/graph/countSpanningTree.cpp
- /library/graph/countSpanningTree.cpp.html
title: graph/countSpanningTree.cpp
---
