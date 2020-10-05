---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://ddcc2017-final.contest.atcoder.jp/tasks/ddcc2017_final_e
    - http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=RitsCamp16Day1&pid=F
  bundledCode: "#line 1 \"graph/treeDP/treeDP.cpp\"\n/*\n\ndp \u306E\u9014\u4E2D\u72B6\
    \u614B vs finalized \u3068\u3044\u3046\u306E\u304C\u3042\u3063\u3066 \u3001\u9014\
    \u4E2D\u72B6\u614B\u306E\u65B9\u3092\u30E1\u30A4\u30F3\u306B\u8003\u3048\u308B\
    \u3053\u3068\uFF01\n\u6700\u7D42\u7684\u306B\u307B\u3057\u3044\u306E\u306Ffinalized\u306A\
    \u3093\u3060\u3051\u3069\u3001+ \u306F \u9014\u4E2D\u72B6\u614B \u540C\u58EB\u306E\
    \u6F14\u7B97\u3067\u3042\u308B\u3053\u3068\u306B\u6CE8\u610F\n\t+: (\u9014\u4E2D\
    ,\u9014\u4E2D) -> \u9014\u4E2D\n\tappend_edge: finalized -> \u9014\u4E2D\n\tfinalize:\
    \ \u9014\u4E2D -> finalized\n\ndp[v] = N()\nfor(int u: child[v]){\n\tdp[v] = dp[v]\
    \ + dp[u].append_edge(v,edge(v,u))\n}\ndp[v].finalize(v)\n\nlp[] + rp[] \u307F\
    \u305F\u3044\u306A\u306E\u3082\u3042\u308B\u304B\u3089\u3001\u9806\u756A\u306B\
    \u8DB3\u3057\u3066\u3044\u304F\u3068\u3044\u3046\u3088\u308A\u304B\u306F\u672C\
    \u5F53\u306BDP\u30C6\u30FC\u30D6\u30EB2\u3064\u306E\u30DE\u30FC\u30B8\u3092 +\
    \ \u306B\u66F8\u304F\u5FC5\u8981\u304C\u3042\u308B\n\n\u666E\u901A\u306E\u6728\
    DP\u3067\u3088\u304F\u3042\u308B\u306E\u304C dp[v] \u3092\u6C42\u3081\u308B\u306E\
    \u306B\n\tV<int> sub(N);\n\tfor(int u: G[v]){\n\t\tsub \u3092 dp[u] \u4F7F\u3063\
    \u3066\u66F4\u65B0\n\t}\n\tdp[v] <- sub\u304B\u3089\u8A08\u7B97\u3067\u304D\u308B\
    \u306A\u306B\u304B\n\u307F\u305F\u3044\u306A\u3084\u3064\u3067\u3001\u5168\u65B9\
    \u4F4D\u306A\u3089 N() \u304C sub\u306E\u521D\u671F\u5316\u3001\u307F\u305F\u3044\
    \u306A\n\n\u307B\u3057\u3044\u306E\u306F\u306A\u306B\u304B \u2192 \u9014\u4E2D\
    \u72B6\u614B\u306F\u4F55\u304B \u2192 +,N() \u2192 finalize,append \u3042\u305F\
    \u308A\u306E\u9806\u756A\u3067\u8003\u3048\u308B\u3068\u3044\u3044\u3068\u601D\
    \u3046\n\n-----------\n\n\u5168\u65B9\u4F4D\u6728DP.\nNode \u306E \u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF, append_edge, +, finalize \u3060\u3051\u304B\u3051\
    \u3070\u3044\u3044. \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306F\u5B50\u304C\
    0\u500B\u306E\u6642\u3069\u3046\u3057\u305F\u3044\u304B\u8003\u3048\u308B\u3068\
    \u308F\u304B\u308A\u3084\u3059\u3044?\npic.png\u53C2\u7167\n\nBidirectionalTreeDP<Node>\
    \ treedp(G);\n\u3068\u3059\u308C\u3070\u3088\u3044\nget(v)\u3067v\u3092\u6839\u3068\
    \u3059\u308Bdp\u304C\u3001get(v,p)\u3067v\u3092\u6839\u3068\u3057\u3066p\u65B9\
    \u5411\u3092\u524A\u3063\u305F\u6642\u306ENode\u304C\u5F97\u3089\u308C\u308B\n\
    \n\u4E2D\u3067normalize\u3088\u3093\u3067G\u304C\u66F8\u304D\u63DB\u308F\u3063\
    \u3066\u308B\u3053\u3068\u306B\u6CE8\u610F\nverified by http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=RitsCamp16Day1&pid=F\n\
    \nold\u3088\u308A\u4F7F\u3044\u3084\u3059\u3044\u3068\u601D\u3046.\u305F\u3060\
    \u3001data\u3068subdata\u3092\u4E00\u7DD2\u304F\u305F\u306B\u3057\u305F\u306E\u3067\
    \u3001\u5B9F\u306F\u96C6\u5408\u540C\u58EB\u306Emerge2\u3068\u8981\u7D20\u3092\
    \u3072\u3068\u3064\u8FFD\u52A0\u3059\u308Bmerge\u3067\u8A08\u7B97\u91CF\u304C\u9055\
    \u3046\u5834\u5408\nold\u3092\u4F7F\u3063\u305F\u307B\u3046\u304C\u826F\u3055\u305D\
    \u3046?\u3067\u3082\u305D\u306E\u3068\u304D\u306Fold\u3067\u3082\u9045\u3044\u306E\
    \u3067\u6C17\u306B\u3057\u306A\u304F\u3066\u826F\u3044\u306D\n\n*/\n\n\n#include\
    \ <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n)\
    \ for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n#define pb push_back\n\
    #define fs first\n#define sc second\n#define show(x) cout << #x << \" = \" <<\
    \ x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing\
    \ namespace std;\ntemplate<class S,class T> ostream& operator<<(ostream& o,const\
    \ pair<S,T> &p){return o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class T>\
    \ ostream& operator<<(ostream& o,const vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"\
    [\";for(const T& v:vc) o<<v<<\",\";o<<\"]\";return o;}\n\nnamespace Normalize{\n\
    \ttemplate<class E>\n\tvoid dfs(vector<vector<E>>& G,vector<int>& ord, int v,int\
    \ p=-1){\n\t\tord.pb(v);\n\t\tint K = G[v].size();\n\t\trep(i,K){\n\t\t\tif(G[v][i].to==p){\n\
    \t\t\t\trotate(G[v].begin()+i,G[v].begin()+i+1,G[v].end());\n\t\t\t\tK--;\n\t\t\
    \t\tbreak;\n\t\t\t}\n\t\t}\n\t\trep(i,K){\n\t\t\tdfs(G,ord,G[v][i].to,v);\n\t\t\
    }\n\t}\n\ttemplate<class E>\n\tvector<int> normalize_and_gettopord(vector<vector<E>>&\
    \ G, int r=0){\n\t\tvector<int> ord;\n\t\tdfs(G,ord,r);\n\t\treturn ord;\n\t}\n\
    }\n\n/*\n\tNode + \u306B\u53EF\u63DB\u306F\u4EEE\u5B9A\u3057\u306A\u304F\u3066\
    \u3082\u5927\u4E08\u592B(\u8DB3\u3059\u9806\u5E8F\u306F\u5909\u3048\u3066\u306A\
    \u3044(\u305F\u3060\u3057up\u3092\u8DB3\u3059\u5834\u6240\u306F\u9069\u5F53\u306A\
    \u306E\u3067\u6CE8\u610F))\n*/\ntemplate<class N>\nstruct BidirectionalTreeDP{\n\
    \tvector<N> dp;\t//dp[v] <- u1,u2,... \t\t\tp\u3092\u524A\u3063\u3066v\u304C\u6839\
    \n\tvector<N> up;\t//up[v] <- v's brothers + pp \tv\u3092\u524A\u3063\u3066p\u304C\
    \u6839\n\tvector<N> rp;\t//dp[r] <- r\u3092\u6839\u3068\u3057\u305F\u6642\u306E\
    \u3053\u305F\u3048\n\n\tvector<int> par;\n\ttemplate<class E>\n\tBidirectionalTreeDP(vector<vector<E>>&\
    \ G, int r=0){\n\t\tint V = G.size();\n\t\tdp.assign(V,N());\n\t\tup.assign(V,N());\n\
    \t\trp.assign(V,N());\n\t\tpar.assign(V,0);\n\n\t\tvector<int> ord = Normalize::normalize_and_gettopord<E>(G,r);\n\
    \t\trep(t,V){\n\t\t\tint v = ord[t];\n\t\t\tif(v==r) par[v]=-1;\n\t\t\telse par[v]=G[v].back().to;\n\
    \t\t}\n\n\t\tfor(int t=V-1;t>=0;t--){\t//dfs\n\t\t\tint v = ord[t];\n\t\t\tdp[v]\
    \ = N();\n\t\t\tint K = G[v].size() - (v!=r);\n\t\t\trep(i,K){\n\t\t\t\tconst\
    \ E& e = G[v][i];\n\t\t\t\tint u = e.to;\n\t\t\t\tdp[v] = dp[v] + dp[u].append_edge(v,e);\n\
    \t\t\t}\n\t\t\tdp[v].finalize(v);\n\t\t}\n\n\t\trep(t,V){\t\t\t\t\t//ufs\n\t\t\
    \tint v = ord[t];\n\t\t\tint K = G[v].size() - (v!=r);\n\t\t\tvector<N> ls(K+1),rs(K+1);\n\
    \t\t\trep(i,K){\n\t\t\t\tls[i+1] = ls[i] + dp[G[v][i].to].append_edge(v,G[v][i]);\n\
    \t\t\t\trs[K-1-i] = dp[G[v][K-1-i].to].append_edge(v,G[v][K-1-i]) + rs[K-i];\n\
    \t\t\t}\n\t\t\trep(i,K){\n\t\t\t\tconst E& e = G[v][i];\n\t\t\t\tint u = e.to;\n\
    \t\t\t\tup[u] = ls[i] + rs[i+1];\n\t\t\t\tif(v!=r) up[u] = up[u] + up[v].append_edge(v,G[v].back());\n\
    \t\t\t\tup[u].finalize(v);\n\t\t\t}\n\t\t\trp[v] = ls[K];\n\t\t\tif(v!=r) rp[v]\
    \ = rp[v] + up[v].append_edge(v,G[v].back());\n\t\t\trp[v].finalize(v);\n\t\t\
    }\n\t}\n\n\tN get(int v,int p=-1){\t//p\u3092\u524A\u3063\u3066v\u304C\u6839\n\
    \t\tif(p==-1) return rp[v];\n\t\tif(par[v]==p) return dp[v];\n\t\treturn up[p];\n\
    \t}\n};\n\n/*\n\t0/1\u70B9\u9664\u3044\u3066\u5B8C\u5168\u30DE\u30C3\u30C1\u30F3\
    \u30B0\u3092\u4F5C\u308B\u901A\u308A\u6570\n\t-> sub\u306E\u72B6\u614B\u306F\u3001\
    (\u6839\u3092\u4F7F\u3063\u305F,\u70B9\u3092\u9664\u3044\u305F)\n*/\nstruct Node{\n\
    \tint f[2][2];int sz;\n\tNode(){\n\t\tf[0][1] = f[1][0] = f[1][1] = 0;\n\t\tf[0][0]\
    \ = 1;\n\t\tsz = 0;\n\t}\n\n\t/*\t\n\t\t\u6839\u4ED8\u304D\u6728\u2192\u68EE\n\
    \t\te=(p -> this)\u3092\u8FFD\u52A0\u3057\u305F\u3082\u306E\u3092\u8FD4\u3059\n\
    \t*/\n\ttemplate<class E>\n\tNode append_edge(int p,const E& e) const {\n\t\t\
    Node n;\n\t\tn.f[1][0] = f[0][0];\n\t\tn.f[1][1] = f[0][1];\n\t\tn.f[0][0] = f[1][0];\n\
    \t\tn.f[0][1] = f[1][1];\n\t\tn.sz = sz;\n\t\treturn n;\n\t}\n\tfriend Node operator+(const\
    \ Node& l,const Node& r){\n\t\tNode z;\trep(i,2) rep(j,2) z.f[i][j] = 0;\n\t\t\
    rep(i,2) rep(j,2) if(l.f[i][j]){\n\t\t\trep(k,2-i) rep(m,2-j) if(r.f[k][m]){\n\
    \t\t\t\tz.f[i+k][j+m] += l.f[i][j]*r.f[k][m];\n\t\t\t}\n\t\t}\n\t\tz.sz = l.sz+r.sz;\n\
    \t\treturn z;\n\t}\n\tvoid finalize(int r){\n\t\tif(f[0][0]) f[1][1]++;\n\t\t\
    sz++;\n\t}\n};\n\n\n/*\n\tget(v,p) = (\u90E8\u5206\u6728\u306E\u76F4\u5F84, \u90E8\
    \u5206\u6728\u306Emax dist, 2nd max dist)\n*/\n\nstruct Node{\t//\n\tint dia;\n\
    \tarray<int,2> rd;\n\tNode(){\n\t\tdia=0;\n\t\trd[0]=rd[1]=0;\n\t}\n\n\t/*\n\t\
    \t\u6839\u4ED8\u304D\u6728\u2192\u68EE\n\t\te=(p -> this)\u3092\u8FFD\u52A0\u3057\
    \u305F\u3082\u306E\u3092\u8FD4\u3059\n\t*/\n\ttemplate<class E>\n\tNode append_edge(int\
    \ p,const E& e) const {\n\t\tNode n;\n\t\tn.rd[0] = rd[0] + e.dist;\n\t\tn.rd[1]\
    \ = 0;\n\t\tn.dia = dia;\n\t\treturn n;\n\t}\n\tNode operator+(const Node& r)\
    \ const {\n\t\tNode n;\n\t\tvector<int> vc;\n\t\trep(t,2) vc.pb(rd[t]),vc.pb(r.rd[t]);\n\
    \t\tsort(all(vc),greater<int>());\n\t\trep(t,2) n.rd[t]=vc[t];\n\t\tn.dia = max(dia,r.dia);\n\
    \t\treturn n;\n\t}\n\tvoid finalize(int r){\n\t\tchmax(dia,rd[0]+rd[1]);\n\t}\n\
    };\n\nstruct Edge{\n\tint to;\n\tint dist;\n};\n\n/*\n\tget(v,p) = v\u304B\u3089\
    \u306Emax dist, \u90E8\u5206\u6728v\u4EE5\u4E0B\u306E\u8449\u306E\u500B\u6570\
    , \u8449\u304B\u3089\u306E\u8DDD\u96E2\u306E\u7DCF\u548C\n\t\"\u8449\u3067\u3042\
    \u308B\" \u306E\u5224\u5B9A\u306E\u305F\u3081\u306B finalize \u306E\u5F15\u6570\
    \u306BG\u3092\u6E21\u3057\u3066\u3044\u308B\n\n\thttp://ddcc2017-final.contest.atcoder.jp/tasks/ddcc2017_final_e\n\
    */\n\nstruct Node{\t//v\u304B\u3089\u6700\u3082\u9060\u3044\u9802\u70B9\u3078\u306E\
    \u8DDD\u96E2\n\tint d;\n\tll lnum;\n\tll lsum;\n\tNode(){\n\t\td=0;\n\t\tlnum=0;\n\
    \t\tlsum=0;\n\t}\n\n\t/*\n\t\t\u6839\u4ED8\u304D\u6728\u2192\u68EE\n\t\te=(p ->\
    \ this)\u3092\u8FFD\u52A0\u3057\u305F\u3082\u306E\u3092\u8FD4\u3059\n\t*/\n\t\
    template<class E>\n\tNode append_edge(int p,const E& e) const {\n\t\tNode n;\n\
    \t\tn.d = d+1;\n\t\tn.lnum = lnum;\n\t\tn.lsum = lsum + lnum;\n\t\treturn n;\n\
    \t}\n\tNode operator+(const Node& r) const {\n\t\tNode n;\n\t\tn.d = max(d,r.d);\n\
    \t\tn.lnum = lnum + r.lnum;\n\t\tn.lsum = lsum + r.lsum;\n\t\treturn n;\n\t}\n\
    \ttemplate<class E>\n\tvoid finalize(int v,vector<vector<E>>& G){\n\t\tif(G[v].size()\
    \ == 1) lnum++;\n\t}\n};\n\nstruct Edge{\n\tint to;\n};\n\n\n\nint main(){\n\t\
    int N;\n\tcin>>N;\n\tvector<vector<Edge>> G(N);\n\trep(i,N-1){\n\t\tint x,y,d;\n\
    \t\tcin>>x>>y>>d;\n\t\tG[x].pb({y,d});\n\t\tG[y].pb({x,d});\n\t}\n\n\tBidirectionalTreeDP<Node>\
    \ treedp(G);\n\trep(v,N){\n\t\tfor(const Edge& e:G[v]){\n\t\t\tint u = e.to;\n\
    \t\t\tprintf(\"dia[%d] (par = %d)  = %d\\n\",v,u,treedp.get(v,u).dia);\n\t\t}\n\
    \t}\n\trep(v,N){\n\t\tprintf(\"all[%d]=%d\\n\",v,treedp.get(v).dia);\n\t}\n}\n"
  code: "/*\n\ndp \u306E\u9014\u4E2D\u72B6\u614B vs finalized \u3068\u3044\u3046\u306E\
    \u304C\u3042\u3063\u3066 \u3001\u9014\u4E2D\u72B6\u614B\u306E\u65B9\u3092\u30E1\
    \u30A4\u30F3\u306B\u8003\u3048\u308B\u3053\u3068\uFF01\n\u6700\u7D42\u7684\u306B\
    \u307B\u3057\u3044\u306E\u306Ffinalized\u306A\u3093\u3060\u3051\u3069\u3001+ \u306F\
    \ \u9014\u4E2D\u72B6\u614B \u540C\u58EB\u306E\u6F14\u7B97\u3067\u3042\u308B\u3053\
    \u3068\u306B\u6CE8\u610F\n\t+: (\u9014\u4E2D,\u9014\u4E2D) -> \u9014\u4E2D\n\t\
    append_edge: finalized -> \u9014\u4E2D\n\tfinalize: \u9014\u4E2D -> finalized\n\
    \ndp[v] = N()\nfor(int u: child[v]){\n\tdp[v] = dp[v] + dp[u].append_edge(v,edge(v,u))\n\
    }\ndp[v].finalize(v)\n\nlp[] + rp[] \u307F\u305F\u3044\u306A\u306E\u3082\u3042\
    \u308B\u304B\u3089\u3001\u9806\u756A\u306B\u8DB3\u3057\u3066\u3044\u304F\u3068\
    \u3044\u3046\u3088\u308A\u304B\u306F\u672C\u5F53\u306BDP\u30C6\u30FC\u30D6\u30EB\
    2\u3064\u306E\u30DE\u30FC\u30B8\u3092 + \u306B\u66F8\u304F\u5FC5\u8981\u304C\u3042\
    \u308B\n\n\u666E\u901A\u306E\u6728DP\u3067\u3088\u304F\u3042\u308B\u306E\u304C\
    \ dp[v] \u3092\u6C42\u3081\u308B\u306E\u306B\n\tV<int> sub(N);\n\tfor(int u: G[v]){\n\
    \t\tsub \u3092 dp[u] \u4F7F\u3063\u3066\u66F4\u65B0\n\t}\n\tdp[v] <- sub\u304B\
    \u3089\u8A08\u7B97\u3067\u304D\u308B\u306A\u306B\u304B\n\u307F\u305F\u3044\u306A\
    \u3084\u3064\u3067\u3001\u5168\u65B9\u4F4D\u306A\u3089 N() \u304C sub\u306E\u521D\
    \u671F\u5316\u3001\u307F\u305F\u3044\u306A\n\n\u307B\u3057\u3044\u306E\u306F\u306A\
    \u306B\u304B \u2192 \u9014\u4E2D\u72B6\u614B\u306F\u4F55\u304B \u2192 +,N() \u2192\
    \ finalize,append \u3042\u305F\u308A\u306E\u9806\u756A\u3067\u8003\u3048\u308B\
    \u3068\u3044\u3044\u3068\u601D\u3046\n\n-----------\n\n\u5168\u65B9\u4F4D\u6728\
    DP.\nNode \u306E \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF, append_edge, +, finalize\
    \ \u3060\u3051\u304B\u3051\u3070\u3044\u3044. \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\u306F\u5B50\u304C0\u500B\u306E\u6642\u3069\u3046\u3057\u305F\u3044\u304B\
    \u8003\u3048\u308B\u3068\u308F\u304B\u308A\u3084\u3059\u3044?\npic.png\u53C2\u7167\
    \n\nBidirectionalTreeDP<Node> treedp(G);\n\u3068\u3059\u308C\u3070\u3088\u3044\
    \nget(v)\u3067v\u3092\u6839\u3068\u3059\u308Bdp\u304C\u3001get(v,p)\u3067v\u3092\
    \u6839\u3068\u3057\u3066p\u65B9\u5411\u3092\u524A\u3063\u305F\u6642\u306ENode\u304C\
    \u5F97\u3089\u308C\u308B\n\n\u4E2D\u3067normalize\u3088\u3093\u3067G\u304C\u66F8\
    \u304D\u63DB\u308F\u3063\u3066\u308B\u3053\u3068\u306B\u6CE8\u610F\nverified by\
    \ http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=RitsCamp16Day1&pid=F\n\
    \nold\u3088\u308A\u4F7F\u3044\u3084\u3059\u3044\u3068\u601D\u3046.\u305F\u3060\
    \u3001data\u3068subdata\u3092\u4E00\u7DD2\u304F\u305F\u306B\u3057\u305F\u306E\u3067\
    \u3001\u5B9F\u306F\u96C6\u5408\u540C\u58EB\u306Emerge2\u3068\u8981\u7D20\u3092\
    \u3072\u3068\u3064\u8FFD\u52A0\u3059\u308Bmerge\u3067\u8A08\u7B97\u91CF\u304C\u9055\
    \u3046\u5834\u5408\nold\u3092\u4F7F\u3063\u305F\u307B\u3046\u304C\u826F\u3055\u305D\
    \u3046?\u3067\u3082\u305D\u306E\u3068\u304D\u306Fold\u3067\u3082\u9045\u3044\u306E\
    \u3067\u6C17\u306B\u3057\u306A\u304F\u3066\u826F\u3044\u306D\n\n*/\n\n\n#include\
    \ <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n)\
    \ for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n#define pb push_back\n\
    #define fs first\n#define sc second\n#define show(x) cout << #x << \" = \" <<\
    \ x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing\
    \ namespace std;\ntemplate<class S,class T> ostream& operator<<(ostream& o,const\
    \ pair<S,T> &p){return o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class T>\
    \ ostream& operator<<(ostream& o,const vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"\
    [\";for(const T& v:vc) o<<v<<\",\";o<<\"]\";return o;}\n\nnamespace Normalize{\n\
    \ttemplate<class E>\n\tvoid dfs(vector<vector<E>>& G,vector<int>& ord, int v,int\
    \ p=-1){\n\t\tord.pb(v);\n\t\tint K = G[v].size();\n\t\trep(i,K){\n\t\t\tif(G[v][i].to==p){\n\
    \t\t\t\trotate(G[v].begin()+i,G[v].begin()+i+1,G[v].end());\n\t\t\t\tK--;\n\t\t\
    \t\tbreak;\n\t\t\t}\n\t\t}\n\t\trep(i,K){\n\t\t\tdfs(G,ord,G[v][i].to,v);\n\t\t\
    }\n\t}\n\ttemplate<class E>\n\tvector<int> normalize_and_gettopord(vector<vector<E>>&\
    \ G, int r=0){\n\t\tvector<int> ord;\n\t\tdfs(G,ord,r);\n\t\treturn ord;\n\t}\n\
    }\n\n/*\n\tNode + \u306B\u53EF\u63DB\u306F\u4EEE\u5B9A\u3057\u306A\u304F\u3066\
    \u3082\u5927\u4E08\u592B(\u8DB3\u3059\u9806\u5E8F\u306F\u5909\u3048\u3066\u306A\
    \u3044(\u305F\u3060\u3057up\u3092\u8DB3\u3059\u5834\u6240\u306F\u9069\u5F53\u306A\
    \u306E\u3067\u6CE8\u610F))\n*/\ntemplate<class N>\nstruct BidirectionalTreeDP{\n\
    \tvector<N> dp;\t//dp[v] <- u1,u2,... \t\t\tp\u3092\u524A\u3063\u3066v\u304C\u6839\
    \n\tvector<N> up;\t//up[v] <- v's brothers + pp \tv\u3092\u524A\u3063\u3066p\u304C\
    \u6839\n\tvector<N> rp;\t//dp[r] <- r\u3092\u6839\u3068\u3057\u305F\u6642\u306E\
    \u3053\u305F\u3048\n\n\tvector<int> par;\n\ttemplate<class E>\n\tBidirectionalTreeDP(vector<vector<E>>&\
    \ G, int r=0){\n\t\tint V = G.size();\n\t\tdp.assign(V,N());\n\t\tup.assign(V,N());\n\
    \t\trp.assign(V,N());\n\t\tpar.assign(V,0);\n\n\t\tvector<int> ord = Normalize::normalize_and_gettopord<E>(G,r);\n\
    \t\trep(t,V){\n\t\t\tint v = ord[t];\n\t\t\tif(v==r) par[v]=-1;\n\t\t\telse par[v]=G[v].back().to;\n\
    \t\t}\n\n\t\tfor(int t=V-1;t>=0;t--){\t//dfs\n\t\t\tint v = ord[t];\n\t\t\tdp[v]\
    \ = N();\n\t\t\tint K = G[v].size() - (v!=r);\n\t\t\trep(i,K){\n\t\t\t\tconst\
    \ E& e = G[v][i];\n\t\t\t\tint u = e.to;\n\t\t\t\tdp[v] = dp[v] + dp[u].append_edge(v,e);\n\
    \t\t\t}\n\t\t\tdp[v].finalize(v);\n\t\t}\n\n\t\trep(t,V){\t\t\t\t\t//ufs\n\t\t\
    \tint v = ord[t];\n\t\t\tint K = G[v].size() - (v!=r);\n\t\t\tvector<N> ls(K+1),rs(K+1);\n\
    \t\t\trep(i,K){\n\t\t\t\tls[i+1] = ls[i] + dp[G[v][i].to].append_edge(v,G[v][i]);\n\
    \t\t\t\trs[K-1-i] = dp[G[v][K-1-i].to].append_edge(v,G[v][K-1-i]) + rs[K-i];\n\
    \t\t\t}\n\t\t\trep(i,K){\n\t\t\t\tconst E& e = G[v][i];\n\t\t\t\tint u = e.to;\n\
    \t\t\t\tup[u] = ls[i] + rs[i+1];\n\t\t\t\tif(v!=r) up[u] = up[u] + up[v].append_edge(v,G[v].back());\n\
    \t\t\t\tup[u].finalize(v);\n\t\t\t}\n\t\t\trp[v] = ls[K];\n\t\t\tif(v!=r) rp[v]\
    \ = rp[v] + up[v].append_edge(v,G[v].back());\n\t\t\trp[v].finalize(v);\n\t\t\
    }\n\t}\n\n\tN get(int v,int p=-1){\t//p\u3092\u524A\u3063\u3066v\u304C\u6839\n\
    \t\tif(p==-1) return rp[v];\n\t\tif(par[v]==p) return dp[v];\n\t\treturn up[p];\n\
    \t}\n};\n\n/*\n\t0/1\u70B9\u9664\u3044\u3066\u5B8C\u5168\u30DE\u30C3\u30C1\u30F3\
    \u30B0\u3092\u4F5C\u308B\u901A\u308A\u6570\n\t-> sub\u306E\u72B6\u614B\u306F\u3001\
    (\u6839\u3092\u4F7F\u3063\u305F,\u70B9\u3092\u9664\u3044\u305F)\n*/\nstruct Node{\n\
    \tint f[2][2];int sz;\n\tNode(){\n\t\tf[0][1] = f[1][0] = f[1][1] = 0;\n\t\tf[0][0]\
    \ = 1;\n\t\tsz = 0;\n\t}\n\n\t/*\t\n\t\t\u6839\u4ED8\u304D\u6728\u2192\u68EE\n\
    \t\te=(p -> this)\u3092\u8FFD\u52A0\u3057\u305F\u3082\u306E\u3092\u8FD4\u3059\n\
    \t*/\n\ttemplate<class E>\n\tNode append_edge(int p,const E& e) const {\n\t\t\
    Node n;\n\t\tn.f[1][0] = f[0][0];\n\t\tn.f[1][1] = f[0][1];\n\t\tn.f[0][0] = f[1][0];\n\
    \t\tn.f[0][1] = f[1][1];\n\t\tn.sz = sz;\n\t\treturn n;\n\t}\n\tfriend Node operator+(const\
    \ Node& l,const Node& r){\n\t\tNode z;\trep(i,2) rep(j,2) z.f[i][j] = 0;\n\t\t\
    rep(i,2) rep(j,2) if(l.f[i][j]){\n\t\t\trep(k,2-i) rep(m,2-j) if(r.f[k][m]){\n\
    \t\t\t\tz.f[i+k][j+m] += l.f[i][j]*r.f[k][m];\n\t\t\t}\n\t\t}\n\t\tz.sz = l.sz+r.sz;\n\
    \t\treturn z;\n\t}\n\tvoid finalize(int r){\n\t\tif(f[0][0]) f[1][1]++;\n\t\t\
    sz++;\n\t}\n};\n\n\n/*\n\tget(v,p) = (\u90E8\u5206\u6728\u306E\u76F4\u5F84, \u90E8\
    \u5206\u6728\u306Emax dist, 2nd max dist)\n*/\n\nstruct Node{\t//\n\tint dia;\n\
    \tarray<int,2> rd;\n\tNode(){\n\t\tdia=0;\n\t\trd[0]=rd[1]=0;\n\t}\n\n\t/*\n\t\
    \t\u6839\u4ED8\u304D\u6728\u2192\u68EE\n\t\te=(p -> this)\u3092\u8FFD\u52A0\u3057\
    \u305F\u3082\u306E\u3092\u8FD4\u3059\n\t*/\n\ttemplate<class E>\n\tNode append_edge(int\
    \ p,const E& e) const {\n\t\tNode n;\n\t\tn.rd[0] = rd[0] + e.dist;\n\t\tn.rd[1]\
    \ = 0;\n\t\tn.dia = dia;\n\t\treturn n;\n\t}\n\tNode operator+(const Node& r)\
    \ const {\n\t\tNode n;\n\t\tvector<int> vc;\n\t\trep(t,2) vc.pb(rd[t]),vc.pb(r.rd[t]);\n\
    \t\tsort(all(vc),greater<int>());\n\t\trep(t,2) n.rd[t]=vc[t];\n\t\tn.dia = max(dia,r.dia);\n\
    \t\treturn n;\n\t}\n\tvoid finalize(int r){\n\t\tchmax(dia,rd[0]+rd[1]);\n\t}\n\
    };\n\nstruct Edge{\n\tint to;\n\tint dist;\n};\n\n/*\n\tget(v,p) = v\u304B\u3089\
    \u306Emax dist, \u90E8\u5206\u6728v\u4EE5\u4E0B\u306E\u8449\u306E\u500B\u6570\
    , \u8449\u304B\u3089\u306E\u8DDD\u96E2\u306E\u7DCF\u548C\n\t\"\u8449\u3067\u3042\
    \u308B\" \u306E\u5224\u5B9A\u306E\u305F\u3081\u306B finalize \u306E\u5F15\u6570\
    \u306BG\u3092\u6E21\u3057\u3066\u3044\u308B\n\n\thttp://ddcc2017-final.contest.atcoder.jp/tasks/ddcc2017_final_e\n\
    */\n\nstruct Node{\t//v\u304B\u3089\u6700\u3082\u9060\u3044\u9802\u70B9\u3078\u306E\
    \u8DDD\u96E2\n\tint d;\n\tll lnum;\n\tll lsum;\n\tNode(){\n\t\td=0;\n\t\tlnum=0;\n\
    \t\tlsum=0;\n\t}\n\n\t/*\n\t\t\u6839\u4ED8\u304D\u6728\u2192\u68EE\n\t\te=(p ->\
    \ this)\u3092\u8FFD\u52A0\u3057\u305F\u3082\u306E\u3092\u8FD4\u3059\n\t*/\n\t\
    template<class E>\n\tNode append_edge(int p,const E& e) const {\n\t\tNode n;\n\
    \t\tn.d = d+1;\n\t\tn.lnum = lnum;\n\t\tn.lsum = lsum + lnum;\n\t\treturn n;\n\
    \t}\n\tNode operator+(const Node& r) const {\n\t\tNode n;\n\t\tn.d = max(d,r.d);\n\
    \t\tn.lnum = lnum + r.lnum;\n\t\tn.lsum = lsum + r.lsum;\n\t\treturn n;\n\t}\n\
    \ttemplate<class E>\n\tvoid finalize(int v,vector<vector<E>>& G){\n\t\tif(G[v].size()\
    \ == 1) lnum++;\n\t}\n};\n\nstruct Edge{\n\tint to;\n};\n\n\n\nint main(){\n\t\
    int N;\n\tcin>>N;\n\tvector<vector<Edge>> G(N);\n\trep(i,N-1){\n\t\tint x,y,d;\n\
    \t\tcin>>x>>y>>d;\n\t\tG[x].pb({y,d});\n\t\tG[y].pb({x,d});\n\t}\n\n\tBidirectionalTreeDP<Node>\
    \ treedp(G);\n\trep(v,N){\n\t\tfor(const Edge& e:G[v]){\n\t\t\tint u = e.to;\n\
    \t\t\tprintf(\"dia[%d] (par = %d)  = %d\\n\",v,u,treedp.get(v,u).dia);\n\t\t}\n\
    \t}\n\trep(v,N){\n\t\tprintf(\"all[%d]=%d\\n\",v,treedp.get(v).dia);\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/treeDP/treeDP.cpp
  requiredBy: []
  timestamp: '2020-09-20 08:11:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/treeDP/treeDP.cpp
layout: document
redirect_from:
- /library/graph/treeDP/treeDP.cpp
- /library/graph/treeDP/treeDP.cpp.html
title: graph/treeDP/treeDP.cpp
---
