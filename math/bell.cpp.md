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
  bundledCode: "#line 1 \"math/bell.cpp\"\n/*\nBell\n\u533A\u5225\u306E\u3064\u304F\
    N\u500B\u306E\u3082\u306E\u3092\u533A\u5225\u306E\u4ED8\u304B\u306A\u3044\u7BB1\
    \u306B\u5206\u5272\u3059\u308B\u3088\u3046\u306A\u3082\u306E\u3092\u5217\u6319\
    \n\nbell.init(N)\u3067\u5217\u6319\u304C\u7D42\u4E86,\u8FD4\u308A\u5024\u306F\
    bell\u6570.\nunionfind\u3067\u8868\u73FE\u3057\u3066\u3044\u3066\u3001bell.UFs[id]\
    \ \u304Cid\u500B\u3081\u306E\u72B6\u614B\u3092\u8868\u3059.\n[0]\u304C\u5168\u3066\
    \u30D0\u30E9\u30D0\u30E9\u306E\u3082\u306E\u3067\u3001[B-1]\u304C\u5168\u90E8\u9023\
    \u7D50\u306E\u3082\u306E.\n0,...,B-1\u304C\u3061\u3083\u3093\u3068\u30C8\u30DD\
    \u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\u306B\u306A\u3063\u3066\u3044\u308B(bfs\u3092\
    \u3057\u3066\u3044\u308B\u305F\u3081,N-\u9023\u7D50\u6210\u5206\u306E\u500B\u6570\
    \u304C\u8DDD\u96E2\u306B\u306A\u308B\u306E\u3067)\nbfs\u306E\u3068\u3053\u306E\
    id->nid\u306E\u3068\u3053\u308D\u3067\u5168\u9077\u79FB\u304C\u5F97\u3089\u308C\
    \u3066\u3044\u308B.\u3053\u306E\u6642\u70B9\u3067->id\u306A\u308B\u9077\u79FB\u306F\
    \u5168\u3066\u5F97\u3089\u308C\u3066\u3044\u308B(\u4E0A\u3068\u540C\u69D8\u306E\
    \u7406\u7531)\u306E\u3067\u3001\u3053\u3053\u3067\u76F4\u63A5DP\u3092\u66F8\u3044\
    \u305F\u307B\u3046\u304C\u3044\u3044\u304B\u3082\n\n\u4E0B\u306E\u4F7F\u7528\u4F8B\
    \u3067\u306F\u5916\u304B\u3089\u547C\u3093\u3067\u3044\u3066\u3001\u3069\u306E\
    \u9023\u7D50\u6210\u5206\u3092\u7E4B\u3044\u3060\u3089\u3069\u308C\u306B\u9077\
    \u79FB\u3059\u308B\u304B(UF2id\u3092\u4F7F\u3046)\u3092\u898B\u3066\u3044\u308B\
    \n\n*/\nstruct unionfind{\n\tint par[15];\n\tvoid init(int N){rep(i,N) par[i]=i;}\n\
    \tint find(int x){\n\t\tif(par[x]==x) return x;\n\t\treturn par[x]=find(par[x]);\n\
    \t}\n\tbool same(int x,int y){\n\t\treturn find(x)==find(y);\n\t}\n\tvoid unite(int\
    \ x,int y){\n\t\tx=find(x),y=find(y);\n\t\tif(x==y) return;\n\t\tif(x>y) swap(x,y);\t\
    \t//roots have the smallest id\n\t\tpar[y]=x;\n\t}\n};\nstruct Bell{\n\t//(1,\
    \ )1, 2, 5, 15, 52,\n\t//203, 877, 4140, 21147, 115975,\n\t//678570, 4213597,\
    \ 27644437, 190899322, 1382958545\n\t\n\tvector<unionfind> UFs;\n\n\ttypedef vector<int>\
    \ VI;\n\tint N;\n\tmap<VI,int> VI2id;\n\tqueue<int> que;\n\n\tVI UF2VI(unionfind\
    \ UF){\n\t\tVI vi(N);\n\t\trep(i,N) vi[i]=UF.find(i);\n\t\treturn vi;\n\t}\n\t\
    int add(unionfind UF){\n\t\tVI vi = UF2VI(UF);\n\t\tint id = UFs.size();\n\t\t\
    VI2id[vi]=id;\n\t\tUFs.pb(UF);\n\t\tque.push(id);\n\t\treturn id;\n\t}\n\tint\
    \ UF2id(unionfind UF){\n\t\tVI vi = UF2VI(UF);\n\t\tif(VI2id.count(vi)) return\
    \ VI2id[vi];\n\t\treturn -1;\n\t}\n\n\tvoid bfs(){\n\t\twhile(!que.empty()){\n\
    \t\t\tint id = que.front();que.pop();\n//\t\t\tprintf(\"id%d -> \",id);\n//\t\t\
    \tshow(UF2VI(UFs[id]));\n\t\t\tVI roots;\n\t\t\trep(i,N) if(UFs[id].find(i)==i)\
    \ roots.pb(i);\n\t\t\tint K=roots.size();\n\t\t\trep(i,K) rep(j,i){\n\t\t\t\t\
    unionfind UF = UFs[id];\n\t\t\t\tUF.unite(roots[i],roots[j]);\n\t\t\t\tint nid;\n\
    \t\t\t\tif((nid=UF2id(UF))==-1){\n\t\t\t\t\tnid = add(UF);\n\t\t\t\t}\n\t\t\t\t\
    //id->nid\n//\t\t\t\tprintf(\"id%d->nid%d\\n\",id,nid);\n\t\t\t}\n\t\t}\n\t}\n\
    \tint init(int N_){\t\t//enum partitions\n\t\tN=N_;\n\t\tunionfind UF;\n\t\tUF.init(N);\n\
    \t\tadd(UF);\n\t\tbfs();\n\t\treturn UFs.size();\n\t}\n\n\n}bell;\nconst int B8=4140;\n\
    \nbool e[8][8];\nll dp[B8];\nint main(){\n\tint N,M;\n\tcin>>N>>M;\n\tint B =\
    \ bell.init(N);\n\trep(i,M){\n\t\tint a,b;\n\t\tcin>>a>>b;\n\t\ta--,b--;\n\t\t\
    e[a][b]=e[b][a]=1;\n\t}\n\trep(id,B){\n//\t\tprintf(\"dp[%d]=%I64d\\n\",id,dp[id]);\n\
    \t\tif(id==B-1) break;\n\t\tvector<int> roots;\n\t\trep(i,N) if(bell.UFs[id].find(i)==i)\
    \ roots.pb(i);\n\t\tint K=roots.size();\n\t\tint cnt = 0;\n\t\trep(i,N) rep(j,i)\
    \ if(e[i][j]&&bell.UFs[id].same(i,j)) cnt++;\n\n\t\trep(i,K) rep(j,i){\n\t\t\t\
    unionfind UF = bell.UFs[id];\n\t\t\tint cand = 0;\n\t\t\trep(a,N) rep(b,N) if(e[a][b]&&UF.find(a)==roots[i]&&UF.find(b)==roots[j])\
    \ cand++;\n\t\t\tif(cand==0) continue;\n\n\t\t\tUF.unite(roots[i],roots[j]);\n\
    \t\t\tint nid=bell.UF2id(UF);\n\t\t\t//id->nid\n\t\t\tll tmp = dp[id]*cand;\n\t\
    \t\tdp[nid] += tmp;\n//\t\t\t\tprintf(\"dp[%d] += %I64d\\n\",nid,tmp);\n\t\t}\n\
    \t}\n}\n"
  code: "/*\nBell\n\u533A\u5225\u306E\u3064\u304FN\u500B\u306E\u3082\u306E\u3092\u533A\
    \u5225\u306E\u4ED8\u304B\u306A\u3044\u7BB1\u306B\u5206\u5272\u3059\u308B\u3088\
    \u3046\u306A\u3082\u306E\u3092\u5217\u6319\n\nbell.init(N)\u3067\u5217\u6319\u304C\
    \u7D42\u4E86,\u8FD4\u308A\u5024\u306Fbell\u6570.\nunionfind\u3067\u8868\u73FE\u3057\
    \u3066\u3044\u3066\u3001bell.UFs[id] \u304Cid\u500B\u3081\u306E\u72B6\u614B\u3092\
    \u8868\u3059.\n[0]\u304C\u5168\u3066\u30D0\u30E9\u30D0\u30E9\u306E\u3082\u306E\
    \u3067\u3001[B-1]\u304C\u5168\u90E8\u9023\u7D50\u306E\u3082\u306E.\n0,...,B-1\u304C\
    \u3061\u3083\u3093\u3068\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\u306B\
    \u306A\u3063\u3066\u3044\u308B(bfs\u3092\u3057\u3066\u3044\u308B\u305F\u3081,N-\u9023\
    \u7D50\u6210\u5206\u306E\u500B\u6570\u304C\u8DDD\u96E2\u306B\u306A\u308B\u306E\
    \u3067)\nbfs\u306E\u3068\u3053\u306Eid->nid\u306E\u3068\u3053\u308D\u3067\u5168\
    \u9077\u79FB\u304C\u5F97\u3089\u308C\u3066\u3044\u308B.\u3053\u306E\u6642\u70B9\
    \u3067->id\u306A\u308B\u9077\u79FB\u306F\u5168\u3066\u5F97\u3089\u308C\u3066\u3044\
    \u308B(\u4E0A\u3068\u540C\u69D8\u306E\u7406\u7531)\u306E\u3067\u3001\u3053\u3053\
    \u3067\u76F4\u63A5DP\u3092\u66F8\u3044\u305F\u307B\u3046\u304C\u3044\u3044\u304B\
    \u3082\n\n\u4E0B\u306E\u4F7F\u7528\u4F8B\u3067\u306F\u5916\u304B\u3089\u547C\u3093\
    \u3067\u3044\u3066\u3001\u3069\u306E\u9023\u7D50\u6210\u5206\u3092\u7E4B\u3044\
    \u3060\u3089\u3069\u308C\u306B\u9077\u79FB\u3059\u308B\u304B(UF2id\u3092\u4F7F\
    \u3046)\u3092\u898B\u3066\u3044\u308B\n\n*/\nstruct unionfind{\n\tint par[15];\n\
    \tvoid init(int N){rep(i,N) par[i]=i;}\n\tint find(int x){\n\t\tif(par[x]==x)\
    \ return x;\n\t\treturn par[x]=find(par[x]);\n\t}\n\tbool same(int x,int y){\n\
    \t\treturn find(x)==find(y);\n\t}\n\tvoid unite(int x,int y){\n\t\tx=find(x),y=find(y);\n\
    \t\tif(x==y) return;\n\t\tif(x>y) swap(x,y);\t\t//roots have the smallest id\n\
    \t\tpar[y]=x;\n\t}\n};\nstruct Bell{\n\t//(1, )1, 2, 5, 15, 52,\n\t//203, 877,\
    \ 4140, 21147, 115975,\n\t//678570, 4213597, 27644437, 190899322, 1382958545\n\
    \t\n\tvector<unionfind> UFs;\n\n\ttypedef vector<int> VI;\n\tint N;\n\tmap<VI,int>\
    \ VI2id;\n\tqueue<int> que;\n\n\tVI UF2VI(unionfind UF){\n\t\tVI vi(N);\n\t\t\
    rep(i,N) vi[i]=UF.find(i);\n\t\treturn vi;\n\t}\n\tint add(unionfind UF){\n\t\t\
    VI vi = UF2VI(UF);\n\t\tint id = UFs.size();\n\t\tVI2id[vi]=id;\n\t\tUFs.pb(UF);\n\
    \t\tque.push(id);\n\t\treturn id;\n\t}\n\tint UF2id(unionfind UF){\n\t\tVI vi\
    \ = UF2VI(UF);\n\t\tif(VI2id.count(vi)) return VI2id[vi];\n\t\treturn -1;\n\t\
    }\n\n\tvoid bfs(){\n\t\twhile(!que.empty()){\n\t\t\tint id = que.front();que.pop();\n\
    //\t\t\tprintf(\"id%d -> \",id);\n//\t\t\tshow(UF2VI(UFs[id]));\n\t\t\tVI roots;\n\
    \t\t\trep(i,N) if(UFs[id].find(i)==i) roots.pb(i);\n\t\t\tint K=roots.size();\n\
    \t\t\trep(i,K) rep(j,i){\n\t\t\t\tunionfind UF = UFs[id];\n\t\t\t\tUF.unite(roots[i],roots[j]);\n\
    \t\t\t\tint nid;\n\t\t\t\tif((nid=UF2id(UF))==-1){\n\t\t\t\t\tnid = add(UF);\n\
    \t\t\t\t}\n\t\t\t\t//id->nid\n//\t\t\t\tprintf(\"id%d->nid%d\\n\",id,nid);\n\t\
    \t\t}\n\t\t}\n\t}\n\tint init(int N_){\t\t//enum partitions\n\t\tN=N_;\n\t\tunionfind\
    \ UF;\n\t\tUF.init(N);\n\t\tadd(UF);\n\t\tbfs();\n\t\treturn UFs.size();\n\t}\n\
    \n\n}bell;\nconst int B8=4140;\n\nbool e[8][8];\nll dp[B8];\nint main(){\n\tint\
    \ N,M;\n\tcin>>N>>M;\n\tint B = bell.init(N);\n\trep(i,M){\n\t\tint a,b;\n\t\t\
    cin>>a>>b;\n\t\ta--,b--;\n\t\te[a][b]=e[b][a]=1;\n\t}\n\trep(id,B){\n//\t\tprintf(\"\
    dp[%d]=%I64d\\n\",id,dp[id]);\n\t\tif(id==B-1) break;\n\t\tvector<int> roots;\n\
    \t\trep(i,N) if(bell.UFs[id].find(i)==i) roots.pb(i);\n\t\tint K=roots.size();\n\
    \t\tint cnt = 0;\n\t\trep(i,N) rep(j,i) if(e[i][j]&&bell.UFs[id].same(i,j)) cnt++;\n\
    \n\t\trep(i,K) rep(j,i){\n\t\t\tunionfind UF = bell.UFs[id];\n\t\t\tint cand =\
    \ 0;\n\t\t\trep(a,N) rep(b,N) if(e[a][b]&&UF.find(a)==roots[i]&&UF.find(b)==roots[j])\
    \ cand++;\n\t\t\tif(cand==0) continue;\n\n\t\t\tUF.unite(roots[i],roots[j]);\n\
    \t\t\tint nid=bell.UF2id(UF);\n\t\t\t//id->nid\n\t\t\tll tmp = dp[id]*cand;\n\t\
    \t\tdp[nid] += tmp;\n//\t\t\t\tprintf(\"dp[%d] += %I64d\\n\",nid,tmp);\n\t\t}\n\
    \t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/bell.cpp
  requiredBy: []
  timestamp: '2018-09-18 03:14:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/bell.cpp
layout: document
redirect_from:
- /library/math/bell.cpp
- /library/math/bell.cpp.html
title: math/bell.cpp
---
