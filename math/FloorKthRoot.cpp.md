---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_oj/FloorKthRoot.test.cpp
    title: test_oj/FloorKthRoot.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/FloorKthRoot.cpp\"\n// floor(a^(1/k))\n// by risjiroh,\
    \ hos\n\ntemplate <class T, class Op = multiplies<>>\nconstexpr T power(T a, uint64_t\
    \ n, T init = 1, Op op = Op{}) {\n\twhile (n) {\n\t\tif (n & 1) init = op(init,\
    \ a);\n\t\tif (n >>= 1) a = op(a, a);\n\t}\n\treturn init;\n}\nuint64_t floorKthRoot(uint64_t\
    \ a, uint64_t k) {\n\tassert(k);\n\tif (a == 0 or k == 1) return a;\n\tif (k >=\
    \ 64) return 1;\n\tif (k == 2) return sqrtl(a);\n\tstatic constexpr uint64_t inf\
    \ = -1;\n\tstatic auto mul = [](auto x, auto y) { return x <= inf / y ? x * y\
    \ : inf; };\n\ta -= a == inf;\n\tuint64_t ok = pow(a, (1 - 1e-15) / k), ng = pow(a,\
    \ (1 + 1e-15) / k) + 1;\n\twhile (ng - ok > 1) {\n\t\tauto mid = (ok + ng) / 2;\n\
    \t\t(power<uint64_t>(mid, k, 1, mul) <= a ? ok : ng) = mid;\n\t}\n\treturn ok;\n\
    }\n/*\nvoid unittest() {\n\t// k = 2\n\tfor (unsigned long long x = 0; x < 1000;\
    \ ++x) {\n\t\tfor (unsigned long long a = x * x; a < (x + 1) * (x + 1); ++a) {\n\
    \t\t\tassert(floorKthRoot(a, 2) == x);\n\t\t}\n\t}\n\tfor (unsigned long long\
    \ x = 4294967295ULL - 1000; x <= 4294967295ULL; ++x) {\n\t\tfor (unsigned long\
    \ long a = x * x - 1000; a < x * x; ++a) {\n\t\t\tassert(floorKthRoot(a, 2) ==\
    \ x - 1);\n\t\t}\n\t\tfor (unsigned long long a = x * x; a < x * x + 1000; ++a)\
    \ {\n\t\t\tassert(floorKthRoot(a, 2) == x);\n\t\t}\n\t}\n\tfor (unsigned long\
    \ long b = 1; b <= 1000; ++b) {\n\t\tassert(floorKthRoot(-b, 2) == 4294967295ULL);\n\
    \t}\n\n\t// general\n\tfor (unsigned long long x = 2; x < 1000; ++x) {\n\t\tunsigned\
    \ long long a = x;\n\t\tfor (int k = 1; ; ++k) {\n\t\t\tassert(floorKthRoot(a\
    \ - 1, k) == x - 1);\n\t\t\tassert(floorKthRoot(a, k) == x);\n\t\t\tif (a > ~0ULL\
    \ / x) break;\n\t\t\ta *= x;\n\t\t}\n\t}\n}\n*/\n"
  code: "// floor(a^(1/k))\n// by risjiroh, hos\n\ntemplate <class T, class Op = multiplies<>>\n\
    constexpr T power(T a, uint64_t n, T init = 1, Op op = Op{}) {\n\twhile (n) {\n\
    \t\tif (n & 1) init = op(init, a);\n\t\tif (n >>= 1) a = op(a, a);\n\t}\n\treturn\
    \ init;\n}\nuint64_t floorKthRoot(uint64_t a, uint64_t k) {\n\tassert(k);\n\t\
    if (a == 0 or k == 1) return a;\n\tif (k >= 64) return 1;\n\tif (k == 2) return\
    \ sqrtl(a);\n\tstatic constexpr uint64_t inf = -1;\n\tstatic auto mul = [](auto\
    \ x, auto y) { return x <= inf / y ? x * y : inf; };\n\ta -= a == inf;\n\tuint64_t\
    \ ok = pow(a, (1 - 1e-15) / k), ng = pow(a, (1 + 1e-15) / k) + 1;\n\twhile (ng\
    \ - ok > 1) {\n\t\tauto mid = (ok + ng) / 2;\n\t\t(power<uint64_t>(mid, k, 1,\
    \ mul) <= a ? ok : ng) = mid;\n\t}\n\treturn ok;\n}\n/*\nvoid unittest() {\n\t\
    // k = 2\n\tfor (unsigned long long x = 0; x < 1000; ++x) {\n\t\tfor (unsigned\
    \ long long a = x * x; a < (x + 1) * (x + 1); ++a) {\n\t\t\tassert(floorKthRoot(a,\
    \ 2) == x);\n\t\t}\n\t}\n\tfor (unsigned long long x = 4294967295ULL - 1000; x\
    \ <= 4294967295ULL; ++x) {\n\t\tfor (unsigned long long a = x * x - 1000; a <\
    \ x * x; ++a) {\n\t\t\tassert(floorKthRoot(a, 2) == x - 1);\n\t\t}\n\t\tfor (unsigned\
    \ long long a = x * x; a < x * x + 1000; ++a) {\n\t\t\tassert(floorKthRoot(a,\
    \ 2) == x);\n\t\t}\n\t}\n\tfor (unsigned long long b = 1; b <= 1000; ++b) {\n\t\
    \tassert(floorKthRoot(-b, 2) == 4294967295ULL);\n\t}\n\n\t// general\n\tfor (unsigned\
    \ long long x = 2; x < 1000; ++x) {\n\t\tunsigned long long a = x;\n\t\tfor (int\
    \ k = 1; ; ++k) {\n\t\t\tassert(floorKthRoot(a - 1, k) == x - 1);\n\t\t\tassert(floorKthRoot(a,\
    \ k) == x);\n\t\t\tif (a > ~0ULL / x) break;\n\t\t\ta *= x;\n\t\t}\n\t}\n}\n*/"
  dependsOn: []
  isVerificationFile: false
  path: math/FloorKthRoot.cpp
  requiredBy: []
  timestamp: '2020-09-20 08:07:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_oj/FloorKthRoot.test.cpp
documentation_of: math/FloorKthRoot.cpp
layout: document
redirect_from:
- /library/math/FloorKthRoot.cpp
- /library/math/FloorKthRoot.cpp.html
title: math/FloorKthRoot.cpp
---
