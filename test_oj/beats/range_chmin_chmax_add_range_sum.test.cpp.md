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
  code: "/*\n\tsz=1 (1\u6557)\n\tmx2,mn2 \u66F4\u65B0\u5FD8\u308C (1\u6557)\n*/\n\
    #ifdef __clang__\n#define IGNORE\n#else\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#endif\n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\
    using uint = unsigned int;\n#define rep(i,n) for(int i=0;i<int(n);i++)\n#define\
    \ rep1(i,n) for(int i=1;i<=int(n);i++)\n#define per(i,n) for(int i=int(n)-1;i>=0;i--)\n\
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
    #define dump(x) void(0)\n#define shows(...) void(0)\n#endif\n\n#include \"../../data\
    \ structure/segtree/segbeats.cpp\"\n\nstruct D{\n\tstatic const ll inf = TEN(13);\n\
    \tll sz=0,mx=-inf,mx2=-inf,mxn=0,mn=inf,mn2=inf,mnn=0,lz=0,sm=0;\n\tD(){}\n\t\
    D(ll v){sz=1,mx=v,mxn=1,mn=v,mnn=1,sm=v;}\n\tstatic D merge(D l,D r){\n\t\tD z;\n\
    \t\tz.sz = l.sz+r.sz;\n\t\t{\n\t\t\tz.mx = max(l.mx,r.mx);\n\t\t\tif(z.mx == l.mx)\
    \ z.mxn += l.mxn;\n\t\t\tif(z.mx == r.mx) z.mxn += r.mxn;\n\t\t\tfor(ll v:{l.mx,l.mx2,r.mx,r.mx2}){\n\
    \t\t\t\tif(z.mx != v) chmax(z.mx2,v);\n\t\t\t}\n\t\t}\n\t\t{\n\t\t\tz.mn = min(l.mn,r.mn);\n\
    \t\t\tif(z.mn == l.mn) z.mnn += l.mnn;\n\t\t\tif(z.mn == r.mn) z.mnn += r.mnn;\n\
    \t\t\tfor(ll v:{l.mn,l.mn2,r.mn,r.mn2}){\n\t\t\t\tif(z.mn != v) chmin(z.mn2,v);\n\
    \t\t\t}\n\t\t}\n\t\tz.sm = l.sm+r.sm;\n\t\treturn z;\n\t}\n\tvoid push(D& x,D&\
    \ y){\n\t\tll oldmx = max(x.mx,y.mx);\n\t\tll oldmn = min(x.mn,y.mn);\n\t\trep(_,2){\n\
    \t\t\tD& z = (_ == 0 ? x : y);\n\t\t\tif(z.mn == z.mx){\t\t\t//1\n\t\t\t\tif(z.mx\
    \ == oldmx){\n\t\t\t\t\tz.sm += (mx-z.mx)*z.sz;\n\t\t\t\t\tz.mn = z.mx = mx;\n\
    \t\t\t\t}else if(z.mn == oldmn){\n\t\t\t\t\tz.sm += (mn-z.mn)*z.sz;\n\t\t\t\t\t\
    z.mn = z.mx = mn;\n\t\t\t\t}else{\n\t\t\t\t\tz.sm += lz*z.sz;\n\t\t\t\t\tz.mn\
    \ = z.mx = z.mn+lz;\n\t\t\t\t}\n\t\t\t}else{\n\t\t\t\tif(z.mx == oldmx){\n\t\t\
    \t\t\tz.sm += (mx-z.mx)*z.mxn;\n\t\t\t\t\tz.mx = mx;\n\t\t\t\t}else{\n\t\t\t\t\
    \tz.sm += lz*z.mxn;\n\t\t\t\t\tz.mx += lz;\n\t\t\t\t}\n\t\t\t\tif(z.mn == oldmn){\n\
    \t\t\t\t\tz.sm += (mn-z.mn)*z.mnn;\n\t\t\t\t\tz.mn = mn;\n\t\t\t\t}else{\n\t\t\
    \t\t\tz.sm += lz*z.mnn;\n\t\t\t\t\tz.mn += lz;\n\t\t\t\t}\n\t\t\t\tll others =\
    \ z.sz - z.mxn - z.mnn;\n\t\t\t\tif(others){\t\t\t\t// 3\n\t\t\t\t\tz.sm += lz\
    \ * others;\n\t\t\t\t\tz.mx2 += lz; z.mn2 += lz;\n\t\t\t\t}else{\t\t\t\t\t// 2\n\
    \t\t\t\t\tz.mn2 = z.mx;\n\t\t\t\t\tz.mx2 = z.mn;\n\t\t\t\t}\n\t\t\t}\n\t\t\tz.lz\
    \ += lz;\n\t\t}\n\t\tlz = 0;\n\t}\n\tbool changemin(ll v){\n\t\tif(v >= mx) return\
    \ true;\n\t\tif(v > mx2){\t//mx -> v\n\t\t\tll oldmx = mx;\n\t\t\tsm += mxn *\
    \ (v-mx);\n\t\t\tmx = v;\n\t\t\tif(oldmx == mn) mn = v;\n\t\t\tif(oldmx == mn2)\
    \ mn2 = v;\n\t\t\treturn true;\n\t\t}\n\t\treturn false;\n\t}\n\tbool changemax(ll\
    \ v){\n\t\tif(v <= mn) return true;\n\t\tif(v < mn2){\t//mn -> v\n\t\t\tll oldmn\
    \ = mn;\n\t\t\tsm += mnn * (v-mn);\n\t\t\tmn = v;\n\t\t\tif(oldmn == mx) mx =\
    \ v;\n\t\t\tif(oldmn == mx2) mx2 = v;\n\t\t\treturn true;\n\t\t}\n\t\treturn false;\n\
    \t}\n\tbool add(ll v){\n\t\tmx += v;\n\t\tif(mx2 != -inf) mx2 += v;\n\t\tmn +=\
    \ v;\n\t\tif(mn2 != inf) mn2 += v;\n\t\tsm += v * sz;\n\t\tlz += v;\n\t\treturn\
    \ true;\n\t}\n\tll getsum(){\n\t\treturn sm;\n\t}\n};\n\n\nint main(){\n\tcin.tie(0);\n\
    \tios::sync_with_stdio(false);\t\t//DON'T USE scanf/printf/puts !!\n\tcout <<\
    \ fixed << setprecision(20);\n\n\tint N,Q; cin >> N >> Q;\n\tV<ll> a(N); rep(i,N)\
    \ cin >> a[i];\n\tsegbeats<D> seg(a);\n\twhile(Q--){\n\t\tint t; cin >> t;\n\t\
    \tif(t == 0){\n\t\t\tint l,r; ll v; cin >> l >> r >> v;\n\t\t\tseg.ch(l,r,&D::changemin,v);\n\
    \t\t}\n\t\tif(t == 1){\n\t\t\tint l,r; ll v; cin >> l >> r >> v;\n\t\t\tseg.ch(l,r,&D::changemax,v);\n\
    \t\t}\n\t\tif(t == 2){\n\t\t\tint l,r; ll v; cin >> l >> r >> v;\n\t\t\tseg.ch(l,r,&D::add,v);\n\
    \t\t}\n\t\tif(t == 3){\n\t\t\tint l,r; cin >> l >> r;\n\t\t\tcout << seg.get(l,r,&D::getsum,[&](ll\
    \ x,ll y){return x+y;},0LL) << endl;\n\t\t}\n\t\t// if(false){\n\t\t// \tcout\
    \ << \"seg: \";\n\t\t// \trep(i,N){\n\t\t// \t\tauto v = seg.getNode(i,i+1);\n\
    \t\t// \t\tshows(v.sm,v.mn,v.mn2,v.mnn,\"---\",v.mx,v.mx2,v.mxn,v.lz);\n\t\t//\
    \ \t\tcout << seg.get(i,i+1,&D::getsum,[&](ll x,ll y){return x+y;},0LL) << \"\
    \ \";\n\t\t// \t}\n\t\t// \tcout << endl;\n\t\t// }\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test_oj/beats/range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_oj/beats/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test_oj/beats/range_chmin_chmax_add_range_sum.test.cpp
- /verify/test_oj/beats/range_chmin_chmax_add_range_sum.test.cpp.html
title: test_oj/beats/range_chmin_chmax_add_range_sum.test.cpp
---
