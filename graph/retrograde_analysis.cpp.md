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
  bundledCode: "#line 1 \"graph/retrograde_analysis.cpp\"\n/*\nretrograde analysis\
    \ \u5F8C\u9000\u89E3\u6790\n\u30B0\u30E9\u30D5\u4E0A\u3067\u30BF\u30FC\u30F3\u6BCE\
    \u306B\u52D5\u304B\u3059\u4E8C\u4EBA\u30B2\u30FC\u30E0\u3092\u3084\u308B \u52D5\
    \u304B\u305B\u306A\u304F\u306A\u3063\u305F\u307B\u3046\u304C\u8CA0\u3051\nDAG\u3067\
    \u306F\u306A\u304F\u3066\u7121\u9650\u30EB\u30FC\u30D7\u3057\u5F97\u308B\u6642\
    ,\u6C7A\u307E\u308B\u3068\u3053\u308D\u304B\u3089\u6C7A\u3081\u3066\u3044\u304F\
    \u65B9\u91DD\u304C\u3053\u308C. \u6700\u5F8C\u307E\u3067\u6C7A\u307E\u3089\u306A\
    \u3044\u3068\u7121\u9650\u306B\u7D9A\u3044\u3066\u5F15\u304D\u5206\u3051.\n\u81EA\
    \u660E\u306A\u90E8\u5206\u3092setdp\u3057\u305F\u3042\u3068\u3001\n\u884C\u304D\
    \u5148\u306B\u76F8\u624B\u306E\u8CA0\u3051\u304C\u3042\u308B or \u884C\u304D\u5148\
    \u304C\u76F8\u624B\u306E\u52DD\u3061\u3067\u57CB\u307E\u3063\u305F \u306E\u3068\
    \u304D\u306B\u305D\u306E\u90E8\u5206\u304C\u57CB\u3081\u3089\u308C\u308B\u306E\
    \u3067queue\u306B\u5165\u308C\u308B.\n\u5168\u4F53\u3067\u8A08\u7B97\u91CF\u306F\
    O(M)\n\nHow to use\nadd_edge\u3067\u30B0\u30E9\u30D5\u69CB\u7BC9\u3057\u305F\u5F8C\
    calcdp(N)\u3059\u308B\u3068dp[t][v]\u306B, \u4EBAt\u304C\u9802\u70B9v\u3067\u306F\
    \u3058\u3081\u308B\u3068\u3069\u3046\u306A\u308B\u304B \u304C\u5165\u308B\n\n\
    verify : yandex/neerc2016/G.cpp\n\n\u3053\u308C\u306F\u7121\u9650\u306B\u7D9A\u3051\
    \u3089\u308C\u308B\u3068\u52DD\u3061 \u3068\u3044\u3046\u3084\u3064\u3067\u5C11\
    \u3057\u7279\u6B8A\n\n*/\n#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define show(x) cout\
    \ << #x << \" = \" << x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y)\
    \ x=max(x,y)\nusing namespace std;\ntemplate<class S,class T> ostream& operator<<(ostream&\
    \ o,const pair<S,T> &p){return o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class\
    \ T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"\
    [\";for(const T& v:vc) o<<v<<\",\";o<<\"]\";return o;}\nconst int MN=100000;\n\
    vector<int> G[MN],iG[MN];\n\nint dp[2][MN];\t//turn,v\twin=1,lose=-1,?=0\nint\
    \ outdeg[MN];\nint done[2][MN];\ntypedef pair<int,int> P;\t//P(turn,v)\nqueue<P>\
    \ que;\nbool vis[2][MN];\n\nvoid add_edge(int v,int u){\n\tG[v].pb(u);\n\tiG[u].pb(v);\n\
    \toutdeg[v]++;\n}\nvoid setdp(int t,int v,int val){\n\tdp[t][v]=val;\n\tfor(int\
    \ u:iG[v]){\n\t\tdone[t^1][u]++;\n\t\tif(val==-1||done[t^1][u]==outdeg[u]){\n\t\
    \t\tif(!vis[t^1][u]){\n\t\t\t\tque.push(P(t^1,u));\n\t\t\t\tvis[t^1][u]=1;\n\t\
    \t\t}\n\t\t}\n\t}\n}\nvoid calcdp(int N){\n\trep(v,N) if(outdeg[v]==0){\n\t\t\
    setdp(0,v,-1);\n\t\tsetdp(1,v,-1);\n\t\tvis[0][v]=vis[1][v]=1;\n\t}\n\twhile(!que.empty()){\n\
    \t\tint t,v;\n\t\ttie(t,v)=que.front();que.pop();\n\t\tbool twin=0;\n\t\tfor(int\
    \ u:G[v]){\n\t\t\tif(dp[t^1][u]==-1) twin=1;\n\t\t}\n\t\tif(twin) setdp(t,v,1);\n\
    \t\telse setdp(t,v,-1);\n\t}\n}\nint N,M;\nint main(){\n\tcin>>N>>M;\n\trep(i,M){\n\
    \t\tint a,b;\n\t\tcin>>a>>b;\n\t\ta--,b--;\n\t\tadd_edge(a,b);\n\t}\n}\n"
  code: "/*\nretrograde analysis \u5F8C\u9000\u89E3\u6790\n\u30B0\u30E9\u30D5\u4E0A\
    \u3067\u30BF\u30FC\u30F3\u6BCE\u306B\u52D5\u304B\u3059\u4E8C\u4EBA\u30B2\u30FC\
    \u30E0\u3092\u3084\u308B \u52D5\u304B\u305B\u306A\u304F\u306A\u3063\u305F\u307B\
    \u3046\u304C\u8CA0\u3051\nDAG\u3067\u306F\u306A\u304F\u3066\u7121\u9650\u30EB\u30FC\
    \u30D7\u3057\u5F97\u308B\u6642,\u6C7A\u307E\u308B\u3068\u3053\u308D\u304B\u3089\
    \u6C7A\u3081\u3066\u3044\u304F\u65B9\u91DD\u304C\u3053\u308C. \u6700\u5F8C\u307E\
    \u3067\u6C7A\u307E\u3089\u306A\u3044\u3068\u7121\u9650\u306B\u7D9A\u3044\u3066\
    \u5F15\u304D\u5206\u3051.\n\u81EA\u660E\u306A\u90E8\u5206\u3092setdp\u3057\u305F\
    \u3042\u3068\u3001\n\u884C\u304D\u5148\u306B\u76F8\u624B\u306E\u8CA0\u3051\u304C\
    \u3042\u308B or \u884C\u304D\u5148\u304C\u76F8\u624B\u306E\u52DD\u3061\u3067\u57CB\
    \u307E\u3063\u305F \u306E\u3068\u304D\u306B\u305D\u306E\u90E8\u5206\u304C\u57CB\
    \u3081\u3089\u308C\u308B\u306E\u3067queue\u306B\u5165\u308C\u308B.\n\u5168\u4F53\
    \u3067\u8A08\u7B97\u91CF\u306FO(M)\n\nHow to use\nadd_edge\u3067\u30B0\u30E9\u30D5\
    \u69CB\u7BC9\u3057\u305F\u5F8Ccalcdp(N)\u3059\u308B\u3068dp[t][v]\u306B, \u4EBA\
    t\u304C\u9802\u70B9v\u3067\u306F\u3058\u3081\u308B\u3068\u3069\u3046\u306A\u308B\
    \u304B \u304C\u5165\u308B\n\nverify : yandex/neerc2016/G.cpp\n\n\u3053\u308C\u306F\
    \u7121\u9650\u306B\u7D9A\u3051\u3089\u308C\u308B\u3068\u52DD\u3061 \u3068\u3044\
    \u3046\u3084\u3064\u3067\u5C11\u3057\u7279\u6B8A\n\n*/\n#include <bits/stdc++.h>\n\
    #define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<\"(\"\
    <<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class T> ostream& operator<<(ostream& o,const\
    \ vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"[\";for(const T& v:vc) o<<v<<\"\
    ,\";o<<\"]\";return o;}\nconst int MN=100000;\nvector<int> G[MN],iG[MN];\n\nint\
    \ dp[2][MN];\t//turn,v\twin=1,lose=-1,?=0\nint outdeg[MN];\nint done[2][MN];\n\
    typedef pair<int,int> P;\t//P(turn,v)\nqueue<P> que;\nbool vis[2][MN];\n\nvoid\
    \ add_edge(int v,int u){\n\tG[v].pb(u);\n\tiG[u].pb(v);\n\toutdeg[v]++;\n}\nvoid\
    \ setdp(int t,int v,int val){\n\tdp[t][v]=val;\n\tfor(int u:iG[v]){\n\t\tdone[t^1][u]++;\n\
    \t\tif(val==-1||done[t^1][u]==outdeg[u]){\n\t\t\tif(!vis[t^1][u]){\n\t\t\t\tque.push(P(t^1,u));\n\
    \t\t\t\tvis[t^1][u]=1;\n\t\t\t}\n\t\t}\n\t}\n}\nvoid calcdp(int N){\n\trep(v,N)\
    \ if(outdeg[v]==0){\n\t\tsetdp(0,v,-1);\n\t\tsetdp(1,v,-1);\n\t\tvis[0][v]=vis[1][v]=1;\n\
    \t}\n\twhile(!que.empty()){\n\t\tint t,v;\n\t\ttie(t,v)=que.front();que.pop();\n\
    \t\tbool twin=0;\n\t\tfor(int u:G[v]){\n\t\t\tif(dp[t^1][u]==-1) twin=1;\n\t\t\
    }\n\t\tif(twin) setdp(t,v,1);\n\t\telse setdp(t,v,-1);\n\t}\n}\nint N,M;\nint\
    \ main(){\n\tcin>>N>>M;\n\trep(i,M){\n\t\tint a,b;\n\t\tcin>>a>>b;\n\t\ta--,b--;\n\
    \t\tadd_edge(a,b);\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/retrograde_analysis.cpp
  requiredBy: []
  timestamp: '2016-12-08 00:51:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/retrograde_analysis.cpp
layout: document
redirect_from:
- /library/graph/retrograde_analysis.cpp
- /library/graph/retrograde_analysis.cpp.html
title: graph/retrograde_analysis.cpp
---
