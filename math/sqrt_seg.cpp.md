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
  bundledCode: "#line 1 \"math/sqrt_seg.cpp\"\n/*\r\n    x \\in [L,R] \u306B\u5BFE\
    \u3057\u3066 N/x = v \u306A\u308B\u533A\u9593 [l,r] \u3092\u5217\u6319\r\n   \
    \ v \u306E\u5024\u304C\u5927\u304D\u3044\u9806 (\u533A\u9593\u3092\u5DE6\u304B\
    \u3089\u9806)\r\n    !!! \u5168\u90E8\u9589\u533A\u9593 !!!\r\n    {3,3,3,}\r\n\
    \    {2,4,5,}\r\n    {1,6,10,}\r\n    {0,11,20,}\r\n    O(\u7A2E\u985E\u6570)\
    \ = O(N/L - N/R)\r\n*/\r\nvector<array<ll,3>> get_vlr(ll L,ll R,ll N){     //[L,R]\r\
    \n    assert(1 <= L && L <= R);\r\n    vector<array<ll,3>> res;\r\n    for(ll\
    \ i=L,j;i<=R;i=j+1){\r\n        ll v = N/i;\r\n        j = v == 0 ? R : N/v; chmin(j,R);\r\
    \n        res.emplace_back(array<ll,3>{v,i,j});\r\n    }\r\n    return res;\r\n\
    }\r\n"
  code: "/*\r\n    x \\in [L,R] \u306B\u5BFE\u3057\u3066 N/x = v \u306A\u308B\u533A\
    \u9593 [l,r] \u3092\u5217\u6319\r\n    v \u306E\u5024\u304C\u5927\u304D\u3044\u9806\
    \ (\u533A\u9593\u3092\u5DE6\u304B\u3089\u9806)\r\n    !!! \u5168\u90E8\u9589\u533A\
    \u9593 !!!\r\n    {3,3,3,}\r\n    {2,4,5,}\r\n    {1,6,10,}\r\n    {0,11,20,}\r\
    \n    O(\u7A2E\u985E\u6570) = O(N/L - N/R)\r\n*/\r\nvector<array<ll,3>> get_vlr(ll\
    \ L,ll R,ll N){     //[L,R]\r\n    assert(1 <= L && L <= R);\r\n    vector<array<ll,3>>\
    \ res;\r\n    for(ll i=L,j;i<=R;i=j+1){\r\n        ll v = N/i;\r\n        j =\
    \ v == 0 ? R : N/v; chmin(j,R);\r\n        res.emplace_back(array<ll,3>{v,i,j});\r\
    \n    }\r\n    return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/sqrt_seg.cpp
  requiredBy: []
  timestamp: '2019-12-03 21:50:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/sqrt_seg.cpp
layout: document
redirect_from:
- /library/math/sqrt_seg.cpp
- /library/math/sqrt_seg.cpp.html
title: math/sqrt_seg.cpp
---
