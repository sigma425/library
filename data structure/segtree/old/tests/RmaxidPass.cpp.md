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
  bundledCode: "#line 1 \"data structure/segtree/old/tests/RmaxidPass.cpp\"\n#include\
    \ <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<n;i++)\n#define fs first\n#define\
    \ sc second\nusing namespace std;\n/*\n\tRmaxPass\u3068\u4F3C\u3066\u308B\u304C\
    ,\u8FD4\u3059\u306E\u306FP(max,\u305D\u308C\u3092\u5B9F\u73FE\u3059\u308Bid\u306E\
    \u3046\u3061\u6700\u3082\u5DE6)\n\t(\u6700\u3082\u53F3,\u306E\u5834\u5408\u306F\
    operator\u306E\u5B9A\u7FA9\u3067x.sc>y.sc\u306B\u3059\u308B)\n*/\ntypedef pair<int,int>\
    \ P;\nP operator+(const P& x,const P& y){\n\tif(x.fs>y.fs||(x.fs==y.fs&&x.sc<y.sc))\
    \ return x;\n\telse return y;\n}\nint inf=1e9;\nstruct segtree{\n\tstatic const\
    \ int N=1<<16;\n\tP seg[N*2];\n\t\n\tvoid update(int k,int val){\n\t\tseg[k+N]=P(val,k);\n\
    \t\tk+=N;\n\t\tk/=2;\n\t\twhile(k){\n\t\t\tseg[k]=seg[k*2]+seg[k*2+1];\n\t\t\t\
    k/=2;\n\t\t}\n\t}\n\tvoid init(){\n\t\trep(i,N) seg[i+N]=P(-inf,i);\n\t\tfor(int\
    \ i=N-1;i>0;i--) seg[i]=seg[i*2]+seg[i*2+1];\n\t}\n\tP getmax(int a,int b,int\
    \ l=0,int r=N,int k=1){\n\t\tif(b<=l||r<=a) return P(-inf,-1);\n\t\tif(a<=l&&r<=b)\
    \ return seg[k];\n\t\treturn getmax(a,b,l,(l+r)/2,k*2)+getmax(a,b,(l+r)/2,r,k*2+1);\n\
    \t}\n};\nint main(){\n\t\n}\n"
  code: "#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<n;i++)\n#define\
    \ fs first\n#define sc second\nusing namespace std;\n/*\n\tRmaxPass\u3068\u4F3C\
    \u3066\u308B\u304C,\u8FD4\u3059\u306E\u306FP(max,\u305D\u308C\u3092\u5B9F\u73FE\
    \u3059\u308Bid\u306E\u3046\u3061\u6700\u3082\u5DE6)\n\t(\u6700\u3082\u53F3,\u306E\
    \u5834\u5408\u306Foperator\u306E\u5B9A\u7FA9\u3067x.sc>y.sc\u306B\u3059\u308B\
    )\n*/\ntypedef pair<int,int> P;\nP operator+(const P& x,const P& y){\n\tif(x.fs>y.fs||(x.fs==y.fs&&x.sc<y.sc))\
    \ return x;\n\telse return y;\n}\nint inf=1e9;\nstruct segtree{\n\tstatic const\
    \ int N=1<<16;\n\tP seg[N*2];\n\t\n\tvoid update(int k,int val){\n\t\tseg[k+N]=P(val,k);\n\
    \t\tk+=N;\n\t\tk/=2;\n\t\twhile(k){\n\t\t\tseg[k]=seg[k*2]+seg[k*2+1];\n\t\t\t\
    k/=2;\n\t\t}\n\t}\n\tvoid init(){\n\t\trep(i,N) seg[i+N]=P(-inf,i);\n\t\tfor(int\
    \ i=N-1;i>0;i--) seg[i]=seg[i*2]+seg[i*2+1];\n\t}\n\tP getmax(int a,int b,int\
    \ l=0,int r=N,int k=1){\n\t\tif(b<=l||r<=a) return P(-inf,-1);\n\t\tif(a<=l&&r<=b)\
    \ return seg[k];\n\t\treturn getmax(a,b,l,(l+r)/2,k*2)+getmax(a,b,(l+r)/2,r,k*2+1);\n\
    \t}\n};\nint main(){\n\t\n}"
  dependsOn: []
  isVerificationFile: false
  path: data structure/segtree/old/tests/RmaxidPass.cpp
  requiredBy: []
  timestamp: '2017-04-22 20:47:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/segtree/old/tests/RmaxidPass.cpp
layout: document
redirect_from:
- /library/data structure/segtree/old/tests/RmaxidPass.cpp
- /library/data structure/segtree/old/tests/RmaxidPass.cpp.html
title: data structure/segtree/old/tests/RmaxidPass.cpp
---
