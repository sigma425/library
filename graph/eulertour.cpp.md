---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://www.codechef.com/LTIME37/problems/TRAVTREE
  bundledCode: "#line 1 \"graph/eulertour.cpp\"\n/*\n\t- in \u306E\u307F\n\t- in out\
    \ \u306E\u307F\n\t- \u8A2A\u308C\u308B\u305F\u3073\n\t\u306E3\u901A\u308A\n\n\t\
    subtree\t: in\u306E\u307F \u3067\u5341\u5206\n\tpath\t: in out\n\tlca\t\t: \u8A2A\
    \u308C\u308B\u305F\u3073\n\n\teulertour\n\tw=lca(a,b)\u3068\u3057\u3066,2\u3064\
    \u306Epath\u306B\u308F\u3051\u308B.wa,wb,\u3092\u3084\u3063\u305F\u3042\u3068\
    ww\u3092\u5F15\u304F\u306E\u3082\u624B.\n\t\u66F4\u65B0\u306F add(v2id[w][0],v2id[a][0]+1,*)\
    \ \u306E\u5F62 +1\u306B\u6CE8\u610F\n\t\u30AF\u30A8\u30EA\u3082\u540C\u69D8\u306A\
    \u3093\u3060\u3051\u3069,\u70B9\u30AF\u30A8\u30EA\u304C\u52D8\u9055\u3044\u3057\
    \u3084\u3059\u304F\u3066,\u3061\u3083\u3093\u3068val(v2id[v][0])-val(v2id[v][1])\
    \ \u3068\u5DEE\u5206\u3092\u53D6\u308B\u3053\u3068.\n\n\tverified by https://www.codechef.com/LTIME37/problems/TRAVTREE\n\
    */\nstruct EulerTour{\t\t//in + out version\n\tint I = 0;\n\tvector<int> id,in,out;\n\
    \n\tEulerTour(const vector<vector<int>>& G, int r = 0){\n\t\tint N = G.size();\n\
    \t\tid.assign(2*N,0);\n\t\tin.assign(N,0);\n\t\tout.assign(N,0);\n\t\ttraverse(r,-1,G);\n\
    \t}\n\n\tvoid traverse(int v,int p,const vector<vector<int>>& G){\n\t\tid[I]=v,in[v]=I,I++;\n\
    \t\tfor(int u:G[v]) if(u!=p) traverse(u,v,G);\n\t\tid[I]=v,out[v]=I,I++;\n\t}\n\
    };\n"
  code: "/*\n\t- in \u306E\u307F\n\t- in out \u306E\u307F\n\t- \u8A2A\u308C\u308B\u305F\
    \u3073\n\t\u306E3\u901A\u308A\n\n\tsubtree\t: in\u306E\u307F \u3067\u5341\u5206\
    \n\tpath\t: in out\n\tlca\t\t: \u8A2A\u308C\u308B\u305F\u3073\n\n\teulertour\n\
    \tw=lca(a,b)\u3068\u3057\u3066,2\u3064\u306Epath\u306B\u308F\u3051\u308B.wa,wb,\u3092\
    \u3084\u3063\u305F\u3042\u3068ww\u3092\u5F15\u304F\u306E\u3082\u624B.\n\t\u66F4\
    \u65B0\u306F add(v2id[w][0],v2id[a][0]+1,*) \u306E\u5F62 +1\u306B\u6CE8\u610F\n\
    \t\u30AF\u30A8\u30EA\u3082\u540C\u69D8\u306A\u3093\u3060\u3051\u3069,\u70B9\u30AF\
    \u30A8\u30EA\u304C\u52D8\u9055\u3044\u3057\u3084\u3059\u304F\u3066,\u3061\u3083\
    \u3093\u3068val(v2id[v][0])-val(v2id[v][1]) \u3068\u5DEE\u5206\u3092\u53D6\u308B\
    \u3053\u3068.\n\n\tverified by https://www.codechef.com/LTIME37/problems/TRAVTREE\n\
    */\nstruct EulerTour{\t\t//in + out version\n\tint I = 0;\n\tvector<int> id,in,out;\n\
    \n\tEulerTour(const vector<vector<int>>& G, int r = 0){\n\t\tint N = G.size();\n\
    \t\tid.assign(2*N,0);\n\t\tin.assign(N,0);\n\t\tout.assign(N,0);\n\t\ttraverse(r,-1,G);\n\
    \t}\n\n\tvoid traverse(int v,int p,const vector<vector<int>>& G){\n\t\tid[I]=v,in[v]=I,I++;\n\
    \t\tfor(int u:G[v]) if(u!=p) traverse(u,v,G);\n\t\tid[I]=v,out[v]=I,I++;\n\t}\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: graph/eulertour.cpp
  requiredBy: []
  timestamp: '2017-07-04 20:23:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/eulertour.cpp
layout: document
redirect_from:
- /library/graph/eulertour.cpp
- /library/graph/eulertour.cpp.html
title: graph/eulertour.cpp
---
