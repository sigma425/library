---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/bell_old.cpp\"\n/*\n\t\u30D9\u30EB\u6570(\u7B2C\u4E8C\
    \u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u548C)\n\t\u30B0\u30EB\u30FC\
    \u30D7\u306B\u5206\u3051\u308B\u65B9\u6CD5\u306E\u5217\u6319\n\tB8=4140,B9=21147,B10=115975,B11=678570,...\n\
    \tN\u3092\u4EE3\u5165\u3057\u3066dfs(0)\u3067\u5168\u5217\u6319\n\t\u3088\u308A\
    \u7D30\u304B\u3044\u5206\u5272\u304Cparts[]\u306Eindex\u5C0F\u3055\u3044\u65B9\
    \u306B\u304F\u308B\u3053\u3068\u306F\u306A\u3044\u3001\u3064\u307E\u308Amerge\u3059\
    \u308B\u3068id\u306F\u6E1B\u308B (\u672C\u5F53?)\n\n\n\trep(i,K) rep(j,A) for(int\
    \ k=j+1;k<A;k++)\u306E\u3068\u3053\u308D\u306F \u5206\u5272\u3068\u3057\u3066\
    Hasse\u56F3\u3067\u76F4\u4E0A\u306E\u3084\u3064\u3092\u5168\u90E8\u63A2\u3057\u3066\
    \u308B\n\t\u3053\u308C\u3092\u3084\u308B\u3053\u3068\u3067\u300CX\u306E\u7D30\u5206\
    \u5168\u4F53\u300D\u306B\u518D\u5E30\u3067\u30A2\u30AF\u30BB\u30B9\u3067\u304D\
    \u308B(dfs2)\u306E\u3067\u5305\u9664\u3068\u304B\u306B\u4F7F\u3048\u308B\n\tO((B_N)^2)\u3068\
    \u304B\u306B\u306A\u308B\u306E\u3067N=9\u304F\u3089\u3044\u307E\u3067\u3063\u307D\
    \u3044(\u306A\u3093\u304B\u5305\u9664\u3059\u308B\u306E\u306B\u3082\u3063\u3068\
    \u826F\u3044\u30AA\u30FC\u30C0\u30FC\u306E\u3082\u306E\u304C\u3042\u308B\u3060\
    \u308D\u3046\u304B)\n\t\u2191\u5305\u9664\u306E\u4FC2\u6570\u306F1 -1 2 -6 24\
    \ -120 \u307F\u305F\u3044\u306B\u306A\u308A\u307E\u3059\n\t\u2191\u3061\u3083\u3093\
    \u3068\u8A00\u3046\u3068\u3001\u300C\u5168\u90E8distinct\u300D\u3092\u6C42\u3081\
    \u308B\u306E\u306B\u3001\u5404\u5206\u5272(\u5185\u306F\u7D76\u5BFE\u306B\u540C\
    \u3058\u5024)\u306E\u7DDA\u5F62\u548C\u3067\u304B\u3051\u308B\u304C\u3001\u305D\
    \u306E\u4FC2\u6570\u306F\u3001\n\t\t\u9023\u7D50\u6210\u5206\u3054\u3068\u306B\
    \u3001fac[size-1] * (-1)^(size-1) \u3092\u304B\u3051\u305F\u3082\u306E\u306B\u306A\
    \u308B\n\t\t\u9023\u7D50\u6210\u5206\u6570\u3060\u3051\u306B\u4F9D\u5B58\u3059\
    \u308B\u308F\u3051\u3067\u306F\u306A\u3044\u3001\u5F53\u305F\u308A\u524D\u3060\
    \u3051\u3069(1\u6557)\n*/\ntypedef vector<int> vi;\ntypedef vector<vi> vv;\nvector<vv>\
    \ parts;\nvv now;\nmap<vv,int> mp;\nvector<int> G[21147];\nint N,M;\nvoid dfs(int\
    \ x){\n\tif(x==N){\n\t\tmp[now]=parts.size();\n\t\tparts.pb(now);\n\t\treturn;\n\
    \t}\n\trep(i,now.size()){\n\t\tnow[i].pb(x);\n\t\tdfs(x+1);\n\t\tnow[i].pop_back();\n\
    \t}\n\tnow.pb(vi(1,x));\n\tdfs(x+1);\n\tnow.pop_back();\n}\n\nbool same(vv vs,int\
    \ a,int b){\n\tint N=vs.size();\n\tint aa=-1,bb=-1;\n\trep(i,N){\n\t\tfor(int\
    \ x:vs[i]){\n\t\t\tif(x==a) aa=i;\n\t\t\tif(x==b) bb=i;\n\t\t}\n\t}\n\tassert(aa>=0&&bb>=0);\n\
    \treturn aa==bb;\n}\nvoid showvv(vv vs){\n\tint N=vs.size();\n\trep(i,N){\n\t\t\
    cout<<\"{\";\n\t\tfor(int x:vs[i]) cout<<x<<\",\";\n\t\tcout<<\"}  \";\n\t}\n\t\
    puts(\"\");\n}\n\nlong long calc[21147];\nbool vis[21147];\nint V;\nvoid dfs2(int\
    \ v){\n\tvis[v]=1;\n\tif(V!=v) calc[V]-=calc[v];\n\tfor(int u:G[v]) if(!vis[u])\
    \ dfs2(u);\n}\n\nclass Gxor{\n\tpublic:\n\tlong long countsubs(vector <string>\
    \ S){\n\t\tM=S.size();\n\t\tfor(;;N++) if(N*(N-1)/2==S[0].size()) break;\n\t\t\
    dfs(0);\n\t\tint K=parts.size();\n\t\tshow(K);\n\t\trep(i,K){\n\t\t\tint A=parts[i].size();\n\
    \t\t\trep(j,A) for(int k=j+1;k<A;k++){\n\t\t\t\tvv nv;\n\t\t\t\trep(l,A){\n\t\t\
    \t\t\tif(l==j){\n\t\t\t\t\t\tvi h=parts[i][j];\n\t\t\t\t\t\th.insert(h.end(),all(parts[i][k]));\n\
    \t\t\t\t\t\tsort(all(h));\n\t\t\t\t\t\tnv.pb(h);\n\t\t\t\t\t}else if(l!=k){\n\t\
    \t\t\t\t\tnv.pb(parts[i][l]);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\tassert(mp.count(nv));\n\
    \t\t\t\tint id=mp[nv];\n\t\t\t\tG[id].pb(i);\n\t\t\t}\n\t\t}\n\t\tfor(int i=K-1;i>=0;i--){\t\
    \t//partition small -> large\n//\t\t\tshow(i);\n\t\t\tV=i;\n\t\t\tmemset(vis,0,K);\n\
    \t\t\tdfs2(i);\n//\t\t\tfor(int j:G[i]) show(j),calc[i]-=calc[j];\n//\t\t\tputs(\"\
    \");\n\t\t}\n\t\treturn calc[0];\n\t}\n};\n"
  code: "/*\n\t\u30D9\u30EB\u6570(\u7B2C\u4E8C\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\
    \u30B0\u6570\u306E\u548C)\n\t\u30B0\u30EB\u30FC\u30D7\u306B\u5206\u3051\u308B\u65B9\
    \u6CD5\u306E\u5217\u6319\n\tB8=4140,B9=21147,B10=115975,B11=678570,...\n\tN\u3092\
    \u4EE3\u5165\u3057\u3066dfs(0)\u3067\u5168\u5217\u6319\n\t\u3088\u308A\u7D30\u304B\
    \u3044\u5206\u5272\u304Cparts[]\u306Eindex\u5C0F\u3055\u3044\u65B9\u306B\u304F\
    \u308B\u3053\u3068\u306F\u306A\u3044\u3001\u3064\u307E\u308Amerge\u3059\u308B\u3068\
    id\u306F\u6E1B\u308B (\u672C\u5F53?)\n\n\n\trep(i,K) rep(j,A) for(int k=j+1;k<A;k++)\u306E\
    \u3068\u3053\u308D\u306F \u5206\u5272\u3068\u3057\u3066Hasse\u56F3\u3067\u76F4\
    \u4E0A\u306E\u3084\u3064\u3092\u5168\u90E8\u63A2\u3057\u3066\u308B\n\t\u3053\u308C\
    \u3092\u3084\u308B\u3053\u3068\u3067\u300CX\u306E\u7D30\u5206\u5168\u4F53\u300D\
    \u306B\u518D\u5E30\u3067\u30A2\u30AF\u30BB\u30B9\u3067\u304D\u308B(dfs2)\u306E\
    \u3067\u5305\u9664\u3068\u304B\u306B\u4F7F\u3048\u308B\n\tO((B_N)^2)\u3068\u304B\
    \u306B\u306A\u308B\u306E\u3067N=9\u304F\u3089\u3044\u307E\u3067\u3063\u307D\u3044\
    (\u306A\u3093\u304B\u5305\u9664\u3059\u308B\u306E\u306B\u3082\u3063\u3068\u826F\
    \u3044\u30AA\u30FC\u30C0\u30FC\u306E\u3082\u306E\u304C\u3042\u308B\u3060\u308D\
    \u3046\u304B)\n\t\u2191\u5305\u9664\u306E\u4FC2\u6570\u306F1 -1 2 -6 24 -120 \u307F\
    \u305F\u3044\u306B\u306A\u308A\u307E\u3059\n\t\u2191\u3061\u3083\u3093\u3068\u8A00\
    \u3046\u3068\u3001\u300C\u5168\u90E8distinct\u300D\u3092\u6C42\u3081\u308B\u306E\
    \u306B\u3001\u5404\u5206\u5272(\u5185\u306F\u7D76\u5BFE\u306B\u540C\u3058\u5024\
    )\u306E\u7DDA\u5F62\u548C\u3067\u304B\u3051\u308B\u304C\u3001\u305D\u306E\u4FC2\
    \u6570\u306F\u3001\n\t\t\u9023\u7D50\u6210\u5206\u3054\u3068\u306B\u3001fac[size-1]\
    \ * (-1)^(size-1) \u3092\u304B\u3051\u305F\u3082\u306E\u306B\u306A\u308B\n\t\t\
    \u9023\u7D50\u6210\u5206\u6570\u3060\u3051\u306B\u4F9D\u5B58\u3059\u308B\u308F\
    \u3051\u3067\u306F\u306A\u3044\u3001\u5F53\u305F\u308A\u524D\u3060\u3051\u3069\
    (1\u6557)\n*/\ntypedef vector<int> vi;\ntypedef vector<vi> vv;\nvector<vv> parts;\n\
    vv now;\nmap<vv,int> mp;\nvector<int> G[21147];\nint N,M;\nvoid dfs(int x){\n\t\
    if(x==N){\n\t\tmp[now]=parts.size();\n\t\tparts.pb(now);\n\t\treturn;\n\t}\n\t\
    rep(i,now.size()){\n\t\tnow[i].pb(x);\n\t\tdfs(x+1);\n\t\tnow[i].pop_back();\n\
    \t}\n\tnow.pb(vi(1,x));\n\tdfs(x+1);\n\tnow.pop_back();\n}\n\nbool same(vv vs,int\
    \ a,int b){\n\tint N=vs.size();\n\tint aa=-1,bb=-1;\n\trep(i,N){\n\t\tfor(int\
    \ x:vs[i]){\n\t\t\tif(x==a) aa=i;\n\t\t\tif(x==b) bb=i;\n\t\t}\n\t}\n\tassert(aa>=0&&bb>=0);\n\
    \treturn aa==bb;\n}\nvoid showvv(vv vs){\n\tint N=vs.size();\n\trep(i,N){\n\t\t\
    cout<<\"{\";\n\t\tfor(int x:vs[i]) cout<<x<<\",\";\n\t\tcout<<\"}  \";\n\t}\n\t\
    puts(\"\");\n}\n\nlong long calc[21147];\nbool vis[21147];\nint V;\nvoid dfs2(int\
    \ v){\n\tvis[v]=1;\n\tif(V!=v) calc[V]-=calc[v];\n\tfor(int u:G[v]) if(!vis[u])\
    \ dfs2(u);\n}\n\nclass Gxor{\n\tpublic:\n\tlong long countsubs(vector <string>\
    \ S){\n\t\tM=S.size();\n\t\tfor(;;N++) if(N*(N-1)/2==S[0].size()) break;\n\t\t\
    dfs(0);\n\t\tint K=parts.size();\n\t\tshow(K);\n\t\trep(i,K){\n\t\t\tint A=parts[i].size();\n\
    \t\t\trep(j,A) for(int k=j+1;k<A;k++){\n\t\t\t\tvv nv;\n\t\t\t\trep(l,A){\n\t\t\
    \t\t\tif(l==j){\n\t\t\t\t\t\tvi h=parts[i][j];\n\t\t\t\t\t\th.insert(h.end(),all(parts[i][k]));\n\
    \t\t\t\t\t\tsort(all(h));\n\t\t\t\t\t\tnv.pb(h);\n\t\t\t\t\t}else if(l!=k){\n\t\
    \t\t\t\t\tnv.pb(parts[i][l]);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\tassert(mp.count(nv));\n\
    \t\t\t\tint id=mp[nv];\n\t\t\t\tG[id].pb(i);\n\t\t\t}\n\t\t}\n\t\tfor(int i=K-1;i>=0;i--){\t\
    \t//partition small -> large\n//\t\t\tshow(i);\n\t\t\tV=i;\n\t\t\tmemset(vis,0,K);\n\
    \t\t\tdfs2(i);\n//\t\t\tfor(int j:G[i]) show(j),calc[i]-=calc[j];\n//\t\t\tputs(\"\
    \");\n\t\t}\n\t\treturn calc[0];\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/bell_old.cpp
  requiredBy: []
  timestamp: '2021-08-11 01:17:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/bell_old.cpp
layout: document
redirect_from:
- /library/math/bell_old.cpp
- /library/math/bell_old.cpp.html
title: math/bell_old.cpp
---
