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
  bundledCode: "#line 1 \"data structure/segtree/old/unrecursive_range.cpp\"\nint\
    \ sum(int a,int b){\n\tint ret=0;\n\ta+=p2,b+=p2;\n\twhile(a<b){\n\t\tif(a&1)\
    \ ret+=seg[a++];\n\t\tif(b&1) ret+=seg[--b];\n\t\ta/=2,b/=2;\n\t}\n}\n"
  code: "int sum(int a,int b){\n\tint ret=0;\n\ta+=p2,b+=p2;\n\twhile(a<b){\n\t\t\
    if(a&1) ret+=seg[a++];\n\t\tif(b&1) ret+=seg[--b];\n\t\ta/=2,b/=2;\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: data structure/segtree/old/unrecursive_range.cpp
  requiredBy: []
  timestamp: '2017-04-22 20:47:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/segtree/old/unrecursive_range.cpp
layout: document
redirect_from:
- /library/data structure/segtree/old/unrecursive_range.cpp
- /library/data structure/segtree/old/unrecursive_range.cpp.html
title: data structure/segtree/old/unrecursive_range.cpp
---
