---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix/matrix_basic.cpp
    title: math/matrix/matrix_basic.cpp
  - icon: ':heavy_check_mark:'
    path: math/mint.cpp
    title: math/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE_IF_CLANG: ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"test_oj/matrix_basic.test.cpp\"\n#ifdef __clang__\n#define\
    \ IGNORE\n#else\n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\
    \n#endif\n\n#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){\n\treturn o<<\"\
    (\"<<p.fs<<\",\"<<p.sc<<\")\";\n}\ntemplate<class T> ostream& operator<<(ostream&\
    \ o,const vector<T> &vc){\n\to<<\"{\";\n\tfor(const T& v:vc) o<<v<<\",\";\n\t\
    o<<\"}\";\n\treturn o;\n}\nusing ll = long long;\ntemplate<class T> using V =\
    \ vector<T>;\ntemplate<class T> using VV = vector<vector<T>>;\nconstexpr ll TEN(int\
    \ n) { return (n == 0) ? 1 : 10 * TEN(n-1); }\n\n#ifdef LOCAL\n#define show(x)\
    \ cerr << \"LINE\" << __LINE__ << \" : \" << #x << \" = \" << (x) << endl\n#else\n\
    #define show(x) true\n#endif\n\n#line 1 \"math/matrix/matrix_basic.cpp\"\n/*\n\
    \t\u57FA\u672C\u64CD\u4F5C\u3060\u3051Matrix\u30E9\u30A4\u30D6\u30E9\u30EA\u306B\
    \u3059\u308B\u3053\u3068\u306B\n\tsweep\u3068\u304B\u306F\u3082\u3046\u76F4\u63A5\
    vector<vector<T>> \u306E\u95A2\u6570\u3067\u66F8\u304F\n*/\n\ntemplate<class T>\n\
    struct Matrix: public vector<vector<T>>{\n\n\tMatrix(int n) : vector<vector<T>>(n,vector<T>(n,0)){}\n\
    \tMatrix(int h,int w) : vector<vector<T>>(h,vector<T>(w,0)){}\n\n\tstatic Matrix\
    \ E(int n){\n\t\tMatrix a(n,n);\n\t\trep(i,n) a[i][i] = 1;\n\t\treturn a;\n\t\
    }\n\tint h() const { return (*this).size(); }\n\tint w() const { return (*this)[0].size();\
    \ }\n\n\tMatrix operator+(const Matrix& r) const {\n\t\tassert(h() == r.h() &&\
    \ w() == r.w());\n\t\tint H = h(), W = w();\n\t\tMatrix z(H,W);\n\t\trep(i,H)\
    \ rep(j,W) z[i][j] = (*this)[i][j] + r[i][j];\n\t\treturn z;\n\t}\n\tMatrix operator-(const\
    \ Matrix& r) const {\n\t\tassert(h() == r.h() && w() == r.w());\n\t\tint H = h(),\
    \ W = w();\n\t\tMatrix z(H,W);\n\t\trep(i,H) rep(j,W) z[i][j] = (*this)[i][j]\
    \ - r[i][j];\n\t\treturn z;\n\t}\n\tMatrix operator*(const Matrix& r) const {\n\
    \t\tassert(w() == r.h());\n\t\tint A = h(), B = w(), C = r.w();\n\t\tMatrix z(A,C);\n\
    \t\trep(i,A) rep(k,B) rep(j,C) z[i][j] += (*this)[i][k] * r[k][j];\n\t\treturn\
    \ z;\n\t}\n\tMatrix& operator+=(const Matrix& r){return (*this)=(*this)+r;}\n\t\
    Matrix& operator-=(const Matrix& r){return (*this)=(*this)-r;}\n\tMatrix& operator*=(const\
    \ Matrix& r){return (*this)=(*this)*r;}\n\n\tMatrix pow(ll p) const {\n\t\tassert(h()\
    \ == w());\n\t\tMatrix res = E(h());\n\t\tMatrix x = *this;\n\t\twhile(p){\n\t\
    \t\tif(p&1) res *= x;\n\t\t\tx *= x;\n\t\t\tp >>= 1;\n\t\t}\n\t\treturn res;\n\
    \t}\n\n\tfriend ostream& operator<<(ostream &o,const Matrix& A){\n\t\trep(i,A.h()){\n\
    \t\t\trep(j,A.w()) o << A[i][j]<<\" \";\n\t\t\to << endl;\n\t\t}\n\t\treturn o;\n\
    \t}\n};\n#line 1 \"math/mint.cpp\"\n/*\n\t\u4EFB\u610Fmod \u306A\u3089 \n\ttemplate\
    \ \u306A\u304F\u3057\u3066 costexpr \u306E\u884C\u6D88\u3057\u3066 global \u306B\
    \ unsigned int mod = 1;\n\t\u3067 cin>>mod \u3057\u3066\u304B\u3089\u4F7F\u3046\
    \n*/\n\ntemplate<unsigned int mod_>\nstruct ModInt{\n\tusing uint = unsigned int;\n\
    \tusing ll = long long;\n\tusing ull = unsigned long long;\n\n\tconstexpr static\
    \ uint mod = mod_;\n\n\tuint v;\n\tModInt():v(0){}\n\tModInt(ll _v):v(normS(_v%mod+mod)){}\n\
    \texplicit operator bool() const {return v!=0;}\n\tstatic uint normS(const uint\
    \ &x){return (x<mod)?x:x-mod;}\t\t// [0 , 2*mod-1] -> [0 , mod-1]\n\tstatic ModInt\
    \ make(const uint &x){ModInt m; m.v=x; return m;}\n\tModInt operator+(const ModInt&\
    \ b) const { return make(normS(v+b.v));}\n\tModInt operator-(const ModInt& b)\
    \ const { return make(normS(v+mod-b.v));}\n\tModInt operator-() const { return\
    \ make(normS(mod-v)); }\n\tModInt operator*(const ModInt& b) const { return make((ull)v*b.v%mod);}\n\
    \tModInt operator/(const ModInt& b) const { return *this*b.inv();}\n\tModInt&\
    \ operator+=(const ModInt& b){ return *this=*this+b;}\n\tModInt& operator-=(const\
    \ ModInt& b){ return *this=*this-b;}\n\tModInt& operator*=(const ModInt& b){ return\
    \ *this=*this*b;}\n\tModInt& operator/=(const ModInt& b){ return *this=*this/b;}\n\
    \tModInt& operator++(int){ return *this=*this+1;}\n\tModInt& operator--(int){\
    \ return *this=*this-1;}\n\ttemplate<class T> friend ModInt operator+(T a, const\
    \ ModInt& b){ return (ModInt(a) += b);}\n\ttemplate<class T> friend ModInt operator-(T\
    \ a, const ModInt& b){ return (ModInt(a) -= b);}\n\ttemplate<class T> friend ModInt\
    \ operator*(T a, const ModInt& b){ return (ModInt(a) *= b);}\n\ttemplate<class\
    \ T> friend ModInt operator/(T a, const ModInt& b){ return (ModInt(a) /= b);}\n\
    \tModInt pow(ll p) const {\n\t\tif(p<0) return inv().pow(-p);\n\t\tModInt a =\
    \ 1;\n\t\tModInt x = *this;\n\t\twhile(p){\n\t\t\tif(p&1) a *= x;\n\t\t\tx *=\
    \ x;\n\t\t\tp >>= 1;\n\t\t}\n\t\treturn a;\n\t}\n\tModInt inv() const {\t\t//\
    \ should be prime\n\t\treturn pow(mod-2);\n\t}\n\t// ll extgcd(ll a,ll b,ll &x,ll\
    \ &y) const{\n\t// \tll p[]={a,1,0},q[]={b,0,1};\n\t// \twhile(*q){\n\t// \t\t\
    ll t=*p/ *q;\n\t// \t\trep(i,3) swap(p[i]-=t*q[i],q[i]);\n\t// \t}\n\t// \tif(p[0]<0)\
    \ rep(i,3) p[i]=-p[i];\n\t// \tx=p[1],y=p[2];\n\t// \treturn p[0];\n\t// }\n\t\
    // ModInt inv() const {\n\t// \tll x,y;\n\t// \textgcd(v,mod,x,y);\n\t// \treturn\
    \ make(normS(x+mod));\n\t// }\n\n\tbool operator==(const ModInt& b) const { return\
    \ v==b.v;}\n\tbool operator!=(const ModInt& b) const { return v!=b.v;}\n\tbool\
    \ operator<(const ModInt& b) const { return v<b.v;}\n\tfriend istream& operator>>(istream\
    \ &o,ModInt& x){\n\t\tll tmp;\n\t\to>>tmp;\n\t\tx=ModInt(tmp);\n\t\treturn o;\n\
    \t}\n\tfriend ostream& operator<<(ostream &o,const ModInt& x){ return o<<x.v;}\n\
    };\nusing mint = ModInt<998244353>;\n//using mint = ModInt<1000000007>;\n\nV<mint>\
    \ fact,ifact,invs;\nmint Choose(int a,int b){\n\tif(b<0 || a<b) return 0;\n\t\
    return fact[a] * ifact[b] * ifact[a-b];\n}\nvoid InitFact(int N){\t//[0,N]\n\t\
    N++;\n\tfact.resize(N);\n\tifact.resize(N);\n\tinvs.resize(N);\n\tfact[0] = 1;\n\
    \trep1(i,N-1) fact[i] = fact[i-1] * i;\n\tifact[N-1] = fact[N-1].inv();\n\tfor(int\
    \ i=N-2;i>=0;i--) ifact[i] = ifact[i+1] * (i+1);\n\trep1(i,N-1) invs[i] = fact[i-1]\
    \ * ifact[i];\n}\n#line 39 \"test_oj/matrix_basic.test.cpp\"\n\nint main(){\n\t\
    cin.tie(0);\n\tios::sync_with_stdio(false);\t\t//DON'T USE scanf/printf/puts !!\n\
    \tcout << fixed << setprecision(20);\n\t\n\tint p,q,r; cin >> p >> q >> r;\n\n\
    \tusing mat = Matrix<mint>;\n\tmat A(p,q), B(q,r);\n\trep(i,p) rep(j,q) cin >>\
    \ A[i][j];\n\trep(j,q) rep(k,r) cin >> B[j][k];\n\tauto C = A * B;\n\tcout <<\
    \ C;\n}\n"
  code: "#ifdef __clang__\n#define IGNORE\n#else\n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\
    \n#endif\n\n#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){\n\treturn o<<\"\
    (\"<<p.fs<<\",\"<<p.sc<<\")\";\n}\ntemplate<class T> ostream& operator<<(ostream&\
    \ o,const vector<T> &vc){\n\to<<\"{\";\n\tfor(const T& v:vc) o<<v<<\",\";\n\t\
    o<<\"}\";\n\treturn o;\n}\nusing ll = long long;\ntemplate<class T> using V =\
    \ vector<T>;\ntemplate<class T> using VV = vector<vector<T>>;\nconstexpr ll TEN(int\
    \ n) { return (n == 0) ? 1 : 10 * TEN(n-1); }\n\n#ifdef LOCAL\n#define show(x)\
    \ cerr << \"LINE\" << __LINE__ << \" : \" << #x << \" = \" << (x) << endl\n#else\n\
    #define show(x) true\n#endif\n\n#include \"../math/matrix/matrix_basic.cpp\"\n\
    #include \"../math/mint.cpp\"\n\nint main(){\n\tcin.tie(0);\n\tios::sync_with_stdio(false);\t\
    \t//DON'T USE scanf/printf/puts !!\n\tcout << fixed << setprecision(20);\n\t\n\
    \tint p,q,r; cin >> p >> q >> r;\n\n\tusing mat = Matrix<mint>;\n\tmat A(p,q),\
    \ B(q,r);\n\trep(i,p) rep(j,q) cin >> A[i][j];\n\trep(j,q) rep(k,r) cin >> B[j][k];\n\
    \tauto C = A * B;\n\tcout << C;\n}\n"
  dependsOn:
  - math/matrix/matrix_basic.cpp
  - math/mint.cpp
  isVerificationFile: true
  path: test_oj/matrix_basic.test.cpp
  requiredBy: []
  timestamp: '2021-12-27 22:50:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test_oj/matrix_basic.test.cpp
layout: document
redirect_from:
- /verify/test_oj/matrix_basic.test.cpp
- /verify/test_oj/matrix_basic.test.cpp.html
title: test_oj/matrix_basic.test.cpp
---
