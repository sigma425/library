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
  bundledCode: "#line 1 \"math/linear_min_mod.cpp\"\n/*\r\n\tlw <= ax mod b <= up\
    \ \u306A\u308B x \u306B\u5BFE\u3057\u3001\r\n\tgetAXmodB : ax \u3092\u8FD4\u3059\
    \r\n\tgetMin : x\u3092\u8FD4\u3059\r\n\r\n\tverified : \u624B\u5143\r\n*/\r\n\r\
    \n/*\r\n\t!!! return ax mod b !!! where x is\r\n\tmin x>=0 s.t. lw <= ax mod b\
    \ <= up\r\n\tno -> -1\r\n\r\n\tgcd\u3068\u5B8C\u5168\u306B\u4E00\u7DD2\u3001\u4E0A\
    \u9650ll,O(log)\r\n*/\r\nll getAXmodB(ll a,ll b,ll lw,ll up){\r\n\tif(lw == 0)\
    \ return 0;\r\n\tif(a == 0) return -1;\r\n\tll p = (lw+a-1)/a*a;\r\n\tif(lw<=p\
    \ && p<=up) return p;\r\n\tll res = getAXmodB(b%a,a,p-up,p-lw);\r\n\tif(res ==\
    \ -1) return -1;\r\n\treturn p-res;\r\n}\r\nstruct EG { ll g, x, y; };\r\nEG ext_gcd(ll\
    \ a, ll b) {\r\n\tif(b == 0){\r\n\t\tif (a >= 0) return EG{a, 1, 0};\r\n\t\telse\
    \ return EG{-a, -1, 0};\r\n\t}else{\r\n\t\tauto e = ext_gcd(b, a % b);\r\n\t\t\
    return EG{e.g, e.y, e.x - a / b * e.y};\r\n\t}\r\n}\r\nll inv_mod(ll x, ll md)\
    \ {\r\n\tauto z = ext_gcd(x, md).x;\r\n\treturn (z % md + md) % md;\r\n}\r\n\r\
    \n/*\r\n\t!!! return x !!! where x is\r\n\tmin x>=0 s.t. lw <= ax mod b <= up\r\
    \n\tno -> -1\r\n\r\n\tgcd\u3068\u5B8C\u5168\u306B\u4E00\u7DD2\u3001\u4E0A\u9650\
    ll,O(log)\r\n\r\n\tgetaxmodb\u306E2.5\u500D\u304F\u3089\u3044\u9045\u3044\u304B\
    \u3089\u3001\u307B\u3057\u3044\u3068\u304D\u3060\u3051\u3053\u3063\u3061\r\n*/\r\
    \nll getMin(ll a,ll b,ll lw,ll up){\r\n\tassert(a >= 0 && b > 0 && 0 <= lw &&\
    \ lw <= up && up < b);\r\n\tll ax = getAXmodB(a,b,lw,up);\r\n\tif(ax == -1) return\
    \ -1;\r\n\tauto e = ext_gcd(a,b);\r\n\tll g = e.g;\r\n\ta/=g,ax/=g,b/=g;\r\n\t\
    return __int128((e.x+b)%b)*ax%b;\r\n}\r\n"
  code: "/*\r\n\tlw <= ax mod b <= up \u306A\u308B x \u306B\u5BFE\u3057\u3001\r\n\t\
    getAXmodB : ax \u3092\u8FD4\u3059\r\n\tgetMin : x\u3092\u8FD4\u3059\r\n\r\n\t\
    verified : \u624B\u5143\r\n*/\r\n\r\n/*\r\n\t!!! return ax mod b !!! where x is\r\
    \n\tmin x>=0 s.t. lw <= ax mod b <= up\r\n\tno -> -1\r\n\r\n\tgcd\u3068\u5B8C\u5168\
    \u306B\u4E00\u7DD2\u3001\u4E0A\u9650ll,O(log)\r\n*/\r\nll getAXmodB(ll a,ll b,ll\
    \ lw,ll up){\r\n\tif(lw == 0) return 0;\r\n\tif(a == 0) return -1;\r\n\tll p =\
    \ (lw+a-1)/a*a;\r\n\tif(lw<=p && p<=up) return p;\r\n\tll res = getAXmodB(b%a,a,p-up,p-lw);\r\
    \n\tif(res == -1) return -1;\r\n\treturn p-res;\r\n}\r\nstruct EG { ll g, x, y;\
    \ };\r\nEG ext_gcd(ll a, ll b) {\r\n\tif(b == 0){\r\n\t\tif (a >= 0) return EG{a,\
    \ 1, 0};\r\n\t\telse return EG{-a, -1, 0};\r\n\t}else{\r\n\t\tauto e = ext_gcd(b,\
    \ a % b);\r\n\t\treturn EG{e.g, e.y, e.x - a / b * e.y};\r\n\t}\r\n}\r\nll inv_mod(ll\
    \ x, ll md) {\r\n\tauto z = ext_gcd(x, md).x;\r\n\treturn (z % md + md) % md;\r\
    \n}\r\n\r\n/*\r\n\t!!! return x !!! where x is\r\n\tmin x>=0 s.t. lw <= ax mod\
    \ b <= up\r\n\tno -> -1\r\n\r\n\tgcd\u3068\u5B8C\u5168\u306B\u4E00\u7DD2\u3001\
    \u4E0A\u9650ll,O(log)\r\n\r\n\tgetaxmodb\u306E2.5\u500D\u304F\u3089\u3044\u9045\
    \u3044\u304B\u3089\u3001\u307B\u3057\u3044\u3068\u304D\u3060\u3051\u3053\u3063\
    \u3061\r\n*/\r\nll getMin(ll a,ll b,ll lw,ll up){\r\n\tassert(a >= 0 && b > 0\
    \ && 0 <= lw && lw <= up && up < b);\r\n\tll ax = getAXmodB(a,b,lw,up);\r\n\t\
    if(ax == -1) return -1;\r\n\tauto e = ext_gcd(a,b);\r\n\tll g = e.g;\r\n\ta/=g,ax/=g,b/=g;\r\
    \n\treturn __int128((e.x+b)%b)*ax%b;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/linear_min_mod.cpp
  requiredBy: []
  timestamp: '2020-04-18 18:18:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/linear_min_mod.cpp
layout: document
redirect_from:
- /library/math/linear_min_mod.cpp
- /library/math/linear_min_mod.cpp.html
title: math/linear_min_mod.cpp
---
