---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/mint.cpp\"\n/*\n\t\u4EFB\u610Fmod \u306A\u3089 \n\t\
    template \u306A\u304F\u3057\u3066 costexpr \u306E\u884C\u6D88\u3057\u3066 global\
    \ \u306B unsigned int mod = 1;\n\t\u3067 cin>>mod \u3057\u3066\u304B\u3089\u4F7F\
    \u3046\n*/\n\ntemplate<unsigned int mod_>\nstruct ModInt{\n\tusing uint = unsigned\
    \ int;\n\tusing ll = long long;\n\tusing ull = unsigned long long;\n\n\tconstexpr\
    \ static uint mod = mod_;\n\n\tuint v;\n\tModInt():v(0){}\n\tModInt(ll _v):v(normS(_v%mod+mod)){}\n\
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
    \ return *this=*this-1;}\n\tll extgcd(ll a,ll b,ll &x,ll &y) const{\n\t\tll p[]={a,1,0},q[]={b,0,1};\n\
    \t\twhile(*q){\n\t\t\tll t=*p/ *q;\n\t\t\trep(i,3) swap(p[i]-=t*q[i],q[i]);\n\t\
    \t}\n\t\tif(p[0]<0) rep(i,3) p[i]=-p[i];\n\t\tx=p[1],y=p[2];\n\t\treturn p[0];\n\
    \t}\n\tModInt inv() const {\n\t\tll x,y;\n\t\textgcd(v,mod,x,y);\n\t\treturn make(normS(x+mod));\n\
    \t}\n\tModInt pow(ll p) const {\n\t\tif(p<0) return inv().pow(-p);\n\t\tModInt\
    \ a = 1;\n\t\tModInt x = *this;\n\t\twhile(p){\n\t\t\tif(p&1) a *= x;\n\t\t\t\
    x *= x;\n\t\t\tp >>= 1;\n\t\t}\n\t\treturn a;\n\t}\n\tbool operator==(const ModInt&\
    \ b) const { return v==b.v;}\n\tbool operator!=(const ModInt& b) const { return\
    \ v!=b.v;}\n\tfriend istream& operator>>(istream &o,ModInt& x){\n\t\tll tmp;\n\
    \t\to>>tmp;\n\t\tx=ModInt(tmp);\n\t\treturn o;\n\t}\n\tfriend ostream& operator<<(ostream\
    \ &o,const ModInt& x){ return o<<x.v;}\n};\nusing mint = ModInt<998244353>;\n\
    //using mint = ModInt<1000000007>;\n\nV<mint> fact,ifact,invs;\nmint Choose(int\
    \ a,int b){\n\tif(b<0 || a<b) return 0;\n\treturn fact[a] * ifact[b] * ifact[a-b];\n\
    }\nvoid InitFact(int N){\t//[0,N]\n\tN++;\n\tfact.resize(N);\n\tifact.resize(N);\n\
    \tinvs.resize(N);\n\tfact[0] = 1;\n\trep1(i,N-1) fact[i] = fact[i-1] * i;\n\t\
    ifact[N-1] = fact[N-1].inv();\n\tfor(int i=N-2;i>=0;i--) ifact[i] = ifact[i+1]\
    \ * (i+1);\n\trep1(i,N-1) invs[i] = fact[i-1] * ifact[i];\n}\n"
  code: "/*\n\t\u4EFB\u610Fmod \u306A\u3089 \n\ttemplate \u306A\u304F\u3057\u3066\
    \ costexpr \u306E\u884C\u6D88\u3057\u3066 global \u306B unsigned int mod = 1;\n\
    \t\u3067 cin>>mod \u3057\u3066\u304B\u3089\u4F7F\u3046\n*/\n\ntemplate<unsigned\
    \ int mod_>\nstruct ModInt{\n\tusing uint = unsigned int;\n\tusing ll = long long;\n\
    \tusing ull = unsigned long long;\n\n\tconstexpr static uint mod = mod_;\n\n\t\
    uint v;\n\tModInt():v(0){}\n\tModInt(ll _v):v(normS(_v%mod+mod)){}\n\texplicit\
    \ operator bool() const {return v!=0;}\n\tstatic uint normS(const uint &x){return\
    \ (x<mod)?x:x-mod;}\t\t// [0 , 2*mod-1] -> [0 , mod-1]\n\tstatic ModInt make(const\
    \ uint &x){ModInt m; m.v=x; return m;}\n\tModInt operator+(const ModInt& b) const\
    \ { return make(normS(v+b.v));}\n\tModInt operator-(const ModInt& b) const { return\
    \ make(normS(v+mod-b.v));}\n\tModInt operator-() const { return make(normS(mod-v));\
    \ }\n\tModInt operator*(const ModInt& b) const { return make((ull)v*b.v%mod);}\n\
    \tModInt operator/(const ModInt& b) const { return *this*b.inv();}\n\tModInt&\
    \ operator+=(const ModInt& b){ return *this=*this+b;}\n\tModInt& operator-=(const\
    \ ModInt& b){ return *this=*this-b;}\n\tModInt& operator*=(const ModInt& b){ return\
    \ *this=*this*b;}\n\tModInt& operator/=(const ModInt& b){ return *this=*this/b;}\n\
    \tModInt& operator++(int){ return *this=*this+1;}\n\tModInt& operator--(int){\
    \ return *this=*this-1;}\n\tll extgcd(ll a,ll b,ll &x,ll &y) const{\n\t\tll p[]={a,1,0},q[]={b,0,1};\n\
    \t\twhile(*q){\n\t\t\tll t=*p/ *q;\n\t\t\trep(i,3) swap(p[i]-=t*q[i],q[i]);\n\t\
    \t}\n\t\tif(p[0]<0) rep(i,3) p[i]=-p[i];\n\t\tx=p[1],y=p[2];\n\t\treturn p[0];\n\
    \t}\n\tModInt inv() const {\n\t\tll x,y;\n\t\textgcd(v,mod,x,y);\n\t\treturn make(normS(x+mod));\n\
    \t}\n\tModInt pow(ll p) const {\n\t\tif(p<0) return inv().pow(-p);\n\t\tModInt\
    \ a = 1;\n\t\tModInt x = *this;\n\t\twhile(p){\n\t\t\tif(p&1) a *= x;\n\t\t\t\
    x *= x;\n\t\t\tp >>= 1;\n\t\t}\n\t\treturn a;\n\t}\n\tbool operator==(const ModInt&\
    \ b) const { return v==b.v;}\n\tbool operator!=(const ModInt& b) const { return\
    \ v!=b.v;}\n\tfriend istream& operator>>(istream &o,ModInt& x){\n\t\tll tmp;\n\
    \t\to>>tmp;\n\t\tx=ModInt(tmp);\n\t\treturn o;\n\t}\n\tfriend ostream& operator<<(ostream\
    \ &o,const ModInt& x){ return o<<x.v;}\n};\nusing mint = ModInt<998244353>;\n\
    //using mint = ModInt<1000000007>;\n\nV<mint> fact,ifact,invs;\nmint Choose(int\
    \ a,int b){\n\tif(b<0 || a<b) return 0;\n\treturn fact[a] * ifact[b] * ifact[a-b];\n\
    }\nvoid InitFact(int N){\t//[0,N]\n\tN++;\n\tfact.resize(N);\n\tifact.resize(N);\n\
    \tinvs.resize(N);\n\tfact[0] = 1;\n\trep1(i,N-1) fact[i] = fact[i-1] * i;\n\t\
    ifact[N-1] = fact[N-1].inv();\n\tfor(int i=N-2;i>=0;i--) ifact[i] = ifact[i+1]\
    \ * (i+1);\n\trep1(i,N-1) invs[i] = fact[i-1] * ifact[i];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mint.cpp
  requiredBy: []
  timestamp: '2020-10-14 02:20:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mint.cpp
layout: document
redirect_from:
- /library/math/mint.cpp
- /library/math/mint.cpp.html
title: math/mint.cpp
---