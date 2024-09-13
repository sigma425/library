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
    - https://contest.ucup.ac/submission/554285
  bundledCode: "#line 1 \"ds/clearable_vector_bool.hpp\"\n/*\n\tclear \u304C O(1)\
    \ \u3067\u53EF\u80FD\u306A vector<bool>\n\n\t\u521D\u671F\u5316 \u3084 clear()\
    \ \u5F8C\u306F\u5168\u3066 false\n\n\t- VecBool a(n);\n\t- a[i] \u3067 true/false\
    \ \u3092\u5F97\u3089\u308C\u308B\n\t- set \u306F a[i] = true \u3068\u306F\u304B\
    \u3051\u306A\u304F\u3066\u3001a.set(i,true) \u3068\u304B\u304F\n\n\tverify: https://contest.ucup.ac/submission/554285\n\
    */\nstruct VecBool {\n\tint tm;\n\tvector<int> a;\n\t\n\tVecBool(int n):tm(1),a(n){}\n\
    \tvoid clear(){ tm++; }\n\tbool operator[](int i) const { return a[i] == tm; }\n\
    \tvoid set(int i, bool val){\n\t\ta[i] = val ? tm : 0;\n\t}\n};\n\n// 2\u6B21\u5143\
    \nstruct VVecBool {\n\tint tm;\n\tvector<vector<int>> a;\n\t\n\tVVecBool(int h,\
    \ int w):tm(1),a(h,vector<int>(w)){}\n\tvoid clear(){ tm++; }\n\tbool get(int\
    \ i, int j) const { return a[i][j] == tm; }\n\tvoid set(int i, int j, bool val){\n\
    \t\ta[i][j] = val ? tm : 0;\n\t}\n};\n"
  code: "/*\n\tclear \u304C O(1) \u3067\u53EF\u80FD\u306A vector<bool>\n\n\t\u521D\
    \u671F\u5316 \u3084 clear() \u5F8C\u306F\u5168\u3066 false\n\n\t- VecBool a(n);\n\
    \t- a[i] \u3067 true/false \u3092\u5F97\u3089\u308C\u308B\n\t- set \u306F a[i]\
    \ = true \u3068\u306F\u304B\u3051\u306A\u304F\u3066\u3001a.set(i,true) \u3068\u304B\
    \u304F\n\n\tverify: https://contest.ucup.ac/submission/554285\n*/\nstruct VecBool\
    \ {\n\tint tm;\n\tvector<int> a;\n\t\n\tVecBool(int n):tm(1),a(n){}\n\tvoid clear(){\
    \ tm++; }\n\tbool operator[](int i) const { return a[i] == tm; }\n\tvoid set(int\
    \ i, bool val){\n\t\ta[i] = val ? tm : 0;\n\t}\n};\n\n// 2\u6B21\u5143\nstruct\
    \ VVecBool {\n\tint tm;\n\tvector<vector<int>> a;\n\t\n\tVVecBool(int h, int w):tm(1),a(h,vector<int>(w)){}\n\
    \tvoid clear(){ tm++; }\n\tbool get(int i, int j) const { return a[i][j] == tm;\
    \ }\n\tvoid set(int i, int j, bool val){\n\t\ta[i][j] = val ? tm : 0;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/clearable_vector_bool.hpp
  requiredBy: []
  timestamp: '2024-09-14 08:27:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/clearable_vector_bool.hpp
layout: document
redirect_from:
- /library/ds/clearable_vector_bool.hpp
- /library/ds/clearable_vector_bool.hpp.html
title: ds/clearable_vector_bool.hpp
---
