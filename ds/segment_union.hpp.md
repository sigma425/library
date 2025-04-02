---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/segment_union.hpp\"\n\n/*\n\t[l,r) \u305F\u3061\u306E\
    \ union \u3092\u4FDD\u6301\n\tsegs \u306B [l,r) \u305F\u3061\u304C\u5165\u3063\
    \u3066\u3044\u308B\n\tadd(l,r) : [l,r) \u3092\u8FFD\u52A0\n\tfind(x) : x \u3092\
    \u542B\u3080\u533A\u9593\u3092\u8FD4\u3059 \u5B58\u5728\u3057\u306A\u3044\u5834\
    \u5408\u306F no = P(0,0)\n\n\tdouble \u3067\u3082\u52D5\u304F\u3088\u3046\u306B\
    \u66F8\u3044\u305F\u3064\u3082\u308A\u3060\u304C verify \u306F\u3057\u3066\u306A\
    \u3044\n*/\ntemplate<class T = int>\nstruct SegmentUnion {\n\tusing P = pair<T,T>;\n\
    \tstatic constexpr P no = P(0,0);\n\tset<P> segs;\n\tSegmentUnion() {}\n\n\tvoid\
    \ add(T l, T r) {\n\t\tif(l >= r) return;\n\t\tauto it = segs.lower_bound(P(l,numeric_limits<T>::min()));\n\
    \t\tif(it != segs.begin()) {\n\t\t\tit--;\n\t\t\tif(l <= it->sc){\n\t\t\t\tl =\
    \ it->fs;\n\t\t\t\tr = max(r,it->sc);\n\t\t\t\tit = segs.erase(it);\n\t\t\t}else{\n\
    \t\t\t\tit++;\n\t\t\t}\n\t\t}\n\t\twhile(it != segs.end() && it->fs <= r) {\n\t\
    \t\tr = max(r,it->sc);\n\t\t\tit = segs.erase(it);\n\t\t}\n\t\tsegs.insert(P(l,r));\n\
    \t}\n\n\t/*\n\t\tx \u3092\u542B\u3080\u533A\u9593\u3092\u8FD4\u3059 \u5B58\u5728\
    \u3057\u306A\u3044\u5834\u5408\u306F no = P(0,0)\n\t*/\n\tP find(T x) {\n\t\t\
    auto it = segs.lower_bound(P(x,numeric_limits<T>::max()));\n\t\tif(it == segs.begin())\
    \ return no;\n\t\tit--;\n\t\tif(it->fs <= x && x < it->sc) return *it;\n\t\treturn\
    \ no;\n\t}\n};\n"
  code: "\n/*\n\t[l,r) \u305F\u3061\u306E union \u3092\u4FDD\u6301\n\tsegs \u306B\
    \ [l,r) \u305F\u3061\u304C\u5165\u3063\u3066\u3044\u308B\n\tadd(l,r) : [l,r) \u3092\
    \u8FFD\u52A0\n\tfind(x) : x \u3092\u542B\u3080\u533A\u9593\u3092\u8FD4\u3059 \u5B58\
    \u5728\u3057\u306A\u3044\u5834\u5408\u306F no = P(0,0)\n\n\tdouble \u3067\u3082\
    \u52D5\u304F\u3088\u3046\u306B\u66F8\u3044\u305F\u3064\u3082\u308A\u3060\u304C\
    \ verify \u306F\u3057\u3066\u306A\u3044\n*/\ntemplate<class T = int>\nstruct SegmentUnion\
    \ {\n\tusing P = pair<T,T>;\n\tstatic constexpr P no = P(0,0);\n\tset<P> segs;\n\
    \tSegmentUnion() {}\n\n\tvoid add(T l, T r) {\n\t\tif(l >= r) return;\n\t\tauto\
    \ it = segs.lower_bound(P(l,numeric_limits<T>::min()));\n\t\tif(it != segs.begin())\
    \ {\n\t\t\tit--;\n\t\t\tif(l <= it->sc){\n\t\t\t\tl = it->fs;\n\t\t\t\tr = max(r,it->sc);\n\
    \t\t\t\tit = segs.erase(it);\n\t\t\t}else{\n\t\t\t\tit++;\n\t\t\t}\n\t\t}\n\t\t\
    while(it != segs.end() && it->fs <= r) {\n\t\t\tr = max(r,it->sc);\n\t\t\tit =\
    \ segs.erase(it);\n\t\t}\n\t\tsegs.insert(P(l,r));\n\t}\n\n\t/*\n\t\tx \u3092\u542B\
    \u3080\u533A\u9593\u3092\u8FD4\u3059 \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\
    \u306F no = P(0,0)\n\t*/\n\tP find(T x) {\n\t\tauto it = segs.lower_bound(P(x,numeric_limits<T>::max()));\n\
    \t\tif(it == segs.begin()) return no;\n\t\tit--;\n\t\tif(it->fs <= x && x < it->sc)\
    \ return *it;\n\t\treturn no;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/segment_union.hpp
  requiredBy: []
  timestamp: '2025-04-03 02:13:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segment_union.hpp
layout: document
redirect_from:
- /library/ds/segment_union.hpp
- /library/ds/segment_union.hpp.html
title: ds/segment_union.hpp
---
