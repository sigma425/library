---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/segtree/segtree_lazy.cpp
    title: ds/segtree/segtree_lazy.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE_IF_CLANG: ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test_oj/segtree/range_affine_range_sum.test.cpp\"\n/*\n\t\
    push \u3068 affine \u306E\u4E21\u65B9\u3067 op*op \u307F\u305F\u3044\u306A\u306E\
    \u3092\u66F8\u304F\u7FBD\u76EE\u306B\u306A\u3063\u3066\u3044\u308B\u304C\u3001\
    \u3053\u308C\u306F\u3057\u3087\u3046\u304C\u306A\u3044\n\t\u30AF\u30A8\u30EA\u3092\
    \u308F\u3056\u308F\u3056opr_t\u306E\u5F62\u306B\u843D\u3068\u3055\u306A\u304F\u3066\
    \u3082\u3044\u3044\u3068\u3044\u3046\u306E\u304Cbeats\u306E\u30E1\u30EA\u30C3\u30C8\
    \u3060\u304B\u3089\u3001\u9006\u306B\u305D\u306E\u307E\u307E\u307F\u305F\u3044\
    \u306A\u3068\u304D\u306F\u5197\u9577\u306B\u306A\u308B\n*/\n#ifdef __clang__\n\
    #define IGNORE\n#else\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
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
    #define show(x) true\n#endif\n\n#line 1 \"ds/segtree/segtree_lazy.cpp\"\n/*\r\n\
    \tinitialize\r\n\t\tlazyseg(vec<type>) \u306F type -> Monoid \u306E\u5909\u63DB\
    \u3055\u3048\u66F8\u3044\u3066\u3042\u308C\u3070\u597D\u304D\u306Atype\u4F7F\u3063\
    \u3066\u3044\u3044\r\n\t\t\u305D\u306E\u305F\u3081\u306B Monoid \u306E\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\u3092\u5897\u3084\u3059\u306E\u3082\u3042\u308A\
    \u3067\u3059\u306D\r\n\r\n\tS query(a,b)\r\n\t\treturn v[a] + .. v[b-1]\r\n\t\
    void apply(a,b, f)\r\n\t\tv[i] = f(v[i])\r\n\tvoid assign(i, x)\r\n\t\tv[i] =\
    \ x\r\n\tassign\u306B\u9650\u3089\u305A\u4E00\u70B9\u306B\u306A\u306B\u304B\u3059\
    \u308B\u3060\u3051\u306A\u3089\u3084\u308A\u305F\u3044\u653E\u984C(\u307E\u3042\
    query(i,i+1)\u3067\u53D6\u5F97\u3057\u3066\u5916\u3067\u8A08\u7B97\u3057\u3066\
    assign\u3059\u308C\u3070\u3044\u3044\u3068\u601D\u3046)\r\n\r\n\t\u306B\u3076\u305F\
    \u3093\u3057\u305F\u3044\u306A\u3089\u8AE6\u3081\u3066ACL!w\r\n\t\thttps://atcoder.github.io/ac-library/master/document_ja/lazysegtree.html\r\
    \n\tverify\r\n\t\ttest_oj/segtree/range_affine_range_sum.test.cpp\r\n*/\r\ntemplate<class\
    \ D>\r\nstruct lazyseg{\r\n\tusing S = typename D::Monoid;\r\n\tusing F = typename\
    \ D::Action;\r\n\tint N;\r\n\tvector<S> val;\r\n\tvector<F> act;\r\n\tlazyseg(){}\r\
    \n\tlazyseg(int n){\r\n\t\tN=1;\r\n\t\twhile(N<n) N*=2;\r\n\t\tval.assign(N*2,D::e());\r\
    \n\t\tact.assign(N*2,D::id());\r\n\t}\r\n\ttemplate<class Slike>\r\n\tlazyseg(const\
    \ vector<Slike>& val_){\r\n\t\tint n = val_.size();\r\n\t\tN=1;\r\n\t\twhile(N<n)\
    \ N*=2;\r\n\t\tval .assign(N*2,D::e());\r\n\t\trep(i,n) val[i+N] = S(val_[i]);\r\
    \n\t\tfor(int i=N-1;i>0;i--) val[i] = D::op(val[i*2],val[i*2+1]);\r\n\t\tact.assign(N*2,D::id());\r\
    \n\t}\r\n\r\n\tS query(int a,int b){\r\n\t\treturn query(a,b,0,N,1);\r\n\t}\r\n\
    \tvoid apply(int i, F f){\r\n\t\tapply(i,i+1,f);\r\n\t}\r\n\tvoid apply(int a,int\
    \ b, F f){\r\n\t\tapply(a,b,f,0,N,1);\r\n\t}\r\n\tvoid assign(int i, S x){\r\n\
    \t\tassign(i,i+1,x,0,N,1);\r\n\t}\r\n\r\n\tprivate:\r\n\tS query(int a,int b,int\
    \ l,int r,int k){\r\n\t\tif(b<=l || r<=a) return D::e();\r\n\t\tif(a<=l && r<=b)\
    \ return val[k];\r\n\t\tpropagate(l,r,k);\r\n\t\treturn D::op(query(a,b,l,(l+r)/2,k*2)\
    \ , query(a,b,(l+r)/2,r,k*2+1));\r\n\t}\r\n\tvoid apply(int a,int b,const F& f,int\
    \ l,int r,int k){\r\n\t\tif(b<=l || r<=a) return;\r\n\t\tif(a<=l && r<=b){\r\n\
    \t\t\taddlazy(k,f);\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tpropagate(l,r,k);\r\n\t\t\
    apply(a,b,f,l,(l+r)/2,k*2);\r\n\t\tapply(a,b,f,(l+r)/2,r,k*2+1);\r\n\t\tval[k]\
    \ = D::op(val[k*2] , val[k*2+1]);\r\n\t}\r\n\tvoid assign(int a,int b,const S&\
    \ x, int l,int r,int k){\r\n\t\tif(b<=l || r<=a) return;\r\n\t\tif(a<=l && r<=b){\r\
    \n\t\t\t// l = i, r = i+1\r\n\t\t\tval[k] = x;\r\n\t\t\tact[k] = D::id();\r\n\t\
    \t\treturn;\r\n\t\t}\r\n\t\tpropagate(l,r,k);\r\n\t\tassign(a,b,x,l,(l+r)/2,k*2);\r\
    \n\t\tassign(a,b,x,(l+r)/2,r,k*2+1);\r\n\t\tval[k] = D::op(val[k*2] , val[k*2+1]);\r\
    \n\t}\r\n\tvoid addlazy(int k, const F& f){\r\n\t\tact[k] = D::composite(f,act[k]);\t\
    \t// \u4E0A\u306E\u968E\u5C64\u306E lazy ( = f) \u306E\u307B\u3046\u304C\u3088\
    \u308A\u3042\u3068\r\n\t\tval[k] = D::act(f,val[k]);\t\t\t\t// val \u306F\u5E38\
    \u306B\u6B63\u3057\u304F\r\n\t}\r\n\r\n\tvoid propagate(int l,int r,int k){\r\n\
    \t\taddlazy(k*2  , act[k]);\r\n\t\taddlazy(k*2+1, act[k]);\r\n\t\tact[k] = D::id();\r\
    \n\t}\r\n};\r\n\r\n/*\r\n\t\u66F8\u304F\u3082\u306E:\r\n\t\tMonoid \u306E\u578B\
    \r\n\t\tAction \u306E\u578B\r\n\r\n\t\tMonoid \u306E\u5358\u4F4D\u5143 e()\r\n\
    \t\tMonoid op(Monoid, Monoid)\r\n\r\n\t\tAction \u306E\u5358\u4F4D\u5143 id()\r\
    \n\t\tAction composite(Action f, Action g) ( = f*g) g \u3084\u3063\u3066 f\r\n\
    \r\n\t\tMonoid act(Action, Monoid)\r\n\r\n\t\t\u30E9\u30A4\u30D6\u30E9\u30EA\u5185\
    \u3067 Monoid() \u3084 Action() \u306F\u547C\u3093\u3067\u306A\u3044(e\u3084id\u3092\
    \u547C\u3093\u3067\u3044\u308B) \u306E\u3067\u3001\u5FC5\u305A\u3057\u3082\u5B9A\
    \u7FA9\u3057\u306A\u304F\u3066\u3082\u3088\u3044\r\n*/\r\n/*\r\nstruct StarrySky{\r\
    \n\tconst ll inf = TEN(18);\r\n\tstruct Monoid{\r\n\t\tll mn;\r\n\t\tMonoid(ll\
    \ mn_):mn(mn_){}\r\n\t};\r\n\tstruct Action{\r\n\t\tll add;\r\n\t\tAction(){ *this\
    \ = id(); }\r\n\t\tAction(ll add_):add(add_){}\r\n\t};\r\n\tconst static Monoid\
    \ e(){\r\n\t\treturn Monoid(TEN(18));\r\n\t}\r\n\tconst static Monoid op(const\
    \ Monoid& x, const Monoid& y){\r\n\t\treturn Monoid(min(x.mn,y.mn));\r\n\t}\r\n\
    \r\n\tconst static Action id(){\r\n\t\treturn Action(0);\r\n\t}\r\n\tconst static\
    \ Action composite(const Action& f, const Action& g){\r\n\t\t// f \\times g\r\n\
    \t\treturn Action(f.add + g.add);\r\n\t}\r\n\r\n\tconst static Monoid act(const\
    \ Action& f, const Monoid& x){\r\n\t\tif(x.mn == inf) return x;\r\n\t\treturn\
    \ Monoid(x.mn + f.add);\r\n\t}\r\n};\r\n\r\n\r\nstruct D{\r\n\tstruct Monoid{\r\
    \n\t\tmint sm;\r\n\t\tint sz;\r\n\t\tMonoid(mint v):sm(v),sz(1){}\r\n\t\tMonoid(mint\
    \ sm_, int sz_):sm(sm_),sz(sz_){}\r\n\t};\r\n\tstruct Action{\r\n\t\tmint a,b;\t\
    // x -> ax+b\r\n\t\tAction(){ *this = id(); }\r\n\t\tAction(mint a_, mint b_):a(a_),b(b_){}\r\
    \n\t};\r\n\tconst static Monoid e(){\r\n\t\treturn Monoid(0,0);\r\n\t}\r\n\tconst\
    \ static Monoid op(const Monoid& x, const Monoid& y){\r\n\t\tMonoid z;\r\n\t\t\
    z.sm = x.sm + y.sm;\r\n\t\tz.sz = x.sz + y.sz;\r\n\t\treturn z;\r\n\t}\r\n\r\n\
    \tconst static Action id(){\r\n\t\treturn Action(1,0);\r\n\t}\r\n\tconst static\
    \ Action composite(const Action& f, const Action& g){\r\n\t\t// f \\times g\r\n\
    \t\tAction h;\r\n\t\th.a = f.a * g.a;\r\n\t\th.b = f.a * g.b + f.b;\r\n\t\treturn\
    \ h;\r\n\t}\r\n\r\n\tconst static Monoid act(const Action& f, const Monoid& x){\r\
    \n\t\tMonoid z;\r\n\t\tz.sz = x.sz;\r\n\t\tz.sm = x.sm * f.a + f.b * x.sz;\r\n\
    \t\treturn z;\r\n\t}\r\n};\r\n*/\n#line 42 \"test_oj/segtree/range_affine_range_sum.test.cpp\"\
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
    struct D{\n\tstruct Monoid{\n\t\tmint sm;\n\t\tint sz;\n\t\tMonoid(){ *this =\
    \ e(); }\n\t\tMonoid(mint v):sm(v),sz(1){}\n\t\tMonoid(mint sm_, int sz_):sm(sm_),sz(sz_){}\n\
    \t};\n\tstruct Action{\n\t\tmint a,b;\t// x -> ax+b\n\t\tAction(){ *this = id();\
    \ }\n\t\tAction(mint a_, mint b_):a(a_),b(b_){}\n\t};\n\tconst static Monoid e(){\n\
    \t\treturn Monoid(0,0);\n\t}\n\tconst static Monoid op(const Monoid& x, const\
    \ Monoid& y){\n\t\tMonoid z;\n\t\tz.sm = x.sm + y.sm;\n\t\tz.sz = x.sz + y.sz;\n\
    \t\treturn z;\n\t}\n\n\tconst static Action id(){\n\t\treturn Action(1,0);\n\t\
    }\n\tconst static Action composite(const Action& f, const Action& g){\n\t\t//\
    \ f \\times g\n\t\tAction h;\n\t\th.a = f.a * g.a;\n\t\th.b = f.a * g.b + f.b;\n\
    \t\treturn h;\n\t}\n\n\tconst static Monoid act(const Action& f, const Monoid&\
    \ x){\n\t\tMonoid z;\n\t\tz.sz = x.sz;\n\t\tz.sm = x.sm * f.a + f.b * x.sz;\n\t\
    \treturn z;\n\t}\n};\nint main(){\n\tcin.tie(0);\n\tios::sync_with_stdio(false);\t\
    \t//DON'T USE scanf/printf/puts !!\n\tcout << fixed << setprecision(20);\n\n\t\
    int N,Q; cin >> N >> Q;\n\tV<mint> A(N); rep(i,N) cin >> A[i];\n\tlazyseg<D> seg(A);\n\
    \tusing F = D::Action;\n\twhile(Q--){\n\t\tint t; cin >> t;\n\t\tif(t == 0){\n\
    \t\t\tint l,r,a,b; cin >> l >> r >> a >> b;\n\t\t\tseg.apply(l,r,F(a,b));\n\t\t\
    }else{\n\t\t\tint l,r; cin >> l >> r;\n\t\t\tcout << seg.query(l,r).sm << endl;\n\
    \t\t}\n\t}\n}\n"
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
    #define show(x) true\n#endif\n\n#include \"../../ds/segtree/segtree_lazy.cpp\"\
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
    struct D{\n\tstruct Monoid{\n\t\tmint sm;\n\t\tint sz;\n\t\tMonoid(){ *this =\
    \ e(); }\n\t\tMonoid(mint v):sm(v),sz(1){}\n\t\tMonoid(mint sm_, int sz_):sm(sm_),sz(sz_){}\n\
    \t};\n\tstruct Action{\n\t\tmint a,b;\t// x -> ax+b\n\t\tAction(){ *this = id();\
    \ }\n\t\tAction(mint a_, mint b_):a(a_),b(b_){}\n\t};\n\tconst static Monoid e(){\n\
    \t\treturn Monoid(0,0);\n\t}\n\tconst static Monoid op(const Monoid& x, const\
    \ Monoid& y){\n\t\tMonoid z;\n\t\tz.sm = x.sm + y.sm;\n\t\tz.sz = x.sz + y.sz;\n\
    \t\treturn z;\n\t}\n\n\tconst static Action id(){\n\t\treturn Action(1,0);\n\t\
    }\n\tconst static Action composite(const Action& f, const Action& g){\n\t\t//\
    \ f \\times g\n\t\tAction h;\n\t\th.a = f.a * g.a;\n\t\th.b = f.a * g.b + f.b;\n\
    \t\treturn h;\n\t}\n\n\tconst static Monoid act(const Action& f, const Monoid&\
    \ x){\n\t\tMonoid z;\n\t\tz.sz = x.sz;\n\t\tz.sm = x.sm * f.a + f.b * x.sz;\n\t\
    \treturn z;\n\t}\n};\nint main(){\n\tcin.tie(0);\n\tios::sync_with_stdio(false);\t\
    \t//DON'T USE scanf/printf/puts !!\n\tcout << fixed << setprecision(20);\n\n\t\
    int N,Q; cin >> N >> Q;\n\tV<mint> A(N); rep(i,N) cin >> A[i];\n\tlazyseg<D> seg(A);\n\
    \tusing F = D::Action;\n\twhile(Q--){\n\t\tint t; cin >> t;\n\t\tif(t == 0){\n\
    \t\t\tint l,r,a,b; cin >> l >> r >> a >> b;\n\t\t\tseg.apply(l,r,F(a,b));\n\t\t\
    }else{\n\t\t\tint l,r; cin >> l >> r;\n\t\t\tcout << seg.query(l,r).sm << endl;\n\
    \t\t}\n\t}\n}\n"
  dependsOn:
  - ds/segtree/segtree_lazy.cpp
  isVerificationFile: true
  path: test_oj/segtree/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-05 03:20:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test_oj/segtree/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test_oj/segtree/range_affine_range_sum.test.cpp
- /verify/test_oj/segtree/range_affine_range_sum.test.cpp.html
title: test_oj/segtree/range_affine_range_sum.test.cpp
---
