---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../math/prime.cpp:\
    \ line -1: no such header\n"
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
  dependsOn: []
  isVerificationFile: true
  path: test_oj/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_oj/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/test_oj/enumerate_primes.test.cpp
- /verify/test_oj/enumerate_primes.test.cpp.html
title: test_oj/enumerate_primes.test.cpp
---
