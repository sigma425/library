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
  bundledCode: "#line 1 \"ds/2D/splay_2Dsegtree.cpp\"\n/*\r\n\t2\u6B21\u5143(N*N grid)\
    \ \u3067point add, range sum \u304C\u51FA\u6765\u308B\r\n\tseg.add(x,y) seg.count(x1,x2,y1,y2)\r\
    \n\tpoint \u306B\u91CD\u307F\u3092\u3064\u3051\u308B\u306B\u306F\u7D50\u69CB\u66F8\
    \u304D\u63DB\u3048\u308B\u5FC5\u8981\u304C\u3042\u308B\u3068\u601D\u3046(Node\
    \ \u306B\u5024\u3082\u305F\u305B\u308B, lower_bound \u8AAD\u3093\u3067\u308B\u3068\
    \u3053\u3082sum\u306B\u66F8\u304D\u63DB\u3048\u308B\u5FC5\u8981\u304C\u3042\u308B\
    )\r\n\r\n\tO(Nlog^2N) \u3060\u3051\u3069\u5B9A\u6570\u500D\u3067\u304B\u306A\u308A\
    \u9045\u3044 N=10^5 \u3067 1sec \u3068\u304B\u305D\u306E\u304F\u3089\u3044\r\n\
    \r\n*/\r\ntemplate<class T>\r\nstruct SplayTree{\r\n\tstruct Node;\r\n\ttypedef\
    \ Node* NP;\r\n\tstatic NP nil;\r\n\tstruct Node{\r\n\t\tNP p,l,r;\t\t\t//parent,left\
    \ child,right child\r\n\t\tint sz;\r\n\t\tint v;\r\n\t\tNode(int v) :p(nullptr),l(nil),r(nil),sz(1),v(v){}\r\
    \n\t\tNode() : p(nullptr),l(nullptr),r(nullptr),sz(0),v(0){}\t\t\t\t\t\t//\u5358\
    \u4F4D\u5143!!\r\n\t\tint pos(){\t\t\t//\u89AA\u306E\u5DE6\u306E\u5B50\u304B,\u53F3\
    \u306E\u5B50\u304B,\u305D\u308C\u3068\u3082\u6839(or null)\u304B\r\n\t\t\tif(p&&p->l\
    \ == this) return -1;\r\n\t\t\tif(p&&p->r == this) return 1;\r\n\t\t\treturn 0;\r\
    \n\t\t}\r\n\t\tvoid rot(){\t\t\t\t//root\u3067\u547C\u3076\u3068\u6B7B\r\n\t\t\
    \tNP pp=p->p;\t\t\t//\u89AA\u306E\u89AA\r\n\t\t\tint pps=p->pos();\t//pp\u304B\
    \u3089\u307F\u305Fp\u306E\u5DE6\u53F3\r\n\t\t\tif(p->l==this){\t\t//pos()==-1\r\
    \n\t\t\t\tp->l=r,r->p=p,r=p,p->p=this;\r\n\t\t\t}else{\r\n\t\t\t\tp->r=l,l->p=p,l=p,p->p=this;\r\
    \n\t\t\t}\r\n\t\t\t//\u65B0\u3057\u3044\u6728\u3067\u4E0B\u304B\u3089update\r\n\
    \t\t\tp->update();\r\n\t\t\tupdate();\r\n\t\t\tp=pp;\r\n\t\t\tif(pps==0) return;\r\
    \n\t\t\tif(pps==-1) pp->l=this;\r\n\t\t\telse pp->r=this;\r\n\t\t\tpp->update();\r\
    \n\t\t}\r\n\t\tvoid splay(){\t\t\t//this\u3092root\u306B\u3082\u3063\u3066\u304F\
    \u308B\r\n\t\t\twhile(true){\r\n\t\t\t\tint ps=pos();\r\n\t\t\t\tif(ps==0) break;\r\
    \n\t\t\t\tint pps=p->pos();\r\n\t\t\t\tif(pps==0){\t\t//zig\r\n\t\t\t\t\trot();\r\
    \n\t\t\t\t}else if(ps==pps){\t\t//zigzig\r\n\t\t\t\t\tp->rot();rot();\r\n\t\t\t\
    \t}else{\t\t\t\t\t//zigzag\r\n\t\t\t\t\trot();rot();\r\n\t\t\t\t}\r\n\t\t\t}\r\
    \n\t\t}\r\n\t\tNP splay(int k){\t\t\t//\u3053\u306E\u533A\u9593\u306E\u5DE6\u304B\
    \u3089kth(0-indexed)\u3092root\u306B\u3082\u3063\u3066\u304D\u3066\u305D\u306E\
    \u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\u3059(sz\u304C\u5FC5\u8981)\r\n\t\t\t//assert(0<=k&&k<sz);\r\
    \n\t\t\tif(k<l->sz){\r\n\t\t\t\treturn l->splay(k);\r\n\t\t\t}else if(k==l->sz){\r\
    \n\t\t\t\tsplay();\r\n\t\t\t\treturn this;\r\n\t\t\t}else{\r\n\t\t\t\treturn r->splay(k-(l->sz+1));\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\tNP update(){\t\t//\u60C5\u5831\u66F4\u65B0(\u5B50\u304C\
    \u6B63\u3057\u3044\u6642\u306B\u547C\u3070\u306A\u3044\u3068\u30C0\u30E1) (\u6700\
    \u5F8C\u306Bupdate\u3057\u3066return\u3059\u308B\u306E\u306B\u697D\u306A\u306E\
    \u3067NP\u3092\u8FD4\u3059)\r\n\t\t\tsz=1+l->sz+r->sz;\r\n\t\t\treturn this;\r\
    \n\t\t}\r\n\r\n\t};\r\n\tNP n;\r\n\tstatic NP merge(NP l,NP r){\t\t\t//merge\u3057\
    \u305F\u6839\r\n\t\tif(r==nil) return l;\r\n\t\tr=r->splay(0);\r\n\t\tr->l=l;\r\
    \n\t\tl->p=r;\r\n\t\treturn r->update();\r\n\t}\r\n\t/*\r\n\t\tkth\u3067split(k=0\u306A\
    \u3089fs=null)\r\n\t\tl\u306F\u5B8C\u5168\u306B\u5207\u308A\u96E2\u3055\u308C\u3066\
    \u308B\u3051\u308C\u3069\r\n\t\tr\u306F\u4E0A\u3068\u3064\u306A\u304C\u3063\u3066\
    \u3044\u308B?\r\n\t\t\u307E\u3042\u3067\u3082\u57FA\u672C\u7684\u306Bsplit\u306E\
    \u7B2C\u4E00\u5F15\u6570\u306Froot\u306A\u306E\u3067\u5927\u4E08\u592B\r\n\t*/\r\
    \n\tstatic pair<NP,NP> split(NP x,int k){\r\n\t\t//assert(0<=k&&k<=x->sz);\r\n\
    \t\tif(k==x->sz) return {x,nil};\r\n\t\tx=x->splay(k);\r\n\t\tNP l=x->l;\r\n\t\
    \tl->p = nullptr;\r\n\t\tx->l = nil;\r\n\t\treturn {l,x->update()};\r\n\t}\r\n\
    \tstatic NP built(int sz,int vs[]){\t\t\t\t//init\r\n\t\tif(!sz) return nil;\r\
    \n\t\tint md=sz/2;\r\n\t\tNP x= new Node(vs[md]);\r\n\t\tx->l = built(md,vs);\r\
    \n\t\tx->l->p=x;\r\n\t\tx->r=built(sz-(md+1),vs+md+1);\r\n\t\tx->r->p=x;\r\n\t\
    \treturn x->update();\r\n\t}\r\n\tSplayTree() : n(nil){}\r\n\tSplayTree(NP n)\
    \ : n(n){}\r\n\tSplayTree(int sz,int vs[]){\r\n\t\tn=built(sz,vs);\r\n\t}\r\n\t\
    void insert(int k,int v){\r\n\t\tauto u=split(n,k);\r\n\t\tn=merge(merge(u.fs,new\
    \ Node(v)),u.sc);\r\n\t}\r\n\tvoid insert(int v){\r\n\t\tint k=lower_bound(v);\r\
    \n\t\tinsert(k,v);\r\n\t}\r\n\tvoid erase(int k){\r\n\t\tauto u=split(n,k);\r\n\
    \t\tn=merge(u.fs,split(u.sc,1).sc);\r\n\t}\r\n\tvoid merge(SplayTree t){\r\n\t\
    \tn=merge(n,t.n);\r\n\t}\r\n\tint sz(){\r\n\t\treturn n->sz;\r\n\t}\r\n\tint get(int\
    \ k){\t\t\t//kth info\r\n\t\tauto a=split(n,k);\r\n\t\tauto b=split(a.sc,1);\r\
    \n\t\tint ret=b.fs->v;\r\n\t\tn=merge(merge(a.fs,b.fs),b.sc);\r\n\t\treturn ret;\r\
    \n\t}\r\n\t/*\r\n\t\tsearch\r\n\t\t\u5E73\u8861\u4E8C\u5206\u6728\u3068\u3057\u3066\
    \u306E\u5F79\u76EE\u3092\u601D\u3044\u51FA\u305B\r\n\t\t\u306A\u3093\u304B\u5217\
    \u3092\u304F\u3063\u3064\u3051\u305F\u308A\u308F\u3051\u305F\u308A\u3067\u304D\
    \u308B\u3068\u3060\u3051\u601D\u3063\u3068\u3051\u3070\u57FA\u672C\u3044\u3044\
    \u3051\u3069\r\n\t\t\u6301\u3063\u3066\u308B\u30C7\u30FC\u30BF\u306B\u9806\u5E8F\
    \u4ED8\u3044\u3066\u308B\u3068\u304D\u306B\u306F\u3061\u3083\u3093\u3068\u4E8C\
    \u5206\u6728\u3068\u3057\u3066\u4F7F\u3048\u308B\r\n\t*/\r\n\tint lower_bound(int\
    \ x){\t\t//x\u4EE5\u4E0A\u3067\u4E00\u756A\u5C0F\u3055\u3044\u3068\u3053\u306E\
    id\u3092\u8FD4\u3059\r\n\t\tNP p=n;\r\n\t\tint ret=0;\r\n\t\twhile(p!=nil){\r\n\
    \t\t\tif(x<=p->v) p=p->l;\r\n\t\t\telse ret+=(p->l->sz)+1,p=p->r;\r\n\t\t}\r\n\
    \t\treturn ret;\r\n\t}\r\n\tint upper_bound(int x){\t\t//x\u3088\u308A\u5927\u3067\
    \u4E00\u756A\u5C0F\u3055\u3044\u3068\u3053\u306Eid\u3092\u8FD4\u3059\r\n\t\tNP\
    \ p=n;\r\n\t\tint ret=0;\r\n\t\twhile(p!=nil){\r\n\t\t\tif(x<p->v) p=p->l;\r\n\
    \t\t\telse ret+=(p->l->sz)+1,p=p->r;\r\n\t\t}\r\n\t\treturn ret;\r\n\t}\r\n};\r\
    \ntemplate<class T>\r\ntypename SplayTree<T>::NP SplayTree<T>::nil = new SplayTree<T>::Node();\r\
    \n\r\nstruct segtree{\r\n\tint N;\r\n\tvector< SplayTree<int> > seg;\r\n\tsegtree(int\
    \ n){\r\n\t\tint p2=1;\r\n\t\twhile(p2<n) p2*=2;\r\n\t\tN=p2;\r\n\t\tseg.resize(N*2);\r\
    \n\t}\r\n\tvoid add(int x,int y){\t\t\t//add P(x,y)\r\n\t\tx+=N;\r\n\t\twhile(x){\r\
    \n\t\t\tseg[x].insert(y);\r\n\t\t\tx/=2;\r\n\t\t}\r\n\t}\r\n\tint count(int a,int\
    \ b,int ya,int yb,int l,int r,int k){\t\t//[a,b) * [ya,yb)\r\n\t\tif(b<=l||r<=a)\
    \ return 0;\r\n\t\tif(a<=l&&r<=b) return seg[k].lower_bound(yb) - seg[k].lower_bound(ya);\r\
    \n\t\treturn count(a,b,ya,yb,l,(l+r)/2,k*2)+count(a,b,ya,yb,(l+r)/2,r,k*2+1);\r\
    \n\t}\r\n\tint count(int a,int b){\r\n//\t\tprintf(\"count [0,%d)*[0,%d)\\n\"\
    ,a,b);\r\n\t\treturn count(0,a,0,b,0,N,1);\r\n\t}\r\n};\n"
  code: "/*\r\n\t2\u6B21\u5143(N*N grid) \u3067point add, range sum \u304C\u51FA\u6765\
    \u308B\r\n\tseg.add(x,y) seg.count(x1,x2,y1,y2)\r\n\tpoint \u306B\u91CD\u307F\u3092\
    \u3064\u3051\u308B\u306B\u306F\u7D50\u69CB\u66F8\u304D\u63DB\u3048\u308B\u5FC5\
    \u8981\u304C\u3042\u308B\u3068\u601D\u3046(Node \u306B\u5024\u3082\u305F\u305B\
    \u308B, lower_bound \u8AAD\u3093\u3067\u308B\u3068\u3053\u3082sum\u306B\u66F8\u304D\
    \u63DB\u3048\u308B\u5FC5\u8981\u304C\u3042\u308B)\r\n\r\n\tO(Nlog^2N) \u3060\u3051\
    \u3069\u5B9A\u6570\u500D\u3067\u304B\u306A\u308A\u9045\u3044 N=10^5 \u3067 1sec\
    \ \u3068\u304B\u305D\u306E\u304F\u3089\u3044\r\n\r\n*/\r\ntemplate<class T>\r\n\
    struct SplayTree{\r\n\tstruct Node;\r\n\ttypedef Node* NP;\r\n\tstatic NP nil;\r\
    \n\tstruct Node{\r\n\t\tNP p,l,r;\t\t\t//parent,left child,right child\r\n\t\t\
    int sz;\r\n\t\tint v;\r\n\t\tNode(int v) :p(nullptr),l(nil),r(nil),sz(1),v(v){}\r\
    \n\t\tNode() : p(nullptr),l(nullptr),r(nullptr),sz(0),v(0){}\t\t\t\t\t\t//\u5358\
    \u4F4D\u5143!!\r\n\t\tint pos(){\t\t\t//\u89AA\u306E\u5DE6\u306E\u5B50\u304B,\u53F3\
    \u306E\u5B50\u304B,\u305D\u308C\u3068\u3082\u6839(or null)\u304B\r\n\t\t\tif(p&&p->l\
    \ == this) return -1;\r\n\t\t\tif(p&&p->r == this) return 1;\r\n\t\t\treturn 0;\r\
    \n\t\t}\r\n\t\tvoid rot(){\t\t\t\t//root\u3067\u547C\u3076\u3068\u6B7B\r\n\t\t\
    \tNP pp=p->p;\t\t\t//\u89AA\u306E\u89AA\r\n\t\t\tint pps=p->pos();\t//pp\u304B\
    \u3089\u307F\u305Fp\u306E\u5DE6\u53F3\r\n\t\t\tif(p->l==this){\t\t//pos()==-1\r\
    \n\t\t\t\tp->l=r,r->p=p,r=p,p->p=this;\r\n\t\t\t}else{\r\n\t\t\t\tp->r=l,l->p=p,l=p,p->p=this;\r\
    \n\t\t\t}\r\n\t\t\t//\u65B0\u3057\u3044\u6728\u3067\u4E0B\u304B\u3089update\r\n\
    \t\t\tp->update();\r\n\t\t\tupdate();\r\n\t\t\tp=pp;\r\n\t\t\tif(pps==0) return;\r\
    \n\t\t\tif(pps==-1) pp->l=this;\r\n\t\t\telse pp->r=this;\r\n\t\t\tpp->update();\r\
    \n\t\t}\r\n\t\tvoid splay(){\t\t\t//this\u3092root\u306B\u3082\u3063\u3066\u304F\
    \u308B\r\n\t\t\twhile(true){\r\n\t\t\t\tint ps=pos();\r\n\t\t\t\tif(ps==0) break;\r\
    \n\t\t\t\tint pps=p->pos();\r\n\t\t\t\tif(pps==0){\t\t//zig\r\n\t\t\t\t\trot();\r\
    \n\t\t\t\t}else if(ps==pps){\t\t//zigzig\r\n\t\t\t\t\tp->rot();rot();\r\n\t\t\t\
    \t}else{\t\t\t\t\t//zigzag\r\n\t\t\t\t\trot();rot();\r\n\t\t\t\t}\r\n\t\t\t}\r\
    \n\t\t}\r\n\t\tNP splay(int k){\t\t\t//\u3053\u306E\u533A\u9593\u306E\u5DE6\u304B\
    \u3089kth(0-indexed)\u3092root\u306B\u3082\u3063\u3066\u304D\u3066\u305D\u306E\
    \u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\u3059(sz\u304C\u5FC5\u8981)\r\n\t\t\t//assert(0<=k&&k<sz);\r\
    \n\t\t\tif(k<l->sz){\r\n\t\t\t\treturn l->splay(k);\r\n\t\t\t}else if(k==l->sz){\r\
    \n\t\t\t\tsplay();\r\n\t\t\t\treturn this;\r\n\t\t\t}else{\r\n\t\t\t\treturn r->splay(k-(l->sz+1));\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\tNP update(){\t\t//\u60C5\u5831\u66F4\u65B0(\u5B50\u304C\
    \u6B63\u3057\u3044\u6642\u306B\u547C\u3070\u306A\u3044\u3068\u30C0\u30E1) (\u6700\
    \u5F8C\u306Bupdate\u3057\u3066return\u3059\u308B\u306E\u306B\u697D\u306A\u306E\
    \u3067NP\u3092\u8FD4\u3059)\r\n\t\t\tsz=1+l->sz+r->sz;\r\n\t\t\treturn this;\r\
    \n\t\t}\r\n\r\n\t};\r\n\tNP n;\r\n\tstatic NP merge(NP l,NP r){\t\t\t//merge\u3057\
    \u305F\u6839\r\n\t\tif(r==nil) return l;\r\n\t\tr=r->splay(0);\r\n\t\tr->l=l;\r\
    \n\t\tl->p=r;\r\n\t\treturn r->update();\r\n\t}\r\n\t/*\r\n\t\tkth\u3067split(k=0\u306A\
    \u3089fs=null)\r\n\t\tl\u306F\u5B8C\u5168\u306B\u5207\u308A\u96E2\u3055\u308C\u3066\
    \u308B\u3051\u308C\u3069\r\n\t\tr\u306F\u4E0A\u3068\u3064\u306A\u304C\u3063\u3066\
    \u3044\u308B?\r\n\t\t\u307E\u3042\u3067\u3082\u57FA\u672C\u7684\u306Bsplit\u306E\
    \u7B2C\u4E00\u5F15\u6570\u306Froot\u306A\u306E\u3067\u5927\u4E08\u592B\r\n\t*/\r\
    \n\tstatic pair<NP,NP> split(NP x,int k){\r\n\t\t//assert(0<=k&&k<=x->sz);\r\n\
    \t\tif(k==x->sz) return {x,nil};\r\n\t\tx=x->splay(k);\r\n\t\tNP l=x->l;\r\n\t\
    \tl->p = nullptr;\r\n\t\tx->l = nil;\r\n\t\treturn {l,x->update()};\r\n\t}\r\n\
    \tstatic NP built(int sz,int vs[]){\t\t\t\t//init\r\n\t\tif(!sz) return nil;\r\
    \n\t\tint md=sz/2;\r\n\t\tNP x= new Node(vs[md]);\r\n\t\tx->l = built(md,vs);\r\
    \n\t\tx->l->p=x;\r\n\t\tx->r=built(sz-(md+1),vs+md+1);\r\n\t\tx->r->p=x;\r\n\t\
    \treturn x->update();\r\n\t}\r\n\tSplayTree() : n(nil){}\r\n\tSplayTree(NP n)\
    \ : n(n){}\r\n\tSplayTree(int sz,int vs[]){\r\n\t\tn=built(sz,vs);\r\n\t}\r\n\t\
    void insert(int k,int v){\r\n\t\tauto u=split(n,k);\r\n\t\tn=merge(merge(u.fs,new\
    \ Node(v)),u.sc);\r\n\t}\r\n\tvoid insert(int v){\r\n\t\tint k=lower_bound(v);\r\
    \n\t\tinsert(k,v);\r\n\t}\r\n\tvoid erase(int k){\r\n\t\tauto u=split(n,k);\r\n\
    \t\tn=merge(u.fs,split(u.sc,1).sc);\r\n\t}\r\n\tvoid merge(SplayTree t){\r\n\t\
    \tn=merge(n,t.n);\r\n\t}\r\n\tint sz(){\r\n\t\treturn n->sz;\r\n\t}\r\n\tint get(int\
    \ k){\t\t\t//kth info\r\n\t\tauto a=split(n,k);\r\n\t\tauto b=split(a.sc,1);\r\
    \n\t\tint ret=b.fs->v;\r\n\t\tn=merge(merge(a.fs,b.fs),b.sc);\r\n\t\treturn ret;\r\
    \n\t}\r\n\t/*\r\n\t\tsearch\r\n\t\t\u5E73\u8861\u4E8C\u5206\u6728\u3068\u3057\u3066\
    \u306E\u5F79\u76EE\u3092\u601D\u3044\u51FA\u305B\r\n\t\t\u306A\u3093\u304B\u5217\
    \u3092\u304F\u3063\u3064\u3051\u305F\u308A\u308F\u3051\u305F\u308A\u3067\u304D\
    \u308B\u3068\u3060\u3051\u601D\u3063\u3068\u3051\u3070\u57FA\u672C\u3044\u3044\
    \u3051\u3069\r\n\t\t\u6301\u3063\u3066\u308B\u30C7\u30FC\u30BF\u306B\u9806\u5E8F\
    \u4ED8\u3044\u3066\u308B\u3068\u304D\u306B\u306F\u3061\u3083\u3093\u3068\u4E8C\
    \u5206\u6728\u3068\u3057\u3066\u4F7F\u3048\u308B\r\n\t*/\r\n\tint lower_bound(int\
    \ x){\t\t//x\u4EE5\u4E0A\u3067\u4E00\u756A\u5C0F\u3055\u3044\u3068\u3053\u306E\
    id\u3092\u8FD4\u3059\r\n\t\tNP p=n;\r\n\t\tint ret=0;\r\n\t\twhile(p!=nil){\r\n\
    \t\t\tif(x<=p->v) p=p->l;\r\n\t\t\telse ret+=(p->l->sz)+1,p=p->r;\r\n\t\t}\r\n\
    \t\treturn ret;\r\n\t}\r\n\tint upper_bound(int x){\t\t//x\u3088\u308A\u5927\u3067\
    \u4E00\u756A\u5C0F\u3055\u3044\u3068\u3053\u306Eid\u3092\u8FD4\u3059\r\n\t\tNP\
    \ p=n;\r\n\t\tint ret=0;\r\n\t\twhile(p!=nil){\r\n\t\t\tif(x<p->v) p=p->l;\r\n\
    \t\t\telse ret+=(p->l->sz)+1,p=p->r;\r\n\t\t}\r\n\t\treturn ret;\r\n\t}\r\n};\r\
    \ntemplate<class T>\r\ntypename SplayTree<T>::NP SplayTree<T>::nil = new SplayTree<T>::Node();\r\
    \n\r\nstruct segtree{\r\n\tint N;\r\n\tvector< SplayTree<int> > seg;\r\n\tsegtree(int\
    \ n){\r\n\t\tint p2=1;\r\n\t\twhile(p2<n) p2*=2;\r\n\t\tN=p2;\r\n\t\tseg.resize(N*2);\r\
    \n\t}\r\n\tvoid add(int x,int y){\t\t\t//add P(x,y)\r\n\t\tx+=N;\r\n\t\twhile(x){\r\
    \n\t\t\tseg[x].insert(y);\r\n\t\t\tx/=2;\r\n\t\t}\r\n\t}\r\n\tint count(int a,int\
    \ b,int ya,int yb,int l,int r,int k){\t\t//[a,b) * [ya,yb)\r\n\t\tif(b<=l||r<=a)\
    \ return 0;\r\n\t\tif(a<=l&&r<=b) return seg[k].lower_bound(yb) - seg[k].lower_bound(ya);\r\
    \n\t\treturn count(a,b,ya,yb,l,(l+r)/2,k*2)+count(a,b,ya,yb,(l+r)/2,r,k*2+1);\r\
    \n\t}\r\n\tint count(int a,int b){\r\n//\t\tprintf(\"count [0,%d)*[0,%d)\\n\"\
    ,a,b);\r\n\t\treturn count(0,a,0,b,0,N,1);\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/2D/splay_2Dsegtree.cpp
  requiredBy: []
  timestamp: '2024-01-03 19:12:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/2D/splay_2Dsegtree.cpp
layout: document
redirect_from:
- /library/ds/2D/splay_2Dsegtree.cpp
- /library/ds/2D/splay_2Dsegtree.cpp.html
title: ds/2D/splay_2Dsegtree.cpp
---
