---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/linear_equations_mod.hpp\"\n/*\n\t\u4E00\u5909\u6570\
    \ x \u306B\u5BFE\u3057\u3066\u3001 x = r mod m \u3084 ax = r mod m \u306A\u3069\
    \u306E\u6761\u4EF6\u3092\u8FFD\u52A0\u3057\u305F\u7D50\u679C\u6700\u7D42\u7684\
    \u306B\n\tx = r mod m \u306B\u306A\u308A\u307E\u3059\u3001\u3068\u3044\u3046 (r,m)\
    \ \u3092\u4FDD\u6301\u3059\u308B\u95A2\u6570\u7FA4\n\t\u3069\u306E\u6BB5\u968E\
    \u3067\u3082 0 <= r < m \u3092\u4EEE\u5B9A\n\t\u89E3\u304C\u5B58\u5728\u3057\u306A\
    \u3044\u3082\u306E\u306F (0,-1) \u3067\u8868\u3059\n\t\u691C\u7D22\u7528: crt,\
    \ garner, gcd\n*/\n\n#line 2 \"template.hpp\"\n\r\n#include <bits/stdc++.h>\r\n\
    using namespace std;\r\nusing ll = long long;\r\nusing uint = unsigned int;\r\n\
    using ull = unsigned long long;\r\n#define rep(i,n) for(int i=0;i<int(n);i++)\r\
    \n#define rep1(i,n) for(int i=1;i<=int(n);i++)\r\n#define per(i,n) for(int i=int(n)-1;i>=0;i--)\r\
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
    \ ? 1 : 10 * TEN(n-1); }\r\n\r\n#ifdef LOCAL\r\nconst bool DEBUG = true;\r\nconst\
    \ bool SUBMIT = false;\r\n#define show(x) cerr << \"LINE\" << __LINE__ << \" :\
    \ \" << #x << \" = \" << (x) << endl\r\nvoid dmpr(ostream& os){os<<endl;}\r\n\
    template<class T,class... Args>\r\nvoid dmpr(ostream&os,const T&t,const Args&...\
    \ args){\r\n\tos<<t<<\" ~ \";\r\n\tdmpr(os,args...);\r\n}\r\n#define shows(...)\
    \ cerr << \"LINE\" << __LINE__ << \" : \";dmpr(cerr,##__VA_ARGS__)\r\n#define\
    \ dump(x) cerr << \"LINE\" << __LINE__ << \" : \" << #x << \" = {\";  \\\r\n\t\
    for(auto v: x) cerr << v << \",\"; cerr << \"}\" << endl;\r\n#else\r\nconst bool\
    \ DEBUG = false;\r\nconst bool SUBMIT = true;\r\n#define show(x) void(0)\r\n#define\
    \ dump(x) void(0)\r\n#define shows(...) void(0)\r\n#endif\r\n\r\ntemplate<class\
    \ D> D divFloor(D a, D b){\r\n\treturn a / b - (((a ^ b) < 0 && a % b != 0) ?\
    \ 1 : 0);\r\n}\r\ntemplate<class D> D divCeil(D a, D b) {\r\n\treturn a / b +\
    \ (((a ^ b) > 0 && a % b != 0) ? 1 : 0);\r\n}\r\n#line 10 \"math/linear_equations_mod.hpp\"\
    \n\ntemplate<class T> struct EG { T g, x, y; };\ntemplate<class T>\nEG<T> extgcd_sub(T\
    \ a, T b) {\n\tif(b == 0){\n\t\tif (a >= 0) return {a, 1, 0};\n\t\telse return\
    \ {-a, -1, 0};\n\t}else{\n\t\tauto e = extgcd_sub(b, a % b);\n\t\treturn {e.g,\
    \ e.y, e.x - a / b * e.y};\n\t}\n}\ntemplate<class T>\nEG<T> extgcd(T a, T b){\n\
    \tauto e = extgcd_sub(a,b);\n\tif(e.x < 0){\n\t\tif(b > 0){\n\t\t\te.x += b/e.g;\n\
    \t\t\te.y -= a/e.g;\n\t\t}else{\n\t\t\te.x -= b/e.g;\n\t\t\te.y += a/e.g;\n\t\t\
    }\n\t}\n\treturn e;\n}\n\n/*\n\tx = r1 mod m1, x = r2 mod m2\n\t<=> x = r mod\
    \ m\n*/\ntemplate<class T>\npair<T,T> crt2(T r1, T m1, T r2, T m2){\n\tif(m1 ==\
    \ -1 || m2 == -1) return {0,-1};\n\tauto e = extgcd(m1,m2);\n\tT g = e.g;\n\t\
    if((r2-r1)%g) return {0,-1};\n\tT q = (r2-r1)/g * e.x % (m2/g);\n\tT r = r1 +\
    \ m1 * q;\n\tT m = m1 * (m2/g);\n\tif(r < 0) r += m;\n\treturn {r,m};\n}\n\n/*\n\
    \tax = r mod m\n\t<=> x = r' mod m'\n*/\ntemplate<class T>\npair<T,T> get_monic(T\
    \ a, T r, T m){\n\tif(m == -1) return {0,-1};\n\tauto [rr,mm] = crt2<T>(r,m,0,a);\n\
    \tif(mm == -1) return {0,-1};\n\treturn {rr/a, mm/a};\n}\n"
  code: "/*\n\t\u4E00\u5909\u6570 x \u306B\u5BFE\u3057\u3066\u3001 x = r mod m \u3084\
    \ ax = r mod m \u306A\u3069\u306E\u6761\u4EF6\u3092\u8FFD\u52A0\u3057\u305F\u7D50\
    \u679C\u6700\u7D42\u7684\u306B\n\tx = r mod m \u306B\u306A\u308A\u307E\u3059\u3001\
    \u3068\u3044\u3046 (r,m) \u3092\u4FDD\u6301\u3059\u308B\u95A2\u6570\u7FA4\n\t\u3069\
    \u306E\u6BB5\u968E\u3067\u3082 0 <= r < m \u3092\u4EEE\u5B9A\n\t\u89E3\u304C\u5B58\
    \u5728\u3057\u306A\u3044\u3082\u306E\u306F (0,-1) \u3067\u8868\u3059\n\t\u691C\
    \u7D22\u7528: crt, garner, gcd\n*/\n\n#include \"template.hpp\"\n\ntemplate<class\
    \ T> struct EG { T g, x, y; };\ntemplate<class T>\nEG<T> extgcd_sub(T a, T b)\
    \ {\n\tif(b == 0){\n\t\tif (a >= 0) return {a, 1, 0};\n\t\telse return {-a, -1,\
    \ 0};\n\t}else{\n\t\tauto e = extgcd_sub(b, a % b);\n\t\treturn {e.g, e.y, e.x\
    \ - a / b * e.y};\n\t}\n}\ntemplate<class T>\nEG<T> extgcd(T a, T b){\n\tauto\
    \ e = extgcd_sub(a,b);\n\tif(e.x < 0){\n\t\tif(b > 0){\n\t\t\te.x += b/e.g;\n\t\
    \t\te.y -= a/e.g;\n\t\t}else{\n\t\t\te.x -= b/e.g;\n\t\t\te.y += a/e.g;\n\t\t\
    }\n\t}\n\treturn e;\n}\n\n/*\n\tx = r1 mod m1, x = r2 mod m2\n\t<=> x = r mod\
    \ m\n*/\ntemplate<class T>\npair<T,T> crt2(T r1, T m1, T r2, T m2){\n\tif(m1 ==\
    \ -1 || m2 == -1) return {0,-1};\n\tauto e = extgcd(m1,m2);\n\tT g = e.g;\n\t\
    if((r2-r1)%g) return {0,-1};\n\tT q = (r2-r1)/g * e.x % (m2/g);\n\tT r = r1 +\
    \ m1 * q;\n\tT m = m1 * (m2/g);\n\tif(r < 0) r += m;\n\treturn {r,m};\n}\n\n/*\n\
    \tax = r mod m\n\t<=> x = r' mod m'\n*/\ntemplate<class T>\npair<T,T> get_monic(T\
    \ a, T r, T m){\n\tif(m == -1) return {0,-1};\n\tauto [rr,mm] = crt2<T>(r,m,0,a);\n\
    \tif(mm == -1) return {0,-1};\n\treturn {rr/a, mm/a};\n}"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: math/linear_equations_mod.hpp
  requiredBy: []
  timestamp: '2025-04-03 02:02:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/linear_equations_mod.hpp
layout: document
redirect_from:
- /library/math/linear_equations_mod.hpp
- /library/math/linear_equations_mod.hpp.html
title: math/linear_equations_mod.hpp
---
