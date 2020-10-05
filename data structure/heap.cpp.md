---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data structure/heap.cpp\"\n#include <bits/stdc++.h>\n#define\
    \ rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\nconst int MAX_N=10000000;\n\
    struct heap{\n\tint pool[MAX_N];\n\tint sz;\n\theap(){sz=0;}\n\tvoid insert(int\
    \ x){\n\t\tint v=sz++;\n\t\tpool[v]=x;\n\t\twhile(v){\n\t\t\tint p=(v-1)/2;\n\t\
    \t\tif(pool[p]<=pool[v]) break;\n\t\t\tswap(pool[p],pool[v]);\n\t\t\tv=p;\n\t\t\
    }\n\t}\n\tint deletemin(){\n\t\tassert(sz);\n\t\tsz--;\n\t\tint ret=pool[0];\n\
    \t\tpool[0]=pool[sz];\n\t\tint v=0;\n\t\twhile(true){\n\t\t\tint l=v*2+1,r=v*2+2;\n\
    \t\t\tif(sz<=l) break;\n\t\t\tint mn=l;\n\t\t\tif(r<sz&&pool[l]>pool[r]) mn=r;\n\
    \t\t\tif(pool[mn]>pool[v]) break;\n\t\t\tswap(pool[mn],pool[v]);\n\t\t\tv=mn;\n\
    \t\t}\n\t\treturn ret;\n\t}\n} h;\nint main(){\n\tsrand((unsigned)time(NULL));\n\
    \tint Ns[4]={1000000,2000000,4000000,8000000};\n\trep(tt,4){\n\t\tint N=Ns[tt];\n\
    \t\tclock_t start=clock();\n\t\trep(i,N){\n\t\t\tint x=rand()%1000000000;\n\t\t\
    \th.insert(x);\n\t\t}\n\t//\trep(i,h.sz) cout<<h.pool[i]<<\" \";\n\t//\tputs(\"\
    \");\n\t//\trep(i,N) cout<<h.deletemin()<<\" \";\n\t\trep(i,N) h.deletemin();\n\
    \t\tclock_t end=clock();\n\t\tprintf(\"N=%8d    time=%.0f ms\\n\",N,(end-start)/(double)CLOCKS_PER_SEC*1000);\n\
    \t}\n}\n"
  code: "#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define show(x) cout\
    \ << #x << \" = \" << x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y)\
    \ x=max(x,y)\nusing namespace std;\nconst int MAX_N=10000000;\nstruct heap{\n\t\
    int pool[MAX_N];\n\tint sz;\n\theap(){sz=0;}\n\tvoid insert(int x){\n\t\tint v=sz++;\n\
    \t\tpool[v]=x;\n\t\twhile(v){\n\t\t\tint p=(v-1)/2;\n\t\t\tif(pool[p]<=pool[v])\
    \ break;\n\t\t\tswap(pool[p],pool[v]);\n\t\t\tv=p;\n\t\t}\n\t}\n\tint deletemin(){\n\
    \t\tassert(sz);\n\t\tsz--;\n\t\tint ret=pool[0];\n\t\tpool[0]=pool[sz];\n\t\t\
    int v=0;\n\t\twhile(true){\n\t\t\tint l=v*2+1,r=v*2+2;\n\t\t\tif(sz<=l) break;\n\
    \t\t\tint mn=l;\n\t\t\tif(r<sz&&pool[l]>pool[r]) mn=r;\n\t\t\tif(pool[mn]>pool[v])\
    \ break;\n\t\t\tswap(pool[mn],pool[v]);\n\t\t\tv=mn;\n\t\t}\n\t\treturn ret;\n\
    \t}\n} h;\nint main(){\n\tsrand((unsigned)time(NULL));\n\tint Ns[4]={1000000,2000000,4000000,8000000};\n\
    \trep(tt,4){\n\t\tint N=Ns[tt];\n\t\tclock_t start=clock();\n\t\trep(i,N){\n\t\
    \t\tint x=rand()%1000000000;\n\t\t\th.insert(x);\n\t\t}\n\t//\trep(i,h.sz) cout<<h.pool[i]<<\"\
    \ \";\n\t//\tputs(\"\");\n\t//\trep(i,N) cout<<h.deletemin()<<\" \";\n\t\trep(i,N)\
    \ h.deletemin();\n\t\tclock_t end=clock();\n\t\tprintf(\"N=%8d    time=%.0f ms\\\
    n\",N,(end-start)/(double)CLOCKS_PER_SEC*1000);\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: data structure/heap.cpp
  requiredBy: []
  timestamp: '2016-12-08 00:51:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/heap.cpp
layout: document
redirect_from:
- /library/data structure/heap.cpp
- /library/data structure/heap.cpp.html
title: data structure/heap.cpp
---
