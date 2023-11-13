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
    - https://atcoder.jp/contests/xmascon19/submissions/38449904
    - https://projecteuler.net/problem=415
  bundledCode: "#line 1 \"math/MultiplicativeSum.cpp\"\n/*\n\tf: multiplicative\n\t\
    F(n) := \\sum_{1<=i<=n} f(n)\n\tk \\in Q(n) := { [n/j] } \u306B\u5BFE\u3057\u3066\
    \u3001F(k) \u3092\u6301\u3063\u3066\u3044\u308B k=0\u3082OK(0)\n\t- Q(n) \u5217\
    \u6319\n\t\tfor(ll k=1;;k=N/(N/(k+1))){\n\t\t\tj \\in ( n/(k+1) , n/k ] \u306B\
    \u5BFE\u3057 n/j = k\n\t\t\tif(k == N) break;\n\t\t}\n*/\ntemplate<class mint>\n\
    struct MultSum{\n\tll N,r;\n\tV<mint> a,b;\n\tMultSum(ll N_):N(N_){\n\t\tr = sqrtl(N);\n\
    \t\ta.resize(r+1); b.resize(r+1);\n\t}\n\tmint operator[](ll k) const { return\
    \ k<=r ? a[k] : b[N/k]; }\n\tmint& operator[](ll k){ return k<=r ? a[k] : b[N/k];\
    \ }\n};\n\n/*\n\treturn H s.t. f*g = h\n\tH(n) = \\sum_{j \\in Q(n)} ( F([n/j])-F([n/(j+1)])\
    \ ) * G(j)\n\tH(1),..,H(L) \u307E\u3067\u306F\u65E2\u306B\u8A08\u7B97\u6E08\u307F\
    \u3068\u3059\u308B\n\t\tL = 0 \u306A\u3089 O(N^{3/4})\n\t\tL = (N/(loglogN))^{2/3}\
    \ \u3068\u3059\u308B\u3053\u3068\u3067 O*(N^{2/3}) \u306B\n\t\t\u5B9F\u969B\u306F\
    \ L = 10^7 \u304F\u3089\u3044\u307E\u3067\u524D\u8A08\u7B97\uFF1F\n\t\u5272\u308A\
    \u7B97\u3092\u6E1B\u3089\u3057\u305F\u308Adouble\u306E\u5272\u308A\u7B97\u306B\
    \u5909\u3048\u308B\uFF1F\u3053\u3068\u3067\u3082\u3046\u3061\u3087\u3063\u3068\
    \u6700\u9069\u5316\u3067\u304D\u308B\u304B\u3082\u306D\n\tverify:\n\t\t\u3057\u3066\
    \u306A\u3044\u305C\n*/\ntemplate<class mint>\nvoid getH(const MultSum<mint>& F,\
    \ const MultSum<mint>& G, MultSum<mint>& H, ll L){\n\tll N = F.N;\n\tfor(ll n=1;;n=N/(N/(n+1))){\n\
    \t\tif(n > L){\n\t\t\tfor(ll j=1;;j=n/(n/(j+1))){\n\t\t\t\tH[n] += (F[n/j] - F[n/(j+1)])\
    \ * G[j];\n\t\t\t\tif(j == n) break;\n\t\t\t}\n\t\t}\n\t\tif(n == N) break;\n\t\
    }\n}\n\n/*\n\tcompute G s.t. f*g = h\n\tH(n) = \\sum_{j \\in Q(n)} ( F([n/j])-F([n/(j+1)])\
    \ ) * G(j)\n\tG(1),..,G(L) \u307E\u3067\u306F\u65E2\u306B\u8A08\u7B97\u6E08\u307F\
    \u3068\u3059\u308B\n\t\tL = 0 \u306A\u3089 O(N^{3/4})\n\t\tL = (N/(loglogN))^{2/3}\
    \ \u3068\u3059\u308B\u3053\u3068\u3067 O*(N^{2/3}) \u306B\n\t\t\u5B9F\u969B\u306F\
    \ L = 10^7 \u304F\u3089\u3044\u307E\u3067\u524D\u8A08\u7B97\uFF1F\n\t\u5272\u308A\
    \u7B97\u3092\u6E1B\u3089\u3057\u305F\u308Adouble\u306E\u5272\u308A\u7B97\u306B\
    \u5909\u3048\u308B\uFF1F\u3053\u3068\u3067\u3082\u3046\u3061\u3087\u3063\u3068\
    \u6700\u9069\u5316\u3067\u304D\u308B\u304B\u3082\u306D\n\tverify:\n\t\thttps://atcoder.jp/contests/xmascon19/submissions/38449904\n\
    \t\thttps://projecteuler.net/problem=415\n*/\ntemplate<class mint>\nvoid getG(const\
    \ MultSum<mint>& F, MultSum<mint>& G, const MultSum<mint>& H, ll L){\n\tll N =\
    \ F.N;\n\tfor(ll n=1;;n=N/(N/(n+1))){\n\t\tif(n > L){\n\t\t\tmint S = H[n];\n\t\
    \t\tfor(ll j=1;;j=n/(n/(j+1))){\n\t\t\t\tif(j < n){\n\t\t\t\t\tS -= (F[n/j] -\
    \ F[n/(j+1)]) * G[j];\n\t\t\t\t}else{\n\t\t\t\t\tG[n] = S;\n\t\t\t\t\tbreak;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif(n == N) break;\n\t}\t\n}\n"
  code: "/*\n\tf: multiplicative\n\tF(n) := \\sum_{1<=i<=n} f(n)\n\tk \\in Q(n) :=\
    \ { [n/j] } \u306B\u5BFE\u3057\u3066\u3001F(k) \u3092\u6301\u3063\u3066\u3044\u308B\
    \ k=0\u3082OK(0)\n\t- Q(n) \u5217\u6319\n\t\tfor(ll k=1;;k=N/(N/(k+1))){\n\t\t\
    \tj \\in ( n/(k+1) , n/k ] \u306B\u5BFE\u3057 n/j = k\n\t\t\tif(k == N) break;\n\
    \t\t}\n*/\ntemplate<class mint>\nstruct MultSum{\n\tll N,r;\n\tV<mint> a,b;\n\t\
    MultSum(ll N_):N(N_){\n\t\tr = sqrtl(N);\n\t\ta.resize(r+1); b.resize(r+1);\n\t\
    }\n\tmint operator[](ll k) const { return k<=r ? a[k] : b[N/k]; }\n\tmint& operator[](ll\
    \ k){ return k<=r ? a[k] : b[N/k]; }\n};\n\n/*\n\treturn H s.t. f*g = h\n\tH(n)\
    \ = \\sum_{j \\in Q(n)} ( F([n/j])-F([n/(j+1)]) ) * G(j)\n\tH(1),..,H(L) \u307E\
    \u3067\u306F\u65E2\u306B\u8A08\u7B97\u6E08\u307F\u3068\u3059\u308B\n\t\tL = 0\
    \ \u306A\u3089 O(N^{3/4})\n\t\tL = (N/(loglogN))^{2/3} \u3068\u3059\u308B\u3053\
    \u3068\u3067 O*(N^{2/3}) \u306B\n\t\t\u5B9F\u969B\u306F L = 10^7 \u304F\u3089\u3044\
    \u307E\u3067\u524D\u8A08\u7B97\uFF1F\n\t\u5272\u308A\u7B97\u3092\u6E1B\u3089\u3057\
    \u305F\u308Adouble\u306E\u5272\u308A\u7B97\u306B\u5909\u3048\u308B\uFF1F\u3053\
    \u3068\u3067\u3082\u3046\u3061\u3087\u3063\u3068\u6700\u9069\u5316\u3067\u304D\
    \u308B\u304B\u3082\u306D\n\tverify:\n\t\t\u3057\u3066\u306A\u3044\u305C\n*/\n\
    template<class mint>\nvoid getH(const MultSum<mint>& F, const MultSum<mint>& G,\
    \ MultSum<mint>& H, ll L){\n\tll N = F.N;\n\tfor(ll n=1;;n=N/(N/(n+1))){\n\t\t\
    if(n > L){\n\t\t\tfor(ll j=1;;j=n/(n/(j+1))){\n\t\t\t\tH[n] += (F[n/j] - F[n/(j+1)])\
    \ * G[j];\n\t\t\t\tif(j == n) break;\n\t\t\t}\n\t\t}\n\t\tif(n == N) break;\n\t\
    }\n}\n\n/*\n\tcompute G s.t. f*g = h\n\tH(n) = \\sum_{j \\in Q(n)} ( F([n/j])-F([n/(j+1)])\
    \ ) * G(j)\n\tG(1),..,G(L) \u307E\u3067\u306F\u65E2\u306B\u8A08\u7B97\u6E08\u307F\
    \u3068\u3059\u308B\n\t\tL = 0 \u306A\u3089 O(N^{3/4})\n\t\tL = (N/(loglogN))^{2/3}\
    \ \u3068\u3059\u308B\u3053\u3068\u3067 O*(N^{2/3}) \u306B\n\t\t\u5B9F\u969B\u306F\
    \ L = 10^7 \u304F\u3089\u3044\u307E\u3067\u524D\u8A08\u7B97\uFF1F\n\t\u5272\u308A\
    \u7B97\u3092\u6E1B\u3089\u3057\u305F\u308Adouble\u306E\u5272\u308A\u7B97\u306B\
    \u5909\u3048\u308B\uFF1F\u3053\u3068\u3067\u3082\u3046\u3061\u3087\u3063\u3068\
    \u6700\u9069\u5316\u3067\u304D\u308B\u304B\u3082\u306D\n\tverify:\n\t\thttps://atcoder.jp/contests/xmascon19/submissions/38449904\n\
    \t\thttps://projecteuler.net/problem=415\n*/\ntemplate<class mint>\nvoid getG(const\
    \ MultSum<mint>& F, MultSum<mint>& G, const MultSum<mint>& H, ll L){\n\tll N =\
    \ F.N;\n\tfor(ll n=1;;n=N/(N/(n+1))){\n\t\tif(n > L){\n\t\t\tmint S = H[n];\n\t\
    \t\tfor(ll j=1;;j=n/(n/(j+1))){\n\t\t\t\tif(j < n){\n\t\t\t\t\tS -= (F[n/j] -\
    \ F[n/(j+1)]) * G[j];\n\t\t\t\t}else{\n\t\t\t\t\tG[n] = S;\n\t\t\t\t\tbreak;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif(n == N) break;\n\t}\t\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/MultiplicativeSum.cpp
  requiredBy: []
  timestamp: '2023-11-14 00:07:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/MultiplicativeSum.cpp
layout: document
redirect_from:
- /library/math/MultiplicativeSum.cpp
- /library/math/MultiplicativeSum.cpp.html
title: math/MultiplicativeSum.cpp
---
