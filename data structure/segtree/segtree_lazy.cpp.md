---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_oj/segtree/range_affine_range_sum.test.cpp
    title: test_oj/segtree/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.github.io/ac-library/master/document_ja/lazysegtree.html
  bundledCode: "#line 1 \"data structure/segtree/segtree_lazy.cpp\"\n/*\r\n\tinitialize\r\
    \n\t\tlazyseg(vec<type>) \u306F type -> Monoid \u306E\u5909\u63DB\u3055\u3048\u66F8\
    \u3044\u3066\u3042\u308C\u3070\u597D\u304D\u306Atype\u4F7F\u3063\u3066\u3044\u3044\
    \r\n\t\t\u305D\u306E\u305F\u3081\u306B Monoid \u306E\u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\u3092\u5897\u3084\u3059\u306E\u3082\u3042\u308A\u3067\u3059\u306D\
    \r\n\r\n\tS query(a,b)\r\n\t\treturn v[a] + .. v[b-1]\r\n\tvoid apply(a,b, f)\r\
    \n\t\tv[i] = f(v[i])\r\n\tvoid assign(i, x)\r\n\t\tv[i] = x\r\n\tassign\u306B\u9650\
    \u3089\u305A\u4E00\u70B9\u306B\u306A\u306B\u304B\u3059\u308B\u3060\u3051\u306A\
    \u3089\u3084\u308A\u305F\u3044\u653E\u984C(\u307E\u3042query(i,i+1)\u3067\u53D6\
    \u5F97\u3057\u3066\u5916\u3067\u8A08\u7B97\u3057\u3066assign\u3059\u308C\u3070\
    \u3044\u3044\u3068\u601D\u3046)\r\n\r\n\t\u306B\u3076\u305F\u3093\u3057\u305F\u3044\
    \u306A\u3089\u8AE6\u3081\u3066ACL!w\r\n\t\thttps://atcoder.github.io/ac-library/master/document_ja/lazysegtree.html\r\
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
    \t\treturn z;\r\n\t}\r\n};\r\n*/\n"
  code: "/*\r\n\tinitialize\r\n\t\tlazyseg(vec<type>) \u306F type -> Monoid \u306E\
    \u5909\u63DB\u3055\u3048\u66F8\u3044\u3066\u3042\u308C\u3070\u597D\u304D\u306A\
    type\u4F7F\u3063\u3066\u3044\u3044\r\n\t\t\u305D\u306E\u305F\u3081\u306B Monoid\
    \ \u306E\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3092\u5897\u3084\u3059\u306E\
    \u3082\u3042\u308A\u3067\u3059\u306D\r\n\r\n\tS query(a,b)\r\n\t\treturn v[a]\
    \ + .. v[b-1]\r\n\tvoid apply(a,b, f)\r\n\t\tv[i] = f(v[i])\r\n\tvoid assign(i,\
    \ x)\r\n\t\tv[i] = x\r\n\tassign\u306B\u9650\u3089\u305A\u4E00\u70B9\u306B\u306A\
    \u306B\u304B\u3059\u308B\u3060\u3051\u306A\u3089\u3084\u308A\u305F\u3044\u653E\
    \u984C(\u307E\u3042query(i,i+1)\u3067\u53D6\u5F97\u3057\u3066\u5916\u3067\u8A08\
    \u7B97\u3057\u3066assign\u3059\u308C\u3070\u3044\u3044\u3068\u601D\u3046)\r\n\r\
    \n\t\u306B\u3076\u305F\u3093\u3057\u305F\u3044\u306A\u3089\u8AE6\u3081\u3066ACL!w\r\
    \n\t\thttps://atcoder.github.io/ac-library/master/document_ja/lazysegtree.html\r\
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
    \t\treturn z;\r\n\t}\r\n};\r\n*/"
  dependsOn: []
  isVerificationFile: false
  path: data structure/segtree/segtree_lazy.cpp
  requiredBy: []
  timestamp: '2021-10-11 06:59:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_oj/segtree/range_affine_range_sum.test.cpp
documentation_of: data structure/segtree/segtree_lazy.cpp
layout: document
redirect_from:
- /library/data structure/segtree/segtree_lazy.cpp
- /library/data structure/segtree/segtree_lazy.cpp.html
title: data structure/segtree/segtree_lazy.cpp
---
