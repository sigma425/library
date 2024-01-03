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
  bundledCode: "#line 1 \"ds/HL_old.cpp\"\n//AOJ2450\u3092\u305D\u306E\u307E\u307E\
    \u30B3\u30D4\u30FC\u3057\u305F\u3060\u3051\n#include <bits/stdc++.h>\n#define\
    \ int long long\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n)\
    \ for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n#define pb push_back\n\
    #define fs first\n#define sc second\n#define show(x) cout << #x << \" = \" <<\
    \ x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing\
    \ namespace std;\nconst int MAX_N=200000;\nint N,Q;\nint par[MAX_N][18];\nint\
    \ p[MAX_N];\nint depth[MAX_N];\n\nvoid genlca(){\n\trep(i,N) par[i][0]=p[i];\n\
    \tfor(int i=1;i<=17;i++){\n\t\trep(v,N){\n\t\t\tif(par[v][i-1]==-1) par[v][i]=-1;\n\
    \t\t\telse par[v][i]=par[par[v][i-1]][i-1];\n\t\t}\n\t}\n}\ntypedef pair<int,int>\
    \ P;\nP lca(int u,int v){\n\tbool swapped=0;\n\tif(depth[u]<depth[v]){\n\t\tswap(u,v);\n\
    \t\tswapped=1;\n\t}\n\tint d=depth[u]-depth[v];\n\trep(i,18){\n\t\tif((d>>i)&1)\
    \ u=par[u][i];\n\t}\n\tif(u==v) return P(u,-1);\n\tfor(int i=18-1;i>=0;i--){\n\
    \t\tif(par[u][i]!=par[v][i]){\n\t\t\tu=par[u][i];\n\t\t\tv=par[v][i];\n\t\t}\n\
    \t}\n\tif(!swapped) return P(par[v][0],v);\n\telse return P(par[v][0],u);\n}\n\
    \nstruct Node{\n\tint mx,l,r,sum;\n\tNode(){mx=-1e9,l=-1e9,r=-1e9,sum=0;}\n};\n\
    Node merge(Node a,Node b){\n\tNode ret;\n\tret.sum=a.sum+b.sum;\n\tret.l=max(a.l,a.sum+b.l);\n\
    \tret.r=max(b.r,b.sum+a.r);\n\tret.mx=max(a.r+b.l,max(a.mx,b.mx));\n\treturn ret;\n\
    }\nNode flip(Node a){\n\tswap(a.l,a.r);\n\treturn a;\n}\nvoid shownode(Node a){\n\
    \tprintf(\"l=%d,r=%d,mx=%d,sum=%d\\n\",a.l,a.r,a.mx,a.sum);\n}\nstruct segtree{\n\
    \tint getp2(int x){\n\t\tint p=1;\n\t\twhile(p<x) p*=2;\n\t\treturn p;\n\t}\n\t\
    segtree(int N):N(N),p2(getp2(N)),seg(p2*2),same(p2*2),val(p2*2) {}\n\tint N;\n\
    \tint p2;\n\tvector<Node> seg;\n\tvector<bool> same;\n\tvector<int> val;\n\tvoid\
    \ dosame(int k,int v,int len){\n\t\tif(len==0) return;\n\t\tsame[k]=1,val[k]=v;\n\
    \t\t// show(k);\n\t\t// show(v);\n\t\t// show(len);\n\t\t// puts(\"\");\n\t\t\
    if(v>=0) seg[k].l=seg[k].r=seg[k].mx=seg[k].sum=v*len;\n\t\telse seg[k].l=seg[k].r=seg[k].mx=v,seg[k].sum=v*len;\n\
    //\t\telse seg[k].l=seg[k].r=seg[k].mx=v,seg[k].sum=v*len;\n\t}\n\tNode calc(int\
    \ a,int b,int l,int r,int k){\n\t\tif(r<=a||b<=l) return Node();\n\t\tif(a<=l&&r<=b)\
    \ return seg[k];\n\t\tif(same[k]){\n\t\t\tdosame(k*2,val[k],(r-l)/2);\n\t\t\t\
    dosame(k*2+1,val[k],(r-l)/2);\n\t\t}\n\t\treturn merge(calc(a,b,l,(l+r)/2,k*2),calc(a,b,(l+r)/2,r,k*2+1));\n\
    \t}\n\tNode calc(int a,int b){\n\t\treturn calc(a,b,0,p2,1);\n\t}\n\tvoid change(int\
    \ a,int b,int l,int r,int k,int v){\n\t\tif(r<=a||b<=l) return;\n\t\tif(a<=l&&r<=b){\n\
    \t\t\tdosame(k,v,r-l);\n\t\t\treturn;\n\t\t}\n\t\tif(same[k]){\n\t\t\tdosame(k*2,val[k],(r-l)/2);\n\
    \t\t\tdosame(k*2+1,val[k],(r-l)/2);\n\t\t}\n\t\tsame[k]=0;\n\t\tchange(a,b,l,(l+r)/2,k*2,v);\n\
    \t\tchange(a,b,(l+r)/2,r,k*2+1,v);\n\t\tseg[k]=merge(seg[k*2],seg[k*2+1]);\n\t\
    }\n\tvoid change(int a,int b,int v){\n\t\tchange(a,b,0,p2,1,v);\n\t}\n};\n\nint\
    \ w[MAX_N];\nint topo[MAX_N];\nint sz[MAX_N];\nint hchild[MAX_N];\nint chainid[MAX_N];\t\
    //vertex->chainid\nint top[MAX_N];\t//chainid->top\nvector<int> G[MAX_N];\nvoid\
    \ bfs(int s){\n\tbool vis[MAX_N]={};\n\tqueue<int> que;\n\tque.push(s);\n\tint\
    \ cnt=0;\n\twhile(!que.empty()){\n\t\tint t=que.front();\n\t\tque.pop();\n\t\t\
    vis[t]=1;\n\t\ttopo[cnt++]=t;\n\t\trep(i,G[t].size()){\n\t\t\tint v=G[t][i];\n\
    \t\t\tif(!vis[v]) que.push(v);\n\t\t\telse{\n\t\t\t\tp[t]=v;\n\t\t\t\tG[t].erase(G[t].begin()+i);\n\
    \t\t\t\ti--;\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t}\n\t}\n}\nvoid dfs(int v){\n\t\
    sz[v]=1;\n\tint id=-1;\n\tfor(int u:G[v]){\n\t\tsz[v]+=sz[u];\n\t\tif(id<0||sz[u]>sz[id])\
    \ id=u;\n\t}\n\thchild[v]=id;\n}\n\nvector<segtree> chains;\n\nNode calcall(int\
    \ T,int B){\n\tNode ret;\n\twhile(true){\n\t\tsegtree &seg=chains[chainid[B]];\n\
    \t\tint t=top[chainid[B]];\n\t\tif(depth[t]<=depth[T]){\n\t\t\tint d1=depth[B]-depth[t];\n\
    \t\t\tint d2=depth[T]-depth[t];\n\t\t\tret=merge(ret,seg.calc(seg.N-1-d1,seg.N-d2));\n\
    /*\t\t\tshow(t);\n\t\t\tshow(B);\n\t\t\tshow(T);\n\t\t\tshow(d1);\n\t\t\tshow(d2);\n\
    \t\t\tshow(N-1-d1);\n\t\t\tshow(seg.N-d2);*/\n\t\t\treturn ret;\n\t\t}\n\t\tint\
    \ d=depth[B]-depth[t];\n\t\tret=merge(ret,seg.calc(seg.N-1-d,seg.N));\n\t\tB=p[t];\n\
    \t}\n}\nvoid changeall(int T,int B,int v){\n\twhile(true){\n\t\tsegtree &seg=chains[chainid[B]];\n\
    \t\tint t=top[chainid[B]];\n\t\tif(depth[t]<=depth[T]){\n\t\t\tint d1=depth[B]-depth[t];\n\
    \t\t\tint d2=depth[T]-depth[t];\n\t\t\tseg.change(seg.N-1-d1,seg.N-d2,v);\n\t\t\
    \treturn;\n\t\t}\n\t\tint d=depth[B]-depth[t];\n\t\tseg.change(seg.N-1-d,seg.N,v);\n\
    \t\tB=p[t];\n\t}\n}\nsigned main(){\n\tcin>>N>>Q;\n\trep(i,N) cin>>w[i];\n\trep(i,N-1){\n\
    \t\tint a,b;\n\t\tcin>>a>>b;\n\t\ta--,b--;\n\t\tG[a].pb(b);\n\t\tG[b].pb(a);\n\
    \t}\n\tbfs(0);\n//\trep(i,N) show(topo[i]);\n\tfor(int i=N-1;i>=0;i--) dfs(topo[i]);\n\
    \trep1(i,N-1){\n\t\tint v=topo[i];\n\t\tdepth[v]=depth[p[v]]+1;\n\t}\n\tp[0]=-1;\n\
    //\trep(i,N) show(p[i]);\n\tint C=0;\n\tbool vis[MAX_N]={};\n\trep(i,N){\n\t\t\
    int v=topo[i];\n\t\tif(!vis[v]){\n\t\t\ttop[C]=v;\n\t\t\tvector<int> vc;\n\t\t\
    \tint u=v;\n\t\t\twhile(u>=0){\n\t\t\t\tvc.pb(u);\n\t\t\t\tvis[u]=1;\n\t\t\t\t\
    chainid[u]=C;\n\t\t\t\tu=hchild[u];\n\t\t\t}\n\t\t\tint Nc=vc.size();\n\t\t\t\
    segtree seg(Nc);\n//\t\t\tshow(Nc);\n\t\t\trep(j,Nc){\n\t\t\t\tseg.change(j,j+1,w[\
    \ vc[Nc-1-j] ]);\n//\t\t\t\tshow(j);\n//\t\t\t\tshow(vc[Nc-1-j]);\n//\t\t\t\t\
    show(w [vc[Nc-1-j] ]);\n\n\t\t\t}\n\t\t\tchains.pb(seg);\n\t\t\tC++;\n\t\t}\n\t\
    }\n//\tshow(C);\n\tgenlca();\n//\trep(i,N) show(depth[i]);\n//\tshow(p.fs);\n\
    //\tshow(p.sc);\n\trep(tt,Q){\n\t\tint t,a,b,c;\n\t\tcin>>t>>a>>b>>c;\n\t\ta--,b--;\n\
    \t\tP p=lca(a,b);\n//\t\tshow(p.fs);\n//\t\tshow(p.sc);\n\t\tif(t%2){\n\t\t\t\
    if(p.sc==-1){\n\t\t\t\tif(b==p.fs) swap(a,b);\n\t\t\t\tchangeall(a,b,c);\n\t\t\
    \t}else{\n\t\t\t\tchangeall(p.fs,a,c);\n\t\t\t\tchangeall(p.sc,b,c);\n\t\t\t}\n\
    \t\t}else{\n\t\t\tif(p.sc==-1){\n\t\t\t\tif(b==p.fs) swap(a,b);\n//\t\t\t\tshow(a);\n\
    //\t\t\t\tshow(b);\n//\t\t\t\tshownode(calcall(a,b));\n\t\t\t\tcout<<calcall(a,b).mx<<endl;\n\
    \t\t\t}else{\n\t\t\t\tNode x=calcall(p.fs,a);\n\t\t\t\tNode y=calcall(p.sc,b);\n\
    //\t\t\t\tshow(a);\n//\t\t\t\tshow(p.fs);\n//\t\t\t\tshownode(x);\n//\t\t\t\t\
    show(b);\n//\t\t\t\tshow(p.sc);\n//\t\t\t\tshownode(y);\n\t\t\t\tcout<<merge(x,flip(y)).mx<<endl;\n\
    \t\t\t}\n\t\t}\n\t}\n}\n"
  code: "//AOJ2450\u3092\u305D\u306E\u307E\u307E\u30B3\u30D4\u30FC\u3057\u305F\u3060\
    \u3051\n#include <bits/stdc++.h>\n#define int long long\n#define rep(i,n) for(int\
    \ i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define\
    \ all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define sc\
    \ second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\nconst int MAX_N=200000;\n\
    int N,Q;\nint par[MAX_N][18];\nint p[MAX_N];\nint depth[MAX_N];\n\nvoid genlca(){\n\
    \trep(i,N) par[i][0]=p[i];\n\tfor(int i=1;i<=17;i++){\n\t\trep(v,N){\n\t\t\tif(par[v][i-1]==-1)\
    \ par[v][i]=-1;\n\t\t\telse par[v][i]=par[par[v][i-1]][i-1];\n\t\t}\n\t}\n}\n\
    typedef pair<int,int> P;\nP lca(int u,int v){\n\tbool swapped=0;\n\tif(depth[u]<depth[v]){\n\
    \t\tswap(u,v);\n\t\tswapped=1;\n\t}\n\tint d=depth[u]-depth[v];\n\trep(i,18){\n\
    \t\tif((d>>i)&1) u=par[u][i];\n\t}\n\tif(u==v) return P(u,-1);\n\tfor(int i=18-1;i>=0;i--){\n\
    \t\tif(par[u][i]!=par[v][i]){\n\t\t\tu=par[u][i];\n\t\t\tv=par[v][i];\n\t\t}\n\
    \t}\n\tif(!swapped) return P(par[v][0],v);\n\telse return P(par[v][0],u);\n}\n\
    \nstruct Node{\n\tint mx,l,r,sum;\n\tNode(){mx=-1e9,l=-1e9,r=-1e9,sum=0;}\n};\n\
    Node merge(Node a,Node b){\n\tNode ret;\n\tret.sum=a.sum+b.sum;\n\tret.l=max(a.l,a.sum+b.l);\n\
    \tret.r=max(b.r,b.sum+a.r);\n\tret.mx=max(a.r+b.l,max(a.mx,b.mx));\n\treturn ret;\n\
    }\nNode flip(Node a){\n\tswap(a.l,a.r);\n\treturn a;\n}\nvoid shownode(Node a){\n\
    \tprintf(\"l=%d,r=%d,mx=%d,sum=%d\\n\",a.l,a.r,a.mx,a.sum);\n}\nstruct segtree{\n\
    \tint getp2(int x){\n\t\tint p=1;\n\t\twhile(p<x) p*=2;\n\t\treturn p;\n\t}\n\t\
    segtree(int N):N(N),p2(getp2(N)),seg(p2*2),same(p2*2),val(p2*2) {}\n\tint N;\n\
    \tint p2;\n\tvector<Node> seg;\n\tvector<bool> same;\n\tvector<int> val;\n\tvoid\
    \ dosame(int k,int v,int len){\n\t\tif(len==0) return;\n\t\tsame[k]=1,val[k]=v;\n\
    \t\t// show(k);\n\t\t// show(v);\n\t\t// show(len);\n\t\t// puts(\"\");\n\t\t\
    if(v>=0) seg[k].l=seg[k].r=seg[k].mx=seg[k].sum=v*len;\n\t\telse seg[k].l=seg[k].r=seg[k].mx=v,seg[k].sum=v*len;\n\
    //\t\telse seg[k].l=seg[k].r=seg[k].mx=v,seg[k].sum=v*len;\n\t}\n\tNode calc(int\
    \ a,int b,int l,int r,int k){\n\t\tif(r<=a||b<=l) return Node();\n\t\tif(a<=l&&r<=b)\
    \ return seg[k];\n\t\tif(same[k]){\n\t\t\tdosame(k*2,val[k],(r-l)/2);\n\t\t\t\
    dosame(k*2+1,val[k],(r-l)/2);\n\t\t}\n\t\treturn merge(calc(a,b,l,(l+r)/2,k*2),calc(a,b,(l+r)/2,r,k*2+1));\n\
    \t}\n\tNode calc(int a,int b){\n\t\treturn calc(a,b,0,p2,1);\n\t}\n\tvoid change(int\
    \ a,int b,int l,int r,int k,int v){\n\t\tif(r<=a||b<=l) return;\n\t\tif(a<=l&&r<=b){\n\
    \t\t\tdosame(k,v,r-l);\n\t\t\treturn;\n\t\t}\n\t\tif(same[k]){\n\t\t\tdosame(k*2,val[k],(r-l)/2);\n\
    \t\t\tdosame(k*2+1,val[k],(r-l)/2);\n\t\t}\n\t\tsame[k]=0;\n\t\tchange(a,b,l,(l+r)/2,k*2,v);\n\
    \t\tchange(a,b,(l+r)/2,r,k*2+1,v);\n\t\tseg[k]=merge(seg[k*2],seg[k*2+1]);\n\t\
    }\n\tvoid change(int a,int b,int v){\n\t\tchange(a,b,0,p2,1,v);\n\t}\n};\n\nint\
    \ w[MAX_N];\nint topo[MAX_N];\nint sz[MAX_N];\nint hchild[MAX_N];\nint chainid[MAX_N];\t\
    //vertex->chainid\nint top[MAX_N];\t//chainid->top\nvector<int> G[MAX_N];\nvoid\
    \ bfs(int s){\n\tbool vis[MAX_N]={};\n\tqueue<int> que;\n\tque.push(s);\n\tint\
    \ cnt=0;\n\twhile(!que.empty()){\n\t\tint t=que.front();\n\t\tque.pop();\n\t\t\
    vis[t]=1;\n\t\ttopo[cnt++]=t;\n\t\trep(i,G[t].size()){\n\t\t\tint v=G[t][i];\n\
    \t\t\tif(!vis[v]) que.push(v);\n\t\t\telse{\n\t\t\t\tp[t]=v;\n\t\t\t\tG[t].erase(G[t].begin()+i);\n\
    \t\t\t\ti--;\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t}\n\t}\n}\nvoid dfs(int v){\n\t\
    sz[v]=1;\n\tint id=-1;\n\tfor(int u:G[v]){\n\t\tsz[v]+=sz[u];\n\t\tif(id<0||sz[u]>sz[id])\
    \ id=u;\n\t}\n\thchild[v]=id;\n}\n\nvector<segtree> chains;\n\nNode calcall(int\
    \ T,int B){\n\tNode ret;\n\twhile(true){\n\t\tsegtree &seg=chains[chainid[B]];\n\
    \t\tint t=top[chainid[B]];\n\t\tif(depth[t]<=depth[T]){\n\t\t\tint d1=depth[B]-depth[t];\n\
    \t\t\tint d2=depth[T]-depth[t];\n\t\t\tret=merge(ret,seg.calc(seg.N-1-d1,seg.N-d2));\n\
    /*\t\t\tshow(t);\n\t\t\tshow(B);\n\t\t\tshow(T);\n\t\t\tshow(d1);\n\t\t\tshow(d2);\n\
    \t\t\tshow(N-1-d1);\n\t\t\tshow(seg.N-d2);*/\n\t\t\treturn ret;\n\t\t}\n\t\tint\
    \ d=depth[B]-depth[t];\n\t\tret=merge(ret,seg.calc(seg.N-1-d,seg.N));\n\t\tB=p[t];\n\
    \t}\n}\nvoid changeall(int T,int B,int v){\n\twhile(true){\n\t\tsegtree &seg=chains[chainid[B]];\n\
    \t\tint t=top[chainid[B]];\n\t\tif(depth[t]<=depth[T]){\n\t\t\tint d1=depth[B]-depth[t];\n\
    \t\t\tint d2=depth[T]-depth[t];\n\t\t\tseg.change(seg.N-1-d1,seg.N-d2,v);\n\t\t\
    \treturn;\n\t\t}\n\t\tint d=depth[B]-depth[t];\n\t\tseg.change(seg.N-1-d,seg.N,v);\n\
    \t\tB=p[t];\n\t}\n}\nsigned main(){\n\tcin>>N>>Q;\n\trep(i,N) cin>>w[i];\n\trep(i,N-1){\n\
    \t\tint a,b;\n\t\tcin>>a>>b;\n\t\ta--,b--;\n\t\tG[a].pb(b);\n\t\tG[b].pb(a);\n\
    \t}\n\tbfs(0);\n//\trep(i,N) show(topo[i]);\n\tfor(int i=N-1;i>=0;i--) dfs(topo[i]);\n\
    \trep1(i,N-1){\n\t\tint v=topo[i];\n\t\tdepth[v]=depth[p[v]]+1;\n\t}\n\tp[0]=-1;\n\
    //\trep(i,N) show(p[i]);\n\tint C=0;\n\tbool vis[MAX_N]={};\n\trep(i,N){\n\t\t\
    int v=topo[i];\n\t\tif(!vis[v]){\n\t\t\ttop[C]=v;\n\t\t\tvector<int> vc;\n\t\t\
    \tint u=v;\n\t\t\twhile(u>=0){\n\t\t\t\tvc.pb(u);\n\t\t\t\tvis[u]=1;\n\t\t\t\t\
    chainid[u]=C;\n\t\t\t\tu=hchild[u];\n\t\t\t}\n\t\t\tint Nc=vc.size();\n\t\t\t\
    segtree seg(Nc);\n//\t\t\tshow(Nc);\n\t\t\trep(j,Nc){\n\t\t\t\tseg.change(j,j+1,w[\
    \ vc[Nc-1-j] ]);\n//\t\t\t\tshow(j);\n//\t\t\t\tshow(vc[Nc-1-j]);\n//\t\t\t\t\
    show(w [vc[Nc-1-j] ]);\n\n\t\t\t}\n\t\t\tchains.pb(seg);\n\t\t\tC++;\n\t\t}\n\t\
    }\n//\tshow(C);\n\tgenlca();\n//\trep(i,N) show(depth[i]);\n//\tshow(p.fs);\n\
    //\tshow(p.sc);\n\trep(tt,Q){\n\t\tint t,a,b,c;\n\t\tcin>>t>>a>>b>>c;\n\t\ta--,b--;\n\
    \t\tP p=lca(a,b);\n//\t\tshow(p.fs);\n//\t\tshow(p.sc);\n\t\tif(t%2){\n\t\t\t\
    if(p.sc==-1){\n\t\t\t\tif(b==p.fs) swap(a,b);\n\t\t\t\tchangeall(a,b,c);\n\t\t\
    \t}else{\n\t\t\t\tchangeall(p.fs,a,c);\n\t\t\t\tchangeall(p.sc,b,c);\n\t\t\t}\n\
    \t\t}else{\n\t\t\tif(p.sc==-1){\n\t\t\t\tif(b==p.fs) swap(a,b);\n//\t\t\t\tshow(a);\n\
    //\t\t\t\tshow(b);\n//\t\t\t\tshownode(calcall(a,b));\n\t\t\t\tcout<<calcall(a,b).mx<<endl;\n\
    \t\t\t}else{\n\t\t\t\tNode x=calcall(p.fs,a);\n\t\t\t\tNode y=calcall(p.sc,b);\n\
    //\t\t\t\tshow(a);\n//\t\t\t\tshow(p.fs);\n//\t\t\t\tshownode(x);\n//\t\t\t\t\
    show(b);\n//\t\t\t\tshow(p.sc);\n//\t\t\t\tshownode(y);\n\t\t\t\tcout<<merge(x,flip(y)).mx<<endl;\n\
    \t\t\t}\n\t\t}\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/HL_old.cpp
  requiredBy: []
  timestamp: '2024-01-03 19:12:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/HL_old.cpp
layout: document
redirect_from:
- /library/ds/HL_old.cpp
- /library/ds/HL_old.cpp.html
title: ds/HL_old.cpp
---
