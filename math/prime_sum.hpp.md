---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime.hpp
    title: math/prime.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/prime_factor_dfs.hpp
    title: math/prime_factor_dfs.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_oj/counting_primes.test.cpp
    title: test_oj/counting_primes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://loj.ac/s/2216105
  bundledCode: "#line 1 \"math/prime_sum.hpp\"\n/*\n\tf: \u5B8C\u5168\u4E57\u6CD5\u7684\
    \ \u306B\u5BFE\u3057\u3001G(n) = \\sum_{p <= n} f(p) \u3092\u307F\u305F\u3059\
    \ G \u3092\u6C42\u3081\u308B\n\tF \u304C\u6C42\u307E\u3063\u3066\u3044\u308B\u5FC5\
    \u8981\u304C\u3042\u308B\n\n\t\u305F\u3060\u3057\u5927\u6587\u5B57\u306F\u5BFE\
    \u5FDC\u3059\u308B\u7D2F\u7A4D\u548C\u3092\u6307\u3059\u3002\n\t\u307E\u305F\u3001\
    \"A \u304C\u6C42\u307E\u3063\u3066\u3044\u308B\" \u3068\u306F\u3001O(sqrt(N))\
    \ \u500B\u306E n \\in {[N/i}} \u306B\u5BFE\u3057\u3066 A(n) = a(1) + .. + a(n)\
    \ \u304C\u6C42\u307E\u3063\u3066\u3044\u308B\u3053\u3068\u3092\u3044\u3046\n\n\
    \t\u4F7F\u3044\u65B9:\n\t\t\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306B N\
    \ \u3068 F \u3092\u6E21\u3059\n\t\tF \u306F n \\in {[N/i]} \u306B F(n) \u3067\u30A2\
    \u30AF\u30BB\u30B9\u3057\u305F\u3068\u304D\u306B\u6B63\u3057\u3044\u5024\u3092\
    \u8FD4\u3059\u5FC5\u8981\u304C\u3042\u308B\n\t\t\u30E9\u30E0\u30C0\u5F0F\u3092\
    \u6E21\u3057\u305F\u308A\u3001\u4ED6\u306E\u7D2F\u7A4D\u548C\u304C \"\u6C42\u307E\
    \u3063\u3066\u3044\u308B\" \u3088\u3046\u306A struct \u3092\u6E21\u3057\u305F\u308A\
    \n\n\t\u5177\u4F53\u4F8B:\n\t- \u7D20\u6570\u30AB\u30A6\u30F3\u30C8: f(n) = 1,\
    \ \u3064\u307E\u308A F(n) = n \u3092\u6E21\u3059\n\t- \u7D20\u6570sum: f(n) =\
    \ n, \u3064\u307E\u308A F(n) = n(n+1)/2 \u3092\u6E21\u3059\n\t- mod 6 \u3067 5\
    \ \u306B\u306A\u308B\u7D20\u6570\u30AB\u30A6\u30F3\u30C8: f(n) = (n%6 == 5) \u3067\
    \u306F\u4E57\u6CD5\u7684\u3067\u3059\u3089\u306A\u3044\u306E\u3067\u30C0\u30E1\
    \n\t\tf \u306F\u5B8C\u5168\u4E57\u6CD5\u7684\u3067\u306A\u3051\u308C\u3070\u306A\
    \u3089\u306A\u3044\u306E\u3067 f(p) \u3092\u6C7A\u3081\u308C\u3070\u6C7A\u307E\
    \u308B\n\t\tf(p) = 0 if p = 2,3\n\t\tf(p) = 1 if p mod 6 = 1\n\t\tf(p) = -1 if\
    \ p mod 6 = 5\n\t\t\u3068\u5B9A\u7FA9\u3059\u308C\u3070\u3001f(n) \u304C n mod\
    \ 6 = 1 \u306A\u3089 1, n mod 6 = 5 \u306A\u3089 -1, \u305D\u308C\u4EE5\u5916\u306A\
    \u3089 0 \u306B\u306A\u308B\u306E\u3067\u3001F \u3092\u7C21\u5358\u306B\u6C42\u3081\
    \u3089\u308C\u308B\n\t\t\u3053\u308C\u3067 (mod6 \u3067 1 \u306E\u500B\u6570)\
    \ - (mod6 \u3067 5 \u306E\u500B\u6570) \u304C\u6C42\u307E\u308B\u306E\u3067\u3001\
    + \u304C\u666E\u901A\u306E\u7D20\u6570\u30AB\u30A6\u30F3\u30C8\u306A\u306E\u3068\
    \u5408\u308F\u305B\u308B\u3068\u6C42\u307E\u308B\n\t\t\u4E00\u822C\u306B\u306F\
    \u3001Z/mZ \u306E\u5F62\u5F0F\u7684\u548C (\u30E2\u30CE\u30A4\u30C9\u74B0) \u304C\
    \ value_type \u3060\u3068\u601D\u3063\u3066\u3084\u308B\u3068\u3088\u3044\n\t\t\
    \tLOJ 6028: https://loj.ac/s/2216105\n\n\t\u8A08\u7B97\u91CF: O(N^{3/4}/logN)\
    \ time, O(N^{1/2}) space\n\tN = 10^11: 0.4s, N = 10^12: 2s \u304F\u3089\u3044\
    \ (prime count, -O3)\n*/\n\n#line 1 \"math/prime.hpp\"\nV<bool> isp;\nV<int> pr;\n\
    V<int> sf; //smallest factor, sf[9*5*11] = 3\nV<int> mu;\t//[1,-1,0,0,...]\nV<int>\
    \ tot;\t//[1,p-1,(p-1)p,(p-1)p^2,..]\nV<int> sig;\t// [1,1+p,1+p+p^2,...]\nvoid\
    \ linear_sieve(int X){\t\t// <= X\n\tisp = V<bool>(X+1,true); isp[0] = isp[1]\
    \ = false;\n\tsf = V<int>(X+1);\n\tpr.clear();\n\tfor(int i=2;i<=X;i++){\n\t\t\
    if(isp[i]){\n\t\t\tpr.pb(i);\n\t\t\tsf[i] = i;\n\t\t}\n\t\tfor(int j=0;i*pr[j]<=X;j++){\n\
    \t\t\tisp[i*pr[j]] = false;\n\t\t\tsf[i*pr[j]] = pr[j];\n\t\t\tif(i%pr[j] == 0)\
    \ break;\n\t\t}\n\t}\n\t// mu = V<int>(X+1);\n\t// mu[1] = 1;\n\t// for(int i=2;i<=X;i++){\n\
    \t// \tint p = sf[i];\n\t// \tif(i/p%p == 0) mu[i] = 0;\n\t// \telse mu[i] = -mu[i/p];\n\
    \t// }\n\t// tot = V<int>(X+1);\n\t// tot[1] = 1;\n\t// for(int i=2;i<=X;i++){\n\
    \t// \tint p = sf[i];\n\t// \tif(i/p%p == 0) tot[i] = tot[i/p] * p;\n\t// \telse\
    \ tot[i] = tot[i/p] * (p-1);\n\t// }\n\t// sig = V<int>(X+1);\n\t// sig[1] = 1;\n\
    \t// for(int i=2;i<=X;i++){\n\t// \tint p = sf[i];\n\t// \tint x = i;\n\t// \t\
    int w = 1;\n\t// \twhile(x%p == 0){\n\t// \t\tx /= p; w = w*p+1;\n\t// \t}\n\t\
    // \tsig[i] = sig[x] * w;\n\t// }\n}\n#line 31 \"math/prime_sum.hpp\"\n\ntemplate\
    \ <class T>\nstruct PrimeSum {\n\tll N,sq;\n\tvector<T> small,large;\n\n\ttemplate\
    \ <class Func>\n\tPrimeSum(ll N_, const Func F) : N(N_), sq(sqrtl(N_)) {\n\t\t\
    linear_sieve(sq);\n\t\tsmall.resize(sq+1); large.resize(sq+1);\n\t\trep1(n,sq)\
    \ small[n] = F(n) - 1;\n\t\trep1(n,sq) large[n] = F(N/n) - 1;\n\t\tfor(ll p: pr){\n\
    \t\t\tint R = min(sq, N/(p*p));\n\t\t\tint M = sq/p;\n\t\t\tT x = small[p-1];\n\
    \t\t\tT fp = small[p] - small[p-1];\n\t\t\trep1(n,M) large[n] -= fp * (large[n*p]\
    \ - x);\n\t\t\tfor(int n=M+1;n<=R;n++) large[n] -= fp * (small[N/(n*p)] - x);\n\
    \t\t\tfor(int n=sq;n>=p*p;n--) small[n] -= fp * (small[n/p] - x);\n\t\t}\n\t}\n\
    \n\tT& operator()(ll n){\n\t\treturn (n <= sq ? small[n] : large[N/n]);\n\t}\n\
    };\n"
  code: "/*\n\tf: \u5B8C\u5168\u4E57\u6CD5\u7684 \u306B\u5BFE\u3057\u3001G(n) = \\\
    sum_{p <= n} f(p) \u3092\u307F\u305F\u3059 G \u3092\u6C42\u3081\u308B\n\tF \u304C\
    \u6C42\u307E\u3063\u3066\u3044\u308B\u5FC5\u8981\u304C\u3042\u308B\n\n\t\u305F\
    \u3060\u3057\u5927\u6587\u5B57\u306F\u5BFE\u5FDC\u3059\u308B\u7D2F\u7A4D\u548C\
    \u3092\u6307\u3059\u3002\n\t\u307E\u305F\u3001\"A \u304C\u6C42\u307E\u3063\u3066\
    \u3044\u308B\" \u3068\u306F\u3001O(sqrt(N)) \u500B\u306E n \\in {[N/i}} \u306B\
    \u5BFE\u3057\u3066 A(n) = a(1) + .. + a(n) \u304C\u6C42\u307E\u3063\u3066\u3044\
    \u308B\u3053\u3068\u3092\u3044\u3046\n\n\t\u4F7F\u3044\u65B9:\n\t\t\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\u306B N \u3068 F \u3092\u6E21\u3059\n\t\tF \u306F\
    \ n \\in {[N/i]} \u306B F(n) \u3067\u30A2\u30AF\u30BB\u30B9\u3057\u305F\u3068\u304D\
    \u306B\u6B63\u3057\u3044\u5024\u3092\u8FD4\u3059\u5FC5\u8981\u304C\u3042\u308B\
    \n\t\t\u30E9\u30E0\u30C0\u5F0F\u3092\u6E21\u3057\u305F\u308A\u3001\u4ED6\u306E\
    \u7D2F\u7A4D\u548C\u304C \"\u6C42\u307E\u3063\u3066\u3044\u308B\" \u3088\u3046\
    \u306A struct \u3092\u6E21\u3057\u305F\u308A\n\n\t\u5177\u4F53\u4F8B:\n\t- \u7D20\
    \u6570\u30AB\u30A6\u30F3\u30C8: f(n) = 1, \u3064\u307E\u308A F(n) = n \u3092\u6E21\
    \u3059\n\t- \u7D20\u6570sum: f(n) = n, \u3064\u307E\u308A F(n) = n(n+1)/2 \u3092\
    \u6E21\u3059\n\t- mod 6 \u3067 5 \u306B\u306A\u308B\u7D20\u6570\u30AB\u30A6\u30F3\
    \u30C8: f(n) = (n%6 == 5) \u3067\u306F\u4E57\u6CD5\u7684\u3067\u3059\u3089\u306A\
    \u3044\u306E\u3067\u30C0\u30E1\n\t\tf \u306F\u5B8C\u5168\u4E57\u6CD5\u7684\u3067\
    \u306A\u3051\u308C\u3070\u306A\u3089\u306A\u3044\u306E\u3067 f(p) \u3092\u6C7A\
    \u3081\u308C\u3070\u6C7A\u307E\u308B\n\t\tf(p) = 0 if p = 2,3\n\t\tf(p) = 1 if\
    \ p mod 6 = 1\n\t\tf(p) = -1 if p mod 6 = 5\n\t\t\u3068\u5B9A\u7FA9\u3059\u308C\
    \u3070\u3001f(n) \u304C n mod 6 = 1 \u306A\u3089 1, n mod 6 = 5 \u306A\u3089 -1,\
    \ \u305D\u308C\u4EE5\u5916\u306A\u3089 0 \u306B\u306A\u308B\u306E\u3067\u3001\
    F \u3092\u7C21\u5358\u306B\u6C42\u3081\u3089\u308C\u308B\n\t\t\u3053\u308C\u3067\
    \ (mod6 \u3067 1 \u306E\u500B\u6570) - (mod6 \u3067 5 \u306E\u500B\u6570) \u304C\
    \u6C42\u307E\u308B\u306E\u3067\u3001+ \u304C\u666E\u901A\u306E\u7D20\u6570\u30AB\
    \u30A6\u30F3\u30C8\u306A\u306E\u3068\u5408\u308F\u305B\u308B\u3068\u6C42\u307E\
    \u308B\n\t\t\u4E00\u822C\u306B\u306F\u3001Z/mZ \u306E\u5F62\u5F0F\u7684\u548C\
    \ (\u30E2\u30CE\u30A4\u30C9\u74B0) \u304C value_type \u3060\u3068\u601D\u3063\u3066\
    \u3084\u308B\u3068\u3088\u3044\n\t\t\tLOJ 6028: https://loj.ac/s/2216105\n\n\t\
    \u8A08\u7B97\u91CF: O(N^{3/4}/logN) time, O(N^{1/2}) space\n\tN = 10^11: 0.4s,\
    \ N = 10^12: 2s \u304F\u3089\u3044 (prime count, -O3)\n*/\n\n#include \"math/prime.hpp\"\
    \n\ntemplate <class T>\nstruct PrimeSum {\n\tll N,sq;\n\tvector<T> small,large;\n\
    \n\ttemplate <class Func>\n\tPrimeSum(ll N_, const Func F) : N(N_), sq(sqrtl(N_))\
    \ {\n\t\tlinear_sieve(sq);\n\t\tsmall.resize(sq+1); large.resize(sq+1);\n\t\t\
    rep1(n,sq) small[n] = F(n) - 1;\n\t\trep1(n,sq) large[n] = F(N/n) - 1;\n\t\tfor(ll\
    \ p: pr){\n\t\t\tint R = min(sq, N/(p*p));\n\t\t\tint M = sq/p;\n\t\t\tT x = small[p-1];\n\
    \t\t\tT fp = small[p] - small[p-1];\n\t\t\trep1(n,M) large[n] -= fp * (large[n*p]\
    \ - x);\n\t\t\tfor(int n=M+1;n<=R;n++) large[n] -= fp * (small[N/(n*p)] - x);\n\
    \t\t\tfor(int n=sq;n>=p*p;n--) small[n] -= fp * (small[n/p] - x);\n\t\t}\n\t}\n\
    \n\tT& operator()(ll n){\n\t\treturn (n <= sq ? small[n] : large[N/n]);\n\t}\n\
    };"
  dependsOn:
  - math/prime.hpp
  isVerificationFile: false
  path: math/prime_sum.hpp
  requiredBy:
  - math/prime_factor_dfs.hpp
  timestamp: '2025-04-03 02:01:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_oj/counting_primes.test.cpp
documentation_of: math/prime_sum.hpp
layout: document
redirect_from:
- /library/math/prime_sum.hpp
- /library/math/prime_sum.hpp.html
title: math/prime_sum.hpp
---
