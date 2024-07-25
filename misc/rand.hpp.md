---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/rand.hpp\"\n\n/*\n\txorshift64\n\t\u6C7A\u5B9A\u7684\
    \u306B\u3057\u305F\u3051\u308C\u3070 x \u306E\u521D\u671F\u5024\u3092\u9069\u5F53\
    \u306B\u56FA\u5B9A\n*/\n#include <chrono>\n#include <climits>\nusing ull = unsigned\
    \ long long;\null xorshift() {\n\tstatic ull x = ull(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n\tx ^= x<<7;\n\treturn x ^= x>>9;\n}\n\n// [0,n)\n\
    ull rng(ull n){\n\treturn xorshift()%n;\n}\n// [l,r] \u9589\u533A\u9593\uFF01\uFF01\
    \null rng(ull l, ull r){\n\treturn l + xorshift() % (r-l+1);\n}\n\n// \u78BA\u7387\
    p\u3067true\ndouble gen_bool(double p){\n\tif(p <= 0) return false;\n\tif(p >=\
    \ 1) return true;\n\treturn xorshift() < ULLONG_MAX * p;\n}\n"
  code: "#pragma once\n\n/*\n\txorshift64\n\t\u6C7A\u5B9A\u7684\u306B\u3057\u305F\u3051\
    \u308C\u3070 x \u306E\u521D\u671F\u5024\u3092\u9069\u5F53\u306B\u56FA\u5B9A\n\
    */\n#include <chrono>\n#include <climits>\nusing ull = unsigned long long;\null\
    \ xorshift() {\n\tstatic ull x = ull(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n\tx ^= x<<7;\n\treturn x ^= x>>9;\n}\n\n// [0,n)\n\
    ull rng(ull n){\n\treturn xorshift()%n;\n}\n// [l,r] \u9589\u533A\u9593\uFF01\uFF01\
    \null rng(ull l, ull r){\n\treturn l + xorshift() % (r-l+1);\n}\n\n// \u78BA\u7387\
    p\u3067true\ndouble gen_bool(double p){\n\tif(p <= 0) return false;\n\tif(p >=\
    \ 1) return true;\n\treturn xorshift() < ULLONG_MAX * p;\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/rand.hpp
  requiredBy: []
  timestamp: '2024-07-25 10:58:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/rand.hpp
layout: document
redirect_from:
- /library/misc/rand.hpp
- /library/misc/rand.hpp.html
title: misc/rand.hpp
---
