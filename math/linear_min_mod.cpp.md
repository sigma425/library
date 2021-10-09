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
  bundledCode: "#line 1 \"math/linear_min_mod.cpp\"\n\r\n/*\r\n\tFirstHitMod(a,m,l,r)\r\
    \n\t0%m, a%m, 2a%m, ... \u306E\u3046\u3061\u3001\u6700\u521D\u306B [l,r] \u306B\
    \u542B\u307E\u308C\u308B\u3082\u306E(\u3092a*x\u3068\u3057\u305F\u3068\u304D\u306B\
    \u3001x)\u3092\u8FD4\u3059\r\n\t\u306A\u3044\u306A\u3089-1\r\n\tm > 0\r\n\ta,m,l,r\
    \ <= 10^18 \u304F\u3089\u3044\u307E\u3067OK\r\n\tO(log m)\r\n\tverified: \u30B9\
    \u30C8\u30EC\u30B9\u30C6\u30B9\u30C8\r\n*/\r\n\r\nll getAXmodB(ll a,ll b,ll lw,ll\
    \ up){\r\n\tif(lw == 0) return 0;\r\n\tif(a == 0) return -1;\r\n\tll p = (lw+a-1)/a*a;\r\
    \n\tif(lw<=p && p<=up) return p;\r\n\tll res = getAXmodB(b%a,a,p-up,p-lw);\r\n\
    \tif(res == -1) return -1;\r\n\treturn p-res;\r\n}\r\nstruct EG { ll g, x, y;\
    \ };\r\nEG ext_gcd(ll a, ll b) {\r\n\tif(b == 0){\r\n\t\tif (a >= 0) return EG{a,\
    \ 1, 0};\r\n\t\telse return EG{-a, -1, 0};\r\n\t}else{\r\n\t\tauto e = ext_gcd(b,\
    \ a % b);\r\n\t\treturn EG{e.g, e.y, e.x - a / b * e.y};\r\n\t}\r\n}\r\nll inv_mod(ll\
    \ x, ll md) {\r\n\tauto z = ext_gcd(x, md).x;\r\n\treturn (z % md + md) % md;\r\
    \n}\r\n\r\nll FirstHitMod(ll a,ll m,ll l,ll r){\r\n\tchmax(l,0); chmin(r,m-1);\r\
    \n\tif(l > r) return -1;\r\n\tassert(m > 0);\r\n\ta = ((a%m)+m)%m;\r\n\t\r\n\t\
    ll ax = getAXmodB(a,m,l,r);\r\n\tif(ax == -1) return -1;\r\n\tauto e = ext_gcd(a,m);\r\
    \n\tll g = e.g;\r\n\ta/=g,ax/=g,m/=g;\r\n\treturn __int128((e.x+m)%m)*ax%m;\r\n\
    }\r\n\r\n\r\n// ll brute(ll a,ll m,ll l,ll r){\r\n// \tfor(int i=0;;i++){\r\n\
    // \t\tint v = (i*a%m+m)%m;\r\n// \t\tif(i>0 && v==0) return -1;\r\n// \t\tif(l<=v\
    \ && v<=r) return i;\r\n// \t}\r\n// \tassert(0);\r\n// }\r\n\r\n// int main(){\r\
    \n// \tcin.tie(0);\r\n// \tios::sync_with_stdio(false);\t\t//DON'T USE scanf/printf/puts\
    \ !!\r\n// \tcout << fixed << setprecision(20);\r\n\r\n// \tint X; cin >> X;\r\
    \n// \trep1(m,X){\r\n// \t\tfor(int a=-X;a<=X;a++){\r\n// \t\t\tfor(int l=-X;l<=X;l++){\r\
    \n// \t\t\t\tfor(int r=-X;r<=X;r++){\r\n// \t\t\t\t\tif(FirstHitMod(a,m,l,r) !=\
    \ brute(a,m,l,r)){\r\n// \t\t\t\t\t\tshows(a,m,l,r);\r\n// \t\t\t\t\t\tshow(FirstHitMod(a,m,l,r));\r\
    \n// \t\t\t\t\t\tshow(brute(a,m,l,r));\r\n// \t\t\t\t\t\tassert(0);\r\n// \t\t\
    \t\t\t}\r\n// \t\t\t\t}\r\n// \t\t\t}\r\n// \t\t}\r\n// \t}\r\n// }\r\n"
  code: "\r\n/*\r\n\tFirstHitMod(a,m,l,r)\r\n\t0%m, a%m, 2a%m, ... \u306E\u3046\u3061\
    \u3001\u6700\u521D\u306B [l,r] \u306B\u542B\u307E\u308C\u308B\u3082\u306E(\u3092\
    a*x\u3068\u3057\u305F\u3068\u304D\u306B\u3001x)\u3092\u8FD4\u3059\r\n\t\u306A\u3044\
    \u306A\u3089-1\r\n\tm > 0\r\n\ta,m,l,r <= 10^18 \u304F\u3089\u3044\u307E\u3067\
    OK\r\n\tO(log m)\r\n\tverified: \u30B9\u30C8\u30EC\u30B9\u30C6\u30B9\u30C8\r\n\
    */\r\n\r\nll getAXmodB(ll a,ll b,ll lw,ll up){\r\n\tif(lw == 0) return 0;\r\n\t\
    if(a == 0) return -1;\r\n\tll p = (lw+a-1)/a*a;\r\n\tif(lw<=p && p<=up) return\
    \ p;\r\n\tll res = getAXmodB(b%a,a,p-up,p-lw);\r\n\tif(res == -1) return -1;\r\
    \n\treturn p-res;\r\n}\r\nstruct EG { ll g, x, y; };\r\nEG ext_gcd(ll a, ll b)\
    \ {\r\n\tif(b == 0){\r\n\t\tif (a >= 0) return EG{a, 1, 0};\r\n\t\telse return\
    \ EG{-a, -1, 0};\r\n\t}else{\r\n\t\tauto e = ext_gcd(b, a % b);\r\n\t\treturn\
    \ EG{e.g, e.y, e.x - a / b * e.y};\r\n\t}\r\n}\r\nll inv_mod(ll x, ll md) {\r\n\
    \tauto z = ext_gcd(x, md).x;\r\n\treturn (z % md + md) % md;\r\n}\r\n\r\nll FirstHitMod(ll\
    \ a,ll m,ll l,ll r){\r\n\tchmax(l,0); chmin(r,m-1);\r\n\tif(l > r) return -1;\r\
    \n\tassert(m > 0);\r\n\ta = ((a%m)+m)%m;\r\n\t\r\n\tll ax = getAXmodB(a,m,l,r);\r\
    \n\tif(ax == -1) return -1;\r\n\tauto e = ext_gcd(a,m);\r\n\tll g = e.g;\r\n\t\
    a/=g,ax/=g,m/=g;\r\n\treturn __int128((e.x+m)%m)*ax%m;\r\n}\r\n\r\n\r\n// ll brute(ll\
    \ a,ll m,ll l,ll r){\r\n// \tfor(int i=0;;i++){\r\n// \t\tint v = (i*a%m+m)%m;\r\
    \n// \t\tif(i>0 && v==0) return -1;\r\n// \t\tif(l<=v && v<=r) return i;\r\n//\
    \ \t}\r\n// \tassert(0);\r\n// }\r\n\r\n// int main(){\r\n// \tcin.tie(0);\r\n\
    // \tios::sync_with_stdio(false);\t\t//DON'T USE scanf/printf/puts !!\r\n// \t\
    cout << fixed << setprecision(20);\r\n\r\n// \tint X; cin >> X;\r\n// \trep1(m,X){\r\
    \n// \t\tfor(int a=-X;a<=X;a++){\r\n// \t\t\tfor(int l=-X;l<=X;l++){\r\n// \t\t\
    \t\tfor(int r=-X;r<=X;r++){\r\n// \t\t\t\t\tif(FirstHitMod(a,m,l,r) != brute(a,m,l,r)){\r\
    \n// \t\t\t\t\t\tshows(a,m,l,r);\r\n// \t\t\t\t\t\tshow(FirstHitMod(a,m,l,r));\r\
    \n// \t\t\t\t\t\tshow(brute(a,m,l,r));\r\n// \t\t\t\t\t\tassert(0);\r\n// \t\t\
    \t\t\t}\r\n// \t\t\t\t}\r\n// \t\t\t}\r\n// \t\t}\r\n// \t}\r\n// }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/linear_min_mod.cpp
  requiredBy: []
  timestamp: '2021-10-10 03:40:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/linear_min_mod.cpp
layout: document
redirect_from:
- /library/math/linear_min_mod.cpp
- /library/math/linear_min_mod.cpp.html
title: math/linear_min_mod.cpp
---
