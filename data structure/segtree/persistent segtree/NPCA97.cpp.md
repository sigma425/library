---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.npca.jp/problems/view/97
  bundledCode: "#line 1 \"data structure/segtree/persistent segtree/NPCA97.cpp\"\n\
    //https://judge.npca.jp/problems/view/97\n#include <iostream>\n#include <cstdio>\n\
    #define rep(i,n) for(int i=0;i<n;i++)\nusing namespace std;\nconst int MX=200000*19;\n\
    struct node{\n\tnode *lch,*rch;\n\tint num;\n\tnode(node *l,node *r,int n){\n\t\
    \tlch=l,rch=r,num=n;\n\t}\n\tnode(node *l,node *r){\n\t\tlch=l,rch=r,num=lch->num+rch->num;\n\
    \t}\n\tnode(){}\n};\nnode pool[MX];\nnode *root[200001];\nnode *nil;\nint sit;\n\
    node *news(node *lch,node *rch,int num){\n\treturn &(pool[sit++]=node(lch,rch,num));\n\
    }\nnode *news(node *lch,node *rch){\n\treturn &(pool[sit++]=node(lch,rch));\n\
    }\nnode *fix(node *x,int pos,int l,int r){\n//\tprintf(\"pos,l,r=(%d,%d,%d)\\\
    n\",pos,l,r);\n\tif(r-l==1){\n\t\treturn news(nil,nil,x->num+1);\n\t}\n\tint m=(l+r)/2;\n\
    \tif(pos<m){\n\t\treturn news(fix(x->lch,pos,l,m),x->rch);\n\t}else{\n\t\treturn\
    \ news(x->lch,fix(x->rch,pos,m,r));\n\t}\n}\nint getnum(int a,int b,int l,int\
    \ r,node *x){\n\tif(x==nil) return 0;\n\tif(b<=l||r<=a) return 0;\n\tif(a<=l&&r<=b)\
    \ return x->num;\n\tint m=(l+r)/2;\n\treturn getnum(a,b,l,m,x->lch)+getnum(a,b,m,r,x->rch);\n\
    }\nvoid showtree(node *x){\n\tif(x==nil) return;\n\tcout<<\"(\";\n\tshowtree(x->lch);\n\
    \tcout<<x->num;\n\tshowtree(x->rch);\n\tcout<<\")\";\n}\nint N,l[200000],r[200000];\n\
    int main(){\n\tnil=news(0,0,0);\n\tnil->lch=nil->rch=nil;\n\tcin>>N;\n\trep(i,N)\
    \ cin>>l[i];\n\trep(i,N) cin>>r[i];\n\tint x=0;\n\troot[0]=nil;\n\trep(i,N){\n\
    //\t\tshowtree(root[i]);puts(\"\");\n\t\troot[i+1]=fix(root[i],x,0,N);\n\t\tint\
    \ cnt=getnum(l[i],r[i],0,N,root[x+1]);\n\t\tx=((long long)cnt*l[i]+r[i])%(i+2);\n\
    \t}\n\tcout<<x<<endl;\n}\n"
  code: "//https://judge.npca.jp/problems/view/97\n#include <iostream>\n#include <cstdio>\n\
    #define rep(i,n) for(int i=0;i<n;i++)\nusing namespace std;\nconst int MX=200000*19;\n\
    struct node{\n\tnode *lch,*rch;\n\tint num;\n\tnode(node *l,node *r,int n){\n\t\
    \tlch=l,rch=r,num=n;\n\t}\n\tnode(node *l,node *r){\n\t\tlch=l,rch=r,num=lch->num+rch->num;\n\
    \t}\n\tnode(){}\n};\nnode pool[MX];\nnode *root[200001];\nnode *nil;\nint sit;\n\
    node *news(node *lch,node *rch,int num){\n\treturn &(pool[sit++]=node(lch,rch,num));\n\
    }\nnode *news(node *lch,node *rch){\n\treturn &(pool[sit++]=node(lch,rch));\n\
    }\nnode *fix(node *x,int pos,int l,int r){\n//\tprintf(\"pos,l,r=(%d,%d,%d)\\\
    n\",pos,l,r);\n\tif(r-l==1){\n\t\treturn news(nil,nil,x->num+1);\n\t}\n\tint m=(l+r)/2;\n\
    \tif(pos<m){\n\t\treturn news(fix(x->lch,pos,l,m),x->rch);\n\t}else{\n\t\treturn\
    \ news(x->lch,fix(x->rch,pos,m,r));\n\t}\n}\nint getnum(int a,int b,int l,int\
    \ r,node *x){\n\tif(x==nil) return 0;\n\tif(b<=l||r<=a) return 0;\n\tif(a<=l&&r<=b)\
    \ return x->num;\n\tint m=(l+r)/2;\n\treturn getnum(a,b,l,m,x->lch)+getnum(a,b,m,r,x->rch);\n\
    }\nvoid showtree(node *x){\n\tif(x==nil) return;\n\tcout<<\"(\";\n\tshowtree(x->lch);\n\
    \tcout<<x->num;\n\tshowtree(x->rch);\n\tcout<<\")\";\n}\nint N,l[200000],r[200000];\n\
    int main(){\n\tnil=news(0,0,0);\n\tnil->lch=nil->rch=nil;\n\tcin>>N;\n\trep(i,N)\
    \ cin>>l[i];\n\trep(i,N) cin>>r[i];\n\tint x=0;\n\troot[0]=nil;\n\trep(i,N){\n\
    //\t\tshowtree(root[i]);puts(\"\");\n\t\troot[i+1]=fix(root[i],x,0,N);\n\t\tint\
    \ cnt=getnum(l[i],r[i],0,N,root[x+1]);\n\t\tx=((long long)cnt*l[i]+r[i])%(i+2);\n\
    \t}\n\tcout<<x<<endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: data structure/segtree/persistent segtree/NPCA97.cpp
  requiredBy: []
  timestamp: '2017-02-02 01:38:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/segtree/persistent segtree/NPCA97.cpp
layout: document
redirect_from:
- /library/data structure/segtree/persistent segtree/NPCA97.cpp
- /library/data structure/segtree/persistent segtree/NPCA97.cpp.html
title: data structure/segtree/persistent segtree/NPCA97.cpp
---
