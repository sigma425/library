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
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624
    - https://official.contest.yandex.ru/opencupXIX/contest/9262/problems/K
  bundledCode: "#line 1 \"math/matrix/matrix.cpp\"\n/*\n\t\u884C\u5217\u306E\u57FA\
    \u672C\u6F14\u7B97, \u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F\u306E\u89E3, \u9006\
    \u884C\u5217 \u3068\u304B\n\ttemplate \u5F15\u6570 T \u306F\u4F53\u3067\u3042\u308B\
    \u5FC5\u8981\u304C\u3042\u308B\n\t+,-,*,/, unary -\n\t\u306E\u4ED6\u306B, zero,\
    \ one, iszero(), isone() \u304C\u3044\u308B\n\t\u6D6E\u52D5\u5C0F\u6570\u70B9\u3068\
    \u304B\u306E\u305F\u3081\u306Biszero\u3068\u304B\u306F==zero\u3092\u907F\u3051\
    \u3066\u3044\u308B\n\n\tusage:\n\t\tfield class (mint\u3068\u304B) \u3092\u7528\
    \u610F\u3059\u308B\n\t\tzero,one,iszero(),isone()\u3092\u66F8\u304F\n\n\tsolveLinearEquation\u306B\
    0\u500B\u306E\u5F0F\u3092\u5165\u308C\u308B\u3068\u6A2A\u5E45\u304C\u53D6\u5F97\
    \u3067\u304D\u305A[0].size() \u3067 segfault \u306E\u3067\u6CE8\u610F\n\n\tcomplexity:\n\
    \t\tsweep\u7CFB\u306F\u3059\u3079\u3066 O(rank * H * W)\n\t\trank\u304C\u5C0F\u3055\
    \u3044\u3068\u52DD\u624B\u306B\u8A08\u7B97\u91CF\u306F\u6E1B\u308B\n\n\t\t\u5B9A\
    \u6570\u500D\u304C\u9045\u3044\u306E\u3067500\u3068\u304B\u306E\u3068\u304D\u306F\
    \u5225\u306E\u3092\u4F7F\u3046\n\n\tverified at http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624\
    \ (solveLinearEquarion mod 2)\n\tverified at https://official.contest.yandex.ru/opencupXIX/contest/9262/problems/K\
    \ (sLE on Rationals)\n\n*/\n\ntemplate<class T>\nstruct Matrix{\n\tint H,W;\n\t\
    VV<T> a;\n\n\tMatrix() : H(0),W(0){}\n\tMatrix(int H_,int W_) : H(H_),W(W_),a(\
    \ VV<T>(H,V<T>(W)) ){}\n\tMatrix(const VV<T>& v) : H(v.size()), W(v[0].size()),\
    \ a(v){}\n\n\tstatic Matrix E(int n){\n\t\tMatrix a(n,n);\n\t\trep(i,n) a[i][i]\
    \ = 1;\n\t\treturn a;\n\t}\n\n\tV<T>& operator[](int i){return a[i];}\n\tconst\
    \ V<T>& operator[](int i) const {return a[i];}\n\n\tMatrix operator+(const Matrix&\
    \ r) const {\n\t\tassert(H==r.H && W==r.W);\n\t\tVV<T> v(H,V<T>(W));\n\t\trep(i,H)\
    \ rep(j,W) v[i][j] = a[i][j] + r.a[i][j];\n\t\treturn Matrix(v);\n\t}\n\tMatrix\
    \ operator-(const Matrix& r) const {\n\t\tassert(H==r.H && W==r.W);\n\t\tVV<T>\
    \ v(H,V<T>(W));\n\t\trep(i,H) rep(j,W) v[i][j] = a[i][j] - r.a[i][j];\n\t\treturn\
    \ Matrix(v);\n\t}\n\tMatrix operator*(const Matrix& r) const {\n\t\tassert(W==r.H);\n\
    \t\tVV<T> v(H,V<T>(r.W));\n\t\trep(i,H) rep(k,W) rep(j,r.W) v[i][j] += a[i][k]\
    \ * r.a[k][j];\n\t\treturn Matrix(v);\n\t}\n\tMatrix& operator+=(const Matrix&\
    \ r){return (*this)=(*this)+r;}\n\tMatrix& operator-=(const Matrix& r){return\
    \ (*this)=(*this)-r;}\n\tMatrix& operator*=(const Matrix& r){return (*this)=(*this)*r;}\n\
    \n\tMatrix pow(ll p) const {\n\t\tassert(H == W);\n\t\tMatrix res = E(H);\n\t\t\
    Matrix x = *this;\n\t\twhile(p){\n\t\t\tif(p&1) res *= x;\n\t\t\tx *= x;\n\t\t\
    \tp >>= 1;\n\t\t}\n\t\treturn res;\n\t}\n\n\tfriend ostream& operator<<(ostream\
    \ &o,const Matrix& A){\n\t\trep(i,A.H){\n\t\t\trep(j,A.W) o<<A.a[i][j]<<\" \"\
    ;\n\t\t\to<<endl;\n\t\t}\n\t\treturn o;\n\t}\n\n\t/*\n\t\t\u526F\u4F5C\u7528\u304C\
    \u3042\u308B, \u57FA\u672C\u7684\u306B\u81EA\u5206\u3067\u3053\u308C\u3092\u547C\
    \u3076\u3053\u3068\u306F\u306A\u3044\n\t\t\u6383\u304D\u51FA\u3057\u6CD5\u3092\
    \u3059\u308B\n\t\t\u5DE6\u304B\u3089var\u5217\u304C\u6383\u304D\u51FA\u3059\u5BFE\
    \u8C61\u3067\u3001\u305D\u308C\u3088\u308A\u53F3\u306F\u540C\u6642\u306B\u5024\
    \u3092\u5909\u66F4\u3059\u308B\u3060\u3051(e.g. \u9006\u884C\u5217\u306F\u53F3\
    \u306B\u5358\u4F4D\u884C\u5217\u304A\u3044\u3066\u304B\u3089\u6383\u304D\u51FA\
    \u3059)\n\t\t\u884Cswap, \u5217swap \u306F\u884C\u308F\u306A\u3044\n\n\t\trank\
    \ \u3092\u8FD4\u3059\n\t*/\n\tint sweep(int var){\n\t\tint rank = 0;\n\t\tvector<bool>\
    \ used(H);\n\t\trep(j,var){\n\t\t\tint i=0;\n\t\t\twhile(i<H && (used[i]||iszero(a[i][j])))\
    \ i++;\n\t\t\tif(i==H) continue;\n\t\t\tused[i] = true;\n\t\t\trank++;\n\t\t\t\
    T t = a[i][j];\n\t\t\trep(k,W) a[i][k] = a[i][k]/t;\n\t\t\trep(k,H) if(k!=i){\n\
    \t\t\t\tT tt = a[k][j];\n\t\t\t\trep(l,W) a[k][l] = a[k][l]-a[i][l]*tt;\n\t\t\t\
    }\n\t\t}\n\t\treturn rank;\n\t}\n};\n\n/*\n\t\u9006\u884C\u5217\u3092\u8FD4\u3059\
    \n\t\u306A\u3051\u308C\u30700*0\u884C\u5217\n*/\ntemplate<class T>\nMatrix<T>\
    \ inv(const Matrix<T>& A){\n\tassert(A.H==A.W);\n\tint N = A.H;\n\tMatrix<T> X(N,2*N);\n\
    \trep(i,N) rep(j,N) X[i][j] = A[i][j];\n\trep(i,N) X[i][i+N] = 1;\n\tint rank\
    \ = X.sweep(N);\n\tif(rank < N) return Matrix<T>();\n\tMatrix<T> B(N,N);\n\trep(i,N){\n\
    \t\trep(j,N){\n\t\t\tB[i][j] = X[i][j+N];\n\t\t}\n\t}\n\treturn B;\n}\n\n/*\n\t\
    Ax = b \u3092\u89E3\u304F\n\tpair(\u89E3\u7A7A\u9593\u306E\u6B21\u5143, \u89E3\
    \u306E\u3046\u3061\u3072\u3068\u3064) \u3092\u8FD4\u3059\n\t\u89E3\u304C\u5B58\
    \u5728\u3057\u306A\u3044\u306A\u3089(-1,{})\n\n\t\u89E3\u3092\u8907\u6570\u5F97\
    \u305F\u3044 \u2192 \u30E9\u30F3\u30C0\u30E0\u306A\u5F0F\u3092\u8FFD\u52A0?\n\
    */\ntemplate<class T>\npair< int, vector<T> > solveLinearEquation(const Matrix<T>&\
    \ A, vector<T> b){\n\tassert(A.H==(int)b.size());\n\tint H = A.H, W = A.W;\n\n\
    \tMatrix<T> X(H,W+1);\n\trep(i,H) rep(j,W) X[i][j] = A[i][j];\n\trep(i,H) X[i][W]\
    \ = b[i];\n\tint rank = X.sweep(W);\n\trep(i,H){\n\t\tbool allzero = true;\n\t\
    \trep(j,W) if(!iszero(X[i][j])) allzero = false;\n\t\tif(allzero){\n\t\t\tif(!iszero(X[i][W])){\t\
    \t//0x + 0y + 0z = non0\n\t\t\t\treturn pair<int,vector<T> >(-1,vector<T>());\n\
    \t\t\t}\n\t\t}\n\t}\n\tvector<bool> done(H);\n\tvector<T> x(W);\n\trep(j,W){\n\
    \t\tint c0 = 0, c1 = 0;\n\t\tint I = -1;\n\t\trep(i,H){\n\t\t\tif(iszero(X[i][j]))\
    \ c0++;\n\t\t\telse if(isone(X[i][j])) c1++,I=i;\n\t\t}\n\t\tif(c0==H-1 && c1==1\
    \ && !done[I]){\n\t\t\tx[j] = X[I][W];\n\t\t\tdone[I] = true;\n\t\t}\n\t}\n\t\
    return pair<int,vector<T> >(W-rank,x);\n}\n\n/*\n\tdeterminant\n*/\ntemplate<class\
    \ T>\nT det(VV<T> a){\n\tconst int N = a.size();\n\tif(N == 0) return T(1);\n\t\
    assert(int(a[0].size()) == N);\n\tT ans(1);\n\trep(i,N){\n\t\tfor(int j=i+1;j<N;j++)\
    \ if(!iszero(a[j][i])){\n\t\t\tans = -ans;\n\t\t\tswap(a[j],a[i]);\n\t\t\tbreak;\n\
    \t\t}\n\t\tif(iszero(a[i][i])) return T(0);\n\t\tans *= a[i][i];\n\t\tfor(int\
    \ j=i+1;j<N;j++){\n\t\t\tmint w = -a[j][i]/a[i][i];\n\t\t\tfor(int k=i;k<N;k++)\
    \ a[j][k] += a[i][k]*w;\n\t\t}\n\t}\n\treturn ans;\n}\n\n/*\n\trank\n*/\ntemplate<class\
    \ T>\nint getrank(Matrix<T> A){\n\treturn A.sweep(A.W);\n}\n"
  code: "/*\n\t\u884C\u5217\u306E\u57FA\u672C\u6F14\u7B97, \u9023\u7ACB\u4E00\u6B21\
    \u65B9\u7A0B\u5F0F\u306E\u89E3, \u9006\u884C\u5217 \u3068\u304B\n\ttemplate \u5F15\
    \u6570 T \u306F\u4F53\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\n\t+,-,*,/,\
    \ unary -\n\t\u306E\u4ED6\u306B, zero, one, iszero(), isone() \u304C\u3044\u308B\
    \n\t\u6D6E\u52D5\u5C0F\u6570\u70B9\u3068\u304B\u306E\u305F\u3081\u306Biszero\u3068\
    \u304B\u306F==zero\u3092\u907F\u3051\u3066\u3044\u308B\n\n\tusage:\n\t\tfield\
    \ class (mint\u3068\u304B) \u3092\u7528\u610F\u3059\u308B\n\t\tzero,one,iszero(),isone()\u3092\
    \u66F8\u304F\n\n\tsolveLinearEquation\u306B0\u500B\u306E\u5F0F\u3092\u5165\u308C\
    \u308B\u3068\u6A2A\u5E45\u304C\u53D6\u5F97\u3067\u304D\u305A[0].size() \u3067\
    \ segfault \u306E\u3067\u6CE8\u610F\n\n\tcomplexity:\n\t\tsweep\u7CFB\u306F\u3059\
    \u3079\u3066 O(rank * H * W)\n\t\trank\u304C\u5C0F\u3055\u3044\u3068\u52DD\u624B\
    \u306B\u8A08\u7B97\u91CF\u306F\u6E1B\u308B\n\n\t\t\u5B9A\u6570\u500D\u304C\u9045\
    \u3044\u306E\u3067500\u3068\u304B\u306E\u3068\u304D\u306F\u5225\u306E\u3092\u4F7F\
    \u3046\n\n\tverified at http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624\
    \ (solveLinearEquarion mod 2)\n\tverified at https://official.contest.yandex.ru/opencupXIX/contest/9262/problems/K\
    \ (sLE on Rationals)\n\n*/\n\ntemplate<class T>\nstruct Matrix{\n\tint H,W;\n\t\
    VV<T> a;\n\n\tMatrix() : H(0),W(0){}\n\tMatrix(int H_,int W_) : H(H_),W(W_),a(\
    \ VV<T>(H,V<T>(W)) ){}\n\tMatrix(const VV<T>& v) : H(v.size()), W(v[0].size()),\
    \ a(v){}\n\n\tstatic Matrix E(int n){\n\t\tMatrix a(n,n);\n\t\trep(i,n) a[i][i]\
    \ = 1;\n\t\treturn a;\n\t}\n\n\tV<T>& operator[](int i){return a[i];}\n\tconst\
    \ V<T>& operator[](int i) const {return a[i];}\n\n\tMatrix operator+(const Matrix&\
    \ r) const {\n\t\tassert(H==r.H && W==r.W);\n\t\tVV<T> v(H,V<T>(W));\n\t\trep(i,H)\
    \ rep(j,W) v[i][j] = a[i][j] + r.a[i][j];\n\t\treturn Matrix(v);\n\t}\n\tMatrix\
    \ operator-(const Matrix& r) const {\n\t\tassert(H==r.H && W==r.W);\n\t\tVV<T>\
    \ v(H,V<T>(W));\n\t\trep(i,H) rep(j,W) v[i][j] = a[i][j] - r.a[i][j];\n\t\treturn\
    \ Matrix(v);\n\t}\n\tMatrix operator*(const Matrix& r) const {\n\t\tassert(W==r.H);\n\
    \t\tVV<T> v(H,V<T>(r.W));\n\t\trep(i,H) rep(k,W) rep(j,r.W) v[i][j] += a[i][k]\
    \ * r.a[k][j];\n\t\treturn Matrix(v);\n\t}\n\tMatrix& operator+=(const Matrix&\
    \ r){return (*this)=(*this)+r;}\n\tMatrix& operator-=(const Matrix& r){return\
    \ (*this)=(*this)-r;}\n\tMatrix& operator*=(const Matrix& r){return (*this)=(*this)*r;}\n\
    \n\tMatrix pow(ll p) const {\n\t\tassert(H == W);\n\t\tMatrix res = E(H);\n\t\t\
    Matrix x = *this;\n\t\twhile(p){\n\t\t\tif(p&1) res *= x;\n\t\t\tx *= x;\n\t\t\
    \tp >>= 1;\n\t\t}\n\t\treturn res;\n\t}\n\n\tfriend ostream& operator<<(ostream\
    \ &o,const Matrix& A){\n\t\trep(i,A.H){\n\t\t\trep(j,A.W) o<<A.a[i][j]<<\" \"\
    ;\n\t\t\to<<endl;\n\t\t}\n\t\treturn o;\n\t}\n\n\t/*\n\t\t\u526F\u4F5C\u7528\u304C\
    \u3042\u308B, \u57FA\u672C\u7684\u306B\u81EA\u5206\u3067\u3053\u308C\u3092\u547C\
    \u3076\u3053\u3068\u306F\u306A\u3044\n\t\t\u6383\u304D\u51FA\u3057\u6CD5\u3092\
    \u3059\u308B\n\t\t\u5DE6\u304B\u3089var\u5217\u304C\u6383\u304D\u51FA\u3059\u5BFE\
    \u8C61\u3067\u3001\u305D\u308C\u3088\u308A\u53F3\u306F\u540C\u6642\u306B\u5024\
    \u3092\u5909\u66F4\u3059\u308B\u3060\u3051(e.g. \u9006\u884C\u5217\u306F\u53F3\
    \u306B\u5358\u4F4D\u884C\u5217\u304A\u3044\u3066\u304B\u3089\u6383\u304D\u51FA\
    \u3059)\n\t\t\u884Cswap, \u5217swap \u306F\u884C\u308F\u306A\u3044\n\n\t\trank\
    \ \u3092\u8FD4\u3059\n\t*/\n\tint sweep(int var){\n\t\tint rank = 0;\n\t\tvector<bool>\
    \ used(H);\n\t\trep(j,var){\n\t\t\tint i=0;\n\t\t\twhile(i<H && (used[i]||iszero(a[i][j])))\
    \ i++;\n\t\t\tif(i==H) continue;\n\t\t\tused[i] = true;\n\t\t\trank++;\n\t\t\t\
    T t = a[i][j];\n\t\t\trep(k,W) a[i][k] = a[i][k]/t;\n\t\t\trep(k,H) if(k!=i){\n\
    \t\t\t\tT tt = a[k][j];\n\t\t\t\trep(l,W) a[k][l] = a[k][l]-a[i][l]*tt;\n\t\t\t\
    }\n\t\t}\n\t\treturn rank;\n\t}\n};\n\n/*\n\t\u9006\u884C\u5217\u3092\u8FD4\u3059\
    \n\t\u306A\u3051\u308C\u30700*0\u884C\u5217\n*/\ntemplate<class T>\nMatrix<T>\
    \ inv(const Matrix<T>& A){\n\tassert(A.H==A.W);\n\tint N = A.H;\n\tMatrix<T> X(N,2*N);\n\
    \trep(i,N) rep(j,N) X[i][j] = A[i][j];\n\trep(i,N) X[i][i+N] = 1;\n\tint rank\
    \ = X.sweep(N);\n\tif(rank < N) return Matrix<T>();\n\tMatrix<T> B(N,N);\n\trep(i,N){\n\
    \t\trep(j,N){\n\t\t\tB[i][j] = X[i][j+N];\n\t\t}\n\t}\n\treturn B;\n}\n\n/*\n\t\
    Ax = b \u3092\u89E3\u304F\n\tpair(\u89E3\u7A7A\u9593\u306E\u6B21\u5143, \u89E3\
    \u306E\u3046\u3061\u3072\u3068\u3064) \u3092\u8FD4\u3059\n\t\u89E3\u304C\u5B58\
    \u5728\u3057\u306A\u3044\u306A\u3089(-1,{})\n\n\t\u89E3\u3092\u8907\u6570\u5F97\
    \u305F\u3044 \u2192 \u30E9\u30F3\u30C0\u30E0\u306A\u5F0F\u3092\u8FFD\u52A0?\n\
    */\ntemplate<class T>\npair< int, vector<T> > solveLinearEquation(const Matrix<T>&\
    \ A, vector<T> b){\n\tassert(A.H==(int)b.size());\n\tint H = A.H, W = A.W;\n\n\
    \tMatrix<T> X(H,W+1);\n\trep(i,H) rep(j,W) X[i][j] = A[i][j];\n\trep(i,H) X[i][W]\
    \ = b[i];\n\tint rank = X.sweep(W);\n\trep(i,H){\n\t\tbool allzero = true;\n\t\
    \trep(j,W) if(!iszero(X[i][j])) allzero = false;\n\t\tif(allzero){\n\t\t\tif(!iszero(X[i][W])){\t\
    \t//0x + 0y + 0z = non0\n\t\t\t\treturn pair<int,vector<T> >(-1,vector<T>());\n\
    \t\t\t}\n\t\t}\n\t}\n\tvector<bool> done(H);\n\tvector<T> x(W);\n\trep(j,W){\n\
    \t\tint c0 = 0, c1 = 0;\n\t\tint I = -1;\n\t\trep(i,H){\n\t\t\tif(iszero(X[i][j]))\
    \ c0++;\n\t\t\telse if(isone(X[i][j])) c1++,I=i;\n\t\t}\n\t\tif(c0==H-1 && c1==1\
    \ && !done[I]){\n\t\t\tx[j] = X[I][W];\n\t\t\tdone[I] = true;\n\t\t}\n\t}\n\t\
    return pair<int,vector<T> >(W-rank,x);\n}\n\n/*\n\tdeterminant\n*/\ntemplate<class\
    \ T>\nT det(VV<T> a){\n\tconst int N = a.size();\n\tif(N == 0) return T(1);\n\t\
    assert(int(a[0].size()) == N);\n\tT ans(1);\n\trep(i,N){\n\t\tfor(int j=i+1;j<N;j++)\
    \ if(!iszero(a[j][i])){\n\t\t\tans = -ans;\n\t\t\tswap(a[j],a[i]);\n\t\t\tbreak;\n\
    \t\t}\n\t\tif(iszero(a[i][i])) return T(0);\n\t\tans *= a[i][i];\n\t\tfor(int\
    \ j=i+1;j<N;j++){\n\t\t\tmint w = -a[j][i]/a[i][i];\n\t\t\tfor(int k=i;k<N;k++)\
    \ a[j][k] += a[i][k]*w;\n\t\t}\n\t}\n\treturn ans;\n}\n\n/*\n\trank\n*/\ntemplate<class\
    \ T>\nint getrank(Matrix<T> A){\n\treturn A.sweep(A.W);\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/matrix.cpp
  requiredBy: []
  timestamp: '2021-12-26 19:27:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix/matrix.cpp
layout: document
redirect_from:
- /library/math/matrix/matrix.cpp
- /library/math/matrix/matrix.cpp.html
title: math/matrix/matrix.cpp
---
