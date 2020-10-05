---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/cycle.cpp\"\n/*\n\t(directed/undirected)\u30B5\u30A4\
    \u30AF\u30EB\u691C\u51FA\n\t\u3072\u3068\u3064\u898B\u3064\u3051\u3066\u305D\u308C\
    \u3092\u8FD4\u3059 \u306A\u3044\u5834\u5408{}\n\t\u81EA\u5DF1loop\u304C\u3042\u308B\
    \u5834\u5408\u305D\u308C\u3092\u8FD4\u3057\u3066\u3057\u307E\u3046(\u9577\u3055\
    1\u306E\u30B5\u30A4\u30AF\u30EB\u3092\u8FD4\u3059) \u2190 \u9069\u5F53\u306B\u5909\
    \u3048\u3089\u308C\u308B\n\t\u591A\u91CD\u8FBA\u304C\u3042\u3063\u3066\u3082\u7121\
    \u8996\u3059\u308B(\u9577\u30552\u306E\u30B5\u30A4\u30AF\u30EB\u306F\u8FD4\u3055\
    \u306A\u3044) \u2190 p\u3058\u3083\u306A\u304F\u3066edge id \u3067\u4FDD\u5B58\
    \u3059\u308B\u3068\u56DE\u907F\u3067\u304D\u308B\n\n\t\u3044\u307Edirected\u3067\
    \u3001undirected\u306B\u3057\u305F\u3044\u306A\u3089p\u3092\u3082\u3063\u3066\
    dfsc\u3059\u308B\n\n\tverified at codefestival2016 final J (Neue Spiel)\n*/\n\n\
    #include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define\
    \ rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n#define\
    \ pb push_back\n#define fs first\n#define sc second\n#define show(x) cout << #x\
    \ << \" = \" << x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y) x=max(x,y)\n\
    using namespace std;\ntemplate<class S,class T> ostream& operator<<(ostream& o,const\
    \ pair<S,T> &p){return o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class T>\
    \ ostream& operator<<(ostream& o,const vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"\
    [\";for(const T& v:vc) o<<v<<\",\";o<<\"]\";return o;}\n\nbool dfsc(int v, const\
    \ vector<vector<int>>& G, vector<int>& vis, vector<int>& cyc, bool& done){\n\t\
    if(vis[v]==1){\n\t\tcyc.pb(v);\n\t\treturn 1;\n\t}\n\tif(vis[v]==2) return 0;\n\
    \n\tvis[v] = 1;\n\tfor(int u:G[v]){\n\t\tif(dfsc(u,G,vis,cyc,done)){\n\t\t\tif(v==cyc[0])\
    \ done=1;\n\t\t\tif(!done) cyc.pb(v);\n\t\t\treturn 1;\n\t\t}\n\t}\n\tvis[v] =\
    \ 2;\n\treturn 0;\n}\nvector<int> getcycle(const vector<vector<int>>& G){\n\t\
    int N = G.size();\n\tvector<int> vis(N,0);\t//0:yet 1:now 2:done\n\tbool done\
    \ = 0;\n\tvector<int> cyc;\n\trep(i,N) if(vis[i]==0){\n\t\tif(dfsc(i,G,vis,cyc,done)){\n\
    \t\t\treverse(all(cyc));\n\t\t\treturn cyc;\n\t\t}\n\t}\n\treturn {};\n}\n\nvoid\
    \ unittest(){\n\t// vector<int> as = {2,3,2,4,2,6,2};\n\t// vector<int> bs = {6,4,3,2,1,5,5};\n\
    \t// vector<int> as = {2};\n\t// vector<int> bs = {1};\n\tvector<int> as = {1,3,4,5,6,7,8,9};\n\
    \tvector<int> bs = {2,1,3,6,7,8,5,8};\n\trep(i,as.size()){\n\t\tG[as[i]].pb(bs[i]);\n\
    //\t\tG[bs[i]].pb(as[i]);\n\t}\n\n\tvector<int> cyc = getcycle(7);\n\tshow(cyc);\n\
    }\n\nint main(){\n\tunittest();\n}\n"
  code: "/*\n\t(directed/undirected)\u30B5\u30A4\u30AF\u30EB\u691C\u51FA\n\t\u3072\
    \u3068\u3064\u898B\u3064\u3051\u3066\u305D\u308C\u3092\u8FD4\u3059 \u306A\u3044\
    \u5834\u5408{}\n\t\u81EA\u5DF1loop\u304C\u3042\u308B\u5834\u5408\u305D\u308C\u3092\
    \u8FD4\u3057\u3066\u3057\u307E\u3046(\u9577\u30551\u306E\u30B5\u30A4\u30AF\u30EB\
    \u3092\u8FD4\u3059) \u2190 \u9069\u5F53\u306B\u5909\u3048\u3089\u308C\u308B\n\t\
    \u591A\u91CD\u8FBA\u304C\u3042\u3063\u3066\u3082\u7121\u8996\u3059\u308B(\u9577\
    \u30552\u306E\u30B5\u30A4\u30AF\u30EB\u306F\u8FD4\u3055\u306A\u3044) \u2190 p\u3058\
    \u3083\u306A\u304F\u3066edge id \u3067\u4FDD\u5B58\u3059\u308B\u3068\u56DE\u907F\
    \u3067\u304D\u308B\n\n\t\u3044\u307Edirected\u3067\u3001undirected\u306B\u3057\
    \u305F\u3044\u306A\u3089p\u3092\u3082\u3063\u3066dfsc\u3059\u308B\n\n\tverified\
    \ at codefestival2016 final J (Neue Spiel)\n*/\n\n#include <bits/stdc++.h>\n#define\
    \ rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<\"(\"\
    <<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class T> ostream& operator<<(ostream& o,const\
    \ vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"[\";for(const T& v:vc) o<<v<<\"\
    ,\";o<<\"]\";return o;}\n\nbool dfsc(int v, const vector<vector<int>>& G, vector<int>&\
    \ vis, vector<int>& cyc, bool& done){\n\tif(vis[v]==1){\n\t\tcyc.pb(v);\n\t\t\
    return 1;\n\t}\n\tif(vis[v]==2) return 0;\n\n\tvis[v] = 1;\n\tfor(int u:G[v]){\n\
    \t\tif(dfsc(u,G,vis,cyc,done)){\n\t\t\tif(v==cyc[0]) done=1;\n\t\t\tif(!done)\
    \ cyc.pb(v);\n\t\t\treturn 1;\n\t\t}\n\t}\n\tvis[v] = 2;\n\treturn 0;\n}\nvector<int>\
    \ getcycle(const vector<vector<int>>& G){\n\tint N = G.size();\n\tvector<int>\
    \ vis(N,0);\t//0:yet 1:now 2:done\n\tbool done = 0;\n\tvector<int> cyc;\n\trep(i,N)\
    \ if(vis[i]==0){\n\t\tif(dfsc(i,G,vis,cyc,done)){\n\t\t\treverse(all(cyc));\n\t\
    \t\treturn cyc;\n\t\t}\n\t}\n\treturn {};\n}\n\nvoid unittest(){\n\t// vector<int>\
    \ as = {2,3,2,4,2,6,2};\n\t// vector<int> bs = {6,4,3,2,1,5,5};\n\t// vector<int>\
    \ as = {2};\n\t// vector<int> bs = {1};\n\tvector<int> as = {1,3,4,5,6,7,8,9};\n\
    \tvector<int> bs = {2,1,3,6,7,8,5,8};\n\trep(i,as.size()){\n\t\tG[as[i]].pb(bs[i]);\n\
    //\t\tG[bs[i]].pb(as[i]);\n\t}\n\n\tvector<int> cyc = getcycle(7);\n\tshow(cyc);\n\
    }\n\nint main(){\n\tunittest();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/cycle.cpp
  requiredBy: []
  timestamp: '2018-01-03 23:14:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/cycle.cpp
layout: document
redirect_from:
- /library/graph/cycle.cpp
- /library/graph/cycle.cpp.html
title: graph/cycle.cpp
---
