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
  bundledCode: "#line 1 \"ds/segtree/specialized/segtree_simple.cpp\"\n/*\n\tpoint\
    \ assign,range + \u975E\u518D\u5E30\n*/\n#include <bits/stdc++.h>\n#define rep(i,n)\
    \ for(int i=0;i<n;i++)\n#define fs first\n#define sc second\n#define chmax(x,y)\
    \ x=max(x,y)\nusing namespace std;\n\ntemplate<class D>\nstruct segtree_simple{\n\
    \tint N;\n\tvector<D> val;\n\n\tsegtree_simple(){}\n\tsegtree_simple(int n){\n\
    \t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\tval.assign(N*2,D::e());\n\t}\n\tsegtree_simple(const\
    \ vector<D>& ds){\n\t\tint n = ds.size();\n\t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\t\
    val.assign(N*2,D::e());\n\t\trep(i,n) val[i+N] = ds[i];\n\t\tfor(int i=N-1;i>0;i--)\
    \ val[i] = val[i*2] + val[i*2+1];\n\t}\n\tvoid assign(int k,D d){\n\t\tk+=N;\n\
    \t\tval[k]=d;\n\t\tk/=2;\n\t\twhile(k){\n\t\t\tval[k] = val[k*2] + val[k*2+1];\n\
    \t\t\tk/=2;\n\t\t}\n\t}\n\tD query(int a,int b){\t\t//non-commutative & unrecursive\n\
    \t\tD L = D::e() , R = D::e();\n\t\ta+=N,b+=N;\n\t\twhile(a<b){\n\t\t\tif(a&1)\
    \ L = L + val[a++];\n\t\t\tif(b&1) R = val[--b] + R;\n\t\t\ta/=2,b/=2;\n\t\t}\n\
    \t\treturn L+R;\n\t}\n\t// D query(int a,int b){\n\t// \treturn query(a,b,0,N,1);\n\
    \t// }\n\t// D query(int a,int b,int l,int r,int k){\n\t// \tif(b<=l||r<=a) return\
    \ D::e;\n\t// \tif(a<=l&&r<=b) return val[k];\n\t// \treturn query(a,b,l,(l+r)/2,k*2)\
    \ + query(a,b,(l+r)/2,r,k*2+1);\n\t// }\n};\n\nstruct Dplus{\t\t//(int,+,0)\n\t\
    int x;\n\tDplus(){}\n\tDplus(int x):x(x){}\n\tstatic Dplus e(){\n\t\treturn Dplus(0);\n\
    \t}\n\tDplus operator+(const Dplus& r) const {\n\t\treturn Dplus(x+r.x);\n\t}\n\
    \tfriend ostream& operator<<(ostream& o,const Dplus& d){return o<<d.x;}\n};\n\n\
    struct Dmax{\t\t//(int,max,-inf)\n\tint x;\n\tDmax(){}\n\tDmax(int x):x(x){}\n\
    \tstatic Dmax e(){\n\t\treturn Dmax(-1e9);\n\t}\n\tDmax operator+(const Dmax&\
    \ r) const {\n\t\treturn Dmax(max(x,r.x));\n\t}\n\tfriend ostream& operator<<(ostream&\
    \ o,const Dmax& d){return o<<d.x;}\n};\n\nstruct Dmin{\t\t//(int,min,inf)\n\t\
    int x;\n\tDmin(){}\n\tDmin(int x):x(x){}\n\tstatic Dmin e(){\n\t\treturn Dmin(1e9);\n\
    \t}\n\tDmin operator+(const Dmin& r) const {\n\t\treturn Dmin(min(x,r.x));\n\t\
    }\n\tfriend ostream& operator<<(ostream& o,const Dmin& d){return o<<d.x;}\n};\n\
    \nstruct Dleftmostmax{\t\t//(int,max,-inf)\n\tusing D = Dleftmostmax;\n\tint x,a;\t\
    //val,argid\n\tDleftmostmax(){}\n\tDleftmostmax(int x,int a):x(x),a(a){}\n\tstatic\
    \ D e(){\n\t\treturn D(-1e9,-1);\n\t}\n\tD operator+(const D& r) const {\n\t\t\
    if(x>r.x || (x==r.x&&a<r.a)) return *this;\n\t\telse return r;\n\t}\n\tfriend\
    \ ostream& operator<<(ostream& o,const D& d){return o<<\"(\"<<d.x<<\",\"<<d.a<<\"\
    )\";}\n};\n\nstruct Dperm{\n\tusing D = Dperm;\n\tconst static int N = 5;\n\t\
    using V = array<int,N>;\n\tV v;\n\tDperm(){}\n\tDperm(V v):v(v){}\n\tconst static\
    \ D e(){\n\t\treturn D({0,1,2,3,4});\n\t}\n\tD operator+(const D& r) const {\n\
    \t\tV ret;\n\t\trep(i,N) ret[i] = v[r.v[i]];\n\t\treturn D(ret);\n\t};\n};\n\n\
    struct Dmat{\n\tusing T = int;\n\tusing D = Dmat;\n\tconst static int N = 5;\n\
    \tusing V = array<T,N>;\n\tusing VV = array<V,N>;\n\tVV a;\n\tDmat(){}\n\tDmat(VV\
    \ a):a(a){}\n\tconst static D e(){\n\t\tVV a;\n\t\trep(i,N) rep(j,N) a[i][j] =\
    \ (i==j?1:0);\n\t\treturn D(a);\n\t}\n\tD operator+(const D& r) const {\n\t\t\
    VV c;\n\t\trep(i,N) rep(j,N) c[i][j]=0;\n\t\trep(i,N) rep(j,N) rep(k,N) c[i][j]\
    \ += a[i][k] * r.a[k][j];\n\t\treturn D(c);\n\t};\n\tbool operator==(const D&\
    \ r) const {\n\t\treturn a==r.a;\n\t}\n};\n\nvoid unittest(){\t//\u3069\u3063\u3061\
    \u304B\u3068\u3044\u3046\u3068struct D\u306E\u30C6\u30B9\u30C8\n\t{\n\t\tvector<Dplus>\
    \ vs = {4,2,5,4,8,3,1,4,1,5};\n\t\tsegtree_simple<Dplus> seg(vs);\n\t\trep(l,10)\
    \ for(int r=l;r<=10;r++){\n\t\t\tint sum = 0;\n\t\t\tfor(int i=l;i<r;i++) sum+=vs[i].x;\n\
    \t\t\tassert( seg.query(l,r).x == sum );\n\t\t}\n\t}\n\t{\n\t\tvector<Dmax> vs\
    \ = {-4,2,-5,-4,8,-3,1,-4,1,5};\n\t\tsegtree_simple<Dmax> seg1(vs);\n\t\trep(l,10)\
    \ for(int r=l;r<=10;r++){\n\t\t\tint mx = Dmax::e().x;\n\t\t\tfor(int i=l;i<r;i++)\
    \ chmax(mx,vs[i].x);\n\t\t\tassert( seg1.query(l,r).x == mx );\n\t\t}\n\t}\n\t\
    {\n\t\tusing D = Dleftmostmax;\n\t\tvector<int> vi = {1,1,2,1,3,2,1,3,2,1};\n\t\
    \tvector<D> vs;\n\t\trep(i,10) vs.push_back(D(vi[i],i));\n\t\tsegtree_simple<D>\
    \ seg(vs);\n\t\trep(l,10) for(int r=l+1;r<=10;r++){\n\t\t\tint mx = D::e().x;\n\
    \t\t\tint ag = -1;\n\t\t\tfor(int i=l;i<r;i++){\n\t\t\t\tif(mx<vi[i]){\n\t\t\t\
    \t\tmx=vi[i];\n\t\t\t\t\tag=i;\n\t\t\t\t}\n\t\t\t}\n\t\t\tassert( seg.query(l,r).a\
    \ == ag );\n\t\t}\n\t}\n\t{\n\t\tusing D = Dperm;\n\t\tvector<D> vs = {D({0,3,2,4,1}),D({0,3,2,1,4}),D({3,2,0,4,1}),D({0,3,4,2,1}),D({0,3,2,4,1}),D({0,3,1,4,2}),D({4,2,3,0,1}),D({3,2,4,1,0})};\n\
    \t\tsegtree_simple<D> seg(vs);\n\t\tint N = vs.size();\n\t\trep(l,N) for(int r=l;r<=N;r++){\n\
    \t\t\tint a[5]={0,1,2,3,4};\n\t\t\tfor(int i=l;i<r;i++){\n\t\t\t\tint na[5];\n\
    \t\t\t\trep(j,5) na[j] = a[vs[i].v[j]];\n\t\t\t\trep(j,5) a[j]=na[j];\n\t\t\t\
    }\n\t\t\tD calc = seg.query(l,r);\n\t\t\trep(i,5) assert( calc.v[i] == a[i] );\n\
    \t\t}\n\t}\n\t{\n\t\tusing D = Dmat;\n\t\tconst int K = Dmat::N;\n\t\tusing T\
    \ = int;\n\t\tusing V = array<T,K>;\n\t\tusing VV = array<V,K>;\n\n\t\tvector<D>\
    \ vs;\n\t\tint N = 10;\n\t\trep(i,N){\n\t\t\tVV a;\n\t\t\trep(x,K) rep(y,K) a[x][y]\
    \ = rand()%201+100;\n\t\t\tvs.push_back(D(a));\n\t\t}\n\t\tsegtree_simple<D> seg(vs);\n\
    \t\trep(l,N) for(int r=l;r<=N;r++){\n\t\t\tD x = D::e();\n\t\t\tfor(int i=l;i<r;i++)\
    \ x = x+vs[i];\n\t\t\tassert( seg.query(l,r) == x );\n\t\t}\n\t}\n}\nint main(){\n\
    \tunittest();\n}\n"
  code: "/*\n\tpoint assign,range + \u975E\u518D\u5E30\n*/\n#include <bits/stdc++.h>\n\
    #define rep(i,n) for(int i=0;i<n;i++)\n#define fs first\n#define sc second\n#define\
    \ chmax(x,y) x=max(x,y)\nusing namespace std;\n\ntemplate<class D>\nstruct segtree_simple{\n\
    \tint N;\n\tvector<D> val;\n\n\tsegtree_simple(){}\n\tsegtree_simple(int n){\n\
    \t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\tval.assign(N*2,D::e());\n\t}\n\tsegtree_simple(const\
    \ vector<D>& ds){\n\t\tint n = ds.size();\n\t\tN=1;\n\t\twhile(N<n) N*=2;\n\t\t\
    val.assign(N*2,D::e());\n\t\trep(i,n) val[i+N] = ds[i];\n\t\tfor(int i=N-1;i>0;i--)\
    \ val[i] = val[i*2] + val[i*2+1];\n\t}\n\tvoid assign(int k,D d){\n\t\tk+=N;\n\
    \t\tval[k]=d;\n\t\tk/=2;\n\t\twhile(k){\n\t\t\tval[k] = val[k*2] + val[k*2+1];\n\
    \t\t\tk/=2;\n\t\t}\n\t}\n\tD query(int a,int b){\t\t//non-commutative & unrecursive\n\
    \t\tD L = D::e() , R = D::e();\n\t\ta+=N,b+=N;\n\t\twhile(a<b){\n\t\t\tif(a&1)\
    \ L = L + val[a++];\n\t\t\tif(b&1) R = val[--b] + R;\n\t\t\ta/=2,b/=2;\n\t\t}\n\
    \t\treturn L+R;\n\t}\n\t// D query(int a,int b){\n\t// \treturn query(a,b,0,N,1);\n\
    \t// }\n\t// D query(int a,int b,int l,int r,int k){\n\t// \tif(b<=l||r<=a) return\
    \ D::e;\n\t// \tif(a<=l&&r<=b) return val[k];\n\t// \treturn query(a,b,l,(l+r)/2,k*2)\
    \ + query(a,b,(l+r)/2,r,k*2+1);\n\t// }\n};\n\nstruct Dplus{\t\t//(int,+,0)\n\t\
    int x;\n\tDplus(){}\n\tDplus(int x):x(x){}\n\tstatic Dplus e(){\n\t\treturn Dplus(0);\n\
    \t}\n\tDplus operator+(const Dplus& r) const {\n\t\treturn Dplus(x+r.x);\n\t}\n\
    \tfriend ostream& operator<<(ostream& o,const Dplus& d){return o<<d.x;}\n};\n\n\
    struct Dmax{\t\t//(int,max,-inf)\n\tint x;\n\tDmax(){}\n\tDmax(int x):x(x){}\n\
    \tstatic Dmax e(){\n\t\treturn Dmax(-1e9);\n\t}\n\tDmax operator+(const Dmax&\
    \ r) const {\n\t\treturn Dmax(max(x,r.x));\n\t}\n\tfriend ostream& operator<<(ostream&\
    \ o,const Dmax& d){return o<<d.x;}\n};\n\nstruct Dmin{\t\t//(int,min,inf)\n\t\
    int x;\n\tDmin(){}\n\tDmin(int x):x(x){}\n\tstatic Dmin e(){\n\t\treturn Dmin(1e9);\n\
    \t}\n\tDmin operator+(const Dmin& r) const {\n\t\treturn Dmin(min(x,r.x));\n\t\
    }\n\tfriend ostream& operator<<(ostream& o,const Dmin& d){return o<<d.x;}\n};\n\
    \nstruct Dleftmostmax{\t\t//(int,max,-inf)\n\tusing D = Dleftmostmax;\n\tint x,a;\t\
    //val,argid\n\tDleftmostmax(){}\n\tDleftmostmax(int x,int a):x(x),a(a){}\n\tstatic\
    \ D e(){\n\t\treturn D(-1e9,-1);\n\t}\n\tD operator+(const D& r) const {\n\t\t\
    if(x>r.x || (x==r.x&&a<r.a)) return *this;\n\t\telse return r;\n\t}\n\tfriend\
    \ ostream& operator<<(ostream& o,const D& d){return o<<\"(\"<<d.x<<\",\"<<d.a<<\"\
    )\";}\n};\n\nstruct Dperm{\n\tusing D = Dperm;\n\tconst static int N = 5;\n\t\
    using V = array<int,N>;\n\tV v;\n\tDperm(){}\n\tDperm(V v):v(v){}\n\tconst static\
    \ D e(){\n\t\treturn D({0,1,2,3,4});\n\t}\n\tD operator+(const D& r) const {\n\
    \t\tV ret;\n\t\trep(i,N) ret[i] = v[r.v[i]];\n\t\treturn D(ret);\n\t};\n};\n\n\
    struct Dmat{\n\tusing T = int;\n\tusing D = Dmat;\n\tconst static int N = 5;\n\
    \tusing V = array<T,N>;\n\tusing VV = array<V,N>;\n\tVV a;\n\tDmat(){}\n\tDmat(VV\
    \ a):a(a){}\n\tconst static D e(){\n\t\tVV a;\n\t\trep(i,N) rep(j,N) a[i][j] =\
    \ (i==j?1:0);\n\t\treturn D(a);\n\t}\n\tD operator+(const D& r) const {\n\t\t\
    VV c;\n\t\trep(i,N) rep(j,N) c[i][j]=0;\n\t\trep(i,N) rep(j,N) rep(k,N) c[i][j]\
    \ += a[i][k] * r.a[k][j];\n\t\treturn D(c);\n\t};\n\tbool operator==(const D&\
    \ r) const {\n\t\treturn a==r.a;\n\t}\n};\n\nvoid unittest(){\t//\u3069\u3063\u3061\
    \u304B\u3068\u3044\u3046\u3068struct D\u306E\u30C6\u30B9\u30C8\n\t{\n\t\tvector<Dplus>\
    \ vs = {4,2,5,4,8,3,1,4,1,5};\n\t\tsegtree_simple<Dplus> seg(vs);\n\t\trep(l,10)\
    \ for(int r=l;r<=10;r++){\n\t\t\tint sum = 0;\n\t\t\tfor(int i=l;i<r;i++) sum+=vs[i].x;\n\
    \t\t\tassert( seg.query(l,r).x == sum );\n\t\t}\n\t}\n\t{\n\t\tvector<Dmax> vs\
    \ = {-4,2,-5,-4,8,-3,1,-4,1,5};\n\t\tsegtree_simple<Dmax> seg1(vs);\n\t\trep(l,10)\
    \ for(int r=l;r<=10;r++){\n\t\t\tint mx = Dmax::e().x;\n\t\t\tfor(int i=l;i<r;i++)\
    \ chmax(mx,vs[i].x);\n\t\t\tassert( seg1.query(l,r).x == mx );\n\t\t}\n\t}\n\t\
    {\n\t\tusing D = Dleftmostmax;\n\t\tvector<int> vi = {1,1,2,1,3,2,1,3,2,1};\n\t\
    \tvector<D> vs;\n\t\trep(i,10) vs.push_back(D(vi[i],i));\n\t\tsegtree_simple<D>\
    \ seg(vs);\n\t\trep(l,10) for(int r=l+1;r<=10;r++){\n\t\t\tint mx = D::e().x;\n\
    \t\t\tint ag = -1;\n\t\t\tfor(int i=l;i<r;i++){\n\t\t\t\tif(mx<vi[i]){\n\t\t\t\
    \t\tmx=vi[i];\n\t\t\t\t\tag=i;\n\t\t\t\t}\n\t\t\t}\n\t\t\tassert( seg.query(l,r).a\
    \ == ag );\n\t\t}\n\t}\n\t{\n\t\tusing D = Dperm;\n\t\tvector<D> vs = {D({0,3,2,4,1}),D({0,3,2,1,4}),D({3,2,0,4,1}),D({0,3,4,2,1}),D({0,3,2,4,1}),D({0,3,1,4,2}),D({4,2,3,0,1}),D({3,2,4,1,0})};\n\
    \t\tsegtree_simple<D> seg(vs);\n\t\tint N = vs.size();\n\t\trep(l,N) for(int r=l;r<=N;r++){\n\
    \t\t\tint a[5]={0,1,2,3,4};\n\t\t\tfor(int i=l;i<r;i++){\n\t\t\t\tint na[5];\n\
    \t\t\t\trep(j,5) na[j] = a[vs[i].v[j]];\n\t\t\t\trep(j,5) a[j]=na[j];\n\t\t\t\
    }\n\t\t\tD calc = seg.query(l,r);\n\t\t\trep(i,5) assert( calc.v[i] == a[i] );\n\
    \t\t}\n\t}\n\t{\n\t\tusing D = Dmat;\n\t\tconst int K = Dmat::N;\n\t\tusing T\
    \ = int;\n\t\tusing V = array<T,K>;\n\t\tusing VV = array<V,K>;\n\n\t\tvector<D>\
    \ vs;\n\t\tint N = 10;\n\t\trep(i,N){\n\t\t\tVV a;\n\t\t\trep(x,K) rep(y,K) a[x][y]\
    \ = rand()%201+100;\n\t\t\tvs.push_back(D(a));\n\t\t}\n\t\tsegtree_simple<D> seg(vs);\n\
    \t\trep(l,N) for(int r=l;r<=N;r++){\n\t\t\tD x = D::e();\n\t\t\tfor(int i=l;i<r;i++)\
    \ x = x+vs[i];\n\t\t\tassert( seg.query(l,r) == x );\n\t\t}\n\t}\n}\nint main(){\n\
    \tunittest();\n}"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/specialized/segtree_simple.cpp
  requiredBy: []
  timestamp: '2024-01-03 19:12:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/specialized/segtree_simple.cpp
layout: document
redirect_from:
- /library/ds/segtree/specialized/segtree_simple.cpp
- /library/ds/segtree/specialized/segtree_simple.cpp.html
title: ds/segtree/specialized/segtree_simple.cpp
---
