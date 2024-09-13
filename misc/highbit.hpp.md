---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: ds/bitset.hpp
    title: ds/bitset.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/highbit.hpp\"\n/*\n\tx       0  1  2  3  4  5  6  7\
    \  8  9\n\tmsb(x) -1  0  1  1  2  2  2  2  3  3\n\t\u6700\u4E0A\u4F4Dbit\n*/\n\
    int highbit(int x){\n\treturn 31 - countl_zero<uint>(x);\n}\nint highbit(uint\
    \ x){\n\treturn 31 - countl_zero<uint>(x);\n}\nint highbit(ll x){\n\treturn 63\
    \ - countl_zero<ull>(x);\n}\nint highbit(ull x){\n\treturn 63 - countl_zero<ull>(x);\n\
    }\n\n/*\n\tx       0  1  2  3  4  5  6  7  8  9\n\tlsb(x) 32  0  1  0  2  0  1\
    \  0  3  0\n\t\u6700\u4E0B\u4F4Dbit\n*/\nint lowbit(int x){\n\treturn countr_zero<uint>(x);\n\
    }\nint lowbit(uint x){\n\treturn countr_zero<uint>(x);\n}\nint lowbit(ll x){\n\
    \treturn countr_zero<ull>(x);\n}\nint lowbit(ull x){\n\treturn countr_zero<ull>(x);\n\
    }\n"
  code: "/*\n\tx       0  1  2  3  4  5  6  7  8  9\n\tmsb(x) -1  0  1  1  2  2  2\
    \  2  3  3\n\t\u6700\u4E0A\u4F4Dbit\n*/\nint highbit(int x){\n\treturn 31 - countl_zero<uint>(x);\n\
    }\nint highbit(uint x){\n\treturn 31 - countl_zero<uint>(x);\n}\nint highbit(ll\
    \ x){\n\treturn 63 - countl_zero<ull>(x);\n}\nint highbit(ull x){\n\treturn 63\
    \ - countl_zero<ull>(x);\n}\n\n/*\n\tx       0  1  2  3  4  5  6  7  8  9\n\t\
    lsb(x) 32  0  1  0  2  0  1  0  3  0\n\t\u6700\u4E0B\u4F4Dbit\n*/\nint lowbit(int\
    \ x){\n\treturn countr_zero<uint>(x);\n}\nint lowbit(uint x){\n\treturn countr_zero<uint>(x);\n\
    }\nint lowbit(ll x){\n\treturn countr_zero<ull>(x);\n}\nint lowbit(ull x){\n\t\
    return countr_zero<ull>(x);\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/highbit.hpp
  requiredBy:
  - ds/bitset.hpp
  timestamp: '2024-09-05 20:28:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/highbit.hpp
layout: document
redirect_from:
- /library/misc/highbit.hpp
- /library/misc/highbit.hpp.html
title: misc/highbit.hpp
---
