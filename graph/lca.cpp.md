---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/lca.cpp\"\n/*\nverified by AOJ GRL 5C\n\nlca(u,v)\u3092\
    \u30AF\u30A8\u30EAO(logN)\u3067\u6C42\u3081\u308B\n\u524D\u51E6\u7406O(NlogN)\n\
    p\u3068depth\u304C\u3046\u307E\u3063\u3066\u308C\u3070\u4E00\u500B\u76EE\u306E\
    genlca\u3060\u3051\u3067\u3044\u3044\u3051\u3069,\u4E00\u822C\u306B\u30B0\u30E9\
    \u30D5G\u304C\u3042\u308B\u72B6\u6CC1\u3060\u3068\n\u4E0B\u306Edfs+genlca\u3057\
    \u306A\u304D\u3083\u30C0\u30E1\n\npath\u306B\u5206\u89E3\u3059\u308B\u3068\u304D\
    \u306F[u,z) + [v,z) + z \u307F\u305F\u3044\u306B\u3059\u308B\u304B, \u7247\u65B9\
    \u3092\u9589\u533A\u9593\u306B\u3059\u308B(depth-1\u6301\u3061\u4E0A\u3052\u308B\
    )\u3068ok\n\n*/\n\nint bsr(int x){\t//4~7 -> 2\n\tif(x==0) return -1;\n\treturn\
    \ 31 ^ __builtin_clz(x);\n}\nstruct LCA{\n\tint N,n;\n\tvector<int> depth;\n\t\
    vector<vector<int>> par;\n\n\tvoid dfs(int v,int p,const vector<vector<int>>&\
    \ G){\n\t\tif(p<0) depth[v]=0;\n\t\telse depth[v]=depth[p]+1;\n\t\tpar[v][0]=p;\n\
    \t\tfor(int u:G[v]){\n\t\t\tif(u!=p) dfs(u,v,G);\n\t\t}\n\t}\n\n\tLCA(const vector<vector<int>>&\
    \ G){\n\t\tN = G.size();\n\t\tn = bsr(N);\n\t\tdepth = vector<int>(N,0);\n\t\t\
    par = vector<vector<int>>(N,vector<int>(n+1,0));\n\n\t\tdfs(0,-1,G);\n\t\trep1(i,n){\n\
    \t\t\trep(v,N){\n\t\t\t\tif(par[v][i-1]==-1){\n\t\t\t\t\tpar[v][i]=-1;\n\t\t\t\
    \t}else{\n\t\t\t\t\tpar[v][i]=par[par[v][i-1]][i-1];\n\t\t\t\t}\n\t\t\t}\n\t\t\
    }\n\t}\n\n\tint lca(int u,int v){\n\t\tif(depth[u]<depth[v]){\n\t\t\tswap(u,v);\n\
    \t\t}\n\t\tint d=depth[u]-depth[v];\n\t\trep(i,n+1){\n\t\t\tif((d>>i)&1) u=par[u][i];\n\
    \t\t}\n\t\tif(u==v) return u;\n\t\tfor(int i=n;i>=0;i--){\n\t\t\tif(par[u][i]!=par[v][i]){\n\
    \t\t\t\tu=par[u][i];\n\t\t\t\tv=par[v][i];\n\t\t\t}\n\t\t}\n\t\treturn par[v][0];\n\
    \t}\n\n\tint distance(int u,int v){\n\t\treturn depth[u] + depth[v] - 2*depth[lca(u,v)];\n\
    \t}\n\n\t/*\n\t\tx\u304B\u3089y\u306B\u3080\u304B\u3063\u3066d\u3046\u3054\u304F\
    \n\t\tdist(x,y) < d \u306A\u3089 y \u3092\u8FD4\u3059\n\t\tCF621 F\n\t*/\n\tint\
    \ jump(int x,int y,int d){\n\t\tint z = lca(x,y);\n\t\tint d1 = depth[x]-depth[z];\n\
    \t\tint d2 = depth[y]-depth[z];\n\t\tif(d <= d1){\n\t\t\t// up d from x\n\t\t\t\
    rep(i,n+1) if(d&1<<i) x = par[x][i];\n\t\t\treturn x;\n\t\t}else if(d <= d1+d2){\n\
    \t\t\t// up d1+d2-d from y\n\t\t\td = d1+d2-d;\n\t\t\trep(i,n+1) if(d&1<<i) y\
    \ = par[y][i];\n\t\t\treturn y;\n\t\t}else{\n\t\t\treturn y;\n\t\t}\n\t}\n};\n\
    \n// weighted graph\n// distance(x,y) \u304C\u91CD\u307F\u4ED8\u304D\u306E\u30B0\
    \u30E9\u30D5\u3067\u6B32\u3057\u3044\u6642\n\nint bsr(int x){\t//4~7 -> 2\n\t\
    if(x==0) return -1;\n\treturn 31 ^ __builtin_clz(x);\n}\ntemplate<class D>\nstruct\
    \ LCA{\n\tint N,n;\n\tvector<int> depth;\n\tV<D> d;\n\tvector<vector<int>> par;\n\
    \n\tvoid dfs(int v,int p,const vector<vector<pair<int,D>>>& G){\n\t\tpar[v][0]\
    \ = p;\n\t\tfor(auto e: G[v]) if(e.fs != p){\n\t\t\tdepth[e.fs] = depth[v] + 1;\n\
    \t\t\td[e.fs] = d[v] + e.sc;\n\t\t\tdfs(e.fs,v,G);\n\t\t}\n\t}\n\n\tLCA(const\
    \ vector<vector<pair<int,D>>>& G){\n\t\tN = G.size();\n\t\tn = bsr(N);\n\t\tdepth\
    \ = V<int>(N);\n\t\td = V<D>(N);\n\t\tpar = vector<vector<int>>(N,vector<int>(n+1,0));\n\
    \n\t\tdfs(0,-1,G);\n\t\trep1(i,n){\n\t\t\trep(v,N){\n\t\t\t\tif(par[v][i-1]==-1){\n\
    \t\t\t\t\tpar[v][i]=-1;\n\t\t\t\t}else{\n\t\t\t\t\tpar[v][i]=par[par[v][i-1]][i-1];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tint lca(int u,int v){\n\t\tif(depth[u]<depth[v]){\n\
    \t\t\tswap(u,v);\n\t\t}\n\t\tint d=depth[u]-depth[v];\n\t\trep(i,n+1){\n\t\t\t\
    if((d>>i)&1) u=par[u][i];\n\t\t}\n\t\tif(u==v) return u;\n\t\tfor(int i=n;i>=0;i--){\n\
    \t\t\tif(par[u][i]!=par[v][i]){\n\t\t\t\tu=par[u][i];\n\t\t\t\tv=par[v][i];\n\t\
    \t\t}\n\t\t}\n\t\treturn par[v][0];\n\t}\n\n\tD distance(int u,int v){\n\t\treturn\
    \ d[u] + d[v] - 2*d[lca(u,v)];\n\t}\n\n};\n"
  code: "/*\nverified by AOJ GRL 5C\n\nlca(u,v)\u3092\u30AF\u30A8\u30EAO(logN)\u3067\
    \u6C42\u3081\u308B\n\u524D\u51E6\u7406O(NlogN)\np\u3068depth\u304C\u3046\u307E\
    \u3063\u3066\u308C\u3070\u4E00\u500B\u76EE\u306Egenlca\u3060\u3051\u3067\u3044\
    \u3044\u3051\u3069,\u4E00\u822C\u306B\u30B0\u30E9\u30D5G\u304C\u3042\u308B\u72B6\
    \u6CC1\u3060\u3068\n\u4E0B\u306Edfs+genlca\u3057\u306A\u304D\u3083\u30C0\u30E1\
    \n\npath\u306B\u5206\u89E3\u3059\u308B\u3068\u304D\u306F[u,z) + [v,z) + z \u307F\
    \u305F\u3044\u306B\u3059\u308B\u304B, \u7247\u65B9\u3092\u9589\u533A\u9593\u306B\
    \u3059\u308B(depth-1\u6301\u3061\u4E0A\u3052\u308B)\u3068ok\n\n*/\n\nint bsr(int\
    \ x){\t//4~7 -> 2\n\tif(x==0) return -1;\n\treturn 31 ^ __builtin_clz(x);\n}\n\
    struct LCA{\n\tint N,n;\n\tvector<int> depth;\n\tvector<vector<int>> par;\n\n\t\
    void dfs(int v,int p,const vector<vector<int>>& G){\n\t\tif(p<0) depth[v]=0;\n\
    \t\telse depth[v]=depth[p]+1;\n\t\tpar[v][0]=p;\n\t\tfor(int u:G[v]){\n\t\t\t\
    if(u!=p) dfs(u,v,G);\n\t\t}\n\t}\n\n\tLCA(const vector<vector<int>>& G){\n\t\t\
    N = G.size();\n\t\tn = bsr(N);\n\t\tdepth = vector<int>(N,0);\n\t\tpar = vector<vector<int>>(N,vector<int>(n+1,0));\n\
    \n\t\tdfs(0,-1,G);\n\t\trep1(i,n){\n\t\t\trep(v,N){\n\t\t\t\tif(par[v][i-1]==-1){\n\
    \t\t\t\t\tpar[v][i]=-1;\n\t\t\t\t}else{\n\t\t\t\t\tpar[v][i]=par[par[v][i-1]][i-1];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tint lca(int u,int v){\n\t\tif(depth[u]<depth[v]){\n\
    \t\t\tswap(u,v);\n\t\t}\n\t\tint d=depth[u]-depth[v];\n\t\trep(i,n+1){\n\t\t\t\
    if((d>>i)&1) u=par[u][i];\n\t\t}\n\t\tif(u==v) return u;\n\t\tfor(int i=n;i>=0;i--){\n\
    \t\t\tif(par[u][i]!=par[v][i]){\n\t\t\t\tu=par[u][i];\n\t\t\t\tv=par[v][i];\n\t\
    \t\t}\n\t\t}\n\t\treturn par[v][0];\n\t}\n\n\tint distance(int u,int v){\n\t\t\
    return depth[u] + depth[v] - 2*depth[lca(u,v)];\n\t}\n\n\t/*\n\t\tx\u304B\u3089\
    y\u306B\u3080\u304B\u3063\u3066d\u3046\u3054\u304F\n\t\tdist(x,y) < d \u306A\u3089\
    \ y \u3092\u8FD4\u3059\n\t\tCF621 F\n\t*/\n\tint jump(int x,int y,int d){\n\t\t\
    int z = lca(x,y);\n\t\tint d1 = depth[x]-depth[z];\n\t\tint d2 = depth[y]-depth[z];\n\
    \t\tif(d <= d1){\n\t\t\t// up d from x\n\t\t\trep(i,n+1) if(d&1<<i) x = par[x][i];\n\
    \t\t\treturn x;\n\t\t}else if(d <= d1+d2){\n\t\t\t// up d1+d2-d from y\n\t\t\t\
    d = d1+d2-d;\n\t\t\trep(i,n+1) if(d&1<<i) y = par[y][i];\n\t\t\treturn y;\n\t\t\
    }else{\n\t\t\treturn y;\n\t\t}\n\t}\n};\n\n// weighted graph\n// distance(x,y)\
    \ \u304C\u91CD\u307F\u4ED8\u304D\u306E\u30B0\u30E9\u30D5\u3067\u6B32\u3057\u3044\
    \u6642\n\nint bsr(int x){\t//4~7 -> 2\n\tif(x==0) return -1;\n\treturn 31 ^ __builtin_clz(x);\n\
    }\ntemplate<class D>\nstruct LCA{\n\tint N,n;\n\tvector<int> depth;\n\tV<D> d;\n\
    \tvector<vector<int>> par;\n\n\tvoid dfs(int v,int p,const vector<vector<pair<int,D>>>&\
    \ G){\n\t\tpar[v][0] = p;\n\t\tfor(auto e: G[v]) if(e.fs != p){\n\t\t\tdepth[e.fs]\
    \ = depth[v] + 1;\n\t\t\td[e.fs] = d[v] + e.sc;\n\t\t\tdfs(e.fs,v,G);\n\t\t}\n\
    \t}\n\n\tLCA(const vector<vector<pair<int,D>>>& G){\n\t\tN = G.size();\n\t\tn\
    \ = bsr(N);\n\t\tdepth = V<int>(N);\n\t\td = V<D>(N);\n\t\tpar = vector<vector<int>>(N,vector<int>(n+1,0));\n\
    \n\t\tdfs(0,-1,G);\n\t\trep1(i,n){\n\t\t\trep(v,N){\n\t\t\t\tif(par[v][i-1]==-1){\n\
    \t\t\t\t\tpar[v][i]=-1;\n\t\t\t\t}else{\n\t\t\t\t\tpar[v][i]=par[par[v][i-1]][i-1];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tint lca(int u,int v){\n\t\tif(depth[u]<depth[v]){\n\
    \t\t\tswap(u,v);\n\t\t}\n\t\tint d=depth[u]-depth[v];\n\t\trep(i,n+1){\n\t\t\t\
    if((d>>i)&1) u=par[u][i];\n\t\t}\n\t\tif(u==v) return u;\n\t\tfor(int i=n;i>=0;i--){\n\
    \t\t\tif(par[u][i]!=par[v][i]){\n\t\t\t\tu=par[u][i];\n\t\t\t\tv=par[v][i];\n\t\
    \t\t}\n\t\t}\n\t\treturn par[v][0];\n\t}\n\n\tD distance(int u,int v){\n\t\treturn\
    \ d[u] + d[v] - 2*d[lca(u,v)];\n\t}\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/lca.cpp
  requiredBy: []
  timestamp: '2020-11-30 23:03:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/lca.cpp
layout: document
redirect_from:
- /library/graph/lca.cpp
- /library/graph/lca.cpp.html
title: graph/lca.cpp
---
