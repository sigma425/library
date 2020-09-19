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
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330
  bundledCode: "#line 1 \"data structure/unionfind/unionfind_dif.cpp\"\n/*\n\tw[x]-w[y]=d\
    \ \u3068\u3059\u308B\u30AF\u30A8\u30EA unite(x,y,d)\n\tw[x]-w[y] \u3092\u7B54\u3048\
    \u308B\u30AF\u30A8\u30EA diff(x,y)\u304C\u51E6\u7406\u3067\u304D\u308B\n\td[x]=w[par[x]]-w[x]\n\
    \tdiff\u306E\u524D\u306Bsame\u3067\u6BD4\u8F03\u53EF\u80FD\u304B\u3069\u3046\u304B\
    \u898B\u308B\u3053\u3068!!(same<->\u6BD4\u8F03\u53EF\u80FD)\n\tsame\u3057\u3066\
    \u308C\u3070diff\u306E\u4E2D\u306Efind\u306F\u3044\u3089\u306A\u3044\u3051\u3069\
    \u4E00\u5FDC\n\n\tw[x]=\u5B9A\u6570 \u307F\u305F\u3044\u306A\u306E\u304C\u3042\
    \u308B\u306A\u3089,w[0]:=0\u3068\u3057\u3066w[x]-w[0]=\u5B9A\u6570 \u306B\u3059\
    \u308B\n\tw[x]+w[y]=a\u3068\u304B\u3082\u9802\u70B9\u500D\u52A0\u3067\n\n\tverified\
    \ by http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330\n*/\n#include\
    \ <bits/stdc++.h>\n#define rep(i,N) for(int i=0;i<N;i++)\nusing namespace std;\n\
    typedef long long ll;\nstruct unionfind{\n\tint par[100000];\n\tll d[100000];\n\
    \tvoid init(int n) { rep(i,n) par[i]=i,d[i]=0; }\n\tint find(int x){\n\t\tif(x==par[x])\
    \ return x;\n\t\tint r=find(par[x]);\n\t\td[x]+=d[par[x]];\n\t\treturn par[x]=r;\n\
    \t}\n\tvoid unite(int x,int y,int z){\t\t//w[x]-w[y]=z\t\n\t\tint rx=find(x),ry=find(y);\n\
    \t\tif(rx==ry) return;\n\t\td[ry]=d[x]-d[y]-z;\n\t\tpar[ry]=rx;\n\t}\n\tint diff(int\
    \ x,int y){\t\t//w[x]-w[y]=?\n\t\tfind(x),find(y);\t\t\t//\u3044\u308B!!\n\t\t\
    return d[x]-d[y];\n\t}\n\tbool same(int x,int y) { return find(x)==find(y); }\n\
    }UF;\n\nint main(){\n\twhile(true){\n\t\tint N,M;\n\t\tcin>>N>>M;\n\t\tif(N==0)\
    \ break;\n\t\tUF.init(N);\n\t\trep(t,M){\n\t\t\tchar c;\n\t\t\tcin>>c;\n\t\t\t\
    if(c=='!'){\n\t\t\t\tint x,y,z;\n\t\t\t\tcin>>x>>y>>z;\n\t\t\t\tx--,y--;\n\t\t\
    \t\tUF.unite(y,x,z);\n\t\t\t}else{\n\t\t\t\tint x,y;\n\t\t\t\tcin>>x>>y;\n\t\t\
    \t\tx--,y--;\n\t\t\t\tif(!UF.same(x,y)) puts(\"UNKNOWN\");\n\t\t\t\telse cout<<UF.diff(y,x)<<endl;\n\
    \t\t\t}\n\t\t}\n\t}\n}\n"
  code: "/*\n\tw[x]-w[y]=d \u3068\u3059\u308B\u30AF\u30A8\u30EA unite(x,y,d)\n\tw[x]-w[y]\
    \ \u3092\u7B54\u3048\u308B\u30AF\u30A8\u30EA diff(x,y)\u304C\u51E6\u7406\u3067\
    \u304D\u308B\n\td[x]=w[par[x]]-w[x]\n\tdiff\u306E\u524D\u306Bsame\u3067\u6BD4\u8F03\
    \u53EF\u80FD\u304B\u3069\u3046\u304B\u898B\u308B\u3053\u3068!!(same<->\u6BD4\u8F03\
    \u53EF\u80FD)\n\tsame\u3057\u3066\u308C\u3070diff\u306E\u4E2D\u306Efind\u306F\u3044\
    \u3089\u306A\u3044\u3051\u3069\u4E00\u5FDC\n\n\tw[x]=\u5B9A\u6570 \u307F\u305F\
    \u3044\u306A\u306E\u304C\u3042\u308B\u306A\u3089,w[0]:=0\u3068\u3057\u3066w[x]-w[0]=\u5B9A\
    \u6570 \u306B\u3059\u308B\n\tw[x]+w[y]=a\u3068\u304B\u3082\u9802\u70B9\u500D\u52A0\
    \u3067\n\n\tverified by http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330\n\
    */\n#include <bits/stdc++.h>\n#define rep(i,N) for(int i=0;i<N;i++)\nusing namespace\
    \ std;\ntypedef long long ll;\nstruct unionfind{\n\tint par[100000];\n\tll d[100000];\n\
    \tvoid init(int n) { rep(i,n) par[i]=i,d[i]=0; }\n\tint find(int x){\n\t\tif(x==par[x])\
    \ return x;\n\t\tint r=find(par[x]);\n\t\td[x]+=d[par[x]];\n\t\treturn par[x]=r;\n\
    \t}\n\tvoid unite(int x,int y,int z){\t\t//w[x]-w[y]=z\t\n\t\tint rx=find(x),ry=find(y);\n\
    \t\tif(rx==ry) return;\n\t\td[ry]=d[x]-d[y]-z;\n\t\tpar[ry]=rx;\n\t}\n\tint diff(int\
    \ x,int y){\t\t//w[x]-w[y]=?\n\t\tfind(x),find(y);\t\t\t//\u3044\u308B!!\n\t\t\
    return d[x]-d[y];\n\t}\n\tbool same(int x,int y) { return find(x)==find(y); }\n\
    }UF;\n\nint main(){\n\twhile(true){\n\t\tint N,M;\n\t\tcin>>N>>M;\n\t\tif(N==0)\
    \ break;\n\t\tUF.init(N);\n\t\trep(t,M){\n\t\t\tchar c;\n\t\t\tcin>>c;\n\t\t\t\
    if(c=='!'){\n\t\t\t\tint x,y,z;\n\t\t\t\tcin>>x>>y>>z;\n\t\t\t\tx--,y--;\n\t\t\
    \t\tUF.unite(y,x,z);\n\t\t\t}else{\n\t\t\t\tint x,y;\n\t\t\t\tcin>>x>>y;\n\t\t\
    \t\tx--,y--;\n\t\t\t\tif(!UF.same(x,y)) puts(\"UNKNOWN\");\n\t\t\t\telse cout<<UF.diff(y,x)<<endl;\n\
    \t\t\t}\n\t\t}\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: data structure/unionfind/unionfind_dif.cpp
  requiredBy: []
  timestamp: '2016-12-08 00:51:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/unionfind/unionfind_dif.cpp
layout: document
redirect_from:
- /library/data structure/unionfind/unionfind_dif.cpp
- /library/data structure/unionfind/unionfind_dif.cpp.html
title: data structure/unionfind/unionfind_dif.cpp
---
