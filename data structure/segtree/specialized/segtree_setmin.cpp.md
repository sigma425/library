---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data structure/segtree/specialized/segtree_setmin.cpp\"\n\
    /*\n\tpoint val\n\tset range min\n*/\nstruct segtree2{\n\tusing D = int;\n\tD\
    \ inf = 1e9;\n\n\tint N;\n\tvector<D> val;\n\n\tsegtree2(){}\n\tsegtree2(int n){\n\
    \t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\tval.assign(N*2,inf);\n\t}\n\tsegtree2(const\
    \ vector<D>& ds){\n\t\tint n = ds.size();\n\t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\t\
    val.assign(N*2,inf);\n\t\trep(i,n) val[i+N] = ds[i];\n\t\tfor(int i=N-1;i>0;i--)\
    \ val[i] = min(val[i*2],val[i*2+1]);\n\t}\n\tD getval(int k){\n\t\tD res = inf;\n\
    \t\tk+=N;\n\t\twhile(k){\n\t\t\tchmin(res,val[k]);\n\t\t\tk/=2;\n\t\t}\n\t\treturn\
    \ res;\n\t}\n\tvoid changemin(int a,int b,D d){\n\t\ta+=N,b+=N;\n\t\twhile(a<b){\n\
    \t\t\tif(a&1){\n\t\t\t\tchmin(val[a],d);\n\t\t\t\ta++;\n\t\t\t}\n\t\t\tif(b&1){\n\
    \t\t\t\t--b;\n\t\t\t\tchmin(val[b],d);\n\t\t\t}\n\t\t\ta/=2,b/=2;\n\t\t}\n\t}\n\
    };\n"
  code: "/*\n\tpoint val\n\tset range min\n*/\nstruct segtree2{\n\tusing D = int;\n\
    \tD inf = 1e9;\n\n\tint N;\n\tvector<D> val;\n\n\tsegtree2(){}\n\tsegtree2(int\
    \ n){\n\t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\tval.assign(N*2,inf);\n\t}\n\tsegtree2(const\
    \ vector<D>& ds){\n\t\tint n = ds.size();\n\t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\t\
    val.assign(N*2,inf);\n\t\trep(i,n) val[i+N] = ds[i];\n\t\tfor(int i=N-1;i>0;i--)\
    \ val[i] = min(val[i*2],val[i*2+1]);\n\t}\n\tD getval(int k){\n\t\tD res = inf;\n\
    \t\tk+=N;\n\t\twhile(k){\n\t\t\tchmin(res,val[k]);\n\t\t\tk/=2;\n\t\t}\n\t\treturn\
    \ res;\n\t}\n\tvoid changemin(int a,int b,D d){\n\t\ta+=N,b+=N;\n\t\twhile(a<b){\n\
    \t\t\tif(a&1){\n\t\t\t\tchmin(val[a],d);\n\t\t\t\ta++;\n\t\t\t}\n\t\t\tif(b&1){\n\
    \t\t\t\t--b;\n\t\t\t\tchmin(val[b],d);\n\t\t\t}\n\t\t\ta/=2,b/=2;\n\t\t}\n\t}\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: data structure/segtree/specialized/segtree_setmin.cpp
  requiredBy: []
  timestamp: '2018-03-30 16:44:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/segtree/specialized/segtree_setmin.cpp
layout: document
redirect_from:
- /library/data structure/segtree/specialized/segtree_setmin.cpp
- /library/data structure/segtree/specialized/segtree_setmin.cpp.html
title: data structure/segtree/specialized/segtree_setmin.cpp
---
