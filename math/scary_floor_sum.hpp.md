---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc183/submissions/57122721
    - https://loj.ac/p/138
    - https://loj.ac/s/2146116
  bundledCode: "#line 1 \"math/scary_floor_sum.hpp\"\n/*\n\tfloor sum \u306E\u4E00\
    \u822C\u5316\n\tMonoid T \u306E\u5143 x,y \u3068\u3001 f(i) := floor((a*i + b)\
    \ / m) \u304C\u4E0E\u3048\u3089\u308C\u305F\u3068\u304D\u306B\u3001\n\ty^f(0)\
    \ x y^(f(1)-f(0)) x y^(f(2)-f(1)) x ... x y^(f(n)-f(n-1)) \u3092\u8A08\u7B97\u3059\
    \u308B\n\t\tx \u304C n \u500B\u3002\u6700\u521D\u3082\u6700\u5F8C\u3082 y \u306E\
    \u5217\u304C(\u4E00\u822C\u306B\u306F)\u3042\u308B\n\n\ty <= (ax+b)/m \u3068\u3044\
    \u3046\u7BC4\u56F2\u3092\u3001(0,0) \u304B\u3089 (n,[(an+b)/m]) \u307E\u3067\u3067\
    \u304D\u308B\u3060\u3051 y \u65B9\u5411\u306B\u8CAA\u6B32\u306B\u79FB\u52D5\u3059\
    \u308B path \u3092\u8A08\u7B97\u3057\u3066\u3044\u308B\u3068\u601D\u3048\u308B\
    \n\n\n\t\u4F8B\u3048\u3070 floor sum \u306F x \u3057\u305F\u3068\u304D\u306E\u3053\
    \u308C\u307E\u3067\u306E y \u306E\u500B\u6570 \u306E\u548C\u306A\u306E\u3067\u3001\
    Monoid{numx,numy,num(x..y)} \u3092\u3082\u3066\u3070\u8A08\u7B97\u53EF\u80FD\n\
    \n\tO(log m)\n\n\t\u8981\u8ACB:\n\t\tMonoid T \u304C T::e(), T::op(a,b), a.pow(p)\
    \ \u3092\u6301\u3064\n\t\tan + b \u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\
    \u3057\u306A\u3044\n\n\tverify:\n\t\tARC183 F https://atcoder.jp/contests/arc183/submissions/57122721\n\
    \t\tLOJ138 https://loj.ac/s/2146116\n*/\ntemplate<class S = __int128, class T>\n\
    T underpath(S a, S b, S m, S n, T x, T y){\n\tassert(m > 0);\n\tassert(n >= 0);\n\
    \tassert(a >= 0);\n\tassert(b >= 0);\n\tS c = (a*n+b)/m;\n\tT pre = T::e(), suf\
    \ = T::e();\n\twhile(true){\n\t\tS p = a/m; a %= m; x = T::op(x, y.pow(p));\n\t\
    \tS q = b/m; b %= m; pre = T::op(pre, y.pow(q));\n\t\tc -= p*n + q;\n\t\tif(c\
    \ == 0) break;\n\t\tS d = (m*c - b - 1) / a + 1;\n\t\tsuf = T::op(T::op(y, x.pow(n-d)),\
    \ suf);\n\t\tb = m-b-1+a; swap(m,a); n = c-1; c = d; swap(x,y);\n\t}\n\treturn\
    \ T::op(T::op(pre, x.pow(n)), suf);\n}\n\n/*\n\tscary floor sum \u306B\u4E57\u305B\
    \u308B\u305F\u3081\u306E\u30E2\u30CE\u30A4\u30C9\n\t\\sum_{0 <= x < N} x^[0,e1]\
    \ * floor( (ax + b) / m )^[0,e2] \u3092\u8A08\u7B97\u3067\u304D\u308B\n\n\t\u53EF\
    \u5909 mint \u307F\u305F\u3044\u306A\u611F\u3058\u3067\u3001\u4F7F\u3046\u524D\
    \u306B set_e1_e2 \u3092\u547C\u3076\n*/\ntemplate<class T>\nstruct MonoidFloorSum{\n\
    \tusing X = MonoidFloorSum;\n\tstatic inline int e1,e2;\n\tstatic inline vector<vector<T>>\
    \ comb;\n\tstatic void set_e1_e2(int e1_, int e2_){\n\t\te1 = e1_, e2 = e2_;\n\
    \t\tint e = max(e1,e2);\n\t\tcomb = vector<vector<T>>(e+1,vector<T>(e+1));\n\t\
    \trep(i,e+1){\n\t\t\tcomb[i][0] = comb[i][i] = T(1);\n\t\t\trep1(j,i-1) comb[i][j]\
    \ = comb[i-1][j-1] + comb[i-1][j];\n\t\t}\n\t}\n\n\tMonoidFloorSum():dp(e1+1,vector<T>(e2+1)){}\n\
    \n\tT dx, dy;\n\tvector<vector<T>> dp;\n\n\tstatic X op(X a, X b){\n\t\tvector<T>\
    \ xpow(e1+1); xpow[0] = 1; rep(i,e1) xpow[i+1] = xpow[i] * a.dx;\n\t\tvector<T>\
    \ ypow(e2+1); ypow[0] = 1; rep(i,e2) ypow[i+1] = ypow[i] * a.dy;\n\n\t\trep(k1,e1+1)\
    \ rep(k2,e2+1){\n\t\t\trep(i1,k1+1) rep(i2,k2+1){\n\t\t\t\ta.dp[k1][k2] += b.dp[i1][i2]\
    \ * comb[k1][i1] * xpow[k1-i1] * comb[k2][i2] * ypow[k2-i2];\n\t\t\t}\n\t\t}\n\
    \t\ta.dx += b.dx, a.dy += b.dy;\n\t\treturn a;\n\t}\n\tX pow(ll exp) const {\n\
    \t\tX res = X::e();\n\t\tX pw = *this;\n\t\twhile(exp){\n\t\t\tif(exp&1) res =\
    \ op(res,pw);\n\t\t\tpw = op(pw,pw);\n\t\t\texp /= 2;\n\t\t}\n\t\treturn res;\n\
    \t}\n\tstatic X to_x(){\n\t\tX x;\n\t\tx.dp[0][0] = 1; x.dx = 1;\n\t\treturn x;\n\
    \t}\n\tstatic X to_y(){\n\t\tX x;\n\t\tx.dy = 1;\n\t\treturn x;\n\t}\n\tstatic\
    \ X e(){\n\t\treturn X();\n\t}\n};\n\n/*\n\tres[k1][k2] = \\sum_{0 <= x < N} x^e1\
    \ * floor( (ax + b) / m )^e2\n\n\t\u8981\u8ACB: a >= 0, b >= 0, m > 0, N >= 0\n\
    \n\t\u5024\u306E\u7BC4\u56F2\u306F S. \u3060\u3044\u305F\u3044 __int128?\n\t\u8FD4\
    \u308A\u5024\u306F T. \u3060\u3044\u305F\u3044 mint?\n\thttps://loj.ac/p/138\n\
    */\ntemplate<class S, class T>\nvector<vector<T>> scary_floor_sum_simple(S N,\
    \ S a, S b, S m, int e1, int e2){\n\t// {\t// brute\n\t// \tvector<vector<T>>\
    \ res(e1+1,vector<T>(e2+1));\n\t// \tfor(S x = 0; x < N; x++){\n\t// \t\tS y =\
    \ divFloor(a*x+b, m);\n\t// \t\tvector<T> xpow(e1+1); xpow[0] = 1; rep(i,e1) xpow[i+1]\
    \ = xpow[i] * T(x);\n\t// \t\tvector<T> ypow(e2+1); ypow[0] = 1; rep(i,e2) ypow[i+1]\
    \ = ypow[i] * T(y);\n\t// \t\trep(k1,e1+1) rep(k2,e2+1){\n\t// \t\t\tres[k1][k2]\
    \ += xpow[k1] * ypow[k2];\n\t// \t\t}\n\t// \t}\n\t// \treturn res;\n\t// }\n\n\
    \tusing Data = MonoidFloorSum<T>;\n\tData::set_e1_e2(e1,e2);\n\tauto f = underpath(a,\
    \ b, m, N, Data::to_x(), Data::to_y());\n\treturn f.dp;\n}\n\n/*\n\tres[k1][k2]\
    \ = \\sum_{L <= x < R} x^k1 * floor( (ax + b) / m )^k2\n\t0 <= k1 <= e1, 0 <=\
    \ k2 <= e2\n\n\t\u8981\u8ACB\u306F m > 0, floor \u306E\u4E2D\u8EAB\u304C [L,R)\
    \ \u3067 non-negative\n\n\t\u5024\u306E\u7BC4\u56F2\u306F S, mint \u3067\u6C42\
    \u3081\u3088 \u3068\u304B\u3082\u3042\u308B\u306E\u3067\u8FD4\u308A\u5024\u306F\
    \ T\n\thttps://loj.ac/p/138\n*/\ntemplate<class S, class T>\nvector<vector<T>>\
    \ scary_floor_sum(S L, S R, S a, S b, S m, int e1, int e2){\n\tassert(L <= R);\n\
    \tassert(m > 0);\n\tassert(e1 >= 0 && e2 >= 0);\n\n\t// {\t// brute\n\t// \tvector<vector<T>>\
    \ res(e1+1,vector<T>(e2+1));\n\t// \tfor(S x = L; x < R; x++){\n\t// \t\tS y =\
    \ divFloor(a*x+b, m);\n\t// \t\tvector<T> xpow(e1+1); xpow[0] = 1; rep(i,e1) xpow[i+1]\
    \ = xpow[i] * T(x);\n\t// \t\tvector<T> ypow(e2+1); ypow[0] = 1; rep(i,e2) ypow[i+1]\
    \ = ypow[i] * T(y);\n\t// \t\trep(k1,e1+1) rep(k2,e2+1){\n\t// \t\t\tres[k1][k2]\
    \ += xpow[k1] * ypow[k2];\n\t// \t\t}\n\t// \t}\n\t// \treturn res;\n\t// }\n\n\
    \t// a >= 0 \u306B\u5909\u5F62\n\tbool a_flipped = false;\n\tif(a < 0){\n\t\t\
    a_flipped = true;\n\t\tR--;\n\t\t//  x^k1 * floor( (a * x + b) / m )^k2 \t\t\t\
    \t\t\tx \\in [L,R]\n\t\t//\t(-1)^k1 * (-x)^k1 * floor( (-a * -x + b) / m )^k2\t\
    \t-x \\in [-R,-L]\n\t\ta = -a; swap(L,R); L = -L, R = -R;\n\t\tR++;\n\t}\n\t//\
    \ L = 0 \u306B\u5909\u5F62\n\t// x \\in [L,R) => x \\in [0,R-L), (x+L)^k1...\n\
    \n\tvector<vector<T>> res(e1+1,vector<T>(e2+1));\n\n\tauto f = scary_floor_sum_simple<S,T>(R-L,\
    \ a, b+a*L, m, e1, e2);\n\n\trep(k1,e1+1) rep(k2,e2+1){\n\t\trep(i,k1+1) res[k1][k2]\
    \ += f[i][k2] * T(L).pow(k1-i) * Choose(k1,i);\n\t}\n\tif(a_flipped){\n\t\trep(k1,e1+1)\
    \ if(k1&1) rep(k2,e2+1) res[k1][k2] *= -1;\n\t}\n\treturn res;\n}\n"
  code: "/*\n\tfloor sum \u306E\u4E00\u822C\u5316\n\tMonoid T \u306E\u5143 x,y \u3068\
    \u3001 f(i) := floor((a*i + b) / m) \u304C\u4E0E\u3048\u3089\u308C\u305F\u3068\
    \u304D\u306B\u3001\n\ty^f(0) x y^(f(1)-f(0)) x y^(f(2)-f(1)) x ... x y^(f(n)-f(n-1))\
    \ \u3092\u8A08\u7B97\u3059\u308B\n\t\tx \u304C n \u500B\u3002\u6700\u521D\u3082\
    \u6700\u5F8C\u3082 y \u306E\u5217\u304C(\u4E00\u822C\u306B\u306F)\u3042\u308B\n\
    \n\ty <= (ax+b)/m \u3068\u3044\u3046\u7BC4\u56F2\u3092\u3001(0,0) \u304B\u3089\
    \ (n,[(an+b)/m]) \u307E\u3067\u3067\u304D\u308B\u3060\u3051 y \u65B9\u5411\u306B\
    \u8CAA\u6B32\u306B\u79FB\u52D5\u3059\u308B path \u3092\u8A08\u7B97\u3057\u3066\
    \u3044\u308B\u3068\u601D\u3048\u308B\n\n\n\t\u4F8B\u3048\u3070 floor sum \u306F\
    \ x \u3057\u305F\u3068\u304D\u306E\u3053\u308C\u307E\u3067\u306E y \u306E\u500B\
    \u6570 \u306E\u548C\u306A\u306E\u3067\u3001Monoid{numx,numy,num(x..y)} \u3092\u3082\
    \u3066\u3070\u8A08\u7B97\u53EF\u80FD\n\n\tO(log m)\n\n\t\u8981\u8ACB:\n\t\tMonoid\
    \ T \u304C T::e(), T::op(a,b), a.pow(p) \u3092\u6301\u3064\n\t\tan + b \u304C\u30AA\
    \u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\n\n\tverify:\n\t\tARC183\
    \ F https://atcoder.jp/contests/arc183/submissions/57122721\n\t\tLOJ138 https://loj.ac/s/2146116\n\
    */\ntemplate<class S = __int128, class T>\nT underpath(S a, S b, S m, S n, T x,\
    \ T y){\n\tassert(m > 0);\n\tassert(n >= 0);\n\tassert(a >= 0);\n\tassert(b >=\
    \ 0);\n\tS c = (a*n+b)/m;\n\tT pre = T::e(), suf = T::e();\n\twhile(true){\n\t\
    \tS p = a/m; a %= m; x = T::op(x, y.pow(p));\n\t\tS q = b/m; b %= m; pre = T::op(pre,\
    \ y.pow(q));\n\t\tc -= p*n + q;\n\t\tif(c == 0) break;\n\t\tS d = (m*c - b - 1)\
    \ / a + 1;\n\t\tsuf = T::op(T::op(y, x.pow(n-d)), suf);\n\t\tb = m-b-1+a; swap(m,a);\
    \ n = c-1; c = d; swap(x,y);\n\t}\n\treturn T::op(T::op(pre, x.pow(n)), suf);\n\
    }\n\n/*\n\tscary floor sum \u306B\u4E57\u305B\u308B\u305F\u3081\u306E\u30E2\u30CE\
    \u30A4\u30C9\n\t\\sum_{0 <= x < N} x^[0,e1] * floor( (ax + b) / m )^[0,e2] \u3092\
    \u8A08\u7B97\u3067\u304D\u308B\n\n\t\u53EF\u5909 mint \u307F\u305F\u3044\u306A\
    \u611F\u3058\u3067\u3001\u4F7F\u3046\u524D\u306B set_e1_e2 \u3092\u547C\u3076\n\
    */\ntemplate<class T>\nstruct MonoidFloorSum{\n\tusing X = MonoidFloorSum;\n\t\
    static inline int e1,e2;\n\tstatic inline vector<vector<T>> comb;\n\tstatic void\
    \ set_e1_e2(int e1_, int e2_){\n\t\te1 = e1_, e2 = e2_;\n\t\tint e = max(e1,e2);\n\
    \t\tcomb = vector<vector<T>>(e+1,vector<T>(e+1));\n\t\trep(i,e+1){\n\t\t\tcomb[i][0]\
    \ = comb[i][i] = T(1);\n\t\t\trep1(j,i-1) comb[i][j] = comb[i-1][j-1] + comb[i-1][j];\n\
    \t\t}\n\t}\n\n\tMonoidFloorSum():dp(e1+1,vector<T>(e2+1)){}\n\n\tT dx, dy;\n\t\
    vector<vector<T>> dp;\n\n\tstatic X op(X a, X b){\n\t\tvector<T> xpow(e1+1); xpow[0]\
    \ = 1; rep(i,e1) xpow[i+1] = xpow[i] * a.dx;\n\t\tvector<T> ypow(e2+1); ypow[0]\
    \ = 1; rep(i,e2) ypow[i+1] = ypow[i] * a.dy;\n\n\t\trep(k1,e1+1) rep(k2,e2+1){\n\
    \t\t\trep(i1,k1+1) rep(i2,k2+1){\n\t\t\t\ta.dp[k1][k2] += b.dp[i1][i2] * comb[k1][i1]\
    \ * xpow[k1-i1] * comb[k2][i2] * ypow[k2-i2];\n\t\t\t}\n\t\t}\n\t\ta.dx += b.dx,\
    \ a.dy += b.dy;\n\t\treturn a;\n\t}\n\tX pow(ll exp) const {\n\t\tX res = X::e();\n\
    \t\tX pw = *this;\n\t\twhile(exp){\n\t\t\tif(exp&1) res = op(res,pw);\n\t\t\t\
    pw = op(pw,pw);\n\t\t\texp /= 2;\n\t\t}\n\t\treturn res;\n\t}\n\tstatic X to_x(){\n\
    \t\tX x;\n\t\tx.dp[0][0] = 1; x.dx = 1;\n\t\treturn x;\n\t}\n\tstatic X to_y(){\n\
    \t\tX x;\n\t\tx.dy = 1;\n\t\treturn x;\n\t}\n\tstatic X e(){\n\t\treturn X();\n\
    \t}\n};\n\n/*\n\tres[k1][k2] = \\sum_{0 <= x < N} x^e1 * floor( (ax + b) / m )^e2\n\
    \n\t\u8981\u8ACB: a >= 0, b >= 0, m > 0, N >= 0\n\n\t\u5024\u306E\u7BC4\u56F2\u306F\
    \ S. \u3060\u3044\u305F\u3044 __int128?\n\t\u8FD4\u308A\u5024\u306F T. \u3060\u3044\
    \u305F\u3044 mint?\n\thttps://loj.ac/p/138\n*/\ntemplate<class S, class T>\nvector<vector<T>>\
    \ scary_floor_sum_simple(S N, S a, S b, S m, int e1, int e2){\n\t// {\t// brute\n\
    \t// \tvector<vector<T>> res(e1+1,vector<T>(e2+1));\n\t// \tfor(S x = 0; x < N;\
    \ x++){\n\t// \t\tS y = divFloor(a*x+b, m);\n\t// \t\tvector<T> xpow(e1+1); xpow[0]\
    \ = 1; rep(i,e1) xpow[i+1] = xpow[i] * T(x);\n\t// \t\tvector<T> ypow(e2+1); ypow[0]\
    \ = 1; rep(i,e2) ypow[i+1] = ypow[i] * T(y);\n\t// \t\trep(k1,e1+1) rep(k2,e2+1){\n\
    \t// \t\t\tres[k1][k2] += xpow[k1] * ypow[k2];\n\t// \t\t}\n\t// \t}\n\t// \t\
    return res;\n\t// }\n\n\tusing Data = MonoidFloorSum<T>;\n\tData::set_e1_e2(e1,e2);\n\
    \tauto f = underpath(a, b, m, N, Data::to_x(), Data::to_y());\n\treturn f.dp;\n\
    }\n\n/*\n\tres[k1][k2] = \\sum_{L <= x < R} x^k1 * floor( (ax + b) / m )^k2\n\t\
    0 <= k1 <= e1, 0 <= k2 <= e2\n\n\t\u8981\u8ACB\u306F m > 0, floor \u306E\u4E2D\
    \u8EAB\u304C [L,R) \u3067 non-negative\n\n\t\u5024\u306E\u7BC4\u56F2\u306F S,\
    \ mint \u3067\u6C42\u3081\u3088 \u3068\u304B\u3082\u3042\u308B\u306E\u3067\u8FD4\
    \u308A\u5024\u306F T\n\thttps://loj.ac/p/138\n*/\ntemplate<class S, class T>\n\
    vector<vector<T>> scary_floor_sum(S L, S R, S a, S b, S m, int e1, int e2){\n\t\
    assert(L <= R);\n\tassert(m > 0);\n\tassert(e1 >= 0 && e2 >= 0);\n\n\t// {\t//\
    \ brute\n\t// \tvector<vector<T>> res(e1+1,vector<T>(e2+1));\n\t// \tfor(S x =\
    \ L; x < R; x++){\n\t// \t\tS y = divFloor(a*x+b, m);\n\t// \t\tvector<T> xpow(e1+1);\
    \ xpow[0] = 1; rep(i,e1) xpow[i+1] = xpow[i] * T(x);\n\t// \t\tvector<T> ypow(e2+1);\
    \ ypow[0] = 1; rep(i,e2) ypow[i+1] = ypow[i] * T(y);\n\t// \t\trep(k1,e1+1) rep(k2,e2+1){\n\
    \t// \t\t\tres[k1][k2] += xpow[k1] * ypow[k2];\n\t// \t\t}\n\t// \t}\n\t// \t\
    return res;\n\t// }\n\n\t// a >= 0 \u306B\u5909\u5F62\n\tbool a_flipped = false;\n\
    \tif(a < 0){\n\t\ta_flipped = true;\n\t\tR--;\n\t\t//  x^k1 * floor( (a * x +\
    \ b) / m )^k2 \t\t\t\t\t\tx \\in [L,R]\n\t\t//\t(-1)^k1 * (-x)^k1 * floor( (-a\
    \ * -x + b) / m )^k2\t\t-x \\in [-R,-L]\n\t\ta = -a; swap(L,R); L = -L, R = -R;\n\
    \t\tR++;\n\t}\n\t// L = 0 \u306B\u5909\u5F62\n\t// x \\in [L,R) => x \\in [0,R-L),\
    \ (x+L)^k1...\n\n\tvector<vector<T>> res(e1+1,vector<T>(e2+1));\n\n\tauto f =\
    \ scary_floor_sum_simple<S,T>(R-L, a, b+a*L, m, e1, e2);\n\n\trep(k1,e1+1) rep(k2,e2+1){\n\
    \t\trep(i,k1+1) res[k1][k2] += f[i][k2] * T(L).pow(k1-i) * Choose(k1,i);\n\t}\n\
    \tif(a_flipped){\n\t\trep(k1,e1+1) if(k1&1) rep(k2,e2+1) res[k1][k2] *= -1;\n\t\
    }\n\treturn res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/scary_floor_sum.hpp
  requiredBy: []
  timestamp: '2024-09-05 20:42:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/scary_floor_sum.hpp
layout: document
redirect_from:
- /library/math/scary_floor_sum.hpp
- /library/math/scary_floor_sum.hpp.html
title: math/scary_floor_sum.hpp
---
