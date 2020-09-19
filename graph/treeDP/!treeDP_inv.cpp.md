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
  bundledCode: "#line 1 \"graph/treeDP/!treeDP_inv.cpp\"\n/*\n\n\u308F\u304B\u308A\
    \u306B\u304F\u3044\u3057,merge(\u5DE6\u305F\u3061,\u53F3\u305F\u3061)\u306B\u6642\
    \u9593\u304C\u639B\u304B\u308B\u306A\u3069\u306E\u7406\u7531\u304C\u306A\u3044\
    \u9650\u308A\u3082\u3046\u4E00\u65B9\u306E\u65B9\u3092\u4F7F\u3063\u305F\u307B\
    \u3046\u304C\u826F\u3044\u3068\u601D\u3046\n\n\n\u5168\u9802\u70B9\u3092\u59CB\
    \u70B9\u306B(1\u9802\u70B9\u3067\u304CO(N)\u306E)\u6728DP\u3092\u3059\u308B O(N)\n\
    \u307E\u305A,children\u305F\u3061\u306E\u30DE\u30FC\u30B8\u306E\u9006\u64CD\u4F5C\
    \u304C\u7121\u3044\u3068\u30C0\u30E1 \u4F8B\u3048\u3070 merge\u304C\u305F\u3060\
    \u306Esum\u3068\u304B\n\u4F7F\u3046\u524D\u306B,G\u306B,\u9006\u8FBA\u540C\u58EB\
    \u304C^1\u306B\u306A\u308B\u3088\u3046\u306Bpush\u3057\u3066\u304A\u304F\nG[a].pb(P(b,I++)),G[b].pb(P(a,I++))\n\
    \n\u4E00\u822C\u7684\u306B\u3059\u308B\u305F\u3081\u306B\u5909\u66F4\u3059\u3079\
    \u304D\u90E8\u5206\u306F,\nsum[v]=1\t\t\t\u3053\u3053\u306F\u521D\u671F\u5316\n\
    add(sum[v],dfs)\t\t2\u7B87\u6240\u3068\u3082\u540C\u3058,merge\u3092\u304B\u304F\
    \nsum[v]*inv[v+1]\t\t\u3053\u3053\u306F\u5B50\u306Emerge\u304C\u7D42\u308F\u3063\
    \u305F\u5F8C\u306B\u4F55\u304B\u8A08\u7B97\u3059\u3079\u304D\u3053\u3068\u304C\
    \u3042\u308B\u306A\u3089\u3053\u3053\u306B\u304B\u304F\nsum[v]-mp[e^1]\t\t\u3053\
    \u3053\u306Fmerge\u306E\u9006\u64CD\u4F5C\n\u8352\u524A\u308A\u3060\u3051\u3069\
    \u4E00\u5FDC SRM664d1m \u3067verify\n\n*/\n#include <bits/stdc++.h>\n#define rep(i,n)\
    \ for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\ntypedef long\
    \ long ll;\ntypedef pair<int,int> P;\nconst int MAX_N=1000000;\nint I;\nll mp[MAX_N*2];\n\
    vector<P> G[MAX_N];\t\t//to,id\nll sum[MAX_N];\nP done[MAX_N];\t\t//fs= -2:nothing\
    \ yet , -1:all done , x>=0: only x left   sc=edgeid(v,done[v])\nll dfs(int v,int\
    \ p,int e){\t\t//v,p,edgeid(v,p)\n\tif(done[v].fs==-2){\n\t\tsum[v]=1;\n\t\tfor(P\
    \ q:G[v]) if(q.fs!=p) add(sum[v],dfs(q.fs,v,q.sc^1));\n\t\tdone[v]=P(p,e);\n\t\
    \treturn mp[e]=sum[v]*inv[v+1]%mod;\n\t}else if(done[v].fs>=0){\n\t\tadd(sum[v],dfs(done[v].fs,v,done[v].sc^1));\n\
    \t\tdone[v].fs=-1;\n\t}\n\tif(p==-1) return sum[v]*inv[v+1]%mod;\n\telse return\
    \ mp[e]=((sum[v]-mp[e^1])*inv[v+1]%mod+mod)%mod;\n}\nint main(){\n\trep(i,N) done[i]=P(-2,0);\n\
    \trep(i,N) dfs(i,-1,0);\n};\n"
  code: "/*\n\n\u308F\u304B\u308A\u306B\u304F\u3044\u3057,merge(\u5DE6\u305F\u3061\
    ,\u53F3\u305F\u3061)\u306B\u6642\u9593\u304C\u639B\u304B\u308B\u306A\u3069\u306E\
    \u7406\u7531\u304C\u306A\u3044\u9650\u308A\u3082\u3046\u4E00\u65B9\u306E\u65B9\
    \u3092\u4F7F\u3063\u305F\u307B\u3046\u304C\u826F\u3044\u3068\u601D\u3046\n\n\n\
    \u5168\u9802\u70B9\u3092\u59CB\u70B9\u306B(1\u9802\u70B9\u3067\u304CO(N)\u306E\
    )\u6728DP\u3092\u3059\u308B O(N)\n\u307E\u305A,children\u305F\u3061\u306E\u30DE\
    \u30FC\u30B8\u306E\u9006\u64CD\u4F5C\u304C\u7121\u3044\u3068\u30C0\u30E1 \u4F8B\
    \u3048\u3070 merge\u304C\u305F\u3060\u306Esum\u3068\u304B\n\u4F7F\u3046\u524D\u306B\
    ,G\u306B,\u9006\u8FBA\u540C\u58EB\u304C^1\u306B\u306A\u308B\u3088\u3046\u306B\
    push\u3057\u3066\u304A\u304F\nG[a].pb(P(b,I++)),G[b].pb(P(a,I++))\n\n\u4E00\u822C\
    \u7684\u306B\u3059\u308B\u305F\u3081\u306B\u5909\u66F4\u3059\u3079\u304D\u90E8\
    \u5206\u306F,\nsum[v]=1\t\t\t\u3053\u3053\u306F\u521D\u671F\u5316\nadd(sum[v],dfs)\t\
    \t2\u7B87\u6240\u3068\u3082\u540C\u3058,merge\u3092\u304B\u304F\nsum[v]*inv[v+1]\t\
    \t\u3053\u3053\u306F\u5B50\u306Emerge\u304C\u7D42\u308F\u3063\u305F\u5F8C\u306B\
    \u4F55\u304B\u8A08\u7B97\u3059\u3079\u304D\u3053\u3068\u304C\u3042\u308B\u306A\
    \u3089\u3053\u3053\u306B\u304B\u304F\nsum[v]-mp[e^1]\t\t\u3053\u3053\u306Fmerge\u306E\
    \u9006\u64CD\u4F5C\n\u8352\u524A\u308A\u3060\u3051\u3069\u4E00\u5FDC SRM664d1m\
    \ \u3067verify\n\n*/\n#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define show(x) cout\
    \ << #x << \" = \" << x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y)\
    \ x=max(x,y)\nusing namespace std;\ntypedef long long ll;\ntypedef pair<int,int>\
    \ P;\nconst int MAX_N=1000000;\nint I;\nll mp[MAX_N*2];\nvector<P> G[MAX_N];\t\
    \t//to,id\nll sum[MAX_N];\nP done[MAX_N];\t\t//fs= -2:nothing yet , -1:all done\
    \ , x>=0: only x left   sc=edgeid(v,done[v])\nll dfs(int v,int p,int e){\t\t//v,p,edgeid(v,p)\n\
    \tif(done[v].fs==-2){\n\t\tsum[v]=1;\n\t\tfor(P q:G[v]) if(q.fs!=p) add(sum[v],dfs(q.fs,v,q.sc^1));\n\
    \t\tdone[v]=P(p,e);\n\t\treturn mp[e]=sum[v]*inv[v+1]%mod;\n\t}else if(done[v].fs>=0){\n\
    \t\tadd(sum[v],dfs(done[v].fs,v,done[v].sc^1));\n\t\tdone[v].fs=-1;\n\t}\n\tif(p==-1)\
    \ return sum[v]*inv[v+1]%mod;\n\telse return mp[e]=((sum[v]-mp[e^1])*inv[v+1]%mod+mod)%mod;\n\
    }\nint main(){\n\trep(i,N) done[i]=P(-2,0);\n\trep(i,N) dfs(i,-1,0);\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/treeDP/!treeDP_inv.cpp
  requiredBy: []
  timestamp: '2016-12-08 00:51:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/treeDP/!treeDP_inv.cpp
layout: document
redirect_from:
- /library/graph/treeDP/!treeDP_inv.cpp
- /library/graph/treeDP/!treeDP_inv.cpp.html
title: graph/treeDP/!treeDP_inv.cpp
---
