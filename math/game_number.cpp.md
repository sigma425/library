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
  bundledCode: "#line 1 \"math/game_number.cpp\"\n/*\n\t\u975E\u4E0D\u504F\u30B2\u30FC\
    \u30E0\u3092\u6570\u3068\u307F\u306A\u305B\u308B\u5834\u5408\u304C\u3042\u308B\
    \n\t\u518D\u5E30\u7684\u306B left\u9078\u629E\u80A2\u306E\u3046\u3061max < right\u9078\
    \u629E\u80A2\u306E\u3046\u3061min \u304C\u6210\u308A\u7ACB\u3063\u3066\u308C\u3070\
    \u305D\u3046\u306A\u308B\n\t\u3053\u306E\u3068\u304D\u306E\u5024\u306F\u3001(lmax,rmin)\
    \ \u306E\u3046\u3061\u6700\u3082\u5358\u7D14\u306A\u6570\n\t\u7279\u306B\u3001\
    right\u9078\u629E\u80A2\u304C\u306A\u3044\u5834\u5408\u306F(lmax,\\infty) \u306E\
    \u3046\u3061\u30FB\u30FB\u30FB\n\n\t\u5358\u7D14:\n\t\t\u6574\u6570\u306F\u7D76\
    \u5BFE\u5024\u304C\u5C0F\u3055\u3044\u65B9\u304C\u5358\u7D14\n\t\t\u6574\u6570\
    \u3092\u542B\u307E\u306A\u3044\u533A\u9593\u306A\u3089\u3001m/2\u3079\u304D \u3068\
    \u8868\u3057\u305F\u3068\u304D\u306E\u51AA\u6570\u304C\u5C11\u306A\u3044\u3082\
    \u306E\u304C\u5358\u7D14\n\n\t\u4F8B\n\t{|} = 0, {0|} = 1, {2|} = 3, {-2|} = 0\n\
    \t{-3 | -2} = -5/2\n\n\t{0|0} = * nim\u306E1 \u6570\u3067\u306F\u306A\u3044\n\n\
    \tx/2^30 \u306E\u5F62\u3067\u6301\u3064\u3000\u5B9F\u9A13\u7528\u306E\u30E9\u30A4\
    \u30D6\u30E9\u30EA\u3068\u3044\u3046\u3053\u3068\u3067\n\n\tle = -inf, ri = inf;\n\
    \tfor(l: le_cand) chmax(le,l)\n\tfor(r: ri_cand) chmin(ri,r)\n\treturn getNum(le,ri)\n\
    */\nusing Num = ll;\nconst int H = 30;\nconst ll B = 1LL<<H;\nconst Num inf =\
    \ 1LL<<60;\n\nNum getNum(Num l, Num r){\n\tassert(l < r);\t\t\t// if so, this\
    \ is not a number\n\tll l0 = divFloor(l,B)*B+B;\n\tll r0 = divCeil(r,B)*B-B;\n\
    \tif(l0 <= r0){\n\t\tif(l0 <= 0 && 0 <= r0) return 0;\n\t\tif(0 <= l0) return\
    \ l0;\n\t\tif(r0 <= 0) return r0;\n\t}\n\tper(h,H){\n\t\tll b = 1LL<<h;\n\t\t\
    ll lh = divFloor(l,b)*b+b;\n\t\tll rh = divCeil(r,b)*b-b;\n\t\tif(lh <= rh){\n\
    \t\t\tassert(lh == rh);\n\t\t\treturn lh;\n\t\t}\n\t}\n\tassert(0);\n};\nvoid\
    \ showNum(Num x){\n\tll g = __gcd(abs(x),B);\n\tcerr << x/g << \"/\" << B/g;\n\
    }\n"
  code: "/*\n\t\u975E\u4E0D\u504F\u30B2\u30FC\u30E0\u3092\u6570\u3068\u307F\u306A\u305B\
    \u308B\u5834\u5408\u304C\u3042\u308B\n\t\u518D\u5E30\u7684\u306B left\u9078\u629E\
    \u80A2\u306E\u3046\u3061max < right\u9078\u629E\u80A2\u306E\u3046\u3061min \u304C\
    \u6210\u308A\u7ACB\u3063\u3066\u308C\u3070\u305D\u3046\u306A\u308B\n\t\u3053\u306E\
    \u3068\u304D\u306E\u5024\u306F\u3001(lmax,rmin) \u306E\u3046\u3061\u6700\u3082\
    \u5358\u7D14\u306A\u6570\n\t\u7279\u306B\u3001right\u9078\u629E\u80A2\u304C\u306A\
    \u3044\u5834\u5408\u306F(lmax,\\infty) \u306E\u3046\u3061\u30FB\u30FB\u30FB\n\n\
    \t\u5358\u7D14:\n\t\t\u6574\u6570\u306F\u7D76\u5BFE\u5024\u304C\u5C0F\u3055\u3044\
    \u65B9\u304C\u5358\u7D14\n\t\t\u6574\u6570\u3092\u542B\u307E\u306A\u3044\u533A\
    \u9593\u306A\u3089\u3001m/2\u3079\u304D \u3068\u8868\u3057\u305F\u3068\u304D\u306E\
    \u51AA\u6570\u304C\u5C11\u306A\u3044\u3082\u306E\u304C\u5358\u7D14\n\n\t\u4F8B\
    \n\t{|} = 0, {0|} = 1, {2|} = 3, {-2|} = 0\n\t{-3 | -2} = -5/2\n\n\t{0|0} = *\
    \ nim\u306E1 \u6570\u3067\u306F\u306A\u3044\n\n\tx/2^30 \u306E\u5F62\u3067\u6301\
    \u3064\u3000\u5B9F\u9A13\u7528\u306E\u30E9\u30A4\u30D6\u30E9\u30EA\u3068\u3044\
    \u3046\u3053\u3068\u3067\n\n\tle = -inf, ri = inf;\n\tfor(l: le_cand) chmax(le,l)\n\
    \tfor(r: ri_cand) chmin(ri,r)\n\treturn getNum(le,ri)\n*/\nusing Num = ll;\nconst\
    \ int H = 30;\nconst ll B = 1LL<<H;\nconst Num inf = 1LL<<60;\n\nNum getNum(Num\
    \ l, Num r){\n\tassert(l < r);\t\t\t// if so, this is not a number\n\tll l0 =\
    \ divFloor(l,B)*B+B;\n\tll r0 = divCeil(r,B)*B-B;\n\tif(l0 <= r0){\n\t\tif(l0\
    \ <= 0 && 0 <= r0) return 0;\n\t\tif(0 <= l0) return l0;\n\t\tif(r0 <= 0) return\
    \ r0;\n\t}\n\tper(h,H){\n\t\tll b = 1LL<<h;\n\t\tll lh = divFloor(l,b)*b+b;\n\t\
    \tll rh = divCeil(r,b)*b-b;\n\t\tif(lh <= rh){\n\t\t\tassert(lh == rh);\n\t\t\t\
    return lh;\n\t\t}\n\t}\n\tassert(0);\n};\nvoid showNum(Num x){\n\tll g = __gcd(abs(x),B);\n\
    \tcerr << x/g << \"/\" << B/g;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/game_number.cpp
  requiredBy: []
  timestamp: '2022-11-15 14:36:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/game_number.cpp
layout: document
redirect_from:
- /library/math/game_number.cpp
- /library/math/game_number.cpp.html
title: math/game_number.cpp
---
