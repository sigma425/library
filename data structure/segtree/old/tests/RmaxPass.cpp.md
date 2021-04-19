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
  bundledCode: "#line 1 \"data structure/segtree/old/tests/RmaxPass.cpp\"\n#include\
    \ <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)n;i++)\nusing namespace\
    \ std;\n/*\nrange max, point assign\n*/\nint inf=1e9;\nstruct segtree{\n\tstatic\
    \ const int N=1<<16;\n\tint seg[N*2];\n\tsegtree(){\n\t\trep(i,N*2) seg[i]=-inf;\n\
    \t}\n\tsegtree(vector<int>& vi){\n\t\trep(i,N*2) seg[i]=-inf;\n\t\trep(i,vi.size())\
    \ seg[N+i]=vi[i];\n\t\tfor(int i=N-1;i>0;i--) seg[i]=max(seg[i*2],seg[i*2+1]);\n\
    \t}\n\n\tvoid update(int x,int v){\n\t\tx+=N;\n\t\tseg[x]=v;\n\t\tx/=2;\n\t\t\
    while(x){\n\t\t\tseg[x]=max(seg[x*2],seg[x*2+1]);\n\t\t\tx/=2;\n\t\t}\n\t}\n\t\
    int getmax(int a,int b,int l=0,int r=N,int k=1){\n\t\tif(b<=l||r<=a) return -inf;\n\
    \t\tif(a<=l&&r<=b) return seg[k];\n\t\treturn max(getmax(a,b,l,(l+r)/2,k*2),getmax(a,b,(l+r)/2,r,k*2+1));\n\
    \t}\n};\nint main(){\n\n}\n"
  code: "#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)n;i++)\nusing\
    \ namespace std;\n/*\nrange max, point assign\n*/\nint inf=1e9;\nstruct segtree{\n\
    \tstatic const int N=1<<16;\n\tint seg[N*2];\n\tsegtree(){\n\t\trep(i,N*2) seg[i]=-inf;\n\
    \t}\n\tsegtree(vector<int>& vi){\n\t\trep(i,N*2) seg[i]=-inf;\n\t\trep(i,vi.size())\
    \ seg[N+i]=vi[i];\n\t\tfor(int i=N-1;i>0;i--) seg[i]=max(seg[i*2],seg[i*2+1]);\n\
    \t}\n\n\tvoid update(int x,int v){\n\t\tx+=N;\n\t\tseg[x]=v;\n\t\tx/=2;\n\t\t\
    while(x){\n\t\t\tseg[x]=max(seg[x*2],seg[x*2+1]);\n\t\t\tx/=2;\n\t\t}\n\t}\n\t\
    int getmax(int a,int b,int l=0,int r=N,int k=1){\n\t\tif(b<=l||r<=a) return -inf;\n\
    \t\tif(a<=l&&r<=b) return seg[k];\n\t\treturn max(getmax(a,b,l,(l+r)/2,k*2),getmax(a,b,(l+r)/2,r,k*2+1));\n\
    \t}\n};\nint main(){\n\n}"
  dependsOn: []
  isVerificationFile: false
  path: data structure/segtree/old/tests/RmaxPass.cpp
  requiredBy: []
  timestamp: '2017-04-22 20:47:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/segtree/old/tests/RmaxPass.cpp
layout: document
redirect_from:
- /library/data structure/segtree/old/tests/RmaxPass.cpp
- /library/data structure/segtree/old/tests/RmaxPass.cpp.html
title: data structure/segtree/old/tests/RmaxPass.cpp
---
