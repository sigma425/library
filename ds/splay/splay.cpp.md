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
  bundledCode: "#line 1 \"ds/splay/splay.cpp\"\n/*\r\nSplayTree(\u304B\u3093\u305F\
    \u3093ver)\r\nsimple_segtree\u306E\u4E0A\u4F4D\u4E92\u63DB.query(l,r), assign(x,d)\u306F\
    \u540C\u3058\u4F7F\u3044\u65B9\u304C\u51FA\u6765\u308B.\r\nverified by AOJ1508(circular\
    \ RMQ)\r\n\u5217\u306B\u5206\u5272\u3059\u308B\u3068\u304D\u306F,split\u95A2\u6570\
    \u3092\u5916\u3067\u5B9A\u7FA9\u3057\u306A\u3044\u3068\u304F\u3063\u305D\u66F8\
    \u304D\u3065\u3089\u3044\u306E\u3067\u305D\u3046\u3059\u308B\r\n\r\nSplayTree<Dmin>::NP\
    \ merge(SplayTree<Dmin>::NP x, SplayTree<Dmin>::NP y){\r\n\treturn SplayTree<Dmin>::merge(x,y);\r\
    \n}\r\npair<SplayTree<Dmin>::NP,SplayTree<Dmin>::NP> split(SplayTree<Dmin>::NP\
    \ x, int k){\r\n\treturn SplayTree<Dmin>::split(x,k);\r\n}\r\n\r\n*/\r\n#include\
    \ <bits/stdc++.h>\r\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\r\n#define rep1(i,n)\
    \ for(int i=1;i<=(int)(n);i++)\r\n#define all(c) c.begin(),c.end()\r\n#define\
    \ pb push_back\r\n#define fs first\r\n#define sc second\r\n#define show(x) cout\
    \ << #x << \" = \" << x << endl\r\n#define chmin(x,y) x=min(x,y)\r\n#define chmax(x,y)\
    \ x=max(x,y)\r\nusing namespace std;\r\n\r\ntemplate<class D>\r\nstruct SplayTree{\r\
    \n\tstruct Node;\r\n\tusing NP = Node*;\r\n\tstatic NP nil;\r\n\r\n\tstruct Node{\r\
    \n\t\tNP p,l,r;\r\n\t\tint sz;\r\n\t\tD v,sm;\r\n\t\tNode(D v) :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v){}\r\
    \n\t\tNode() : p(nullptr),l(nullptr),r(nullptr),sz(0),v(D::e()),sm(D::e()){}\r\
    \n\t\tint pos(){\t\t\t//\u89AA\u306E\u5DE6\u306E\u5B50\u304B,\u53F3\u306E\u5B50\
    \u304B,\u305D\u308C\u3068\u3082\u6839(or nil)\u304B\r\n\t\t\tif(p&&p->l == this)\
    \ return -1;\r\n\t\t\tif(p&&p->r == this) return 1;\r\n\t\t\treturn 0;\r\n\t\t\
    }\r\n\t\tvoid rot(){\t\t\t\t//root\u3067\u547C\u3076\u3068\u6B7B\r\n\t\t\tassert(p\
    \ != nullptr);\r\n\t\t\tNP pp=p->p;\r\n\t\t\tint pps=p->pos();\r\n\t\t\tif(p->l==this){\r\
    \n\t\t\t\tp->l=r,r->p=p,r=p,p->p=this;\r\n\t\t\t}else{\r\n\t\t\t\tp->r=l,l->p=p,l=p,p->p=this;\r\
    \n\t\t\t}\r\n\t\t\tp->update();\r\n//\t\t\tupdate();\tzig,zig-zag,zig-zig\u3068\
    \u3082\u306B\u3069\u3046\u305B\u6B21\u3067update\u304C\u3088\u3070\u308C\u308B\
    \u306E\u3067\u3044\u3089\u306A\u3044(\u6700\u5F8C\u6839\u306F\u3044\u308B\u2190\
    \u3053\u308C\u5B9F\u306Fmerge/split\u3067\u3061\u3083\u3093\u3068update\u3057\u3066\
    \u308B\u304B\u3089\u66F8\u304B\u306A\u304F\u3066\u3044\u3044\u3093\u3060\u3088\
    \u306D)\r\n\t\t\tp=pp;\r\n\t\t\tif(pps==0) return;\r\n\t\t\tif(pps==-1) pp->l=this;\r\
    \n\t\t\telse pp->r=this;\r\n\t\t}\r\n\t\tvoid splay(){\t\t\t//this\u3092root\u306B\
    \u3082\u3063\u3066\u304F\u308B\r\n\t\t\twhile(true){\r\n\t\t\t\tint ps=pos();\r\
    \n\t\t\t\tif(ps==0) break;\r\n\t\t\t\tint pps=p->pos();\r\n\t\t\t\tif(pps==0){\t\
    \t//zig\r\n\t\t\t\t\trot();\r\n\t\t\t\t}else if(ps==pps){\t\t//zigzig\r\n\t\t\t\
    \t\tp->rot();rot();\r\n\t\t\t\t}else{\t\t\t\t\t//zigzag\r\n\t\t\t\t\trot();rot();\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tupdate();\t\t\t//merge/split\u4EE5\u5916\u304B\
    \u3089\u547C\u3070\u308C\u308B\u304B\u3082\u3057\u308C\u306A\u3044\u306E\u3067\
    \u4E00\u5FDC\u3064\u3051\u3066\u304A\u304F\r\n\t\t}\r\n\t\tNP splay(int k){\t\t\
    \t//\u3053\u306E\u533A\u9593\u306E\u5DE6\u304B\u3089kth(0-indexed)\u3092root\u306B\
    \u3082\u3063\u3066\u304D\u3066\u305D\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\
    \u3059\r\n\t\t\tassert(0<=k&&k<sz);\r\n\t\t\tif(k<l->sz){\r\n\t\t\t\treturn l->splay(k);\r\
    \n\t\t\t}else if(k==l->sz){\r\n\t\t\t\tsplay();\r\n\t\t\t\treturn this;\r\n\t\t\
    \t}else{\r\n\t\t\t\treturn r->splay(k-(l->sz+1));\r\n\t\t\t}\r\n\t\t}\r\n\t\t\
    NP update(){\t\t//\u60C5\u5831\u66F4\u65B0(\u5B50\u304C\u6B63\u3057\u3044\u6642\
    \u306B\u547C\u3070\u306A\u3044\u3068\u30C0\u30E1) (\u6700\u5F8C\u306Bupdate\u3057\
    \u3066return\u3059\u308B\u306E\u306B\u697D\u306A\u306E\u3067NP\u3092\u8FD4\u3059\
    )\r\n\t\t\tsz=1+l->sz+r->sz;\r\n\t\t\tsm = v;\r\n\t\t\tif(l->sz) sm = l->sm +\
    \ sm;\t//if(l) \u3060\u3068nil\u3067\u3082\u547C\u3076\u7FBD\u76EE\u306B\u306A\
    \u308A\u305D\u3046\r\n\t\t\tif(r->sz) sm = sm + r->sm;\r\n\t\t\treturn this;\r\
    \n\t\t}\r\n\r\n\t\tvoid showtree(){\r\n\t\t\tcout<<\"[\";\r\n\t\t\tif(l->sz) l->showtree();\r\
    \n\t\t\tcout<<v;\r\n\t\t\tif(r->sz) r->showtree();\r\n\t\t\tcout<<\"]\";\r\n\t\
    \t}\r\n\r\n\t};\r\n\tNP n;\r\n\r\n\t/*\r\n\t\t(r!=nil\u306A\u3089)r\u306E\u5DE6\
    \u7AEF\u304C\u6839\u306B\u306A\u308B\r\n\t\t\u305D\u306E\u5DE6\u306E\u5B50\u304C\
    l\r\n\t*/\r\n\tstatic NP merge(NP l,NP r){\r\n\t\tif(r==nil) return l;\r\n\t\t\
    r=r->splay(0);\r\n\t\tr->l=l;\r\n\t\tl->p=r;\r\n\t\treturn r->update();\r\n\t\
    }\r\n\t/*\r\n\t\tkth\u3067split(k=0\u306A\u3089fs=null)\r\n\t\t\u3068\u308A\u3042\
    \u3048\u305Ak\u500B\u76EE\u3092\u6301\u3063\u3066\u304D\u3066\u3001pair(\u305D\
    \u308C\u672A\u6E80,\u305D\u308C\u4EE5\u4E0A)\u3092\u8FD4\u3059.\u4E0A\u306B\u3064\
    \u306A\u304C\u3063\u3066\u3044\u308B\u306E\u306F(\u305D\u308C\u4EE5\u4E0A)\u306E\
    \u65B9,\u3068\u3044\u3046\u304Bk\r\n\t\t\u57FA\u672C\u7684\u306Bsplit\u306E\u7B2C\
    \u4E00\u5F15\u6570\u306Froot\u306A\u306E\u3067?\u305D\u3093\u306A\u306B\u6C17\u306B\
    \u3057\u306A\u304F\u3066\u3044\u3044\u304B\u306A\r\n\t\t\u5168\u533A\u9593\u3092\
    split\u3057\u3066\u304F ([1,2,3,4] -> [1,2][3,4] -> [1][2][3,4]) \u3076\u3093\u306B\
    \u306F\u5E38\u306Broot\u306A\u305F\u3081\r\n\t*/\r\n\tstatic pair<NP,NP> split(NP\
    \ x,int k){\r\n\t\tassert(0<=k&&k<=x->sz);\r\n\t\tif(k==x->sz) return {x,nil};\r\
    \n\t\tx=x->splay(k);\r\n\t\tNP l=x->l;\r\n\t\tl->p = nullptr;\r\n\t\tx->l = nil;\r\
    \n\t\treturn {l,x->update()};\r\n\t}\r\n\tstatic NP build(int sz,D vs[]){\t\t\t\
    \t//init\r\n\t\tif(!sz) return nil;\r\n\t\tint md=sz/2;\r\n\t\tNP x= new Node(vs[md]);\r\
    \n\t\tx->l = build(md,vs);\r\n\t\tx->l->p=x;\r\n\t\tx->r=build(sz-(md+1),vs+md+1);\r\
    \n\t\tx->r->p=x;\r\n\t\treturn x->update();\r\n\t}\r\n\tstatic NP build(const\
    \ vector<D>& vs){\r\n\t\treturn build(vs.size(),vs,0);\r\n\t}\r\n\tstatic NP build(int\
    \ sz,const vector<D>& vs,int off){\t\t\t\t//init\r\n\t\tif(!sz) return nil;\r\n\
    \t\tint md=sz/2;\r\n\t\tNP x= new Node(vs[off+md]);\r\n\t\tx->l = build(md,vs,off);\r\
    \n\t\tx->l->p=x;\r\n\t\tx->r=build(sz-(md+1),vs,off+md+1);\r\n\t\tx->r->p=x;\r\
    \n\t\treturn x->update();\r\n\t}\r\n\r\n\tSplayTree() : n(nil){}\r\n\tSplayTree(NP\
    \ n) : n(n){}\r\n\tSplayTree(int sz,D vs[]){\r\n\t\tn=build(sz,vs);\r\n\t}\r\n\
    \tSplayTree(vector<D> vs){\r\n\t\tn=build(vs);\r\n\t}\r\n\r\n\tvoid insert(int\
    \ k,D v){\r\n\t\tauto u=split(n,k);\r\n\t\tn=merge(merge(u.fs,new Node(v)),u.sc);\r\
    \n\t}\r\n\tvoid erase(int k){\r\n\t\tauto u=split(n,k);\r\n\t\tn=merge(u.fs,split(u.sc,1).sc);\r\
    \n\t}\r\n\tvoid merge(SplayTree t){\r\n\t\tn=merge(n,t.n);\r\n\t}\r\n\tint sz(){\r\
    \n\t\treturn n->sz;\r\n\t}\r\n\tD get(int k){\t\t\t//kth info\r\n\t\tauto a=split(n,k);\r\
    \n\t\tauto b=split(a.sc,1);\r\n\t\tD ret=b.fs->v;\r\n\t\tn=merge(merge(a.fs,b.fs),b.sc);\r\
    \n\t\treturn ret;\r\n\t}\r\n\tvoid assign(int k,D d){\r\n\t\tauto a = split(n,k);\r\
    \n\t\tauto b = split(a.sc,1);\r\n\t\tn = merge(merge(a.fs,new Node(d)),b.sc);\r\
    \n\t}\r\n\tD query(int l,int r){\t\t\t//[l,r)\r\n\t\tauto b=split(n,r);\r\n\t\t\
    auto a=split(b.fs,l);\r\n\t\tD ret=a.sc->sm;\r\n\t\tn=merge(merge(a.fs,a.sc),b.sc);\r\
    \n\t\treturn ret;\r\n\t}\r\n\r\n\t/*\r\n\t\tsearch\r\n\t\t\u5E73\u8861\u4E8C\u5206\
    \u6728\u3068\u3057\u3066\u306E\u5F79\u76EE\u3092\u601D\u3044\u51FA\u305B\r\n\t\
    \t\u306A\u3093\u304B\u5217\u3092\u304F\u3063\u3064\u3051\u305F\u308A\u308F\u3051\
    \u305F\u308A\u3067\u304D\u308B\u3068\u3060\u3051\u601D\u3063\u3068\u3051\u3070\
    \u57FA\u672C\u3044\u3044\u3051\u3069\r\n\t\t\u6301\u3063\u3066\u308B\u30C7\u30FC\
    \u30BF\u306B\u9806\u5E8F\u4ED8\u3044\u3066\u308B\u3068\u304D\u306B\u306F\u3061\
    \u3083\u3093\u3068\u4E8C\u5206\u6728\u3068\u3057\u3066\u4F7F\u3048\u308B\r\n\t\
    \tD \u306B operator< \u3068 operator<= \u304C\u5FC5\u8981\r\n\t*/\r\n\tint lower_bound(D\
    \ x){\t\t//x\u4EE5\u4E0A\u3067\u4E00\u756A\u5C0F\u3055\u3044\u3068\u3053\u306E\
    id\u3092\u8FD4\u3059\r\n\t\tNP p=n;\r\n\t\tint ret=0;\r\n\t\twhile(p!=nil){\r\n\
    \t\t\tif(x<=p->v) p=p->l;\r\n\t\t\telse ret+=(p->l->sz)+1,p=p->r;\r\n\t\t}\r\n\
    \t\treturn ret;\r\n\t}\r\n\tint upper_bound(D x){\t\t//x\u3088\u308A\u5927\u3067\
    \u4E00\u756A\u5C0F\u3055\u3044\u3068\u3053\u306Eid\u3092\u8FD4\u3059\r\n\t\tNP\
    \ p=n;\r\n\t\tint ret=0;\r\n\t\twhile(p!=nil){\r\n\t\t\tif(x<p->v) p=p->l;\r\n\
    \t\t\telse ret+=(p->l->sz)+1,p=p->r;\r\n\t\t}\r\n\t\treturn ret;\r\n\t}\r\n\r\n\
    \t/*\r\n\t\tdebug\r\n\t\tstruct D \u306B << \u304C\u306A\u3044\u3068\u3060\u3081\
    \r\n\t*/\r\n\tvoid showtree(){\r\n\t\tn->showtree();\r\n\t\tcout<<endl;\r\n\t\
    }\r\n};\r\n\r\n\r\nstruct Dmin{\t\t//(int,min,inf)\r\n\tint x;\r\n\tDmin(){}\r\
    \n\tDmin(int x):x(x){}\r\n\tstatic Dmin e(){\r\n\t\treturn Dmin(1e9);\r\n\t}\r\
    \n\tDmin operator+(const Dmin& r) const {\r\n\t\treturn Dmin(min(x,r.x));\r\n\t\
    }\r\n\tfriend ostream& operator<<(ostream& o,const Dmin& d){return o<<d.x;}\r\n\
    };\r\ntemplate<>\r\nSplayTree<Dmin>::NP SplayTree<Dmin>::nil = new SplayTree<Dmin>::Node();\r\
    \n\r\nSplayTree<Dmin>::NP merge(SplayTree<Dmin>::NP x, SplayTree<Dmin>::NP y){\r\
    \n\treturn SplayTree<Dmin>::merge(x,y);\r\n}\r\npair<SplayTree<Dmin>::NP,SplayTree<Dmin>::NP>\
    \ split(SplayTree<Dmin>::NP x, int k){\r\n\treturn SplayTree<Dmin>::split(x,k);\r\
    \n}\r\n\r\n/*\r\nstruct Dmat{\r\n\tusing T = int;\r\n\tusing D = Dmat;\r\n\tconst\
    \ static int N = 5;\r\n\tusing V = array<T,N>;\r\n\tusing VV = array<V,N>;\r\n\
    \tVV a;\r\n\tDmat(){}\r\n\tDmat(VV a):a(a){}\r\n\tconst static D e(){\r\n\t\t\
    VV a;\r\n\t\trep(i,N) rep(j,N) a[i][j] = (i==j?1:0);\r\n\t\treturn D(a);\r\n\t\
    }\r\n\tD operator+(const D& r) const {\r\n\t\tVV c;\r\n\t\trep(i,N) rep(j,N) c[i][j]=0;\r\
    \n\t\trep(i,N) rep(j,N) rep(k,N) c[i][j] += a[i][k] * r.a[k][j];\r\n\t\treturn\
    \ D(c);\r\n\t};\r\n\tbool operator==(const D& r) const {\r\n\t\treturn a==r.a;\r\
    \n\t}\r\n};\r\ntemplate<>\r\nSplayTree<Dmat>::NP SplayTree<Dmat>::nil = new SplayTree<Dmat>::Node();\r\
    \n\r\n*/\r\n\r\nvoid unittest(){\r\n\t{\r\n\t\tusing D = Dmin;\r\n\t\tvector<D>\
    \ vc;\r\n\t\tint N = 100;\r\n\t\trep(i,N) vc.pb(Dmin(rand()%1000));\r\n\t\tSplayTree<Dmin>\
    \ Stree(vc);\r\n\t\trep(l,N) for(int r=l;r<=N;r++){\r\n\t\t\tint mn = 1e9;\r\n\
    \t\t\tfor(int i=l;i<r;i++) chmin(mn,vc[i].x);\r\n\t\t\tassert( Stree.query(l,r).x\
    \ == mn);\r\n\t\t}\r\n\t}\r\n\t{\r\n\t\tusing D = Dmat;\r\n\t\tconst int K = Dmat::N;\r\
    \n\t\tusing T = int;\r\n\t\tusing V = array<T,K>;\r\n\t\tusing VV = array<V,K>;\r\
    \n\r\n\t\tvector<D> vs;\r\n\t\tint N = 100;\r\n\t\trep(i,N){\r\n\t\t\tVV a;\r\n\
    \t\t\trep(x,K) rep(y,K) a[x][y] = rand()%201+100;\r\n\t\t\tvs.push_back(D(a));\r\
    \n\t\t}\r\n//\t\tsegtree_simple<D> seg(vs);\r\n\t\tSplayTree<D> Stree(vs);\r\n\
    \t\trep(qt,1000){\r\n\t\t\tif(rand()%2){\r\n\t\t\t\tVV a;\r\n\t\t\t\trep(x,K)\
    \ rep(y,K) a[x][y] = rand()%201+100;\r\n\t\t\t\tint idx = rand()%N;\r\n\t\t\t\t\
    vs[idx] = D(a);\r\n\t\t\t\tStree.assign(idx,D(a));\r\n\t\t\t}else{\r\n\t\t\t\t\
    int l = rand()%100, r = rand()%100;\r\n\t\t\t\tif(l>r) swap(l,r);\r\n\t\t\t\t\
    r++;\r\n\t\t\t\tD x = D::e();\r\n\t\t\t\tfor(int i=l;i<r;i++) x = x+vs[i];\r\n\
    \t\t\t\tassert( Stree.query(l,r) == x );\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n}\r\n\r\
    \nint main(){\r\n\tsrand((unsigned)time(NULL));\r\n\tunittest();\r\n\r\n// \t\
    int N,Q;\t//AOJ1508\r\n// \tvector<D> vs;\r\n// \tcin>>N>>Q;\r\n// \trep(i,N){\r\
    \n// \t\tint x;\r\n// \t\tcin>>x;\r\n// \t\tvs.pb(D(x));\r\n// \t}\r\n// \tSplayTree<D>\
    \ st(vs);\r\n// \trep(qt,Q){\r\n// \t\tint x,y,z;\r\n// \t\tcin>>x>>y>>z;\r\n\
    // \t\tif(x==0){\t//[y..z-1][z] -> [z][y..z-1]\r\n// \t\t\tauto a = split(st.n,y);\t\
    //[0..y-1][y..N-1]\r\n// \t\t\tauto b = split(a.sc,z-y+1);\t//[y..z][~]\r\n//\
    \ \t\t\tauto c = split(b.fs,z-y);\t\t//[y..z-1][z]\r\n// \t\t\tst.n = merge(merge(a.fs,c.sc),merge(c.fs,b.sc));\r\
    \n// \t\t}\r\n// \t\tif(x==1){\r\n// \t\t\tcout<<st.query(y,z+1).x<<endl;\r\n\
    // \t\t}\r\n// \t\tif(x==2){\r\n// \t\t\tst.assign(y,z);\r\n// \t\t}\r\n// //\t\
    \tst.showtree();\r\n// \t}\r\n}\r\n"
  code: "/*\r\nSplayTree(\u304B\u3093\u305F\u3093ver)\r\nsimple_segtree\u306E\u4E0A\
    \u4F4D\u4E92\u63DB.query(l,r), assign(x,d)\u306F\u540C\u3058\u4F7F\u3044\u65B9\
    \u304C\u51FA\u6765\u308B.\r\nverified by AOJ1508(circular RMQ)\r\n\u5217\u306B\
    \u5206\u5272\u3059\u308B\u3068\u304D\u306F,split\u95A2\u6570\u3092\u5916\u3067\
    \u5B9A\u7FA9\u3057\u306A\u3044\u3068\u304F\u3063\u305D\u66F8\u304D\u3065\u3089\
    \u3044\u306E\u3067\u305D\u3046\u3059\u308B\r\n\r\nSplayTree<Dmin>::NP merge(SplayTree<Dmin>::NP\
    \ x, SplayTree<Dmin>::NP y){\r\n\treturn SplayTree<Dmin>::merge(x,y);\r\n}\r\n\
    pair<SplayTree<Dmin>::NP,SplayTree<Dmin>::NP> split(SplayTree<Dmin>::NP x, int\
    \ k){\r\n\treturn SplayTree<Dmin>::split(x,k);\r\n}\r\n\r\n*/\r\n#include <bits/stdc++.h>\r\
    \n#define rep(i,n) for(int i=0;i<(int)(n);i++)\r\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\r\
    \n#define all(c) c.begin(),c.end()\r\n#define pb push_back\r\n#define fs first\r\
    \n#define sc second\r\n#define show(x) cout << #x << \" = \" << x << endl\r\n\
    #define chmin(x,y) x=min(x,y)\r\n#define chmax(x,y) x=max(x,y)\r\nusing namespace\
    \ std;\r\n\r\ntemplate<class D>\r\nstruct SplayTree{\r\n\tstruct Node;\r\n\tusing\
    \ NP = Node*;\r\n\tstatic NP nil;\r\n\r\n\tstruct Node{\r\n\t\tNP p,l,r;\r\n\t\
    \tint sz;\r\n\t\tD v,sm;\r\n\t\tNode(D v) :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v){}\r\
    \n\t\tNode() : p(nullptr),l(nullptr),r(nullptr),sz(0),v(D::e()),sm(D::e()){}\r\
    \n\t\tint pos(){\t\t\t//\u89AA\u306E\u5DE6\u306E\u5B50\u304B,\u53F3\u306E\u5B50\
    \u304B,\u305D\u308C\u3068\u3082\u6839(or nil)\u304B\r\n\t\t\tif(p&&p->l == this)\
    \ return -1;\r\n\t\t\tif(p&&p->r == this) return 1;\r\n\t\t\treturn 0;\r\n\t\t\
    }\r\n\t\tvoid rot(){\t\t\t\t//root\u3067\u547C\u3076\u3068\u6B7B\r\n\t\t\tassert(p\
    \ != nullptr);\r\n\t\t\tNP pp=p->p;\r\n\t\t\tint pps=p->pos();\r\n\t\t\tif(p->l==this){\r\
    \n\t\t\t\tp->l=r,r->p=p,r=p,p->p=this;\r\n\t\t\t}else{\r\n\t\t\t\tp->r=l,l->p=p,l=p,p->p=this;\r\
    \n\t\t\t}\r\n\t\t\tp->update();\r\n//\t\t\tupdate();\tzig,zig-zag,zig-zig\u3068\
    \u3082\u306B\u3069\u3046\u305B\u6B21\u3067update\u304C\u3088\u3070\u308C\u308B\
    \u306E\u3067\u3044\u3089\u306A\u3044(\u6700\u5F8C\u6839\u306F\u3044\u308B\u2190\
    \u3053\u308C\u5B9F\u306Fmerge/split\u3067\u3061\u3083\u3093\u3068update\u3057\u3066\
    \u308B\u304B\u3089\u66F8\u304B\u306A\u304F\u3066\u3044\u3044\u3093\u3060\u3088\
    \u306D)\r\n\t\t\tp=pp;\r\n\t\t\tif(pps==0) return;\r\n\t\t\tif(pps==-1) pp->l=this;\r\
    \n\t\t\telse pp->r=this;\r\n\t\t}\r\n\t\tvoid splay(){\t\t\t//this\u3092root\u306B\
    \u3082\u3063\u3066\u304F\u308B\r\n\t\t\twhile(true){\r\n\t\t\t\tint ps=pos();\r\
    \n\t\t\t\tif(ps==0) break;\r\n\t\t\t\tint pps=p->pos();\r\n\t\t\t\tif(pps==0){\t\
    \t//zig\r\n\t\t\t\t\trot();\r\n\t\t\t\t}else if(ps==pps){\t\t//zigzig\r\n\t\t\t\
    \t\tp->rot();rot();\r\n\t\t\t\t}else{\t\t\t\t\t//zigzag\r\n\t\t\t\t\trot();rot();\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tupdate();\t\t\t//merge/split\u4EE5\u5916\u304B\
    \u3089\u547C\u3070\u308C\u308B\u304B\u3082\u3057\u308C\u306A\u3044\u306E\u3067\
    \u4E00\u5FDC\u3064\u3051\u3066\u304A\u304F\r\n\t\t}\r\n\t\tNP splay(int k){\t\t\
    \t//\u3053\u306E\u533A\u9593\u306E\u5DE6\u304B\u3089kth(0-indexed)\u3092root\u306B\
    \u3082\u3063\u3066\u304D\u3066\u305D\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\
    \u3059\r\n\t\t\tassert(0<=k&&k<sz);\r\n\t\t\tif(k<l->sz){\r\n\t\t\t\treturn l->splay(k);\r\
    \n\t\t\t}else if(k==l->sz){\r\n\t\t\t\tsplay();\r\n\t\t\t\treturn this;\r\n\t\t\
    \t}else{\r\n\t\t\t\treturn r->splay(k-(l->sz+1));\r\n\t\t\t}\r\n\t\t}\r\n\t\t\
    NP update(){\t\t//\u60C5\u5831\u66F4\u65B0(\u5B50\u304C\u6B63\u3057\u3044\u6642\
    \u306B\u547C\u3070\u306A\u3044\u3068\u30C0\u30E1) (\u6700\u5F8C\u306Bupdate\u3057\
    \u3066return\u3059\u308B\u306E\u306B\u697D\u306A\u306E\u3067NP\u3092\u8FD4\u3059\
    )\r\n\t\t\tsz=1+l->sz+r->sz;\r\n\t\t\tsm = v;\r\n\t\t\tif(l->sz) sm = l->sm +\
    \ sm;\t//if(l) \u3060\u3068nil\u3067\u3082\u547C\u3076\u7FBD\u76EE\u306B\u306A\
    \u308A\u305D\u3046\r\n\t\t\tif(r->sz) sm = sm + r->sm;\r\n\t\t\treturn this;\r\
    \n\t\t}\r\n\r\n\t\tvoid showtree(){\r\n\t\t\tcout<<\"[\";\r\n\t\t\tif(l->sz) l->showtree();\r\
    \n\t\t\tcout<<v;\r\n\t\t\tif(r->sz) r->showtree();\r\n\t\t\tcout<<\"]\";\r\n\t\
    \t}\r\n\r\n\t};\r\n\tNP n;\r\n\r\n\t/*\r\n\t\t(r!=nil\u306A\u3089)r\u306E\u5DE6\
    \u7AEF\u304C\u6839\u306B\u306A\u308B\r\n\t\t\u305D\u306E\u5DE6\u306E\u5B50\u304C\
    l\r\n\t*/\r\n\tstatic NP merge(NP l,NP r){\r\n\t\tif(r==nil) return l;\r\n\t\t\
    r=r->splay(0);\r\n\t\tr->l=l;\r\n\t\tl->p=r;\r\n\t\treturn r->update();\r\n\t\
    }\r\n\t/*\r\n\t\tkth\u3067split(k=0\u306A\u3089fs=null)\r\n\t\t\u3068\u308A\u3042\
    \u3048\u305Ak\u500B\u76EE\u3092\u6301\u3063\u3066\u304D\u3066\u3001pair(\u305D\
    \u308C\u672A\u6E80,\u305D\u308C\u4EE5\u4E0A)\u3092\u8FD4\u3059.\u4E0A\u306B\u3064\
    \u306A\u304C\u3063\u3066\u3044\u308B\u306E\u306F(\u305D\u308C\u4EE5\u4E0A)\u306E\
    \u65B9,\u3068\u3044\u3046\u304Bk\r\n\t\t\u57FA\u672C\u7684\u306Bsplit\u306E\u7B2C\
    \u4E00\u5F15\u6570\u306Froot\u306A\u306E\u3067?\u305D\u3093\u306A\u306B\u6C17\u306B\
    \u3057\u306A\u304F\u3066\u3044\u3044\u304B\u306A\r\n\t\t\u5168\u533A\u9593\u3092\
    split\u3057\u3066\u304F ([1,2,3,4] -> [1,2][3,4] -> [1][2][3,4]) \u3076\u3093\u306B\
    \u306F\u5E38\u306Broot\u306A\u305F\u3081\r\n\t*/\r\n\tstatic pair<NP,NP> split(NP\
    \ x,int k){\r\n\t\tassert(0<=k&&k<=x->sz);\r\n\t\tif(k==x->sz) return {x,nil};\r\
    \n\t\tx=x->splay(k);\r\n\t\tNP l=x->l;\r\n\t\tl->p = nullptr;\r\n\t\tx->l = nil;\r\
    \n\t\treturn {l,x->update()};\r\n\t}\r\n\tstatic NP build(int sz,D vs[]){\t\t\t\
    \t//init\r\n\t\tif(!sz) return nil;\r\n\t\tint md=sz/2;\r\n\t\tNP x= new Node(vs[md]);\r\
    \n\t\tx->l = build(md,vs);\r\n\t\tx->l->p=x;\r\n\t\tx->r=build(sz-(md+1),vs+md+1);\r\
    \n\t\tx->r->p=x;\r\n\t\treturn x->update();\r\n\t}\r\n\tstatic NP build(const\
    \ vector<D>& vs){\r\n\t\treturn build(vs.size(),vs,0);\r\n\t}\r\n\tstatic NP build(int\
    \ sz,const vector<D>& vs,int off){\t\t\t\t//init\r\n\t\tif(!sz) return nil;\r\n\
    \t\tint md=sz/2;\r\n\t\tNP x= new Node(vs[off+md]);\r\n\t\tx->l = build(md,vs,off);\r\
    \n\t\tx->l->p=x;\r\n\t\tx->r=build(sz-(md+1),vs,off+md+1);\r\n\t\tx->r->p=x;\r\
    \n\t\treturn x->update();\r\n\t}\r\n\r\n\tSplayTree() : n(nil){}\r\n\tSplayTree(NP\
    \ n) : n(n){}\r\n\tSplayTree(int sz,D vs[]){\r\n\t\tn=build(sz,vs);\r\n\t}\r\n\
    \tSplayTree(vector<D> vs){\r\n\t\tn=build(vs);\r\n\t}\r\n\r\n\tvoid insert(int\
    \ k,D v){\r\n\t\tauto u=split(n,k);\r\n\t\tn=merge(merge(u.fs,new Node(v)),u.sc);\r\
    \n\t}\r\n\tvoid erase(int k){\r\n\t\tauto u=split(n,k);\r\n\t\tn=merge(u.fs,split(u.sc,1).sc);\r\
    \n\t}\r\n\tvoid merge(SplayTree t){\r\n\t\tn=merge(n,t.n);\r\n\t}\r\n\tint sz(){\r\
    \n\t\treturn n->sz;\r\n\t}\r\n\tD get(int k){\t\t\t//kth info\r\n\t\tauto a=split(n,k);\r\
    \n\t\tauto b=split(a.sc,1);\r\n\t\tD ret=b.fs->v;\r\n\t\tn=merge(merge(a.fs,b.fs),b.sc);\r\
    \n\t\treturn ret;\r\n\t}\r\n\tvoid assign(int k,D d){\r\n\t\tauto a = split(n,k);\r\
    \n\t\tauto b = split(a.sc,1);\r\n\t\tn = merge(merge(a.fs,new Node(d)),b.sc);\r\
    \n\t}\r\n\tD query(int l,int r){\t\t\t//[l,r)\r\n\t\tauto b=split(n,r);\r\n\t\t\
    auto a=split(b.fs,l);\r\n\t\tD ret=a.sc->sm;\r\n\t\tn=merge(merge(a.fs,a.sc),b.sc);\r\
    \n\t\treturn ret;\r\n\t}\r\n\r\n\t/*\r\n\t\tsearch\r\n\t\t\u5E73\u8861\u4E8C\u5206\
    \u6728\u3068\u3057\u3066\u306E\u5F79\u76EE\u3092\u601D\u3044\u51FA\u305B\r\n\t\
    \t\u306A\u3093\u304B\u5217\u3092\u304F\u3063\u3064\u3051\u305F\u308A\u308F\u3051\
    \u305F\u308A\u3067\u304D\u308B\u3068\u3060\u3051\u601D\u3063\u3068\u3051\u3070\
    \u57FA\u672C\u3044\u3044\u3051\u3069\r\n\t\t\u6301\u3063\u3066\u308B\u30C7\u30FC\
    \u30BF\u306B\u9806\u5E8F\u4ED8\u3044\u3066\u308B\u3068\u304D\u306B\u306F\u3061\
    \u3083\u3093\u3068\u4E8C\u5206\u6728\u3068\u3057\u3066\u4F7F\u3048\u308B\r\n\t\
    \tD \u306B operator< \u3068 operator<= \u304C\u5FC5\u8981\r\n\t*/\r\n\tint lower_bound(D\
    \ x){\t\t//x\u4EE5\u4E0A\u3067\u4E00\u756A\u5C0F\u3055\u3044\u3068\u3053\u306E\
    id\u3092\u8FD4\u3059\r\n\t\tNP p=n;\r\n\t\tint ret=0;\r\n\t\twhile(p!=nil){\r\n\
    \t\t\tif(x<=p->v) p=p->l;\r\n\t\t\telse ret+=(p->l->sz)+1,p=p->r;\r\n\t\t}\r\n\
    \t\treturn ret;\r\n\t}\r\n\tint upper_bound(D x){\t\t//x\u3088\u308A\u5927\u3067\
    \u4E00\u756A\u5C0F\u3055\u3044\u3068\u3053\u306Eid\u3092\u8FD4\u3059\r\n\t\tNP\
    \ p=n;\r\n\t\tint ret=0;\r\n\t\twhile(p!=nil){\r\n\t\t\tif(x<p->v) p=p->l;\r\n\
    \t\t\telse ret+=(p->l->sz)+1,p=p->r;\r\n\t\t}\r\n\t\treturn ret;\r\n\t}\r\n\r\n\
    \t/*\r\n\t\tdebug\r\n\t\tstruct D \u306B << \u304C\u306A\u3044\u3068\u3060\u3081\
    \r\n\t*/\r\n\tvoid showtree(){\r\n\t\tn->showtree();\r\n\t\tcout<<endl;\r\n\t\
    }\r\n};\r\n\r\n\r\nstruct Dmin{\t\t//(int,min,inf)\r\n\tint x;\r\n\tDmin(){}\r\
    \n\tDmin(int x):x(x){}\r\n\tstatic Dmin e(){\r\n\t\treturn Dmin(1e9);\r\n\t}\r\
    \n\tDmin operator+(const Dmin& r) const {\r\n\t\treturn Dmin(min(x,r.x));\r\n\t\
    }\r\n\tfriend ostream& operator<<(ostream& o,const Dmin& d){return o<<d.x;}\r\n\
    };\r\ntemplate<>\r\nSplayTree<Dmin>::NP SplayTree<Dmin>::nil = new SplayTree<Dmin>::Node();\r\
    \n\r\nSplayTree<Dmin>::NP merge(SplayTree<Dmin>::NP x, SplayTree<Dmin>::NP y){\r\
    \n\treturn SplayTree<Dmin>::merge(x,y);\r\n}\r\npair<SplayTree<Dmin>::NP,SplayTree<Dmin>::NP>\
    \ split(SplayTree<Dmin>::NP x, int k){\r\n\treturn SplayTree<Dmin>::split(x,k);\r\
    \n}\r\n\r\n/*\r\nstruct Dmat{\r\n\tusing T = int;\r\n\tusing D = Dmat;\r\n\tconst\
    \ static int N = 5;\r\n\tusing V = array<T,N>;\r\n\tusing VV = array<V,N>;\r\n\
    \tVV a;\r\n\tDmat(){}\r\n\tDmat(VV a):a(a){}\r\n\tconst static D e(){\r\n\t\t\
    VV a;\r\n\t\trep(i,N) rep(j,N) a[i][j] = (i==j?1:0);\r\n\t\treturn D(a);\r\n\t\
    }\r\n\tD operator+(const D& r) const {\r\n\t\tVV c;\r\n\t\trep(i,N) rep(j,N) c[i][j]=0;\r\
    \n\t\trep(i,N) rep(j,N) rep(k,N) c[i][j] += a[i][k] * r.a[k][j];\r\n\t\treturn\
    \ D(c);\r\n\t};\r\n\tbool operator==(const D& r) const {\r\n\t\treturn a==r.a;\r\
    \n\t}\r\n};\r\ntemplate<>\r\nSplayTree<Dmat>::NP SplayTree<Dmat>::nil = new SplayTree<Dmat>::Node();\r\
    \n\r\n*/\r\n\r\nvoid unittest(){\r\n\t{\r\n\t\tusing D = Dmin;\r\n\t\tvector<D>\
    \ vc;\r\n\t\tint N = 100;\r\n\t\trep(i,N) vc.pb(Dmin(rand()%1000));\r\n\t\tSplayTree<Dmin>\
    \ Stree(vc);\r\n\t\trep(l,N) for(int r=l;r<=N;r++){\r\n\t\t\tint mn = 1e9;\r\n\
    \t\t\tfor(int i=l;i<r;i++) chmin(mn,vc[i].x);\r\n\t\t\tassert( Stree.query(l,r).x\
    \ == mn);\r\n\t\t}\r\n\t}\r\n\t{\r\n\t\tusing D = Dmat;\r\n\t\tconst int K = Dmat::N;\r\
    \n\t\tusing T = int;\r\n\t\tusing V = array<T,K>;\r\n\t\tusing VV = array<V,K>;\r\
    \n\r\n\t\tvector<D> vs;\r\n\t\tint N = 100;\r\n\t\trep(i,N){\r\n\t\t\tVV a;\r\n\
    \t\t\trep(x,K) rep(y,K) a[x][y] = rand()%201+100;\r\n\t\t\tvs.push_back(D(a));\r\
    \n\t\t}\r\n//\t\tsegtree_simple<D> seg(vs);\r\n\t\tSplayTree<D> Stree(vs);\r\n\
    \t\trep(qt,1000){\r\n\t\t\tif(rand()%2){\r\n\t\t\t\tVV a;\r\n\t\t\t\trep(x,K)\
    \ rep(y,K) a[x][y] = rand()%201+100;\r\n\t\t\t\tint idx = rand()%N;\r\n\t\t\t\t\
    vs[idx] = D(a);\r\n\t\t\t\tStree.assign(idx,D(a));\r\n\t\t\t}else{\r\n\t\t\t\t\
    int l = rand()%100, r = rand()%100;\r\n\t\t\t\tif(l>r) swap(l,r);\r\n\t\t\t\t\
    r++;\r\n\t\t\t\tD x = D::e();\r\n\t\t\t\tfor(int i=l;i<r;i++) x = x+vs[i];\r\n\
    \t\t\t\tassert( Stree.query(l,r) == x );\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n}\r\n\r\
    \nint main(){\r\n\tsrand((unsigned)time(NULL));\r\n\tunittest();\r\n\r\n// \t\
    int N,Q;\t//AOJ1508\r\n// \tvector<D> vs;\r\n// \tcin>>N>>Q;\r\n// \trep(i,N){\r\
    \n// \t\tint x;\r\n// \t\tcin>>x;\r\n// \t\tvs.pb(D(x));\r\n// \t}\r\n// \tSplayTree<D>\
    \ st(vs);\r\n// \trep(qt,Q){\r\n// \t\tint x,y,z;\r\n// \t\tcin>>x>>y>>z;\r\n\
    // \t\tif(x==0){\t//[y..z-1][z] -> [z][y..z-1]\r\n// \t\t\tauto a = split(st.n,y);\t\
    //[0..y-1][y..N-1]\r\n// \t\t\tauto b = split(a.sc,z-y+1);\t//[y..z][~]\r\n//\
    \ \t\t\tauto c = split(b.fs,z-y);\t\t//[y..z-1][z]\r\n// \t\t\tst.n = merge(merge(a.fs,c.sc),merge(c.fs,b.sc));\r\
    \n// \t\t}\r\n// \t\tif(x==1){\r\n// \t\t\tcout<<st.query(y,z+1).x<<endl;\r\n\
    // \t\t}\r\n// \t\tif(x==2){\r\n// \t\t\tst.assign(y,z);\r\n// \t\t}\r\n// //\t\
    \tst.showtree();\r\n// \t}\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/splay/splay.cpp
  requiredBy: []
  timestamp: '2024-01-03 19:12:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/splay/splay.cpp
layout: document
redirect_from:
- /library/ds/splay/splay.cpp
- /library/ds/splay/splay.cpp.html
title: ds/splay/splay.cpp
---
