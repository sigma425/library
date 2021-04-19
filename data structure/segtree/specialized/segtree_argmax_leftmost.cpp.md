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
  bundledCode: "#line 1 \"data structure/segtree/specialized/segtree_argmax_leftmost.cpp\"\
    \n/*\n\tpoint assign\n\trange leftmost argmax\n\tint/long long/(double)\n\tdouble\
    \ \u306A\u3089 \u6BD4\u8F03\u95A2\u6570\u3092\u5909\u3048\u308B\n*/\n#include\
    \ <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<n;i++)\n#define fs first\n#define\
    \ sc second\n#define chmax(x,y) x=max(x,y)\n#define chmin(x,y) x=min(x,y)\nusing\
    \ namespace std;\n\nstruct segtree{\n\tusing D = long long;\n\tD inf = 1e18;\n\
    \tusing P = pair<D,int>;\n\n\tint N;\n\tvector<P> val;\n\t\n\tsegtree(){}\n\t\
    segtree(int n){\n\t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\tval.assign(N*2,P(-inf,-1));\n\
    \t\trep(i,n) val[i+N].sc = -i;\n\t\tfor(int i=N-1;i>0;i--) val[i] = max(val[i*2],val[i*2+1]);\n\
    \t}\n\tsegtree(const vector<D>& ds){\n\t\tint n = ds.size();\n\t\tN=1;\n\t\twhile(N<n)\
    \ N*=2;\n\t\tval.assign(N*2,P(-inf,-1));\n\t\trep(i,n) val[i+N] = P(ds[i],-i);\n\
    \t\tfor(int i=N-1;i>0;i--) val[i] = max(val[i*2],val[i*2+1]);\n\t}\n\tvoid assign(int\
    \ k,D d){\n\t\tk+=N;\n\t\tval[k]=P(d,-(k-N));\n\t\tk/=2;\n\t\twhile(k){\n\t\t\t\
    val[k] = max(val[k*2],val[k*2+1]);\n\t\t\tk/=2;\n\t\t}\n\t}\n\tP getmaxa(int a,int\
    \ b){\t//P(max,rightmost argmax)\n\t\tP res = P(-inf,-1);\n\t\ta+=N,b+=N;\n\t\t\
    while(a<b){\n\t\t\tif(a&1) chmax(res,val[a++]);\n\t\t\tif(b&1) chmax(res,val[--b]);\n\
    \t\t\ta/=2,b/=2;\n\t\t}\n\t\tres.sc = -res.sc;\n\t\treturn res;\n\t}\n};\n\nint\
    \ main(){\n\tvector<long long> vc = {3,2,3,4};\n\tsegtree seg(vc);\n\tusing P\
    \ = pair<long long,int>;\n\tassert(seg.getmaxa(0,4) == P(4,3));\n\tseg.assign(3,-100);\n\
    \tassert(seg.getmaxa(0,4) == P(3,0));\n}\n"
  code: "/*\n\tpoint assign\n\trange leftmost argmax\n\tint/long long/(double)\n\t\
    double \u306A\u3089 \u6BD4\u8F03\u95A2\u6570\u3092\u5909\u3048\u308B\n*/\n#include\
    \ <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<n;i++)\n#define fs first\n#define\
    \ sc second\n#define chmax(x,y) x=max(x,y)\n#define chmin(x,y) x=min(x,y)\nusing\
    \ namespace std;\n\nstruct segtree{\n\tusing D = long long;\n\tD inf = 1e18;\n\
    \tusing P = pair<D,int>;\n\n\tint N;\n\tvector<P> val;\n\t\n\tsegtree(){}\n\t\
    segtree(int n){\n\t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\tval.assign(N*2,P(-inf,-1));\n\
    \t\trep(i,n) val[i+N].sc = -i;\n\t\tfor(int i=N-1;i>0;i--) val[i] = max(val[i*2],val[i*2+1]);\n\
    \t}\n\tsegtree(const vector<D>& ds){\n\t\tint n = ds.size();\n\t\tN=1;\n\t\twhile(N<n)\
    \ N*=2;\n\t\tval.assign(N*2,P(-inf,-1));\n\t\trep(i,n) val[i+N] = P(ds[i],-i);\n\
    \t\tfor(int i=N-1;i>0;i--) val[i] = max(val[i*2],val[i*2+1]);\n\t}\n\tvoid assign(int\
    \ k,D d){\n\t\tk+=N;\n\t\tval[k]=P(d,-(k-N));\n\t\tk/=2;\n\t\twhile(k){\n\t\t\t\
    val[k] = max(val[k*2],val[k*2+1]);\n\t\t\tk/=2;\n\t\t}\n\t}\n\tP getmaxa(int a,int\
    \ b){\t//P(max,rightmost argmax)\n\t\tP res = P(-inf,-1);\n\t\ta+=N,b+=N;\n\t\t\
    while(a<b){\n\t\t\tif(a&1) chmax(res,val[a++]);\n\t\t\tif(b&1) chmax(res,val[--b]);\n\
    \t\t\ta/=2,b/=2;\n\t\t}\n\t\tres.sc = -res.sc;\n\t\treturn res;\n\t}\n};\n\nint\
    \ main(){\n\tvector<long long> vc = {3,2,3,4};\n\tsegtree seg(vc);\n\tusing P\
    \ = pair<long long,int>;\n\tassert(seg.getmaxa(0,4) == P(4,3));\n\tseg.assign(3,-100);\n\
    \tassert(seg.getmaxa(0,4) == P(3,0));\n}"
  dependsOn: []
  isVerificationFile: false
  path: data structure/segtree/specialized/segtree_argmax_leftmost.cpp
  requiredBy: []
  timestamp: '2017-09-14 22:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/segtree/specialized/segtree_argmax_leftmost.cpp
layout: document
redirect_from:
- /library/data structure/segtree/specialized/segtree_argmax_leftmost.cpp
- /library/data structure/segtree/specialized/segtree_argmax_leftmost.cpp.html
title: data structure/segtree/specialized/segtree_argmax_leftmost.cpp
---
