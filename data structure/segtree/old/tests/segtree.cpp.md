---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"data structure/segtree/old/tests/segtree.cpp\"\n/*\n\tpoint\
    \ assign, range \u306A\u3093\u3089\u304B(operator +)\n*/\n#include <bits/stdc++.h>\n\
    #define rep(i,n) for(int i=0;i<n;i++)\n#define fs first\n#define sc second\nusing\
    \ namespace std;\n/*\n\tpoint assign,range \u307B\u3052\n\t\u66F8\u304F\u3082\u306E\
    \u306F\n\tD op()\t(\u6F14\u7B97)\n\tD e\t\t(\u5358\u4F4D\u5143)\n*/\ntypedef pair<int,int>\
    \ D;\nstruct segtree{\n\tstatic const int N=1<<16;\n\tD seg[N*2],e=;\n\tsegtree(vector<D>&\
    \ vc){\n\t\trep(i,N) seg[i+N]=e;\n\t\trep(i,vc.size()) seg[i+N]=vc[i];\n\t\tfor(int\
    \ i=N-1;i>0;i--) seg[i]=op(seg[i*2],seg[i*2+1]);\n\t}\n\tD op(const D& x,const\
    \ D& y){\n\n\t}\n\tvoid update(int k,D val){\n\t\tk+=N;\n\t\tseg[k]=val;\n\t\t\
    k/=2;\n\t\twhile(k){\n\t\t\tseg[k]=op(seg[k*2],seg[k*2+1]);\n\t\t\tk/=2;\n\t\t\
    }\n\t}\n\tP calc(int a,int b,int l=0,int r=N,int k=1){\n\t\tif(b<=l||r<=a) return\
    \ e;\n\t\tif(a<=l&&r<=b) return seg[k];\n\t\treturn op(calc(a,b,l,(l+r)/2,k*2),calc(a,b,(l+r)/2,r,k*2+1));\n\
    \t}\n};\nint main(){\n\t\n}\n"
  code: "/*\n\tpoint assign, range \u306A\u3093\u3089\u304B(operator +)\n*/\n#include\
    \ <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<n;i++)\n#define fs first\n#define\
    \ sc second\nusing namespace std;\n/*\n\tpoint assign,range \u307B\u3052\n\t\u66F8\
    \u304F\u3082\u306E\u306F\n\tD op()\t(\u6F14\u7B97)\n\tD e\t\t(\u5358\u4F4D\u5143\
    )\n*/\ntypedef pair<int,int> D;\nstruct segtree{\n\tstatic const int N=1<<16;\n\
    \tD seg[N*2],e=;\n\tsegtree(vector<D>& vc){\n\t\trep(i,N) seg[i+N]=e;\n\t\trep(i,vc.size())\
    \ seg[i+N]=vc[i];\n\t\tfor(int i=N-1;i>0;i--) seg[i]=op(seg[i*2],seg[i*2+1]);\n\
    \t}\n\tD op(const D& x,const D& y){\n\n\t}\n\tvoid update(int k,D val){\n\t\t\
    k+=N;\n\t\tseg[k]=val;\n\t\tk/=2;\n\t\twhile(k){\n\t\t\tseg[k]=op(seg[k*2],seg[k*2+1]);\n\
    \t\t\tk/=2;\n\t\t}\n\t}\n\tP calc(int a,int b,int l=0,int r=N,int k=1){\n\t\t\
    if(b<=l||r<=a) return e;\n\t\tif(a<=l&&r<=b) return seg[k];\n\t\treturn op(calc(a,b,l,(l+r)/2,k*2),calc(a,b,(l+r)/2,r,k*2+1));\n\
    \t}\n};\nint main(){\n\t\n}"
  dependsOn: []
  isVerificationFile: false
  path: data structure/segtree/old/tests/segtree.cpp
  requiredBy: []
  timestamp: '2017-04-22 20:47:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/segtree/old/tests/segtree.cpp
layout: document
redirect_from:
- /library/data structure/segtree/old/tests/segtree.cpp
- /library/data structure/segtree/old/tests/segtree.cpp.html
title: data structure/segtree/old/tests/segtree.cpp
---
