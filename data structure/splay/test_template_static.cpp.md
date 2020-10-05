---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data structure/splay/test_template_static.cpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n/*\tOK\ntemplate<class T>\nstruct A{\n\
    \tstatic int i;\n\tT x;\n};\ntemplate<> int A<int>::i=0;\n*/\n/*\tOK\ntemplate<class\
    \ T>\nstruct A{\n\tstatic int i;\n\tT x;\n};\ntemplate<class T> int A<T>::i=0;\n\
    */\ntemplate<class T>\nstruct A{\n\tstruct Ta{\n\t\tT t;\n\t\tTa(){}\n\t};\n\t\
    static Ta x;\n};\ntemplate<class T> typename A<T>::Ta A<T>::x=Ta();\n\nint main(){\n\
    \tcout << A<int>::x.t <<endl;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n/*\tOK\ntemplate<class T>\n\
    struct A{\n\tstatic int i;\n\tT x;\n};\ntemplate<> int A<int>::i=0;\n*/\n/*\t\
    OK\ntemplate<class T>\nstruct A{\n\tstatic int i;\n\tT x;\n};\ntemplate<class\
    \ T> int A<T>::i=0;\n*/\ntemplate<class T>\nstruct A{\n\tstruct Ta{\n\t\tT t;\n\
    \t\tTa(){}\n\t};\n\tstatic Ta x;\n};\ntemplate<class T> typename A<T>::Ta A<T>::x=Ta();\n\
    \nint main(){\n\tcout << A<int>::x.t <<endl;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: data structure/splay/test_template_static.cpp
  requiredBy: []
  timestamp: '2016-12-08 00:51:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/splay/test_template_static.cpp
layout: document
redirect_from:
- /library/data structure/splay/test_template_static.cpp
- /library/data structure/splay/test_template_static.cpp.html
title: data structure/splay/test_template_static.cpp
---
