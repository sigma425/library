---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://csacademy.com/contest/round-11/#task/connected-tree-subgraphs
  bundledCode: "#line 1 \"graph/treeDP/treeDP_old.cpp\"\n/*\nData dp[MN];\nSubData\
    \ init;\nSubData merge(SubData val,Data v);\nData term(SubData val);\nvoid dfs(int\
    \ v,int p){\n\tfor(int u:G[v]) if(u!=p) dfs(u,v);\n\tSubData val=init;\n\tfor(int\
    \ u:G[v]) if(u!=p) val=merge(val,dp[u]);\n\tdp[v]=term(val);\n}\n\u3053\u308C\u3092\
    \u30AA\u30FC\u30C0\u30FC\u3092\u5909\u3048\u305A\u306B\u5168\u65B9\u5411\u306B\
    \u3059\u308B\nmerge\u306B\u9806\u5E8F\u304C\u95A2\u4FC2\u306A\u3044 \u3068\u304B\
    \u304C\u5FC5\u8981(\u5B9F\u306F\u3046\u307E\u304F\u3084\u308C\u3070\u9069\u5207\
    \u306A\u9806\u306A\u3089\u51FA\u6765\u308B\u3068\u601D\u3046(ex.\u9802\u70B9id\u5C0F\
    \u3055\u3044\u9806)\u3051\u3069\u305D\u3093\u306A\u30A8\u30B0\u3044\u306E\u306F\
    \u51FA\u306A\u3044\u3068\u601D\u3046)\n\nmerge2\u304C\u8A08\u7B97\u91CF\u7684\u306B\
    \u9593\u306B\u5408\u308F\u306A\u3044\u5834\u5408\u306F\u7121\u7406\u3060\u3068\
    \u601D\u3046(\u4F8B\u3048\u3070,knapsack\u3067\u4F55\u304B\u8377\u7269\u3092\u8FFD\
    \u52A0\u3059\u308B \u306FO(K)\u3067\u51FA\u6765\u3066\u3082,\u4ECA\u306Edp\u306E\
    \u72B6\u6CC1 \u3069\u3046\u3057\u3092\u8FFD\u52A0\u3059\u308B\u306E\u306B\u306F\
    O(NK)\u304B\u304B\u308B)\n\u305D\u306E\u5834\u5408\u306F\u9006\u5143\u3067\u5B50\
    \u3092\u6D88\u3059\u30BF\u30A4\u30D7\u306E\u3084\u3064\u3092\u3084\u308C\u3070\
    \u3088\u3055\u305D\u3046(ls,rs\u304C\u3044\u3089\u306A\u304F\u3066,nottermed\u304B\
    \u3089\u5B50\u3092\u4E00\u3064\u5F15\u304F\u611F\u3058)\n\n\nHow To Use\nG\u3064\
    \u304F\u308B\n\nData,SubData,init,merge,merge2\u3092\u5B9A\u7FA9\u3059\u308B(\u4E0A\
    \u306E\u666E\u901A\u306E\u6728DP\u3092\u53C2\u7167)\n\nData\u306F\u7B54\u3048\u3060\
    \u3051\u3058\u3083\u306A\u304F\u3066,\u518D\u5E30\u7684\u306B\u8A08\u7B97\u3059\
    \u308B\u3068\u304D\u306B\u5FC5\u8981\u306A\u5024\u306F\u4FDD\u6301\u3059\u308B\
    (ex.size\u3068\u304B)\n\nmerge2\u306F,SubData\u540C\u58EB\u306E\u6F14\u7B97\n\
    Data=SubData,merge=merge2\u306B\u51FA\u6765\u308B\u3053\u3068\u3082\u591A\u305D\
    \u3046?(\u305F\u3060\u306E\u7A4D\u3068\u304B)\n\n\ncalcDP\u3092\u3088\u3076\n\
    DP[]\u3092\u4F7F\u3046(dp\u3067\u306F\u306A\u3044!!!!)\n\ndebug\u306E\u305F\u3081\
    \u306B\u5143\u3068\u306A\u308Broot\u3092\u5909\u3048\u3089\u308C\u308B\u3088\u3046\
    \u306B\u3057\u3066\u3042\u308B(\u521D\u671F\u5316\u3068\u304B\u306F\u3044\u3089\
    \u306A\u3044) calcDP(N,r)\n\nverified by https://csacademy.com/contest/round-11/#task/connected-tree-subgraphs\n\
    AGC06 black radius\n\n*/\n\n\n#include <bits/stdc++.h>\n#define rep(i,n) for(int\
    \ i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define\
    \ all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define sc\
    \ second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<\"(\"\
    <<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class T> ostream& operator<<(ostream& o,const\
    \ vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"[\";for(const T& v:vc) o<<v<<\"\
    ,\";o<<\"]\";return o;}\n\ntypedef long long ll;\nll mod=1e9+7;\nvoid add(ll &x,ll\
    \ y){\n\tx+=y;\n\tx%=mod;\n}\nll extgcd(ll a,ll b,ll &x,ll &y){\n\tif(b==0){\n\
    \t\tx=1,y=0;\n\t\treturn a;\n\t}\n\tll g=extgcd(b,a%b,y,x);\n\ty-=(a/b)*x;\n\t\
    return g;\n}\nll inv(ll a){\n\tll x,y;\n\textgcd(a,mod,x,y);\n\tif(x<0) x+=mod;\n\
    \treturn x;\n}\n\ntypedef pair<ll,int> Data;\ntypedef pair<ll,int> SubData;\n\n\
    const int MN=100000;\nll f[MN+1],g[MN+1];\n\nvector<int> G[MN];\nData dp[MN];\t\
    \t\t//0-rooted dp[v]=term(merge(dp[u1],dp[u2],...))\nSubData dp_nottermed[MN];\t\
    //0-rooted merge(dp[u1],...)\nData up[MN];\t\t\t//up[v]= 0-rooted\u3067\u306E\
    v\u306E\u89AA\u3092p\u3068\u3057\u3066, v->p\u65B9\u5411\u306Edp\u306E\u5024 term(merge(up[p],dp[v's\
    \ bro1],dp[v's bro1],...))\nData DP[MN];\t\t\t//DP[v]: ans for v-rooted tree\n\
    vector<SubData> ls,rs;\t\t//ls/rs[i] = 0-rooted\u3067\u898B\u3066v\u306Echildren\u3092\
    \u5DE6/\u53F3\u304B\u3089i\u500Bmerge\u3057\u305F\u3082\u306E(\u5404v\u3067\u4F7F\
    \u3044\u56DE\u3059)\nSubData init(1,0);\nSubData merge(SubData val,Data v){\n\t\
    return SubData(val.fs*v.fs%mod*g[v.sc]%mod,val.sc+v.sc);\n}\nSubData merge2(SubData\
    \ x,SubData y){\n\treturn SubData(x.fs*y.fs%mod,x.sc+y.sc);\n}\nData term(SubData\
    \ val){\n\treturn Data(val.fs*f[val.sc]%mod,val.sc+1);\n}\nvoid dfs(int v,int\
    \ p=-1){\n\tSubData val=init;\n\tfor(int u:G[v]) if(u!=p){\n\t\tdfs(u,v);\n\t\t\
    val=merge(val,dp[u]);\n\t}\n\tdp_nottermed[v]=val;\n\tdp[v]=term(val);\n//\tcout<<\"\
    dp[\"<<v<<\"]=\"<<dp[v]<<endl;\n}\nvoid ufs(int v,int p=-1){\t\t//0-rooted\u3067\
    upward\u306A\u90E8\u5206\u3092\u8A08\u7B97\n\tvector<int> ch;\t//children\n\t\
    for(int u:G[v]) if(u!=p) ch.pb(u);\n\tint K=ch.size();\n\tls.resize(K+1);\n\t\
    rs.resize(K+1);\n\tls[0]=init;\n\trs[0]=init;\n\trep(i,K){\n\t\tls[i+1]=merge(ls[i],dp[ch[i]]);\n\
    \t\trs[i+1]=merge(rs[i],dp[ch[K-1-i]]);\n\t}\n//\tif(p==-1) rep1(i,K) show(ls[i]),show(rs[i]);\n\
    \trep(i,K){\n\t\tint u=ch[i];\n\t\tSubData val=merge2(ls[i],rs[K-1-i]);\n\t\t\
    if(p>=0) val=merge(val,up[v]);\n\t\tup[u]=term(val);\n//\t\tcout<<\"up[\"<<u<<\"\
    ]=\"<<up[u]<<endl;\n\t}\n\trep(i,K) ufs(ch[i],v);\n}\nvoid calcDP(int N,int r=0){\n\
    \tdfs(r);\n//\tup[r]=e\t\t\t//Data\u306E\u5358\u4F4D\u5143(\u2260init)\u304C\u5FC5\
    \u8981\u3067\u9762\u5012\u306A\u306E\u3067\u56DE\u907F\n\tufs(r);\n\trep(v,N){\n\
    \t\tSubData val=dp_nottermed[v];\n\t\tif(v!=r) val=merge(val,up[v]);\n\t\tDP[v]=term(val);\n\
    \t}\n}\nint main(){\n\tint N;\n\tcin>>N;\n\tf[0]=1;\n\trep1(i,N) f[i]=f[i-1]*i%mod;\n\
    \trep(i,N+1) g[i]=inv(f[i]);\n\trep(i,N-1){\n\t\tint x,y;\n\t\tscanf(\"%d %d\"\
    ,&x,&y);\n\t\tx--,y--;\n\t\tG[x].pb(y);G[y].pb(x);\n\t}\n\tcalcDP(N);\n\tll ans=0;\n\
    \trep(i,N) add(ans,DP[i].fs);\n\tcout<<ans<<endl;\n}\n"
  code: "/*\nData dp[MN];\nSubData init;\nSubData merge(SubData val,Data v);\nData\
    \ term(SubData val);\nvoid dfs(int v,int p){\n\tfor(int u:G[v]) if(u!=p) dfs(u,v);\n\
    \tSubData val=init;\n\tfor(int u:G[v]) if(u!=p) val=merge(val,dp[u]);\n\tdp[v]=term(val);\n\
    }\n\u3053\u308C\u3092\u30AA\u30FC\u30C0\u30FC\u3092\u5909\u3048\u305A\u306B\u5168\
    \u65B9\u5411\u306B\u3059\u308B\nmerge\u306B\u9806\u5E8F\u304C\u95A2\u4FC2\u306A\
    \u3044 \u3068\u304B\u304C\u5FC5\u8981(\u5B9F\u306F\u3046\u307E\u304F\u3084\u308C\
    \u3070\u9069\u5207\u306A\u9806\u306A\u3089\u51FA\u6765\u308B\u3068\u601D\u3046\
    (ex.\u9802\u70B9id\u5C0F\u3055\u3044\u9806)\u3051\u3069\u305D\u3093\u306A\u30A8\
    \u30B0\u3044\u306E\u306F\u51FA\u306A\u3044\u3068\u601D\u3046)\n\nmerge2\u304C\u8A08\
    \u7B97\u91CF\u7684\u306B\u9593\u306B\u5408\u308F\u306A\u3044\u5834\u5408\u306F\
    \u7121\u7406\u3060\u3068\u601D\u3046(\u4F8B\u3048\u3070,knapsack\u3067\u4F55\u304B\
    \u8377\u7269\u3092\u8FFD\u52A0\u3059\u308B \u306FO(K)\u3067\u51FA\u6765\u3066\u3082\
    ,\u4ECA\u306Edp\u306E\u72B6\u6CC1 \u3069\u3046\u3057\u3092\u8FFD\u52A0\u3059\u308B\
    \u306E\u306B\u306FO(NK)\u304B\u304B\u308B)\n\u305D\u306E\u5834\u5408\u306F\u9006\
    \u5143\u3067\u5B50\u3092\u6D88\u3059\u30BF\u30A4\u30D7\u306E\u3084\u3064\u3092\
    \u3084\u308C\u3070\u3088\u3055\u305D\u3046(ls,rs\u304C\u3044\u3089\u306A\u304F\
    \u3066,nottermed\u304B\u3089\u5B50\u3092\u4E00\u3064\u5F15\u304F\u611F\u3058)\n\
    \n\nHow To Use\nG\u3064\u304F\u308B\n\nData,SubData,init,merge,merge2\u3092\u5B9A\
    \u7FA9\u3059\u308B(\u4E0A\u306E\u666E\u901A\u306E\u6728DP\u3092\u53C2\u7167)\n\
    \nData\u306F\u7B54\u3048\u3060\u3051\u3058\u3083\u306A\u304F\u3066,\u518D\u5E30\
    \u7684\u306B\u8A08\u7B97\u3059\u308B\u3068\u304D\u306B\u5FC5\u8981\u306A\u5024\
    \u306F\u4FDD\u6301\u3059\u308B(ex.size\u3068\u304B)\n\nmerge2\u306F,SubData\u540C\
    \u58EB\u306E\u6F14\u7B97\nData=SubData,merge=merge2\u306B\u51FA\u6765\u308B\u3053\
    \u3068\u3082\u591A\u305D\u3046?(\u305F\u3060\u306E\u7A4D\u3068\u304B)\n\n\ncalcDP\u3092\
    \u3088\u3076\nDP[]\u3092\u4F7F\u3046(dp\u3067\u306F\u306A\u3044!!!!)\n\ndebug\u306E\
    \u305F\u3081\u306B\u5143\u3068\u306A\u308Broot\u3092\u5909\u3048\u3089\u308C\u308B\
    \u3088\u3046\u306B\u3057\u3066\u3042\u308B(\u521D\u671F\u5316\u3068\u304B\u306F\
    \u3044\u3089\u306A\u3044) calcDP(N,r)\n\nverified by https://csacademy.com/contest/round-11/#task/connected-tree-subgraphs\n\
    AGC06 black radius\n\n*/\n\n\n#include <bits/stdc++.h>\n#define rep(i,n) for(int\
    \ i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define\
    \ all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define sc\
    \ second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<\"(\"\
    <<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class T> ostream& operator<<(ostream& o,const\
    \ vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"[\";for(const T& v:vc) o<<v<<\"\
    ,\";o<<\"]\";return o;}\n\ntypedef long long ll;\nll mod=1e9+7;\nvoid add(ll &x,ll\
    \ y){\n\tx+=y;\n\tx%=mod;\n}\nll extgcd(ll a,ll b,ll &x,ll &y){\n\tif(b==0){\n\
    \t\tx=1,y=0;\n\t\treturn a;\n\t}\n\tll g=extgcd(b,a%b,y,x);\n\ty-=(a/b)*x;\n\t\
    return g;\n}\nll inv(ll a){\n\tll x,y;\n\textgcd(a,mod,x,y);\n\tif(x<0) x+=mod;\n\
    \treturn x;\n}\n\ntypedef pair<ll,int> Data;\ntypedef pair<ll,int> SubData;\n\n\
    const int MN=100000;\nll f[MN+1],g[MN+1];\n\nvector<int> G[MN];\nData dp[MN];\t\
    \t\t//0-rooted dp[v]=term(merge(dp[u1],dp[u2],...))\nSubData dp_nottermed[MN];\t\
    //0-rooted merge(dp[u1],...)\nData up[MN];\t\t\t//up[v]= 0-rooted\u3067\u306E\
    v\u306E\u89AA\u3092p\u3068\u3057\u3066, v->p\u65B9\u5411\u306Edp\u306E\u5024 term(merge(up[p],dp[v's\
    \ bro1],dp[v's bro1],...))\nData DP[MN];\t\t\t//DP[v]: ans for v-rooted tree\n\
    vector<SubData> ls,rs;\t\t//ls/rs[i] = 0-rooted\u3067\u898B\u3066v\u306Echildren\u3092\
    \u5DE6/\u53F3\u304B\u3089i\u500Bmerge\u3057\u305F\u3082\u306E(\u5404v\u3067\u4F7F\
    \u3044\u56DE\u3059)\nSubData init(1,0);\nSubData merge(SubData val,Data v){\n\t\
    return SubData(val.fs*v.fs%mod*g[v.sc]%mod,val.sc+v.sc);\n}\nSubData merge2(SubData\
    \ x,SubData y){\n\treturn SubData(x.fs*y.fs%mod,x.sc+y.sc);\n}\nData term(SubData\
    \ val){\n\treturn Data(val.fs*f[val.sc]%mod,val.sc+1);\n}\nvoid dfs(int v,int\
    \ p=-1){\n\tSubData val=init;\n\tfor(int u:G[v]) if(u!=p){\n\t\tdfs(u,v);\n\t\t\
    val=merge(val,dp[u]);\n\t}\n\tdp_nottermed[v]=val;\n\tdp[v]=term(val);\n//\tcout<<\"\
    dp[\"<<v<<\"]=\"<<dp[v]<<endl;\n}\nvoid ufs(int v,int p=-1){\t\t//0-rooted\u3067\
    upward\u306A\u90E8\u5206\u3092\u8A08\u7B97\n\tvector<int> ch;\t//children\n\t\
    for(int u:G[v]) if(u!=p) ch.pb(u);\n\tint K=ch.size();\n\tls.resize(K+1);\n\t\
    rs.resize(K+1);\n\tls[0]=init;\n\trs[0]=init;\n\trep(i,K){\n\t\tls[i+1]=merge(ls[i],dp[ch[i]]);\n\
    \t\trs[i+1]=merge(rs[i],dp[ch[K-1-i]]);\n\t}\n//\tif(p==-1) rep1(i,K) show(ls[i]),show(rs[i]);\n\
    \trep(i,K){\n\t\tint u=ch[i];\n\t\tSubData val=merge2(ls[i],rs[K-1-i]);\n\t\t\
    if(p>=0) val=merge(val,up[v]);\n\t\tup[u]=term(val);\n//\t\tcout<<\"up[\"<<u<<\"\
    ]=\"<<up[u]<<endl;\n\t}\n\trep(i,K) ufs(ch[i],v);\n}\nvoid calcDP(int N,int r=0){\n\
    \tdfs(r);\n//\tup[r]=e\t\t\t//Data\u306E\u5358\u4F4D\u5143(\u2260init)\u304C\u5FC5\
    \u8981\u3067\u9762\u5012\u306A\u306E\u3067\u56DE\u907F\n\tufs(r);\n\trep(v,N){\n\
    \t\tSubData val=dp_nottermed[v];\n\t\tif(v!=r) val=merge(val,up[v]);\n\t\tDP[v]=term(val);\n\
    \t}\n}\nint main(){\n\tint N;\n\tcin>>N;\n\tf[0]=1;\n\trep1(i,N) f[i]=f[i-1]*i%mod;\n\
    \trep(i,N+1) g[i]=inv(f[i]);\n\trep(i,N-1){\n\t\tint x,y;\n\t\tscanf(\"%d %d\"\
    ,&x,&y);\n\t\tx--,y--;\n\t\tG[x].pb(y);G[y].pb(x);\n\t}\n\tcalcDP(N);\n\tll ans=0;\n\
    \trep(i,N) add(ans,DP[i].fs);\n\tcout<<ans<<endl;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/treeDP/treeDP_old.cpp
  requiredBy: []
  timestamp: '2017-04-11 17:24:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/treeDP/treeDP_old.cpp
layout: document
redirect_from:
- /library/graph/treeDP/treeDP_old.cpp
- /library/graph/treeDP/treeDP_old.cpp.html
title: graph/treeDP/treeDP_old.cpp
---
