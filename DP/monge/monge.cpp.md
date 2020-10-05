---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://atc002.contest.atcoder.jp/tasks/atc002_c
  bundledCode: "#line 1 \"DP/monge/monge.cpp\"\n/*\n\u523A\u8EAB\u7CFB\n[0,N)\u3092\
    \u5206\u5272\u3059\u308B\n\nw:monge & monotone \u306E\u6642\ndp[l][r]=min(dp[l][i]+dp[i][r])+w[l][r]\n\
    \t\tl<i<r\n\n\u3092O(N^2)\u3067\u89E3\u304F\n\nverified by http://atc002.contest.atcoder.jp/tasks/atc002_c\n\
    \n*/\n\nconst int MAX_N=3000;\nll cost(int l,int r){\t\t//[l,r)\n\treturn w[l][r];\n\
    }\nll dp[MAX_N][MAX_N+1];\nint ar[MAX_N][MAX_N+1];\nll inf=1e17;\nll monge(int\
    \ N){\n\trep(i,N) rep(j,N+1) dp[i][j]=inf;\n\trep(i,N) dp[i][i+1]=cost(i,i+1),ar[i][i+1]=i;\n\
    \tfor(int d=2;d<=N;d++){\n\t\trep(l,N+1-d){\n\t\t\tint r=l+d;\n\t\t\tint L=ar[l][r-1];\n\
    \t\t\tint R=ar[l+1][r];\n\t\t\tfor(int i=L;i<=R;i++){\n\t\t\t\tif(chmin(dp[l][r],dp[l][i]+dp[i][r]))\
    \ ar[l][r]=i;\n\t\t\t}\n\t\t\tdp[l][r]+=cost(l,r);\n\t\t}\n\t}\n\treturn dp[0][N];\n\
    }\n"
  code: "/*\n\u523A\u8EAB\u7CFB\n[0,N)\u3092\u5206\u5272\u3059\u308B\n\nw:monge &\
    \ monotone \u306E\u6642\ndp[l][r]=min(dp[l][i]+dp[i][r])+w[l][r]\n\t\tl<i<r\n\n\
    \u3092O(N^2)\u3067\u89E3\u304F\n\nverified by http://atc002.contest.atcoder.jp/tasks/atc002_c\n\
    \n*/\n\nconst int MAX_N=3000;\nll cost(int l,int r){\t\t//[l,r)\n\treturn w[l][r];\n\
    }\nll dp[MAX_N][MAX_N+1];\nint ar[MAX_N][MAX_N+1];\nll inf=1e17;\nll monge(int\
    \ N){\n\trep(i,N) rep(j,N+1) dp[i][j]=inf;\n\trep(i,N) dp[i][i+1]=cost(i,i+1),ar[i][i+1]=i;\n\
    \tfor(int d=2;d<=N;d++){\n\t\trep(l,N+1-d){\n\t\t\tint r=l+d;\n\t\t\tint L=ar[l][r-1];\n\
    \t\t\tint R=ar[l+1][r];\n\t\t\tfor(int i=L;i<=R;i++){\n\t\t\t\tif(chmin(dp[l][r],dp[l][i]+dp[i][r]))\
    \ ar[l][r]=i;\n\t\t\t}\n\t\t\tdp[l][r]+=cost(l,r);\n\t\t}\n\t}\n\treturn dp[0][N];\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/monge/monge.cpp
  requiredBy: []
  timestamp: '2016-12-08 00:51:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/monge/monge.cpp
layout: document
redirect_from:
- /library/DP/monge/monge.cpp
- /library/DP/monge/monge.cpp.html
title: DP/monge/monge.cpp
---
