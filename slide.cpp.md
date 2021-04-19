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
  bundledCode: "#line 1 \"slide.cpp\"\n/*\n\t\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024\
    \n\t[0,L), [1,L+1), .. , [N-L,N) \u306E\u3046\u3061\u306E !!!ARGMIN!!! \u3092\u8FD4\
    \u3059\n\n\tmax\u306B\u3057\u305F\u3051\u308C\u3070rsucc\u306Ewhile\u306E\u4E0D\
    \u7B49\u5F0F\u3092\u9006\u306B\u3059\u308B\n\n\t\u9577\u3055\u4E00\u5B9A\u3058\
    \u3083\u306A\u304F\u3066\u3082\u3001\u66F8\u304D\u63DB\u3048\u308C\u3070\u5C3A\
    \u53D6\u3063\u307D\u3044\u3084\u3064\u306F\u5168\u3066\u3067\u304D\u308B\n*/\n\
    \ntemplate<class D>\nvector<int> calcmins(vector<D> a,int L){\n\tint N = a.size();\n\
    \n\tvector<int> ret;\n\tdeque<int> deq;\n\tauto rsucc = [&](int i){\n\t\twhile(!deq.empty()\
    \ && a[deq.back()]>a[i]) deq.pop_back();\n\t\tdeq.push_back(i);\n\t};\n\tauto\
    \ lsucc = [&](int i){\n\t\tif(!deq.empty() && deq.front()==i) deq.pop_front();\n\
    \t};\n\trep(i,N){\n\t\trsucc(i);\n\t\tif(i>=L-1){\n\t\t\tret.pb(deq.front());\n\
    \t\t\tlsucc(i-L+1);\n\t\t}\n\t}\n\treturn ret;\n}\n"
  code: "/*\n\t\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024\n\t[0,L), [1,L+1), .. ,\
    \ [N-L,N) \u306E\u3046\u3061\u306E !!!ARGMIN!!! \u3092\u8FD4\u3059\n\n\tmax\u306B\
    \u3057\u305F\u3051\u308C\u3070rsucc\u306Ewhile\u306E\u4E0D\u7B49\u5F0F\u3092\u9006\
    \u306B\u3059\u308B\n\n\t\u9577\u3055\u4E00\u5B9A\u3058\u3083\u306A\u304F\u3066\
    \u3082\u3001\u66F8\u304D\u63DB\u3048\u308C\u3070\u5C3A\u53D6\u3063\u307D\u3044\
    \u3084\u3064\u306F\u5168\u3066\u3067\u304D\u308B\n*/\n\ntemplate<class D>\nvector<int>\
    \ calcmins(vector<D> a,int L){\n\tint N = a.size();\n\n\tvector<int> ret;\n\t\
    deque<int> deq;\n\tauto rsucc = [&](int i){\n\t\twhile(!deq.empty() && a[deq.back()]>a[i])\
    \ deq.pop_back();\n\t\tdeq.push_back(i);\n\t};\n\tauto lsucc = [&](int i){\n\t\
    \tif(!deq.empty() && deq.front()==i) deq.pop_front();\n\t};\n\trep(i,N){\n\t\t\
    rsucc(i);\n\t\tif(i>=L-1){\n\t\t\tret.pb(deq.front());\n\t\t\tlsucc(i-L+1);\n\t\
    \t}\n\t}\n\treturn ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: slide.cpp
  requiredBy: []
  timestamp: '2017-11-27 15:40:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: slide.cpp
layout: document
redirect_from:
- /library/slide.cpp
- /library/slide.cpp.html
title: slide.cpp
---
