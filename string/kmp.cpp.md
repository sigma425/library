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
  bundledCode: "#line 1 \"string/kmp.cpp\"\n/*\n\tkmp[i] = \u9577\u3055 i \u306E prefix\
    \ \u306E longest border\n\ts : aabaabaaa\n\tk : _010123452\n\n\t\u306F\u3058\u3081\
    \u3066\u306E\u6587\u5B57\u306E\u6BD4\u8F03 \t\t\ti -> A[i] (\u524D\u30EB\u30FC\
    \u30D7\u306Ej\u306A\u306E\u3067\u3001\u4ECA\u306Ei\u304B\u3089\u307F\u308B\u3068\
    A[i])\n\t\u6587\u5B57\u304C\u4E00\u81F4\u3057\u305F\u5834\u6240(\u7D42\u4E86\u3057\
    \u305F\u7B87\u6240)\ti -> A[i+1]-1 (\u307E\u3042\u307F\u308C\u3070\u308F\u304B\
    \u308B)\n\t\u7247\u65B9\u304B\u3089\u7247\u65B9\u306F\u7C21\u5358\u306B\u5C0E\u3051\
    \u308B.\u4E21\u65B9\u3068\u3082\u6839\u4ED8\u304D\u6728\u3067\u304B\u306A\u308A\
    \u6027\u8CEA\u304C\u826F\u3044.\n\t\u8A08\u7B97\u91CF\u89E3\u6790\u306F\u3001\u9ED2\
    \u8FBA\u3092\u4E0B\u308B\u56DE\u6570\u304C\u3001\u3068\u304B\u601D\u3063\u305F\
    \u3051\u3069+1\u304C\u3042\u308B\u306E\u3067\u666E\u901A\u306BA[i]\u306E\u5024\
    \u306E\u9077\u79FB\u3092\u8003\u3048\u305F\u307B\u3046\u304C\u3044\u3044\u304B\
    .\n\n\tstring, vector<hoge> \u3069\u3063\u3061\u3067\u3082\u4F7F\u3048\u308B\n\
    \n\tgetBorder: [1,N] \u306E\u3046\u3061 border\u306E\u9577\u3055 \u3092\u6607\u9806\
    \u306B\u8FD4\u3059\n\t\t\u7279\u306B N \u306F\u5E38\u306B\u542B\u307E\u308C\u3066\
    \u3044\u308B\u3053\u3068\u306B\u6CE8\u610F\n\n*/\n\n\ntemplate<class Str>\nvector<int>\
    \ getKMP(Str s){\n\tint N = s.size();\n\tvector<int> A(N+1);\n\tA[0] = -1;\n\t\
    int j = -1;\n\trep(i,N){\n\t\twhile(j>=0 && s[i]!=s[j]) j = A[j];\n\t\tj++;\n\t\
    \tA[i+1] = j;\n\t}\n\treturn A;\n}\n\ntemplate<class Str>\nV<int> getBorder(Str\
    \ s){\n\tint N = s.size();\n\tauto kmp = getKMP(s);\n\tV<int> res;\n\tfor(int\
    \ b=N;b>0;b=kmp[b]) res.eb(b);\n\treverse(all(res));\n\treturn res;\n}\n"
  code: "/*\n\tkmp[i] = \u9577\u3055 i \u306E prefix \u306E longest border\n\ts :\
    \ aabaabaaa\n\tk : _010123452\n\n\t\u306F\u3058\u3081\u3066\u306E\u6587\u5B57\u306E\
    \u6BD4\u8F03 \t\t\ti -> A[i] (\u524D\u30EB\u30FC\u30D7\u306Ej\u306A\u306E\u3067\
    \u3001\u4ECA\u306Ei\u304B\u3089\u307F\u308B\u3068A[i])\n\t\u6587\u5B57\u304C\u4E00\
    \u81F4\u3057\u305F\u5834\u6240(\u7D42\u4E86\u3057\u305F\u7B87\u6240)\ti -> A[i+1]-1\
    \ (\u307E\u3042\u307F\u308C\u3070\u308F\u304B\u308B)\n\t\u7247\u65B9\u304B\u3089\
    \u7247\u65B9\u306F\u7C21\u5358\u306B\u5C0E\u3051\u308B.\u4E21\u65B9\u3068\u3082\
    \u6839\u4ED8\u304D\u6728\u3067\u304B\u306A\u308A\u6027\u8CEA\u304C\u826F\u3044\
    .\n\t\u8A08\u7B97\u91CF\u89E3\u6790\u306F\u3001\u9ED2\u8FBA\u3092\u4E0B\u308B\u56DE\
    \u6570\u304C\u3001\u3068\u304B\u601D\u3063\u305F\u3051\u3069+1\u304C\u3042\u308B\
    \u306E\u3067\u666E\u901A\u306BA[i]\u306E\u5024\u306E\u9077\u79FB\u3092\u8003\u3048\
    \u305F\u307B\u3046\u304C\u3044\u3044\u304B.\n\n\tstring, vector<hoge> \u3069\u3063\
    \u3061\u3067\u3082\u4F7F\u3048\u308B\n\n\tgetBorder: [1,N] \u306E\u3046\u3061\
    \ border\u306E\u9577\u3055 \u3092\u6607\u9806\u306B\u8FD4\u3059\n\t\t\u7279\u306B\
    \ N \u306F\u5E38\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u3053\u3068\u306B\u6CE8\
    \u610F\n\n*/\n\n\ntemplate<class Str>\nvector<int> getKMP(Str s){\n\tint N = s.size();\n\
    \tvector<int> A(N+1);\n\tA[0] = -1;\n\tint j = -1;\n\trep(i,N){\n\t\twhile(j>=0\
    \ && s[i]!=s[j]) j = A[j];\n\t\tj++;\n\t\tA[i+1] = j;\n\t}\n\treturn A;\n}\n\n\
    template<class Str>\nV<int> getBorder(Str s){\n\tint N = s.size();\n\tauto kmp\
    \ = getKMP(s);\n\tV<int> res;\n\tfor(int b=N;b>0;b=kmp[b]) res.eb(b);\n\treverse(all(res));\n\
    \treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/kmp.cpp
  requiredBy: []
  timestamp: '2024-03-26 11:08:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/kmp.cpp
layout: document
redirect_from:
- /library/string/kmp.cpp
- /library/string/kmp.cpp.html
title: string/kmp.cpp
---
