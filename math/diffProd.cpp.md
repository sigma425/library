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
  bundledCode: "#line 1 \"math/diffProd.cpp\"\n/*\n\t\u5DEE\u7A4D \\prod_{i<j} (A_j-A_i)\n\
    \n\tO(Nlog^2N) MultipointEval \u304C\u3044\u308B\n\n\tf_0 := 1, f_1 := (x-A_0),\
    \ .. , f_N := (x-A_0)..(x-A_{N-1}) \u3068\u3057\u3066\n\tans = \\prod_{i} f_i(A_i)\n\
    \n\tN = 100000 \u3067 3s \u9045\u3059\u304E\n\t\u4FFA\u306E MultiPointEval \u304C\
    \u305D\u3082\u305D\u3082 1s \u304F\u3089\u3044\u3060\u304B\u3089\u306D\n*/\nmint\
    \ diffProd(V<mint> A){\n\tint N = si(A);\n\tint s = 1, h = 0; while(s < N) {s\
    \ *= 2; h++;}\n\tV<Poly<mint>> g(s+s,{1});\n\trep(i,N) g[s+i] = {-A[i],1};\n\t\
    for(int i=s-1;i>0;i--) g[i] = g[i*2] * g[i*2+1];\n\tmint res = 1;\n\trep(k,h+1){\n\
    \t\trep(i,1<<k) if(!(i&1)){\n\t\t\tint y = (i+1)<<(h-k), z = (i+2)<<(h-k);\n\t\
    \t\tV<mint> ps;\n\t\t\tfor(int p=y;p<min(z,N);p++) ps.eb(A[p]);\n\t\t\tint id\
    \ = (1<<k)+i;\n\t\t\tauto qs = MultipointEval<mint>(g[id],ps);\n\t\t\tfor(auto\
    \ q: qs) res *= q;\n\t\t}\n\t}\n\treturn res;\n}\nmint diffProdBrute(V<mint> A){\n\
    \tint N = si(A);\n\tmint res = 1;\n\trep(j,N) rep(i,j) res *= A[j]-A[i];\n\treturn\
    \ res;\n}\n\nvoid diffProdTest(){\n\trep(N,17){\n\t\trep(t,100){\n\t\t\tV<mint>\
    \ A(N);\n\t\t\trep(i,N) A[i] = rnd(201)-100;\n\t\t\tassert(diffProd(A) == diffProdBrute(A));\n\
    \t\t}\n\t}\n\tcerr << \"diffProdTest: passed\" << endl;\n}\n"
  code: "/*\n\t\u5DEE\u7A4D \\prod_{i<j} (A_j-A_i)\n\n\tO(Nlog^2N) MultipointEval\
    \ \u304C\u3044\u308B\n\n\tf_0 := 1, f_1 := (x-A_0), .. , f_N := (x-A_0)..(x-A_{N-1})\
    \ \u3068\u3057\u3066\n\tans = \\prod_{i} f_i(A_i)\n\n\tN = 100000 \u3067 3s \u9045\
    \u3059\u304E\n\t\u4FFA\u306E MultiPointEval \u304C\u305D\u3082\u305D\u3082 1s\
    \ \u304F\u3089\u3044\u3060\u304B\u3089\u306D\n*/\nmint diffProd(V<mint> A){\n\t\
    int N = si(A);\n\tint s = 1, h = 0; while(s < N) {s *= 2; h++;}\n\tV<Poly<mint>>\
    \ g(s+s,{1});\n\trep(i,N) g[s+i] = {-A[i],1};\n\tfor(int i=s-1;i>0;i--) g[i] =\
    \ g[i*2] * g[i*2+1];\n\tmint res = 1;\n\trep(k,h+1){\n\t\trep(i,1<<k) if(!(i&1)){\n\
    \t\t\tint y = (i+1)<<(h-k), z = (i+2)<<(h-k);\n\t\t\tV<mint> ps;\n\t\t\tfor(int\
    \ p=y;p<min(z,N);p++) ps.eb(A[p]);\n\t\t\tint id = (1<<k)+i;\n\t\t\tauto qs =\
    \ MultipointEval<mint>(g[id],ps);\n\t\t\tfor(auto q: qs) res *= q;\n\t\t}\n\t\
    }\n\treturn res;\n}\nmint diffProdBrute(V<mint> A){\n\tint N = si(A);\n\tmint\
    \ res = 1;\n\trep(j,N) rep(i,j) res *= A[j]-A[i];\n\treturn res;\n}\n\nvoid diffProdTest(){\n\
    \trep(N,17){\n\t\trep(t,100){\n\t\t\tV<mint> A(N);\n\t\t\trep(i,N) A[i] = rnd(201)-100;\n\
    \t\t\tassert(diffProd(A) == diffProdBrute(A));\n\t\t}\n\t}\n\tcerr << \"diffProdTest:\
    \ passed\" << endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/diffProd.cpp
  requiredBy: []
  timestamp: '2023-12-03 19:00:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/diffProd.cpp
layout: document
redirect_from:
- /library/math/diffProd.cpp
- /library/math/diffProd.cpp.html
title: math/diffProd.cpp
---
