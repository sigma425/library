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
  bundledCode: "#line 1 \"math/FFT.cpp\"\n/*\n\t\u53E4\u3044\u3093\u3060\u3051\u3069\
    double\u304C\u307B\u3057\u3051\u308C\u3070\u3053\u3063\u3061\u4F7F\u3046\u304B\
    \n\tNTT\u306F poly.cpp \u3092\u53C2\u7167\n\n\tFFT, NTT\n\tFFT\u3057\u305F\u5F8C\
    \u306E\u914D\u5217\u306B\u5165\u3063\u3066\u3044\u308B\u5024\u306F\u3001\u672C\
    \u6765\u5165\u308B\u3079\u304D\u5024\u3068\u306E\u76F8\u5BFE\u8AA4\u5DEE\u304C\
    2^-53 * log2(\u914D\u5217\u9577)\u3050\u3089\u3044\u3089\u3057\u3044\n\t\u914D\
    \u5217\u9577N,\u5024X\u3068\u3059\u308B\u3068, NXX >= 2^53 \u304F\u3089\u3044\u306B\
    \u306A\u308B\u3068\u7D76\u5BFE\u8AA4\u5DEE\u304C1\u304F\u3089\u3044\u306B\u306A\
    \u308A\u307E\u305A\u3044\n\t\u306A\u306E\u3067, X=10^9 -> \u6B7B\n\t\u305D\u3053\
    \u3067, \u5024\u30923\u6841\u306E1024\u9032\u6CD5\u3068\u306E\u6570\u307F\u306A\
    \u3057\u3066\u5206\u5272\u3057\u3066\u7B46\u7B97\u3092\u3059\u308B.\u7B46\u7B97\
    \u306E\u5404\u304B\u3051\u3056\u3093\u304CFFT\u3067,\u3042\u3068\u306F\u666E\u901A\
    \u306B\u7B46\u7B97\u306E\u3088\u3046\u306B\u8DB3\u3057\u7B97\u3059\u308B.\n\t\
    multiply_fft3 -> 3\u5206\u5272 1024\u9032\u6CD5\t\tN*1024*1024 >= 2^53   <=> \
    \  N>=2^30 \u306A\u306E\u3067\u7D76\u5BFE\u5927\u4E08\u592B\n\tmultiply_fft2 ->\
    \ 2\u5206\u5272 2^15\u9032\u6CD5\t\tN*(2^15)^2 >= 2^53   <=>   N>=2^23 \u306A\u306E\
    \u3067\u307E\u3042\u5927\u4E08\u592B?\n\n\tB bit \u3054\u3068 K\u500B\u306B\u5206\
    \u5272\u3059\u308B \u306E B,K \u304C\u5B9A\u6570\u306B\u306A\u3063\u3066\u3044\
    \u308B\u3001\u666E\u901A B = 15, K = 2\n*/\n\n\nint bsr(int x) { return 31 - __builtin_clz(x);\
    \ }\nusing D = double;\nconst D pi = acos(-1);\nusing Pc = complex<D>;\n\nvoid\
    \ fft(bool type, vector<Pc> &c){\t//multiply : false -> mult -> true\n\tstatic\
    \ vector<Pc> buf[30];\n\tint N = c.size();\n\tint s = bsr(N);\n\tassert(1<<s ==\
    \ N);\n\tif(buf[s].empty()){\n\t\tbuf[s]=vector<Pc>(N);\n\t\trep(i,N) buf[s][i]\
    \ = polar<D>(1,i*2*pi/N);\n\t}\n\tvector<Pc> a(N),b(N);\n\tcopy(begin(c),end(c),begin(a));\n\
    \trep1(i,s){\n\t\tint W = 1<<(s-i);\n\t\tfor(int y=0;y<N/2;y+=W){\n\t\t\tPc now\
    \ = buf[s][y];\n\t\t\tif(type) now = conj(now);\n\t\t\trep(x,W){\n\t\t\t\tauto\
    \ l =       a[y<<1 | x];\n\t\t\t\tauto r = now * a[y<<1 | x | W];\n\t\t\t\tb[y\
    \ | x]        = l+r;\n\t\t\t\tb[y | x | N>>1] = l-r;\n\t\t\t}\n\t\t}\n\t\tswap(a,b);\n\
    \t}\n\tcopy(begin(a),end(a),begin(c));\n}\n\n\n/*\n\tlong long/mint \u7528\n\t\
    \u6700\u5F8Cround\u3057\u3066\u30AD\u30E3\u30B9\u30C8\u3059\u308B\n*/\n\ntemplate<class\
    \ Mint>\nvector<Mint> multiply_fft(const vector<Mint>& x,const vector<Mint>& y){\n\
    \tif(x.empty() || y.empty()) return {};\n\tconst int B = 15;\n\tconst int K =\
    \ 2;\n\tint S = x.size()+y.size()-1;\n\tint N = 1; while(N<S) N*=2;\n\tvector<Pc>\
    \ a[K],b[K];\n\trep(t,K){\n\t\ta[t] = vector<Pc>(N);\n\t\tb[t] = vector<Pc>(N);\n\
    \t\trep(i,x.size()) a[t][i] = Pc( (x[i].v >> (t*B)) & ((1<<B)-1) , 0 );\n\t\t\
    rep(i,y.size()) b[t][i] = Pc( (y[i].v >> (t*B)) & ((1<<B)-1) , 0 );\n\t\tfft(false,a[t]);\n\
    \t\tfft(false,b[t]);\n\t}\n\tvector<Mint> z(S);\n\tvector<Pc> c(N);\n\tMint base\
    \ = 1;\n\trep(t,K+K-1){\n\t\tfill_n(begin(c),N,Pc(0,0));\n\t\trep(xt,K){\n\t\t\
    \tint yt = t-xt;\n\t\t\tif(0<=yt && yt<K){\n\t\t\t\trep(i,N) c[i] += a[xt][i]\
    \ * b[yt][i];\n\t\t\t}\n\t\t}\n\t\tfft(true,c);\n\t\trep(i,S){\n\t\t\tc[i] *=\
    \ 1.0/N;\n\t\t\tz[i] += Mint(ll(round(c[i].real()))) * base;\n\t\t}\n\t\tbase\
    \ *= 1<<B;\n\t}\n\treturn z;\n}\n\n/*\n\tdouble \u7528\n\t\u304B\u3051\u3056\u3093\
    \n*/\ntemplate<class D>\nvector<D> multiply_fft(const vector<D>& x,const vector<D>&\
    \ y){\n\tif(x.empty() || y.empty()) return {};\n\tint S = x.size()+y.size()-1;\n\
    \tint N = 1; while(N<S) N*=2;\n\tvector<Pc> a(N),b(N);\n\trep(i,x.size()) a[i]\
    \ = Pc( x[i] , 0 );\n\trep(i,y.size()) b[i] = Pc( y[i] , 0 );\n\tfft(false,a);\n\
    \tfft(false,b);\n\n\tvector<D> z(S);\n\tvector<Pc> c(N);\n\trep(i,N) c[i] = a[i]*b[i];\n\
    \tfft(true,c);\n\trep(i,S){\n\t\tc[i] *= 1.0/N;\n\t\tz[i] = c[i].real();\n\t}\n\
    \treturn z;\n}\n\n/*\n\tNTT\n\tK=2 \u306EFFT\u3088\u308A\u306F\u5727\u5012\u7684\
    \u306B\u901F\u3044\u306E\u3067\u307E\u3068\u3082mod\u306A\u3089\u7D76\u5BFE\u3053\
    \u3063\u3061\n\t\u539F\u5B50\u6839 G=3 \u3092\u5909\u3048\u308B\u3053\u3068\uFF01\
    \uFF01(998244353 \u306A\u3089 3 \u3067\u3044\u3044)\n*/\nint bsr(int x) { return\
    \ 31 - __builtin_clz(x); }\nvoid ntt(bool type, V<mint>& c) {\n\tconst mint G\
    \ = 3;\t//primitive root\n\n\tint N = int(c.size());\n\tint s = bsr(N);\n\tassert(1\
    \ << s == N);\n\n\tV<mint> a = c, b(N);\n\trep1(i,s){\n\t\tint W = 1 << (s - i);\n\
    \t\tmint base = G.pow((mint::mod - 1)>>i);\n\t\tif(type) base = base.inv();\n\t\
    \tmint now = 1;\n\t\tfor(int y = 0; y < N / 2; y += W) {\n\t\t\tfor (int x = 0;\
    \ x < W; x++) {\n\t\t\t\tauto l = a[y << 1 | x];\n\t\t\t\tauto r = now * a[y <<\
    \ 1 | x | W];\n\t\t\t\tb[y | x] = l + r;\n\t\t\t\tb[y | x | N >> 1] = l - r;\n\
    \t\t\t}\n\t\t\tnow *= base;\n\t\t}\n\t\tswap(a, b);\n\t}\n\tc = a;\n}\n\nV<mint>\
    \ multiply_ntt(const V<mint>& a, const V<mint>& b) {\n\tint A = int(a.size()),\
    \ B = int(b.size());\n\tif (!A || !B) return {};\n\tint lg = 0;\n\twhile ((1 <<\
    \ lg) < A + B - 1) lg++;\n\tint N = 1 << lg;\n\tV<mint> ac(N), bc(N);\n\tfor (int\
    \ i = 0; i < A; i++) ac[i] = a[i];\n\tfor (int i = 0; i < B; i++) bc[i] = b[i];\n\
    \tntt(false, ac);\n\tntt(false, bc);\n\tfor (int i = 0; i < N; i++) {\n\t\tac[i]\
    \ *= bc[i];\n\t}\n\tntt(true, ac);\n\tV<mint> c(A + B - 1);\n\tmint iN = mint(N).inv();\n\
    \tfor (int i = 0; i < A + B - 1; i++) {\n\t\tc[i] = ac[i] * iN;\n\t}\n\treturn\
    \ c;\n}\n"
  code: "/*\n\t\u53E4\u3044\u3093\u3060\u3051\u3069double\u304C\u307B\u3057\u3051\u308C\
    \u3070\u3053\u3063\u3061\u4F7F\u3046\u304B\n\tNTT\u306F poly.cpp \u3092\u53C2\u7167\
    \n\n\tFFT, NTT\n\tFFT\u3057\u305F\u5F8C\u306E\u914D\u5217\u306B\u5165\u3063\u3066\
    \u3044\u308B\u5024\u306F\u3001\u672C\u6765\u5165\u308B\u3079\u304D\u5024\u3068\
    \u306E\u76F8\u5BFE\u8AA4\u5DEE\u304C2^-53 * log2(\u914D\u5217\u9577)\u3050\u3089\
    \u3044\u3089\u3057\u3044\n\t\u914D\u5217\u9577N,\u5024X\u3068\u3059\u308B\u3068\
    , NXX >= 2^53 \u304F\u3089\u3044\u306B\u306A\u308B\u3068\u7D76\u5BFE\u8AA4\u5DEE\
    \u304C1\u304F\u3089\u3044\u306B\u306A\u308A\u307E\u305A\u3044\n\t\u306A\u306E\u3067\
    , X=10^9 -> \u6B7B\n\t\u305D\u3053\u3067, \u5024\u30923\u6841\u306E1024\u9032\u6CD5\
    \u3068\u306E\u6570\u307F\u306A\u3057\u3066\u5206\u5272\u3057\u3066\u7B46\u7B97\
    \u3092\u3059\u308B.\u7B46\u7B97\u306E\u5404\u304B\u3051\u3056\u3093\u304CFFT\u3067\
    ,\u3042\u3068\u306F\u666E\u901A\u306B\u7B46\u7B97\u306E\u3088\u3046\u306B\u8DB3\
    \u3057\u7B97\u3059\u308B.\n\tmultiply_fft3 -> 3\u5206\u5272 1024\u9032\u6CD5\t\
    \tN*1024*1024 >= 2^53   <=>   N>=2^30 \u306A\u306E\u3067\u7D76\u5BFE\u5927\u4E08\
    \u592B\n\tmultiply_fft2 -> 2\u5206\u5272 2^15\u9032\u6CD5\t\tN*(2^15)^2 >= 2^53\
    \   <=>   N>=2^23 \u306A\u306E\u3067\u307E\u3042\u5927\u4E08\u592B?\n\n\tB bit\
    \ \u3054\u3068 K\u500B\u306B\u5206\u5272\u3059\u308B \u306E B,K \u304C\u5B9A\u6570\
    \u306B\u306A\u3063\u3066\u3044\u308B\u3001\u666E\u901A B = 15, K = 2\n*/\n\n\n\
    int bsr(int x) { return 31 - __builtin_clz(x); }\nusing D = double;\nconst D pi\
    \ = acos(-1);\nusing Pc = complex<D>;\n\nvoid fft(bool type, vector<Pc> &c){\t\
    //multiply : false -> mult -> true\n\tstatic vector<Pc> buf[30];\n\tint N = c.size();\n\
    \tint s = bsr(N);\n\tassert(1<<s == N);\n\tif(buf[s].empty()){\n\t\tbuf[s]=vector<Pc>(N);\n\
    \t\trep(i,N) buf[s][i] = polar<D>(1,i*2*pi/N);\n\t}\n\tvector<Pc> a(N),b(N);\n\
    \tcopy(begin(c),end(c),begin(a));\n\trep1(i,s){\n\t\tint W = 1<<(s-i);\n\t\tfor(int\
    \ y=0;y<N/2;y+=W){\n\t\t\tPc now = buf[s][y];\n\t\t\tif(type) now = conj(now);\n\
    \t\t\trep(x,W){\n\t\t\t\tauto l =       a[y<<1 | x];\n\t\t\t\tauto r = now * a[y<<1\
    \ | x | W];\n\t\t\t\tb[y | x]        = l+r;\n\t\t\t\tb[y | x | N>>1] = l-r;\n\t\
    \t\t}\n\t\t}\n\t\tswap(a,b);\n\t}\n\tcopy(begin(a),end(a),begin(c));\n}\n\n\n\
    /*\n\tlong long/mint \u7528\n\t\u6700\u5F8Cround\u3057\u3066\u30AD\u30E3\u30B9\
    \u30C8\u3059\u308B\n*/\n\ntemplate<class Mint>\nvector<Mint> multiply_fft(const\
    \ vector<Mint>& x,const vector<Mint>& y){\n\tif(x.empty() || y.empty()) return\
    \ {};\n\tconst int B = 15;\n\tconst int K = 2;\n\tint S = x.size()+y.size()-1;\n\
    \tint N = 1; while(N<S) N*=2;\n\tvector<Pc> a[K],b[K];\n\trep(t,K){\n\t\ta[t]\
    \ = vector<Pc>(N);\n\t\tb[t] = vector<Pc>(N);\n\t\trep(i,x.size()) a[t][i] = Pc(\
    \ (x[i].v >> (t*B)) & ((1<<B)-1) , 0 );\n\t\trep(i,y.size()) b[t][i] = Pc( (y[i].v\
    \ >> (t*B)) & ((1<<B)-1) , 0 );\n\t\tfft(false,a[t]);\n\t\tfft(false,b[t]);\n\t\
    }\n\tvector<Mint> z(S);\n\tvector<Pc> c(N);\n\tMint base = 1;\n\trep(t,K+K-1){\n\
    \t\tfill_n(begin(c),N,Pc(0,0));\n\t\trep(xt,K){\n\t\t\tint yt = t-xt;\n\t\t\t\
    if(0<=yt && yt<K){\n\t\t\t\trep(i,N) c[i] += a[xt][i] * b[yt][i];\n\t\t\t}\n\t\
    \t}\n\t\tfft(true,c);\n\t\trep(i,S){\n\t\t\tc[i] *= 1.0/N;\n\t\t\tz[i] += Mint(ll(round(c[i].real())))\
    \ * base;\n\t\t}\n\t\tbase *= 1<<B;\n\t}\n\treturn z;\n}\n\n/*\n\tdouble \u7528\
    \n\t\u304B\u3051\u3056\u3093\n*/\ntemplate<class D>\nvector<D> multiply_fft(const\
    \ vector<D>& x,const vector<D>& y){\n\tif(x.empty() || y.empty()) return {};\n\
    \tint S = x.size()+y.size()-1;\n\tint N = 1; while(N<S) N*=2;\n\tvector<Pc> a(N),b(N);\n\
    \trep(i,x.size()) a[i] = Pc( x[i] , 0 );\n\trep(i,y.size()) b[i] = Pc( y[i] ,\
    \ 0 );\n\tfft(false,a);\n\tfft(false,b);\n\n\tvector<D> z(S);\n\tvector<Pc> c(N);\n\
    \trep(i,N) c[i] = a[i]*b[i];\n\tfft(true,c);\n\trep(i,S){\n\t\tc[i] *= 1.0/N;\n\
    \t\tz[i] = c[i].real();\n\t}\n\treturn z;\n}\n\n/*\n\tNTT\n\tK=2 \u306EFFT\u3088\
    \u308A\u306F\u5727\u5012\u7684\u306B\u901F\u3044\u306E\u3067\u307E\u3068\u3082\
    mod\u306A\u3089\u7D76\u5BFE\u3053\u3063\u3061\n\t\u539F\u5B50\u6839 G=3 \u3092\
    \u5909\u3048\u308B\u3053\u3068\uFF01\uFF01(998244353 \u306A\u3089 3 \u3067\u3044\
    \u3044)\n*/\nint bsr(int x) { return 31 - __builtin_clz(x); }\nvoid ntt(bool type,\
    \ V<mint>& c) {\n\tconst mint G = 3;\t//primitive root\n\n\tint N = int(c.size());\n\
    \tint s = bsr(N);\n\tassert(1 << s == N);\n\n\tV<mint> a = c, b(N);\n\trep1(i,s){\n\
    \t\tint W = 1 << (s - i);\n\t\tmint base = G.pow((mint::mod - 1)>>i);\n\t\tif(type)\
    \ base = base.inv();\n\t\tmint now = 1;\n\t\tfor(int y = 0; y < N / 2; y += W)\
    \ {\n\t\t\tfor (int x = 0; x < W; x++) {\n\t\t\t\tauto l = a[y << 1 | x];\n\t\t\
    \t\tauto r = now * a[y << 1 | x | W];\n\t\t\t\tb[y | x] = l + r;\n\t\t\t\tb[y\
    \ | x | N >> 1] = l - r;\n\t\t\t}\n\t\t\tnow *= base;\n\t\t}\n\t\tswap(a, b);\n\
    \t}\n\tc = a;\n}\n\nV<mint> multiply_ntt(const V<mint>& a, const V<mint>& b) {\n\
    \tint A = int(a.size()), B = int(b.size());\n\tif (!A || !B) return {};\n\tint\
    \ lg = 0;\n\twhile ((1 << lg) < A + B - 1) lg++;\n\tint N = 1 << lg;\n\tV<mint>\
    \ ac(N), bc(N);\n\tfor (int i = 0; i < A; i++) ac[i] = a[i];\n\tfor (int i = 0;\
    \ i < B; i++) bc[i] = b[i];\n\tntt(false, ac);\n\tntt(false, bc);\n\tfor (int\
    \ i = 0; i < N; i++) {\n\t\tac[i] *= bc[i];\n\t}\n\tntt(true, ac);\n\tV<mint>\
    \ c(A + B - 1);\n\tmint iN = mint(N).inv();\n\tfor (int i = 0; i < A + B - 1;\
    \ i++) {\n\t\tc[i] = ac[i] * iN;\n\t}\n\treturn c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/FFT.cpp
  requiredBy: []
  timestamp: '2021-04-19 18:48:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/FFT.cpp
layout: document
redirect_from:
- /library/math/FFT.cpp
- /library/math/FFT.cpp.html
title: math/FFT.cpp
---
