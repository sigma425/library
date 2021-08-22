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
    \u3063\u3066\u3044\u3061\u3044\u3061\u914D\u5217\u4F5C\u3063\u3066\u30FB\u30FB\
    \u30FB\u3063\u3066\u3084\u308B\u3068\u91CD\u3044\u3053\u3068\u304C\u591A\u3044\
    \u6C17\u304C\u3059\u308B\u306E\u3067\u4F7F\u3044\u307E\u308F\u3057\u53EF\u80FD\
    \u306A\u3084\u3064\u3092\u4F5C\u3063\u305F\n\t\u3067\u3082\u30B0\u30ED\u30FC\u30D0\
    \u30EB\u306F\u6D41\u77F3\u306B\u5ACC\u3060\u304B\u3089\u3001namespace\u3067\n\n\
    \t\u4F8B: f[x] = min(f[x],f[x-v]+1,f[x-2v]+2,..f[x-Kv]+K)\n\trep(r,v){\n\t\tSlideMin::clear();\n\
    \t\tfor(int x=r;x<=S;x+=v){\n\t\t\tint i = x/v;\n\t\t\tSlideMin::add(sum2mn[x]-i);\n\
    \t\t\tsum2mn[x] = SlideMin::getmin()+i;\n\t\t\tif(i>=K) SlideMin::del();\n\t\t\
    }\n\t}\n*/\n\nnamespace SlideMin{\n\tusing D = int;\n\tconst int X = 1000000;\n\
    \tD a[X];\n\tint idx[X];\n\tint L,R,I,num_del;\n\tvoid clear(){\n\t\tL = R = I\
    \ = num_del = 0;\n\t}\n\tvoid add(D v){\n\t\twhile(L<R && v<a[R-1]) R--;\t\t\t\
    // D-D comparison v<a[R-1]\n\t\ta[R] = v;\n\t\tidx[R] = I;\n\t\tR++,I++;\n\t}\n\
    \tvoid del(){\n\t\tif(L<R && idx[L] == num_del) L++;\n\t\tnum_del++;\n\t}\n\t\
    D getmin(){\n\t\tassert(L<R);\n\t\treturn a[L];\n\t}\n\tint getargmin(){\n\t\t\
    assert(L<R);\n\t\treturn idx[L];\n\t}\n}\nnamespace SlideMax{\n\tusing D = int;\n\
    \tconst int X = 1000000;\n\tD a[X];\n\tint idx[X];\n\tint L,R,I,num_del;\n\tvoid\
    \ clear(){\n\t\tL = R = I = num_del = 0;\n\t}\n\tvoid add(D v){\n\t\twhile(L<R\
    \ && v>a[R-1]) R--;\t\t\t// D-D comparison v<a[R-1]\n\t\ta[R] = v;\n\t\tidx[R]\
    \ = I;\n\t\tR++,I++;\n\t}\n\tvoid del(){\n\t\tif(L<R && idx[L] == num_del) L++;\n\
    \t\tnum_del++;\n\t}\n\tD getmax(){\n\t\tassert(L<R);\n\t\treturn a[L];\n\t}\n\t\
    int getargmax(){\n\t\tassert(L<R);\n\t\treturn idx[L];\n\t}\n}\n\n\n/*\n\t\u30B9\
    \u30E9\u30A4\u30C9\u6700\u5C0F\u5024\n\t[0,L), [1,L+1), .. , [N-L,N) \u306E\u3046\
    \u3061\u306E !!!ARGMIN!!! \u3092\u8FD4\u3059\n\n\tmax\u306B\u3057\u305F\u3051\u308C\
    \u3070rsucc\u306Ewhile\u306E\u4E0D\u7B49\u5F0F\u3092\u9006\u306B\u3059\u308B\n\
    \n\t\u9577\u3055\u4E00\u5B9A\u3058\u3083\u306A\u304F\u3066\u3082\u3001\u66F8\u304D\
    \u63DB\u3048\u308C\u3070\u5C3A\u53D6\u3063\u307D\u3044\u3084\u3064\u306F\u5168\
    \u3066\u3067\u304D\u308B\n*/\n\ntemplate<class D>\nvector<int> calcmins(vector<D>\
    \ a,int L){\n\tint N = a.size();\n\n\tvector<int> ret;\n\tdeque<int> deq;\n\t\
    auto rsucc = [&](int i){\n\t\twhile(!deq.empty() && a[deq.back()]>a[i]) deq.pop_back();\n\
    \t\tdeq.push_back(i);\n\t};\n\tauto lsucc = [&](int i){\n\t\tif(!deq.empty() &&\
    \ deq.front()==i) deq.pop_front();\n\t};\n\trep(i,N){\n\t\trsucc(i);\n\t\tif(i>=L-1){\n\
    \t\t\tret.pb(deq.front());\n\t\t\tlsucc(i-L+1);\n\t\t}\n\t}\n\treturn ret;\n}\n"
  code: "/*\n\t\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024\u3063\u3066\u3044\u3061\u3044\
    \u3061\u914D\u5217\u4F5C\u3063\u3066\u30FB\u30FB\u30FB\u3063\u3066\u3084\u308B\
    \u3068\u91CD\u3044\u3053\u3068\u304C\u591A\u3044\u6C17\u304C\u3059\u308B\u306E\
    \u3067\u4F7F\u3044\u307E\u308F\u3057\u53EF\u80FD\u306A\u3084\u3064\u3092\u4F5C\
    \u3063\u305F\n\t\u3067\u3082\u30B0\u30ED\u30FC\u30D0\u30EB\u306F\u6D41\u77F3\u306B\
    \u5ACC\u3060\u304B\u3089\u3001namespace\u3067\n\n\t\u4F8B: f[x] = min(f[x],f[x-v]+1,f[x-2v]+2,..f[x-Kv]+K)\n\
    \trep(r,v){\n\t\tSlideMin::clear();\n\t\tfor(int x=r;x<=S;x+=v){\n\t\t\tint i\
    \ = x/v;\n\t\t\tSlideMin::add(sum2mn[x]-i);\n\t\t\tsum2mn[x] = SlideMin::getmin()+i;\n\
    \t\t\tif(i>=K) SlideMin::del();\n\t\t}\n\t}\n*/\n\nnamespace SlideMin{\n\tusing\
    \ D = int;\n\tconst int X = 1000000;\n\tD a[X];\n\tint idx[X];\n\tint L,R,I,num_del;\n\
    \tvoid clear(){\n\t\tL = R = I = num_del = 0;\n\t}\n\tvoid add(D v){\n\t\twhile(L<R\
    \ && v<a[R-1]) R--;\t\t\t// D-D comparison v<a[R-1]\n\t\ta[R] = v;\n\t\tidx[R]\
    \ = I;\n\t\tR++,I++;\n\t}\n\tvoid del(){\n\t\tif(L<R && idx[L] == num_del) L++;\n\
    \t\tnum_del++;\n\t}\n\tD getmin(){\n\t\tassert(L<R);\n\t\treturn a[L];\n\t}\n\t\
    int getargmin(){\n\t\tassert(L<R);\n\t\treturn idx[L];\n\t}\n}\nnamespace SlideMax{\n\
    \tusing D = int;\n\tconst int X = 1000000;\n\tD a[X];\n\tint idx[X];\n\tint L,R,I,num_del;\n\
    \tvoid clear(){\n\t\tL = R = I = num_del = 0;\n\t}\n\tvoid add(D v){\n\t\twhile(L<R\
    \ && v>a[R-1]) R--;\t\t\t// D-D comparison v<a[R-1]\n\t\ta[R] = v;\n\t\tidx[R]\
    \ = I;\n\t\tR++,I++;\n\t}\n\tvoid del(){\n\t\tif(L<R && idx[L] == num_del) L++;\n\
    \t\tnum_del++;\n\t}\n\tD getmax(){\n\t\tassert(L<R);\n\t\treturn a[L];\n\t}\n\t\
    int getargmax(){\n\t\tassert(L<R);\n\t\treturn idx[L];\n\t}\n}\n\n\n/*\n\t\u30B9\
    \u30E9\u30A4\u30C9\u6700\u5C0F\u5024\n\t[0,L), [1,L+1), .. , [N-L,N) \u306E\u3046\
    \u3061\u306E !!!ARGMIN!!! \u3092\u8FD4\u3059\n\n\tmax\u306B\u3057\u305F\u3051\u308C\
    \u3070rsucc\u306Ewhile\u306E\u4E0D\u7B49\u5F0F\u3092\u9006\u306B\u3059\u308B\n\
    \n\t\u9577\u3055\u4E00\u5B9A\u3058\u3083\u306A\u304F\u3066\u3082\u3001\u66F8\u304D\
    \u63DB\u3048\u308C\u3070\u5C3A\u53D6\u3063\u307D\u3044\u3084\u3064\u306F\u5168\
    \u3066\u3067\u304D\u308B\n*/\n\ntemplate<class D>\nvector<int> calcmins(vector<D>\
    \ a,int L){\n\tint N = a.size();\n\n\tvector<int> ret;\n\tdeque<int> deq;\n\t\
    auto rsucc = [&](int i){\n\t\twhile(!deq.empty() && a[deq.back()]>a[i]) deq.pop_back();\n\
    \t\tdeq.push_back(i);\n\t};\n\tauto lsucc = [&](int i){\n\t\tif(!deq.empty() &&\
    \ deq.front()==i) deq.pop_front();\n\t};\n\trep(i,N){\n\t\trsucc(i);\n\t\tif(i>=L-1){\n\
    \t\t\tret.pb(deq.front());\n\t\t\tlsucc(i-L+1);\n\t\t}\n\t}\n\treturn ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: slide.cpp
  requiredBy: []
  timestamp: '2021-08-23 00:41:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: slide.cpp
layout: document
redirect_from:
- /library/slide.cpp
- /library/slide.cpp.html
title: slide.cpp
---
