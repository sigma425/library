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
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2387
  bundledCode: "#line 1 \"math/linear_min_mod.cpp\"\n/*\r\n\tx = min{ 0 <= i | l <=\
    \ a*i%m <= r}\r\n\tax = a*x % m\r\n\t\u306A\u3044\u306A\u3089-1\r\n\tm > 0\r\n\
    \ta,m,l,r <= 10^18 \u304F\u3089\u3044\u307E\u3067OK\r\n\tO(log m)\r\n\tverify:\
    \ \u30B9\u30C8\u30EC\u30B9\u30C6\u30B9\u30C8\r\n*/\r\n\r\n/*\r\n\tx = min{ 0 <=\
    \ i | l <= a*i%m <= r}\r\n\tax = a*x % m\r\n\t\u306A\u3044\u306A\u3089-1\r\n\t\
    m > 0\r\n\ta,m,l,r <= 10^18 \u304F\u3089\u3044\u307E\u3067OK\r\n\tO(log m)\r\n\
    \tverified: \u30B9\u30C8\u30EC\u30B9\u30C6\u30B9\u30C8\r\n*/\r\n\r\nstruct firstHitRem{\r\
    \n\tll x,ax;\r\n\tfirstHitRem(ll a,ll m,ll l,ll r){\r\n\t\tassert(m > 0);\r\n\t\
    \tchmax(l,0); chmin(r,m-1);\r\n\t\tif(l > r){\r\n\t\t\tx = ax = -1; return;\r\n\
    \t\t}\r\n\t\ta = ((a%m)+m)%m;\r\n\t\t\r\n\t\tax = getAXmodB(a,m,l,r);\r\n\t\t\
    if(ax == -1){\r\n\t\t\tx = ax = -1; return;\r\n\t\t}\r\n\t\tauto e = ext_gcd(a,m);\r\
    \n\t\tll g = e.g;\r\n\t\ta/=g, ax/=g, m/=g;\r\n\t\tx = __int128((e.x+m)%m)*ax%m;\r\
    \n\t\tax *= g;\r\n\t}\r\n\t\r\n\tll getAXmodB(ll a,ll b,ll lw,ll up){\r\n\t\t\
    if(lw == 0) return 0;\r\n\t\tif(a == 0) return -1;\r\n\t\tll p = (lw+a-1)/a*a;\r\
    \n\t\tif(lw<=p && p<=up) return p;\r\n\t\tll res = getAXmodB(b%a,a,p-up,p-lw);\r\
    \n\t\tif(res == -1) return -1;\r\n\t\treturn p-res;\r\n\t}\r\n\tstruct EG { ll\
    \ g, x, y; };\r\n\tEG ext_gcd(ll a, ll b) {\r\n\t\tif(b == 0){\r\n\t\t\tif (a\
    \ >= 0) return EG{a, 1, 0};\r\n\t\t\telse return EG{-a, -1, 0};\r\n\t\t}else{\r\
    \n\t\t\tauto e = ext_gcd(b, a % b);\r\n\t\t\treturn EG{e.g, e.y, e.x - a / b *\
    \ e.y};\r\n\t\t}\r\n\t}\r\n\tll inv_mod(ll v, ll md) {\r\n\t\tauto z = ext_gcd(v,\
    \ md).x;\r\n\t\treturn (z % md + md) % md;\r\n\t}\r\n};\r\n\r\n\r\n/*\r\n\tS =\
    \ {  ai%m | 1 <= i <= n }\r\n\tT = { -ai%m | 1 <= i <= n }\r\n\r\n\tx = S \u306E\
    \u6700\u5C0F\u5024\u3092\u3068\u308B i (\u306E\u3046\u3061\u6700\u5C0F)\r\n\t\
    y = T \u306E\u6700\u5C0F\u5024\u3092\u3068\u308B i (\u306E\u3046\u3061\u6700\u5C0F\
    )\r\n\tl = min S, r = min T\r\n\r\n\t\u5186\u74B0\u306B\u7B49\u5DEE\u6570\u5217\
    \u3063\u307D\u304F\u70B9\u3092\u7F6E\u3044\u3066\u3044\u3063\u305F\u3068\u304D\
    \u306E 0 \u304B\u3089\u306E\u5DE6\u53F3\u3078\u306E\u8DDD\u96E2\u3068\u3001\u305D\
    \u306Eindex\u307F\u305F\u3044\u306A\r\n\r\n\tO(log)\r\n\tverify: \u30B9\u30C8\u30EC\
    \u30B9\u30C6\u30B9\u30C8\r\n*/\r\nstruct minMaxRem{\r\n\tll x,y,l,r;\r\n\tminMaxRem(ll\
    \ a,ll m,ll n){\r\n\t\tassert(m > 0); assert(n > 0);\r\n\t\ta = (a%m+m)%m;\r\n\
    \t\tx = 1, y = 1, l = a, r = m-a;\r\n\t\tfor(ll k;;){\r\n\t\t\tif(l == 0){ y =\
    \ x; r = l; return; }\r\n\t\t\tk = r/l;\r\n\t\t\tif(chmin(k,(n-y)/x)) { y += k*x;\
    \ r -= k*l; return;}\r\n\t\t\ty += k*x; r -= k*l;\r\n\t\t\tif(!r){ x = y; l =\
    \ r; return; }\r\n\t\t\tk = l/r;\r\n\t\t\tif(chmin(k,(n-x)/y)) { x += k*y; l -=\
    \ k*r; return;}\r\n\t\t\tx += k*y; l -= k*r;\r\n\t\t}\r\n\t}\r\n};\r\n\r\n\r\n\
    /*\r\n\tthree-gap theorem\r\n\t0, a%m, .. , (n-1)a%m \u3092\u5186\u74B0\u4E0A\u306B\
    \u7F6E\u304D\u3001\u5404 x\\in [0,n) \u306B\u5BFE\u3057\u3066\u3001\u305D\u306E\
    \u70B9\u304B\u3089\u6B21\u306E\u70B9\u307E\u3067\u306E\u8DDD\u96E2\u3092\u6C42\
    \u3081\u308B d[x]\u3068\u3059\u308B\r\n\t\u5B9F\u306F d[0], .. , d[n-1] \u306F\
    \ p,..,p, p+q,..,p+q, q,..,q \u307F\u305F\u3044\u306A\u5F62\u3092\u3057\u3066\u3044\
    \u308B \u7279\u306B\u3001\u305F\u304B\u3060\u304B3\u7A2E\u985E\r\n\t{num,val}\
    \ \u306E vector \u3092\u8FD4\u3059\r\n\t\t- num > 0\r\n\t\t- \u540C\u3058val\u306F\
    \u9023\u7D9A\u3057\u306A\u3044\r\n\t\t- \\sum num = n\r\n\t\t- \\sum val = m\r\
    \n\r\n\t\u4E00\u5468\u3057\u30660\u3092\u3075\u3080\u3068\u304D\u3001\u3000\u3064\
    \u307E\u308A n-1 >= m/gcd(a,m) \u306E\u6642\u306F\u547C\u3093\u3058\u3083\u3060\
    \u3081\uFF01\uFF01\uFF01 assert\u3057\u3066\u3044\u308B\r\n\r\n\tO(log)\r\n\t\
    verify: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2387\r\n*/\r\
    \nV<pair<ll,ll>> threegap(ll a,ll m,ll n){\r\n\tusing P = pair<ll,ll>;\r\n\tassert(m\
    \ > 0); assert(n >= 1);\r\n\ta = (a%m+m)%m;\r\n\tassert(n-1 < m/__gcd(a,m));\t\
    \t\t\t// shouldn't have two points on the same place\r\n\tif(n == 1){\r\n\t\t\
    return {P(1,m)};\r\n\t}\r\n\tauto f = minMaxRem(a,m,n-1);\r\n\tll x = f.x, y =\
    \ f.y, l = f.l, r = f.r;\r\n\tP pre(n-x,l);\r\n\tP mid(n-(n-x)-(n-y),l+r);\r\n\
    \tP suf(n-y,r);\r\n\tV<P> res;\r\n\tfor(P p: {pre,mid,suf}) if(p.fs){\r\n\t\t\
    if(!res.empty() && res.back().sc == p.sc) res.back().fs += p.fs;\r\n\t\telse res.pb(p);\r\
    \n\t}\r\n\treturn res;\r\n}\r\n\r\n\r\n\r\n// \u304A\u307E\u3051\r\n\r\nvoid test_firstHitRem(){\r\
    \n\tauto brute = [&](ll a,ll m,ll l,ll r){\r\n\t\tfor(int i=0;;i++){\r\n\t\t\t\
    int v = (i*a%m+m)%m;\r\n\t\t\tif(i>0 && v==0) return pair<ll,ll>(-1,-1);\r\n\t\
    \t\tif(l<=v && v<=r) return pair<ll,ll>(i,v);\r\n\t\t}\r\n\t\tassert(0);\r\n\t\
    };\r\n\tint X = 50;\r\n\trep1(m,X){\r\n\t\tfor(int a=-X;a<=X;a++){\r\n\t\t\tfor(int\
    \ l=-X;l<=X;l++){\r\n\t\t\t\tfor(int r=-X;r<=X;r++){\r\n\t\t\t\t\tauto f = firstHitRem(a,m,l,r);\r\
    \n\t\t\t\t\tauto god = brute(a,m,l,r);\r\n\t\t\t\t\tassert(f.x == god.fs && f.ax\
    \ == god.sc);\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n}\r\n\r\n// O(log^2)\r\
    \nll getMinLinearMod(ll a,ll m,ll n){\r\n\tassert(n > 0);\r\n\tassert(m > 0);\r\
    \n\ta = (a%m+m)%m;\r\n\r\n\tif(m/gcd(a,m) <= n) return m/gcd(a,m);\r\n\tll lb\
    \ = 0, ub = m;\r\n\twhile(ub-lb>1){\r\n\t\tll mid = (ub+lb)/2;\r\n\t\tll x = FirstHitMod(a,m,1,mid);\r\
    \n\t\tif(x != -1 && x <= n) ub = mid;\r\n\t\telse lb = mid;\r\n\t}\r\n\t// ax\
    \ = ub\r\n\treturn FirstHitMod(a,m,1,ub);\r\n}\n"
  code: "/*\r\n\tx = min{ 0 <= i | l <= a*i%m <= r}\r\n\tax = a*x % m\r\n\t\u306A\u3044\
    \u306A\u3089-1\r\n\tm > 0\r\n\ta,m,l,r <= 10^18 \u304F\u3089\u3044\u307E\u3067\
    OK\r\n\tO(log m)\r\n\tverify: \u30B9\u30C8\u30EC\u30B9\u30C6\u30B9\u30C8\r\n*/\r\
    \n\r\n/*\r\n\tx = min{ 0 <= i | l <= a*i%m <= r}\r\n\tax = a*x % m\r\n\t\u306A\
    \u3044\u306A\u3089-1\r\n\tm > 0\r\n\ta,m,l,r <= 10^18 \u304F\u3089\u3044\u307E\
    \u3067OK\r\n\tO(log m)\r\n\tverified: \u30B9\u30C8\u30EC\u30B9\u30C6\u30B9\u30C8\
    \r\n*/\r\n\r\nstruct firstHitRem{\r\n\tll x,ax;\r\n\tfirstHitRem(ll a,ll m,ll\
    \ l,ll r){\r\n\t\tassert(m > 0);\r\n\t\tchmax(l,0); chmin(r,m-1);\r\n\t\tif(l\
    \ > r){\r\n\t\t\tx = ax = -1; return;\r\n\t\t}\r\n\t\ta = ((a%m)+m)%m;\r\n\t\t\
    \r\n\t\tax = getAXmodB(a,m,l,r);\r\n\t\tif(ax == -1){\r\n\t\t\tx = ax = -1; return;\r\
    \n\t\t}\r\n\t\tauto e = ext_gcd(a,m);\r\n\t\tll g = e.g;\r\n\t\ta/=g, ax/=g, m/=g;\r\
    \n\t\tx = __int128((e.x+m)%m)*ax%m;\r\n\t\tax *= g;\r\n\t}\r\n\t\r\n\tll getAXmodB(ll\
    \ a,ll b,ll lw,ll up){\r\n\t\tif(lw == 0) return 0;\r\n\t\tif(a == 0) return -1;\r\
    \n\t\tll p = (lw+a-1)/a*a;\r\n\t\tif(lw<=p && p<=up) return p;\r\n\t\tll res =\
    \ getAXmodB(b%a,a,p-up,p-lw);\r\n\t\tif(res == -1) return -1;\r\n\t\treturn p-res;\r\
    \n\t}\r\n\tstruct EG { ll g, x, y; };\r\n\tEG ext_gcd(ll a, ll b) {\r\n\t\tif(b\
    \ == 0){\r\n\t\t\tif (a >= 0) return EG{a, 1, 0};\r\n\t\t\telse return EG{-a,\
    \ -1, 0};\r\n\t\t}else{\r\n\t\t\tauto e = ext_gcd(b, a % b);\r\n\t\t\treturn EG{e.g,\
    \ e.y, e.x - a / b * e.y};\r\n\t\t}\r\n\t}\r\n\tll inv_mod(ll v, ll md) {\r\n\t\
    \tauto z = ext_gcd(v, md).x;\r\n\t\treturn (z % md + md) % md;\r\n\t}\r\n};\r\n\
    \r\n\r\n/*\r\n\tS = {  ai%m | 1 <= i <= n }\r\n\tT = { -ai%m | 1 <= i <= n }\r\
    \n\r\n\tx = S \u306E\u6700\u5C0F\u5024\u3092\u3068\u308B i (\u306E\u3046\u3061\
    \u6700\u5C0F)\r\n\ty = T \u306E\u6700\u5C0F\u5024\u3092\u3068\u308B i (\u306E\u3046\
    \u3061\u6700\u5C0F)\r\n\tl = min S, r = min T\r\n\r\n\t\u5186\u74B0\u306B\u7B49\
    \u5DEE\u6570\u5217\u3063\u307D\u304F\u70B9\u3092\u7F6E\u3044\u3066\u3044\u3063\
    \u305F\u3068\u304D\u306E 0 \u304B\u3089\u306E\u5DE6\u53F3\u3078\u306E\u8DDD\u96E2\
    \u3068\u3001\u305D\u306Eindex\u307F\u305F\u3044\u306A\r\n\r\n\tO(log)\r\n\tverify:\
    \ \u30B9\u30C8\u30EC\u30B9\u30C6\u30B9\u30C8\r\n*/\r\nstruct minMaxRem{\r\n\t\
    ll x,y,l,r;\r\n\tminMaxRem(ll a,ll m,ll n){\r\n\t\tassert(m > 0); assert(n > 0);\r\
    \n\t\ta = (a%m+m)%m;\r\n\t\tx = 1, y = 1, l = a, r = m-a;\r\n\t\tfor(ll k;;){\r\
    \n\t\t\tif(l == 0){ y = x; r = l; return; }\r\n\t\t\tk = r/l;\r\n\t\t\tif(chmin(k,(n-y)/x))\
    \ { y += k*x; r -= k*l; return;}\r\n\t\t\ty += k*x; r -= k*l;\r\n\t\t\tif(!r){\
    \ x = y; l = r; return; }\r\n\t\t\tk = l/r;\r\n\t\t\tif(chmin(k,(n-x)/y)) { x\
    \ += k*y; l -= k*r; return;}\r\n\t\t\tx += k*y; l -= k*r;\r\n\t\t}\r\n\t}\r\n\
    };\r\n\r\n\r\n/*\r\n\tthree-gap theorem\r\n\t0, a%m, .. , (n-1)a%m \u3092\u5186\
    \u74B0\u4E0A\u306B\u7F6E\u304D\u3001\u5404 x\\in [0,n) \u306B\u5BFE\u3057\u3066\
    \u3001\u305D\u306E\u70B9\u304B\u3089\u6B21\u306E\u70B9\u307E\u3067\u306E\u8DDD\
    \u96E2\u3092\u6C42\u3081\u308B d[x]\u3068\u3059\u308B\r\n\t\u5B9F\u306F d[0],\
    \ .. , d[n-1] \u306F p,..,p, p+q,..,p+q, q,..,q \u307F\u305F\u3044\u306A\u5F62\
    \u3092\u3057\u3066\u3044\u308B \u7279\u306B\u3001\u305F\u304B\u3060\u304B3\u7A2E\
    \u985E\r\n\t{num,val} \u306E vector \u3092\u8FD4\u3059\r\n\t\t- num > 0\r\n\t\t\
    - \u540C\u3058val\u306F\u9023\u7D9A\u3057\u306A\u3044\r\n\t\t- \\sum num = n\r\
    \n\t\t- \\sum val = m\r\n\r\n\t\u4E00\u5468\u3057\u30660\u3092\u3075\u3080\u3068\
    \u304D\u3001\u3000\u3064\u307E\u308A n-1 >= m/gcd(a,m) \u306E\u6642\u306F\u547C\
    \u3093\u3058\u3083\u3060\u3081\uFF01\uFF01\uFF01 assert\u3057\u3066\u3044\u308B\
    \r\n\r\n\tO(log)\r\n\tverify: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2387\r\
    \n*/\r\nV<pair<ll,ll>> threegap(ll a,ll m,ll n){\r\n\tusing P = pair<ll,ll>;\r\
    \n\tassert(m > 0); assert(n >= 1);\r\n\ta = (a%m+m)%m;\r\n\tassert(n-1 < m/__gcd(a,m));\t\
    \t\t\t// shouldn't have two points on the same place\r\n\tif(n == 1){\r\n\t\t\
    return {P(1,m)};\r\n\t}\r\n\tauto f = minMaxRem(a,m,n-1);\r\n\tll x = f.x, y =\
    \ f.y, l = f.l, r = f.r;\r\n\tP pre(n-x,l);\r\n\tP mid(n-(n-x)-(n-y),l+r);\r\n\
    \tP suf(n-y,r);\r\n\tV<P> res;\r\n\tfor(P p: {pre,mid,suf}) if(p.fs){\r\n\t\t\
    if(!res.empty() && res.back().sc == p.sc) res.back().fs += p.fs;\r\n\t\telse res.pb(p);\r\
    \n\t}\r\n\treturn res;\r\n}\r\n\r\n\r\n\r\n// \u304A\u307E\u3051\r\n\r\nvoid test_firstHitRem(){\r\
    \n\tauto brute = [&](ll a,ll m,ll l,ll r){\r\n\t\tfor(int i=0;;i++){\r\n\t\t\t\
    int v = (i*a%m+m)%m;\r\n\t\t\tif(i>0 && v==0) return pair<ll,ll>(-1,-1);\r\n\t\
    \t\tif(l<=v && v<=r) return pair<ll,ll>(i,v);\r\n\t\t}\r\n\t\tassert(0);\r\n\t\
    };\r\n\tint X = 50;\r\n\trep1(m,X){\r\n\t\tfor(int a=-X;a<=X;a++){\r\n\t\t\tfor(int\
    \ l=-X;l<=X;l++){\r\n\t\t\t\tfor(int r=-X;r<=X;r++){\r\n\t\t\t\t\tauto f = firstHitRem(a,m,l,r);\r\
    \n\t\t\t\t\tauto god = brute(a,m,l,r);\r\n\t\t\t\t\tassert(f.x == god.fs && f.ax\
    \ == god.sc);\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n}\r\n\r\n// O(log^2)\r\
    \nll getMinLinearMod(ll a,ll m,ll n){\r\n\tassert(n > 0);\r\n\tassert(m > 0);\r\
    \n\ta = (a%m+m)%m;\r\n\r\n\tif(m/gcd(a,m) <= n) return m/gcd(a,m);\r\n\tll lb\
    \ = 0, ub = m;\r\n\twhile(ub-lb>1){\r\n\t\tll mid = (ub+lb)/2;\r\n\t\tll x = FirstHitMod(a,m,1,mid);\r\
    \n\t\tif(x != -1 && x <= n) ub = mid;\r\n\t\telse lb = mid;\r\n\t}\r\n\t// ax\
    \ = ub\r\n\treturn FirstHitMod(a,m,1,ub);\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/linear_min_mod.cpp
  requiredBy: []
  timestamp: '2021-10-10 08:48:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/linear_min_mod.cpp
layout: document
redirect_from:
- /library/math/linear_min_mod.cpp
- /library/math/linear_min_mod.cpp.html
title: math/linear_min_mod.cpp
---
