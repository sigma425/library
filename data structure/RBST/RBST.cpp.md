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
  bundledCode: "#line 1 \"data structure/RBST/RBST.cpp\"\n#include <iostream>\n#include\
    \ <cstdio>\n#include <vector>\n#include <set>\n#include <map>\n#include <queue>\n\
    #include <deque>\n#include <stack>\n#include <algorithm>\n#include <cstring>\n\
    #include <functional>\n#include <cmath>\n#include <utility>\n#include <complex>\n\
    using namespace std;\n#define rep(i,n) for(int i=0;i<(n);++i)\n#define rep1(i,n)\
    \ for(int i=1;i<=(n);++i)\n#define all(c) (c).begin(),(c).end()\n#define fs first\n\
    #define sc second\n#define pb push_back\n#define show(x) cout << #x << \" \" <<\
    \ x << endl\n#define chmin(x,y) x=min(x,y);\nint inf=1e9;\nunsigned int xor128(){\n\
    \tstatic unsigned int x=123456789,y=362436069,z=521288629,w=88675123;\n\tunsigned\
    \ int t;\n\tt=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) );\n}\n\
    struct node{\t//node of RBST\n\tint val,mn,size;\n\tnode *lch,*rch;\n\tnode(int\
    \ v){\n\t\tval=mn=v;\n\t\tsize=1;\n\t\tlch=0,rch=0;\n\t}\n};\ntypedef pair<node*,node*>\
    \ Pnn;\nnode *root;\n//\u3059\u3079\u3066\u306E\u95A2\u6570\u306F\u64CD\u4F5C\u3057\
    \u305F\u5F8C\u306E\u6728\u306E\u89AA\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\
    \u3059\nnode *update(node *x){\n\tx->size=1;\n\tx->mn=x->val;\n\tif(x->lch){\n\
    \t\tx->size+=x->lch->size;\n\t\tchmin(x->mn,x->lch->mn);\n\t}\n\tif(x->rch){\n\
    \t\tx->size+=x->rch->size;\n\t\tchmin(x->mn,x->rch->mn);\n\t}\n\treturn x;\n}\n\
    node *merge(node *x,node *y){\n\tif(x==0) return y;\n\tif(y==0) return x;\n\t\
    int m=x->size,n=y->size;\n\tif(xor128()%(m+n)<m){\n\t\tx->rch=merge(x->rch,y);\n\
    \t\treturn update(x);\n\t}else{\n\t\ty->lch=merge(x,y->lch);\n\t\treturn update(y);\n\
    \t}\n}\nint count(node *x){\n\tif(x==0) return 0;\n\treturn x->size;\n}\nPnn split(node\
    \ *x,int pos){\t\t//[,pos),[pos,)\n\tif(x==0) return Pnn(0,0);\n\tif(pos<=count(x->lch)){\n\
    \t\tPnn tmp=split(x->lch,pos);\n\t\tx->lch=tmp.sc;\n\t\treturn Pnn(tmp.fs,update(x));\n\
    \t}else{\n\t\tPnn tmp=split(x->rch,pos-count(x->lch)-1);\n\t\tx->rch=tmp.fs;\n\
    \t\treturn Pnn(update(x),tmp.sc);\n\t}\n}\nnode *insert(node *x,int pos,int val){\n\
    \tnode *p = new node(val);\n\tPnn tmp=split(x,pos);\n\tnode *l=merge(tmp.fs,p),*r=tmp.sc;\n\
    \treturn merge(l,r);\n}\nnode *erase(node *x,int pos){\n\tPnn tmp=split(x,pos);\n\
    \tnode *l=tmp.fs,*r=split(tmp.sc,1).sc;\n\treturn merge(l,r);\n}\nvoid showtree(node\
    \ *c){\n\tif(!c) return;\n\tcout<<\"(\";\n\tshowtree(c->lch);\n\tcout<<\"\"<<\
    \ c->val <<\"\";\n\tshowtree(c->rch);\n\tcout<<\")\";\n}\nvoid query0(int b,int\
    \ c){\n\tPnn x=split(root,c);\n\tPnn y=split(x.fs,b);\n\tPnn z=split(x.sc,1);\n\
    //\tshow(count(z.sc));\n\tnode *t=merge(y.fs,z.fs);\n\tnode *s=merge(y.sc,z.sc);\n\
    //\tshowtree(t);puts(\"\");\n//\tshowtree(s);puts(\"\");\n\troot=merge(t,s);\n\
    }\nvoid query1(int b,int c){\n\tPnn x=split(root,b);\n\tPnn y=split(x.sc,c+1-b);\n\
    //\tshow(count(y.fs));\n\tcout<<y.fs->mn<<endl;\n\troot=merge(x.fs,merge(y.fs,y.sc));\n\
    }\nvoid query2(int b,int c){\n\troot=erase(root,b);\n\troot=insert(root,b,c);\n\
    }\nint main(){\n\tint N,Q;\n\tcin>>N>>Q;\n\trep(i,N){\n\t\tint a;\n\t\tscanf(\"\
    %d\",&a);\n\t\troot=insert(root,i,a);\n\t}\n//\tshow(count(root));\n\tshowtree(root);puts(\"\
    \");\n\trep(i,Q){\n\t\tint a,b,c;\n\t\tcin>>a>>b>>c;\n\t\tif(a==0) query0(b,c);\n\
    \t\tif(a==1) query1(b,c);\n\t\tif(a==2) query2(b,c);\n\t\tshowtree(root);puts(\"\
    \");\n\t}\n}\n"
  code: "#include <iostream>\n#include <cstdio>\n#include <vector>\n#include <set>\n\
    #include <map>\n#include <queue>\n#include <deque>\n#include <stack>\n#include\
    \ <algorithm>\n#include <cstring>\n#include <functional>\n#include <cmath>\n#include\
    \ <utility>\n#include <complex>\nusing namespace std;\n#define rep(i,n) for(int\
    \ i=0;i<(n);++i)\n#define rep1(i,n) for(int i=1;i<=(n);++i)\n#define all(c) (c).begin(),(c).end()\n\
    #define fs first\n#define sc second\n#define pb push_back\n#define show(x) cout\
    \ << #x << \" \" << x << endl\n#define chmin(x,y) x=min(x,y);\nint inf=1e9;\n\
    unsigned int xor128(){\n\tstatic unsigned int x=123456789,y=362436069,z=521288629,w=88675123;\n\
    \tunsigned int t;\n\tt=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8))\
    \ );\n}\nstruct node{\t//node of RBST\n\tint val,mn,size;\n\tnode *lch,*rch;\n\
    \tnode(int v){\n\t\tval=mn=v;\n\t\tsize=1;\n\t\tlch=0,rch=0;\n\t}\n};\ntypedef\
    \ pair<node*,node*> Pnn;\nnode *root;\n//\u3059\u3079\u3066\u306E\u95A2\u6570\u306F\
    \u64CD\u4F5C\u3057\u305F\u5F8C\u306E\u6728\u306E\u89AA\u306E\u30DD\u30A4\u30F3\
    \u30BF\u3092\u8FD4\u3059\nnode *update(node *x){\n\tx->size=1;\n\tx->mn=x->val;\n\
    \tif(x->lch){\n\t\tx->size+=x->lch->size;\n\t\tchmin(x->mn,x->lch->mn);\n\t}\n\
    \tif(x->rch){\n\t\tx->size+=x->rch->size;\n\t\tchmin(x->mn,x->rch->mn);\n\t}\n\
    \treturn x;\n}\nnode *merge(node *x,node *y){\n\tif(x==0) return y;\n\tif(y==0)\
    \ return x;\n\tint m=x->size,n=y->size;\n\tif(xor128()%(m+n)<m){\n\t\tx->rch=merge(x->rch,y);\n\
    \t\treturn update(x);\n\t}else{\n\t\ty->lch=merge(x,y->lch);\n\t\treturn update(y);\n\
    \t}\n}\nint count(node *x){\n\tif(x==0) return 0;\n\treturn x->size;\n}\nPnn split(node\
    \ *x,int pos){\t\t//[,pos),[pos,)\n\tif(x==0) return Pnn(0,0);\n\tif(pos<=count(x->lch)){\n\
    \t\tPnn tmp=split(x->lch,pos);\n\t\tx->lch=tmp.sc;\n\t\treturn Pnn(tmp.fs,update(x));\n\
    \t}else{\n\t\tPnn tmp=split(x->rch,pos-count(x->lch)-1);\n\t\tx->rch=tmp.fs;\n\
    \t\treturn Pnn(update(x),tmp.sc);\n\t}\n}\nnode *insert(node *x,int pos,int val){\n\
    \tnode *p = new node(val);\n\tPnn tmp=split(x,pos);\n\tnode *l=merge(tmp.fs,p),*r=tmp.sc;\n\
    \treturn merge(l,r);\n}\nnode *erase(node *x,int pos){\n\tPnn tmp=split(x,pos);\n\
    \tnode *l=tmp.fs,*r=split(tmp.sc,1).sc;\n\treturn merge(l,r);\n}\nvoid showtree(node\
    \ *c){\n\tif(!c) return;\n\tcout<<\"(\";\n\tshowtree(c->lch);\n\tcout<<\"\"<<\
    \ c->val <<\"\";\n\tshowtree(c->rch);\n\tcout<<\")\";\n}\nvoid query0(int b,int\
    \ c){\n\tPnn x=split(root,c);\n\tPnn y=split(x.fs,b);\n\tPnn z=split(x.sc,1);\n\
    //\tshow(count(z.sc));\n\tnode *t=merge(y.fs,z.fs);\n\tnode *s=merge(y.sc,z.sc);\n\
    //\tshowtree(t);puts(\"\");\n//\tshowtree(s);puts(\"\");\n\troot=merge(t,s);\n\
    }\nvoid query1(int b,int c){\n\tPnn x=split(root,b);\n\tPnn y=split(x.sc,c+1-b);\n\
    //\tshow(count(y.fs));\n\tcout<<y.fs->mn<<endl;\n\troot=merge(x.fs,merge(y.fs,y.sc));\n\
    }\nvoid query2(int b,int c){\n\troot=erase(root,b);\n\troot=insert(root,b,c);\n\
    }\nint main(){\n\tint N,Q;\n\tcin>>N>>Q;\n\trep(i,N){\n\t\tint a;\n\t\tscanf(\"\
    %d\",&a);\n\t\troot=insert(root,i,a);\n\t}\n//\tshow(count(root));\n\tshowtree(root);puts(\"\
    \");\n\trep(i,Q){\n\t\tint a,b,c;\n\t\tcin>>a>>b>>c;\n\t\tif(a==0) query0(b,c);\n\
    \t\tif(a==1) query1(b,c);\n\t\tif(a==2) query2(b,c);\n\t\tshowtree(root);puts(\"\
    \");\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: data structure/RBST/RBST.cpp
  requiredBy: []
  timestamp: '2016-12-08 00:51:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/RBST/RBST.cpp
layout: document
redirect_from:
- /library/data structure/RBST/RBST.cpp
- /library/data structure/RBST/RBST.cpp.html
title: data structure/RBST/RBST.cpp
---
