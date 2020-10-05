---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/isprime.cpp\"\n/*\n\t\u7D20\u6570\u5224\u5B9A n <=\
    \ 10^18\n\t\u3053\u306E\u7BC4\u56F2\u306A\u308937\u4EE5\u4E0B\u306E\u7D20\u6570\
    \u3092\u4F7F\u3063\u3066\u7D20\u6570\u30C6\u30B9\u30C8\u3059\u308C\u3070\u5341\
    \u5206\u3089\u3057\u3044\n\t\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u6CE8\u610F\
    \n*/\n#include<bits/stdc++.h>\nusing namespace std;\n\ntemplate<class T>\nT gcd(T\
    \ a,T b){\n\ta = abs(a), b = abs(b);\n\tif(b==0) return a;\n\treturn gcd(b,a%b);\n\
    }\ntemplate<class T, class U>\nT pow_mod(T x, U p, T mod){\n\tassert(p>=0);\n\t\
    x %= mod;\n\tT a = 1 % mod;\n\twhile(p){\n\t\tif(p&1) a = a*x%mod;\n\t\tx = x*x%mod;\n\
    \t\tp >>= 1;\n\t}\n\treturn a;\n}\nusing ll = long long;\nbool isprime(ll n){\n\
    \tif(n<=1) return 0;\n\tif(n==2) return 1;\n\tif(n%2==0) return 0;\n\tll d = n-1;\n\
    \twhile(d%2==0) d/=2;\n\tstatic const vector<ll> alist{2,3,5,7,11,13,17,19,23,29,31,37};\n\
    \tfor(ll a: alist){\n\t\tif(n<=a) break;\n\t\tll t = d;\n\t\tll y = pow_mod<__int128>(a,t,n);\n\
    \t\twhile(t!=n-1 && y!=1 && y!=n-1){\n\t\t\ty = __int128(y)*y%n;\n\t\t\tt<<=1;\n\
    \t\t}\n\t\tif(y!=n-1 && t%2==0) return 0;\n\t}\n\treturn 1;\n}\n\nint main(){\n\
    \twhile(true){\n\t\tll n;\n\t\tcin>>n;\n\t\tif(isprime(n)) puts(\"prime\");\n\t\
    \telse puts(\"composite\");\n\t}\n}\n"
  code: "/*\n\t\u7D20\u6570\u5224\u5B9A n <= 10^18\n\t\u3053\u306E\u7BC4\u56F2\u306A\
    \u308937\u4EE5\u4E0B\u306E\u7D20\u6570\u3092\u4F7F\u3063\u3066\u7D20\u6570\u30C6\
    \u30B9\u30C8\u3059\u308C\u3070\u5341\u5206\u3089\u3057\u3044\n\t\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u6CE8\u610F\n*/\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate<class T>\nT gcd(T a,T b){\n\ta = abs(a), b = abs(b);\n\tif(b==0)\
    \ return a;\n\treturn gcd(b,a%b);\n}\ntemplate<class T, class U>\nT pow_mod(T\
    \ x, U p, T mod){\n\tassert(p>=0);\n\tx %= mod;\n\tT a = 1 % mod;\n\twhile(p){\n\
    \t\tif(p&1) a = a*x%mod;\n\t\tx = x*x%mod;\n\t\tp >>= 1;\n\t}\n\treturn a;\n}\n\
    using ll = long long;\nbool isprime(ll n){\n\tif(n<=1) return 0;\n\tif(n==2) return\
    \ 1;\n\tif(n%2==0) return 0;\n\tll d = n-1;\n\twhile(d%2==0) d/=2;\n\tstatic const\
    \ vector<ll> alist{2,3,5,7,11,13,17,19,23,29,31,37};\n\tfor(ll a: alist){\n\t\t\
    if(n<=a) break;\n\t\tll t = d;\n\t\tll y = pow_mod<__int128>(a,t,n);\n\t\twhile(t!=n-1\
    \ && y!=1 && y!=n-1){\n\t\t\ty = __int128(y)*y%n;\n\t\t\tt<<=1;\n\t\t}\n\t\tif(y!=n-1\
    \ && t%2==0) return 0;\n\t}\n\treturn 1;\n}\n\nint main(){\n\twhile(true){\n\t\
    \tll n;\n\t\tcin>>n;\n\t\tif(isprime(n)) puts(\"prime\");\n\t\telse puts(\"composite\"\
    );\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/isprime.cpp
  requiredBy: []
  timestamp: '2018-09-18 03:14:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/isprime.cpp
layout: document
redirect_from:
- /library/math/isprime.cpp
- /library/math/isprime.cpp.html
title: math/isprime.cpp
---
