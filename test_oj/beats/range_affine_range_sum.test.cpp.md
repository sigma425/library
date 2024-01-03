---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../data structure/segtree/segbeats.cpp:\
    \ line -1: no such header\n"
  code: "/*\n\tpush \u3068 affine \u306E\u4E21\u65B9\u3067 op*op \u307F\u305F\u3044\
    \u306A\u306E\u3092\u66F8\u304F\u7FBD\u76EE\u306B\u306A\u3063\u3066\u3044\u308B\
    \u304C\u3001\u3053\u308C\u306F\u3057\u3087\u3046\u304C\u306A\u3044\n\t\u30AF\u30A8\
    \u30EA\u3092\u308F\u3056\u308F\u3056opr_t\u306E\u5F62\u306B\u843D\u3068\u3055\u306A\
    \u304F\u3066\u3082\u3044\u3044\u3068\u3044\u3046\u306E\u304Cbeats\u306E\u30E1\u30EA\
    \u30C3\u30C8\u3060\u304B\u3089\u3001\u9006\u306B\u305D\u306E\u307E\u307E\u307F\
    \u305F\u3044\u306A\u3068\u304D\u306F\u5197\u9577\u306B\u306A\u308B\n*/\n#ifdef\
    \ __clang__\n#define IGNORE\n#else\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
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
    #define show(x) true\n#endif\n\n#include \"../../data structure/segtree/segbeats.cpp\"\
    \n\ntemplate<unsigned int mod_>\nstruct ModInt{\n\tusing uint = unsigned int;\n\
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
    \ &o,const ModInt& x){ return o<<x.v;}\n};\nusing mint = ModInt<998244353>;\n\n\
    struct D{\n\tint sz=1;\n\tmint a=1,b=0;\n\tmint sm=0;\n\tD(mint v=0){sm=v;}\n\t\
    static D merge(D l,D r){\n\t\tD z;\n\t\tz.sz = l.sz+r.sz;\n\t\tz.sm = l.sm+r.sm;\n\
    \t\treturn z;\n\t}\n\tvoid push(D& x,D& y){\n\t\t{\n\t\t\tmint c=x.a,d=x.b;\n\t\
    \t\tx.a = a*c;\n\t\t\tx.b = d*a+b;\n\t\t\tx.sm = x.sm*a+b*x.sz;\n\t\t}\n\t\t{\n\
    \t\t\tmint c=y.a,d=y.b;\n\t\t\ty.a = a*c;\n\t\t\ty.b = d*a+b;\n\t\t\ty.sm = y.sm*a+b*y.sz;\n\
    \t\t}\n\t\ta=1,b=0;\n\t}\n\tbool affine(mint c,mint d){\n\t\ta = a*c;\n\t\tb =\
    \ b*c+d;\n\t\tsm = sm*c+d*sz;\n\t\treturn true;\n\t}\n\tmint getsum(){\n\t\treturn\
    \ sm;\n\t}\n};\n\n\nint main(){\n\tcin.tie(0);\n\tios::sync_with_stdio(false);\t\
    \t//DON'T USE scanf/printf/puts !!\n\tcout << fixed << setprecision(20);\n\n\t\
    int N,Q; cin >> N >> Q;\n\tV<int> a(N); rep(i,N) cin >> a[i];\n\tsegbeats<D> seg(a);\n\
    \twhile(Q--){\n\t\tint t; cin >> t;\n\t\tif(t == 0){\n\t\t\tint l,r,a,b; cin >>\
    \ l >> r >> a >> b;\n\t\t\tseg.ch(l,r,&D::affine,a,b);\n\t\t}else{\n\t\t\tint\
    \ l,r; cin >> l >> r;\n\t\t\tcout << seg.get(l,r,&D::getsum,[&](mint x,mint y){return\
    \ x+y;},mint(0)) << endl;\n\t\t}\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test_oj/beats/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_oj/beats/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test_oj/beats/range_affine_range_sum.test.cpp
- /verify/test_oj/beats/range_affine_range_sum.test.cpp.html
title: test_oj/beats/range_affine_range_sum.test.cpp
---
