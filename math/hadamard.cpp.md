---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_oj/xorconv.test.cpp
    title: test_oj/xorconv.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/hadamard.cpp\"\ntemplate<class T>\nvoid hadamard(V<T>&\
    \ a, bool inv = false){\n\tint n = si(a);\n\tassert(__builtin_popcount(n) == 1);\n\
    \tfor(int i=1;i<n;i<<=1){\n\t\tfor(int j=0;j<n;j+=i<<1){\n\t\t\trep(k,i){\n\t\t\
    \t\tT s = a[j+k], t = a[j+k+i];\n\t\t\t\ta[j+k] = s+t;\n\t\t\t\ta[j+k+i] = s-t;\n\
    \t\t\t}\n\t\t}\n\t}\n\tif(inv){\n\t\tT in = T(1)/n;\n\t\tfor(auto& x: a) x *=\
    \ in;\n\t}\n}\n"
  code: "template<class T>\nvoid hadamard(V<T>& a, bool inv = false){\n\tint n = si(a);\n\
    \tassert(__builtin_popcount(n) == 1);\n\tfor(int i=1;i<n;i<<=1){\n\t\tfor(int\
    \ j=0;j<n;j+=i<<1){\n\t\t\trep(k,i){\n\t\t\t\tT s = a[j+k], t = a[j+k+i];\n\t\t\
    \t\ta[j+k] = s+t;\n\t\t\t\ta[j+k+i] = s-t;\n\t\t\t}\n\t\t}\n\t}\n\tif(inv){\n\t\
    \tT in = T(1)/n;\n\t\tfor(auto& x: a) x *= in;\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/hadamard.cpp
  requiredBy: []
  timestamp: '2021-08-11 04:07:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_oj/xorconv.test.cpp
documentation_of: math/hadamard.cpp
layout: document
redirect_from:
- /library/math/hadamard.cpp
- /library/math/hadamard.cpp.html
title: math/hadamard.cpp
---
