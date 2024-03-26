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
    - https://contest.ucup.ac/submission/364008
  bundledCode: "#line 1 \"DP/CHT.cpp\"\n/*\n\tConvex Hull Trick (\u8FFD\u52A0\u3059\
    \u308B\u76F4\u7DDA\u306E\u50BE\u304D\u304C\u5358\u8ABF\u306A\u30D0\u30FC\u30B8\
    \u30E7\u30F3)\n\n\t\u521D\u671F\u5316:\n\t\tcalc_min: true \u306A\u3089 min, false\
    \ \u306A\u3089 max \u3092\u8A08\u7B97\n\t\tT: a,b,x,y \u306A\u3069\u306E\u578B\
    \n\t\ta*b \u304F\u3089\u3044\u306E\u5024\u304C\u4E00\u7B87\u6240\u3060\u3051\u51FA\
    \u3066\u304F\u308B \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u306B\u6CE8\u610F\
    \n\tadd(a,b):\n\t\t\u76F4\u7DDA y = ax+b \u3092\u8FFD\u52A0\n\t\ta\u306F\u5E83\
    \u7FA9\u5358\u8ABF\u5897\u52A0\u3042\u308B\u3044\u306F\u5E83\u7FA9\u5358\u8ABF\
    \u6E1B\u5C11 \u52DD\u624B\u306B\u5224\u65AD\u3057\u3066\u304F\u308C\u308B\n\t\
    get(x):\n\t\tmin (\u3042\u308B\u3044\u306Fmax) {ax+b}\n\t\t\u521D\u671F\u5316\u6642\
    \u306Btemplate\u5F15\u6570\u3067min\u304Bmax\u304B\u6307\u5B9A\n\t\tO(log N)\n\
    \tget_incr / get_decr\n\t\tget\u306E\u30AF\u30A8\u30EA\u306B\u5358\u8ABF\u6027\
    \u304C\u3042\u308B\u5834\u5408 amortized O(1)\n\t\t\u5ACC\u3060\u3068\u601D\u3046\
    \u3093\u3060\u3051\u3069\u3001CHT_old \u3092\u4F7F\u3063\u3066\u307B\u3057\u3044\
    \ \u3054\u3081\u3093\n\n\tverify:\n\t\thttps://contest.ucup.ac/submission/364008\n\
    */\n\ntemplate<bool calc_min, typename T>\nstruct ConvexHullTrick{\n\tusing P\
    \ = pair<T,T>;\n\tdeque<P> q;\n\tConvexHullTrick() {}\n\tvoid add(T a, T b){\n\
    \t\tif(!calc_min) a = -a, b = -b;\n\t\tP p(a,b);\n\t\tif(q.empty()){\n\t\t\tq.push_back(p);\
    \ return;\n\t\t}\n\t\tif(q.back().fs >= a){\n\t\t\tif(a == q.back().fs){\n\t\t\
    \t\tif(q.back().sc <= b) return;\n\t\t\t\tq.pop_back();\n\t\t\t}\n\t\t\twhile(si(q)\
    \ >= 2 && !necessary(q[si(q)-2],q.back(),p)){\n\t\t\t\tq.pop_back();\n\t\t\t}\n\
    \t\t\tq.push_back(p);\n\t\t}else if(a >= q.front().fs){\n\t\t\tif(a == q.front().fs){\n\
    \t\t\t\tif(q.front().sc <= b) return;\n\t\t\t\tq.pop_front();\n\t\t\t}\n\t\t\t\
    while(si(q) >= 2 && !necessary(p,q.front(),q[1])){\n\t\t\t\tq.pop_front();\n\t\
    \t\t}\n\t\t\tq.push_front(p);\n\t\t}else{\n\t\t\tassert(false); // a\u304C\u5358\
    \u8ABF\u3067\u306A\u3044\n\t\t}\n\t}\n\tbool necessary(P l, P m, P r){\n\t\t//\
    \ m \u304C\u6700\u5C0F\u5024\u3092\u53D6\u308B\u3053\u3068\u304C\u3042\u308B\u304B\
    ?\n\t\t// assume: \u50BE\u304D la > ma > ra\n\t\tassert(l.fs > m.fs && m.fs >\
    \ r.fs);\n\t\t// (mb-lb)/(la-ma) < (rb-mb)/(ma-ra) \u5206\u6BCD\u306F\u5171\u306B\
    \u6B63\n\t\t// \u901A\u5206\u3059\u308B\u3068 a*b \u304F\u3089\u3044\u306E\u5024\
    \u304C\u767B\u5834\u3059\u308B \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u306B\
    \u6CE8\u610F\n\t\t// int128\u306B\u3059\u3089\u5165\u3089\u306A\u3051\u308C\u3070\
    \u5E2F\u5206\u6570\u307F\u305F\u3044\u306B\u3084\u308B\u306E\u3082\u3042\u308A\
    \n\t\treturn (m.sc-l.sc) * (m.fs-r.fs) < (r.sc-m.sc) * (l.fs-m.fs);\n\t}\n\tT\
    \ get(T x){\n\t\tassert(!q.empty());\n\t\tauto f_i = [&](int i){ return q[i].fs\
    \ * x + q[i].sc; };\n\t\tint l = 0, r = si(q);\n\t\twhile(r-l > 1){\n\t\t\tint\
    \ m = (l+r)/2;\n\t\t\tif(f_i(m-1) <= f_i(m)) r = m;\n\t\t\telse l = m;\n\t\t}\n\
    \t\treturn f_i(l) * (calc_min ? 1 : -1);\n\t}\n};\n"
  code: "/*\n\tConvex Hull Trick (\u8FFD\u52A0\u3059\u308B\u76F4\u7DDA\u306E\u50BE\
    \u304D\u304C\u5358\u8ABF\u306A\u30D0\u30FC\u30B8\u30E7\u30F3)\n\n\t\u521D\u671F\
    \u5316:\n\t\tcalc_min: true \u306A\u3089 min, false \u306A\u3089 max \u3092\u8A08\
    \u7B97\n\t\tT: a,b,x,y \u306A\u3069\u306E\u578B\n\t\ta*b \u304F\u3089\u3044\u306E\
    \u5024\u304C\u4E00\u7B87\u6240\u3060\u3051\u51FA\u3066\u304F\u308B \u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u306B\u6CE8\u610F\n\tadd(a,b):\n\t\t\u76F4\u7DDA\
    \ y = ax+b \u3092\u8FFD\u52A0\n\t\ta\u306F\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\
    \u3042\u308B\u3044\u306F\u5E83\u7FA9\u5358\u8ABF\u6E1B\u5C11 \u52DD\u624B\u306B\
    \u5224\u65AD\u3057\u3066\u304F\u308C\u308B\n\tget(x):\n\t\tmin (\u3042\u308B\u3044\
    \u306Fmax) {ax+b}\n\t\t\u521D\u671F\u5316\u6642\u306Btemplate\u5F15\u6570\u3067\
    min\u304Bmax\u304B\u6307\u5B9A\n\t\tO(log N)\n\tget_incr / get_decr\n\t\tget\u306E\
    \u30AF\u30A8\u30EA\u306B\u5358\u8ABF\u6027\u304C\u3042\u308B\u5834\u5408 amortized\
    \ O(1)\n\t\t\u5ACC\u3060\u3068\u601D\u3046\u3093\u3060\u3051\u3069\u3001CHT_old\
    \ \u3092\u4F7F\u3063\u3066\u307B\u3057\u3044 \u3054\u3081\u3093\n\n\tverify:\n\
    \t\thttps://contest.ucup.ac/submission/364008\n*/\n\ntemplate<bool calc_min, typename\
    \ T>\nstruct ConvexHullTrick{\n\tusing P = pair<T,T>;\n\tdeque<P> q;\n\tConvexHullTrick()\
    \ {}\n\tvoid add(T a, T b){\n\t\tif(!calc_min) a = -a, b = -b;\n\t\tP p(a,b);\n\
    \t\tif(q.empty()){\n\t\t\tq.push_back(p); return;\n\t\t}\n\t\tif(q.back().fs >=\
    \ a){\n\t\t\tif(a == q.back().fs){\n\t\t\t\tif(q.back().sc <= b) return;\n\t\t\
    \t\tq.pop_back();\n\t\t\t}\n\t\t\twhile(si(q) >= 2 && !necessary(q[si(q)-2],q.back(),p)){\n\
    \t\t\t\tq.pop_back();\n\t\t\t}\n\t\t\tq.push_back(p);\n\t\t}else if(a >= q.front().fs){\n\
    \t\t\tif(a == q.front().fs){\n\t\t\t\tif(q.front().sc <= b) return;\n\t\t\t\t\
    q.pop_front();\n\t\t\t}\n\t\t\twhile(si(q) >= 2 && !necessary(p,q.front(),q[1])){\n\
    \t\t\t\tq.pop_front();\n\t\t\t}\n\t\t\tq.push_front(p);\n\t\t}else{\n\t\t\tassert(false);\
    \ // a\u304C\u5358\u8ABF\u3067\u306A\u3044\n\t\t}\n\t}\n\tbool necessary(P l,\
    \ P m, P r){\n\t\t// m \u304C\u6700\u5C0F\u5024\u3092\u53D6\u308B\u3053\u3068\u304C\
    \u3042\u308B\u304B?\n\t\t// assume: \u50BE\u304D la > ma > ra\n\t\tassert(l.fs\
    \ > m.fs && m.fs > r.fs);\n\t\t// (mb-lb)/(la-ma) < (rb-mb)/(ma-ra) \u5206\u6BCD\
    \u306F\u5171\u306B\u6B63\n\t\t// \u901A\u5206\u3059\u308B\u3068 a*b \u304F\u3089\
    \u3044\u306E\u5024\u304C\u767B\u5834\u3059\u308B \u30AA\u30FC\u30D0\u30FC\u30D5\
    \u30ED\u30FC\u306B\u6CE8\u610F\n\t\t// int128\u306B\u3059\u3089\u5165\u3089\u306A\
    \u3051\u308C\u3070\u5E2F\u5206\u6570\u307F\u305F\u3044\u306B\u3084\u308B\u306E\
    \u3082\u3042\u308A\n\t\treturn (m.sc-l.sc) * (m.fs-r.fs) < (r.sc-m.sc) * (l.fs-m.fs);\n\
    \t}\n\tT get(T x){\n\t\tassert(!q.empty());\n\t\tauto f_i = [&](int i){ return\
    \ q[i].fs * x + q[i].sc; };\n\t\tint l = 0, r = si(q);\n\t\twhile(r-l > 1){\n\t\
    \t\tint m = (l+r)/2;\n\t\t\tif(f_i(m-1) <= f_i(m)) r = m;\n\t\t\telse l = m;\n\
    \t\t}\n\t\treturn f_i(l) * (calc_min ? 1 : -1);\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: DP/CHT.cpp
  requiredBy: []
  timestamp: '2024-03-26 10:57:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/CHT.cpp
layout: document
redirect_from:
- /library/DP/CHT.cpp
- /library/DP/CHT.cpp.html
title: DP/CHT.cpp
---
