---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data structure/segtree/segtree_simple.cpp\"\n/*\r\n\tpoint\
    \ assign,range + \u975E\u518D\u5E30\r\n\r\n\tstruct D \u306E\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\u306F\u5F15\u6570\u7121\u3057\u3067\u5358\u4F4D\u5143\
    \u3092\u8FD4\u3059\u3088\u3046\u306B\u3057\u3066\u304A\u304F\u3053\u3068\r\n*/\r\
    \n#include <bits/stdc++.h>\r\n#define rep(i,n) for(int i=0;i<n;i++)\r\n#define\
    \ fs first\r\n#define sc second\r\n#define chmax(x,y) x=max(x,y)\r\nusing namespace\
    \ std;\r\n\r\ntemplate<class D>\r\nstruct segtree{\r\n\tint N;\r\n\tvector<D>\
    \ val;\r\n\r\n\tsegtree(){}\r\n\tsegtree(int n){\r\n\t\tN=1;\r\n\t\twhile(N<n)\
    \ N*=2;\r\n\t\tval.assign(N*2,D::e());\r\n\t}\r\n\tsegtree(const vector<D>& ds){\r\
    \n\t\tint n = ds.size();\r\n\t\tN=1;\r\n\t\twhile(N<n) N*=2;\r\n\t\tval.assign(N*2,D::e());\r\
    \n\t\trep(i,n) val[i+N] = ds[i];\r\n\t\tfor(int i=N-1;i>0;i--) val[i] = val[i*2]\
    \ + val[i*2+1];\r\n\t}\r\n\tvoid assign(int k,D d){\r\n\t\tk+=N;\r\n\t\tval[k]=d;\r\
    \n\t\tk/=2;\r\n\t\twhile(k){\r\n\t\t\tval[k] = val[k*2] + val[k*2+1];\r\n\t\t\t\
    k/=2;\r\n\t\t}\r\n\t}\r\n\tD query(int a,int b){\t\t//non-commutative & unrecursive\r\
    \n\t\tD L = D::e() , R = D::e();\r\n\t\ta+=N,b+=N;\r\n\t\twhile(a<b){\r\n\t\t\t\
    if(a&1) L = L + val[a++];\r\n\t\t\tif(b&1) R = val[--b] + R;\r\n\t\t\ta/=2,b/=2;\r\
    \n\t\t}\r\n\t\treturn L+R;\r\n\t}\r\n\t// D query(int a,int b){\r\n\t// \treturn\
    \ query(a,b,0,N,1);\r\n\t// }\r\n\t// D query(int a,int b,int l,int r,int k){\r\
    \n\t// \tif(b<=l||r<=a) return D::e;\r\n\t// \tif(a<=l&&r<=b) return val[k];\r\
    \n\t// \treturn query(a,b,l,(l+r)/2,k*2) + query(a,b,(l+r)/2,r,k*2+1);\r\n\t//\
    \ }\r\n};\r\n\r\nstruct Dplus{\t\t//(int,+,0)\r\n\tint x;\r\n\tDplus(){*this =\
    \ e();}\r\n\tDplus(int x):x(x){}\r\n\tstatic Dplus e(){\r\n\t\treturn Dplus(0);\r\
    \n\t}\r\n\tDplus operator+(const Dplus& r) const {\r\n\t\treturn Dplus(x+r.x);\r\
    \n\t}\r\n\tfriend ostream& operator<<(ostream& o,const Dplus& d){return o<<d.x;}\r\
    \n};\r\n\r\nstruct Dmax{\t\t//(int,max,-inf)\r\n\tint x;\r\n\tDmax(){*this = e();}\r\
    \n\tDmax(int x):x(x){}\r\n\tstatic Dmax e(){\r\n\t\treturn Dmax(-1e9);\r\n\t}\r\
    \n\tDmax operator+(const Dmax& r) const {\r\n\t\treturn Dmax(max(x,r.x));\r\n\t\
    }\r\n\tfriend ostream& operator<<(ostream& o,const Dmax& d){return o<<d.x;}\r\n\
    };\r\n\r\nstruct Dmin{\t\t//(int,min,inf)\r\n\tint x;\r\n\tDmin(){*this = e();}\r\
    \n\tDmin(int x):x(x){}\r\n\tstatic Dmin e(){\r\n\t\treturn Dmin(1e9);\r\n\t}\r\
    \n\tDmin operator+(const Dmin& r) const {\r\n\t\treturn Dmin(min(x,r.x));\r\n\t\
    }\r\n\tfriend ostream& operator<<(ostream& o,const Dmin& d){return o<<d.x;}\r\n\
    };\r\n\r\nstruct Dleftmostmax{\t\t//(int,max,-inf)\r\n\tusing D = Dleftmostmax;\r\
    \n\tint x,a;\t//val,argid\r\n\tDleftmostmax(){*this = e();}\r\n\tDleftmostmax(int\
    \ x,int a):x(x),a(a){}\r\n\tstatic D e(){\r\n\t\treturn D(-1e9,-1);\r\n\t}\r\n\
    \tD operator+(const D& r) const {\r\n\t\tif(x>r.x || (x==r.x&&a<r.a)) return *this;\r\
    \n\t\telse return r;\r\n\t}\r\n\tfriend ostream& operator<<(ostream& o,const D&\
    \ d){return o<<\"(\"<<d.x<<\",\"<<d.a<<\")\";}\r\n};\r\n\r\nstruct Dperm{\r\n\t\
    using D = Dperm;\r\n\tconst static int N = 5;\r\n\tusing V = array<int,N>;\r\n\
    \tV v;\r\n\tDperm(){*this = e();}\r\n\tDperm(V v):v(v){}\r\n\tconst static D e(){\r\
    \n\t\treturn D({0,1,2,3,4});\r\n\t}\r\n\tD operator+(const D& r) const {\r\n\t\
    \tV ret;\r\n\t\trep(i,N) ret[i] = v[r.v[i]];\r\n\t\treturn D(ret);\r\n\t};\r\n\
    };\r\n\r\nstruct Dmat{\r\n\tusing T = int;\r\n\tusing D = Dmat;\r\n\tconst static\
    \ int N = 5;\r\n\tusing V = array<T,N>;\r\n\tusing VV = array<V,N>;\r\n\tVV a;\r\
    \n\tDmat(){*this = e();}\r\n\tDmat(VV a):a(a){}\r\n\tconst static D e(){\r\n\t\
    \tVV a;\r\n\t\trep(i,N) rep(j,N) a[i][j] = (i==j?1:0);\r\n\t\treturn D(a);\r\n\
    \t}\r\n\tD operator+(const D& r) const {\r\n\t\tVV c;\r\n\t\trep(i,N) rep(j,N)\
    \ c[i][j]=0;\r\n\t\trep(i,N) rep(j,N) rep(k,N) c[i][j] += a[i][k] * r.a[k][j];\r\
    \n\t\treturn D(c);\r\n\t};\r\n\tbool operator==(const D& r) const {\r\n\t\treturn\
    \ a==r.a;\r\n\t}\r\n};\r\n\r\nvoid unittest(){\t//\u3069\u3063\u3061\u304B\u3068\
    \u3044\u3046\u3068struct D\u306E\u30C6\u30B9\u30C8\r\n\t{\r\n\t\tvector<Dplus>\
    \ vs = {4,2,5,4,8,3,1,4,1,5};\r\n\t\tsegtree<Dplus> seg(vs);\r\n\t\trep(l,10)\
    \ for(int r=l;r<=10;r++){\r\n\t\t\tint sum = 0;\r\n\t\t\tfor(int i=l;i<r;i++)\
    \ sum+=vs[i].x;\r\n\t\t\tassert( seg.query(l,r).x == sum );\r\n\t\t}\r\n\t}\r\n\
    \t{\r\n\t\tvector<Dmax> vs = {-4,2,-5,-4,8,-3,1,-4,1,5};\r\n\t\tsegtree<Dmax>\
    \ seg1(vs);\r\n\t\trep(l,10) for(int r=l;r<=10;r++){\r\n\t\t\tint mx = Dmax::e().x;\r\
    \n\t\t\tfor(int i=l;i<r;i++) chmax(mx,vs[i].x);\r\n\t\t\tassert( seg1.query(l,r).x\
    \ == mx );\r\n\t\t}\r\n\t}\r\n\t{\r\n\t\tusing D = Dleftmostmax;\r\n\t\tvector<int>\
    \ vi = {1,1,2,1,3,2,1,3,2,1};\r\n\t\tvector<D> vs;\r\n\t\trep(i,10) vs.push_back(D(vi[i],i));\r\
    \n\t\tsegtree<D> seg(vs);\r\n\t\trep(l,10) for(int r=l+1;r<=10;r++){\r\n\t\t\t\
    int mx = D::e().x;\r\n\t\t\tint ag = -1;\r\n\t\t\tfor(int i=l;i<r;i++){\r\n\t\t\
    \t\tif(mx<vi[i]){\r\n\t\t\t\t\tmx=vi[i];\r\n\t\t\t\t\tag=i;\r\n\t\t\t\t}\r\n\t\
    \t\t}\r\n\t\t\tassert( seg.query(l,r).a == ag );\r\n\t\t}\r\n\t}\r\n\t{\r\n\t\t\
    using D = Dperm;\r\n\t\tvector<D> vs = {D({0,3,2,4,1}),D({0,3,2,1,4}),D({3,2,0,4,1}),D({0,3,4,2,1}),D({0,3,2,4,1}),D({0,3,1,4,2}),D({4,2,3,0,1}),D({3,2,4,1,0})};\r\
    \n\t\tsegtree<D> seg(vs);\r\n\t\tint N = vs.size();\r\n\t\trep(l,N) for(int r=l;r<=N;r++){\r\
    \n\t\t\tint a[5]={0,1,2,3,4};\r\n\t\t\tfor(int i=l;i<r;i++){\r\n\t\t\t\tint na[5];\r\
    \n\t\t\t\trep(j,5) na[j] = a[vs[i].v[j]];\r\n\t\t\t\trep(j,5) a[j]=na[j];\r\n\t\
    \t\t}\r\n\t\t\tD calc = seg.query(l,r);\r\n\t\t\trep(i,5) assert( calc.v[i] ==\
    \ a[i] );\r\n\t\t}\r\n\t}\r\n\t{\r\n\t\tusing D = Dmat;\r\n\t\tconst int K = Dmat::N;\r\
    \n\t\tusing T = int;\r\n\t\tusing V = array<T,K>;\r\n\t\tusing VV = array<V,K>;\r\
    \n\r\n\t\tvector<D> vs;\r\n\t\tint N = 10;\r\n\t\trep(i,N){\r\n\t\t\tVV a;\r\n\
    \t\t\trep(x,K) rep(y,K) a[x][y] = rand()%201+100;\r\n\t\t\tvs.push_back(D(a));\r\
    \n\t\t}\r\n\t\tsegtree<D> seg(vs);\r\n\t\trep(l,N) for(int r=l;r<=N;r++){\r\n\t\
    \t\tD x = D::e();\r\n\t\t\tfor(int i=l;i<r;i++) x = x+vs[i];\r\n\t\t\tassert(\
    \ seg.query(l,r) == x );\r\n\t\t}\r\n\t}\r\n}\r\nint main(){\r\n\tunittest();\r\
    \n}\n"
  code: "/*\r\n\tpoint assign,range + \u975E\u518D\u5E30\r\n\r\n\tstruct D \u306E\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306F\u5F15\u6570\u7121\u3057\u3067\u5358\
    \u4F4D\u5143\u3092\u8FD4\u3059\u3088\u3046\u306B\u3057\u3066\u304A\u304F\u3053\
    \u3068\r\n*/\r\n#include <bits/stdc++.h>\r\n#define rep(i,n) for(int i=0;i<n;i++)\r\
    \n#define fs first\r\n#define sc second\r\n#define chmax(x,y) x=max(x,y)\r\nusing\
    \ namespace std;\r\n\r\ntemplate<class D>\r\nstruct segtree{\r\n\tint N;\r\n\t\
    vector<D> val;\r\n\r\n\tsegtree(){}\r\n\tsegtree(int n){\r\n\t\tN=1;\r\n\t\twhile(N<n)\
    \ N*=2;\r\n\t\tval.assign(N*2,D::e());\r\n\t}\r\n\tsegtree(const vector<D>& ds){\r\
    \n\t\tint n = ds.size();\r\n\t\tN=1;\r\n\t\twhile(N<n) N*=2;\r\n\t\tval.assign(N*2,D::e());\r\
    \n\t\trep(i,n) val[i+N] = ds[i];\r\n\t\tfor(int i=N-1;i>0;i--) val[i] = val[i*2]\
    \ + val[i*2+1];\r\n\t}\r\n\tvoid assign(int k,D d){\r\n\t\tk+=N;\r\n\t\tval[k]=d;\r\
    \n\t\tk/=2;\r\n\t\twhile(k){\r\n\t\t\tval[k] = val[k*2] + val[k*2+1];\r\n\t\t\t\
    k/=2;\r\n\t\t}\r\n\t}\r\n\tD query(int a,int b){\t\t//non-commutative & unrecursive\r\
    \n\t\tD L = D::e() , R = D::e();\r\n\t\ta+=N,b+=N;\r\n\t\twhile(a<b){\r\n\t\t\t\
    if(a&1) L = L + val[a++];\r\n\t\t\tif(b&1) R = val[--b] + R;\r\n\t\t\ta/=2,b/=2;\r\
    \n\t\t}\r\n\t\treturn L+R;\r\n\t}\r\n\t// D query(int a,int b){\r\n\t// \treturn\
    \ query(a,b,0,N,1);\r\n\t// }\r\n\t// D query(int a,int b,int l,int r,int k){\r\
    \n\t// \tif(b<=l||r<=a) return D::e;\r\n\t// \tif(a<=l&&r<=b) return val[k];\r\
    \n\t// \treturn query(a,b,l,(l+r)/2,k*2) + query(a,b,(l+r)/2,r,k*2+1);\r\n\t//\
    \ }\r\n};\r\n\r\nstruct Dplus{\t\t//(int,+,0)\r\n\tint x;\r\n\tDplus(){*this =\
    \ e();}\r\n\tDplus(int x):x(x){}\r\n\tstatic Dplus e(){\r\n\t\treturn Dplus(0);\r\
    \n\t}\r\n\tDplus operator+(const Dplus& r) const {\r\n\t\treturn Dplus(x+r.x);\r\
    \n\t}\r\n\tfriend ostream& operator<<(ostream& o,const Dplus& d){return o<<d.x;}\r\
    \n};\r\n\r\nstruct Dmax{\t\t//(int,max,-inf)\r\n\tint x;\r\n\tDmax(){*this = e();}\r\
    \n\tDmax(int x):x(x){}\r\n\tstatic Dmax e(){\r\n\t\treturn Dmax(-1e9);\r\n\t}\r\
    \n\tDmax operator+(const Dmax& r) const {\r\n\t\treturn Dmax(max(x,r.x));\r\n\t\
    }\r\n\tfriend ostream& operator<<(ostream& o,const Dmax& d){return o<<d.x;}\r\n\
    };\r\n\r\nstruct Dmin{\t\t//(int,min,inf)\r\n\tint x;\r\n\tDmin(){*this = e();}\r\
    \n\tDmin(int x):x(x){}\r\n\tstatic Dmin e(){\r\n\t\treturn Dmin(1e9);\r\n\t}\r\
    \n\tDmin operator+(const Dmin& r) const {\r\n\t\treturn Dmin(min(x,r.x));\r\n\t\
    }\r\n\tfriend ostream& operator<<(ostream& o,const Dmin& d){return o<<d.x;}\r\n\
    };\r\n\r\nstruct Dleftmostmax{\t\t//(int,max,-inf)\r\n\tusing D = Dleftmostmax;\r\
    \n\tint x,a;\t//val,argid\r\n\tDleftmostmax(){*this = e();}\r\n\tDleftmostmax(int\
    \ x,int a):x(x),a(a){}\r\n\tstatic D e(){\r\n\t\treturn D(-1e9,-1);\r\n\t}\r\n\
    \tD operator+(const D& r) const {\r\n\t\tif(x>r.x || (x==r.x&&a<r.a)) return *this;\r\
    \n\t\telse return r;\r\n\t}\r\n\tfriend ostream& operator<<(ostream& o,const D&\
    \ d){return o<<\"(\"<<d.x<<\",\"<<d.a<<\")\";}\r\n};\r\n\r\nstruct Dperm{\r\n\t\
    using D = Dperm;\r\n\tconst static int N = 5;\r\n\tusing V = array<int,N>;\r\n\
    \tV v;\r\n\tDperm(){*this = e();}\r\n\tDperm(V v):v(v){}\r\n\tconst static D e(){\r\
    \n\t\treturn D({0,1,2,3,4});\r\n\t}\r\n\tD operator+(const D& r) const {\r\n\t\
    \tV ret;\r\n\t\trep(i,N) ret[i] = v[r.v[i]];\r\n\t\treturn D(ret);\r\n\t};\r\n\
    };\r\n\r\nstruct Dmat{\r\n\tusing T = int;\r\n\tusing D = Dmat;\r\n\tconst static\
    \ int N = 5;\r\n\tusing V = array<T,N>;\r\n\tusing VV = array<V,N>;\r\n\tVV a;\r\
    \n\tDmat(){*this = e();}\r\n\tDmat(VV a):a(a){}\r\n\tconst static D e(){\r\n\t\
    \tVV a;\r\n\t\trep(i,N) rep(j,N) a[i][j] = (i==j?1:0);\r\n\t\treturn D(a);\r\n\
    \t}\r\n\tD operator+(const D& r) const {\r\n\t\tVV c;\r\n\t\trep(i,N) rep(j,N)\
    \ c[i][j]=0;\r\n\t\trep(i,N) rep(j,N) rep(k,N) c[i][j] += a[i][k] * r.a[k][j];\r\
    \n\t\treturn D(c);\r\n\t};\r\n\tbool operator==(const D& r) const {\r\n\t\treturn\
    \ a==r.a;\r\n\t}\r\n};\r\n\r\nvoid unittest(){\t//\u3069\u3063\u3061\u304B\u3068\
    \u3044\u3046\u3068struct D\u306E\u30C6\u30B9\u30C8\r\n\t{\r\n\t\tvector<Dplus>\
    \ vs = {4,2,5,4,8,3,1,4,1,5};\r\n\t\tsegtree<Dplus> seg(vs);\r\n\t\trep(l,10)\
    \ for(int r=l;r<=10;r++){\r\n\t\t\tint sum = 0;\r\n\t\t\tfor(int i=l;i<r;i++)\
    \ sum+=vs[i].x;\r\n\t\t\tassert( seg.query(l,r).x == sum );\r\n\t\t}\r\n\t}\r\n\
    \t{\r\n\t\tvector<Dmax> vs = {-4,2,-5,-4,8,-3,1,-4,1,5};\r\n\t\tsegtree<Dmax>\
    \ seg1(vs);\r\n\t\trep(l,10) for(int r=l;r<=10;r++){\r\n\t\t\tint mx = Dmax::e().x;\r\
    \n\t\t\tfor(int i=l;i<r;i++) chmax(mx,vs[i].x);\r\n\t\t\tassert( seg1.query(l,r).x\
    \ == mx );\r\n\t\t}\r\n\t}\r\n\t{\r\n\t\tusing D = Dleftmostmax;\r\n\t\tvector<int>\
    \ vi = {1,1,2,1,3,2,1,3,2,1};\r\n\t\tvector<D> vs;\r\n\t\trep(i,10) vs.push_back(D(vi[i],i));\r\
    \n\t\tsegtree<D> seg(vs);\r\n\t\trep(l,10) for(int r=l+1;r<=10;r++){\r\n\t\t\t\
    int mx = D::e().x;\r\n\t\t\tint ag = -1;\r\n\t\t\tfor(int i=l;i<r;i++){\r\n\t\t\
    \t\tif(mx<vi[i]){\r\n\t\t\t\t\tmx=vi[i];\r\n\t\t\t\t\tag=i;\r\n\t\t\t\t}\r\n\t\
    \t\t}\r\n\t\t\tassert( seg.query(l,r).a == ag );\r\n\t\t}\r\n\t}\r\n\t{\r\n\t\t\
    using D = Dperm;\r\n\t\tvector<D> vs = {D({0,3,2,4,1}),D({0,3,2,1,4}),D({3,2,0,4,1}),D({0,3,4,2,1}),D({0,3,2,4,1}),D({0,3,1,4,2}),D({4,2,3,0,1}),D({3,2,4,1,0})};\r\
    \n\t\tsegtree<D> seg(vs);\r\n\t\tint N = vs.size();\r\n\t\trep(l,N) for(int r=l;r<=N;r++){\r\
    \n\t\t\tint a[5]={0,1,2,3,4};\r\n\t\t\tfor(int i=l;i<r;i++){\r\n\t\t\t\tint na[5];\r\
    \n\t\t\t\trep(j,5) na[j] = a[vs[i].v[j]];\r\n\t\t\t\trep(j,5) a[j]=na[j];\r\n\t\
    \t\t}\r\n\t\t\tD calc = seg.query(l,r);\r\n\t\t\trep(i,5) assert( calc.v[i] ==\
    \ a[i] );\r\n\t\t}\r\n\t}\r\n\t{\r\n\t\tusing D = Dmat;\r\n\t\tconst int K = Dmat::N;\r\
    \n\t\tusing T = int;\r\n\t\tusing V = array<T,K>;\r\n\t\tusing VV = array<V,K>;\r\
    \n\r\n\t\tvector<D> vs;\r\n\t\tint N = 10;\r\n\t\trep(i,N){\r\n\t\t\tVV a;\r\n\
    \t\t\trep(x,K) rep(y,K) a[x][y] = rand()%201+100;\r\n\t\t\tvs.push_back(D(a));\r\
    \n\t\t}\r\n\t\tsegtree<D> seg(vs);\r\n\t\trep(l,N) for(int r=l;r<=N;r++){\r\n\t\
    \t\tD x = D::e();\r\n\t\t\tfor(int i=l;i<r;i++) x = x+vs[i];\r\n\t\t\tassert(\
    \ seg.query(l,r) == x );\r\n\t\t}\r\n\t}\r\n}\r\nint main(){\r\n\tunittest();\r\
    \n}"
  dependsOn: []
  isVerificationFile: false
  path: data structure/segtree/segtree_simple.cpp
  requiredBy: []
  timestamp: '2018-07-12 01:03:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/segtree/segtree_simple.cpp
layout: document
redirect_from:
- /library/data structure/segtree/segtree_simple.cpp
- /library/data structure/segtree/segtree_simple.cpp.html
title: data structure/segtree/segtree_simple.cpp
---
