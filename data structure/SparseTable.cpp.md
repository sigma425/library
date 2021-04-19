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
  bundledCode: "#line 1 \"data structure/SparseTable.cpp\"\nint bsr(unsigned int x){\n\
    \tif(x==0) return -1;\n\treturn 31 ^ __builtin_clz(x);\n}\n\nstruct SparseTable{\n\
    \tusing D = int;\t\t\t\t\t\t\t\t\t\t\t\t//type\n\tVV<D> d;\n\tint lg;\n\n\tSparseTable(){}\n\
    \tSparseTable(const vector<D>& v){\n\t\tint N = v.size();\n\t\tassert(N > 0);\n\
    \n\t\tlg = bsr(N)+1;\n\t\td.resize(lg);\n\t\td[0] = v;\n\t\tfor(int t=1;t<lg;t++){\n\
    \t\t\tint len = 1<<t;\n\t\t\td[t].resize(N-len+1);\n\t\t\trep(i,N-len+1){\n\t\t\
    \t\td[t][i] = max(d[t-1][i] , d[t-1][i+len/2]);\t\t//op\n\t\t\t}\n\t\t}\n\t}\n\
    \tD query(int l, int r) const {\n\t\tif(l>=r) return -1;\t\t\t\t\t\t\t\t\t\t//e\n\
    \t\tint u = bsr(r-l);\n\t\treturn max(d[u][l] , d[u][r-(1<<u)]);\t\t\t\t\t//op\n\
    \t}\n};\n"
  code: "int bsr(unsigned int x){\n\tif(x==0) return -1;\n\treturn 31 ^ __builtin_clz(x);\n\
    }\n\nstruct SparseTable{\n\tusing D = int;\t\t\t\t\t\t\t\t\t\t\t\t//type\n\tVV<D>\
    \ d;\n\tint lg;\n\n\tSparseTable(){}\n\tSparseTable(const vector<D>& v){\n\t\t\
    int N = v.size();\n\t\tassert(N > 0);\n\n\t\tlg = bsr(N)+1;\n\t\td.resize(lg);\n\
    \t\td[0] = v;\n\t\tfor(int t=1;t<lg;t++){\n\t\t\tint len = 1<<t;\n\t\t\td[t].resize(N-len+1);\n\
    \t\t\trep(i,N-len+1){\n\t\t\t\td[t][i] = max(d[t-1][i] , d[t-1][i+len/2]);\t\t\
    //op\n\t\t\t}\n\t\t}\n\t}\n\tD query(int l, int r) const {\n\t\tif(l>=r) return\
    \ -1;\t\t\t\t\t\t\t\t\t\t//e\n\t\tint u = bsr(r-l);\n\t\treturn max(d[u][l] ,\
    \ d[u][r-(1<<u)]);\t\t\t\t\t//op\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data structure/SparseTable.cpp
  requiredBy: []
  timestamp: '2019-02-15 03:36:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/SparseTable.cpp
layout: document
redirect_from:
- /library/data structure/SparseTable.cpp
- /library/data structure/SparseTable.cpp.html
title: data structure/SparseTable.cpp
---
