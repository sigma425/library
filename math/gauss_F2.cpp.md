---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1299/problem/D
  bundledCode: "#line 1 \"math/gauss_F2.cpp\"\n/*\n    F2 ^ D\u306E\u57FA\u5E95\u6301\
    \u3064 / \u66F4\u65B0\u3059\u308B\u3084\u3064\n    add \u304C O(D)\n    merge\
    \ \u306F add \u3092 D\u56DE\u3001 O(D^2)\n\n    given a \u306B\u5BFE\u3057\u3001\
    \ min(max){a^v | v \\in space} \u306F\u4E0A\u306E\u6841\u304B\u3089xor\u3059\u308B\
    \u304B\u3057\u306A\u3044\u304B\u8CAA\u6B32\u306B\u9078\u3079\u3070\u3044\u3044\
    \n\n    (normalize)\n        \u90E8\u5206\u7A7A\u9593\u3092\u72B6\u614B\u3068\u3057\
    \u3066\u6301\u3061\u305F\u3044\u3068\u304D\u306FB\u3092\u6B63\u898F\u5316\u3059\
    \u308B\u5FC5\u8981\u304C\u3042\u308B\n        \u4E0A\u306E\u6841\u304B\u3089\u898B\
    \u3066\u8F9E\u66F8\u9806\u6700\u5C0F\u306B\u3059\u308B\n        O(D^2)\n    \n\
    \    subspace \u306E\u6570\u306F {1, 2, 5, 16, 67, 374, 2825, 29212, 417199, 8283458}\n\
    \    \u305D\u3082\u305D\u3082\u500B\u6570\u304C\u5C11\u306A\u3044\u306E\u3067\
    N\u56DEdp\u3092\u66F4\u65B0\u3059\u308B\u4EE3\u308F\u308A\u306B\u540C\u3058subspace\u306B\
    \u306A\u308B\u3084\u3064\u306F\u307E\u3068\u3081\u3066\u3001\u3068\u304B\u3082\
    \u3042\u308A\u3046\u308B\n        https://codeforces.com/contest/1299/problem/D\n\
    \n    D <= 6 \u306A\u3089\u8CBC\u308B\u7A7A\u9593\u3092 2^D bit \u3067\u6301\u3063\
    \u305F\u65B9\u304C\u697D\u304B? \u8A08\u7B97\u91CF\u60AA\u304F\u306A\u308B\u304C\
    \n\n    \u3068\u306B\u304B\u304F\u72B6\u614B\u304C\u5C11\u306A\u304F\u3066\u8A08\
    \u7B97\u3059\u308B\u56DE\u6570\u304C\u591A\u3044\u306A\u3089\u3001\u306F\u3058\
    \u3081\u306B\u5168\u90E8\u751F\u6210\u3057\u3066\u304B\u3089\u6F14\u7B97\u8868\
    (merge,add)\u3092\u4F5C\u308A\u307E\u3057\u3087\u3046\n    1299/D.cpp \u53C2\u7167\
    \n*/\n\nconst int D = 64;\nV<ull> B(D);\n\nvoid add(ull x){\n    for(int i=D-1;i>=0;i--){\n\
    \        if(B[i] == 0 && x&1ULL<<i){ // add to base\n            B[i] = x;\n \
    \           return;\n        }else if(x&1ULL<<i){\n            x ^= B[i];\n  \
    \      }\n    }\n    // don't add to base\n    // (dependent)\n}\n\nvoid normalize(){\n\
    \    for(int i=D-1;i>=0;i--) if(B[i]){\n        for(int j=i-1;j>=0;j--) chmin(B[i],B[i]^B[j]);\n\
    \    }\n}\n"
  code: "/*\n    F2 ^ D\u306E\u57FA\u5E95\u6301\u3064 / \u66F4\u65B0\u3059\u308B\u3084\
    \u3064\n    add \u304C O(D)\n    merge \u306F add \u3092 D\u56DE\u3001 O(D^2)\n\
    \n    given a \u306B\u5BFE\u3057\u3001 min(max){a^v | v \\in space} \u306F\u4E0A\
    \u306E\u6841\u304B\u3089xor\u3059\u308B\u304B\u3057\u306A\u3044\u304B\u8CAA\u6B32\
    \u306B\u9078\u3079\u3070\u3044\u3044\n\n    (normalize)\n        \u90E8\u5206\u7A7A\
    \u9593\u3092\u72B6\u614B\u3068\u3057\u3066\u6301\u3061\u305F\u3044\u3068\u304D\
    \u306FB\u3092\u6B63\u898F\u5316\u3059\u308B\u5FC5\u8981\u304C\u3042\u308B\n  \
    \      \u4E0A\u306E\u6841\u304B\u3089\u898B\u3066\u8F9E\u66F8\u9806\u6700\u5C0F\
    \u306B\u3059\u308B\n        O(D^2)\n    \n    subspace \u306E\u6570\u306F {1,\
    \ 2, 5, 16, 67, 374, 2825, 29212, 417199, 8283458}\n    \u305D\u3082\u305D\u3082\
    \u500B\u6570\u304C\u5C11\u306A\u3044\u306E\u3067N\u56DEdp\u3092\u66F4\u65B0\u3059\
    \u308B\u4EE3\u308F\u308A\u306B\u540C\u3058subspace\u306B\u306A\u308B\u3084\u3064\
    \u306F\u307E\u3068\u3081\u3066\u3001\u3068\u304B\u3082\u3042\u308A\u3046\u308B\
    \n        https://codeforces.com/contest/1299/problem/D\n\n    D <= 6 \u306A\u3089\
    \u8CBC\u308B\u7A7A\u9593\u3092 2^D bit \u3067\u6301\u3063\u305F\u65B9\u304C\u697D\
    \u304B? \u8A08\u7B97\u91CF\u60AA\u304F\u306A\u308B\u304C\n\n    \u3068\u306B\u304B\
    \u304F\u72B6\u614B\u304C\u5C11\u306A\u304F\u3066\u8A08\u7B97\u3059\u308B\u56DE\
    \u6570\u304C\u591A\u3044\u306A\u3089\u3001\u306F\u3058\u3081\u306B\u5168\u90E8\
    \u751F\u6210\u3057\u3066\u304B\u3089\u6F14\u7B97\u8868(merge,add)\u3092\u4F5C\u308A\
    \u307E\u3057\u3087\u3046\n    1299/D.cpp \u53C2\u7167\n*/\n\nconst int D = 64;\n\
    V<ull> B(D);\n\nvoid add(ull x){\n    for(int i=D-1;i>=0;i--){\n        if(B[i]\
    \ == 0 && x&1ULL<<i){ // add to base\n            B[i] = x;\n            return;\n\
    \        }else if(x&1ULL<<i){\n            x ^= B[i];\n        }\n    }\n    //\
    \ don't add to base\n    // (dependent)\n}\n\nvoid normalize(){\n    for(int i=D-1;i>=0;i--)\
    \ if(B[i]){\n        for(int j=i-1;j>=0;j--) chmin(B[i],B[i]^B[j]);\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/gauss_F2.cpp
  requiredBy: []
  timestamp: '2020-05-02 14:53:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/gauss_F2.cpp
layout: document
redirect_from:
- /library/math/gauss_F2.cpp
- /library/math/gauss_F2.cpp.html
title: math/gauss_F2.cpp
---
