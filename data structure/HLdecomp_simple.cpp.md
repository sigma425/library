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
  bundledCode: "#line 1 \"data structure/HLdecomp_simple.cpp\"\n/*\n    \u3053\u3063\
    \u3061\u306F lazy \u304C\u306A\u3044\u65B9\u306E HLdecomp\n        OnEdge\n  \
    \      VV<E> G \u3092\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306B\u6E21\u3059\
    \n        query(u,v)\n        assign(v,x) <- OnEdge = 0 \u306E\u3068\u304D\n \
    \       assign(u,v,x) <- OnEdge = 1 \u306E\u3068\u304D\n    \n    verified at\
    \ ABC133F\n*/\n\ntemplate<class D>\nstruct segtree_simple{\n\tint N;\n\tvector<D>\
    \ val;\n\n\tsegtree_simple(){}\n\tsegtree_simple(int n){\n\t\tN=1;\n\t\twhile(N<n)\
    \ N*=2;\n\t\tval.assign(N*2,D::e());\n\t}\n\tsegtree_simple(const vector<D>& ds){\n\
    \t\tint n = ds.size();\n\t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\tval.assign(N*2,D::e());\n\
    \t\trep(i,n) val[i+N] = ds[i];\n\t\tfor(int i=N-1;i>0;i--) val[i] = val[i*2] +\
    \ val[i*2+1];\n\t}\n\tvoid assign(int k,D d){\n\t\tk+=N;\n\t\tval[k]=d;\n\t\t\
    k/=2;\n\t\twhile(k){\n\t\t\tval[k] = val[k*2] + val[k*2+1];\n\t\t\tk/=2;\n\t\t\
    }\n\t}\n\tD query(int a,int b){\t\t//non-commutative & unrecursive\n\t\tD L =\
    \ D::e() , R = D::e();\n\t\ta+=N,b+=N;\n\t\twhile(a<b){\n\t\t\tif(a&1) L = L +\
    \ val[a++];\n\t\t\tif(b&1) R = val[--b] + R;\n\t\t\ta/=2,b/=2;\n\t\t}\n\t\treturn\
    \ L+R;\n\t}\n};\n\ntemplate<class E, class D>\t\t//for simple segtree\nstruct\
    \ HLdecomp{\n\tusing segtree = segtree_simple<D>;\n\n\tstatic const bool OnEdge\
    \ = 1;\n\n\tvector<vector<E>> G;\n\tusing P = pair<int,int>;\n\tvector<P> id;\t\
    \t\t\t//id[v] = P(chain_id,pos_on_chain)\tpos\u306Ftop to bottom\n\tvector<int>\
    \ sz;\t\t\t\t//sz[v] = subtree_size\n\tvector<int> dep;\t\t\t//dep[v] = depth\n\
    \tvector<int> par;\t\t\t//par[v] = parent\n\tvector<int> top;\t\t\t//id[v].fs\
    \ \u306E\u4E00\u756A\u4E0A\n\n\tint C;\t//num of chains\n\tvector<vector<int>>\
    \ chains;\t//chains[c][i] = v <=> id[v] = P(c,i)\n\tvector<segtree> segs;\n\n\t\
    HLdecomp(const vector<vector<E>>& G_, int r = 0):G(G_){\n\t\tint N = G.size();\n\
    \t\tC = 1;\n\t\tchains.pb({0});\n\t\tid.assign(N,P(0,0));\n\t\tsz.assign(N,0);\n\
    \t\tdep.assign(N,0);\n\t\tpar.assign(N,0);\n\t\ttop.assign(N,0);\n\n\t\tdfs_base(r);\n\
    \t\tdfs_decomp(r);\n\n\t\n\t\trep(c,C) segs.pb(segtree(chains[c].size()));\n\t\
    }\n\tvoid dfs_base(int v,int p=-1){\t//calc sz,dep\n\t\tsz[v] = 1;\n\t\tpar[v]\
    \ = p;\n\t\tif(p==-1) dep[v] = 0;\n\t\telse dep[v] = dep[p] + 1;\n\t\tfor(const\
    \ auto& e: G[v]){\n\t\t\tint u = e.to;\n\t\t\tif(u==p) continue;\n\t\t\tdfs_base(u,v);\n\
    \t\t\tsz[v] += sz[u];\n\t\t}\n\t}\n\tvoid dfs_decomp(int v,int p=-1){\n\t\tint\
    \ heavy = -1;\n\t\tfor(const auto& e: G[v]){\n\t\t\tint u = e.to;\n\t\t\tif(u\
    \ == p) continue;\n\t\t\tif(heavy == -1 || sz[heavy]<sz[u]) heavy = u;\n\t\t}\n\
    \t\tfor(const auto& e: G[v]){\n\t\t\tint u = e.to;\n\t\t\tif(u == p) continue;\n\
    \t\t\tif(u == heavy){\n\t\t\t\tid[u] = P(id[v].fs,id[v].sc+1);\n\t\t\t\ttop[u]\
    \ = top[v];\n\t\t\t}else{\n\t\t\t\tid[u] = P(C,0);\n\t\t\t\ttop[u] = u;\n\t\t\t\
    \tC++;\n\t\t\t\tchains.pb({});\n\t\t\t}\n\t\t\tchains[id[u].fs].pb(u);\n\t\t\t\
    dfs_decomp(u,v);\n\t\t}\n\t}\n\tint lca(int a,int b){\n\t\twhile(id[a].fs != id[b].fs){\n\
    \t\t\tif(id[a].fs < id[b].fs) b = par[top[b]];\n\t\t\telse a = par[top[a]];\n\t\
    \t}\n\t\treturn dep[a]<dep[b] ? a : b;\n\t}\n\tint up(int v,int d){\t//v\u304B\
    \u3089\u4E0A\u306Bd\u4E0A\u304C\u3063\u305F\u70B9\n\t\tif(dep[v]<d) return -1;\n\
    \t\twhile(true){\n\t\t\tint d1 = dep[v] - dep[top[v]];\n\t\t\tif(d1<=d){\n\t\t\
    \t\td -= d1;\n\t\t\t\tv = top[v];\n\t\t\t}else{\n\t\t\t\tint c = id[v].fs;\n\t\
    \t\t\treturn chains[c][d1-d];\n\t\t\t}\n\t\t\tif(d==0) return v;\n\t\t\tv = par[v];\n\
    \t\t\td--;\n\t\t}\n\t\tassert(0);\n\t\treturn -1;\n\t}\n\tD query(int u,int v){\t\
    //[u,w) + [w,v]\t\t\tedge ver \u306A\u3089 [u,w) + (w,v]\n\t\tint w = lca(u,v);\n\
    \t\tD up,down;\n\n\t\t{\n\t\t\tfor(;id[u].fs!=id[w].fs; u = par[top[u]]){\n\t\t\
    \t\t//chains[c][l,r]\n\t\t\t\tint c = id[u].fs;\n\t\t\t\tint l = id[top[u]].sc;\n\
    \t\t\t\tint r = id[u].sc;\n\t\t\t\tD x = segs[c].query(l,r+1);\n\t\t\t\tup = x\
    \ + up;\n\t\t\t}\n\t\t\tint c = id[u].fs;\n\t\t\tint l = id[w].sc+1;\n\t\t\tint\
    \ r = id[u].sc;\n\t\t\tD x = segs[c].query(l,r+1);\n\t\t\tup = x + up;\n\t\t}\n\
    \t\t{\n\t\t\tu = v;\n\t\t\tfor(;id[u].fs!=id[w].fs; u = par[top[u]]){\n\t\t\t\t\
    int c = id[u].fs;\n\t\t\t\tint l = id[top[u]].sc;\n\t\t\t\tint r = id[u].sc;\n\
    \t\t\t\tD x = segs[c].query(l,r+1);\n\t\t\t\tdown = x + down;\n\t\t\t}\n\t\t\t\
    int c = id[u].fs;\n\t\t\tint l = id[w].sc + OnEdge;\n\t\t\tint r = id[u].sc;\n\
    \t\t\tD x = segs[c].query(l,r+1);\n\t\t\tdown = x + down;\n\t\t}\n\n\t\t// ! reverse\
    \ up !\n\t\treturn up + down;\n\t}\n\n\t// Vertex version\n\t// d[v] <= x\n\t\
    void assign(int v,const D &x){\n\t\tint c = id[v].fs;\n\t\tint i = id[v].sc;\n\
    \t\tsegs[c].assign(i,x);\n\t}\n\t// Edge version\n\t// d[(v,u)] <= x\n\tvoid assign(int\
    \ v,int u,const D &x){\n\t\tif(dep[v] < dep[u]) swap(v,u);\n\t\tassert(dep[v]\
    \ == dep[u]+1);\n\t\tint c = id[v].fs;\n\t\tint i = id[v].sc;\n\t\tsegs[c].assign(i,x);\n\
    \t}\n};\n\nstruct D{\n\tint x;\n\tD(){*this = e();}\n\tD(int x_):x(x_){}\n\tstatic\
    \ D e(){\n\t\treturn D(0);\n\t}\n\tD operator+(const D& r) const {\n\t\treturn\
    \ D(x+r.x);\n\t}\n};\n"
  code: "/*\n    \u3053\u3063\u3061\u306F lazy \u304C\u306A\u3044\u65B9\u306E HLdecomp\n\
    \        OnEdge\n        VV<E> G \u3092\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \u306B\u6E21\u3059\n        query(u,v)\n        assign(v,x) <- OnEdge = 0 \u306E\
    \u3068\u304D\n        assign(u,v,x) <- OnEdge = 1 \u306E\u3068\u304D\n    \n \
    \   verified at ABC133F\n*/\n\ntemplate<class D>\nstruct segtree_simple{\n\tint\
    \ N;\n\tvector<D> val;\n\n\tsegtree_simple(){}\n\tsegtree_simple(int n){\n\t\t\
    N=1;\n\t\twhile(N<n) N*=2;\n\t\tval.assign(N*2,D::e());\n\t}\n\tsegtree_simple(const\
    \ vector<D>& ds){\n\t\tint n = ds.size();\n\t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\t\
    val.assign(N*2,D::e());\n\t\trep(i,n) val[i+N] = ds[i];\n\t\tfor(int i=N-1;i>0;i--)\
    \ val[i] = val[i*2] + val[i*2+1];\n\t}\n\tvoid assign(int k,D d){\n\t\tk+=N;\n\
    \t\tval[k]=d;\n\t\tk/=2;\n\t\twhile(k){\n\t\t\tval[k] = val[k*2] + val[k*2+1];\n\
    \t\t\tk/=2;\n\t\t}\n\t}\n\tD query(int a,int b){\t\t//non-commutative & unrecursive\n\
    \t\tD L = D::e() , R = D::e();\n\t\ta+=N,b+=N;\n\t\twhile(a<b){\n\t\t\tif(a&1)\
    \ L = L + val[a++];\n\t\t\tif(b&1) R = val[--b] + R;\n\t\t\ta/=2,b/=2;\n\t\t}\n\
    \t\treturn L+R;\n\t}\n};\n\ntemplate<class E, class D>\t\t//for simple segtree\n\
    struct HLdecomp{\n\tusing segtree = segtree_simple<D>;\n\n\tstatic const bool\
    \ OnEdge = 1;\n\n\tvector<vector<E>> G;\n\tusing P = pair<int,int>;\n\tvector<P>\
    \ id;\t\t\t\t//id[v] = P(chain_id,pos_on_chain)\tpos\u306Ftop to bottom\n\tvector<int>\
    \ sz;\t\t\t\t//sz[v] = subtree_size\n\tvector<int> dep;\t\t\t//dep[v] = depth\n\
    \tvector<int> par;\t\t\t//par[v] = parent\n\tvector<int> top;\t\t\t//id[v].fs\
    \ \u306E\u4E00\u756A\u4E0A\n\n\tint C;\t//num of chains\n\tvector<vector<int>>\
    \ chains;\t//chains[c][i] = v <=> id[v] = P(c,i)\n\tvector<segtree> segs;\n\n\t\
    HLdecomp(const vector<vector<E>>& G_, int r = 0):G(G_){\n\t\tint N = G.size();\n\
    \t\tC = 1;\n\t\tchains.pb({0});\n\t\tid.assign(N,P(0,0));\n\t\tsz.assign(N,0);\n\
    \t\tdep.assign(N,0);\n\t\tpar.assign(N,0);\n\t\ttop.assign(N,0);\n\n\t\tdfs_base(r);\n\
    \t\tdfs_decomp(r);\n\n\t\n\t\trep(c,C) segs.pb(segtree(chains[c].size()));\n\t\
    }\n\tvoid dfs_base(int v,int p=-1){\t//calc sz,dep\n\t\tsz[v] = 1;\n\t\tpar[v]\
    \ = p;\n\t\tif(p==-1) dep[v] = 0;\n\t\telse dep[v] = dep[p] + 1;\n\t\tfor(const\
    \ auto& e: G[v]){\n\t\t\tint u = e.to;\n\t\t\tif(u==p) continue;\n\t\t\tdfs_base(u,v);\n\
    \t\t\tsz[v] += sz[u];\n\t\t}\n\t}\n\tvoid dfs_decomp(int v,int p=-1){\n\t\tint\
    \ heavy = -1;\n\t\tfor(const auto& e: G[v]){\n\t\t\tint u = e.to;\n\t\t\tif(u\
    \ == p) continue;\n\t\t\tif(heavy == -1 || sz[heavy]<sz[u]) heavy = u;\n\t\t}\n\
    \t\tfor(const auto& e: G[v]){\n\t\t\tint u = e.to;\n\t\t\tif(u == p) continue;\n\
    \t\t\tif(u == heavy){\n\t\t\t\tid[u] = P(id[v].fs,id[v].sc+1);\n\t\t\t\ttop[u]\
    \ = top[v];\n\t\t\t}else{\n\t\t\t\tid[u] = P(C,0);\n\t\t\t\ttop[u] = u;\n\t\t\t\
    \tC++;\n\t\t\t\tchains.pb({});\n\t\t\t}\n\t\t\tchains[id[u].fs].pb(u);\n\t\t\t\
    dfs_decomp(u,v);\n\t\t}\n\t}\n\tint lca(int a,int b){\n\t\twhile(id[a].fs != id[b].fs){\n\
    \t\t\tif(id[a].fs < id[b].fs) b = par[top[b]];\n\t\t\telse a = par[top[a]];\n\t\
    \t}\n\t\treturn dep[a]<dep[b] ? a : b;\n\t}\n\tint up(int v,int d){\t//v\u304B\
    \u3089\u4E0A\u306Bd\u4E0A\u304C\u3063\u305F\u70B9\n\t\tif(dep[v]<d) return -1;\n\
    \t\twhile(true){\n\t\t\tint d1 = dep[v] - dep[top[v]];\n\t\t\tif(d1<=d){\n\t\t\
    \t\td -= d1;\n\t\t\t\tv = top[v];\n\t\t\t}else{\n\t\t\t\tint c = id[v].fs;\n\t\
    \t\t\treturn chains[c][d1-d];\n\t\t\t}\n\t\t\tif(d==0) return v;\n\t\t\tv = par[v];\n\
    \t\t\td--;\n\t\t}\n\t\tassert(0);\n\t\treturn -1;\n\t}\n\tD query(int u,int v){\t\
    //[u,w) + [w,v]\t\t\tedge ver \u306A\u3089 [u,w) + (w,v]\n\t\tint w = lca(u,v);\n\
    \t\tD up,down;\n\n\t\t{\n\t\t\tfor(;id[u].fs!=id[w].fs; u = par[top[u]]){\n\t\t\
    \t\t//chains[c][l,r]\n\t\t\t\tint c = id[u].fs;\n\t\t\t\tint l = id[top[u]].sc;\n\
    \t\t\t\tint r = id[u].sc;\n\t\t\t\tD x = segs[c].query(l,r+1);\n\t\t\t\tup = x\
    \ + up;\n\t\t\t}\n\t\t\tint c = id[u].fs;\n\t\t\tint l = id[w].sc+1;\n\t\t\tint\
    \ r = id[u].sc;\n\t\t\tD x = segs[c].query(l,r+1);\n\t\t\tup = x + up;\n\t\t}\n\
    \t\t{\n\t\t\tu = v;\n\t\t\tfor(;id[u].fs!=id[w].fs; u = par[top[u]]){\n\t\t\t\t\
    int c = id[u].fs;\n\t\t\t\tint l = id[top[u]].sc;\n\t\t\t\tint r = id[u].sc;\n\
    \t\t\t\tD x = segs[c].query(l,r+1);\n\t\t\t\tdown = x + down;\n\t\t\t}\n\t\t\t\
    int c = id[u].fs;\n\t\t\tint l = id[w].sc + OnEdge;\n\t\t\tint r = id[u].sc;\n\
    \t\t\tD x = segs[c].query(l,r+1);\n\t\t\tdown = x + down;\n\t\t}\n\n\t\t// ! reverse\
    \ up !\n\t\treturn up + down;\n\t}\n\n\t// Vertex version\n\t// d[v] <= x\n\t\
    void assign(int v,const D &x){\n\t\tint c = id[v].fs;\n\t\tint i = id[v].sc;\n\
    \t\tsegs[c].assign(i,x);\n\t}\n\t// Edge version\n\t// d[(v,u)] <= x\n\tvoid assign(int\
    \ v,int u,const D &x){\n\t\tif(dep[v] < dep[u]) swap(v,u);\n\t\tassert(dep[v]\
    \ == dep[u]+1);\n\t\tint c = id[v].fs;\n\t\tint i = id[v].sc;\n\t\tsegs[c].assign(i,x);\n\
    \t}\n};\n\nstruct D{\n\tint x;\n\tD(){*this = e();}\n\tD(int x_):x(x_){}\n\tstatic\
    \ D e(){\n\t\treturn D(0);\n\t}\n\tD operator+(const D& r) const {\n\t\treturn\
    \ D(x+r.x);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data structure/HLdecomp_simple.cpp
  requiredBy: []
  timestamp: '2019-08-22 16:22:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/HLdecomp_simple.cpp
layout: document
redirect_from:
- /library/data structure/HLdecomp_simple.cpp
- /library/data structure/HLdecomp_simple.cpp.html
title: data structure/HLdecomp_simple.cpp
---
