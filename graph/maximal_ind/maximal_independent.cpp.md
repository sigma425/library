---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"graph/maximal_ind/maximal_independent.cpp\"\n#include <bits/stdc++.h>\n\
    #define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\nint V;\nconst\
    \ int MAX_V=40;\nvector<int> G[MAX_V];\nbool used[MAX_V];\nint ord[MAX_V];\nint\
    \ cnt[MAX_V];\t\t//cnt[v] = the num of selected verticies connected with v;\n\
    typedef long long ll;\nset<ll> done;\nvoid dfs(int it){\n\tif(it==V){\n\t\tll\
    \ x=0;\n\t\trep(i,V) if(used[i]) x|=(1LL<<i);\n\t\tif(done.find(x)!=done.end())\
    \ return;\n\t\tdone.insert(x);\n\t\trep(i,V) cout<<used[i];\n\t\tputs(\"\");\n\
    \t\treturn;\n\t}\n\tint v=ord[it];\n\tif(used[v]||cnt[v]){\n\t\tdfs(it+1);\n\t\
    \treturn;\n\t}\n\t//use v\n\tused[v]=1;\n\tfor(int u:G[v]) cnt[u]++;\n\tdfs(it+1);\n\
    \tused[v]=0;\n\tfor(int u:G[v]) cnt[u]--;\n\n\tfor(int u:G[v]) if(cnt[u]==0&&!used[u]){\n\
    \t\tused[u]=1;\n\t\tfor(int w:G[u]) cnt[w]++;\n\t\tdfs(it+1);\n\t\tused[u]=0;\n\
    \t\tfor(int w:G[u]) cnt[w]--;\n\t}\n}\nvoid enum_ind(int N){\n\tV=N;\n\ttypedef\
    \ pair<int,int> P;\n\tvector<P> tmp;\n\trep(i,N) tmp.pb(P(G[i].size(),i));\n\t\
    sort(all(tmp));\n\trep(i,N) ord[i]=tmp[i].sc;\n\trep(i,N) used[i]=0,cnt[i]=0;\n\
    \tdone.clear();\n\tdfs(0);\n}\nint main(){\n\tint N,M;\n\tcin>>N>>M;\n\trep(i,M){\n\
    \t\tint a,b;\n\t\tcin>>a>>b;\n\t\tG[a].pb(b);\n\t\tG[b].pb(a);\n\t}\n\tenum_ind(N);\n\
    }\n"
  code: "#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define show(x) cout\
    \ << #x << \" = \" << x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y)\
    \ x=max(x,y)\nusing namespace std;\nint V;\nconst int MAX_V=40;\nvector<int> G[MAX_V];\n\
    bool used[MAX_V];\nint ord[MAX_V];\nint cnt[MAX_V];\t\t//cnt[v] = the num of selected\
    \ verticies connected with v;\ntypedef long long ll;\nset<ll> done;\nvoid dfs(int\
    \ it){\n\tif(it==V){\n\t\tll x=0;\n\t\trep(i,V) if(used[i]) x|=(1LL<<i);\n\t\t\
    if(done.find(x)!=done.end()) return;\n\t\tdone.insert(x);\n\t\trep(i,V) cout<<used[i];\n\
    \t\tputs(\"\");\n\t\treturn;\n\t}\n\tint v=ord[it];\n\tif(used[v]||cnt[v]){\n\t\
    \tdfs(it+1);\n\t\treturn;\n\t}\n\t//use v\n\tused[v]=1;\n\tfor(int u:G[v]) cnt[u]++;\n\
    \tdfs(it+1);\n\tused[v]=0;\n\tfor(int u:G[v]) cnt[u]--;\n\n\tfor(int u:G[v]) if(cnt[u]==0&&!used[u]){\n\
    \t\tused[u]=1;\n\t\tfor(int w:G[u]) cnt[w]++;\n\t\tdfs(it+1);\n\t\tused[u]=0;\n\
    \t\tfor(int w:G[u]) cnt[w]--;\n\t}\n}\nvoid enum_ind(int N){\n\tV=N;\n\ttypedef\
    \ pair<int,int> P;\n\tvector<P> tmp;\n\trep(i,N) tmp.pb(P(G[i].size(),i));\n\t\
    sort(all(tmp));\n\trep(i,N) ord[i]=tmp[i].sc;\n\trep(i,N) used[i]=0,cnt[i]=0;\n\
    \tdone.clear();\n\tdfs(0);\n}\nint main(){\n\tint N,M;\n\tcin>>N>>M;\n\trep(i,M){\n\
    \t\tint a,b;\n\t\tcin>>a>>b;\n\t\tG[a].pb(b);\n\t\tG[b].pb(a);\n\t}\n\tenum_ind(N);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/maximal_ind/maximal_independent.cpp
  requiredBy: []
  timestamp: '2016-12-08 00:51:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/maximal_ind/maximal_independent.cpp
layout: document
redirect_from:
- /library/graph/maximal_ind/maximal_independent.cpp
- /library/graph/maximal_ind/maximal_independent.cpp.html
title: graph/maximal_ind/maximal_independent.cpp
---
