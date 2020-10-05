---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data structure/kth.cpp\"\nll sum(int a,int b,int l,int r,int\
    \ k){\n\tif(r<=a||b<=l) return 0;\n\tif(a<=l&&r<=b) return seg[k];\n\treturn sum(a,b,l,(l+r)/2,k*2+1,seg)+sum(a,b,(l+r)/2,r,k*2+2,seg);\n\
    }\nvoid add(int x,int v){\n\twhile(true){\n\t\tseg[x]+=v;\n\t\tif(x==0) break;\n\
    \t\tx=(x-1)/2;\n\t}\n}\nint kth(int l,int r,int id,int k){\n\tif(l+1==r) return\
    \ l;\n\tif(seg[2*id+1]>=k) return kth(l,(l+r)/2,id*2+1,k);\n\telse return kth((l+r)/2,r,id*2+2,k-seg[2*id+1]);\n\
    }\n"
  code: "ll sum(int a,int b,int l,int r,int k){\n\tif(r<=a||b<=l) return 0;\n\tif(a<=l&&r<=b)\
    \ return seg[k];\n\treturn sum(a,b,l,(l+r)/2,k*2+1,seg)+sum(a,b,(l+r)/2,r,k*2+2,seg);\n\
    }\nvoid add(int x,int v){\n\twhile(true){\n\t\tseg[x]+=v;\n\t\tif(x==0) break;\n\
    \t\tx=(x-1)/2;\n\t}\n}\nint kth(int l,int r,int id,int k){\n\tif(l+1==r) return\
    \ l;\n\tif(seg[2*id+1]>=k) return kth(l,(l+r)/2,id*2+1,k);\n\telse return kth((l+r)/2,r,id*2+2,k-seg[2*id+1]);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: data structure/kth.cpp
  requiredBy: []
  timestamp: '2016-12-08 00:51:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/kth.cpp
layout: document
redirect_from:
- /library/data structure/kth.cpp
- /library/data structure/kth.cpp.html
title: data structure/kth.cpp
---
