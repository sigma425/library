---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"data structure/segtree/specialized/segtree_sum.cpp\"\n/*\n\
    \tpoint assign\n\trange sum\n\tint/long long/double\n*/\n#include <bits/stdc++.h>\n\
    #define rep(i,n) for(int i=0;i<n;i++)\n#define fs first\n#define sc second\n#define\
    \ chmax(x,y) x=max(x,y)\nusing namespace std;\n\nstruct segtree{\n\tusing D =\
    \ long long;\n\n\tint N;\n\tvector<D> val;\n\n\tsegtree(){}\n\tsegtree(int n){\n\
    \t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\tval.assign(N*2,0);\n\t}\n\tsegtree(const vector<D>&\
    \ ds){\n\t\tint n = ds.size();\n\t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\tval.assign(N*2,0);\n\
    \t\trep(i,n) val[i+N] = ds[i];\n\t\tfor(int i=N-1;i>0;i--) val[i] = val[i*2] +\
    \ val[i*2+1];\n\t}\n\tvoid assign(int k,D d){\n\t\tk+=N;\n\t\tval[k]=d;\n\t\t\
    k/=2;\n\t\twhile(k){\n\t\t\tval[k] = val[k*2] + val[k*2+1];\n\t\t\tk/=2;\n\t\t\
    }\n\t}\n\tD sum(int a,int b){\t\t//non-commutative & unrecursive\n\t\tD res =\
    \ 0;\n\t\ta+=N,b+=N;\n\t\twhile(a<b){\n\t\t\tif(a&1) res += val[a++];\n\t\t\t\
    if(b&1) res += val[--b];\n\t\t\ta/=2,b/=2;\n\t\t}\n\t\treturn res;\n\t}\n};\n\n\
    int main(){\n\tvector<long long> vc = {1,2,3,4};\n\tsegtree seg(vc);\n\tassert(seg.sum(2,4)\
    \ == 7);\n\tseg.assign(0,-100);\n\tassert(seg.sum(0,3) == -95);\n}\n"
  code: "/*\n\tpoint assign\n\trange sum\n\tint/long long/double\n*/\n#include <bits/stdc++.h>\n\
    #define rep(i,n) for(int i=0;i<n;i++)\n#define fs first\n#define sc second\n#define\
    \ chmax(x,y) x=max(x,y)\nusing namespace std;\n\nstruct segtree{\n\tusing D =\
    \ long long;\n\n\tint N;\n\tvector<D> val;\n\n\tsegtree(){}\n\tsegtree(int n){\n\
    \t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\tval.assign(N*2,0);\n\t}\n\tsegtree(const vector<D>&\
    \ ds){\n\t\tint n = ds.size();\n\t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\tval.assign(N*2,0);\n\
    \t\trep(i,n) val[i+N] = ds[i];\n\t\tfor(int i=N-1;i>0;i--) val[i] = val[i*2] +\
    \ val[i*2+1];\n\t}\n\tvoid assign(int k,D d){\n\t\tk+=N;\n\t\tval[k]=d;\n\t\t\
    k/=2;\n\t\twhile(k){\n\t\t\tval[k] = val[k*2] + val[k*2+1];\n\t\t\tk/=2;\n\t\t\
    }\n\t}\n\tD sum(int a,int b){\t\t//non-commutative & unrecursive\n\t\tD res =\
    \ 0;\n\t\ta+=N,b+=N;\n\t\twhile(a<b){\n\t\t\tif(a&1) res += val[a++];\n\t\t\t\
    if(b&1) res += val[--b];\n\t\t\ta/=2,b/=2;\n\t\t}\n\t\treturn res;\n\t}\n};\n\n\
    int main(){\n\tvector<long long> vc = {1,2,3,4};\n\tsegtree seg(vc);\n\tassert(seg.sum(2,4)\
    \ == 7);\n\tseg.assign(0,-100);\n\tassert(seg.sum(0,3) == -95);\n}"
  dependsOn: []
  isVerificationFile: false
  path: data structure/segtree/specialized/segtree_sum.cpp
  requiredBy: []
  timestamp: '2017-09-14 22:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/segtree/specialized/segtree_sum.cpp
layout: document
redirect_from:
- /library/data structure/segtree/specialized/segtree_sum.cpp
- /library/data structure/segtree/specialized/segtree_sum.cpp.html
title: data structure/segtree/specialized/segtree_sum.cpp
---
