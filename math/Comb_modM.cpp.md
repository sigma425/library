---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/Comb_modM.cpp\"\n/*\n\t\u4EFB\u610Fmod \u3067\u306E\
    \ a choose b\n\tmod \u306F\u3067\u304B\u304F\u3066\u3082\u3044\u3044\n\tX! \u307E\
    \u3067\u306E\u5404\u7D20\u6570\u3067\u306Eorder(acc_order_p)\u3068\u305D\u308C\
    \u4EE5\u5916(other)\u306E\u90E8\u5206\u3092\u524D\u8A08\u7B97\u3057\u3066\u304A\
    \u3044\u3066\u3084\u308B\n\torder\u306FX/p + X/p^2 + .. \u3067\u6C42\u307E\u308B\
    \u306E\u3067\u30E1\u30E2\u30EA\u6E1B\u3089\u3057\u305F\u3044\u306A\u3089\u524D\
    \u8A08\u7B97\u6D88\u3057\u305F\u65B9\u304C\u3044\u3044\u304B\u3082\n\n\t\u3053\
    \u308C\u3067a,b\u3082\u3067\u304B\u304B\u3063\u305F\u3089Lucas?\n\n\t\u7D14\u7C8B\
    \u306B\u3055\u3089\u306B\u30AF\u30A8\u30EA\u3092\u65E9\u304F\u3057\u305F\u3044\
    \u306A\u3089\u3001\u7D2F\u4E57\u3092\u524D\u8A08\u7B97\n\n\tverified at CF/896/D\n\
    */\n\n\n#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define show(x) cout\
    \ << #x << \" = \" << x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y)\
    \ x=max(x,y)\nusing namespace std;\ntemplate<class S,class T> ostream& operator<<(ostream&\
    \ o,const pair<S,T> &p){return o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class\
    \ T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"\
    [\";for(const T& v:vc) o<<v<<\",\";o<<\"]\";return o;}\n\nunsigned int mod;\n\n\
    struct ModInt{\n\tusing uint = unsigned int;\n\tusing ll = long long;\n\tusing\
    \ ull = unsigned long long;\n\n\tuint v;\n\tModInt():v(0){}\n\tModInt(ll v):v(normS(v%mod+mod)){}\n\
    \texplicit operator bool() const {return v!=0;}\n\tstatic uint normS(const uint\
    \ &x){return (x<mod)?x:x-mod;}\t\t// [0 , 2*mod-1] -> [0 , mod-1]\n\tstatic ModInt\
    \ make(const uint &x){ModInt m; m.v=x; return m;}\n\tModInt operator+(const ModInt&\
    \ b) const { return make(normS(v+b.v));}\n\tModInt operator-(const ModInt& b)\
    \ const { return make(normS(v+mod-b.v));}\n\tModInt operator-() const { return\
    \ make(normS(mod-v)); }\n\tModInt operator*(const ModInt& b) const { return make((ull)v*b.v%mod);}\n\
    \tModInt operator/(const ModInt& b) const { return *this*b.inv();}\n\tModInt&\
    \ operator+=(const ModInt& b){ return *this=*this+b;}\n\tModInt& operator-=(const\
    \ ModInt& b){ return *this=*this-b;}\n\tModInt& operator*=(const ModInt& b){ return\
    \ *this=*this*b;}\n\tModInt& operator/=(const ModInt& b){ return *this=*this/b;}\n\
    \tll extgcd(ll a,ll b,ll &x,ll &y) const{\n\t\tll u[]={a,1,0},v[]={b,0,1};\n\t\
    \twhile(*v){\n\t\t\tll t=*u/ *v;\n\t\t\trep(i,3) swap(u[i]-=t*v[i],v[i]);\n\t\t\
    }\n\t\tif(u[0]<0) rep(i,3) u[i]=-u[i];\n\t\tx=u[1],y=u[2];\n\t\treturn u[0];\n\
    \t}\n\tModInt inv() const{\n\t\tll x,y;\n\t\textgcd(v,mod,x,y);\n\t\treturn make(normS(x+mod));\n\
    \t}\n\tbool operator==(const ModInt& b) const { return v==b.v;}\n\tbool operator!=(const\
    \ ModInt& b) const { return v!=b.v;}\n\tfriend istream& operator>>(istream &o,ModInt&\
    \ x){\n\t\tll tmp;\n\t\to>>tmp;\n\t\tx=ModInt(tmp);\n\t\treturn o;\n\t}\n\tfriend\
    \ ostream& operator<<(ostream &o,const ModInt& x){ return o<<x.v;}\n};\nusing\
    \ mint = ModInt;\n\nstruct precalc_comb{\n\tusing ll = long long;\n\tll M;\n\t\
    vector<ll> ps;\n\n\tvector<vector<int>> acc_order_p;\n\tvector<mint> acc_other;\n\
    \n\tprecalc_comb(){}\n\n\tprecalc_comb(ll M,int X):M(M){\t//X! \u307E\u3067\n\t\
    \tmod = M;\t//mint\n\n\t\t{\t//factorize\n\t\t\tll x = M;\n\t\t\tfor(ll i=2;i*i<=x;i++)\
    \ if(x%i==0){\n\t\t\t\tps.pb(i);\n\t\t\t\twhile(x%i==0) x/=i;\n\t\t\t}\n\t\t\t\
    if(x>1) ps.pb(x);\n\t\t}\n\n\t\tint K = ps.size();\n\n\t\tacc_order_p = vector<vector<int>>(X+1,vector<int>(K,0));\n\
    \t\tacc_other = vector<mint>(X+1);\n\n\t\tvector<int> n(X+1);\n\t\trep(i,X+1)\
    \ n[i] = i;\n\n\t\trep(k,K){\n\t\t\tll p = ps[k];\n\t\t\tfor(ll x=p;x<=X;x+=p){\n\
    \t\t\t\twhile(n[x]%p==0){\n\t\t\t\t\tn[x]/=p;\n\t\t\t\t\tacc_order_p[x][k]++;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tacc_other[0] = 1;\n\t\trep(i,X) acc_other[i+1]\
    \ = acc_other[i] * n[i+1];\n\t\trep(k,K){\n\t\t\trep(i,X) acc_order_p[i+1][k]\
    \ += acc_order_p[i][k];\n\t\t}\n\t}\n\n\tmint ex(mint x,int p){\n\t\tmint a =\
    \ 1;\n\t\twhile(p){\n\t\t\tif(p%2) a*=x;\n\t\t\tx*=x;\n\t\t\tp/=2;\n\t\t}\n\t\t\
    return a;\n\t}\n\n\n\tmint C(int x,int y){\t//x choose y\n\t\tif(M==1) return\
    \ 0;\n\t\tif(y<0 || y>x) return 0;\n\t\tint K = ps.size();\n\t\tmint c = acc_other[x]\
    \ / (acc_other[y] * acc_other[x-y]);\n\t\trep(k,K){\n\t\t\tint r = acc_order_p[x][k]\
    \ - acc_order_p[y][k] - acc_order_p[x-y][k];\n\t\t\tc *= ex(ps[k],r);\n\t\t}\n\
    \t\treturn c;\n\t}\n}PC;\n\n// mint C(int x,int y){\n// \treturn PC.C(x,y);\n\
    // }\n\nlong long C[1001][1001];\n\nint main(){\n\tlong long M;\n\tcin>>M;\n//\t\
    M = 2*3*5*7*11*13*17*19*23; //(223'093'870)\n\trep(i,1001){\n\t\tC[i][0] = C[i][i]\
    \ = 1%M;\n\t\trep1(j,i-1) C[i][j] = (C[i-1][j-1]+C[i-1][j])%M;\n\t}\n\tPC = precalc_comb(M,200000);\n\
    \tputs(\"done constructer\");\n\n\trep1(x,1000) rep(y,x+1){\n\t\tif(C[x][y] !=\
    \ (int)PC.C(x,y).v){\n\t\t\tshow(x);\n\t\t\tshow(y);\n\t\t\tshow(C[x][y]);\n\t\
    \t\tshow(PC.C(x,y));\n\t\t\tassert(0);\n\t\t}\n\t}\n\n\twhile(true){\n\t\tint\
    \ x,y;\n\t\tcin>>x>>y;\n\t\tprintf(\"%d choose %d = %d     mod %d\\n\",x,y,(int)PC.C(x,y).v,(int)M);\n\
    \t}\n\n}\n"
  code: "/*\n\t\u4EFB\u610Fmod \u3067\u306E a choose b\n\tmod \u306F\u3067\u304B\u304F\
    \u3066\u3082\u3044\u3044\n\tX! \u307E\u3067\u306E\u5404\u7D20\u6570\u3067\u306E\
    order(acc_order_p)\u3068\u305D\u308C\u4EE5\u5916(other)\u306E\u90E8\u5206\u3092\
    \u524D\u8A08\u7B97\u3057\u3066\u304A\u3044\u3066\u3084\u308B\n\torder\u306FX/p\
    \ + X/p^2 + .. \u3067\u6C42\u307E\u308B\u306E\u3067\u30E1\u30E2\u30EA\u6E1B\u3089\
    \u3057\u305F\u3044\u306A\u3089\u524D\u8A08\u7B97\u6D88\u3057\u305F\u65B9\u304C\
    \u3044\u3044\u304B\u3082\n\n\t\u3053\u308C\u3067a,b\u3082\u3067\u304B\u304B\u3063\
    \u305F\u3089Lucas?\n\n\t\u7D14\u7C8B\u306B\u3055\u3089\u306B\u30AF\u30A8\u30EA\
    \u3092\u65E9\u304F\u3057\u305F\u3044\u306A\u3089\u3001\u7D2F\u4E57\u3092\u524D\
    \u8A08\u7B97\n\n\tverified at CF/896/D\n*/\n\n\n#include <bits/stdc++.h>\n#define\
    \ rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<\"(\"\
    <<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class T> ostream& operator<<(ostream& o,const\
    \ vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"[\";for(const T& v:vc) o<<v<<\"\
    ,\";o<<\"]\";return o;}\n\nunsigned int mod;\n\nstruct ModInt{\n\tusing uint =\
    \ unsigned int;\n\tusing ll = long long;\n\tusing ull = unsigned long long;\n\n\
    \tuint v;\n\tModInt():v(0){}\n\tModInt(ll v):v(normS(v%mod+mod)){}\n\texplicit\
    \ operator bool() const {return v!=0;}\n\tstatic uint normS(const uint &x){return\
    \ (x<mod)?x:x-mod;}\t\t// [0 , 2*mod-1] -> [0 , mod-1]\n\tstatic ModInt make(const\
    \ uint &x){ModInt m; m.v=x; return m;}\n\tModInt operator+(const ModInt& b) const\
    \ { return make(normS(v+b.v));}\n\tModInt operator-(const ModInt& b) const { return\
    \ make(normS(v+mod-b.v));}\n\tModInt operator-() const { return make(normS(mod-v));\
    \ }\n\tModInt operator*(const ModInt& b) const { return make((ull)v*b.v%mod);}\n\
    \tModInt operator/(const ModInt& b) const { return *this*b.inv();}\n\tModInt&\
    \ operator+=(const ModInt& b){ return *this=*this+b;}\n\tModInt& operator-=(const\
    \ ModInt& b){ return *this=*this-b;}\n\tModInt& operator*=(const ModInt& b){ return\
    \ *this=*this*b;}\n\tModInt& operator/=(const ModInt& b){ return *this=*this/b;}\n\
    \tll extgcd(ll a,ll b,ll &x,ll &y) const{\n\t\tll u[]={a,1,0},v[]={b,0,1};\n\t\
    \twhile(*v){\n\t\t\tll t=*u/ *v;\n\t\t\trep(i,3) swap(u[i]-=t*v[i],v[i]);\n\t\t\
    }\n\t\tif(u[0]<0) rep(i,3) u[i]=-u[i];\n\t\tx=u[1],y=u[2];\n\t\treturn u[0];\n\
    \t}\n\tModInt inv() const{\n\t\tll x,y;\n\t\textgcd(v,mod,x,y);\n\t\treturn make(normS(x+mod));\n\
    \t}\n\tbool operator==(const ModInt& b) const { return v==b.v;}\n\tbool operator!=(const\
    \ ModInt& b) const { return v!=b.v;}\n\tfriend istream& operator>>(istream &o,ModInt&\
    \ x){\n\t\tll tmp;\n\t\to>>tmp;\n\t\tx=ModInt(tmp);\n\t\treturn o;\n\t}\n\tfriend\
    \ ostream& operator<<(ostream &o,const ModInt& x){ return o<<x.v;}\n};\nusing\
    \ mint = ModInt;\n\nstruct precalc_comb{\n\tusing ll = long long;\n\tll M;\n\t\
    vector<ll> ps;\n\n\tvector<vector<int>> acc_order_p;\n\tvector<mint> acc_other;\n\
    \n\tprecalc_comb(){}\n\n\tprecalc_comb(ll M,int X):M(M){\t//X! \u307E\u3067\n\t\
    \tmod = M;\t//mint\n\n\t\t{\t//factorize\n\t\t\tll x = M;\n\t\t\tfor(ll i=2;i*i<=x;i++)\
    \ if(x%i==0){\n\t\t\t\tps.pb(i);\n\t\t\t\twhile(x%i==0) x/=i;\n\t\t\t}\n\t\t\t\
    if(x>1) ps.pb(x);\n\t\t}\n\n\t\tint K = ps.size();\n\n\t\tacc_order_p = vector<vector<int>>(X+1,vector<int>(K,0));\n\
    \t\tacc_other = vector<mint>(X+1);\n\n\t\tvector<int> n(X+1);\n\t\trep(i,X+1)\
    \ n[i] = i;\n\n\t\trep(k,K){\n\t\t\tll p = ps[k];\n\t\t\tfor(ll x=p;x<=X;x+=p){\n\
    \t\t\t\twhile(n[x]%p==0){\n\t\t\t\t\tn[x]/=p;\n\t\t\t\t\tacc_order_p[x][k]++;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tacc_other[0] = 1;\n\t\trep(i,X) acc_other[i+1]\
    \ = acc_other[i] * n[i+1];\n\t\trep(k,K){\n\t\t\trep(i,X) acc_order_p[i+1][k]\
    \ += acc_order_p[i][k];\n\t\t}\n\t}\n\n\tmint ex(mint x,int p){\n\t\tmint a =\
    \ 1;\n\t\twhile(p){\n\t\t\tif(p%2) a*=x;\n\t\t\tx*=x;\n\t\t\tp/=2;\n\t\t}\n\t\t\
    return a;\n\t}\n\n\n\tmint C(int x,int y){\t//x choose y\n\t\tif(M==1) return\
    \ 0;\n\t\tif(y<0 || y>x) return 0;\n\t\tint K = ps.size();\n\t\tmint c = acc_other[x]\
    \ / (acc_other[y] * acc_other[x-y]);\n\t\trep(k,K){\n\t\t\tint r = acc_order_p[x][k]\
    \ - acc_order_p[y][k] - acc_order_p[x-y][k];\n\t\t\tc *= ex(ps[k],r);\n\t\t}\n\
    \t\treturn c;\n\t}\n}PC;\n\n// mint C(int x,int y){\n// \treturn PC.C(x,y);\n\
    // }\n\nlong long C[1001][1001];\n\nint main(){\n\tlong long M;\n\tcin>>M;\n//\t\
    M = 2*3*5*7*11*13*17*19*23; //(223'093'870)\n\trep(i,1001){\n\t\tC[i][0] = C[i][i]\
    \ = 1%M;\n\t\trep1(j,i-1) C[i][j] = (C[i-1][j-1]+C[i-1][j])%M;\n\t}\n\tPC = precalc_comb(M,200000);\n\
    \tputs(\"done constructer\");\n\n\trep1(x,1000) rep(y,x+1){\n\t\tif(C[x][y] !=\
    \ (int)PC.C(x,y).v){\n\t\t\tshow(x);\n\t\t\tshow(y);\n\t\t\tshow(C[x][y]);\n\t\
    \t\tshow(PC.C(x,y));\n\t\t\tassert(0);\n\t\t}\n\t}\n\n\twhile(true){\n\t\tint\
    \ x,y;\n\t\tcin>>x>>y;\n\t\tprintf(\"%d choose %d = %d     mod %d\\n\",x,y,(int)PC.C(x,y).v,(int)M);\n\
    \t}\n\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/Comb_modM.cpp
  requiredBy: []
  timestamp: '2018-09-18 03:14:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Comb_modM.cpp
layout: document
redirect_from:
- /library/math/Comb_modM.cpp
- /library/math/Comb_modM.cpp.html
title: math/Comb_modM.cpp
---
