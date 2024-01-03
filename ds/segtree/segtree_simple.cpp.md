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
  bundledCode: "#line 1 \"ds/segtree/segtree_simple.cpp\"\ntemplate<class D>\r\nstruct\
    \ segtree{\r\n\tint N;\r\n\tvector<D> val;\r\n\r\n\tsegtree(){}\r\n\tsegtree(int\
    \ n){\r\n\t\tN=1;\r\n\t\twhile(N<n) N*=2;\r\n\t\tval.assign(N*2,D());\r\n\t}\r\
    \n\tsegtree(const vector<D>& ds){\r\n\t\tint n = ds.size();\r\n\t\tN=1;\r\n\t\t\
    while(N<n) N*=2;\r\n\t\tval.assign(N*2,D());\r\n\t\trep(i,n) val[i+N] = ds[i];\r\
    \n\t\tfor(int i=N-1;i>0;i--) val[i] = op(val[i*2],val[i*2+1]);\r\n\t}\r\n\tvoid\
    \ assign(int k,D d){\r\n\t\tk+=N;\r\n\t\tval[k]=d;\r\n\t\tk/=2;\r\n\t\twhile(k){\r\
    \n\t\t\tval[k] = op(val[k*2],val[k*2+1]);\r\n\t\t\tk/=2;\r\n\t\t}\r\n\t}\r\n\t\
    D query(int a,int b){\t\t//non-commutative & unrecursive\r\n\t\tD L = D() , R\
    \ = D();\r\n\t\ta+=N,b+=N;\r\n\t\twhile(a<b){\r\n\t\t\tif(a&1) L = op(L,val[a++]);\r\
    \n\t\t\tif(b&1) R = op(val[--b],R);\r\n\t\t\ta/=2,b/=2;\r\n\t\t}\r\n\t\treturn\
    \ op(L,R);\r\n\t}\r\n};\r\n\r\n/*\r\n\t\u66F8\u304F\u3082\u306E:\r\n\t\t\u578B\
    \u306E\u5B9A\u7FA9\r\n\t\t\u6F14\u7B97 op\r\n\t\t\u5358\u4F4D\u5143 e()\r\n*/\r\
    \nstruct D{\r\n\tint s;\r\n\tD(){ *this = e(); }\r\n\tD(int s_):s(s_){}\r\n\t\
    static D op(const D& x,const D& y){\r\n\t\tD z;\r\n\t\tz.s = x.s + y.s;\r\n\t\
    }\r\n\tconst static D e(){\r\n\t\treturn D(0);\r\n\t}\r\n//\tfriend ostream& operator<<(ostream&\
    \ o,const D& d){return o<<d.s;}\r\n};\r\n"
  code: "template<class D>\r\nstruct segtree{\r\n\tint N;\r\n\tvector<D> val;\r\n\r\
    \n\tsegtree(){}\r\n\tsegtree(int n){\r\n\t\tN=1;\r\n\t\twhile(N<n) N*=2;\r\n\t\
    \tval.assign(N*2,D());\r\n\t}\r\n\tsegtree(const vector<D>& ds){\r\n\t\tint n\
    \ = ds.size();\r\n\t\tN=1;\r\n\t\twhile(N<n) N*=2;\r\n\t\tval.assign(N*2,D());\r\
    \n\t\trep(i,n) val[i+N] = ds[i];\r\n\t\tfor(int i=N-1;i>0;i--) val[i] = op(val[i*2],val[i*2+1]);\r\
    \n\t}\r\n\tvoid assign(int k,D d){\r\n\t\tk+=N;\r\n\t\tval[k]=d;\r\n\t\tk/=2;\r\
    \n\t\twhile(k){\r\n\t\t\tval[k] = op(val[k*2],val[k*2+1]);\r\n\t\t\tk/=2;\r\n\t\
    \t}\r\n\t}\r\n\tD query(int a,int b){\t\t//non-commutative & unrecursive\r\n\t\
    \tD L = D() , R = D();\r\n\t\ta+=N,b+=N;\r\n\t\twhile(a<b){\r\n\t\t\tif(a&1) L\
    \ = op(L,val[a++]);\r\n\t\t\tif(b&1) R = op(val[--b],R);\r\n\t\t\ta/=2,b/=2;\r\
    \n\t\t}\r\n\t\treturn op(L,R);\r\n\t}\r\n};\r\n\r\n/*\r\n\t\u66F8\u304F\u3082\u306E\
    :\r\n\t\t\u578B\u306E\u5B9A\u7FA9\r\n\t\t\u6F14\u7B97 op\r\n\t\t\u5358\u4F4D\u5143\
    \ e()\r\n*/\r\nstruct D{\r\n\tint s;\r\n\tD(){ *this = e(); }\r\n\tD(int s_):s(s_){}\r\
    \n\tstatic D op(const D& x,const D& y){\r\n\t\tD z;\r\n\t\tz.s = x.s + y.s;\r\n\
    \t}\r\n\tconst static D e(){\r\n\t\treturn D(0);\r\n\t}\r\n//\tfriend ostream&\
    \ operator<<(ostream& o,const D& d){return o<<d.s;}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/segtree_simple.cpp
  requiredBy: []
  timestamp: '2024-01-03 19:12:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/segtree_simple.cpp
layout: document
redirect_from:
- /library/ds/segtree/segtree_simple.cpp
- /library/ds/segtree/segtree_simple.cpp.html
title: ds/segtree/segtree_simple.cpp
---
