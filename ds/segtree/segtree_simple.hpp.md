---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_oj/segtree/point_add_range_sum.test.cpp
    title: test_oj/segtree/point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/segtree/segtree_simple.hpp\"\n/*\r\n\tsegtree\r\n\tpoint\
    \ seg/add, range sum\r\n*/\r\ntemplate<class D>\r\nstruct Segtree{\r\n\tint N;\r\
    \n\tvector<D> val;\r\n\r\n\tSegtree(){}\r\n\tSegtree(int n){\r\n\t\tN = 1; while(N\
    \ < n) N *= 2;\r\n\t\tval.assign(N*2, D());\r\n\t}\r\n\ttemplate<class Dlike>\r\
    \n\tSegtree(const vector<Dlike>& vs){\r\n\t\tint n = vs.size();\r\n\t\tN = 1;\
    \ while(N < n) N *= 2;\r\n\t\tval.assign(N*2, D());\r\n\t\trep(i,n) val[i+N] =\
    \ vs[i];\r\n\t\tfor(int i=N-1;i>0;i--) val[i] = D::op(val[i*2],val[i*2+1]);\r\n\
    \t}\r\n\tvoid set(int k, D v){\r\n\t\tk += N;\r\n\t\tval[k] = v;\r\n\t\tk /= 2;\r\
    \n\t\twhile(k){\r\n\t\t\tval[k] = D::op(val[k*2],val[k*2+1]);\r\n\t\t\tk /= 2;\r\
    \n\t\t}\r\n\t}\r\n\tvoid add(int k, D v){\r\n\t\tk += N;\r\n\t\tval[k] = D::op(val[k],v);\r\
    \n\t\tk /= 2;\r\n\t\twhile(k){\r\n\t\t\tval[k] = D::op(val[k*2],val[k*2+1]);\r\
    \n\t\t\tk /= 2;\r\n\t\t}\r\n\t}\r\n\tD query(int a, int b){\t\t//non-commutative\
    \ & unrecursive\r\n\t\tD L = D() , R = D();\r\n\t\ta += N, b += N;\r\n\t\twhile(a<b){\r\
    \n\t\t\tif(a&1) L = D::op(L,val[a++]);\r\n\t\t\tif(b&1) R = D::op(val[--b],R);\r\
    \n\t\t\ta /= 2, b /= 2;\r\n\t\t}\r\n\t\treturn D::op(L,R);\r\n\t}\r\n};\r\n\r\n\
    // struct D{\r\n// \tint v;\r\n// \tD(){ *this = e(); }\r\n// \tD(int v_):v(v_){}\r\
    \n// \tstatic D op(const D& x,const D& y){\r\n// \t\treturn D(x.v+y.v);\r\n//\
    \ \t}\r\n// \tconst static D e(){\r\n// \t\treturn D(0);\r\n// \t}\r\n// //\t\
    friend ostream& operator<<(ostream& o,const D& d){return o<<d.v;}\r\n// };\r\n"
  code: "/*\r\n\tsegtree\r\n\tpoint seg/add, range sum\r\n*/\r\ntemplate<class D>\r\
    \nstruct Segtree{\r\n\tint N;\r\n\tvector<D> val;\r\n\r\n\tSegtree(){}\r\n\tSegtree(int\
    \ n){\r\n\t\tN = 1; while(N < n) N *= 2;\r\n\t\tval.assign(N*2, D());\r\n\t}\r\
    \n\ttemplate<class Dlike>\r\n\tSegtree(const vector<Dlike>& vs){\r\n\t\tint n\
    \ = vs.size();\r\n\t\tN = 1; while(N < n) N *= 2;\r\n\t\tval.assign(N*2, D());\r\
    \n\t\trep(i,n) val[i+N] = vs[i];\r\n\t\tfor(int i=N-1;i>0;i--) val[i] = D::op(val[i*2],val[i*2+1]);\r\
    \n\t}\r\n\tvoid set(int k, D v){\r\n\t\tk += N;\r\n\t\tval[k] = v;\r\n\t\tk /=\
    \ 2;\r\n\t\twhile(k){\r\n\t\t\tval[k] = D::op(val[k*2],val[k*2+1]);\r\n\t\t\t\
    k /= 2;\r\n\t\t}\r\n\t}\r\n\tvoid add(int k, D v){\r\n\t\tk += N;\r\n\t\tval[k]\
    \ = D::op(val[k],v);\r\n\t\tk /= 2;\r\n\t\twhile(k){\r\n\t\t\tval[k] = D::op(val[k*2],val[k*2+1]);\r\
    \n\t\t\tk /= 2;\r\n\t\t}\r\n\t}\r\n\tD query(int a, int b){\t\t//non-commutative\
    \ & unrecursive\r\n\t\tD L = D() , R = D();\r\n\t\ta += N, b += N;\r\n\t\twhile(a<b){\r\
    \n\t\t\tif(a&1) L = D::op(L,val[a++]);\r\n\t\t\tif(b&1) R = D::op(val[--b],R);\r\
    \n\t\t\ta /= 2, b /= 2;\r\n\t\t}\r\n\t\treturn D::op(L,R);\r\n\t}\r\n};\r\n\r\n\
    // struct D{\r\n// \tint v;\r\n// \tD(){ *this = e(); }\r\n// \tD(int v_):v(v_){}\r\
    \n// \tstatic D op(const D& x,const D& y){\r\n// \t\treturn D(x.v+y.v);\r\n//\
    \ \t}\r\n// \tconst static D e(){\r\n// \t\treturn D(0);\r\n// \t}\r\n// //\t\
    friend ostream& operator<<(ostream& o,const D& d){return o<<d.v;}\r\n// };\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/segtree_simple.hpp
  requiredBy: []
  timestamp: '2024-09-05 20:51:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_oj/segtree/point_add_range_sum.test.cpp
documentation_of: ds/segtree/segtree_simple.hpp
layout: document
redirect_from:
- /library/ds/segtree/segtree_simple.hpp
- /library/ds/segtree/segtree_simple.hpp.html
title: ds/segtree/segtree_simple.hpp
---
