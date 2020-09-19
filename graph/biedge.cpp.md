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
  bundledCode: "#line 1 \"graph/biedge.cpp\"\n/*\nbiedge connected component\nbs\u306B\
    bridge,cc\u306B\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u304C\u5165\u308B\n\
    !!! \u591A\u91CD\u8FBA\u304C\u3042\u308B\u3068\u304D\u306Felse if(u!=p) \u306E\
    \u3068\u3053\u3067 u-p\u306B\u591A\u91CD\u8FBA\u304C\u3042\u308B\u306A\u3089\u623B\
    \u3063\u3066\u3082\u826F\u3044\nelse if( (u!=p&&inS[u]) || (u==p&&mp[P(min(v,p),max(v,p)]>=2)\
    \ )\nmp\u306Fmultimap\u3058\u3083\u306A\u304F\u3066map<P,int>\n*/\ntypedef vector<int>\
    \ vi;\ntypedef pair<int,int> P;\nconst int MN=;\nvector<int> G[MN];\nint ord[MN];\n\
    bool inS[MN];\nstack<int> roots,S;\nvector<vi> cc;\nvector<P> bs;\nint cnt;\n\
    /*\nint cmp[MN];\nvector<int> cG[MN];\n*/\nvoid vis(int v,int p){\n\tord[v]=++cnt;\n\
    \tS.push(v);\n\tinS[v]=true;\n\troots.push(v);\n\tfor(int u:G[v]){\n\t\tif(ord[u]==0){\n\
    \t\t\tvis(u,v);\n\t\t}else if(u!=p&&inS[u]){\n\t\t\twhile(ord[roots.top()]>ord[u])\
    \ roots.pop();\n\t\t}\n\t}\n\tif(v==roots.top()){\n\t\tbs.pb(P(p,v));\n\t\tvector<int>\
    \ vc;\n\t\twhile(true){\n\t\t\tint w=S.top();S.pop();\n\t\t\tinS[w]=false;\n\t\
    \t\tvc.pb(w);\n//\t\t\tcmp[w]=cc.size();\n\t\t\tif(v==w) break;\n\t\t}\n\t\troots.pop();\n\
    \t\tcc.pb(vc);\n\t}\n}\nvoid bridge(int N){\n\trep(i,N) if(ord[i]==0){\n\t\tvis(i,-1);\n\
    \t\tbs.pop_back();\t//P(-1,hoge)\n\t}\n/*\tfor(P p:bs){\n\t\tint x=cmp[p.fs],y=cmp[p.sc];\n\
    \t\tcG[x].pb(y),cG[y].pb(x);\n\t}*/\n}\n"
  code: "/*\nbiedge connected component\nbs\u306Bbridge,cc\u306B\u4E8C\u91CD\u8FBA\
    \u9023\u7D50\u6210\u5206\u304C\u5165\u308B\n!!! \u591A\u91CD\u8FBA\u304C\u3042\
    \u308B\u3068\u304D\u306Felse if(u!=p) \u306E\u3068\u3053\u3067 u-p\u306B\u591A\
    \u91CD\u8FBA\u304C\u3042\u308B\u306A\u3089\u623B\u3063\u3066\u3082\u826F\u3044\
    \nelse if( (u!=p&&inS[u]) || (u==p&&mp[P(min(v,p),max(v,p)]>=2) )\nmp\u306Fmultimap\u3058\
    \u3083\u306A\u304F\u3066map<P,int>\n*/\ntypedef vector<int> vi;\ntypedef pair<int,int>\
    \ P;\nconst int MN=;\nvector<int> G[MN];\nint ord[MN];\nbool inS[MN];\nstack<int>\
    \ roots,S;\nvector<vi> cc;\nvector<P> bs;\nint cnt;\n/*\nint cmp[MN];\nvector<int>\
    \ cG[MN];\n*/\nvoid vis(int v,int p){\n\tord[v]=++cnt;\n\tS.push(v);\n\tinS[v]=true;\n\
    \troots.push(v);\n\tfor(int u:G[v]){\n\t\tif(ord[u]==0){\n\t\t\tvis(u,v);\n\t\t\
    }else if(u!=p&&inS[u]){\n\t\t\twhile(ord[roots.top()]>ord[u]) roots.pop();\n\t\
    \t}\n\t}\n\tif(v==roots.top()){\n\t\tbs.pb(P(p,v));\n\t\tvector<int> vc;\n\t\t\
    while(true){\n\t\t\tint w=S.top();S.pop();\n\t\t\tinS[w]=false;\n\t\t\tvc.pb(w);\n\
    //\t\t\tcmp[w]=cc.size();\n\t\t\tif(v==w) break;\n\t\t}\n\t\troots.pop();\n\t\t\
    cc.pb(vc);\n\t}\n}\nvoid bridge(int N){\n\trep(i,N) if(ord[i]==0){\n\t\tvis(i,-1);\n\
    \t\tbs.pop_back();\t//P(-1,hoge)\n\t}\n/*\tfor(P p:bs){\n\t\tint x=cmp[p.fs],y=cmp[p.sc];\n\
    \t\tcG[x].pb(y),cG[y].pb(x);\n\t}*/\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/biedge.cpp
  requiredBy: []
  timestamp: '2016-12-08 00:51:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/biedge.cpp
layout: document
redirect_from:
- /library/graph/biedge.cpp
- /library/graph/biedge.cpp.html
title: graph/biedge.cpp
---
