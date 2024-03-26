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
  bundledCode: "#line 1 \"math/getOrder.cpp\"\n/*\n\tx,p \u304C\u4E0E\u3048\u3089\u308C\
    \u3066\u3001x^r = 1 mod p \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\u6B63\u6574\
    \u6570 r \u3092\u8FD4\u3059\n\tp: fix \u3067 x \u304C\u5927\u91CF\u306B\u6765\u308B\
    \u30B1\u30FC\u30B9\u3092\u60F3\u5B9A\n\n\t\u524D\u8A08\u7B97: p-1 \u306E\u7D20\
    \u56E0\u6570 q_i \u3092\u5217\u6319\n\t\u30AF\u30A8\u30EA:\n\t\tx^(p-1) = 1 \u306F\
    \u308F\u304B\u3063\u3066\u308B\u306E\u3067\u3001\u6307\u6570\u3092\u3069\u3093\
    \u3069\u3093 q_i \u3067\u5272\u3063\u3066\u3044\u304F\n\t\tO(log p * (p-1\u306E\
    \u7D20\u56E0\u6570\u306E\u500B\u6570))\n\tp \u304C\u7D20\u6570\u3058\u3083\u306A\
    \u3044\u5834\u5408\u306F\u3001p-1 \u3058\u3083\u306A\u304F\u3066 phi(m) \u3067\
    \u540C\u3058\u3053\u3068\u3092\u3084\u308C\u3070\u3044\u3044\n*/\n\ntemplate <class\
    \ T, class Op = multiplies<>>\nconstexpr T power(T a, uint64_t n, T init = 1,\
    \ Op op = Op{}) {\n\twhile (n) {\n\t\tif (n & 1) init = op(init, a);\n\t\tif (n\
    \ >>= 1) a = op(a, a);\n\t}\n\treturn init;\n}\n\nll getOrder(ll x){\n\tauto pw\
    \ = [&](ll x, ll r){\n\t\treturn power<ll>(x,r,1,[&](ll a,ll b){return ll(__int128(a)*b%p);});\n\
    \t};\n\tll r = p-1;\n\t// ps: p-1 (or phi(m)) \u3092\u5272\u308B\u7D20\u6570\u306E\
    \u96C6\u5408 \u524D\u8A08\u7B97\n\tfor(ll q: ps){\n\t\twhile(r%q==0 && pw(x,r/q)\
    \ == 1) r /= q;\n\t}\n\treturn r;\n};\n"
  code: "/*\n\tx,p \u304C\u4E0E\u3048\u3089\u308C\u3066\u3001x^r = 1 mod p \u3092\u6E80\
    \u305F\u3059\u6700\u5C0F\u306E\u6B63\u6574\u6570 r \u3092\u8FD4\u3059\n\tp: fix\
    \ \u3067 x \u304C\u5927\u91CF\u306B\u6765\u308B\u30B1\u30FC\u30B9\u3092\u60F3\u5B9A\
    \n\n\t\u524D\u8A08\u7B97: p-1 \u306E\u7D20\u56E0\u6570 q_i \u3092\u5217\u6319\n\
    \t\u30AF\u30A8\u30EA:\n\t\tx^(p-1) = 1 \u306F\u308F\u304B\u3063\u3066\u308B\u306E\
    \u3067\u3001\u6307\u6570\u3092\u3069\u3093\u3069\u3093 q_i \u3067\u5272\u3063\u3066\
    \u3044\u304F\n\t\tO(log p * (p-1\u306E\u7D20\u56E0\u6570\u306E\u500B\u6570))\n\
    \tp \u304C\u7D20\u6570\u3058\u3083\u306A\u3044\u5834\u5408\u306F\u3001p-1 \u3058\
    \u3083\u306A\u304F\u3066 phi(m) \u3067\u540C\u3058\u3053\u3068\u3092\u3084\u308C\
    \u3070\u3044\u3044\n*/\n\ntemplate <class T, class Op = multiplies<>>\nconstexpr\
    \ T power(T a, uint64_t n, T init = 1, Op op = Op{}) {\n\twhile (n) {\n\t\tif\
    \ (n & 1) init = op(init, a);\n\t\tif (n >>= 1) a = op(a, a);\n\t}\n\treturn init;\n\
    }\n\nll getOrder(ll x){\n\tauto pw = [&](ll x, ll r){\n\t\treturn power<ll>(x,r,1,[&](ll\
    \ a,ll b){return ll(__int128(a)*b%p);});\n\t};\n\tll r = p-1;\n\t// ps: p-1 (or\
    \ phi(m)) \u3092\u5272\u308B\u7D20\u6570\u306E\u96C6\u5408 \u524D\u8A08\u7B97\n\
    \tfor(ll q: ps){\n\t\twhile(r%q==0 && pw(x,r/q) == 1) r /= q;\n\t}\n\treturn r;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: math/getOrder.cpp
  requiredBy: []
  timestamp: '2024-03-26 11:10:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/getOrder.cpp
layout: document
redirect_from:
- /library/math/getOrder.cpp
- /library/math/getOrder.cpp.html
title: math/getOrder.cpp
---
