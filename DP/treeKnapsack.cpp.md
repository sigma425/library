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
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1631
  bundledCode: "#line 1 \"DP/treeKnapsack.cpp\"\n/*\n\tV<ll> treeKnapsack(VV<int>\
    \ G, V<Item> items, int W)\n\n\tinput:\n\t\tG: \u6728 N \u9802\u70B9\n\t\titems:\
    \ (w,p,n) \u304C N \u500B\n\t\tW: \u91CD\u3055\u306E\u4E0A\u9650\n\toutput:\n\t\
    \tdp[w] = \u3061\u3087\u3046\u3069\u91CD\u307F w \u306E\u3068\u304D\u306E\u4FA1\
    \u5024\u306E\u6700\u5927\u5024\n\n\t\u9802\u70B9 v \u306B\u306F\u91CD\u3055 w,\
    \ \u4FA1\u5024 p \u306E\u3082\u306E\u304C n \u500B\u304A\u3044\u3066\u3042\u308A\
    \u3001n \u500B\u5168\u3066\u4F7F\u3044\u5207\u3089\u306A\u3044\u9650\u308A\u90E8\
    \u5206\u6728\u306F\u4F7F\u3048\u306A\u3044\n\tO(NW)\n\t\u9577\u3055 W+1 \u306E\
    vector \u3092 N \u56DE\u751F\u6210\u3057\u3066\u308B\u3068\u3053\u304C\u3082\u3063\
    \u3068\u91CD\u305D\u3046\u3060\u304C\u3001\u6D88\u3057\u65B9\u304C\u308F\u304B\
    \u3089\u306D\u3048\n\tverify: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1631\n\
    */\n\nnamespace SlideMax{\n\tusing D = ll;\n\tconst int X = 1000000;\n\tD a[X];\n\
    \tint idx[X];\n\tint L,R,I,num_del;\n\tvoid clear(){\n\t\tL = R = I = num_del\
    \ = 0;\n\t}\n\tvoid add(D v){\n\t\twhile(L<R && v>a[R-1]) R--;\t\t\t// D-D comparison\
    \ v<a[R-1]\n\t\ta[R] = v;\n\t\tidx[R] = I;\n\t\tR++,I++;\n\t}\n\tvoid del(){\n\
    \t\tif(L<R && idx[L] == num_del) L++;\n\t\tnum_del++;\n\t}\n\tD getmax(){\n\t\t\
    assert(L<R);\n\t\treturn a[L];\n\t}\n\tint getargmax(){\n\t\tassert(L<R);\n\t\t\
    return idx[L];\n\t}\n}\nconst ll inf = TEN(18);\nstruct Item{\n\t// \u91CD\u3055\
    w, \u4FA1\u5024p \u306E\u7269\u4F53\u304C n\u500B\n\t// n\u500B\u5168\u90E8\u4F7F\
    \u3044\u5207\u308B\u3068\u4E0B\u306E\u9802\u70B9\u3092\u4F7F\u3048\u308B\u3088\
    \u3046\u306B\u306A\u308B\n\tint w; ll p; int n;\n\tfriend ostream& operator<<(ostream\
    \ &o,const Item& x){ return o<<\"(\"<<x.w<<\",\"<<x.p<<\" * \" << x.n << \")\"\
    ;}\n};\nvoid slide(V<ll>& f, int w, ll p, int n){\n\tint W = si(f)-1;\n\trep(r,w){\n\
    \t\tSlideMax::clear();\n\t\tif(r > W) break;\n\t\tfor(int i=0,x=r;x<=W;i++,x+=w){\n\
    \t\t\tSlideMax::add(f[x]-i*p);\n\t\t\tf[x] = SlideMax::getmax() + i*p;\n\t\t\t\
    if(f[x] < -inf/2) f[x] = -inf;\n\t\t\tif(i >= n) SlideMax::del();\n\t\t}\n\t}\n\
    }\n\nV<ll> treeKnapsack(VV<int> G, V<Item> items, int W){\n\tassert(si(G) == si(items));\n\
    \tauto rec = [&](auto& self, int v, int p, V<ll>& dp_init)->void{\n\t\tV<ll> dp(W+1,-inf);\n\
    \t\tauto& f = items[v];\n\t\tfor(ll i=0; i+ll(f.w)*f.n<=W; i++){\n\t\t\tif(dp_init[i]\
    \ != -inf) dp[i+f.w*f.n] = dp_init[i] + f.p * f.n;\n\t\t}\n\t\tfor(int u: G[v])\
    \ if(u != p){\n\t\t\tself(self,u,v,dp);\n\t\t}\n\t\tslide(dp_init,f.w,f.p,f.n);\t\
    // <= n\n\t\trep(i,W+1) chmax(dp[i], dp_init[i]);\n\t\tdp_init = dp;\n\t};\n\t\
    V<ll> dp(W+1,-inf); dp[0] = 0;\n\trec(rec,0,-1,dp); return dp;\n}\n"
  code: "/*\n\tV<ll> treeKnapsack(VV<int> G, V<Item> items, int W)\n\n\tinput:\n\t\
    \tG: \u6728 N \u9802\u70B9\n\t\titems: (w,p,n) \u304C N \u500B\n\t\tW: \u91CD\u3055\
    \u306E\u4E0A\u9650\n\toutput:\n\t\tdp[w] = \u3061\u3087\u3046\u3069\u91CD\u307F\
    \ w \u306E\u3068\u304D\u306E\u4FA1\u5024\u306E\u6700\u5927\u5024\n\n\t\u9802\u70B9\
    \ v \u306B\u306F\u91CD\u3055 w, \u4FA1\u5024 p \u306E\u3082\u306E\u304C n \u500B\
    \u304A\u3044\u3066\u3042\u308A\u3001n \u500B\u5168\u3066\u4F7F\u3044\u5207\u3089\
    \u306A\u3044\u9650\u308A\u90E8\u5206\u6728\u306F\u4F7F\u3048\u306A\u3044\n\tO(NW)\n\
    \t\u9577\u3055 W+1 \u306Evector \u3092 N \u56DE\u751F\u6210\u3057\u3066\u308B\u3068\
    \u3053\u304C\u3082\u3063\u3068\u91CD\u305D\u3046\u3060\u304C\u3001\u6D88\u3057\
    \u65B9\u304C\u308F\u304B\u3089\u306D\u3048\n\tverify: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1631\n\
    */\n\nnamespace SlideMax{\n\tusing D = ll;\n\tconst int X = 1000000;\n\tD a[X];\n\
    \tint idx[X];\n\tint L,R,I,num_del;\n\tvoid clear(){\n\t\tL = R = I = num_del\
    \ = 0;\n\t}\n\tvoid add(D v){\n\t\twhile(L<R && v>a[R-1]) R--;\t\t\t// D-D comparison\
    \ v<a[R-1]\n\t\ta[R] = v;\n\t\tidx[R] = I;\n\t\tR++,I++;\n\t}\n\tvoid del(){\n\
    \t\tif(L<R && idx[L] == num_del) L++;\n\t\tnum_del++;\n\t}\n\tD getmax(){\n\t\t\
    assert(L<R);\n\t\treturn a[L];\n\t}\n\tint getargmax(){\n\t\tassert(L<R);\n\t\t\
    return idx[L];\n\t}\n}\nconst ll inf = TEN(18);\nstruct Item{\n\t// \u91CD\u3055\
    w, \u4FA1\u5024p \u306E\u7269\u4F53\u304C n\u500B\n\t// n\u500B\u5168\u90E8\u4F7F\
    \u3044\u5207\u308B\u3068\u4E0B\u306E\u9802\u70B9\u3092\u4F7F\u3048\u308B\u3088\
    \u3046\u306B\u306A\u308B\n\tint w; ll p; int n;\n\tfriend ostream& operator<<(ostream\
    \ &o,const Item& x){ return o<<\"(\"<<x.w<<\",\"<<x.p<<\" * \" << x.n << \")\"\
    ;}\n};\nvoid slide(V<ll>& f, int w, ll p, int n){\n\tint W = si(f)-1;\n\trep(r,w){\n\
    \t\tSlideMax::clear();\n\t\tif(r > W) break;\n\t\tfor(int i=0,x=r;x<=W;i++,x+=w){\n\
    \t\t\tSlideMax::add(f[x]-i*p);\n\t\t\tf[x] = SlideMax::getmax() + i*p;\n\t\t\t\
    if(f[x] < -inf/2) f[x] = -inf;\n\t\t\tif(i >= n) SlideMax::del();\n\t\t}\n\t}\n\
    }\n\nV<ll> treeKnapsack(VV<int> G, V<Item> items, int W){\n\tassert(si(G) == si(items));\n\
    \tauto rec = [&](auto& self, int v, int p, V<ll>& dp_init)->void{\n\t\tV<ll> dp(W+1,-inf);\n\
    \t\tauto& f = items[v];\n\t\tfor(ll i=0; i+ll(f.w)*f.n<=W; i++){\n\t\t\tif(dp_init[i]\
    \ != -inf) dp[i+f.w*f.n] = dp_init[i] + f.p * f.n;\n\t\t}\n\t\tfor(int u: G[v])\
    \ if(u != p){\n\t\t\tself(self,u,v,dp);\n\t\t}\n\t\tslide(dp_init,f.w,f.p,f.n);\t\
    // <= n\n\t\trep(i,W+1) chmax(dp[i], dp_init[i]);\n\t\tdp_init = dp;\n\t};\n\t\
    V<ll> dp(W+1,-inf); dp[0] = 0;\n\trec(rec,0,-1,dp); return dp;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/treeKnapsack.cpp
  requiredBy: []
  timestamp: '2021-10-15 01:21:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/treeKnapsack.cpp
layout: document
redirect_from:
- /library/DP/treeKnapsack.cpp
- /library/DP/treeKnapsack.cpp.html
title: DP/treeKnapsack.cpp
---
