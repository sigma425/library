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
    - http://codeforces.com/contest/662/problem/C
  bundledCode: "#line 1 \"math/matrix/rank_mod2.cpp\"\n/*\rAx = b mod 2\r\u306E\u89E3\
    \u304C\u4F55\u500B\u3042\u308B\u304B\r\rN\u5909\u6570\u3067\u5F0F\u304CM\u500B\
    ,\u3064\u307E\u308A A:M*N, x:N, b:M\r\rres = -1 -> 0\u500B\rotherwise -> 2^(N-r)\u500B\
    \r\r\u305F\u3060rank\u3092\u6C42\u3081\u305F\u3044\u6642(b\u304C\u306A\u3044\u3068\
    \u304D) \u306F b\u306B\u95A2\u3059\u308B\u90E8\u5206\u3092\u6D88\u305B\u3070\u826F\
    \u3044.\r\rO(NM min(N,M) / 32)\t(j\u306E\u30EB\u30FC\u30D7\u304Cmin(N,M)\u56DE\
    )\r\rverified: http://codeforces.com/contest/662/problem/C\r\r*/\r\rconst int\
    \ MN = ;\rtypedef bitset<MN> Bs;\rtypedef vector<Bs> mat;\rint getrank(mat A,\
    \ vector<bool> b,int N){\r\tassert(A.size() == b.size());\r\r\tint M = b.size();\r\
    \r\tint res=0;\r\tvector<bool> used(M,false);\r\r\trep(j,N){\r\t\tint i = 0;\r\
    \t\twhile( (i < M) && (used[i] || !A[i][j]) ) i++;\r\t\tif(i == M) continue;\r\
    \t\tres++;\r\t\tused[i] = 1;\r\t\trep(k,M) if(!used[k]&&A[k][j]){\r\t\t\tA[k]^=A[i];\r\
    \t\t\tb[k]=b[k]^b[i];\r\t\t}\r\t}\r\trep(i,M) if(!used[i] && b[i] ) return -1;\r\
    \treturn res;\r}\rtypedef long long ll;\rbool B(ll x,int i){return (x>>i)&1;}\r\
    \rint main(){\r\tint N;\r\tscanf(\"%d\",&N);\r\tll o = 0;\r\tvector<ll> vs;\r\t\
    rep(i,N){\r\t\tll x,y;\r\t\tscanf(\"%lld%lld\",&x,&y);\r\t\to ^= x;\r\t\tvs.pb(x^y);\r\
    \t}\r\tmat A(60);\r\trep(i,N){\r\t\trep(j,60){\r\t\t\tA[j][i] = B(vs[i],j);\r\t\
    \t}\r\t}\r\tvector<bool> b(60);\r\trep(j,60) b[j] = B(o,j);\r\tint r = getrank(A,b,N);\r\
    \tif(r == -1){\r\t\tputs(\"1/1\");\r\t\treturn 0;\r\t}\r\tcout << (1LL<<r)-1 <<\
    \ \"/\" << (1LL<<r) <<endl;\r}\r\n"
  code: "/*\rAx = b mod 2\r\u306E\u89E3\u304C\u4F55\u500B\u3042\u308B\u304B\r\rN\u5909\
    \u6570\u3067\u5F0F\u304CM\u500B,\u3064\u307E\u308A A:M*N, x:N, b:M\r\rres = -1\
    \ -> 0\u500B\rotherwise -> 2^(N-r)\u500B\r\r\u305F\u3060rank\u3092\u6C42\u3081\
    \u305F\u3044\u6642(b\u304C\u306A\u3044\u3068\u304D) \u306F b\u306B\u95A2\u3059\
    \u308B\u90E8\u5206\u3092\u6D88\u305B\u3070\u826F\u3044.\r\rO(NM min(N,M) / 32)\t\
    (j\u306E\u30EB\u30FC\u30D7\u304Cmin(N,M)\u56DE)\r\rverified: http://codeforces.com/contest/662/problem/C\r\
    \r*/\r\rconst int MN = ;\rtypedef bitset<MN> Bs;\rtypedef vector<Bs> mat;\rint\
    \ getrank(mat A, vector<bool> b,int N){\r\tassert(A.size() == b.size());\r\r\t\
    int M = b.size();\r\r\tint res=0;\r\tvector<bool> used(M,false);\r\r\trep(j,N){\r\
    \t\tint i = 0;\r\t\twhile( (i < M) && (used[i] || !A[i][j]) ) i++;\r\t\tif(i ==\
    \ M) continue;\r\t\tres++;\r\t\tused[i] = 1;\r\t\trep(k,M) if(!used[k]&&A[k][j]){\r\
    \t\t\tA[k]^=A[i];\r\t\t\tb[k]=b[k]^b[i];\r\t\t}\r\t}\r\trep(i,M) if(!used[i] &&\
    \ b[i] ) return -1;\r\treturn res;\r}\rtypedef long long ll;\rbool B(ll x,int\
    \ i){return (x>>i)&1;}\r\rint main(){\r\tint N;\r\tscanf(\"%d\",&N);\r\tll o =\
    \ 0;\r\tvector<ll> vs;\r\trep(i,N){\r\t\tll x,y;\r\t\tscanf(\"%lld%lld\",&x,&y);\r\
    \t\to ^= x;\r\t\tvs.pb(x^y);\r\t}\r\tmat A(60);\r\trep(i,N){\r\t\trep(j,60){\r\
    \t\t\tA[j][i] = B(vs[i],j);\r\t\t}\r\t}\r\tvector<bool> b(60);\r\trep(j,60) b[j]\
    \ = B(o,j);\r\tint r = getrank(A,b,N);\r\tif(r == -1){\r\t\tputs(\"1/1\");\r\t\
    \treturn 0;\r\t}\r\tcout << (1LL<<r)-1 << \"/\" << (1LL<<r) <<endl;\r}\r"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/rank_mod2.cpp
  requiredBy: []
  timestamp: '2018-09-18 03:14:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix/rank_mod2.cpp
layout: document
redirect_from:
- /library/math/matrix/rank_mod2.cpp
- /library/math/matrix/rank_mod2.cpp.html
title: math/matrix/rank_mod2.cpp
---
