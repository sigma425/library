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
  bundledCode: "#line 1 \"math/divisor_zeta.cpp\"\n/*\n\t\u7D04\u6570\u5305\u9664\
    \ / \u500D\u6570\u5305\u9664\n\tO(NloglogN)\n\t[0] \u306B\u306F\u4E00\u5207\u89E6\
    \u3089\u306A\u3044\n*/\n\n// b[6] = a[1] + a[2] + a[3] + a[6]\ntemplate <class\
    \ T> void div_zeta(vector<T>& a){\n\tint N = si(a);\n\tvector<bool> sieve(N,true);\n\
    \tfor(int p=2;p<N;p++) if(sieve[p]){\n\t\tfor(int k=1;k*p<N;k++){\n\t\t\tsieve[k*p]\
    \ = false;\n\t\t\ta[k*p] += a[k];\n\t\t}\n\t}\n}\n// inversion of div_zeta\n//\
    \ a[6] = b[6] - b[3] - b[2] + b[1]\ntemplate <class T> void div_mobius(vector<T>&\
    \ b){\n\tint N = si(b);\n\tvector<bool> sieve(N,true);\n\tfor(int p=2;p<N;p++)\
    \ if(sieve[p]){\n\t\tfor(int k=(N-1)/p;k>0;k--){\n\t\t\tsieve[k*p] = false;\n\t\
    \t\tb[k*p] -= b[k];\n\t\t}\n\t}\n}\n\n// b[6] = a[6] + a[12] + a[18] + ...\ntemplate\
    \ <class T> void mult_zeta(vector<T>& a){\n\tint N = si(a);\n\tvector<bool> sieve(N,true);\n\
    \tfor(int p=2;p<N;p++) if(sieve[p]){\n\t\tfor(int k=(N-1)/p;k>0;k--){\n\t\t\t\
    sieve[k*p] = false;\n\t\t\ta[k] += a[k*p];\n\t\t}\n\t}\n}\n\n// inversion of mult_zeta\n\
    // a[6] = b[6] - b[6*p] + b[6*p*q] - ...\ntemplate <class T> void mult_mobius(vector<T>&\
    \ b){\n\tint N = si(b);\n\tvector<bool> sieve(N,true);\n\tfor(int p=2;p<N;p++)\
    \ if(sieve[p]){\n\t\tfor(int k=1;k*p<N;k++){\n\t\t\tsieve[k*p] = false;\n\t\t\t\
    b[k] -= b[k*p];\n\t\t}\n\t}\n}\n"
  code: "/*\n\t\u7D04\u6570\u5305\u9664 / \u500D\u6570\u5305\u9664\n\tO(NloglogN)\n\
    \t[0] \u306B\u306F\u4E00\u5207\u89E6\u3089\u306A\u3044\n*/\n\n// b[6] = a[1] +\
    \ a[2] + a[3] + a[6]\ntemplate <class T> void div_zeta(vector<T>& a){\n\tint N\
    \ = si(a);\n\tvector<bool> sieve(N,true);\n\tfor(int p=2;p<N;p++) if(sieve[p]){\n\
    \t\tfor(int k=1;k*p<N;k++){\n\t\t\tsieve[k*p] = false;\n\t\t\ta[k*p] += a[k];\n\
    \t\t}\n\t}\n}\n// inversion of div_zeta\n// a[6] = b[6] - b[3] - b[2] + b[1]\n\
    template <class T> void div_mobius(vector<T>& b){\n\tint N = si(b);\n\tvector<bool>\
    \ sieve(N,true);\n\tfor(int p=2;p<N;p++) if(sieve[p]){\n\t\tfor(int k=(N-1)/p;k>0;k--){\n\
    \t\t\tsieve[k*p] = false;\n\t\t\tb[k*p] -= b[k];\n\t\t}\n\t}\n}\n\n// b[6] = a[6]\
    \ + a[12] + a[18] + ...\ntemplate <class T> void mult_zeta(vector<T>& a){\n\t\
    int N = si(a);\n\tvector<bool> sieve(N,true);\n\tfor(int p=2;p<N;p++) if(sieve[p]){\n\
    \t\tfor(int k=(N-1)/p;k>0;k--){\n\t\t\tsieve[k*p] = false;\n\t\t\ta[k] += a[k*p];\n\
    \t\t}\n\t}\n}\n\n// inversion of mult_zeta\n// a[6] = b[6] - b[6*p] + b[6*p*q]\
    \ - ...\ntemplate <class T> void mult_mobius(vector<T>& b){\n\tint N = si(b);\n\
    \tvector<bool> sieve(N,true);\n\tfor(int p=2;p<N;p++) if(sieve[p]){\n\t\tfor(int\
    \ k=1;k*p<N;k++){\n\t\t\tsieve[k*p] = false;\n\t\t\tb[k] -= b[k*p];\n\t\t}\n\t\
    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/divisor_zeta.cpp
  requiredBy: []
  timestamp: '2023-11-14 00:07:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisor_zeta.cpp
layout: document
redirect_from:
- /library/math/divisor_zeta.cpp
- /library/math/divisor_zeta.cpp.html
title: math/divisor_zeta.cpp
---
