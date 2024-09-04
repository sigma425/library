---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://qiita.com/PruneMazui/items/8a023347772620025ad6
  bundledCode: "#line 1 \"misc/color_debug.cpp\"\n/*\n\t\u30C7\u30D0\u30C3\u30B0\u7528\
    \u306B\u30BF\u30FC\u30DF\u30CA\u30EB\u306B\u51FA\u529B\u3059\u308B\u6587\u5B57\
    \u306E\u8272\u3092\u5909\u3048\u308B\n\thttps://qiita.com/PruneMazui/items/8a023347772620025ad6\n\
    \tCOLOR(\"4?\")\u3067\u3001\n\t0 1 2 3 4 5 6 7\n\t\u9ED2\u8D64\u7DD1\u9EC3\u9752\
    \u7D2B\u6C34\u7070\n\n\t\u30B0\u30EA\u30C3\u30C9\u5857\u308A\u5206\u3051\u3068\
    \u304B\u306B\u4F7F\u3046\u3068\u3044\u3044\u304B\u3082\n*/\n#line 2 \"template.hpp\"\
    \n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\nusing ll = long long;\r\
    \nusing uint = unsigned int;\r\nusing ull = unsigned long long;\r\n#define rep(i,n)\
    \ for(int i=0;i<int(n);i++)\r\n#define rep1(i,n) for(int i=1;i<=int(n);i++)\r\n\
    #define per(i,n) for(int i=int(n)-1;i>=0;i--)\r\n#define per1(i,n) for(int i=int(n);i>0;i--)\r\
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
    #ifdef LOCAL\r\n#define show(x) cerr << \"LINE\" << __LINE__ << \" : \" << #x\
    \ << \" = \" << (x) << endl\r\nvoid dmpr(ostream& os){os<<endl;}\r\ntemplate<class\
    \ T,class... Args>\r\nvoid dmpr(ostream&os,const T&t,const Args&... args){\r\n\
    \tos<<t<<\" ~ \";\r\n\tdmpr(os,args...);\r\n}\r\n#define shows(...) cerr << \"\
    LINE\" << __LINE__ << \" : \";dmpr(cerr,##__VA_ARGS__)\r\n#define dump(x) cerr\
    \ << \"LINE\" << __LINE__ << \" : \" << #x << \" = {\";  \\\r\n\tfor(auto v: x)\
    \ cerr << v << \",\"; cerr << \"}\" << endl;\r\n#else\r\n#define show(x) void(0)\r\
    \n#define dump(x) void(0)\r\n#define shows(...) void(0)\r\n#endif\r\n\r\ntemplate<class\
    \ D> D divFloor(D a, D b){\r\n\treturn a / b - (((a ^ b) < 0 && a % b != 0) ?\
    \ 1 : 0);\r\n}\r\ntemplate<class D> D divCeil(D a, D b) {\r\n\treturn a / b +\
    \ (((a ^ b) > 0 && a % b != 0) ? 1 : 0);\r\n}\r\n\r\n/*\r\nx       0  1  2  3\
    \  4  5  6  7  8  9\r\nbsr(x) -1  0  1  1  2  2  2  2  3  3\r\n\u6700\u4E0A\u4F4D\
    bit\r\n*/\r\nint bsr(int x){\r\n\treturn x == 0 ? -1 : 31 ^ __builtin_clz(x);\r\
    \n}\r\nint bsr(uint x){\r\n\treturn x == 0 ? -1 : 31 ^ __builtin_clz(x);\r\n}\r\
    \nint bsr(ll x){\r\n\treturn x == 0 ? -1 : 63 ^ __builtin_clzll(x);\r\n}\r\nint\
    \ bsr(ull x){\r\n\treturn x == 0 ? -1 : 63 ^ __builtin_clzll(x);\r\n}\r\n\r\n\
    /*\r\nx       0  1  2  3  4  5  6  7  8  9\r\nbsl(x) -1  0  1  0  2  0  1  0 \
    \ 3  0\r\n\u6700\u4E0B\u4F4Dbit\r\n*/\r\nint bsl(int x){\r\n\tif(x==0) return\
    \ -1;\r\n\treturn __builtin_ctz(x);\r\n}\r\nint bsl(uint x){\r\n\tif(x==0) return\
    \ -1;\r\n\treturn __builtin_ctz(x);\r\n}\r\nint bsl(ll x){\r\n\tif(x==0) return\
    \ -1;\r\n\treturn __builtin_ctzll(x);\r\n}\r\nint bsl(ull x){\r\n\tif(x==0) return\
    \ -1;\r\n\treturn __builtin_ctzll(x);\r\n}\r\n#line 11 \"misc/color_debug.cpp\"\
    \n\n#define COLOR(s) (\"\\x1b[\" s \"m\")\n\n\nvoid ANDGrid(){\n\tauto printc\
    \ = [&](int c){\n\t\tif(c == 0) cout << COLOR(\"47\")<<' '<<COLOR();\n\t\tif(c\
    \ == 1) cout << COLOR(\"41\")<<'A'<<COLOR();\n\t\tif(c == 2) cout << COLOR(\"\
    44\")<<'B'<<COLOR();\n\t\tif(c == 3) cout << COLOR(\"45\")<<'X'<<COLOR();\n\t\
    };\n\tint H,W; cin>>H>>W;\n\tV<string> s(H),a(H),b(H);\n\trep(i,H) cin>>s[i];\n\
    \trep(i,H){\n\t\tif(i%2==0){\n\t\t\ta[i]=string(W-1,'#')+\".\";\n\t\t\tb[i]=string(W-1,'.')+\"\
    #\";\n\t\t}else{\n\t\t\ta[i]=\"#\"+string(W-1,'.');\n\t\t\tb[i]=\".\"+string(W-1,'#');\n\
    \t\t}\n\t}\n\trep(i,H) rep(j,W) if(s[i][j]=='#') a[i][j]=b[i][j]='#';\n\trep(i,H)\
    \ cout<<a[i]<<endl;\n\tputs(\"\");\n\trep(i,H) cout<<b[i]<<endl;\n\tputs(\"\"\
    );\n\trep(i,H){\n\t\trep(j,W) printc((a[i][j]=='#')*2 + (b[i][j]=='#'));\n\t\t\
    cout << endl;\n\t}\n}\n\nint main(){\n\n}\n"
  code: "/*\n\t\u30C7\u30D0\u30C3\u30B0\u7528\u306B\u30BF\u30FC\u30DF\u30CA\u30EB\u306B\
    \u51FA\u529B\u3059\u308B\u6587\u5B57\u306E\u8272\u3092\u5909\u3048\u308B\n\thttps://qiita.com/PruneMazui/items/8a023347772620025ad6\n\
    \tCOLOR(\"4?\")\u3067\u3001\n\t0 1 2 3 4 5 6 7\n\t\u9ED2\u8D64\u7DD1\u9EC3\u9752\
    \u7D2B\u6C34\u7070\n\n\t\u30B0\u30EA\u30C3\u30C9\u5857\u308A\u5206\u3051\u3068\
    \u304B\u306B\u4F7F\u3046\u3068\u3044\u3044\u304B\u3082\n*/\n#include \"../template.hpp\"\
    \n\n#define COLOR(s) (\"\\x1b[\" s \"m\")\n\n\nvoid ANDGrid(){\n\tauto printc\
    \ = [&](int c){\n\t\tif(c == 0) cout << COLOR(\"47\")<<' '<<COLOR();\n\t\tif(c\
    \ == 1) cout << COLOR(\"41\")<<'A'<<COLOR();\n\t\tif(c == 2) cout << COLOR(\"\
    44\")<<'B'<<COLOR();\n\t\tif(c == 3) cout << COLOR(\"45\")<<'X'<<COLOR();\n\t\
    };\n\tint H,W; cin>>H>>W;\n\tV<string> s(H),a(H),b(H);\n\trep(i,H) cin>>s[i];\n\
    \trep(i,H){\n\t\tif(i%2==0){\n\t\t\ta[i]=string(W-1,'#')+\".\";\n\t\t\tb[i]=string(W-1,'.')+\"\
    #\";\n\t\t}else{\n\t\t\ta[i]=\"#\"+string(W-1,'.');\n\t\t\tb[i]=\".\"+string(W-1,'#');\n\
    \t\t}\n\t}\n\trep(i,H) rep(j,W) if(s[i][j]=='#') a[i][j]=b[i][j]='#';\n\trep(i,H)\
    \ cout<<a[i]<<endl;\n\tputs(\"\");\n\trep(i,H) cout<<b[i]<<endl;\n\tputs(\"\"\
    );\n\trep(i,H){\n\t\trep(j,W) printc((a[i][j]=='#')*2 + (b[i][j]=='#'));\n\t\t\
    cout << endl;\n\t}\n}\n\nint main(){\n\n}"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: misc/color_debug.cpp
  requiredBy: []
  timestamp: '2024-07-25 10:58:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/color_debug.cpp
layout: document
redirect_from:
- /library/misc/color_debug.cpp
- /library/misc/color_debug.cpp.html
title: misc/color_debug.cpp
---
