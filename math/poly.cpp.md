---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/438/problem/E
    - https://official.contest.yandex.com/ptz-winter-2019/contest/11818/problems/G1/
  bundledCode: "#line 1 \"math/poly.cpp\"\n/*\n\n\u30E1\u30E2\uFF1A constructor (int\
    \ n) \u3092\u5165\u308C\u308B\u3068 Poly<mint>({2}) \u3068\u304B\u3067\u7834\u58CA\
    \u3055\u308C\u308B\ninitializer list? \n Poly() {}\n  explicit Poly(int n) : vector<Mint>(n)\
    \ {}\n  Poly(const vector<Mint> &vec) : vector<Mint>(vec) {}\n  Poly(std::initializer_list<Mint>\
    \ il) : vector<Mint>(il) {}\n\n\u308F\u304B\u3093\u306D\n\u3081\u3082\u304A\u308F\
    \u308A\n\n\u4F9D\u5B58\u95A2\u4FC2 : mint,fft(ntt)\n\n\n\u591A\u9805\u5F0F.\n\
    shrink()\u3067leading-0\u3092\u53D6\u308A\u9664\u304D,\u5E38\u306B\u3053\u306E\
    \u610F\u5473\u3067\u306E\u6B63\u898F\u7CFB\u3092\u5024\u3068\u3057\u3066\u6301\
    \u3064.\n\u305D\u306E\u610F\u5473\u3067int\u3068mint\u4EE5\u5916\u306F\u307E\u3042\
    \u307E\u3042\u307E\u305A\u3044\u304B\u306A\n\u3067\u3082+-\u3068\u304B\u7C21\u5358\
    \u306A\u306E\u306F\u51FA\u6765\u308B(\u3044\u308B\u304B?)\n\n\u5272\u308A\u7B97\
    \u3082 O(NlogN) \u3060\u304CN\u304C\u5C0F\u3055\u3044\u6642\u9045\u3044\u306E\u3067\
    \u5206\u5272\u7D71\u6CBB\u307F\u305F\u3044\u306A\u3053\u3068\u3092\u3059\u308B\
    \u3068\u304D\u306F\u6CE8\u610F\n\ninv(N),exp(N),log(N),sqrt(N) : N\u6B21\u307E\
    \u3067\u3092\u8FD4\u3059\ndiff / intg : \u5FAE\u7A4D\n\nverified: \u3042\u308A\
    \u3059\u304E\u3066\u5FD8\u308C\u305F\n\thttps://codeforces.com/contest/438/problem/E\
    \ (sqrt,inv)\n\thttps://official.contest.yandex.com/ptz-winter-2019/contest/11818/problems/G1/\
    \ (exp,log)\n\n\u8A08\u6E2C:\n\t-O2\n\n\tfft2 *\n\t- N = 100000\n\t141 [ms]\n\t\
    - N = 200000\n\t279 [ms]\n\t- N = 500000\n\t595 [ms]\n\t- N = 1000000\n\t1186\
    \ [ms]\n\n\tfft2 N % N/4 \u304F\u3089\u3044 \u5272\u308B\u5074\u306E\u6B21\u6570\
    \u306F\u3053\u308C\u304F\u3089\u3044\u304C\u4E00\u756A\u9045\u3044\u6C17\u304C\
    \u3059\u308B\n\t- N = 10000\n\t44 [ms]\n\t- N = 100000\n\t643 [ms]\n\t- N = 200000\n\
    \t1340 [ms]\n\t- N = 500000\n\t3033 [ms]\n\t- N = 1000000\n\t5875 [ms]\n\n\tntt\
    \ * \n\t- N = 1000000\n\t231 [ms]\n\n\tntt N % N/4\n\t- N = 200000\n\t147 [ms]\n\
    \t- N = 500000\n\t310 [ms]\n\t- N = 1000000\n\t646 [ms]\n\n*/\n\n#include <bits/stdc++.h>\n\
    #define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) cout << #x << \" = \" << (x) << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){\n\treturn o<<\"\
    (\"<<p.fs<<\",\"<<p.sc<<\")\";\n}\ntemplate<class T> ostream& operator<<(ostream&\
    \ o,const vector<T> &vc){\n\to<<\"{\";\n\tfor(const T& v:vc) o<<v<<\",\";\n\t\
    o<<\"}\";\n\treturn o;\n}\nusing ll = long long;\ntemplate<class T> using V =\
    \ vector<T>;\ntemplate<class T> using VV = vector<vector<T>>;\n\ntemplate<unsigned\
    \ int mod_>\nstruct ModInt{\n\tusing uint = unsigned int;\n\tusing ll = long long;\n\
    \tusing ull = unsigned long long;\n\n\tconstexpr static uint mod = mod_;\n\n\t\
    uint v;\n\tModInt():v(0){}\n\tModInt(ll _v):v(normS(_v%mod+mod)){}\n\texplicit\
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
    \tModInt& operator++(int){ return *this=*this+1;}\n\tModInt& operator--(int){\
    \ return *this=*this-1;}\n\tll extgcd(ll a,ll b,ll &x,ll &y) const{\n\t\tll p[]={a,1,0},q[]={b,0,1};\n\
    \t\twhile(*q){\n\t\t\tll t=*p/ *q;\n\t\t\trep(i,3) swap(p[i]-=t*q[i],q[i]);\n\t\
    \t}\n\t\tif(p[0]<0) rep(i,3) p[i]=-p[i];\n\t\tx=p[1],y=p[2];\n\t\treturn p[0];\n\
    \t}\n\tModInt inv() const {\n\t\tll x,y;\n\t\textgcd(v,mod,x,y);\n\t\treturn make(normS(x+mod));\n\
    \t}\n\tModInt pow(ll p) const {\n\t\tModInt a = 1;\n\t\tModInt x = *this;\n\t\t\
    while(p){\n\t\t\tif(p&1) a *= x;\n\t\t\tx *= x;\n\t\t\tp >>= 1;\n\t\t}\n\t\treturn\
    \ a;\n\t}\n\tbool operator==(const ModInt& b) const { return v==b.v;}\n\tbool\
    \ operator!=(const ModInt& b) const { return v!=b.v;}\n\tfriend istream& operator>>(istream\
    \ &o,ModInt& x){\n\t\tll tmp;\n\t\to>>tmp;\n\t\tx=ModInt(tmp);\n\t\treturn o;\n\
    \t}\n\tfriend ostream& operator<<(ostream &o,const ModInt& x){ return o<<x.v;}\n\
    };\nusing mint = ModInt<998244353>;\n\nint bsr(int x) { return 31 - __builtin_clz(x);\
    \ }\nvoid ntt(bool type, V<mint>& c) {\n\tconst mint G = 3;\t//primitive root\n\
    \n\tint N = int(c.size());\n\tint s = bsr(N);\n\tassert(1 << s == N);\n\n\tV<mint>\
    \ a = c, b(N);\n\trep1(i,s){\n\t\tint W = 1 << (s - i);\n\t\tmint base = G.pow((mint::mod\
    \ - 1)>>i);\n\t\tif(type) base = base.inv();\n\t\tmint now = 1;\n\t\tfor(int y\
    \ = 0; y < N / 2; y += W) {\n\t\t\tfor (int x = 0; x < W; x++) {\n\t\t\t\tauto\
    \ l = a[y << 1 | x];\n\t\t\t\tauto r = now * a[y << 1 | x | W];\n\t\t\t\tb[y |\
    \ x] = l + r;\n\t\t\t\tb[y | x | N >> 1] = l - r;\n\t\t\t}\n\t\t\tnow *= base;\n\
    \t\t}\n\t\tswap(a, b);\n\t}\n\tc = a;\n}\n\nV<mint> multiply_ntt(const V<mint>&\
    \ a, const V<mint>& b) {\n\tint A = int(a.size()), B = int(b.size());\n\tif (!A\
    \ || !B) return {};\n\tint lg = 0;\n\twhile ((1 << lg) < A + B - 1) lg++;\n\t\
    int N = 1 << lg;\n\tV<mint> ac(N), bc(N);\n\tfor (int i = 0; i < A; i++) ac[i]\
    \ = a[i];\n\tfor (int i = 0; i < B; i++) bc[i] = b[i];\n\tntt(false, ac);\n\t\
    ntt(false, bc);\n\tfor (int i = 0; i < N; i++) {\n\t\tac[i] *= bc[i];\n\t}\n\t\
    ntt(true, ac);\n\tV<mint> c(A + B - 1);\n\tmint iN = mint(N).inv();\n\tfor (int\
    \ i = 0; i < A + B - 1; i++) {\n\t\tc[i] = ac[i] * iN;\n\t}\n\treturn c;\n}\n\n\
    template<class D>\nstruct Poly{\n\tvector<D> v;\n\tint size() const{ return v.size();}\t\
    //deg+1\n\tPoly(){}\n\tPoly(vector<D> _v) : v(_v){shrink();}\n\n\tPoly& shrink(){\n\
    \t\twhile(!v.empty()&&v.back()==D(0)) v.pop_back();\n\t\treturn *this;\n\t}\n\t\
    D& operator[](int i){return v[i];}\n\tconst D& operator[](int i) const {return\
    \ v[i];}\n\tD at(int i) const{\n\t\treturn (i<size())?v[i]:D(0);\n\t}\n\tvoid\
    \ set(int i,const D& x){\t\t//v[i] := x\n\t\tif(i>=size() && !x) return;\n\t\t\
    while(i>=size()) v.push_back(D(0));\n\t\tv[i]=x;\n\t\tshrink();\n\t\treturn;\n\
    \t}\n\tD operator()(D x) const {\n\t\tD res = 0;\n\t\tint n = size();\n\t\tD a\
    \ = 1;\n\t\trep(i,n){\n\t\t\tres += a*v[i];\n\t\t\ta *= x;\n\t\t}\n\t\treturn\
    \ res;\n\t}\n\n\tPoly operator+(const Poly &r) const{\n\t\tint N=max(size(),r.size());\n\
    \t\tvector<D> ret(N);\n\t\trep(i,N) ret[i]=at(i)+r.at(i);\n\t\treturn Poly(ret);\n\
    \t}\n\tPoly operator-(const Poly &r) const{\n\t\tint N=max(size(),r.size());\n\
    \t\tvector<D> ret(N);\n\t\trep(i,N) ret[i]=at(i)-r.at(i);\n\t\treturn Poly(ret);\n\
    \t}\n\tPoly operator-() const{\n\t\tint N=size();\n\t\tvector<D> ret(N);\n\t\t\
    rep(i,N) ret[i] = -at(i);\n\t\treturn Poly(ret);\n\t}\n\tPoly operator*(const\
    \ Poly &r) const{\n\t\tif(size()==0||r.size()==0) return Poly();\n\t\treturn mul_ntt(r);\t\
    \t\t\t\t\t\t\t\t// FFT or NTT ?\n\t}\n\tPoly operator*(const D &r) const{\n\t\t\
    int N=size();\n\t\tvector<D> ret(N);\n\t\trep(i,N) ret[i]=v[i]*r;\n\t\treturn\
    \ Poly(ret);\n\t}\n\tPoly operator/(const D &r) const{\n\t\treturn *this * r.inv();\n\
    \t}\n\tPoly operator/(const Poly &y) const{\n\t\treturn div_fast(y);\n\t}\n\t\
    Poly operator%(const Poly &y) const{\n\t\treturn rem_fast(y);\n//\t\treturn rem_naive(y);\n\
    \t}\n\tPoly operator<<(const int &n) const{\t// *=x^n\n\t\tassert(n>=0);\n\t\t\
    int N=size();\n\t\tvector<D> ret(N+n);\n\t\trep(i,N) ret[i+n]=v[i];\n\t\treturn\
    \ Poly(ret);\n\t}\n\tPoly operator>>(const int &n) const{\t// /=x^n\n\t\tassert(n>=0);\n\
    \t\tint N=size();\n\t\tif(N<=n) return Poly();\n\t\tvector<D> ret(N-n);\n\t\t\
    rep(i,N-n) ret[i]=v[i+n];\n\t\treturn Poly(ret);\n\t}\n\tbool operator==(const\
    \ Poly &y) const{\n\t\treturn v==y.v;\n\t}\n\tbool operator!=(const Poly &y) const{\n\
    \t\treturn v!=y.v;\n\t}\n\n\tPoly& operator+=(const Poly &r) {return *this = *this+r;}\n\
    \tPoly& operator-=(const Poly &r) {return *this = *this-r;}\n\tPoly& operator*=(const\
    \ Poly &r) {return *this = *this*r;}\n\tPoly& operator*=(const D &r) {return *this\
    \ = *this*r;}\n\tPoly& operator/=(const Poly &r) {return *this = *this/r;}\n\t\
    Poly& operator/=(const D &r) {return *this = *this/r;}\n\tPoly& operator%=(const\
    \ Poly &y) {return *this = *this%y;}\n\tPoly& operator<<=(const int &n) {return\
    \ *this = *this<<n;}\n\tPoly& operator>>=(const int &n) {return *this = *this>>n;}\n\
    \n\tPoly diff() const {\n\t\tint n = size();\n\t\tif(n == 0) return Poly();\n\t\
    \tV<D> u(n-1);\n\t\trep(i,n-1) u[i] = at(i+1) * (i+1);\n\t\treturn Poly(u);\n\t\
    }\n\tPoly intg() const {\n\t\tint n = size();\n\t\tV<D> u(n+1);\n\t\trep(i,n)\
    \ u[i+1] = at(i) / (i+1);\n\t\treturn Poly(u);\n\t}\n\n\tPoly pow(long long n,\
    \ int L) const {\t\t// f^n, ignoring x^L,x^{L+1},..\n\t\tPoly a({1});\n\t\tPoly\
    \ x = *this;\n\t\twhile(n){\n\t\t\tif(n&1){\n\t\t\t\ta *= x;\n\t\t\t\ta = a.strip(L);\n\
    \t\t\t}\n\t\t\tx *= x;\n\t\t\tx = x.strip(L);\n\t\t\tn /= 2;\n\t\t}\n\t\treturn\
    \ a;\n\t}\n\n\t/*\n\t\t[x^0~n] exp(f) = 1 + f + f^2 / 2 + f^3 / 6 + ..\n\t\tf(0)\
    \ should be 0\n\n\t\tO((N+n) log n)\t(N = size())\n\t\tNTT, -O3\n\t\t- N = n =\
    \ 100000 : 200 [ms]\n\t\t- N = n = 200000 : 400 [ms]\n\t\t- N = n = 500000 : 1000\
    \ [ms]\n\t*/\n\tPoly exp(int n) const {\n\t\tassert(at(0) == 0);\n\t\tPoly f({1}),\
    \ g({1});\n\t\tfor(int i=1;i<=n;i*=2){\n\t\t\tg = (g*2 - f*g*g).strip(i);\n\t\t\
    \tPoly q = (this->diff()).strip(i-1);\n\t\t\tPoly w = (q + g * (f.diff() - f*q))\
    \ .strip(2*i-1);\n\t\t\tf = (f + f * (*this - w.intg()).strip(2*i)) .strip(2*i);\n\
    \t\t}\n\t\treturn f.strip(n+1);\n\t}\n\n\t/*\n\t\t[x^0~n] log(f) = log(1-(1-f))\
    \ = - (1-f) - (1-f)^2 / 2 - (1-f)^3 / 3 - ...\n\t\tf(0) should be 1\n\t\tO(n log\
    \ n)\n\n\t\tNTT, -O3\n\t\t1e5 : 140 [ms]\n\t\t2e5 : 296 [ms]\n\t\t5e5 : 640 [ms]\n\
    \t\t1e6 : 1343 [ms]\n\t*/\n\tPoly log(int n) const {\n\t\tassert(at(0) == 1);\n\
    \t\tauto f = strip(n+1);\n\t\treturn (f.diff() * f.inv(n)).strip(n).intg();\n\t\
    }\n\n\t/*\n\t\t[x^0~n] sqrt(f)\n\t\tf(0) should be 1\n\t\t\u3044\u3084\u5E73\u65B9\
    \u5270\u4F59\u306A\u3089\u4F55\u3067\u3082\u3044\u3044\u3068\u601D\u3046\u3051\
    \u3069\u63A2\u3059\u306E\u304C\u3081\u3093\u3069\u304F\u3055\u3044\u306E\u3067\
    \n\t\t+- 2\u901A\u308A\u3060\u3051\u3069 \u5B9A\u6570\u9805\u304C 1 \u306E\u65B9\
    \n\t\tO(n log n)\n\n\t\tNTT, -O3\n\t\t1e5 : 234 [ms]\n\t\t2e5 : 484 [ms]\n\t\t\
    5e5 : 1000 [ms]\n\t\t1e6 : 2109 [ms]\n\t*/\n\tPoly sqrt(int n) const {\n\t\tassert(at(0)\
    \ == 1);\n\t\tPoly f = strip(n+1);\n\t\tPoly g({1});\n\t\tfor(int i=1; i<=n; i*=2){\n\
    \t\t\tg = (g + f.strip(2*i)*g.inv(2*i-1)) / 2;\n\t\t}\n\t\treturn g.strip(n+1);\n\
    \t}\n\n\t/*\n\t\t[x^0~n] f^-1 = (1-(1-f))^-1 = (1-f) + (1-f)^2 + ...\n\t\tf *\
    \ f.inv(n) = 1 + x^n * poly\n\t\tf(0) should be non0\n\t\tO(n log n)\n\t*/\n\t\
    Poly inv(int n) const {\n\t\tassert(at(0) != 0);\n\t\tPoly f = strip(n+1);\n\t\
    \tPoly g({at(0).inv()});\n\t\tfor(int i=1; i<=n; i*=2){\t\t//need to strip!!\n\
    \t\t\tg *= (Poly({2}) - f.strip(2*i)*g).strip(2*i);\n\t\t}\n\t\treturn g.strip(n+1);\n\
    \t}\t\n\n\tPoly exp_naive(int n) const {\n\t\tassert(at(0) == 0);\n\t\tPoly res;\n\
    \t\tPoly fk({1});\n\t\trep(k,n+1){\n\t\t\tres += fk;\n\t\t\tfk *= *this;\n\t\t\
    \tfk = fk.strip(n+1) / (k+1);\n\t\t}\n\t\treturn res;\n\t}\n\tPoly log_naive(int\
    \ n) const {\n\t\tassert(at(0) == 1);\n\t\tPoly res;\n\t\tPoly g({1});\n\t\trep1(k,n){\n\
    \t\t\tg *= (Poly({1}) - *this);\n\t\t\tg = g.strip(n+1);\n\t\t\tres -= g / k;\n\
    \t\t}\n\t\treturn res;\n\t}\n\n\n\tPoly mul_naive(const Poly &r) const{\n\t\t\
    int N=size(),M=r.size();\n\t\tvector<D> ret(N+M-1);\n\t\trep(i,N) rep(j,M) ret[i+j]+=at(i)*r.at(j);\n\
    \t\treturn Poly(ret);\n\t}\n\tPoly mul_ntt(const Poly &r) const{\n\t\treturn Poly(multiply_ntt(v,r.v));\n\
    \t}\n\tPoly mul_fft(const Poly &r) const{\n\t\treturn Poly(multiply_fft(v,r.v));\n\
    \t}\n\n\tPoly div_fast_with_inv(const Poly &inv, int B) const {\n\t\treturn (*this\
    \ * inv)>>(B-1);\n\t}\n\tPoly div_fast(const Poly &y) const{\n\t\tif(size()<y.size())\
    \ return Poly();\n\t\tint n = size();\n\t\treturn div_fast_with_inv(y.inv_div(n-1),n);\n\
    \t}\n\tPoly rem_naive(const Poly &y) const{\n\t\tPoly x = *this;\n\t\twhile(y.size()<=x.size()){\n\
    \t\t\tint N=x.size(),M=y.size();\n\t\t\tD coef = x.v[N-1]/y.v[M-1];\n\t\t\tx -=\
    \ (y<<(N-M))*coef;\n\t\t}\n\t\treturn x;\n\t}\n\tPoly rem_fast(const Poly &y)\
    \ const{\n\t\treturn *this - y * div_fast(y);\n\t}\n\tPoly strip(int n) const\
    \ {\t//ignore x^n , x^n+1,...\n\t\tvector<D> res = v;\n\t\tres.resize(min(n,size()));\n\
    \t\treturn Poly(res);\n\t}\n\tPoly rev(int n = -1) const {\t//ignore x^n ~  ->\
    \  return x^(n-1) * f(1/x)\n\t\tvector<D> res = v;\n\t\tif(n!=-1) res.resize(n);\n\
    \t\treverse(all(res));\n\t\treturn Poly(res);\n\t}\n\n\t/*\n\t\tf.inv_div(n) =\
    \ x^n / f\n\t\tf should be non0\n\t\tO((N+n) log n)\n\n\t\tfor division\n\t*/\n\
    \tPoly inv_div(int n) const {\n\t\tn++;\n\t\tint d = size() - 1;\n\t\tassert(d\
    \ != -1);\n\t\tif(n < d) return Poly();\n\t\tPoly a = rev();\n\t\tPoly g({at(d).inv()});\n\
    \t\tfor(int i=1; i+d<=n; i*=2){\t\t//need to strip!!\n\t\t\tg *= (Poly({2})-a.strip(2*i)*g).strip(2*i);\n\
    \t\t}\n\t\treturn g.rev(n-d);\n\t}\n\n\n\tfriend ostream& operator<<(ostream &o,const\
    \ Poly& x){\n\t\tif(x.size()==0) return o<<0;\n\t\trep(i,x.size()) if(x.v[i]!=D(0)){\n\
    \t\t\to<<x.v[i]<<\"x^\"<<i;\n\t\t\tif(i!=x.size()-1) o<<\" + \";\n\t\t}\n\t\t\
    return o;\n\t}\n};\n\n\n/*\n\t\u2193 test\n*/\n\ntemplate<class T>\nT rnd(T l,T\
    \ r){\t//[l,r)\n\tusing D = uniform_int_distribution<T>;\n\tstatic random_device\
    \ rd;\n\tstatic mt19937 gen(rd());\n\treturn D(l,r-1)(gen);\n}\ntemplate<class\
    \ T>\nT rnd(T n){\t//[0,n)\n\treturn rnd(0,n);\n}\nstruct Timer{\n\tclock_t st;\n\
    \tvoid start(){\n\t\tst = clock();\n\t}\n\tint ms(){\n\t\treturn (clock()-st)*1000\
    \ / CLOCKS_PER_SEC;\n\t}\n}timer;\n\n\nvoid unittest(){\n\tvector<int> Ns = {2,10,100,1000,10000,100000,200000,500000,1000000};\n\
    \tfor(int N: Ns){\n\t\tPoly<mint> f,g;\n\t\trep(i,N) f.set(i,rnd<int>(mint::mod));\n\
    \t\trep(i,N) g.set(i,rnd<int>(mint::mod));\n\t\ttimer.start();\n\t\tauto h = f*g;\n\
    \t\tcerr << \"- N = \" << N << endl;\n\t\tcerr << \"  \" << timer.ms() << \" [ms]\"\
    \ << endl;\n\t}\n}\nvoid invtest(){\n\twhile(true){\n\t\tint N,n;\n\t\tcin >>\
    \ N >> n;\n\t\tPoly<mint> f;\n\t\tf.set(0,1);\n\t\trep1(i,N-1) f.set(i,rnd<int>(mint::mod));\n\
    \t\ttimer.start();\n\t\tauto g = f.sqrt(n);\n\t\tshow((f-g*g).strip(n+1));\n\t\
    \tauto h = f.inv(n);\n\t\tshow((f*h).strip(n+1));\n\t\tcerr << \"  \" << timer.ms()\
    \ << \" [ms]\" << endl;\n\t}\n}\nvoid Catalan(){\n\tint N;\n\tcin >> N;\n\tauto\
    \ f = ((Poly<mint>({1}) - Poly<mint>({1,-4}).sqrt(N)) / Poly<mint>({0,2})) . strip(N+1);\n\
    \tshow(f);\n}\n\nint main(){\n//\tunittest();\n//\tinvtest();\n\tCatalan();\n\
    }\n"
  code: "/*\n\n\u30E1\u30E2\uFF1A constructor (int n) \u3092\u5165\u308C\u308B\u3068\
    \ Poly<mint>({2}) \u3068\u304B\u3067\u7834\u58CA\u3055\u308C\u308B\ninitializer\
    \ list? \n Poly() {}\n  explicit Poly(int n) : vector<Mint>(n) {}\n  Poly(const\
    \ vector<Mint> &vec) : vector<Mint>(vec) {}\n  Poly(std::initializer_list<Mint>\
    \ il) : vector<Mint>(il) {}\n\n\u308F\u304B\u3093\u306D\n\u3081\u3082\u304A\u308F\
    \u308A\n\n\u4F9D\u5B58\u95A2\u4FC2 : mint,fft(ntt)\n\n\n\u591A\u9805\u5F0F.\n\
    shrink()\u3067leading-0\u3092\u53D6\u308A\u9664\u304D,\u5E38\u306B\u3053\u306E\
    \u610F\u5473\u3067\u306E\u6B63\u898F\u7CFB\u3092\u5024\u3068\u3057\u3066\u6301\
    \u3064.\n\u305D\u306E\u610F\u5473\u3067int\u3068mint\u4EE5\u5916\u306F\u307E\u3042\
    \u307E\u3042\u307E\u305A\u3044\u304B\u306A\n\u3067\u3082+-\u3068\u304B\u7C21\u5358\
    \u306A\u306E\u306F\u51FA\u6765\u308B(\u3044\u308B\u304B?)\n\n\u5272\u308A\u7B97\
    \u3082 O(NlogN) \u3060\u304CN\u304C\u5C0F\u3055\u3044\u6642\u9045\u3044\u306E\u3067\
    \u5206\u5272\u7D71\u6CBB\u307F\u305F\u3044\u306A\u3053\u3068\u3092\u3059\u308B\
    \u3068\u304D\u306F\u6CE8\u610F\n\ninv(N),exp(N),log(N),sqrt(N) : N\u6B21\u307E\
    \u3067\u3092\u8FD4\u3059\ndiff / intg : \u5FAE\u7A4D\n\nverified: \u3042\u308A\
    \u3059\u304E\u3066\u5FD8\u308C\u305F\n\thttps://codeforces.com/contest/438/problem/E\
    \ (sqrt,inv)\n\thttps://official.contest.yandex.com/ptz-winter-2019/contest/11818/problems/G1/\
    \ (exp,log)\n\n\u8A08\u6E2C:\n\t-O2\n\n\tfft2 *\n\t- N = 100000\n\t141 [ms]\n\t\
    - N = 200000\n\t279 [ms]\n\t- N = 500000\n\t595 [ms]\n\t- N = 1000000\n\t1186\
    \ [ms]\n\n\tfft2 N % N/4 \u304F\u3089\u3044 \u5272\u308B\u5074\u306E\u6B21\u6570\
    \u306F\u3053\u308C\u304F\u3089\u3044\u304C\u4E00\u756A\u9045\u3044\u6C17\u304C\
    \u3059\u308B\n\t- N = 10000\n\t44 [ms]\n\t- N = 100000\n\t643 [ms]\n\t- N = 200000\n\
    \t1340 [ms]\n\t- N = 500000\n\t3033 [ms]\n\t- N = 1000000\n\t5875 [ms]\n\n\tntt\
    \ * \n\t- N = 1000000\n\t231 [ms]\n\n\tntt N % N/4\n\t- N = 200000\n\t147 [ms]\n\
    \t- N = 500000\n\t310 [ms]\n\t- N = 1000000\n\t646 [ms]\n\n*/\n\n#include <bits/stdc++.h>\n\
    #define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) cout << #x << \" = \" << (x) << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){\n\treturn o<<\"\
    (\"<<p.fs<<\",\"<<p.sc<<\")\";\n}\ntemplate<class T> ostream& operator<<(ostream&\
    \ o,const vector<T> &vc){\n\to<<\"{\";\n\tfor(const T& v:vc) o<<v<<\",\";\n\t\
    o<<\"}\";\n\treturn o;\n}\nusing ll = long long;\ntemplate<class T> using V =\
    \ vector<T>;\ntemplate<class T> using VV = vector<vector<T>>;\n\ntemplate<unsigned\
    \ int mod_>\nstruct ModInt{\n\tusing uint = unsigned int;\n\tusing ll = long long;\n\
    \tusing ull = unsigned long long;\n\n\tconstexpr static uint mod = mod_;\n\n\t\
    uint v;\n\tModInt():v(0){}\n\tModInt(ll _v):v(normS(_v%mod+mod)){}\n\texplicit\
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
    \tModInt& operator++(int){ return *this=*this+1;}\n\tModInt& operator--(int){\
    \ return *this=*this-1;}\n\tll extgcd(ll a,ll b,ll &x,ll &y) const{\n\t\tll p[]={a,1,0},q[]={b,0,1};\n\
    \t\twhile(*q){\n\t\t\tll t=*p/ *q;\n\t\t\trep(i,3) swap(p[i]-=t*q[i],q[i]);\n\t\
    \t}\n\t\tif(p[0]<0) rep(i,3) p[i]=-p[i];\n\t\tx=p[1],y=p[2];\n\t\treturn p[0];\n\
    \t}\n\tModInt inv() const {\n\t\tll x,y;\n\t\textgcd(v,mod,x,y);\n\t\treturn make(normS(x+mod));\n\
    \t}\n\tModInt pow(ll p) const {\n\t\tModInt a = 1;\n\t\tModInt x = *this;\n\t\t\
    while(p){\n\t\t\tif(p&1) a *= x;\n\t\t\tx *= x;\n\t\t\tp >>= 1;\n\t\t}\n\t\treturn\
    \ a;\n\t}\n\tbool operator==(const ModInt& b) const { return v==b.v;}\n\tbool\
    \ operator!=(const ModInt& b) const { return v!=b.v;}\n\tfriend istream& operator>>(istream\
    \ &o,ModInt& x){\n\t\tll tmp;\n\t\to>>tmp;\n\t\tx=ModInt(tmp);\n\t\treturn o;\n\
    \t}\n\tfriend ostream& operator<<(ostream &o,const ModInt& x){ return o<<x.v;}\n\
    };\nusing mint = ModInt<998244353>;\n\nint bsr(int x) { return 31 - __builtin_clz(x);\
    \ }\nvoid ntt(bool type, V<mint>& c) {\n\tconst mint G = 3;\t//primitive root\n\
    \n\tint N = int(c.size());\n\tint s = bsr(N);\n\tassert(1 << s == N);\n\n\tV<mint>\
    \ a = c, b(N);\n\trep1(i,s){\n\t\tint W = 1 << (s - i);\n\t\tmint base = G.pow((mint::mod\
    \ - 1)>>i);\n\t\tif(type) base = base.inv();\n\t\tmint now = 1;\n\t\tfor(int y\
    \ = 0; y < N / 2; y += W) {\n\t\t\tfor (int x = 0; x < W; x++) {\n\t\t\t\tauto\
    \ l = a[y << 1 | x];\n\t\t\t\tauto r = now * a[y << 1 | x | W];\n\t\t\t\tb[y |\
    \ x] = l + r;\n\t\t\t\tb[y | x | N >> 1] = l - r;\n\t\t\t}\n\t\t\tnow *= base;\n\
    \t\t}\n\t\tswap(a, b);\n\t}\n\tc = a;\n}\n\nV<mint> multiply_ntt(const V<mint>&\
    \ a, const V<mint>& b) {\n\tint A = int(a.size()), B = int(b.size());\n\tif (!A\
    \ || !B) return {};\n\tint lg = 0;\n\twhile ((1 << lg) < A + B - 1) lg++;\n\t\
    int N = 1 << lg;\n\tV<mint> ac(N), bc(N);\n\tfor (int i = 0; i < A; i++) ac[i]\
    \ = a[i];\n\tfor (int i = 0; i < B; i++) bc[i] = b[i];\n\tntt(false, ac);\n\t\
    ntt(false, bc);\n\tfor (int i = 0; i < N; i++) {\n\t\tac[i] *= bc[i];\n\t}\n\t\
    ntt(true, ac);\n\tV<mint> c(A + B - 1);\n\tmint iN = mint(N).inv();\n\tfor (int\
    \ i = 0; i < A + B - 1; i++) {\n\t\tc[i] = ac[i] * iN;\n\t}\n\treturn c;\n}\n\n\
    template<class D>\nstruct Poly{\n\tvector<D> v;\n\tint size() const{ return v.size();}\t\
    //deg+1\n\tPoly(){}\n\tPoly(vector<D> _v) : v(_v){shrink();}\n\n\tPoly& shrink(){\n\
    \t\twhile(!v.empty()&&v.back()==D(0)) v.pop_back();\n\t\treturn *this;\n\t}\n\t\
    D& operator[](int i){return v[i];}\n\tconst D& operator[](int i) const {return\
    \ v[i];}\n\tD at(int i) const{\n\t\treturn (i<size())?v[i]:D(0);\n\t}\n\tvoid\
    \ set(int i,const D& x){\t\t//v[i] := x\n\t\tif(i>=size() && !x) return;\n\t\t\
    while(i>=size()) v.push_back(D(0));\n\t\tv[i]=x;\n\t\tshrink();\n\t\treturn;\n\
    \t}\n\tD operator()(D x) const {\n\t\tD res = 0;\n\t\tint n = size();\n\t\tD a\
    \ = 1;\n\t\trep(i,n){\n\t\t\tres += a*v[i];\n\t\t\ta *= x;\n\t\t}\n\t\treturn\
    \ res;\n\t}\n\n\tPoly operator+(const Poly &r) const{\n\t\tint N=max(size(),r.size());\n\
    \t\tvector<D> ret(N);\n\t\trep(i,N) ret[i]=at(i)+r.at(i);\n\t\treturn Poly(ret);\n\
    \t}\n\tPoly operator-(const Poly &r) const{\n\t\tint N=max(size(),r.size());\n\
    \t\tvector<D> ret(N);\n\t\trep(i,N) ret[i]=at(i)-r.at(i);\n\t\treturn Poly(ret);\n\
    \t}\n\tPoly operator-() const{\n\t\tint N=size();\n\t\tvector<D> ret(N);\n\t\t\
    rep(i,N) ret[i] = -at(i);\n\t\treturn Poly(ret);\n\t}\n\tPoly operator*(const\
    \ Poly &r) const{\n\t\tif(size()==0||r.size()==0) return Poly();\n\t\treturn mul_ntt(r);\t\
    \t\t\t\t\t\t\t\t// FFT or NTT ?\n\t}\n\tPoly operator*(const D &r) const{\n\t\t\
    int N=size();\n\t\tvector<D> ret(N);\n\t\trep(i,N) ret[i]=v[i]*r;\n\t\treturn\
    \ Poly(ret);\n\t}\n\tPoly operator/(const D &r) const{\n\t\treturn *this * r.inv();\n\
    \t}\n\tPoly operator/(const Poly &y) const{\n\t\treturn div_fast(y);\n\t}\n\t\
    Poly operator%(const Poly &y) const{\n\t\treturn rem_fast(y);\n//\t\treturn rem_naive(y);\n\
    \t}\n\tPoly operator<<(const int &n) const{\t// *=x^n\n\t\tassert(n>=0);\n\t\t\
    int N=size();\n\t\tvector<D> ret(N+n);\n\t\trep(i,N) ret[i+n]=v[i];\n\t\treturn\
    \ Poly(ret);\n\t}\n\tPoly operator>>(const int &n) const{\t// /=x^n\n\t\tassert(n>=0);\n\
    \t\tint N=size();\n\t\tif(N<=n) return Poly();\n\t\tvector<D> ret(N-n);\n\t\t\
    rep(i,N-n) ret[i]=v[i+n];\n\t\treturn Poly(ret);\n\t}\n\tbool operator==(const\
    \ Poly &y) const{\n\t\treturn v==y.v;\n\t}\n\tbool operator!=(const Poly &y) const{\n\
    \t\treturn v!=y.v;\n\t}\n\n\tPoly& operator+=(const Poly &r) {return *this = *this+r;}\n\
    \tPoly& operator-=(const Poly &r) {return *this = *this-r;}\n\tPoly& operator*=(const\
    \ Poly &r) {return *this = *this*r;}\n\tPoly& operator*=(const D &r) {return *this\
    \ = *this*r;}\n\tPoly& operator/=(const Poly &r) {return *this = *this/r;}\n\t\
    Poly& operator/=(const D &r) {return *this = *this/r;}\n\tPoly& operator%=(const\
    \ Poly &y) {return *this = *this%y;}\n\tPoly& operator<<=(const int &n) {return\
    \ *this = *this<<n;}\n\tPoly& operator>>=(const int &n) {return *this = *this>>n;}\n\
    \n\tPoly diff() const {\n\t\tint n = size();\n\t\tif(n == 0) return Poly();\n\t\
    \tV<D> u(n-1);\n\t\trep(i,n-1) u[i] = at(i+1) * (i+1);\n\t\treturn Poly(u);\n\t\
    }\n\tPoly intg() const {\n\t\tint n = size();\n\t\tV<D> u(n+1);\n\t\trep(i,n)\
    \ u[i+1] = at(i) / (i+1);\n\t\treturn Poly(u);\n\t}\n\n\tPoly pow(long long n,\
    \ int L) const {\t\t// f^n, ignoring x^L,x^{L+1},..\n\t\tPoly a({1});\n\t\tPoly\
    \ x = *this;\n\t\twhile(n){\n\t\t\tif(n&1){\n\t\t\t\ta *= x;\n\t\t\t\ta = a.strip(L);\n\
    \t\t\t}\n\t\t\tx *= x;\n\t\t\tx = x.strip(L);\n\t\t\tn /= 2;\n\t\t}\n\t\treturn\
    \ a;\n\t}\n\n\t/*\n\t\t[x^0~n] exp(f) = 1 + f + f^2 / 2 + f^3 / 6 + ..\n\t\tf(0)\
    \ should be 0\n\n\t\tO((N+n) log n)\t(N = size())\n\t\tNTT, -O3\n\t\t- N = n =\
    \ 100000 : 200 [ms]\n\t\t- N = n = 200000 : 400 [ms]\n\t\t- N = n = 500000 : 1000\
    \ [ms]\n\t*/\n\tPoly exp(int n) const {\n\t\tassert(at(0) == 0);\n\t\tPoly f({1}),\
    \ g({1});\n\t\tfor(int i=1;i<=n;i*=2){\n\t\t\tg = (g*2 - f*g*g).strip(i);\n\t\t\
    \tPoly q = (this->diff()).strip(i-1);\n\t\t\tPoly w = (q + g * (f.diff() - f*q))\
    \ .strip(2*i-1);\n\t\t\tf = (f + f * (*this - w.intg()).strip(2*i)) .strip(2*i);\n\
    \t\t}\n\t\treturn f.strip(n+1);\n\t}\n\n\t/*\n\t\t[x^0~n] log(f) = log(1-(1-f))\
    \ = - (1-f) - (1-f)^2 / 2 - (1-f)^3 / 3 - ...\n\t\tf(0) should be 1\n\t\tO(n log\
    \ n)\n\n\t\tNTT, -O3\n\t\t1e5 : 140 [ms]\n\t\t2e5 : 296 [ms]\n\t\t5e5 : 640 [ms]\n\
    \t\t1e6 : 1343 [ms]\n\t*/\n\tPoly log(int n) const {\n\t\tassert(at(0) == 1);\n\
    \t\tauto f = strip(n+1);\n\t\treturn (f.diff() * f.inv(n)).strip(n).intg();\n\t\
    }\n\n\t/*\n\t\t[x^0~n] sqrt(f)\n\t\tf(0) should be 1\n\t\t\u3044\u3084\u5E73\u65B9\
    \u5270\u4F59\u306A\u3089\u4F55\u3067\u3082\u3044\u3044\u3068\u601D\u3046\u3051\
    \u3069\u63A2\u3059\u306E\u304C\u3081\u3093\u3069\u304F\u3055\u3044\u306E\u3067\
    \n\t\t+- 2\u901A\u308A\u3060\u3051\u3069 \u5B9A\u6570\u9805\u304C 1 \u306E\u65B9\
    \n\t\tO(n log n)\n\n\t\tNTT, -O3\n\t\t1e5 : 234 [ms]\n\t\t2e5 : 484 [ms]\n\t\t\
    5e5 : 1000 [ms]\n\t\t1e6 : 2109 [ms]\n\t*/\n\tPoly sqrt(int n) const {\n\t\tassert(at(0)\
    \ == 1);\n\t\tPoly f = strip(n+1);\n\t\tPoly g({1});\n\t\tfor(int i=1; i<=n; i*=2){\n\
    \t\t\tg = (g + f.strip(2*i)*g.inv(2*i-1)) / 2;\n\t\t}\n\t\treturn g.strip(n+1);\n\
    \t}\n\n\t/*\n\t\t[x^0~n] f^-1 = (1-(1-f))^-1 = (1-f) + (1-f)^2 + ...\n\t\tf *\
    \ f.inv(n) = 1 + x^n * poly\n\t\tf(0) should be non0\n\t\tO(n log n)\n\t*/\n\t\
    Poly inv(int n) const {\n\t\tassert(at(0) != 0);\n\t\tPoly f = strip(n+1);\n\t\
    \tPoly g({at(0).inv()});\n\t\tfor(int i=1; i<=n; i*=2){\t\t//need to strip!!\n\
    \t\t\tg *= (Poly({2}) - f.strip(2*i)*g).strip(2*i);\n\t\t}\n\t\treturn g.strip(n+1);\n\
    \t}\t\n\n\tPoly exp_naive(int n) const {\n\t\tassert(at(0) == 0);\n\t\tPoly res;\n\
    \t\tPoly fk({1});\n\t\trep(k,n+1){\n\t\t\tres += fk;\n\t\t\tfk *= *this;\n\t\t\
    \tfk = fk.strip(n+1) / (k+1);\n\t\t}\n\t\treturn res;\n\t}\n\tPoly log_naive(int\
    \ n) const {\n\t\tassert(at(0) == 1);\n\t\tPoly res;\n\t\tPoly g({1});\n\t\trep1(k,n){\n\
    \t\t\tg *= (Poly({1}) - *this);\n\t\t\tg = g.strip(n+1);\n\t\t\tres -= g / k;\n\
    \t\t}\n\t\treturn res;\n\t}\n\n\n\tPoly mul_naive(const Poly &r) const{\n\t\t\
    int N=size(),M=r.size();\n\t\tvector<D> ret(N+M-1);\n\t\trep(i,N) rep(j,M) ret[i+j]+=at(i)*r.at(j);\n\
    \t\treturn Poly(ret);\n\t}\n\tPoly mul_ntt(const Poly &r) const{\n\t\treturn Poly(multiply_ntt(v,r.v));\n\
    \t}\n\tPoly mul_fft(const Poly &r) const{\n\t\treturn Poly(multiply_fft(v,r.v));\n\
    \t}\n\n\tPoly div_fast_with_inv(const Poly &inv, int B) const {\n\t\treturn (*this\
    \ * inv)>>(B-1);\n\t}\n\tPoly div_fast(const Poly &y) const{\n\t\tif(size()<y.size())\
    \ return Poly();\n\t\tint n = size();\n\t\treturn div_fast_with_inv(y.inv_div(n-1),n);\n\
    \t}\n\tPoly rem_naive(const Poly &y) const{\n\t\tPoly x = *this;\n\t\twhile(y.size()<=x.size()){\n\
    \t\t\tint N=x.size(),M=y.size();\n\t\t\tD coef = x.v[N-1]/y.v[M-1];\n\t\t\tx -=\
    \ (y<<(N-M))*coef;\n\t\t}\n\t\treturn x;\n\t}\n\tPoly rem_fast(const Poly &y)\
    \ const{\n\t\treturn *this - y * div_fast(y);\n\t}\n\tPoly strip(int n) const\
    \ {\t//ignore x^n , x^n+1,...\n\t\tvector<D> res = v;\n\t\tres.resize(min(n,size()));\n\
    \t\treturn Poly(res);\n\t}\n\tPoly rev(int n = -1) const {\t//ignore x^n ~  ->\
    \  return x^(n-1) * f(1/x)\n\t\tvector<D> res = v;\n\t\tif(n!=-1) res.resize(n);\n\
    \t\treverse(all(res));\n\t\treturn Poly(res);\n\t}\n\n\t/*\n\t\tf.inv_div(n) =\
    \ x^n / f\n\t\tf should be non0\n\t\tO((N+n) log n)\n\n\t\tfor division\n\t*/\n\
    \tPoly inv_div(int n) const {\n\t\tn++;\n\t\tint d = size() - 1;\n\t\tassert(d\
    \ != -1);\n\t\tif(n < d) return Poly();\n\t\tPoly a = rev();\n\t\tPoly g({at(d).inv()});\n\
    \t\tfor(int i=1; i+d<=n; i*=2){\t\t//need to strip!!\n\t\t\tg *= (Poly({2})-a.strip(2*i)*g).strip(2*i);\n\
    \t\t}\n\t\treturn g.rev(n-d);\n\t}\n\n\n\tfriend ostream& operator<<(ostream &o,const\
    \ Poly& x){\n\t\tif(x.size()==0) return o<<0;\n\t\trep(i,x.size()) if(x.v[i]!=D(0)){\n\
    \t\t\to<<x.v[i]<<\"x^\"<<i;\n\t\t\tif(i!=x.size()-1) o<<\" + \";\n\t\t}\n\t\t\
    return o;\n\t}\n};\n\n\n/*\n\t\u2193 test\n*/\n\ntemplate<class T>\nT rnd(T l,T\
    \ r){\t//[l,r)\n\tusing D = uniform_int_distribution<T>;\n\tstatic random_device\
    \ rd;\n\tstatic mt19937 gen(rd());\n\treturn D(l,r-1)(gen);\n}\ntemplate<class\
    \ T>\nT rnd(T n){\t//[0,n)\n\treturn rnd(0,n);\n}\nstruct Timer{\n\tclock_t st;\n\
    \tvoid start(){\n\t\tst = clock();\n\t}\n\tint ms(){\n\t\treturn (clock()-st)*1000\
    \ / CLOCKS_PER_SEC;\n\t}\n}timer;\n\n\nvoid unittest(){\n\tvector<int> Ns = {2,10,100,1000,10000,100000,200000,500000,1000000};\n\
    \tfor(int N: Ns){\n\t\tPoly<mint> f,g;\n\t\trep(i,N) f.set(i,rnd<int>(mint::mod));\n\
    \t\trep(i,N) g.set(i,rnd<int>(mint::mod));\n\t\ttimer.start();\n\t\tauto h = f*g;\n\
    \t\tcerr << \"- N = \" << N << endl;\n\t\tcerr << \"  \" << timer.ms() << \" [ms]\"\
    \ << endl;\n\t}\n}\nvoid invtest(){\n\twhile(true){\n\t\tint N,n;\n\t\tcin >>\
    \ N >> n;\n\t\tPoly<mint> f;\n\t\tf.set(0,1);\n\t\trep1(i,N-1) f.set(i,rnd<int>(mint::mod));\n\
    \t\ttimer.start();\n\t\tauto g = f.sqrt(n);\n\t\tshow((f-g*g).strip(n+1));\n\t\
    \tauto h = f.inv(n);\n\t\tshow((f*h).strip(n+1));\n\t\tcerr << \"  \" << timer.ms()\
    \ << \" [ms]\" << endl;\n\t}\n}\nvoid Catalan(){\n\tint N;\n\tcin >> N;\n\tauto\
    \ f = ((Poly<mint>({1}) - Poly<mint>({1,-4}).sqrt(N)) / Poly<mint>({0,2})) . strip(N+1);\n\
    \tshow(f);\n}\n\nint main(){\n//\tunittest();\n//\tinvtest();\n\tCatalan();\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: math/poly.cpp
  requiredBy: []
  timestamp: '2020-12-16 01:48:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/poly.cpp
layout: document
redirect_from:
- /library/math/poly.cpp
- /library/math/poly.cpp.html
title: math/poly.cpp
---
