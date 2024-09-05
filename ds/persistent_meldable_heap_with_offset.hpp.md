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
    - https://contest.ucup.ac/submission/443812
  bundledCode: "#line 1 \"ds/persistent_meldable_heap_with_offset.hpp\"\n/*\n\t\u6C38\
    \u7D9A meldable heap with offset\n\toffset \u306A\u3044\u7248\u3068\u307B\u307C\
    \u540C\u3058\u306A\u306E\u3067\u8AAC\u660E\u306F\u305D\u3063\u3061\u3092\u53C2\
    \u7167\n\n\t- NP add_offset(a, off): heap a \u306E\u8981\u7D20\u5168\u4F53\u306B\
    \ += off \u3057\u305F heap \u3092\u8FD4\u3059 O(1)\n\n\t\u4ED5\u7D44\u307F\n\t\
    \tlazy \u307F\u305F\u3044\u306A\u611F\u3058\u3067\u3001heap a \u306B\u5165\u3063\
    \u3066\u308B\u5024 v \u306F\u3001a \u304B\u3089 v \u306B\u6F5C\u3063\u3066\u3044\
    \u304F\u9593\u306E val \u3092\u8DB3\u3057\u5408\u308F\u305B\u305F\u3082\u306E\
    \ \u306B\u306A\u3063\u3066\u3044\u308B\n\t\n\tverify\n\t\tucup 3-2 B https://contest.ucup.ac/submission/443812\n\
    */\n\ntemplate<class T, class F = less<T>>\nstruct PersistentMeldableHeapWithOffset{\n\
    \tstruct Node{\n\t\tT val;\n\t\tNode *l, *r;\n\t\tint s;\n\t};\n\tusing NP = Node*;\n\
    \tstatic constexpr int pool_size = 900'000'000 / sizeof(Node);\t// 0.9GB \u3068\
    \u308B\n\tNode pool[pool_size];\n\tint I;\t// currently used\n\tF comp = F();\n\
    \n\tT top(NP a){\n\t\tassert(a);\t// a: empty\n\t\treturn a->val;\n\t}\n\tNP pop(NP\
    \ a){\n\t\tassert(a);\n\t\treturn merge(a->l, a->r, a->val, a->val);\n\t}\n\t\
    NP push(NP a, T v){\n\t\treturn merge(a,newnode(v));\n\t}\n\tNP merge(NP a, NP\
    \ b, T aoff=0, T boff=0){\n\t\tif(!a && !b) return nullptr;\n\t\tif(!a) return\
    \ add_offset(b,boff);\n\t\tif(!b) return add_offset(a, aoff);\n\t\tif(comp(a->val+aoff,\
    \ b->val+boff)){\n\t\t\t// F \u304C\u30C7\u30D5\u30A9\u30EB\u30C8\u306E less \u306E\
    \u5834\u5408: a \u5074\u304C\u5C0F\u3055\u3044\u3068\u304D\u306F\u3001swap \u3059\
    \u3079\u304D (a \u304C\u4E0A\u306B\u306A\u308B\u306E\u3067\u3001\u5927\u304D\u3044\
    \u65B9\u304C\u4E0A)\n\t\t\tswap(a,b); swap(aoff,boff);\n\t\t}\n\t\treturn newnode(a->val+aoff,\
    \ a->l, merge(a->r, b, 0, boff-(a->val+aoff)));\n\t}\n\tbool empty(NP a){\n\t\t\
    return !a;\n\t}\n\tNP add_offset(NP a, T off){\n\t\tif(!a || off == 0) return\
    \ a;\n\t\tNP b = clone(a);\n\t\tb->val += off;\n\t\treturn b;\n\t}\n\tNP newnode(){\n\
    \t\treturn nullptr;\n\t}\n\tNP newnode(T v){\n\t\tpool[I] = {v, nullptr, nullptr,\
    \ 1};\n\t\treturn &pool[I++];\n\t}\n\tNP newnode(T v, NP l, NP r){\n\t\tif(depth(l)\
    \ < depth(r)) swap(l,r);\n\t\tpool[I] = {v, l, r, depth(r)+1};\n\t\treturn &pool[I++];\n\
    \t}\n\tNP clone(NP a){\n\t\tpool[I] = *a;\n\t\treturn &pool[I++];\n\t}\n\tint\
    \ depth(NP a){\n\t\treturn a ? a->s : 0;\n\t}\n\tvector<T> enumerate(NP a, T off=0){\n\
    \t\tif(!a) return {};\n\t\tvector<T> res = {off+a->val};\n\t\tauto vl = enumerate(a->l,\
    \ off+a->val);\n\t\tauto vr = enumerate(a->r, off+a->val);\n\t\tres.insert(res.end(),all(vl));\n\
    \t\tres.insert(res.end(),all(vr));\n\t\treturn res;\n\t}\n};\n// PersistentMeldableHeapWithOffset<ll>\
    \ heap;\n// using NP = decltype(heap)::NP;\n"
  code: "/*\n\t\u6C38\u7D9A meldable heap with offset\n\toffset \u306A\u3044\u7248\
    \u3068\u307B\u307C\u540C\u3058\u306A\u306E\u3067\u8AAC\u660E\u306F\u305D\u3063\
    \u3061\u3092\u53C2\u7167\n\n\t- NP add_offset(a, off): heap a \u306E\u8981\u7D20\
    \u5168\u4F53\u306B += off \u3057\u305F heap \u3092\u8FD4\u3059 O(1)\n\n\t\u4ED5\
    \u7D44\u307F\n\t\tlazy \u307F\u305F\u3044\u306A\u611F\u3058\u3067\u3001heap a\
    \ \u306B\u5165\u3063\u3066\u308B\u5024 v \u306F\u3001a \u304B\u3089 v \u306B\u6F5C\
    \u3063\u3066\u3044\u304F\u9593\u306E val \u3092\u8DB3\u3057\u5408\u308F\u305B\u305F\
    \u3082\u306E \u306B\u306A\u3063\u3066\u3044\u308B\n\t\n\tverify\n\t\tucup 3-2\
    \ B https://contest.ucup.ac/submission/443812\n*/\n\ntemplate<class T, class F\
    \ = less<T>>\nstruct PersistentMeldableHeapWithOffset{\n\tstruct Node{\n\t\tT\
    \ val;\n\t\tNode *l, *r;\n\t\tint s;\n\t};\n\tusing NP = Node*;\n\tstatic constexpr\
    \ int pool_size = 900'000'000 / sizeof(Node);\t// 0.9GB \u3068\u308B\n\tNode pool[pool_size];\n\
    \tint I;\t// currently used\n\tF comp = F();\n\n\tT top(NP a){\n\t\tassert(a);\t\
    // a: empty\n\t\treturn a->val;\n\t}\n\tNP pop(NP a){\n\t\tassert(a);\n\t\treturn\
    \ merge(a->l, a->r, a->val, a->val);\n\t}\n\tNP push(NP a, T v){\n\t\treturn merge(a,newnode(v));\n\
    \t}\n\tNP merge(NP a, NP b, T aoff=0, T boff=0){\n\t\tif(!a && !b) return nullptr;\n\
    \t\tif(!a) return add_offset(b,boff);\n\t\tif(!b) return add_offset(a, aoff);\n\
    \t\tif(comp(a->val+aoff, b->val+boff)){\n\t\t\t// F \u304C\u30C7\u30D5\u30A9\u30EB\
    \u30C8\u306E less \u306E\u5834\u5408: a \u5074\u304C\u5C0F\u3055\u3044\u3068\u304D\
    \u306F\u3001swap \u3059\u3079\u304D (a \u304C\u4E0A\u306B\u306A\u308B\u306E\u3067\
    \u3001\u5927\u304D\u3044\u65B9\u304C\u4E0A)\n\t\t\tswap(a,b); swap(aoff,boff);\n\
    \t\t}\n\t\treturn newnode(a->val+aoff, a->l, merge(a->r, b, 0, boff-(a->val+aoff)));\n\
    \t}\n\tbool empty(NP a){\n\t\treturn !a;\n\t}\n\tNP add_offset(NP a, T off){\n\
    \t\tif(!a || off == 0) return a;\n\t\tNP b = clone(a);\n\t\tb->val += off;\n\t\
    \treturn b;\n\t}\n\tNP newnode(){\n\t\treturn nullptr;\n\t}\n\tNP newnode(T v){\n\
    \t\tpool[I] = {v, nullptr, nullptr, 1};\n\t\treturn &pool[I++];\n\t}\n\tNP newnode(T\
    \ v, NP l, NP r){\n\t\tif(depth(l) < depth(r)) swap(l,r);\n\t\tpool[I] = {v, l,\
    \ r, depth(r)+1};\n\t\treturn &pool[I++];\n\t}\n\tNP clone(NP a){\n\t\tpool[I]\
    \ = *a;\n\t\treturn &pool[I++];\n\t}\n\tint depth(NP a){\n\t\treturn a ? a->s\
    \ : 0;\n\t}\n\tvector<T> enumerate(NP a, T off=0){\n\t\tif(!a) return {};\n\t\t\
    vector<T> res = {off+a->val};\n\t\tauto vl = enumerate(a->l, off+a->val);\n\t\t\
    auto vr = enumerate(a->r, off+a->val);\n\t\tres.insert(res.end(),all(vl));\n\t\
    \tres.insert(res.end(),all(vr));\n\t\treturn res;\n\t}\n};\n// PersistentMeldableHeapWithOffset<ll>\
    \ heap;\n// using NP = decltype(heap)::NP;"
  dependsOn: []
  isVerificationFile: false
  path: ds/persistent_meldable_heap_with_offset.hpp
  requiredBy: []
  timestamp: '2024-09-05 20:45:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/persistent_meldable_heap_with_offset.hpp
layout: document
redirect_from:
- /library/ds/persistent_meldable_heap_with_offset.hpp
- /library/ds/persistent_meldable_heap_with_offset.hpp.html
title: ds/persistent_meldable_heap_with_offset.hpp
---
