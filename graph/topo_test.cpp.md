---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/topo_test.cpp\"\n#include <bits/stdc++.h>\n#define\
    \ rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\nconst int MAX_V=10;\n\
    int vis[MAX_V];\t\t//0->yet,1->now,2->done\nvector<int> topo;\nvector<int> G[MAX_V];\n\
    bool visit(int v){\n\tif(vis[v]==2) return 1;\n\tif(vis[v]==1) return 0;\n\tvis[v]=1;\n\
    \tfor(int u:G[v]) if(!visit(u)) return 0;\n\tvis[v]=2;\n\ttopo.pb(v);\n\treturn\
    \ 1;\n}\nbool maketopo(int V){\n\trep(i,V) if(!visit(i)) return 0;\n\treverse(all(topo));\n\
    \treturn 1;\n}\nint main(){\n\tint N,M;\n\tcin>>N>>M;\n\trep(i,M){\n\t\tint a,b;\n\
    \t\tcin>>a>>b;\n\t\tG[a].pb(b);\n\t}\n\tif(maketopo(N)){\n\t\trep(i,N) cout<<topo[i]<<\"\
    \ \";\n\t\tputs(\"\");\n\t}else{\n\t\tputs(\"not dag\");\n\t}\n}\n"
  code: "#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define show(x) cout\
    \ << #x << \" = \" << x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y)\
    \ x=max(x,y)\nusing namespace std;\nconst int MAX_V=10;\nint vis[MAX_V];\t\t//0->yet,1->now,2->done\n\
    vector<int> topo;\nvector<int> G[MAX_V];\nbool visit(int v){\n\tif(vis[v]==2)\
    \ return 1;\n\tif(vis[v]==1) return 0;\n\tvis[v]=1;\n\tfor(int u:G[v]) if(!visit(u))\
    \ return 0;\n\tvis[v]=2;\n\ttopo.pb(v);\n\treturn 1;\n}\nbool maketopo(int V){\n\
    \trep(i,V) if(!visit(i)) return 0;\n\treverse(all(topo));\n\treturn 1;\n}\nint\
    \ main(){\n\tint N,M;\n\tcin>>N>>M;\n\trep(i,M){\n\t\tint a,b;\n\t\tcin>>a>>b;\n\
    \t\tG[a].pb(b);\n\t}\n\tif(maketopo(N)){\n\t\trep(i,N) cout<<topo[i]<<\" \";\n\
    \t\tputs(\"\");\n\t}else{\n\t\tputs(\"not dag\");\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/topo_test.cpp
  requiredBy: []
  timestamp: '2016-12-08 00:51:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/topo_test.cpp
layout: document
redirect_from:
- /library/graph/topo_test.cpp
- /library/graph/topo_test.cpp.html
title: graph/topo_test.cpp
---
