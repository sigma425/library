---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/cartesian_tree.hpp
    title: ds/cartesian_tree.hpp
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"test_oj/cartesian_tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\
    \n\n#line 2 \"template.hpp\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\nusing ll = long long;\r\nusing uint = unsigned int;\r\nusing ull = unsigned\
    \ long long;\r\n#define rep(i,n) for(int i=0;i<int(n);i++)\r\n#define rep1(i,n)\
    \ for(int i=1;i<=int(n);i++)\r\n#define per(i,n) for(int i=int(n)-1;i>=0;i--)\r\
    \n#define per1(i,n) for(int i=int(n);i>0;i--)\r\n#define all(c) c.begin(),c.end()\r\
    \n#define si(x) int(x.size())\r\n#define pb push_back\r\n#define eb emplace_back\r\
    \n#define fs first\r\n#define sc second\r\ntemplate<class T> using V = vector<T>;\r\
    \ntemplate<class T> using VV = vector<vector<T>>;\r\ntemplate<class T,class U>\
    \ bool chmax(T& x, U y){\r\n\tif(x<y){ x=y; return true; }\r\n\treturn false;\r\
    \n}\r\ntemplate<class T,class U> bool chmin(T& x, U y){\r\n\tif(y<x){ x=y; return\
    \ true; }\r\n\treturn false;\r\n}\r\ntemplate<class T> void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}\r\
    \ntemplate<class T> int lwb(const V<T>& v, const T& a){return lower_bound(all(v),a)\
    \ - v.begin();}\r\ntemplate<class T>\r\nV<T> Vec(size_t a) {\r\n    return V<T>(a);\r\
    \n}\r\ntemplate<class T, class... Ts>\r\nauto Vec(size_t a, Ts... ts) {\r\n  return\
    \ V<decltype(Vec<T>(ts...))>(a, Vec<T>(ts...));\r\n}\r\ntemplate<class S,class\
    \ T> ostream& operator<<(ostream& o,const pair<S,T> &p){\r\n\treturn o<<\"(\"\
    <<p.fs<<\",\"<<p.sc<<\")\";\r\n}\r\ntemplate<class T> ostream& operator<<(ostream&\
    \ o,const vector<T> &vc){\r\n\to<<\"{\";\r\n\tfor(const T& v:vc) o<<v<<\",\";\r\
    \n\to<<\"}\";\r\n\treturn o;\r\n}\r\nconstexpr ll TEN(int n) { return (n == 0)\
    \ ? 1 : 10 * TEN(n-1); }\r\n\r\n#ifdef LOCAL\r\n#define show(x) cerr << \"LINE\"\
    \ << __LINE__ << \" : \" << #x << \" = \" << (x) << endl\r\nvoid dmpr(ostream&\
    \ os){os<<endl;}\r\ntemplate<class T,class... Args>\r\nvoid dmpr(ostream&os,const\
    \ T&t,const Args&... args){\r\n\tos<<t<<\" ~ \";\r\n\tdmpr(os,args...);\r\n}\r\
    \n#define shows(...) cerr << \"LINE\" << __LINE__ << \" : \";dmpr(cerr,##__VA_ARGS__)\r\
    \n#define dump(x) cerr << \"LINE\" << __LINE__ << \" : \" << #x << \" = {\"; \
    \ \\\r\n\tfor(auto v: x) cerr << v << \",\"; cerr << \"}\" << endl;\r\n#else\r\
    \n#define show(x) void(0)\r\n#define dump(x) void(0)\r\n#define shows(...) void(0)\r\
    \n#endif\r\n\r\ntemplate<class D> D divFloor(D a, D b){\r\n\treturn a / b - (((a\
    \ ^ b) < 0 && a % b != 0) ? 1 : 0);\r\n}\r\ntemplate<class D> D divCeil(D a, D\
    \ b) {\r\n\treturn a / b + (((a ^ b) > 0 && a % b != 0) ? 1 : 0);\r\n}\r\n#line\
    \ 1 \"ds/cartesian_tree.hpp\"\n/*\n\tcartesian tree\n\t\u4E00\u756A\u5C0F\u3055\
    \u3044\u3068\u3053\u308D\u3067 i \u5206\u3051\u3066\u3001\u5DE6\u53F3\u306B\u5206\
    \u5272\n\trange[i] = [l,r) \u306E min/max \u304C A[i]\n\t[l,i) \u306E min \u304C\
    \ lch[i], [i+1,r) \u306E min \u304C rch[i] \u7A7A\u306A\u3089 -1\n\t\u4E00\u756A\
    \u5C0F\u3055\u3044\u3068\u3053\u304C root\n\n\ttie-break \u306F\u8F9E\u66F8\u9806\
    \n\n\tverify: yosupo judge\n*/\ntemplate<class T, bool is_min>\nstruct CartesianTree\
    \ {\n\tint N;\n\tvector<T> A;\n\tvector<pair<int,int>> range;\n\tvector<int> lch,rch,par;\n\
    \tint root;\n\n\tCartesianTree(const vector<T>& A_): N(A_.size()), A(A_), range(N),\
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
    return {range[i].first, range[i].second, A[i]};\n\t}\n};\n#line 5 \"test_oj/cartesian_tree.test.cpp\"\
    \n\nint main(){\n\tint N; cin >> N;\n\tV<int> A(N); rep(i,N) cin >> A[i];\n\t\
    CartesianTree<int, true> Tree(A);\n\trep(i,N){\n\t\tif(Tree.par[i] == -1) cout\
    \ << i << \" \";\n\t\telse cout << Tree.par[i] << \" \";\n\t}\n\tcout << endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include\
    \ \"template.hpp\"\n#include \"ds/cartesian_tree.hpp\"\n\nint main(){\n\tint N;\
    \ cin >> N;\n\tV<int> A(N); rep(i,N) cin >> A[i];\n\tCartesianTree<int, true>\
    \ Tree(A);\n\trep(i,N){\n\t\tif(Tree.par[i] == -1) cout << i << \" \";\n\t\telse\
    \ cout << Tree.par[i] << \" \";\n\t}\n\tcout << endl;\n}\n"
  dependsOn:
  - template.hpp
  - ds/cartesian_tree.hpp
  isVerificationFile: true
  path: test_oj/cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2024-09-14 08:25:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test_oj/cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/test_oj/cartesian_tree.test.cpp
- /verify/test_oj/cartesian_tree.test.cpp.html
title: test_oj/cartesian_tree.test.cpp
---
