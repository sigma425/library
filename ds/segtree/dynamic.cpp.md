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
  bundledCode: "#line 1 \"ds/segtree/dynamic.cpp\"\n/*\n\tRange+_PointAssign \u306E\
    \u52D5\u7684\u7248\n\t\u65B0\u898F\u306B\u30A2\u30AF\u30BB\u30B9\u3059\u308B\u3068\
    \u3084\u3063\u3068\u30CE\u30FC\u30C9\u3092\u4F5C\u308B \u7BC4\u56F2\u30A2\u30AF\
    \u30BB\u30B9\u3054\u3068\u306Blog N\u500B\u306E\u30CE\u30FC\u30C9\u3092\u4F5C\u308B\
    \u306E\u3067\u3001\u8A08QlogN\u500B. \u6642\u9593\u8A08\u7B97\u91CF\u306F\u30AF\
    \u30A8\u30EA\u3054\u3068logN.\n\n\t\u5143\u304B\u3089\u306A\u3093\u3089\u304B\u306E\
    \u5024\u304C\u5165\u3063\u3066\u3044\u308B\u304C\u30B5\u30DC\u308C\u308B\u5834\
    \u5408\n\tex. N=10^9\u3067,\u306F\u3058\u3081\u306Fa[i]=i,range sum\u3068point\
    \ assign\u304C\u304F\u308B\n\tnew Node\u3059\u308B\u3068\u304D\u306B\u3046\u307E\
    \u3044\u3053\u3068\u3084\u308C\u3070\u3044\u3044\u306E\u3067\u3001\n\tNode\u306E\
    \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF(int l,int r,NP p)\u3067\u3001val\u3092\
    \u66F8\u304D\u63DB\u3048\u308C\u3070\u826F\u3044(\u4E0A\u306E\u4F8B\u3060\u3068\
    \u3001val=l+...+r-1\u306B\u3059\u308B)\n\tl\u3068r\u3055\u3048\u3042\u308C\u3070\
    \u5FC5\u8981\u306A\u60C5\u5831\u306F\u3042\u308B\u306F\u305A\u306A\u306E\u3067\
    \u3053\u308C\u3067\u5341\u5206\n\n\tpoint assign,range +\n\tsemigroup D \u3067\
    \u306Esegtree\n\n\t\u5909\u3048\u308B\u3079\u304D\u3068\u3053\u308D\u306F,\n\t\
    - D\u306E\u30E1\u30F3\u30D0\u5909\u6570\n\t- D\u306E\u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n\t- operator+\n\t- struct\u306E\u5916\u306ED::e\u306Einitialize\n\
    \t- (\u3042\u3068\u304A\u597D\u307F\u3067operator<<)\n\n*/\n#include <bits/stdc++.h>\n\
    #define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define show(x) cout<< #x <<\" \"\
    <<x<<endl\nusing namespace std;\n\nstruct D{\n\tint x;\n\tD(){*this = e;}\n\t\
    D(int x):x(x){}\n\tconst static D e;\n\tD operator+(const D& r) const {\n\t\t\
    return D(x+r.x);\n\t}\n\tfriend ostream& operator<<(ostream& o,const D& d){return\
    \ o<<d.x;}\n};\nconst D D::e = D(0);\n\ntemplate<class T>\nstruct segtree{\n\t\
    struct Node;\n\tusing NP = Node*;\n\n\tstruct Node{\n\t\tT val;\n\t\tint l,r;\n\
    \t\tNP p,lch,rch;\n\t\tNode(int l,int r,NP p):val(),l(l),r(r),p(p),lch(nullptr),rch(nullptr){\n\
    //\t\t\tval=T((r-l)*(r+l-1)/2);\n\t\t}\n//\t\tNode(int l,int r,NP p,T val=T::e):val(val),l(l),r(r),p(p),lch(nullptr),rch(nullptr){}\n\
    \t};\n\n\tT e=T::e;\n\tNP root;\n\tsegtree(){}\n\tsegtree(int n){\n\t\tint N=1;\n\
    \t\twhile(n>N) N*=2;\n\t\troot = new Node(0,N,nullptr);\n\t\troot->lch = nullptr;\n\
    \t\troot->rch = nullptr;\n\t\troot->val = e;\n\t}\n\n\tvoid update(int x,T val,NP\
    \ n=nullptr){\n\t\tif(n==nullptr) n=root;\n\t\tint l=n->l,r=n->r;\n\t\tif(x<l||r<=x)\
    \ return;\n\t\tif(l==x&&r-l==1){\n\t\t\tn->val=val;\n\t\t\treturn;\n\t\t}\n\t\t\
    if(n->lch == nullptr) n->lch = new Node(l,(l+r)/2,n);\n\t\tif(n->rch == nullptr)\
    \ n->rch = new Node((l+r)/2,r,n);\n\t\tupdate(x,val,n->lch);\n\t\tupdate(x,val,n->rch);\n\
    \t\tn->val = n->lch->val + n->rch->val ;\n\t}\n\tT calc(int a,int b,NP n=nullptr){\n\
    \t\tif(n==nullptr) n=root;\n\t\tint l=n->l,r=n->r;\n\t\tif(b<=l||r<=a) return\
    \ e;\n\t\tif(a<=l&&r<=b) return n->val;\n\t\tif(n->lch == nullptr) n->lch = new\
    \ Node(l,(l+r)/2,n);\n\t\tif(n->rch == nullptr) n->rch = new Node((l+r)/2,r,n);\n\
    \t\treturn calc(a,b,n->lch)+calc(a,b,n->rch);\n\t}\n};\nsegtree<D> seg;\nint main(){\n\
    \tint N;\n\tcin>>N;\n\tseg=segtree<D>(N);\n\twhile(true){\n\t\tchar c;\n\t\tcin>>c;\n\
    \t\tif(c=='c'){\t//change\n\t\t\tint x,v;\n\t\t\tcin>>x>>v;\n\t\t\tseg.update(x,D(v));\n\
    \t\t}else{\n\t\t\tint l,r;\n\t\t\tcin>>l>>r;\n\t\t\tr++;\n\t\t\tcout<<\"ans=\"\
    <<seg.calc(l,r)<<endl;\n\t\t}\n\t}\n}\n"
  code: "/*\n\tRange+_PointAssign \u306E\u52D5\u7684\u7248\n\t\u65B0\u898F\u306B\u30A2\
    \u30AF\u30BB\u30B9\u3059\u308B\u3068\u3084\u3063\u3068\u30CE\u30FC\u30C9\u3092\
    \u4F5C\u308B \u7BC4\u56F2\u30A2\u30AF\u30BB\u30B9\u3054\u3068\u306Blog N\u500B\
    \u306E\u30CE\u30FC\u30C9\u3092\u4F5C\u308B\u306E\u3067\u3001\u8A08QlogN\u500B\
    . \u6642\u9593\u8A08\u7B97\u91CF\u306F\u30AF\u30A8\u30EA\u3054\u3068logN.\n\n\t\
    \u5143\u304B\u3089\u306A\u3093\u3089\u304B\u306E\u5024\u304C\u5165\u3063\u3066\
    \u3044\u308B\u304C\u30B5\u30DC\u308C\u308B\u5834\u5408\n\tex. N=10^9\u3067,\u306F\
    \u3058\u3081\u306Fa[i]=i,range sum\u3068point assign\u304C\u304F\u308B\n\tnew\
    \ Node\u3059\u308B\u3068\u304D\u306B\u3046\u307E\u3044\u3053\u3068\u3084\u308C\
    \u3070\u3044\u3044\u306E\u3067\u3001\n\tNode\u306E\u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF(int l,int r,NP p)\u3067\u3001val\u3092\u66F8\u304D\u63DB\u3048\u308C\
    \u3070\u826F\u3044(\u4E0A\u306E\u4F8B\u3060\u3068\u3001val=l+...+r-1\u306B\u3059\
    \u308B)\n\tl\u3068r\u3055\u3048\u3042\u308C\u3070\u5FC5\u8981\u306A\u60C5\u5831\
    \u306F\u3042\u308B\u306F\u305A\u306A\u306E\u3067\u3053\u308C\u3067\u5341\u5206\
    \n\n\tpoint assign,range +\n\tsemigroup D \u3067\u306Esegtree\n\n\t\u5909\u3048\
    \u308B\u3079\u304D\u3068\u3053\u308D\u306F,\n\t- D\u306E\u30E1\u30F3\u30D0\u5909\
    \u6570\n\t- D\u306E\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n\t- operator+\n\
    \t- struct\u306E\u5916\u306ED::e\u306Einitialize\n\t- (\u3042\u3068\u304A\u597D\
    \u307F\u3067operator<<)\n\n*/\n#include <bits/stdc++.h>\n#define rep(i,n) for(int\
    \ i=0;i<(int)(n);i++)\n#define show(x) cout<< #x <<\" \"<<x<<endl\nusing namespace\
    \ std;\n\nstruct D{\n\tint x;\n\tD(){*this = e;}\n\tD(int x):x(x){}\n\tconst static\
    \ D e;\n\tD operator+(const D& r) const {\n\t\treturn D(x+r.x);\n\t}\n\tfriend\
    \ ostream& operator<<(ostream& o,const D& d){return o<<d.x;}\n};\nconst D D::e\
    \ = D(0);\n\ntemplate<class T>\nstruct segtree{\n\tstruct Node;\n\tusing NP =\
    \ Node*;\n\n\tstruct Node{\n\t\tT val;\n\t\tint l,r;\n\t\tNP p,lch,rch;\n\t\t\
    Node(int l,int r,NP p):val(),l(l),r(r),p(p),lch(nullptr),rch(nullptr){\n//\t\t\
    \tval=T((r-l)*(r+l-1)/2);\n\t\t}\n//\t\tNode(int l,int r,NP p,T val=T::e):val(val),l(l),r(r),p(p),lch(nullptr),rch(nullptr){}\n\
    \t};\n\n\tT e=T::e;\n\tNP root;\n\tsegtree(){}\n\tsegtree(int n){\n\t\tint N=1;\n\
    \t\twhile(n>N) N*=2;\n\t\troot = new Node(0,N,nullptr);\n\t\troot->lch = nullptr;\n\
    \t\troot->rch = nullptr;\n\t\troot->val = e;\n\t}\n\n\tvoid update(int x,T val,NP\
    \ n=nullptr){\n\t\tif(n==nullptr) n=root;\n\t\tint l=n->l,r=n->r;\n\t\tif(x<l||r<=x)\
    \ return;\n\t\tif(l==x&&r-l==1){\n\t\t\tn->val=val;\n\t\t\treturn;\n\t\t}\n\t\t\
    if(n->lch == nullptr) n->lch = new Node(l,(l+r)/2,n);\n\t\tif(n->rch == nullptr)\
    \ n->rch = new Node((l+r)/2,r,n);\n\t\tupdate(x,val,n->lch);\n\t\tupdate(x,val,n->rch);\n\
    \t\tn->val = n->lch->val + n->rch->val ;\n\t}\n\tT calc(int a,int b,NP n=nullptr){\n\
    \t\tif(n==nullptr) n=root;\n\t\tint l=n->l,r=n->r;\n\t\tif(b<=l||r<=a) return\
    \ e;\n\t\tif(a<=l&&r<=b) return n->val;\n\t\tif(n->lch == nullptr) n->lch = new\
    \ Node(l,(l+r)/2,n);\n\t\tif(n->rch == nullptr) n->rch = new Node((l+r)/2,r,n);\n\
    \t\treturn calc(a,b,n->lch)+calc(a,b,n->rch);\n\t}\n};\nsegtree<D> seg;\nint main(){\n\
    \tint N;\n\tcin>>N;\n\tseg=segtree<D>(N);\n\twhile(true){\n\t\tchar c;\n\t\tcin>>c;\n\
    \t\tif(c=='c'){\t//change\n\t\t\tint x,v;\n\t\t\tcin>>x>>v;\n\t\t\tseg.update(x,D(v));\n\
    \t\t}else{\n\t\t\tint l,r;\n\t\t\tcin>>l>>r;\n\t\t\tr++;\n\t\t\tcout<<\"ans=\"\
    <<seg.calc(l,r)<<endl;\n\t\t}\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/dynamic.cpp
  requiredBy: []
  timestamp: '2024-01-03 19:12:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/dynamic.cpp
layout: document
redirect_from:
- /library/ds/segtree/dynamic.cpp
- /library/ds/segtree/dynamic.cpp.html
title: ds/segtree/dynamic.cpp
---
