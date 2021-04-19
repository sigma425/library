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
  bundledCode: "#line 1 \"math/berlekamp-massey.cpp\"\n/*\nBerlekamp-Massey\n\u4F53\
    K\u4E0A\u306En+1\u9805\u9593\u7DDA\u5F62\u6F38\u5316\u5F0F\u304B\u3089\u751F\u6210\
    \u3055\u308C\u308B\u6570\u5217\u306E,\u306F\u3058\u30812n\u9805\u3092\u6E21\u3059\
    \u3068,\u305D\u306E\u7DDA\u5F62\u6F38\u5316\u5F0F(\u3068\u3044\u3046\u304B\u6700\
    \u5C0F\u591A\u9805\u5F0F)\u3092\u6C42\u3081\u3066\u304F\u308C\u308B\n\u4F8B\u3048\
    \u3070fib\u306A\u30894\u9805\u5FC5\u8981.\ninput \u3092 u , N\u9805 \u3068\u3057\
    \u3066 output \u3092 c \u3068\u3059\u308B\u3068\nfor all j < N-K,\nc_0 * u_j +\
    \ c_1 * u_{j+1} + .. + c_K * u_{j+K} = 0\n\u3068\u306A\u308B.\nO(N^2)\n\nfft,poly,mint\
    \ \u3068\u304B\u304C\u3044\u308B\nmain\u95A2\u6570\u3088\u308A\u4E0B\u306B\u307E\
    \u308B\u3054\u3068\u8CBC\u3063\u3066\u3042\u308B\u306E\u3067mint\u3067\u4F7F\u3046\
    \u3068\u304D\u306F\u3053\u3063\u304B\u3089\u30B3\u30D4\u30FC\u3059\u308B\n!! mod\
    \ \u306E\u5024\u3092\u5909\u3048\u308B !!\n\nN\u9805\u76EE\u3092\u6C42\u3081\u305F\
    \u3044\u3068\u304D\u306F\u3001x^N \u3092 \u3053\u306E\u591A\u9805\u5F0F\u3067\u5272\
    \u308B\n\u307E\u3042typicalDP/T.cpp \u3068\u304B\u306B\u3042\u308B\u3093\u3067\
    \u3059\u3051\u3069, \u4E00\u822C\u7684\u306A\u51E6\u7406\u306F\n\tvector<mint>\
    \ vals = {0,1,1,2};\n\tauto mod = berlekamp_massey(vals);\n\n\tPoly<mint> a =\
    \ vector<mint>{1};\n\tPoly<mint> x = vector<mint>{0,1};\n\n\tlong long N;\n\t\
    cin>>N;\n\twhile(N){\n\t\tif(N%2) (a*=x)%=mod;\n\t\tx*=x;\n\t\tx%=mod;\n\t\tN/=2;\n\
    \t}\n\tmint ans=0;\n\tint K = mod.size();\n\trep(i,K) ans+=a.at(i)*vals[i];\n\t\
    cout<<ans<<endl;\n\n\t\u3067\u3059\n\n*/\n#include <bits/stdc++.h>\n#define rep(i,n)\
    \ for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<\"(\"\
    <<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class T> ostream& operator<<(ostream& o,const\
    \ vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"[\";for(const T& v:vc) o<<v<<\"\
    ,\";o<<\"]\";return o;}\n\n\ntemplate<class D>\nPoly<D> berlekamp_massey(const\
    \ vector<D> &u){\n\tint N = u.size();\n\tvector<D> b = {D(-1)}, c = {D(-1)};\n\
    \tD y = D(1);\n\trep1(n,N){\n\t\tint L = c.size(), M = b.size();\n\t\tD x = 0;\n\
    \t\trep(i,L) x += c[i]*u[n-L+i];\n\t\tb.pb(0);\n\t\tM++;\n\t\tif(!x) continue;\n\
    \t\tD coef = x/y;\n\t\tif(L<M){\n\t\t\tauto tmp = c;\n\t\t\tc.insert(begin(c),M-L,D(0));\n\
    \t\t\trep(i,M) c[M-1-i] -= coef*b[M-1-i];\n\t\t\tb=tmp;\n\t\t\ty=x;\n\t\t}else{\n\
    \t\t\trep(i,M) c[L-1-i] -= coef*b[M-1-i];\n\t\t}\n\t}\n\treturn Poly<D>(c);\n\
    }\n\nint main(){\n\tvector<int> fib({0,1,1,2,3,5,8});\n\t//0,1,1,2 \u307E\u3067\
    \u306F\u5FC5\u8981\n\tvector<int> hoge({0,1,2,-1,5,-2,5,3});\t//\t\t2 a_i + a_i+1\
    \ - a_i+2 - a_i+3 = 0\n\t//-2\u307E\u3067\u306F\u5FC5\u8981\n\tauto c = berlekamp_massey(hoge);\t\
    // return\t2 x^0 +   x^1 -   x^2 -   x^3\n\tshow(c);\n}\n\n\ntemplate<class T>\
    \ using V = vector<T>;\ntemplate<class T> using VV = vector<vector<T>>;\ntemplate<unsigned\
    \ int mod_>\nstruct ModInt{\n\tusing uint = unsigned int;\n\tusing ll = long long;\n\
    \tusing ull = unsigned long long;\n\n\tconstexpr static uint mod = mod_;\n\n\t\
    uint v;\n\tModInt():v(0){}\n\tModInt(ll v):v(normS(v%mod+mod)){}\n\texplicit operator\
    \ bool() const {return v!=0;}\n\tstatic uint normS(const uint &x){return (x<mod)?x:x-mod;}\t\
    \t// [0 , 2*mod-1] -> [0 , mod-1]\n\tstatic ModInt make(const uint &x){ModInt\
    \ m; m.v=x; return m;}\n\tModInt operator+(const ModInt& b) const { return make(normS(v+b.v));}\n\
    \tModInt operator-(const ModInt& b) const { return make(normS(v+mod-b.v));}\n\t\
    ModInt operator-() const { return make(normS(mod-v)); }\n\tModInt operator*(const\
    \ ModInt& b) const { return make((ull)v*b.v%mod);}\n\tModInt operator/(const ModInt&\
    \ b) const { return *this*b.inv();}\n\tModInt& operator+=(const ModInt& b){ return\
    \ *this=*this+b;}\n\tModInt& operator-=(const ModInt& b){ return *this=*this-b;}\n\
    \tModInt& operator*=(const ModInt& b){ return *this=*this*b;}\n\tModInt& operator/=(const\
    \ ModInt& b){ return *this=*this/b;}\n\tll extgcd(ll a,ll b,ll &x,ll &y) const{\n\
    \t\tll u[]={a,1,0},v[]={b,0,1};\n\t\twhile(*v){\n\t\t\tll t=*u/ *v;\n\t\t\trep(i,3)\
    \ swap(u[i]-=t*v[i],v[i]);\n\t\t}\n\t\tif(u[0]<0) rep(i,3) u[i]=-u[i];\n\t\tx=u[1],y=u[2];\n\
    \t\treturn u[0];\n\t}\n\tModInt inv() const{\n\t\tll x,y;\n\t\textgcd(v,mod,x,y);\n\
    \t\treturn make(normS(x+mod));\n\t}\n\tbool operator==(const ModInt& b) const\
    \ { return v==b.v;}\n\tbool operator!=(const ModInt& b) const { return v!=b.v;}\n\
    \tfriend istream& operator>>(istream &o,ModInt& x){\n\t\tll tmp;\n\t\to>>tmp;\n\
    \t\tx=ModInt(tmp);\n\t\treturn o;\n\t}\n\tfriend ostream& operator<<(ostream &o,const\
    \ ModInt& x){ return o<<x.v;}\n};\nusing mint = ModInt<>;\n\nint bsr(int x) {\
    \ return 31 - __builtin_clz(x); }\nusing D = double;\nconst D pi = acos(-1);\n\
    using Pc = complex<D>;\n\nvoid fft(bool type, vector<Pc> &c){\t//multiply : false\
    \ -> mult -> true\n\tstatic vector<Pc> buf[30];\n\tint N = c.size();\n\tint s\
    \ = bsr(N);\n\tassert(1<<s == N);\n\tif(buf[s].empty()){\n\t\tbuf[s]=vector<Pc>(N);\n\
    \t\trep(i,N) buf[s][i] = polar<D>(1,i*2*pi/N);\n\t}\n\tvector<Pc> a(N),b(N);\n\
    \tcopy(begin(c),end(c),begin(a));\n\trep1(i,s){\n\t\tint W = 1<<(s-i);\n\t\tfor(int\
    \ y=0;y<N/2;y+=W){\n\t\t\tPc now = buf[s][y];\n\t\t\tif(type) now = conj(now);\n\
    \t\t\trep(x,W){\n\t\t\t\tauto l =       a[y<<1 | x];\n\t\t\t\tauto r = now * a[y<<1\
    \ | x | W];\n\t\t\t\tb[y | x]        = l+r;\n\t\t\t\tb[y | x | N>>1] = l-r;\n\t\
    \t\t}\n\t\t}\n\t\tswap(a,b);\n\t}\n\tcopy(begin(a),end(a),begin(c));\n}\ntemplate<class\
    \ Mint>\nvector<Mint> multiply_fft2(const vector<Mint>& x,const vector<Mint>&\
    \ y){\n\tconst int B = 15;\n\tint S = x.size()+y.size()-1;\n\tint N = 2<<bsr(S-1);\n\
    \tvector<Pc> a[2],b[2];\n\trep(t,2){\n\t\ta[t] = vector<Pc>(N);\n\t\tb[t] = vector<Pc>(N);\n\
    \t\trep(i,x.size()) a[t][i] = Pc( (x[i].v >> (t*B)) & ((1<<B)-1) , 0 );\n\t\t\
    rep(i,y.size()) b[t][i] = Pc( (y[i].v >> (t*B)) & ((1<<B)-1) , 0 );\n\t\tfft(false,a[t]);\n\
    \t\tfft(false,b[t]);\n\t}\n\tvector<Mint> z(S);\n\tvector<Pc> c(N);\n\tMint base\
    \ = 1;\n\trep(t,3){\n\t\tfill_n(begin(c),N,Pc(0,0));\n\t\tfor(int xt = max(t-1,0);\
    \ xt<=min(1,t); xt++){\n\t\t\tint yt = t-xt;\n\t\t\trep(i,N) c[i] += a[xt][i]*b[yt][i];\n\
    \t\t}\n\t\tfft(true,c);\n\t\trep(i,S){\n\t\t\tc[i] *= 1.0/N;\n\t\t\tz[i] += Mint(ll(round(c[i].real())))\
    \ * base;\n\t\t}\n\t\tbase *= 1<<B;\n\t}\n\treturn z;\n}\ntemplate<class Mint>\n\
    vector<Mint> multiply_fft(const vector<Mint>& x,const vector<Mint>& y){\n\treturn\
    \ multiply_fft2(x,y);\n}\n\n\ntemplate<class D>\nstruct Poly{\n\tvector<D> v;\n\
    \tint size() const{ return v.size();}\t//deg+1\n\tPoly(int N=0) : v(vector<D>(N)){}\n\
    \tPoly(vector<D> v) : v(v){shrink();}\n\n\tPoly& shrink(){\n\t\twhile(!v.empty()&&v.back()==D(0))\
    \ v.pop_back();\t//double? iszero\u3092global\u306B\u7528\u610F\u3057\u305F\u307B\
    \u3046\u304C\u3044\u3044\u304B\u306A\n\t\treturn *this;\n\t}\n\tD at(int i) const{\n\
    \t\treturn (i<size())?v[i]:D(0);\n\t}\n\tvoid set(int i,const D& x){\t\t//v[i]\
    \ := x\n\t\tif(i>=size() && !x) return;\n\t\twhile(i>=size()) v.push_back(D(0));\n\
    \t\tv[i]=x;\n\t\tshrink();\n\t\treturn;\n\t}\n\t\n\tPoly operator+(const Poly\
    \ &r) const{\n\t\tint N=max(size(),r.size());\n\t\tvector<D> ret(N);\n\t\trep(i,N)\
    \ ret[i]=at(i)+r.at(i);\n\t\treturn Poly(ret);\n\t}\n\tPoly operator-(const Poly\
    \ &r) const{\n\t\tint N=max(size(),r.size());\n\t\tvector<D> ret(N);\n\t\trep(i,N)\
    \ ret[i]=at(i)-r.at(i);\n\t\treturn Poly(ret);\n\t}\n\tPoly operator-() const{\n\
    \t\tint N=size();\n\t\tvector<D> ret(N);\n\t\trep(i,N) ret[i] = -at(i);\n\t\t\
    return Poly(ret);\n\t}\n\tPoly operator*(const Poly &r) const{\n\t\tif(size()==0||r.size()==0)\
    \ return Poly();\n\t\treturn mul_fft(r);\n\t}\n\tPoly operator*(const D &r) const{\n\
    \t\tint N=size();\n\t\tvector<D> ret(N);\n\t\trep(i,N) ret[i]=v[i]*r;\n\t\treturn\
    \ Poly(ret);\n\t}\n\tPoly operator/(const Poly &y) const{\n\t\treturn div_fast(y);\n\
    \t}\n\tPoly operator%(const Poly &y) const{\n\t\treturn rem_fast(y);\n//\t\treturn\
    \ rem_naive(y);\n\t}\n\tPoly operator<<(const int &n) const{\t// *=x^n\n\t\tassert(n>=0);\n\
    \t\tint N=size();\n\t\tvector<D> ret(N+n);\n\t\trep(i,N) ret[i+n]=v[i];\n\t\t\
    return Poly(ret);\n\t}\n\tPoly operator>>(const int &n) const{\t// /=x^n\n\t\t\
    assert(n>=0);\n\t\tint N=size();\n\t\tif(N<=n) return Poly();\n\t\tvector<D> ret(N-n);\n\
    \t\trep(i,N-n) ret[i]=v[i+n];\n\t\treturn Poly(ret);\n\t}\n\tbool operator==(const\
    \ Poly &y) const{\n\t\treturn v==y.v;\n\t}\n\tbool operator!=(const Poly &y) const{\n\
    \t\treturn v!=y.v;\n\t}\n\n\tPoly& operator+=(const Poly &r) {return *this = *this+r;}\n\
    \tPoly& operator-=(const Poly &r) {return *this = *this-r;}\n\tPoly& operator*=(const\
    \ Poly &r) {return *this = *this*r;}\n\tPoly& operator*=(const D &r) {return *this\
    \ = *this*r;}\n\tPoly& operator%=(const Poly &y) {return *this = *this%y;}\n\t\
    Poly& operator<<=(const int &n) {return *this = *this<<n;}\n\tPoly& operator>>=(const\
    \ int &n) {return *this = *this>>n;}\n\n\n\tPoly mul_naive(const Poly &r) const{\n\
    \t\tint N=size(),M=r.size();\n\t\tvector<D> ret(N+M-1);\n\t\trep(i,N) rep(j,M)\
    \ ret[i+j]+=at(i)*r.at(j);\n\t\treturn Poly(ret);\n\t}\n\tPoly mul_ntt(const Poly\
    \ &r) const{\n\t\treturn Poly(multiply_ntt(this->v,r.v));\n\t}\n\tPoly mul_fft(const\
    \ Poly &r) const{\n\t\tvector<D> ret = multiply_fft(v,r.v);\n\t\treturn Poly(ret);\n\
    \t}\n\n\tPoly div_fast_with_inv(const Poly &inv, int B) const {\n\t\treturn (*this\
    \ * inv)>>(B-1);\n\t}\n\tPoly div_fast(const Poly &y) const{\n\t\tif(size()<y.size())\
    \ return Poly();\n\t\tint n = size();\n\t\treturn div_fast_with_inv(y.inv(n),n);\n\
    \t}\n\tPoly rem_naive(const Poly &y) const{\n\t\tPoly x = *this;\n\t\twhile(y.size()<=x.size()){\n\
    \t\t\tint N=x.size(),M=y.size();\n\t\t\tD coef = x.v[N-1]/y.v[M-1];\n\t\t\tx -=\
    \ (y<<(N-M))*coef;\n\t\t}\n\t\treturn x;\n\t}\n\tPoly rem_fast(const Poly &y)\
    \ const{\n\t\treturn *this - y * div_fast(y);\n\t}\n\tPoly strip(int n) const\
    \ {\t//ignore x^n , x^n+1,...\n\t\tvector<D> res = v;\n\t\tres.resize(min(n,size()));\n\
    \t\treturn Poly(res);\n\t}\n\tPoly rev(int n = -1) const {\t//ignore x^n ~  ->\
    \  return x^(n-1) * f(1/x)\n\t\tvector<D> res = v;\n\t\tif(n!=-1) res.resize(n);\n\
    \t\treverse(all(res));\n\t\treturn Poly(res);\n\t}\n\tPoly inv(int n) const{\t\
    \t// f * f.inv() = x^B + r(x) (B>=n)\n\t\tint N = size();\n\t\tassert(N>=1);\t\
    \t//f : non0\n\t\tassert(n>=N-1);\t\t//f = .. + c_{N-1}x^{N-1}\n\t\tD coef = D(1)/at(N-1);\n\
    \t\tPoly a = rev();\n\t\tPoly g(vector<D>(1,coef));\n\t\tfor(int i=1; i+N-2<n;\
    \ i*=2){\t\t//need to strip!!\n\t\t\tg *= (Poly(vector<D>{2})-a*g).strip(2*i);\n\
    \t\t}\n\t\treturn g.rev(n+1-N);\n\t}\n\n\tfriend ostream& operator<<(ostream &o,const\
    \ Poly& x){\n\t\tif(x.size()==0) return o<<0;\n\t\trep(i,x.size()) if(x.v[i]!=D(0)){\n\
    \t\t\to<<x.v[i]<<\"x^\"<<i;\n\t\t\tif(i!=x.size()-1) o<<\" + \";\n\t\t}\n\t\t\
    return o;\n\t}\n};\ntemplate<class D>\nPoly<D> berlekamp_massey(const vector<D>\
    \ &u){\n\tint N = u.size();\n\tvector<D> b = {D(-1)}, c = {D(-1)};\n\tD y = D(1);\n\
    \trep1(n,N){\n\t\tint L = c.size(), M = b.size();\n\t\tD x = 0;\n\t\trep(i,L)\
    \ x += c[i]*u[n-L+i];\n\t\tb.pb(0);\n\t\tM++;\n\t\tif(!x) continue;\n\t\tD coef\
    \ = x/y;\n\t\tif(L<M){\n\t\t\tauto tmp = c;\n\t\t\tc.insert(begin(c),M-L,D(0));\n\
    \t\t\trep(i,M) c[M-1-i] -= coef*b[M-1-i];\n\t\t\tb=tmp;\n\t\t\ty=x;\n\t\t}else{\n\
    \t\t\trep(i,M) c[L-1-i] -= coef*b[M-1-i];\n\t\t}\n\t}\n\treturn Poly<D>(c);\n\
    }\n"
  code: "/*\nBerlekamp-Massey\n\u4F53K\u4E0A\u306En+1\u9805\u9593\u7DDA\u5F62\u6F38\
    \u5316\u5F0F\u304B\u3089\u751F\u6210\u3055\u308C\u308B\u6570\u5217\u306E,\u306F\
    \u3058\u30812n\u9805\u3092\u6E21\u3059\u3068,\u305D\u306E\u7DDA\u5F62\u6F38\u5316\
    \u5F0F(\u3068\u3044\u3046\u304B\u6700\u5C0F\u591A\u9805\u5F0F)\u3092\u6C42\u3081\
    \u3066\u304F\u308C\u308B\n\u4F8B\u3048\u3070fib\u306A\u30894\u9805\u5FC5\u8981\
    .\ninput \u3092 u , N\u9805 \u3068\u3057\u3066 output \u3092 c \u3068\u3059\u308B\
    \u3068\nfor all j < N-K,\nc_0 * u_j + c_1 * u_{j+1} + .. + c_K * u_{j+K} = 0\n\
    \u3068\u306A\u308B.\nO(N^2)\n\nfft,poly,mint \u3068\u304B\u304C\u3044\u308B\n\
    main\u95A2\u6570\u3088\u308A\u4E0B\u306B\u307E\u308B\u3054\u3068\u8CBC\u3063\u3066\
    \u3042\u308B\u306E\u3067mint\u3067\u4F7F\u3046\u3068\u304D\u306F\u3053\u3063\u304B\
    \u3089\u30B3\u30D4\u30FC\u3059\u308B\n!! mod \u306E\u5024\u3092\u5909\u3048\u308B\
    \ !!\n\nN\u9805\u76EE\u3092\u6C42\u3081\u305F\u3044\u3068\u304D\u306F\u3001x^N\
    \ \u3092 \u3053\u306E\u591A\u9805\u5F0F\u3067\u5272\u308B\n\u307E\u3042typicalDP/T.cpp\
    \ \u3068\u304B\u306B\u3042\u308B\u3093\u3067\u3059\u3051\u3069, \u4E00\u822C\u7684\
    \u306A\u51E6\u7406\u306F\n\tvector<mint> vals = {0,1,1,2};\n\tauto mod = berlekamp_massey(vals);\n\
    \n\tPoly<mint> a = vector<mint>{1};\n\tPoly<mint> x = vector<mint>{0,1};\n\n\t\
    long long N;\n\tcin>>N;\n\twhile(N){\n\t\tif(N%2) (a*=x)%=mod;\n\t\tx*=x;\n\t\t\
    x%=mod;\n\t\tN/=2;\n\t}\n\tmint ans=0;\n\tint K = mod.size();\n\trep(i,K) ans+=a.at(i)*vals[i];\n\
    \tcout<<ans<<endl;\n\n\t\u3067\u3059\n\n*/\n#include <bits/stdc++.h>\n#define\
    \ rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<\"(\"\
    <<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class T> ostream& operator<<(ostream& o,const\
    \ vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"[\";for(const T& v:vc) o<<v<<\"\
    ,\";o<<\"]\";return o;}\n\n\ntemplate<class D>\nPoly<D> berlekamp_massey(const\
    \ vector<D> &u){\n\tint N = u.size();\n\tvector<D> b = {D(-1)}, c = {D(-1)};\n\
    \tD y = D(1);\n\trep1(n,N){\n\t\tint L = c.size(), M = b.size();\n\t\tD x = 0;\n\
    \t\trep(i,L) x += c[i]*u[n-L+i];\n\t\tb.pb(0);\n\t\tM++;\n\t\tif(!x) continue;\n\
    \t\tD coef = x/y;\n\t\tif(L<M){\n\t\t\tauto tmp = c;\n\t\t\tc.insert(begin(c),M-L,D(0));\n\
    \t\t\trep(i,M) c[M-1-i] -= coef*b[M-1-i];\n\t\t\tb=tmp;\n\t\t\ty=x;\n\t\t}else{\n\
    \t\t\trep(i,M) c[L-1-i] -= coef*b[M-1-i];\n\t\t}\n\t}\n\treturn Poly<D>(c);\n\
    }\n\nint main(){\n\tvector<int> fib({0,1,1,2,3,5,8});\n\t//0,1,1,2 \u307E\u3067\
    \u306F\u5FC5\u8981\n\tvector<int> hoge({0,1,2,-1,5,-2,5,3});\t//\t\t2 a_i + a_i+1\
    \ - a_i+2 - a_i+3 = 0\n\t//-2\u307E\u3067\u306F\u5FC5\u8981\n\tauto c = berlekamp_massey(hoge);\t\
    // return\t2 x^0 +   x^1 -   x^2 -   x^3\n\tshow(c);\n}\n\n\ntemplate<class T>\
    \ using V = vector<T>;\ntemplate<class T> using VV = vector<vector<T>>;\ntemplate<unsigned\
    \ int mod_>\nstruct ModInt{\n\tusing uint = unsigned int;\n\tusing ll = long long;\n\
    \tusing ull = unsigned long long;\n\n\tconstexpr static uint mod = mod_;\n\n\t\
    uint v;\n\tModInt():v(0){}\n\tModInt(ll v):v(normS(v%mod+mod)){}\n\texplicit operator\
    \ bool() const {return v!=0;}\n\tstatic uint normS(const uint &x){return (x<mod)?x:x-mod;}\t\
    \t// [0 , 2*mod-1] -> [0 , mod-1]\n\tstatic ModInt make(const uint &x){ModInt\
    \ m; m.v=x; return m;}\n\tModInt operator+(const ModInt& b) const { return make(normS(v+b.v));}\n\
    \tModInt operator-(const ModInt& b) const { return make(normS(v+mod-b.v));}\n\t\
    ModInt operator-() const { return make(normS(mod-v)); }\n\tModInt operator*(const\
    \ ModInt& b) const { return make((ull)v*b.v%mod);}\n\tModInt operator/(const ModInt&\
    \ b) const { return *this*b.inv();}\n\tModInt& operator+=(const ModInt& b){ return\
    \ *this=*this+b;}\n\tModInt& operator-=(const ModInt& b){ return *this=*this-b;}\n\
    \tModInt& operator*=(const ModInt& b){ return *this=*this*b;}\n\tModInt& operator/=(const\
    \ ModInt& b){ return *this=*this/b;}\n\tll extgcd(ll a,ll b,ll &x,ll &y) const{\n\
    \t\tll u[]={a,1,0},v[]={b,0,1};\n\t\twhile(*v){\n\t\t\tll t=*u/ *v;\n\t\t\trep(i,3)\
    \ swap(u[i]-=t*v[i],v[i]);\n\t\t}\n\t\tif(u[0]<0) rep(i,3) u[i]=-u[i];\n\t\tx=u[1],y=u[2];\n\
    \t\treturn u[0];\n\t}\n\tModInt inv() const{\n\t\tll x,y;\n\t\textgcd(v,mod,x,y);\n\
    \t\treturn make(normS(x+mod));\n\t}\n\tbool operator==(const ModInt& b) const\
    \ { return v==b.v;}\n\tbool operator!=(const ModInt& b) const { return v!=b.v;}\n\
    \tfriend istream& operator>>(istream &o,ModInt& x){\n\t\tll tmp;\n\t\to>>tmp;\n\
    \t\tx=ModInt(tmp);\n\t\treturn o;\n\t}\n\tfriend ostream& operator<<(ostream &o,const\
    \ ModInt& x){ return o<<x.v;}\n};\nusing mint = ModInt<>;\n\nint bsr(int x) {\
    \ return 31 - __builtin_clz(x); }\nusing D = double;\nconst D pi = acos(-1);\n\
    using Pc = complex<D>;\n\nvoid fft(bool type, vector<Pc> &c){\t//multiply : false\
    \ -> mult -> true\n\tstatic vector<Pc> buf[30];\n\tint N = c.size();\n\tint s\
    \ = bsr(N);\n\tassert(1<<s == N);\n\tif(buf[s].empty()){\n\t\tbuf[s]=vector<Pc>(N);\n\
    \t\trep(i,N) buf[s][i] = polar<D>(1,i*2*pi/N);\n\t}\n\tvector<Pc> a(N),b(N);\n\
    \tcopy(begin(c),end(c),begin(a));\n\trep1(i,s){\n\t\tint W = 1<<(s-i);\n\t\tfor(int\
    \ y=0;y<N/2;y+=W){\n\t\t\tPc now = buf[s][y];\n\t\t\tif(type) now = conj(now);\n\
    \t\t\trep(x,W){\n\t\t\t\tauto l =       a[y<<1 | x];\n\t\t\t\tauto r = now * a[y<<1\
    \ | x | W];\n\t\t\t\tb[y | x]        = l+r;\n\t\t\t\tb[y | x | N>>1] = l-r;\n\t\
    \t\t}\n\t\t}\n\t\tswap(a,b);\n\t}\n\tcopy(begin(a),end(a),begin(c));\n}\ntemplate<class\
    \ Mint>\nvector<Mint> multiply_fft2(const vector<Mint>& x,const vector<Mint>&\
    \ y){\n\tconst int B = 15;\n\tint S = x.size()+y.size()-1;\n\tint N = 2<<bsr(S-1);\n\
    \tvector<Pc> a[2],b[2];\n\trep(t,2){\n\t\ta[t] = vector<Pc>(N);\n\t\tb[t] = vector<Pc>(N);\n\
    \t\trep(i,x.size()) a[t][i] = Pc( (x[i].v >> (t*B)) & ((1<<B)-1) , 0 );\n\t\t\
    rep(i,y.size()) b[t][i] = Pc( (y[i].v >> (t*B)) & ((1<<B)-1) , 0 );\n\t\tfft(false,a[t]);\n\
    \t\tfft(false,b[t]);\n\t}\n\tvector<Mint> z(S);\n\tvector<Pc> c(N);\n\tMint base\
    \ = 1;\n\trep(t,3){\n\t\tfill_n(begin(c),N,Pc(0,0));\n\t\tfor(int xt = max(t-1,0);\
    \ xt<=min(1,t); xt++){\n\t\t\tint yt = t-xt;\n\t\t\trep(i,N) c[i] += a[xt][i]*b[yt][i];\n\
    \t\t}\n\t\tfft(true,c);\n\t\trep(i,S){\n\t\t\tc[i] *= 1.0/N;\n\t\t\tz[i] += Mint(ll(round(c[i].real())))\
    \ * base;\n\t\t}\n\t\tbase *= 1<<B;\n\t}\n\treturn z;\n}\ntemplate<class Mint>\n\
    vector<Mint> multiply_fft(const vector<Mint>& x,const vector<Mint>& y){\n\treturn\
    \ multiply_fft2(x,y);\n}\n\n\ntemplate<class D>\nstruct Poly{\n\tvector<D> v;\n\
    \tint size() const{ return v.size();}\t//deg+1\n\tPoly(int N=0) : v(vector<D>(N)){}\n\
    \tPoly(vector<D> v) : v(v){shrink();}\n\n\tPoly& shrink(){\n\t\twhile(!v.empty()&&v.back()==D(0))\
    \ v.pop_back();\t//double? iszero\u3092global\u306B\u7528\u610F\u3057\u305F\u307B\
    \u3046\u304C\u3044\u3044\u304B\u306A\n\t\treturn *this;\n\t}\n\tD at(int i) const{\n\
    \t\treturn (i<size())?v[i]:D(0);\n\t}\n\tvoid set(int i,const D& x){\t\t//v[i]\
    \ := x\n\t\tif(i>=size() && !x) return;\n\t\twhile(i>=size()) v.push_back(D(0));\n\
    \t\tv[i]=x;\n\t\tshrink();\n\t\treturn;\n\t}\n\t\n\tPoly operator+(const Poly\
    \ &r) const{\n\t\tint N=max(size(),r.size());\n\t\tvector<D> ret(N);\n\t\trep(i,N)\
    \ ret[i]=at(i)+r.at(i);\n\t\treturn Poly(ret);\n\t}\n\tPoly operator-(const Poly\
    \ &r) const{\n\t\tint N=max(size(),r.size());\n\t\tvector<D> ret(N);\n\t\trep(i,N)\
    \ ret[i]=at(i)-r.at(i);\n\t\treturn Poly(ret);\n\t}\n\tPoly operator-() const{\n\
    \t\tint N=size();\n\t\tvector<D> ret(N);\n\t\trep(i,N) ret[i] = -at(i);\n\t\t\
    return Poly(ret);\n\t}\n\tPoly operator*(const Poly &r) const{\n\t\tif(size()==0||r.size()==0)\
    \ return Poly();\n\t\treturn mul_fft(r);\n\t}\n\tPoly operator*(const D &r) const{\n\
    \t\tint N=size();\n\t\tvector<D> ret(N);\n\t\trep(i,N) ret[i]=v[i]*r;\n\t\treturn\
    \ Poly(ret);\n\t}\n\tPoly operator/(const Poly &y) const{\n\t\treturn div_fast(y);\n\
    \t}\n\tPoly operator%(const Poly &y) const{\n\t\treturn rem_fast(y);\n//\t\treturn\
    \ rem_naive(y);\n\t}\n\tPoly operator<<(const int &n) const{\t// *=x^n\n\t\tassert(n>=0);\n\
    \t\tint N=size();\n\t\tvector<D> ret(N+n);\n\t\trep(i,N) ret[i+n]=v[i];\n\t\t\
    return Poly(ret);\n\t}\n\tPoly operator>>(const int &n) const{\t// /=x^n\n\t\t\
    assert(n>=0);\n\t\tint N=size();\n\t\tif(N<=n) return Poly();\n\t\tvector<D> ret(N-n);\n\
    \t\trep(i,N-n) ret[i]=v[i+n];\n\t\treturn Poly(ret);\n\t}\n\tbool operator==(const\
    \ Poly &y) const{\n\t\treturn v==y.v;\n\t}\n\tbool operator!=(const Poly &y) const{\n\
    \t\treturn v!=y.v;\n\t}\n\n\tPoly& operator+=(const Poly &r) {return *this = *this+r;}\n\
    \tPoly& operator-=(const Poly &r) {return *this = *this-r;}\n\tPoly& operator*=(const\
    \ Poly &r) {return *this = *this*r;}\n\tPoly& operator*=(const D &r) {return *this\
    \ = *this*r;}\n\tPoly& operator%=(const Poly &y) {return *this = *this%y;}\n\t\
    Poly& operator<<=(const int &n) {return *this = *this<<n;}\n\tPoly& operator>>=(const\
    \ int &n) {return *this = *this>>n;}\n\n\n\tPoly mul_naive(const Poly &r) const{\n\
    \t\tint N=size(),M=r.size();\n\t\tvector<D> ret(N+M-1);\n\t\trep(i,N) rep(j,M)\
    \ ret[i+j]+=at(i)*r.at(j);\n\t\treturn Poly(ret);\n\t}\n\tPoly mul_ntt(const Poly\
    \ &r) const{\n\t\treturn Poly(multiply_ntt(this->v,r.v));\n\t}\n\tPoly mul_fft(const\
    \ Poly &r) const{\n\t\tvector<D> ret = multiply_fft(v,r.v);\n\t\treturn Poly(ret);\n\
    \t}\n\n\tPoly div_fast_with_inv(const Poly &inv, int B) const {\n\t\treturn (*this\
    \ * inv)>>(B-1);\n\t}\n\tPoly div_fast(const Poly &y) const{\n\t\tif(size()<y.size())\
    \ return Poly();\n\t\tint n = size();\n\t\treturn div_fast_with_inv(y.inv(n),n);\n\
    \t}\n\tPoly rem_naive(const Poly &y) const{\n\t\tPoly x = *this;\n\t\twhile(y.size()<=x.size()){\n\
    \t\t\tint N=x.size(),M=y.size();\n\t\t\tD coef = x.v[N-1]/y.v[M-1];\n\t\t\tx -=\
    \ (y<<(N-M))*coef;\n\t\t}\n\t\treturn x;\n\t}\n\tPoly rem_fast(const Poly &y)\
    \ const{\n\t\treturn *this - y * div_fast(y);\n\t}\n\tPoly strip(int n) const\
    \ {\t//ignore x^n , x^n+1,...\n\t\tvector<D> res = v;\n\t\tres.resize(min(n,size()));\n\
    \t\treturn Poly(res);\n\t}\n\tPoly rev(int n = -1) const {\t//ignore x^n ~  ->\
    \  return x^(n-1) * f(1/x)\n\t\tvector<D> res = v;\n\t\tif(n!=-1) res.resize(n);\n\
    \t\treverse(all(res));\n\t\treturn Poly(res);\n\t}\n\tPoly inv(int n) const{\t\
    \t// f * f.inv() = x^B + r(x) (B>=n)\n\t\tint N = size();\n\t\tassert(N>=1);\t\
    \t//f : non0\n\t\tassert(n>=N-1);\t\t//f = .. + c_{N-1}x^{N-1}\n\t\tD coef = D(1)/at(N-1);\n\
    \t\tPoly a = rev();\n\t\tPoly g(vector<D>(1,coef));\n\t\tfor(int i=1; i+N-2<n;\
    \ i*=2){\t\t//need to strip!!\n\t\t\tg *= (Poly(vector<D>{2})-a*g).strip(2*i);\n\
    \t\t}\n\t\treturn g.rev(n+1-N);\n\t}\n\n\tfriend ostream& operator<<(ostream &o,const\
    \ Poly& x){\n\t\tif(x.size()==0) return o<<0;\n\t\trep(i,x.size()) if(x.v[i]!=D(0)){\n\
    \t\t\to<<x.v[i]<<\"x^\"<<i;\n\t\t\tif(i!=x.size()-1) o<<\" + \";\n\t\t}\n\t\t\
    return o;\n\t}\n};\ntemplate<class D>\nPoly<D> berlekamp_massey(const vector<D>\
    \ &u){\n\tint N = u.size();\n\tvector<D> b = {D(-1)}, c = {D(-1)};\n\tD y = D(1);\n\
    \trep1(n,N){\n\t\tint L = c.size(), M = b.size();\n\t\tD x = 0;\n\t\trep(i,L)\
    \ x += c[i]*u[n-L+i];\n\t\tb.pb(0);\n\t\tM++;\n\t\tif(!x) continue;\n\t\tD coef\
    \ = x/y;\n\t\tif(L<M){\n\t\t\tauto tmp = c;\n\t\t\tc.insert(begin(c),M-L,D(0));\n\
    \t\t\trep(i,M) c[M-1-i] -= coef*b[M-1-i];\n\t\t\tb=tmp;\n\t\t\ty=x;\n\t\t}else{\n\
    \t\t\trep(i,M) c[L-1-i] -= coef*b[M-1-i];\n\t\t}\n\t}\n\treturn Poly<D>(c);\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/berlekamp-massey.cpp
  requiredBy: []
  timestamp: '2018-09-18 03:14:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/berlekamp-massey.cpp
layout: document
redirect_from:
- /library/math/berlekamp-massey.cpp
- /library/math/berlekamp-massey.cpp.html
title: math/berlekamp-massey.cpp
---
