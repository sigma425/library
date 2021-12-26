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
    - https://yukicoder.me/problems/no/1783
  bundledCode: "#line 1 \"math/multivariate_mult.cpp\"\n/*\n\th[i1+j1][i2+j2]..[ik+jk]\
    \ += f[i1][i2]..[ik] * g[i1][i2]..[ik] \u3092\u3059\u308B\n\t\u305F\u3060\u3057\
    \ \u6DFB\u5B57\u306E\u7BC4\u56F2\u306F 0 <= ip,jp < np \u3067\u3001\u8DB3\u3057\
    \u305F\u7D50\u679C\u4E00\u7B87\u6240\u3067\u3082\u306F\u307F\u51FA\u305F\u5024\
    \u306F\u6368\u3066\u308B\n\tf,g \u306F flatten \u3055\u308C\u3066\u3044\u308B\
    \ (i1,i2,..,ik) \u304C i1 + i2n1 + i3n1n2 + .. \u306B\u5BFE\u5FDC\u3059\u308B\n\
    \tmagic\u306Fcalc_magic\u3067\u8A08\u7B97\u3057\u305F\u306E\u3092\u4F7F\u3046\n\
    \n\tO(knlogn + k^2n)\n\t\u307E\u3042 k \u306F O(logn) \u306A\u3093\u3067 O(knlogn)\
    \ \u3063\u3059\u306D\n\t\u5404\u6B21\u5143\u30922\u500D\u306B\u3057\u3066\u611A\
    \u76F4\u306B\u3084\u308B\u3068O(2^k nlogn) \u3068\u304B\u306B\u306A\u308B\u306F\
    \u305A\u3067\u3001\u3059\u3052\uFF5E\n\n\tverify: https://yukicoder.me/problems/no/1783\n\
    */\n/*\n\t\u8FFD\u52A0\u306E\u96D1\u306A\u30E1\u30E2\n\tmultivariate_log \u3059\
    \u308B\u3068\u304D\u306B D log(f) = (D f) / f \u3092\u3069\u3046\u89E3\u91C8\u3059\
    \u308B\u304B\n\n\tD log(f) = (D f) / f\n\n\tf = sum f[x][y] x^iy^j\n\n\tf[x] =\
    \ sum f[x][*]\n\n\t(d/dx) log(f) = ((d/dx)f) / f\n\n\tl = log f\n\tg = ((d/dx)f)\
    \ / f\n\n\t(d/dx) log(f) = ((d/dx)f) / f\n\t[x^i][y^j]\n\n\t(i+1) * l[i+1][j]\
    \ = g[i][j]\n\n\tl[0][*] \u3060\u3051\u308F\u304B\u3089\u306A\u3044\n\n\tl[*][0]\
    \ \u3060\u3051\u308F\u304B\u3089\u306A\u3044\n\n\tl[0][0] = 0\n\n\tg\u306E\u8A08\
    \u7B97\u3000\uFF08\u5272\u308A\u7B97\uFF09\u304Ck\u56DE\u3000\u304A\u305D\u3044\
    \n\n\n\tDx = x(d/dx) \u3068\u3059\u308B\u3068\n\tDx log(f) = (Dx f) / f \u304C\
    \u306A\u308A\u305F\u3064\n\n\tD = Dx + Dy\n\tD log(f) = (D f) / f \u304C\u306A\
    \u308A\u305F\u3064\n\n\t[x^iy^jz^k] (1Dx + n1Dy + n1n2Dz) log(f) = [x^iy^j] (((1Dx\
    \ + n1Dy + n1n2Dz) f) / f)\n\n\n\tl[i][j][k] = g[i][j][k] / (i+j*n1+k*n1n2)\n\t\
    \tflatten\u3057\u305Findex\u3092\u305D\u306E\u307E\u307E\u304B\u3051\u3066\u3067\
    \u304D\u308B\n\n\tl[0][0][0] = 0\n*/\nV<int> calc_magic(const vector<int>& ns){\n\
    \tint k = si(ns);\n\tif(k == 0) return {};\n\tint n = 1;\n\tfor(int ni: ns) n\
    \ *= ni;\n\tV<int> magic(n);\n\trep(i,n){\n\t\tint x = i;\n\t\trep(j,k){\n\t\t\
    \tmagic[i] += x;\n\t\t\tx /= ns[j];\n\t\t}\n\t\tmagic[i] %= k;\n\t}\n\treturn\
    \ magic;\n}\nvector<mint> multivariate_mult(const vector<mint>& f, const vector<mint>&\
    \ g, const vector<int>& ns, const vector<int>& magic){\n\tassert(si(f) == si(g));\n\
    \tint n = si(f);\n\tint k = si(ns);\n\tif(k == 0){\n\t\treturn {f[0]*g[0]};\n\t\
    }\n\tint s = 1; while(s<n*2-1) s*=2;\n\tvector<mint> h(n);\n\tvector<vector<mint>>\
    \ zf(k,vector<mint>(s));\n\tvector<vector<mint>> zg(k,vector<mint>(s));\n\tvector<vector<mint>>\
    \ zh(k,vector<mint>(s));\n\trep(i,n) zf[magic[i]][i] = f[i];\n\trep(i,k) fft(zf[i]);\n\
    \trep(i,n) zg[magic[i]][i] = g[i];\n\trep(i,k) fft(zg[i]);\n\trep(a,k) rep(b,k){\n\
    \t\tint c = (a+b)%k;\n\t\trep(i,s) zh[c][i] += zf[a][i] * zg[b][i];\n\t}\n\trep(i,k)\
    \ invfft(zh[i]);\n\trep(i,n) h[i] = zh[magic[i]][i];\n\treturn h;\n}\n"
  code: "/*\n\th[i1+j1][i2+j2]..[ik+jk] += f[i1][i2]..[ik] * g[i1][i2]..[ik] \u3092\
    \u3059\u308B\n\t\u305F\u3060\u3057 \u6DFB\u5B57\u306E\u7BC4\u56F2\u306F 0 <= ip,jp\
    \ < np \u3067\u3001\u8DB3\u3057\u305F\u7D50\u679C\u4E00\u7B87\u6240\u3067\u3082\
    \u306F\u307F\u51FA\u305F\u5024\u306F\u6368\u3066\u308B\n\tf,g \u306F flatten \u3055\
    \u308C\u3066\u3044\u308B (i1,i2,..,ik) \u304C i1 + i2n1 + i3n1n2 + .. \u306B\u5BFE\
    \u5FDC\u3059\u308B\n\tmagic\u306Fcalc_magic\u3067\u8A08\u7B97\u3057\u305F\u306E\
    \u3092\u4F7F\u3046\n\n\tO(knlogn + k^2n)\n\t\u307E\u3042 k \u306F O(logn) \u306A\
    \u3093\u3067 O(knlogn) \u3063\u3059\u306D\n\t\u5404\u6B21\u5143\u30922\u500D\u306B\
    \u3057\u3066\u611A\u76F4\u306B\u3084\u308B\u3068O(2^k nlogn) \u3068\u304B\u306B\
    \u306A\u308B\u306F\u305A\u3067\u3001\u3059\u3052\uFF5E\n\n\tverify: https://yukicoder.me/problems/no/1783\n\
    */\n/*\n\t\u8FFD\u52A0\u306E\u96D1\u306A\u30E1\u30E2\n\tmultivariate_log \u3059\
    \u308B\u3068\u304D\u306B D log(f) = (D f) / f \u3092\u3069\u3046\u89E3\u91C8\u3059\
    \u308B\u304B\n\n\tD log(f) = (D f) / f\n\n\tf = sum f[x][y] x^iy^j\n\n\tf[x] =\
    \ sum f[x][*]\n\n\t(d/dx) log(f) = ((d/dx)f) / f\n\n\tl = log f\n\tg = ((d/dx)f)\
    \ / f\n\n\t(d/dx) log(f) = ((d/dx)f) / f\n\t[x^i][y^j]\n\n\t(i+1) * l[i+1][j]\
    \ = g[i][j]\n\n\tl[0][*] \u3060\u3051\u308F\u304B\u3089\u306A\u3044\n\n\tl[*][0]\
    \ \u3060\u3051\u308F\u304B\u3089\u306A\u3044\n\n\tl[0][0] = 0\n\n\tg\u306E\u8A08\
    \u7B97\u3000\uFF08\u5272\u308A\u7B97\uFF09\u304Ck\u56DE\u3000\u304A\u305D\u3044\
    \n\n\n\tDx = x(d/dx) \u3068\u3059\u308B\u3068\n\tDx log(f) = (Dx f) / f \u304C\
    \u306A\u308A\u305F\u3064\n\n\tD = Dx + Dy\n\tD log(f) = (D f) / f \u304C\u306A\
    \u308A\u305F\u3064\n\n\t[x^iy^jz^k] (1Dx + n1Dy + n1n2Dz) log(f) = [x^iy^j] (((1Dx\
    \ + n1Dy + n1n2Dz) f) / f)\n\n\n\tl[i][j][k] = g[i][j][k] / (i+j*n1+k*n1n2)\n\t\
    \tflatten\u3057\u305Findex\u3092\u305D\u306E\u307E\u307E\u304B\u3051\u3066\u3067\
    \u304D\u308B\n\n\tl[0][0][0] = 0\n*/\nV<int> calc_magic(const vector<int>& ns){\n\
    \tint k = si(ns);\n\tif(k == 0) return {};\n\tint n = 1;\n\tfor(int ni: ns) n\
    \ *= ni;\n\tV<int> magic(n);\n\trep(i,n){\n\t\tint x = i;\n\t\trep(j,k){\n\t\t\
    \tmagic[i] += x;\n\t\t\tx /= ns[j];\n\t\t}\n\t\tmagic[i] %= k;\n\t}\n\treturn\
    \ magic;\n}\nvector<mint> multivariate_mult(const vector<mint>& f, const vector<mint>&\
    \ g, const vector<int>& ns, const vector<int>& magic){\n\tassert(si(f) == si(g));\n\
    \tint n = si(f);\n\tint k = si(ns);\n\tif(k == 0){\n\t\treturn {f[0]*g[0]};\n\t\
    }\n\tint s = 1; while(s<n*2-1) s*=2;\n\tvector<mint> h(n);\n\tvector<vector<mint>>\
    \ zf(k,vector<mint>(s));\n\tvector<vector<mint>> zg(k,vector<mint>(s));\n\tvector<vector<mint>>\
    \ zh(k,vector<mint>(s));\n\trep(i,n) zf[magic[i]][i] = f[i];\n\trep(i,k) fft(zf[i]);\n\
    \trep(i,n) zg[magic[i]][i] = g[i];\n\trep(i,k) fft(zg[i]);\n\trep(a,k) rep(b,k){\n\
    \t\tint c = (a+b)%k;\n\t\trep(i,s) zh[c][i] += zf[a][i] * zg[b][i];\n\t}\n\trep(i,k)\
    \ invfft(zh[i]);\n\trep(i,n) h[i] = zh[magic[i]][i];\n\treturn h;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/multivariate_mult.cpp
  requiredBy: []
  timestamp: '2021-12-26 19:30:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/multivariate_mult.cpp
layout: document
redirect_from:
- /library/math/multivariate_mult.cpp
- /library/math/multivariate_mult.cpp.html
title: math/multivariate_mult.cpp
---
