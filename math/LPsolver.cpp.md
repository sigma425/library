---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/LPsolver.cpp\"\n/*\n\tLP\n\tmax cx\n\ts.t. Ax <= b,\
    \ x >= 0\n\n\ttime complexity: exponential. fast $O(HW^2)$ in experiment. dependent\
    \ on the modeling.\n*/\ntemplate<class T>\nstruct LPsolver{\n\tconst T eps = 1e-7;\n\
    \n\tint type;\n\tT cx;\n\tV<T> sol;   //W\n\n\t// 0: found solution, 1: infeasible,\
    \ 2: unbounded\n\tLPsolver(VV<T> A, V<T> b, V<T> c){\n\t\tint H = A.size(), W\
    \ = A[0].size();\n\t\tassert((int)b.size() == H);\n\t\tassert((int)c.size() ==\
    \ W);\n\n\t\tLeft.resize(H);\n\t\tDown.resize(W);\n\t\tsol.resize(W);\n\t\tcx\
    \ = 0;\n\n\t\tauto pivot = [&](int x, int y) {\n\t\t\tswap(Left[x], Down[y]);\n\
    \t\t\tT k = A[x][y];\n\t\t\tA[x][y] = 1;\n\t\t\tvector<int> nz;\n\t\t\trep(i,W){\n\
    \t\t\t\tA[x][i] /= k;\n\t\t\t\tif (!eq(A[x][i], 0)) nz.push_back(i);\n\t\t\t}\n\
    \t\t\tb[x] /= k;\n\n\t\t\trep(i,H){\n\t\t\t\tif (i == x || eq(A[i][y], 0)) continue;\n\
    \t\t\t\tk = A[i][y];\n\t\t\t\tA[i][y] = 0;\n\t\t\t\tb[i] -= k * b[x];\n\t\t\t\t\
    for (int j : nz) A[i][j] -= k * A[x][j];\n\t\t\t}\n\t\t\tif (eq(c[y], 0)) return;\n\
    \t\t\tk = c[y];\n\t\t\tc[y] = 0;\n\t\t\tcx += k * b[x];\n\t\t\tfor (int i : nz)\
    \ c[i] -= k * A[x][i];\n\t\t};\n\n\t\trep(i,W) Down[i] = i;\n\t\trep(i,H) Left[i]\
    \ = W + i;\n\t\twhile (1) { // Eliminating negative b[i]\n\t\t\tint x = -1, y\
    \ = -1;\n\t\t\trep(i,H) if(ls(b[i], 0) && (x == -1 || b[i] < b[x])) x = i;\n\t\
    \t\tif (x == -1) break;\n\t\t\trep(i,W) if(ls(A[x][i], 0) && (y == -1 || A[x][i]\
    \ < A[x][y])) y = i;\n\t\t\tif (y == -1){\n\t\t\t\ttype = 1;   //infeasible\n\t\
    \t\t\tcx = -1e100;\n\t\t\t\treturn;\n\t\t\t}\n\t\t\tpivot(x, y);\n\t\t}\n\t\t\
    while (1) {\n\t\t\tint x = -1, y = -1;\n\t\t\trep(i,W) if(ls(0, c[i]) && (y ==\
    \ -1 || c[i] > c[y])) y = i;\n\t\t\tif (y == -1) break;\n\t\t\trep(i,H) if(ls(0,\
    \ A[i][y]) && (x == -1 || b[i] / A[i][y] < b[x] / A[x][y])) x = i;\n\t\t\tif (x\
    \ == -1){\n\t\t\t\ttype = 2;   //unbounded\n\t\t\t\tcx = 1e100;\n\t\t\t\treturn;\n\
    \t\t\t}\n\t\t\tpivot(x, y);\n\t\t}\n\t\trep(i,H) if (Left[i] < W) sol[Left[i]]\
    \ = b[i];\n\t\ttype = 0;\n\t}\n\n\tV<int> Left,Down;   //H,W\n\tbool eq(T a, T\
    \ b) { return fabs(a - b) < eps; }\n\tbool ls(T a, T b) { return a < b && !eq(a,\
    \ b); }\n};\n"
  code: "/*\n\tLP\n\tmax cx\n\ts.t. Ax <= b, x >= 0\n\n\ttime complexity: exponential.\
    \ fast $O(HW^2)$ in experiment. dependent on the modeling.\n*/\ntemplate<class\
    \ T>\nstruct LPsolver{\n\tconst T eps = 1e-7;\n\n\tint type;\n\tT cx;\n\tV<T>\
    \ sol;   //W\n\n\t// 0: found solution, 1: infeasible, 2: unbounded\n\tLPsolver(VV<T>\
    \ A, V<T> b, V<T> c){\n\t\tint H = A.size(), W = A[0].size();\n\t\tassert((int)b.size()\
    \ == H);\n\t\tassert((int)c.size() == W);\n\n\t\tLeft.resize(H);\n\t\tDown.resize(W);\n\
    \t\tsol.resize(W);\n\t\tcx = 0;\n\n\t\tauto pivot = [&](int x, int y) {\n\t\t\t\
    swap(Left[x], Down[y]);\n\t\t\tT k = A[x][y];\n\t\t\tA[x][y] = 1;\n\t\t\tvector<int>\
    \ nz;\n\t\t\trep(i,W){\n\t\t\t\tA[x][i] /= k;\n\t\t\t\tif (!eq(A[x][i], 0)) nz.push_back(i);\n\
    \t\t\t}\n\t\t\tb[x] /= k;\n\n\t\t\trep(i,H){\n\t\t\t\tif (i == x || eq(A[i][y],\
    \ 0)) continue;\n\t\t\t\tk = A[i][y];\n\t\t\t\tA[i][y] = 0;\n\t\t\t\tb[i] -= k\
    \ * b[x];\n\t\t\t\tfor (int j : nz) A[i][j] -= k * A[x][j];\n\t\t\t}\n\t\t\tif\
    \ (eq(c[y], 0)) return;\n\t\t\tk = c[y];\n\t\t\tc[y] = 0;\n\t\t\tcx += k * b[x];\n\
    \t\t\tfor (int i : nz) c[i] -= k * A[x][i];\n\t\t};\n\n\t\trep(i,W) Down[i] =\
    \ i;\n\t\trep(i,H) Left[i] = W + i;\n\t\twhile (1) { // Eliminating negative b[i]\n\
    \t\t\tint x = -1, y = -1;\n\t\t\trep(i,H) if(ls(b[i], 0) && (x == -1 || b[i] <\
    \ b[x])) x = i;\n\t\t\tif (x == -1) break;\n\t\t\trep(i,W) if(ls(A[x][i], 0) &&\
    \ (y == -1 || A[x][i] < A[x][y])) y = i;\n\t\t\tif (y == -1){\n\t\t\t\ttype =\
    \ 1;   //infeasible\n\t\t\t\tcx = -1e100;\n\t\t\t\treturn;\n\t\t\t}\n\t\t\tpivot(x,\
    \ y);\n\t\t}\n\t\twhile (1) {\n\t\t\tint x = -1, y = -1;\n\t\t\trep(i,W) if(ls(0,\
    \ c[i]) && (y == -1 || c[i] > c[y])) y = i;\n\t\t\tif (y == -1) break;\n\t\t\t\
    rep(i,H) if(ls(0, A[i][y]) && (x == -1 || b[i] / A[i][y] < b[x] / A[x][y])) x\
    \ = i;\n\t\t\tif (x == -1){\n\t\t\t\ttype = 2;   //unbounded\n\t\t\t\tcx = 1e100;\n\
    \t\t\t\treturn;\n\t\t\t}\n\t\t\tpivot(x, y);\n\t\t}\n\t\trep(i,H) if (Left[i]\
    \ < W) sol[Left[i]] = b[i];\n\t\ttype = 0;\n\t}\n\n\tV<int> Left,Down;   //H,W\n\
    \tbool eq(T a, T b) { return fabs(a - b) < eps; }\n\tbool ls(T a, T b) { return\
    \ a < b && !eq(a, b); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/LPsolver.cpp
  requiredBy: []
  timestamp: '2019-03-14 23:16:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/LPsolver.cpp
layout: document
redirect_from:
- /library/math/LPsolver.cpp
- /library/math/LPsolver.cpp.html
title: math/LPsolver.cpp
---
