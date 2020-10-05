---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/biedge_test.cpp\"\n#include <bits/stdc++.h>\n#define\
    \ chmin(x,y) x=min(x,y)\n#define pb push_back\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define show(x) cout<<#x<<\" \"<<x<<endl\nusing namespace std;\nconst int MAX_V=100;\n\
    //\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\n//biedge connected component\n\
    //bs\u306Bbridge,cc\u306B\u4E8C\u91CD\u9023\u7D50\u6210\u5206\u304C\u5165\u308B\
    \ntypedef vector<int> vi;\ntypedef pair<int,int> P;\nvector<int> G[MAX_V];\nint\
    \ ord[MAX_V];\nbool inS[MAX_V];\nstack<int> roots,S;\nvector<vi> cc;\nvector<P>\
    \ bs;\nint cnt;\nint N,M;\n\nint cmp[MAX_V];\nvector<int> cG[MAX_V];\n\nvoid vis(int\
    \ v,int p){\n\tord[v]=++cnt;\n\tS.push(v);\n\tinS[v]=true;\n\troots.push(v);\n\
    \tfor(int u:G[v]){\n\t\tif(ord[u]==0){\n\t\t\tvis(u,v);\n\t\t}else if(u!=p&&inS[u]){\n\
    \t\t\twhile(ord[roots.top()]>ord[u]) roots.pop();\n\t\t}\n\t}\n\tif(v==roots.top()){\n\
    \t\tbs.pb(P(p,v));\n\t\tvector<int> vc;\n\t\twhile(true){\n\t\t\tint w=S.top();S.pop();\n\
    \t\t\tinS[w]=false;\n\t\t\tvc.pb(w);\n\t\t\tcmp[w]=cc.size();\n\t\t\tif(v==w)\
    \ break;\n\t\t}\n\t\troots.pop();\n\t\tcc.pb(vc);\n\t}\n}\nvoid bridge(){\n\t\
    rep(i,N) if(ord[i]==0){\n\t\tvis(i,-1);\n\t\tbs.pop_back();\t//P(-1,hoge)\n\t\
    }\n\tfor(P p:bs){\n\t\tint x=cmp[p.first],y=cmp[p.second];\n\t\tcG[x].pb(y),cG[y].pb(x);\n\
    \t}\n}\nint main(){\n\tcin>>N>>M;\n\trep(i,M){\n\t\tint a,b;\n\t\tcin>>a>>b;\n\
    \t\tG[a].pb(b);\n\t\tG[b].pb(a);\n\t}\n\tbridge();\n\tshow(cc.size());\n\trep(i,cc.size()){\n\
    \t\tprintf(\"No.%d   \",i);\n\t\trep(j,cc[i].size()) cout<<cc[i][j]<<\" \";\n\t\
    \tputs(\"\");\n\t}\n\trep(i,bs.size()){\n\t\tcout<<\"(\"<<bs[i].first<<\",\"<<bs[i].second<<\"\
    )\"<<endl;\n\t}\n\trep(i,cc.size()){\n\t\tprintf(\"i=%d   \",i);\n\t\tfor(int\
    \ u:cG[i]) cout<<u<<\" \";\n\t\tputs(\"\");\n\t}\n}\n"
  code: "#include <bits/stdc++.h>\n#define chmin(x,y) x=min(x,y)\n#define pb push_back\n\
    #define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define show(x) cout<<#x<<\" \"\
    <<x<<endl\nusing namespace std;\nconst int MAX_V=100;\n//\u4E8C\u91CD\u8FBA\u9023\
    \u7D50\u6210\u5206\u5206\u89E3\n//biedge connected component\n//bs\u306Bbridge,cc\u306B\
    \u4E8C\u91CD\u9023\u7D50\u6210\u5206\u304C\u5165\u308B\ntypedef vector<int> vi;\n\
    typedef pair<int,int> P;\nvector<int> G[MAX_V];\nint ord[MAX_V];\nbool inS[MAX_V];\n\
    stack<int> roots,S;\nvector<vi> cc;\nvector<P> bs;\nint cnt;\nint N,M;\n\nint\
    \ cmp[MAX_V];\nvector<int> cG[MAX_V];\n\nvoid vis(int v,int p){\n\tord[v]=++cnt;\n\
    \tS.push(v);\n\tinS[v]=true;\n\troots.push(v);\n\tfor(int u:G[v]){\n\t\tif(ord[u]==0){\n\
    \t\t\tvis(u,v);\n\t\t}else if(u!=p&&inS[u]){\n\t\t\twhile(ord[roots.top()]>ord[u])\
    \ roots.pop();\n\t\t}\n\t}\n\tif(v==roots.top()){\n\t\tbs.pb(P(p,v));\n\t\tvector<int>\
    \ vc;\n\t\twhile(true){\n\t\t\tint w=S.top();S.pop();\n\t\t\tinS[w]=false;\n\t\
    \t\tvc.pb(w);\n\t\t\tcmp[w]=cc.size();\n\t\t\tif(v==w) break;\n\t\t}\n\t\troots.pop();\n\
    \t\tcc.pb(vc);\n\t}\n}\nvoid bridge(){\n\trep(i,N) if(ord[i]==0){\n\t\tvis(i,-1);\n\
    \t\tbs.pop_back();\t//P(-1,hoge)\n\t}\n\tfor(P p:bs){\n\t\tint x=cmp[p.first],y=cmp[p.second];\n\
    \t\tcG[x].pb(y),cG[y].pb(x);\n\t}\n}\nint main(){\n\tcin>>N>>M;\n\trep(i,M){\n\
    \t\tint a,b;\n\t\tcin>>a>>b;\n\t\tG[a].pb(b);\n\t\tG[b].pb(a);\n\t}\n\tbridge();\n\
    \tshow(cc.size());\n\trep(i,cc.size()){\n\t\tprintf(\"No.%d   \",i);\n\t\trep(j,cc[i].size())\
    \ cout<<cc[i][j]<<\" \";\n\t\tputs(\"\");\n\t}\n\trep(i,bs.size()){\n\t\tcout<<\"\
    (\"<<bs[i].first<<\",\"<<bs[i].second<<\")\"<<endl;\n\t}\n\trep(i,cc.size()){\n\
    \t\tprintf(\"i=%d   \",i);\n\t\tfor(int u:cG[i]) cout<<u<<\" \";\n\t\tputs(\"\"\
    );\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/biedge_test.cpp
  requiredBy: []
  timestamp: '2016-12-08 00:51:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/biedge_test.cpp
layout: document
redirect_from:
- /library/graph/biedge_test.cpp
- /library/graph/biedge_test.cpp.html
title: graph/biedge_test.cpp
---
