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
  bundledCode: "#line 1 \"misc/timer.cpp\"\n#include <bits/stdc++.h>\n#define rep(i,n)\
    \ for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<\"(\"\
    <<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class T> ostream& operator<<(ostream& o,const\
    \ vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"[\";for(const T& v:vc) o<<v<<\"\
    ,\";o<<\"]\";return o;}\nstruct Timer{\n\tclock_t st;\n\tvoid start(){\n\t\tst\
    \ = clock();\n\t}\n\tint ms(){\n\t\treturn (clock()-st)*1000 / CLOCKS_PER_SEC;\n\
    \t}\n};\nint main(){\n\tTimer timer;\n\ttimer.start();\n\tunsigned long long ans\
    \ = 0;\n\tfor(unsigned long long i = 1; i<=1000000000ull; i++ ){\n\t\tans ^= i;\n\
    \t}\n\tshow(ans);\n\tshow(timer.ms());\n}\n"
  code: "#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define show(x) cout\
    \ << #x << \" = \" << x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y)\
    \ x=max(x,y)\nusing namespace std;\ntemplate<class S,class T> ostream& operator<<(ostream&\
    \ o,const pair<S,T> &p){return o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class\
    \ T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"\
    [\";for(const T& v:vc) o<<v<<\",\";o<<\"]\";return o;}\nstruct Timer{\n\tclock_t\
    \ st;\n\tvoid start(){\n\t\tst = clock();\n\t}\n\tint ms(){\n\t\treturn (clock()-st)*1000\
    \ / CLOCKS_PER_SEC;\n\t}\n};\nint main(){\n\tTimer timer;\n\ttimer.start();\n\t\
    unsigned long long ans = 0;\n\tfor(unsigned long long i = 1; i<=1000000000ull;\
    \ i++ ){\n\t\tans ^= i;\n\t}\n\tshow(ans);\n\tshow(timer.ms());\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/timer.cpp
  requiredBy: []
  timestamp: '2024-01-04 00:07:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/timer.cpp
layout: document
redirect_from:
- /library/misc/timer.cpp
- /library/misc/timer.cpp.html
title: misc/timer.cpp
---
