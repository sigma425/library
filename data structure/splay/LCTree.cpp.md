---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1675225
    - http://yosupo.hatenablog.com/entry/2014/12/26/001414
    - https://github.com/yosupo06/Algorithm/blob/master/datastructure/linkcuttree.h#L36
    - https://www.slideshare.net/iwiwi/2-12188845
  bundledCode: "#line 1 \"data structure/splay/LCTree.cpp\"\n/*\r\n\tLink Cut Tree\r\
    \n\t\u6839\u4ED8\u304D\u68EE\u3092\u6271\u3046\u30C7\u30FC\u30BF\u69CB\u9020\r\
    \n\t\r\n\t\u4F7F\u3044\u65B9\r\n\t\tpath\u306B\u5BFE\u3059\u308B query,lazy query\r\
    \n\t\tlink : v(\u89AA\u306A\u3057) \u306E\u89AA\u3092 p \u306B\u8A2D\u5B9A\u3059\
    \u308B\r\n\t\tcut : v \u3092 \u89AA\u304B\u3089\u5207\u308A\u96E2\u3059\r\n\t\t\
    evert: \u6839\u3092\u5909\u66F4\u3059\u308B\r\n\t\t\u3053\u308C\u3089\u304C\u5168\
    \u3066 O(log N) \u3067\u53EF\u80FD.\r\n\r\n\t\t\u5916\u5074\u3067\u306F\u5404\u9802\
    \u70B9v\u306B\u5BFE\u3057\u3066, NP n[v] \u3092\u6301\u3064(\u5916\u3067\u3053\
    \u308C\u3092\u3044\u3058\u308B\u5FC5\u8981\u306F\u306A\u3044)\r\n\t\t\u9006\u306B\
    \u5185\u5074\u3067 NP \u304B\u3089 v \u3092\u5FA9\u5143\u3057\u305F\u3044\u3068\
    \u304D\u306FHandler\u306B\u9802\u70B9\u3092\u8FFD\u52A0\u3057\u3066\u304A\u3051\
    \u3070\u826F\u3044?\r\n\r\n\t\t\u3088\u308A\u5909\u306A\u64CD\u4F5C(v-u\u9593\
    rotate)\u3068\u304B\u306B\u306A\u3063\u305F\u3089splay(int k) \u3068\u304B\u3092\
    splay_lazy \u304B\u3089\u6301\u3063\u3066\u304F\u308B\u5FC5\u8981\u304C\u3042\u308A\
    \u305D\u3046\r\n\r\n\r\n\t\u52D5\u4F5C\u539F\u7406?\r\n\t\t\u52D5\u7684 HL decomposition\
    \ \u307F\u305F\u3044\u306A\u96F0\u56F2\u6C17\r\n\t\t\u5404path\u3092splay tree\
    \ \u3067\u8868\u73FE\u3059\u308B\u3001\u6839\u306B\u8FD1\u3044\u65B9\u304Cleft\r\
    \n\t\texpose(v): (\u6839\u4ED8\u304D\u6728\u3067\u306E)v\u304B\u3089root\u3092\
    \u4E00\u3064\u306Epath\u306B\u3059\u308B, \u3064\u3044\u3067\u306Bv\u3092\u305D\
    \u306E\"splay\u6728\u306E\"\u6839\u306B\u3059\u308B)\r\n\t\t\t\u3053\u308C\u306B\
    \u542B\u307E\u308C\u308BHLdecomp\u306E\u5404path\u3067\u306F\u3042\u308B\u70B9\
    \u304B\u3089\u4E0A\u5168\u3066\u3092\u898B\u308B\u3053\u3068\u306B\u306A\u308B\
    \u306E\u3067\u3001\r\n\t\t\tsplay\u306E\u8A00\u8449\u3067\u3044\u3046\u3068left\
    \ child \u3092\u6B8B\u3059\r\n\t\t\tv-root\u9593\u304Cv\u3092\u6839\u3068\u3059\
    \u308B\u4E00\u3064\u306Esplay\u306B\u306A\u308B\u306E\u3067\u3001\u4F55\u3082\u8003\
    \u3048\u305A\u306Bv\u306B\u30AF\u30A8\u30EA\u98DB\u3070\u305B\u3070\u3044\u3044\
    \r\n\t\tevert(v): (\u6839\u4ED8\u304D\u6728\u3067\u306E)root\u3092v\u306B\u5909\
    \u3048\u308B\r\n\t\t\texpose\u3057\u305F\u3042\u3068\u306Fsplay\u7684\u306B\u306F\
    reverse\u306B\u5BFE\u5FDC\u3059\u308B\r\n\r\n\t\tsm\u3068\u304B\u306F\u5404splay\u5185\
    \u3067\u5B8C\u7D50\u3057\u3066\u3044\u308B\u3053\u3068\u306B\u6CE8\u610F!\r\n\t\
    \t\u4F8B\u3048\u3070\u3001link\u3067 p = r \u3068\u3057\u305F\u3068\u304D\u306B\
    \ r->update() \u3057\u306A\u304F\u3066\u3044\u3044\u306E\u306F\u3001\u3053\u308C\
    \u304C splay tree \u306E edge \u3067\u306F\u306A\u3044\u304B\u3089\r\n\r\n\t\u53C2\
    \u8003\r\n\t\thttp://yosupo.hatenablog.com/entry/2014/12/26/001414 (\u53E4\u3044\
    \u306E\u3067rev\u306E\u6301\u3061\u65B9\u3068\u304B\u5FAE\u5999)\r\n\t\thttp://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1675225\
    \ (\u307F\u3058\u304B\u3044)\r\n\t\thttps://github.com/yosupo06/Algorithm/blob/master/datastructure/linkcuttree.h#L36\
    \ (\u304B\u306A\u308A\u4FE1\u983C\u3067\u304D\u308B)\r\n\t\thttps://www.slideshare.net/iwiwi/2-12188845\
    \ (iwiwi\u3055\u3093\u306E\u3044\u3064\u3082\u306E\u3084\u3064)\r\n\r\n\tverified\r\
    \n\t\tdo use segment tree\r\n\t\t\t\u30D0\u30B0\u3089\u305B\u305F\u3068\u3053\
    : act\u306E\u6642\u9577\u3055\u304C\u5F15\u6570\u306B\u3044\u308B, \u5F15\u6570\
    \u306Fsm\u306Fsz\u3067\u3044\u3044\u3051\u3069v\u306F1\r\n\t\tspaceships\r\n\t\
    \t\tlca\u306Everify\u306B\u306A\u3063\u305F\u306D\r\n*/\r\n#include <bits/stdc++.h>\r\
    \n#define rep(i,n) for(int i=0;i<(int)(n);i++)\r\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\r\
    \n#define all(c) c.begin(),c.end()\r\n#define pb push_back\r\n#define fs first\r\
    \n#define sc second\r\n#define show(x) cout << #x << \" = \" << x << endl\r\n\
    #define chmin(x,y) x=min(x,y)\r\n#define chmax(x,y) x=max(x,y)\r\nusing namespace\
    \ std;\r\n\r\ntemplate<class Handler>\r\nstruct LCNode{\r\n\tusing NP = LCNode*;\r\
    \n\tstatic NP nil;\r\n\r\n\tusing D = typename Handler::val_t;\t//data\r\n\tusing\
    \ A = typename Handler::opr_t;\t//action\r\n\r\n\r\n\tNP p,l,r;\r\n\tint sz;\r\
    \n\tD v,sm;\r\n\tA lz;\r\n\tbool rev;\r\n\tLCNode(D v,A a) :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v),lz(a),rev(false){}\r\
    \n\tLCNode(D v) :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v),lz(A::e()),rev(false){}\r\
    \n\tLCNode() : p(nullptr),l(nullptr),r(nullptr),sz(0),v(D::e()),sm(D::e()),lz(A::e()),rev(false){}\r\
    \n\r\n\tint pos(){\t\t\t//\u89AA\u306E\u5DE6\u306E\u5B50\u304B,\u53F3\u306E\u5B50\
    \u304B,\u305D\u308C\u3068\u3082\u6839(or nil)\u304B\r\n\t\tif(p&&p->l == this)\
    \ return -1;\r\n\t\tif(p&&p->r == this) return 1;\r\n\t\treturn 0;\r\n\t}\r\n\t\
    void rot(){\t\t\t\t//root\u3067\u547C\u3076\u3068\u6B7B\r\n\t\tassert(p != nullptr);\r\
    \n\t\tNP pp=p->p;\r\n\t\tint pps=p->pos();\r\n\t\tif(p->l==this){\r\n\t\t\tp->l=r,r->p=p,r=p,p->p=this;\r\
    \n\t\t}else{\r\n\t\t\tp->r=l,l->p=p,l=p,p->p=this;\r\n\t\t}\r\n\t\tp->update();\r\
    \n\t\tupdate();//\tzig,zig-zag,zig-zig\u3068\u3082\u306B\u3069\u3046\u305B\u6B21\
    \u3067update\u304C\u3088\u3070\u308C\u308B\u306E\u3067\u3044\u3089\u306A\u3044\
    (\u6700\u5F8C\u6839\u306F\u3044\u308B\u2190\u3053\u308C\u5B9F\u306Fmerge/split\u3067\
    \u3061\u3083\u3093\u3068update\u3057\u3066\u308B\u304B\u3089\u66F8\u304B\u306A\
    \u304F\u3066\u3044\u3044\u3093\u3060\u3088\u306D)\r\n\t\tp=pp;\r\n\t\tif(pps==0)\
    \ return;\r\n\t\tif(pps==-1) pp->l=this;\r\n\t\telse pp->r=this;\r\n\t\tif(pp->sz)\
    \ pp->update();\t//\u3053\u308C\u3082\u3044\u3089\u3093\u304B\u3082\r\n\t}\r\n\
    \tvoid splay(){\t\t\t//this\u3092root\u306B\u3082\u3063\u3066\u304F\u308B\r\n\t\
    \tpushdown();\r\n\t\twhile(true){\r\n\t\t\tint ps=pos();\r\n\t\t\tif(ps==0) break;\r\
    \n\t\t\tint pps=p->pos();\r\n\t\t\tif(pps==0){\t\t//zig\r\n\t\t\t\trot();\r\n\t\
    \t\t}else if(ps==pps){\t\t//zigzig\r\n\t\t\t\tp->rot();rot();\r\n\t\t\t}else{\t\
    \t\t\t\t//zigzag\r\n\t\t\t\trot();rot();\r\n\t\t\t}\r\n\t\t}\r\n\t\tupdate();\t\
    \t\t//merge/split\u4EE5\u5916\u304B\u3089\u547C\u3070\u308C\u308B\u304B\u3082\u3057\
    \u308C\u306A\u3044\u306E\u3067\u4E00\u5FDC\u3064\u3051\u3066\u304A\u304F\r\n\t\
    }\r\n\t/*\r\n\t\texpose\r\n\t\t\u6839\u4ED8\u304D\u6728\u306B\u304A\u3044\u3066\
    \u3001this\u304B\u3089r\u307E\u3067\u306Epath\u30921\u3064\u306Esplay tree\u306B\
    \u3059\u308B(\u4E0B\u306F\u3061\u3083\u3093\u3068\u5207\u308B)\r\n\t\t\u3064\u3044\
    \u3067\u306Bthis\u3092(splay tree \u306E\u610F\u5473\u3067)root\u306B\u6301\u3063\
    \u3066\u304F\u308B\r\n\t\t\u5B9F\u969B\u306E\u6728\u306E\u6839\u3092\u5909\u3048\
    \u308Bevert\u3068\u306F\u9055\u3046\u306E\u3067\u6CE8\u610F!\r\n\t*/\r\n\tvoid\
    \ expose(){\r\n\t\tNP v = this, vr = nil;\r\n\r\n\t\twhile(true){\r\n\t\t\tv->splay();\r\
    \n\t\t\tv->r = vr;\t//first: cut right\r\n\t\t\tv->update();\r\n\t\t\tvr = v;\t\
    \t//next vr\r\n\t\t\tv = v->p;\t//LinkCut\u306Eparent(\u5225\u306Esplaytree\u306B\
    \u79FB\u52D5\u3059\u308B)\r\n\t\t\tif(v==nullptr) break;\r\n\t\t}\r\n\t\tv = this;\r\
    \n\t\tv->r = nil;\t//cut\r\n\t\tv->update();\r\n\r\n\t\twhile(v->p){\r\n\t\t\t\
    v->p->r = v;\r\n\t\t\tv = v->p;\r\n\t\t\tv->update();\r\n\t\t}\r\n\t\tsplay();\r\
    \n\t}\r\n\tNP update(){\t\t//\u60C5\u5831\u66F4\u65B0(\u5B50\u304C\u6B63\u3057\
    \u3044\u6642\u306B\u547C\u3070\u306A\u3044\u3068\u30C0\u30E1) (\u6700\u5F8C\u306B\
    update\u3057\u3066return\u3059\u308B\u306E\u306B\u697D\u306A\u306E\u3067NP\u3092\
    \u8FD4\u3059)\r\n\t\tsz=1+l->sz+r->sz;\r\n\t\tsm = v;\r\n\t\tif(l->sz) sm = l->sm\
    \ + sm;\t//if(l) \u3060\u3068nil\u3067\u3082\u547C\u3076\u7FBD\u76EE\u306B\u306A\
    \u308A\u305D\u3046\r\n\t\tif(r->sz) sm = sm + r->sm;\r\n\t\treturn this;\r\n\t\
    }\r\n\t/*\r\n\t\treverse\r\n\r\n\t\trev\u3092\u6271\u3046\u3068\u304D\u306F\u5168\
    \u3066revdata()\u3092\u3088\u3076\u3001\u500B\u306E\u30BF\u30A4\u30DF\u30F3\u30B0\
    \u3067\u3082\u3046swap(l,r)\u3082\u3057\u3061\u3083\u3046\r\n\r\n\t\treverse\u6A5F\
    \u80FD\u306Flazy splay\u306E\u6A5F\u69CB\u306E\u5185\u5074\u3067\u6271\u3063\u3066\
    \u3082\u3044\u3044\u304B\u3068\u601D\u3063\u305F\u3051\u3069\u3001LCTree \u306E\
    \ Node \u306B\u5225\u306E\u60C5\u5831\u3068\u3057\u3066\u6301\u305F\u305B\u308B\
    \u3053\u3068\u306B\u3057\u305F\r\n\t\t1. \u4ECA\u6301\u3063\u3066\u308B data sm\
    \ (a+b+..+c) \u304B\u3089\u3001sm.reverse (c+..+b+a)\u304C\u7C21\u5358\u306B\u8A08\
    \u7B97\u3067\u304D\u308B\u5834\u5408\r\n\t\t\trevdata() \u306E\u4E2D\u306B\u305D\
    \u308C\u3092\u304B\u3051\u3070\u304A\u308F\u308A\r\n\t\t2. \u3067\u304D\u306A\u3044\
    \u5834\u5408\r\n\t\t\tsm \u3068 revsm (\u5FC5\u8981\u306A\u3089lz \u3082\u540C\
    \u69D8?) \u3092Node\u306B\u4E21\u65B9\u6301\u3063\u3066\u9811\u5F35\u308B\r\n\t\
    \t\t\u3068\u601D\u3063\u305F\u3051\u3069\u305D\u308C\u3088\u308A\u306FHandler\u306B\
    2\u3064\u6301\u305F\u305B\u305F\u307B\u3046\u304C\u697D\u305D\u3046\r\n\t\tlz\u3082\
    \u5909\u308F\u3063\u3061\u3083\u3046\u5834\u5408\u306B\u6839\u672C\u7684\u306B\
    \u5BFE\u5FDC\u3067\u304D\u3066\u306A\u3044\u6C17\u304C\u3057\u3066\u304D\u305F\
    \u3001\u666E\u901A\u305D\u3046\u306A\u3089\u3093\u3057\u3080\u305A\u305D\u3046\
    \u306A\u306E\u3067\u8AE6\u3081\r\n\r\n\t\t\u3061\u306A\u307F\u306Breverse\u306F\
    \u3001evert(\u6839\u5909\u66F4\u30AF\u30A8\u30EA)\u306E\u305F\u3081\u306B\u4F7F\
    \u3044\u307E\u3059\r\n\t\t(\u73FEroot - root \u9593\u306Epath\u306E\u5411\u304D\
    \u3060\u3051\u9006\u306B\u3059\u308B\u3068\u3044\u3046\u64CD\u4F5C\u306B\u306A\
    \u3063\u3066\u3001\u5404splay\u6728\u3067\u5DE6\u304C\u5143\u306E\u6839\u4ED8\u304D\
    \u6728\u3067\u306E\u4E0A\u306B\u5BFE\u5FDC\u3059\u308B\u3053\u3068\u3092\u601D\
    \u3044\u51FA\u3059\u3068)\r\n\t*/\r\n\tvoid revdata(){\r\n\t\trev ^= true;\r\n\
    \t\tswap(l,r);\r\n\t\tsm.revdata();\r\n\t}\r\n\tvoid addlazy(const A& f){\r\n\t\
    \tHandler::setg2fg(f,lz);\r\n\t\tv = Handler::act(f,v,1);\r\n\t\tsm = Handler::act(f,sm,sz);\r\
    \n\t}\r\n\tvoid push(){\r\n\t\tif(rev){\r\n\t\t\tif(l->sz) l->revdata();\r\n\t\
    \t\tif(r->sz) r->revdata();\r\n\t\t\trev = false;\r\n\t\t}\r\n\t\tif(l->sz) l->addlazy(lz);\r\
    \n\t\tif(r->sz) r->addlazy(lz);\r\n\t\tlz = A::e();\r\n\t}\r\n\tvoid pushdown(){\t\
    //from root to this\r\n\t\tif(pos()) p->pushdown();\r\n\t\tpush();\r\n\t}\r\n\r\
    \n\t/*\r\n\t\tlink:\r\n\t\t\tthis\u306B\u5BFE\u5FDC\u3059\u308B\u6839\u4ED8\u304D\
    \u6728\u306E\u9802\u70B9\u306E\u89AA \u3092 r\u306B\u5BFE\u5FDC\u3059\u308B\u6839\
    \u4ED8\u304D\u6728\u306E\u9802\u70B9 \u306B\u3059\u308B\r\n\t\t\t( \u3064\u307E\
    \u308A\u3001\u5916\u304B\u3089\u306Fn[v].link(n[r]) )\r\n\t*/\r\n\tvoid link(NP\
    \ r){\r\n\t\texpose();\r\n\t\tr->expose();\r\n\t\tp = r;\r\n\t}\r\n\t/*\r\n\t\t\
    cut:\r\n\t\t\tthis\u306B\u5BFE\u5FDC\u3059\u308B\u6839\u4ED8\u304D\u6728\u306E\
    \u9802\u70B9 \u3068 \u305D\u306E\u89AA \u3092\u5207\u308B\r\n\t\t\t( \u3064\u307E\
    \u308A\u3001\u5916\u304B\u3089\u306Fn[v].cut() )\r\n\t\t\tv\u306E\u89AA\u3063\u3066\
    \u306E\u306Fsplay\u3067\u3044\u3046\u3068expose(v)\u3057\u305F\u3042\u3068\u306E\
    v->l\r\n\t*/\r\n\tvoid cut(){\r\n\t\texpose();\r\n\t\tl->p = nullptr;\r\n\t\t\
    l = nil;\r\n\t\tupdate();\r\n\t}\r\n\tvoid evert(){\r\n\t\texpose();\r\n\t\trevdata();\r\
    \n\t}\r\n\r\n\t/*\r\n\t\tquery for [this, x] \r\n\t*/\r\n\tD query(NP x){\r\n\t\
    \tevert();\r\n\t\tx->expose();\r\n//\t\tx->showtree();puts(\"\");\r\n\t\treturn\
    \ x->sm;\r\n\t}\r\n\tvoid query_update(NP x,const A& f){\r\n\t\tevert();\r\n\t\
    \tx->expose();\r\n\t\tx->addlazy(f);\r\n\t}\r\n\r\n\t/*\r\n\t\tparent:\r\n\t\t\
    \texpose(v) \u3057\u305F\u3042\u3068\u306F\u4E00\u3064\u5DE6\u306B\u884C\u3063\
    \u3066\u305D\u3063\u304B\u3089\u53F3\u306B\u884C\u304D\u7D9A\u3051\u305F\u3068\
    \u3053\u308D\r\n\t\t\t\u3061\u3083\u3093\u3068\u30A2\u30AF\u30BB\u30B9\u3057\u305F\
    \u3089expose\u3057\u306A\u3044\u3068\u8A08\u7B97\u91CF\u58CA\u308C\u308B\u306E\
    \u3067\u6700\u5F8C\u306Bexpose\u3059\u308B\r\n\t*/\r\n\tNP parent(){\r\n\t\texpose();\r\
    \n\t\tNP v = this->l;\r\n\t\tif(v == nil) return nil;\r\n\t\twhile(v->r != nil){\r\
    \n\t\t\tv = v->r;\r\n\t\t}\r\n\t\tv->expose();\r\n\t\treturn v;\r\n\t}\r\n\r\n\
    \tNP root(){\r\n\t\texpose();\r\n\t\tNP v = this;\r\n\t\twhile(v->l != nil){\r\
    \n\t\t\tv = v->l;\r\n\t\t}\r\n\t\tv->expose();\r\n\t\treturn v;\r\n\t}\r\n\r\n\
    \tNP lca(NP x){\r\n\t\tx->expose();\r\n\t\texpose();\r\n\t\tNP w = x;\r\n\t\t\
    while(x->p != nullptr){\r\n\t\t\tif(!x->pos()) w = x->p;\r\n\t\t\tx = x->p;\r\n\
    \t\t}\r\n\t\treturn (this == x) ? w : nullptr;\r\n\t}\r\n\r\n\t/*\r\n\t\tthis\u304B\
    \u3089\u305D\u306Esplay\u6728\u5185\u3060\u3051\r\n\t*/\r\n\tvoid showtree(){\r\
    \n\t\tcout<<\" [ \";\r\n\t\tif(l->sz) l->showtree();\r\n\t\tcout<<v;\r\n\t\tif(r->sz)\
    \ r->showtree();\r\n\t\tcout<<\" ] \";\r\n\t}\r\n};\r\n\r\nusing ll = long long;\r\
    \nconst ll inf = 1e17;\r\n\r\nstruct handler{\r\n\t/*\r\n\t\trange assign\r\n\t\
    \trange subseqsummax\r\n\t*/\r\n\tstruct val_t{\r\n\t\tll sm,lmx,rmx,mx;\r\n\t\
    \tval_t(){*this = e();}\r\n\t\tval_t(ll x){\r\n\t\t\tsm = lmx = rmx = mx = x;\r\
    \n\t\t}\r\n\t\tval_t(ll sm,ll lmx,ll rmx,ll mx):sm(sm),lmx(lmx),rmx(rmx),mx(mx){}\r\
    \n\r\n\t\tconst static val_t e(){\r\n\t\t\treturn val_t(0,-inf,-inf,-inf);\r\n\
    \t\t}\r\n\t\tval_t operator+(const val_t &r) const {\r\n\t\t\treturn val_t(sm+r.sm,\
    \ max(lmx,sm+r.lmx), max(r.rmx,r.sm+rmx), max(max(mx,r.mx),rmx+r.lmx));\r\n\t\t\
    }\r\n\r\n\t\tvoid revdata(){\r\n\t\t\tswap(lmx,rmx);\r\n\t\t}\r\n\r\n\t\tfriend\
    \ ostream& operator<<(ostream& o,const val_t& d){return o<<d.sm;}\r\n\t};\r\n\r\
    \n\tstruct opr_t{\r\n\t\tll x;\r\n\t\topr_t(){*this = e();}\r\n\t\topr_t(ll x):x(x){}\r\
    \n\r\n\t\tconst static opr_t e(){\r\n\t\t\treturn opr_t(inf);\r\n\t\t}\r\n\t\t\
    friend ostream& operator<<(ostream& o,const opr_t& d){return o<<d.x;}\r\n\t};\r\
    \n\r\n\tstatic void setg2fg(const opr_t &f, opr_t &g){\t//g -> fg\t\tf after g\r\
    \n\t\tif(f.x != inf) g.x = f.x;\r\n\t}\r\n\tstatic val_t act(const opr_t &f, const\
    \ val_t &v,int len){\r\n\t\tif(f.x == inf) return v;\r\n\t\tll a = f.x*len;\r\n\
    \t\tll b = max(a,f.x);\r\n\t\treturn val_t(a,b,b,b);\r\n\t}\r\n};\r\ntemplate<>\r\
    \nLCNode<handler>::NP LCNode<handler>::nil = new LCNode();\r\n\r\n\r\nusing D\
    \ = handler::val_t;\r\nusing A = handler::opr_t;\r\nusing NP = LCNode<handler>*;\r\
    \n\r\nint N,Q;\r\nvector<vector<int>> G;\r\nvector<NP> tree;\r\n\r\nvoid dfs(int\
    \ v,int p=-1){\r\n\tif(p!=-1){\r\n\t\ttree[v]->link(tree[p]);\r\n\t}\r\n\tfor(int\
    \ u:G[v]) if(u!=p) dfs(u,v);\r\n}\r\n\r\nD query(int a,int b){\r\n\treturn tree[a]->query(tree[b]);\r\
    \n}\r\nvoid update(int a,int b,const A& f){\r\n\treturn tree[a]->query_update(tree[b],f);\r\
    \n}\r\n\r\nint main(){\r\n\tcin>>N>>Q;\r\n\tG.resize(N);\r\n\ttree.resize(N);\r\
    \n\trep(i,N){\r\n\t\tint w;\r\n\t\tcin>>w;\r\n\t\ttree[i] = new LCNode<handler>(D(w));\r\
    \n\t}\r\n\trep(i,N-1){\r\n\t\tint x,y;\r\n\t\tcin>>x>>y;\r\n\t\tx--,y--;\r\n\t\
    \tG[x].pb(y);\r\n\t\tG[y].pb(x);\r\n\t}\r\n\tdfs(0);\r\n\r\n\trep(q,Q){\r\n//\t\
    \tprintf(\"----- %d times end-----\\n\",q);\r\n\t\tint t,a,b,c;\r\n\t\tcin>>t>>a>>b>>c;\r\
    \n\t\ta--,b--;\r\n\t\tif(t==1){\r\n\t\t\tupdate(a,b,A(c));\r\n\t\t}else{\r\n\t\
    \t\tD v = query(a,b);\r\n//\t\t\tshow(v.sm);\r\n//\t\t\tshow(v.lmx);\r\n//\t\t\
    \tshow(v.rmx);\r\n//\t\t\tshow(v.mx);\r\n\t\t\tcout<<v.mx<<endl;\r\n\t\t}\r\n\t\
    }\r\n}\n"
  code: "/*\r\n\tLink Cut Tree\r\n\t\u6839\u4ED8\u304D\u68EE\u3092\u6271\u3046\u30C7\
    \u30FC\u30BF\u69CB\u9020\r\n\t\r\n\t\u4F7F\u3044\u65B9\r\n\t\tpath\u306B\u5BFE\
    \u3059\u308B query,lazy query\r\n\t\tlink : v(\u89AA\u306A\u3057) \u306E\u89AA\
    \u3092 p \u306B\u8A2D\u5B9A\u3059\u308B\r\n\t\tcut : v \u3092 \u89AA\u304B\u3089\
    \u5207\u308A\u96E2\u3059\r\n\t\tevert: \u6839\u3092\u5909\u66F4\u3059\u308B\r\n\
    \t\t\u3053\u308C\u3089\u304C\u5168\u3066 O(log N) \u3067\u53EF\u80FD.\r\n\r\n\t\
    \t\u5916\u5074\u3067\u306F\u5404\u9802\u70B9v\u306B\u5BFE\u3057\u3066, NP n[v]\
    \ \u3092\u6301\u3064(\u5916\u3067\u3053\u308C\u3092\u3044\u3058\u308B\u5FC5\u8981\
    \u306F\u306A\u3044)\r\n\t\t\u9006\u306B\u5185\u5074\u3067 NP \u304B\u3089 v \u3092\
    \u5FA9\u5143\u3057\u305F\u3044\u3068\u304D\u306FHandler\u306B\u9802\u70B9\u3092\
    \u8FFD\u52A0\u3057\u3066\u304A\u3051\u3070\u826F\u3044?\r\n\r\n\t\t\u3088\u308A\
    \u5909\u306A\u64CD\u4F5C(v-u\u9593rotate)\u3068\u304B\u306B\u306A\u3063\u305F\u3089\
    splay(int k) \u3068\u304B\u3092splay_lazy \u304B\u3089\u6301\u3063\u3066\u304F\
    \u308B\u5FC5\u8981\u304C\u3042\u308A\u305D\u3046\r\n\r\n\r\n\t\u52D5\u4F5C\u539F\
    \u7406?\r\n\t\t\u52D5\u7684 HL decomposition \u307F\u305F\u3044\u306A\u96F0\u56F2\
    \u6C17\r\n\t\t\u5404path\u3092splay tree \u3067\u8868\u73FE\u3059\u308B\u3001\u6839\
    \u306B\u8FD1\u3044\u65B9\u304Cleft\r\n\t\texpose(v): (\u6839\u4ED8\u304D\u6728\
    \u3067\u306E)v\u304B\u3089root\u3092\u4E00\u3064\u306Epath\u306B\u3059\u308B,\
    \ \u3064\u3044\u3067\u306Bv\u3092\u305D\u306E\"splay\u6728\u306E\"\u6839\u306B\
    \u3059\u308B)\r\n\t\t\t\u3053\u308C\u306B\u542B\u307E\u308C\u308BHLdecomp\u306E\
    \u5404path\u3067\u306F\u3042\u308B\u70B9\u304B\u3089\u4E0A\u5168\u3066\u3092\u898B\
    \u308B\u3053\u3068\u306B\u306A\u308B\u306E\u3067\u3001\r\n\t\t\tsplay\u306E\u8A00\
    \u8449\u3067\u3044\u3046\u3068left child \u3092\u6B8B\u3059\r\n\t\t\tv-root\u9593\
    \u304Cv\u3092\u6839\u3068\u3059\u308B\u4E00\u3064\u306Esplay\u306B\u306A\u308B\
    \u306E\u3067\u3001\u4F55\u3082\u8003\u3048\u305A\u306Bv\u306B\u30AF\u30A8\u30EA\
    \u98DB\u3070\u305B\u3070\u3044\u3044\r\n\t\tevert(v): (\u6839\u4ED8\u304D\u6728\
    \u3067\u306E)root\u3092v\u306B\u5909\u3048\u308B\r\n\t\t\texpose\u3057\u305F\u3042\
    \u3068\u306Fsplay\u7684\u306B\u306Freverse\u306B\u5BFE\u5FDC\u3059\u308B\r\n\r\
    \n\t\tsm\u3068\u304B\u306F\u5404splay\u5185\u3067\u5B8C\u7D50\u3057\u3066\u3044\
    \u308B\u3053\u3068\u306B\u6CE8\u610F!\r\n\t\t\u4F8B\u3048\u3070\u3001link\u3067\
    \ p = r \u3068\u3057\u305F\u3068\u304D\u306B r->update() \u3057\u306A\u304F\u3066\
    \u3044\u3044\u306E\u306F\u3001\u3053\u308C\u304C splay tree \u306E edge \u3067\
    \u306F\u306A\u3044\u304B\u3089\r\n\r\n\t\u53C2\u8003\r\n\t\thttp://yosupo.hatenablog.com/entry/2014/12/26/001414\
    \ (\u53E4\u3044\u306E\u3067rev\u306E\u6301\u3061\u65B9\u3068\u304B\u5FAE\u5999\
    )\r\n\t\thttp://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1675225 (\u307F\u3058\
    \u304B\u3044)\r\n\t\thttps://github.com/yosupo06/Algorithm/blob/master/datastructure/linkcuttree.h#L36\
    \ (\u304B\u306A\u308A\u4FE1\u983C\u3067\u304D\u308B)\r\n\t\thttps://www.slideshare.net/iwiwi/2-12188845\
    \ (iwiwi\u3055\u3093\u306E\u3044\u3064\u3082\u306E\u3084\u3064)\r\n\r\n\tverified\r\
    \n\t\tdo use segment tree\r\n\t\t\t\u30D0\u30B0\u3089\u305B\u305F\u3068\u3053\
    : act\u306E\u6642\u9577\u3055\u304C\u5F15\u6570\u306B\u3044\u308B, \u5F15\u6570\
    \u306Fsm\u306Fsz\u3067\u3044\u3044\u3051\u3069v\u306F1\r\n\t\tspaceships\r\n\t\
    \t\tlca\u306Everify\u306B\u306A\u3063\u305F\u306D\r\n*/\r\n#include <bits/stdc++.h>\r\
    \n#define rep(i,n) for(int i=0;i<(int)(n);i++)\r\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\r\
    \n#define all(c) c.begin(),c.end()\r\n#define pb push_back\r\n#define fs first\r\
    \n#define sc second\r\n#define show(x) cout << #x << \" = \" << x << endl\r\n\
    #define chmin(x,y) x=min(x,y)\r\n#define chmax(x,y) x=max(x,y)\r\nusing namespace\
    \ std;\r\n\r\ntemplate<class Handler>\r\nstruct LCNode{\r\n\tusing NP = LCNode*;\r\
    \n\tstatic NP nil;\r\n\r\n\tusing D = typename Handler::val_t;\t//data\r\n\tusing\
    \ A = typename Handler::opr_t;\t//action\r\n\r\n\r\n\tNP p,l,r;\r\n\tint sz;\r\
    \n\tD v,sm;\r\n\tA lz;\r\n\tbool rev;\r\n\tLCNode(D v,A a) :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v),lz(a),rev(false){}\r\
    \n\tLCNode(D v) :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v),lz(A::e()),rev(false){}\r\
    \n\tLCNode() : p(nullptr),l(nullptr),r(nullptr),sz(0),v(D::e()),sm(D::e()),lz(A::e()),rev(false){}\r\
    \n\r\n\tint pos(){\t\t\t//\u89AA\u306E\u5DE6\u306E\u5B50\u304B,\u53F3\u306E\u5B50\
    \u304B,\u305D\u308C\u3068\u3082\u6839(or nil)\u304B\r\n\t\tif(p&&p->l == this)\
    \ return -1;\r\n\t\tif(p&&p->r == this) return 1;\r\n\t\treturn 0;\r\n\t}\r\n\t\
    void rot(){\t\t\t\t//root\u3067\u547C\u3076\u3068\u6B7B\r\n\t\tassert(p != nullptr);\r\
    \n\t\tNP pp=p->p;\r\n\t\tint pps=p->pos();\r\n\t\tif(p->l==this){\r\n\t\t\tp->l=r,r->p=p,r=p,p->p=this;\r\
    \n\t\t}else{\r\n\t\t\tp->r=l,l->p=p,l=p,p->p=this;\r\n\t\t}\r\n\t\tp->update();\r\
    \n\t\tupdate();//\tzig,zig-zag,zig-zig\u3068\u3082\u306B\u3069\u3046\u305B\u6B21\
    \u3067update\u304C\u3088\u3070\u308C\u308B\u306E\u3067\u3044\u3089\u306A\u3044\
    (\u6700\u5F8C\u6839\u306F\u3044\u308B\u2190\u3053\u308C\u5B9F\u306Fmerge/split\u3067\
    \u3061\u3083\u3093\u3068update\u3057\u3066\u308B\u304B\u3089\u66F8\u304B\u306A\
    \u304F\u3066\u3044\u3044\u3093\u3060\u3088\u306D)\r\n\t\tp=pp;\r\n\t\tif(pps==0)\
    \ return;\r\n\t\tif(pps==-1) pp->l=this;\r\n\t\telse pp->r=this;\r\n\t\tif(pp->sz)\
    \ pp->update();\t//\u3053\u308C\u3082\u3044\u3089\u3093\u304B\u3082\r\n\t}\r\n\
    \tvoid splay(){\t\t\t//this\u3092root\u306B\u3082\u3063\u3066\u304F\u308B\r\n\t\
    \tpushdown();\r\n\t\twhile(true){\r\n\t\t\tint ps=pos();\r\n\t\t\tif(ps==0) break;\r\
    \n\t\t\tint pps=p->pos();\r\n\t\t\tif(pps==0){\t\t//zig\r\n\t\t\t\trot();\r\n\t\
    \t\t}else if(ps==pps){\t\t//zigzig\r\n\t\t\t\tp->rot();rot();\r\n\t\t\t}else{\t\
    \t\t\t\t//zigzag\r\n\t\t\t\trot();rot();\r\n\t\t\t}\r\n\t\t}\r\n\t\tupdate();\t\
    \t\t//merge/split\u4EE5\u5916\u304B\u3089\u547C\u3070\u308C\u308B\u304B\u3082\u3057\
    \u308C\u306A\u3044\u306E\u3067\u4E00\u5FDC\u3064\u3051\u3066\u304A\u304F\r\n\t\
    }\r\n\t/*\r\n\t\texpose\r\n\t\t\u6839\u4ED8\u304D\u6728\u306B\u304A\u3044\u3066\
    \u3001this\u304B\u3089r\u307E\u3067\u306Epath\u30921\u3064\u306Esplay tree\u306B\
    \u3059\u308B(\u4E0B\u306F\u3061\u3083\u3093\u3068\u5207\u308B)\r\n\t\t\u3064\u3044\
    \u3067\u306Bthis\u3092(splay tree \u306E\u610F\u5473\u3067)root\u306B\u6301\u3063\
    \u3066\u304F\u308B\r\n\t\t\u5B9F\u969B\u306E\u6728\u306E\u6839\u3092\u5909\u3048\
    \u308Bevert\u3068\u306F\u9055\u3046\u306E\u3067\u6CE8\u610F!\r\n\t*/\r\n\tvoid\
    \ expose(){\r\n\t\tNP v = this, vr = nil;\r\n\r\n\t\twhile(true){\r\n\t\t\tv->splay();\r\
    \n\t\t\tv->r = vr;\t//first: cut right\r\n\t\t\tv->update();\r\n\t\t\tvr = v;\t\
    \t//next vr\r\n\t\t\tv = v->p;\t//LinkCut\u306Eparent(\u5225\u306Esplaytree\u306B\
    \u79FB\u52D5\u3059\u308B)\r\n\t\t\tif(v==nullptr) break;\r\n\t\t}\r\n\t\tv = this;\r\
    \n\t\tv->r = nil;\t//cut\r\n\t\tv->update();\r\n\r\n\t\twhile(v->p){\r\n\t\t\t\
    v->p->r = v;\r\n\t\t\tv = v->p;\r\n\t\t\tv->update();\r\n\t\t}\r\n\t\tsplay();\r\
    \n\t}\r\n\tNP update(){\t\t//\u60C5\u5831\u66F4\u65B0(\u5B50\u304C\u6B63\u3057\
    \u3044\u6642\u306B\u547C\u3070\u306A\u3044\u3068\u30C0\u30E1) (\u6700\u5F8C\u306B\
    update\u3057\u3066return\u3059\u308B\u306E\u306B\u697D\u306A\u306E\u3067NP\u3092\
    \u8FD4\u3059)\r\n\t\tsz=1+l->sz+r->sz;\r\n\t\tsm = v;\r\n\t\tif(l->sz) sm = l->sm\
    \ + sm;\t//if(l) \u3060\u3068nil\u3067\u3082\u547C\u3076\u7FBD\u76EE\u306B\u306A\
    \u308A\u305D\u3046\r\n\t\tif(r->sz) sm = sm + r->sm;\r\n\t\treturn this;\r\n\t\
    }\r\n\t/*\r\n\t\treverse\r\n\r\n\t\trev\u3092\u6271\u3046\u3068\u304D\u306F\u5168\
    \u3066revdata()\u3092\u3088\u3076\u3001\u500B\u306E\u30BF\u30A4\u30DF\u30F3\u30B0\
    \u3067\u3082\u3046swap(l,r)\u3082\u3057\u3061\u3083\u3046\r\n\r\n\t\treverse\u6A5F\
    \u80FD\u306Flazy splay\u306E\u6A5F\u69CB\u306E\u5185\u5074\u3067\u6271\u3063\u3066\
    \u3082\u3044\u3044\u304B\u3068\u601D\u3063\u305F\u3051\u3069\u3001LCTree \u306E\
    \ Node \u306B\u5225\u306E\u60C5\u5831\u3068\u3057\u3066\u6301\u305F\u305B\u308B\
    \u3053\u3068\u306B\u3057\u305F\r\n\t\t1. \u4ECA\u6301\u3063\u3066\u308B data sm\
    \ (a+b+..+c) \u304B\u3089\u3001sm.reverse (c+..+b+a)\u304C\u7C21\u5358\u306B\u8A08\
    \u7B97\u3067\u304D\u308B\u5834\u5408\r\n\t\t\trevdata() \u306E\u4E2D\u306B\u305D\
    \u308C\u3092\u304B\u3051\u3070\u304A\u308F\u308A\r\n\t\t2. \u3067\u304D\u306A\u3044\
    \u5834\u5408\r\n\t\t\tsm \u3068 revsm (\u5FC5\u8981\u306A\u3089lz \u3082\u540C\
    \u69D8?) \u3092Node\u306B\u4E21\u65B9\u6301\u3063\u3066\u9811\u5F35\u308B\r\n\t\
    \t\t\u3068\u601D\u3063\u305F\u3051\u3069\u305D\u308C\u3088\u308A\u306FHandler\u306B\
    2\u3064\u6301\u305F\u305B\u305F\u307B\u3046\u304C\u697D\u305D\u3046\r\n\t\tlz\u3082\
    \u5909\u308F\u3063\u3061\u3083\u3046\u5834\u5408\u306B\u6839\u672C\u7684\u306B\
    \u5BFE\u5FDC\u3067\u304D\u3066\u306A\u3044\u6C17\u304C\u3057\u3066\u304D\u305F\
    \u3001\u666E\u901A\u305D\u3046\u306A\u3089\u3093\u3057\u3080\u305A\u305D\u3046\
    \u306A\u306E\u3067\u8AE6\u3081\r\n\r\n\t\t\u3061\u306A\u307F\u306Breverse\u306F\
    \u3001evert(\u6839\u5909\u66F4\u30AF\u30A8\u30EA)\u306E\u305F\u3081\u306B\u4F7F\
    \u3044\u307E\u3059\r\n\t\t(\u73FEroot - root \u9593\u306Epath\u306E\u5411\u304D\
    \u3060\u3051\u9006\u306B\u3059\u308B\u3068\u3044\u3046\u64CD\u4F5C\u306B\u306A\
    \u3063\u3066\u3001\u5404splay\u6728\u3067\u5DE6\u304C\u5143\u306E\u6839\u4ED8\u304D\
    \u6728\u3067\u306E\u4E0A\u306B\u5BFE\u5FDC\u3059\u308B\u3053\u3068\u3092\u601D\
    \u3044\u51FA\u3059\u3068)\r\n\t*/\r\n\tvoid revdata(){\r\n\t\trev ^= true;\r\n\
    \t\tswap(l,r);\r\n\t\tsm.revdata();\r\n\t}\r\n\tvoid addlazy(const A& f){\r\n\t\
    \tHandler::setg2fg(f,lz);\r\n\t\tv = Handler::act(f,v,1);\r\n\t\tsm = Handler::act(f,sm,sz);\r\
    \n\t}\r\n\tvoid push(){\r\n\t\tif(rev){\r\n\t\t\tif(l->sz) l->revdata();\r\n\t\
    \t\tif(r->sz) r->revdata();\r\n\t\t\trev = false;\r\n\t\t}\r\n\t\tif(l->sz) l->addlazy(lz);\r\
    \n\t\tif(r->sz) r->addlazy(lz);\r\n\t\tlz = A::e();\r\n\t}\r\n\tvoid pushdown(){\t\
    //from root to this\r\n\t\tif(pos()) p->pushdown();\r\n\t\tpush();\r\n\t}\r\n\r\
    \n\t/*\r\n\t\tlink:\r\n\t\t\tthis\u306B\u5BFE\u5FDC\u3059\u308B\u6839\u4ED8\u304D\
    \u6728\u306E\u9802\u70B9\u306E\u89AA \u3092 r\u306B\u5BFE\u5FDC\u3059\u308B\u6839\
    \u4ED8\u304D\u6728\u306E\u9802\u70B9 \u306B\u3059\u308B\r\n\t\t\t( \u3064\u307E\
    \u308A\u3001\u5916\u304B\u3089\u306Fn[v].link(n[r]) )\r\n\t*/\r\n\tvoid link(NP\
    \ r){\r\n\t\texpose();\r\n\t\tr->expose();\r\n\t\tp = r;\r\n\t}\r\n\t/*\r\n\t\t\
    cut:\r\n\t\t\tthis\u306B\u5BFE\u5FDC\u3059\u308B\u6839\u4ED8\u304D\u6728\u306E\
    \u9802\u70B9 \u3068 \u305D\u306E\u89AA \u3092\u5207\u308B\r\n\t\t\t( \u3064\u307E\
    \u308A\u3001\u5916\u304B\u3089\u306Fn[v].cut() )\r\n\t\t\tv\u306E\u89AA\u3063\u3066\
    \u306E\u306Fsplay\u3067\u3044\u3046\u3068expose(v)\u3057\u305F\u3042\u3068\u306E\
    v->l\r\n\t*/\r\n\tvoid cut(){\r\n\t\texpose();\r\n\t\tl->p = nullptr;\r\n\t\t\
    l = nil;\r\n\t\tupdate();\r\n\t}\r\n\tvoid evert(){\r\n\t\texpose();\r\n\t\trevdata();\r\
    \n\t}\r\n\r\n\t/*\r\n\t\tquery for [this, x] \r\n\t*/\r\n\tD query(NP x){\r\n\t\
    \tevert();\r\n\t\tx->expose();\r\n//\t\tx->showtree();puts(\"\");\r\n\t\treturn\
    \ x->sm;\r\n\t}\r\n\tvoid query_update(NP x,const A& f){\r\n\t\tevert();\r\n\t\
    \tx->expose();\r\n\t\tx->addlazy(f);\r\n\t}\r\n\r\n\t/*\r\n\t\tparent:\r\n\t\t\
    \texpose(v) \u3057\u305F\u3042\u3068\u306F\u4E00\u3064\u5DE6\u306B\u884C\u3063\
    \u3066\u305D\u3063\u304B\u3089\u53F3\u306B\u884C\u304D\u7D9A\u3051\u305F\u3068\
    \u3053\u308D\r\n\t\t\t\u3061\u3083\u3093\u3068\u30A2\u30AF\u30BB\u30B9\u3057\u305F\
    \u3089expose\u3057\u306A\u3044\u3068\u8A08\u7B97\u91CF\u58CA\u308C\u308B\u306E\
    \u3067\u6700\u5F8C\u306Bexpose\u3059\u308B\r\n\t*/\r\n\tNP parent(){\r\n\t\texpose();\r\
    \n\t\tNP v = this->l;\r\n\t\tif(v == nil) return nil;\r\n\t\twhile(v->r != nil){\r\
    \n\t\t\tv = v->r;\r\n\t\t}\r\n\t\tv->expose();\r\n\t\treturn v;\r\n\t}\r\n\r\n\
    \tNP root(){\r\n\t\texpose();\r\n\t\tNP v = this;\r\n\t\twhile(v->l != nil){\r\
    \n\t\t\tv = v->l;\r\n\t\t}\r\n\t\tv->expose();\r\n\t\treturn v;\r\n\t}\r\n\r\n\
    \tNP lca(NP x){\r\n\t\tx->expose();\r\n\t\texpose();\r\n\t\tNP w = x;\r\n\t\t\
    while(x->p != nullptr){\r\n\t\t\tif(!x->pos()) w = x->p;\r\n\t\t\tx = x->p;\r\n\
    \t\t}\r\n\t\treturn (this == x) ? w : nullptr;\r\n\t}\r\n\r\n\t/*\r\n\t\tthis\u304B\
    \u3089\u305D\u306Esplay\u6728\u5185\u3060\u3051\r\n\t*/\r\n\tvoid showtree(){\r\
    \n\t\tcout<<\" [ \";\r\n\t\tif(l->sz) l->showtree();\r\n\t\tcout<<v;\r\n\t\tif(r->sz)\
    \ r->showtree();\r\n\t\tcout<<\" ] \";\r\n\t}\r\n};\r\n\r\nusing ll = long long;\r\
    \nconst ll inf = 1e17;\r\n\r\nstruct handler{\r\n\t/*\r\n\t\trange assign\r\n\t\
    \trange subseqsummax\r\n\t*/\r\n\tstruct val_t{\r\n\t\tll sm,lmx,rmx,mx;\r\n\t\
    \tval_t(){*this = e();}\r\n\t\tval_t(ll x){\r\n\t\t\tsm = lmx = rmx = mx = x;\r\
    \n\t\t}\r\n\t\tval_t(ll sm,ll lmx,ll rmx,ll mx):sm(sm),lmx(lmx),rmx(rmx),mx(mx){}\r\
    \n\r\n\t\tconst static val_t e(){\r\n\t\t\treturn val_t(0,-inf,-inf,-inf);\r\n\
    \t\t}\r\n\t\tval_t operator+(const val_t &r) const {\r\n\t\t\treturn val_t(sm+r.sm,\
    \ max(lmx,sm+r.lmx), max(r.rmx,r.sm+rmx), max(max(mx,r.mx),rmx+r.lmx));\r\n\t\t\
    }\r\n\r\n\t\tvoid revdata(){\r\n\t\t\tswap(lmx,rmx);\r\n\t\t}\r\n\r\n\t\tfriend\
    \ ostream& operator<<(ostream& o,const val_t& d){return o<<d.sm;}\r\n\t};\r\n\r\
    \n\tstruct opr_t{\r\n\t\tll x;\r\n\t\topr_t(){*this = e();}\r\n\t\topr_t(ll x):x(x){}\r\
    \n\r\n\t\tconst static opr_t e(){\r\n\t\t\treturn opr_t(inf);\r\n\t\t}\r\n\t\t\
    friend ostream& operator<<(ostream& o,const opr_t& d){return o<<d.x;}\r\n\t};\r\
    \n\r\n\tstatic void setg2fg(const opr_t &f, opr_t &g){\t//g -> fg\t\tf after g\r\
    \n\t\tif(f.x != inf) g.x = f.x;\r\n\t}\r\n\tstatic val_t act(const opr_t &f, const\
    \ val_t &v,int len){\r\n\t\tif(f.x == inf) return v;\r\n\t\tll a = f.x*len;\r\n\
    \t\tll b = max(a,f.x);\r\n\t\treturn val_t(a,b,b,b);\r\n\t}\r\n};\r\ntemplate<>\r\
    \nLCNode<handler>::NP LCNode<handler>::nil = new LCNode();\r\n\r\n\r\nusing D\
    \ = handler::val_t;\r\nusing A = handler::opr_t;\r\nusing NP = LCNode<handler>*;\r\
    \n\r\nint N,Q;\r\nvector<vector<int>> G;\r\nvector<NP> tree;\r\n\r\nvoid dfs(int\
    \ v,int p=-1){\r\n\tif(p!=-1){\r\n\t\ttree[v]->link(tree[p]);\r\n\t}\r\n\tfor(int\
    \ u:G[v]) if(u!=p) dfs(u,v);\r\n}\r\n\r\nD query(int a,int b){\r\n\treturn tree[a]->query(tree[b]);\r\
    \n}\r\nvoid update(int a,int b,const A& f){\r\n\treturn tree[a]->query_update(tree[b],f);\r\
    \n}\r\n\r\nint main(){\r\n\tcin>>N>>Q;\r\n\tG.resize(N);\r\n\ttree.resize(N);\r\
    \n\trep(i,N){\r\n\t\tint w;\r\n\t\tcin>>w;\r\n\t\ttree[i] = new LCNode<handler>(D(w));\r\
    \n\t}\r\n\trep(i,N-1){\r\n\t\tint x,y;\r\n\t\tcin>>x>>y;\r\n\t\tx--,y--;\r\n\t\
    \tG[x].pb(y);\r\n\t\tG[y].pb(x);\r\n\t}\r\n\tdfs(0);\r\n\r\n\trep(q,Q){\r\n//\t\
    \tprintf(\"----- %d times end-----\\n\",q);\r\n\t\tint t,a,b,c;\r\n\t\tcin>>t>>a>>b>>c;\r\
    \n\t\ta--,b--;\r\n\t\tif(t==1){\r\n\t\t\tupdate(a,b,A(c));\r\n\t\t}else{\r\n\t\
    \t\tD v = query(a,b);\r\n//\t\t\tshow(v.sm);\r\n//\t\t\tshow(v.lmx);\r\n//\t\t\
    \tshow(v.rmx);\r\n//\t\t\tshow(v.mx);\r\n\t\t\tcout<<v.mx<<endl;\r\n\t\t}\r\n\t\
    }\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: data structure/splay/LCTree.cpp
  requiredBy: []
  timestamp: '2018-07-12 06:46:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/splay/LCTree.cpp
layout: document
redirect_from:
- /library/data structure/splay/LCTree.cpp
- /library/data structure/splay/LCTree.cpp.html
title: data structure/splay/LCTree.cpp
---
