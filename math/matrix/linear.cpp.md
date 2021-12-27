---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_oj/inv_matrix.test.cpp
    title: test_oj/inv_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_oj/linearEquation.test.cpp
    title: test_oj/linearEquation.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/matrix/linear.cpp\"\n/*\n\t\u7DDA\u5F62\u4EE3\u6570\
    \u3044\u308D\u3044\u308D\n\tverified: yosupo\n*/\n\ntemplate<class T>\nT det(vector<vector<T>>\
    \ a){\n\tassert(a.size() == a[0].size());\n\tint n = a.size();\n\tT ans = 1;\n\
    \trep(i,n){\n\t\tfor(int j=i+1;j<n;j++) if(a[j][i]){\n\t\t\tans = -ans;\n\t\t\t\
    swap(a[j],a[i]);\n\t\t\tbreak;\n\t\t}\n\t\tif(!a[i][i]) return T(0);\n\t\tans\
    \ *= a[i][i];\n\t\tfor(int j=i+1;j<n;j++){\n\t\t\tT w = -a[j][i]/a[i][i];\n\t\t\
    \tfor(int k=i;k<n;k++) a[j][k] += a[i][k]*w;\n\t\t}\n\t}\n\treturn ans;\t\n}\n\
    /*\n\t\u5DE6c\u5217\u3092sweep \u6307\u5B9A\u3057\u306A\u3044\u3068c = w\n\t\u884C\
    \u306Eswap\u306F\u3059\u308B\n\t\u6383\u304D\u51FA\u3057\u306B\u4F7F\u3063\u305F\
    \u5217\u306E\u96C6\u5408\u3092\u8FD4\u3059\n*/\ntemplate<class T>\nvector<int>\
    \ sweep(vector<vector<T>>& a, int c = -1){\n\tif(a.empty()) return {};\n\tif(c\
    \ == -1) c = a[0].size();\n\tint h = a.size(), w = a[0].size(), r = 0;\n\tvector<int>\
    \ used_col;\n\trep(i,c){\n\t\tif(r == h) break;\n\t\tfor(int j=r;j<h;j++) if(a[j][i]){\n\
    \t\t\tswap(a[r],a[j]); break;\n\t\t}\n\t\tif(!a[r][i]) continue;\n\t\trep(j,h)\
    \ if(j != r){\n\t\t\tconst T t = -a[j][i]/a[r][i];\n\t\t\tfor(int k=i;k<w;k++)\
    \ a[j][k] += a[r][k]*t;\n\t\t}\n\t\tused_col.pb(i);\n\t\tr++;\n\t}\n\treturn used_col;\n\
    }\n\n/*\n\tax = b \u306E\u89E3\u306E\u3072\u3068\u3064\u3092\u51FA\u529B\n\t\u89E3\
    \u7A7A\u9593\u306F (output) + ker(a)\n\t\u89E3\u304C\u5B58\u5728\u3057\u306A\u3044\
    \u306A\u3089 {}\n\n\t\u5F0F\u304C0\u500B(si(a) == 0) \u3067\u58CA\u308C\u306A\u3044\
    \u3088\u3046\u306B\u5909\u6570\u306E\u500B\u6570 ( = si(a[0]) ) w \u3092\u4E0E\
    \u3048\u308B\n*/\ntemplate<class T>\nvector<T> linearEquation(vector<vector<T>>\
    \ a, int w, vector<T> b){\n\tassert(a.size() == b.size());\n\tint h = a.size();\n\
    \trep(i,h) a[i].pb(b[i]);\n\tvector<int> idx = sweep(a,w);\n\tfor(int i = idx.size();i<h;i++)\
    \ if(a[i][w]) return {};\n\tvector<T> x(w);\n\trep(i,idx.size()) x[idx[i]] = a[i][w]\
    \ / a[i][idx[i]];\n\treturn x;\n}\n/*\n\t{x | ax = 0} \u306E\u3042\u308B\u57FA\
    \u5E95\u3092\u51FA\u529B\n\t\u5F0F\u304C0\u500B(si(a) == 0) \u3067\u58CA\u308C\
    \u306A\u3044\u3088\u3046\u306B\u5909\u6570\u306E\u500B\u6570 ( = si(a[0]) ) w\
    \ \u3092\u4E0E\u3048\u308B\n\tsi(kernel) + rank(a) == w\n*/\ntemplate<class T>\n\
    vector<vector<T>> kernel(vector<vector<T>> a, int w){\n\tint h = a.size();\n\t\
    vector<vector<T>> b(w,vector<T>(h+w));\n\trep(i,h) rep(j,w) b[j][i] = a[i][j];\n\
    \trep(i,w) b[i][h+i] = 1;\n\tint r = sweep(b,h).size();\n\tvector<vector<T>> res;\n\
    \tfor(int i=r;i<w;i++) res.eb(b[i].begin()+h,b[i].end());\n\treturn res;\n}\n\n\
    \n\n/*\n\tinversion\n\t\u306A\u3051\u308C\u3070 {{}}\n*/\ntemplate<class T>\n\
    vector<vector<T>> inv(vector<vector<T>> a){\n\tassert(a.size() == a[0].size());\n\
    \tvector<vector<T>> no;\n\tint n = a.size();\n\tvector<int> ih(n,-1), jh(n,-1);\n\
    \trep(k,n){\n\t\tfor(int i=k;i<n;i++) if(ih[k] == -1){\n\t\t\tfor(int j=k;j<n;j++)\
    \ if(a[i][j]){\n\t\t\t\tih[k] = i, jh[k] = j; break;\n\t\t\t}\n\t\t}\n\t\tif(ih[k]\
    \ == -1) return no;\n\t\trep(j,n) swap(a[k][j],a[ih[k]][j]);\n\t\trep(i,n) swap(a[i][k],a[i][jh[k]]);\n\
    \t\tif(!a[k][k]) return no;\n\t\ta[k][k] = a[k][k].inv();\n\t\trep(i,n) if(i !=\
    \ k) a[k][i] *= a[k][k];\n\t\trep(i,n) if(i != k){\n\t\t\trep(j,n) if(j != k){\n\
    \t\t\t\ta[i][j] -= a[i][k]*a[k][j];\n\t\t\t}\n\t\t}\n\t\trep(i,n) if(i != k) a[i][k]\
    \ *= -a[k][k];\n\t}\n\tper(k,n){\n\t\trep(j,n) swap(a[k][j],a[jh[k]][j]);\n\t\t\
    rep(i,n) swap(a[i][k],a[i][ih[k]]);\n\t}\n\treturn a;\n}\n"
  code: "/*\n\t\u7DDA\u5F62\u4EE3\u6570\u3044\u308D\u3044\u308D\n\tverified: yosupo\n\
    */\n\ntemplate<class T>\nT det(vector<vector<T>> a){\n\tassert(a.size() == a[0].size());\n\
    \tint n = a.size();\n\tT ans = 1;\n\trep(i,n){\n\t\tfor(int j=i+1;j<n;j++) if(a[j][i]){\n\
    \t\t\tans = -ans;\n\t\t\tswap(a[j],a[i]);\n\t\t\tbreak;\n\t\t}\n\t\tif(!a[i][i])\
    \ return T(0);\n\t\tans *= a[i][i];\n\t\tfor(int j=i+1;j<n;j++){\n\t\t\tT w =\
    \ -a[j][i]/a[i][i];\n\t\t\tfor(int k=i;k<n;k++) a[j][k] += a[i][k]*w;\n\t\t}\n\
    \t}\n\treturn ans;\t\n}\n/*\n\t\u5DE6c\u5217\u3092sweep \u6307\u5B9A\u3057\u306A\
    \u3044\u3068c = w\n\t\u884C\u306Eswap\u306F\u3059\u308B\n\t\u6383\u304D\u51FA\u3057\
    \u306B\u4F7F\u3063\u305F\u5217\u306E\u96C6\u5408\u3092\u8FD4\u3059\n*/\ntemplate<class\
    \ T>\nvector<int> sweep(vector<vector<T>>& a, int c = -1){\n\tif(a.empty()) return\
    \ {};\n\tif(c == -1) c = a[0].size();\n\tint h = a.size(), w = a[0].size(), r\
    \ = 0;\n\tvector<int> used_col;\n\trep(i,c){\n\t\tif(r == h) break;\n\t\tfor(int\
    \ j=r;j<h;j++) if(a[j][i]){\n\t\t\tswap(a[r],a[j]); break;\n\t\t}\n\t\tif(!a[r][i])\
    \ continue;\n\t\trep(j,h) if(j != r){\n\t\t\tconst T t = -a[j][i]/a[r][i];\n\t\
    \t\tfor(int k=i;k<w;k++) a[j][k] += a[r][k]*t;\n\t\t}\n\t\tused_col.pb(i);\n\t\
    \tr++;\n\t}\n\treturn used_col;\n}\n\n/*\n\tax = b \u306E\u89E3\u306E\u3072\u3068\
    \u3064\u3092\u51FA\u529B\n\t\u89E3\u7A7A\u9593\u306F (output) + ker(a)\n\t\u89E3\
    \u304C\u5B58\u5728\u3057\u306A\u3044\u306A\u3089 {}\n\n\t\u5F0F\u304C0\u500B(si(a)\
    \ == 0) \u3067\u58CA\u308C\u306A\u3044\u3088\u3046\u306B\u5909\u6570\u306E\u500B\
    \u6570 ( = si(a[0]) ) w \u3092\u4E0E\u3048\u308B\n*/\ntemplate<class T>\nvector<T>\
    \ linearEquation(vector<vector<T>> a, int w, vector<T> b){\n\tassert(a.size()\
    \ == b.size());\n\tint h = a.size();\n\trep(i,h) a[i].pb(b[i]);\n\tvector<int>\
    \ idx = sweep(a,w);\n\tfor(int i = idx.size();i<h;i++) if(a[i][w]) return {};\n\
    \tvector<T> x(w);\n\trep(i,idx.size()) x[idx[i]] = a[i][w] / a[i][idx[i]];\n\t\
    return x;\n}\n/*\n\t{x | ax = 0} \u306E\u3042\u308B\u57FA\u5E95\u3092\u51FA\u529B\
    \n\t\u5F0F\u304C0\u500B(si(a) == 0) \u3067\u58CA\u308C\u306A\u3044\u3088\u3046\
    \u306B\u5909\u6570\u306E\u500B\u6570 ( = si(a[0]) ) w \u3092\u4E0E\u3048\u308B\
    \n\tsi(kernel) + rank(a) == w\n*/\ntemplate<class T>\nvector<vector<T>> kernel(vector<vector<T>>\
    \ a, int w){\n\tint h = a.size();\n\tvector<vector<T>> b(w,vector<T>(h+w));\n\t\
    rep(i,h) rep(j,w) b[j][i] = a[i][j];\n\trep(i,w) b[i][h+i] = 1;\n\tint r = sweep(b,h).size();\n\
    \tvector<vector<T>> res;\n\tfor(int i=r;i<w;i++) res.eb(b[i].begin()+h,b[i].end());\n\
    \treturn res;\n}\n\n\n\n/*\n\tinversion\n\t\u306A\u3051\u308C\u3070 {{}}\n*/\n\
    template<class T>\nvector<vector<T>> inv(vector<vector<T>> a){\n\tassert(a.size()\
    \ == a[0].size());\n\tvector<vector<T>> no;\n\tint n = a.size();\n\tvector<int>\
    \ ih(n,-1), jh(n,-1);\n\trep(k,n){\n\t\tfor(int i=k;i<n;i++) if(ih[k] == -1){\n\
    \t\t\tfor(int j=k;j<n;j++) if(a[i][j]){\n\t\t\t\tih[k] = i, jh[k] = j; break;\n\
    \t\t\t}\n\t\t}\n\t\tif(ih[k] == -1) return no;\n\t\trep(j,n) swap(a[k][j],a[ih[k]][j]);\n\
    \t\trep(i,n) swap(a[i][k],a[i][jh[k]]);\n\t\tif(!a[k][k]) return no;\n\t\ta[k][k]\
    \ = a[k][k].inv();\n\t\trep(i,n) if(i != k) a[k][i] *= a[k][k];\n\t\trep(i,n)\
    \ if(i != k){\n\t\t\trep(j,n) if(j != k){\n\t\t\t\ta[i][j] -= a[i][k]*a[k][j];\n\
    \t\t\t}\n\t\t}\n\t\trep(i,n) if(i != k) a[i][k] *= -a[k][k];\n\t}\n\tper(k,n){\n\
    \t\trep(j,n) swap(a[k][j],a[jh[k]][j]);\n\t\trep(i,n) swap(a[i][k],a[i][ih[k]]);\n\
    \t}\n\treturn a;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/linear.cpp
  requiredBy: []
  timestamp: '2021-12-27 22:49:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_oj/inv_matrix.test.cpp
  - test_oj/linearEquation.test.cpp
documentation_of: math/matrix/linear.cpp
layout: document
redirect_from:
- /library/math/matrix/linear.cpp
- /library/math/matrix/linear.cpp.html
title: math/matrix/linear.cpp
---
