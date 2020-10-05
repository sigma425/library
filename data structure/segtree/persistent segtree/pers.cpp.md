---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://codeforces.com/contest/484/problem/E
    - https://judge.npca.jp/problems/view/97
  bundledCode: "#line 1 \"data structure/segtree/persistent segtree/pers.cpp\"\n/*\n\
    \u6C38\u7D9Asegtree\n\u66F8\u3044\u3066\u308B\u9014\u4E2D\n\nverified by https://judge.npca.jp/problems/view/97\n\
    \t\t\thttp://codeforces.com/contest/484/problem/E\n*/\n\n\n#include <iostream>\n\
    #include <cstdio>\n#define rep(i,n) for(int i=0;i<n;i++)\nusing namespace std;\n\
    const int MX=200000*19;\nstruct node{\n\tnode *lch,*rch;\n\tint sum;\n\tnode(node\
    \ *l,node *r,int s):lch(l),rch(r),sum(s){}\n\tnode(node *l,node *r){\n\t\tlch=l,rch=r,sum=lch->sum+rch->sum;\n\
    \t}\n\tnode(){}\n};\nnode pool[MX];\nnode* root[200001];\nnode* nil;\nint SI;\n\
    node* news(node *lch,node *rch,int sum){\n\treturn &(pool[SI++]=node(lch,rch,sum));\n\
    }\nnode* news(node *lch,node *rch){\n\treturn &(pool[SI++]=node(lch,rch));\n}\n\
    node* update(node *x,int pos,int l,int r){\n//\tprintf(\"pos,l,r=(%d,%d,%d)\\\
    n\",pos,l,r);\n\tif(r-l==1){\n\t\treturn news(nil,nil,x->sum);\n\t}\n\tint m=(l+r)/2;\n\
    \tif(pos<m){\n\t\treturn news(fix(x->lch,pos,l,m),x->rch);\n\t}else{\n\t\treturn\
    \ news(x->lch,fix(x->rch,pos,m,r));\n\t}\n}\nint getsum(int a,int b,int l,int\
    \ r,node *x){\n\tif(x==nil) return 0;\t\t//\u521D\u671F\u5024\u304C\u5909\u306A\
    \u306E\u306A\u3089\u3053\u3053\u3092\u5909\u3048\u308B\n\tif(b<=l||r<=a) return\
    \ 0;\n\tif(a<=l&&r<=b) return x->sum;\n\tint m=(l+r)/2;\n\treturn getsum(a,b,l,m,x->lch)+getsum(a,b,m,r,x->rch);\n\
    }\nvoid showtree(node *x){\n\tif(x==nil) return;\n\tcout<<\"(\";\n\tshowtree(x->lch);\n\
    \tcout<<x->sum;\n\tshowtree(x->rch);\n\tcout<<\")\";\n}\nint N,l[200000],r[200000];\n\
    int main(){\n\tnil=news(0,0,0);\n\tnil->lch=nil->rch=nil;\n\tcin>>N;\n\trep(i,N)\
    \ cin>>l[i];\n\trep(i,N) cin>>r[i];\n\tint x=0;\n\troot[0]=nil;\n\trep(i,N){\n\
    //\t\tshowtree(root[i]);puts(\"\");\n\t\troot[i+1]=fix(root[i],x,0,N);\n\t\tint\
    \ cnt=getsum(l[i],r[i],0,N,root[x+1]);\n\t\tx=((long long)cnt*l[i]+r[i])%(i+2);\n\
    \t}\n\tcout<<x<<endl;\n}\n"
  code: "/*\n\u6C38\u7D9Asegtree\n\u66F8\u3044\u3066\u308B\u9014\u4E2D\n\nverified\
    \ by https://judge.npca.jp/problems/view/97\n\t\t\thttp://codeforces.com/contest/484/problem/E\n\
    */\n\n\n#include <iostream>\n#include <cstdio>\n#define rep(i,n) for(int i=0;i<n;i++)\n\
    using namespace std;\nconst int MX=200000*19;\nstruct node{\n\tnode *lch,*rch;\n\
    \tint sum;\n\tnode(node *l,node *r,int s):lch(l),rch(r),sum(s){}\n\tnode(node\
    \ *l,node *r){\n\t\tlch=l,rch=r,sum=lch->sum+rch->sum;\n\t}\n\tnode(){}\n};\n\
    node pool[MX];\nnode* root[200001];\nnode* nil;\nint SI;\nnode* news(node *lch,node\
    \ *rch,int sum){\n\treturn &(pool[SI++]=node(lch,rch,sum));\n}\nnode* news(node\
    \ *lch,node *rch){\n\treturn &(pool[SI++]=node(lch,rch));\n}\nnode* update(node\
    \ *x,int pos,int l,int r){\n//\tprintf(\"pos,l,r=(%d,%d,%d)\\n\",pos,l,r);\n\t\
    if(r-l==1){\n\t\treturn news(nil,nil,x->sum);\n\t}\n\tint m=(l+r)/2;\n\tif(pos<m){\n\
    \t\treturn news(fix(x->lch,pos,l,m),x->rch);\n\t}else{\n\t\treturn news(x->lch,fix(x->rch,pos,m,r));\n\
    \t}\n}\nint getsum(int a,int b,int l,int r,node *x){\n\tif(x==nil) return 0;\t\
    \t//\u521D\u671F\u5024\u304C\u5909\u306A\u306E\u306A\u3089\u3053\u3053\u3092\u5909\
    \u3048\u308B\n\tif(b<=l||r<=a) return 0;\n\tif(a<=l&&r<=b) return x->sum;\n\t\
    int m=(l+r)/2;\n\treturn getsum(a,b,l,m,x->lch)+getsum(a,b,m,r,x->rch);\n}\nvoid\
    \ showtree(node *x){\n\tif(x==nil) return;\n\tcout<<\"(\";\n\tshowtree(x->lch);\n\
    \tcout<<x->sum;\n\tshowtree(x->rch);\n\tcout<<\")\";\n}\nint N,l[200000],r[200000];\n\
    int main(){\n\tnil=news(0,0,0);\n\tnil->lch=nil->rch=nil;\n\tcin>>N;\n\trep(i,N)\
    \ cin>>l[i];\n\trep(i,N) cin>>r[i];\n\tint x=0;\n\troot[0]=nil;\n\trep(i,N){\n\
    //\t\tshowtree(root[i]);puts(\"\");\n\t\troot[i+1]=fix(root[i],x,0,N);\n\t\tint\
    \ cnt=getsum(l[i],r[i],0,N,root[x+1]);\n\t\tx=((long long)cnt*l[i]+r[i])%(i+2);\n\
    \t}\n\tcout<<x<<endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: data structure/segtree/persistent segtree/pers.cpp
  requiredBy: []
  timestamp: '2017-02-02 01:38:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/segtree/persistent segtree/pers.cpp
layout: document
redirect_from:
- /library/data structure/segtree/persistent segtree/pers.cpp
- /library/data structure/segtree/persistent segtree/pers.cpp.html
title: data structure/segtree/persistent segtree/pers.cpp
---
