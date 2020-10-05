---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://codeforces.com/problemset/problem/662/C
  bundledCode: "#line 1 \"math/hadamard.cpp\"\n/*\n\txor convolution\n\trep(i,N) rep(j,N)\
    \ h[i^j] += f[i]*g[j]\n\trep(i,N) rep(j,N) h[i] += f[i^j]*g[j]\t<-\t\u3053\u308C\
    \u4E00\u7DD2\u3060\u3051\u3069\u308F\u304B\u308A\u306B\u304F\u3044\n\n\thadamard\u5909\
    \u63DB\u306B\u5BFE\u5FDC\u3057\u3066\u3044\u308B\n\txor\u306A\u306E\u3067\u9006\
    \u5143\u306F\u81EA\u5206\u81EA\u8EAB\u3001\u306A\u306E\u3067\u9006\u5909\u63DB\
    \u3082\u305F\u3060\u306Etransform, \u305F\u3060\u3057det\u5206\u306EN\u3067\u5272\
    \u308B.\n\n\tverified: http://codeforces.com/problemset/problem/662/C\n*/\n\n\
    using D = ll;\nvoid transform(vector<D> &a, int l, int n) {\n\tif (n == 1) return;\n\
    \tint m = l + n / 2;\n\ttransform(a, l, n / 2);\n\ttransform(a, m, n / 2);\n\t\
    for (int i = 0; i < n / 2; i++) {\n\t\tD x = a[l + i], y = a[m + i];\n\t\ta[l\
    \ + i] = x + y;\n\t\ta[m + i] = x - y;\n\t}\n}\n\nvoid transform(vector<D> &a)\
    \ {\t//size must be power of 2\n\ttransform(a, 0, a.size());\n}\nvector<D> conv(vector<D>\
    \ a,vector<D> b){\n\tassert(a.size()==b.size());\n\tint N = a.size();\n\ttransform(a);\n\
    \ttransform(b);\n\tvector<D> c(N);\n\trep(i,N) c[i] = a[i]*b[i];\n\ttransform(c);\n\
    \trep(i,N) c[i]/=N;\n\treturn c;\n}\n"
  code: "/*\n\txor convolution\n\trep(i,N) rep(j,N) h[i^j] += f[i]*g[j]\n\trep(i,N)\
    \ rep(j,N) h[i] += f[i^j]*g[j]\t<-\t\u3053\u308C\u4E00\u7DD2\u3060\u3051\u3069\
    \u308F\u304B\u308A\u306B\u304F\u3044\n\n\thadamard\u5909\u63DB\u306B\u5BFE\u5FDC\
    \u3057\u3066\u3044\u308B\n\txor\u306A\u306E\u3067\u9006\u5143\u306F\u81EA\u5206\
    \u81EA\u8EAB\u3001\u306A\u306E\u3067\u9006\u5909\u63DB\u3082\u305F\u3060\u306E\
    transform, \u305F\u3060\u3057det\u5206\u306EN\u3067\u5272\u308B.\n\n\tverified:\
    \ http://codeforces.com/problemset/problem/662/C\n*/\n\nusing D = ll;\nvoid transform(vector<D>\
    \ &a, int l, int n) {\n\tif (n == 1) return;\n\tint m = l + n / 2;\n\ttransform(a,\
    \ l, n / 2);\n\ttransform(a, m, n / 2);\n\tfor (int i = 0; i < n / 2; i++) {\n\
    \t\tD x = a[l + i], y = a[m + i];\n\t\ta[l + i] = x + y;\n\t\ta[m + i] = x - y;\n\
    \t}\n}\n\nvoid transform(vector<D> &a) {\t//size must be power of 2\n\ttransform(a,\
    \ 0, a.size());\n}\nvector<D> conv(vector<D> a,vector<D> b){\n\tassert(a.size()==b.size());\n\
    \tint N = a.size();\n\ttransform(a);\n\ttransform(b);\n\tvector<D> c(N);\n\trep(i,N)\
    \ c[i] = a[i]*b[i];\n\ttransform(c);\n\trep(i,N) c[i]/=N;\n\treturn c;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/hadamard.cpp
  requiredBy: []
  timestamp: '2018-09-18 03:14:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/hadamard.cpp
layout: document
redirect_from:
- /library/math/hadamard.cpp
- /library/math/hadamard.cpp.html
title: math/hadamard.cpp
---
