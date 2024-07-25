---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: 0.cpp
    title: 0.cpp
  - icon: ':warning:'
    path: DP/axiotis_tzamos_knapsack.hpp
    title: DP/axiotis_tzamos_knapsack.hpp
  - icon: ':heavy_check_mark:'
    path: DP/maxplus_convolution_b_concave.hpp
    title: DP/maxplus_convolution_b_concave.hpp
  - icon: ':heavy_check_mark:'
    path: DP/smawk.hpp
    title: DP/smawk.hpp
  - icon: ':warning:'
    path: geom/RotatingPoints.cpp
    title: geom/RotatingPoints.cpp
  - icon: ':warning:'
    path: math/famous_seq/unrooted_tree.cpp
    title: math/famous_seq/unrooted_tree.cpp
  - icon: ':warning:'
    path: misc/color_debug.cpp
    title: misc/color_debug.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_oj/maxplus_convolution_b_concave.test.cpp
    title: test_oj/maxplus_convolution_b_concave.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_oj/online_conv/online_conv.test.cpp
    title: test_oj/online_conv/online_conv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_oj/online_conv/online_div.test.cpp
    title: test_oj/online_conv/online_div.test.cpp
  - icon: ':x:'
    path: test_oj/online_conv/online_pow.test.cpp
    title: test_oj/online_conv/online_pow.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\nusing ll = long long;\r\nusing uint = unsigned int;\r\nusing ull = unsigned\
    \ long long;\r\n#define rep(i,n) for(int i=0;i<int(n);i++)\r\n#define rep1(i,n)\
    \ for(int i=1;i<=int(n);i++)\r\n#define per(i,n) for(int i=int(n)-1;i>=0;i--)\r\
    \n#define per1(i,n) for(int i=int(n);i>0;i--)\r\n#define all(c) c.begin(),c.end()\r\
    \n#define si(x) int(x.size())\r\n#define pb push_back\r\n#define eb emplace_back\r\
    \n#define fs first\r\n#define sc second\r\ntemplate<class T> using V = vector<T>;\r\
    \ntemplate<class T> using VV = vector<vector<T>>;\r\ntemplate<class T,class U>\
    \ bool chmax(T& x, U y){\r\n\tif(x<y){ x=y; return true; }\r\n\treturn false;\r\
    \n}\r\ntemplate<class T,class U> bool chmin(T& x, U y){\r\n\tif(y<x){ x=y; return\
    \ true; }\r\n\treturn false;\r\n}\r\ntemplate<class T> void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}\r\
    \ntemplate<class T> int lwb(const V<T>& v, const T& a){return lower_bound(all(v),a)\
    \ - v.begin();}\r\ntemplate<class T>\r\nV<T> Vec(size_t a) {\r\n    return V<T>(a);\r\
    \n}\r\ntemplate<class T, class... Ts>\r\nauto Vec(size_t a, Ts... ts) {\r\n  return\
    \ V<decltype(Vec<T>(ts...))>(a, Vec<T>(ts...));\r\n}\r\ntemplate<class S,class\
    \ T> ostream& operator<<(ostream& o,const pair<S,T> &p){\r\n\treturn o<<\"(\"\
    <<p.fs<<\",\"<<p.sc<<\")\";\r\n}\r\ntemplate<class T> ostream& operator<<(ostream&\
    \ o,const vector<T> &vc){\r\n\to<<\"{\";\r\n\tfor(const T& v:vc) o<<v<<\",\";\r\
    \n\to<<\"}\";\r\n\treturn o;\r\n}\r\nconstexpr ll TEN(int n) { return (n == 0)\
    \ ? 1 : 10 * TEN(n-1); }\r\n\r\n#ifdef LOCAL\r\n#define show(x) cerr << \"LINE\"\
    \ << __LINE__ << \" : \" << #x << \" = \" << (x) << endl\r\nvoid dmpr(ostream&\
    \ os){os<<endl;}\r\ntemplate<class T,class... Args>\r\nvoid dmpr(ostream&os,const\
    \ T&t,const Args&... args){\r\n\tos<<t<<\" ~ \";\r\n\tdmpr(os,args...);\r\n}\r\
    \n#define shows(...) cerr << \"LINE\" << __LINE__ << \" : \";dmpr(cerr,##__VA_ARGS__)\r\
    \n#define dump(x) cerr << \"LINE\" << __LINE__ << \" : \" << #x << \" = {\"; \
    \ \\\r\n\tfor(auto v: x) cerr << v << \",\"; cerr << \"}\" << endl;\r\n#else\r\
    \n#define show(x) void(0)\r\n#define dump(x) void(0)\r\n#define shows(...) void(0)\r\
    \n#endif\r\n\r\ntemplate<class D> D divFloor(D a, D b){\r\n\treturn a / b - (((a\
    \ ^ b) < 0 && a % b != 0) ? 1 : 0);\r\n}\r\ntemplate<class D> D divCeil(D a, D\
    \ b) {\r\n\treturn a / b + (((a ^ b) > 0 && a % b != 0) ? 1 : 0);\r\n}\r\n\r\n\
    /*\r\nx       0  1  2  3  4  5  6  7  8  9\r\nbsr(x) -1  0  1  1  2  2  2  2 \
    \ 3  3\r\n\u6700\u4E0A\u4F4Dbit\r\n*/\r\nint bsr(int x){\r\n\treturn x == 0 ?\
    \ -1 : 31 ^ __builtin_clz(x);\r\n}\r\nint bsr(uint x){\r\n\treturn x == 0 ? -1\
    \ : 31 ^ __builtin_clz(x);\r\n}\r\nint bsr(ll x){\r\n\treturn x == 0 ? -1 : 63\
    \ ^ __builtin_clzll(x);\r\n}\r\nint bsr(ull x){\r\n\treturn x == 0 ? -1 : 63 ^\
    \ __builtin_clzll(x);\r\n}\r\n\r\n/*\r\nx       0  1  2  3  4  5  6  7  8  9\r\
    \nbsl(x) -1  0  1  0  2  0  1  0  3  0\r\n\u6700\u4E0B\u4F4Dbit\r\n*/\r\nint bsl(int\
    \ x){\r\n\tif(x==0) return -1;\r\n\treturn __builtin_ctz(x);\r\n}\r\nint bsl(uint\
    \ x){\r\n\tif(x==0) return -1;\r\n\treturn __builtin_ctz(x);\r\n}\r\nint bsl(ll\
    \ x){\r\n\tif(x==0) return -1;\r\n\treturn __builtin_ctzll(x);\r\n}\r\nint bsl(ull\
    \ x){\r\n\tif(x==0) return -1;\r\n\treturn __builtin_ctzll(x);\r\n}\r\n\r\n\r\n\
    template<class T>\r\nT rnd(T l,T r){\t//[l,r)\r\n\tusing D = uniform_int_distribution<T>;\r\
    \n\tstatic random_device rd;\r\n\tstatic mt19937 gen(rd());\r\n\treturn D(l,r-1)(gen);\r\
    \n}\r\ntemplate<class T>\r\nT rnd(T n){\t//[0,n)\r\n\treturn rnd(T(0),n);\r\n\
    }\r\n"
  code: "#pragma once\r\n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\
    using ll = long long;\r\nusing uint = unsigned int;\r\nusing ull = unsigned long\
    \ long;\r\n#define rep(i,n) for(int i=0;i<int(n);i++)\r\n#define rep1(i,n) for(int\
    \ i=1;i<=int(n);i++)\r\n#define per(i,n) for(int i=int(n)-1;i>=0;i--)\r\n#define\
    \ per1(i,n) for(int i=int(n);i>0;i--)\r\n#define all(c) c.begin(),c.end()\r\n\
    #define si(x) int(x.size())\r\n#define pb push_back\r\n#define eb emplace_back\r\
    \n#define fs first\r\n#define sc second\r\ntemplate<class T> using V = vector<T>;\r\
    \ntemplate<class T> using VV = vector<vector<T>>;\r\ntemplate<class T,class U>\
    \ bool chmax(T& x, U y){\r\n\tif(x<y){ x=y; return true; }\r\n\treturn false;\r\
    \n}\r\ntemplate<class T,class U> bool chmin(T& x, U y){\r\n\tif(y<x){ x=y; return\
    \ true; }\r\n\treturn false;\r\n}\r\ntemplate<class T> void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}\r\
    \ntemplate<class T> int lwb(const V<T>& v, const T& a){return lower_bound(all(v),a)\
    \ - v.begin();}\r\ntemplate<class T>\r\nV<T> Vec(size_t a) {\r\n    return V<T>(a);\r\
    \n}\r\ntemplate<class T, class... Ts>\r\nauto Vec(size_t a, Ts... ts) {\r\n  return\
    \ V<decltype(Vec<T>(ts...))>(a, Vec<T>(ts...));\r\n}\r\ntemplate<class S,class\
    \ T> ostream& operator<<(ostream& o,const pair<S,T> &p){\r\n\treturn o<<\"(\"\
    <<p.fs<<\",\"<<p.sc<<\")\";\r\n}\r\ntemplate<class T> ostream& operator<<(ostream&\
    \ o,const vector<T> &vc){\r\n\to<<\"{\";\r\n\tfor(const T& v:vc) o<<v<<\",\";\r\
    \n\to<<\"}\";\r\n\treturn o;\r\n}\r\nconstexpr ll TEN(int n) { return (n == 0)\
    \ ? 1 : 10 * TEN(n-1); }\r\n\r\n#ifdef LOCAL\r\n#define show(x) cerr << \"LINE\"\
    \ << __LINE__ << \" : \" << #x << \" = \" << (x) << endl\r\nvoid dmpr(ostream&\
    \ os){os<<endl;}\r\ntemplate<class T,class... Args>\r\nvoid dmpr(ostream&os,const\
    \ T&t,const Args&... args){\r\n\tos<<t<<\" ~ \";\r\n\tdmpr(os,args...);\r\n}\r\
    \n#define shows(...) cerr << \"LINE\" << __LINE__ << \" : \";dmpr(cerr,##__VA_ARGS__)\r\
    \n#define dump(x) cerr << \"LINE\" << __LINE__ << \" : \" << #x << \" = {\"; \
    \ \\\r\n\tfor(auto v: x) cerr << v << \",\"; cerr << \"}\" << endl;\r\n#else\r\
    \n#define show(x) void(0)\r\n#define dump(x) void(0)\r\n#define shows(...) void(0)\r\
    \n#endif\r\n\r\ntemplate<class D> D divFloor(D a, D b){\r\n\treturn a / b - (((a\
    \ ^ b) < 0 && a % b != 0) ? 1 : 0);\r\n}\r\ntemplate<class D> D divCeil(D a, D\
    \ b) {\r\n\treturn a / b + (((a ^ b) > 0 && a % b != 0) ? 1 : 0);\r\n}\r\n\r\n\
    /*\r\nx       0  1  2  3  4  5  6  7  8  9\r\nbsr(x) -1  0  1  1  2  2  2  2 \
    \ 3  3\r\n\u6700\u4E0A\u4F4Dbit\r\n*/\r\nint bsr(int x){\r\n\treturn x == 0 ?\
    \ -1 : 31 ^ __builtin_clz(x);\r\n}\r\nint bsr(uint x){\r\n\treturn x == 0 ? -1\
    \ : 31 ^ __builtin_clz(x);\r\n}\r\nint bsr(ll x){\r\n\treturn x == 0 ? -1 : 63\
    \ ^ __builtin_clzll(x);\r\n}\r\nint bsr(ull x){\r\n\treturn x == 0 ? -1 : 63 ^\
    \ __builtin_clzll(x);\r\n}\r\n\r\n/*\r\nx       0  1  2  3  4  5  6  7  8  9\r\
    \nbsl(x) -1  0  1  0  2  0  1  0  3  0\r\n\u6700\u4E0B\u4F4Dbit\r\n*/\r\nint bsl(int\
    \ x){\r\n\tif(x==0) return -1;\r\n\treturn __builtin_ctz(x);\r\n}\r\nint bsl(uint\
    \ x){\r\n\tif(x==0) return -1;\r\n\treturn __builtin_ctz(x);\r\n}\r\nint bsl(ll\
    \ x){\r\n\tif(x==0) return -1;\r\n\treturn __builtin_ctzll(x);\r\n}\r\nint bsl(ull\
    \ x){\r\n\tif(x==0) return -1;\r\n\treturn __builtin_ctzll(x);\r\n}\r\n\r\n\r\n\
    template<class T>\r\nT rnd(T l,T r){\t//[l,r)\r\n\tusing D = uniform_int_distribution<T>;\r\
    \n\tstatic random_device rd;\r\n\tstatic mt19937 gen(rd());\r\n\treturn D(l,r-1)(gen);\r\
    \n}\r\ntemplate<class T>\r\nT rnd(T n){\t//[0,n)\r\n\treturn rnd(T(0),n);\r\n\
    }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: template.hpp
  requiredBy:
  - DP/smawk.hpp
  - DP/maxplus_convolution_b_concave.hpp
  - DP/axiotis_tzamos_knapsack.hpp
  - 0.cpp
  - misc/color_debug.cpp
  - math/famous_seq/unrooted_tree.cpp
  - geom/RotatingPoints.cpp
  timestamp: '2024-03-26 11:02:36+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_oj/online_conv/online_pow.test.cpp
  - test_oj/online_conv/online_conv.test.cpp
  - test_oj/online_conv/online_div.test.cpp
  - test_oj/maxplus_convolution_b_concave.test.cpp
documentation_of: template.hpp
layout: document
redirect_from:
- /library/template.hpp
- /library/template.hpp.html
title: template.hpp
---
