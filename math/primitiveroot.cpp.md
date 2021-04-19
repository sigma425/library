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
  bundledCode: "#line 1 \"math/primitiveroot.cpp\"\n/*\n\tZ/pZ \u539F\u59CB\u6839\u53D6\
    \u5F97\n\t2 <= p <= 10^18, p: prime\n\t\u539F\u59CB\u6839\u304B\u3069\u3046\u304B\
    \u306F\u3001\u5404p-1\u306E\u7D20\u56E0\u6570d\u306B\u5BFE\u3057\u3066\u3001g^\
    \ (p-1)/d != 1 \u304B\u3092\u5224\u5B9A\u3059\u308C\u3070\u3088\u3044\n\td\u306E\
    \u53D6\u5F97\u306Bfactorization.cpp \u3092\u4F7F\u3063\u3066\u308B\u3051\u3069\
    \u3082\u3063\u3068\u697D\u306B\u3067\u304D\u308B\u304B\u3082\n\n\tp\u7D20\u6570\
    \u3058\u3083\u306A\u3044\u5834\u5408\u3082\u540C\u69D8\u306B\u3067\u304D\u308B\
    \ phi(m) \u304C\u3044\u308B\u3051\u3069\u7D20\u56E0\u6570\u5206\u89E3\u3042\u308C\
    \u3070\u4F59\u88D5\n*/\n#include<bits/stdc++.h>\nusing namespace std;\n\ntemplate<class\
    \ T>\nT gcd(T a,T b){\n\ta = abs(a), b = abs(b);\n\tif(b==0) return a;\n\treturn\
    \ gcd(b,a%b);\n}\ntemplate<class T, class U>\nT pow_mod(T x, U p, T mod){\n\t\
    assert(p>=0);\n\tx %= mod;\n\tT a = 1 % mod;\n\twhile(p){\n\t\tif(p&1) a = a*x%mod;\n\
    \t\tx = x*x%mod;\n\t\tp >>= 1;\n\t}\n\treturn a;\n}\nusing ll = long long;\nbool\
    \ isprime(ll n){\n\tif(n<=1) return 0;\n\tif(n==2) return 1;\n\tif(n%2==0) return\
    \ 0;\n\tll d = n-1;\n\twhile(d%2==0) d/=2;\n\tstatic const vector<ll> alist{2,3,5,7,11,13,17,19,23,29,31,37};\n\
    \tfor(ll a: alist){\n\t\tif(n<=a) break;\n\t\tll t = d;\n\t\tll y = pow_mod<__int128>(a,t,n);\n\
    \t\twhile(t!=n-1 && y!=1 && y!=n-1){\n\t\t\ty = __int128(y)*y%n;\n\t\t\tt<<=1;\n\
    \t\t}\n\t\tif(y!=n-1 && t%2==0) return 0;\n\t}\n\treturn 1;\n}\n\nll f(ll x,ll\
    \ n){ return (__int128(x)*x+1)%n;}\nll pollard_single(ll n){\n\tif(isprime(n))\
    \ return n;\n\tif(!(n&1)) return 2;\n\tll i,x,y,p;\n\tfor(i=1;i<20;i++){\n\t\t\
    x=i; y=f(x,n); p=gcd(y-x,n);\n\t\twhile(p==1){\n\t\t\tx=f(x,n); y=f(f(y,n),n);\
    \ p=gcd((y-x+n)%n,n)%n;\n\t\t}\n\t\tif(p==0 || p==n) continue;\n\t\treturn p;\n\
    \t}\n\tassert(0);\n}\n\nvector<ll> pollard(ll n){\n\tif(n==1) return {};\n\tll\
    \ x = pollard_single(n);\n\tif(x==n) return {x};\n\tvector<ll> le = pollard(x);\n\
    \tvector<ll> ri = pollard(n/x);\n\tfor(ll d: ri) le.push_back(d);\n\treturn le;\n\
    }\nll primitiveroot(ll p){\n\tauto v = pollard(p-1);\n\tfor(ll g=1;;g++){\n\t\t\
    bool ok = 1;\n\t\tfor(auto d:v){\n\t\t\tll f = (p-1)/d;\n\t\t\tif(pow_mod<__int128>(g,f,p)\
    \ == 1){\n\t\t\t\tok = 0;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tif(ok) return g;\n\
    \t}\n}\n\nint main(){\n\twhile(true){\n\t\tll p;\n\t\tcin>>p;\n\t\tauto g = primitiveroot(p);\n\
    \t\tcout<<\"g = \"<<g<<endl;\n\t}\n}\n"
  code: "/*\n\tZ/pZ \u539F\u59CB\u6839\u53D6\u5F97\n\t2 <= p <= 10^18, p: prime\n\t\
    \u539F\u59CB\u6839\u304B\u3069\u3046\u304B\u306F\u3001\u5404p-1\u306E\u7D20\u56E0\
    \u6570d\u306B\u5BFE\u3057\u3066\u3001g^ (p-1)/d != 1 \u304B\u3092\u5224\u5B9A\u3059\
    \u308C\u3070\u3088\u3044\n\td\u306E\u53D6\u5F97\u306Bfactorization.cpp \u3092\u4F7F\
    \u3063\u3066\u308B\u3051\u3069\u3082\u3063\u3068\u697D\u306B\u3067\u304D\u308B\
    \u304B\u3082\n\n\tp\u7D20\u6570\u3058\u3083\u306A\u3044\u5834\u5408\u3082\u540C\
    \u69D8\u306B\u3067\u304D\u308B phi(m) \u304C\u3044\u308B\u3051\u3069\u7D20\u56E0\
    \u6570\u5206\u89E3\u3042\u308C\u3070\u4F59\u88D5\n*/\n#include<bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<class T>\nT gcd(T a,T b){\n\ta = abs(a), b =\
    \ abs(b);\n\tif(b==0) return a;\n\treturn gcd(b,a%b);\n}\ntemplate<class T, class\
    \ U>\nT pow_mod(T x, U p, T mod){\n\tassert(p>=0);\n\tx %= mod;\n\tT a = 1 % mod;\n\
    \twhile(p){\n\t\tif(p&1) a = a*x%mod;\n\t\tx = x*x%mod;\n\t\tp >>= 1;\n\t}\n\t\
    return a;\n}\nusing ll = long long;\nbool isprime(ll n){\n\tif(n<=1) return 0;\n\
    \tif(n==2) return 1;\n\tif(n%2==0) return 0;\n\tll d = n-1;\n\twhile(d%2==0) d/=2;\n\
    \tstatic const vector<ll> alist{2,3,5,7,11,13,17,19,23,29,31,37};\n\tfor(ll a:\
    \ alist){\n\t\tif(n<=a) break;\n\t\tll t = d;\n\t\tll y = pow_mod<__int128>(a,t,n);\n\
    \t\twhile(t!=n-1 && y!=1 && y!=n-1){\n\t\t\ty = __int128(y)*y%n;\n\t\t\tt<<=1;\n\
    \t\t}\n\t\tif(y!=n-1 && t%2==0) return 0;\n\t}\n\treturn 1;\n}\n\nll f(ll x,ll\
    \ n){ return (__int128(x)*x+1)%n;}\nll pollard_single(ll n){\n\tif(isprime(n))\
    \ return n;\n\tif(!(n&1)) return 2;\n\tll i,x,y,p;\n\tfor(i=1;i<20;i++){\n\t\t\
    x=i; y=f(x,n); p=gcd(y-x,n);\n\t\twhile(p==1){\n\t\t\tx=f(x,n); y=f(f(y,n),n);\
    \ p=gcd((y-x+n)%n,n)%n;\n\t\t}\n\t\tif(p==0 || p==n) continue;\n\t\treturn p;\n\
    \t}\n\tassert(0);\n}\n\nvector<ll> pollard(ll n){\n\tif(n==1) return {};\n\tll\
    \ x = pollard_single(n);\n\tif(x==n) return {x};\n\tvector<ll> le = pollard(x);\n\
    \tvector<ll> ri = pollard(n/x);\n\tfor(ll d: ri) le.push_back(d);\n\treturn le;\n\
    }\nll primitiveroot(ll p){\n\tauto v = pollard(p-1);\n\tfor(ll g=1;;g++){\n\t\t\
    bool ok = 1;\n\t\tfor(auto d:v){\n\t\t\tll f = (p-1)/d;\n\t\t\tif(pow_mod<__int128>(g,f,p)\
    \ == 1){\n\t\t\t\tok = 0;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tif(ok) return g;\n\
    \t}\n}\n\nint main(){\n\twhile(true){\n\t\tll p;\n\t\tcin>>p;\n\t\tauto g = primitiveroot(p);\n\
    \t\tcout<<\"g = \"<<g<<endl;\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/primitiveroot.cpp
  requiredBy: []
  timestamp: '2018-09-18 03:14:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/primitiveroot.cpp
layout: document
redirect_from:
- /library/math/primitiveroot.cpp
- /library/math/primitiveroot.cpp.html
title: math/primitiveroot.cpp
---
