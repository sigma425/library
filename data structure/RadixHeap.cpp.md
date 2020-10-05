---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://nyc2015.contest.atcoder.jp/submissions/1089478
  bundledCode: "#line 1 \"data structure/RadixHeap.cpp\"\n/*\n\tRadixHeap\n\tHeap\u306A\
    \u3093\u3060\u3051\u3069\u6761\u4EF6\u3068\u3057\u3066\u3001\n\t - \u975E\u8CA0\
    \u6574\u6570\u3092\u5165\u308C\u308B\n\t - \u6700\u5F8C\u306B\u53D6\u308A\u51FA\
    \u3057\u305F\u5024\u3088\u308A\u5C0F\u3055\u3044\u5024\u3092\u5165\u308C\u3089\
    \u308C\u306A\u3044!\n\t\u3068\u3044\u3046\u306E\u304C\u3042\u308B.\n\t\u5F8C\u8005\
    \u306F\u5909\u306A\u5236\u7D04\u3060\u304C\u3001\u4F8B\u3048\u3070dijkstra\u306F\
    \u3053\u306E\u5236\u7D04\u3092\u6E80\u305F\u3059.\n\t\u5165\u308C\u308B\u6574\u6570\
    \u306E\u5927\u304D\u3055\u3092D\u3068\u3059\u308B\u3068\u64CD\u4F5C\u306F\u306A\
    \u3089\u3057O(log D). \u5B9A\u6570\u500D\u304C\u30AF\u30BD\u8EFD\u3044\u3089\u3057\
    \u3044.\n\t\u3053\u306E\u306A\u3089\u3057\u306B\u306Ftop\u3068\u304B\u3082\u542B\
    \u307E\u308C\u3066\u308B\u306E\u3067\u3001\u5909\u306A\u9806\u3060\u3068\u9045\
    \u3044\u3068\u304B\u3082\u306A\u3044.\n\t\u3053\u306E\u5B9F\u88C5\u3067\u306F\u4E2D\
    \u8EAB\u3092pair<uint,T> \u306B\u3057\u3066\u3044\u3066(uint\u304C\u30B3\u30B9\
    \u30C8,T\u304C\u72B6\u614B),\n\t\u306A\u306E\u3067dijkstra\u306E\n\tpriority_queue<\
    \ pair<int,T> ,vector,greater > \u306E\u304B\u308F\u308A\u306B\n\t\n\tRadixHeap<T>\
    \ \u3068\u3059\u308C\u3070\u3088\u3044.\u3042\u3068\u306F\u5168\u3066\u305D\u306E\
    \u307E\u307E.\n\t\u3053\u306E\u5B9F\u88C5\u3060\u3068\u30B3\u30B9\u30C8\u3068\u3057\
    \u3066UINT_MAX\u307E\u3067\u306F\u8A31\u3055\u308C\u308B.\n\n\t\u4E0B\u306BULONGLONG\u7248\
    \u3092\u4F5C\u308A\u307E\u3057\u305F\n\tverified by http://nyc2015.contest.atcoder.jp/submissions/1089478\n\
    \t(\u3061\u3083\u3093\u3068uint\u7248\u3067\u306F\u843D\u3061\u3066\u308B\u306E\
    \u3082\u78BA\u8A8D\u6E08\u307F)\n*/\n\ntypedef unsigned int uint;\nint bsr(uint\
    \ x){\n\tif(x==0) return -1;\n\treturn 31-__builtin_clz(x);\n}\ntemplate<class\
    \ T>\nstruct RadixHeap{\n\ttypedef pair<uint,T> P;\n\tvector<P> v[33];\n\tuint\
    \ last,sz;\n\tRadixHeap():last(0),sz(0){}\n\tvoid push(uint x,T t){\n\t\tassert(last<=x);\n\
    \t\tsz++;\n\t\tv[bsr(x^last)+1].pb(P(x,t));\n\t}\n\tvoid push(P p){\n\t\tpush(p.fs,p.sc);\n\
    \t}\n\tP top(){\n\t\treturn pop(false);\n\t}\n\tP pop(bool f = true){\n\t\tassert(sz);\n\
    \t\tif(v[0].empty()){\n\t\t\tint i=1;\n\t\t\twhile(v[i].empty()) i++;\n\t\t\t\
    last = min_element(all(v[i]))->fs;\n\t\t\tfor(P p:v[i]){\n\t\t\t\tv[bsr(p.fs^last)+1].pb(p);\n\
    \t\t\t}\n\t\t\tv[i].clear();\n\t\t}\n\t\tP r=v[0].back();\n\t\tif(f){\n\t\t\t\
    sz--;\n\t\t\tv[0].pop_back();\n\t\t}\n\t\treturn r;\n\t}\n\tint size(){\n\t\t\
    return sz;\n\t}\n\tbool empty(){\n\t\treturn sz==0;\n\t}\n\tvoid clear(){\n\t\t\
    last=sz=0;\n\t\trep(i,33) v[i].clear();\n\t}\n};\n\n\n//ULONGLONG\n\ntypedef unsigned\
    \ long long ull;\nint bsr(ull x){\n\tif(x==0) return -1;\n\treturn 63-__builtin_clzll(x);\n\
    }\ntemplate<class T>\nstruct RadixHeap{\n\ttypedef pair<ull,T> P;\n\tvector<P>\
    \ v[65];\n\tull last,sz;\n\tRadixHeap():last(0),sz(0){}\n\tvoid push(ull x,T t){\n\
    \t\tassert(last<=x);\n\t\tsz++;\n\t\tv[bsr(x^last)+1].pb(P(x,t));\n\t}\n\tvoid\
    \ push(P p){\n\t\tpush(p.fs,p.sc);\n\t}\n\tP top(){\n\t\treturn pop(false);\n\t\
    }\n\tP pop(bool f = true){\n\t\tassert(sz);\n\t\tif(v[0].empty()){\n\t\t\tint\
    \ i=1;\n\t\t\twhile(v[i].empty()) i++;\n\t\t\tlast = min_element(all(v[i]))->fs;\n\
    \t\t\tfor(P p:v[i]){\n\t\t\t\tv[bsr(p.fs^last)+1].pb(p);\n\t\t\t}\n\t\t\tv[i].clear();\n\
    \t\t}\n\t\tP r=v[0].back();\n\t\tif(f){\n\t\t\tsz--;\n\t\t\tv[0].pop_back();\n\
    \t\t}\n\t\treturn r;\n\t}\n\tint size(){\n\t\treturn sz;\n\t}\n\tbool empty(){\n\
    \t\treturn sz==0;\n\t}\n\tvoid clear(){\n\t\tlast=sz=0;\n\t\trep(i,65) v[i].clear();\n\
    \t}\n};\n"
  code: "/*\n\tRadixHeap\n\tHeap\u306A\u3093\u3060\u3051\u3069\u6761\u4EF6\u3068\u3057\
    \u3066\u3001\n\t - \u975E\u8CA0\u6574\u6570\u3092\u5165\u308C\u308B\n\t - \u6700\
    \u5F8C\u306B\u53D6\u308A\u51FA\u3057\u305F\u5024\u3088\u308A\u5C0F\u3055\u3044\
    \u5024\u3092\u5165\u308C\u3089\u308C\u306A\u3044!\n\t\u3068\u3044\u3046\u306E\u304C\
    \u3042\u308B.\n\t\u5F8C\u8005\u306F\u5909\u306A\u5236\u7D04\u3060\u304C\u3001\u4F8B\
    \u3048\u3070dijkstra\u306F\u3053\u306E\u5236\u7D04\u3092\u6E80\u305F\u3059.\n\t\
    \u5165\u308C\u308B\u6574\u6570\u306E\u5927\u304D\u3055\u3092D\u3068\u3059\u308B\
    \u3068\u64CD\u4F5C\u306F\u306A\u3089\u3057O(log D). \u5B9A\u6570\u500D\u304C\u30AF\
    \u30BD\u8EFD\u3044\u3089\u3057\u3044.\n\t\u3053\u306E\u306A\u3089\u3057\u306B\u306F\
    top\u3068\u304B\u3082\u542B\u307E\u308C\u3066\u308B\u306E\u3067\u3001\u5909\u306A\
    \u9806\u3060\u3068\u9045\u3044\u3068\u304B\u3082\u306A\u3044.\n\t\u3053\u306E\u5B9F\
    \u88C5\u3067\u306F\u4E2D\u8EAB\u3092pair<uint,T> \u306B\u3057\u3066\u3044\u3066\
    (uint\u304C\u30B3\u30B9\u30C8,T\u304C\u72B6\u614B),\n\t\u306A\u306E\u3067dijkstra\u306E\
    \n\tpriority_queue< pair<int,T> ,vector,greater > \u306E\u304B\u308F\u308A\u306B\
    \n\t\n\tRadixHeap<T> \u3068\u3059\u308C\u3070\u3088\u3044.\u3042\u3068\u306F\u5168\
    \u3066\u305D\u306E\u307E\u307E.\n\t\u3053\u306E\u5B9F\u88C5\u3060\u3068\u30B3\u30B9\
    \u30C8\u3068\u3057\u3066UINT_MAX\u307E\u3067\u306F\u8A31\u3055\u308C\u308B.\n\n\
    \t\u4E0B\u306BULONGLONG\u7248\u3092\u4F5C\u308A\u307E\u3057\u305F\n\tverified\
    \ by http://nyc2015.contest.atcoder.jp/submissions/1089478\n\t(\u3061\u3083\u3093\
    \u3068uint\u7248\u3067\u306F\u843D\u3061\u3066\u308B\u306E\u3082\u78BA\u8A8D\u6E08\
    \u307F)\n*/\n\ntypedef unsigned int uint;\nint bsr(uint x){\n\tif(x==0) return\
    \ -1;\n\treturn 31-__builtin_clz(x);\n}\ntemplate<class T>\nstruct RadixHeap{\n\
    \ttypedef pair<uint,T> P;\n\tvector<P> v[33];\n\tuint last,sz;\n\tRadixHeap():last(0),sz(0){}\n\
    \tvoid push(uint x,T t){\n\t\tassert(last<=x);\n\t\tsz++;\n\t\tv[bsr(x^last)+1].pb(P(x,t));\n\
    \t}\n\tvoid push(P p){\n\t\tpush(p.fs,p.sc);\n\t}\n\tP top(){\n\t\treturn pop(false);\n\
    \t}\n\tP pop(bool f = true){\n\t\tassert(sz);\n\t\tif(v[0].empty()){\n\t\t\tint\
    \ i=1;\n\t\t\twhile(v[i].empty()) i++;\n\t\t\tlast = min_element(all(v[i]))->fs;\n\
    \t\t\tfor(P p:v[i]){\n\t\t\t\tv[bsr(p.fs^last)+1].pb(p);\n\t\t\t}\n\t\t\tv[i].clear();\n\
    \t\t}\n\t\tP r=v[0].back();\n\t\tif(f){\n\t\t\tsz--;\n\t\t\tv[0].pop_back();\n\
    \t\t}\n\t\treturn r;\n\t}\n\tint size(){\n\t\treturn sz;\n\t}\n\tbool empty(){\n\
    \t\treturn sz==0;\n\t}\n\tvoid clear(){\n\t\tlast=sz=0;\n\t\trep(i,33) v[i].clear();\n\
    \t}\n};\n\n\n//ULONGLONG\n\ntypedef unsigned long long ull;\nint bsr(ull x){\n\
    \tif(x==0) return -1;\n\treturn 63-__builtin_clzll(x);\n}\ntemplate<class T>\n\
    struct RadixHeap{\n\ttypedef pair<ull,T> P;\n\tvector<P> v[65];\n\tull last,sz;\n\
    \tRadixHeap():last(0),sz(0){}\n\tvoid push(ull x,T t){\n\t\tassert(last<=x);\n\
    \t\tsz++;\n\t\tv[bsr(x^last)+1].pb(P(x,t));\n\t}\n\tvoid push(P p){\n\t\tpush(p.fs,p.sc);\n\
    \t}\n\tP top(){\n\t\treturn pop(false);\n\t}\n\tP pop(bool f = true){\n\t\tassert(sz);\n\
    \t\tif(v[0].empty()){\n\t\t\tint i=1;\n\t\t\twhile(v[i].empty()) i++;\n\t\t\t\
    last = min_element(all(v[i]))->fs;\n\t\t\tfor(P p:v[i]){\n\t\t\t\tv[bsr(p.fs^last)+1].pb(p);\n\
    \t\t\t}\n\t\t\tv[i].clear();\n\t\t}\n\t\tP r=v[0].back();\n\t\tif(f){\n\t\t\t\
    sz--;\n\t\t\tv[0].pop_back();\n\t\t}\n\t\treturn r;\n\t}\n\tint size(){\n\t\t\
    return sz;\n\t}\n\tbool empty(){\n\t\treturn sz==0;\n\t}\n\tvoid clear(){\n\t\t\
    last=sz=0;\n\t\trep(i,65) v[i].clear();\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data structure/RadixHeap.cpp
  requiredBy: []
  timestamp: '2017-02-02 01:38:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/RadixHeap.cpp
layout: document
redirect_from:
- /library/data structure/RadixHeap.cpp
- /library/data structure/RadixHeap.cpp.html
title: data structure/RadixHeap.cpp
---
