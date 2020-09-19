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
  bundledCode: "#line 1 \"DP/Narou.cpp\"\n/*\r\n\t\u6298\u308C\u7DDA\u3092\u4FDD\u3064\
    DP\r\n\t\u3067\u304D\u308B\u3053\u3068 : \r\n\t\tf'(x) := min_[x+l <= y <= x+r]\
    \ f(y)\r\n\t\tf'(x) := f(x) + |x-a|\r\n\t\tgiven a -> compute f(a)\r\n\tf(a) \u306E\
    \u8A08\u7B97\u306F O(N) \u3067\u3001\u3053\u308C\u3092log\u306B\u3057\u3088\u3046\
    \u3068\u3059\u308B\u3068BIT\u3092\u4FDD\u3064\u5FC5\u8981\u304C\u51FA\u3066\u304F\
    \u308B\u3001\u3084\u308A\u305F\u304F\u306A\u3044\r\n\t\u307E\u3042\u666E\u901A\
    \u306Fbottom\u304C\u7B54\u3048\u306B\u306A\u308B\r\n\r\n\tverified at \r\n\t\t\
    1228(CF588) F\r\n\t\tARC70 E\r\n*/\r\n\r\nstruct Narou{\r\n\tusing D = ll;\r\n\
    \tpriority_queue<D> L;\r\n\tpriority_queue<D,V<D>,greater<D>> R;\r\n\tD offL =\
    \ 0, offR = 0;\r\n\tD bottom = 0;\r\n\r\n\t// initially f(x) = 0\r\n\r\n\tvoid\
    \ Min(D l,D r){\t// f'(x) := min_[x+l <= y <= x+r] f(y)\r\n\t\tassert(l <= r);\r\
    \n\t\toffL -= r;\r\n\t\toffR -= l;\r\n\t}\r\n\tvoid Add(D s){\t\t// f'(x) := f(x)\
    \ + |x-s|\r\n\t\toffL -= s, offR -= s;\r\n\t\tif(L.empty()){\r\n\t\t\tL.push(0-offL);\
    \ R.push(0-offR);\r\n\t\t\toffL += s, offR += s;\r\n\t\t\treturn;\r\n\t\t}\r\n\
    \t\tD le = L.top() + offL, ri = R.top() + offR;\r\n\t\tif(le <= 0 && 0 <= ri){\r\
    \n\t\t\tL.push(0-offL); R.push(0-offR);\r\n\t\t}else if(ri < 0){\r\n\t\t\tbottom\
    \ += -ri;\r\n\t\t\tL.push(ri-offL); R.pop();\r\n\t\t\tR.push(0-offR); R.push(0-offR);\r\
    \n\t\t}else{\r\n\t\t\tbottom += le;\r\n\t\t\tR.push(le-offR); L.pop();\r\n\t\t\
    \tL.push(0-offL); L.push(0-offL);\r\n\t\t}\r\n\t\toffL += s, offR += s;\r\n\t\
    }\r\n\tvoid AddConst(D c){\t// f'(x) = f(x) + c\r\n\t\tbottom += c;\r\n\t}\r\n\
    \tD f(D s){\t\t//O(N) :(\r\n\t\toffL -= s, offR -= s;\r\n\t\tD le = L.top() +\
    \ offL, ri = R.top() + offR;\r\n\t\tD res = bottom;\r\n\t\tif(le <= 0 && 0 <=\
    \ ri){\r\n\t\t}else if(ri < 0){\r\n\t\t\tauto cp = R;\r\n\t\t\trep1(k,cp.size()){\r\
    \n\t\t\t\tR.pop();\r\n\t\t\t\tD nri = R.empty() ? 0 : R.top() + offR;\r\n\t\t\t\
    \tif(nri >= 0){\r\n\t\t\t\t\tR = cp;\r\n\t\t\t\t\tres += (-ri) * k;\r\n\t\t\t\t\
    \tbreak;\r\n\t\t\t\t}\r\n\t\t\t\tres += (nri-ri) * k;\r\n\t\t\t\tri = nri;\r\n\
    \t\t\t}\r\n\t\t}else{\r\n\t\t\tauto cp = L;\r\n\t\t\trep1(k,cp.size()){\r\n\t\t\
    \t\tL.pop();\r\n\t\t\t\tD nle = L.empty() ? 0 : L.top() + offL;\r\n\t\t\t\tif(nle\
    \ <= 0){\r\n\t\t\t\t\tL = cp;\r\n\t\t\t\t\tres += le * k;\r\n\t\t\t\t\tbreak;\r\
    \n\t\t\t\t}\r\n\t\t\t\tres += (le-nle) * k;\r\n\t\t\t\tle = nle;\r\n\t\t\t}\r\n\
    \t\t}\r\n\t\toffL += s, offR += s;\r\n\t\treturn res;\r\n\t}\r\n};\r\n"
  code: "/*\r\n\t\u6298\u308C\u7DDA\u3092\u4FDD\u3064DP\r\n\t\u3067\u304D\u308B\u3053\
    \u3068 : \r\n\t\tf'(x) := min_[x+l <= y <= x+r] f(y)\r\n\t\tf'(x) := f(x) + |x-a|\r\
    \n\t\tgiven a -> compute f(a)\r\n\tf(a) \u306E\u8A08\u7B97\u306F O(N) \u3067\u3001\
    \u3053\u308C\u3092log\u306B\u3057\u3088\u3046\u3068\u3059\u308B\u3068BIT\u3092\
    \u4FDD\u3064\u5FC5\u8981\u304C\u51FA\u3066\u304F\u308B\u3001\u3084\u308A\u305F\
    \u304F\u306A\u3044\r\n\t\u307E\u3042\u666E\u901A\u306Fbottom\u304C\u7B54\u3048\
    \u306B\u306A\u308B\r\n\r\n\tverified at \r\n\t\t1228(CF588) F\r\n\t\tARC70 E\r\
    \n*/\r\n\r\nstruct Narou{\r\n\tusing D = ll;\r\n\tpriority_queue<D> L;\r\n\tpriority_queue<D,V<D>,greater<D>>\
    \ R;\r\n\tD offL = 0, offR = 0;\r\n\tD bottom = 0;\r\n\r\n\t// initially f(x)\
    \ = 0\r\n\r\n\tvoid Min(D l,D r){\t// f'(x) := min_[x+l <= y <= x+r] f(y)\r\n\t\
    \tassert(l <= r);\r\n\t\toffL -= r;\r\n\t\toffR -= l;\r\n\t}\r\n\tvoid Add(D s){\t\
    \t// f'(x) := f(x) + |x-s|\r\n\t\toffL -= s, offR -= s;\r\n\t\tif(L.empty()){\r\
    \n\t\t\tL.push(0-offL); R.push(0-offR);\r\n\t\t\toffL += s, offR += s;\r\n\t\t\
    \treturn;\r\n\t\t}\r\n\t\tD le = L.top() + offL, ri = R.top() + offR;\r\n\t\t\
    if(le <= 0 && 0 <= ri){\r\n\t\t\tL.push(0-offL); R.push(0-offR);\r\n\t\t}else\
    \ if(ri < 0){\r\n\t\t\tbottom += -ri;\r\n\t\t\tL.push(ri-offL); R.pop();\r\n\t\
    \t\tR.push(0-offR); R.push(0-offR);\r\n\t\t}else{\r\n\t\t\tbottom += le;\r\n\t\
    \t\tR.push(le-offR); L.pop();\r\n\t\t\tL.push(0-offL); L.push(0-offL);\r\n\t\t\
    }\r\n\t\toffL += s, offR += s;\r\n\t}\r\n\tvoid AddConst(D c){\t// f'(x) = f(x)\
    \ + c\r\n\t\tbottom += c;\r\n\t}\r\n\tD f(D s){\t\t//O(N) :(\r\n\t\toffL -= s,\
    \ offR -= s;\r\n\t\tD le = L.top() + offL, ri = R.top() + offR;\r\n\t\tD res =\
    \ bottom;\r\n\t\tif(le <= 0 && 0 <= ri){\r\n\t\t}else if(ri < 0){\r\n\t\t\tauto\
    \ cp = R;\r\n\t\t\trep1(k,cp.size()){\r\n\t\t\t\tR.pop();\r\n\t\t\t\tD nri = R.empty()\
    \ ? 0 : R.top() + offR;\r\n\t\t\t\tif(nri >= 0){\r\n\t\t\t\t\tR = cp;\r\n\t\t\t\
    \t\tres += (-ri) * k;\r\n\t\t\t\t\tbreak;\r\n\t\t\t\t}\r\n\t\t\t\tres += (nri-ri)\
    \ * k;\r\n\t\t\t\tri = nri;\r\n\t\t\t}\r\n\t\t}else{\r\n\t\t\tauto cp = L;\r\n\
    \t\t\trep1(k,cp.size()){\r\n\t\t\t\tL.pop();\r\n\t\t\t\tD nle = L.empty() ? 0\
    \ : L.top() + offL;\r\n\t\t\t\tif(nle <= 0){\r\n\t\t\t\t\tL = cp;\r\n\t\t\t\t\t\
    res += le * k;\r\n\t\t\t\t\tbreak;\r\n\t\t\t\t}\r\n\t\t\t\tres += (le-nle) * k;\r\
    \n\t\t\t\tle = nle;\r\n\t\t\t}\r\n\t\t}\r\n\t\toffL += s, offR += s;\r\n\t\treturn\
    \ res;\r\n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/Narou.cpp
  requiredBy: []
  timestamp: '2019-09-27 00:09:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/Narou.cpp
layout: document
redirect_from:
- /library/DP/Narou.cpp
- /library/DP/Narou.cpp.html
title: DP/Narou.cpp
---
