---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/FloorKthRoot.cpp
    title: math/FloorKthRoot.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/kth_root_integer
    links:
    - https://judge.yosupo.jp/problem/kth_root_integer
  bundledCode: "#line 1 \"test_oj/FloorKthRoot.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/kth_root_integer\"\
    \n\n#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define\
    \ rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n#define\
    \ pb push_back\n#define fs first\n#define sc second\n#define chmin(x,y) x=min(x,y)\n\
    #define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class S,class T>\
    \ ostream& operator<<(ostream& o,const pair<S,T> &p){\n\treturn o<<\"(\"<<p.fs<<\"\
    ,\"<<p.sc<<\")\";\n}\ntemplate<class T> ostream& operator<<(ostream& o,const vector<T>\
    \ &vc){\n\to<<\"{\";\n\tfor(const T& v:vc) o<<v<<\",\";\n\to<<\"}\";\n\treturn\
    \ o;\n}\nusing ll = long long;\ntemplate<class T> using V = vector<T>;\ntemplate<class\
    \ T> using VV = vector<vector<T>>;\nconstexpr ll TEN(int n) { return (n == 0)\
    \ ? 1 : 10 * TEN(n-1); }\n\n#ifdef LOCAL\n#define show(x) cerr << \"LINE\" <<\
    \ __LINE__ << \" : \" << #x << \" = \" << (x) << endl\n#else\n#define show(x)\
    \ true\n#endif\n\n#line 1 \"math/FloorKthRoot.cpp\"\n// floor(a^(1/k))\n// by\
    \ risjiroh, hos\n\ntemplate <class T, class Op = multiplies<>>\nconstexpr T power(T\
    \ a, uint64_t n, T init = 1, Op op = Op{}) {\n\twhile (n) {\n\t\tif (n & 1) init\
    \ = op(init, a);\n\t\tif (n >>= 1) a = op(a, a);\n\t}\n\treturn init;\n}\nuint64_t\
    \ floorKthRoot(uint64_t a, uint64_t k) {\n\tassert(k);\n\tif (a == 0 or k == 1)\
    \ return a;\n\tif (k >= 64) return 1;\n\tif (k == 2) return sqrtl(a);\n\tstatic\
    \ constexpr uint64_t inf = -1;\n\tstatic auto mul = [](auto x, auto y) { return\
    \ x <= inf / y ? x * y : inf; };\n\ta -= a == inf;\n\tuint64_t ok = pow(a, (1\
    \ - 1e-15) / k), ng = pow(a, (1 + 1e-15) / k) + 1;\n\twhile (ng - ok > 1) {\n\t\
    \tauto mid = (ok + ng) / 2;\n\t\t(power<uint64_t>(mid, k, 1, mul) <= a ? ok :\
    \ ng) = mid;\n\t}\n\treturn ok;\n}\n/*\nvoid unittest() {\n\t// k = 2\n\tfor (unsigned\
    \ long long x = 0; x < 1000; ++x) {\n\t\tfor (unsigned long long a = x * x; a\
    \ < (x + 1) * (x + 1); ++a) {\n\t\t\tassert(floorKthRoot(a, 2) == x);\n\t\t}\n\
    \t}\n\tfor (unsigned long long x = 4294967295ULL - 1000; x <= 4294967295ULL; ++x)\
    \ {\n\t\tfor (unsigned long long a = x * x - 1000; a < x * x; ++a) {\n\t\t\tassert(floorKthRoot(a,\
    \ 2) == x - 1);\n\t\t}\n\t\tfor (unsigned long long a = x * x; a < x * x + 1000;\
    \ ++a) {\n\t\t\tassert(floorKthRoot(a, 2) == x);\n\t\t}\n\t}\n\tfor (unsigned\
    \ long long b = 1; b <= 1000; ++b) {\n\t\tassert(floorKthRoot(-b, 2) == 4294967295ULL);\n\
    \t}\n\n\t// general\n\tfor (unsigned long long x = 2; x < 1000; ++x) {\n\t\tunsigned\
    \ long long a = x;\n\t\tfor (int k = 1; ; ++k) {\n\t\t\tassert(floorKthRoot(a\
    \ - 1, k) == x - 1);\n\t\t\tassert(floorKthRoot(a, k) == x);\n\t\t\tif (a > ~0ULL\
    \ / x) break;\n\t\t\ta *= x;\n\t\t}\n\t}\n}\n*/\n#line 34 \"test_oj/FloorKthRoot.test.cpp\"\
    \n\nint main(){\n\tcin.tie(0);\n\tios::sync_with_stdio(false);\t\t//DON'T USE\
    \ scanf/printf/puts !!\n\tcout << fixed << setprecision(20);\n\t\n\tint T; cin\
    \ >> T;\n\twhile(T--){\n\t\tunsigned long long a,k; cin >> a >> k;\n\t\tcout <<\
    \ floorKthRoot(a,k) << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_root_integer\"\n\n\
    #include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define\
    \ rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n#define\
    \ pb push_back\n#define fs first\n#define sc second\n#define chmin(x,y) x=min(x,y)\n\
    #define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class S,class T>\
    \ ostream& operator<<(ostream& o,const pair<S,T> &p){\n\treturn o<<\"(\"<<p.fs<<\"\
    ,\"<<p.sc<<\")\";\n}\ntemplate<class T> ostream& operator<<(ostream& o,const vector<T>\
    \ &vc){\n\to<<\"{\";\n\tfor(const T& v:vc) o<<v<<\",\";\n\to<<\"}\";\n\treturn\
    \ o;\n}\nusing ll = long long;\ntemplate<class T> using V = vector<T>;\ntemplate<class\
    \ T> using VV = vector<vector<T>>;\nconstexpr ll TEN(int n) { return (n == 0)\
    \ ? 1 : 10 * TEN(n-1); }\n\n#ifdef LOCAL\n#define show(x) cerr << \"LINE\" <<\
    \ __LINE__ << \" : \" << #x << \" = \" << (x) << endl\n#else\n#define show(x)\
    \ true\n#endif\n\n#include \"../math/FloorKthRoot.cpp\"\n\nint main(){\n\tcin.tie(0);\n\
    \tios::sync_with_stdio(false);\t\t//DON'T USE scanf/printf/puts !!\n\tcout <<\
    \ fixed << setprecision(20);\n\t\n\tint T; cin >> T;\n\twhile(T--){\n\t\tunsigned\
    \ long long a,k; cin >> a >> k;\n\t\tcout << floorKthRoot(a,k) << '\\n';\n\t}\n\
    }\n"
  dependsOn:
  - math/FloorKthRoot.cpp
  isVerificationFile: true
  path: test_oj/FloorKthRoot.test.cpp
  requiredBy: []
  timestamp: '2020-09-20 08:07:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test_oj/FloorKthRoot.test.cpp
layout: document
redirect_from:
- /verify/test_oj/FloorKthRoot.test.cpp
- /verify/test_oj/FloorKthRoot.test.cpp.html
title: test_oj/FloorKthRoot.test.cpp
---
