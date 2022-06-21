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
  bundledCode: "#line 1 \"math/gcd.cpp\"\n/*\n\treturn:\n\t\tg = gcd(a, b) >= 0\n\t\
    \tx,y s.t.\n\t\t\tax + by = g\n\t\t\tif b == 0:\n\t\t\t\t(1,0) or (-1,0)\n\t\t\
    \telse:\n\t\t\t\t0 <= x < abs(b)/g\n\t\t\t\t(uniquely exists)\n\tnote:\n\t\t{(x,y)|ax+by=g}\
    \ = (x,y) + t(b/g,-a/g)\t\tif (a,b) \\neq (0,0)\n*/\nstruct EG { ll g, x, y; };\n\
    EG extGcdSub(ll a, ll b) {\n\tif(b == 0){\n\t\tif (a >= 0) return EG{a, 1, 0};\n\
    \t\telse return EG{-a, -1, 0};\n\t}else{\n\t\tauto e = extGcdSub(b, a % b);\n\t\
    \treturn EG{e.g, e.y, e.x - a / b * e.y};\n\t}\n}\nEG extGcd(ll a,ll b){\n\tauto\
    \ e = extGcdSub(a,b);\n\tif(e.x < 0){\n\t\tif(b > 0){\n\t\t\te.x += b/e.g;\n\t\
    \t\te.y -= a/e.g;\n\t\t}else{\n\t\t\te.x -= b/e.g;\n\t\t\te.y += a/e.g;\n\t\t\
    }\n\t}\n\treturn e;\n}\nvoid test(){\n\tfor(ll a=-10;a<=10;a++){\n\t\tfor(ll b=-10;b<=10;b++){\n\
    \t\t\tif(b==0) continue;\n\t\t\tauto e = extGcd(a,b);\n\t\t\tshow(a);show(b);show(e.x);show(e.y);show(e.g);\n\
    \t\t\tassert(a*e.x+b*e.y == e.g);\n\t\t\tassert(0 <= e.g);\n\t\t\tassert(0 <=\
    \ e.x && e.x < abs(b)/e.g);\n\t\t}\n\t}\n\tcout << \"OK\" << endl;\t// OK\n}\n\
    /*\n\txz + md? = g\n*/\nll inv_mod(ll x, ll md) {\n\tauto z = ext_gcd(x, md).x;\n\
    \treturn (z % md + md) % md;\n}\n\n/*\n\t(rem,mod) 0 <= rem < mod\n\tmod \u304C\
    \u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u5FC5\u8981\u306F\u306A\u3044\n\tno\
    \ -> (0,-1)\n\tverify: CF/724(IntelCodeFinal)/C.cpp\n\tTODO: garner \u306E mods\
    \ \u81EA\u7531\u30D0\u30FC\u30B8\u30E7\u30F3\n*/\npair<ll,ll> crt(const V<ll>&\
    \ rs, const V<ll>& ms){\n\tint N = rs.size();\n\tll r = 0, m = 1;\n\trep(i,N){\n\
    \t\tll ri = rs[i], mi = ms[i];\n\t\t// assert(0 <= ri && ri < mi);\n\t\tauto e\
    \ = ext_gcd(m,mi);\n\t\tll g = e.g, m_inv = e.x;\n\t\tif((ri-r)%g) return {0,-1};\n\
    \t\tll tmp = (ri-r)/g * m_inv % (mi/g);\n\t\tr += m * tmp;\n\t\tm *= mi / g;\n\
    \t}\n\treturn {(r%m+m)%m,m};\n}\n\n// binary gcd\nint bsf(ll x) { return __builtin_ctzll(x);\
    \ } \nll gcd(ll a, ll b){\n\ta = abs(a), b = abs(b);\n\tif(a==0) return b;\n\t\
    if(b==0) return a;\n\tint shift = bsf(a|b);\n\ta >>= bsf(a);\n\tdo{\n\t\tb >>=\
    \ bsf(b);\n\t\tif(a>b) swap(a,b);\n\t\tb -= a;\n\t}while(b);\n\treturn a<<shift;\n\
    }\n\n\n//\u2193\u975E\u518D\u5E30 extgcd\nll extgcd(ll a,ll b,ll &x,ll &y){\n\t\
    ll u[]={a,1,0},v[]={b,0,1};\n\twhile(*v){\n\t\tll t=*u/ *v;\n\t\trep(i,3) swap(u[i]-=t*v[i],v[i]);\n\
    \t}\n\tif(u[0]<0) rep(i,3) u[i]=-u[i];\n\tx=u[1],y=u[2];\n\treturn u[0];\n}\n"
  code: "/*\n\treturn:\n\t\tg = gcd(a, b) >= 0\n\t\tx,y s.t.\n\t\t\tax + by = g\n\t\
    \t\tif b == 0:\n\t\t\t\t(1,0) or (-1,0)\n\t\t\telse:\n\t\t\t\t0 <= x < abs(b)/g\n\
    \t\t\t\t(uniquely exists)\n\tnote:\n\t\t{(x,y)|ax+by=g} = (x,y) + t(b/g,-a/g)\t\
    \tif (a,b) \\neq (0,0)\n*/\nstruct EG { ll g, x, y; };\nEG extGcdSub(ll a, ll\
    \ b) {\n\tif(b == 0){\n\t\tif (a >= 0) return EG{a, 1, 0};\n\t\telse return EG{-a,\
    \ -1, 0};\n\t}else{\n\t\tauto e = extGcdSub(b, a % b);\n\t\treturn EG{e.g, e.y,\
    \ e.x - a / b * e.y};\n\t}\n}\nEG extGcd(ll a,ll b){\n\tauto e = extGcdSub(a,b);\n\
    \tif(e.x < 0){\n\t\tif(b > 0){\n\t\t\te.x += b/e.g;\n\t\t\te.y -= a/e.g;\n\t\t\
    }else{\n\t\t\te.x -= b/e.g;\n\t\t\te.y += a/e.g;\n\t\t}\n\t}\n\treturn e;\n}\n\
    void test(){\n\tfor(ll a=-10;a<=10;a++){\n\t\tfor(ll b=-10;b<=10;b++){\n\t\t\t\
    if(b==0) continue;\n\t\t\tauto e = extGcd(a,b);\n\t\t\tshow(a);show(b);show(e.x);show(e.y);show(e.g);\n\
    \t\t\tassert(a*e.x+b*e.y == e.g);\n\t\t\tassert(0 <= e.g);\n\t\t\tassert(0 <=\
    \ e.x && e.x < abs(b)/e.g);\n\t\t}\n\t}\n\tcout << \"OK\" << endl;\t// OK\n}\n\
    /*\n\txz + md? = g\n*/\nll inv_mod(ll x, ll md) {\n\tauto z = ext_gcd(x, md).x;\n\
    \treturn (z % md + md) % md;\n}\n\n/*\n\t(rem,mod) 0 <= rem < mod\n\tmod \u304C\
    \u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u5FC5\u8981\u306F\u306A\u3044\n\tno\
    \ -> (0,-1)\n\tverify: CF/724(IntelCodeFinal)/C.cpp\n\tTODO: garner \u306E mods\
    \ \u81EA\u7531\u30D0\u30FC\u30B8\u30E7\u30F3\n*/\npair<ll,ll> crt(const V<ll>&\
    \ rs, const V<ll>& ms){\n\tint N = rs.size();\n\tll r = 0, m = 1;\n\trep(i,N){\n\
    \t\tll ri = rs[i], mi = ms[i];\n\t\t// assert(0 <= ri && ri < mi);\n\t\tauto e\
    \ = ext_gcd(m,mi);\n\t\tll g = e.g, m_inv = e.x;\n\t\tif((ri-r)%g) return {0,-1};\n\
    \t\tll tmp = (ri-r)/g * m_inv % (mi/g);\n\t\tr += m * tmp;\n\t\tm *= mi / g;\n\
    \t}\n\treturn {(r%m+m)%m,m};\n}\n\n// binary gcd\nint bsf(ll x) { return __builtin_ctzll(x);\
    \ } \nll gcd(ll a, ll b){\n\ta = abs(a), b = abs(b);\n\tif(a==0) return b;\n\t\
    if(b==0) return a;\n\tint shift = bsf(a|b);\n\ta >>= bsf(a);\n\tdo{\n\t\tb >>=\
    \ bsf(b);\n\t\tif(a>b) swap(a,b);\n\t\tb -= a;\n\t}while(b);\n\treturn a<<shift;\n\
    }\n\n\n//\u2193\u975E\u518D\u5E30 extgcd\nll extgcd(ll a,ll b,ll &x,ll &y){\n\t\
    ll u[]={a,1,0},v[]={b,0,1};\n\twhile(*v){\n\t\tll t=*u/ *v;\n\t\trep(i,3) swap(u[i]-=t*v[i],v[i]);\n\
    \t}\n\tif(u[0]<0) rep(i,3) u[i]=-u[i];\n\tx=u[1],y=u[2];\n\treturn u[0];\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/gcd.cpp
  requiredBy: []
  timestamp: '2022-06-22 06:46:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/gcd.cpp
layout: document
redirect_from:
- /library/math/gcd.cpp
- /library/math/gcd.cpp.html
title: math/gcd.cpp
---
