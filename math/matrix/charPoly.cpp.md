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
    - https://ac.nowcoder.com/acm/contest/view-submission?submissionId=48446911
    - https://atcoder.jp/contests/xmascon21/submissions/28183908
    - https://github.com/noshi91/n91lib_rs/blob/master/src/algorithm/division_free_determinant.rs
    - https://official.contest.yandex.ru/opencupXX/contest/17333/run-report/63224090/
  bundledCode: "#line 1 \"math/matrix/charPoly.cpp\"\n/*\n\tT: field\n\t\tcharPoly(VV<T>\
    \ a):\n\t\t\tdet( xI - a )\n\t\t\tO(n^3)\n\t\tdetPoly(VV<T> a, VV<T> b):\n\t\t\
    \tdet( a + xb )\n\t\t\tO(n^3)\n\t\tdetPoly(vector<VV<T>> a):\n\t\t\tdet( a0 +\
    \ a1x + ..)\n\t\t\tO(n^3k^3)\n\t\t\thttps://ac.nowcoder.com/acm/contest/view-submission?submissionId=48446911\n\
    \n\tT: commutative ring\n\t\tcharPoly_divfree(VV<T> a):\n\t\t\tdet( xI - a )\n\
    \t\t\tO(n^4)\n\n\tT: field\n\t\tresultant(V<T> f, V<T> g)\n\t\tProdSumOfRoots(V<T>\
    \ f, V<T> g)\n\t\tProdSumOfRootsWithout0(V<T> f, V<T> g)\n*/\n\ntemplate<class\
    \ T>\nvector<T> charPoly(vector<vector<T>> a){\n\tint n = si(a);\n\trep(j,n-2){\n\
    \t\tfor(int i=j+1;i<n;i++) if(a[i][j]){\n\t\t\tswap(a[j+1],a[i]);\n\t\t\trep(k,n)\
    \ swap(a[k][j+1],a[k][i]);\n\t\t\tbreak;\n\t\t}\n\t\tif(a[j+1][j]){\n\t\t\tconst\
    \ T r = T(1) / a[j+1][j];\n\t\t\tfor(int i=j+2;i<n;i++){\n\t\t\t\tconst T s =\
    \ r * a[i][j];\n\t\t\t\tfor(int k=j;k<n;k++) a[i][k] -= s * a[j+1][k];\n\t\t\t\
    \trep(k,n) a[k][j+1] += s * a[k][i];\n\t\t\t}\n\t\t}\n\t}\n\tvector<vector<T>>\
    \ f(n+1);\n\tf[0] = {1};\n\trep(i,n){\n\t\tf[i+1] = vector<T>(i+2);\n\t\trep(j,i+1)\
    \ f[i+1][j+1] = f[i][j];\n\t\trep(j,i+1) f[i+1][j] -= a[i][i] * f[i][j];\n\t\t\
    T beta = 1;\n\t\tper(j,i){\n\t\t\tbeta *= a[j+1][j];\n\t\t\tconst T s = beta *\
    \ -a[j][i];\n\t\t\trep(k,j+1) f[i+1][k] += s * f[j][k];\n\t\t}\n\t}\n\treturn\
    \ f[n];\n}\n\n/*\n\thttps://github.com/noshi91/n91lib_rs/blob/master/src/algorithm/division_free_determinant.rs\n\
    \tverify\u306F\u3057\u3066\u306A\u3044\u3001\u4F7F\u3063\u3066\u306A\u3044\u304B\
    \u3089(?)\n\tO(N^4)\n*/\ntemplate<class T>\nT divfree_determinant(VV<T> a){\n\t\
    int N = si(a);\n\tVV<T> dp(N+1,V<T>(N+1,T::zero()));\n\trep(i,N+1) dp[i][i] =\
    \ T::one();\n\trep(_,N){\n\t\tVV<T> nx(N+1,V<T>(N+1,T::zero()));\n\t\trep(h,N){\n\
    \t\t\tfor(int c=h;c<N;c++){\n\t\t\t\tfor(int v=h+1;v<N;v++){\n\t\t\t\t\tnx[h][v]\
    \ -= dp[h][c] * a[c][v];\n\t\t\t\t}\n\t\t\t\tauto t = dp[h][c] * a[c][h];\n\t\t\
    \t\tfor(int v=h+1;v<N+1;v++){\n\t\t\t\t\tnx[v][v] += t;\n\t\t\t\t}\n\t\t\t}\n\t\
    \t}\n\t\tdp = nx;\n\t}\n\treturn dp[N][N];\n}\n\n\n/*\n\tT: field\n\n\t\u5B9A\u7FA9\
    :\n\t\t\u7A7A\u3067\u306A\u3044*\u6570\u5217* f = [a_0 , .. , a_m], g = [b_0 ,\
    \ .. , b_n] \u306B\u5BFE\u3057\u3066\u6B21\u306E\u3088\u3046\u306B\u5B9A\u7FA9\
    \u3055\u308C\u308B\n\t\t\t\t\t|a2 a1 a0      |\n\t\t\t\t\t|   a2 a1 a0   |\n\t\
    \tRes(f,g) = \t|\t   a2 a1 a0|\n\t\t\t\t\t|b3 b2 b1 b0   |\n\t\t\t\t\t|   b3 b2\
    \ b1 b0|\n\n\t\u6027\u8CEA:\n\t\tRes(g,f) = Res(f,g) * (-1)^(mn)\n\t\tRes(cf,g)\
    \ = Res(f,g) * c^n\n\t\tRes(f,dg) = Res(f,g) * d^m\n\t\tRes(f%g,g) = Res(f,g%f)\
    \ = Res(f,g)\t\u6570\u5217\u3068\u3057\u3066\u898B\u3066\u308B\u306E\u3067\u884C\
    \u5217\u306E\u30B5\u30A4\u30BA\u306F\u5909\u308F\u3089\u306A\u3044\u3053\u3068\
    \u306B\u6CE8\u610F\n\t\tm > 0 \u304B\u3064 a_m = 0 \u306E\u3068\u304D\u3001a_m\u3092\
    \u524A\u308B\u3068\u3001\n\t\t\tRes(f,g) = Res([a_0 , .. , a_{m-1}], [b_0 , ..\
    \ , b_n]) * b_n * (-1)^n\n\n\t\t\u2606 a_m \\neq 0 \u304B\u3064 b_n \\neq 0 \u306E\
    \u3068\u304D\u3001\n\t\tf = a_0 + a_1 x + .. a_m x^m\n\t\tg = b_0 + b_1 x + ..\
    \ b_n x^n\n\t\tf \u306E\u6839\u3092 \u03B11,..,\u03B1m, g \u306E\u6839\u3092 \u03B2\
    1,..,\u03B2n \u3068\u3059\u308B\n\t\tRes(f,g) = a_m^n * b_n^m * \\prod_{i,j} (\u03B1\
    i - \u03B2j)\n\n\tO(mn) f\u3068g\u306E\u4E92\u9664\u6CD5\u307F\u305F\u3044\u306A\
    \u611F\u3058\u3067\u8A08\u7B97\u3059\u308B\n\n\tverify:\n\t\tXX Zhejiang K https://official.contest.yandex.ru/opencupXX/contest/17333/run-report/63224090/\n\
    \t\txmas 2021 H https://atcoder.jp/contests/xmascon21/submissions/28183908\n*/\n\
    template<class T>\nT resultant(vector<T> f, vector<T> g){\n\tT res = 1;\n\tint\
    \ m = si(f)-1, n = si(g)-1;\n\twhile(true){\n\t\twhile(m>=0 && f[m]==0) m--;\n\
    \t\twhile(n>=0 && g[n]==0) n--;\n\t\tif(m < 0 or n < 0){\n\t\t\tres = 0; break;\n\
    \t\t}\n\t\tif(m <= 0 or n <= 0){\n\t\t\tres *= f[m].pow(n) * g[n].pow(m);\n\t\t\
    \tbreak;\n\t\t}\n\t\tif(m > n){\n\t\t\tif(m&n&1) res *= -1;\n\t\t\tswap(m,n);\n\
    \t\t\tswap(f,g);\n\t\t}\n\t\tres *= f[m].pow(n);\n\t\tconst T r = f[m].inv();\n\
    \t\tfor(int i=0;i<=m;i++) f[i] *= r;\n\t\tfor(int j=n;j>=m;j--){\n\t\t\tfor(int\
    \ i=0;i<m;i++) g[j-m+i] -= f[i] * g[j];\n\t\t\tg[j] = 0;\n\t\t}\n\t}\n\treturn\
    \ res;\n}\n/*\n\tf = (x-\u03B10)(x-\u03B11)..\n\tg = (x-\u03B20)(x-\u03B21)..\n\
    \tf,g should be monic\n\t\n\toutput: \\prod_{i,j} (\u03B1i + \u03B2j)\n*/\ntemplate<class\
    \ T>\nT prodSumOfRoots(vector<T> f, vector<T> g){\n\tint m = si(f)-1, n = si(g)-1;\n\
    \tassert(m >= 0);\n\tassert(n >= 0);\n\tassert(f[m] == 1);\n\tassert(g[n] == 1);\n\
    \n\t// for non-monic\n\t// while(!f[m]) m--;\n\t// while(!g[n]) n--;\n\t// {\n\
    \t// \tconst T r = f[m].inv();\n\t// \trep(i,m+1) f[i] *= r;\n\t// }\n\t// {\n\
    \t// \tconst T r = g[n].inv();\n\t// \trep(i,n+1) g[i] *= r;\n\t// }\n\n\tfor(int\
    \ i=n-1;i>=0;i-=2) g[i] *= -1;\n\treturn resultant(f,g);\n}\n\n/*\n\t\u03B10 =\
    \ \u03B20 = 0\n\tf = x(x-\u03B11)..\n\tg = x(x-\u03B21)..\n\tf,g should be monic\n\
    \n\toutput: \\prod_{i,j, i+j>0} (\u03B1i + \u03B2j)\n\n\t\\prod_{i,j, i+j>0} (\u03B1\
    i + \u03B2j)\n\t = \\prod_{i >= 0, j > 0} (\u03B1i + \u03B2j) * \\prod_{i > 0}\
    \ \u03B1i\n\t = prodSumOfRoots(f,g/x) * [x]f * (-1)^(m-1)\n*/\ntemplate<class\
    \ T>\nT prodSumOfRootsWithout0(vector<T> f, vector<T> g){\n\tint m = si(f)-1,\
    \ n = si(g)-1;\n\tassert(m >= 1);\n\tassert(n >= 1);\n\tassert(f[0] == 0);\n\t\
    assert(g[0] == 0);\n\tassert(f[m] == 1);\n\tassert(g[n] == 1);\n\n\tvector<T>\
    \ gs(n); rep(i,n) gs[i] = g[i+1];\n\treturn prodSumOfRoots(f,gs) * f[1] * mint(-1).pow(m-1);\n\
    }\n"
  code: "/*\n\tT: field\n\t\tcharPoly(VV<T> a):\n\t\t\tdet( xI - a )\n\t\t\tO(n^3)\n\
    \t\tdetPoly(VV<T> a, VV<T> b):\n\t\t\tdet( a + xb )\n\t\t\tO(n^3)\n\t\tdetPoly(vector<VV<T>>\
    \ a):\n\t\t\tdet( a0 + a1x + ..)\n\t\t\tO(n^3k^3)\n\t\t\thttps://ac.nowcoder.com/acm/contest/view-submission?submissionId=48446911\n\
    \n\tT: commutative ring\n\t\tcharPoly_divfree(VV<T> a):\n\t\t\tdet( xI - a )\n\
    \t\t\tO(n^4)\n\n\tT: field\n\t\tresultant(V<T> f, V<T> g)\n\t\tProdSumOfRoots(V<T>\
    \ f, V<T> g)\n\t\tProdSumOfRootsWithout0(V<T> f, V<T> g)\n*/\n\ntemplate<class\
    \ T>\nvector<T> charPoly(vector<vector<T>> a){\n\tint n = si(a);\n\trep(j,n-2){\n\
    \t\tfor(int i=j+1;i<n;i++) if(a[i][j]){\n\t\t\tswap(a[j+1],a[i]);\n\t\t\trep(k,n)\
    \ swap(a[k][j+1],a[k][i]);\n\t\t\tbreak;\n\t\t}\n\t\tif(a[j+1][j]){\n\t\t\tconst\
    \ T r = T(1) / a[j+1][j];\n\t\t\tfor(int i=j+2;i<n;i++){\n\t\t\t\tconst T s =\
    \ r * a[i][j];\n\t\t\t\tfor(int k=j;k<n;k++) a[i][k] -= s * a[j+1][k];\n\t\t\t\
    \trep(k,n) a[k][j+1] += s * a[k][i];\n\t\t\t}\n\t\t}\n\t}\n\tvector<vector<T>>\
    \ f(n+1);\n\tf[0] = {1};\n\trep(i,n){\n\t\tf[i+1] = vector<T>(i+2);\n\t\trep(j,i+1)\
    \ f[i+1][j+1] = f[i][j];\n\t\trep(j,i+1) f[i+1][j] -= a[i][i] * f[i][j];\n\t\t\
    T beta = 1;\n\t\tper(j,i){\n\t\t\tbeta *= a[j+1][j];\n\t\t\tconst T s = beta *\
    \ -a[j][i];\n\t\t\trep(k,j+1) f[i+1][k] += s * f[j][k];\n\t\t}\n\t}\n\treturn\
    \ f[n];\n}\n\n/*\n\thttps://github.com/noshi91/n91lib_rs/blob/master/src/algorithm/division_free_determinant.rs\n\
    \tverify\u306F\u3057\u3066\u306A\u3044\u3001\u4F7F\u3063\u3066\u306A\u3044\u304B\
    \u3089(?)\n\tO(N^4)\n*/\ntemplate<class T>\nT divfree_determinant(VV<T> a){\n\t\
    int N = si(a);\n\tVV<T> dp(N+1,V<T>(N+1,T::zero()));\n\trep(i,N+1) dp[i][i] =\
    \ T::one();\n\trep(_,N){\n\t\tVV<T> nx(N+1,V<T>(N+1,T::zero()));\n\t\trep(h,N){\n\
    \t\t\tfor(int c=h;c<N;c++){\n\t\t\t\tfor(int v=h+1;v<N;v++){\n\t\t\t\t\tnx[h][v]\
    \ -= dp[h][c] * a[c][v];\n\t\t\t\t}\n\t\t\t\tauto t = dp[h][c] * a[c][h];\n\t\t\
    \t\tfor(int v=h+1;v<N+1;v++){\n\t\t\t\t\tnx[v][v] += t;\n\t\t\t\t}\n\t\t\t}\n\t\
    \t}\n\t\tdp = nx;\n\t}\n\treturn dp[N][N];\n}\n\n\n/*\n\tT: field\n\n\t\u5B9A\u7FA9\
    :\n\t\t\u7A7A\u3067\u306A\u3044*\u6570\u5217* f = [a_0 , .. , a_m], g = [b_0 ,\
    \ .. , b_n] \u306B\u5BFE\u3057\u3066\u6B21\u306E\u3088\u3046\u306B\u5B9A\u7FA9\
    \u3055\u308C\u308B\n\t\t\t\t\t|a2 a1 a0      |\n\t\t\t\t\t|   a2 a1 a0   |\n\t\
    \tRes(f,g) = \t|\t   a2 a1 a0|\n\t\t\t\t\t|b3 b2 b1 b0   |\n\t\t\t\t\t|   b3 b2\
    \ b1 b0|\n\n\t\u6027\u8CEA:\n\t\tRes(g,f) = Res(f,g) * (-1)^(mn)\n\t\tRes(cf,g)\
    \ = Res(f,g) * c^n\n\t\tRes(f,dg) = Res(f,g) * d^m\n\t\tRes(f%g,g) = Res(f,g%f)\
    \ = Res(f,g)\t\u6570\u5217\u3068\u3057\u3066\u898B\u3066\u308B\u306E\u3067\u884C\
    \u5217\u306E\u30B5\u30A4\u30BA\u306F\u5909\u308F\u3089\u306A\u3044\u3053\u3068\
    \u306B\u6CE8\u610F\n\t\tm > 0 \u304B\u3064 a_m = 0 \u306E\u3068\u304D\u3001a_m\u3092\
    \u524A\u308B\u3068\u3001\n\t\t\tRes(f,g) = Res([a_0 , .. , a_{m-1}], [b_0 , ..\
    \ , b_n]) * b_n * (-1)^n\n\n\t\t\u2606 a_m \\neq 0 \u304B\u3064 b_n \\neq 0 \u306E\
    \u3068\u304D\u3001\n\t\tf = a_0 + a_1 x + .. a_m x^m\n\t\tg = b_0 + b_1 x + ..\
    \ b_n x^n\n\t\tf \u306E\u6839\u3092 \u03B11,..,\u03B1m, g \u306E\u6839\u3092 \u03B2\
    1,..,\u03B2n \u3068\u3059\u308B\n\t\tRes(f,g) = a_m^n * b_n^m * \\prod_{i,j} (\u03B1\
    i - \u03B2j)\n\n\tO(mn) f\u3068g\u306E\u4E92\u9664\u6CD5\u307F\u305F\u3044\u306A\
    \u611F\u3058\u3067\u8A08\u7B97\u3059\u308B\n\n\tverify:\n\t\tXX Zhejiang K https://official.contest.yandex.ru/opencupXX/contest/17333/run-report/63224090/\n\
    \t\txmas 2021 H https://atcoder.jp/contests/xmascon21/submissions/28183908\n*/\n\
    template<class T>\nT resultant(vector<T> f, vector<T> g){\n\tT res = 1;\n\tint\
    \ m = si(f)-1, n = si(g)-1;\n\twhile(true){\n\t\twhile(m>=0 && f[m]==0) m--;\n\
    \t\twhile(n>=0 && g[n]==0) n--;\n\t\tif(m < 0 or n < 0){\n\t\t\tres = 0; break;\n\
    \t\t}\n\t\tif(m <= 0 or n <= 0){\n\t\t\tres *= f[m].pow(n) * g[n].pow(m);\n\t\t\
    \tbreak;\n\t\t}\n\t\tif(m > n){\n\t\t\tif(m&n&1) res *= -1;\n\t\t\tswap(m,n);\n\
    \t\t\tswap(f,g);\n\t\t}\n\t\tres *= f[m].pow(n);\n\t\tconst T r = f[m].inv();\n\
    \t\tfor(int i=0;i<=m;i++) f[i] *= r;\n\t\tfor(int j=n;j>=m;j--){\n\t\t\tfor(int\
    \ i=0;i<m;i++) g[j-m+i] -= f[i] * g[j];\n\t\t\tg[j] = 0;\n\t\t}\n\t}\n\treturn\
    \ res;\n}\n/*\n\tf = (x-\u03B10)(x-\u03B11)..\n\tg = (x-\u03B20)(x-\u03B21)..\n\
    \tf,g should be monic\n\t\n\toutput: \\prod_{i,j} (\u03B1i + \u03B2j)\n*/\ntemplate<class\
    \ T>\nT prodSumOfRoots(vector<T> f, vector<T> g){\n\tint m = si(f)-1, n = si(g)-1;\n\
    \tassert(m >= 0);\n\tassert(n >= 0);\n\tassert(f[m] == 1);\n\tassert(g[n] == 1);\n\
    \n\t// for non-monic\n\t// while(!f[m]) m--;\n\t// while(!g[n]) n--;\n\t// {\n\
    \t// \tconst T r = f[m].inv();\n\t// \trep(i,m+1) f[i] *= r;\n\t// }\n\t// {\n\
    \t// \tconst T r = g[n].inv();\n\t// \trep(i,n+1) g[i] *= r;\n\t// }\n\n\tfor(int\
    \ i=n-1;i>=0;i-=2) g[i] *= -1;\n\treturn resultant(f,g);\n}\n\n/*\n\t\u03B10 =\
    \ \u03B20 = 0\n\tf = x(x-\u03B11)..\n\tg = x(x-\u03B21)..\n\tf,g should be monic\n\
    \n\toutput: \\prod_{i,j, i+j>0} (\u03B1i + \u03B2j)\n\n\t\\prod_{i,j, i+j>0} (\u03B1\
    i + \u03B2j)\n\t = \\prod_{i >= 0, j > 0} (\u03B1i + \u03B2j) * \\prod_{i > 0}\
    \ \u03B1i\n\t = prodSumOfRoots(f,g/x) * [x]f * (-1)^(m-1)\n*/\ntemplate<class\
    \ T>\nT prodSumOfRootsWithout0(vector<T> f, vector<T> g){\n\tint m = si(f)-1,\
    \ n = si(g)-1;\n\tassert(m >= 1);\n\tassert(n >= 1);\n\tassert(f[0] == 0);\n\t\
    assert(g[0] == 0);\n\tassert(f[m] == 1);\n\tassert(g[n] == 1);\n\n\tvector<T>\
    \ gs(n); rep(i,n) gs[i] = g[i+1];\n\treturn prodSumOfRoots(f,gs) * f[1] * mint(-1).pow(m-1);\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/charPoly.cpp
  requiredBy: []
  timestamp: '2021-12-28 23:52:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix/charPoly.cpp
layout: document
redirect_from:
- /library/math/matrix/charPoly.cpp
- /library/math/matrix/charPoly.cpp.html
title: math/matrix/charPoly.cpp
---
