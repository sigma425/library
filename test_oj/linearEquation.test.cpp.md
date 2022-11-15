---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix/linear.cpp
    title: math/matrix/linear.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/system_of_linear_equations
    links:
    - https://judge.yosupo.jp/problem/system_of_linear_equations
  bundledCode: "#line 1 \"test_oj/linearEquation.test.cpp\"\n#ifdef __clang__\n#define\
    \ IGNORE\n#else\n#define PROBLEM \"https://judge.yosupo.jp/problem/system_of_linear_equations\"\
    \n#endif\n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\
    using uint = unsigned int;\nusing ull = unsigned long long;\n#define rep(i,n)\
    \ for(int i=0;i<int(n);i++)\n#define rep1(i,n) for(int i=1;i<=int(n);i++)\n#define\
    \ per(i,n) for(int i=int(n)-1;i>=0;i--)\n#define per1(i,n) for(int i=int(n);i>0;i--)\n\
    #define all(c) c.begin(),c.end()\n#define si(x) int(x.size())\n#define pb push_back\n\
    #define eb emplace_back\n#define fs first\n#define sc second\ntemplate<class T>\
    \ using V = vector<T>;\ntemplate<class T> using VV = vector<vector<T>>;\ntemplate<class\
    \ T,class U> bool chmax(T& x, U y){\n\tif(x<y){ x=y; return true; }\n\treturn\
    \ false;\n}\ntemplate<class T,class U> bool chmin(T& x, U y){\n\tif(y<x){ x=y;\
    \ return true; }\n\treturn false;\n}\ntemplate<class T> void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}\n\
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
    \ntemplate<class D> D divFloor(D a, D b){\n\treturn a / b - (((a ^ b) < 0 && a\
    \ % b != 0) ? 1 : 0);\n}\ntemplate<class D> D divCeil(D a, D b) {\n\treturn a\
    \ / b + (((a ^ b) > 0 && a % b != 0) ? 1 : 0);\n}\n\n\n#line 1 \"math/matrix/linear.cpp\"\
    \n/*\n\t\u7DDA\u5F62\u4EE3\u6570\u3044\u308D\u3044\u308D\n\tverified: yosupo\n\
    */\n\ntemplate<class T>\nT det(vector<vector<T>> a){\n\tassert(a.size() == a[0].size());\n\
    \tint n = a.size();\n\tT ans = 1;\n\trep(i,n){\n\t\tfor(int j=i+1;j<n;j++) if(a[j][i]){\n\
    \t\t\tans = -ans;\n\t\t\tswap(a[j],a[i]);\n\t\t\tbreak;\n\t\t}\n\t\tif(!a[i][i])\
    \ return T(0);\n\t\tans *= a[i][i];\n\t\tfor(int j=i+1;j<n;j++){\n\t\t\tT w =\
    \ -a[j][i]/a[i][i];\n\t\t\tfor(int k=i;k<n;k++) a[j][k] += a[i][k]*w;\n\t\t}\n\
    \t}\n\treturn ans;\t\n}\n/*\n\t\u5DE6c\u5217\u3092sweep \u6307\u5B9A\u3057\u306A\
    \u3044\u3068c = w\n\t\u884C\u306Eswap\u306F\u3059\u308B\n\t\u6383\u304D\u51FA\u3057\
    \u306B\u4F7F\u3063\u305F\u5217\u306E\u96C6\u5408\u3092\u8FD4\u3059\n*/\ntemplate<class\
    \ T>\nvector<int> sweep(vector<vector<T>>& a, int c = -1){\n\tif(a.empty()) return\
    \ {};\n\tif(c == -1) c = a[0].size();\n\tint h = a.size(), w = a[0].size(), r\
    \ = 0;\n\tvector<int> used_col;\n\trep(i,c){\n\t\tif(r == h) break;\n\t\tfor(int\
    \ j=r;j<h;j++) if(a[j][i]){\n\t\t\tswap(a[r],a[j]); break;\n\t\t}\n\t\tif(!a[r][i])\
    \ continue;\n\t\trep(j,h) if(j != r){\n\t\t\tconst T t = -a[j][i]/a[r][i];\n\t\
    \t\tfor(int k=i;k<w;k++) a[j][k] += a[r][k]*t;\n\t\t}\n\t\tused_col.pb(i);\n\t\
    \tr++;\n\t}\n\treturn used_col;\n}\n\n/*\n\tax = b \u306E\u89E3\u306E\u3072\u3068\
    \u3064\u3092\u51FA\u529B\n\t\u89E3\u7A7A\u9593\u306F (output) + ker(a)\n\t\u89E3\
    \u304C\u5B58\u5728\u3057\u306A\u3044\u306A\u3089 {}\n\n\t\u5F0F\u304C0\u500B(si(a)\
    \ == 0) \u3067\u58CA\u308C\u306A\u3044\u3088\u3046\u306B\u5909\u6570\u306E\u500B\
    \u6570 ( = si(a[0]) ) w \u3092\u4E0E\u3048\u308B\n*/\ntemplate<class T>\nvector<T>\
    \ linearEquation(vector<vector<T>> a, int w, vector<T> b){\n\tassert(a.size()\
    \ == b.size());\n\tint h = a.size();\n\trep(i,h) a[i].pb(b[i]);\n\tvector<int>\
    \ idx = sweep(a,w);\n\tfor(int i = idx.size();i<h;i++) if(a[i][w]) return {};\n\
    \tvector<T> x(w);\n\trep(i,idx.size()) x[idx[i]] = a[i][w] / a[i][idx[i]];\n\t\
    return x;\n}\n/*\n\t{x | ax = 0} \u306E\u3042\u308B\u57FA\u5E95\u3092\u51FA\u529B\
    \n\t\u5F0F\u304C0\u500B(si(a) == 0) \u3067\u58CA\u308C\u306A\u3044\u3088\u3046\
    \u306B\u5909\u6570\u306E\u500B\u6570 ( = si(a[0]) ) w \u3092\u4E0E\u3048\u308B\
    \n\tsi(kernel) + rank(a) == w\n*/\ntemplate<class T>\nvector<vector<T>> kernel(vector<vector<T>>\
    \ a, int w){\n\tint h = a.size();\n\tvector<vector<T>> b(w,vector<T>(h+w));\n\t\
    rep(i,h) rep(j,w) b[j][i] = a[i][j];\n\trep(i,w) b[i][h+i] = 1;\n\tint r = sweep(b,h).size();\n\
    \tvector<vector<T>> res;\n\tfor(int i=r;i<w;i++) res.eb(b[i].begin()+h,b[i].end());\n\
    \treturn res;\n}\n\n// mod 2\n// \u5E45(\u4F8B: \u5909\u6570\u306E\u500B\u6570\
    )\u3060\u3051bitset\u306B\u3057\u3066\u7E26\u306F\u3057\u3066\u306A\u3044\u3053\
    \u3068\u306B\u6CE8\u610F\n// \u4F8B\u3048\u3070 Ax = b \u306E b \u306F vector<bool>\n\
    using BS = bitset<8010>;\t// max_width\nvector<int> sweep_mod2(vector<BS>& a,\
    \ int c = -1){\n\tif(a.empty()) return {};\n\tif(c == -1) c = a[0].size();\n\t\
    int h = a.size(), r = 0;\n\tvector<int> used_col;\n\trep(i,c){\n\t\tif(r == h)\
    \ break;\n\t\tfor(int j=r;j<h;j++) if(a[j][i]){\n\t\t\tswap(a[r],a[j]); break;\n\
    \t\t}\n\t\tif(!a[r][i]) continue;\n\t\trep(j,h) if(j != r && a[j][i]){\n\t\t\t\
    a[j] ^= a[r];\n\t\t}\n\t\tused_col.pb(i);\n\t\tr++;\n\t}\n\treturn used_col;\n\
    }\nvector<bool> linearEquation_mod2(vector<BS> a, int w, vector<bool> b){\n\t\
    assert(a.size() == b.size());\n\tint h = a.size();\n\trep(i,h) a[i][w] = b[i];\t\
    \t\t// \u3053\u3053\u8FBC\u3067width\u3068\u308B\u3053\u3068\n\tvector<int> idx\
    \ = sweep_mod2(a,w);\n\tfor(int i = idx.size();i<h;i++) if(a[i][w]) return {};\n\
    \tvector<bool> x(w);\n\trep(i,idx.size()) x[idx[i]] = a[i][w];\n\treturn x;\n\
    }\n\n\n/*\n\tinversion\n\t\u306A\u3051\u308C\u3070 {{}}\n*/\ntemplate<class T>\n\
    vector<vector<T>> inv(vector<vector<T>> a){\n\tassert(a.size() == a[0].size());\n\
    \tvector<vector<T>> no;\n\tint n = a.size();\n\tvector<int> ih(n,-1), jh(n,-1);\n\
    \trep(k,n){\n\t\tfor(int i=k;i<n;i++) if(ih[k] == -1){\n\t\t\tfor(int j=k;j<n;j++)\
    \ if(a[i][j]){\n\t\t\t\tih[k] = i, jh[k] = j; break;\n\t\t\t}\n\t\t}\n\t\tif(ih[k]\
    \ == -1) return no;\n\t\trep(j,n) swap(a[k][j],a[ih[k]][j]);\n\t\trep(i,n) swap(a[i][k],a[i][jh[k]]);\n\
    \t\tif(!a[k][k]) return no;\n\t\ta[k][k] = a[k][k].inv();\n\t\trep(i,n) if(i !=\
    \ k) a[k][i] *= a[k][k];\n\t\trep(i,n) if(i != k){\n\t\t\trep(j,n) if(j != k){\n\
    \t\t\t\ta[i][j] -= a[i][k]*a[k][j];\n\t\t\t}\n\t\t}\n\t\trep(i,n) if(i != k) a[i][k]\
    \ *= -a[k][k];\n\t}\n\tper(k,n){\n\t\trep(j,n) swap(a[k][j],a[jh[k]][j]);\n\t\t\
    rep(i,n) swap(a[i][k],a[i][ih[k]]);\n\t}\n\treturn a;\n}\n#line 1 \"math/mint.cpp\"\
    \n/*\n\t\u4EFB\u610Fmod \u306A\u3089 \n\ttemplate \u306A\u304F\u3057\u3066 costexpr\
    \ \u306E\u884C\u6D88\u3057\u3066 global \u306B unsigned int mod = 1;\n\t\u3067\
    \ cin>>mod \u3057\u3066\u304B\u3089\u4F7F\u3046\n*/\n\ntemplate<unsigned int mod_>\n\
    struct ModInt{\n\tusing uint = unsigned int;\n\tusing ll = long long;\n\tusing\
    \ ull = unsigned long long;\n\n\tconstexpr static uint mod = mod_;\n\n\tuint v;\n\
    \tModInt():v(0){}\n\tModInt(ll _v):v(normS(_v%mod+mod)){}\n\texplicit operator\
    \ bool() const {return v!=0;}\n\tstatic uint normS(const uint &x){return (x<mod)?x:x-mod;}\t\
    \t// [0 , 2*mod-1] -> [0 , mod-1]\n\tstatic ModInt make(const uint &x){ModInt\
    \ m; m.v=x; return m;}\n\tModInt operator+(const ModInt& b) const { return make(normS(v+b.v));}\n\
    \tModInt operator-(const ModInt& b) const { return make(normS(v+mod-b.v));}\n\t\
    ModInt operator-() const { return make(normS(mod-v)); }\n\tModInt operator*(const\
    \ ModInt& b) const { return make((ull)v*b.v%mod);}\n\tModInt operator/(const ModInt&\
    \ b) const { return *this*b.inv();}\n\tModInt& operator+=(const ModInt& b){ return\
    \ *this=*this+b;}\n\tModInt& operator-=(const ModInt& b){ return *this=*this-b;}\n\
    \tModInt& operator*=(const ModInt& b){ return *this=*this*b;}\n\tModInt& operator/=(const\
    \ ModInt& b){ return *this=*this/b;}\n\tModInt& operator++(int){ return *this=*this+1;}\n\
    \tModInt& operator--(int){ return *this=*this-1;}\n\ttemplate<class T> friend\
    \ ModInt operator+(T a, const ModInt& b){ return (ModInt(a) += b);}\n\ttemplate<class\
    \ T> friend ModInt operator-(T a, const ModInt& b){ return (ModInt(a) -= b);}\n\
    \ttemplate<class T> friend ModInt operator*(T a, const ModInt& b){ return (ModInt(a)\
    \ *= b);}\n\ttemplate<class T> friend ModInt operator/(T a, const ModInt& b){\
    \ return (ModInt(a) /= b);}\n\tModInt pow(ll p) const {\n\t\tif(p<0) return inv().pow(-p);\n\
    \t\tModInt a = 1;\n\t\tModInt x = *this;\n\t\twhile(p){\n\t\t\tif(p&1) a *= x;\n\
    \t\t\tx *= x;\n\t\t\tp >>= 1;\n\t\t}\n\t\treturn a;\n\t}\n\tModInt inv() const\
    \ {\t\t// should be prime\n\t\treturn pow(mod-2);\n\t}\n\t// ll extgcd(ll a,ll\
    \ b,ll &x,ll &y) const{\n\t// \tll p[]={a,1,0},q[]={b,0,1};\n\t// \twhile(*q){\n\
    \t// \t\tll t=*p/ *q;\n\t// \t\trep(i,3) swap(p[i]-=t*q[i],q[i]);\n\t// \t}\n\t\
    // \tif(p[0]<0) rep(i,3) p[i]=-p[i];\n\t// \tx=p[1],y=p[2];\n\t// \treturn p[0];\n\
    \t// }\n\t// ModInt inv() const {\n\t// \tll x,y;\n\t// \textgcd(v,mod,x,y);\n\
    \t// \treturn make(normS(x+mod));\n\t// }\n\n\tbool operator==(const ModInt& b)\
    \ const { return v==b.v;}\n\tbool operator!=(const ModInt& b) const { return v!=b.v;}\n\
    \tbool operator<(const ModInt& b) const { return v<b.v;}\n\tfriend istream& operator>>(istream\
    \ &o,ModInt& x){\n\t\tll tmp;\n\t\to>>tmp;\n\t\tx=ModInt(tmp);\n\t\treturn o;\n\
    \t}\n\tfriend ostream& operator<<(ostream &o,const ModInt& x){ return o<<x.v;}\n\
    };\nusing mint = ModInt<998244353>;\n//using mint = ModInt<1000000007>;\n\nV<mint>\
    \ fact,ifact,invs;\nmint Choose(int a,int b){\n\tif(b<0 || a<b) return 0;\n\t\
    return fact[a] * ifact[b] * ifact[a-b];\n}\nvoid InitFact(int N){\t//[0,N]\n\t\
    N++;\n\tfact.resize(N);\n\tifact.resize(N);\n\tinvs.resize(N);\n\tfact[0] = 1;\n\
    \trep1(i,N-1) fact[i] = fact[i-1] * i;\n\tifact[N-1] = fact[N-1].inv();\n\tfor(int\
    \ i=N-2;i>=0;i--) ifact[i] = ifact[i+1] * (i+1);\n\trep1(i,N-1) invs[i] = fact[i-1]\
    \ * ifact[i];\n}\n#line 80 \"test_oj/linearEquation.test.cpp\"\n\nint main(){\n\
    \tcin.tie(0);\n\tios::sync_with_stdio(false);\t\t//DON'T USE scanf/printf/puts\
    \ !!\n\tcout << fixed << setprecision(20);\n\t\n\tint H,W; cin >> H >> W;\n\t\
    vector<vector<mint>> a(H,vector<mint>(W));\n\trep(i,H) rep(j,W) cin >> a[i][j];\n\
    \tvector<mint> b(H); rep(i,H) cin >> b[i];\n\tauto x = linearEquation(a,W,b);\n\
    \tif(x.empty()){\n\t\tcout << -1 << endl;\n\t\treturn 0;\n\t}\n\tauto ker = kernel(a,W);\n\
    \tcout << ker.size() << endl;\n\tfor(auto c: x) cout << c << \" \";\n\tcout <<\
    \ endl;\n\tfor(auto v: ker){\n\t\tfor(auto c: v) cout << c << \" \";\n\t\tcout\
    \ << endl;\n\t}\n}\n"
  code: "#ifdef __clang__\n#define IGNORE\n#else\n#define PROBLEM \"https://judge.yosupo.jp/problem/system_of_linear_equations\"\
    \n#endif\n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\
    using uint = unsigned int;\nusing ull = unsigned long long;\n#define rep(i,n)\
    \ for(int i=0;i<int(n);i++)\n#define rep1(i,n) for(int i=1;i<=int(n);i++)\n#define\
    \ per(i,n) for(int i=int(n)-1;i>=0;i--)\n#define per1(i,n) for(int i=int(n);i>0;i--)\n\
    #define all(c) c.begin(),c.end()\n#define si(x) int(x.size())\n#define pb push_back\n\
    #define eb emplace_back\n#define fs first\n#define sc second\ntemplate<class T>\
    \ using V = vector<T>;\ntemplate<class T> using VV = vector<vector<T>>;\ntemplate<class\
    \ T,class U> bool chmax(T& x, U y){\n\tif(x<y){ x=y; return true; }\n\treturn\
    \ false;\n}\ntemplate<class T,class U> bool chmin(T& x, U y){\n\tif(y<x){ x=y;\
    \ return true; }\n\treturn false;\n}\ntemplate<class T> void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}\n\
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
    \ntemplate<class D> D divFloor(D a, D b){\n\treturn a / b - (((a ^ b) < 0 && a\
    \ % b != 0) ? 1 : 0);\n}\ntemplate<class D> D divCeil(D a, D b) {\n\treturn a\
    \ / b + (((a ^ b) > 0 && a % b != 0) ? 1 : 0);\n}\n\n\n#include \"../math/matrix/linear.cpp\"\
    \n#include \"../math/mint.cpp\"\n\nint main(){\n\tcin.tie(0);\n\tios::sync_with_stdio(false);\t\
    \t//DON'T USE scanf/printf/puts !!\n\tcout << fixed << setprecision(20);\n\t\n\
    \tint H,W; cin >> H >> W;\n\tvector<vector<mint>> a(H,vector<mint>(W));\n\trep(i,H)\
    \ rep(j,W) cin >> a[i][j];\n\tvector<mint> b(H); rep(i,H) cin >> b[i];\n\tauto\
    \ x = linearEquation(a,W,b);\n\tif(x.empty()){\n\t\tcout << -1 << endl;\n\t\t\
    return 0;\n\t}\n\tauto ker = kernel(a,W);\n\tcout << ker.size() << endl;\n\tfor(auto\
    \ c: x) cout << c << \" \";\n\tcout << endl;\n\tfor(auto v: ker){\n\t\tfor(auto\
    \ c: v) cout << c << \" \";\n\t\tcout << endl;\n\t}\n}\n"
  dependsOn:
  - math/matrix/linear.cpp
  - math/mint.cpp
  isVerificationFile: true
  path: test_oj/linearEquation.test.cpp
  requiredBy: []
  timestamp: '2022-11-15 14:34:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test_oj/linearEquation.test.cpp
layout: document
redirect_from:
- /verify/test_oj/linearEquation.test.cpp
- /verify/test_oj/linearEquation.test.cpp.html
title: test_oj/linearEquation.test.cpp
---
