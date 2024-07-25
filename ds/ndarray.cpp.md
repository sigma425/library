---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://qoj.ac/submission/189638
  bundledCode: "#line 1 \"ds/ndarray.cpp\"\n/*\n\t\u591A\u6B21\u5143\u914D\u5217 \u3092\
    \ flatten \u3057\u305F\u3084\u3064\n\tA[i0]..[i_{D-1}] = f[i0 + i1*m0 + i2*m0*m1\
    \ + ..]\n\t0 \u304C lsb \u3067 D-1 \u304C msb \u3068\u3044\u3046\u3053\u3068\u3067\
    \u3059\n\n\t\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF:\n\t\t\u5404\u6B21\u5143\
    \u306E\u30B5\u30A4\u30BA m[0],..,m[D-1]\n\n\t\u30A2\u30AF\u30BB\u30B9:\n\t\t\u5DE6\
    \u8FBA\u5024\u53F3\u8FBA\u5024\u3069\u3063\u3061\u3067\u3082\n\t\tA[{i0,..,i_{D-1}}],\
    \ \u3042\u308B\u3044\u306F\u76F4\u63A5 A[i]\n\n\tid: {i0,..,i_{D-1}} -> i\n\t\
    di: i -> {i0,..,i_{D-1}}\n\n\tverify:\n\t\tICPC final 46 Z\n\t\tdjq \u5B66\u751F\
    \u7269 https://qoj.ac/submission/189638\n*/\ntemplate<class T>\nstruct ndarray{\n\
    \tint S;\n\tvector<T> v;\n\tvector<int> ms;\n\tvector<int> coefs;\n\n\tndarray(){}\n\
    \tndarray(vector<int> ms_):ms(ms_),coefs(si(ms_),1){\n\t\trep(d,si(ms)-1) coefs[d+1]\
    \ = coefs[d] * ms[d];\n\t\tS = 1; rep(d,si(ms)) S *= ms[d];\n\t\tv.resize(S);\n\
    \t}\n\tint id(const vector<int>& is) const {\n\t\tint s = 0;\n\t\trep(d,si(ms))\
    \ s += is[d] * coefs[d];\n\t\treturn s;\n\t}\n\tvector<int> di(int i){\n\t\tV<int>\
    \ is(si(ms));\n\t\tper(d,si(ms)){\n\t\t\tis[d] = i/coefs[d];\n\t\t\ti %= coefs[d];\n\
    \t\t}\n\t\treturn is;\n\t}\n\n\tT& operator[](const vector<int>& is){\n\t\treturn\
    \ v[id(is)];\n\t}\n\tconst T& operator[](const vector<int>& is) const {\n\t\t\
    return v[id(is)];\n\t}\n\tT& operator[](int i){\n\t\treturn v[i];\n\t}\n\tconst\
    \ T& operator[](int i) const {\n\t\treturn v[i];\n\t}\n\n\tfriend ostream& operator<<(ostream\
    \ &o,const ndarray& a){\n\t\treturn o << a.v;\n\t}\n\tint size(){\n\t\treturn\
    \ S;\n\t}\n\tint dim(){\n\t\treturn si(ms);\n\t}\n};\n"
  code: "/*\n\t\u591A\u6B21\u5143\u914D\u5217 \u3092 flatten \u3057\u305F\u3084\u3064\
    \n\tA[i0]..[i_{D-1}] = f[i0 + i1*m0 + i2*m0*m1 + ..]\n\t0 \u304C lsb \u3067 D-1\
    \ \u304C msb \u3068\u3044\u3046\u3053\u3068\u3067\u3059\n\n\t\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF:\n\t\t\u5404\u6B21\u5143\u306E\u30B5\u30A4\u30BA m[0],..,m[D-1]\n\
    \n\t\u30A2\u30AF\u30BB\u30B9:\n\t\t\u5DE6\u8FBA\u5024\u53F3\u8FBA\u5024\u3069\u3063\
    \u3061\u3067\u3082\n\t\tA[{i0,..,i_{D-1}}], \u3042\u308B\u3044\u306F\u76F4\u63A5\
    \ A[i]\n\n\tid: {i0,..,i_{D-1}} -> i\n\tdi: i -> {i0,..,i_{D-1}}\n\n\tverify:\n\
    \t\tICPC final 46 Z\n\t\tdjq \u5B66\u751F\u7269 https://qoj.ac/submission/189638\n\
    */\ntemplate<class T>\nstruct ndarray{\n\tint S;\n\tvector<T> v;\n\tvector<int>\
    \ ms;\n\tvector<int> coefs;\n\n\tndarray(){}\n\tndarray(vector<int> ms_):ms(ms_),coefs(si(ms_),1){\n\
    \t\trep(d,si(ms)-1) coefs[d+1] = coefs[d] * ms[d];\n\t\tS = 1; rep(d,si(ms)) S\
    \ *= ms[d];\n\t\tv.resize(S);\n\t}\n\tint id(const vector<int>& is) const {\n\t\
    \tint s = 0;\n\t\trep(d,si(ms)) s += is[d] * coefs[d];\n\t\treturn s;\n\t}\n\t\
    vector<int> di(int i){\n\t\tV<int> is(si(ms));\n\t\tper(d,si(ms)){\n\t\t\tis[d]\
    \ = i/coefs[d];\n\t\t\ti %= coefs[d];\n\t\t}\n\t\treturn is;\n\t}\n\n\tT& operator[](const\
    \ vector<int>& is){\n\t\treturn v[id(is)];\n\t}\n\tconst T& operator[](const vector<int>&\
    \ is) const {\n\t\treturn v[id(is)];\n\t}\n\tT& operator[](int i){\n\t\treturn\
    \ v[i];\n\t}\n\tconst T& operator[](int i) const {\n\t\treturn v[i];\n\t}\n\n\t\
    friend ostream& operator<<(ostream &o,const ndarray& a){\n\t\treturn o << a.v;\n\
    \t}\n\tint size(){\n\t\treturn S;\n\t}\n\tint dim(){\n\t\treturn si(ms);\n\t}\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: ds/ndarray.cpp
  requiredBy: []
  timestamp: '2024-07-25 11:00:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/ndarray.cpp
layout: document
redirect_from:
- /library/ds/ndarray.cpp
- /library/ds/ndarray.cpp.html
title: ds/ndarray.cpp
---
