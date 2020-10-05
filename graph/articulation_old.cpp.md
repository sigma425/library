---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://hos.ac/slides/20110504_graph.pdf
  bundledCode: "#line 1 \"graph/articulation_old.cpp\"\n/*\nhttp://hos.ac/slides/20110504_graph.pdf\n\
    \n\u591A\u91CD\u8FBA\u306F\u5BFE\u5FDC\u3057\u3066\u306A\u3044\n\n\u95A2\u7BC0\
    \u70B9\nord[v]: dfs\u68EE\u3067\u306Eid\nlow[v]: lowlink, dfs\u6728\u3067\u5B50\
    \u306B\u3044\u304F + \u4E00\u56DE\u3060\u3051\u5F8C\u9000\u8FBA\u3067\u4E0A\u306B\
    \u4E0A\u304C\u308C\u308B \u3068\u304D\u306B\u305F\u3069\u308A\u3064\u3051\u308B\
    ord \u306Emin\nv\u304C\u95A2\u7BC0\u70B9\u21D4\n v\u304Cdfs\u6728\u306Eroot \u304B\
    \u3064 \u6B21\u6570\u304C2\u4EE5\u4E0A or\n v\u304Cdfs\u6728\u306Eroot\u3067\u306A\
    \u3044 \u304B\u3064 \u3042\u308B\u5B50u\u304C\u5B58\u5728\u3057, ord[v]<=low[u]\n\
    ord[v]=low[u]\u3067\u3082\u95A2\u7BC0\u70B9(\u81EA\u5206\u306B\u30B5\u30A4\u30AF\
    \u30EB\u304C\u623B\u3063\u3066\u304D\u305F\u3068\u3057\u3066\u3082\u4E0A\u306B\
    \u306F\u3044\u3051\u306A\u3044\u306E\u3067\u307E\u3060\u95A2\u7BC0\u70B9\u306A\
    \u307E\u307E) \u306A\u3053\u3068\u306B\u6CE8\u610F\n\n\u4E8C\u91CD(\u9802\u70B9\
    )\u9023\u7D50\u6210\u5206\n\u6A4B\u306B\u5BFE\u3059\u308B\u4E8C\u91CD\u8FBA\u9023\
    \u7D50\u6210\u5206\u306E\u3088\u3046\u306B\u3001\u4E8C\u91CD\u9023\u7D50\u6210\
    \u5206\u304C\u5B9A\u7FA9\u3055\u308C\u308B\u3002\n\u8FBA\u96C6\u5408E\u304C\u4E8C\
    \u91CD\u9023\u7D50\u21D4E\u3067\u8A98\u5C0E\u3055\u308C\u308B\u30B0\u30E9\u30D5\
    \u304C\u95A2\u7BC0\u70B9\u3092\u6301\u305F\u306A\u3044\n\n\n\u4F5C\u696D\u4E2D\
    :\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\u304C\u6728\u3092\u4F5C\
    \u308B\u3088\u3046\u306B\u3001\u95A2\u7BC0\u70B9\u3068\u4E8C\u91CD\u8FBA\u9023\
    \u7D50\u6210\u5206\u3092\u9802\u70B9\u3068\u3057\u3066\u6301\u3064\u6728\u307F\
    \u305F\u3044\u306A\u306E\u3092\u4F5C\u308C\u308B\n\n\n*/\n#include <bits/stdc++.h>\n\
    #define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<\"(\"\
    <<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class T> ostream& operator<<(ostream& o,const\
    \ vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"[\";for(const T& v:vc) o<<v<<\"\
    ,\";o<<\"]\";return o;}\n\ntypedef pair<int,int> P;\nconst int MV=100;\nvector<int>\
    \ G[MV];\nint ord[MV],low[MV];\nint I;\nvector<int> arts;\n\nstack<P> st;\ntypedef\
    \ vector<P> VP;\nvector<VP> biedges;\n\nvoid dfs(int v,int p){\n\tord[v]=++I;\n\
    \tlow[v]=ord[v];\n\tint c=0;\n\tbool isart=0;\n\tfor(int u:G[v]) if(u!=p){\n\t\
    \tif(ord[u]<ord[v]) st.push(P(v,u));\n\t\tif(ord[u]) chmin(low[v],ord[u]);\t//back\
    \ edge\n\t\telse{\n\t\t\tdfs(u,v);\n\t\t\tc++;\n\t\t\tchmin(low[v],low[u]);\n\t\
    \t\tif(low[u]>=ord[v]) isart=1;\n\n\t\t\tif(low[u]>=ord[v]){\n\t\t\t\tvector<P>\
    \ vp;\n\t\t\t\twhile(true){\n\t\t\t\t\tP p=st.top();st.pop();\n\t\t\t\t\tvp.pb(p);\n\
    \t\t\t\t\tif(p.fs==v && p.sc==u) break;\n\t\t\t\t}\n\t\t\t\tbiedges.pb(vp);\n\t\
    \t\t}\n\t\t}\n\t}\n\tif(p<0) isart=(c>1);\n\tif(isart) arts.pb(v);\n}\nvoid arti(int\
    \ N){\n\trep(i,N) if(ord[i]==0){\n\t\twhile(!st.empty()) st.pop();\n\t\tdfs(i,-1);\n\
    \t}\n}\nint main(){\n\tint N,M;\n\tcin>>N>>M;\n\trep(i,M){\n\t\tint a,b;\n\t\t\
    cin>>a>>b;\n\t\tG[a].pb(b);G[b].pb(a);\n\t}\n\tarti(N);\n\tsort(all(arts));\n\t\
    puts(\"---arts----\");\n\tfor(int a:arts) cout<<a<<endl;\n\tputs(\"--------\"\
    );\n\tint K=biedges.size();\n\tshow(K);\n\trep(i,K) show(biedges[i]);\n}\n"
  code: "/*\nhttp://hos.ac/slides/20110504_graph.pdf\n\n\u591A\u91CD\u8FBA\u306F\u5BFE\
    \u5FDC\u3057\u3066\u306A\u3044\n\n\u95A2\u7BC0\u70B9\nord[v]: dfs\u68EE\u3067\u306E\
    id\nlow[v]: lowlink, dfs\u6728\u3067\u5B50\u306B\u3044\u304F + \u4E00\u56DE\u3060\
    \u3051\u5F8C\u9000\u8FBA\u3067\u4E0A\u306B\u4E0A\u304C\u308C\u308B \u3068\u304D\
    \u306B\u305F\u3069\u308A\u3064\u3051\u308Bord \u306Emin\nv\u304C\u95A2\u7BC0\u70B9\
    \u21D4\n v\u304Cdfs\u6728\u306Eroot \u304B\u3064 \u6B21\u6570\u304C2\u4EE5\u4E0A\
    \ or\n v\u304Cdfs\u6728\u306Eroot\u3067\u306A\u3044 \u304B\u3064 \u3042\u308B\u5B50\
    u\u304C\u5B58\u5728\u3057, ord[v]<=low[u]\nord[v]=low[u]\u3067\u3082\u95A2\u7BC0\
    \u70B9(\u81EA\u5206\u306B\u30B5\u30A4\u30AF\u30EB\u304C\u623B\u3063\u3066\u304D\
    \u305F\u3068\u3057\u3066\u3082\u4E0A\u306B\u306F\u3044\u3051\u306A\u3044\u306E\
    \u3067\u307E\u3060\u95A2\u7BC0\u70B9\u306A\u307E\u307E) \u306A\u3053\u3068\u306B\
    \u6CE8\u610F\n\n\u4E8C\u91CD(\u9802\u70B9)\u9023\u7D50\u6210\u5206\n\u6A4B\u306B\
    \u5BFE\u3059\u308B\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u306E\u3088\u3046\
    \u306B\u3001\u4E8C\u91CD\u9023\u7D50\u6210\u5206\u304C\u5B9A\u7FA9\u3055\u308C\
    \u308B\u3002\n\u8FBA\u96C6\u5408E\u304C\u4E8C\u91CD\u9023\u7D50\u21D4E\u3067\u8A98\
    \u5C0E\u3055\u308C\u308B\u30B0\u30E9\u30D5\u304C\u95A2\u7BC0\u70B9\u3092\u6301\
    \u305F\u306A\u3044\n\n\n\u4F5C\u696D\u4E2D:\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\
    \u5206\u5206\u89E3\u304C\u6728\u3092\u4F5C\u308B\u3088\u3046\u306B\u3001\u95A2\
    \u7BC0\u70B9\u3068\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u3092\u9802\u70B9\
    \u3068\u3057\u3066\u6301\u3064\u6728\u307F\u305F\u3044\u306A\u306E\u3092\u4F5C\
    \u308C\u308B\n\n\n*/\n#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define show(x) cout\
    \ << #x << \" = \" << x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y)\
    \ x=max(x,y)\nusing namespace std;\ntemplate<class S,class T> ostream& operator<<(ostream&\
    \ o,const pair<S,T> &p){return o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class\
    \ T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"\
    [\";for(const T& v:vc) o<<v<<\",\";o<<\"]\";return o;}\n\ntypedef pair<int,int>\
    \ P;\nconst int MV=100;\nvector<int> G[MV];\nint ord[MV],low[MV];\nint I;\nvector<int>\
    \ arts;\n\nstack<P> st;\ntypedef vector<P> VP;\nvector<VP> biedges;\n\nvoid dfs(int\
    \ v,int p){\n\tord[v]=++I;\n\tlow[v]=ord[v];\n\tint c=0;\n\tbool isart=0;\n\t\
    for(int u:G[v]) if(u!=p){\n\t\tif(ord[u]<ord[v]) st.push(P(v,u));\n\t\tif(ord[u])\
    \ chmin(low[v],ord[u]);\t//back edge\n\t\telse{\n\t\t\tdfs(u,v);\n\t\t\tc++;\n\
    \t\t\tchmin(low[v],low[u]);\n\t\t\tif(low[u]>=ord[v]) isart=1;\n\n\t\t\tif(low[u]>=ord[v]){\n\
    \t\t\t\tvector<P> vp;\n\t\t\t\twhile(true){\n\t\t\t\t\tP p=st.top();st.pop();\n\
    \t\t\t\t\tvp.pb(p);\n\t\t\t\t\tif(p.fs==v && p.sc==u) break;\n\t\t\t\t}\n\t\t\t\
    \tbiedges.pb(vp);\n\t\t\t}\n\t\t}\n\t}\n\tif(p<0) isart=(c>1);\n\tif(isart) arts.pb(v);\n\
    }\nvoid arti(int N){\n\trep(i,N) if(ord[i]==0){\n\t\twhile(!st.empty()) st.pop();\n\
    \t\tdfs(i,-1);\n\t}\n}\nint main(){\n\tint N,M;\n\tcin>>N>>M;\n\trep(i,M){\n\t\
    \tint a,b;\n\t\tcin>>a>>b;\n\t\tG[a].pb(b);G[b].pb(a);\n\t}\n\tarti(N);\n\tsort(all(arts));\n\
    \tputs(\"---arts----\");\n\tfor(int a:arts) cout<<a<<endl;\n\tputs(\"--------\"\
    );\n\tint K=biedges.size();\n\tshow(K);\n\trep(i,K) show(biedges[i]);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/articulation_old.cpp
  requiredBy: []
  timestamp: '2017-09-14 22:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/articulation_old.cpp
layout: document
redirect_from:
- /library/graph/articulation_old.cpp
- /library/graph/articulation_old.cpp.html
title: graph/articulation_old.cpp
---
