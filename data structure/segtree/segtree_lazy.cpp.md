---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data structure/segtree/segtree_lazy.cpp\"\n#include <bits/stdc++.h>\r\
    \n#define rep(i,N) for(int i=0;i<(int)N;i++)\r\n#define show(x) cout << #x <<\
    \ \" = \" << x << endl\r\nusing namespace std;\r\ntemplate<class S,class T> ostream&\
    \ operator<<(ostream& o,const pair<S,T> &p){return o<<\"(\"<<p.fs<<\",\"<<p.sc<<\"\
    )\";}\r\ntemplate<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<\"\
    sz = \"<<vc.size()<<endl<<\"[\";for(const T& v:vc) o<<v<<\",\";o<<\"]\";return\
    \ o;}\r\n/*\r\n\u9045\u5EF6\u8A55\u4FA1segtree\r\n\u30C7\u30FC\u30BF\u306E\u578B\
    \ val_t \u3068\u64CD\u4F5C\u306E\u578B opr_t \u304C\u3042\u308B\r\nopr_t \u306E\
    \u7D50\u5408\u5F8B\u304C\u5FC5\u8981\r\n\r\n\u3044\u308D\u3044\u308D\u67D4\u8EDF\
    \u306B\u66F8\u304D\u63DB\u3048\u3066\u3044\u304F\u5FC5\u8981\u304C\u3042\u308A\
    \u305D\u3046(ex.propagate\u3067\u7B49\u5DEE\u6570\u5217\u3092\u8DB3\u3059\u3068\
    \u304D\u306Bopr_t\u578B\u3060\u3068\u53F3\u5074\u3067\u306F\u521D\u9805\u304C\u305A\
    \u308C\u308B,\u3053\u308C\u306B\u306Fl,r\u3082\u5FC5\u8981)\r\n\u305D\u308C\u305E\
    \u308C\u66F8\u304F\u3079\u304D\u306A\u306E\u306F\u3001handler\u5185\u306E\r\n\
    \ - val_t\u306Edef\u3068+\r\n - opr_t\u306Edef\r\n - getfg (setg2fg)\r\n - act\r\
    \n - \u5916\u5074\u306B\u304A\u3044\u3066\u3042\u308Bconst static e \u306E\u5B9F\
    \u4F53\r\n\r\n \u3042\u3068\u3001act\u306Bl,r\u3092\u6E21\u3059\u5FC5\u8981\u304C\
    \u3042\u308B\u3068\u304B\u305D\u3046\u3044\u3063\u305F\u3053\u3068\u3067\u5185\
    \u5074\u3092\u66F8\u304D\u63DB\u3048\u308B(\u5F15\u6570\u5897\u3084\u3059\u3060\
    \u3051)\r\n\r\n2018/07/11\u5909\u66F4\r\n\tlazy\u304B\u3051\u308B\u30BF\u30A4\u30DF\
    \u30F3\u30B0\u3067val\u3082\u5909\u66F4\u3055\u305B\u3061\u3083\u3063\u305F\u307B\
    \u3046\u304C\u826F\u3055\u305D\u3046\u306A\u306E\u3067\u5B9F\u88C5\u3092\u5909\
    \u3048\u305F, unittest\u306F\u901A\u3063\u305F\r\n*/\r\ntemplate<class Handler>\r\
    \nstruct segtree_lazy{\r\n\tusing val_t = typename Handler::val_t;\r\n\tusing\
    \ opr_t = typename Handler::opr_t;\r\n\tint N;\r\n\tvector<val_t> val;\r\n\tvector<opr_t>\
    \ lazy;\r\n\tsegtree_lazy(){}\r\n\tsegtree_lazy(int n){init(n);}\r\n\tsegtree_lazy(const\
    \ vector<val_t>& vc){init(vc);}\r\n\tvoid init(int n){\r\n\t\tN=1;\r\n\t\twhile(N<n)\
    \ N*=2;\r\n\t\tval .assign(N*2,val_t::e());\r\n\t\tlazy.assign(N*2,opr_t::e());\r\
    \n\t}\r\n\tvoid init(const vector<val_t>& vc){\r\n\t\tint n = vc.size();\r\n\t\
    \tN=1;\r\n\t\twhile(N<n) N*=2;\r\n\t\tval .assign(N*2,val_t::e());\r\n\t\trep(i,n)\
    \ val[i+N] = vc[i];\r\n\t\tfor(int i=N-1;i>0;i--) val[i] = val[i*2] + val[i*2+1];\r\
    \n\t\tlazy.assign(N*2,opr_t::e());\r\n\t}\r\n\r\n\tval_t query(int a,int b,int\
    \ l=0,int r=-1,int k=1){\t//query_calc\r\n\t\tif(r==-1) r=N;\r\n\t\tif(b<=l||r<=a)\
    \ return val_t::e();\r\n\t\tif(a<=l&&r<=b) return val[k];\r\n\t\tpropagate(l,r,k);\r\
    \n\t\treturn query(a,b,l,(l+r)/2,k*2) + query(a,b,(l+r)/2,r,k*2+1);\r\n\t}\r\n\
    \tvoid addlazy(int k,const opr_t &f){\r\n\t\tHandler::setg2fg(f,lazy[k]);\r\n\t\
    \tval[k] = Handler::act(f,val[k]);\r\n\t}\r\n\r\n\tvoid update(int a,int b,const\
    \ opr_t &f,int l=0,int r=-1,int k=1){\t//query_update\r\n\t\tif(r==-1) r=N;\r\n\
    \t\tif(b<=l||r<=a) return;\r\n\t\tif(a<=l&&r<=b){\r\n\t\t\taddlazy(k,f);\r\n\t\
    \t\treturn;\r\n\t\t}\r\n\t\tpropagate(l,r,k);\r\n\t\tupdate(a,b,f,l,(l+r)/2,k*2);\r\
    \n\t\tupdate(a,b,f,(l+r)/2,r,k*2+1);\r\n\t\tval[k] = val[k*2] + val[k*2+1];\r\n\
    \t}\r\n\tvoid propagate(int l,int r,int k){\t//opr_child -> opr_parent * opr_child\t\
    \tparent after child\r\n\t\taddlazy(k*2  ,lazy[k]);\r\n\t\taddlazy(k*2+1,lazy[k]);\r\
    \n\t\tlazy[k] = opr_t::e();\r\n\t}\r\n};\r\n\r\nstruct handler1{\r\n\t/*\r\n\t\
    \trange assign 0\u4EE5\u4E0A\r\n\t\trange max\r\n\r\n\t\tval_t = int,max\t\t\t\
    val[k]=max\r\n\t\topr_t(x) : y -> x\t\tlazy[k]=assign\r\n\r\n\t\t\u4ECA\u56DE\u306E\
    \u5834\u5408opr_t::e\u306F\u306A\u3044(assign\u306B\u5358\u4F4D\u5143\u306F\u306A\
    \u3044)\r\n\t\t\u3053\u306E\u3088\u3046\u306A\u3068\u304D\u306F\u3001\u9069\u5F53\
    \u306A\u5024\u3092\u5358\u4F4D\u5143\u306B\u8A2D\u5B9A\u306B\u3057\u3066\u304A\
    \u304D\u3001getfg/setg2fg/ act!! \u3067\u5408\u6210\u3057\u306A\u3044\u3088\u3046\
    \u51E6\u7406\u3057\u3066\u304A\u3051\u3070\u826F\u3044\r\n\t\t\u8003\u3048\u306B\
    \u304F\u3044\u3051\u3069val_t\u3082\u540C\u69D8.\r\n\t\t\u6700\u60AAoption\u578B\
    \u307F\u305F\u3044\u306Bbool\u5024\u3092\u3082\u305F\u305B\u308C\u3070\u826F\u3055\
    \u305D\u3046\r\n\t*/\r\n\tstruct val_t{\r\n\t\tint x;\r\n\t\tval_t(){*this = e();}\r\
    \n\t\tval_t(int x):x(x){}\r\n\r\n\t\tconst static val_t e(){\r\n\t\t\treturn val_t(0);\r\
    \n\t\t}\r\n\t\tval_t operator+(const val_t &r) const {\r\n\t\t\treturn val_t(max(x,r.x));\r\
    \n\t\t}\r\n\t\tfriend ostream& operator<<(ostream& o,const val_t& d){return o<<d.x;}\r\
    \n\t};\r\n\r\n\tstruct opr_t{\r\n\t\tint x;\r\n\t\topr_t(){*this = e();}\r\n\t\
    \topr_t(int x):x(x){}\r\n\r\n\t\tconst static opr_t e(){\r\n\t\t\treturn opr_t(-1);\r\
    \n\t\t}\r\n\t\tfriend ostream& operator<<(ostream& o,const opr_t& d){return o<<d.x;}\r\
    \n\t};\r\n\r\n//\tstatic opr_t getfg(const opr_t &f, const opr_t &g){\r\n//\r\n\
    //\t}\r\n\t/*\r\n\t\t\u3082\u3057\u30B3\u30D4\u30FC\u30B3\u30B9\u30C8\u3068\u304B\
    \u304C\u6C17\u306B\u306A\u3063\u3066,\u3057\u304B\u3082\u697D\u306B\u66F8\u3051\
    \u308B\u306A\u3089setg2fg\u3092\u76F4\u63A5\u66F8\u304F\r\n\t\t\u305D\u3046\u3058\
    \u3083\u306A\u3044\u306A\u3089 g = getfg(f,g)\r\n\t*/\r\n\tstatic void setg2fg(const\
    \ opr_t &f, opr_t &g){\t//g -> fg\t\tf after g\r\n\t\tif(f.x != -1) g.x = f.x;\r\
    \n\t}\r\n\tstatic val_t act(const opr_t &f, const val_t &v){\t\t//max\u304Cv \u3063\
    \u3066\u3044\u3046\u72B6\u614B\u306E\u3068\u3053\u308D\u306Bf\u3092\u4F5C\u7528\
    \u3055\u305B\u308B\u3068max\u306F\u4F55\u306B\u306A\u308A\u307E\u3059\u304B?\r\
    \n\t\tif(f.x == -1) return v;\r\n\t\treturn val_t(f.x);\r\n\t}\r\n};\r\n\r\n\r\
    \nstruct handler2{\r\n\t/*\r\n\t\trange assign 0\u4EE5\u4E0A\r\n\t\trange sum\r\
    \n\r\n\t\tval_t = int,+\t\t\tval[k]= +\r\n\t\topr_t(x) : y -> x\t\tlazy[k]=assign\r\
    \n\r\n\t\tassign\u306F\u4E00\u7DD2\u306A\u306E\u3067\u3001opr_t,getfg\u306F\u5909\
    \u3048\u306A\u304F\u3066\u3044\u3044\r\n\t\t\u6C17\u3065\u3044\u305F\u3093\u3067\
    \u3059\u304C,act\u3068\u304B\u306Bl,r\u304C\u5FC5\u8981\u306A\u30B1\u30FC\u30B9\
    \u304C\u591A\u3059\u304E\u308B(sum\u7CFB\u3068\u304B\u307B\u307C\u78BA\u5B9F\u306B\
    \u5FC5\u8981)\u306E\u3067\u3001\u3082\u3046\u3053\u3046\u3044\u3046\u306E\u306F\
    val_t\u306Bl,r\u3092\u7F6E\u304F\u3053\u3068\u306B\u3057\u307E\u3059\r\n\t\t\u3068\
    \u601D\u3063\u305F\u304C\u3001\u3084\u3063\u3071\u308A\u3084\u3081\u3066\u3001\
    l\u3068r\u3092\u9811\u5F35\u3063\u3066act\u306B\u6E21\u3059\u3053\u3068\u306B\u3057\
    \u305F\r\n\t\tgetfg\u3068\u304B\u306B\u3082\u5FC5\u8981\u306B\u306A\u308B\u3068\
    \u7D76\u671B\u611F\u304C\u5897\u3057\u305D\u3046\r\n\r\n\t*/\r\n\tstruct val_t{\r\
    \n\t\tint x;\r\n\t\tval_t(){*this = e();}\r\n\t\tval_t(int x):x(x){}\r\n\r\n\t\
    \tconst static val_t e(){\r\n\t\t\treturn val_t(0);\r\n\t\t}\r\n\t\tval_t operator+(const\
    \ val_t &r) const {\r\n\t\t\treturn val_t(x+r.x);\r\n\t\t}\r\n\t\tfriend ostream&\
    \ operator<<(ostream& o,const val_t& d){return o<<d.x;}\r\n\t};\r\n\r\n\tstruct\
    \ opr_t{\r\n\t\tint x;\r\n\t\topr_t(){*this = e();}\r\n\t\topr_t(int x):x(x){}\r\
    \n\r\n\t\tconst static opr_t e(){\r\n\t\t\treturn opr_t(-1);\r\n\t\t}\r\n\t\t\
    friend ostream& operator<<(ostream& o,const opr_t& d){return o<<d.x;}\r\n\t};\r\
    \n\r\n\tstatic void getfg(const opr_t &f, const opr_t &g){\r\n\t\t\r\n\t}\r\n\t\
    /*\r\n\t\t\u3082\u3057\u30B3\u30D4\u30FC\u30B3\u30B9\u30C8\u3068\u304B\u304C\u6C17\
    \u306B\u306A\u3063\u3066,\u3057\u304B\u3082\u697D\u306B\u66F8\u3051\u308B\u306A\
    \u3089setg2fg\u3092\u76F4\u63A5\u66F8\u304F\r\n\t\t\u305D\u3046\u3058\u3083\u306A\
    \u3044\u306A\u3089 g = getfg(f,g)\r\n\t*/\r\n\tstatic void setg2fg(const opr_t\
    \ &f, opr_t &g){\t//g -> fg\t\tf after g\r\n\t\tif(f.x != -1) g.x = f.x;\r\n\t\
    }\r\n\tstatic val_t act(const opr_t &f, const val_t &v,int k,int l,int r){\t//assign\
    \ f.x -> sum = \r\n\t\tif(f.x == -1) return v;\r\n\t\treturn val_t(f.x*(r-l));\r\
    \n\t}\r\n};\r\n\r\n\r\nstruct handler3{\r\n\tusing ll = long long;\r\n\t/*\r\n\
    \t\trange assign\r\n\t\trange add\r\n\t\tpoint val\r\n\r\n\t\tval_t = int\r\n\t\
    \topr_t(x) : assign x or add y\r\n\r\n\t\t(assign x)(assign y) = (assign x)\r\n\
    \t\t(assign x)(add y) = (assign x)\r\n\t\t(add x)(assign y) = (assign y+x)\r\n\
    \t\t(add x)(add y) = (add x+y)\r\n\t\t(assign or add)\u304C\u9589\u3058\u3066\u3044\
    \u308B\u306E\u3067\u3001\u3053\u306E\u5F62\u3092opr_t\u3068\u3057\u3066\u6301\u3066\
    \u3070\u826F\u3044.\r\n\t\t\u533A\u9593get\u304C\u306A\u3044\u3068\u304B\u306A\
    \u308A\u8003\u3048\u3084\u3059\u3044\u306A\u3042\r\n\t\t\u3068\u3044\u3046\u304B\
    \u3001val_t\u540C\u58EB\u306E\u6F14\u7B97\u304C\u3044\u3089\u306A\u304F\u3066\u3001\
    opr_t\u3060\u3051\u3067\u3067\u304D\u3066\u308B\u306A\u3053\u308C\r\n\t\t\u3068\
    \u306F\u3044\u3048\u3068\u308A\u3042\u3048\u305A\u7528\u610F\u3057\u3066\u308B\
    (\u5358\u4F4D\u5143\u3068\u306E\u5408\u6210\u306F\u884C\u308F\u308C\u308B)\u306E\
    \u3067\u3001\u77DB\u76FE\u304C\u306A\u3044\u3088\u3046\u306B\u3057\u306A\u3044\
    \u3068\u307E\u305A\u3044(\u306E\u3067+\u3068e=0\u306B\u3057\u305F)\r\n\t\tverified\
    \ at atcoder/dwango2015/qual/E_lazy.cpp \u82B1\u706B\r\n\r\n\t*/\r\n\tstruct val_t{\r\
    \n\t\tll x;\r\n\t\tval_t(){*this = e();}\r\n\t\tval_t(ll x):x(x){}\r\n\r\n\t\t\
    const static val_t e(){\r\n\t\t\treturn val_t(0);\r\n\t\t}\r\n\t\tval_t operator+(const\
    \ val_t &r) const {\r\n\t\t\treturn val_t(x+r.x);\r\n\t\t}\r\n\t\tfriend ostream&\
    \ operator<<(ostream& o,const val_t& d){return o<<d.x;}\r\n\t};\r\n\r\n\tstruct\
    \ opr_t{\r\n\t\tbool is_add;\r\n\t\tll x;\r\n\t\topr_t(){*this = e();}\r\n\t\t\
    opr_t(bool b,ll x):is_add(b),x(x){}\r\n\r\n\t\tconst static opr_t e(){\r\n\t\t\
    \treturn opr_t(true,0);\t//add 0\r\n\t\t}\r\n\t\tfriend ostream& operator<<(ostream&\
    \ o,const opr_t& d){return o<<(d.is_add?\"add\":\"assign\")<<\" \"<<d.x;}\r\n\t\
    };\r\n\r\n\tstatic opr_t getfg(const opr_t &f, const opr_t &g){\r\n\t\tif(f.is_add){\r\
    \n\t\t\tif(g.is_add) return opr_t(true,f.x+g.x);\r\n\t\t\telse return opr_t(false,f.x+g.x);\r\
    \n\t\t}else{\r\n\t\t\treturn f;\r\n\t\t}\r\n\t}\r\n\tstatic void setg2fg(const\
    \ opr_t &f, opr_t &g){\t//g -> fg\t\tf after g\r\n\t\tg = getfg(f,g);\r\n\t}\r\
    \n\tstatic val_t act(const opr_t &f, const val_t &v,int k,int l,int r){\t//assign\
    \ f.x -> sum = \r\n\t\tif(f.is_add) return val_t(v+f.x);\r\n\t\telse return val_t(f.x);\r\
    \n\t}\r\n};\r\n\r\nstruct handler4{\r\n\t/*\r\n\t\tOpenCup/3192/E.cpp\r\n\t\t\
    range add\r\n\t\trange max \u305F\u3060\u3057\u3001\u3053\u306E\u30AF\u30A8\u30EA\
    \u304C\u6295\u3052\u3089\u308C\u308B\u307E\u3067\u306E\u5168\u3066\u306E\u6642\
    \u9593\u306E\u4E2D\u3067\u306Emax\r\n\r\n\t\tval_t = \u305D\u306E\u533A\u9593\u306E\
    \u3001(\u4ECA\u306Emax,\u3053\u308C\u307E\u3067\u306Emax)\t\r\n\t\topr_t(l,m)\
    \ = (\u4ECA\u306Elazy,\u3053\u308C\u307E\u3067\u306Elazy\u306Emax)\r\n\r\n\t\t\
    \u30AF\u30A8\u30EA\u3092\u3042\u308B\u4E00\u5B9A\u306E\u5F62\u3067\u304B\u3051\
    \u3066\u3001\u7D50\u5408\u5F8B\u304C\u6210\u308A\u7ACB\u3064\u304B?\u304C\u91CD\
    \u8981\r\n\t\t\u4ECA\u56DE\u306F\u3053\u306E\u5F62\u3067\u6301\u3064\u3068\u5408\
    \u6210\u3067\u304D\u308B\r\n\t\t\u3068\u308A\u3042\u3048\u305A\u5FC5\u8981\u306A\
    \u3082\u306E\u3092\u6301\u3061\u3001\u7D50\u5408\u3067\u304D\u308B\u3088\u3046\
    \u306B\u8FFD\u52A0\u3067\u30C7\u30FC\u30BF\u3092\u6301\u3064\r\n\r\n\t*/\r\n\t\
    using ll = long long;\r\n\tconst static ll inf = 1e16;\r\n\tstruct val_t{\r\n\t\
    \tll x,y;\r\n\t\tval_t(){*this = e();}\r\n\t\tval_t(ll x,ll y):x(x),y(y){}\r\n\
    \r\n\t\tconst static val_t e(){\r\n\t\t\treturn val_t(-inf,-inf);\r\n\t\t}\r\n\
    \t\tval_t operator+(const val_t &r) const {\r\n\t\t\treturn val_t(max(x,r.x),max(y,r.y));\r\
    \n\t\t}\r\n//\t\tfriend ostream& operator<<(ostream& o,const val_t& d){return\
    \ o<<\"(\"<<d.x<<\" \"<<d.y<<\")\";}\r\n\t};\r\n\r\n\tstruct opr_t{\r\n\t\tll\
    \ l,m;\r\n\t\topr_t(){*this = e();}\r\n\t\topr_t(ll l,ll m):l(l),m(m){}\r\n\r\n\
    \t\tconst static opr_t e(){\r\n\t\t\treturn opr_t(0,-inf);\r\n\t\t}\r\n//\t\t\
    friend ostream& operator<<(ostream& o,const opr_t& d){return o<<d.x;}\r\n\t};\r\
    \n\r\n\tstatic opr_t getfg(const opr_t &f, const opr_t &g){\r\n\t\treturn opr_t(f.l+g.l,max(g.m,f.m+g.l));\r\
    \n\t}\r\n\tstatic void setg2fg(const opr_t &f, opr_t &g){\t//g -> fg\t\tf after\
    \ g\r\n\t\tg = getfg(f,g);\r\n\t}\r\n\tstatic val_t act(const opr_t &f, const\
    \ val_t &v,int k,int l,int r){\t//assign f.x -> sum = \r\n\t\treturn val_t(v.x+f.l,max(v.y,v.x+f.m));\r\
    \n\t}\r\n};\r\n\r\n\r\nstruct handler5{\r\n\t/*\r\n\t\tverified at AOJ/RUPC/17/day2/I.cpp\r\
    \n\t\t{0,1,2,..9} -> {0,1,2,..9}\u3078\u306E\u5199\u50CF\u304C\u533A\u9593\u306B\
    \u304B\u304B\u308B\u3001\u8CEA\u554F\u306F\u533A\u9593\u5185\u306Ei\u306E\u6570\
    \r\n\t\t\u5199\u50CF\u3060\u3057\u3001\u5408\u6210\u53EF\u80FD\u306A\u306E\u306F\
    \u3042\u305F\u308A\u307E\u3048\u3002\u7DF4\u7FD2\u306B\u3061\u3087\u3046\u3069\
    \u3088\u304B\u3063\u305F\r\n\t\tarray\u4F7F\u3063\u305F\u307B\u3046\u304C\u901F\
    \u304B\u3063\u305F\u304B\u3082\u306D\r\n\t\t\r\n\t*/\r\n\tstruct val_t{\r\n\t\t\
    int n[10];\r\n\t\tval_t(){*this = e();}\r\n\t\tval_t(vector<int> v){\r\n//\t\t\
    \tshow(v.size());\r\n\t\t\trep(i,10) n[i]=v[i];\r\n\t\t}\r\n\r\n\t\tconst static\
    \ val_t e(){\r\n\t\t\treturn val_t(vector<int>(10,0));\r\n\t\t}\r\n\t\tval_t operator+(const\
    \ val_t &r) const {\r\n\t\t\tvector<int> v(10);\r\n\t\t\trep(i,10) v[i] = n[i]+r.n[i];\r\
    \n\t\t\treturn val_t(v);\r\n\t\t}\r\n\t};\r\n\tstruct opr_t{\r\n\t\tint f[10];\r\
    \n\t\topr_t(){*this = e();}\r\n\t\topr_t(vector<int> v){\r\n//\t\t\tshow(v.size());\r\
    \n\t\t\trep(i,10) f[i]=v[i];\r\n\t\t}\r\n\t\tconst static opr_t e(){\r\n\t\t\t\
    vector<int> vc(10);\r\n\t\t\trep(i,10) vc[i]=i;\r\n\t\t\treturn opr_t(vc);\r\n\
    \t\t}\r\n\t};\r\n\tstatic opr_t getfg(const opr_t &f, const opr_t &g){\r\n\t\t\
    vector<int> v(10);\r\n\t\trep(i,10) v[i] = f.f[g.f[i]];\r\n\t\treturn opr_t(v);\r\
    \n\t}\r\n\tstatic void setg2fg(const opr_t &f, opr_t &g){\r\n\t\tg = getfg(f,g);\r\
    \n\t}\r\n\tstatic val_t act(const opr_t &f, const val_t &v){\r\n\t\tvector<int>\
    \ x(10);\r\n\t\trep(i,10) x[f.f[i]]+=v.n[i];\r\n\t\treturn val_t(x);\r\n\t}\r\n\
    };\r\n/*\r\nfortune_telling\r\nAB\r\n*/\r\n\r\nvoid unittest(){\r\n\t{\r\n\t\t\
    using val_t = handler1::val_t;\r\n\t\tusing opr_t = handler1::opr_t;\r\n\t\tvector<val_t>\
    \ st = {1,2,3,4,5,6,7,8,9,0};\r\n\t\tsegtree_lazy<handler1> seg(st);\r\n\t\tint\
    \ N = st.size();\r\n\r\n\t\trep(qt,100){\r\n\t\t\tint l = rand()%N;\r\n\t\t\t\
    int r = rand()%N + 1;\r\n\t\t\tint t = rand()%2;\r\n\t\t\tif(t==0){\r\n\t\t\t\t\
    int x = rand()%10;\r\n\t\t\t\tseg.update(l,r,opr_t(x));\r\n\r\n\t\t\t\tfor(int\
    \ i = l;i<r;i++) st[i] = val_t(x);\r\n\r\n\t\t\t}else{\r\n\t\t\t\tval_t res;\r\
    \n\t\t\t\tfor(int i=l;i<r;i++) res = res + st[i];\r\n\t\t\t\tassert( seg.query(l,r).x\
    \ == res.x );\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n}\r\n\r\n\r\nint main(){\r\n\tunittest();\r\
    \n\tputs(\"OK\");\r\n}\n"
  code: "#include <bits/stdc++.h>\r\n#define rep(i,N) for(int i=0;i<(int)N;i++)\r\n\
    #define show(x) cout << #x << \" = \" << x << endl\r\nusing namespace std;\r\n\
    template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return\
    \ o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";}\r\ntemplate<class T> ostream& operator<<(ostream&\
    \ o,const vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"[\";for(const T& v:vc)\
    \ o<<v<<\",\";o<<\"]\";return o;}\r\n/*\r\n\u9045\u5EF6\u8A55\u4FA1segtree\r\n\
    \u30C7\u30FC\u30BF\u306E\u578B val_t \u3068\u64CD\u4F5C\u306E\u578B opr_t \u304C\
    \u3042\u308B\r\nopr_t \u306E\u7D50\u5408\u5F8B\u304C\u5FC5\u8981\r\n\r\n\u3044\
    \u308D\u3044\u308D\u67D4\u8EDF\u306B\u66F8\u304D\u63DB\u3048\u3066\u3044\u304F\
    \u5FC5\u8981\u304C\u3042\u308A\u305D\u3046(ex.propagate\u3067\u7B49\u5DEE\u6570\
    \u5217\u3092\u8DB3\u3059\u3068\u304D\u306Bopr_t\u578B\u3060\u3068\u53F3\u5074\u3067\
    \u306F\u521D\u9805\u304C\u305A\u308C\u308B,\u3053\u308C\u306B\u306Fl,r\u3082\u5FC5\
    \u8981)\r\n\u305D\u308C\u305E\u308C\u66F8\u304F\u3079\u304D\u306A\u306E\u306F\u3001\
    handler\u5185\u306E\r\n - val_t\u306Edef\u3068+\r\n - opr_t\u306Edef\r\n - getfg\
    \ (setg2fg)\r\n - act\r\n - \u5916\u5074\u306B\u304A\u3044\u3066\u3042\u308Bconst\
    \ static e \u306E\u5B9F\u4F53\r\n\r\n \u3042\u3068\u3001act\u306Bl,r\u3092\u6E21\
    \u3059\u5FC5\u8981\u304C\u3042\u308B\u3068\u304B\u305D\u3046\u3044\u3063\u305F\
    \u3053\u3068\u3067\u5185\u5074\u3092\u66F8\u304D\u63DB\u3048\u308B(\u5F15\u6570\
    \u5897\u3084\u3059\u3060\u3051)\r\n\r\n2018/07/11\u5909\u66F4\r\n\tlazy\u304B\u3051\
    \u308B\u30BF\u30A4\u30DF\u30F3\u30B0\u3067val\u3082\u5909\u66F4\u3055\u305B\u3061\
    \u3083\u3063\u305F\u307B\u3046\u304C\u826F\u3055\u305D\u3046\u306A\u306E\u3067\
    \u5B9F\u88C5\u3092\u5909\u3048\u305F, unittest\u306F\u901A\u3063\u305F\r\n*/\r\
    \ntemplate<class Handler>\r\nstruct segtree_lazy{\r\n\tusing val_t = typename\
    \ Handler::val_t;\r\n\tusing opr_t = typename Handler::opr_t;\r\n\tint N;\r\n\t\
    vector<val_t> val;\r\n\tvector<opr_t> lazy;\r\n\tsegtree_lazy(){}\r\n\tsegtree_lazy(int\
    \ n){init(n);}\r\n\tsegtree_lazy(const vector<val_t>& vc){init(vc);}\r\n\tvoid\
    \ init(int n){\r\n\t\tN=1;\r\n\t\twhile(N<n) N*=2;\r\n\t\tval .assign(N*2,val_t::e());\r\
    \n\t\tlazy.assign(N*2,opr_t::e());\r\n\t}\r\n\tvoid init(const vector<val_t>&\
    \ vc){\r\n\t\tint n = vc.size();\r\n\t\tN=1;\r\n\t\twhile(N<n) N*=2;\r\n\t\tval\
    \ .assign(N*2,val_t::e());\r\n\t\trep(i,n) val[i+N] = vc[i];\r\n\t\tfor(int i=N-1;i>0;i--)\
    \ val[i] = val[i*2] + val[i*2+1];\r\n\t\tlazy.assign(N*2,opr_t::e());\r\n\t}\r\
    \n\r\n\tval_t query(int a,int b,int l=0,int r=-1,int k=1){\t//query_calc\r\n\t\
    \tif(r==-1) r=N;\r\n\t\tif(b<=l||r<=a) return val_t::e();\r\n\t\tif(a<=l&&r<=b)\
    \ return val[k];\r\n\t\tpropagate(l,r,k);\r\n\t\treturn query(a,b,l,(l+r)/2,k*2)\
    \ + query(a,b,(l+r)/2,r,k*2+1);\r\n\t}\r\n\tvoid addlazy(int k,const opr_t &f){\r\
    \n\t\tHandler::setg2fg(f,lazy[k]);\r\n\t\tval[k] = Handler::act(f,val[k]);\r\n\
    \t}\r\n\r\n\tvoid update(int a,int b,const opr_t &f,int l=0,int r=-1,int k=1){\t\
    //query_update\r\n\t\tif(r==-1) r=N;\r\n\t\tif(b<=l||r<=a) return;\r\n\t\tif(a<=l&&r<=b){\r\
    \n\t\t\taddlazy(k,f);\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tpropagate(l,r,k);\r\n\t\
    \tupdate(a,b,f,l,(l+r)/2,k*2);\r\n\t\tupdate(a,b,f,(l+r)/2,r,k*2+1);\r\n\t\tval[k]\
    \ = val[k*2] + val[k*2+1];\r\n\t}\r\n\tvoid propagate(int l,int r,int k){\t//opr_child\
    \ -> opr_parent * opr_child\t\tparent after child\r\n\t\taddlazy(k*2  ,lazy[k]);\r\
    \n\t\taddlazy(k*2+1,lazy[k]);\r\n\t\tlazy[k] = opr_t::e();\r\n\t}\r\n};\r\n\r\n\
    struct handler1{\r\n\t/*\r\n\t\trange assign 0\u4EE5\u4E0A\r\n\t\trange max\r\n\
    \r\n\t\tval_t = int,max\t\t\tval[k]=max\r\n\t\topr_t(x) : y -> x\t\tlazy[k]=assign\r\
    \n\r\n\t\t\u4ECA\u56DE\u306E\u5834\u5408opr_t::e\u306F\u306A\u3044(assign\u306B\
    \u5358\u4F4D\u5143\u306F\u306A\u3044)\r\n\t\t\u3053\u306E\u3088\u3046\u306A\u3068\
    \u304D\u306F\u3001\u9069\u5F53\u306A\u5024\u3092\u5358\u4F4D\u5143\u306B\u8A2D\
    \u5B9A\u306B\u3057\u3066\u304A\u304D\u3001getfg/setg2fg/ act!! \u3067\u5408\u6210\
    \u3057\u306A\u3044\u3088\u3046\u51E6\u7406\u3057\u3066\u304A\u3051\u3070\u826F\
    \u3044\r\n\t\t\u8003\u3048\u306B\u304F\u3044\u3051\u3069val_t\u3082\u540C\u69D8\
    .\r\n\t\t\u6700\u60AAoption\u578B\u307F\u305F\u3044\u306Bbool\u5024\u3092\u3082\
    \u305F\u305B\u308C\u3070\u826F\u3055\u305D\u3046\r\n\t*/\r\n\tstruct val_t{\r\n\
    \t\tint x;\r\n\t\tval_t(){*this = e();}\r\n\t\tval_t(int x):x(x){}\r\n\r\n\t\t\
    const static val_t e(){\r\n\t\t\treturn val_t(0);\r\n\t\t}\r\n\t\tval_t operator+(const\
    \ val_t &r) const {\r\n\t\t\treturn val_t(max(x,r.x));\r\n\t\t}\r\n\t\tfriend\
    \ ostream& operator<<(ostream& o,const val_t& d){return o<<d.x;}\r\n\t};\r\n\r\
    \n\tstruct opr_t{\r\n\t\tint x;\r\n\t\topr_t(){*this = e();}\r\n\t\topr_t(int\
    \ x):x(x){}\r\n\r\n\t\tconst static opr_t e(){\r\n\t\t\treturn opr_t(-1);\r\n\t\
    \t}\r\n\t\tfriend ostream& operator<<(ostream& o,const opr_t& d){return o<<d.x;}\r\
    \n\t};\r\n\r\n//\tstatic opr_t getfg(const opr_t &f, const opr_t &g){\r\n//\r\n\
    //\t}\r\n\t/*\r\n\t\t\u3082\u3057\u30B3\u30D4\u30FC\u30B3\u30B9\u30C8\u3068\u304B\
    \u304C\u6C17\u306B\u306A\u3063\u3066,\u3057\u304B\u3082\u697D\u306B\u66F8\u3051\
    \u308B\u306A\u3089setg2fg\u3092\u76F4\u63A5\u66F8\u304F\r\n\t\t\u305D\u3046\u3058\
    \u3083\u306A\u3044\u306A\u3089 g = getfg(f,g)\r\n\t*/\r\n\tstatic void setg2fg(const\
    \ opr_t &f, opr_t &g){\t//g -> fg\t\tf after g\r\n\t\tif(f.x != -1) g.x = f.x;\r\
    \n\t}\r\n\tstatic val_t act(const opr_t &f, const val_t &v){\t\t//max\u304Cv \u3063\
    \u3066\u3044\u3046\u72B6\u614B\u306E\u3068\u3053\u308D\u306Bf\u3092\u4F5C\u7528\
    \u3055\u305B\u308B\u3068max\u306F\u4F55\u306B\u306A\u308A\u307E\u3059\u304B?\r\
    \n\t\tif(f.x == -1) return v;\r\n\t\treturn val_t(f.x);\r\n\t}\r\n};\r\n\r\n\r\
    \nstruct handler2{\r\n\t/*\r\n\t\trange assign 0\u4EE5\u4E0A\r\n\t\trange sum\r\
    \n\r\n\t\tval_t = int,+\t\t\tval[k]= +\r\n\t\topr_t(x) : y -> x\t\tlazy[k]=assign\r\
    \n\r\n\t\tassign\u306F\u4E00\u7DD2\u306A\u306E\u3067\u3001opr_t,getfg\u306F\u5909\
    \u3048\u306A\u304F\u3066\u3044\u3044\r\n\t\t\u6C17\u3065\u3044\u305F\u3093\u3067\
    \u3059\u304C,act\u3068\u304B\u306Bl,r\u304C\u5FC5\u8981\u306A\u30B1\u30FC\u30B9\
    \u304C\u591A\u3059\u304E\u308B(sum\u7CFB\u3068\u304B\u307B\u307C\u78BA\u5B9F\u306B\
    \u5FC5\u8981)\u306E\u3067\u3001\u3082\u3046\u3053\u3046\u3044\u3046\u306E\u306F\
    val_t\u306Bl,r\u3092\u7F6E\u304F\u3053\u3068\u306B\u3057\u307E\u3059\r\n\t\t\u3068\
    \u601D\u3063\u305F\u304C\u3001\u3084\u3063\u3071\u308A\u3084\u3081\u3066\u3001\
    l\u3068r\u3092\u9811\u5F35\u3063\u3066act\u306B\u6E21\u3059\u3053\u3068\u306B\u3057\
    \u305F\r\n\t\tgetfg\u3068\u304B\u306B\u3082\u5FC5\u8981\u306B\u306A\u308B\u3068\
    \u7D76\u671B\u611F\u304C\u5897\u3057\u305D\u3046\r\n\r\n\t*/\r\n\tstruct val_t{\r\
    \n\t\tint x;\r\n\t\tval_t(){*this = e();}\r\n\t\tval_t(int x):x(x){}\r\n\r\n\t\
    \tconst static val_t e(){\r\n\t\t\treturn val_t(0);\r\n\t\t}\r\n\t\tval_t operator+(const\
    \ val_t &r) const {\r\n\t\t\treturn val_t(x+r.x);\r\n\t\t}\r\n\t\tfriend ostream&\
    \ operator<<(ostream& o,const val_t& d){return o<<d.x;}\r\n\t};\r\n\r\n\tstruct\
    \ opr_t{\r\n\t\tint x;\r\n\t\topr_t(){*this = e();}\r\n\t\topr_t(int x):x(x){}\r\
    \n\r\n\t\tconst static opr_t e(){\r\n\t\t\treturn opr_t(-1);\r\n\t\t}\r\n\t\t\
    friend ostream& operator<<(ostream& o,const opr_t& d){return o<<d.x;}\r\n\t};\r\
    \n\r\n\tstatic void getfg(const opr_t &f, const opr_t &g){\r\n\t\t\r\n\t}\r\n\t\
    /*\r\n\t\t\u3082\u3057\u30B3\u30D4\u30FC\u30B3\u30B9\u30C8\u3068\u304B\u304C\u6C17\
    \u306B\u306A\u3063\u3066,\u3057\u304B\u3082\u697D\u306B\u66F8\u3051\u308B\u306A\
    \u3089setg2fg\u3092\u76F4\u63A5\u66F8\u304F\r\n\t\t\u305D\u3046\u3058\u3083\u306A\
    \u3044\u306A\u3089 g = getfg(f,g)\r\n\t*/\r\n\tstatic void setg2fg(const opr_t\
    \ &f, opr_t &g){\t//g -> fg\t\tf after g\r\n\t\tif(f.x != -1) g.x = f.x;\r\n\t\
    }\r\n\tstatic val_t act(const opr_t &f, const val_t &v,int k,int l,int r){\t//assign\
    \ f.x -> sum = \r\n\t\tif(f.x == -1) return v;\r\n\t\treturn val_t(f.x*(r-l));\r\
    \n\t}\r\n};\r\n\r\n\r\nstruct handler3{\r\n\tusing ll = long long;\r\n\t/*\r\n\
    \t\trange assign\r\n\t\trange add\r\n\t\tpoint val\r\n\r\n\t\tval_t = int\r\n\t\
    \topr_t(x) : assign x or add y\r\n\r\n\t\t(assign x)(assign y) = (assign x)\r\n\
    \t\t(assign x)(add y) = (assign x)\r\n\t\t(add x)(assign y) = (assign y+x)\r\n\
    \t\t(add x)(add y) = (add x+y)\r\n\t\t(assign or add)\u304C\u9589\u3058\u3066\u3044\
    \u308B\u306E\u3067\u3001\u3053\u306E\u5F62\u3092opr_t\u3068\u3057\u3066\u6301\u3066\
    \u3070\u826F\u3044.\r\n\t\t\u533A\u9593get\u304C\u306A\u3044\u3068\u304B\u306A\
    \u308A\u8003\u3048\u3084\u3059\u3044\u306A\u3042\r\n\t\t\u3068\u3044\u3046\u304B\
    \u3001val_t\u540C\u58EB\u306E\u6F14\u7B97\u304C\u3044\u3089\u306A\u304F\u3066\u3001\
    opr_t\u3060\u3051\u3067\u3067\u304D\u3066\u308B\u306A\u3053\u308C\r\n\t\t\u3068\
    \u306F\u3044\u3048\u3068\u308A\u3042\u3048\u305A\u7528\u610F\u3057\u3066\u308B\
    (\u5358\u4F4D\u5143\u3068\u306E\u5408\u6210\u306F\u884C\u308F\u308C\u308B)\u306E\
    \u3067\u3001\u77DB\u76FE\u304C\u306A\u3044\u3088\u3046\u306B\u3057\u306A\u3044\
    \u3068\u307E\u305A\u3044(\u306E\u3067+\u3068e=0\u306B\u3057\u305F)\r\n\t\tverified\
    \ at atcoder/dwango2015/qual/E_lazy.cpp \u82B1\u706B\r\n\r\n\t*/\r\n\tstruct val_t{\r\
    \n\t\tll x;\r\n\t\tval_t(){*this = e();}\r\n\t\tval_t(ll x):x(x){}\r\n\r\n\t\t\
    const static val_t e(){\r\n\t\t\treturn val_t(0);\r\n\t\t}\r\n\t\tval_t operator+(const\
    \ val_t &r) const {\r\n\t\t\treturn val_t(x+r.x);\r\n\t\t}\r\n\t\tfriend ostream&\
    \ operator<<(ostream& o,const val_t& d){return o<<d.x;}\r\n\t};\r\n\r\n\tstruct\
    \ opr_t{\r\n\t\tbool is_add;\r\n\t\tll x;\r\n\t\topr_t(){*this = e();}\r\n\t\t\
    opr_t(bool b,ll x):is_add(b),x(x){}\r\n\r\n\t\tconst static opr_t e(){\r\n\t\t\
    \treturn opr_t(true,0);\t//add 0\r\n\t\t}\r\n\t\tfriend ostream& operator<<(ostream&\
    \ o,const opr_t& d){return o<<(d.is_add?\"add\":\"assign\")<<\" \"<<d.x;}\r\n\t\
    };\r\n\r\n\tstatic opr_t getfg(const opr_t &f, const opr_t &g){\r\n\t\tif(f.is_add){\r\
    \n\t\t\tif(g.is_add) return opr_t(true,f.x+g.x);\r\n\t\t\telse return opr_t(false,f.x+g.x);\r\
    \n\t\t}else{\r\n\t\t\treturn f;\r\n\t\t}\r\n\t}\r\n\tstatic void setg2fg(const\
    \ opr_t &f, opr_t &g){\t//g -> fg\t\tf after g\r\n\t\tg = getfg(f,g);\r\n\t}\r\
    \n\tstatic val_t act(const opr_t &f, const val_t &v,int k,int l,int r){\t//assign\
    \ f.x -> sum = \r\n\t\tif(f.is_add) return val_t(v+f.x);\r\n\t\telse return val_t(f.x);\r\
    \n\t}\r\n};\r\n\r\nstruct handler4{\r\n\t/*\r\n\t\tOpenCup/3192/E.cpp\r\n\t\t\
    range add\r\n\t\trange max \u305F\u3060\u3057\u3001\u3053\u306E\u30AF\u30A8\u30EA\
    \u304C\u6295\u3052\u3089\u308C\u308B\u307E\u3067\u306E\u5168\u3066\u306E\u6642\
    \u9593\u306E\u4E2D\u3067\u306Emax\r\n\r\n\t\tval_t = \u305D\u306E\u533A\u9593\u306E\
    \u3001(\u4ECA\u306Emax,\u3053\u308C\u307E\u3067\u306Emax)\t\r\n\t\topr_t(l,m)\
    \ = (\u4ECA\u306Elazy,\u3053\u308C\u307E\u3067\u306Elazy\u306Emax)\r\n\r\n\t\t\
    \u30AF\u30A8\u30EA\u3092\u3042\u308B\u4E00\u5B9A\u306E\u5F62\u3067\u304B\u3051\
    \u3066\u3001\u7D50\u5408\u5F8B\u304C\u6210\u308A\u7ACB\u3064\u304B?\u304C\u91CD\
    \u8981\r\n\t\t\u4ECA\u56DE\u306F\u3053\u306E\u5F62\u3067\u6301\u3064\u3068\u5408\
    \u6210\u3067\u304D\u308B\r\n\t\t\u3068\u308A\u3042\u3048\u305A\u5FC5\u8981\u306A\
    \u3082\u306E\u3092\u6301\u3061\u3001\u7D50\u5408\u3067\u304D\u308B\u3088\u3046\
    \u306B\u8FFD\u52A0\u3067\u30C7\u30FC\u30BF\u3092\u6301\u3064\r\n\r\n\t*/\r\n\t\
    using ll = long long;\r\n\tconst static ll inf = 1e16;\r\n\tstruct val_t{\r\n\t\
    \tll x,y;\r\n\t\tval_t(){*this = e();}\r\n\t\tval_t(ll x,ll y):x(x),y(y){}\r\n\
    \r\n\t\tconst static val_t e(){\r\n\t\t\treturn val_t(-inf,-inf);\r\n\t\t}\r\n\
    \t\tval_t operator+(const val_t &r) const {\r\n\t\t\treturn val_t(max(x,r.x),max(y,r.y));\r\
    \n\t\t}\r\n//\t\tfriend ostream& operator<<(ostream& o,const val_t& d){return\
    \ o<<\"(\"<<d.x<<\" \"<<d.y<<\")\";}\r\n\t};\r\n\r\n\tstruct opr_t{\r\n\t\tll\
    \ l,m;\r\n\t\topr_t(){*this = e();}\r\n\t\topr_t(ll l,ll m):l(l),m(m){}\r\n\r\n\
    \t\tconst static opr_t e(){\r\n\t\t\treturn opr_t(0,-inf);\r\n\t\t}\r\n//\t\t\
    friend ostream& operator<<(ostream& o,const opr_t& d){return o<<d.x;}\r\n\t};\r\
    \n\r\n\tstatic opr_t getfg(const opr_t &f, const opr_t &g){\r\n\t\treturn opr_t(f.l+g.l,max(g.m,f.m+g.l));\r\
    \n\t}\r\n\tstatic void setg2fg(const opr_t &f, opr_t &g){\t//g -> fg\t\tf after\
    \ g\r\n\t\tg = getfg(f,g);\r\n\t}\r\n\tstatic val_t act(const opr_t &f, const\
    \ val_t &v,int k,int l,int r){\t//assign f.x -> sum = \r\n\t\treturn val_t(v.x+f.l,max(v.y,v.x+f.m));\r\
    \n\t}\r\n};\r\n\r\n\r\nstruct handler5{\r\n\t/*\r\n\t\tverified at AOJ/RUPC/17/day2/I.cpp\r\
    \n\t\t{0,1,2,..9} -> {0,1,2,..9}\u3078\u306E\u5199\u50CF\u304C\u533A\u9593\u306B\
    \u304B\u304B\u308B\u3001\u8CEA\u554F\u306F\u533A\u9593\u5185\u306Ei\u306E\u6570\
    \r\n\t\t\u5199\u50CF\u3060\u3057\u3001\u5408\u6210\u53EF\u80FD\u306A\u306E\u306F\
    \u3042\u305F\u308A\u307E\u3048\u3002\u7DF4\u7FD2\u306B\u3061\u3087\u3046\u3069\
    \u3088\u304B\u3063\u305F\r\n\t\tarray\u4F7F\u3063\u305F\u307B\u3046\u304C\u901F\
    \u304B\u3063\u305F\u304B\u3082\u306D\r\n\t\t\r\n\t*/\r\n\tstruct val_t{\r\n\t\t\
    int n[10];\r\n\t\tval_t(){*this = e();}\r\n\t\tval_t(vector<int> v){\r\n//\t\t\
    \tshow(v.size());\r\n\t\t\trep(i,10) n[i]=v[i];\r\n\t\t}\r\n\r\n\t\tconst static\
    \ val_t e(){\r\n\t\t\treturn val_t(vector<int>(10,0));\r\n\t\t}\r\n\t\tval_t operator+(const\
    \ val_t &r) const {\r\n\t\t\tvector<int> v(10);\r\n\t\t\trep(i,10) v[i] = n[i]+r.n[i];\r\
    \n\t\t\treturn val_t(v);\r\n\t\t}\r\n\t};\r\n\tstruct opr_t{\r\n\t\tint f[10];\r\
    \n\t\topr_t(){*this = e();}\r\n\t\topr_t(vector<int> v){\r\n//\t\t\tshow(v.size());\r\
    \n\t\t\trep(i,10) f[i]=v[i];\r\n\t\t}\r\n\t\tconst static opr_t e(){\r\n\t\t\t\
    vector<int> vc(10);\r\n\t\t\trep(i,10) vc[i]=i;\r\n\t\t\treturn opr_t(vc);\r\n\
    \t\t}\r\n\t};\r\n\tstatic opr_t getfg(const opr_t &f, const opr_t &g){\r\n\t\t\
    vector<int> v(10);\r\n\t\trep(i,10) v[i] = f.f[g.f[i]];\r\n\t\treturn opr_t(v);\r\
    \n\t}\r\n\tstatic void setg2fg(const opr_t &f, opr_t &g){\r\n\t\tg = getfg(f,g);\r\
    \n\t}\r\n\tstatic val_t act(const opr_t &f, const val_t &v){\r\n\t\tvector<int>\
    \ x(10);\r\n\t\trep(i,10) x[f.f[i]]+=v.n[i];\r\n\t\treturn val_t(x);\r\n\t}\r\n\
    };\r\n/*\r\nfortune_telling\r\nAB\r\n*/\r\n\r\nvoid unittest(){\r\n\t{\r\n\t\t\
    using val_t = handler1::val_t;\r\n\t\tusing opr_t = handler1::opr_t;\r\n\t\tvector<val_t>\
    \ st = {1,2,3,4,5,6,7,8,9,0};\r\n\t\tsegtree_lazy<handler1> seg(st);\r\n\t\tint\
    \ N = st.size();\r\n\r\n\t\trep(qt,100){\r\n\t\t\tint l = rand()%N;\r\n\t\t\t\
    int r = rand()%N + 1;\r\n\t\t\tint t = rand()%2;\r\n\t\t\tif(t==0){\r\n\t\t\t\t\
    int x = rand()%10;\r\n\t\t\t\tseg.update(l,r,opr_t(x));\r\n\r\n\t\t\t\tfor(int\
    \ i = l;i<r;i++) st[i] = val_t(x);\r\n\r\n\t\t\t}else{\r\n\t\t\t\tval_t res;\r\
    \n\t\t\t\tfor(int i=l;i<r;i++) res = res + st[i];\r\n\t\t\t\tassert( seg.query(l,r).x\
    \ == res.x );\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n}\r\n\r\n\r\nint main(){\r\n\tunittest();\r\
    \n\tputs(\"OK\");\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: data structure/segtree/segtree_lazy.cpp
  requiredBy: []
  timestamp: '2018-07-11 23:02:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/segtree/segtree_lazy.cpp
layout: document
redirect_from:
- /library/data structure/segtree/segtree_lazy.cpp
- /library/data structure/segtree/segtree_lazy.cpp.html
title: data structure/segtree/segtree_lazy.cpp
---
