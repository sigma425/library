---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../data structure/segtree/segbeats.cpp:\
    \ line -1: no such header\n"
  code: "#ifdef __clang__\n#define IGNORE\n#else\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n#endif\n\n#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){\n\treturn o<<\"\
    (\"<<p.fs<<\",\"<<p.sc<<\")\";\n}\ntemplate<class T> ostream& operator<<(ostream&\
    \ o,const vector<T> &vc){\n\to<<\"{\";\n\tfor(const T& v:vc) o<<v<<\",\";\n\t\
    o<<\"}\";\n\treturn o;\n}\nusing ll = long long;\ntemplate<class T> using V =\
    \ vector<T>;\ntemplate<class T> using VV = vector<vector<T>>;\nconstexpr ll TEN(int\
    \ n) { return (n == 0) ? 1 : 10 * TEN(n-1); }\n\n#ifdef LOCAL\n#define show(x)\
    \ cerr << \"LINE\" << __LINE__ << \" : \" << #x << \" = \" << (x) << endl\n#else\n\
    #define show(x) true\n#endif\n\n#include \"../../data structure/segtree/segbeats.cpp\"\
    \n\nstruct D{\n\tint sz=1;\n\tll sm=0,lz=0;\n\tD(ll v=0){sm=v;}\n\tstatic D merge(D\
    \ l,D r){\n\t\tD z;\n\t\tz.sz = l.sz+r.sz;\n\t\tz.sm = l.sm+r.sm;\n\t\treturn\
    \ z;\n\t}\n\tvoid push(D& x,D& y){\n\t\tx.sm += lz * x.sz; x.lz += lz;\n\t\ty.sm\
    \ += lz * y.sz; y.lz += lz;\n\t\tlz = 0;\n\t}\n\tbool add(ll v){\n\t\tassert(sz\
    \ == 1);\n\t\tsm += v;\n\t\treturn true;\n\t}\n\tll getsum(){\n\t\treturn sm;\n\
    \t}\n};\n\n\nint main(){\n\tcin.tie(0);\n\tios::sync_with_stdio(false);\t\t//DON'T\
    \ USE scanf/printf/puts !!\n\tcout << fixed << setprecision(20);\n\n\tint N,Q;\
    \ cin >> N >> Q;\n\tV<int> a(N); rep(i,N) cin >> a[i];\n\tsegbeats<D> seg(a);\n\
    \twhile(Q--){\n\t\tint t; cin >> t;\n\t\tif(t == 0){\n\t\t\tint p,x; cin >> p\
    \ >> x;\n\t\t\tseg.ch(p,p+1,&D::add,x);\n\t\t}else{\n\t\t\tint l,r; cin >> l >>\
    \ r;\n\t\t\tcout << seg.get(l,r,&D::getsum,[&](ll x,ll y){return x+y;},0LL) <<\
    \ endl;\n\t\t}\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test_oj/beats/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_oj/beats/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test_oj/beats/point_add_range_sum.test.cpp
- /verify/test_oj/beats/point_add_range_sum.test.cpp.html
title: test_oj/beats/point_add_range_sum.test.cpp
---