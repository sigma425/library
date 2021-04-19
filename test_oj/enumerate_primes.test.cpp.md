---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime.cpp
    title: math/prime.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"test_oj/enumerate_primes.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/enumerate_primes\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing uint = unsigned int;\n#define\
    \ rep(i,n) for(int i=0;i<int(n);i++)\n#define rep1(i,n) for(int i=1;i<=int(n);i++)\n\
    #define per(i,n) for(int i=int(n)-1;i>=0;i--)\n#define per1(i,n) for(int i=int(n);i>0;i--)\n\
    #define all(c) c.begin(),c.end()\n#define si(x) int(x.size())\n#define pb emplace_back\n\
    #define fs first\n#define sc second\ntemplate<class T> using V = vector<T>;\n\
    template<class T> using VV = vector<vector<T>>;\ntemplate<class T,class U> void\
    \ chmax(T& x, U y){if(x<y) x=y;}\ntemplate<class T,class U> void chmin(T& x, U\
    \ y){if(y<x) x=y;}\ntemplate<class T> void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}\n\
    template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){\n\
    \treturn o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";\n}\ntemplate<class T> ostream& operator<<(ostream&\
    \ o,const vector<T> &vc){\n\to<<\"{\";\n\tfor(const T& v:vc) o<<v<<\",\";\n\t\
    o<<\"}\";\n\treturn o;\n}\nconstexpr ll TEN(int n) { return (n == 0) ? 1 : 10\
    \ * TEN(n-1); }\n\n#ifdef LOCAL\n#define show(x) cerr << \"LINE\" << __LINE__\
    \ << \" : \" << #x << \" = \" << (x) << endl\nvoid dmpr(ostream& os){os<<endl;}\n\
    template<class T,class... Args>\nvoid dmpr(ostream&os,const T&t,const Args&...\
    \ args){\n\tos<<t<<\" ~ \";\n\tdmpr(os,args...);\n}\n#define shows(...) cerr <<\
    \ \"LINE\" << __LINE__ << \" : \";dmpr(cerr,##__VA_ARGS__)\n#define dump(x) cerr\
    \ << \"LINE\" << __LINE__ << \" : \" << #x << \" = {\";  \\\n\tfor(auto v: x)\
    \ cerr << v << \",\"; cerr << \"}\" << endl;\n#else\n#define show(x) void(0)\n\
    #define dump(x) void(0)\n#define shows(...) void(0)\n#endif\n\n#line 1 \"math/prime.cpp\"\
    \n\nV<bool> isp;\nV<int> pr;\nV<int> sf; //smallest factor, sf[9*5*11] = 3\nvoid\
    \ linear_sieve(int X){\t\t// <= X\n\tisp = V<bool>(X+1,true); isp[0] = isp[1]\
    \ = false;\n\tsf = V<int>(X+1);\n\tfor(int i=2;i<=X;i++){\n\t\tif(isp[i]){\n\t\
    \t\tpr.pb(i);\n\t\t\tsf[i] = i;\n\t\t}\n\t\tfor(int j=0;i*pr[j]<=X;j++){\n\t\t\
    \tisp[i*pr[j]] = false;\n\t\t\tsf[i*pr[j]] = pr[j];\n\t\t\tif(i%pr[j] == 0) break;\n\
    \t\t}\n\t}\n}\n#line 50 \"test_oj/enumerate_primes.test.cpp\"\n\nint main(){\n\
    \tcin.tie(0);\n\tios::sync_with_stdio(false);\t\t//DON'T USE scanf/printf/puts\
    \ !!\n\tcout << fixed << setprecision(20);\n\n\tint N,A,B; cin >> N >> A >> B;\n\
    \tlinear_sieve(N);\n\tV<int> ans;\n\tfor(int i=B;i<si(pr);i+=A) ans.pb(pr[i]);\n\
    \tcout << si(pr) << \" \" << si(ans) << endl;\n\tfor(int v: ans) cout << v <<\
    \ \" \";\n\tcout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing uint\
    \ = unsigned int;\n#define rep(i,n) for(int i=0;i<int(n);i++)\n#define rep1(i,n)\
    \ for(int i=1;i<=int(n);i++)\n#define per(i,n) for(int i=int(n)-1;i>=0;i--)\n\
    #define per1(i,n) for(int i=int(n);i>0;i--)\n#define all(c) c.begin(),c.end()\n\
    #define si(x) int(x.size())\n#define pb emplace_back\n#define fs first\n#define\
    \ sc second\ntemplate<class T> using V = vector<T>;\ntemplate<class T> using VV\
    \ = vector<vector<T>>;\ntemplate<class T,class U> void chmax(T& x, U y){if(x<y)\
    \ x=y;}\ntemplate<class T,class U> void chmin(T& x, U y){if(y<x) x=y;}\ntemplate<class\
    \ T> void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){\n\treturn o<<\"\
    (\"<<p.fs<<\",\"<<p.sc<<\")\";\n}\ntemplate<class T> ostream& operator<<(ostream&\
    \ o,const vector<T> &vc){\n\to<<\"{\";\n\tfor(const T& v:vc) o<<v<<\",\";\n\t\
    o<<\"}\";\n\treturn o;\n}\nconstexpr ll TEN(int n) { return (n == 0) ? 1 : 10\
    \ * TEN(n-1); }\n\n#ifdef LOCAL\n#define show(x) cerr << \"LINE\" << __LINE__\
    \ << \" : \" << #x << \" = \" << (x) << endl\nvoid dmpr(ostream& os){os<<endl;}\n\
    template<class T,class... Args>\nvoid dmpr(ostream&os,const T&t,const Args&...\
    \ args){\n\tos<<t<<\" ~ \";\n\tdmpr(os,args...);\n}\n#define shows(...) cerr <<\
    \ \"LINE\" << __LINE__ << \" : \";dmpr(cerr,##__VA_ARGS__)\n#define dump(x) cerr\
    \ << \"LINE\" << __LINE__ << \" : \" << #x << \" = {\";  \\\n\tfor(auto v: x)\
    \ cerr << v << \",\"; cerr << \"}\" << endl;\n#else\n#define show(x) void(0)\n\
    #define dump(x) void(0)\n#define shows(...) void(0)\n#endif\n\n#include \"../math/prime.cpp\"\
    \n\nint main(){\n\tcin.tie(0);\n\tios::sync_with_stdio(false);\t\t//DON'T USE\
    \ scanf/printf/puts !!\n\tcout << fixed << setprecision(20);\n\n\tint N,A,B; cin\
    \ >> N >> A >> B;\n\tlinear_sieve(N);\n\tV<int> ans;\n\tfor(int i=B;i<si(pr);i+=A)\
    \ ans.pb(pr[i]);\n\tcout << si(pr) << \" \" << si(ans) << endl;\n\tfor(int v:\
    \ ans) cout << v << \" \";\n\tcout << endl;\n}\n"
  dependsOn:
  - math/prime.cpp
  isVerificationFile: true
  path: test_oj/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2020-09-20 08:09:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test_oj/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/test_oj/enumerate_primes.test.cpp
- /verify/test_oj/enumerate_primes.test.cpp.html
title: test_oj/enumerate_primes.test.cpp
---
