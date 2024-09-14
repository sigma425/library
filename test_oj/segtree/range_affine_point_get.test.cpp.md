---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/segtree/segtree_dual.hpp
    title: ds/segtree/segtree_dual.hpp
  - icon: ':heavy_check_mark:'
    path: math/mint.cpp
    title: math/mint.cpp
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_point_get
    links:
    - https://judge.yosupo.jp/problem/range_affine_point_get
  bundledCode: "#line 1 \"test_oj/segtree/range_affine_point_get.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\n\n#line\
    \ 2 \"template.hpp\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\
    using ll = long long;\r\nusing uint = unsigned int;\r\nusing ull = unsigned long\
    \ long;\r\n#define rep(i,n) for(int i=0;i<int(n);i++)\r\n#define rep1(i,n) for(int\
    \ i=1;i<=int(n);i++)\r\n#define per(i,n) for(int i=int(n)-1;i>=0;i--)\r\n#define\
    \ per1(i,n) for(int i=int(n);i>0;i--)\r\n#define all(c) c.begin(),c.end()\r\n\
    #define si(x) int(x.size())\r\n#define pb push_back\r\n#define eb emplace_back\r\
    \n#define fs first\r\n#define sc second\r\ntemplate<class T> using V = vector<T>;\r\
    \ntemplate<class T> using VV = vector<vector<T>>;\r\ntemplate<class T,class U>\
    \ bool chmax(T& x, U y){\r\n\tif(x<y){ x=y; return true; }\r\n\treturn false;\r\
    \n}\r\ntemplate<class T,class U> bool chmin(T& x, U y){\r\n\tif(y<x){ x=y; return\
    \ true; }\r\n\treturn false;\r\n}\r\ntemplate<class T> void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}\r\
    \ntemplate<class T> int lwb(const V<T>& v, const T& a){return lower_bound(all(v),a)\
    \ - v.begin();}\r\ntemplate<class T>\r\nV<T> Vec(size_t a) {\r\n    return V<T>(a);\r\
    \n}\r\ntemplate<class T, class... Ts>\r\nauto Vec(size_t a, Ts... ts) {\r\n  return\
    \ V<decltype(Vec<T>(ts...))>(a, Vec<T>(ts...));\r\n}\r\ntemplate<class S,class\
    \ T> ostream& operator<<(ostream& o,const pair<S,T> &p){\r\n\treturn o<<\"(\"\
    <<p.fs<<\",\"<<p.sc<<\")\";\r\n}\r\ntemplate<class T> ostream& operator<<(ostream&\
    \ o,const vector<T> &vc){\r\n\to<<\"{\";\r\n\tfor(const T& v:vc) o<<v<<\",\";\r\
    \n\to<<\"}\";\r\n\treturn o;\r\n}\r\nconstexpr ll TEN(int n) { return (n == 0)\
    \ ? 1 : 10 * TEN(n-1); }\r\n\r\n#ifdef LOCAL\r\n#define show(x) cerr << \"LINE\"\
    \ << __LINE__ << \" : \" << #x << \" = \" << (x) << endl\r\nvoid dmpr(ostream&\
    \ os){os<<endl;}\r\ntemplate<class T,class... Args>\r\nvoid dmpr(ostream&os,const\
    \ T&t,const Args&... args){\r\n\tos<<t<<\" ~ \";\r\n\tdmpr(os,args...);\r\n}\r\
    \n#define shows(...) cerr << \"LINE\" << __LINE__ << \" : \";dmpr(cerr,##__VA_ARGS__)\r\
    \n#define dump(x) cerr << \"LINE\" << __LINE__ << \" : \" << #x << \" = {\"; \
    \ \\\r\n\tfor(auto v: x) cerr << v << \",\"; cerr << \"}\" << endl;\r\n#else\r\
    \n#define show(x) void(0)\r\n#define dump(x) void(0)\r\n#define shows(...) void(0)\r\
    \n#endif\r\n\r\ntemplate<class D> D divFloor(D a, D b){\r\n\treturn a / b - (((a\
    \ ^ b) < 0 && a % b != 0) ? 1 : 0);\r\n}\r\ntemplate<class D> D divCeil(D a, D\
    \ b) {\r\n\treturn a / b + (((a ^ b) > 0 && a % b != 0) ? 1 : 0);\r\n}\r\n#line\
    \ 1 \"ds/segtree/segtree_dual.hpp\"\n/*\r\n\trange apply + point get segtree\r\
    \n\r\n\tlazy segtree \u306E\u4F5C\u7528\u3060\u3051\u3092\u6301\u3063\u3066\u308B\
    \u3084\u3064\u3000\u305F\u3060\u3001\u5358\u306B \u533A\u9593add + \u70B9\u53D6\
    \u5F97 \u307F\u305F\u3044\u306A\u306E\u306B\u3082\u4F7F\u3048\u308B\r\n\t- \u4F5C\
    \u7528\u3060\u3051\u3092\u3082\u3063\u3066\u308B lazy segtree \u3068\u307F\u306A\
    \u3059\r\n\t\tas[k] + q1 + q3 + q4 \u307F\u305F\u3044\u306B\u6765\u305F\u30AF\u30A8\
    \u30EA\u9806\u306B\u8DB3\u3057\u3066\u3044\u3063\u305F\u3082\u306E\u3092\u3061\
    \u3083\u3093\u3068\u53D6\u5F97\u3067\u304D\u308B\u5FC5\u8981\u304C\u3042\u308A\
    \u3001\u305D\u3046\u306A\u3063\u3066\u3044\u308B\r\n\t\t\u9593\u9055\u3048\u3066\
    \u521D\u671F\u5316\u3067 lazy segtree \u3067\u3044\u3046 D \u306E\u65B9\u3092\u4E0E\
    \u3048\u306A\u3044\u3053\u3068\r\n\t\t(\u4F8B: x -> ax + b \u304C range query\
    \ \u3067\u6765\u308B\u3068\u3057\u3066\u3001\u521D\u671F\u5024\u306B x_i \u3092\
    \u4E0E\u3048\u308B\u306E\u306F\u304A\u304B\u3057\u3044, \u5358\u306B\u4F5C\u7528\
    \u306E\u5358\u4F4D\u5143(1,0)\u304C\u521D\u671F\u5024)\r\n\t- \u533A\u9593add\
    \ + \u70B9\u53D6\u5F97\r\n\t\t\u4F8B\u3048\u3070\u5358\u306B\u533A\u9593\u306B\
    \ +=v, \u70B9\u53D6\u5F97 \u3060\u3068\u4F5C\u7528\u3068\u3044\u3046\u611F\u3058\
    \u306F\u5168\u304F\u3057\u306A\u3044\u304C\u3001\u3053\u308C\u3092\u4F7F\u3063\
    \u3066\u304F\u3060\u3055\u3044\r\n\t\r\n\t- A get(int k)\r\n\t- void apply(int\
    \ a, int b, A a)\r\n*/\r\ntemplate<class A>\r\nstruct SegtreeDual{\r\n\tint N,lg;\r\
    \n\tvector<A> lazy;\r\n\r\n\tSegtreeDual(){}\r\n\tSegtreeDual(int n){\r\n\t\t\
    N = 1; while(N < n){N *= 2, lg++;}\r\n\t\tlazy.assign(N*2, A());\r\n\t}\r\n\t\
    template<class Alike>\r\n\tSegtreeDual(const vector<Alike>& as){\r\n\t\tint n\
    \ = as.size();\r\n\t\tN = 1; while(N < n){N *= 2, lg++;}\r\n\t\tlazy.assign(N*2,\
    \ A());\r\n\t\trep(i,n) lazy[i+N] = as[i];\r\n\t}\r\n\tA get(int i){\r\n\t\ti\
    \ += N;\r\n\t\tfor(int h=lg;h>=1;h--) push(i >> h);\r\n\t\treturn lazy[i];\r\n\
    \t}\r\n\tvoid apply(int l, int r, A a){\r\n\t\tl += N, r += N;\r\n\t\tfor(int\
    \ h = lg; h >= 1; h--){\r\n\t\t\tif(((l>>h)<<h) != l) push(l >> h);\r\n\t\t\t\
    if(((r>>h)<<h) != r) push((r-1) >> h);\r\n\t\t}\r\n\t\twhile(l < r){\r\n\t\t\t\
    if(l&1) all_apply(l++, a);\r\n\t\t\tif(r&1) all_apply(--r, a);\r\n\t\t\tl >>=\
    \ 1, r >>= 1;\r\n\t\t}\r\n\t}\r\n\tprivate:\r\n\tvoid push(int k){\r\n\t\tall_apply(k*2,\
    \ lazy[k]); all_apply(k*2+1, lazy[k]);\r\n\t\tlazy[k] = A();\r\n\t}\r\n\tvoid\
    \ all_apply(int k, A a){\r\n\t\tlazy[k] = A::op(a,lazy[k]);\t// \u4E0A\u306E\u968E\
    \u5C64\u306E lazy (a) \u306E\u307B\u3046\u304C\u3088\u308A\u5F8C\r\n\t}\r\n};\r\
    \n\r\n// struct D{\r\n// \tint v;\r\n// \tD(){ *this = e(); }\r\n// \tD(int v_):v(v_){}\r\
    \n// \tstatic D op(const D& x,const D& y){\r\n// \t\treturn D(x.v+y.v);\r\n//\
    \ \t}\r\n// \tconst static D e(){\r\n// \t\treturn D(0);\r\n// \t}\r\n// //\t\
    friend ostream& operator<<(ostream& o,const D& d){return o<<d.v;}\r\n// };\r\n\
    #line 1 \"math/mint.cpp\"\n/*\n\t\u4EFB\u610Fmod \u306A\u3089 \n\ttemplate \u306A\
    \u304F\u3057\u3066 costexpr \u306E\u884C\u6D88\u3057\u3066 global \u306B unsigned\
    \ int mod = 1;\n\t\u3067 cin>>mod \u3057\u3066\u304B\u3089\u4F7F\u3046\n\t\u4EFB\
    \u610F mod \u306F\u304B\u306A\u308A\u9045\u3044\u306E\u3067\u3001\u3067\u304D\u308C\
    \u3070 \"atcoder/modint\" \u3092\u4F7F\u3046\n*/\n\ntemplate<unsigned int mod_>\n\
    struct ModInt{\t\n\tusing uint = unsigned int;\n\tusing ll = long long;\n\tusing\
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
    \t// friend ostream& operator<<(ostream &o,const ModInt& x){\n\t// \tfor(int b=1;b<=1000;b++){\n\
    \t// \t\tModInt ib = ModInt(b).inv();\n\t// \t\tfor(int a=-1000;a<=1000;a++){\n\
    \t// \t\t\tif(ModInt(a) * ib == x){\n\t// \t\t\t\treturn o << a << \"/\" << b;\n\
    \t// \t\t\t}\n\t// \t\t}\n\t// \t}\n\t// \treturn o<<x.v;\n\t// }\n};\nusing mint\
    \ = ModInt<998244353>;\n//using mint = ModInt<1000000007>;\n\nV<mint> fact,ifact,invs;\n\
    // a,b >= 0 \u306E\u307F\nmint Choose(int a,int b){\n\tif(b<0 || a<b) return 0;\n\
    \treturn fact[a] * ifact[b] * ifact[a-b];\n}\n\n/*\n// b >= 0 \u306E\u7BC4\u56F2\
    \u3067\u3001 Choose(a,b) = a(a-1)..(a-b+1) / b!\nmint Choose(int a,int b){\n\t\
    if(b<0 || a<b) return 0;\n\treturn fact[a] * ifact[b] * ifact[a-b];\n}\n*/\n\n\
    void InitFact(int N){\t//[0,N]\n\tN++;\n\tfact.resize(N);\n\tifact.resize(N);\n\
    \tinvs.resize(N);\n\tfact[0] = 1;\n\trep1(i,N-1) fact[i] = fact[i-1] * i;\n\t\
    ifact[N-1] = fact[N-1].inv();\n\tfor(int i=N-2;i>=0;i--) ifact[i] = ifact[i+1]\
    \ * (i+1);\n\trep1(i,N-1) invs[i] = fact[i-1] * ifact[i];\n}\n#line 6 \"test_oj/segtree/range_affine_point_get.test.cpp\"\
    \n\nstruct A{\n\t// x -> ax + b\n\tmint a,b;\n\tA(){ *this = e(); }\n\tA(mint\
    \ a_, mint b_):a(a_),b(b_){}\n\t// f*g: g\u3084\u3063\u3066f\n\tstatic A op(const\
    \ A& f,const A& g){\n\t\treturn A(f.a*g.a, f.b+f.a*g.b);\n\t}\n\tconst static\
    \ A e(){\n\t\treturn A(1,0);\n\t}\n\tfriend ostream& operator<<(ostream& o,const\
    \ A& v){return o<<v.a<<\"x+\"<<v.b;}\n};\n\nint main(){\n\tint N,Q; cin >> N >>\
    \ Q;\n\tV<mint> xs(N); rep(i,N) cin >> xs[i];\n\tSegtreeDual<A> seg(N);\n\twhile(Q--){\n\
    \t\tint t; cin >> t;\n\t\tif(t == 0){\n\t\t\tint l,r; mint a,b; cin >> l >> r\
    \ >> a >> b;\n\t\t\tseg.apply(l,r,A(a,b));\n\t\t}else{\n\t\t\tint i; cin >> i;\n\
    \t\t\tauto f = seg.get(i);\n\t\t\tcout << f.a * xs[i] + f.b << endl;\n\t\t}\n\t\
    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n\n#include \"template.hpp\"\n#include \"ds/segtree/segtree_dual.hpp\"\n#include\
    \ \"math/mint.cpp\"\n\nstruct A{\n\t// x -> ax + b\n\tmint a,b;\n\tA(){ *this\
    \ = e(); }\n\tA(mint a_, mint b_):a(a_),b(b_){}\n\t// f*g: g\u3084\u3063\u3066\
    f\n\tstatic A op(const A& f,const A& g){\n\t\treturn A(f.a*g.a, f.b+f.a*g.b);\n\
    \t}\n\tconst static A e(){\n\t\treturn A(1,0);\n\t}\n\tfriend ostream& operator<<(ostream&\
    \ o,const A& v){return o<<v.a<<\"x+\"<<v.b;}\n};\n\nint main(){\n\tint N,Q; cin\
    \ >> N >> Q;\n\tV<mint> xs(N); rep(i,N) cin >> xs[i];\n\tSegtreeDual<A> seg(N);\n\
    \twhile(Q--){\n\t\tint t; cin >> t;\n\t\tif(t == 0){\n\t\t\tint l,r; mint a,b;\
    \ cin >> l >> r >> a >> b;\n\t\t\tseg.apply(l,r,A(a,b));\n\t\t}else{\n\t\t\tint\
    \ i; cin >> i;\n\t\t\tauto f = seg.get(i);\n\t\t\tcout << f.a * xs[i] + f.b <<\
    \ endl;\n\t\t}\n\t}\n}"
  dependsOn:
  - template.hpp
  - ds/segtree/segtree_dual.hpp
  - math/mint.cpp
  isVerificationFile: true
  path: test_oj/segtree/range_affine_point_get.test.cpp
  requiredBy: []
  timestamp: '2024-09-05 20:51:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test_oj/segtree/range_affine_point_get.test.cpp
layout: document
redirect_from:
- /verify/test_oj/segtree/range_affine_point_get.test.cpp
- /verify/test_oj/segtree/range_affine_point_get.test.cpp.html
title: test_oj/segtree/range_affine_point_get.test.cpp
---
