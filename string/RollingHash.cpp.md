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
  bundledCode: "#line 1 \"string/RollingHash.cpp\"\nusing m1 = ModInt<998244353>;\n\
    using m2 = ModInt<1000000007>;\n\nusing Hash2 = pair<m1,m2>;\nHash2 operator+(const\
    \ Hash2& a, const Hash2& b){\n\treturn {a.fs+b.fs,a.sc+b.sc};\n}\nHash2 operator-(const\
    \ Hash2& a, const Hash2& b){\n\treturn {a.fs-b.fs,a.sc-b.sc};\n}\nHash2 operator*(const\
    \ Hash2& a, const Hash2& b){\n\treturn {a.fs*b.fs,a.sc*b.sc};\n}\nconst Hash2\
    \ base = {31415,27182};\n// pow_base / ipow_base\n\nusing Hash = Hash2;\n"
  code: "using m1 = ModInt<998244353>;\nusing m2 = ModInt<1000000007>;\n\nusing Hash2\
    \ = pair<m1,m2>;\nHash2 operator+(const Hash2& a, const Hash2& b){\n\treturn {a.fs+b.fs,a.sc+b.sc};\n\
    }\nHash2 operator-(const Hash2& a, const Hash2& b){\n\treturn {a.fs-b.fs,a.sc-b.sc};\n\
    }\nHash2 operator*(const Hash2& a, const Hash2& b){\n\treturn {a.fs*b.fs,a.sc*b.sc};\n\
    }\nconst Hash2 base = {31415,27182};\n// pow_base / ipow_base\n\nusing Hash =\
    \ Hash2;"
  dependsOn: []
  isVerificationFile: false
  path: string/RollingHash.cpp
  requiredBy: []
  timestamp: '2021-12-26 19:29:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/RollingHash.cpp
layout: document
redirect_from:
- /library/string/RollingHash.cpp
- /library/string/RollingHash.cpp.html
title: string/RollingHash.cpp
---
