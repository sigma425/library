---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/segtree/segtree_simple.hpp
    title: ds/segtree/segtree_simple.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test_oj/segtree/point_add_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#line 2 \"\
    template.hpp\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\nusing\
    \ ll = long long;\r\nusing uint = unsigned int;\r\nusing ull = unsigned long long;\r\
    \n#define rep(i,n) for(int i=0;i<int(n);i++)\r\n#define rep1(i,n) for(int i=1;i<=int(n);i++)\r\
    \n#define per(i,n) for(int i=int(n)-1;i>=0;i--)\r\n#define per1(i,n) for(int i=int(n);i>0;i--)\r\
    \n#define all(c) c.begin(),c.end()\r\n#define si(x) int(x.size())\r\n#define pb\
    \ push_back\r\n#define eb emplace_back\r\n#define fs first\r\n#define sc second\r\
    \ntemplate<class T> using V = vector<T>;\r\ntemplate<class T> using VV = vector<vector<T>>;\r\
    \ntemplate<class T,class U> bool chmax(T& x, U y){\r\n\tif(x<y){ x=y; return true;\
    \ }\r\n\treturn false;\r\n}\r\ntemplate<class T,class U> bool chmin(T& x, U y){\r\
    \n\tif(y<x){ x=y; return true; }\r\n\treturn false;\r\n}\r\ntemplate<class T>\
    \ void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}\r\ntemplate<class\
    \ T> int lwb(const V<T>& v, const T& a){return lower_bound(all(v),a) - v.begin();}\r\
    \ntemplate<class T>\r\nV<T> Vec(size_t a) {\r\n    return V<T>(a);\r\n}\r\ntemplate<class\
    \ T, class... Ts>\r\nauto Vec(size_t a, Ts... ts) {\r\n  return V<decltype(Vec<T>(ts...))>(a,\
    \ Vec<T>(ts...));\r\n}\r\ntemplate<class S,class T> ostream& operator<<(ostream&\
    \ o,const pair<S,T> &p){\r\n\treturn o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";\r\n}\r\
    \ntemplate<class T> ostream& operator<<(ostream& o,const vector<T> &vc){\r\n\t\
    o<<\"{\";\r\n\tfor(const T& v:vc) o<<v<<\",\";\r\n\to<<\"}\";\r\n\treturn o;\r\
    \n}\r\nconstexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }\r\n\r\n\
    #ifdef LOCAL\r\nconst bool DEBUG = true;\r\nconst bool SUBMIT = false;\r\n#define\
    \ show(x) cerr << \"LINE\" << __LINE__ << \" : \" << #x << \" = \" << (x) << endl\r\
    \nvoid dmpr(ostream& os){os<<endl;}\r\ntemplate<class T,class... Args>\r\nvoid\
    \ dmpr(ostream&os,const T&t,const Args&... args){\r\n\tos<<t<<\" ~ \";\r\n\tdmpr(os,args...);\r\
    \n}\r\n#define shows(...) cerr << \"LINE\" << __LINE__ << \" : \";dmpr(cerr,##__VA_ARGS__)\r\
    \n#define dump(x) cerr << \"LINE\" << __LINE__ << \" : \" << #x << \" = {\"; \
    \ \\\r\n\tfor(auto v: x) cerr << v << \",\"; cerr << \"}\" << endl;\r\n#else\r\
    \nconst bool DEBUG = false;\r\nconst bool SUBMIT = true;\r\n#define show(x) void(0)\r\
    \n#define dump(x) void(0)\r\n#define shows(...) void(0)\r\n#endif\r\n\r\ntemplate<class\
    \ D> D divFloor(D a, D b){\r\n\treturn a / b - (((a ^ b) < 0 && a % b != 0) ?\
    \ 1 : 0);\r\n}\r\ntemplate<class D> D divCeil(D a, D b) {\r\n\treturn a / b +\
    \ (((a ^ b) > 0 && a % b != 0) ? 1 : 0);\r\n}\r\n#line 1 \"ds/segtree/segtree_simple.hpp\"\
    \n/*\r\n\tsegtree\r\n\tpoint seg/add, range sum\r\n*/\r\ntemplate<class D>\r\n\
    struct Segtree{\r\n\tint N;\r\n\tvector<D> val;\r\n\r\n\tSegtree(){}\r\n\tSegtree(int\
    \ n){\r\n\t\tN = 1; while(N < n) N *= 2;\r\n\t\tval.assign(N*2, D());\r\n\t}\r\
    \n\ttemplate<class Dlike>\r\n\tSegtree(const vector<Dlike>& vs){\r\n\t\tint n\
    \ = vs.size();\r\n\t\tN = 1; while(N < n) N *= 2;\r\n\t\tval.assign(N*2, D());\r\
    \n\t\trep(i,n) val[i+N] = vs[i];\r\n\t\tfor(int i=N-1;i>0;i--) val[i] = D::op(val[i*2],val[i*2+1]);\r\
    \n\t}\r\n\tvoid set(int k, D v){\r\n\t\tk += N;\r\n\t\tval[k] = v;\r\n\t\tk /=\
    \ 2;\r\n\t\twhile(k){\r\n\t\t\tval[k] = D::op(val[k*2],val[k*2+1]);\r\n\t\t\t\
    k /= 2;\r\n\t\t}\r\n\t}\r\n\tvoid add(int k, D v){\r\n\t\tk += N;\r\n\t\tval[k]\
    \ = D::op(val[k],v);\r\n\t\tk /= 2;\r\n\t\twhile(k){\r\n\t\t\tval[k] = D::op(val[k*2],val[k*2+1]);\r\
    \n\t\t\tk /= 2;\r\n\t\t}\r\n\t}\r\n\tD query(int a, int b){\t\t//non-commutative\
    \ & unrecursive\r\n\t\tD L = D() , R = D();\r\n\t\ta += N, b += N;\r\n\t\twhile(a<b){\r\
    \n\t\t\tif(a&1) L = D::op(L,val[a++]);\r\n\t\t\tif(b&1) R = D::op(val[--b],R);\r\
    \n\t\t\ta /= 2, b /= 2;\r\n\t\t}\r\n\t\treturn D::op(L,R);\r\n\t}\r\n};\r\n\r\n\
    // struct D{\r\n// \tint v;\r\n// \tD(){ *this = e(); }\r\n// \tD(int v_):v(v_){}\r\
    \n// \tstatic D op(const D& x,const D& y){\r\n// \t\treturn D(x.v+y.v);\r\n//\
    \ \t}\r\n// \tconst static D e(){\r\n// \t\treturn D(0);\r\n// \t}\r\n// //\t\
    friend ostream& operator<<(ostream& o,const D& d){return o<<d.v;}\r\n// };\r\n\
    #line 5 \"test_oj/segtree/point_add_range_sum.test.cpp\"\n\nstruct D{\n\tll v;\n\
    \tD(){ *this = e(); }\n\tD(ll v_):v(v_){}\n\tstatic D op(const D& x,const D& y){\n\
    \t\treturn D(x.v+y.v);\n\t}\n\tconst static D e(){\n\t\treturn D(0);\n\t}\n\t\
    friend ostream& operator<<(ostream& o,const D& d){return o<<d.v;}\n};\n\nint main(){\n\
    \tint N,Q; cin >> N >> Q;\n\tV<ll> A(N); rep(i,N) cin >> A[i];\n\tSegtree<D> seg(A);\n\
    \twhile(Q--){\n\t\tint t; cin >> t;\n\t\tif(t == 0){\n\t\t\tint i,x; cin >> i\
    \ >> x;\n\t\t\tseg.add(i,x);\n\t\t}else{\n\t\t\tint l,r; cin >> l >> r;\n\t\t\t\
    cout << seg.query(l,r) << endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"template.hpp\"\n#include \"ds/segtree/segtree_simple.hpp\"\n\nstruct\
    \ D{\n\tll v;\n\tD(){ *this = e(); }\n\tD(ll v_):v(v_){}\n\tstatic D op(const\
    \ D& x,const D& y){\n\t\treturn D(x.v+y.v);\n\t}\n\tconst static D e(){\n\t\t\
    return D(0);\n\t}\n\tfriend ostream& operator<<(ostream& o,const D& d){return\
    \ o<<d.v;}\n};\n\nint main(){\n\tint N,Q; cin >> N >> Q;\n\tV<ll> A(N); rep(i,N)\
    \ cin >> A[i];\n\tSegtree<D> seg(A);\n\twhile(Q--){\n\t\tint t; cin >> t;\n\t\t\
    if(t == 0){\n\t\t\tint i,x; cin >> i >> x;\n\t\t\tseg.add(i,x);\n\t\t}else{\n\t\
    \t\tint l,r; cin >> l >> r;\n\t\t\tcout << seg.query(l,r) << endl;\n\t\t}\n\t\
    }\n}"
  dependsOn:
  - template.hpp
  - ds/segtree/segtree_simple.hpp
  isVerificationFile: true
  path: test_oj/segtree/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-04-03 02:02:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test_oj/segtree/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test_oj/segtree/point_add_range_sum.test.cpp
- /verify/test_oj/segtree/point_add_range_sum.test.cpp.html
title: test_oj/segtree/point_add_range_sum.test.cpp
---
