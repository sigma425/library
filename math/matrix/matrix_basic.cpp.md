---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_oj/matrix_basic.test.cpp
    title: test_oj/matrix_basic.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/matrix/matrix_basic.cpp\"\n/*\n\t\u57FA\u672C\u64CD\
    \u4F5C\u3060\u3051Matrix\u30E9\u30A4\u30D6\u30E9\u30EA\u306B\u3059\u308B\u3053\
    \u3068\u306B\n\tsweep\u3068\u304B\u306F\u3082\u3046\u76F4\u63A5vector<vector<T>>\
    \ \u306E\u95A2\u6570\u3067\u66F8\u304F\n*/\n\ntemplate<class T>\nstruct Matrix:\
    \ public vector<vector<T>>{\n\n\tMatrix(int n) : vector<vector<T>>(n,vector<T>(n)){}\n\
    \tMatrix(int h,int w) : vector<vector<T>>(h,vector<T>(w)){}\n\tMatrix(const vector<vector<T>>&\
    \ m){(*this) = m;}\n\n\tstatic Matrix E(int n){\n\t\tMatrix a(n,n);\n\t\trep(i,n)\
    \ a[i][i] = 1;\n\t\treturn a;\n\t}\n\tint h() const { return (*this).size(); }\n\
    \tint w() const { return (*this)[0].size(); }\n\n\tMatrix operator+(const Matrix&\
    \ r) const {\n\t\tassert(h() == r.h() && w() == r.w());\n\t\tint H = h(), W =\
    \ w();\n\t\tMatrix z(H,W);\n\t\trep(i,H) rep(j,W) z[i][j] = (*this)[i][j] + r[i][j];\n\
    \t\treturn z;\n\t}\n\tMatrix operator-(const Matrix& r) const {\n\t\tassert(h()\
    \ == r.h() && w() == r.w());\n\t\tint H = h(), W = w();\n\t\tMatrix z(H,W);\n\t\
    \trep(i,H) rep(j,W) z[i][j] = (*this)[i][j] - r[i][j];\n\t\treturn z;\n\t}\n\t\
    Matrix operator*(const Matrix& r) const {\n\t\tassert(w() == r.h());\n\t\tint\
    \ A = h(), B = w(), C = r.w();\n\t\tMatrix z(A,C);\n\t\trep(i,A) rep(k,B) rep(j,C)\
    \ z[i][j] += (*this)[i][k] * r[k][j];\n\t\treturn z;\n\t}\n\tMatrix& operator+=(const\
    \ Matrix& r){return (*this)=(*this)+r;}\n\tMatrix& operator-=(const Matrix& r){return\
    \ (*this)=(*this)-r;}\n\tMatrix& operator*=(const Matrix& r){return (*this)=(*this)*r;}\n\
    \n\tMatrix pow(ll p) const {\n\t\tassert(h() == w());\n\t\tMatrix res = E(h());\n\
    \t\tMatrix x = *this;\n\t\twhile(p){\n\t\t\tif(p&1) res *= x;\n\t\t\tx *= x;\n\
    \t\t\tp >>= 1;\n\t\t}\n\t\treturn res;\n\t}\n\n\tfriend ostream& operator<<(ostream\
    \ &o,const Matrix& A){\n\t\trep(i,A.h()){\n\t\t\trep(j,A.w()) o << A[i][j]<<\"\
    \ \";\n\t\t\to << endl;\n\t\t}\n\t\treturn o;\n\t}\n};\n\n/*\n\t\u30C6\u30F3\u30BD\
    \u30EB\u7A4D (\u30AF\u30ED\u30CD\u30C3\u30AB\u30FC\u7A4D)\n\tA\u2297B =[a{0,0}B\
    \ .. a_{0,w-1}B]\n\t\t  [a{1,0}B .. a_{1,w-1}B]\n\t\t\t:\n\tA\u306E1\u30DE\u30B9\
    \u3092\u5206\u5272\u3057\u3066B\u306B\u3059\u308B\u30A4\u30E1\u30FC\u30B8\n*/\n\
    template<class T>\nvector<vector<T>> tensor(vector<vector<T>> A, vector<vector<T>>\
    \ B){\n\tint ah = si(A), aw = si(A[0]), bh = si(B), bw = si(B[0]);\n\tvector<vector<T>>\
    \ C(ah*bh,vector<T>(aw*bw));\n\trep(ai,ah) rep(aj,aw){\n\t\trep(bi,bh) rep(bj,bw){\n\
    \t\t\tC[ai*bh+bi][aj*bw+bj] = A[ai][aj] * B[bi][bj];\n\t\t}\n\t}\n\treturn C;\n\
    }\n"
  code: "/*\n\t\u57FA\u672C\u64CD\u4F5C\u3060\u3051Matrix\u30E9\u30A4\u30D6\u30E9\u30EA\
    \u306B\u3059\u308B\u3053\u3068\u306B\n\tsweep\u3068\u304B\u306F\u3082\u3046\u76F4\
    \u63A5vector<vector<T>> \u306E\u95A2\u6570\u3067\u66F8\u304F\n*/\n\ntemplate<class\
    \ T>\nstruct Matrix: public vector<vector<T>>{\n\n\tMatrix(int n) : vector<vector<T>>(n,vector<T>(n)){}\n\
    \tMatrix(int h,int w) : vector<vector<T>>(h,vector<T>(w)){}\n\tMatrix(const vector<vector<T>>&\
    \ m){(*this) = m;}\n\n\tstatic Matrix E(int n){\n\t\tMatrix a(n,n);\n\t\trep(i,n)\
    \ a[i][i] = 1;\n\t\treturn a;\n\t}\n\tint h() const { return (*this).size(); }\n\
    \tint w() const { return (*this)[0].size(); }\n\n\tMatrix operator+(const Matrix&\
    \ r) const {\n\t\tassert(h() == r.h() && w() == r.w());\n\t\tint H = h(), W =\
    \ w();\n\t\tMatrix z(H,W);\n\t\trep(i,H) rep(j,W) z[i][j] = (*this)[i][j] + r[i][j];\n\
    \t\treturn z;\n\t}\n\tMatrix operator-(const Matrix& r) const {\n\t\tassert(h()\
    \ == r.h() && w() == r.w());\n\t\tint H = h(), W = w();\n\t\tMatrix z(H,W);\n\t\
    \trep(i,H) rep(j,W) z[i][j] = (*this)[i][j] - r[i][j];\n\t\treturn z;\n\t}\n\t\
    Matrix operator*(const Matrix& r) const {\n\t\tassert(w() == r.h());\n\t\tint\
    \ A = h(), B = w(), C = r.w();\n\t\tMatrix z(A,C);\n\t\trep(i,A) rep(k,B) rep(j,C)\
    \ z[i][j] += (*this)[i][k] * r[k][j];\n\t\treturn z;\n\t}\n\tMatrix& operator+=(const\
    \ Matrix& r){return (*this)=(*this)+r;}\n\tMatrix& operator-=(const Matrix& r){return\
    \ (*this)=(*this)-r;}\n\tMatrix& operator*=(const Matrix& r){return (*this)=(*this)*r;}\n\
    \n\tMatrix pow(ll p) const {\n\t\tassert(h() == w());\n\t\tMatrix res = E(h());\n\
    \t\tMatrix x = *this;\n\t\twhile(p){\n\t\t\tif(p&1) res *= x;\n\t\t\tx *= x;\n\
    \t\t\tp >>= 1;\n\t\t}\n\t\treturn res;\n\t}\n\n\tfriend ostream& operator<<(ostream\
    \ &o,const Matrix& A){\n\t\trep(i,A.h()){\n\t\t\trep(j,A.w()) o << A[i][j]<<\"\
    \ \";\n\t\t\to << endl;\n\t\t}\n\t\treturn o;\n\t}\n};\n\n/*\n\t\u30C6\u30F3\u30BD\
    \u30EB\u7A4D (\u30AF\u30ED\u30CD\u30C3\u30AB\u30FC\u7A4D)\n\tA\u2297B =[a{0,0}B\
    \ .. a_{0,w-1}B]\n\t\t  [a{1,0}B .. a_{1,w-1}B]\n\t\t\t:\n\tA\u306E1\u30DE\u30B9\
    \u3092\u5206\u5272\u3057\u3066B\u306B\u3059\u308B\u30A4\u30E1\u30FC\u30B8\n*/\n\
    template<class T>\nvector<vector<T>> tensor(vector<vector<T>> A, vector<vector<T>>\
    \ B){\n\tint ah = si(A), aw = si(A[0]), bh = si(B), bw = si(B[0]);\n\tvector<vector<T>>\
    \ C(ah*bh,vector<T>(aw*bw));\n\trep(ai,ah) rep(aj,aw){\n\t\trep(bi,bh) rep(bj,bw){\n\
    \t\t\tC[ai*bh+bi][aj*bw+bj] = A[ai][aj] * B[bi][bj];\n\t\t}\n\t}\n\treturn C;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/matrix_basic.cpp
  requiredBy: []
  timestamp: '2024-07-25 11:02:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_oj/matrix_basic.test.cpp
documentation_of: math/matrix/matrix_basic.cpp
layout: document
redirect_from:
- /library/math/matrix/matrix_basic.cpp
- /library/math/matrix/matrix_basic.cpp.html
title: math/matrix/matrix_basic.cpp
---
