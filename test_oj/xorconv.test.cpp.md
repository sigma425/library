---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/hadamard.cpp
    title: math/hadamard.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "#line 1 \"test_oj/xorconv.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ uint = unsigned int;\nusing ull = unsigned long long;\n#define rep(i,n) for(int\
    \ i=0;i<int(n);i++)\n#define rep1(i,n) for(int i=1;i<=int(n);i++)\n#define per(i,n)\
    \ for(int i=int(n)-1;i>=0;i--)\n#define per1(i,n) for(int i=int(n);i>0;i--)\n\
    #define all(c) c.begin(),c.end()\n#define si(x) int(x.size())\n#define pb emplace_back\n\
    #define fs first\n#define sc second\ntemplate<class T> using V = vector<T>;\n\
    template<class T> using VV = vector<vector<T>>;\ntemplate<class T,class U> void\
    \ chmax(T& x, U y){if(x<y) x=y;}\ntemplate<class T,class U> void chmin(T& x, U\
    \ y){if(y<x) x=y;}\ntemplate<class T> void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}\n\
    template<class T> int lwb(const V<T>& v, const T& a){return lower_bound(all(v),a)\
    \ - v.begin();}\ntemplate<class T>\nV<T> Vec(size_t a) {\n    return V<T>(a);\n\
    }\ntemplate<class T, class... Ts>\nauto Vec(size_t a, Ts... ts) {\n  return V<decltype(Vec<T>(ts...))>(a,\
    \ Vec<T>(ts...));\n}\ntemplate<class S,class T> ostream& operator<<(ostream& o,const\
    \ pair<S,T> &p){\n\treturn o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";\n}\ntemplate<class\
    \ T> ostream& operator<<(ostream& o,const vector<T> &vc){\n\to<<\"{\";\n\tfor(const\
    \ T& v:vc) o<<v<<\",\";\n\to<<\"}\";\n\treturn o;\n}\nconstexpr ll TEN(int n)\
    \ { return (n == 0) ? 1 : 10 * TEN(n-1); }\n\n#ifdef LOCAL\n#define show(x) cerr\
    \ << \"LINE\" << __LINE__ << \" : \" << #x << \" = \" << (x) << endl\nvoid dmpr(ostream&\
    \ os){os<<endl;}\ntemplate<class T,class... Args>\nvoid dmpr(ostream&os,const\
    \ T&t,const Args&... args){\n\tos<<t<<\" ~ \";\n\tdmpr(os,args...);\n}\n#define\
    \ shows(...) cerr << \"LINE\" << __LINE__ << \" : \";dmpr(cerr,##__VA_ARGS__)\n\
    #define dump(x) cerr << \"LINE\" << __LINE__ << \" : \" << #x << \" = {\";  \\\
    \n\tfor(auto v: x) cerr << v << \",\"; cerr << \"}\" << endl;\n#else\n#define\
    \ show(x) void(0)\n#define dump(x) void(0)\n#define shows(...) void(0)\n#endif\n\
    \n\n#line 1 \"math/mint.cpp\"\n/*\n\t\u4EFB\u610Fmod \u306A\u3089 \n\ttemplate\
    \ \u306A\u304F\u3057\u3066 costexpr \u306E\u884C\u6D88\u3057\u3066 global \u306B\
    \ unsigned int mod = 1;\n\t\u3067 cin>>mod \u3057\u3066\u304B\u3089\u4F7F\u3046\
    \n\t\u4EFB\u610F mod \u306F\u304B\u306A\u308A\u9045\u3044\u306E\u3067\u3001\u3067\
    \u304D\u308C\u3070 \"atcoder/modint\" \u3092\u4F7F\u3046\n*/\n\ntemplate<unsigned\
    \ int mod_>\nstruct ModInt{\t\n\tusing uint = unsigned int;\n\tusing ll = long\
    \ long;\n\tusing ull = unsigned long long;\n\n\tconstexpr static uint mod = mod_;\n\
    \n\tuint v;\n\tModInt():v(0){}\n\tModInt(ll _v):v(normS(_v%mod+mod)){}\n\texplicit\
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
    \t// friend ostream& operator<<(ostream &o,const ModInt& x){\n\t// \tfor(int b=1;b<=100;b++){\n\
    \t// \t\tfor(int a=-100;a<=100;a++){\n\t// \t\t\tif(ModInt(a)/b == x){\n\t// \t\
    \t\t\treturn o << a << \"/\" << b;\n\t// \t\t\t}\n\t// \t\t}\n\t// \t}\n\t// \t\
    return o<<x.v;\n\t// }\n};\nusing mint = ModInt<998244353>;\n//using mint = ModInt<1000000007>;\n\
    \nV<mint> fact,ifact,invs;\n// a,b >= 0 \u306E\u307F\nmint Choose(int a,int b){\n\
    \tif(b<0 || a<b) return 0;\n\treturn fact[a] * ifact[b] * ifact[a-b];\n}\n\n/*\n\
    // b >= 0 \u306E\u7BC4\u56F2\u3067\u3001 Choose(a,b) = a(a-1)..(a-b+1) / b!\n\
    mint Choose(int a,int b){\n\tif(b<0 || a<b) return 0;\n\treturn fact[a] * ifact[b]\
    \ * ifact[a-b];\n}\n*/\n\nvoid InitFact(int N){\t//[0,N]\n\tN++;\n\tfact.resize(N);\n\
    \tifact.resize(N);\n\tinvs.resize(N);\n\tfact[0] = 1;\n\trep1(i,N-1) fact[i] =\
    \ fact[i-1] * i;\n\tifact[N-1] = fact[N-1].inv();\n\tfor(int i=N-2;i>=0;i--) ifact[i]\
    \ = ifact[i+1] * (i+1);\n\trep1(i,N-1) invs[i] = fact[i-1] * ifact[i];\n}\n#line\
    \ 1 \"math/hadamard.cpp\"\ntemplate<class T>\nvoid hadamard(V<T>& a, bool inv\
    \ = false){\n\tint n = si(a);\n\tassert(__builtin_popcount(n) == 1);\n\tfor(int\
    \ i=1;i<n;i<<=1){\n\t\tfor(int j=0;j<n;j+=i<<1){\n\t\t\trep(k,i){\n\t\t\t\tT s\
    \ = a[j+k], t = a[j+k+i];\n\t\t\t\ta[j+k] = s+t;\n\t\t\t\ta[j+k+i] = s-t;\n\t\t\
    \t}\n\t\t}\n\t}\n\tif(inv){\n\t\tT in = T(1)/n;\n\t\tfor(auto& x: a) x *= in;\n\
    \t}\n}\n#line 62 \"test_oj/xorconv.test.cpp\"\n\nint main(){\n\tcin.tie(0);\n\t\
    ios::sync_with_stdio(false);\t\t//DON'T USE scanf/printf/puts !!\n\tcout << fixed\
    \ << setprecision(20);\n\n    int N; cin >> N;\n    V<mint> a(1<<N); for(auto&\
    \ v: a) cin >> v;\n    V<mint> b(1<<N); for(auto& v: b) cin >> v;\n    hadamard(a);\
    \ hadamard(b);\n    rep(i,1<<N) a[i] *= b[i];\n    hadamard(a,true);\n    for(auto\
    \ v: a) cout << v << \" \";\n    cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ uint = unsigned int;\nusing ull = unsigned long long;\n#define rep(i,n) for(int\
    \ i=0;i<int(n);i++)\n#define rep1(i,n) for(int i=1;i<=int(n);i++)\n#define per(i,n)\
    \ for(int i=int(n)-1;i>=0;i--)\n#define per1(i,n) for(int i=int(n);i>0;i--)\n\
    #define all(c) c.begin(),c.end()\n#define si(x) int(x.size())\n#define pb emplace_back\n\
    #define fs first\n#define sc second\ntemplate<class T> using V = vector<T>;\n\
    template<class T> using VV = vector<vector<T>>;\ntemplate<class T,class U> void\
    \ chmax(T& x, U y){if(x<y) x=y;}\ntemplate<class T,class U> void chmin(T& x, U\
    \ y){if(y<x) x=y;}\ntemplate<class T> void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}\n\
    template<class T> int lwb(const V<T>& v, const T& a){return lower_bound(all(v),a)\
    \ - v.begin();}\ntemplate<class T>\nV<T> Vec(size_t a) {\n    return V<T>(a);\n\
    }\ntemplate<class T, class... Ts>\nauto Vec(size_t a, Ts... ts) {\n  return V<decltype(Vec<T>(ts...))>(a,\
    \ Vec<T>(ts...));\n}\ntemplate<class S,class T> ostream& operator<<(ostream& o,const\
    \ pair<S,T> &p){\n\treturn o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";\n}\ntemplate<class\
    \ T> ostream& operator<<(ostream& o,const vector<T> &vc){\n\to<<\"{\";\n\tfor(const\
    \ T& v:vc) o<<v<<\",\";\n\to<<\"}\";\n\treturn o;\n}\nconstexpr ll TEN(int n)\
    \ { return (n == 0) ? 1 : 10 * TEN(n-1); }\n\n#ifdef LOCAL\n#define show(x) cerr\
    \ << \"LINE\" << __LINE__ << \" : \" << #x << \" = \" << (x) << endl\nvoid dmpr(ostream&\
    \ os){os<<endl;}\ntemplate<class T,class... Args>\nvoid dmpr(ostream&os,const\
    \ T&t,const Args&... args){\n\tos<<t<<\" ~ \";\n\tdmpr(os,args...);\n}\n#define\
    \ shows(...) cerr << \"LINE\" << __LINE__ << \" : \";dmpr(cerr,##__VA_ARGS__)\n\
    #define dump(x) cerr << \"LINE\" << __LINE__ << \" : \" << #x << \" = {\";  \\\
    \n\tfor(auto v: x) cerr << v << \",\"; cerr << \"}\" << endl;\n#else\n#define\
    \ show(x) void(0)\n#define dump(x) void(0)\n#define shows(...) void(0)\n#endif\n\
    \n\n#include \"../math/mint.cpp\"\n#include \"../math/hadamard.cpp\"\n\nint main(){\n\
    \tcin.tie(0);\n\tios::sync_with_stdio(false);\t\t//DON'T USE scanf/printf/puts\
    \ !!\n\tcout << fixed << setprecision(20);\n\n    int N; cin >> N;\n    V<mint>\
    \ a(1<<N); for(auto& v: a) cin >> v;\n    V<mint> b(1<<N); for(auto& v: b) cin\
    \ >> v;\n    hadamard(a); hadamard(b);\n    rep(i,1<<N) a[i] *= b[i];\n    hadamard(a,true);\n\
    \    for(auto v: a) cout << v << \" \";\n    cout << endl;\n}\n"
  dependsOn:
  - math/mint.cpp
  - math/hadamard.cpp
  isVerificationFile: true
  path: test_oj/xorconv.test.cpp
  requiredBy: []
  timestamp: '2024-07-25 11:02:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test_oj/xorconv.test.cpp
layout: document
redirect_from:
- /verify/test_oj/xorconv.test.cpp
- /verify/test_oj/xorconv.test.cpp.html
title: test_oj/xorconv.test.cpp
---
