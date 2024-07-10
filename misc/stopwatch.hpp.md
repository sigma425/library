---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/stopwatch.hpp\"\nstruct Stopwatch{\n\tchrono::steady_clock::time_point\
    \ start;\n\tStopwatch():start(chrono::steady_clock::now()){}\n\n\tint msec(){\n\
    \t\tauto now = chrono::steady_clock::now();\n\t\treturn int(chrono::duration_cast<chrono::milliseconds>(now-start).count());\n\
    \t}\n};\n"
  code: "struct Stopwatch{\n\tchrono::steady_clock::time_point start;\n\tStopwatch():start(chrono::steady_clock::now()){}\n\
    \n\tint msec(){\n\t\tauto now = chrono::steady_clock::now();\n\t\treturn int(chrono::duration_cast<chrono::milliseconds>(now-start).count());\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/stopwatch.hpp
  requiredBy: []
  timestamp: '2024-06-12 05:28:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/stopwatch.hpp
layout: document
redirect_from:
- /library/misc/stopwatch.hpp
- /library/misc/stopwatch.hpp.html
title: misc/stopwatch.hpp
---
