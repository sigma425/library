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
  bundledCode: "#line 1 \"data structure/segtree/persistent segtree/pers_R-Pass_template.cpp\"\
    \n/*\n\tpoint assign,range \u307B\u3052(+)\n\tsemigroup D \u3067\u306Esegtree\n\
    \n\t\u5909\u3048\u308B\u3079\u304D\u3068\u3053\u308D\u306F,\n\t- D\u306E\u30E1\
    \u30F3\u30D0\u5909\u6570\n\t- D\u306E\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \n\t- operator+\n\t- struct\u306E\u5916\u306ED::e\u306Einitialize\n\t- (\u3042\
    \u3068\u304A\u597D\u307F\u3067operator<<)\n\n*/\n#include <bits/stdc++.h>\n#define\
    \ rep(i,n) for(int i=0;i<(int)(n);i++)\n#define show(x) cout<< #x <<\" \"<<x<<endl\n\
    using namespace std;\n\nstruct D{\n\tint x;\n\tD(){}\n\tD(int x):x(x){}\n\tconst\
    \ static D e;\n\tD operator+(const D& r) const {\n\t\treturn D(x+r.x);\n\t}\n\t\
    friend ostream& operator<<(ostream& o,const D& d){return o<<d.x;}\n};\nconst D\
    \ D::e = D(0);\n\ntemplate<class D>\nstruct segtree{\n\tint update(int ver,int\
    \ x,D v){\t\t\t\t//\u5909\u66F4\u30AF\u30A8\u30EA version ver \u306Ea[x]\u3092\
    v\u306B\u5909\u3048\u3066,\u65B0\u3057\u3044version\u306Eroot id\u3092\u8FD4\u3059\
    \n\t\troot[++R]=update(root[ver],x,0,N,v);\n\t\treturn R;\n\t}\n\tint update_(int\
    \ ver,int x,D v){\n\t\troot[R]=update(root[ver],x,0,N,v);\n\t\treturn R;\n\t}\n\
    \tD query(int ver,int a,int b){\t\t\t\t//\u56DE\u7B54\u30AF\u30A8\u30EA version\
    \ ver\u306E[a,b)\u3092\u6C42\u3081\u308B\n\t\treturn query(a,b,0,N,root[ver]);\n\
    \t}\n\tstatic const int N=11;\t\t\t//\u914D\u5217\u306E\u9577\u3055,2\u30D9\u30AD\
    \u3058\u3083\u306A\u304F\u3066\u3088\u3044\n\tstatic const int MX=1000000;\t\t\
    //node\u306E\u6570 \u5909\u66F4\u30AF\u30A8\u30EA\u306E\u6570* segtree\u306E\u6DF1\
    \u3055 \u304F\u3089\u3044\n\tstatic const int MR=1000000;\t\t//root\u306E\u6570\
    \ \u666E\u901A,\u5909\u66F4\u30AF\u30A8\u30EA\u306E\u6570+1\u3060\u3068\u601D\u3046\
    \n\tstruct Node;\n\ttypedef Node* NP;\n\tstruct Node{\n\t\tNP lch,rch;\n\t\tD\
    \ v;\n\t\tNode(NP l,NP r,D v):lch(l),rch(r),v(v){}\n\t\tNode(){}\n\t};\n\tNode\
    \ pool[MX];\n\tNP root[MR];\n\tNP nil;\n\tint I,R;\n\tNP news(NP lch,NP rch,D\
    \ v){\n\t\treturn &(pool[I++]=Node(lch,rch,v));\n\t}\n\tNP news(NP lch,NP rch){\n\
    \t\treturn &(pool[I++]=Node(lch,rch,lch->v+rch->v));\n\t}\n\tNP update(NP x,int\
    \ pos,int l,int r,D v){\t\t//a[pos]:=v. \u4ECAx\u4EE5\u4E0B\u3092\u51E6\u7406\u3057\
    \u3066\u3044\u308B \u65B0\u3057\u3044\u30D0\u30FC\u30B8\u30E7\u30F3\u306Ex\u306B\
    \u5BFE\u5FDC\u3059\u308B\u90E8\u5206\u3092\u8FD4\u3059\n/*\t\tNP tmp;\n\t\tif(r-l==1)\
    \ tmp=news(nil,nil,v);\t\t\t//add\u306A\u3089\u3053\u3053\u3092\u5909\u3048\u308B\
    \n\t\telse{\n\t\t\tint m=(l+r)/2;\n\t\t\tif(pos<m) tmp=news(update(x->lch,pos,l,m,v),x->rch);\n\
    \t\t\telse tmp=news(x->lch,update(x->rch,pos,m,r,v));\n\t\t}\n\n\t\tprintf(\"\
    pos,l,r=(%d,%d,%d)\\n\",pos,l,r);\n\t\tshow(v);\n\t\tshowtree(tmp);\n\t\tputs(\"\
    \");\n\t\treturn tmp;*/\n\t\tif(r-l==1) return news(nil,nil,v);\t\t\t//add\u306A\
    \u3089\u3053\u3053\u3092\u5909\u3048\u308B\n\t\tint m=(l+r)/2;\n\t\tif(pos<m)\
    \ return news(update(x->lch,pos,l,m,v),x->rch);\n\t\telse return news(x->lch,update(x->rch,pos,m,r,v));\n\
    \t}\n\tD query(int a,int b,int l,int r,NP x){\t\t\t//range query\n\t\tif(x==nil)\
    \ return D::e;\t\t\t\t\t//\u521D\u671F\u5024\u304C\u5909\u306A\u5834\u5408\u306F\
    \u3053\u3053\u3092\u5909\u3048\u308B!!\n\t\tif(b<=l||r<=a) return D::e;\n\t\t\
    if(a<=l&&r<=b) return x->v;\n\t\tint m=(l+r)/2;\n\t\treturn query(a,b,l,m,x->lch)+query(a,b,m,r,x->rch);\n\
    \t}\n\tvoid showtree(int r){\n\t\tshowtree(root[r]);\n\t}\n\tvoid showtree(NP\
    \ x){\n\t\tif(x==nil){\n\t\t\tcout<<\"nil\";\n\t\t\treturn;\n\t\t}\n\t\tprintf(\"\
    (\");\n\t\tshowtree(x->lch);\n\t\tcout<<\",\"<<x->v<<\",\";\t//D\u306B<<\u304C\
    \u5B9A\u7FA9\u3055\u308C\u3066\u308C\u3070OK\n\t\tshowtree(x->rch);\n\t\tprintf(\"\
    )\");\n\t}\n\tsegtree(){\n\t\tI=0,R=0;\n\t\tnil=news(0,0,D::e);\n\t\tnil->lch=nil,nil->rch=nil;\n\
    \t\troot[0]=nil;\n\t}\n};\nsegtree<D> seg;\nint main(){\n\tint Q;\n\tcin>>Q;\n\
    \tint r=0;\n\trep(i,Q){\n\t\tchar c;\n\t\tcin>>c;\n\t\tif(c=='c'){\n\t\t\tint\
    \ x,v,ver;\n\t\t\tcin>>x>>v>>ver;\n\t\t\tr=seg.update(ver,x,D(v));\n\t\t\tshow(r);\n\
    \t\t\tseg.showtree(r);\n\t\t\tputs(\"\");\n\t\t}else{\n\t\t\tint x,y;\n\t\t\t\
    cin>>x>>y;\n\t\t\tshow(seg.query(r,x,y));\n\t\t}\n\t}\n}\n"
  code: "/*\n\tpoint assign,range \u307B\u3052(+)\n\tsemigroup D \u3067\u306Esegtree\n\
    \n\t\u5909\u3048\u308B\u3079\u304D\u3068\u3053\u308D\u306F,\n\t- D\u306E\u30E1\
    \u30F3\u30D0\u5909\u6570\n\t- D\u306E\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \n\t- operator+\n\t- struct\u306E\u5916\u306ED::e\u306Einitialize\n\t- (\u3042\
    \u3068\u304A\u597D\u307F\u3067operator<<)\n\n*/\n#include <bits/stdc++.h>\n#define\
    \ rep(i,n) for(int i=0;i<(int)(n);i++)\n#define show(x) cout<< #x <<\" \"<<x<<endl\n\
    using namespace std;\n\nstruct D{\n\tint x;\n\tD(){}\n\tD(int x):x(x){}\n\tconst\
    \ static D e;\n\tD operator+(const D& r) const {\n\t\treturn D(x+r.x);\n\t}\n\t\
    friend ostream& operator<<(ostream& o,const D& d){return o<<d.x;}\n};\nconst D\
    \ D::e = D(0);\n\ntemplate<class D>\nstruct segtree{\n\tint update(int ver,int\
    \ x,D v){\t\t\t\t//\u5909\u66F4\u30AF\u30A8\u30EA version ver \u306Ea[x]\u3092\
    v\u306B\u5909\u3048\u3066,\u65B0\u3057\u3044version\u306Eroot id\u3092\u8FD4\u3059\
    \n\t\troot[++R]=update(root[ver],x,0,N,v);\n\t\treturn R;\n\t}\n\tint update_(int\
    \ ver,int x,D v){\n\t\troot[R]=update(root[ver],x,0,N,v);\n\t\treturn R;\n\t}\n\
    \tD query(int ver,int a,int b){\t\t\t\t//\u56DE\u7B54\u30AF\u30A8\u30EA version\
    \ ver\u306E[a,b)\u3092\u6C42\u3081\u308B\n\t\treturn query(a,b,0,N,root[ver]);\n\
    \t}\n\tstatic const int N=11;\t\t\t//\u914D\u5217\u306E\u9577\u3055,2\u30D9\u30AD\
    \u3058\u3083\u306A\u304F\u3066\u3088\u3044\n\tstatic const int MX=1000000;\t\t\
    //node\u306E\u6570 \u5909\u66F4\u30AF\u30A8\u30EA\u306E\u6570* segtree\u306E\u6DF1\
    \u3055 \u304F\u3089\u3044\n\tstatic const int MR=1000000;\t\t//root\u306E\u6570\
    \ \u666E\u901A,\u5909\u66F4\u30AF\u30A8\u30EA\u306E\u6570+1\u3060\u3068\u601D\u3046\
    \n\tstruct Node;\n\ttypedef Node* NP;\n\tstruct Node{\n\t\tNP lch,rch;\n\t\tD\
    \ v;\n\t\tNode(NP l,NP r,D v):lch(l),rch(r),v(v){}\n\t\tNode(){}\n\t};\n\tNode\
    \ pool[MX];\n\tNP root[MR];\n\tNP nil;\n\tint I,R;\n\tNP news(NP lch,NP rch,D\
    \ v){\n\t\treturn &(pool[I++]=Node(lch,rch,v));\n\t}\n\tNP news(NP lch,NP rch){\n\
    \t\treturn &(pool[I++]=Node(lch,rch,lch->v+rch->v));\n\t}\n\tNP update(NP x,int\
    \ pos,int l,int r,D v){\t\t//a[pos]:=v. \u4ECAx\u4EE5\u4E0B\u3092\u51E6\u7406\u3057\
    \u3066\u3044\u308B \u65B0\u3057\u3044\u30D0\u30FC\u30B8\u30E7\u30F3\u306Ex\u306B\
    \u5BFE\u5FDC\u3059\u308B\u90E8\u5206\u3092\u8FD4\u3059\n/*\t\tNP tmp;\n\t\tif(r-l==1)\
    \ tmp=news(nil,nil,v);\t\t\t//add\u306A\u3089\u3053\u3053\u3092\u5909\u3048\u308B\
    \n\t\telse{\n\t\t\tint m=(l+r)/2;\n\t\t\tif(pos<m) tmp=news(update(x->lch,pos,l,m,v),x->rch);\n\
    \t\t\telse tmp=news(x->lch,update(x->rch,pos,m,r,v));\n\t\t}\n\n\t\tprintf(\"\
    pos,l,r=(%d,%d,%d)\\n\",pos,l,r);\n\t\tshow(v);\n\t\tshowtree(tmp);\n\t\tputs(\"\
    \");\n\t\treturn tmp;*/\n\t\tif(r-l==1) return news(nil,nil,v);\t\t\t//add\u306A\
    \u3089\u3053\u3053\u3092\u5909\u3048\u308B\n\t\tint m=(l+r)/2;\n\t\tif(pos<m)\
    \ return news(update(x->lch,pos,l,m,v),x->rch);\n\t\telse return news(x->lch,update(x->rch,pos,m,r,v));\n\
    \t}\n\tD query(int a,int b,int l,int r,NP x){\t\t\t//range query\n\t\tif(x==nil)\
    \ return D::e;\t\t\t\t\t//\u521D\u671F\u5024\u304C\u5909\u306A\u5834\u5408\u306F\
    \u3053\u3053\u3092\u5909\u3048\u308B!!\n\t\tif(b<=l||r<=a) return D::e;\n\t\t\
    if(a<=l&&r<=b) return x->v;\n\t\tint m=(l+r)/2;\n\t\treturn query(a,b,l,m,x->lch)+query(a,b,m,r,x->rch);\n\
    \t}\n\tvoid showtree(int r){\n\t\tshowtree(root[r]);\n\t}\n\tvoid showtree(NP\
    \ x){\n\t\tif(x==nil){\n\t\t\tcout<<\"nil\";\n\t\t\treturn;\n\t\t}\n\t\tprintf(\"\
    (\");\n\t\tshowtree(x->lch);\n\t\tcout<<\",\"<<x->v<<\",\";\t//D\u306B<<\u304C\
    \u5B9A\u7FA9\u3055\u308C\u3066\u308C\u3070OK\n\t\tshowtree(x->rch);\n\t\tprintf(\"\
    )\");\n\t}\n\tsegtree(){\n\t\tI=0,R=0;\n\t\tnil=news(0,0,D::e);\n\t\tnil->lch=nil,nil->rch=nil;\n\
    \t\troot[0]=nil;\n\t}\n};\nsegtree<D> seg;\nint main(){\n\tint Q;\n\tcin>>Q;\n\
    \tint r=0;\n\trep(i,Q){\n\t\tchar c;\n\t\tcin>>c;\n\t\tif(c=='c'){\n\t\t\tint\
    \ x,v,ver;\n\t\t\tcin>>x>>v>>ver;\n\t\t\tr=seg.update(ver,x,D(v));\n\t\t\tshow(r);\n\
    \t\t\tseg.showtree(r);\n\t\t\tputs(\"\");\n\t\t}else{\n\t\t\tint x,y;\n\t\t\t\
    cin>>x>>y;\n\t\t\tshow(seg.query(r,x,y));\n\t\t}\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: data structure/segtree/persistent segtree/pers_R-Pass_template.cpp
  requiredBy: []
  timestamp: '2017-02-02 01:38:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/segtree/persistent segtree/pers_R-Pass_template.cpp
layout: document
redirect_from:
- /library/data structure/segtree/persistent segtree/pers_R-Pass_template.cpp
- /library/data structure/segtree/persistent segtree/pers_R-Pass_template.cpp.html
title: data structure/segtree/persistent segtree/pers_R-Pass_template.cpp
---
