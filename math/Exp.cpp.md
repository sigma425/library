---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/76447
    - https://official.contest.yandex.com/ptz-winter-2020/contest/17020/run-report/35151613/
  bundledCode: "#line 1 \"math/Exp.cpp\"\n/*\r\n\tf^n \u306E [x^0], .., [x^(m-1)]\
    \ \u3092\u8FD4\u3059\r\n\tf\u306E\u975E0\u8981\u7D20\u304C k \u500B\u306E\u3068\
    \u304D O(mk)\r\n\t\tcf. FFT\u3067\u3084\u308B\u3068 O(m log m log n) \u3068\u304B\
    \r\n\r\n\t! \u3044\u307E\u5B9F\u88C5\u304C\u3060\u308B\u3044\u304B\u3089k\u306E\
    \u4EE3\u308F\u308A\u306B\u6B21\u6570\u3067\u6291\u3048\u3066\u308B\u3001\u3044\
    \u3084\u5B9F\u88C5\u305D\u3093\u306A\u5909\u308F\u3089\u306A\u3044\u304B\u3089\
    \u51FA\u305F\u3089\u66F8\u3044\u3066\uFF08\u3054\u3081\u3093\uFF01\uFF57\uFF09\
    \r\n\r\n\thttps://codeforces.com/blog/entry/76447\r\n\tMifafa \u30C6\u30AF\r\n\
    \r\n\tverify : https://official.contest.yandex.com/ptz-winter-2020/contest/17020/run-report/35151613/\r\
    \n\t\t\u30B3\u30FC\u30CA\u30FC\u30B1\u30FC\u30B9\u306F\u77E5\u3089\u306D\u301C\
    \r\n\r\n\t\u5B9A\u6570\u500D : \r\n\t\t10^7 \u56DE\u304F\u3089\u3044mint\u306E\
    \u5272\u308A\u7B97\u3057\u305F\u30893s\u304B\u304B\u3063\u305F\u304B\u3089\u3001\
    \u3084\u3081\u3088\u3046\u306D\uFF01 (\u3061\u3083\u3093\u3068invs\u3092\u8A08\
    \u7B97\u3057\u3066\u304A\u304F)\r\n\t\t\u2191\u3057\u305F\u3089\u3001md <= 5e7\
    \ \u3067 1s \u304F\u3089\u3044 \u3061\u3087\u3044\u9045\u3044\u306A\r\n*/\r\n\r\
    \nV<mint> Exp(V<mint> f,ll n,int m){\r\n\tV<mint> g(m);\r\n\tif(m == 0) return\
    \ g;\r\n\tif(n == 0){\r\n\t\tg[0] = 1;\t// 0^0 = 1\r\n\t\treturn g;\r\n\t}\r\n\
    \tif(f.empty()){\r\n\t\treturn g;\r\n\t}\r\n\tif(f[0] == 0){\r\n\t\tint k = si(f);\r\
    \n\t\tint s=0;\r\n\t\twhile(s<k && f[s]==0) s++;\r\n\t\tif(s == k) return V<mint>();\t\
    // f = 0\r\n\t\t// f   = f_s * x^s + ...\r\n\t\t// f^n = x^ns * (const + ...)\r\
    \n\t\t// if(n*s >= m) return V<mint>();\r\n\t\tif(n >= (m+s-1)/s) return V<mint>();\r\
    \n\t\tV<mint> nf(k-s); rep(i,k-s) nf[i] = f[i+s];\r\n\t\tauto tmp = Exp(nf,n,m-n*s);\r\
    \n\t\trep(i,m-n*s) g[n*s+i] = tmp[i];\r\n\t\treturn g;\r\n\t}\r\n\tg[0] = f[0].pow(n);\t\
    \t// mint\u3058\u3083\u306A\u304B\u3063\u305F\u3089\u5B9A\u7FA9\u3057\u3066\u306A\
    \u3044\u304B\u3082\r\n\tmint if0 = f[0].inv();\r\n\trep(i,m-1){\r\n\t\t// (i+1)\
    \ g_{i+1} f_0 + i g_i f_1 + .. +           (i+1-d) g_{i+1-d} f_d\r\n\t\t// = \t\
    \t\t      n (g_i f_1 + 2 g_{i-1} f_2 + .. + d g_{i+1-d} f_d)\r\n\t\tint d = si(f)-1;\r\
    \n\t\tmint res = 0;\r\n\t\trep1(j,min(d,i+1)) res += g[i+1-j] * f[j] * (mint(n)*j\
    \ - (i+1-j));\r\n\t\tg[i+1] = res * if0 * invs[i+1];\r\n\t}\r\n\treturn g;\r\n\
    }\r\n"
  code: "/*\r\n\tf^n \u306E [x^0], .., [x^(m-1)] \u3092\u8FD4\u3059\r\n\tf\u306E\u975E\
    0\u8981\u7D20\u304C k \u500B\u306E\u3068\u304D O(mk)\r\n\t\tcf. FFT\u3067\u3084\
    \u308B\u3068 O(m log m log n) \u3068\u304B\r\n\r\n\t! \u3044\u307E\u5B9F\u88C5\
    \u304C\u3060\u308B\u3044\u304B\u3089k\u306E\u4EE3\u308F\u308A\u306B\u6B21\u6570\
    \u3067\u6291\u3048\u3066\u308B\u3001\u3044\u3084\u5B9F\u88C5\u305D\u3093\u306A\
    \u5909\u308F\u3089\u306A\u3044\u304B\u3089\u51FA\u305F\u3089\u66F8\u3044\u3066\
    \uFF08\u3054\u3081\u3093\uFF01\uFF57\uFF09\r\n\r\n\thttps://codeforces.com/blog/entry/76447\r\
    \n\tMifafa \u30C6\u30AF\r\n\r\n\tverify : https://official.contest.yandex.com/ptz-winter-2020/contest/17020/run-report/35151613/\r\
    \n\t\t\u30B3\u30FC\u30CA\u30FC\u30B1\u30FC\u30B9\u306F\u77E5\u3089\u306D\u301C\
    \r\n\r\n\t\u5B9A\u6570\u500D : \r\n\t\t10^7 \u56DE\u304F\u3089\u3044mint\u306E\
    \u5272\u308A\u7B97\u3057\u305F\u30893s\u304B\u304B\u3063\u305F\u304B\u3089\u3001\
    \u3084\u3081\u3088\u3046\u306D\uFF01 (\u3061\u3083\u3093\u3068invs\u3092\u8A08\
    \u7B97\u3057\u3066\u304A\u304F)\r\n\t\t\u2191\u3057\u305F\u3089\u3001md <= 5e7\
    \ \u3067 1s \u304F\u3089\u3044 \u3061\u3087\u3044\u9045\u3044\u306A\r\n*/\r\n\r\
    \nV<mint> Exp(V<mint> f,ll n,int m){\r\n\tV<mint> g(m);\r\n\tif(m == 0) return\
    \ g;\r\n\tif(n == 0){\r\n\t\tg[0] = 1;\t// 0^0 = 1\r\n\t\treturn g;\r\n\t}\r\n\
    \tif(f.empty()){\r\n\t\treturn g;\r\n\t}\r\n\tif(f[0] == 0){\r\n\t\tint k = si(f);\r\
    \n\t\tint s=0;\r\n\t\twhile(s<k && f[s]==0) s++;\r\n\t\tif(s == k) return V<mint>();\t\
    // f = 0\r\n\t\t// f   = f_s * x^s + ...\r\n\t\t// f^n = x^ns * (const + ...)\r\
    \n\t\t// if(n*s >= m) return V<mint>();\r\n\t\tif(n >= (m+s-1)/s) return V<mint>();\r\
    \n\t\tV<mint> nf(k-s); rep(i,k-s) nf[i] = f[i+s];\r\n\t\tauto tmp = Exp(nf,n,m-n*s);\r\
    \n\t\trep(i,m-n*s) g[n*s+i] = tmp[i];\r\n\t\treturn g;\r\n\t}\r\n\tg[0] = f[0].pow(n);\t\
    \t// mint\u3058\u3083\u306A\u304B\u3063\u305F\u3089\u5B9A\u7FA9\u3057\u3066\u306A\
    \u3044\u304B\u3082\r\n\tmint if0 = f[0].inv();\r\n\trep(i,m-1){\r\n\t\t// (i+1)\
    \ g_{i+1} f_0 + i g_i f_1 + .. +           (i+1-d) g_{i+1-d} f_d\r\n\t\t// = \t\
    \t\t      n (g_i f_1 + 2 g_{i-1} f_2 + .. + d g_{i+1-d} f_d)\r\n\t\tint d = si(f)-1;\r\
    \n\t\tmint res = 0;\r\n\t\trep1(j,min(d,i+1)) res += g[i+1-j] * f[j] * (mint(n)*j\
    \ - (i+1-j));\r\n\t\tg[i+1] = res * if0 * invs[i+1];\r\n\t}\r\n\treturn g;\r\n\
    }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/Exp.cpp
  requiredBy: []
  timestamp: '2020-10-05 12:04:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Exp.cpp
layout: document
redirect_from:
- /library/math/Exp.cpp
- /library/math/Exp.cpp.html
title: math/Exp.cpp
---
