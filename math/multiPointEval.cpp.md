---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/multiPointEval.cpp\"\n/*\n    f: N\u6B21\u591A\u9805\
    \u5F0F\n    a_1,..,a_Q : \u5024 \u306E\u3068\u304D\u306B\u3001\n    f(a_i) \u3092\
    \u3059\u3079\u3066\u6C42\u3081\u308B O( NlogN + Qlog^2(Q) )\n\n    f % (x-a)(x-b)(x-c)(x-d)\
    \ % (x-c)(x-d) % (x-c) \u307F\u305F\u3044\u306A\u611F\u3058\u3067\u518D\u5E30\u3059\
    \u308B\u3060\u3051\n\n    \u3068\u601D\u3044\u304D\u3084\u672C\u8CEA\u306F\u9014\
    \u4E2D\u304B\u3089\u611A\u76F4\u306B\u4EE3\u5165\u3057\u3066\u8A08\u7B97\u3059\
    \u308B\u3053\u3068\u3060\u3063\u305F\u3001\n    d\u6B21\u307E\u3067\u6E1B\u3089\
    \u3059\u3068\u305D\u3063\u304B\u3089\u306F\u5168\u4F53\u3067 O(dQ) \u3067\u3001\
    fft/ntt \u304C\u5C0F\u3055\u3044 n \u3067\u9045\u3044\u3053\u3068\u3092\u8003\u3048\
    \u308B\u3068\n    O(dQ) \u304C TL \u3092\u8A31\u3059\u9650\u308A d \u3092\u5897\
    \u3084\u3059\u306E\u304C\u3044\u3044\u6C17\u304C\u3059\u308B\n\n    ntt \u3067\
    \ N = 10^5 \u306E\u3068\u304D\u306F 1024 \u304C\u6700\u5584\u3067\u3057\u305F\
    \ (2500ms -O3)\n\n    verified at Petrozavodsk(19w)/1/I\n*/\nusing P = pair<int,int>;\n\
    map<pair<int,int>,Poly<mint>> qs;\nPoly<mint> calcq(int l,int r,V<mint>& a){\n\
    \tif(r-l==1){\n\t\treturn qs[P(l,r)] = Poly<mint>(V<mint>{-a[l],1});\n\t}\n\t\
    return qs[P(l,r)] = calcq(l,(l+r)/2,a) * calcq((l+r)/2,r,a);\n}\nvoid calc(int\
    \ l,int r,Poly<mint> f, V<mint>& a, V<mint>& res){\n\tf %= qs[P(l,r)];\n\tif(r-l<=1024){\n\
    \t\tfor(int i=l;i<r;i++) res[i] = f.eval(a[i]);\n\t\treturn;\n\t}\n\tcalc(l,(l+r)/2,f,a,res);\n\
    \tcalc((l+r)/2,r,f,a,res);\n}\nV<mint> multiPointEval(Poly<mint>& f,V<mint> a){\
    \    //return {f(a_i)}\n    int N = a.size();\n\tV<mint> res(N);\n\tcalcq(0,N,a);\n\
    \tcalc(0,N,f,a,res);\n\treturn res;\n}\n"
  code: "/*\n    f: N\u6B21\u591A\u9805\u5F0F\n    a_1,..,a_Q : \u5024 \u306E\u3068\
    \u304D\u306B\u3001\n    f(a_i) \u3092\u3059\u3079\u3066\u6C42\u3081\u308B O( NlogN\
    \ + Qlog^2(Q) )\n\n    f % (x-a)(x-b)(x-c)(x-d) % (x-c)(x-d) % (x-c) \u307F\u305F\
    \u3044\u306A\u611F\u3058\u3067\u518D\u5E30\u3059\u308B\u3060\u3051\n\n    \u3068\
    \u601D\u3044\u304D\u3084\u672C\u8CEA\u306F\u9014\u4E2D\u304B\u3089\u611A\u76F4\
    \u306B\u4EE3\u5165\u3057\u3066\u8A08\u7B97\u3059\u308B\u3053\u3068\u3060\u3063\
    \u305F\u3001\n    d\u6B21\u307E\u3067\u6E1B\u3089\u3059\u3068\u305D\u3063\u304B\
    \u3089\u306F\u5168\u4F53\u3067 O(dQ) \u3067\u3001fft/ntt \u304C\u5C0F\u3055\u3044\
    \ n \u3067\u9045\u3044\u3053\u3068\u3092\u8003\u3048\u308B\u3068\n    O(dQ) \u304C\
    \ TL \u3092\u8A31\u3059\u9650\u308A d \u3092\u5897\u3084\u3059\u306E\u304C\u3044\
    \u3044\u6C17\u304C\u3059\u308B\n\n    ntt \u3067 N = 10^5 \u306E\u3068\u304D\u306F\
    \ 1024 \u304C\u6700\u5584\u3067\u3057\u305F (2500ms -O3)\n\n    verified at Petrozavodsk(19w)/1/I\n\
    */\nusing P = pair<int,int>;\nmap<pair<int,int>,Poly<mint>> qs;\nPoly<mint> calcq(int\
    \ l,int r,V<mint>& a){\n\tif(r-l==1){\n\t\treturn qs[P(l,r)] = Poly<mint>(V<mint>{-a[l],1});\n\
    \t}\n\treturn qs[P(l,r)] = calcq(l,(l+r)/2,a) * calcq((l+r)/2,r,a);\n}\nvoid calc(int\
    \ l,int r,Poly<mint> f, V<mint>& a, V<mint>& res){\n\tf %= qs[P(l,r)];\n\tif(r-l<=1024){\n\
    \t\tfor(int i=l;i<r;i++) res[i] = f.eval(a[i]);\n\t\treturn;\n\t}\n\tcalc(l,(l+r)/2,f,a,res);\n\
    \tcalc((l+r)/2,r,f,a,res);\n}\nV<mint> multiPointEval(Poly<mint>& f,V<mint> a){\
    \    //return {f(a_i)}\n    int N = a.size();\n\tV<mint> res(N);\n\tcalcq(0,N,a);\n\
    \tcalc(0,N,f,a,res);\n\treturn res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/multiPointEval.cpp
  requiredBy: []
  timestamp: '2019-02-01 16:59:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/multiPointEval.cpp
layout: document
redirect_from:
- /library/math/multiPointEval.cpp
- /library/math/multiPointEval.cpp.html
title: math/multiPointEval.cpp
---
