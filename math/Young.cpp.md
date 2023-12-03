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
    - https://codeforces.com/gym/102220/problem/I
  bundledCode: "#line 1 \"math/Young.cpp\"\n// \u6A2An, \u9AD8\u3055a[0],..,a[n-1]\
    \ \u306E\u30E4\u30F3\u30B0\u56F3\u5F62\u4E0A\u3067 (0,0) \u304B\u3089 (n,0),..,(n,a[n-1])\
    \ \u3078\u306E\u7D4C\u8DEF\u6570\n// a \u4EE5\u4E0B\u306E increasing sequence\
    \ \u3068\u8A00\u3063\u3066\u3082\u3044\u3044\n// O(N log^2 N) \u305F\u3060\u3057\
    \ N = n + a[n-1]\n// multiply \u304C\u3044\u308B InitFact(N) \u3092\u547C\u3073\
    \u51FA\u3059\u306E\u3092\u5FD8\u308C\u306A\u3044\u3053\u3068\n// n >= 1, a: non-decreasing\
    \ >= 0\n// verify: https://codeforces.com/gym/102220/problem/I\n\nV<mint> CountYoungPaths(V<int>\
    \ a,int h = -1){\n\tassert(!a.empty());\n\tif(h == -1) h = a.back();\n\tauto parallel\
    \ = [&](V<mint> x, int w){\n\t\tint h = si(x)-1;\n\t\tV<mint> f(h+1);\n\t\trep(i,h+1)\
    \ f[i] = Choose(w+i,w);\n\t\tauto g = multiply(x,f); g.resize(h+1);\n\t\treturn\
    \ g;\n\t};\n\tauto vertical = [&](V<mint> x, int w){\n\t\tint h = si(x)-1;\n\t\
    \trep(i,h+1) x[i] *= ifact[h-i];\n\t\tV<mint> f(h+w+1); rep(i,h+w+1) f[i] = fact[i];\n\
    \t\tauto g = multiply(x,f); g.resize(h+1);\n\t\tV<mint> res(w+1);\n\t\trep(i,w+1)\
    \ res[i] = g[h+i] * ifact[i];\n\t\treturn res;\t\n\t};\n\n\t// \u6A2An, \u9AD8\
    \u3055a[0],..,a[n-1] \u306E\u30E4\u30F3\u30B0\u56F3\u5F62\u304C\u3042\u308B\n\t\
    // for 0<=j<=a[n-1], res[j] = \\sum_{0<=i<=n} [ (i,0) \u304B\u3089 (n,j) \u307E\
    \u3067\u884C\u304F\u901A\u308A\u6570 ] * s[i]\n\t// \u30E4\u30F3\u30B0\u56F3\u5F62\
    \u306E\u4E0B\u3068\u53F3\u306B\u3072\u3052\u304C\u751F\u3048\u3066\u3066\u3001\
    \u305D\u3053\u304Cin/out\u3060\u3068\u601D\u3046\u3068\u308F\u304B\u308A\u3084\
    \u3059\u3044\u304B\u3082\uFF1F\n\t// h \u306F a[n-1] \u3088\u308A\u5927\u304D\u3044\
    \u304B\u3082\u3057\u308C\u306A\u3044\n\t// \u304A\u6C17\u6301\u3061 \u2192 s:\
    \ \u7D2F\u7A4D\u524D res: \u7D2F\u7A4D\u5F8C\n\t// \u3053\u3063\u3061\u3092\u5916\
    \u304B\u3089\u76F4\u63A5\u547C\u3073\u51FA\u3057\u305F\u3044\u3053\u3068\u3082\
    \u3042\u308B\u6C17\u304C\u3059\u308B\u306D(\u4E0B\u306E\u5024\u305F\u3061s\u304C\
    \u4E0E\u3048\u3089\u308C\u3066\u308B\u3068\u304D\u3068\u304B)\n\tauto rec = [&](auto&\
    \ self, V<int> a, int h, V<mint> s) -> V<mint> {\n\t\tassert(si(a)+1 == si(s));\n\
    \t\tint n = si(a);\n\t\tif(n <= 1 || h <= 1){\n\t\t\tV<mint> res(h+1);\n\t\t\t\
    a.pb(h);\n\t\t\trep(i,n+1){\n\t\t\t\tres[0] += s[i];\n\t\t\t\trep(j,a[i]) res[j+1]\
    \ += res[j];\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n\t\tint m = n/2;\n\t\tauto le\
    \ = self(self,V<int>(a.begin(),a.begin()+m),a[m],V<mint>(s.begin(),s.begin()+m+1));\n\
    \t\tV<mint> dw(s.begin()+m+1,s.end());\n\t\tV<mint> res(h+1);\n\t\tV<mint> up(n-m);\n\
    \t\t{\n\t\t\tauto le2ri = parallel(le,n-m-1);\n\t\t\trep(i,si(le2ri)) res[i] +=\
    \ le2ri[i];\n\t\t}\n\t\t{\n\t\t\tauto le2up = vertical(le,n-m-1);\n\t\t\trep(i,si(le2up))\
    \ up[i] += le2up[i];\n\t\t}\n\t\t{\n\t\t\tauto dw2ri = vertical(dw,a[m]);\n\t\t\
    \trep(i,si(dw2ri)) res[i] += dw2ri[i];\n\t\t}\n\t\t{\n\t\t\tauto dw2up = parallel(dw,a[m]);\n\
    \t\t\trep(i,si(dw2up)) up[i] += dw2up[i];\n\t\t}\n\t\tV<int> na(a.begin()+m+1,a.end());\
    \ for(int& v: na) v -= a[m];\n\t\tper(i,n-m-1) up[i+1] -= up[i];\n\t\tauto ur\
    \ = self(self,na,h-a[m],up);\n\t\trep1(i,si(ur)-1) res[a[m]+i] += ur[i];\n\t\t\
    return res;\n\t};\n\tV<mint> s(si(a)+1); s[0] = 1;\n\treturn rec(rec,a,h,s);\n\
    }\n\n// decreasing -> decreasing\nV<int> ConjugateYoung(V<int> a){\n\tif(a.empty())\
    \ return a;\n\tint w = a[0];\n\tV<int> b(w);\n\tint h = si(a);\n\trep(j,w){\n\t\
    \twhile(h>0 && a[h-1] <= j) h--;\n\t\tb[j] = h;\n\t}\n\treturn b;\n}\n\n// increasing\
    \ -> increasing\nV<int> ConjugateYoung(V<int> a){\n\tif(a.empty()) return a;\n\
    \tint w = a.back();\n\tV<int> b(w);\n\tint i = 0;\n\trep(j,w){\n\t\twhile(i<si(a)\
    \ && a[i] == j) i++;\n\t\tb[w-1-j] = si(a)-i;\n\t}\n\treturn b;\n}\n\n// hook\
    \ length formula\n// a: decreasing\n\nmint Hook(V<int> a){\n\tint n = accumulate(all(a),0);\n\
    \tauto b = ConjugateYoung(a);\n\tmint res = fact[n];\n\trep(i,si(a)){\n\t\trep(j,a[i]){\n\
    \t\t\tres *= invs[a[i]+b[j]-i-j-1];\n\t\t}\n\t}\n\treturn res;\n}\n\n/*\n\tSSYT\
    \ of shape A with values [1,M]\n\tA: decreasing\n\tO(M log^2 M)\n\t\u591A\u5206\
    \ O(N log^2 N) \u306B\u3067\u304D\u308B (N > M \u306A\u3089 ans = 0 \u306B\u6CE8\
    \u610F)\n\tdiffProd.cpp \u304C\u5FC5\u8981\n*/\nmint CountSSYT(V<ll> A, ll M){\n\
    \tif(M >= 1000000) assert(false);\n\twhile(!A.empty() && A.back() == 0) A.pop_back();\n\
    \tint N = si(A);\n\tif(N > M) return 0;\n\trep(i,M-N) A.eb(0);\n\tN = M;\n\tV<mint>\
    \ B(N); rep(i,N) B[i] = A[i]+N-i;\n\treverse(all(B));\n\tmint numer = diffProd(B);\n\
    \tmint denom = 1; rep(i,N) denom *= fact[i];\n\treturn numer/denom;\n}\n"
  code: "// \u6A2An, \u9AD8\u3055a[0],..,a[n-1] \u306E\u30E4\u30F3\u30B0\u56F3\u5F62\
    \u4E0A\u3067 (0,0) \u304B\u3089 (n,0),..,(n,a[n-1]) \u3078\u306E\u7D4C\u8DEF\u6570\
    \n// a \u4EE5\u4E0B\u306E increasing sequence \u3068\u8A00\u3063\u3066\u3082\u3044\
    \u3044\n// O(N log^2 N) \u305F\u3060\u3057 N = n + a[n-1]\n// multiply \u304C\u3044\
    \u308B InitFact(N) \u3092\u547C\u3073\u51FA\u3059\u306E\u3092\u5FD8\u308C\u306A\
    \u3044\u3053\u3068\n// n >= 1, a: non-decreasing >= 0\n// verify: https://codeforces.com/gym/102220/problem/I\n\
    \nV<mint> CountYoungPaths(V<int> a,int h = -1){\n\tassert(!a.empty());\n\tif(h\
    \ == -1) h = a.back();\n\tauto parallel = [&](V<mint> x, int w){\n\t\tint h =\
    \ si(x)-1;\n\t\tV<mint> f(h+1);\n\t\trep(i,h+1) f[i] = Choose(w+i,w);\n\t\tauto\
    \ g = multiply(x,f); g.resize(h+1);\n\t\treturn g;\n\t};\n\tauto vertical = [&](V<mint>\
    \ x, int w){\n\t\tint h = si(x)-1;\n\t\trep(i,h+1) x[i] *= ifact[h-i];\n\t\tV<mint>\
    \ f(h+w+1); rep(i,h+w+1) f[i] = fact[i];\n\t\tauto g = multiply(x,f); g.resize(h+1);\n\
    \t\tV<mint> res(w+1);\n\t\trep(i,w+1) res[i] = g[h+i] * ifact[i];\n\t\treturn\
    \ res;\t\n\t};\n\n\t// \u6A2An, \u9AD8\u3055a[0],..,a[n-1] \u306E\u30E4\u30F3\u30B0\
    \u56F3\u5F62\u304C\u3042\u308B\n\t// for 0<=j<=a[n-1], res[j] = \\sum_{0<=i<=n}\
    \ [ (i,0) \u304B\u3089 (n,j) \u307E\u3067\u884C\u304F\u901A\u308A\u6570 ] * s[i]\n\
    \t// \u30E4\u30F3\u30B0\u56F3\u5F62\u306E\u4E0B\u3068\u53F3\u306B\u3072\u3052\u304C\
    \u751F\u3048\u3066\u3066\u3001\u305D\u3053\u304Cin/out\u3060\u3068\u601D\u3046\
    \u3068\u308F\u304B\u308A\u3084\u3059\u3044\u304B\u3082\uFF1F\n\t// h \u306F a[n-1]\
    \ \u3088\u308A\u5927\u304D\u3044\u304B\u3082\u3057\u308C\u306A\u3044\n\t// \u304A\
    \u6C17\u6301\u3061 \u2192 s: \u7D2F\u7A4D\u524D res: \u7D2F\u7A4D\u5F8C\n\t//\
    \ \u3053\u3063\u3061\u3092\u5916\u304B\u3089\u76F4\u63A5\u547C\u3073\u51FA\u3057\
    \u305F\u3044\u3053\u3068\u3082\u3042\u308B\u6C17\u304C\u3059\u308B\u306D(\u4E0B\
    \u306E\u5024\u305F\u3061s\u304C\u4E0E\u3048\u3089\u308C\u3066\u308B\u3068\u304D\
    \u3068\u304B)\n\tauto rec = [&](auto& self, V<int> a, int h, V<mint> s) -> V<mint>\
    \ {\n\t\tassert(si(a)+1 == si(s));\n\t\tint n = si(a);\n\t\tif(n <= 1 || h <=\
    \ 1){\n\t\t\tV<mint> res(h+1);\n\t\t\ta.pb(h);\n\t\t\trep(i,n+1){\n\t\t\t\tres[0]\
    \ += s[i];\n\t\t\t\trep(j,a[i]) res[j+1] += res[j];\n\t\t\t}\n\t\t\treturn res;\n\
    \t\t}\n\t\tint m = n/2;\n\t\tauto le = self(self,V<int>(a.begin(),a.begin()+m),a[m],V<mint>(s.begin(),s.begin()+m+1));\n\
    \t\tV<mint> dw(s.begin()+m+1,s.end());\n\t\tV<mint> res(h+1);\n\t\tV<mint> up(n-m);\n\
    \t\t{\n\t\t\tauto le2ri = parallel(le,n-m-1);\n\t\t\trep(i,si(le2ri)) res[i] +=\
    \ le2ri[i];\n\t\t}\n\t\t{\n\t\t\tauto le2up = vertical(le,n-m-1);\n\t\t\trep(i,si(le2up))\
    \ up[i] += le2up[i];\n\t\t}\n\t\t{\n\t\t\tauto dw2ri = vertical(dw,a[m]);\n\t\t\
    \trep(i,si(dw2ri)) res[i] += dw2ri[i];\n\t\t}\n\t\t{\n\t\t\tauto dw2up = parallel(dw,a[m]);\n\
    \t\t\trep(i,si(dw2up)) up[i] += dw2up[i];\n\t\t}\n\t\tV<int> na(a.begin()+m+1,a.end());\
    \ for(int& v: na) v -= a[m];\n\t\tper(i,n-m-1) up[i+1] -= up[i];\n\t\tauto ur\
    \ = self(self,na,h-a[m],up);\n\t\trep1(i,si(ur)-1) res[a[m]+i] += ur[i];\n\t\t\
    return res;\n\t};\n\tV<mint> s(si(a)+1); s[0] = 1;\n\treturn rec(rec,a,h,s);\n\
    }\n\n// decreasing -> decreasing\nV<int> ConjugateYoung(V<int> a){\n\tif(a.empty())\
    \ return a;\n\tint w = a[0];\n\tV<int> b(w);\n\tint h = si(a);\n\trep(j,w){\n\t\
    \twhile(h>0 && a[h-1] <= j) h--;\n\t\tb[j] = h;\n\t}\n\treturn b;\n}\n\n// increasing\
    \ -> increasing\nV<int> ConjugateYoung(V<int> a){\n\tif(a.empty()) return a;\n\
    \tint w = a.back();\n\tV<int> b(w);\n\tint i = 0;\n\trep(j,w){\n\t\twhile(i<si(a)\
    \ && a[i] == j) i++;\n\t\tb[w-1-j] = si(a)-i;\n\t}\n\treturn b;\n}\n\n// hook\
    \ length formula\n// a: decreasing\n\nmint Hook(V<int> a){\n\tint n = accumulate(all(a),0);\n\
    \tauto b = ConjugateYoung(a);\n\tmint res = fact[n];\n\trep(i,si(a)){\n\t\trep(j,a[i]){\n\
    \t\t\tres *= invs[a[i]+b[j]-i-j-1];\n\t\t}\n\t}\n\treturn res;\n}\n\n/*\n\tSSYT\
    \ of shape A with values [1,M]\n\tA: decreasing\n\tO(M log^2 M)\n\t\u591A\u5206\
    \ O(N log^2 N) \u306B\u3067\u304D\u308B (N > M \u306A\u3089 ans = 0 \u306B\u6CE8\
    \u610F)\n\tdiffProd.cpp \u304C\u5FC5\u8981\n*/\nmint CountSSYT(V<ll> A, ll M){\n\
    \tif(M >= 1000000) assert(false);\n\twhile(!A.empty() && A.back() == 0) A.pop_back();\n\
    \tint N = si(A);\n\tif(N > M) return 0;\n\trep(i,M-N) A.eb(0);\n\tN = M;\n\tV<mint>\
    \ B(N); rep(i,N) B[i] = A[i]+N-i;\n\treverse(all(B));\n\tmint numer = diffProd(B);\n\
    \tmint denom = 1; rep(i,N) denom *= fact[i];\n\treturn numer/denom;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/Young.cpp
  requiredBy: []
  timestamp: '2023-12-03 19:00:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Young.cpp
layout: document
redirect_from:
- /library/math/Young.cpp
- /library/math/Young.cpp.html
title: math/Young.cpp
---
