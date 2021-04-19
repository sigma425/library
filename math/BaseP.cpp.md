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
  bundledCode: "#line 1 \"math/BaseP.cpp\"\n/*\r\n\tbase-10\u306Estring\u3092p\u9032\
    \u8868\u8A18\u306B\u3057\u305F\u306E\u3092\u8FD4\u3059 ret[0]\u304C1\u306E\u4F4D\
    \r\n\tO(L^2)\r\n*/\r\nvector<ll> Basep(string s,ll p){\r\n\tint L=s.size();\r\n\
    \tint up=4000;\r\n\tvector<ll> ret(up,0);\r\n\tint N=0;\r\n\trep(i,L){\r\n\t\t\
    rep(j,N) ret[j]*=10;\r\n\t\tret[0]+=s[i]-'0';\r\n\t\tint j=0;\r\n\t\twhile(j<N-1||ret[j]>=p){\r\
    \n\t\t\tret[j+1]+=ret[j]/p;\r\n\t\t\tret[j]%=p;\r\n\t\t\tj++;\r\n\t\t}\r\n\t\t\
    N=j+1;\r\n\t}\r\n\tret.erase(ret.begin()+N,ret.end());\r\n\treturn ret;\r\n}\r\
    \n"
  code: "/*\r\n\tbase-10\u306Estring\u3092p\u9032\u8868\u8A18\u306B\u3057\u305F\u306E\
    \u3092\u8FD4\u3059 ret[0]\u304C1\u306E\u4F4D\r\n\tO(L^2)\r\n*/\r\nvector<ll> Basep(string\
    \ s,ll p){\r\n\tint L=s.size();\r\n\tint up=4000;\r\n\tvector<ll> ret(up,0);\r\
    \n\tint N=0;\r\n\trep(i,L){\r\n\t\trep(j,N) ret[j]*=10;\r\n\t\tret[0]+=s[i]-'0';\r\
    \n\t\tint j=0;\r\n\t\twhile(j<N-1||ret[j]>=p){\r\n\t\t\tret[j+1]+=ret[j]/p;\r\n\
    \t\t\tret[j]%=p;\r\n\t\t\tj++;\r\n\t\t}\r\n\t\tN=j+1;\r\n\t}\r\n\tret.erase(ret.begin()+N,ret.end());\r\
    \n\treturn ret;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/BaseP.cpp
  requiredBy: []
  timestamp: '2018-09-18 03:14:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/BaseP.cpp
layout: document
redirect_from:
- /library/math/BaseP.cpp
- /library/math/BaseP.cpp.html
title: math/BaseP.cpp
---
