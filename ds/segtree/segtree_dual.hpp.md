---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_oj/segtree/range_affine_point_get.test.cpp
    title: test_oj/segtree/range_affine_point_get.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/segtree/segtree_dual.hpp\"\n/*\r\n\trange apply + point\
    \ get segtree\r\n\r\n\tlazy segtree \u306E\u4F5C\u7528\u3060\u3051\u3092\u6301\
    \u3063\u3066\u308B\u3084\u3064\u3000\u305F\u3060\u3001\u5358\u306B \u533A\u9593\
    add + \u70B9\u53D6\u5F97 \u307F\u305F\u3044\u306A\u306E\u306B\u3082\u4F7F\u3048\
    \u308B\r\n\t- \u4F5C\u7528\u3060\u3051\u3092\u3082\u3063\u3066\u308B lazy segtree\
    \ \u3068\u307F\u306A\u3059\r\n\t\tas[k] + q1 + q3 + q4 \u307F\u305F\u3044\u306B\
    \u6765\u305F\u30AF\u30A8\u30EA\u9806\u306B\u8DB3\u3057\u3066\u3044\u3063\u305F\
    \u3082\u306E\u3092\u3061\u3083\u3093\u3068\u53D6\u5F97\u3067\u304D\u308B\u5FC5\
    \u8981\u304C\u3042\u308A\u3001\u305D\u3046\u306A\u3063\u3066\u3044\u308B\r\n\t\
    \t\u9593\u9055\u3048\u3066\u521D\u671F\u5316\u3067 lazy segtree \u3067\u3044\u3046\
    \ D \u306E\u65B9\u3092\u4E0E\u3048\u306A\u3044\u3053\u3068\r\n\t\t(\u4F8B: x ->\
    \ ax + b \u304C range query \u3067\u6765\u308B\u3068\u3057\u3066\u3001\u521D\u671F\
    \u5024\u306B x_i \u3092\u4E0E\u3048\u308B\u306E\u306F\u304A\u304B\u3057\u3044\
    , \u5358\u306B\u4F5C\u7528\u306E\u5358\u4F4D\u5143(1,0)\u304C\u521D\u671F\u5024\
    )\r\n\t- \u533A\u9593add + \u70B9\u53D6\u5F97\r\n\t\t\u4F8B\u3048\u3070\u5358\u306B\
    \u533A\u9593\u306B +=v, \u70B9\u53D6\u5F97 \u3060\u3068\u4F5C\u7528\u3068\u3044\
    \u3046\u611F\u3058\u306F\u5168\u304F\u3057\u306A\u3044\u304C\u3001\u3053\u308C\
    \u3092\u4F7F\u3063\u3066\u304F\u3060\u3055\u3044\r\n\t\r\n\t- A get(int k)\r\n\
    \t- void apply(int a, int b, A a)\r\n*/\r\ntemplate<class A>\r\nstruct SegtreeDual{\r\
    \n\tint N,lg;\r\n\tvector<A> lazy;\r\n\r\n\tSegtreeDual(){}\r\n\tSegtreeDual(int\
    \ n){\r\n\t\tN = 1; while(N < n){N *= 2, lg++;}\r\n\t\tlazy.assign(N*2, A());\r\
    \n\t}\r\n\ttemplate<class Alike>\r\n\tSegtreeDual(const vector<Alike>& as){\r\n\
    \t\tint n = as.size();\r\n\t\tN = 1; while(N < n){N *= 2, lg++;}\r\n\t\tlazy.assign(N*2,\
    \ A());\r\n\t\trep(i,n) lazy[i+N] = as[i];\r\n\t}\r\n\tA get(int i){\r\n\t\ti\
    \ += N;\r\n\t\tfor(int h=lg;h>=1;h--) push(i >> h);\r\n\t\treturn lazy[i];\r\n\
    \t}\r\n\tvoid apply(int l, int r, A a){\r\n\t\tl += N, r += N;\r\n\t\tfor(int\
    \ h = lg; h >= 1; h--){\r\n\t\t\tif(((l>>h)<<h) != l) push(l >> h);\r\n\t\t\t\
    if(((r>>h)<<h) != r) push((r-1) >> h);\r\n\t\t}\r\n\t\twhile(l < r){\r\n\t\t\t\
    if(l&1) all_apply(l++, a);\r\n\t\t\tif(r&1) all_apply(--r, a);\r\n\t\t\tl >>=\
    \ 1, r >>= 1;\r\n\t\t}\r\n\t}\r\n\tprivate:\r\n\tvoid push(int k){\r\n\t\tall_apply(k*2,\
    \ lazy[k]); all_apply(k*2+1, lazy[k]);\r\n\t\tlazy[k] = A();\r\n\t}\r\n\tvoid\
    \ all_apply(int k, A a){\r\n\t\tlazy[k] = A::op(a,lazy[k]);\t// \u4E0A\u306E\u968E\
    \u5C64\u306E lazy (a) \u306E\u307B\u3046\u304C\u3088\u308A\u5F8C\r\n\t}\r\n};\r\
    \n\r\n// struct D{\r\n// \tint v;\r\n// \tD(){ *this = e(); }\r\n// \tD(int v_):v(v_){}\r\
    \n// \tstatic D op(const D& x,const D& y){\r\n// \t\treturn D(x.v+y.v);\r\n//\
    \ \t}\r\n// \tconst static D e(){\r\n// \t\treturn D(0);\r\n// \t}\r\n// //\t\
    friend ostream& operator<<(ostream& o,const D& d){return o<<d.v;}\r\n// };\r\n"
  code: "/*\r\n\trange apply + point get segtree\r\n\r\n\tlazy segtree \u306E\u4F5C\
    \u7528\u3060\u3051\u3092\u6301\u3063\u3066\u308B\u3084\u3064\u3000\u305F\u3060\
    \u3001\u5358\u306B \u533A\u9593add + \u70B9\u53D6\u5F97 \u307F\u305F\u3044\u306A\
    \u306E\u306B\u3082\u4F7F\u3048\u308B\r\n\t- \u4F5C\u7528\u3060\u3051\u3092\u3082\
    \u3063\u3066\u308B lazy segtree \u3068\u307F\u306A\u3059\r\n\t\tas[k] + q1 + q3\
    \ + q4 \u307F\u305F\u3044\u306B\u6765\u305F\u30AF\u30A8\u30EA\u9806\u306B\u8DB3\
    \u3057\u3066\u3044\u3063\u305F\u3082\u306E\u3092\u3061\u3083\u3093\u3068\u53D6\
    \u5F97\u3067\u304D\u308B\u5FC5\u8981\u304C\u3042\u308A\u3001\u305D\u3046\u306A\
    \u3063\u3066\u3044\u308B\r\n\t\t\u9593\u9055\u3048\u3066\u521D\u671F\u5316\u3067\
    \ lazy segtree \u3067\u3044\u3046 D \u306E\u65B9\u3092\u4E0E\u3048\u306A\u3044\
    \u3053\u3068\r\n\t\t(\u4F8B: x -> ax + b \u304C range query \u3067\u6765\u308B\
    \u3068\u3057\u3066\u3001\u521D\u671F\u5024\u306B x_i \u3092\u4E0E\u3048\u308B\u306E\
    \u306F\u304A\u304B\u3057\u3044, \u5358\u306B\u4F5C\u7528\u306E\u5358\u4F4D\u5143\
    (1,0)\u304C\u521D\u671F\u5024)\r\n\t- \u533A\u9593add + \u70B9\u53D6\u5F97\r\n\
    \t\t\u4F8B\u3048\u3070\u5358\u306B\u533A\u9593\u306B +=v, \u70B9\u53D6\u5F97 \u3060\
    \u3068\u4F5C\u7528\u3068\u3044\u3046\u611F\u3058\u306F\u5168\u304F\u3057\u306A\
    \u3044\u304C\u3001\u3053\u308C\u3092\u4F7F\u3063\u3066\u304F\u3060\u3055\u3044\
    \r\n\t\r\n\t- A get(int k)\r\n\t- void apply(int a, int b, A a)\r\n*/\r\ntemplate<class\
    \ A>\r\nstruct SegtreeDual{\r\n\tint N,lg;\r\n\tvector<A> lazy;\r\n\r\n\tSegtreeDual(){}\r\
    \n\tSegtreeDual(int n){\r\n\t\tN = 1; while(N < n){N *= 2, lg++;}\r\n\t\tlazy.assign(N*2,\
    \ A());\r\n\t}\r\n\ttemplate<class Alike>\r\n\tSegtreeDual(const vector<Alike>&\
    \ as){\r\n\t\tint n = as.size();\r\n\t\tN = 1; while(N < n){N *= 2, lg++;}\r\n\
    \t\tlazy.assign(N*2, A());\r\n\t\trep(i,n) lazy[i+N] = as[i];\r\n\t}\r\n\tA get(int\
    \ i){\r\n\t\ti += N;\r\n\t\tfor(int h=lg;h>=1;h--) push(i >> h);\r\n\t\treturn\
    \ lazy[i];\r\n\t}\r\n\tvoid apply(int l, int r, A a){\r\n\t\tl += N, r += N;\r\
    \n\t\tfor(int h = lg; h >= 1; h--){\r\n\t\t\tif(((l>>h)<<h) != l) push(l >> h);\r\
    \n\t\t\tif(((r>>h)<<h) != r) push((r-1) >> h);\r\n\t\t}\r\n\t\twhile(l < r){\r\
    \n\t\t\tif(l&1) all_apply(l++, a);\r\n\t\t\tif(r&1) all_apply(--r, a);\r\n\t\t\
    \tl >>= 1, r >>= 1;\r\n\t\t}\r\n\t}\r\n\tprivate:\r\n\tvoid push(int k){\r\n\t\
    \tall_apply(k*2, lazy[k]); all_apply(k*2+1, lazy[k]);\r\n\t\tlazy[k] = A();\r\n\
    \t}\r\n\tvoid all_apply(int k, A a){\r\n\t\tlazy[k] = A::op(a,lazy[k]);\t// \u4E0A\
    \u306E\u968E\u5C64\u306E lazy (a) \u306E\u307B\u3046\u304C\u3088\u308A\u5F8C\r\
    \n\t}\r\n};\r\n\r\n// struct D{\r\n// \tint v;\r\n// \tD(){ *this = e(); }\r\n\
    // \tD(int v_):v(v_){}\r\n// \tstatic D op(const D& x,const D& y){\r\n// \t\t\
    return D(x.v+y.v);\r\n// \t}\r\n// \tconst static D e(){\r\n// \t\treturn D(0);\r\
    \n// \t}\r\n// //\tfriend ostream& operator<<(ostream& o,const D& d){return o<<d.v;}\r\
    \n// };\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/segtree_dual.hpp
  requiredBy: []
  timestamp: '2024-09-05 20:51:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_oj/segtree/range_affine_point_get.test.cpp
documentation_of: ds/segtree/segtree_dual.hpp
layout: document
redirect_from:
- /library/ds/segtree/segtree_dual.hpp
- /library/ds/segtree/segtree_dual.hpp.html
title: ds/segtree/segtree_dual.hpp
---
