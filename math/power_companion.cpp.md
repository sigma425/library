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
    - https://codeforces.com/blog/entry/124815
    - https://contest.ucup.ac/submission/518580
    - https://github.com/hos-lyric/libra/blob/master/algebra/matrix_frobenius.cpp
  bundledCode: "#line 1 \"math/power_companion.cpp\"\n/*\n\tC := \t0\t0\t0\tc_0\n\t\
    \t\t1\t0\t0\tc_1\n\t\t\t0\t1\t0\tc_2\n\t\t\t0\t0\t1\tc_{n-1}\n\n\t\u3068\u3044\
    \u3046 n*n \u30B3\u30F3\u30D1\u30CB\u30AA\u30F3\u884C\u5217 C \u3092\u8003\u3048\
    \u308B\n\tC^m \u304C\u3069\u3046\u3044\u3046\u5F62\u306B\u306A\u308B\u304B\u3068\
    \u3044\u3046\u3068\u3001\n\tv_0 := T^(1 0 0 0), v_i = C * v_{i-1} \u3068\u3057\
    \u3066\u3001\n\tC^m = (v_m v_{m+1} ... v_{m+n-1})\n\n\t\u3053\u306E\u30E9\u30A4\
    \u30D6\u30E9\u30EA\u306F\u9577\u3055 n \u306E\u30D9\u30AF\u30C8\u30EB v_m \u3092\
    \u8FD4\u3059\u3002\u578B\u306F\u53EF\u63DB\u74B0\u3067\u3042\u308B\u3053\u3068\
    \u3057\u304B\u8981\u8ACB\u3057\u306A\u3044\n\tO(n^2 log m)\n\tmint \u3068\u304B\
    \u306A\u3089 FFT \u3067 O(n logn logm)\u3001\u3068\u3044\u3046\u304B x^m % (x^n\
    \ - (a+bx+c^2)) \u3092\u8A08\u7B97\u3057\u3066\u304F\u3060\u3055\u3044(\u5F8C\u8FF0\
    )\n\n\t\u4ED5\u7D44\u307F:\n\t\tv_0\t\tv_1\t\tv_2\t\tv_3\t\tv_4\t\t...\n\t\t1\t\
    \t0\t\t0\t\ta\t\tac\n\t\t0\t\t1\t\t0\t\tb\t\ta+bc\n\t\t0\t\t0\t\t1\t\tc\t\tb+c^2\n\
    \n\t\t1\t\tx\t\tx^2\t\ta+bx+cx^2\t...\n\t\t\u3068\u306A\u308B\u3002v_m \u306F\u3001\
    \ x^m % (x^n - (a+bx+c^2)) \u3068\u5BFE\u5FDC\u3057\u3066\u3044\u308B\n\n\t\u4F7F\
    \u3044\u9053:\n\t\t- Toeplitz \u884C\u5217\u306E\u7D2F\u4E57\u304C\u3053\u308C\
    \u306B\u5E30\u7740\u3055\u308C\u308B\n\t\t- \u4E00\u822C\u306E\u4F53\u3067\u306E\
    \u884C\u5217\u7D2F\u4E57\u3092 O(N^3 + N logN logK) \u3067\u3084\u308B\u3068\u304D\
    \u306B\u3053\u308C\u306B\u5E30\u7740\u3059\u308B\n\t\t\t\u884C\u5217 A \u306F\
    \ \u3061\u3087\u3046\u3069\u4E00\u3064\u306E\u30D5\u30ED\u30D9\u30CB\u30A6\u30B9\
    \u6A19\u6E96\u5F62\u306B\u76F8\u4F3C (B = QAQ^-1)\n\t\t\t\u30D5\u30ED\u30D9\u30CB\
    \u30A6\u30B9\u6A19\u6E96\u5F62\u306F\u3001(\u5BFE\u89D2)\u30D6\u30ED\u30C3\u30AF\
    \u3054\u3068\u306B\u30B3\u30F3\u30D1\u30CB\u30AA\u30F3\u884C\u5217\u3001\u307F\
    \u305F\u3044\u306B\u306A\u3063\u3066\u308B\n\t\t\thttps://codeforces.com/blog/entry/124815\n\
    \t\t\thttps://github.com/hos-lyric/libra/blob/master/algebra/matrix_frobenius.cpp\n\
    \tverify:\n\t\tucup-3-6 E https://contest.ucup.ac/submission/518580\n\n*/\n\n\
    /*\n\tv_m -> v_{m+1}\n\tO(n)\n*/\nvoid shift(V<mint>& v, const V<mint>& c){\n\t\
    int n = c.size();\n\tmint vn = v[n-1];\n\tper1(i,n-1) v[i] = v[i-1];\n\tv[0] =\
    \ 0;\n\trep(i,n) v[i] += vn * c[i];\n}\n/*\n\tf = v_p, g = v_q\t-> v_{p+q}\n\t\
    O(n^2)\n*/\nV<mint> mul(const V<mint>& f, const V<mint>& g, const V<mint>& c){\n\
    \tint n = c.size();\n\tV<mint> h(n+n-1);\n\trep(i,n) rep(j,n) h[i+j] += f[i] *\
    \ g[j];\n\tfor(int k=n+n-2;k>=n;k--){\n\t\trep(i,n) h[k-n+i] += h[k] * c[i];\n\
    \t}\n\th.resize(n);\n\treturn h;\n}\n// v_m \u3092\u8FD4\u3059, O(n^2 log m)\n\
    V<mint> power_companion(const V<mint>& c, ll m){\n\tassert(m >= 0);\n\tint n =\
    \ c.size();\n\tif(m == 0){\n\t\tV<mint> f(n); f[0] = 1;\n\t\treturn f;\n\t}\n\t\
    auto f = power_companion(c, m/2);\n\tf = mul(f,f,c);\n\tif(m&1) shift(f,c);\n\t\
    return f;\n}\n"
  code: "/*\n\tC := \t0\t0\t0\tc_0\n\t\t\t1\t0\t0\tc_1\n\t\t\t0\t1\t0\tc_2\n\t\t\t\
    0\t0\t1\tc_{n-1}\n\n\t\u3068\u3044\u3046 n*n \u30B3\u30F3\u30D1\u30CB\u30AA\u30F3\
    \u884C\u5217 C \u3092\u8003\u3048\u308B\n\tC^m \u304C\u3069\u3046\u3044\u3046\u5F62\
    \u306B\u306A\u308B\u304B\u3068\u3044\u3046\u3068\u3001\n\tv_0 := T^(1 0 0 0),\
    \ v_i = C * v_{i-1} \u3068\u3057\u3066\u3001\n\tC^m = (v_m v_{m+1} ... v_{m+n-1})\n\
    \n\t\u3053\u306E\u30E9\u30A4\u30D6\u30E9\u30EA\u306F\u9577\u3055 n \u306E\u30D9\
    \u30AF\u30C8\u30EB v_m \u3092\u8FD4\u3059\u3002\u578B\u306F\u53EF\u63DB\u74B0\u3067\
    \u3042\u308B\u3053\u3068\u3057\u304B\u8981\u8ACB\u3057\u306A\u3044\n\tO(n^2 log\
    \ m)\n\tmint \u3068\u304B\u306A\u3089 FFT \u3067 O(n logn logm)\u3001\u3068\u3044\
    \u3046\u304B x^m % (x^n - (a+bx+c^2)) \u3092\u8A08\u7B97\u3057\u3066\u304F\u3060\
    \u3055\u3044(\u5F8C\u8FF0)\n\n\t\u4ED5\u7D44\u307F:\n\t\tv_0\t\tv_1\t\tv_2\t\t\
    v_3\t\tv_4\t\t...\n\t\t1\t\t0\t\t0\t\ta\t\tac\n\t\t0\t\t1\t\t0\t\tb\t\ta+bc\n\t\
    \t0\t\t0\t\t1\t\tc\t\tb+c^2\n\n\t\t1\t\tx\t\tx^2\t\ta+bx+cx^2\t...\n\t\t\u3068\
    \u306A\u308B\u3002v_m \u306F\u3001 x^m % (x^n - (a+bx+c^2)) \u3068\u5BFE\u5FDC\
    \u3057\u3066\u3044\u308B\n\n\t\u4F7F\u3044\u9053:\n\t\t- Toeplitz \u884C\u5217\
    \u306E\u7D2F\u4E57\u304C\u3053\u308C\u306B\u5E30\u7740\u3055\u308C\u308B\n\t\t\
    - \u4E00\u822C\u306E\u4F53\u3067\u306E\u884C\u5217\u7D2F\u4E57\u3092 O(N^3 + N\
    \ logN logK) \u3067\u3084\u308B\u3068\u304D\u306B\u3053\u308C\u306B\u5E30\u7740\
    \u3059\u308B\n\t\t\t\u884C\u5217 A \u306F \u3061\u3087\u3046\u3069\u4E00\u3064\
    \u306E\u30D5\u30ED\u30D9\u30CB\u30A6\u30B9\u6A19\u6E96\u5F62\u306B\u76F8\u4F3C\
    \ (B = QAQ^-1)\n\t\t\t\u30D5\u30ED\u30D9\u30CB\u30A6\u30B9\u6A19\u6E96\u5F62\u306F\
    \u3001(\u5BFE\u89D2)\u30D6\u30ED\u30C3\u30AF\u3054\u3068\u306B\u30B3\u30F3\u30D1\
    \u30CB\u30AA\u30F3\u884C\u5217\u3001\u307F\u305F\u3044\u306B\u306A\u3063\u3066\
    \u308B\n\t\t\thttps://codeforces.com/blog/entry/124815\n\t\t\thttps://github.com/hos-lyric/libra/blob/master/algebra/matrix_frobenius.cpp\n\
    \tverify:\n\t\tucup-3-6 E https://contest.ucup.ac/submission/518580\n\n*/\n\n\
    /*\n\tv_m -> v_{m+1}\n\tO(n)\n*/\nvoid shift(V<mint>& v, const V<mint>& c){\n\t\
    int n = c.size();\n\tmint vn = v[n-1];\n\tper1(i,n-1) v[i] = v[i-1];\n\tv[0] =\
    \ 0;\n\trep(i,n) v[i] += vn * c[i];\n}\n/*\n\tf = v_p, g = v_q\t-> v_{p+q}\n\t\
    O(n^2)\n*/\nV<mint> mul(const V<mint>& f, const V<mint>& g, const V<mint>& c){\n\
    \tint n = c.size();\n\tV<mint> h(n+n-1);\n\trep(i,n) rep(j,n) h[i+j] += f[i] *\
    \ g[j];\n\tfor(int k=n+n-2;k>=n;k--){\n\t\trep(i,n) h[k-n+i] += h[k] * c[i];\n\
    \t}\n\th.resize(n);\n\treturn h;\n}\n// v_m \u3092\u8FD4\u3059, O(n^2 log m)\n\
    V<mint> power_companion(const V<mint>& c, ll m){\n\tassert(m >= 0);\n\tint n =\
    \ c.size();\n\tif(m == 0){\n\t\tV<mint> f(n); f[0] = 1;\n\t\treturn f;\n\t}\n\t\
    auto f = power_companion(c, m/2);\n\tf = mul(f,f,c);\n\tif(m&1) shift(f,c);\n\t\
    return f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/power_companion.cpp
  requiredBy: []
  timestamp: '2024-09-05 20:37:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/power_companion.cpp
layout: document
redirect_from:
- /library/math/power_companion.cpp
- /library/math/power_companion.cpp.html
title: math/power_companion.cpp
---
