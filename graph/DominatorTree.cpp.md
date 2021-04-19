---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://www.codechef.com/problems/GRAPHCNT
  bundledCode: "#line 1 \"graph/DominatorTree.cpp\"\n/*\n\tG : directed graph\n\t\
    v,w in V \u306B\u3064\u3044\u3066,v dominates w \u21D4 Dominator Tree\u306B\u304A\
    \u3044\u3066v\u304B\u3089w\u3078\u306Epath\u304C\u3042\u308B\n\tv\u306E\u89AA\u3092\
    idom[v]\u3068\u3057\u3066\u6839\u4ED8\u304D\u6728(dominator tree)\u3092\u4F5C\u308C\
    \u3070dominate\u95A2\u4FC2(r->w\u306B\u884C\u304F\u3068\u304D\u5FC5\u305Av\u3092\
    \u901A\u308B\u304B)\u304C\u3059\u3079\u3066\u308F\u304B\u308B\n\tverified at:\n\
    \t\tAOJ294\n\t\thttps://www.codechef.com/problems/GRAPHCNT (root \u304B\u3089\u305F\
    \u3069\u308A\u7740\u3051\u306A\u3044\u9802\u70B9\u304C\u3042\u308B)\n\t\n*/\n\n\
    struct DominatorTree{\n\tV<int> par,m,parent,vertex,semi,U,idom;\n\tint I,N;\n\
    \tVV<int> bucket,G,rG;\n\n\tDominatorTree(const VV<int>& G_, int r = 0):G(G_){\n\
    \t\tN = G.size();\n\t\tI = 0;\n\t\tpar.resize(N);\n\t\tm.resize(N);\n\t\tparent.resize(N);\n\
    \t\tvertex = V<int>(N,-1);\n\t\tsemi.resize(N);\n\t\tU.resize(N);\n\t\tidom =\
    \ V<int>(N,-2);\n\t\tbucket.resize(N);\n\t\trG.resize(N);\n\t\trep(i,N) for(int\
    \ j: G[i]){\n\t\t\trG[j].pb(i);\n\t\t}\n\n\t\trep(i,N){\n\t\t\tpar[i] = i;\n\t\
    \t\tm[i] = i;\n\t\t\tsemi[i] = -1;\n\t\t}\n\t\tdfs(r);\n\t\tfor(int i=N-1;i>0;i--){\n\
    \t\t\tint w=vertex[i];\n\t\t\tif(w == -1) continue;\n\t\t\tfor(int v:rG[w]) if(semi[v]\
    \ != -1){\n\t\t\t\tint u=EVAL(v);\n\t\t\t\tchmin(semi[w],semi[u]);\n\t\t\t}\n\t\
    \t\tbucket[vertex[semi[w]]].pb(w);\n\t\t\tfor(int v:bucket[parent[w]]) U[v]=EVAL(v);\n\
    \t\t\tbucket[parent[w]].clear();\n\t\t\tLINK(parent[w],w);\n\t\t}\n\t\tfor(int\
    \ i=1;i<N;i++){\n\t\t\tint w=vertex[i];\n\t\t\tif(w == -1) continue;\n\t\t\tint\
    \ u=U[w];\n\t\t\tif(semi[w]==semi[u]) idom[w]=semi[w];\n\t\t\telse idom[w]=idom[u];\n\
    \t\t}\n\n\t\tfor(int i=1;i<N;i++){\t\t\t\t//idom[w]\u306E\u4E2D\u8EAB\u3092vertex\
    \ id\u304B\u3089\u540D\u524D\u306B\u5909\u3048\u308B\n\t\t\tint w=vertex[i];\n\
    \t\t\tif(w == -1) continue;\n\t\t\tidom[w]=vertex[idom[w]];\n\t\t}\n\t\tidom[r]\
    \ = -1;\n\t}\n\n\tint find(int v){\n\t\tif(par[v]==v) return v;\n\t\tint r=find(par[v]);\n\
    \t\tif(semi[m[v]]>semi[m[par[v]]]) m[v]=m[par[v]];\n\t\treturn par[v]=r;\n\t}\n\
    \tint EVAL(int v){\n\t\tfind(v);\n\t\treturn m[v];\n\t}\n\tvoid LINK(int x,int\
    \ y){\n\t\tpar[y]=x;\n\t}\n\tvoid dfs(int v){\n\t\tsemi[v]=I;\n\t\tvertex[I++]=v;\n\
    \t\tfor(int u:G[v]) if(semi[u]<0){\n\t\t\tparent[u]=v;\n\t\t\tdfs(u);\n\t\t}\n\
    \t}\n};\n\nint main(){\n\tint N,M;\n\tcin>>N>>M;\n\tVV<int> G(N);\n\trep(i,M){\n\
    \t\tint a,b;\n\t\tcin>>a>>b;\n\t\ta--,b--;\n\t\tG[a].pb(b);\n\t}\n\tDominatorTree\
    \ DT(G,0);\n\tVV<int> tree(N);\n\trep(i,N){\n\t\tint p = DT.idom[i];\n\t\tif(p\
    \ >= 0){\n\t\t\ttree[p].pb(i);\n\t\t}\n\t}\n\tfunction<int(int)> dfs = [&](int\
    \ v){\n\t\tint res = 1;\n\t\tfor(int u:tree[v]) res += dfs(u);\n\t\treturn res;\n\
    \t};\n\tusing ll = long long;\n\tV<ll> subtree_sz;\n\tfor(int c: tree[0]) subtree_sz.pb(dfs(c));\n\
    \tll ans = 0;\n\tll sm = 1;\n\tfor(ll x: subtree_sz){\n\t\tans += x * sm;\n\t\t\
    sm += x;\n\t}\n\tcout << ans << endl;\n}\n"
  code: "/*\n\tG : directed graph\n\tv,w in V \u306B\u3064\u3044\u3066,v dominates\
    \ w \u21D4 Dominator Tree\u306B\u304A\u3044\u3066v\u304B\u3089w\u3078\u306Epath\u304C\
    \u3042\u308B\n\tv\u306E\u89AA\u3092idom[v]\u3068\u3057\u3066\u6839\u4ED8\u304D\
    \u6728(dominator tree)\u3092\u4F5C\u308C\u3070dominate\u95A2\u4FC2(r->w\u306B\u884C\
    \u304F\u3068\u304D\u5FC5\u305Av\u3092\u901A\u308B\u304B)\u304C\u3059\u3079\u3066\
    \u308F\u304B\u308B\n\tverified at:\n\t\tAOJ294\n\t\thttps://www.codechef.com/problems/GRAPHCNT\
    \ (root \u304B\u3089\u305F\u3069\u308A\u7740\u3051\u306A\u3044\u9802\u70B9\u304C\
    \u3042\u308B)\n\t\n*/\n\nstruct DominatorTree{\n\tV<int> par,m,parent,vertex,semi,U,idom;\n\
    \tint I,N;\n\tVV<int> bucket,G,rG;\n\n\tDominatorTree(const VV<int>& G_, int r\
    \ = 0):G(G_){\n\t\tN = G.size();\n\t\tI = 0;\n\t\tpar.resize(N);\n\t\tm.resize(N);\n\
    \t\tparent.resize(N);\n\t\tvertex = V<int>(N,-1);\n\t\tsemi.resize(N);\n\t\tU.resize(N);\n\
    \t\tidom = V<int>(N,-2);\n\t\tbucket.resize(N);\n\t\trG.resize(N);\n\t\trep(i,N)\
    \ for(int j: G[i]){\n\t\t\trG[j].pb(i);\n\t\t}\n\n\t\trep(i,N){\n\t\t\tpar[i]\
    \ = i;\n\t\t\tm[i] = i;\n\t\t\tsemi[i] = -1;\n\t\t}\n\t\tdfs(r);\n\t\tfor(int\
    \ i=N-1;i>0;i--){\n\t\t\tint w=vertex[i];\n\t\t\tif(w == -1) continue;\n\t\t\t\
    for(int v:rG[w]) if(semi[v] != -1){\n\t\t\t\tint u=EVAL(v);\n\t\t\t\tchmin(semi[w],semi[u]);\n\
    \t\t\t}\n\t\t\tbucket[vertex[semi[w]]].pb(w);\n\t\t\tfor(int v:bucket[parent[w]])\
    \ U[v]=EVAL(v);\n\t\t\tbucket[parent[w]].clear();\n\t\t\tLINK(parent[w],w);\n\t\
    \t}\n\t\tfor(int i=1;i<N;i++){\n\t\t\tint w=vertex[i];\n\t\t\tif(w == -1) continue;\n\
    \t\t\tint u=U[w];\n\t\t\tif(semi[w]==semi[u]) idom[w]=semi[w];\n\t\t\telse idom[w]=idom[u];\n\
    \t\t}\n\n\t\tfor(int i=1;i<N;i++){\t\t\t\t//idom[w]\u306E\u4E2D\u8EAB\u3092vertex\
    \ id\u304B\u3089\u540D\u524D\u306B\u5909\u3048\u308B\n\t\t\tint w=vertex[i];\n\
    \t\t\tif(w == -1) continue;\n\t\t\tidom[w]=vertex[idom[w]];\n\t\t}\n\t\tidom[r]\
    \ = -1;\n\t}\n\n\tint find(int v){\n\t\tif(par[v]==v) return v;\n\t\tint r=find(par[v]);\n\
    \t\tif(semi[m[v]]>semi[m[par[v]]]) m[v]=m[par[v]];\n\t\treturn par[v]=r;\n\t}\n\
    \tint EVAL(int v){\n\t\tfind(v);\n\t\treturn m[v];\n\t}\n\tvoid LINK(int x,int\
    \ y){\n\t\tpar[y]=x;\n\t}\n\tvoid dfs(int v){\n\t\tsemi[v]=I;\n\t\tvertex[I++]=v;\n\
    \t\tfor(int u:G[v]) if(semi[u]<0){\n\t\t\tparent[u]=v;\n\t\t\tdfs(u);\n\t\t}\n\
    \t}\n};\n\nint main(){\n\tint N,M;\n\tcin>>N>>M;\n\tVV<int> G(N);\n\trep(i,M){\n\
    \t\tint a,b;\n\t\tcin>>a>>b;\n\t\ta--,b--;\n\t\tG[a].pb(b);\n\t}\n\tDominatorTree\
    \ DT(G,0);\n\tVV<int> tree(N);\n\trep(i,N){\n\t\tint p = DT.idom[i];\n\t\tif(p\
    \ >= 0){\n\t\t\ttree[p].pb(i);\n\t\t}\n\t}\n\tfunction<int(int)> dfs = [&](int\
    \ v){\n\t\tint res = 1;\n\t\tfor(int u:tree[v]) res += dfs(u);\n\t\treturn res;\n\
    \t};\n\tusing ll = long long;\n\tV<ll> subtree_sz;\n\tfor(int c: tree[0]) subtree_sz.pb(dfs(c));\n\
    \tll ans = 0;\n\tll sm = 1;\n\tfor(ll x: subtree_sz){\n\t\tans += x * sm;\n\t\t\
    sm += x;\n\t}\n\tcout << ans << endl;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/DominatorTree.cpp
  requiredBy: []
  timestamp: '2019-03-15 00:48:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/DominatorTree.cpp
layout: document
redirect_from:
- /library/graph/DominatorTree.cpp
- /library/graph/DominatorTree.cpp.html
title: graph/DominatorTree.cpp
---
