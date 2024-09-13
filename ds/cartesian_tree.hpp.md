---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: string/suffix_tree.hpp
    title: string/suffix_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_oj/cartesian_tree.test.cpp
    title: test_oj/cartesian_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/cartesian_tree.hpp\"\n/*\n\tcartesian tree\n\t\u4E00\u756A\
    \u5C0F\u3055\u3044\u3068\u3053\u308D\u3067 i \u5206\u3051\u3066\u3001\u5DE6\u53F3\
    \u306B\u5206\u5272\n\trange[i] = [l,r) \u306E min/max \u304C A[i]\n\t[l,i) \u306E\
    \ min \u304C lch[i], [i+1,r) \u306E min \u304C rch[i] \u7A7A\u306A\u3089 -1\n\t\
    \u4E00\u756A\u5C0F\u3055\u3044\u3068\u3053\u304C root\n\n\ttie-break \u306F\u8F9E\
    \u66F8\u9806\n\n\tverify: yosupo judge\n*/\ntemplate<class T, bool is_min>\nstruct\
    \ CartesianTree {\n\tint N;\n\tvector<T> A;\n\tvector<pair<int,int>> range;\n\t\
    vector<int> lch,rch,par;\n\tint root;\n\n\tCartesianTree(const vector<T>& A_):\
    \ N(A_.size()), A(A_), range(N), lch(N,-1), rch(N,-1), par(N,-1){\n\t\tauto less\
    \ = [&](int i, int j) -> bool {\n\t\t\tif(is_min) return (A[i] < A[j]) || (A[i]\
    \ == A[j] && i < j);\n\t\t\treturn (A[i] > A[j]) || (A[i] == A[j] && i < j);\n\
    \t\t};\n\t\tvector<int> st;\n\t\trep(i,N){\n\t\t\twhile(!st.empty() && less(i,\
    \ st.back())){\n\t\t\t\tlch[i] = st.back();\n\t\t\t\tst.pop_back();\n\t\t\t}\n\
    \t\t\trange[i].first = (st.empty() ? 0 : st.back() + 1);\n\t\t\tst.eb(i);\n\t\t\
    }\n\t\tst.clear();\n\t\tper(i,N){\n\t\t\twhile(!st.empty() && less(i, st.back())){\n\
    \t\t\t\trch[i] = st.back();\n\t\t\t\tst.pop_back();\n\t\t\t}\n\t\t\trange[i].second\
    \ = (st.empty() ? N : st.back());\n\t\t\tst.eb(i);\n\t\t}\n\t\trep(i,N){\n\t\t\
    \tif(lch[i] != -1) par[lch[i]] = i;\n\t\t\tif(rch[i] != -1) par[rch[i]] = i;\n\
    \t\t}\n\t\trep(i,N) if(par[i] == -1) root = i;\n\t}\n\n\t/*\n\t\t(l, r, h)\n\t\
    \tl <= i < r\n\t\th[i] \u3092\u3067\u304D\u308B\u3060\u3051\u5DE6\u53F3\u306B\u4F38\
    \u3070\u3057\u305F\u6642\u306E\u9577\u65B9\u5F62\n\t*/\n\ttuple<int, int, T> maximum_rectangle(int\
    \ i){\n\t\treturn {range[i].first, range[i].second, A[i]};\n\t}\n};\n"
  code: "/*\n\tcartesian tree\n\t\u4E00\u756A\u5C0F\u3055\u3044\u3068\u3053\u308D\u3067\
    \ i \u5206\u3051\u3066\u3001\u5DE6\u53F3\u306B\u5206\u5272\n\trange[i] = [l,r)\
    \ \u306E min/max \u304C A[i]\n\t[l,i) \u306E min \u304C lch[i], [i+1,r) \u306E\
    \ min \u304C rch[i] \u7A7A\u306A\u3089 -1\n\t\u4E00\u756A\u5C0F\u3055\u3044\u3068\
    \u3053\u304C root\n\n\ttie-break \u306F\u8F9E\u66F8\u9806\n\n\tverify: yosupo\
    \ judge\n*/\ntemplate<class T, bool is_min>\nstruct CartesianTree {\n\tint N;\n\
    \tvector<T> A;\n\tvector<pair<int,int>> range;\n\tvector<int> lch,rch,par;\n\t\
    int root;\n\n\tCartesianTree(const vector<T>& A_): N(A_.size()), A(A_), range(N),\
    \ lch(N,-1), rch(N,-1), par(N,-1){\n\t\tauto less = [&](int i, int j) -> bool\
    \ {\n\t\t\tif(is_min) return (A[i] < A[j]) || (A[i] == A[j] && i < j);\n\t\t\t\
    return (A[i] > A[j]) || (A[i] == A[j] && i < j);\n\t\t};\n\t\tvector<int> st;\n\
    \t\trep(i,N){\n\t\t\twhile(!st.empty() && less(i, st.back())){\n\t\t\t\tlch[i]\
    \ = st.back();\n\t\t\t\tst.pop_back();\n\t\t\t}\n\t\t\trange[i].first = (st.empty()\
    \ ? 0 : st.back() + 1);\n\t\t\tst.eb(i);\n\t\t}\n\t\tst.clear();\n\t\tper(i,N){\n\
    \t\t\twhile(!st.empty() && less(i, st.back())){\n\t\t\t\trch[i] = st.back();\n\
    \t\t\t\tst.pop_back();\n\t\t\t}\n\t\t\trange[i].second = (st.empty() ? N : st.back());\n\
    \t\t\tst.eb(i);\n\t\t}\n\t\trep(i,N){\n\t\t\tif(lch[i] != -1) par[lch[i]] = i;\n\
    \t\t\tif(rch[i] != -1) par[rch[i]] = i;\n\t\t}\n\t\trep(i,N) if(par[i] == -1)\
    \ root = i;\n\t}\n\n\t/*\n\t\t(l, r, h)\n\t\tl <= i < r\n\t\th[i] \u3092\u3067\
    \u304D\u308B\u3060\u3051\u5DE6\u53F3\u306B\u4F38\u3070\u3057\u305F\u6642\u306E\
    \u9577\u65B9\u5F62\n\t*/\n\ttuple<int, int, T> maximum_rectangle(int i){\n\t\t\
    return {range[i].first, range[i].second, A[i]};\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/cartesian_tree.hpp
  requiredBy:
  - string/suffix_tree.hpp
  timestamp: '2024-09-14 08:25:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_oj/cartesian_tree.test.cpp
documentation_of: ds/cartesian_tree.hpp
layout: document
redirect_from:
- /library/ds/cartesian_tree.hpp
- /library/ds/cartesian_tree.hpp.html
title: ds/cartesian_tree.hpp
---
