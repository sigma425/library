---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/manacher.cpp\"\n/*\n\tR[i] = s[i] \u3092\u4E2D\u5FC3\
    \u3068\u3059\u308B\u6700\u9577\u56DE\u6587\u306E\u534A\u5F84((len+1)/2)\n\ts:abaaababa\n\
    \tR:121412321\n\n \t\u5076\u6570\u9577\u3082\u8003\u3048\u305F\u3044\u3068\u304D\
    \u306F\n\ts:a$b$a$a$a$b$a$b$a\n\n\t\u6587\u5B57\u5217\u3058\u3083\u306A\u3044\u3082\
    \u306E\u306B\u4F7F\u3046\u3068\u304D,1\u6587\u5B57\u3092\u56DE\u5206\u3068\u307F\
    \u306A\u3057\u3066\u306F\u3044\u3051\u306A\u3044\u5834\u5408\u3082\u3042\u308B\
    \n\t\u305D\u306E\u5834\u5408\u306F\n\tR[i]=j;\n\tif(R[i]==0){\n\t\ti++,j=0;\n\t\
    \tcontinue;\n\t}\n\t\u3067OK\n*/\nvector<int> manacher(string s){\n\tint N = s.size();\n\
    \tvector<int> R(N);\n\tint i=0,j=0;\n\twhile(i < N){\n\t\twhile(i-j>=0 && i+j<N\
    \ && s[i-j]==s[i+j]) ++j;\n\t\tR[i] = j;\n\t\tint k = 1;\n\t\twhile(i-k>=0 &&\
    \ i+k<N && k+R[i-k]<j) R[i+k]=R[i-k],++k;\n\t\ti+=k,j-=k;\n\t}\n\treturn R;\n\
    }\n"
  code: "/*\n\tR[i] = s[i] \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u6700\u9577\u56DE\u6587\
    \u306E\u534A\u5F84((len+1)/2)\n\ts:abaaababa\n\tR:121412321\n\n \t\u5076\u6570\
    \u9577\u3082\u8003\u3048\u305F\u3044\u3068\u304D\u306F\n\ts:a$b$a$a$a$b$a$b$a\n\
    \n\t\u6587\u5B57\u5217\u3058\u3083\u306A\u3044\u3082\u306E\u306B\u4F7F\u3046\u3068\
    \u304D,1\u6587\u5B57\u3092\u56DE\u5206\u3068\u307F\u306A\u3057\u3066\u306F\u3044\
    \u3051\u306A\u3044\u5834\u5408\u3082\u3042\u308B\n\t\u305D\u306E\u5834\u5408\u306F\
    \n\tR[i]=j;\n\tif(R[i]==0){\n\t\ti++,j=0;\n\t\tcontinue;\n\t}\n\t\u3067OK\n*/\n\
    vector<int> manacher(string s){\n\tint N = s.size();\n\tvector<int> R(N);\n\t\
    int i=0,j=0;\n\twhile(i < N){\n\t\twhile(i-j>=0 && i+j<N && s[i-j]==s[i+j]) ++j;\n\
    \t\tR[i] = j;\n\t\tint k = 1;\n\t\twhile(i-k>=0 && i+k<N && k+R[i-k]<j) R[i+k]=R[i-k],++k;\n\
    \t\ti+=k,j-=k;\n\t}\n\treturn R;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.cpp
  requiredBy: []
  timestamp: '2018-09-18 03:14:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/manacher.cpp
layout: document
redirect_from:
- /library/string/manacher.cpp
- /library/string/manacher.cpp.html
title: string/manacher.cpp
---
