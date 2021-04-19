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
  bundledCode: "#line 1 \"data structure/decomposing.cpp\"\n/*\n\tdecomposable problem\n\
    \t\u30C7\u30FC\u30BF\u3092\u8907\u6570\u500B\u306E\u30C7\u30FC\u30BF\u306B\u5206\
    \u3051\u305F\u5F8C\u3001\u305D\u308C\u305E\u308C\u306Bquery\u3092\u6295\u3052\u305F\
    \u5F8C\u7D71\u5408\u3067\u304D\u308B\u5F62\u306A\u3089\u3067\u304D\u308B\n\tquery([a1,a2,a3,a4,a5])\
    \ = query([a1,a2]) * query([a3]) * query([a4,a5])\n\n\tcount\u3068\u304B\u306A\
    \u3089erase\u7528\u306E\u3092\u4F5C\u3063\u3066\u6D88\u3059\n\n\t\u4E0B\u306E\u4F8B\
    \u306FBIT(\u5EA7\u6A19\u7BC4\u56F2\u5236\u9650\u306A\u3057) \u611A\u76F4\u306B\
    sorted vector\u306B\u3082\u3064\u3060\u3051\n\tvv[K-2] \u3068 vv[K-1] \u306F\u4E00\
    \u304B\u3089\u4F5C\u3089\u306A\u304F\u3066\u3082merge\u3067\u3044\u3044\u305F\u3081\
    \u3001\u8A08\u7B97\u91CF\u306FO(NlogN)\n*/\n\nstruct Decomposing{\n\tusing D =\
    \ int;\n\tvector<vector<D>> vv;\n\n\tDecomposing(){}\n\n\tvoid add(D x){\n\t\t\
    vv.pb({x});\n\t\twhile(true){\n\t\t\tint K = vv.size();\n\t\t\tif(K==1 || vv[K-1].size()!=vv[K-2].size())\
    \ break;\n\t\t\tvector<D> nv(vv[K-1].size()+vv[K-2].size());\n\t\t\tmerge(all(vv[K-2]),all(vv[K-1]),nv.begin());\t\
    //reconstruct (with using vv[K-2],vv[K-1])\n\t\t\tvv.pop_back();vv.pop_back();\n\
    \t\t\tvv.pb(nv);\n\t\t}\n\t}\n\tint get(int x){\n\t\tint res = 0;\n\t\tfor(const\
    \ auto& v:vv){\t//calc query for each and combine them\n\t\t\tres += v.end() -\
    \ lower_bound(all(v),x);\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "/*\n\tdecomposable problem\n\t\u30C7\u30FC\u30BF\u3092\u8907\u6570\u500B\u306E\
    \u30C7\u30FC\u30BF\u306B\u5206\u3051\u305F\u5F8C\u3001\u305D\u308C\u305E\u308C\
    \u306Bquery\u3092\u6295\u3052\u305F\u5F8C\u7D71\u5408\u3067\u304D\u308B\u5F62\u306A\
    \u3089\u3067\u304D\u308B\n\tquery([a1,a2,a3,a4,a5]) = query([a1,a2]) * query([a3])\
    \ * query([a4,a5])\n\n\tcount\u3068\u304B\u306A\u3089erase\u7528\u306E\u3092\u4F5C\
    \u3063\u3066\u6D88\u3059\n\n\t\u4E0B\u306E\u4F8B\u306FBIT(\u5EA7\u6A19\u7BC4\u56F2\
    \u5236\u9650\u306A\u3057) \u611A\u76F4\u306Bsorted vector\u306B\u3082\u3064\u3060\
    \u3051\n\tvv[K-2] \u3068 vv[K-1] \u306F\u4E00\u304B\u3089\u4F5C\u3089\u306A\u304F\
    \u3066\u3082merge\u3067\u3044\u3044\u305F\u3081\u3001\u8A08\u7B97\u91CF\u306F\
    O(NlogN)\n*/\n\nstruct Decomposing{\n\tusing D = int;\n\tvector<vector<D>> vv;\n\
    \n\tDecomposing(){}\n\n\tvoid add(D x){\n\t\tvv.pb({x});\n\t\twhile(true){\n\t\
    \t\tint K = vv.size();\n\t\t\tif(K==1 || vv[K-1].size()!=vv[K-2].size()) break;\n\
    \t\t\tvector<D> nv(vv[K-1].size()+vv[K-2].size());\n\t\t\tmerge(all(vv[K-2]),all(vv[K-1]),nv.begin());\t\
    //reconstruct (with using vv[K-2],vv[K-1])\n\t\t\tvv.pop_back();vv.pop_back();\n\
    \t\t\tvv.pb(nv);\n\t\t}\n\t}\n\tint get(int x){\n\t\tint res = 0;\n\t\tfor(const\
    \ auto& v:vv){\t//calc query for each and combine them\n\t\t\tres += v.end() -\
    \ lower_bound(all(v),x);\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data structure/decomposing.cpp
  requiredBy: []
  timestamp: '2017-09-14 22:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/decomposing.cpp
layout: document
redirect_from:
- /library/data structure/decomposing.cpp
- /library/data structure/decomposing.cpp.html
title: data structure/decomposing.cpp
---
