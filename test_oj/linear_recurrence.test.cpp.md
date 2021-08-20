---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/poly.cpp
    title: math/poly.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
    links:
    - https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
  bundledCode: "#line 1 \"test_oj/linear_recurrence.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing uint\
    \ = unsigned int;\nusing ull = unsigned long long;\n#define rep(i,n) for(int i=0;i<int(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=int(n);i++)\n#define per(i,n) for(int i=int(n)-1;i>=0;i--)\n\
    #define per1(i,n) for(int i=int(n);i>0;i--)\n#define all(c) c.begin(),c.end()\n\
    #define si(x) int(x.size())\n#define pb emplace_back\n#define fs first\n#define\
    \ sc second\ntemplate<class T> using V = vector<T>;\ntemplate<class T> using VV\
    \ = vector<vector<T>>;\ntemplate<class T,class U> void chmax(T& x, U y){if(x<y)\
    \ x=y;}\ntemplate<class T,class U> void chmin(T& x, U y){if(y<x) x=y;}\ntemplate<class\
    \ T> void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}\ntemplate<class\
    \ T> int lwb(const V<T>& v, const T& a){return lower_bound(all(v),a) - v.begin();}\n\
    template<class T>\nV<T> Vec(size_t a) {\n    return V<T>(a);\n}\ntemplate<class\
    \ T, class... Ts>\nauto Vec(size_t a, Ts... ts) {\n  return V<decltype(Vec<T>(ts...))>(a,\
    \ Vec<T>(ts...));\n}\ntemplate<class S,class T> ostream& operator<<(ostream& o,const\
    \ pair<S,T> &p){\n\treturn o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";\n}\ntemplate<class\
    \ T> ostream& operator<<(ostream& o,const vector<T> &vc){\n\to<<\"{\";\n\tfor(const\
    \ T& v:vc) o<<v<<\",\";\n\to<<\"}\";\n\treturn o;\n}\nconstexpr ll TEN(int n)\
    \ { return (n == 0) ? 1 : 10 * TEN(n-1); }\n\n#ifdef LOCAL\n#define show(x) cerr\
    \ << \"LINE\" << __LINE__ << \" : \" << #x << \" = \" << (x) << endl\nvoid dmpr(ostream&\
    \ os){os<<endl;}\ntemplate<class T,class... Args>\nvoid dmpr(ostream&os,const\
    \ T&t,const Args&... args){\n\tos<<t<<\" ~ \";\n\tdmpr(os,args...);\n}\n#define\
    \ shows(...) cerr << \"LINE\" << __LINE__ << \" : \";dmpr(cerr,##__VA_ARGS__)\n\
    #define dump(x) cerr << \"LINE\" << __LINE__ << \" : \" << #x << \" = {\";  \\\
    \n\tfor(auto v: x) cerr << v << \",\"; cerr << \"}\" << endl;\n#else\n#define\
    \ show(x) void(0)\n#define dump(x) void(0)\n#define shows(...) void(0)\n#endif\n\
    \n\n#line 1 \"math/poly.cpp\"\n/*\n\t2021/04/14 \u5927\u5E45\u5909\u66F4\n\tpoly\
    \ \u57FA\u672C, MultipointEval, Interpolate\n*/\ntemplate<unsigned int mod_>\n\
    struct ModInt{\n\tusing uint = unsigned int;\n\tusing ll = long long;\n\tusing\
    \ ull = unsigned long long;\n\n\tconstexpr static uint mod = mod_;\n\n\tuint v;\n\
    \tModInt():v(0){}\n\tModInt(ll _v):v(normS(_v%mod+mod)){}\n\texplicit operator\
    \ bool() const {return v!=0;}\n\tstatic uint normS(const uint &x){return (x<mod)?x:x-mod;}\t\
    \t// [0 , 2*mod-1] -> [0 , mod-1]\n\tstatic ModInt make(const uint &x){ModInt\
    \ m; m.v=x; return m;}\n\tModInt operator+(const ModInt& b) const { return make(normS(v+b.v));}\n\
    \tModInt operator-(const ModInt& b) const { return make(normS(v+mod-b.v));}\n\t\
    ModInt operator-() const { return make(normS(mod-v)); }\n\tModInt operator*(const\
    \ ModInt& b) const { return make((ull)v*b.v%mod);}\n\tModInt operator/(const ModInt&\
    \ b) const { return *this*b.inv();}\n\tModInt& operator+=(const ModInt& b){ return\
    \ *this=*this+b;}\n\tModInt& operator-=(const ModInt& b){ return *this=*this-b;}\n\
    \tModInt& operator*=(const ModInt& b){ return *this=*this*b;}\n\tModInt& operator/=(const\
    \ ModInt& b){ return *this=*this/b;}\n\tModInt& operator++(int){ return *this=*this+1;}\n\
    \tModInt& operator--(int){ return *this=*this-1;}\n\tModInt pow(ll p) const {\n\
    \t\tif(p<0) return inv().pow(-p);\n\t\tModInt a = 1;\n\t\tModInt x = *this;\n\t\
    \twhile(p){\n\t\t\tif(p&1) a *= x;\n\t\t\tx *= x;\n\t\t\tp >>= 1;\n\t\t}\n\t\t\
    return a;\n\t}\n\tModInt inv() const {\t\t// should be prime\n\t\treturn pow(mod-2);\n\
    \t}\n\t// ll extgcd(ll a,ll b,ll &x,ll &y) const{\n\t// \tll p[]={a,1,0},q[]={b,0,1};\n\
    \t// \twhile(*q){\n\t// \t\tll t=*p/ *q;\n\t// \t\trep(i,3) swap(p[i]-=t*q[i],q[i]);\n\
    \t// \t}\n\t// \tif(p[0]<0) rep(i,3) p[i]=-p[i];\n\t// \tx=p[1],y=p[2];\n\t//\
    \ \treturn p[0];\n\t// }\n\t// ModInt inv() const {\n\t// \tll x,y;\n\t// \textgcd(v,mod,x,y);\n\
    \t// \treturn make(normS(x+mod));\n\t// }\n\n\tbool operator==(const ModInt& b)\
    \ const { return v==b.v;}\n\tbool operator!=(const ModInt& b) const { return v!=b.v;}\n\
    \tbool operator<(const ModInt& b) const { return v<b.v;}\n\tfriend istream& operator>>(istream\
    \ &o,ModInt& x){\n\t\tll tmp;\n\t\to>>tmp;\n\t\tx=ModInt(tmp);\n\t\treturn o;\n\
    \t}\n\tfriend ostream& operator<<(ostream &o,const ModInt& x){ return o<<x.v;}\n\
    };\nusing mint = ModInt<998244353>;\n//using mint = ModInt<1000000007>;\n\nV<mint>\
    \ fact,ifact,invs;\nmint Choose(int a,int b){\n\tif(b<0 || a<b) return 0;\n\t\
    return fact[a] * ifact[b] * ifact[a-b];\n}\nvoid InitFact(int N){\t//[0,N]\n\t\
    N++;\n\tfact.resize(N);\n\tifact.resize(N);\n\tinvs.resize(N);\n\tfact[0] = 1;\n\
    \trep1(i,N-1) fact[i] = fact[i-1] * i;\n\tifact[N-1] = fact[N-1].inv();\n\tfor(int\
    \ i=N-2;i>=0;i--) ifact[i] = ifact[i+1] * (i+1);\n\trep1(i,N-1) invs[i] = fact[i-1]\
    \ * ifact[i];\n}\n\n// inplace_fmt (without bit rearranging)\n// fft:\n// \t\t\
    a[rev(i)] <- \\sum_j \\zeta^{ij} a[j]\n// invfft:\n//\t\ta[i] <- (1/n) \\sum_j\
    \ \\zeta^{-ij} a[rev(j)]\n// These two are inversions.\n\n\n// !!! CHANGE IF MOD\
    \ is unusual !!!\nconst int ORDER_2_MOD_MINUS_1 = 23;\t// ord_2 (mod-1)\nconst\
    \ mint PRIMITIVE_ROOT = 3; // primitive root of (Z/pZ)*\n\nvoid fft(V<mint>& a){\n\
    \tstatic constexpr uint mod = mint::mod;\n\tstatic constexpr uint mod2 = mod +\
    \ mod;\n\tstatic const int H = ORDER_2_MOD_MINUS_1;\n\tstatic const mint root\
    \ = PRIMITIVE_ROOT;\n\tstatic mint magic[H-1];\n\n\tint n = si(a);\n\tassert(!(n\
    \ & (n-1))); assert(n >= 1); assert(n <= 1<<H);\t// n should be power of 2\n\n\
    \tif(!magic[0]){\t\t// precalc\n\t\trep(i,H-1){\n\t\t\tmint w = -root.pow(((mod-1)>>(i+2))*3);\n\
    \t\t\tmagic[i] = w;\n\t\t}\n\t}\n\tint m = n;\n\tif(m >>= 1){\n\t\trep(i,m){\n\
    \t\t\tuint v = a[i+m].v;\t\t\t\t\t// < M\n\t\t\ta[i+m].v = a[i].v + mod - v;\t\
    \t// < 2M\n\t\t\ta[i].v += v;\t\t\t\t\t\t// < 2M\n\t\t}\n\t}\n\tif(m >>= 1){\n\
    \t\tmint p = 1;\n\t\tfor(int h=0,s=0; s<n; s += m*2){\n\t\t\tfor(int i=s;i<s+m;i++){\n\
    \t\t\t\tuint v = (a[i+m] * p).v;\t\t// < M\n\t\t\t\ta[i+m].v = a[i].v + mod -\
    \ v;\t// < 3M\n\t\t\t\ta[i].v += v;\t\t\t\t\t// < 3M\n\t\t\t}\n\t\t\tp *= magic[__builtin_ctz(++h)];\n\
    \t\t}\n\t}\n\twhile(m){\n\t\tif(m >>= 1){\n\t\t\tmint p = 1;\n\t\t\tfor(int h=0,s=0;\
    \ s<n; s += m*2){\n\t\t\t\tfor(int i=s;i<s+m;i++){\n\t\t\t\t\tuint v = (a[i+m]\
    \ * p).v;\t\t// < M\n\t\t\t\t\ta[i+m].v = a[i].v + mod - v;\t// < 4M\n\t\t\t\t\
    \ta[i].v += v;\t\t\t\t\t// < 4M\n\t\t\t\t}\n\t\t\t\tp *= magic[__builtin_ctz(++h)];\n\
    \t\t\t}\n\t\t}\n\t\tif(m >>= 1){\n\t\t\tmint p = 1;\n\t\t\tfor(int h=0,s=0; s<n;\
    \ s += m*2){\n\t\t\t\tfor(int i=s;i<s+m;i++){\n\t\t\t\t\tuint v = (a[i+m] * p).v;\t\
    \t\t\t\t\t\t\t// < M\n\t\t\t\t\ta[i].v = (a[i].v >= mod2) ? a[i].v - mod2 : a[i].v;\t\
    // < 2M\n\t\t\t\t\ta[i+m].v = a[i].v + mod - v;\t\t\t\t\t\t\t// < 3M\n\t\t\t\t\
    \ta[i].v += v;\t\t\t\t\t\t\t\t\t\t\t// < 3M\n\t\t\t\t}\n\t\t\t\tp *= magic[__builtin_ctz(++h)];\n\
    \t\t\t}\n\t\t}\n\t}\n\trep(i,n){\n\t\ta[i].v = (a[i].v >= mod2) ? a[i].v - mod2\
    \ : a[i].v;\t\t// < 2M\n\t\ta[i].v = (a[i].v >= mod) ? a[i].v - mod : a[i].v;\t\
    \t// < M\n\t}\n\t// finally < mod !!\n}\nvoid invfft(V<mint>& a){\n\tstatic constexpr\
    \ uint mod = mint::mod;\n\tstatic constexpr uint mod2 = mod + mod;\n\tstatic const\
    \ int H = ORDER_2_MOD_MINUS_1;\n\tstatic const mint root = PRIMITIVE_ROOT;\n\t\
    static mint magic[H-1];\n\n\tint n = si(a);\n\tassert(!(n & (n-1))); assert(n\
    \ >= 1); assert(n <= 1<<H);\t// n should be power of 2\n\n\tif(!magic[0]){\t\t\
    // precalc\n\t\trep(i,H-1){\n\t\t\tmint w = -root.pow(((mod-1)>>(i+2))*3);\n\t\
    \t\tmagic[i] = w.inv();\n\t\t}\n\t}\n\tint m = 1;\n\tif(m < n>>1){\n\t\tmint p\
    \ = 1;\n\t\tfor(int h=0,s=0; s<n; s += m*2){\n\t\t\tfor(int i=s;i<s+m;i++){\n\t\
    \t\t\tull x = a[i].v + mod - a[i+m].v;\t// < 2M\n\t\t\t\ta[i].v += a[i+m].v;\t\
    \t\t\t\t// < 2M\n\t\t\t\ta[i+m].v = (p.v * x) % mod;\t\t\t// < M\n\t\t\t}\n\t\t\
    \tp *= magic[__builtin_ctz(++h)];\n\t\t}\n\t\tm <<= 1;\n\t}\n\tfor(;m < n>>1;\
    \ m <<= 1){\n\t\tmint p = 1;\n\t\tfor(int h=0,s=0; s<n; s+= m*2){\n\t\t\tfor(int\
    \ i=s;i<s+(m>>1);i++){\n\t\t\t\tull x = a[i].v + mod2 - a[i+m].v;\t// < 4M\n\t\
    \t\t\ta[i].v += a[i+m].v;\t\t\t\t\t// < 4M\n\t\t\t\ta[i].v = (a[i].v >= mod2)\
    \ ? a[i].v - mod2 : a[i].v;\t// < 2M\n\t\t\t\ta[i+m].v = (p.v * x) % mod;\t\t\
    // < M\n\t\t\t}\n\t\t\tfor(int i=s+(m>>1); i<s+m; i++){\n\t\t\t\tull x = a[i].v\
    \ + mod - a[i+m].v;\t// < 2M\n\t\t\t\ta[i].v += a[i+m].v;\t// < 2M\n\t\t\t\ta[i+m].v\
    \ = (p.v * x) % mod;\t// < M\n\t\t\t}\n\t\t\tp *= magic[__builtin_ctz(++h)];\n\
    \t\t}\n\t}\n\tif(m < n){\n\t\trep(i,m){\n\t\t\tuint x = a[i].v + mod2 - a[i+m].v;\t\
    // < 4M\n\t\t\ta[i].v += a[i+m].v;\t// < 4M\n\t\t\ta[i+m].v = x;\t// < 4M\n\t\t\
    }\n\t}\n\tconst mint in = mint(n).inv();\n\trep(i,n) a[i] *= in;\t// < M\n\t//\
    \ finally < mod !!\n}\n\n// A,B = 500000 -> 70ms\n// verify https://judge.yosupo.jp/submission/44937\n\
    V<mint> multiply(V<mint> a, V<mint> b) {\n\tint A = si(a), B = si(b);\n\tif (!A\
    \ || !B) return {};\n\tint n = A+B-1;\n\tint s = 1; while(s<n) s*=2;\n\tif(a ==\
    \ b){\t\t\t// # of fft call : 3 -> 2\n\t\ta.resize(s); fft(a);\n\t\trep(i,s) a[i]\
    \ *= a[i];\n\t}else{\n\t\ta.resize(s); fft(a);\n\t\tb.resize(s); fft(b);\n\t\t\
    rep(i,s) a[i] *= b[i];\n\t}\n\tinvfft(a); a.resize(n);\n\treturn a;\n}\n\n/*\n\
    \t\u4FC2\u6570\u30A2\u30AF\u30BB\u30B9\n\t\tf[i] \u3067\u3044\u3044\u304C\u3001\
    \ \u914D\u5217\u5916\u53C2\u7167\u3059\u308B\u53EF\u80FD\u6027\u304C\u3042\u308B\
    \u306A\u3089 at/set\n\t\n*/\n\ntemplate<class mint>\nstruct Poly: public V<mint>{\n\
    \ttemplate<class...Args>\n\tPoly(Args...args) : V<mint>(args...){}\n\tPoly(initializer_list<mint>\
    \ li) : V<mint>(li){}\n\n\tint size() const { return V<mint>::size(); }\n\tmint\
    \ at(int i) const {\n\t\treturn i<size() ? (*this)[i] : 0;\n\t}\n\tvoid set(int\
    \ i, mint x){\n\t\tif(i>=size() && !x) return;\n\t\twhile(i>=size()) this->pb(0);\n\
    \t\t(*this)[i] = x;\n\t\treturn;\n\t}\n\tmint operator()(mint x) const {\t\t//\
    \ eval\n\t\tmint res = 0;\n\t\tint n = size();\n\t\tmint a = 1;\n\t\trep(i,n){\n\
    \t\t\tres += a * (*this)[i];\n\t\t\ta *= x;\n\t\t}\n\t\treturn res;\n\t}\n\tPoly\
    \ low(int n) const {\t\t// ignore x^n (take first n), but not empty\n\t\treturn\
    \ Poly(this->begin(), this->begin()+min(max(n,1),size()));\n\t}\n\tPoly rev()\
    \ const {\n\t\treturn Poly(this->rbegin(), this->rend());\n\t}\n\tfriend ostream&\
    \ operator<<(ostream &o,const Poly& f){\n\t\to << \"[\";\n\t\trep(i,f.size()){\n\
    \t\t\to << f[i];\n\t\t\tif(i != f.size()-1) o << \",\";\n\t\t}\n\t\to << \"]\"\
    ;\n\t\treturn o;\n\t}\n\n\tPoly operator-() const {\n\t\tPoly res = *this;\n\t\
    \tfor(auto& v: res) v = -v;\n\t\treturn res;\n\t}\n\ttemplate<class T>\n\tPoly&\
    \ operator+=(T c){\n\t\t(*this)[0] += c;\n\t\treturn *this;\n\t}\n\ttemplate<class\
    \ T>\n\tPoly& operator-=(T c){\n\t\t(*this)[0] -= c;\n\t\treturn *this;\n\t}\n\
    \ttemplate<class T>\n\tPoly& operator*=(T c){\n\t\tfor(auto& v: *this) v *= c;\n\
    \t\treturn *this;\n\t}\n\ttemplate<class T>\n\tPoly& operator/=(T c){\n\t\treturn\
    \ *this *= mint(1)/mint(c);\n\t}\n\tPoly& operator+=(const Poly& r){\n\t\tif(size()\
    \ < r.size()) this->resize(r.size(),0);\n\t\trep(i,r.size()) (*this)[i] += r[i];\n\
    \t\treturn *this;\n\t}\n\tPoly& operator-=(const Poly& r){\n\t\tif(size() < r.size())\
    \ this->resize(r.size(),0);\n\t\trep(i,r.size()) (*this)[i] -= r[i];\n\t\treturn\
    \ *this;\n\t}\n\tPoly& operator*=(const Poly& r){\n\t\treturn *this = multiply(*this,r);\n\
    \t}\n\n\t// \u4F55\u56DE\u3082\u540C\u3058r\u3067\u5272\u308A\u7B97\u3059\u308B\
    \u306A\u3089\u6BCE\u56DErinv\u3092\u8A08\u7B97\u3059\u308B\u306E\u306F\u7121\u99C4\
    \u306A\u306E\u3067\u3001\u547C\u3073\u51FA\u3057\u5074\u3067\u4E00\u56DE\u8A08\
    \u7B97\u3057\u305F\u5F8C\u76F4\u63A5\u3053\u3063\u3061\u3092\u547C\u3076\u3068\
    \u826F\u3044\n\t// \u53D6\u308B\u3079\u304Dinv\u306E\u9577\u3055\u306B\u6CE8\u610F\
    \n\t// \u4F8B\u3048\u3070 mod r \u3067\u8272\u3005\u8A08\u7B97\u3057\u305F\u3044\
    \u6642\u306F\u3001\u57FA\u672C\u7684\u306B deg(r) * 2 \u9577\u3055\u306E\u591A\
    \u9805\u5F0F\u3092 r \u3067\u5272\u308B\u3053\u3068\u306B\u306A\u308B\n\t// \u3068\
    \u306F\u3044\u3048\u3044\u3063\u305F\u3093 rinv \u3092\u9577\u304F\u8A08\u7B97\
    \u3057\u305F\u3089\u3088\u308A\u77ED\u3044\u5834\u5408\u306Fprefix\u898B\u308B\
    \u3060\u3051\u3060\u3057\u3001 rinv \u3068\u3057\u3066\u30E0\u30C0\u306B\u9577\
    \u3044\u3082\u306E\u3092\u6E21\u3057\u3066\u3082\u554F\u984C\u306A\u3044\u306E\
    \u3067\n\t// \u5272\u3089\u308C\u308B\u591A\u9805\u5F0F\u3068\u3057\u3066\u6700\
    \u5927\u306E\u6B21\u6570\u3092\u53D6\u308C\u3070\u3088\u3044\n\n\tPoly quotient(const\
    \ Poly& r, const Poly& rinv){\n\t\tint m = r.size(); assert(r[m-1].v);\n\t\tint\
    \ n = size();\n\t\tint s = n-m+1;\n\t\tif(s <= 0) return {0};\n\t\treturn (rev().low(s)*rinv.low(s)).low(s).rev();\n\
    \t}\n\tPoly& operator/=(const Poly& r){\n\t\treturn *this = quotient(r,r.rev().inv(max(size()-r.size(),0)+1));\n\
    \t}\n\tPoly& operator%=(const Poly& r){\n\t\t*this -= *this/r * r;\n\t\treturn\
    \ *this = low(r.size()-1);\n\t}\n\n\t\n\ttemplate<class T> Poly operator+(T c)\
    \ const {return Poly(*this) += c; }\n\ttemplate<class T> Poly operator-(T c) const\
    \ {return Poly(*this) -= c; }\n\ttemplate<class T> Poly operator*(T c) const {return\
    \ Poly(*this) *= c; }\n\ttemplate<class T> Poly operator/(T c) const {return Poly(*this)\
    \ /= c; }\n\tPoly operator+(const Poly& r) const {return Poly(*this) += r; }\n\
    \tPoly operator-(const Poly& r) const {return Poly(*this) -= r; }\n\tPoly operator*(const\
    \ Poly& r) const {return Poly(*this) *= r; }\n\tPoly operator/(const Poly& r)\
    \ const {return Poly(*this) /= r; }\n\tPoly operator%(const Poly& r) const {return\
    \ Poly(*this) %= r; }\n\n\tPoly diff() const {\n\t\tPoly g(max(size()-1,0));\n\
    \t\trep(i,g.size()) g[i] = (*this)[i+1] * (i+1);\n\t\treturn g;\n\t}\n\tPoly intg()\
    \ const {\n\t\tassert(si(invs) > size());\n\t\tPoly g(size()+1);\n\t\trep(i,size())\
    \ g[i+1] = (*this)[i] * invs[i+1];\n\t\treturn g;\n\t}\n\tPoly square() const\
    \ {\n\t\treturn multiply(*this,*this);\n\t}\n\n\t// 1/f(x) mod x^s\n\t// N = s\
    \ = 500000 -> 90ms\n\t// inv \u306F 5 \u56DE fft(2n) \u3092\u547C\u3093\u3067\u3044\
    \u308B\u306E\u3067\u3001multiply \u304C 3 \u56DE fft(2n) \u3092\u547C\u3076\u306E\
    \u3068\u6BD4\u3079\u308B\u3068\n\t// \u3060\u3044\u305F\u3044 multiply \u306E\
    \ 5/3 \u500D\u306E\u6642\u9593\u304C\u304B\u304B\u308B\n\t// \u5C0E\u51FA: Newton\n\
    \t// \t\tfg = 1 mod x^m\n\t// \t\t(fg-1)^2 = 0 mod x^2m\n\t// \t\tf(2g-fg^2) =\
    \ 1 mod x^2m\n\t// verify: https://judge.yosupo.jp/submission/44938\n\tPoly inv(int\
    \ s) const {\n\t\tPoly r(s);\n\t\tr[0] = mint(1)/at(0);\n\t\tfor(int n=1;n<s;n*=2){\t\
    \t\t// 5 times fft : length 2n\n\t\t\tV<mint> f = low(2*n); f.resize(2*n);\n\t\
    \t\tfft(f);\n\t\t\tV<mint> g = r.low(2*n); g.resize(2*n);\n\t\t\tfft(g);\n\t\t\
    \trep(i,2*n) f[i] *= g[i];\n\t\t\tinvfft(f);\n\t\t\trep(i,n) f[i] = 0;\n\t\t\t\
    fft(f);\n\t\t\trep(i,2*n) f[i] *= g[i];\n\t\t\tinvfft(f);\n\t\t\tfor(int i=n;i<min(2*n,s);i++)\
    \ r[i] -= f[i];\n\t\t}\n\t\treturn r;\n\t}\n\n\t// log f mod x^s\n\t// \u5C0E\u51FA\
    : D log(f) = (D f) / f\n\t// 500000: 180ms\n\t// mult \u306E 8/3 \u500D\n\t//\
    \ verify: https://judge.yosupo.jp/submission/44962\n\tPoly log(int s) const {\n\
    \t\tassert(at(0) == 1);\n\t\tif(s == 1) return {0};\n\t\treturn (low(s).diff()\
    \ * inv(s-1)).low(s-1).intg();\n\t}\n\n\t// e^f mod x^s\n\t// f.log(s).exp(s)\
    \ == [1,0,...,0]\n\t// 500000 : 440ms\n\t// TODO: \u9AD8\u901F\u5316\uFF01\n\t\
    // \u901F\u3044\u5B9F\u88C5\u4F8B (hos): https://judge.yosupo.jp/submission/36732\
    \ 150ms\n\t// \u5C0E\u51FA Newton:\n\t//\t\t\u3088\u304F\u308F\u304B\u3063\u3066\
    \u306D\uFF5E\n\t// verify: yosupo\n\tPoly exp(int s) const {\n\t\tassert(at(0)\
    \ == 0);\n\t\tPoly f({1}),g({1});\n\t\tfor(int n=1;n<s;n*=2){\n\t\t\tg = (g*2-g.square().low(n)*f).low(n);\n\
    \t\t\tPoly q = low(n).diff();\n\t\t\tq = q + g * (f.diff() - f*q).low(2*n-1);\n\
    \t\t\tf = (f + f * (low(2*n)-q.intg()) ).low(2*n);\n\t\t}\n\t\treturn f.low(s);\n\
    \t}\n\n\t// f^p mod x^s\n\t// 500000: 600ms\n\t// \u5C0E\u51FA: f^p = e^(p log\
    \ f)\n\t// log 1\u56DE\u3001 exp 1\u56DE\n\t// Exp.cpp (Mifafa technique) \u3082\
    \u53C2\u7167\n\t// \tc.f. (f \u306E non0 coef \u306E\u500B\u6570) * s\n\t// verify:\
    \ https://judge.yosupo.jp/submission/44992\n\tPoly pow(ll p, int s) const {\n\t\
    \tif(p == 0){\n\t\t\treturn Poly(s) + 1;\t// 0^0 is 1\n\t\t}\n\t\tint ord = 0;\n\
    \t\twhile(ord<s && !at(ord)) ord++;\n\t\tif((s-1)/p < ord) return Poly(s);\t//\
    \ s <= p * ord\n\t\tint off = p*ord;\n\t\tint s_ = s-off;\n\t\tconst mint a0 =\
    \ at(ord), ia0 = a0.inv(), ap = a0.pow(p);\n\t\tPoly f(s_); rep(i,s_) f[i] = at(i+ord)\
    \ * ia0;\n\t\tf = (f.log(s_) * p).exp(s_);\n\t\tPoly res(s);\n\t\trep(i,s_) res[i+off]\
    \ = f[i] * ap;\n\t\treturn res;\n\t}\n\n\t// f^(1/2) mod x^s\n\t// f[0] should\
    \ be 1\n\t// 11/6\n\t// verify: https://judge.yosupo.jp/submission/44997\n\tPoly\
    \ sqrt(int s) const {\n\t\tassert(at(0) == 1);\n\t\tstatic const mint i2 = mint(2).inv();\n\
    \t\tV<mint> f{1},g{1},z{1};\n\t\tfor(int n=1;n<s;n*=2){\n\t\t\trep(i,n) z[i] *=\
    \ z[i];\n\t\t\tinvfft(z);\n\t\t\tV<mint> d(2*n);\n\t\t\trep(i,n) d[n+i] = z[i]\
    \ - at(i) - at(n+i);\n\t\t\tfft(d);\n\t\t\tV<mint> g2(2*n);\n\t\t\trep(i,n) g2[i]\
    \ = g[i];\n\t\t\tfft(g2);\n\t\t\trep(i,n*2) d[i] *= g2[i];\n\t\t\tinvfft(d);\n\
    \t\t\tf.resize(n*2);\n\t\t\tfor(int i=n;i<n*2;i++) f[i] = -d[i] * i2;\n\t\t\t\
    if(n*2 >= s) break;\n\t\t\tz = f;\n\t\t\tfft(z);\n\t\t\tV<mint> eps = g2;\n\t\t\
    \trep(i,n*2) eps[i] *= z[i];\n\t\t\tinvfft(eps);\n\t\t\trep(i,n) eps[i] = 0;\n\
    \t\t\tfft(eps);\n\t\t\trep(i,n*2) eps[i] *= g2[i];\n\t\t\tinvfft(eps);\n\t\t\t\
    g.resize(n*2);\n\t\t\tfor(int i=n;i<n*2;i++) g[i] -= eps[i];\n\t\t}\n\t\tf.resize(s);\n\
    \t\treturn f;\n\t}\n};\n\n\nll norm_mod(ll a, ll m){\n\ta %= m; if(a < 0) a +=\
    \ m;\n\treturn a;\n}\n\n//p: odd (not necessarily prime)\nll jacobi(ll a,ll p){\n\
    \ta = norm_mod(a,p);\n\tauto sgn = [](ll x){ return x&1 ? -1 : 1; };\n\tif(a ==\
    \ 0) return p == 1;\n\telse if(a&1) return sgn(((p-1)&(a-1))>>1) * jacobi(p%a,a);\n\
    \telse return sgn(((p&15)*(p&15)-1)/8) * jacobi(a/2,p);\n}\n\n// p : prime\n//\
    \ 0 <= a < p\n// return smaller solution\n// if no solution, -1\nll sqrt_mod(ll\
    \ a,ll p){\n\tif(a == 0) return 0;\n\tif(p == 2) return 1;\n\tif(jacobi(a,p) ==\
    \ -1)return -1;\n\tll b,c;\n\tfor(b=0;;b++){\n\t\tc = norm_mod(b*b-a,p);\n\t\t\
    if(jacobi(c,p) == -1) break;\n\t}\n\tauto mul = [&](pair<ll,ll> x, pair<ll,ll>\
    \ y){\n\t\treturn pair<ll,ll>(norm_mod(x.fs*y.fs+x.sc*y.sc%p*c,p),norm_mod(x.fs*y.sc+x.sc*y.fs,p));\n\
    \t};\n\tpair<ll,ll> x(b,1),res(1,0);\n\tll n = (p+1)/2;\n\twhile(n){\n\t\tif(n&1)\
    \ res = mul(res,x);\n\t\tx = mul(x,x);\n\t\tn >>= 1;\n\t}\n\tassert(res.sc ==\
    \ 0);\n\treturn min(res.fs, p-res.fs);\n}\n\n// \u8F9E\u66F8\u9806\u6700\u5C0F\
    \n// no solution -> {}\nPoly<mint> sqrt(Poly<mint> f){\n\tint n = f.size();\n\t\
    int ord = 0;\n\twhile(ord<n && !f[ord]) ord++;\n\tif(ord == n) return {0};\n\t\
    if(ord&1) return {};\n\tll c0 = sqrt_mod(f[ord].v,mint::mod);\n\tif(c0 == -1)\
    \ return {};\n\tint n_ = n-ord;\n\tauto g = (Poly<mint>(f.begin()+ord,f.end())/f[ord]).sqrt(n_)\
    \ * c0;\n\tPoly<mint> res(ord/2 + n_);\n\trep(i,n_) res[ord/2 + i] = g[i];\n\t\
    return res;\n}\n\n// Q log^2 Q \u3067\u306F\u3042\u308B\n// \u9AD8\u901F\u306A\
    \u306E\u306F\u3046\u307E\u304F subproduct tree \u3092\u69CB\u7BC9\u3059\u308B\u3089\
    \u3057\u3044\n// maroon https://judge.yosupo.jp/submission/3240 160ms\n// verify:\
    \ https://judge.yosupo.jp/submission/45006 950ms \u304A\u305B\uFF5E\ntemplate<class\
    \ mint>\nV<mint> MultipointEval(const Poly<mint>& f, V<mint> a){\n\tint Q = a.size();\n\
    \tint s = 1; while(s < Q) s *= 2;\n\tV<Poly<mint>> g(s+s,{1});\n\trep(i,Q) g[s+i]\
    \ = {-a[i],1};\n\tfor(int i=s-1;i>0;i--) g[i] = g[i*2] * g[i*2+1];\n\tg[1] = f\
    \ % g[1];\n\tfor(int i=2;i<s+Q;i++) g[i] = g[i>>1] % g[i];\n\tV<mint> res(Q);\n\
    \trep(i,Q) res[i] = g[s+i][0];\n\treturn res;\n}\n\n// N log^2 N \u3067\u306F\u3042\
    \u308B\n// \u9AD8\u901F\u306A\u306E\u306F\u3046\u307E\u304F sub\u3046\u3093\u306C\
    \u3093\ntemplate<class mint>\nPoly<mint> interpolate(const V<mint>& x, const V<mint>&\
    \ y){\n\tint n = si(x);\n\tint s = 1; while(s<n) s*=2;\n\tV<Poly<mint>> g(s+s,{1}),\
    \ h(s+s);\n\trep(i,n) g[s+i] = {-x[i],1};\n\tfor(int i=s-1;i>0;i--) g[i] = g[i*2]\
    \ * g[i*2+1];\n\th[1] = g[1].diff();\n\tfor(int i=2;i<s+n;i++) h[i] = h[i>>1]\
    \ % g[i];\n\trep(i,n) h[s+i] = {y[i] / h[s+i][0]};\n\tfor(int i=s-1;i>0;i--) h[i]\
    \ = h[i*2]*g[i*2+1] + h[i*2+1]*g[i*2];\n\treturn h[1];\n}\n\n// [x^p] f/g\n//\
    \ O(n logn logp)\n// O(f logf + g logg logn) (f \u304C\u5927\u304D\u304F\u3066\
    \u3082\u3084\u3084OK)\n// verified: https://ac.nowcoder.com/acm/contest/11259/H\n\
    // hos,divAt : https://ac.nowcoder.com/acm/contest/view-submission?submissionId=48462458\n\
    \ntemplate<class T>\nT Kevinsogo(Poly<T> f, Poly<T> g, ll p){\n\tassert(g.at(0));\n\
    \twhile(p){\n\t\tauto gm = g;\n\t\tfor(int i=1;i<si(g);i+=2) gm[i] = -gm[i];\n\
    \t\tauto f2 = f*gm;\n\t\tauto g2 = g*gm;\n\t\tf.clear();g.clear();\n\t\tfor(int\
    \ i=p&1;i<si(f2);i+=2) f.set(i/2,f2[i]);\n\t\tfor(int i=0;i<si(g2);i+=2) g.set(i/2,g2[i]);\n\
    \t\tp /= 2;\n\t}\n\treturn f.at(0)/g.at(0);\n}\n\n/*\n\tinput:\n\t\t\u306F\u3058\
    \u3081 d \u9805: a_0, a_1, .., a_{d-1}\n\t\td+1 \u9805 reccurence: c_0 * a_{i+d}\
    \ + .. + c_d * a_i = 0\n\t\ta\u3092\u7121\u99C4\u306B\u4E0E\u3048\u3066\u3082\u826F\
    \u3044(\u8DB3\u308A\u306A\u3044\u3068\u3001\u30AB\u30B9)\n\t\tll k\n\toutput:\n\
    \t\ta_k\n\tO(d logd logk)\n\tverified: https://judge.yosupo.jp/problem/find_linear_recurrence\n\
    */\ntemplate<class T>\nT linearRecurrenceAt(V<T> a, V<T> c, ll k){\n\tassert(!c.empty()\
    \ && c[0]);\n\tint d = si(c) - 1;\n\tassert(si(a) >= d);\n\treturn Kevinsogo((Poly<T>(a.begin(),a.begin()+d)\
    \ * Poly<T>(c)).low(d), Poly<T>(c), k);\n}\n#line 61 \"test_oj/linear_recurrence.test.cpp\"\
    \n\nint main(){\n\tcin.tie(0);\n\tios::sync_with_stdio(false);\t\t//DON'T USE\
    \ scanf/printf/puts !!\n\tcout << fixed << setprecision(20);\n\n\tint d; ll k;\
    \ cin >> d >> k;\n\tV<mint> a(d); rep(i,d) cin >> a[i];\n\tV<mint> c(d+1); c[0]\
    \ = -1;\n\trep1(i,d) cin >> c[i];\n\tcout << linearRecurrenceAt(a,c,k) << endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ uint = unsigned int;\nusing ull = unsigned long long;\n#define rep(i,n) for(int\
    \ i=0;i<int(n);i++)\n#define rep1(i,n) for(int i=1;i<=int(n);i++)\n#define per(i,n)\
    \ for(int i=int(n)-1;i>=0;i--)\n#define per1(i,n) for(int i=int(n);i>0;i--)\n\
    #define all(c) c.begin(),c.end()\n#define si(x) int(x.size())\n#define pb emplace_back\n\
    #define fs first\n#define sc second\ntemplate<class T> using V = vector<T>;\n\
    template<class T> using VV = vector<vector<T>>;\ntemplate<class T,class U> void\
    \ chmax(T& x, U y){if(x<y) x=y;}\ntemplate<class T,class U> void chmin(T& x, U\
    \ y){if(y<x) x=y;}\ntemplate<class T> void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}\n\
    template<class T> int lwb(const V<T>& v, const T& a){return lower_bound(all(v),a)\
    \ - v.begin();}\ntemplate<class T>\nV<T> Vec(size_t a) {\n    return V<T>(a);\n\
    }\ntemplate<class T, class... Ts>\nauto Vec(size_t a, Ts... ts) {\n  return V<decltype(Vec<T>(ts...))>(a,\
    \ Vec<T>(ts...));\n}\ntemplate<class S,class T> ostream& operator<<(ostream& o,const\
    \ pair<S,T> &p){\n\treturn o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";\n}\ntemplate<class\
    \ T> ostream& operator<<(ostream& o,const vector<T> &vc){\n\to<<\"{\";\n\tfor(const\
    \ T& v:vc) o<<v<<\",\";\n\to<<\"}\";\n\treturn o;\n}\nconstexpr ll TEN(int n)\
    \ { return (n == 0) ? 1 : 10 * TEN(n-1); }\n\n#ifdef LOCAL\n#define show(x) cerr\
    \ << \"LINE\" << __LINE__ << \" : \" << #x << \" = \" << (x) << endl\nvoid dmpr(ostream&\
    \ os){os<<endl;}\ntemplate<class T,class... Args>\nvoid dmpr(ostream&os,const\
    \ T&t,const Args&... args){\n\tos<<t<<\" ~ \";\n\tdmpr(os,args...);\n}\n#define\
    \ shows(...) cerr << \"LINE\" << __LINE__ << \" : \";dmpr(cerr,##__VA_ARGS__)\n\
    #define dump(x) cerr << \"LINE\" << __LINE__ << \" : \" << #x << \" = {\";  \\\
    \n\tfor(auto v: x) cerr << v << \",\"; cerr << \"}\" << endl;\n#else\n#define\
    \ show(x) void(0)\n#define dump(x) void(0)\n#define shows(...) void(0)\n#endif\n\
    \n\n#include \"../math/poly.cpp\"\n\nint main(){\n\tcin.tie(0);\n\tios::sync_with_stdio(false);\t\
    \t//DON'T USE scanf/printf/puts !!\n\tcout << fixed << setprecision(20);\n\n\t\
    int d; ll k; cin >> d >> k;\n\tV<mint> a(d); rep(i,d) cin >> a[i];\n\tV<mint>\
    \ c(d+1); c[0] = -1;\n\trep1(i,d) cin >> c[i];\n\tcout << linearRecurrenceAt(a,c,k)\
    \ << endl;\n}\n"
  dependsOn:
  - math/poly.cpp
  isVerificationFile: true
  path: test_oj/linear_recurrence.test.cpp
  requiredBy: []
  timestamp: '2021-08-21 01:23:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test_oj/linear_recurrence.test.cpp
layout: document
redirect_from:
- /verify/test_oj/linear_recurrence.test.cpp
- /verify/test_oj/linear_recurrence.test.cpp.html
title: test_oj/linear_recurrence.test.cpp
---
