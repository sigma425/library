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
  bundledCode: "#line 1 \"math/interpolation_simple.cpp\"\n/*\n\tnote: mod 998 \u3067\
    \u9AD8\u901F\u306B\u591A\u9805\u5F0F\u81EA\u4F53\u306E\u5FA9\u5143\u3092\u3057\
    \u305F\u3044\u6642\u306F poly.cpp \u3092\u53C2\u7167\uFF01\uFF01 O(Nlog^2N)\n\n\
    \t\u591A\u9805\u5F0F\u88DC\u9593\n\tLagrange interpolation\n\tO(N^2)\n\tN\u70B9\
    (xs[i],ys[i])\u304C\u4E0E\u3048\u3089\u308C\u305F\u6642\u306B\u305D\u308C\u3092\
    \u901A\u308BN-1\u6B21\u591A\u9805\u5F0F\u306Ex\u3067\u306E\u5024\u3092\u8FD4\u3059\
    \n\txs[i]\u304Cpairwise distinct\u3058\u3083\u306A\u3044\u3068\u30C0\u30E1\n\n\
    */\n\ntemplate<class T>\nT interpolate(V<T> xs, V<T> ys, T x){\n\tint N = xs.size();\n\
    \tT res = 0;\n\trep(i,N){\n\t\tT a = ys[i];\n\t\trep(j,N) if(j!=i) a *= (x-xs[j])\
    \ / (xs[i]-xs[j]);\n\t\tres += a;\n\t}\n\treturn res;\n}\n\n// O(N^2)\n// verified:\
    \ XXI GP of Tokyo A\ntemplate<class T>\nV<T> interpolate(V<T> xs,V<T> ys){\n\t\
    int N = xs.size();\n\tV<T> p(N+1); p[0] = 1; // \\prod_i (x-xs[i])\n\trep(i,N){\n\
    \t\tper(j,i+1){\n\t\t\tp[j+1] += p[j];\n\t\t\tp[j] *= -xs[i];\n\t\t}\n\t}\n\t\
    V<T> res(N);\n\trep(i,N){\n\t\t// w_i := ys[i] / \\prod_j(\\neq i) (xs[i]-xs[j])\n\
    \t\tT w = 1;\n\t\trep(j,N) if(j!=i) w *= (xs[i]-xs[j]);\n\t\tw = ys[i] / w;\n\t\
    \t// add w_i * p/(x-xs[i])\n\t\tT v = 1;\n\t\tper(j,N){\n\t\t\tres[j] += v * w;\n\
    \t\t\tv = p[j] + v * xs[i];\n\t\t}\n\t}\n\treturn res;\n}\n"
  code: "/*\n\tnote: mod 998 \u3067\u9AD8\u901F\u306B\u591A\u9805\u5F0F\u81EA\u4F53\
    \u306E\u5FA9\u5143\u3092\u3057\u305F\u3044\u6642\u306F poly.cpp \u3092\u53C2\u7167\
    \uFF01\uFF01 O(Nlog^2N)\n\n\t\u591A\u9805\u5F0F\u88DC\u9593\n\tLagrange interpolation\n\
    \tO(N^2)\n\tN\u70B9(xs[i],ys[i])\u304C\u4E0E\u3048\u3089\u308C\u305F\u6642\u306B\
    \u305D\u308C\u3092\u901A\u308BN-1\u6B21\u591A\u9805\u5F0F\u306Ex\u3067\u306E\u5024\
    \u3092\u8FD4\u3059\n\txs[i]\u304Cpairwise distinct\u3058\u3083\u306A\u3044\u3068\
    \u30C0\u30E1\n\n*/\n\ntemplate<class T>\nT interpolate(V<T> xs, V<T> ys, T x){\n\
    \tint N = xs.size();\n\tT res = 0;\n\trep(i,N){\n\t\tT a = ys[i];\n\t\trep(j,N)\
    \ if(j!=i) a *= (x-xs[j]) / (xs[i]-xs[j]);\n\t\tres += a;\n\t}\n\treturn res;\n\
    }\n\n// O(N^2)\n// verified: XXI GP of Tokyo A\ntemplate<class T>\nV<T> interpolate(V<T>\
    \ xs,V<T> ys){\n\tint N = xs.size();\n\tV<T> p(N+1); p[0] = 1; // \\prod_i (x-xs[i])\n\
    \trep(i,N){\n\t\tper(j,i+1){\n\t\t\tp[j+1] += p[j];\n\t\t\tp[j] *= -xs[i];\n\t\
    \t}\n\t}\n\tV<T> res(N);\n\trep(i,N){\n\t\t// w_i := ys[i] / \\prod_j(\\neq i)\
    \ (xs[i]-xs[j])\n\t\tT w = 1;\n\t\trep(j,N) if(j!=i) w *= (xs[i]-xs[j]);\n\t\t\
    w = ys[i] / w;\n\t\t// add w_i * p/(x-xs[i])\n\t\tT v = 1;\n\t\tper(j,N){\n\t\t\
    \tres[j] += v * w;\n\t\t\tv = p[j] + v * xs[i];\n\t\t}\n\t}\n\treturn res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/interpolation_simple.cpp
  requiredBy: []
  timestamp: '2024-01-04 00:07:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/interpolation_simple.cpp
layout: document
redirect_from:
- /library/math/interpolation_simple.cpp
- /library/math/interpolation_simple.cpp.html
title: math/interpolation_simple.cpp
---
