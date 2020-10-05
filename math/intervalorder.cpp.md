---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/intervalorder.cpp\"\n/*\n\u9577\u3055\u304C\u6B63\u306E\
    \u533A\u9593\u304CM\u500B\u4E0E\u3048\u3089\u308C\u305F\u3068\u304D\u306B\u3001\
    \u7AEF\u70B9\u306E\u9806\u5E8F(=\u3082\u3042\u308A\u3046\u308B)\u3092\u5168\u5217\
    \u6319\u3059\u308B\n\u533A\u9593i\u306E\u5DE6\u7AEF\u304Ci,\u53F3\u7AEF\u304C\
    i+M\n\u5404VI\u304C\u540C\u3058\u5EA7\u6A19\u3092\u8868\u3057\u3066\u3044\u308B\
    \n\nords\u306E\u5927\u304D\u3055\u306F 1, 13, 409, 23917, 2244361, 308682013\n\
    M=5\u307E\u3067\u3057\u304B\u4F7F\u3048\u306A\u3044\n\nSRM710\n\n\u5404\u533A\u9593\
    \u30B0\u30E9\u30D5\u304C\u4F55\u500B\u3042\u308B\u304B\u304C\u6C42\u3081\u305F\
    \u3044\u306A\u3089\u3001\u5DE6\u7AEF\u3092\u5FD8\u308C\u3066\u53F3\u7AEF\u306E\
    \u9806\u3092\u30AD\u30FC\u306B\u6301\u3063\u3066DP\n*/\nbool B(int x,int i){return\
    \ (x>>i)&1;}\n\ntypedef vector<int> VI;\ntypedef vector<VI> VV;\n\nint M;\nvector<VV>\
    \ ords;\nint cnt;\n\nvoid dfs(int usel, int user, VV& ord){\n//\tshow(usel);\n\
    //\tshow(user);\n\tif(usel==(1<<M)-1 && user==(1<<M)-1){\n//\t\tords.pb(ord);\n\
    \t\tcnt++;\n\t\treturn;\n\t}\n\tint prev=-1;\n\tif(!ord.back().empty()) prev =\
    \ ord.back().back();\n\trep(i,M){\n\t\tif(!B(usel,i)){\n\t\t\tif(prev>=i) continue;\n\
    \t\t\tord.back().pb(i);\n\t\t\tdfs(usel|(1<<i),user,ord);\n\t\t\tord.back().pop_back();\n\
    \t\t}else if(!B(user,i)){\n\t\t\tif(prev>=i+M) continue;\n\t\t\tbool len0=0;\n\
    \t\t\tfor(int x:ord.back()) if(x==i) len0=1;\n\t\t\tif(len0) continue;\n\t\t\t\
    ord.back().pb(i+M);\n\t\t\tdfs(usel,user|(1<<i),ord);\n\t\t\tord.back().pop_back();\n\
    \t\t}else{\n\t\t\t;\n\t\t}\n\t}\n\tif(!ord.back().empty()){\n\t\tord.pb({});\n\
    \t\tdfs(usel,user,ord);\n\t\tord.pop_back();\n\t}\n}\n\nvoid enumorder(int M){\n\
    \t::M = M;\n\tVV st(1,VI());\n\tdfs(0,0,st);\n}\n"
  code: "/*\n\u9577\u3055\u304C\u6B63\u306E\u533A\u9593\u304CM\u500B\u4E0E\u3048\u3089\
    \u308C\u305F\u3068\u304D\u306B\u3001\u7AEF\u70B9\u306E\u9806\u5E8F(=\u3082\u3042\
    \u308A\u3046\u308B)\u3092\u5168\u5217\u6319\u3059\u308B\n\u533A\u9593i\u306E\u5DE6\
    \u7AEF\u304Ci,\u53F3\u7AEF\u304Ci+M\n\u5404VI\u304C\u540C\u3058\u5EA7\u6A19\u3092\
    \u8868\u3057\u3066\u3044\u308B\n\nords\u306E\u5927\u304D\u3055\u306F 1, 13, 409,\
    \ 23917, 2244361, 308682013\nM=5\u307E\u3067\u3057\u304B\u4F7F\u3048\u306A\u3044\
    \n\nSRM710\n\n\u5404\u533A\u9593\u30B0\u30E9\u30D5\u304C\u4F55\u500B\u3042\u308B\
    \u304B\u304C\u6C42\u3081\u305F\u3044\u306A\u3089\u3001\u5DE6\u7AEF\u3092\u5FD8\
    \u308C\u3066\u53F3\u7AEF\u306E\u9806\u3092\u30AD\u30FC\u306B\u6301\u3063\u3066\
    DP\n*/\nbool B(int x,int i){return (x>>i)&1;}\n\ntypedef vector<int> VI;\ntypedef\
    \ vector<VI> VV;\n\nint M;\nvector<VV> ords;\nint cnt;\n\nvoid dfs(int usel, int\
    \ user, VV& ord){\n//\tshow(usel);\n//\tshow(user);\n\tif(usel==(1<<M)-1 && user==(1<<M)-1){\n\
    //\t\tords.pb(ord);\n\t\tcnt++;\n\t\treturn;\n\t}\n\tint prev=-1;\n\tif(!ord.back().empty())\
    \ prev = ord.back().back();\n\trep(i,M){\n\t\tif(!B(usel,i)){\n\t\t\tif(prev>=i)\
    \ continue;\n\t\t\tord.back().pb(i);\n\t\t\tdfs(usel|(1<<i),user,ord);\n\t\t\t\
    ord.back().pop_back();\n\t\t}else if(!B(user,i)){\n\t\t\tif(prev>=i+M) continue;\n\
    \t\t\tbool len0=0;\n\t\t\tfor(int x:ord.back()) if(x==i) len0=1;\n\t\t\tif(len0)\
    \ continue;\n\t\t\tord.back().pb(i+M);\n\t\t\tdfs(usel,user|(1<<i),ord);\n\t\t\
    \tord.back().pop_back();\n\t\t}else{\n\t\t\t;\n\t\t}\n\t}\n\tif(!ord.back().empty()){\n\
    \t\tord.pb({});\n\t\tdfs(usel,user,ord);\n\t\tord.pop_back();\n\t}\n}\n\nvoid\
    \ enumorder(int M){\n\t::M = M;\n\tVV st(1,VI());\n\tdfs(0,0,st);\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/intervalorder.cpp
  requiredBy: []
  timestamp: '2018-09-18 03:14:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/intervalorder.cpp
layout: document
redirect_from:
- /library/math/intervalorder.cpp
- /library/math/intervalorder.cpp.html
title: math/intervalorder.cpp
---
