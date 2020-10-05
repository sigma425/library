---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"bsr.cpp\"\n/*\nx       0  1  2  3  4  5  6  7  8  9\nbsr(x)\
    \ -1  0  1  1  2  2  2  2  3  3\n\u6700\u4E0A\u4F4Dbit\n*/\nint bsr(uint x){\n\
    \tif(x==0) return -1;\n\treturn 31 ^ __builtin_clz(x);\n}\nint bsr(unsigned long\
    \ long x){\n\tif(x==0) return -1;\n\treturn 63 ^ __builtin_clzll(x);\n}\n\n/*\n\
    x       0  1  2  3  4  5  6  7  8  9\nbsl(x) -1  0  1  0  2  0  1  0  3  0\n\u6700\
    \u4E0B\u4F4Dbit\n*/\nint bsl(uint x){\n\tif(x==0) return -1;\n\treturn __builtin_ctz(x);\n\
    }\nint bsl(unsigned long long x){\n\tif(x==0) return -1;\n\treturn __builtin_ctzll(x);\n\
    }\n\n"
  code: "/*\nx       0  1  2  3  4  5  6  7  8  9\nbsr(x) -1  0  1  1  2  2  2  2\
    \  3  3\n\u6700\u4E0A\u4F4Dbit\n*/\nint bsr(uint x){\n\tif(x==0) return -1;\n\t\
    return 31 ^ __builtin_clz(x);\n}\nint bsr(unsigned long long x){\n\tif(x==0) return\
    \ -1;\n\treturn 63 ^ __builtin_clzll(x);\n}\n\n/*\nx       0  1  2  3  4  5  6\
    \  7  8  9\nbsl(x) -1  0  1  0  2  0  1  0  3  0\n\u6700\u4E0B\u4F4Dbit\n*/\n\
    int bsl(uint x){\n\tif(x==0) return -1;\n\treturn __builtin_ctz(x);\n}\nint bsl(unsigned\
    \ long long x){\n\tif(x==0) return -1;\n\treturn __builtin_ctzll(x);\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: bsr.cpp
  requiredBy: []
  timestamp: '2017-10-19 00:06:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bsr.cpp
layout: document
redirect_from:
- /library/bsr.cpp
- /library/bsr.cpp.html
title: bsr.cpp
---
