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
    - http://arc033.contest.atcoder.jp/submissions/521951
  bundledCode: "#line 1 \"data structure/splay/arc33C.cpp\"\n//k-th set\n//http://arc033.contest.atcoder.jp/submissions/521951\
    \ AC\n#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define show(x) cout\
    \ << #x << \" = \" << x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y)\
    \ x=max(x,y)\nusing namespace std;\ntypedef long long ll;\nstruct SplayTree{\n\
    \tstruct Node;\n\tusing NP = Node*;\n\tstatic NP nil;\n\n\tstruct Node{\n\t\t\
    NP p,l,r;\t\t\t//parent,left child,right child\n\t\tint sz;\n\t\tll v,sm;\t\t\t\
    \t//infos\n\t\tNode(ll v) :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v){}\n\t\tNode()\
    \ : l(nullptr),r(nullptr),sz(0),v(0),sm(0){}\t\t\t\t\t\t//\u5358\u4F4D\u5143!!\n\
    \t\tint pos(){\t\t\t//\u89AA\u306E\u5DE6\u306E\u5B50\u304B,\u53F3\u306E\u5B50\u304B\
    ,\u305D\u308C\u3068\u3082\u6839(or null)\u304B\n\t\t\tif(p&&p->l == this) return\
    \ -1;\n\t\t\tif(p&&p->r == this) return 1;\n\t\t\treturn 0;\n\t\t}\n\t\tvoid rot(){\t\
    \t\t\t//root\u3067\u547C\u3076\u3068\u6B7B\n\t\t\tNP pp=p->p;\t\t\t//\u89AA\u306E\
    \u89AA\n\t\t\tint pps=p->pos();\t//pp\u304B\u3089\u307F\u305Fp\u306E\u5DE6\u53F3\
    \n\t\t\tif(p->l==this){\t\t//pos()==-1\n\t\t\t\tp->l=r,r->p=p,r=p,p->p=this;\n\
    \t\t\t}else{\n\t\t\t\tp->r=l,l->p=p,l=p,p->p=this;\n\t\t\t}\n\t\t\t//\u65B0\u3057\
    \u3044\u6728\u3067\u4E0B\u304B\u3089update\n\t\t\tp->update();\n\t\t\tupdate();\n\
    \t\t\tp=pp;\n\t\t\tif(pps==0) return;\n\t\t\tif(pps==-1) pp->l=this;\n\t\t\telse\
    \ pp->r=this;\n\t\t\tpp->update();\n\t\t}\n\t\tvoid splay(){\t\t\t//this\u3092\
    root\u306B\u3082\u3063\u3066\u304F\u308B\n\t\t\twhile(true){\n\t\t\t\tint ps=pos();\n\
    \t\t\t\tif(ps==0) break;\n\t\t\t\tint pps=p->pos();\n\t\t\t\tif(pps==0){\t\t//zig\n\
    \t\t\t\t\trot();\n\t\t\t\t}else if(ps==pps){\t\t//zigzig\n\t\t\t\t\tp->rot();rot();\n\
    \t\t\t\t}else{\t\t\t\t\t//zigzag\n\t\t\t\t\trot();rot();\n\t\t\t\t}\n\t\t\t}\n\
    \t\t}\n\t\tNP splay(int k){\t\t\t//\u3053\u306E\u533A\u9593\u306E\u5DE6\u304B\u3089\
    kth(0-indexed)\u3092root\u306B\u3082\u3063\u3066\u304D\u3066\u305D\u306E\u30DD\
    \u30A4\u30F3\u30BF\u3092\u8FD4\u3059(sz\u304C\u5FC5\u8981)\n\t\t\tassert(0<=k&&k<sz);\n\
    \t\t\tif(k<l->sz){\n\t\t\t\treturn l->splay(k);\n\t\t\t}else if(k==l->sz){\n\t\
    \t\t\tsplay();\n\t\t\t\treturn this;\n\t\t\t}else{\n\t\t\t\treturn r->splay(k-(l->sz+1));\n\
    \t\t\t}\n\t\t}\n\t\tNP update(){\t\t//\u60C5\u5831\u66F4\u65B0(\u5B50\u304C\u6B63\
    \u3057\u3044\u6642\u306B\u547C\u3070\u306A\u3044\u3068\u30C0\u30E1) (\u6700\u5F8C\
    \u306Bupdate\u3057\u3066return\u3059\u308B\u306E\u306B\u697D\u306A\u306E\u3067\
    NP\u3092\u8FD4\u3059)\n\t\t\tsz=1+l->sz+r->sz;\n\t\t\tif(l) sm+=l->sm;\n\t\t\t\
    if(r) sm+=r->sm;\n\t\t\treturn this;\n\t\t}\n\n\t};\n\tNP n;\n\tstatic NP merge(NP\
    \ l,NP r){\t\t\t//merge\u3057\u305F\u6839\n\t\tif(r==nil) return l;\n\t\tr=r->splay(0);\n\
    \t\tr->l=l;\n\t\tl->p=r;\n\t\treturn r->update();\n\t}\n\t/*\n\t\tkth\u3067split(k=0\u306A\
    \u3089fs=null)\n\t\tl\u306F\u5B8C\u5168\u306B\u5207\u308A\u96E2\u3055\u308C\u3066\
    \u308B\u3051\u308C\u3069\n\t\tr\u306F\u4E0A\u3068\u3064\u306A\u304C\u3063\u3066\
    \u3044\u308B?\n\t*/\n\tstatic pair<NP,NP> split(NP x,int k){\n\t\tassert(0<=k&&k<=x->sz);\n\
    \t\tif(k==x->sz) return {x,nil};\n\t\tx=x->splay(k);\n\t\tNP l=x->l;\n\t\tl->p\
    \ = nullptr;\n\t\tx->l = nil;\n\t\treturn {l,x->update()};\n\t}\n\tstatic NP built(int\
    \ sz,ll vs[]){\t\t\t\t//init\n\t\tif(!sz) return nil;\n\t\tint md=sz/2;\n\t\t\
    NP x= new Node(vs[md]);\n\t\tx->l = built(md,vs);\n\t\tx->l->p=x;\n\t\tx->r=built(sz-(md+1),vs+md+1);\n\
    \t\tx->r->p=x;\n\t\treturn x->update();\n\t}\n\tSplayTree() : n(nil){}\n\tSplayTree(NP\
    \ n) : n(n){}\n\tSplayTree(int sz,ll vs[]){\n\t\tn=built(sz,vs);\n\t}\n\tvoid\
    \ insert(int k,ll v){\n\t\tauto u=split(n,k);\n\t\tn=merge(merge(u.fs,new Node(v)),u.sc);\n\
    \t}\n\tvoid erase(int k){\n\t\tauto u=split(n,k);\n\t\tn=merge(u.fs,split(u.sc,1).sc);\n\
    \t}\n\tvoid merge(SplayTree t){\n\t\tn=merge(n,t.n);\n\t}\n\tint sz(){\n\t\treturn\
    \ n->sz;\n\t}\n\tll get(int k){\t\t\t//kth info\n\t\tauto a=split(n,k);\n\t\t\
    auto b=split(a.sc,1);\n\t\tll ret=b.fs->v;\n\t\tn=merge(merge(a.fs,b.fs),b.sc);\n\
    \t\treturn ret;\n\t}\n\tll sum(int l,int r){\n\t\tauto b=split(n,r);\n\t\tauto\
    \ a=split(b.fs,l);\n\t\tll ret=a.sc->sm;\n\t\tn=merge(merge(a.fs,a.sc),b.sc);\n\
    \t\treturn ret;\n\t}\n\t/*\n\t\tsearch\n\t\t\u5E73\u8861\u4E8C\u5206\u6728\u3068\
    \u3057\u3066\u306E\u5F79\u76EE\u3092\u601D\u3044\u51FA\u305B\n\t\t\u306A\u3093\
    \u304B\u5217\u3092\u304F\u3063\u3064\u3051\u305F\u308A\u308F\u3051\u305F\u308A\
    \u3067\u304D\u308B\u3068\u3060\u3051\u601D\u3063\u3068\u3051\u3070\u57FA\u672C\
    \u3044\u3044\u3051\u3069\n\t\t\u6301\u3063\u3066\u308B\u30C7\u30FC\u30BF\u306B\
    \u9806\u5E8F\u4ED8\u3044\u3066\u308B\u3068\u304D\u306B\u306F\u3061\u3083\u3093\
    \u3068\u4E8C\u5206\u6728\u3068\u3057\u3066\u4F7F\u3048\u308B\n\t*/\n\tint lower_bound(int\
    \ x){\n\t\tNP p=n;\n\t\tint ret=0;\n\t\twhile(p!=nil){\n\t\t\tif(x<=p->v) p=p->l;\n\
    \t\t\telse ret+=(p->l->sz)+1,p=p->r;\n\t\t}\n\t\treturn ret;\n\t}\n};\nSplayTree::NP\
    \ SplayTree::nil = new SplayTree::Node();\nint main(){\n\tint Q;\n\tcin>>Q;\n\t\
    SplayTree ST;\n\trep(tt,Q){\n\t\tint t,x;\n\t\tcin>>t>>x;\n\t\tif(t==1){\n\t\t\
    \tint id=ST.lower_bound(x);\n\t\t\tST.insert(id,x);\n\t\t}else{\n\t\t\tx--;\n\t\
    \t\tcout<<ST.get(x)<<endl;\n\t\t\tST.erase(x);\n\t\t}\n\t}\n}\n"
  code: "//k-th set\n//http://arc033.contest.atcoder.jp/submissions/521951 AC\n#include\
    \ <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n)\
    \ for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n#define pb push_back\n\
    #define fs first\n#define sc second\n#define show(x) cout << #x << \" = \" <<\
    \ x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing\
    \ namespace std;\ntypedef long long ll;\nstruct SplayTree{\n\tstruct Node;\n\t\
    using NP = Node*;\n\tstatic NP nil;\n\n\tstruct Node{\n\t\tNP p,l,r;\t\t\t//parent,left\
    \ child,right child\n\t\tint sz;\n\t\tll v,sm;\t\t\t\t//infos\n\t\tNode(ll v)\
    \ :p(nullptr),l(nil),r(nil),sz(1),v(v),sm(v){}\n\t\tNode() : l(nullptr),r(nullptr),sz(0),v(0),sm(0){}\t\
    \t\t\t\t\t//\u5358\u4F4D\u5143!!\n\t\tint pos(){\t\t\t//\u89AA\u306E\u5DE6\u306E\
    \u5B50\u304B,\u53F3\u306E\u5B50\u304B,\u305D\u308C\u3068\u3082\u6839(or null)\u304B\
    \n\t\t\tif(p&&p->l == this) return -1;\n\t\t\tif(p&&p->r == this) return 1;\n\t\
    \t\treturn 0;\n\t\t}\n\t\tvoid rot(){\t\t\t\t//root\u3067\u547C\u3076\u3068\u6B7B\
    \n\t\t\tNP pp=p->p;\t\t\t//\u89AA\u306E\u89AA\n\t\t\tint pps=p->pos();\t//pp\u304B\
    \u3089\u307F\u305Fp\u306E\u5DE6\u53F3\n\t\t\tif(p->l==this){\t\t//pos()==-1\n\t\
    \t\t\tp->l=r,r->p=p,r=p,p->p=this;\n\t\t\t}else{\n\t\t\t\tp->r=l,l->p=p,l=p,p->p=this;\n\
    \t\t\t}\n\t\t\t//\u65B0\u3057\u3044\u6728\u3067\u4E0B\u304B\u3089update\n\t\t\t\
    p->update();\n\t\t\tupdate();\n\t\t\tp=pp;\n\t\t\tif(pps==0) return;\n\t\t\tif(pps==-1)\
    \ pp->l=this;\n\t\t\telse pp->r=this;\n\t\t\tpp->update();\n\t\t}\n\t\tvoid splay(){\t\
    \t\t//this\u3092root\u306B\u3082\u3063\u3066\u304F\u308B\n\t\t\twhile(true){\n\
    \t\t\t\tint ps=pos();\n\t\t\t\tif(ps==0) break;\n\t\t\t\tint pps=p->pos();\n\t\
    \t\t\tif(pps==0){\t\t//zig\n\t\t\t\t\trot();\n\t\t\t\t}else if(ps==pps){\t\t//zigzig\n\
    \t\t\t\t\tp->rot();rot();\n\t\t\t\t}else{\t\t\t\t\t//zigzag\n\t\t\t\t\trot();rot();\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tNP splay(int k){\t\t\t//\u3053\u306E\u533A\u9593\
    \u306E\u5DE6\u304B\u3089kth(0-indexed)\u3092root\u306B\u3082\u3063\u3066\u304D\
    \u3066\u305D\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\u3059(sz\u304C\u5FC5\u8981\
    )\n\t\t\tassert(0<=k&&k<sz);\n\t\t\tif(k<l->sz){\n\t\t\t\treturn l->splay(k);\n\
    \t\t\t}else if(k==l->sz){\n\t\t\t\tsplay();\n\t\t\t\treturn this;\n\t\t\t}else{\n\
    \t\t\t\treturn r->splay(k-(l->sz+1));\n\t\t\t}\n\t\t}\n\t\tNP update(){\t\t//\u60C5\
    \u5831\u66F4\u65B0(\u5B50\u304C\u6B63\u3057\u3044\u6642\u306B\u547C\u3070\u306A\
    \u3044\u3068\u30C0\u30E1) (\u6700\u5F8C\u306Bupdate\u3057\u3066return\u3059\u308B\
    \u306E\u306B\u697D\u306A\u306E\u3067NP\u3092\u8FD4\u3059)\n\t\t\tsz=1+l->sz+r->sz;\n\
    \t\t\tif(l) sm+=l->sm;\n\t\t\tif(r) sm+=r->sm;\n\t\t\treturn this;\n\t\t}\n\n\t\
    };\n\tNP n;\n\tstatic NP merge(NP l,NP r){\t\t\t//merge\u3057\u305F\u6839\n\t\t\
    if(r==nil) return l;\n\t\tr=r->splay(0);\n\t\tr->l=l;\n\t\tl->p=r;\n\t\treturn\
    \ r->update();\n\t}\n\t/*\n\t\tkth\u3067split(k=0\u306A\u3089fs=null)\n\t\tl\u306F\
    \u5B8C\u5168\u306B\u5207\u308A\u96E2\u3055\u308C\u3066\u308B\u3051\u308C\u3069\
    \n\t\tr\u306F\u4E0A\u3068\u3064\u306A\u304C\u3063\u3066\u3044\u308B?\n\t*/\n\t\
    static pair<NP,NP> split(NP x,int k){\n\t\tassert(0<=k&&k<=x->sz);\n\t\tif(k==x->sz)\
    \ return {x,nil};\n\t\tx=x->splay(k);\n\t\tNP l=x->l;\n\t\tl->p = nullptr;\n\t\
    \tx->l = nil;\n\t\treturn {l,x->update()};\n\t}\n\tstatic NP built(int sz,ll vs[]){\t\
    \t\t\t//init\n\t\tif(!sz) return nil;\n\t\tint md=sz/2;\n\t\tNP x= new Node(vs[md]);\n\
    \t\tx->l = built(md,vs);\n\t\tx->l->p=x;\n\t\tx->r=built(sz-(md+1),vs+md+1);\n\
    \t\tx->r->p=x;\n\t\treturn x->update();\n\t}\n\tSplayTree() : n(nil){}\n\tSplayTree(NP\
    \ n) : n(n){}\n\tSplayTree(int sz,ll vs[]){\n\t\tn=built(sz,vs);\n\t}\n\tvoid\
    \ insert(int k,ll v){\n\t\tauto u=split(n,k);\n\t\tn=merge(merge(u.fs,new Node(v)),u.sc);\n\
    \t}\n\tvoid erase(int k){\n\t\tauto u=split(n,k);\n\t\tn=merge(u.fs,split(u.sc,1).sc);\n\
    \t}\n\tvoid merge(SplayTree t){\n\t\tn=merge(n,t.n);\n\t}\n\tint sz(){\n\t\treturn\
    \ n->sz;\n\t}\n\tll get(int k){\t\t\t//kth info\n\t\tauto a=split(n,k);\n\t\t\
    auto b=split(a.sc,1);\n\t\tll ret=b.fs->v;\n\t\tn=merge(merge(a.fs,b.fs),b.sc);\n\
    \t\treturn ret;\n\t}\n\tll sum(int l,int r){\n\t\tauto b=split(n,r);\n\t\tauto\
    \ a=split(b.fs,l);\n\t\tll ret=a.sc->sm;\n\t\tn=merge(merge(a.fs,a.sc),b.sc);\n\
    \t\treturn ret;\n\t}\n\t/*\n\t\tsearch\n\t\t\u5E73\u8861\u4E8C\u5206\u6728\u3068\
    \u3057\u3066\u306E\u5F79\u76EE\u3092\u601D\u3044\u51FA\u305B\n\t\t\u306A\u3093\
    \u304B\u5217\u3092\u304F\u3063\u3064\u3051\u305F\u308A\u308F\u3051\u305F\u308A\
    \u3067\u304D\u308B\u3068\u3060\u3051\u601D\u3063\u3068\u3051\u3070\u57FA\u672C\
    \u3044\u3044\u3051\u3069\n\t\t\u6301\u3063\u3066\u308B\u30C7\u30FC\u30BF\u306B\
    \u9806\u5E8F\u4ED8\u3044\u3066\u308B\u3068\u304D\u306B\u306F\u3061\u3083\u3093\
    \u3068\u4E8C\u5206\u6728\u3068\u3057\u3066\u4F7F\u3048\u308B\n\t*/\n\tint lower_bound(int\
    \ x){\n\t\tNP p=n;\n\t\tint ret=0;\n\t\twhile(p!=nil){\n\t\t\tif(x<=p->v) p=p->l;\n\
    \t\t\telse ret+=(p->l->sz)+1,p=p->r;\n\t\t}\n\t\treturn ret;\n\t}\n};\nSplayTree::NP\
    \ SplayTree::nil = new SplayTree::Node();\nint main(){\n\tint Q;\n\tcin>>Q;\n\t\
    SplayTree ST;\n\trep(tt,Q){\n\t\tint t,x;\n\t\tcin>>t>>x;\n\t\tif(t==1){\n\t\t\
    \tint id=ST.lower_bound(x);\n\t\t\tST.insert(id,x);\n\t\t}else{\n\t\t\tx--;\n\t\
    \t\tcout<<ST.get(x)<<endl;\n\t\t\tST.erase(x);\n\t\t}\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: data structure/splay/arc33C.cpp
  requiredBy: []
  timestamp: '2016-12-08 00:51:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/splay/arc33C.cpp
layout: document
redirect_from:
- /library/data structure/splay/arc33C.cpp
- /library/data structure/splay/arc33C.cpp.html
title: data structure/splay/arc33C.cpp
---
