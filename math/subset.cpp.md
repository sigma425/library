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
  bundledCode: "#line 1 \"math/subset.cpp\"\n// size k\nint c=(1<<k)-1;\nwhile(c<1<<n){\n\
    \t// hoge\n\tint x=c&-c,y=c+x;\n\tc=(((c&~y)/x)>>1)|y;\n}\n\n//subset of b(descending)\n\
    int a=b;\ndo{\n\t//\n\ta=(a-1)&b;\n}while(a!=b);\n"
  code: "// size k\nint c=(1<<k)-1;\nwhile(c<1<<n){\n\t// hoge\n\tint x=c&-c,y=c+x;\n\
    \tc=(((c&~y)/x)>>1)|y;\n}\n\n//subset of b(descending)\nint a=b;\ndo{\n\t//\n\t\
    a=(a-1)&b;\n}while(a!=b);"
  dependsOn: []
  isVerificationFile: false
  path: math/subset.cpp
  requiredBy: []
  timestamp: '2018-09-18 03:14:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/subset.cpp
layout: document
redirect_from:
- /library/math/subset.cpp
- /library/math/subset.cpp.html
title: math/subset.cpp
---
