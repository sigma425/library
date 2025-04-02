---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_oj/factorization.test.cpp
    title: test_oj/factorization.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/factorization.hpp\"\n/*\r\n\t\u7D20\u56E0\u6570\u5206\
    \u89E3 1 <= n <= 10^18\r\n\tpollard_rho's algorithm\r\n\tO(n^0.25 polylog(n))\
    \ \u304F\u3089\u3044\u3089\u3057\u3044\r\n*/\r\n\r\ntemplate<class T>\r\nT gcd(T\
    \ a,T b){\r\n\ta = abs(a), b = abs(b);\r\n\tif(b==0) return a;\r\n\treturn gcd(b,a%b);\r\
    \n}\r\ntemplate<class T, class U>\r\nT pow_mod(T x, U p, T mod){\r\n\tassert(p>=0);\r\
    \n\tx %= mod;\r\n\tT a = 1 % mod;\r\n\twhile(p){\r\n\t\tif(p&1) a = a*x%mod;\r\
    \n\t\tx = x*x%mod;\r\n\t\tp >>= 1;\r\n\t}\r\n\treturn a;\r\n}\r\nusing ll = long\
    \ long;\r\nbool isprime(ll n){\r\n\tif(n<=1) return 0;\r\n\tif(n==2) return 1;\r\
    \n\tif(n%2==0) return 0;\r\n\tll d = n-1;\r\n\twhile(d%2==0) d/=2;\r\n\tstatic\
    \ const vector<ll> alist{2,3,5,7,11,13,17,19,23,29,31,37};\r\n\tfor(ll a: alist){\r\
    \n\t\tif(n<=a) break;\r\n\t\tll t = d;\r\n\t\tll y = pow_mod<__int128>(a,t,n);\r\
    \n\t\twhile(t!=n-1 && y!=1 && y!=n-1){\r\n\t\t\ty = __int128(y)*y%n;\r\n\t\t\t\
    t<<=1;\r\n\t\t}\r\n\t\tif(y!=n-1 && t%2==0) return 0;\r\n\t}\r\n\treturn 1;\r\n\
    }\r\n\r\nll pollard_single(ll n){\r\n\tif(isprime(n)) return n;\r\n\tif(!(n&1))\
    \ return 2;\r\n\tll ph,x,y,p;\r\n\tauto f = [&](ll x, ll n){ return (__int128(x)*x+ph)%n;\
    \ };\r\n\tfor(ph=1;;ph++){\r\n\t\tx=ph; y=f(x,n); p=gcd(y-x,n);\r\n\t\twhile(p==1){\r\
    \n\t\t\tx=f(x,n); y=f(f(y,n),n); p=gcd((y-x+n)%n,n)%n;\r\n\t\t}\r\n\t\tif(p==0\
    \ || p==n) continue;\r\n\t\treturn p;\r\n\t}\r\n\tassert(0);\r\n}\r\n\r\nvector<ll>\
    \ pollard(ll n){\r\n\tif(n==1) return {};\r\n\tll x = pollard_single(n);\r\n\t\
    if(x==n) return {x};\r\n\tvector<ll> le = pollard(x);\r\n\tvector<ll> ri = pollard(n/x);\r\
    \n\tfor(ll d: ri) le.push_back(d);\r\n\tsort(all(le));\r\n\treturn le;\r\n}\r\n\
    \r\nvector<pair<long long,int>> factorize(ll n){\r\n\tauto ps = pollard(n);\r\n\
    \tsort(all(ps));\r\n\tmap<ll,int> mp;\r\n\tfor(ll p: ps) mp[p]++;\r\n\tvector<pair<ll,int>>\
    \ res;\r\n\tfor(auto [p,r]: mp) res.emplace_back(p,r);\r\n\treturn res;\r\n}\r\
    \n\r\nll totient(ll n){\r\n\tauto v = pollard(n);\r\n\tmap<ll,int> mp; for(ll\
    \ p: v) mp[p]++;\r\n\tll phi = 1;\r\n\tfor(auto [p,r]: mp){\r\n\t\tfor(int _=0;_<r-1;_++)\
    \ phi *= p;\r\n\t\tphi *= p-1;\r\n\t}\r\n\treturn phi;\r\n}\r\n"
  code: "/*\r\n\t\u7D20\u56E0\u6570\u5206\u89E3 1 <= n <= 10^18\r\n\tpollard_rho's\
    \ algorithm\r\n\tO(n^0.25 polylog(n)) \u304F\u3089\u3044\u3089\u3057\u3044\r\n\
    */\r\n\r\ntemplate<class T>\r\nT gcd(T a,T b){\r\n\ta = abs(a), b = abs(b);\r\n\
    \tif(b==0) return a;\r\n\treturn gcd(b,a%b);\r\n}\r\ntemplate<class T, class U>\r\
    \nT pow_mod(T x, U p, T mod){\r\n\tassert(p>=0);\r\n\tx %= mod;\r\n\tT a = 1 %\
    \ mod;\r\n\twhile(p){\r\n\t\tif(p&1) a = a*x%mod;\r\n\t\tx = x*x%mod;\r\n\t\t\
    p >>= 1;\r\n\t}\r\n\treturn a;\r\n}\r\nusing ll = long long;\r\nbool isprime(ll\
    \ n){\r\n\tif(n<=1) return 0;\r\n\tif(n==2) return 1;\r\n\tif(n%2==0) return 0;\r\
    \n\tll d = n-1;\r\n\twhile(d%2==0) d/=2;\r\n\tstatic const vector<ll> alist{2,3,5,7,11,13,17,19,23,29,31,37};\r\
    \n\tfor(ll a: alist){\r\n\t\tif(n<=a) break;\r\n\t\tll t = d;\r\n\t\tll y = pow_mod<__int128>(a,t,n);\r\
    \n\t\twhile(t!=n-1 && y!=1 && y!=n-1){\r\n\t\t\ty = __int128(y)*y%n;\r\n\t\t\t\
    t<<=1;\r\n\t\t}\r\n\t\tif(y!=n-1 && t%2==0) return 0;\r\n\t}\r\n\treturn 1;\r\n\
    }\r\n\r\nll pollard_single(ll n){\r\n\tif(isprime(n)) return n;\r\n\tif(!(n&1))\
    \ return 2;\r\n\tll ph,x,y,p;\r\n\tauto f = [&](ll x, ll n){ return (__int128(x)*x+ph)%n;\
    \ };\r\n\tfor(ph=1;;ph++){\r\n\t\tx=ph; y=f(x,n); p=gcd(y-x,n);\r\n\t\twhile(p==1){\r\
    \n\t\t\tx=f(x,n); y=f(f(y,n),n); p=gcd((y-x+n)%n,n)%n;\r\n\t\t}\r\n\t\tif(p==0\
    \ || p==n) continue;\r\n\t\treturn p;\r\n\t}\r\n\tassert(0);\r\n}\r\n\r\nvector<ll>\
    \ pollard(ll n){\r\n\tif(n==1) return {};\r\n\tll x = pollard_single(n);\r\n\t\
    if(x==n) return {x};\r\n\tvector<ll> le = pollard(x);\r\n\tvector<ll> ri = pollard(n/x);\r\
    \n\tfor(ll d: ri) le.push_back(d);\r\n\tsort(all(le));\r\n\treturn le;\r\n}\r\n\
    \r\nvector<pair<long long,int>> factorize(ll n){\r\n\tauto ps = pollard(n);\r\n\
    \tsort(all(ps));\r\n\tmap<ll,int> mp;\r\n\tfor(ll p: ps) mp[p]++;\r\n\tvector<pair<ll,int>>\
    \ res;\r\n\tfor(auto [p,r]: mp) res.emplace_back(p,r);\r\n\treturn res;\r\n}\r\
    \n\r\nll totient(ll n){\r\n\tauto v = pollard(n);\r\n\tmap<ll,int> mp; for(ll\
    \ p: v) mp[p]++;\r\n\tll phi = 1;\r\n\tfor(auto [p,r]: mp){\r\n\t\tfor(int _=0;_<r-1;_++)\
    \ phi *= p;\r\n\t\tphi *= p-1;\r\n\t}\r\n\treturn phi;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/factorization.hpp
  requiredBy: []
  timestamp: '2025-04-03 01:59:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_oj/factorization.test.cpp
documentation_of: math/factorization.hpp
layout: document
redirect_from:
- /library/math/factorization.hpp
- /library/math/factorization.hpp.html
title: math/factorization.hpp
---
