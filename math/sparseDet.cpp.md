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
    - https://qoj.ac/problem/5244
    - https://yukicoder.me/wiki/black_box_linear_algebra
  bundledCode: "#line 1 \"math/sparseDet.cpp\"\n/*\n\t\u5FC5\u8981:\n\t\tlinearRecurrence\
    \ (Berlekamp_massey.cpp)\n\t\trnd()\n\t\t\u3053\u3093\u306A\u306E\u66F8\u304F\u304F\
    \u3089\u3044\u306A\u3089\u3059\u3079\u3066\u3092include\u5F62\u5F0F\u306B\u3057\
    \u305F\u307B\u3046\u304C\u3044\u3044\u306E\u306F\u9593\u9055\u3044\u306A\u3044\
    \u3060\u308D\u3046\u306A\n\n\n\t\u884C\u5217\u306E\u6700\u5C0F\u591A\u9805\u5F0F\
    \ ( = \u7279\u6027\u591A\u9805\u5F0F\u306E\u91CD\u89E3\u3092\u6D88\u3057\u305F\
    \u3084\u3064)\n\tf[i] = c * A^i * v \u3068\u3044\u3046\u30B9\u30AB\u30E9\u30FC\
    \u306E\u5217\u306B\u3057\u3066\u304B\u3089 linearRecurrence \u3092\u6C42\u3081\
    \u308C\u3070\u826F\u3044\n\tsparse matrix \u306F {i,j,val} \u306E\u5F62\u3067\u6E21\
    \u3059 (i,j) \u304C unique \u3058\u3083\u306A\u304F\u3066\u3082\u3044\u3044\n\t\
    N\u306F\u884C\u5217\u306E\u30B5\u30A4\u30BA \u3068\u898B\u305B\u304B\u3051\u3066\
    \u6700\u5C0F\u591A\u9805\u5F0F\u306E\u6B21\u6570\u4EE5\u4E0A\u306A\u3089\u306A\
    \u3093\u3067\u3082\u3088\u3044\n\tO(N^2 + N * mat.size)\n\n\tverified: https://qoj.ac/problem/5244\n\
    */\ntemplate<class mint>\nvector<mint> sparseMinPoly(int N, vector<tuple<int,int,mint>>\
    \ mat){\n\tvector<mint> f(N+N+5);\n\tvector<mint> c(N),v(N);\n\trep(i,N) c[i]\
    \ = rnd<int>(mint::mod);\n\trep(i,N) v[i] = rnd<int>(mint::mod);\n\trep(k,N+N+5){\n\
    \t\trep(i,N) f[k] += c[i] * v[i];\n\t\tV<mint> vv(N);\n\t\tfor(auto&& [i,j,x]:\
    \ mat) vv[j] += x * v[i];\n\t\tv = vv;\n\t}\n\treturn linearRecurrence(f);\n}\n\
    \n/*\n\t\u758E\u884C\u5217\u306E\u884C\u5217\u5F0F\n\t(mod\u304C\u3067\u304B\u3051\
    \u308C\u3070) \u30E9\u30F3\u30C0\u30E0\u306A\u5BFE\u89D2\u884C\u5217\u3092\u304B\
    \u3051\u308B\u3068charpoly\u306B\u91CD\u89E3\u304C\u306A\u304F\u306A\u308B\u306E\
    \u3067\u3001minpoly\u3068\u4E00\u81F4\u3059\u308B\n\tN \u306F\u884C\u5217\u306E\
    \u30B5\u30A4\u30BA\n\tO(N^2 + N * mat.size)\n\thttps://yukicoder.me/wiki/black_box_linear_algebra\n\
    */\ntemplate<class mint>\nmint sparseDet(int N, vector<tuple<int,int,mint>> mat){\n\
    \tvector<mint> d(N,1); rep(i,N) d[i] = rnd<int>(1,mint::mod);\n\tfor(auto&& [i,j,x]:\
    \ mat) x *= d[i];\n\tauto f = sparseMinPoly(N,mat);\n\tshow(f);\n\tif(si(f) !=\
    \ N+1) return mint(0);\n\tmint det = f[0]/f[N];\n\tif(N&1) det *= -1;\n\trep(i,N)\
    \ det /= d[i];\n\tshow(det);\n\treturn det;\n}\ntemplate<class mint>\nmint sparseDet(VV<mint>\
    \ A){\n\tshow(A);\n\tint N = si(A);\n\tvector<tuple<int,int,mint>> mat;\n\trep(i,N)\
    \ rep(j,N) if(A[i][j]){\n\t\tmat.pb({i,j,A[i][j]});\n\t}\n\treturn sparseDet(N,mat);\n\
    }\n"
  code: "/*\n\t\u5FC5\u8981:\n\t\tlinearRecurrence (Berlekamp_massey.cpp)\n\t\trnd()\n\
    \t\t\u3053\u3093\u306A\u306E\u66F8\u304F\u304F\u3089\u3044\u306A\u3089\u3059\u3079\
    \u3066\u3092include\u5F62\u5F0F\u306B\u3057\u305F\u307B\u3046\u304C\u3044\u3044\
    \u306E\u306F\u9593\u9055\u3044\u306A\u3044\u3060\u308D\u3046\u306A\n\n\n\t\u884C\
    \u5217\u306E\u6700\u5C0F\u591A\u9805\u5F0F ( = \u7279\u6027\u591A\u9805\u5F0F\u306E\
    \u91CD\u89E3\u3092\u6D88\u3057\u305F\u3084\u3064)\n\tf[i] = c * A^i * v \u3068\
    \u3044\u3046\u30B9\u30AB\u30E9\u30FC\u306E\u5217\u306B\u3057\u3066\u304B\u3089\
    \ linearRecurrence \u3092\u6C42\u3081\u308C\u3070\u826F\u3044\n\tsparse matrix\
    \ \u306F {i,j,val} \u306E\u5F62\u3067\u6E21\u3059 (i,j) \u304C unique \u3058\u3083\
    \u306A\u304F\u3066\u3082\u3044\u3044\n\tN\u306F\u884C\u5217\u306E\u30B5\u30A4\u30BA\
    \ \u3068\u898B\u305B\u304B\u3051\u3066\u6700\u5C0F\u591A\u9805\u5F0F\u306E\u6B21\
    \u6570\u4EE5\u4E0A\u306A\u3089\u306A\u3093\u3067\u3082\u3088\u3044\n\tO(N^2 +\
    \ N * mat.size)\n\n\tverified: https://qoj.ac/problem/5244\n*/\ntemplate<class\
    \ mint>\nvector<mint> sparseMinPoly(int N, vector<tuple<int,int,mint>> mat){\n\
    \tvector<mint> f(N+N+5);\n\tvector<mint> c(N),v(N);\n\trep(i,N) c[i] = rnd<int>(mint::mod);\n\
    \trep(i,N) v[i] = rnd<int>(mint::mod);\n\trep(k,N+N+5){\n\t\trep(i,N) f[k] +=\
    \ c[i] * v[i];\n\t\tV<mint> vv(N);\n\t\tfor(auto&& [i,j,x]: mat) vv[j] += x *\
    \ v[i];\n\t\tv = vv;\n\t}\n\treturn linearRecurrence(f);\n}\n\n/*\n\t\u758E\u884C\
    \u5217\u306E\u884C\u5217\u5F0F\n\t(mod\u304C\u3067\u304B\u3051\u308C\u3070) \u30E9\
    \u30F3\u30C0\u30E0\u306A\u5BFE\u89D2\u884C\u5217\u3092\u304B\u3051\u308B\u3068\
    charpoly\u306B\u91CD\u89E3\u304C\u306A\u304F\u306A\u308B\u306E\u3067\u3001minpoly\u3068\
    \u4E00\u81F4\u3059\u308B\n\tN \u306F\u884C\u5217\u306E\u30B5\u30A4\u30BA\n\tO(N^2\
    \ + N * mat.size)\n\thttps://yukicoder.me/wiki/black_box_linear_algebra\n*/\n\
    template<class mint>\nmint sparseDet(int N, vector<tuple<int,int,mint>> mat){\n\
    \tvector<mint> d(N,1); rep(i,N) d[i] = rnd<int>(1,mint::mod);\n\tfor(auto&& [i,j,x]:\
    \ mat) x *= d[i];\n\tauto f = sparseMinPoly(N,mat);\n\tshow(f);\n\tif(si(f) !=\
    \ N+1) return mint(0);\n\tmint det = f[0]/f[N];\n\tif(N&1) det *= -1;\n\trep(i,N)\
    \ det /= d[i];\n\tshow(det);\n\treturn det;\n}\ntemplate<class mint>\nmint sparseDet(VV<mint>\
    \ A){\n\tshow(A);\n\tint N = si(A);\n\tvector<tuple<int,int,mint>> mat;\n\trep(i,N)\
    \ rep(j,N) if(A[i][j]){\n\t\tmat.pb({i,j,A[i][j]});\n\t}\n\treturn sparseDet(N,mat);\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/sparseDet.cpp
  requiredBy: []
  timestamp: '2023-11-14 00:07:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/sparseDet.cpp
layout: document
redirect_from:
- /library/math/sparseDet.cpp
- /library/math/sparseDet.cpp.html
title: math/sparseDet.cpp
---
