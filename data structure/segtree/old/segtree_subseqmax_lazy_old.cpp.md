---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data structure/segtree/old/segtree_subseqmax_lazy_old.cpp\"\
    \n/*\n\t\n*/\n#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define show(x) cout\
    \ << #x << \" = \" << x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y)\
    \ x=max(x,y)\nusing namespace std;\nstruct Node{\n\tint mx,l,r,sum;\n};\nNode\
    \ merge(Node a,Node b){\n\tNode ret;\n\tret.sum=a.sum+b.sum;\n\tret.l=max(a.l,a.sum+b.l);\n\
    \tret.r=max(b.r,b.sum+a.r);\n\tret.mx=max(a.r+b.l,max(a.mx,b.mx));\n\treturn ret;\n\
    }\nstruct segtree{\n\tint getp2(int x){\n\t\tint p=1;\n\t\twhile(p<x) p*=2;\n\t\
    \treturn p;\n\t}\n\tsegtree(int N):p2(getp2(N)),seg(p2*2),same(p2*2),val(p2*2)\
    \ {\n\n\t}\n\tconst int p2;\n\tvector<Node> seg;\n\tvector<bool> same;\n\tvector<int>\
    \ val;\n\tvoid dosame(int k,int v,int len){\n\t\tif(len==0) return;\n\t\tsame[k]=1,val[k]=v;\n\
    \t\tshow(k);\n\t\tshow(v);\n\t\tshow(len);\n\t\tputs(\"\");\n\t\tif(v>=0) seg[k].l=seg[k].r=seg[k].mx=seg[k].sum=v*len;\n\
    \t\telse seg[k].l=seg[k].r=seg[k].mx=0,seg[k].sum=v*len;\n\t}\n\tNode calc(int\
    \ a,int b,int l,int r,int k){\n\t\tif(r<=a||b<=l) return Node();\n\t\tif(a<=l&&r<=b)\
    \ return seg[k];\n\t\tif(same[k]){\n\t\t\tdosame(k*2,val[k],(r-l)/2);\n\t\t\t\
    dosame(k*2+1,val[k],(r-l)/2);\n\t\t}\n\t\treturn merge(calc(a,b,l,(l+r)/2,k*2),calc(a,b,(l+r)/2,r,k*2+1));\n\
    \t}\n\tNode calc(int a,int b){\n\t\treturn calc(a,b,0,p2,1);\n\t}\n\tvoid change(int\
    \ a,int b,int l,int r,int k,int v){\n\t\tif(r<=a||b<=l) return;\n\t\tif(a<=l&&r<=b){\n\
    \t\t\tdosame(k,v,r-l);\n\t\t\treturn;\n\t\t}\n\t\tif(same[k]){\n\t\t\tdosame(k*2,val[k],(r-l)/2);\n\
    \t\t\tdosame(k*2+1,val[k],(r-l)/2);\n\t\t}\n\t\tsame[k]=0;\n\t\tchange(a,b,l,(l+r)/2,k*2,v);\n\
    \t\tchange(a,b,(l+r)/2,r,k*2+1,v);\n\t\tseg[k]=merge(seg[k*2],seg[k*2+1]);\n\t\
    }\n\tvoid change(int a,int b,int v){\n\t\tchange(a,b,0,p2,1,v);\n\t}\n};\nint\
    \ main(){\n\tint N;\n\tcin>>N;\n\tsegtree seg(N);\n\tint Q;\n\tcin>>Q;\n\trep(i,Q){\n\
    \t\tint t;\n\t\tcin>>t;\n\t\tif(t==0){\n\t\t\tint a,b,v;\n\t\t\tcin>>a>>b>>v;\n\
    \t\t\tseg.change(a,b,v);\n\t\t}else{\n\t\t\tint a,b;\n\t\t\tcin>>a>>b;\n\t\t\t\
    cout<<seg.calc(a,b).mx<<endl;\n\t\t}\n\t}\n}\n"
  code: "/*\n\t\n*/\n#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define show(x) cout\
    \ << #x << \" = \" << x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y)\
    \ x=max(x,y)\nusing namespace std;\nstruct Node{\n\tint mx,l,r,sum;\n};\nNode\
    \ merge(Node a,Node b){\n\tNode ret;\n\tret.sum=a.sum+b.sum;\n\tret.l=max(a.l,a.sum+b.l);\n\
    \tret.r=max(b.r,b.sum+a.r);\n\tret.mx=max(a.r+b.l,max(a.mx,b.mx));\n\treturn ret;\n\
    }\nstruct segtree{\n\tint getp2(int x){\n\t\tint p=1;\n\t\twhile(p<x) p*=2;\n\t\
    \treturn p;\n\t}\n\tsegtree(int N):p2(getp2(N)),seg(p2*2),same(p2*2),val(p2*2)\
    \ {\n\n\t}\n\tconst int p2;\n\tvector<Node> seg;\n\tvector<bool> same;\n\tvector<int>\
    \ val;\n\tvoid dosame(int k,int v,int len){\n\t\tif(len==0) return;\n\t\tsame[k]=1,val[k]=v;\n\
    \t\tshow(k);\n\t\tshow(v);\n\t\tshow(len);\n\t\tputs(\"\");\n\t\tif(v>=0) seg[k].l=seg[k].r=seg[k].mx=seg[k].sum=v*len;\n\
    \t\telse seg[k].l=seg[k].r=seg[k].mx=0,seg[k].sum=v*len;\n\t}\n\tNode calc(int\
    \ a,int b,int l,int r,int k){\n\t\tif(r<=a||b<=l) return Node();\n\t\tif(a<=l&&r<=b)\
    \ return seg[k];\n\t\tif(same[k]){\n\t\t\tdosame(k*2,val[k],(r-l)/2);\n\t\t\t\
    dosame(k*2+1,val[k],(r-l)/2);\n\t\t}\n\t\treturn merge(calc(a,b,l,(l+r)/2,k*2),calc(a,b,(l+r)/2,r,k*2+1));\n\
    \t}\n\tNode calc(int a,int b){\n\t\treturn calc(a,b,0,p2,1);\n\t}\n\tvoid change(int\
    \ a,int b,int l,int r,int k,int v){\n\t\tif(r<=a||b<=l) return;\n\t\tif(a<=l&&r<=b){\n\
    \t\t\tdosame(k,v,r-l);\n\t\t\treturn;\n\t\t}\n\t\tif(same[k]){\n\t\t\tdosame(k*2,val[k],(r-l)/2);\n\
    \t\t\tdosame(k*2+1,val[k],(r-l)/2);\n\t\t}\n\t\tsame[k]=0;\n\t\tchange(a,b,l,(l+r)/2,k*2,v);\n\
    \t\tchange(a,b,(l+r)/2,r,k*2+1,v);\n\t\tseg[k]=merge(seg[k*2],seg[k*2+1]);\n\t\
    }\n\tvoid change(int a,int b,int v){\n\t\tchange(a,b,0,p2,1,v);\n\t}\n};\nint\
    \ main(){\n\tint N;\n\tcin>>N;\n\tsegtree seg(N);\n\tint Q;\n\tcin>>Q;\n\trep(i,Q){\n\
    \t\tint t;\n\t\tcin>>t;\n\t\tif(t==0){\n\t\t\tint a,b,v;\n\t\t\tcin>>a>>b>>v;\n\
    \t\t\tseg.change(a,b,v);\n\t\t}else{\n\t\t\tint a,b;\n\t\t\tcin>>a>>b;\n\t\t\t\
    cout<<seg.calc(a,b).mx<<endl;\n\t\t}\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: data structure/segtree/old/segtree_subseqmax_lazy_old.cpp
  requiredBy: []
  timestamp: '2017-04-22 20:47:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/segtree/old/segtree_subseqmax_lazy_old.cpp
layout: document
redirect_from:
- /library/data structure/segtree/old/segtree_subseqmax_lazy_old.cpp
- /library/data structure/segtree/old/segtree_subseqmax_lazy_old.cpp.html
title: data structure/segtree/old/segtree_subseqmax_lazy_old.cpp
---
