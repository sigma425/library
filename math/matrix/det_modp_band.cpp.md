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
  bundledCode: "#line 1 \"math/matrix/det_modp_band.cpp\"\n/*\nuse under a[i][j]!=0\
    \ -> abs(i-j)<=B\n(\u9AD8\u3005+-B\u306B\u3057\u304B\u8FBA\u304C\u8CBC\u3089\u308C\
    \u3066\u306A\u3044)\n\u6383\u304D\u51FA\u3057\u6642\u306Eswap\u306E\u5F71\u97FF\
    \u3067,-B~+2B\u307E\u3067\u306E3B+1\u500B\u3092vi\u306E\u4E2D\u306B\u6301\u3063\
    \u3066\u308B\n\u9069\u5F53\u306B0\u3092\u3064\u3081\u3066B-th value(0-indexed)\
    \ \u304Ca[i][i]\u306B\u306A\u308B\u3088\u3046\u306B\u3057\u3066\u3044\u308B\n\
    time O(NB^2)\nspace O(NB)\n*/\ntypedef long long ll;\nll mod=1e9+7;\ntypedef vector<ll>\
    \ vi;\ntypedef vector<vi> bmat;\nll ex(ll x,ll p){\n\tll a=1;\n\twhile(p){\n\t\
    \tif(p%2) a=a*x%mod;\n\t\tx=x*x%mod;\n\t\tp/=2;\n\t}\n\treturn a;\n}\nll inv(ll\
    \ a){\n\treturn ex(a,mod-2);\n}\nll det(bmat a){\n\tint N=a.size();\n\tint B=a[0].size()/3;\n\
    \tll ans=1;\n\trep(i,N){\n\t\tif(a[i][B]==0){\n\t\t\tfor(int j=i+1;j<N;j++){\n\
    \t\t\t\tif(B-(j-i)<0) break;\n\t\t\t\tif(a[j][B-(j-i)]!=0){\n\t\t\t\t\tint d=j-i;\n\
    \t\t\t\t\tfor(int k=d;k<=2*B+d;k++){\n\t\t\t\t\t\tswap(a[i][k],a[j][k-d]);\n\t\
    \t\t\t\t}\n\t\t\t\t\tans*=-1;\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(a[i][B]==0)\
    \ return 0;\n\t\t}\n\t\tfor(int j=i+1;j<N;j++){\n\t\t\tif(B-(j-i)<0) break;\n\t\
    \t\tint d=j-i;\n\t\t\tll c=a[j][B-d]*inv(a[i][B])%mod;\n\t\t\tfor(int k=B;k<=3*B;k++){\n\
    \t\t\t\ta[j][k-d]=(a[j][k-d]-c*a[i][k])%mod;\n\t\t\t}\n\t\t}\n\t\tans=ans*a[i][B]%mod;\n\
    \t}\n\tif(ans<0) ans+=mod;\n\treturn ans;\n}\n"
  code: "/*\nuse under a[i][j]!=0 -> abs(i-j)<=B\n(\u9AD8\u3005+-B\u306B\u3057\u304B\
    \u8FBA\u304C\u8CBC\u3089\u308C\u3066\u306A\u3044)\n\u6383\u304D\u51FA\u3057\u6642\
    \u306Eswap\u306E\u5F71\u97FF\u3067,-B~+2B\u307E\u3067\u306E3B+1\u500B\u3092vi\u306E\
    \u4E2D\u306B\u6301\u3063\u3066\u308B\n\u9069\u5F53\u306B0\u3092\u3064\u3081\u3066\
    B-th value(0-indexed) \u304Ca[i][i]\u306B\u306A\u308B\u3088\u3046\u306B\u3057\u3066\
    \u3044\u308B\ntime O(NB^2)\nspace O(NB)\n*/\ntypedef long long ll;\nll mod=1e9+7;\n\
    typedef vector<ll> vi;\ntypedef vector<vi> bmat;\nll ex(ll x,ll p){\n\tll a=1;\n\
    \twhile(p){\n\t\tif(p%2) a=a*x%mod;\n\t\tx=x*x%mod;\n\t\tp/=2;\n\t}\n\treturn\
    \ a;\n}\nll inv(ll a){\n\treturn ex(a,mod-2);\n}\nll det(bmat a){\n\tint N=a.size();\n\
    \tint B=a[0].size()/3;\n\tll ans=1;\n\trep(i,N){\n\t\tif(a[i][B]==0){\n\t\t\t\
    for(int j=i+1;j<N;j++){\n\t\t\t\tif(B-(j-i)<0) break;\n\t\t\t\tif(a[j][B-(j-i)]!=0){\n\
    \t\t\t\t\tint d=j-i;\n\t\t\t\t\tfor(int k=d;k<=2*B+d;k++){\n\t\t\t\t\t\tswap(a[i][k],a[j][k-d]);\n\
    \t\t\t\t\t}\n\t\t\t\t\tans*=-1;\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\t\
    if(a[i][B]==0) return 0;\n\t\t}\n\t\tfor(int j=i+1;j<N;j++){\n\t\t\tif(B-(j-i)<0)\
    \ break;\n\t\t\tint d=j-i;\n\t\t\tll c=a[j][B-d]*inv(a[i][B])%mod;\n\t\t\tfor(int\
    \ k=B;k<=3*B;k++){\n\t\t\t\ta[j][k-d]=(a[j][k-d]-c*a[i][k])%mod;\n\t\t\t}\n\t\t\
    }\n\t\tans=ans*a[i][B]%mod;\n\t}\n\tif(ans<0) ans+=mod;\n\treturn ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/det_modp_band.cpp
  requiredBy: []
  timestamp: '2018-09-18 03:14:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix/det_modp_band.cpp
layout: document
redirect_from:
- /library/math/matrix/det_modp_band.cpp
- /library/math/matrix/det_modp_band.cpp.html
title: math/matrix/det_modp_band.cpp
---
