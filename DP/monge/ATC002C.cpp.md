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
    - http://atc002.contest.atcoder.jp/tasks/atc002_c
  bundledCode: "#line 1 \"DP/monge/ATC002C.cpp\"\n// http://atc002.contest.atcoder.jp/tasks/atc002_c\n\
    #include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define\
    \ rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n#define\
    \ pb push_back\n#define fs first\n#define sc second\n#define show(x) cout << #x\
    \ << \" = \" << x << endl\n#define chmax(x,y) x=max(x,y)\ntemplate<class S,class\
    \ T> bool chmin(S& x,T y){\n\tif(x>y){x=y;return 1;}\n\treturn 0;\n}\nusing namespace\
    \ std;\n\n/*\n\u523A\u8EAB\u7CFB\nw:monge & monotone \u306E\u6642\ndp[l][r]=min(dp[l][i]+dp[i+1][r])+w[l][r]\n\
    \t\tl<=i<r\n\nd=r-l\u304C\u77ED\u3044\u9806\u306B\u57CB\u3081\u308B\ninitialize\n\
    dp[i][i]=0\n\n\u3092O(N^2)\u3067\u89E3\u304F\n*/\ntypedef long long ll;\ntypedef\
    \ pair<ll,int> P;\nconst int MAX_N=3000;\nll a[MAX_N],asum[MAX_N+1];\nll cost(int\
    \ l,int r){\t\t//[l,r)\n\treturn asum[r]-asum[l];\n}\nll dp[MAX_N][MAX_N+1];\n\
    int ar[MAX_N][MAX_N+1];\nll inf=1e17;\nll monge(int N){\n\trep(i,N) rep(j,N+1)\
    \ dp[i][j]=inf;\n\trep(i,N) dp[i][i+1]=cost(i,i+1),ar[i][i+1]=i;\n\tfor(int d=2;d<=N;d++){\n\
    \t\trep(l,N+1-d){\n\t\t\tint r=l+d;\n\t\t\tint L=ar[l][r-1];\n\t\t\tint R=ar[l+1][r];\n\
    \t\t\tfor(int i=L;i<=R;i++){\n\t\t\t\tif(chmin(dp[l][r],dp[l][i]+dp[i][r])) ar[l][r]=i;\n\
    \t\t\t}\n\t\t\tdp[l][r]+=cost(l,r);\n\t\t}\n\t}\n\treturn dp[0][N];\n}\n\n\nint\
    \ main(){\n\tint N;\n\tcin>>N;\n\trep(i,N) cin>>a[i],asum[i+1]=asum[i]+a[i];\n\
    \tcout<<monge(N)-asum[N]<<endl;\n}\n"
  code: "// http://atc002.contest.atcoder.jp/tasks/atc002_c\n#include <bits/stdc++.h>\n\
    #define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmax(x,y)\
    \ x=max(x,y)\ntemplate<class S,class T> bool chmin(S& x,T y){\n\tif(x>y){x=y;return\
    \ 1;}\n\treturn 0;\n}\nusing namespace std;\n\n/*\n\u523A\u8EAB\u7CFB\nw:monge\
    \ & monotone \u306E\u6642\ndp[l][r]=min(dp[l][i]+dp[i+1][r])+w[l][r]\n\t\tl<=i<r\n\
    \nd=r-l\u304C\u77ED\u3044\u9806\u306B\u57CB\u3081\u308B\ninitialize\ndp[i][i]=0\n\
    \n\u3092O(N^2)\u3067\u89E3\u304F\n*/\ntypedef long long ll;\ntypedef pair<ll,int>\
    \ P;\nconst int MAX_N=3000;\nll a[MAX_N],asum[MAX_N+1];\nll cost(int l,int r){\t\
    \t//[l,r)\n\treturn asum[r]-asum[l];\n}\nll dp[MAX_N][MAX_N+1];\nint ar[MAX_N][MAX_N+1];\n\
    ll inf=1e17;\nll monge(int N){\n\trep(i,N) rep(j,N+1) dp[i][j]=inf;\n\trep(i,N)\
    \ dp[i][i+1]=cost(i,i+1),ar[i][i+1]=i;\n\tfor(int d=2;d<=N;d++){\n\t\trep(l,N+1-d){\n\
    \t\t\tint r=l+d;\n\t\t\tint L=ar[l][r-1];\n\t\t\tint R=ar[l+1][r];\n\t\t\tfor(int\
    \ i=L;i<=R;i++){\n\t\t\t\tif(chmin(dp[l][r],dp[l][i]+dp[i][r])) ar[l][r]=i;\n\t\
    \t\t}\n\t\t\tdp[l][r]+=cost(l,r);\n\t\t}\n\t}\n\treturn dp[0][N];\n}\n\n\nint\
    \ main(){\n\tint N;\n\tcin>>N;\n\trep(i,N) cin>>a[i],asum[i+1]=asum[i]+a[i];\n\
    \tcout<<monge(N)-asum[N]<<endl;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/monge/ATC002C.cpp
  requiredBy: []
  timestamp: '2016-12-08 00:51:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/monge/ATC002C.cpp
layout: document
redirect_from:
- /library/DP/monge/ATC002C.cpp
- /library/DP/monge/ATC002C.cpp.html
title: DP/monge/ATC002C.cpp
---
