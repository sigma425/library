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
    - https://www.codechef.com/problems/UNIVERSE
  bundledCode: "#line 1 \"graph/CompressSubtree.cpp\"\n/*\n\t\u6728\u304C\u4E0E\u3048\
    \u3089\u308C\u308B\n\t\u30AF\u30A8\u30EA\u3068\u3057\u3066\u30B5\u30A4\u30BA K\
    \ \u306E\u9802\u70B9\u96C6\u5408\u304C\u6765\u308B\u3068\u3001\u7E2E\u7D04\u3057\
    \u305F\u6728\u3092 O(K log N) \u3067\u3064\u304F\u308B\n\n\tusage:\n\t\tCompressedSubtree\
    \ CS(tree)\n\t\t\u306E\u3042\u3068\u597D\u304D\u306A\u3060\u3051 CS.ComputeSubtree(vs)\
    \ \u3092\u547C\u3079\u3070\u3044\u3044\n\t\t\u8FD4\u308A\u5024\u306F vector<pair<int,int>>\
    \ \u3082\u3068\u306E\u9802\u70B9\u756A\u53F7\u3092\u4F7F\u3063\u3066\u3044\u308B\
    \n\t\t\u3082\u3057reindex\u3057\u305F\u3044\u306A\u3089index[v] \u3092\u898B\u308C\
    \u3070\u3044\u3044\n\n\tverified at : https://www.codechef.com/problems/UNIVERSE\n\
    \n*/\n\n#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define show(x) cout\
    \ << #x << \" = \" << x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y)\
    \ x=max(x,y)\nusing namespace std;\ntemplate<class S,class T> ostream& operator<<(ostream&\
    \ o,const pair<S,T> &p){return o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class\
    \ T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"\
    [\";for(const T& v:vc) o<<v<<\",\";o<<\"]\";return o;}\nusing ll = long long;\n\
    template<class T> using V = vector<T>;\ntemplate<class T> using VV = vector<vector<T>>;\n\
    \nint bsr(int x){\t//4~7 -> 2\n\tif(x==0) return -1;\n\treturn 31 ^ __builtin_clz(x);\n\
    }\n\ntemplate<class E>\nstruct CompressedSubtree{\n\tint N,n;\n\tV<int> depth;\n\
    \tVV<int> par;\n\tV<int> in;\n\tint I;\n\n\tV<int> index;\n\tV<int> vs;\n\n\t\
    CompressedSubtree(const VV<E>& G, int r = 0):N((int)G.size()),n(bsr(N)),depth(N),par(N,V<int>(n+1)),in(N),I(0),index(N){\n\
    \t\tdfs(r,-1,G);\n\t\trep1(i,n){\n\t\t\trep(v,N){\n\t\t\t\tif(par[v][i-1] == -1)\
    \ par[v][i] = -1;\n\t\t\t\telse par[v][i] = par[par[v][i-1]][i-1];\n\t\t\t}\n\t\
    \t}\n\t}\n\n\tV<pair<int,int>> ComputeTree(const V<int>& _vs){\n\t\tauto comp\
    \ = [&](int x,int y){\n\t\t\treturn in[x] < in[y];\n\t\t};\n\t\tvs = _vs;\n\t\t\
    sort(all(vs),comp);\n\t\tvs.erase(unique(vs.begin(),vs.end()),vs.end());\n\n\t\
    \tint K = vs.size();\n\t\trep(i,K-1){\n\t\t\tvs.pb(lca(vs[i],vs[i+1]));\n\t\t\
    }\n\t\tsort(all(vs),comp);\n\t\tvs.erase(unique(vs.begin(),vs.end()),vs.end());\n\
    \t\tK = vs.size();\n\t\trep(i,K) index[vs[i]] = i;\n\t\tV<pair<int,int>> es;\n\
    \t\trep1(i,K-1){\n\t\t\tint p = lca(vs[i-1],vs[i]);\n\t\t\tes.pb(pair<int,int>(vs[i],p));\n\
    \t\t}\n\t\treturn es;\n\t}\n\n\tvoid dfs(int v,int p,const VV<E>& G){\n\t\tin[v]\
    \ = I++;\n\t\tpar[v][0] = p;\n\t\tfor(auto& e : G[v]){\n\t\t\tint u = e.to;\n\t\
    \t\tif(u == p) continue;\n\t\t\tdepth[u] = depth[v] + 1;\n\t\t\tdfs(u,v,G);\n\t\
    \t}\n\t}\n\n\tint lca(int u,int v){\n\t\tif(depth[u]<depth[v]) swap(u,v);\n\t\t\
    int d = depth[u]-depth[v];\n\t\trep(i,n+1){\n\t\t\tif((d>>i)&1) u=par[u][i];\n\
    \t\t}\n\t\tif(u==v) return u;\n\t\tfor(int i=n;i>=0;i--){\n\t\t\tif(par[u][i]!=par[v][i]){\n\
    \t\t\t\tu=par[u][i];\n\t\t\t\tv=par[v][i];\n\t\t\t}\n\t\t}\n\t\treturn par[v][0];\n\
    \t}\n\tint distance(int u,int v){\n\t\treturn depth[u]+depth[v]-2*depth[lca(u,v)];\n\
    \t}\n};\n\nstruct edge{\n\tint to;\n};\n\ntemplate<class D>\nvector<D> dijkstra(const\
    \ vector<vector<pair<int,D>>>& G, int s = 0){\t//G:(v,cost)\n\tusing P = pair<D,int>;\n\
    \tpriority_queue<P,vector<P>,greater<P> > que;\n\tint N = G.size();\n\n\tD inf\
    \ = 1e18;\n\tvector<D> d(N,inf);\n\td[s] = 0;\n\tque.push(P(0,s));\n\n\twhile(!que.empty()){\n\
    \t\tP p=que.top();\n\t\tque.pop();\n\t\tint v = p.sc;\n\t\tD c = p.fs;\n\t\tif(d[v]!=c)\
    \ continue;\n\t\tfor(auto p:G[v]){\n\t\t\tint to=p.fs;\n\t\t\tif(d[to]>d[v]+p.sc){\n\
    \t\t\t\td[to]=d[v]+p.sc;\n\t\t\t\tque.push(P(d[to],to));\n\t\t\t}\n\t\t}\n\t}\n\
    \n\treturn d;\n}\n\nint main(){\n\tint N,M,Q;\n\tcin>>N>>M>>Q;\n\tVV<edge> T(N);\n\
    \trep(i,N-1){\n\t\tint x,y;\n\t\tcin>>x>>y;\n\t\tx--,y--;\n\t\tT[x].pb({y});\n\
    \t\tT[y].pb({x});\n\t}\n\tCompressedSubtree<edge> CS(T);\n\n\tVV<int> t2vs(200000);\n\
    \tV<int> x(M),tx(M),y(M),ty(M);\n\tV<int> qx(Q),qtx(Q),qy(Q),qty(Q);\n\n\trep(i,M){\n\
    \t\tcin>>x[i]>>tx[i]>>y[i]>>ty[i];\n\t\tx[i]--,tx[i]--,y[i]--,ty[i]--;\n\t\tt2vs[tx[i]].pb(x[i]);\n\
    \t\tt2vs[ty[i]].pb(y[i]);\n\t}\n\trep(i,Q){\n\t\tcin>>qx[i]>>qtx[i]>>qy[i]>>qty[i];\n\
    \t\tqx[i]--,qtx[i]--,qy[i]--,qty[i]--;\n\t\tt2vs[qtx[i]].pb(qx[i]);\n\t\tt2vs[qty[i]].pb(qy[i]);\n\
    \t}\n\n\tusing P = pair<int,int>;\n\tmap<P,int> mp;\t//t,v -> id\n\tint I = 0;\n\
    \n\trep(t,200000){\n\t\tauto& vs = t2vs[t];\n\t\tsort(all(vs));\n\t\tvs.erase(unique(all(vs)),vs.end());\n\
    \t\tauto es = CS.ComputeTree(vs);\n\t\tfor(int v : CS.vs){\n\t\t\tmp[P(t,v)] =\
    \ I++;\n\t\t}\n\t}\n\tVV<pair<int,ll>> G(I);\n\n\tauto add_edge = [&](int x,int\
    \ y,ll d){\n\t\tG[x].pb(pair<int,ll>(y,d));\n\t\tG[y].pb(pair<int,ll>(x,d));\n\
    \t};\n\n\trep(t,200000){\n\t\tauto& vs = t2vs[t];\n\t\tauto es = CS.ComputeTree(vs);\n\
    \t\tfor(P e: es){\n\t\t\tint x = e.fs, y = e.sc;\n\t\t\tadd_edge(mp[P(t,x)],mp[P(t,y)],CS.distance(x,y));\n\
    \t\t}\n\t}\n\trep(i,M){\n\t\tadd_edge(mp[P(tx[i],x[i])],mp[P(ty[i],y[i])],1);\n\
    \t}\n\n\trep(qt,Q){\n\t\tint a = qx[qt], ta = qtx[qt], b = qy[qt], tb = qty[qt];\n\
    \t\tvector<ll> d = dijkstra<ll>(G,mp[P(ta,a)]);\n\t\tll ans = d[mp[P(tb,b)]];\n\
    \t\tif(ans == 1e18) puts(\"impossible\");\n\t\telse cout<<ans<<endl;\n\t}\n}\n"
  code: "/*\n\t\u6728\u304C\u4E0E\u3048\u3089\u308C\u308B\n\t\u30AF\u30A8\u30EA\u3068\
    \u3057\u3066\u30B5\u30A4\u30BA K \u306E\u9802\u70B9\u96C6\u5408\u304C\u6765\u308B\
    \u3068\u3001\u7E2E\u7D04\u3057\u305F\u6728\u3092 O(K log N) \u3067\u3064\u304F\
    \u308B\n\n\tusage:\n\t\tCompressedSubtree CS(tree)\n\t\t\u306E\u3042\u3068\u597D\
    \u304D\u306A\u3060\u3051 CS.ComputeSubtree(vs) \u3092\u547C\u3079\u3070\u3044\u3044\
    \n\t\t\u8FD4\u308A\u5024\u306F vector<pair<int,int>> \u3082\u3068\u306E\u9802\u70B9\
    \u756A\u53F7\u3092\u4F7F\u3063\u3066\u3044\u308B\n\t\t\u3082\u3057reindex\u3057\
    \u305F\u3044\u306A\u3089index[v] \u3092\u898B\u308C\u3070\u3044\u3044\n\n\tverified\
    \ at : https://www.codechef.com/problems/UNIVERSE\n\n*/\n\n#include <bits/stdc++.h>\n\
    #define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<\"(\"\
    <<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class T> ostream& operator<<(ostream& o,const\
    \ vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"[\";for(const T& v:vc) o<<v<<\"\
    ,\";o<<\"]\";return o;}\nusing ll = long long;\ntemplate<class T> using V = vector<T>;\n\
    template<class T> using VV = vector<vector<T>>;\n\nint bsr(int x){\t//4~7 -> 2\n\
    \tif(x==0) return -1;\n\treturn 31 ^ __builtin_clz(x);\n}\n\ntemplate<class E>\n\
    struct CompressedSubtree{\n\tint N,n;\n\tV<int> depth;\n\tVV<int> par;\n\tV<int>\
    \ in;\n\tint I;\n\n\tV<int> index;\n\tV<int> vs;\n\n\tCompressedSubtree(const\
    \ VV<E>& G, int r = 0):N((int)G.size()),n(bsr(N)),depth(N),par(N,V<int>(n+1)),in(N),I(0),index(N){\n\
    \t\tdfs(r,-1,G);\n\t\trep1(i,n){\n\t\t\trep(v,N){\n\t\t\t\tif(par[v][i-1] == -1)\
    \ par[v][i] = -1;\n\t\t\t\telse par[v][i] = par[par[v][i-1]][i-1];\n\t\t\t}\n\t\
    \t}\n\t}\n\n\tV<pair<int,int>> ComputeTree(const V<int>& _vs){\n\t\tauto comp\
    \ = [&](int x,int y){\n\t\t\treturn in[x] < in[y];\n\t\t};\n\t\tvs = _vs;\n\t\t\
    sort(all(vs),comp);\n\t\tvs.erase(unique(vs.begin(),vs.end()),vs.end());\n\n\t\
    \tint K = vs.size();\n\t\trep(i,K-1){\n\t\t\tvs.pb(lca(vs[i],vs[i+1]));\n\t\t\
    }\n\t\tsort(all(vs),comp);\n\t\tvs.erase(unique(vs.begin(),vs.end()),vs.end());\n\
    \t\tK = vs.size();\n\t\trep(i,K) index[vs[i]] = i;\n\t\tV<pair<int,int>> es;\n\
    \t\trep1(i,K-1){\n\t\t\tint p = lca(vs[i-1],vs[i]);\n\t\t\tes.pb(pair<int,int>(vs[i],p));\n\
    \t\t}\n\t\treturn es;\n\t}\n\n\tvoid dfs(int v,int p,const VV<E>& G){\n\t\tin[v]\
    \ = I++;\n\t\tpar[v][0] = p;\n\t\tfor(auto& e : G[v]){\n\t\t\tint u = e.to;\n\t\
    \t\tif(u == p) continue;\n\t\t\tdepth[u] = depth[v] + 1;\n\t\t\tdfs(u,v,G);\n\t\
    \t}\n\t}\n\n\tint lca(int u,int v){\n\t\tif(depth[u]<depth[v]) swap(u,v);\n\t\t\
    int d = depth[u]-depth[v];\n\t\trep(i,n+1){\n\t\t\tif((d>>i)&1) u=par[u][i];\n\
    \t\t}\n\t\tif(u==v) return u;\n\t\tfor(int i=n;i>=0;i--){\n\t\t\tif(par[u][i]!=par[v][i]){\n\
    \t\t\t\tu=par[u][i];\n\t\t\t\tv=par[v][i];\n\t\t\t}\n\t\t}\n\t\treturn par[v][0];\n\
    \t}\n\tint distance(int u,int v){\n\t\treturn depth[u]+depth[v]-2*depth[lca(u,v)];\n\
    \t}\n};\n\nstruct edge{\n\tint to;\n};\n\ntemplate<class D>\nvector<D> dijkstra(const\
    \ vector<vector<pair<int,D>>>& G, int s = 0){\t//G:(v,cost)\n\tusing P = pair<D,int>;\n\
    \tpriority_queue<P,vector<P>,greater<P> > que;\n\tint N = G.size();\n\n\tD inf\
    \ = 1e18;\n\tvector<D> d(N,inf);\n\td[s] = 0;\n\tque.push(P(0,s));\n\n\twhile(!que.empty()){\n\
    \t\tP p=que.top();\n\t\tque.pop();\n\t\tint v = p.sc;\n\t\tD c = p.fs;\n\t\tif(d[v]!=c)\
    \ continue;\n\t\tfor(auto p:G[v]){\n\t\t\tint to=p.fs;\n\t\t\tif(d[to]>d[v]+p.sc){\n\
    \t\t\t\td[to]=d[v]+p.sc;\n\t\t\t\tque.push(P(d[to],to));\n\t\t\t}\n\t\t}\n\t}\n\
    \n\treturn d;\n}\n\nint main(){\n\tint N,M,Q;\n\tcin>>N>>M>>Q;\n\tVV<edge> T(N);\n\
    \trep(i,N-1){\n\t\tint x,y;\n\t\tcin>>x>>y;\n\t\tx--,y--;\n\t\tT[x].pb({y});\n\
    \t\tT[y].pb({x});\n\t}\n\tCompressedSubtree<edge> CS(T);\n\n\tVV<int> t2vs(200000);\n\
    \tV<int> x(M),tx(M),y(M),ty(M);\n\tV<int> qx(Q),qtx(Q),qy(Q),qty(Q);\n\n\trep(i,M){\n\
    \t\tcin>>x[i]>>tx[i]>>y[i]>>ty[i];\n\t\tx[i]--,tx[i]--,y[i]--,ty[i]--;\n\t\tt2vs[tx[i]].pb(x[i]);\n\
    \t\tt2vs[ty[i]].pb(y[i]);\n\t}\n\trep(i,Q){\n\t\tcin>>qx[i]>>qtx[i]>>qy[i]>>qty[i];\n\
    \t\tqx[i]--,qtx[i]--,qy[i]--,qty[i]--;\n\t\tt2vs[qtx[i]].pb(qx[i]);\n\t\tt2vs[qty[i]].pb(qy[i]);\n\
    \t}\n\n\tusing P = pair<int,int>;\n\tmap<P,int> mp;\t//t,v -> id\n\tint I = 0;\n\
    \n\trep(t,200000){\n\t\tauto& vs = t2vs[t];\n\t\tsort(all(vs));\n\t\tvs.erase(unique(all(vs)),vs.end());\n\
    \t\tauto es = CS.ComputeTree(vs);\n\t\tfor(int v : CS.vs){\n\t\t\tmp[P(t,v)] =\
    \ I++;\n\t\t}\n\t}\n\tVV<pair<int,ll>> G(I);\n\n\tauto add_edge = [&](int x,int\
    \ y,ll d){\n\t\tG[x].pb(pair<int,ll>(y,d));\n\t\tG[y].pb(pair<int,ll>(x,d));\n\
    \t};\n\n\trep(t,200000){\n\t\tauto& vs = t2vs[t];\n\t\tauto es = CS.ComputeTree(vs);\n\
    \t\tfor(P e: es){\n\t\t\tint x = e.fs, y = e.sc;\n\t\t\tadd_edge(mp[P(t,x)],mp[P(t,y)],CS.distance(x,y));\n\
    \t\t}\n\t}\n\trep(i,M){\n\t\tadd_edge(mp[P(tx[i],x[i])],mp[P(ty[i],y[i])],1);\n\
    \t}\n\n\trep(qt,Q){\n\t\tint a = qx[qt], ta = qtx[qt], b = qy[qt], tb = qty[qt];\n\
    \t\tvector<ll> d = dijkstra<ll>(G,mp[P(ta,a)]);\n\t\tll ans = d[mp[P(tb,b)]];\n\
    \t\tif(ans == 1e18) puts(\"impossible\");\n\t\telse cout<<ans<<endl;\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/CompressSubtree.cpp
  requiredBy: []
  timestamp: '2019-03-25 15:41:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/CompressSubtree.cpp
layout: document
redirect_from:
- /library/graph/CompressSubtree.cpp
- /library/graph/CompressSubtree.cpp.html
title: graph/CompressSubtree.cpp
---
