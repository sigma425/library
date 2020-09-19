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
  bundledCode: "#line 1 \"data structure/BIT.cpp\"\n/*\n\tBinary Indexed Tree\n\t\
    1\u6B21\u5143\n\tkth\u306F\u307E\u3060\u624B\u5143\u3067\u8A66\u3057\u305F\u3060\
    \u3051\n*/\n#include <bits/stdc++.h>\n#define rep(i,N) for(int i=0;i<N;i++)\n\
    using namespace std;\n\nstruct BIT{\n\tusing D = int;\n\tint N;\n\tvector<D> bit;\n\
    \tBIT(int n){\t\t//n\u306F\u533A\u9593\u5E45!!!\n\t\tN=n;\n\t\tbit.assign(n+1,0);\n\
    \t}\n\tBIT(){}\n\tvoid init(int n){\n\t\tN=n;\n\t\tbit.assign(n+1,0);\n\t}\n\t\
    D sum(int i){\t\t//i\u500B\u306E\u548Ca[0]+..a[i-1]\n\t\tD s=0;\n\t\twhile(i>0){\n\
    \t\t\ts+=bit[i];\n\t\t\ti-=(i&-i);\n\t\t}\n\t\treturn s;\n\t}\n\tD val(int i){\t\
    //return a[i]\t(0-ind)\n\t\treturn sum(i+1)-sum(i);\n\t}\n\tvoid add(int i,D x){\t\
    //a[i]+=x (0-indexed)\n\t\ti++;\n\t\twhile(i<=N){\n\t\t\tbit[i]+=x;\n\t\t\ti+=(i&-i);\n\
    \t\t}\n\t}\n\tvoid assign(int i,D x){\t//a[i]=x\n\t\tadd(i,x-val(i));\n\t}\n\t\
    /*\n\t!!!a[i] SHOULD be non-negative!!!\n\treturn min i s.t. sum(i+1)>=s\n\ta[0]+..a[i]\
    \ >= s \u306A\u308B\u6700\u5C0F\u306Ei\u3092\u8FD4\u3059\n\ts=0 \u306A\u3089-1\u3092\
    \u8FD4\u3059\n\n\ta[i]=1 or 0\u306E\u6642\u306F,s\u756A\u76EE(1-INDEXED)\u304C\
    \u4F55\u304B\u3092\u8FD4\u3059(0-indexed) \n\te.g\n\ta:0 1 1 0 1\n\tkth(0)=-1,kth(1)=1,kth(2)=2,kth(3)=4,kth(4>=)=5\n\
    \n\n\t*/\n\tint kth(int s){\n\t\tif(s==0) return -1;\n\t\tint p=1;\n\t\twhile(p<=N)\
    \ p<<=1;\n\t\tp>>=1;\n\t\tint i=0;\n\t\twhile(p){\n\t\t\tif(i+p<=N&&s>bit[i+p])\
    \ s-=bit[i+p],i|=p;\n\t\t\tp>>=1;\n\t\t}\n\t\treturn i;\n\t}\n}bit;\n\n//template\
    \ ver \u4E00\u90E8(\u533A\u9593\u548C\u3068\u304Bassign)\u5F15\u304D\u7B97\u304C\
    \u5FC5\u8981,kth\u3067\u306F\u9806\u5E8F\u3082\u5FC5\u8981(\u3057\u304B\u3082\u591A\
    \u5206\u9806\u5E8F\u7FA4\u3092\u8981\u8ACB\u3059\u308B)\n\ntemplate<class T>\n\
    struct BIT{\n\tint N;\n\tvector<T> bit;\n\tBIT(int n){\t\t//n\u306F\u533A\u9593\
    \u5E45!!!\n\t\tN=n;\n\t\tbit.assign(n+1,T(0));\n\t}\n\tBIT(){}\n\tvoid init(int\
    \ n){\n\t\tN=n;\n\t\tbit.assign(n+1,T(0));\n\t}\n\tT sum(int i){\t\t//i\u500B\u306E\
    \u548Ca[0]+..a[i-1]\n\t\tT s(0);\n\t\twhile(i>0){\n\t\t\ts=s+bit[i];\n\t\t\ti-=(i&-i);\n\
    \t\t}\n\t\treturn s;\n\t}\n\tT val(int i){\t//return a[i]\t(0-ind)\t\t//\u5F15\
    \u304D\u7B97\u304C\u5FC5\u8981\n\t\treturn sum(i+1)-sum(i);\n\t}\n\tvoid add(int\
    \ i,T x){\t//a[i]+=x (0-indexed)\n\t\ti++;\n\t\twhile(i<=N){\n\t\t\tbit[i]=bit[i]+x;\n\
    \t\t\ti+=(i&-i);\n\t\t}\n\t}\n\tvoid assign(int i,T x){\t//a[i]=x-val\t\t//\u5F15\
    \u304D\u7B97\n\t\tadd(i,x-val(i));\n\t}\n\t/*\n\t!!!a[i] SHOULD be non-negative!!!\n\
    \treturn min i s.t. sum(i+1)>=s\n\ta[0]+..a[i] >= s \u306A\u308B\u6700\u5C0F\u306E\
    i\u3092\u8FD4\u3059\n\ts=0 \u306A\u3089-1\u3092\u8FD4\u3059\n\n\ta[i]=1 or 0\u306E\
    \u6642\u306F,s\u756A\u76EE(1-INDEXED)\u304C\u4F55\u304B\u3092\u8FD4\u3059(0-indexed)\
    \ \n\te.g\n\ta:0 1 1 0 1\n\tkth(0)=-1,kth(1)=1,kth(2)=2,kth(3)=4,kth(4>=)=5\n\n\
    \n\t*/\n\tint kth(T s){\t\t\t\t\t// order\u304C\u3044\u308B\n\t\tif(s==T(0)) return\
    \ -1;\n\t\tint p=1;\n\t\twhile(p<=N) p<<=1;\n\t\tp>>=1;\n\t\tint i=0;\n\t\twhile(p){\n\
    \t\t\tif(i+p<=N&&s>bit[i+p]) s=s-bit[i+p],i|=p;\n\t\t\tp>>=1;\n\t\t}\n\t\treturn\
    \ i;\n\t}\n}bit;\n\n\n\nint main(){\n\tint N;\n\tcin>>N;\n\tBIT bit(N);\n\twhile(true){\n\
    \t\tchar c;\n\t\tcin>>c;\n\t\tif(c=='a'){\n\t\t\tint i,x;\n\t\t\tcin>>i>>x;\n\t\
    \t\tbit.assign(i,x);\n\t\t}\n\t\tif(c=='k'){\n\t\t\tint k;\n\t\t\tcin>>k;\n\t\t\
    \tcout<<\"kth=\"<<bit.kth(k)<<endl;\n\t\t}\n\t\tcout<<\"vals=\";\n\t\trep(i,N)\
    \ cout<<bit.val(i)<<\" \";\n\t\tputs(\"\");\n\t}\n\n}\n"
  code: "/*\n\tBinary Indexed Tree\n\t1\u6B21\u5143\n\tkth\u306F\u307E\u3060\u624B\
    \u5143\u3067\u8A66\u3057\u305F\u3060\u3051\n*/\n#include <bits/stdc++.h>\n#define\
    \ rep(i,N) for(int i=0;i<N;i++)\nusing namespace std;\n\nstruct BIT{\n\tusing\
    \ D = int;\n\tint N;\n\tvector<D> bit;\n\tBIT(int n){\t\t//n\u306F\u533A\u9593\
    \u5E45!!!\n\t\tN=n;\n\t\tbit.assign(n+1,0);\n\t}\n\tBIT(){}\n\tvoid init(int n){\n\
    \t\tN=n;\n\t\tbit.assign(n+1,0);\n\t}\n\tD sum(int i){\t\t//i\u500B\u306E\u548C\
    a[0]+..a[i-1]\n\t\tD s=0;\n\t\twhile(i>0){\n\t\t\ts+=bit[i];\n\t\t\ti-=(i&-i);\n\
    \t\t}\n\t\treturn s;\n\t}\n\tD val(int i){\t//return a[i]\t(0-ind)\n\t\treturn\
    \ sum(i+1)-sum(i);\n\t}\n\tvoid add(int i,D x){\t//a[i]+=x (0-indexed)\n\t\ti++;\n\
    \t\twhile(i<=N){\n\t\t\tbit[i]+=x;\n\t\t\ti+=(i&-i);\n\t\t}\n\t}\n\tvoid assign(int\
    \ i,D x){\t//a[i]=x\n\t\tadd(i,x-val(i));\n\t}\n\t/*\n\t!!!a[i] SHOULD be non-negative!!!\n\
    \treturn min i s.t. sum(i+1)>=s\n\ta[0]+..a[i] >= s \u306A\u308B\u6700\u5C0F\u306E\
    i\u3092\u8FD4\u3059\n\ts=0 \u306A\u3089-1\u3092\u8FD4\u3059\n\n\ta[i]=1 or 0\u306E\
    \u6642\u306F,s\u756A\u76EE(1-INDEXED)\u304C\u4F55\u304B\u3092\u8FD4\u3059(0-indexed)\
    \ \n\te.g\n\ta:0 1 1 0 1\n\tkth(0)=-1,kth(1)=1,kth(2)=2,kth(3)=4,kth(4>=)=5\n\n\
    \n\t*/\n\tint kth(int s){\n\t\tif(s==0) return -1;\n\t\tint p=1;\n\t\twhile(p<=N)\
    \ p<<=1;\n\t\tp>>=1;\n\t\tint i=0;\n\t\twhile(p){\n\t\t\tif(i+p<=N&&s>bit[i+p])\
    \ s-=bit[i+p],i|=p;\n\t\t\tp>>=1;\n\t\t}\n\t\treturn i;\n\t}\n}bit;\n\n//template\
    \ ver \u4E00\u90E8(\u533A\u9593\u548C\u3068\u304Bassign)\u5F15\u304D\u7B97\u304C\
    \u5FC5\u8981,kth\u3067\u306F\u9806\u5E8F\u3082\u5FC5\u8981(\u3057\u304B\u3082\u591A\
    \u5206\u9806\u5E8F\u7FA4\u3092\u8981\u8ACB\u3059\u308B)\n\ntemplate<class T>\n\
    struct BIT{\n\tint N;\n\tvector<T> bit;\n\tBIT(int n){\t\t//n\u306F\u533A\u9593\
    \u5E45!!!\n\t\tN=n;\n\t\tbit.assign(n+1,T(0));\n\t}\n\tBIT(){}\n\tvoid init(int\
    \ n){\n\t\tN=n;\n\t\tbit.assign(n+1,T(0));\n\t}\n\tT sum(int i){\t\t//i\u500B\u306E\
    \u548Ca[0]+..a[i-1]\n\t\tT s(0);\n\t\twhile(i>0){\n\t\t\ts=s+bit[i];\n\t\t\ti-=(i&-i);\n\
    \t\t}\n\t\treturn s;\n\t}\n\tT val(int i){\t//return a[i]\t(0-ind)\t\t//\u5F15\
    \u304D\u7B97\u304C\u5FC5\u8981\n\t\treturn sum(i+1)-sum(i);\n\t}\n\tvoid add(int\
    \ i,T x){\t//a[i]+=x (0-indexed)\n\t\ti++;\n\t\twhile(i<=N){\n\t\t\tbit[i]=bit[i]+x;\n\
    \t\t\ti+=(i&-i);\n\t\t}\n\t}\n\tvoid assign(int i,T x){\t//a[i]=x-val\t\t//\u5F15\
    \u304D\u7B97\n\t\tadd(i,x-val(i));\n\t}\n\t/*\n\t!!!a[i] SHOULD be non-negative!!!\n\
    \treturn min i s.t. sum(i+1)>=s\n\ta[0]+..a[i] >= s \u306A\u308B\u6700\u5C0F\u306E\
    i\u3092\u8FD4\u3059\n\ts=0 \u306A\u3089-1\u3092\u8FD4\u3059\n\n\ta[i]=1 or 0\u306E\
    \u6642\u306F,s\u756A\u76EE(1-INDEXED)\u304C\u4F55\u304B\u3092\u8FD4\u3059(0-indexed)\
    \ \n\te.g\n\ta:0 1 1 0 1\n\tkth(0)=-1,kth(1)=1,kth(2)=2,kth(3)=4,kth(4>=)=5\n\n\
    \n\t*/\n\tint kth(T s){\t\t\t\t\t// order\u304C\u3044\u308B\n\t\tif(s==T(0)) return\
    \ -1;\n\t\tint p=1;\n\t\twhile(p<=N) p<<=1;\n\t\tp>>=1;\n\t\tint i=0;\n\t\twhile(p){\n\
    \t\t\tif(i+p<=N&&s>bit[i+p]) s=s-bit[i+p],i|=p;\n\t\t\tp>>=1;\n\t\t}\n\t\treturn\
    \ i;\n\t}\n}bit;\n\n\n\nint main(){\n\tint N;\n\tcin>>N;\n\tBIT bit(N);\n\twhile(true){\n\
    \t\tchar c;\n\t\tcin>>c;\n\t\tif(c=='a'){\n\t\t\tint i,x;\n\t\t\tcin>>i>>x;\n\t\
    \t\tbit.assign(i,x);\n\t\t}\n\t\tif(c=='k'){\n\t\t\tint k;\n\t\t\tcin>>k;\n\t\t\
    \tcout<<\"kth=\"<<bit.kth(k)<<endl;\n\t\t}\n\t\tcout<<\"vals=\";\n\t\trep(i,N)\
    \ cout<<bit.val(i)<<\" \";\n\t\tputs(\"\");\n\t}\n\n}"
  dependsOn: []
  isVerificationFile: false
  path: data structure/BIT.cpp
  requiredBy: []
  timestamp: '2018-03-30 16:44:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/BIT.cpp
layout: document
redirect_from:
- /library/data structure/BIT.cpp
- /library/data structure/BIT.cpp.html
title: data structure/BIT.cpp
---
