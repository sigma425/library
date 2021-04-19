---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data structure/segtree/specialized/segtree_max.cpp\"\n/*\n\
    \tpoint assign\n\trange max\n\tint/long long/double\n*/\n#include <bits/stdc++.h>\n\
    #define rep(i,n) for(int i=0;i<n;i++)\n#define fs first\n#define sc second\n#define\
    \ chmax(x,y) x=max(x,y)\n#define chmin(x,y) x=min(x,y)\nusing namespace std;\n\
    \nstruct segtree{\n\tusing D = long long;\n\tD inf = 1e18;\n\n\tint N;\n\tvector<D>\
    \ val;\n\n\tsegtree(){}\n\tsegtree(int n){\n\t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\
    \tval.assign(N*2,-inf);\n\t}\n\tsegtree(const vector<D>& ds){\n\t\tint n = ds.size();\n\
    \t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\tval.assign(N*2,-inf);\n\t\trep(i,n) val[i+N]\
    \ = ds[i];\n\t\tfor(int i=N-1;i>0;i--) val[i] = max(val[i*2],val[i*2+1]);\n\t\
    }\n\tvoid assign(int k,D d){\n\t\tk+=N;\n\t\tval[k]=d;\n\t\tk/=2;\n\t\twhile(k){\n\
    \t\t\tval[k] = max(val[k*2],val[k*2+1]);\n\t\t\tk/=2;\n\t\t}\n\t}\n\tD getmax(int\
    \ a,int b){\n\t\tD res = -inf;\n\t\ta+=N,b+=N;\n\t\twhile(a<b){\n\t\t\tif(a&1)\
    \ chmax(res,val[a++]);\n\t\t\tif(b&1) chmax(res,val[--b]);\n\t\t\ta/=2,b/=2;\n\
    \t\t}\n\t\treturn res;\n\t}\n};\n\nint main(){\n\tvector<long long> vc = {1,2,3,4};\n\
    \tsegtree seg(vc);\n\tassert(seg.getmax(2,4) == 4);\n\tseg.assign(0,100);\n\t\
    assert(seg.getmax(0,3) == 100);\n}\n"
  code: "/*\n\tpoint assign\n\trange max\n\tint/long long/double\n*/\n#include <bits/stdc++.h>\n\
    #define rep(i,n) for(int i=0;i<n;i++)\n#define fs first\n#define sc second\n#define\
    \ chmax(x,y) x=max(x,y)\n#define chmin(x,y) x=min(x,y)\nusing namespace std;\n\
    \nstruct segtree{\n\tusing D = long long;\n\tD inf = 1e18;\n\n\tint N;\n\tvector<D>\
    \ val;\n\n\tsegtree(){}\n\tsegtree(int n){\n\t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\
    \tval.assign(N*2,-inf);\n\t}\n\tsegtree(const vector<D>& ds){\n\t\tint n = ds.size();\n\
    \t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\tval.assign(N*2,-inf);\n\t\trep(i,n) val[i+N]\
    \ = ds[i];\n\t\tfor(int i=N-1;i>0;i--) val[i] = max(val[i*2],val[i*2+1]);\n\t\
    }\n\tvoid assign(int k,D d){\n\t\tk+=N;\n\t\tval[k]=d;\n\t\tk/=2;\n\t\twhile(k){\n\
    \t\t\tval[k] = max(val[k*2],val[k*2+1]);\n\t\t\tk/=2;\n\t\t}\n\t}\n\tD getmax(int\
    \ a,int b){\n\t\tD res = -inf;\n\t\ta+=N,b+=N;\n\t\twhile(a<b){\n\t\t\tif(a&1)\
    \ chmax(res,val[a++]);\n\t\t\tif(b&1) chmax(res,val[--b]);\n\t\t\ta/=2,b/=2;\n\
    \t\t}\n\t\treturn res;\n\t}\n};\n\nint main(){\n\tvector<long long> vc = {1,2,3,4};\n\
    \tsegtree seg(vc);\n\tassert(seg.getmax(2,4) == 4);\n\tseg.assign(0,100);\n\t\
    assert(seg.getmax(0,3) == 100);\n}"
  dependsOn: []
  isVerificationFile: false
  path: data structure/segtree/specialized/segtree_max.cpp
  requiredBy: []
  timestamp: '2017-09-14 22:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/segtree/specialized/segtree_max.cpp
layout: document
redirect_from:
- /library/data structure/segtree/specialized/segtree_max.cpp
- /library/data structure/segtree/specialized/segtree_max.cpp.html
title: data structure/segtree/specialized/segtree_max.cpp
---
