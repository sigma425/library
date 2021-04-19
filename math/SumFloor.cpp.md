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
  bundledCode: "#line 1 \"math/SumFloor.cpp\"\n/*\n\treturn sum_{k=0~n-1} [ak/b]\n\
    \n\ta>=0,b>0,n>=0\n\tO(log(max(a,b)))\n\t\u8A08\u7B97\u9014\u4E2D\u3067max(a,b,n)^2\
    \ \u304F\u3089\u3044\u306E\u5927\u304D\u3055\u306B\u306F\u306A\u308B\u306E\u3067\
    \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u306B\u6CE8\u610F\n\n\tverified at\
    \ opencup/7836/F.cpp\n*/\ntemplate<class D>\nD sumFloor(D a,D b,D n){\n\tassert(b!=0);\n\
    \tif(a==0 || n==0) return 0;\n\tD g = gcd(a,b);\n\ta/=g, b/=g;\n\n\tD res = 0;\n\
    \twhile(a!=0 && n!=0){\n\t\tif(a>=b){\n\t\t\tres += a/b * n*(n-1)/2;\n\t\t\ta\
    \ %= b;\n\t\t\tif(a==0) break;\n\t\t}\n\t\tif(n>=b){\n\t\t\tres += (n/b)*(n/b-1)/2*a*b\
    \ + (a-1)*(b-1)/2*(n/b) + (n/b)*a*(n%b);\n\t\t\tn %= b;\n\t\t\tif(n==0) break;\n\
    \t\t}\n\t\tres += (b-1)*(a-1)/2 - (b-n)*(a*(n-1)/b);\n\t\tn = a-a*(n-1)/b;\n\t\
    \tswap(a,b);\n\t\tres = -res;\n\t}\n\tres = abs(res);\n\treturn res;\n}\n"
  code: "/*\n\treturn sum_{k=0~n-1} [ak/b]\n\n\ta>=0,b>0,n>=0\n\tO(log(max(a,b)))\n\
    \t\u8A08\u7B97\u9014\u4E2D\u3067max(a,b,n)^2 \u304F\u3089\u3044\u306E\u5927\u304D\
    \u3055\u306B\u306F\u306A\u308B\u306E\u3067\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\
    \u30FC\u306B\u6CE8\u610F\n\n\tverified at opencup/7836/F.cpp\n*/\ntemplate<class\
    \ D>\nD sumFloor(D a,D b,D n){\n\tassert(b!=0);\n\tif(a==0 || n==0) return 0;\n\
    \tD g = gcd(a,b);\n\ta/=g, b/=g;\n\n\tD res = 0;\n\twhile(a!=0 && n!=0){\n\t\t\
    if(a>=b){\n\t\t\tres += a/b * n*(n-1)/2;\n\t\t\ta %= b;\n\t\t\tif(a==0) break;\n\
    \t\t}\n\t\tif(n>=b){\n\t\t\tres += (n/b)*(n/b-1)/2*a*b + (a-1)*(b-1)/2*(n/b) +\
    \ (n/b)*a*(n%b);\n\t\t\tn %= b;\n\t\t\tif(n==0) break;\n\t\t}\n\t\tres += (b-1)*(a-1)/2\
    \ - (b-n)*(a*(n-1)/b);\n\t\tn = a-a*(n-1)/b;\n\t\tswap(a,b);\n\t\tres = -res;\n\
    \t}\n\tres = abs(res);\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/SumFloor.cpp
  requiredBy: []
  timestamp: '2018-09-18 03:14:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/SumFloor.cpp
layout: document
redirect_from:
- /library/math/SumFloor.cpp
- /library/math/SumFloor.cpp.html
title: math/SumFloor.cpp
---
