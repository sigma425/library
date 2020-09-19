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
  bundledCode: "#line 1 \"data structure/segtree/old/Range+_PointAssign.cpp\"\n/*\n\
    \tpoint assign,range +\n\tsemigroup D \u3067\u306Esegtree\n\n\t\u5909\u3048\u308B\
    \u3079\u304D\u3068\u3053\u308D\u306F,\n\t- D\u306E\u30E1\u30F3\u30D0\u5909\u6570\
    \n\t- D\u306E\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n\t- operator+\n\t- struct\u306E\
    \u5916\u306ED::e\u306Einitialize\n\t- (\u3042\u3068\u304A\u597D\u307F\u3067operator<<)\n\
    \n\t\u5916\u304B\u3089\u4F7F\u3046\u306E\u306F\n\t- update(0-indexed)\n\t- calc(0-indexed\
    \ \u534A\u958B\u533A\u9593)\n\t- \u3042\u3068init\n\n\t20161209\n*/\n\n#include\
    \ <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define show(x)\
    \ cout<< #x <<\" \"<<x<<endl\nusing namespace std;\n\nstruct D{\n\tint x;\n\t\
    D(){*this = e;}\n\tD(int x):x(x){}\n\tconst static D e;\n\tD operator+(const D&\
    \ r) const {\n\t\treturn D(x+r.x);\n\t}\n\tfriend ostream& operator<<(ostream&\
    \ o,const D& d){return o<<d.x;}\n};\nconst D D::e = D(0);\n\ntemplate<class T>\n\
    struct segtree{\n\tint N;\n\n\tT e=T::e;\n\tvector<T> seg;\n\tsegtree(){}\n\t\
    segtree(int n){\n\t\tinit(n);\n\t}\n\tsegtree(vector<T>& vc){\n\t\tinit(vc);\n\
    \t}\n\tvoid init(int n){\n\t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\tseg.assign(N*2,e);\n\
    \t}\n\tvoid init(vector<T>& vc){\n\t\tN=1;\n\t\tint n=vc.size();\n\t\twhile(N<n)\
    \ N*=2;\n\t\tseg.assign(N*2,e);\n\t\trep(i,vc.size()) seg[i+N]=vc[i];\n\t\tfor(int\
    \ i=N-1;i>0;i--) seg[i]=seg[i*2]+seg[i*2+1];\n\t}\n\tvoid update(int x,T val){\n\
    \t\tx+=N;\n\t\tseg[x]=val;\n\t\tx/=2;\n\t\twhile(x){\n\t\t\tseg[x]=seg[x*2]+seg[x*2+1];\n\
    \t\t\tx/=2;\n\t\t}\n\t}\n\tT calc(int a,int b,int l=0,int r=-1,int k=1){\n\t\t\
    if(r==-1) r=N;\n\t\tif(b<=l||r<=a) return e;\n\t\tif(a<=l&&r<=b) return seg[k];\n\
    \t\treturn calc(a,b,l,(l+r)/2,k*2)+calc(a,b,(l+r)/2,r,k*2+1);\n\t}\n};\nsegtree<D>\
    \ seg;\nint main(){\n\tint N;\n\tcin>>N;\n\tvector<D> vc;\n\trep(i,N){\n\t\tint\
    \ x;\n\t\tcin>>x;\n\t\tvc.push_back(D(x));\n\t}\n\tseg=segtree<D>(vc);\n\twhile(true){\n\
    \t\tint l,r;\n\t\tcin>>l>>r;\n\t\tr++;\n\t\tcout<<\"ans=\"<<seg.calc(l,r)<<endl;\n\
    \t}\n}\n"
  code: "/*\n\tpoint assign,range +\n\tsemigroup D \u3067\u306Esegtree\n\n\t\u5909\
    \u3048\u308B\u3079\u304D\u3068\u3053\u308D\u306F,\n\t- D\u306E\u30E1\u30F3\u30D0\
    \u5909\u6570\n\t- D\u306E\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n\t- operator+\n\
    \t- struct\u306E\u5916\u306ED::e\u306Einitialize\n\t- (\u3042\u3068\u304A\u597D\
    \u307F\u3067operator<<)\n\n\t\u5916\u304B\u3089\u4F7F\u3046\u306E\u306F\n\t- update(0-indexed)\n\
    \t- calc(0-indexed \u534A\u958B\u533A\u9593)\n\t- \u3042\u3068init\n\n\t20161209\n\
    */\n\n#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define show(x) cout<< #x <<\" \"<<x<<endl\nusing namespace std;\n\nstruct D{\n\
    \tint x;\n\tD(){*this = e;}\n\tD(int x):x(x){}\n\tconst static D e;\n\tD operator+(const\
    \ D& r) const {\n\t\treturn D(x+r.x);\n\t}\n\tfriend ostream& operator<<(ostream&\
    \ o,const D& d){return o<<d.x;}\n};\nconst D D::e = D(0);\n\ntemplate<class T>\n\
    struct segtree{\n\tint N;\n\n\tT e=T::e;\n\tvector<T> seg;\n\tsegtree(){}\n\t\
    segtree(int n){\n\t\tinit(n);\n\t}\n\tsegtree(vector<T>& vc){\n\t\tinit(vc);\n\
    \t}\n\tvoid init(int n){\n\t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\tseg.assign(N*2,e);\n\
    \t}\n\tvoid init(vector<T>& vc){\n\t\tN=1;\n\t\tint n=vc.size();\n\t\twhile(N<n)\
    \ N*=2;\n\t\tseg.assign(N*2,e);\n\t\trep(i,vc.size()) seg[i+N]=vc[i];\n\t\tfor(int\
    \ i=N-1;i>0;i--) seg[i]=seg[i*2]+seg[i*2+1];\n\t}\n\tvoid update(int x,T val){\n\
    \t\tx+=N;\n\t\tseg[x]=val;\n\t\tx/=2;\n\t\twhile(x){\n\t\t\tseg[x]=seg[x*2]+seg[x*2+1];\n\
    \t\t\tx/=2;\n\t\t}\n\t}\n\tT calc(int a,int b,int l=0,int r=-1,int k=1){\n\t\t\
    if(r==-1) r=N;\n\t\tif(b<=l||r<=a) return e;\n\t\tif(a<=l&&r<=b) return seg[k];\n\
    \t\treturn calc(a,b,l,(l+r)/2,k*2)+calc(a,b,(l+r)/2,r,k*2+1);\n\t}\n};\nsegtree<D>\
    \ seg;\nint main(){\n\tint N;\n\tcin>>N;\n\tvector<D> vc;\n\trep(i,N){\n\t\tint\
    \ x;\n\t\tcin>>x;\n\t\tvc.push_back(D(x));\n\t}\n\tseg=segtree<D>(vc);\n\twhile(true){\n\
    \t\tint l,r;\n\t\tcin>>l>>r;\n\t\tr++;\n\t\tcout<<\"ans=\"<<seg.calc(l,r)<<endl;\n\
    \t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: data structure/segtree/old/Range+_PointAssign.cpp
  requiredBy: []
  timestamp: '2017-04-22 20:47:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/segtree/old/Range+_PointAssign.cpp
layout: document
redirect_from:
- /library/data structure/segtree/old/Range+_PointAssign.cpp
- /library/data structure/segtree/old/Range+_PointAssign.cpp.html
title: data structure/segtree/old/Range+_PointAssign.cpp
---
