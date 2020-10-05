---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/Z.cpp\"\n/*\n\tZ-algorithm\n\tthe longest common\
    \ prefix of S and S[i~]\n\ts: aaabaaaab\n\tZ: 921034210\n\n    s[i~] \u3068 t\
    \ \u306E common prefix \u3082 t+\"$\"+s \u306B\u5BFE\u3057\u3066\u547C\u3079\u3070\
    \u6C42\u307E\u308B\n*/\nvector<int> Zalgo(string s){\n\tint N = s.size();\n\t\
    vector<int> Z(N);\n\tZ[0] = N;\n\tint i = 1, j = 0;\n\twhile(i<N){\n\t\twhile(i+j<N\
    \ && s[j]==s[i+j]) ++j;\n\t\tZ[i] = j;\n\t\tif(j==0){\n\t\t\t++i;\n\t\t\tcontinue;\n\
    \t\t}\n\t\tint k = 1;\n\t\twhile(i+k<N && k+Z[k]<j) Z[i+k]=Z[k],++k;\n\t\ti +=\
    \ k, j -= k;\n\t}\n\treturn Z;\n}\n"
  code: "/*\n\tZ-algorithm\n\tthe longest common prefix of S and S[i~]\n\ts: aaabaaaab\n\
    \tZ: 921034210\n\n    s[i~] \u3068 t \u306E common prefix \u3082 t+\"$\"+s \u306B\
    \u5BFE\u3057\u3066\u547C\u3079\u3070\u6C42\u307E\u308B\n*/\nvector<int> Zalgo(string\
    \ s){\n\tint N = s.size();\n\tvector<int> Z(N);\n\tZ[0] = N;\n\tint i = 1, j =\
    \ 0;\n\twhile(i<N){\n\t\twhile(i+j<N && s[j]==s[i+j]) ++j;\n\t\tZ[i] = j;\n\t\t\
    if(j==0){\n\t\t\t++i;\n\t\t\tcontinue;\n\t\t}\n\t\tint k = 1;\n\t\twhile(i+k<N\
    \ && k+Z[k]<j) Z[i+k]=Z[k],++k;\n\t\ti += k, j -= k;\n\t}\n\treturn Z;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/Z.cpp
  requiredBy: []
  timestamp: '2018-09-18 03:14:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/Z.cpp
layout: document
redirect_from:
- /library/string/Z.cpp
- /library/string/Z.cpp.html
title: string/Z.cpp
---
