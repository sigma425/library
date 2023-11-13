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
    - https://paper.dropbox.com/doc/Tellegen--B14rtYTHEo3_HNE_alGHKuF~Ag-rfmOzvP8OswA8Vug7Dn5H
  bundledCode: "#line 1 \"math/Tellegen.cpp\"\n/*\n\tTellegen \u8EE2\u7F6E\n\thttps://paper.dropbox.com/doc/Tellegen--B14rtYTHEo3_HNE_alGHKuF~Ag-rfmOzvP8OswA8Vug7Dn5H\n\
    \n\tFFT -> FFT\n\tiFFT -> iFFT\n\t *= f -> middle product\n\t multieval -> \\\
    sum_j b_j/(1-a_jx)\n\t \u306A\u3069\n*/\n\n\n/*\n\tMultipointEval\n\t\tfix : x_0\
    \ , .. , x_{n-1}\tn \u70B9\n\t\tin : a_0 , .. , a_d\t\t\td \u6B21\u5F0F\n\t\t\
    out : b_0 , .. , b_{n-1}\tn \u70B9\n\t\t\tb_i = a(x_i)\n\t\u306E\u8EE2\u7F6E\n\
    \t\tfix : x_0 , .. , x_{n-1}\tn \u70B9\n\t\tin : p_0 , .. , p_{n-1}\t\tn \u70B9\
    \n\t\tout : q_0 , .. , q_d\t\td \u6B21\u5F0F\n\t\t\tq(y) = \\sum_j p_j/(1 - x_j\
    \ y) \u3092 d \u6B21\u307E\u3067\u3068\u3063\u305F\u3082\u306E\n*/\nV<mint> TransposedMultipointEval(V<mint>\
    \ p, V<mint> x, int d){\n\tusing poly = Poly<mint>;\n\tassert(si(p) == si(x));\n\
    \tint n = si(p);\n\tauto rec = [&](auto&& self, int l, int r) -> pair<poly,poly>\
    \ {\n\t\tif(r-l == 1){\n\t\t\treturn make_pair(poly({p[l]}),poly({1,-x[l]}));\n\
    \t\t}\n\t\tint m = (l+r)/2;\n\t\tauto fl = self(self,l,m);\n\t\tauto fr = self(self,m,r);\n\
    \t\tpoly numer = fl.fs * fr.sc + fr.fs * fl.sc;\n\t\tpoly denom = fl.sc * fr.sc;\n\
    \t\treturn make_pair(numer,denom);\n\t};\n\tauto f = rec(rec,0,n);\n\treturn (f.fs\
    \ * f.sc.inv(d+1)).low(d+1);\n}\n\n/*\n\t\u591A\u9805\u5F0F\u306E\u7A4D ( *= f)\n\
    \t\tfix: f_0 , .. , f_d\t\t\td \u6B21\u5F0F\n\t\tin: a_0 , .. , a_n\t\t\tn \u6B21\
    \u5F0F\n\t\tout: b_0 , .. , b_{n+d}\t\tn+d \u6B21\u5F0F\n\t\t\tb = a*f\n\t\u8EE2\
    \u7F6E (middle product)\n\t\tfix: f_0 , .. , f_d\t\t\td \u6B21\u5F0F\n\t\tin:\
    \ p_0 , .. , p_{n+d}\t\tn+d \u6B21\u5F0F\n\t\tout: q_0 , .. , q_n\t\t\tn \u6B21\
    \u5F0F\n\t\t\tq = rev(f) * p \u306E [d,n+d] \u6B21\u3092\u53D6\u308A\u51FA\u3057\
    \u305F\u3082\u306E\n\t\tnote :\n\t\t\t\u4F8B\u3048\u3070 p \u3082 n \u6B21\u307E\
    \u3067\u3057\u304B\u8003\u3048\u306A\u3044\u5834\u5408(\u3064\u307E\u308Ap_{n+1}\
    \ \u4EE5\u964D\u3092\u6368\u3066\u308B\u5834\u5408)\u3001\u305D\u3053\u30920\u3067\
    \u57CB\u3081\u305F\u3068\u601D\u3048\u3070\u3088\u3044\n\t\t\t(\u5024\u3092\u6368\
    \u3066\u308B\u5834\u5408 \u3092\u53C2\u8003)\n*/\nV<mint> MiddleProduct(V<mint>\
    \ p, V<mint> f, int n, int d){\n\tassert(si(f) == d+1);\n\tassert(si(p) == n+d+1);\n\
    \treverse(all(f));\n\tauto z = multiply(f,p);\n\tV<mint> q(n+1); rep(i,n+1) q[i]\
    \ = z.at(d+i);\n\treturn q;\n}\n\n/*\n\t\u9806\u554F\u984C\n\t\tin: p_0 , .. ,\
    \ p_{n-1}\n\t\tout: q_0, .. , q_n\n\t\t\tp_0(x+b_0) + p_1(x+b_0)(x+b_1) + .. +\
    \ p_{n-1}(x+b_0)..(x+b_{n-1})\n\t\t\t\u306E [0,n] \u6B21\n*/\nV<mint> solve2(V<mint>\
    \ q, V<mint> b, int n){\n\tassert(si(q) == n+1);\n\tassert(si(b) == n);\n\tV<mint>\
    \ p(n);\n\tauto rec = [&](auto&& self, int l, int r, V<mint> f) -> V<mint> {\n\
    \t\tassert(si(f) == r-l+1);\n\t\tif(r-l == 1){\n\t\t\tp[l] = f[0] * b[l] + f[1];\n\
    \t\t\treturn {b[l],1};\n\t\t}\n\t\tint m = (l+r)/2;\n\t\tV<mint> fl,fr;\n\t\t\
    fl = V<mint>(f.begin(),f.begin()+m-l+1);\n\t\tauto zl = self(self,l,m,fl);\n\t\
    \tfr = MiddleProduct(f,zl,r-m,m-l);\n\t\tauto zr = self(self,m,r,fr);\n\t\treturn\
    \ multiply(zl,zr);\n\t};\n\trec(rec,0,n,q);\n\treturn p;\n}\n"
  code: "/*\n\tTellegen \u8EE2\u7F6E\n\thttps://paper.dropbox.com/doc/Tellegen--B14rtYTHEo3_HNE_alGHKuF~Ag-rfmOzvP8OswA8Vug7Dn5H\n\
    \n\tFFT -> FFT\n\tiFFT -> iFFT\n\t *= f -> middle product\n\t multieval -> \\\
    sum_j b_j/(1-a_jx)\n\t \u306A\u3069\n*/\n\n\n/*\n\tMultipointEval\n\t\tfix : x_0\
    \ , .. , x_{n-1}\tn \u70B9\n\t\tin : a_0 , .. , a_d\t\t\td \u6B21\u5F0F\n\t\t\
    out : b_0 , .. , b_{n-1}\tn \u70B9\n\t\t\tb_i = a(x_i)\n\t\u306E\u8EE2\u7F6E\n\
    \t\tfix : x_0 , .. , x_{n-1}\tn \u70B9\n\t\tin : p_0 , .. , p_{n-1}\t\tn \u70B9\
    \n\t\tout : q_0 , .. , q_d\t\td \u6B21\u5F0F\n\t\t\tq(y) = \\sum_j p_j/(1 - x_j\
    \ y) \u3092 d \u6B21\u307E\u3067\u3068\u3063\u305F\u3082\u306E\n*/\nV<mint> TransposedMultipointEval(V<mint>\
    \ p, V<mint> x, int d){\n\tusing poly = Poly<mint>;\n\tassert(si(p) == si(x));\n\
    \tint n = si(p);\n\tauto rec = [&](auto&& self, int l, int r) -> pair<poly,poly>\
    \ {\n\t\tif(r-l == 1){\n\t\t\treturn make_pair(poly({p[l]}),poly({1,-x[l]}));\n\
    \t\t}\n\t\tint m = (l+r)/2;\n\t\tauto fl = self(self,l,m);\n\t\tauto fr = self(self,m,r);\n\
    \t\tpoly numer = fl.fs * fr.sc + fr.fs * fl.sc;\n\t\tpoly denom = fl.sc * fr.sc;\n\
    \t\treturn make_pair(numer,denom);\n\t};\n\tauto f = rec(rec,0,n);\n\treturn (f.fs\
    \ * f.sc.inv(d+1)).low(d+1);\n}\n\n/*\n\t\u591A\u9805\u5F0F\u306E\u7A4D ( *= f)\n\
    \t\tfix: f_0 , .. , f_d\t\t\td \u6B21\u5F0F\n\t\tin: a_0 , .. , a_n\t\t\tn \u6B21\
    \u5F0F\n\t\tout: b_0 , .. , b_{n+d}\t\tn+d \u6B21\u5F0F\n\t\t\tb = a*f\n\t\u8EE2\
    \u7F6E (middle product)\n\t\tfix: f_0 , .. , f_d\t\t\td \u6B21\u5F0F\n\t\tin:\
    \ p_0 , .. , p_{n+d}\t\tn+d \u6B21\u5F0F\n\t\tout: q_0 , .. , q_n\t\t\tn \u6B21\
    \u5F0F\n\t\t\tq = rev(f) * p \u306E [d,n+d] \u6B21\u3092\u53D6\u308A\u51FA\u3057\
    \u305F\u3082\u306E\n\t\tnote :\n\t\t\t\u4F8B\u3048\u3070 p \u3082 n \u6B21\u307E\
    \u3067\u3057\u304B\u8003\u3048\u306A\u3044\u5834\u5408(\u3064\u307E\u308Ap_{n+1}\
    \ \u4EE5\u964D\u3092\u6368\u3066\u308B\u5834\u5408)\u3001\u305D\u3053\u30920\u3067\
    \u57CB\u3081\u305F\u3068\u601D\u3048\u3070\u3088\u3044\n\t\t\t(\u5024\u3092\u6368\
    \u3066\u308B\u5834\u5408 \u3092\u53C2\u8003)\n*/\nV<mint> MiddleProduct(V<mint>\
    \ p, V<mint> f, int n, int d){\n\tassert(si(f) == d+1);\n\tassert(si(p) == n+d+1);\n\
    \treverse(all(f));\n\tauto z = multiply(f,p);\n\tV<mint> q(n+1); rep(i,n+1) q[i]\
    \ = z.at(d+i);\n\treturn q;\n}\n\n/*\n\t\u9806\u554F\u984C\n\t\tin: p_0 , .. ,\
    \ p_{n-1}\n\t\tout: q_0, .. , q_n\n\t\t\tp_0(x+b_0) + p_1(x+b_0)(x+b_1) + .. +\
    \ p_{n-1}(x+b_0)..(x+b_{n-1})\n\t\t\t\u306E [0,n] \u6B21\n*/\nV<mint> solve2(V<mint>\
    \ q, V<mint> b, int n){\n\tassert(si(q) == n+1);\n\tassert(si(b) == n);\n\tV<mint>\
    \ p(n);\n\tauto rec = [&](auto&& self, int l, int r, V<mint> f) -> V<mint> {\n\
    \t\tassert(si(f) == r-l+1);\n\t\tif(r-l == 1){\n\t\t\tp[l] = f[0] * b[l] + f[1];\n\
    \t\t\treturn {b[l],1};\n\t\t}\n\t\tint m = (l+r)/2;\n\t\tV<mint> fl,fr;\n\t\t\
    fl = V<mint>(f.begin(),f.begin()+m-l+1);\n\t\tauto zl = self(self,l,m,fl);\n\t\
    \tfr = MiddleProduct(f,zl,r-m,m-l);\n\t\tauto zr = self(self,m,r,fr);\n\t\treturn\
    \ multiply(zl,zr);\n\t};\n\trec(rec,0,n,q);\n\treturn p;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/Tellegen.cpp
  requiredBy: []
  timestamp: '2023-11-14 00:07:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Tellegen.cpp
layout: document
redirect_from:
- /library/math/Tellegen.cpp
- /library/math/Tellegen.cpp.html
title: math/Tellegen.cpp
---
