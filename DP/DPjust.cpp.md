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
  bundledCode: "#line 1 \"DP/DPjust.cpp\"\n/*\nN\u500B\u4E2DK\u500B\u9078\u3093\u3067\
    \u3067\u304D\u308B\u3082\u306E\u306E\u548C\u3092\u5217\u6319(\u7DCF\u548C\u3092\
    S\u3068\u3059\u308B)\nO(NS)\n*/\n#include <bits/stdc++.h>\n#define rep(i,n) for(int\
    \ i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define\
    \ all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define sc\
    \ second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\nconst int MAX_N=600,MAX_S=100000,inf=1e9;\n\
    int N,K,a[MAX_N];\nint dp0[MAX_N][MAX_S+1];\nint dp1[MAX_N][MAX_S+1];\nint main(){\n\
    \tcin>>N>>K;\n\trep(i,N) cin>>a[i];\n\tint S=accumulate(a,a+N,0);\n\tfor(int j=K;j<=N;j++)\
    \ rep(s,S+1) dp0[j][s]=dp1[j][s]=inf;\n\tdp0[K][accumulate(a,a+K,0)]=0;\n\tfor(int\
    \ j=K;j<=N;j++){\n\t\trep(s,S+1){\n\t\t\tif(dp1[j][s]==inf) continue;\n\t\t\t\
    chmin(dp1[j+1][s],dp1[j][s]);\n\t\t\tint l=dp1[j][s],r=K;\n\t\t\tif(j>K) chmin(r,dp1[j-1][s]);\n\
    \t\t\tfor(int i=l;i<r;i++) chmin(dp0[j][s-a[i]],i+1);\n\t\t}\n\t\trep(s,S+1){\n\
    \t\t\tif(dp0[j][s]==inf) continue;\n\t\t\tchmin(dp0[j+1][s],dp0[j][s]);\n\t\t\t\
    chmin(dp1[j+1][s+a[j]],dp0[j][s]);\n\t\t}\n\t}\n\trep(s,S+1) if(dp0[N][s]!=inf)\
    \ cout<<s<<\" \";\n\tputs(\"\");\n}\n"
  code: "/*\nN\u500B\u4E2DK\u500B\u9078\u3093\u3067\u3067\u304D\u308B\u3082\u306E\u306E\
    \u548C\u3092\u5217\u6319(\u7DCF\u548C\u3092S\u3068\u3059\u308B)\nO(NS)\n*/\n#include\
    \ <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n)\
    \ for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n#define pb push_back\n\
    #define fs first\n#define sc second\n#define show(x) cout << #x << \" = \" <<\
    \ x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing\
    \ namespace std;\nconst int MAX_N=600,MAX_S=100000,inf=1e9;\nint N,K,a[MAX_N];\n\
    int dp0[MAX_N][MAX_S+1];\nint dp1[MAX_N][MAX_S+1];\nint main(){\n\tcin>>N>>K;\n\
    \trep(i,N) cin>>a[i];\n\tint S=accumulate(a,a+N,0);\n\tfor(int j=K;j<=N;j++) rep(s,S+1)\
    \ dp0[j][s]=dp1[j][s]=inf;\n\tdp0[K][accumulate(a,a+K,0)]=0;\n\tfor(int j=K;j<=N;j++){\n\
    \t\trep(s,S+1){\n\t\t\tif(dp1[j][s]==inf) continue;\n\t\t\tchmin(dp1[j+1][s],dp1[j][s]);\n\
    \t\t\tint l=dp1[j][s],r=K;\n\t\t\tif(j>K) chmin(r,dp1[j-1][s]);\n\t\t\tfor(int\
    \ i=l;i<r;i++) chmin(dp0[j][s-a[i]],i+1);\n\t\t}\n\t\trep(s,S+1){\n\t\t\tif(dp0[j][s]==inf)\
    \ continue;\n\t\t\tchmin(dp0[j+1][s],dp0[j][s]);\n\t\t\tchmin(dp1[j+1][s+a[j]],dp0[j][s]);\n\
    \t\t}\n\t}\n\trep(s,S+1) if(dp0[N][s]!=inf) cout<<s<<\" \";\n\tputs(\"\");\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/DPjust.cpp
  requiredBy: []
  timestamp: '2016-12-08 00:51:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/DPjust.cpp
layout: document
redirect_from:
- /library/DP/DPjust.cpp
- /library/DP/DPjust.cpp.html
title: DP/DPjust.cpp
---
