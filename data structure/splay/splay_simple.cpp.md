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
  bundledCode: "#line 1 \"data structure/splay/splay_simple.cpp\"\n#include <bits/stdc++.h>\n\
    #define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<\"(\"\
    <<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class T> ostream& operator<<(ostream& o,const\
    \ vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"[\";for(const T& v:vc) o<<v<<\"\
    ,\";o<<\"]\";return o;}\n\n/*\n\tsm\u306A\u3057\u30D0\u30FC\u30B8\u30E7\u30F3\
    (\u305F\u3060\u306E\u5217\u3092\u6271\u3046\u3060\u3051(get,insert,erase,lower_bound\
    \ \u3068\u304B))\n\tD \u540C\u58EB\u306E\u6F14\u7B97/\u5358\u4F4D\u5143 \u306F\
    \u5B9A\u7FA9\u3055\u308C\u3066\u7121\u304F\u3066\u5927\u4E08\u592B \u3060\u3051\
    \u3069, Node()\u306E\u5B9A\u7FA9\u306Ev\u306B\u4F55\u3092\u5165\u308C\u308B\u304B\
    \u5FAE\u5999(\u3068\u308A\u3042\u3048\u305A0\u3092\u5165\u308C\u3066\u3044\u308B\
    \u3051\u3069)\n\t\u306A\u306E\u3067int\u3092\u305D\u306E\u307E\u307E\u7A81\u3063\
    \u8FBC\u3093\u3060\u308A\u3082\u51FA\u6765\u308B(\u307E\u3042nil\u306E\u5B9F\u4F53\
    \u306F\u66F8\u304F\u5FC5\u8981\u304C\u3042\u308B\u3051\u3069)\n*/\ntemplate<class\
    \ D>\nstruct SplayTree{\n\tstruct Node;\n\tusing NP = Node*;\n\tstatic NP nil;\n\
    \n\tstruct Node{\n\t\tNP p,l,r;\n\t\tint sz;\n\t\tD v;\n\t\tNode(D v) :p(nullptr),l(nil),r(nil),sz(1),v(v){}\n\
    \t\tNode() : p(nullptr),l(nullptr),r(nullptr),sz(0),v(0){}\t\t//!!!\n\t\tint pos(){\t\
    \t\t//\u89AA\u306E\u5DE6\u306E\u5B50\u304B,\u53F3\u306E\u5B50\u304B,\u305D\u308C\
    \u3068\u3082\u6839(or nil)\u304B\n\t\t\tif(p&&p->l == this) return -1;\n\t\t\t\
    if(p&&p->r == this) return 1;\n\t\t\treturn 0;\n\t\t}\n\t\tvoid rot(){\t\t\t\t\
    //root\u3067\u547C\u3076\u3068\u6B7B\n\t\t\tNP pp=p->p;\n\t\t\tint pps=p->pos();\n\
    \t\t\tif(p->l==this){\n\t\t\t\tp->l=r,r->p=p,r=p,p->p=this;\n\t\t\t}else{\n\t\t\
    \t\tp->r=l,l->p=p,l=p,p->p=this;\n\t\t\t}\n\t\t\tp->update();\n//\t\t\tupdate();\t\
    zig,zig-zag,zig-zig\u3068\u3082\u306B\u3069\u3046\u305B\u6B21\u3067update\u304C\
    \u3088\u3070\u308C\u308B\u306E\u3067\u3044\u3089\u306A\u3044(\u6700\u5F8C\u6839\
    \u306F\u3044\u308B\u2190\u3053\u308C\u5B9F\u306Fmerge/split\u3067\u3061\u3083\u3093\
    \u3068update\u3057\u3066\u308B\u304B\u3089\u66F8\u304B\u306A\u304F\u3066\u3044\
    \u3044\u3093\u3060\u3088\u306D)\n\t\t\tp=pp;\n\t\t\tif(pps==0) return;\n\t\t\t\
    if(pps==-1) pp->l=this;\n\t\t\telse pp->r=this;\n\t\t}\n\t\tvoid splay(){\t\t\t\
    //this\u3092root\u306B\u3082\u3063\u3066\u304F\u308B\n\t\t\twhile(true){\n\t\t\
    \t\tint ps=pos();\n\t\t\t\tif(ps==0) break;\n\t\t\t\tint pps=p->pos();\n\t\t\t\
    \tif(pps==0){\t\t//zig\n\t\t\t\t\trot();\n\t\t\t\t}else if(ps==pps){\t\t//zigzig\n\
    \t\t\t\t\tp->rot();rot();\n\t\t\t\t}else{\t\t\t\t\t//zigzag\n\t\t\t\t\trot();rot();\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\tupdate();\t\t\t//merge/split\u4EE5\u5916\u304B\u3089\
    \u547C\u3070\u308C\u308B\u304B\u3082\u3057\u308C\u306A\u3044\u306E\u3067\u4E00\
    \u5FDC\u3064\u3051\u3066\u304A\u304F\n\t\t}\n\t\tNP splay(int k){\t\t\t//\u3053\
    \u306E\u533A\u9593\u306E\u5DE6\u304B\u3089kth(0-indexed)\u3092root\u306B\u3082\
    \u3063\u3066\u304D\u3066\u305D\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\u3059\
    \n\t\t\tassert(0<=k&&k<sz);\n\t\t\tif(k<l->sz){\n\t\t\t\treturn l->splay(k);\n\
    \t\t\t}else if(k==l->sz){\n\t\t\t\tsplay();\n\t\t\t\treturn this;\n\t\t\t}else{\n\
    \t\t\t\treturn r->splay(k-(l->sz+1));\n\t\t\t}\n\t\t}\n\t\tNP update(){\t\t//\u60C5\
    \u5831\u66F4\u65B0(\u5B50\u304C\u6B63\u3057\u3044\u6642\u306B\u547C\u3070\u306A\
    \u3044\u3068\u30C0\u30E1) (\u6700\u5F8C\u306Bupdate\u3057\u3066return\u3059\u308B\
    \u306E\u306B\u697D\u306A\u306E\u3067NP\u3092\u8FD4\u3059)\n\t\t\tsz=1+l->sz+r->sz;\n\
    \t\t\treturn this;\n\t\t}\n\n\t\tvoid showtree(){\n\t\t\tcout<<\"[\";\n\t\t\t\
    if(l->sz) l->showtree();\n\t\t\tcout<<v;\n\t\t\tif(r->sz) r->showtree();\n\t\t\
    \tcout<<\"]\";\n\t\t}\n\n\t};\n\tNP n;\n\n\t/*\n\t\t(r!=nil\u306A\u3089)r\u306E\
    \u5DE6\u7AEF\u304C\u6839\u306B\u306A\u308B\n\t\t\u305D\u306E\u5DE6\u306E\u5B50\
    \u304Cl\n\t*/\n\tstatic NP merge(NP l,NP r){\n\t\tif(r==nil) return l;\n\t\tr=r->splay(0);\n\
    \t\tr->l=l;\n\t\tl->p=r;\n\t\treturn r->update();\n\t}\n\t/*\n\t\tkth\u3067split(k=0\u306A\
    \u3089fs=null)\n\t\t\u3068\u308A\u3042\u3048\u305Ak\u500B\u76EE\u3092\u6301\u3063\
    \u3066\u304D\u3066\u3001pair(\u305D\u308C\u672A\u6E80,\u305D\u308C\u4EE5\u4E0A\
    )\u3092\u8FD4\u3059.\u4E0A\u306B\u3064\u306A\u304C\u3063\u3066\u3044\u308B\u306E\
    \u306F(\u305D\u308C\u4EE5\u4E0A)\u306E\u65B9,\u3068\u3044\u3046\u304Bk\n\t\t\u57FA\
    \u672C\u7684\u306Bsplit\u306E\u7B2C\u4E00\u5F15\u6570\u306Froot\u306A\u306E\u3067\
    ?\u305D\u3093\u306A\u306B\u6C17\u306B\u3057\u306A\u304F\u3066\u3044\u3044\u304B\
    \u306A\n\t\t\u5168\u533A\u9593\u3092split\u3057\u3066\u304F ([1,2,3,4] -> [1,2][3,4]\
    \ -> [1][2][3,4]) \u3076\u3093\u306B\u306F\u5E38\u306Broot\u306A\u305F\u3081\n\
    \t*/\n\tstatic pair<NP,NP> split(NP x,int k){\n\t\tassert(0<=k&&k<=x->sz);\n\t\
    \tif(k==x->sz) return {x,nil};\n\t\tx=x->splay(k);\n\t\tNP l=x->l;\n\t\tl->p =\
    \ nullptr;\n\t\tx->l = nil;\n\t\treturn {l,x->update()};\n\t}\n\tstatic NP build(int\
    \ sz,D vs[]){\t\t\t\t//init\n\t\tif(!sz) return nil;\n\t\tint md=sz/2;\n\t\tNP\
    \ x= new Node(vs[md]);\n\t\tx->l = build(md,vs);\n\t\tx->l->p=x;\n\t\tx->r=build(sz-(md+1),vs+md+1);\n\
    \t\tx->r->p=x;\n\t\treturn x->update();\n\t}\n\tstatic NP build(const vector<D>&\
    \ vs){\n\t\treturn build(vs.size(),vs,0);\n\t}\n\tstatic NP build(int sz,const\
    \ vector<D>& vs,int off){\t\t\t\t//init\n\t\tif(!sz) return nil;\n\t\tint md=sz/2;\n\
    \t\tNP x= new Node(vs[off+md]);\n\t\tx->l = build(md,vs,off);\n\t\tx->l->p=x;\n\
    \t\tx->r=build(sz-(md+1),vs,off+md+1);\n\t\tx->r->p=x;\n\t\treturn x->update();\n\
    \t}\n\n\tSplayTree() : n(nil){}\n\tSplayTree(NP n) : n(n){}\n\tSplayTree(int sz,D\
    \ vs[]){\n\t\tn=build(sz,vs);\n\t}\n\tSplayTree(vector<D> vs){\n\t\tn=build(vs);\n\
    \t}\n\n\tvoid insert(int k,D v){\n\t\tauto u=split(n,k);\n\t\tn=merge(merge(u.fs,new\
    \ Node(v)),u.sc);\n\t}\n\tvoid erase(int k){\n\t\tauto u=split(n,k);\n\t\tn=merge(u.fs,split(u.sc,1).sc);\n\
    \t}\n\tvoid merge(SplayTree t){\n\t\tn=merge(n,t.n);\n\t}\n\tint sz(){\n\t\treturn\
    \ n->sz;\n\t}\n\tD get(int k){\t\t\t//kth info\n\t\tauto a=split(n,k);\n\t\tauto\
    \ b=split(a.sc,1);\n\t\tD ret=b.fs->v;\n\t\tn=merge(merge(a.fs,b.fs),b.sc);\n\t\
    \treturn ret;\n\t}\n\tvoid assign(int k,D d){\n\t\tauto a = split(n,k);\n\t\t\
    auto b = split(a.sc,1);\n\t\tn = merge(merge(a.fs,new Node(d)),b.sc);\n\t}\n\n\
    \t/*\n\t\tsearch\n\t\t\u5E73\u8861\u4E8C\u5206\u6728\u3068\u3057\u3066\u306E\u5F79\
    \u76EE\u3092\u601D\u3044\u51FA\u305B\n\t\t\u306A\u3093\u304B\u5217\u3092\u304F\
    \u3063\u3064\u3051\u305F\u308A\u308F\u3051\u305F\u308A\u3067\u304D\u308B\u3068\
    \u3060\u3051\u601D\u3063\u3068\u3051\u3070\u57FA\u672C\u3044\u3044\u3051\u3069\
    \n\t\t\u6301\u3063\u3066\u308B\u30C7\u30FC\u30BF\u306B\u9806\u5E8F\u4ED8\u3044\
    \u3066\u308B\u3068\u304D\u306B\u306F\u3061\u3083\u3093\u3068\u4E8C\u5206\u6728\
    \u3068\u3057\u3066\u4F7F\u3048\u308B\n\t\tD \u306B operator< \u3068 operator<=\
    \ \u304C\u5FC5\u8981\n\t*/\n\tint lower_bound(D x){\t\t//x\u4EE5\u4E0A\u3067\u4E00\
    \u756A\u5C0F\u3055\u3044\u3068\u3053\u306Eid\u3092\u8FD4\u3059\n\t\tNP p=n;\n\t\
    \tint ret=0;\n\t\twhile(p!=nil){\n\t\t\tif(x<=p->v) p=p->l;\n\t\t\telse ret+=(p->l->sz)+1,p=p->r;\n\
    \t\t}\n\t\treturn ret;\n\t}\n\tint upper_bound(D x){\t\t//x\u3088\u308A\u5927\u3067\
    \u4E00\u756A\u5C0F\u3055\u3044\u3068\u3053\u306Eid\u3092\u8FD4\u3059\n\t\tNP p=n;\n\
    \t\tint ret=0;\n\t\twhile(p!=nil){\n\t\t\tif(x<p->v) p=p->l;\n\t\t\telse ret+=(p->l->sz)+1,p=p->r;\n\
    \t\t}\n\t\treturn ret;\n\t}\n\n\t/*\n\t\tdebug\n\t\tstruct D \u306B << \u304C\u306A\
    \u3044\u3068\u3060\u3081\n\t*/\n\tvoid showtree(){\n\t\tn->showtree();\n\t\tcout<<endl;\n\
    \t}\n};\n\ntemplate<>\nSplayTree<int>::NP SplayTree<int>::nil = new SplayTree<int>::Node();\n\
    \n\nint main(){\n\tSplayTree<int> st;\n}\n"
  code: "#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define show(x) cout\
    \ << #x << \" = \" << x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y)\
    \ x=max(x,y)\nusing namespace std;\ntemplate<class S,class T> ostream& operator<<(ostream&\
    \ o,const pair<S,T> &p){return o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class\
    \ T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"\
    [\";for(const T& v:vc) o<<v<<\",\";o<<\"]\";return o;}\n\n/*\n\tsm\u306A\u3057\
    \u30D0\u30FC\u30B8\u30E7\u30F3(\u305F\u3060\u306E\u5217\u3092\u6271\u3046\u3060\
    \u3051(get,insert,erase,lower_bound \u3068\u304B))\n\tD \u540C\u58EB\u306E\u6F14\
    \u7B97/\u5358\u4F4D\u5143 \u306F\u5B9A\u7FA9\u3055\u308C\u3066\u7121\u304F\u3066\
    \u5927\u4E08\u592B \u3060\u3051\u3069, Node()\u306E\u5B9A\u7FA9\u306Ev\u306B\u4F55\
    \u3092\u5165\u308C\u308B\u304B\u5FAE\u5999(\u3068\u308A\u3042\u3048\u305A0\u3092\
    \u5165\u308C\u3066\u3044\u308B\u3051\u3069)\n\t\u306A\u306E\u3067int\u3092\u305D\
    \u306E\u307E\u307E\u7A81\u3063\u8FBC\u3093\u3060\u308A\u3082\u51FA\u6765\u308B\
    (\u307E\u3042nil\u306E\u5B9F\u4F53\u306F\u66F8\u304F\u5FC5\u8981\u304C\u3042\u308B\
    \u3051\u3069)\n*/\ntemplate<class D>\nstruct SplayTree{\n\tstruct Node;\n\tusing\
    \ NP = Node*;\n\tstatic NP nil;\n\n\tstruct Node{\n\t\tNP p,l,r;\n\t\tint sz;\n\
    \t\tD v;\n\t\tNode(D v) :p(nullptr),l(nil),r(nil),sz(1),v(v){}\n\t\tNode() : p(nullptr),l(nullptr),r(nullptr),sz(0),v(0){}\t\
    \t//!!!\n\t\tint pos(){\t\t\t//\u89AA\u306E\u5DE6\u306E\u5B50\u304B,\u53F3\u306E\
    \u5B50\u304B,\u305D\u308C\u3068\u3082\u6839(or nil)\u304B\n\t\t\tif(p&&p->l ==\
    \ this) return -1;\n\t\t\tif(p&&p->r == this) return 1;\n\t\t\treturn 0;\n\t\t\
    }\n\t\tvoid rot(){\t\t\t\t//root\u3067\u547C\u3076\u3068\u6B7B\n\t\t\tNP pp=p->p;\n\
    \t\t\tint pps=p->pos();\n\t\t\tif(p->l==this){\n\t\t\t\tp->l=r,r->p=p,r=p,p->p=this;\n\
    \t\t\t}else{\n\t\t\t\tp->r=l,l->p=p,l=p,p->p=this;\n\t\t\t}\n\t\t\tp->update();\n\
    //\t\t\tupdate();\tzig,zig-zag,zig-zig\u3068\u3082\u306B\u3069\u3046\u305B\u6B21\
    \u3067update\u304C\u3088\u3070\u308C\u308B\u306E\u3067\u3044\u3089\u306A\u3044\
    (\u6700\u5F8C\u6839\u306F\u3044\u308B\u2190\u3053\u308C\u5B9F\u306Fmerge/split\u3067\
    \u3061\u3083\u3093\u3068update\u3057\u3066\u308B\u304B\u3089\u66F8\u304B\u306A\
    \u304F\u3066\u3044\u3044\u3093\u3060\u3088\u306D)\n\t\t\tp=pp;\n\t\t\tif(pps==0)\
    \ return;\n\t\t\tif(pps==-1) pp->l=this;\n\t\t\telse pp->r=this;\n\t\t}\n\t\t\
    void splay(){\t\t\t//this\u3092root\u306B\u3082\u3063\u3066\u304F\u308B\n\t\t\t\
    while(true){\n\t\t\t\tint ps=pos();\n\t\t\t\tif(ps==0) break;\n\t\t\t\tint pps=p->pos();\n\
    \t\t\t\tif(pps==0){\t\t//zig\n\t\t\t\t\trot();\n\t\t\t\t}else if(ps==pps){\t\t\
    //zigzig\n\t\t\t\t\tp->rot();rot();\n\t\t\t\t}else{\t\t\t\t\t//zigzag\n\t\t\t\t\
    \trot();rot();\n\t\t\t\t}\n\t\t\t}\n\t\t\tupdate();\t\t\t//merge/split\u4EE5\u5916\
    \u304B\u3089\u547C\u3070\u308C\u308B\u304B\u3082\u3057\u308C\u306A\u3044\u306E\
    \u3067\u4E00\u5FDC\u3064\u3051\u3066\u304A\u304F\n\t\t}\n\t\tNP splay(int k){\t\
    \t\t//\u3053\u306E\u533A\u9593\u306E\u5DE6\u304B\u3089kth(0-indexed)\u3092root\u306B\
    \u3082\u3063\u3066\u304D\u3066\u305D\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\
    \u3059\n\t\t\tassert(0<=k&&k<sz);\n\t\t\tif(k<l->sz){\n\t\t\t\treturn l->splay(k);\n\
    \t\t\t}else if(k==l->sz){\n\t\t\t\tsplay();\n\t\t\t\treturn this;\n\t\t\t}else{\n\
    \t\t\t\treturn r->splay(k-(l->sz+1));\n\t\t\t}\n\t\t}\n\t\tNP update(){\t\t//\u60C5\
    \u5831\u66F4\u65B0(\u5B50\u304C\u6B63\u3057\u3044\u6642\u306B\u547C\u3070\u306A\
    \u3044\u3068\u30C0\u30E1) (\u6700\u5F8C\u306Bupdate\u3057\u3066return\u3059\u308B\
    \u306E\u306B\u697D\u306A\u306E\u3067NP\u3092\u8FD4\u3059)\n\t\t\tsz=1+l->sz+r->sz;\n\
    \t\t\treturn this;\n\t\t}\n\n\t\tvoid showtree(){\n\t\t\tcout<<\"[\";\n\t\t\t\
    if(l->sz) l->showtree();\n\t\t\tcout<<v;\n\t\t\tif(r->sz) r->showtree();\n\t\t\
    \tcout<<\"]\";\n\t\t}\n\n\t};\n\tNP n;\n\n\t/*\n\t\t(r!=nil\u306A\u3089)r\u306E\
    \u5DE6\u7AEF\u304C\u6839\u306B\u306A\u308B\n\t\t\u305D\u306E\u5DE6\u306E\u5B50\
    \u304Cl\n\t*/\n\tstatic NP merge(NP l,NP r){\n\t\tif(r==nil) return l;\n\t\tr=r->splay(0);\n\
    \t\tr->l=l;\n\t\tl->p=r;\n\t\treturn r->update();\n\t}\n\t/*\n\t\tkth\u3067split(k=0\u306A\
    \u3089fs=null)\n\t\t\u3068\u308A\u3042\u3048\u305Ak\u500B\u76EE\u3092\u6301\u3063\
    \u3066\u304D\u3066\u3001pair(\u305D\u308C\u672A\u6E80,\u305D\u308C\u4EE5\u4E0A\
    )\u3092\u8FD4\u3059.\u4E0A\u306B\u3064\u306A\u304C\u3063\u3066\u3044\u308B\u306E\
    \u306F(\u305D\u308C\u4EE5\u4E0A)\u306E\u65B9,\u3068\u3044\u3046\u304Bk\n\t\t\u57FA\
    \u672C\u7684\u306Bsplit\u306E\u7B2C\u4E00\u5F15\u6570\u306Froot\u306A\u306E\u3067\
    ?\u305D\u3093\u306A\u306B\u6C17\u306B\u3057\u306A\u304F\u3066\u3044\u3044\u304B\
    \u306A\n\t\t\u5168\u533A\u9593\u3092split\u3057\u3066\u304F ([1,2,3,4] -> [1,2][3,4]\
    \ -> [1][2][3,4]) \u3076\u3093\u306B\u306F\u5E38\u306Broot\u306A\u305F\u3081\n\
    \t*/\n\tstatic pair<NP,NP> split(NP x,int k){\n\t\tassert(0<=k&&k<=x->sz);\n\t\
    \tif(k==x->sz) return {x,nil};\n\t\tx=x->splay(k);\n\t\tNP l=x->l;\n\t\tl->p =\
    \ nullptr;\n\t\tx->l = nil;\n\t\treturn {l,x->update()};\n\t}\n\tstatic NP build(int\
    \ sz,D vs[]){\t\t\t\t//init\n\t\tif(!sz) return nil;\n\t\tint md=sz/2;\n\t\tNP\
    \ x= new Node(vs[md]);\n\t\tx->l = build(md,vs);\n\t\tx->l->p=x;\n\t\tx->r=build(sz-(md+1),vs+md+1);\n\
    \t\tx->r->p=x;\n\t\treturn x->update();\n\t}\n\tstatic NP build(const vector<D>&\
    \ vs){\n\t\treturn build(vs.size(),vs,0);\n\t}\n\tstatic NP build(int sz,const\
    \ vector<D>& vs,int off){\t\t\t\t//init\n\t\tif(!sz) return nil;\n\t\tint md=sz/2;\n\
    \t\tNP x= new Node(vs[off+md]);\n\t\tx->l = build(md,vs,off);\n\t\tx->l->p=x;\n\
    \t\tx->r=build(sz-(md+1),vs,off+md+1);\n\t\tx->r->p=x;\n\t\treturn x->update();\n\
    \t}\n\n\tSplayTree() : n(nil){}\n\tSplayTree(NP n) : n(n){}\n\tSplayTree(int sz,D\
    \ vs[]){\n\t\tn=build(sz,vs);\n\t}\n\tSplayTree(vector<D> vs){\n\t\tn=build(vs);\n\
    \t}\n\n\tvoid insert(int k,D v){\n\t\tauto u=split(n,k);\n\t\tn=merge(merge(u.fs,new\
    \ Node(v)),u.sc);\n\t}\n\tvoid erase(int k){\n\t\tauto u=split(n,k);\n\t\tn=merge(u.fs,split(u.sc,1).sc);\n\
    \t}\n\tvoid merge(SplayTree t){\n\t\tn=merge(n,t.n);\n\t}\n\tint sz(){\n\t\treturn\
    \ n->sz;\n\t}\n\tD get(int k){\t\t\t//kth info\n\t\tauto a=split(n,k);\n\t\tauto\
    \ b=split(a.sc,1);\n\t\tD ret=b.fs->v;\n\t\tn=merge(merge(a.fs,b.fs),b.sc);\n\t\
    \treturn ret;\n\t}\n\tvoid assign(int k,D d){\n\t\tauto a = split(n,k);\n\t\t\
    auto b = split(a.sc,1);\n\t\tn = merge(merge(a.fs,new Node(d)),b.sc);\n\t}\n\n\
    \t/*\n\t\tsearch\n\t\t\u5E73\u8861\u4E8C\u5206\u6728\u3068\u3057\u3066\u306E\u5F79\
    \u76EE\u3092\u601D\u3044\u51FA\u305B\n\t\t\u306A\u3093\u304B\u5217\u3092\u304F\
    \u3063\u3064\u3051\u305F\u308A\u308F\u3051\u305F\u308A\u3067\u304D\u308B\u3068\
    \u3060\u3051\u601D\u3063\u3068\u3051\u3070\u57FA\u672C\u3044\u3044\u3051\u3069\
    \n\t\t\u6301\u3063\u3066\u308B\u30C7\u30FC\u30BF\u306B\u9806\u5E8F\u4ED8\u3044\
    \u3066\u308B\u3068\u304D\u306B\u306F\u3061\u3083\u3093\u3068\u4E8C\u5206\u6728\
    \u3068\u3057\u3066\u4F7F\u3048\u308B\n\t\tD \u306B operator< \u3068 operator<=\
    \ \u304C\u5FC5\u8981\n\t*/\n\tint lower_bound(D x){\t\t//x\u4EE5\u4E0A\u3067\u4E00\
    \u756A\u5C0F\u3055\u3044\u3068\u3053\u306Eid\u3092\u8FD4\u3059\n\t\tNP p=n;\n\t\
    \tint ret=0;\n\t\twhile(p!=nil){\n\t\t\tif(x<=p->v) p=p->l;\n\t\t\telse ret+=(p->l->sz)+1,p=p->r;\n\
    \t\t}\n\t\treturn ret;\n\t}\n\tint upper_bound(D x){\t\t//x\u3088\u308A\u5927\u3067\
    \u4E00\u756A\u5C0F\u3055\u3044\u3068\u3053\u306Eid\u3092\u8FD4\u3059\n\t\tNP p=n;\n\
    \t\tint ret=0;\n\t\twhile(p!=nil){\n\t\t\tif(x<p->v) p=p->l;\n\t\t\telse ret+=(p->l->sz)+1,p=p->r;\n\
    \t\t}\n\t\treturn ret;\n\t}\n\n\t/*\n\t\tdebug\n\t\tstruct D \u306B << \u304C\u306A\
    \u3044\u3068\u3060\u3081\n\t*/\n\tvoid showtree(){\n\t\tn->showtree();\n\t\tcout<<endl;\n\
    \t}\n};\n\ntemplate<>\nSplayTree<int>::NP SplayTree<int>::nil = new SplayTree<int>::Node();\n\
    \n\nint main(){\n\tSplayTree<int> st;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: data structure/splay/splay_simple.cpp
  requiredBy: []
  timestamp: '2017-10-19 00:06:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/splay/splay_simple.cpp
layout: document
redirect_from:
- /library/data structure/splay/splay_simple.cpp
- /library/data structure/splay/splay_simple.cpp.html
title: data structure/splay/splay_simple.cpp
---
