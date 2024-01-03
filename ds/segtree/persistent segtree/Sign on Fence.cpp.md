---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://codeforces.com/contest/484/problem/E
  bundledCode: "#line 1 \"ds/segtree/persistent segtree/Sign on Fence.cpp\"\n//http://codeforces.com/contest/484/problem/E\n\
    #include <iostream>\n#include <cstdio>\n#include <vector>\n#include <set>\n#include\
    \ <map>\n#include <queue>\n#include <deque>\n#include <stack>\n#include <algorithm>\n\
    #include <cstring>\n#include <functional>\n#include <cmath>\nusing namespace std;\n\
    #define rep(i,n) for(int i=0;i<(n);++i)\n#define rep1(i,n) for(int i=1;i<=(n);++i)\n\
    #define all(c) (c).begin(),(c).end()\n#define fs first\n#define sc second\n#define\
    \ pb push_back\n#define show(x) cout << #x << \" \" << x << endl\n#define chmax(x,y)\
    \ x=max(x,y)\nconst int MX=2000000;\nstruct node{\n\tnode *lch,*rch;\n\tint l,r,mx;\n\
    \tbool all;\n\tnode(node *lch_,node *rch_,int l_,int r_,int mx_,bool all_){\n\t\
    \tlch=lch_,rch=rch_,l=l_,r=r_,mx=mx_,all=all_;\n\t}\n\tnode(node *lch_,node *rch_){\n\
    \t\tlch=lch_,rch=rch_;\n\t\tall=lch->all & rch->all;\n\t\tif(lch->all) l=lch->mx+rch->l;\n\
    \t\telse l=lch->l;\n\t\tif(rch->all) r=rch->mx+lch->r;\n\t\telse r=rch->r;\n\t\
    \tmx=max(lch->mx,rch->mx);\n\t\tchmax(mx,lch->r+rch->l);\n\t}\n\tnode(){}\n};\n\
    node pool[MX];\nnode *root[100001];\nnode *nil;\nint sit;\nnode *news(node *lch,node\
    \ *rch,int l,int r,int mx,bool all){\n\treturn &(pool[sit++]=node(lch,rch,l,r,mx,all));\n\
    }\nnode *news(node *lch,node *rch){\n\treturn &(pool[sit++]=node(lch,rch));\n\
    }\nnode *fix(node *x,int pos,int l,int r){\t\t//0->1\n//\tprintf(\"pos,l,r=(%d,%d,%d)\\\
    n\",pos,l,r);\n\tif(r-l==1){\n\t\treturn news(nil,nil,1,1,1,1);\n\t}\n\tint m=(l+r)/2;\n\
    \tif(pos<m){\n\t\treturn news(fix(x->lch,pos,l,m),x->rch);\n\t}else{\n\t\treturn\
    \ news(x->lch,fix(x->rch,pos,m,r));\n\t}\n}\ntypedef pair<int,int> P;\nint mx,cont;\n\
    void query(int a,int b,int l,int r,node *x){\n\tif(x==nil){\n\t\tcont=0;\n\t\t\
    return;\n\t}\n\tif(b<=l||r<=a) return;\n\tif(a<=l&&r<=b){\n\t\tchmax(mx,x->mx);\n\
    \t\tchmax(mx,cont+x->l);\n\t\tif(x->all) cont+=r-l;\n\t\telse cont=x->r;\n\t\t\
    return;\n\t}\n\tint m=(l+r)/2;\n\tquery(a,b,l,m,x->lch);\n\tquery(a,b,m,r,x->rch);\n\
    }\nvoid showtree(node *x){\n\tif(x==nil) return;\n\tcout<<\"(\";\n\tshowtree(x->lch);\n\
    \tprintf(\"<%d,%d,%d>\",x->l,x->mx,x->r);\n\tshowtree(x->rch);\n\tcout<<\")\"\
    ;\n}\nint n,q,x[100000];\nvector<int> ash;\nvector<int> val[100000];\nint main(){\n\
    \tnil=news(0,0,0,0,0,0);\n\tnil->lch=nil->rch=nil;\n\troot[0]=nil;\n\tcin>>n;\n\
    \trep(i,n) cin>>x[i];\n\trep(i,n) ash.pb(x[i]);\n\tsort(all(ash));\n\tash.erase(unique(all(ash)),ash.end());\n\
    \tint m=ash.size();\n\trep(i,n) x[i]=lower_bound(all(ash),x[i])-ash.begin();\n\
    \trep(i,n) val[x[i]].pb(i);\n\trep(i,m){\n\t\troot[i+1]=root[i];\n\t\tfor(int\
    \ v:val[m-1-i]) root[i+1]=fix(root[i+1],v,0,n);\n\t}\n/*\trep(i,m+1){\n\t\tprintf(\"\
    ver i:%d\\n\",i);\n\t\tshowtree(root[i]);puts(\"\");\n\t}*/\n\tcin>>q;\n\trep(i,q){\n\
    \t\tint l,r,w;\n\t\tcin>>l>>r>>w;\n\t\tl--;\n\t\tint ub=m,lb=0;\n\t\twhile(ub-lb>1){\n\
    \t\t\tmx=cont=0;\n\t\t\tint mid=(ub+lb)/2;\n\t\t\tquery(l,r,0,n,root[mid]);\n\
    //\t\t\tprintf(\"ver,mx=(%d,%d)\\n\",mid,mx);\n\t\t\tif(w<=mx) ub=mid;\n\t\t\t\
    else lb=mid;\n\t\t}\n\t\tcout<<ash[m-ub]<<endl;\n\t}\n}\n"
  code: "//http://codeforces.com/contest/484/problem/E\n#include <iostream>\n#include\
    \ <cstdio>\n#include <vector>\n#include <set>\n#include <map>\n#include <queue>\n\
    #include <deque>\n#include <stack>\n#include <algorithm>\n#include <cstring>\n\
    #include <functional>\n#include <cmath>\nusing namespace std;\n#define rep(i,n)\
    \ for(int i=0;i<(n);++i)\n#define rep1(i,n) for(int i=1;i<=(n);++i)\n#define all(c)\
    \ (c).begin(),(c).end()\n#define fs first\n#define sc second\n#define pb push_back\n\
    #define show(x) cout << #x << \" \" << x << endl\n#define chmax(x,y) x=max(x,y)\n\
    const int MX=2000000;\nstruct node{\n\tnode *lch,*rch;\n\tint l,r,mx;\n\tbool\
    \ all;\n\tnode(node *lch_,node *rch_,int l_,int r_,int mx_,bool all_){\n\t\tlch=lch_,rch=rch_,l=l_,r=r_,mx=mx_,all=all_;\n\
    \t}\n\tnode(node *lch_,node *rch_){\n\t\tlch=lch_,rch=rch_;\n\t\tall=lch->all\
    \ & rch->all;\n\t\tif(lch->all) l=lch->mx+rch->l;\n\t\telse l=lch->l;\n\t\tif(rch->all)\
    \ r=rch->mx+lch->r;\n\t\telse r=rch->r;\n\t\tmx=max(lch->mx,rch->mx);\n\t\tchmax(mx,lch->r+rch->l);\n\
    \t}\n\tnode(){}\n};\nnode pool[MX];\nnode *root[100001];\nnode *nil;\nint sit;\n\
    node *news(node *lch,node *rch,int l,int r,int mx,bool all){\n\treturn &(pool[sit++]=node(lch,rch,l,r,mx,all));\n\
    }\nnode *news(node *lch,node *rch){\n\treturn &(pool[sit++]=node(lch,rch));\n\
    }\nnode *fix(node *x,int pos,int l,int r){\t\t//0->1\n//\tprintf(\"pos,l,r=(%d,%d,%d)\\\
    n\",pos,l,r);\n\tif(r-l==1){\n\t\treturn news(nil,nil,1,1,1,1);\n\t}\n\tint m=(l+r)/2;\n\
    \tif(pos<m){\n\t\treturn news(fix(x->lch,pos,l,m),x->rch);\n\t}else{\n\t\treturn\
    \ news(x->lch,fix(x->rch,pos,m,r));\n\t}\n}\ntypedef pair<int,int> P;\nint mx,cont;\n\
    void query(int a,int b,int l,int r,node *x){\n\tif(x==nil){\n\t\tcont=0;\n\t\t\
    return;\n\t}\n\tif(b<=l||r<=a) return;\n\tif(a<=l&&r<=b){\n\t\tchmax(mx,x->mx);\n\
    \t\tchmax(mx,cont+x->l);\n\t\tif(x->all) cont+=r-l;\n\t\telse cont=x->r;\n\t\t\
    return;\n\t}\n\tint m=(l+r)/2;\n\tquery(a,b,l,m,x->lch);\n\tquery(a,b,m,r,x->rch);\n\
    }\nvoid showtree(node *x){\n\tif(x==nil) return;\n\tcout<<\"(\";\n\tshowtree(x->lch);\n\
    \tprintf(\"<%d,%d,%d>\",x->l,x->mx,x->r);\n\tshowtree(x->rch);\n\tcout<<\")\"\
    ;\n}\nint n,q,x[100000];\nvector<int> ash;\nvector<int> val[100000];\nint main(){\n\
    \tnil=news(0,0,0,0,0,0);\n\tnil->lch=nil->rch=nil;\n\troot[0]=nil;\n\tcin>>n;\n\
    \trep(i,n) cin>>x[i];\n\trep(i,n) ash.pb(x[i]);\n\tsort(all(ash));\n\tash.erase(unique(all(ash)),ash.end());\n\
    \tint m=ash.size();\n\trep(i,n) x[i]=lower_bound(all(ash),x[i])-ash.begin();\n\
    \trep(i,n) val[x[i]].pb(i);\n\trep(i,m){\n\t\troot[i+1]=root[i];\n\t\tfor(int\
    \ v:val[m-1-i]) root[i+1]=fix(root[i+1],v,0,n);\n\t}\n/*\trep(i,m+1){\n\t\tprintf(\"\
    ver i:%d\\n\",i);\n\t\tshowtree(root[i]);puts(\"\");\n\t}*/\n\tcin>>q;\n\trep(i,q){\n\
    \t\tint l,r,w;\n\t\tcin>>l>>r>>w;\n\t\tl--;\n\t\tint ub=m,lb=0;\n\t\twhile(ub-lb>1){\n\
    \t\t\tmx=cont=0;\n\t\t\tint mid=(ub+lb)/2;\n\t\t\tquery(l,r,0,n,root[mid]);\n\
    //\t\t\tprintf(\"ver,mx=(%d,%d)\\n\",mid,mx);\n\t\t\tif(w<=mx) ub=mid;\n\t\t\t\
    else lb=mid;\n\t\t}\n\t\tcout<<ash[m-ub]<<endl;\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/persistent segtree/Sign on Fence.cpp
  requiredBy: []
  timestamp: '2024-01-03 19:12:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/persistent segtree/Sign on Fence.cpp
layout: document
redirect_from:
- /library/ds/segtree/persistent segtree/Sign on Fence.cpp
- /library/ds/segtree/persistent segtree/Sign on Fence.cpp.html
title: ds/segtree/persistent segtree/Sign on Fence.cpp
---
