---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data structure/HLdecomp_lazy.cpp\"\n/*\n\tHL-decomposition\
    \ for lazy\n\tlazy segtree \u3068\u540C\u3058\u3053\u3068\u3092\u6728\u306E(\u9802\
    \u70B9\u96C6\u5408 / \u8FBA\u96C6\u5408)\u306B\u5BFE\u3057\u3066\u3067\u304D\u308B\
    \n\t**** OnEdge **** \u3068\u3044\u3046 bool \u3092\u5909\u3048\u308B\u3060\u3051\
    \u3067\u4F7F\u3048\u308B\n\n\tassumption :\n\t\ta*b*..*c*d \u304B\u3089 d*c*..*b*a\
    \ \u304C\u7C21\u5358\u306B\u8A08\u7B97\u3067\u304D\u308B (up \u3092 reverse \u3059\
    \u308B\u5FC5\u8981\u304C\u3042\u308B)\n\t\t\t\u305D\u3046\u3067\u306A\u3044\u5834\
    \u5408\u3001\u4E0A\u5411\u304D\u3068\u4E0B\u5411\u304D\u306Esegtree\u3092\u4E21\
    \u65B9\u4FDD\u3064\u5FC5\u8981\u304C\u3042\u308B(\u4ECA\u306F\u4E0B\u5411\u304D\
    \u3060\u3051)\n\n\tusage : \n\t\tOnEdge \u5909\u3048\u308B\n\t\tvector<vector<Edge>>\
    \ G \u3092constructor\u306B\u6E21\u3059\n\t\tquery(u,val_t)\n\t\tupdate(u,v,opr_t)\n\
    \n\tverified at AGC14/E\n\t\t\t\tOpenCup/9922/E.cpp\n*/\n\ntemplate<class Handler>\n\
    struct segtree_lazy{\n\tusing val_t = typename Handler::val_t;\n\tusing opr_t\
    \ = typename Handler::opr_t;\n\tint N;\n\tvector<val_t> val;\n\tvector<opr_t>\
    \ lazy;\n\tsegtree_lazy(){}\n\tsegtree_lazy(int n){init(n);}\n\tsegtree_lazy(const\
    \ vector<val_t>& vc){init(vc);}\n\tvoid init(int n){\n\t\tN=1;\n\t\twhile(N<n)\
    \ N*=2;\n\t\tval .assign(N*2,val_t::e());\n\t\tlazy.assign(N*2,opr_t::e());\n\t\
    }\n\tvoid init(const vector<val_t>& vc){\n\t\tint n = vc.size();\n\t\tN=1;\n\t\
    \twhile(N<n) N*=2;\n\t\tval .assign(N*2,val_t::e());\n\t\trep(i,n) val[i+N] =\
    \ vc[i];\n\t\tfor(int i=N-1;i>0;i--) val[i] = val[i*2] + val[i*2+1];\n\t\tlazy.assign(N*2,opr_t::e());\n\
    \t}\n\tval_t realvalue(int k,int l,int r){\n//\t\treturn Handler::act(lazy[k],val[k]);\n\
    \t\treturn Handler::act(lazy[k],val[k],k,l,r);\n\t}\n\n\tval_t query(int a,int\
    \ b,int l=0,int r=-1,int k=1){\t//query_calc\n//\t\tif(k==1) printf(\"query [%d,%d)\\\
    n\",a,b);\n\t\tif(r==-1) r=N;\n\t\tif(b<=l||r<=a) return val_t::e();\n\t\tif(a<=l&&r<=b)\
    \ return realvalue(k,l,r);\n\t\tpropagate(l,r,k);\n\t\tval_t ret = query(a,b,l,(l+r)/2,k*2)\
    \ + query(a,b,(l+r)/2,r,k*2+1);\n\t\tval[k] = realvalue(k*2,l,(l+r)/2) + realvalue(k*2+1,(l+r)/2,r);\n\
    \t\treturn ret;\n\n\t}\n//\tval_t query_leftassoc(){}\n\tvoid update(int a,int\
    \ b,const opr_t &x,int l=0,int r=-1,int k=1){\t//query_update\n//\t\tif(k==1)\
    \ printf(\"update [%d,%d)\\n\",a,b);\n\t\tif(r==-1) r=N;\n\t\tif(b<=l||r<=a) return;\n\
    \t\tif(a<=l&&r<=b){\n\t\t\tHandler::setg2fg(x,lazy[k]);\n\t\t\treturn;\n\t\t}\n\
    \t\tpropagate(l,r,k);\n\t\tupdate(a,b,x,l,(l+r)/2,k*2);\n\t\tupdate(a,b,x,(l+r)/2,r,k*2+1);\n\
    \t\tval[k] = realvalue(k*2,l,(l+r)/2) + realvalue(k*2+1,(l+r)/2,r);\n\t}\n\tvoid\
    \ propagate(int l,int r,int k){\t//opr_child -> opr_parent * opr_child\t\tparent\
    \ after child\n\t\tHandler::setg2fg(lazy[k],lazy[k*2  ]);\n\t\tHandler::setg2fg(lazy[k],lazy[k*2+1]);\n\
    \t\tlazy[k] = opr_t::e();\n\t}\n};\n\ntemplate<class E, class Handler>\t\t//for\
    \ lazy segtree\nstruct HLdecomp{\n\tusing val_t = typename Handler::val_t;\n\t\
    using opr_t = typename Handler::opr_t;\n\tusing segtree = segtree_lazy<Handler>;\n\
    \n\tstatic const bool OnEdge = 0;\n\n\tvector<vector<E>> G;\n\tusing P = pair<int,int>;\n\
    \tvector<P> id;\t\t\t\t//id[v] = P(chain_id,pos_on_chain)\tpos\u306Ftop to bottom\n\
    \tvector<int> sz;\t\t\t\t//sz[v] = subtree_size\n\tvector<int> dep;\t\t\t//dep[v]\
    \ = depth\n\tvector<int> par;\t\t\t//par[v] = parent\n\tvector<int> top;\t\t\t\
    //id[v].fs \u306E\u4E00\u756A\u4E0A\n\n\tint C;\t//num of chains\n\tvector<vector<int>>\
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
    \t\t\td--;\n\t\t}\n\t\tassert(0);\n\t\treturn -1;\n\t}\n\tval_t query(int u,int\
    \ v){\t//[u,w) + [w,v]\t\t\tedge ver \u306A\u3089 [u,w) + (w,v]\n\t\tint w = lca(u,v);\n\
    \t\tval_t up,down;\n\n\t\t{\n\t\t\tfor(;id[u].fs!=id[w].fs; u = par[top[u]]){\n\
    \t\t\t\t//chains[c][l,r]\n\t\t\t\tint c = id[u].fs;\n\t\t\t\tint l = id[top[u]].sc;\n\
    \t\t\t\tint r = id[u].sc;\n\t\t\t\tval_t x = segs[c].query(l,r+1);\n\t\t\t\tup\
    \ = x + up;\n\t\t\t}\n\t\t\tint c = id[u].fs;\n\t\t\tint l = id[w].sc+1;\n\t\t\
    \tint r = id[u].sc;\n\t\t\tval_t x = segs[c].query(l,r+1);\n\t\t\tup = x + up;\n\
    \t\t}\n\t\t{\n\t\t\tu = v;\n\t\t\tfor(;id[u].fs!=id[w].fs; u = par[top[u]]){\n\
    \t\t\t\tint c = id[u].fs;\n\t\t\t\tint l = id[top[u]].sc;\n\t\t\t\tint r = id[u].sc;\n\
    \t\t\t\tval_t x = segs[c].query(l,r+1);\n\t\t\t\tdown = x + down;\n\t\t\t}\n\t\
    \t\tint c = id[u].fs;\n\t\t\tint l = id[w].sc + OnEdge;\n\t\t\tint r = id[u].sc;\n\
    \t\t\tval_t x = segs[c].query(l,r+1);\n\t\t\tdown = x + down;\n\t\t}\n\n\t\t//\
    \ ! reverse up !\n\t\treturn up + down;\n\t}\n\tvoid update(int u,int v,const\
    \ opr_t &x){\t//[u,w) + [w,v]\n\t\tint w = lca(u,v);\n\n\t\t{\n\t\t\tfor(;id[u].fs!=id[w].fs;\
    \ u = par[top[u]]){\n\t\t\t\t//chains[c][l,r]\n\t\t\t\tint c = id[u].fs;\n\t\t\
    \t\tint l = id[top[u]].sc;\n\t\t\t\tint r = id[u].sc;\n\t\t\t\tsegs[c].update(l,r+1,x);\n\
    \t\t\t}\n\t\t\tint c = id[u].fs;\n\t\t\tint l = id[w].sc+1;\n\t\t\tint r = id[u].sc;\n\
    \t\t\tsegs[c].update(l,r+1,x);\n\t\t}\n\t\t{\n\t\t\tu = v;\n\t\t\tfor(;id[u].fs!=id[w].fs;\
    \ u = par[top[u]]){\n\t\t\t\tint c = id[u].fs;\n\t\t\t\tint l = id[top[u]].sc;\n\
    \t\t\t\tint r = id[u].sc;\n\t\t\t\tsegs[c].update(l,r+1,x);\n\t\t\t}\n\t\t\tint\
    \ c = id[u].fs;\n\t\t\tint l = id[w].sc + OnEdge;\n\t\t\tint r = id[u].sc;\n\t\
    \t\tsegs[c].update(l,r+1,x);\n\t\t}\n\t}\n};\n\nstruct handler2{\n\t/*\n\t\trange\
    \ assign 0\u4EE5\u4E0A\n\t\trange sum\n\n\t\tval_t = int,+\t\t\tval[k]= +\n\t\t\
    opr_t(x) : y -> x\t\tlazy[k]=assign\n\n\t\tassign\u306F\u4E00\u7DD2\u306A\u306E\
    \u3067\u3001opr_t,getfg\u306F\u5909\u3048\u306A\u304F\u3066\u3044\u3044\n\t\t\u6C17\
    \u3065\u3044\u305F\u3093\u3067\u3059\u304C,act\u3068\u304B\u306Bl,r\u304C\u5FC5\
    \u8981\u306A\u30B1\u30FC\u30B9\u304C\u591A\u3059\u304E\u308B(sum\u7CFB\u3068\u304B\
    \u307B\u307C\u78BA\u5B9F\u306B\u5FC5\u8981)\u306E\u3067\u3001\u3082\u3046\u3053\
    \u3046\u3044\u3046\u306E\u306Fval_t\u306Bl,r\u3092\u7F6E\u304F\u3053\u3068\u306B\
    \u3057\u307E\u3059\n\t\t\u3068\u601D\u3063\u305F\u304C\u3001\u3084\u3063\u3071\
    \u308A\u3084\u3081\u3066\u3001l\u3068r\u3092\u9811\u5F35\u3063\u3066act\u306B\u6E21\
    \u3059\u3053\u3068\u306B\u3057\u305F\n\t\tgetfg\u3068\u304B\u306B\u3082\u5FC5\u8981\
    \u306B\u306A\u308B\u3068\u7D76\u671B\u611F\u304C\u5897\u3057\u305D\u3046\n\n\t\
    */\n\tstruct val_t{\n\t\tint x;\n\t\tval_t(){*this = e();}\n\t\tval_t(int x):x(x){}\n\
    \n\t\tconst static val_t e(){\n\t\t\treturn val_t(0);\n\t\t}\n\t\tval_t operator+(const\
    \ val_t &r) const {\n\t\t\treturn val_t(x+r.x);\n\t\t}\n\t\tfriend ostream& operator<<(ostream&\
    \ o,const val_t& d){return o<<d.x;}\n\t};\n\n\tstruct opr_t{\n\t\tint x;\n\t\t\
    opr_t(){*this = e();}\n\t\topr_t(int x):x(x){}\n\n\t\tconst static opr_t e(){\n\
    \t\t\treturn opr_t(-1);\n\t\t}\n\t\tfriend ostream& operator<<(ostream& o,const\
    \ opr_t& d){return o<<d.x;}\n\t};\n\n\tstatic void getfg(const opr_t &f, const\
    \ opr_t &g){\n\n\t}\n\t/*\n\t\t\u3082\u3057\u30B3\u30D4\u30FC\u30B3\u30B9\u30C8\
    \u3068\u304B\u304C\u6C17\u306B\u306A\u3063\u3066,\u3057\u304B\u3082\u697D\u306B\
    \u66F8\u3051\u308B\u306A\u3089setg2fg\u3092\u76F4\u63A5\u66F8\u304F\n\t\t\u305D\
    \u3046\u3058\u3083\u306A\u3044\u306A\u3089 g = getfg(f,g)\n\t*/\n\tstatic void\
    \ setg2fg(const opr_t &f, opr_t &g){\t//g -> fg\t\tf after g\n\t\tif(f.x != -1)\
    \ g.x = f.x;\n\t}\n\tstatic val_t act(const opr_t &f, const val_t &v,int k,int\
    \ l,int r){\t//assign f.x -> sum = \n\t\tif(f.x == -1) return v;\n\t\treturn val_t(f.x*(r-l));\n\
    \t}\n};\n\nstruct Edge{int to;};\n\nvoid unittest(){\n\tint N;\n\tcin>>N;\n\t\
    vector<vector<Edge>> G(N);\n\n\t//brute\n\tvector<vector<int>> d(N,vector<int>(N,1e9));\n\
    \trep(i,N) d[i][i] = 0;\n\n\n\trep(i,N-1){\n\t\tint x,y;\n\t\tcin>>x>>y;\n\t\t\
    G[x].pb({y});\n\t\tG[y].pb({x});\n\t\td[x][y] = d[y][x] = 1;\n\t}\n\trep(i,N)\
    \ rep(j,N) rep(k,N) chmin(d[j][k],d[j][i]+d[i][k]);\n\tHLdecomp<Edge,handler2>\
    \ HLD(G);\n\n\tvector<int> a(N);\n\n\twhile(true){\n\t\tchar c;\n\t\tcin>>c;\n\
    \t\tif(c=='q'){\n\t\t\tint u,v;\n\t\t\tcin>>u>>v;\n\t\t\tint res = HLD.query(u,v).x;\n\
    \t\t\tint brute = 0;\n\t\t\trep(i,N) if(d[u][i]+d[i][v]==d[u][v]) brute += a[i];\n\
    \t\t\tassert(res == brute);\n\t\t}else{\n\t\t\tint u,v,c;\n\t\t\tcin>>u>>v>>c;\n\
    \t\t\tHLD.update(u,v,c);\n\t\t\trep(i,N) if(d[u][i]+d[i][v]==d[u][v]) a[i] = c;\n\
    \t\t}\n\t}\n}\n\nint main(){\n\tunittest();\n}\n"
  code: "/*\n\tHL-decomposition for lazy\n\tlazy segtree \u3068\u540C\u3058\u3053\u3068\
    \u3092\u6728\u306E(\u9802\u70B9\u96C6\u5408 / \u8FBA\u96C6\u5408)\u306B\u5BFE\u3057\
    \u3066\u3067\u304D\u308B\n\t**** OnEdge **** \u3068\u3044\u3046 bool \u3092\u5909\
    \u3048\u308B\u3060\u3051\u3067\u4F7F\u3048\u308B\n\n\tassumption :\n\t\ta*b*..*c*d\
    \ \u304B\u3089 d*c*..*b*a \u304C\u7C21\u5358\u306B\u8A08\u7B97\u3067\u304D\u308B\
    \ (up \u3092 reverse \u3059\u308B\u5FC5\u8981\u304C\u3042\u308B)\n\t\t\t\u305D\
    \u3046\u3067\u306A\u3044\u5834\u5408\u3001\u4E0A\u5411\u304D\u3068\u4E0B\u5411\
    \u304D\u306Esegtree\u3092\u4E21\u65B9\u4FDD\u3064\u5FC5\u8981\u304C\u3042\u308B\
    (\u4ECA\u306F\u4E0B\u5411\u304D\u3060\u3051)\n\n\tusage : \n\t\tOnEdge \u5909\u3048\
    \u308B\n\t\tvector<vector<Edge>> G \u3092constructor\u306B\u6E21\u3059\n\t\tquery(u,val_t)\n\
    \t\tupdate(u,v,opr_t)\n\n\tverified at AGC14/E\n\t\t\t\tOpenCup/9922/E.cpp\n*/\n\
    \ntemplate<class Handler>\nstruct segtree_lazy{\n\tusing val_t = typename Handler::val_t;\n\
    \tusing opr_t = typename Handler::opr_t;\n\tint N;\n\tvector<val_t> val;\n\tvector<opr_t>\
    \ lazy;\n\tsegtree_lazy(){}\n\tsegtree_lazy(int n){init(n);}\n\tsegtree_lazy(const\
    \ vector<val_t>& vc){init(vc);}\n\tvoid init(int n){\n\t\tN=1;\n\t\twhile(N<n)\
    \ N*=2;\n\t\tval .assign(N*2,val_t::e());\n\t\tlazy.assign(N*2,opr_t::e());\n\t\
    }\n\tvoid init(const vector<val_t>& vc){\n\t\tint n = vc.size();\n\t\tN=1;\n\t\
    \twhile(N<n) N*=2;\n\t\tval .assign(N*2,val_t::e());\n\t\trep(i,n) val[i+N] =\
    \ vc[i];\n\t\tfor(int i=N-1;i>0;i--) val[i] = val[i*2] + val[i*2+1];\n\t\tlazy.assign(N*2,opr_t::e());\n\
    \t}\n\tval_t realvalue(int k,int l,int r){\n//\t\treturn Handler::act(lazy[k],val[k]);\n\
    \t\treturn Handler::act(lazy[k],val[k],k,l,r);\n\t}\n\n\tval_t query(int a,int\
    \ b,int l=0,int r=-1,int k=1){\t//query_calc\n//\t\tif(k==1) printf(\"query [%d,%d)\\\
    n\",a,b);\n\t\tif(r==-1) r=N;\n\t\tif(b<=l||r<=a) return val_t::e();\n\t\tif(a<=l&&r<=b)\
    \ return realvalue(k,l,r);\n\t\tpropagate(l,r,k);\n\t\tval_t ret = query(a,b,l,(l+r)/2,k*2)\
    \ + query(a,b,(l+r)/2,r,k*2+1);\n\t\tval[k] = realvalue(k*2,l,(l+r)/2) + realvalue(k*2+1,(l+r)/2,r);\n\
    \t\treturn ret;\n\n\t}\n//\tval_t query_leftassoc(){}\n\tvoid update(int a,int\
    \ b,const opr_t &x,int l=0,int r=-1,int k=1){\t//query_update\n//\t\tif(k==1)\
    \ printf(\"update [%d,%d)\\n\",a,b);\n\t\tif(r==-1) r=N;\n\t\tif(b<=l||r<=a) return;\n\
    \t\tif(a<=l&&r<=b){\n\t\t\tHandler::setg2fg(x,lazy[k]);\n\t\t\treturn;\n\t\t}\n\
    \t\tpropagate(l,r,k);\n\t\tupdate(a,b,x,l,(l+r)/2,k*2);\n\t\tupdate(a,b,x,(l+r)/2,r,k*2+1);\n\
    \t\tval[k] = realvalue(k*2,l,(l+r)/2) + realvalue(k*2+1,(l+r)/2,r);\n\t}\n\tvoid\
    \ propagate(int l,int r,int k){\t//opr_child -> opr_parent * opr_child\t\tparent\
    \ after child\n\t\tHandler::setg2fg(lazy[k],lazy[k*2  ]);\n\t\tHandler::setg2fg(lazy[k],lazy[k*2+1]);\n\
    \t\tlazy[k] = opr_t::e();\n\t}\n};\n\ntemplate<class E, class Handler>\t\t//for\
    \ lazy segtree\nstruct HLdecomp{\n\tusing val_t = typename Handler::val_t;\n\t\
    using opr_t = typename Handler::opr_t;\n\tusing segtree = segtree_lazy<Handler>;\n\
    \n\tstatic const bool OnEdge = 0;\n\n\tvector<vector<E>> G;\n\tusing P = pair<int,int>;\n\
    \tvector<P> id;\t\t\t\t//id[v] = P(chain_id,pos_on_chain)\tpos\u306Ftop to bottom\n\
    \tvector<int> sz;\t\t\t\t//sz[v] = subtree_size\n\tvector<int> dep;\t\t\t//dep[v]\
    \ = depth\n\tvector<int> par;\t\t\t//par[v] = parent\n\tvector<int> top;\t\t\t\
    //id[v].fs \u306E\u4E00\u756A\u4E0A\n\n\tint C;\t//num of chains\n\tvector<vector<int>>\
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
    \t\t\td--;\n\t\t}\n\t\tassert(0);\n\t\treturn -1;\n\t}\n\tval_t query(int u,int\
    \ v){\t//[u,w) + [w,v]\t\t\tedge ver \u306A\u3089 [u,w) + (w,v]\n\t\tint w = lca(u,v);\n\
    \t\tval_t up,down;\n\n\t\t{\n\t\t\tfor(;id[u].fs!=id[w].fs; u = par[top[u]]){\n\
    \t\t\t\t//chains[c][l,r]\n\t\t\t\tint c = id[u].fs;\n\t\t\t\tint l = id[top[u]].sc;\n\
    \t\t\t\tint r = id[u].sc;\n\t\t\t\tval_t x = segs[c].query(l,r+1);\n\t\t\t\tup\
    \ = x + up;\n\t\t\t}\n\t\t\tint c = id[u].fs;\n\t\t\tint l = id[w].sc+1;\n\t\t\
    \tint r = id[u].sc;\n\t\t\tval_t x = segs[c].query(l,r+1);\n\t\t\tup = x + up;\n\
    \t\t}\n\t\t{\n\t\t\tu = v;\n\t\t\tfor(;id[u].fs!=id[w].fs; u = par[top[u]]){\n\
    \t\t\t\tint c = id[u].fs;\n\t\t\t\tint l = id[top[u]].sc;\n\t\t\t\tint r = id[u].sc;\n\
    \t\t\t\tval_t x = segs[c].query(l,r+1);\n\t\t\t\tdown = x + down;\n\t\t\t}\n\t\
    \t\tint c = id[u].fs;\n\t\t\tint l = id[w].sc + OnEdge;\n\t\t\tint r = id[u].sc;\n\
    \t\t\tval_t x = segs[c].query(l,r+1);\n\t\t\tdown = x + down;\n\t\t}\n\n\t\t//\
    \ ! reverse up !\n\t\treturn up + down;\n\t}\n\tvoid update(int u,int v,const\
    \ opr_t &x){\t//[u,w) + [w,v]\n\t\tint w = lca(u,v);\n\n\t\t{\n\t\t\tfor(;id[u].fs!=id[w].fs;\
    \ u = par[top[u]]){\n\t\t\t\t//chains[c][l,r]\n\t\t\t\tint c = id[u].fs;\n\t\t\
    \t\tint l = id[top[u]].sc;\n\t\t\t\tint r = id[u].sc;\n\t\t\t\tsegs[c].update(l,r+1,x);\n\
    \t\t\t}\n\t\t\tint c = id[u].fs;\n\t\t\tint l = id[w].sc+1;\n\t\t\tint r = id[u].sc;\n\
    \t\t\tsegs[c].update(l,r+1,x);\n\t\t}\n\t\t{\n\t\t\tu = v;\n\t\t\tfor(;id[u].fs!=id[w].fs;\
    \ u = par[top[u]]){\n\t\t\t\tint c = id[u].fs;\n\t\t\t\tint l = id[top[u]].sc;\n\
    \t\t\t\tint r = id[u].sc;\n\t\t\t\tsegs[c].update(l,r+1,x);\n\t\t\t}\n\t\t\tint\
    \ c = id[u].fs;\n\t\t\tint l = id[w].sc + OnEdge;\n\t\t\tint r = id[u].sc;\n\t\
    \t\tsegs[c].update(l,r+1,x);\n\t\t}\n\t}\n};\n\nstruct handler2{\n\t/*\n\t\trange\
    \ assign 0\u4EE5\u4E0A\n\t\trange sum\n\n\t\tval_t = int,+\t\t\tval[k]= +\n\t\t\
    opr_t(x) : y -> x\t\tlazy[k]=assign\n\n\t\tassign\u306F\u4E00\u7DD2\u306A\u306E\
    \u3067\u3001opr_t,getfg\u306F\u5909\u3048\u306A\u304F\u3066\u3044\u3044\n\t\t\u6C17\
    \u3065\u3044\u305F\u3093\u3067\u3059\u304C,act\u3068\u304B\u306Bl,r\u304C\u5FC5\
    \u8981\u306A\u30B1\u30FC\u30B9\u304C\u591A\u3059\u304E\u308B(sum\u7CFB\u3068\u304B\
    \u307B\u307C\u78BA\u5B9F\u306B\u5FC5\u8981)\u306E\u3067\u3001\u3082\u3046\u3053\
    \u3046\u3044\u3046\u306E\u306Fval_t\u306Bl,r\u3092\u7F6E\u304F\u3053\u3068\u306B\
    \u3057\u307E\u3059\n\t\t\u3068\u601D\u3063\u305F\u304C\u3001\u3084\u3063\u3071\
    \u308A\u3084\u3081\u3066\u3001l\u3068r\u3092\u9811\u5F35\u3063\u3066act\u306B\u6E21\
    \u3059\u3053\u3068\u306B\u3057\u305F\n\t\tgetfg\u3068\u304B\u306B\u3082\u5FC5\u8981\
    \u306B\u306A\u308B\u3068\u7D76\u671B\u611F\u304C\u5897\u3057\u305D\u3046\n\n\t\
    */\n\tstruct val_t{\n\t\tint x;\n\t\tval_t(){*this = e();}\n\t\tval_t(int x):x(x){}\n\
    \n\t\tconst static val_t e(){\n\t\t\treturn val_t(0);\n\t\t}\n\t\tval_t operator+(const\
    \ val_t &r) const {\n\t\t\treturn val_t(x+r.x);\n\t\t}\n\t\tfriend ostream& operator<<(ostream&\
    \ o,const val_t& d){return o<<d.x;}\n\t};\n\n\tstruct opr_t{\n\t\tint x;\n\t\t\
    opr_t(){*this = e();}\n\t\topr_t(int x):x(x){}\n\n\t\tconst static opr_t e(){\n\
    \t\t\treturn opr_t(-1);\n\t\t}\n\t\tfriend ostream& operator<<(ostream& o,const\
    \ opr_t& d){return o<<d.x;}\n\t};\n\n\tstatic void getfg(const opr_t &f, const\
    \ opr_t &g){\n\n\t}\n\t/*\n\t\t\u3082\u3057\u30B3\u30D4\u30FC\u30B3\u30B9\u30C8\
    \u3068\u304B\u304C\u6C17\u306B\u306A\u3063\u3066,\u3057\u304B\u3082\u697D\u306B\
    \u66F8\u3051\u308B\u306A\u3089setg2fg\u3092\u76F4\u63A5\u66F8\u304F\n\t\t\u305D\
    \u3046\u3058\u3083\u306A\u3044\u306A\u3089 g = getfg(f,g)\n\t*/\n\tstatic void\
    \ setg2fg(const opr_t &f, opr_t &g){\t//g -> fg\t\tf after g\n\t\tif(f.x != -1)\
    \ g.x = f.x;\n\t}\n\tstatic val_t act(const opr_t &f, const val_t &v,int k,int\
    \ l,int r){\t//assign f.x -> sum = \n\t\tif(f.x == -1) return v;\n\t\treturn val_t(f.x*(r-l));\n\
    \t}\n};\n\nstruct Edge{int to;};\n\nvoid unittest(){\n\tint N;\n\tcin>>N;\n\t\
    vector<vector<Edge>> G(N);\n\n\t//brute\n\tvector<vector<int>> d(N,vector<int>(N,1e9));\n\
    \trep(i,N) d[i][i] = 0;\n\n\n\trep(i,N-1){\n\t\tint x,y;\n\t\tcin>>x>>y;\n\t\t\
    G[x].pb({y});\n\t\tG[y].pb({x});\n\t\td[x][y] = d[y][x] = 1;\n\t}\n\trep(i,N)\
    \ rep(j,N) rep(k,N) chmin(d[j][k],d[j][i]+d[i][k]);\n\tHLdecomp<Edge,handler2>\
    \ HLD(G);\n\n\tvector<int> a(N);\n\n\twhile(true){\n\t\tchar c;\n\t\tcin>>c;\n\
    \t\tif(c=='q'){\n\t\t\tint u,v;\n\t\t\tcin>>u>>v;\n\t\t\tint res = HLD.query(u,v).x;\n\
    \t\t\tint brute = 0;\n\t\t\trep(i,N) if(d[u][i]+d[i][v]==d[u][v]) brute += a[i];\n\
    \t\t\tassert(res == brute);\n\t\t}else{\n\t\t\tint u,v,c;\n\t\t\tcin>>u>>v>>c;\n\
    \t\t\tHLD.update(u,v,c);\n\t\t\trep(i,N) if(d[u][i]+d[i][v]==d[u][v]) a[i] = c;\n\
    \t\t}\n\t}\n}\n\nint main(){\n\tunittest();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: data structure/HLdecomp_lazy.cpp
  requiredBy: []
  timestamp: '2019-08-22 16:18:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/HLdecomp_lazy.cpp
layout: document
redirect_from:
- /library/data structure/HLdecomp_lazy.cpp
- /library/data structure/HLdecomp_lazy.cpp.html
title: data structure/HLdecomp_lazy.cpp
---
