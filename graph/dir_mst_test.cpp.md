---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/dir_mst_test.cpp\"\n/*\nr\u3092\u6839\u3068\u3059\u308B\
    \u6700\u5C0F\u6709\u5411\u5168\u57DF\u6728\nO(NM)\u306A\u306E\u3067\u96A3\u63A5\
    \u3067\u6301\u3063\u3066\u3082\u69CB\u308F\u306A\u3044\nd[][]\u306B\u8FBA\u306E\
    cost or inf \u3092\u5165\u308C\u305F\u72B6\u614B\u3067dir_mst\u3092\u547C\u3076\
    \ \n*/\nusing namespace std;\n#include <bits/stdc++.h>\n#define rep(i,n) for(int\
    \ i=0;i<n;i++)\n#define pb push_back\n#define fs first\n#define sc second\n#define\
    \ show(x) cout<< #x<<\" \"<<x<<endl\ntypedef pair<double,int> P;\nint N,M,from[101],nid[101];\n\
    double inf=1e5,d[101][101],d2[101][101];\nbool vis[101];\nvector<int> cycle;\n\
    bool visit(int v,int s,int r){\n\tif(v==r) return 0;\n\tif(vis[v]) return v==s;\n\
    \tcycle.pb(v);\n\tvis[v]=1;\n\treturn visit(from[v],s,r);\n}\ndouble dir_mst(int\
    \ r){\t//root = r\n\tint S=N;\n/*\tputs(\"dist\");\n\trep(i,S){\n\t\trep(j,S)\
    \ cout<<d[i][j]<<\" \";\n\t\tputs(\"\");\n\t}*/\n\tbool update=1;\n\twhile(update){\n\
    \t\tupdate=0;\n\t\tdouble sco=0;\n\t\trep(i,S){\n\t\t\tif(i==r) continue;\n\t\t\
    \tP mn=P(inf,-1);\n\t\t\trep(j,S) if(i!=j) mn=min(mn,P(d[j][i],j));\n\t\t\tif(mn.fs==inf)\
    \ return inf;\n\t\t\tfrom[i]=mn.sc;\n\t\t\tsco+=mn.fs;\n\t\t}\n\t\trep(i,S){\n\
    \t\t\tif(i==r) continue;\n\t\t\trep(j,S) vis[j]=0;\n\t\t\tcycle.clear();\n\t\t\
    \tif(!visit(i,i,r)) continue;\n\t\t\tupdate=1;\n\t\t\tint len=cycle.size();\n\t\
    \t\tcycle.pb(cycle[0]);\n\t\t\tint S2=S-len+1,it=0;\n\t\t\trep(j,S){\n\t\t\t\t\
    if(!vis[j]) nid[j]=it++;\n\t\t\t\telse nid[j]=-1;\n\t\t\t}\n\t\t\tr=nid[r];\n\t\
    \t\trep(j,S) if(nid[j]!=-1){\n\t\t\t\trep(k,S) if(nid[k]!=-1){\n\t\t\t\t\td2[nid[j]][nid[k]]=d[j][k];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\trep(j,S) if(nid[j]!=-1){\n\t\t\t\tdouble mn=inf;\n\t\
    \t\t\trep(k,S) if(nid[k]==-1) mn=min(mn,d[k][j]);\n\t\t\t\td2[S2-1][nid[j]]=mn;\n\
    \t\t\t}\n\t\t\tdouble csum=0;\n\t\t\trep(j,len) csum+=d[cycle[j+1]][cycle[j]];\n\
    \t\t\trep(j,S) if(nid[j]!=-1){\n\t\t\t\tdouble mn=inf;\n\t\t\t\trep(k,len){\n\t\
    \t\t\t\tmn=min(mn,d[j][cycle[k]]+csum-d[cycle[k+1]][cycle[k]]);\n\t\t\t\t}\n\t\
    \t\t\td2[nid[j]][S2-1]=mn;\n\t\t\t}\n\t\t\tS=S2;\n\t\t\trep(j,S) rep(k,S) d[j][k]=d2[j][k];\n\
    \t\t\tbreak;\n\t\t}\n\t\tif(!update) return sco;\n\t}\n}\nint main(){\n\tcin>>N>>M;\n\
    \trep(i,N) rep(j,N) d[i][j]=0;\n\trep(i,N) rep(j,N) {\n\t\tint c;\n\t\tcin>>c;\n\
    \t\td[i][j]=c;\n\t}\n\tshow(dir_mst(0));\n}\n"
  code: "/*\nr\u3092\u6839\u3068\u3059\u308B\u6700\u5C0F\u6709\u5411\u5168\u57DF\u6728\
    \nO(NM)\u306A\u306E\u3067\u96A3\u63A5\u3067\u6301\u3063\u3066\u3082\u69CB\u308F\
    \u306A\u3044\nd[][]\u306B\u8FBA\u306Ecost or inf \u3092\u5165\u308C\u305F\u72B6\
    \u614B\u3067dir_mst\u3092\u547C\u3076 \n*/\nusing namespace std;\n#include <bits/stdc++.h>\n\
    #define rep(i,n) for(int i=0;i<n;i++)\n#define pb push_back\n#define fs first\n\
    #define sc second\n#define show(x) cout<< #x<<\" \"<<x<<endl\ntypedef pair<double,int>\
    \ P;\nint N,M,from[101],nid[101];\ndouble inf=1e5,d[101][101],d2[101][101];\n\
    bool vis[101];\nvector<int> cycle;\nbool visit(int v,int s,int r){\n\tif(v==r)\
    \ return 0;\n\tif(vis[v]) return v==s;\n\tcycle.pb(v);\n\tvis[v]=1;\n\treturn\
    \ visit(from[v],s,r);\n}\ndouble dir_mst(int r){\t//root = r\n\tint S=N;\n/*\t\
    puts(\"dist\");\n\trep(i,S){\n\t\trep(j,S) cout<<d[i][j]<<\" \";\n\t\tputs(\"\"\
    );\n\t}*/\n\tbool update=1;\n\twhile(update){\n\t\tupdate=0;\n\t\tdouble sco=0;\n\
    \t\trep(i,S){\n\t\t\tif(i==r) continue;\n\t\t\tP mn=P(inf,-1);\n\t\t\trep(j,S)\
    \ if(i!=j) mn=min(mn,P(d[j][i],j));\n\t\t\tif(mn.fs==inf) return inf;\n\t\t\t\
    from[i]=mn.sc;\n\t\t\tsco+=mn.fs;\n\t\t}\n\t\trep(i,S){\n\t\t\tif(i==r) continue;\n\
    \t\t\trep(j,S) vis[j]=0;\n\t\t\tcycle.clear();\n\t\t\tif(!visit(i,i,r)) continue;\n\
    \t\t\tupdate=1;\n\t\t\tint len=cycle.size();\n\t\t\tcycle.pb(cycle[0]);\n\t\t\t\
    int S2=S-len+1,it=0;\n\t\t\trep(j,S){\n\t\t\t\tif(!vis[j]) nid[j]=it++;\n\t\t\t\
    \telse nid[j]=-1;\n\t\t\t}\n\t\t\tr=nid[r];\n\t\t\trep(j,S) if(nid[j]!=-1){\n\t\
    \t\t\trep(k,S) if(nid[k]!=-1){\n\t\t\t\t\td2[nid[j]][nid[k]]=d[j][k];\n\t\t\t\t\
    }\n\t\t\t}\n\t\t\trep(j,S) if(nid[j]!=-1){\n\t\t\t\tdouble mn=inf;\n\t\t\t\trep(k,S)\
    \ if(nid[k]==-1) mn=min(mn,d[k][j]);\n\t\t\t\td2[S2-1][nid[j]]=mn;\n\t\t\t}\n\t\
    \t\tdouble csum=0;\n\t\t\trep(j,len) csum+=d[cycle[j+1]][cycle[j]];\n\t\t\trep(j,S)\
    \ if(nid[j]!=-1){\n\t\t\t\tdouble mn=inf;\n\t\t\t\trep(k,len){\n\t\t\t\t\tmn=min(mn,d[j][cycle[k]]+csum-d[cycle[k+1]][cycle[k]]);\n\
    \t\t\t\t}\n\t\t\t\td2[nid[j]][S2-1]=mn;\n\t\t\t}\n\t\t\tS=S2;\n\t\t\trep(j,S)\
    \ rep(k,S) d[j][k]=d2[j][k];\n\t\t\tbreak;\n\t\t}\n\t\tif(!update) return sco;\n\
    \t}\n}\nint main(){\n\tcin>>N>>M;\n\trep(i,N) rep(j,N) d[i][j]=0;\n\trep(i,N)\
    \ rep(j,N) {\n\t\tint c;\n\t\tcin>>c;\n\t\td[i][j]=c;\n\t}\n\tshow(dir_mst(0));\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: graph/dir_mst_test.cpp
  requiredBy: []
  timestamp: '2016-12-08 00:51:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dir_mst_test.cpp
layout: document
redirect_from:
- /library/graph/dir_mst_test.cpp
- /library/graph/dir_mst_test.cpp.html
title: graph/dir_mst_test.cpp
---
