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
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2377
  bundledCode: "#line 1 \"ds/segtree/lazyseg_dynamic.cpp\"\n/*\n\tlazyseg \u3068\u307B\
    \u307C\u540C\u3058API\u306B\u306A\u3063\u3066\u3044\u308B\n\t\u4E00\u3064\u9055\
    \u3046\u306E\u306F\u3001 Node(l,r) \u3092\u547C\u3093\u3060\u3068\u304D D::e()\
    \ \u3092\u8FD4\u3057\u3066\u306F\u3044\u3051\u306A\u3044(\u305D\u308C\u306F\u305D\
    \u3046\u3001\u4F8B\u3048\u3070\u30B5\u30A4\u30BA\u306F r-l) \u305F\u3081\u3001\
    \n\tD \u306E\u4E2D\u306B initialize(l,r) \u3068\u3044\u3046\u95A2\u6570\u3092\u4F5C\
    \u308B\u5FC5\u8981\u304C\u3042\u308B\n\t\u521D\u671F\u72B6\u614B\u3067\u306E a[l]\
    \ + .. + a[r-1] \u3092\u8FD4\u305B\u3070\u3044\u3044\n\n\t\u30E1\u30E2\u30EA\u304C\
    \u3084\u3070\u3044\u53EF\u80FD\u6027\u304C\u9AD8\u3044\u3002\u305D\u306E\u5834\
    \u5408:\n\t\t- Node \u306E l,r \u3092\u53EF\u80FD\u306A\u3089 int \u306B\n\t\t\
    - \u3061\u3083\u3093\u3068 delete \u3092\u3059\u308B (\u3057\u306A\u3044\u307B\
    \u3046\u304C\u5B9F\u884C\u6642\u9593\u306F\u901F\u305D\u3046) \u6A19\u6E96\u3067\
    \u306F\u3057\u3066\u3044\u308B\n\t\t- \u3046\u3057\u308D\u306B\u8CBC\u3063\u3066\
    \u3042\u308B lazyseg_dynamic_pool \u3092\u4F7F\u3046\n\tpool, \u305D\u3093\u306A\
    \u306B\u4F7F\u3044\u3065\u3089\u304F\u306A\u3044\u3051\u3069\u914D\u5217\u306E\
    \u9577\u3055\u3092\u6307\u5B9A\u3057\u305F\u308A\u3059\u308B\u5FC5\u8981\u304C\
    \u3042\u3063\u3066\u307B\u3093\u306E\u5C11\u3057\u9762\u5012\n\n\tverify\n\t\t\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2377 ThreeRooks\n*/\n\
    template<class D>\nstruct lazyseg_dynamic{\n\tusing S = typename D::Monoid;\n\t\
    using F = typename D::Action;\n\n\tstruct Node;\n\tusing NP = Node*;\n\tstruct\
    \ Node{\n\t\tS val;\n\t\tF act;\n\t\tll l,r;\t\t\t\t// 10^9 \u3067\u30E1\u30E2\
    \u30EA\u6E1B\u3089\u3057\u305F\u3044\u306A\u3089int\u306B\u5909\u3048\u308B\n\t\
    \tNP lch,rch;\n\t\tNode(ll l_,ll r_):act(D::id()),l(l_),r(r_),lch(nullptr),rch(nullptr){\n\
    \t\t\t// should initialize val for [l,r)\n\t\t\t// ex. val = l + .. + r-1\n\t\t\
    \t// ex. val.sz = r-l\n\t\t\tval = D::initialize(l,r);\n\t\t}\n\t\tNode(ll l_,ll\
    \ r_,S val_):val(val_),act(D::id()),l(l_),r(r_),lch(nullptr),rch(nullptr){\n\t\
    \t\t// OK. initlized with val (act = D::id())\n\t\t}\n\t\t~Node(){\n\t\t\tdelete\
    \ lch;\n\t\t\tdelete rch;\n\t\t}\n\t};\n\n\tNP root;\n\tlazyseg_dynamic(){}\n\t\
    lazyseg_dynamic(ll N){\n\t\tll n2 = 1;\n\t\twhile(n2 < N) n2 *= 2;\n\t\troot =\
    \ new Node(0,n2);\n\t}\n\t~lazyseg_dynamic(){\n\t\tdelete root;\n\t}\n\n\tS query(ll\
    \ a, ll b){\n\t\treturn query(a,b,root);\n\t}\n\tvoid apply(ll i, F f){\n\t\t\
    apply(i,i+1,f);\n\t}\n\tvoid apply(ll a, ll b, F f){\n\t\tapply(a,b,f,root);\n\
    \t}\n\tvoid assign(ll i, S x){\n\t\tassign(i,i+1,x,root);\n\t}\n\tprivate:\n\t\
    S query(ll a, ll b, NP n){\n\t\tll l = n->l, r = n->r;\n\t\tif(b<=l || r<=a) return\
    \ D::e();\n\t\tif(a<=l && r<=b) return n->val;\n\t\tif(!n->lch) n->lch = new Node(l,(l+r)/2);\n\
    \t\tif(!n->rch) n->rch = new Node((l+r)/2,r);\n\t\tpropagate(l,r,n);\n\t\treturn\
    \ D::op(query(a,b,n->lch) , query(a,b,n->rch));\n\t}\n\tvoid apply(ll a, ll b,\
    \ const F& f, NP n){\n\t\tll l = n->l, r = n->r;\n\t\tif(b<=l || r<=a) return;\n\
    \t\tif(a<=l && r<=b){\n\t\t\taddlazy(n,f);\n\t\t\treturn;\n\t\t}\n\t\tif(!n->lch)\
    \ n->lch = new Node(l,(l+r)/2);\n\t\tif(!n->rch) n->rch = new Node((l+r)/2,r);\n\
    \t\tpropagate(l,r,n);\n\t\tapply(a,b,f,n->lch);\n\t\tapply(a,b,f,n->rch);\n\t\t\
    n->val = D::op(n->lch->val , n->rch->val);\n\t}\n\tvoid assign(ll a, ll b, const\
    \ S& x, NP n){\n\t\tll l = n->l, r = n->r;\n\t\tif(b<=l || r<=a) return;\n\t\t\
    if(a<=l && r<=b){\n\t\t\t// l = i, r = i+1\n\t\t\tn->val = x;\n\t\t\tn->act =\
    \ D::id();\n\t\t\treturn;\n\t\t}\n\t\tif(!n->lch) n->lch = new Node(l,(l+r)/2);\n\
    \t\tif(!n->rch) n->rch = new Node((l+r)/2,r);\n\t\tpropagate(l,r,n);\n\t\tassign(a,b,x,n->lch);\n\
    \t\tassign(a,b,x,n->rch);\n\t\tn->val = D::op(n->lch->val , n->rch->val);\n\t\
    }\n\tvoid addlazy(NP n, const F& f){\n\t\tn->act = D::composite(f,n->act);\t\t\
    // \u4E0A\u306E\u968E\u5C64\u306E lazy ( = f) \u306E\u307B\u3046\u304C\u3088\u308A\
    \u3042\u3068\n\t\tn->val = D::act(f,n->val);\t\t\t\t// val \u306F\u5E38\u306B\u6B63\
    \u3057\u304F\n\t}\n\n\tvoid propagate(ll l, ll r, NP n){\n\t\taddlazy(n->lch,\
    \ n->act);\n\t\taddlazy(n->rch, n->act);\n\t\tn->act = D::id();\n\t}\n};\n\nstruct\
    \ D{\n\tstruct Monoid{\n\t\tmint s,ss;\n\t\tmint len;\n\t\tMonoid(){ *this = e();\
    \ }\n\t\tMonoid(mint v):s(v),ss(0),len(1){}\n\t\tMonoid(mint s_,mint ss_,mint\
    \ len_):s(s_),ss(ss_),len(len_){}\n\t\tfriend ostream& operator<<(ostream &o,const\
    \ Monoid& x){ return o<<\"{\"<<x.s<<\",\"<<x.ss<<\",\"<<x.len<<\"}\";}\n\t};\n\
    \tusing Action = mint;\n\tconst static Monoid e(){\n\t\treturn Monoid(0,0,0);\n\
    \t}\n\tconst static Monoid op(const Monoid& x, const Monoid& y){\n\t\tMonoid z;\n\
    \t\tz.s = x.s + y.s;\n\t\tz.ss = x.ss + x.s*y.len + y.ss;\n\t\tz.len = x.len +\
    \ y.len;\n\t\treturn z;\n\t}\n\n\tconst static Action id(){\n\t\treturn Action(0);\n\
    \t}\n\tconst static Action composite(const Action& f, const Action& g){\n\t\t\
    // f \\times g\n\t\treturn f+g;\n\t}\n\n\tconst static Monoid act(const Action&\
    \ f, const Monoid& x){\n\t\tMonoid z;\n\t\tz.s = x.s + f * x.len;\n\t\tz.ss =\
    \ x.ss + f * Choose(x.len,2);\n\t\tz.len = x.len;\n\t\treturn z;\n\t}\n\n\tconst\
    \ static Monoid initialize(ll l, ll r){\n\t\treturn Monoid(0,0,r-l);\n\t}\n};\n\
    \n// pool \u30D0\u30FC\u30B8\u30E7\u30F3\n// \u30B0\u30ED\u30FC\u30D0\u30EB\u306B\
    \ Node<D> pool[] \u3068\u304B\u3092\u304A\u3044\u3066\u3044\u308B\u306E\u3067\u5B9A\
    \u7FA9\u9806\u3068\u304B\u304C\u5FAE\u5999\u306B\u9055\u3046\n\n\ntemplate<class\
    \ D>\nstruct Node{\n\tusing S = typename D::Monoid;\n\tusing F = typename D::Action;\n\
    \tS val;\n\tF act;\n\tint l,r;\t\t\t\t// 10^9 \u3067\u30E1\u30E2\u30EA\u6E1B\u3089\
    \u3057\u305F\u3044\u306A\u3089int\u306B\u5909\u3048\u308B\n\tint lch,rch;\n\t\
    Node(){}\n\tNode(ll l_,ll r_):act(D::id()),l(l_),r(r_),lch(-1),rch(-1){\n\t\t\
    // should initialize val for [l,r)\n\t\t// ex. val = l + .. + r-1\n\t\t// ex.\
    \ val.sz = r-l\n\t\tval = D::initialize(l,r);\n\t}\n\tNode(ll l_,ll r_,S val_):val(val_),act(D::id()),l(l_),r(r_),lch(-1),rch(-1){\n\
    \t\t// OK. initlized with val (act = D::id())\n\t}\n};\nstruct D{\n\tstruct Monoid{\n\
    \t\tmint s,ss;\n\t\tmint len;\n\t\tMonoid(){ *this = e(); }\n\t\tMonoid(mint v):s(v),ss(0),len(1){}\n\
    \t\tMonoid(mint s_,mint ss_,mint len_):s(s_),ss(ss_),len(len_){}\n\t\tfriend ostream&\
    \ operator<<(ostream &o,const Monoid& x){ return o<<\"{\"<<x.s<<\",\"<<x.ss<<\"\
    ,\"<<x.len<<\"}\";}\n\t};\n\tusing Action = mint;\n\tconst static Monoid e(){\n\
    \t\treturn Monoid(0,0,0);\n\t}\n\tconst static Monoid op(const Monoid& x, const\
    \ Monoid& y){\n\t\tMonoid z;\n\t\tz.s = x.s + y.s;\n\t\tz.ss = x.ss + x.s*y.len\
    \ + y.ss;\n\t\tz.len = x.len + y.len;\n\t\treturn z;\n\t}\n\n\tconst static Action\
    \ id(){\n\t\treturn Action(0);\n\t}\n\tconst static Action composite(const Action&\
    \ f, const Action& g){\n\t\t// f \\times g\n\t\treturn f+g;\n\t}\n\n\tconst static\
    \ Monoid act(const Action& f, const Monoid& x){\n\t\tMonoid z;\n\t\tz.s = x.s\
    \ + f * x.len;\n\t\tz.ss = x.ss + f * Choose(x.len,2);\n\t\tz.len = x.len;\n\t\
    \treturn z;\n\t}\n\n\tconst static Monoid initialize(ll l, ll r){\n\t\treturn\
    \ Monoid(0,0,r-l);\n\t}\n};\n\n\nNode<D> pool[3000000];\n\ntemplate<class D>\n\
    struct lazyseg_dynamic{\n\tusing S = typename D::Monoid;\n\tusing F = typename\
    \ D::Action;\n\n\tint I;\n\ttemplate<class... Args>\n\tint makeNode(Args... args){\n\
    \t\tpool[I] = Node<D>(args...);\n\t\treturn I++;\n\t}\n\n\tint root;\n\tlazyseg_dynamic(){\
    \ I = 0; }\n\tlazyseg_dynamic(ll N){\n\t\tI = 0;\n\t\tll n2 = 1;\n\t\twhile(n2\
    \ < N) n2 *= 2;\n\t\troot = makeNode(0,n2);\n\t}\n\n\tS query(ll a, ll b){\n\t\
    \treturn query(a,b,root);\n\t}\n\tvoid apply(ll i, F f){\n\t\tapply(i,i+1,f);\n\
    \t}\n\tvoid apply(ll a, ll b, F f){\n\t\tapply(a,b,f,root);\n\t}\n\tvoid assign(ll\
    \ i, S x){\n\t\tassign(i,i+1,x,root);\n\t}\n\tprivate:\n\tS query(ll a, ll b,\
    \ int n){\n\t\tll l = pool[n].l, r = pool[n].r;\n\t\tif(b<=l || r<=a) return D::e();\n\
    \t\tif(a<=l && r<=b) return pool[n].val;\n\t\tif(pool[n].lch == -1) pool[n].lch\
    \ = makeNode(l,(l+r)/2);\n\t\tif(pool[n].rch == -1) pool[n].rch = makeNode((l+r)/2,r);\n\
    \t\tpropagate(l,r,n);\n\t\treturn D::op(query(a,b,pool[n].lch) , query(a,b,pool[n].rch));\n\
    \t}\n\tvoid apply(ll a, ll b, const F& f, int n){\n\t\tll l = pool[n].l, r = pool[n].r;\n\
    \t\tif(b<=l || r<=a) return;\n\t\tif(a<=l && r<=b){\n\t\t\taddlazy(n,f);\n\t\t\
    \treturn;\n\t\t}\n\t\tif(pool[n].lch == -1) pool[n].lch = makeNode(l,(l+r)/2);\n\
    \t\tif(pool[n].rch == -1) pool[n].rch = makeNode((l+r)/2,r);\n\t\tpropagate(l,r,n);\n\
    \t\tapply(a,b,f,pool[n].lch);\n\t\tapply(a,b,f,pool[n].rch);\n\t\tpool[n].val\
    \ = D::op(pool[pool[n].lch].val , pool[pool[n].rch].val);\n\t}\n\tvoid assign(ll\
    \ a, ll b, const S& x, int n){\n\t\tll l = pool[n].l, r = pool[n].r;\n\t\tif(b<=l\
    \ || r<=a) return;\n\t\tif(a<=l && r<=b){\n\t\t\t// l = i, r = i+1\n\t\t\tpool[n].val\
    \ = x;\n\t\t\tpool[n].act = D::id();\n\t\t\treturn;\n\t\t}\n\t\tif(pool[n].lch\
    \ == -1) pool[n].lch = makeNode(l,(l+r)/2);\n\t\tif(pool[n].rch == -1) pool[n].rch\
    \ = makeNode((l+r)/2,r);\n\t\tpropagate(l,r,n);\n\t\tassign(a,b,x,pool[n].lch);\n\
    \t\tassign(a,b,x,pool[n].rch);\n\t\tpool[n].val = D::op(pool[pool[n].lch].val\
    \ , pool[pool[n].rch].val);\n\t}\n\tvoid addlazy(int n, const F& f){\n\t\tpool[n].act\
    \ = D::composite(f,pool[n].act);\t\t// \u4E0A\u306E\u968E\u5C64\u306E lazy ( =\
    \ f) \u306E\u307B\u3046\u304C\u3088\u308A\u3042\u3068\n\t\tpool[n].val = D::act(f,pool[n].val);\t\
    \t\t\t// val \u306F\u5E38\u306B\u6B63\u3057\u304F\n\t}\n\n\tvoid propagate(ll\
    \ l, ll r, int n){\n\t\taddlazy(pool[n].lch, pool[n].act);\n\t\taddlazy(pool[n].rch,\
    \ pool[n].act);\n\t\tpool[n].act = D::id();\n\t}\n};\n"
  code: "/*\n\tlazyseg \u3068\u307B\u307C\u540C\u3058API\u306B\u306A\u3063\u3066\u3044\
    \u308B\n\t\u4E00\u3064\u9055\u3046\u306E\u306F\u3001 Node(l,r) \u3092\u547C\u3093\
    \u3060\u3068\u304D D::e() \u3092\u8FD4\u3057\u3066\u306F\u3044\u3051\u306A\u3044\
    (\u305D\u308C\u306F\u305D\u3046\u3001\u4F8B\u3048\u3070\u30B5\u30A4\u30BA\u306F\
    \ r-l) \u305F\u3081\u3001\n\tD \u306E\u4E2D\u306B initialize(l,r) \u3068\u3044\
    \u3046\u95A2\u6570\u3092\u4F5C\u308B\u5FC5\u8981\u304C\u3042\u308B\n\t\u521D\u671F\
    \u72B6\u614B\u3067\u306E a[l] + .. + a[r-1] \u3092\u8FD4\u305B\u3070\u3044\u3044\
    \n\n\t\u30E1\u30E2\u30EA\u304C\u3084\u3070\u3044\u53EF\u80FD\u6027\u304C\u9AD8\
    \u3044\u3002\u305D\u306E\u5834\u5408:\n\t\t- Node \u306E l,r \u3092\u53EF\u80FD\
    \u306A\u3089 int \u306B\n\t\t- \u3061\u3083\u3093\u3068 delete \u3092\u3059\u308B\
    \ (\u3057\u306A\u3044\u307B\u3046\u304C\u5B9F\u884C\u6642\u9593\u306F\u901F\u305D\
    \u3046) \u6A19\u6E96\u3067\u306F\u3057\u3066\u3044\u308B\n\t\t- \u3046\u3057\u308D\
    \u306B\u8CBC\u3063\u3066\u3042\u308B lazyseg_dynamic_pool \u3092\u4F7F\u3046\n\
    \tpool, \u305D\u3093\u306A\u306B\u4F7F\u3044\u3065\u3089\u304F\u306A\u3044\u3051\
    \u3069\u914D\u5217\u306E\u9577\u3055\u3092\u6307\u5B9A\u3057\u305F\u308A\u3059\
    \u308B\u5FC5\u8981\u304C\u3042\u3063\u3066\u307B\u3093\u306E\u5C11\u3057\u9762\
    \u5012\n\n\tverify\n\t\thttps://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2377\
    \ ThreeRooks\n*/\ntemplate<class D>\nstruct lazyseg_dynamic{\n\tusing S = typename\
    \ D::Monoid;\n\tusing F = typename D::Action;\n\n\tstruct Node;\n\tusing NP =\
    \ Node*;\n\tstruct Node{\n\t\tS val;\n\t\tF act;\n\t\tll l,r;\t\t\t\t// 10^9 \u3067\
    \u30E1\u30E2\u30EA\u6E1B\u3089\u3057\u305F\u3044\u306A\u3089int\u306B\u5909\u3048\
    \u308B\n\t\tNP lch,rch;\n\t\tNode(ll l_,ll r_):act(D::id()),l(l_),r(r_),lch(nullptr),rch(nullptr){\n\
    \t\t\t// should initialize val for [l,r)\n\t\t\t// ex. val = l + .. + r-1\n\t\t\
    \t// ex. val.sz = r-l\n\t\t\tval = D::initialize(l,r);\n\t\t}\n\t\tNode(ll l_,ll\
    \ r_,S val_):val(val_),act(D::id()),l(l_),r(r_),lch(nullptr),rch(nullptr){\n\t\
    \t\t// OK. initlized with val (act = D::id())\n\t\t}\n\t\t~Node(){\n\t\t\tdelete\
    \ lch;\n\t\t\tdelete rch;\n\t\t}\n\t};\n\n\tNP root;\n\tlazyseg_dynamic(){}\n\t\
    lazyseg_dynamic(ll N){\n\t\tll n2 = 1;\n\t\twhile(n2 < N) n2 *= 2;\n\t\troot =\
    \ new Node(0,n2);\n\t}\n\t~lazyseg_dynamic(){\n\t\tdelete root;\n\t}\n\n\tS query(ll\
    \ a, ll b){\n\t\treturn query(a,b,root);\n\t}\n\tvoid apply(ll i, F f){\n\t\t\
    apply(i,i+1,f);\n\t}\n\tvoid apply(ll a, ll b, F f){\n\t\tapply(a,b,f,root);\n\
    \t}\n\tvoid assign(ll i, S x){\n\t\tassign(i,i+1,x,root);\n\t}\n\tprivate:\n\t\
    S query(ll a, ll b, NP n){\n\t\tll l = n->l, r = n->r;\n\t\tif(b<=l || r<=a) return\
    \ D::e();\n\t\tif(a<=l && r<=b) return n->val;\n\t\tif(!n->lch) n->lch = new Node(l,(l+r)/2);\n\
    \t\tif(!n->rch) n->rch = new Node((l+r)/2,r);\n\t\tpropagate(l,r,n);\n\t\treturn\
    \ D::op(query(a,b,n->lch) , query(a,b,n->rch));\n\t}\n\tvoid apply(ll a, ll b,\
    \ const F& f, NP n){\n\t\tll l = n->l, r = n->r;\n\t\tif(b<=l || r<=a) return;\n\
    \t\tif(a<=l && r<=b){\n\t\t\taddlazy(n,f);\n\t\t\treturn;\n\t\t}\n\t\tif(!n->lch)\
    \ n->lch = new Node(l,(l+r)/2);\n\t\tif(!n->rch) n->rch = new Node((l+r)/2,r);\n\
    \t\tpropagate(l,r,n);\n\t\tapply(a,b,f,n->lch);\n\t\tapply(a,b,f,n->rch);\n\t\t\
    n->val = D::op(n->lch->val , n->rch->val);\n\t}\n\tvoid assign(ll a, ll b, const\
    \ S& x, NP n){\n\t\tll l = n->l, r = n->r;\n\t\tif(b<=l || r<=a) return;\n\t\t\
    if(a<=l && r<=b){\n\t\t\t// l = i, r = i+1\n\t\t\tn->val = x;\n\t\t\tn->act =\
    \ D::id();\n\t\t\treturn;\n\t\t}\n\t\tif(!n->lch) n->lch = new Node(l,(l+r)/2);\n\
    \t\tif(!n->rch) n->rch = new Node((l+r)/2,r);\n\t\tpropagate(l,r,n);\n\t\tassign(a,b,x,n->lch);\n\
    \t\tassign(a,b,x,n->rch);\n\t\tn->val = D::op(n->lch->val , n->rch->val);\n\t\
    }\n\tvoid addlazy(NP n, const F& f){\n\t\tn->act = D::composite(f,n->act);\t\t\
    // \u4E0A\u306E\u968E\u5C64\u306E lazy ( = f) \u306E\u307B\u3046\u304C\u3088\u308A\
    \u3042\u3068\n\t\tn->val = D::act(f,n->val);\t\t\t\t// val \u306F\u5E38\u306B\u6B63\
    \u3057\u304F\n\t}\n\n\tvoid propagate(ll l, ll r, NP n){\n\t\taddlazy(n->lch,\
    \ n->act);\n\t\taddlazy(n->rch, n->act);\n\t\tn->act = D::id();\n\t}\n};\n\nstruct\
    \ D{\n\tstruct Monoid{\n\t\tmint s,ss;\n\t\tmint len;\n\t\tMonoid(){ *this = e();\
    \ }\n\t\tMonoid(mint v):s(v),ss(0),len(1){}\n\t\tMonoid(mint s_,mint ss_,mint\
    \ len_):s(s_),ss(ss_),len(len_){}\n\t\tfriend ostream& operator<<(ostream &o,const\
    \ Monoid& x){ return o<<\"{\"<<x.s<<\",\"<<x.ss<<\",\"<<x.len<<\"}\";}\n\t};\n\
    \tusing Action = mint;\n\tconst static Monoid e(){\n\t\treturn Monoid(0,0,0);\n\
    \t}\n\tconst static Monoid op(const Monoid& x, const Monoid& y){\n\t\tMonoid z;\n\
    \t\tz.s = x.s + y.s;\n\t\tz.ss = x.ss + x.s*y.len + y.ss;\n\t\tz.len = x.len +\
    \ y.len;\n\t\treturn z;\n\t}\n\n\tconst static Action id(){\n\t\treturn Action(0);\n\
    \t}\n\tconst static Action composite(const Action& f, const Action& g){\n\t\t\
    // f \\times g\n\t\treturn f+g;\n\t}\n\n\tconst static Monoid act(const Action&\
    \ f, const Monoid& x){\n\t\tMonoid z;\n\t\tz.s = x.s + f * x.len;\n\t\tz.ss =\
    \ x.ss + f * Choose(x.len,2);\n\t\tz.len = x.len;\n\t\treturn z;\n\t}\n\n\tconst\
    \ static Monoid initialize(ll l, ll r){\n\t\treturn Monoid(0,0,r-l);\n\t}\n};\n\
    \n// pool \u30D0\u30FC\u30B8\u30E7\u30F3\n// \u30B0\u30ED\u30FC\u30D0\u30EB\u306B\
    \ Node<D> pool[] \u3068\u304B\u3092\u304A\u3044\u3066\u3044\u308B\u306E\u3067\u5B9A\
    \u7FA9\u9806\u3068\u304B\u304C\u5FAE\u5999\u306B\u9055\u3046\n\n\ntemplate<class\
    \ D>\nstruct Node{\n\tusing S = typename D::Monoid;\n\tusing F = typename D::Action;\n\
    \tS val;\n\tF act;\n\tint l,r;\t\t\t\t// 10^9 \u3067\u30E1\u30E2\u30EA\u6E1B\u3089\
    \u3057\u305F\u3044\u306A\u3089int\u306B\u5909\u3048\u308B\n\tint lch,rch;\n\t\
    Node(){}\n\tNode(ll l_,ll r_):act(D::id()),l(l_),r(r_),lch(-1),rch(-1){\n\t\t\
    // should initialize val for [l,r)\n\t\t// ex. val = l + .. + r-1\n\t\t// ex.\
    \ val.sz = r-l\n\t\tval = D::initialize(l,r);\n\t}\n\tNode(ll l_,ll r_,S val_):val(val_),act(D::id()),l(l_),r(r_),lch(-1),rch(-1){\n\
    \t\t// OK. initlized with val (act = D::id())\n\t}\n};\nstruct D{\n\tstruct Monoid{\n\
    \t\tmint s,ss;\n\t\tmint len;\n\t\tMonoid(){ *this = e(); }\n\t\tMonoid(mint v):s(v),ss(0),len(1){}\n\
    \t\tMonoid(mint s_,mint ss_,mint len_):s(s_),ss(ss_),len(len_){}\n\t\tfriend ostream&\
    \ operator<<(ostream &o,const Monoid& x){ return o<<\"{\"<<x.s<<\",\"<<x.ss<<\"\
    ,\"<<x.len<<\"}\";}\n\t};\n\tusing Action = mint;\n\tconst static Monoid e(){\n\
    \t\treturn Monoid(0,0,0);\n\t}\n\tconst static Monoid op(const Monoid& x, const\
    \ Monoid& y){\n\t\tMonoid z;\n\t\tz.s = x.s + y.s;\n\t\tz.ss = x.ss + x.s*y.len\
    \ + y.ss;\n\t\tz.len = x.len + y.len;\n\t\treturn z;\n\t}\n\n\tconst static Action\
    \ id(){\n\t\treturn Action(0);\n\t}\n\tconst static Action composite(const Action&\
    \ f, const Action& g){\n\t\t// f \\times g\n\t\treturn f+g;\n\t}\n\n\tconst static\
    \ Monoid act(const Action& f, const Monoid& x){\n\t\tMonoid z;\n\t\tz.s = x.s\
    \ + f * x.len;\n\t\tz.ss = x.ss + f * Choose(x.len,2);\n\t\tz.len = x.len;\n\t\
    \treturn z;\n\t}\n\n\tconst static Monoid initialize(ll l, ll r){\n\t\treturn\
    \ Monoid(0,0,r-l);\n\t}\n};\n\n\nNode<D> pool[3000000];\n\ntemplate<class D>\n\
    struct lazyseg_dynamic{\n\tusing S = typename D::Monoid;\n\tusing F = typename\
    \ D::Action;\n\n\tint I;\n\ttemplate<class... Args>\n\tint makeNode(Args... args){\n\
    \t\tpool[I] = Node<D>(args...);\n\t\treturn I++;\n\t}\n\n\tint root;\n\tlazyseg_dynamic(){\
    \ I = 0; }\n\tlazyseg_dynamic(ll N){\n\t\tI = 0;\n\t\tll n2 = 1;\n\t\twhile(n2\
    \ < N) n2 *= 2;\n\t\troot = makeNode(0,n2);\n\t}\n\n\tS query(ll a, ll b){\n\t\
    \treturn query(a,b,root);\n\t}\n\tvoid apply(ll i, F f){\n\t\tapply(i,i+1,f);\n\
    \t}\n\tvoid apply(ll a, ll b, F f){\n\t\tapply(a,b,f,root);\n\t}\n\tvoid assign(ll\
    \ i, S x){\n\t\tassign(i,i+1,x,root);\n\t}\n\tprivate:\n\tS query(ll a, ll b,\
    \ int n){\n\t\tll l = pool[n].l, r = pool[n].r;\n\t\tif(b<=l || r<=a) return D::e();\n\
    \t\tif(a<=l && r<=b) return pool[n].val;\n\t\tif(pool[n].lch == -1) pool[n].lch\
    \ = makeNode(l,(l+r)/2);\n\t\tif(pool[n].rch == -1) pool[n].rch = makeNode((l+r)/2,r);\n\
    \t\tpropagate(l,r,n);\n\t\treturn D::op(query(a,b,pool[n].lch) , query(a,b,pool[n].rch));\n\
    \t}\n\tvoid apply(ll a, ll b, const F& f, int n){\n\t\tll l = pool[n].l, r = pool[n].r;\n\
    \t\tif(b<=l || r<=a) return;\n\t\tif(a<=l && r<=b){\n\t\t\taddlazy(n,f);\n\t\t\
    \treturn;\n\t\t}\n\t\tif(pool[n].lch == -1) pool[n].lch = makeNode(l,(l+r)/2);\n\
    \t\tif(pool[n].rch == -1) pool[n].rch = makeNode((l+r)/2,r);\n\t\tpropagate(l,r,n);\n\
    \t\tapply(a,b,f,pool[n].lch);\n\t\tapply(a,b,f,pool[n].rch);\n\t\tpool[n].val\
    \ = D::op(pool[pool[n].lch].val , pool[pool[n].rch].val);\n\t}\n\tvoid assign(ll\
    \ a, ll b, const S& x, int n){\n\t\tll l = pool[n].l, r = pool[n].r;\n\t\tif(b<=l\
    \ || r<=a) return;\n\t\tif(a<=l && r<=b){\n\t\t\t// l = i, r = i+1\n\t\t\tpool[n].val\
    \ = x;\n\t\t\tpool[n].act = D::id();\n\t\t\treturn;\n\t\t}\n\t\tif(pool[n].lch\
    \ == -1) pool[n].lch = makeNode(l,(l+r)/2);\n\t\tif(pool[n].rch == -1) pool[n].rch\
    \ = makeNode((l+r)/2,r);\n\t\tpropagate(l,r,n);\n\t\tassign(a,b,x,pool[n].lch);\n\
    \t\tassign(a,b,x,pool[n].rch);\n\t\tpool[n].val = D::op(pool[pool[n].lch].val\
    \ , pool[pool[n].rch].val);\n\t}\n\tvoid addlazy(int n, const F& f){\n\t\tpool[n].act\
    \ = D::composite(f,pool[n].act);\t\t// \u4E0A\u306E\u968E\u5C64\u306E lazy ( =\
    \ f) \u306E\u307B\u3046\u304C\u3088\u308A\u3042\u3068\n\t\tpool[n].val = D::act(f,pool[n].val);\t\
    \t\t\t// val \u306F\u5E38\u306B\u6B63\u3057\u304F\n\t}\n\n\tvoid propagate(ll\
    \ l, ll r, int n){\n\t\taddlazy(pool[n].lch, pool[n].act);\n\t\taddlazy(pool[n].rch,\
    \ pool[n].act);\n\t\tpool[n].act = D::id();\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/lazyseg_dynamic.cpp
  requiredBy: []
  timestamp: '2024-01-03 19:12:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/lazyseg_dynamic.cpp
layout: document
redirect_from:
- /library/ds/segtree/lazyseg_dynamic.cpp
- /library/ds/segtree/lazyseg_dynamic.cpp.html
title: ds/segtree/lazyseg_dynamic.cpp
---
