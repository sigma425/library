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
  bundledCode: "#line 1 \"data structure/fastset.cpp\"\n/*\n\tg++11 -O3\n\tfastset\
    \ 233[ms]\n\tset 7757[ms]\n\t\u3088\u3055\u305D\u3046\n*/\n#include <bits/stdc++.h>\n\
    #define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing\
    \ namespace std;\ntemplate<class S,class T> ostream& operator<<(ostream& o,const\
    \ pair<S,T> &p){\n\treturn o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";\n}\ntemplate<class\
    \ T> ostream& operator<<(ostream& o,const vector<T> &vc){\n\to<<\"{\";\n\tfor(const\
    \ T& v:vc) o<<v<<\",\";\n\to<<\"}\";\n\treturn o;\n}\nusing ll = long long;\n\
    template<class T> using V = vector<T>;\ntemplate<class T> using VV = vector<vector<T>>;\n\
    constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }\n\n#ifdef LOCAL\n\
    #define show(x) cerr << \"LINE\" << __LINE__ << \" : \" << #x << \" = \" << (x)\
    \ << endl\n#define dump(x) cerr << \"LINE\" << __LINE__ << \" : \" << #x << \"\
    \ = {\";  \\\n\tfor(auto v: x) cerr << v << \",\"; cerr << \"}\" << endl;\n#else\n\
    #define show(x) true\n#define dump(x) true\n#endif\n\nstruct FastSet{\t//[0,N)\n\
    \tusing ull = unsigned long long;\n\tint N,D;\n\tvector<vector<ull>> seg;\n\t\
    FastSet(int N_):N(N_){\n\t\tassert(N_ >= 1);\n\t\tif(N_ == 1) N_++;\n\t\twhile(N_>1){\n\
    \t\t\tN_ = (N_+63)>>6;\n\t\t\tseg.pb(vector<ull>(N_));\n\t\t}\n\t\tD = seg.size();\n\
    \t}\n\tvoid insert(int x){\n\t\trep(d,D){\n\t\t\tull b = 1ull<<(x&63);\n\t\t\t\
    x >>= 6;\n\t\t\tseg[d][x] |= b;\n\t\t}\n\t}\n\tvoid erase(int x){\t//\u306A\u304F\
    \u3066\u3082\u3088\u3093\u3067\u3044\u3044\n\t\trep(d,D){\n\t\t\tull b = 1ull<<(x&63);\n\
    \t\t\tx >>= 6;\n\t\t\tseg[d][x] &= ~b;\n\t\t\tif(seg[d][x]) break;\n\t\t}\n\t\
    }\n\tint geq(int x){\t\t//x<=res\n\t\tif(x >= N) return N;\n\t\tif(x < 0) x =\
    \ 0;\n\t\trep(d,D){\n\t\t\tint i = x>>6, r = x&63;\n\t\t\tif(i == (int)seg[d].size())\
    \ break;\n\t\t\tull b = seg[d][i]>>r;\n\t\t\tif(b){\n\t\t\t\tx += bsf(b);\n\t\t\
    \t\twhile(d--){\n\t\t\t\t\tx = (x<<6)|bsf(seg[d][x]);\n\t\t\t\t}\n\t\t\t\treturn\
    \ x;\n\t\t\t}else{\n\t\t\t\tx = (x>>6)+1;\n\t\t\t}\n\t\t}\n\t\treturn N;\n\t}\n\
    \tint leq(int x){\t\t//res<=x\n\t\tif(x < 0) return -1;\n\t\tif(x >= N) x = N-1;\n\
    \t\trep(d,D){\n\t\t\tif(x == -1) break;\n\t\t\tint i = x>>6, r = x&63;\n\t\t\t\
    ull b = seg[d][i]<<(r^63);\n\t\t\tif(b){\n\t\t\t\tx -= bsr(b)^63;\n\t\t\t\twhile(d--){\n\
    \t\t\t\t\tx = (x<<6)|bsr(seg[d][x]);\n\t\t\t\t}\n\t\t\t\treturn x;\n\t\t\t}\n\t\
    \t\tx = (x>>6)-1;\n\t\t}\n\t\treturn -1;\n\t}\n\tbool has(int x){\n\t\tif(x<0\
    \ || x>=N) return false;\n\t\treturn (seg[0][x>>6]>>(x&63))&1;\n\t}\n\n\tint bsr(ull\
    \ x){return __builtin_clzll(x)^63;}\n\tint bsf(ull x){return __builtin_ctzll(x);}\n\
    \n};\n\n\nstruct Timer{\n\tclock_t st;\n\tvoid start(){\n\t\tst = clock();\n\t\
    }\n\tint ms(){\n\t\treturn (clock()-st)*1000 / CLOCKS_PER_SEC;\n\t}\n};\n\nvoid\
    \ unittest(){\n\tsrand((unsigned)time(NULL));\n\tint N = 1e7;\n\n\tvector<int>\
    \ qs,qs2,qs3;\n\tint T = 1e7;\n\trep(i,T){\n\t\tqs.pb(rand()%(N));\n\t}\n\trep(i,T){\n\
    \t\tqs2.pb(rand()%N);\n\t}\n\trep(i,T){\n\t\tqs3.pb(rand()%N);\n\t}\n\n\tvector<int>\
    \ ans,ans2;\n\t{\n\t\tTimer tm;\n\t\ttm.start();\n\t\tFastSet st(N);\n\t\trep(i,T){\n\
    \t\t\tst.insert(qs[i]);\n\t\t\tint v = st.geq(qs2[i]);\n\t\t\tans.pb(v);\n\t\t\
    \tv = st.leq(qs2[i]);\n\t\t\tans.pb(v);\n\t\t\tst.erase(qs3[i]);\n\t\t}\n\t\t\
    printf(\"fastset %d[ms]\\n\",tm.ms());\n\t}\n\t{\n\t\tTimer tm;\n\t\ttm.start();\n\
    \t\tset<int> st;\n\t\tst.insert(-1);\n\t\tst.insert(N);\n\t\trep(i,T){\n\t\t\t\
    st.insert(qs[i]);\n\t\t\tint v = *st.lower_bound(qs2[i]);\n\t\t\tans2.pb(v);\n\
    \t\t\tauto it = st.upper_bound(qs2[i]);\n\t\t\tit--;\n\t\t\tans2.pb(*it);\n\t\t\
    \tst.erase(qs3[i]);\n\t\t}\n\t\tprintf(\"set %d[ms]\\n\",tm.ms());\n\t}\n\tassert(ans\
    \ == ans2);\n}\nint main(){\n\tint N; cin >> N;\n\tFastSet st(N);\n\twhile(true){\n\
    \t\tstring s; cin >> s;\n\t\tint x; cin >> x;\n\t\tif(s == \"insert\"){\n\t\t\t\
    st.insert(x);\n\t\t}else if(s == \"erase\"){\n\t\t\tst.erase(x);\n\t\t}else if(s\
    \ == \"leq\"){\n\t\t\tshow(st.leq(x));\n\t\t}else if(s == \"geq\"){\n\t\t\tshow(st.geq(x));\n\
    \t\t}else if(s == \"has\"){\n\t\t\tshow(st.has(x));\n\t\t}else{\n\t\t\tcerr <<\
    \ \"waf\" << endl;\n\t\t}\n\t}\n\tunittest();\n}\n"
  code: "/*\n\tg++11 -O3\n\tfastset 233[ms]\n\tset 7757[ms]\n\t\u3088\u3055\u305D\u3046\
    \n*/\n#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){\n\treturn o<<\"\
    (\"<<p.fs<<\",\"<<p.sc<<\")\";\n}\ntemplate<class T> ostream& operator<<(ostream&\
    \ o,const vector<T> &vc){\n\to<<\"{\";\n\tfor(const T& v:vc) o<<v<<\",\";\n\t\
    o<<\"}\";\n\treturn o;\n}\nusing ll = long long;\ntemplate<class T> using V =\
    \ vector<T>;\ntemplate<class T> using VV = vector<vector<T>>;\nconstexpr ll TEN(int\
    \ n) { return (n == 0) ? 1 : 10 * TEN(n-1); }\n\n#ifdef LOCAL\n#define show(x)\
    \ cerr << \"LINE\" << __LINE__ << \" : \" << #x << \" = \" << (x) << endl\n#define\
    \ dump(x) cerr << \"LINE\" << __LINE__ << \" : \" << #x << \" = {\";  \\\n\tfor(auto\
    \ v: x) cerr << v << \",\"; cerr << \"}\" << endl;\n#else\n#define show(x) true\n\
    #define dump(x) true\n#endif\n\nstruct FastSet{\t//[0,N)\n\tusing ull = unsigned\
    \ long long;\n\tint N,D;\n\tvector<vector<ull>> seg;\n\tFastSet(int N_):N(N_){\n\
    \t\tassert(N_ >= 1);\n\t\tif(N_ == 1) N_++;\n\t\twhile(N_>1){\n\t\t\tN_ = (N_+63)>>6;\n\
    \t\t\tseg.pb(vector<ull>(N_));\n\t\t}\n\t\tD = seg.size();\n\t}\n\tvoid insert(int\
    \ x){\n\t\trep(d,D){\n\t\t\tull b = 1ull<<(x&63);\n\t\t\tx >>= 6;\n\t\t\tseg[d][x]\
    \ |= b;\n\t\t}\n\t}\n\tvoid erase(int x){\t//\u306A\u304F\u3066\u3082\u3088\u3093\
    \u3067\u3044\u3044\n\t\trep(d,D){\n\t\t\tull b = 1ull<<(x&63);\n\t\t\tx >>= 6;\n\
    \t\t\tseg[d][x] &= ~b;\n\t\t\tif(seg[d][x]) break;\n\t\t}\n\t}\n\tint geq(int\
    \ x){\t\t//x<=res\n\t\tif(x >= N) return N;\n\t\tif(x < 0) x = 0;\n\t\trep(d,D){\n\
    \t\t\tint i = x>>6, r = x&63;\n\t\t\tif(i == (int)seg[d].size()) break;\n\t\t\t\
    ull b = seg[d][i]>>r;\n\t\t\tif(b){\n\t\t\t\tx += bsf(b);\n\t\t\t\twhile(d--){\n\
    \t\t\t\t\tx = (x<<6)|bsf(seg[d][x]);\n\t\t\t\t}\n\t\t\t\treturn x;\n\t\t\t}else{\n\
    \t\t\t\tx = (x>>6)+1;\n\t\t\t}\n\t\t}\n\t\treturn N;\n\t}\n\tint leq(int x){\t\
    \t//res<=x\n\t\tif(x < 0) return -1;\n\t\tif(x >= N) x = N-1;\n\t\trep(d,D){\n\
    \t\t\tif(x == -1) break;\n\t\t\tint i = x>>6, r = x&63;\n\t\t\tull b = seg[d][i]<<(r^63);\n\
    \t\t\tif(b){\n\t\t\t\tx -= bsr(b)^63;\n\t\t\t\twhile(d--){\n\t\t\t\t\tx = (x<<6)|bsr(seg[d][x]);\n\
    \t\t\t\t}\n\t\t\t\treturn x;\n\t\t\t}\n\t\t\tx = (x>>6)-1;\n\t\t}\n\t\treturn\
    \ -1;\n\t}\n\tbool has(int x){\n\t\tif(x<0 || x>=N) return false;\n\t\treturn\
    \ (seg[0][x>>6]>>(x&63))&1;\n\t}\n\n\tint bsr(ull x){return __builtin_clzll(x)^63;}\n\
    \tint bsf(ull x){return __builtin_ctzll(x);}\n\n};\n\n\nstruct Timer{\n\tclock_t\
    \ st;\n\tvoid start(){\n\t\tst = clock();\n\t}\n\tint ms(){\n\t\treturn (clock()-st)*1000\
    \ / CLOCKS_PER_SEC;\n\t}\n};\n\nvoid unittest(){\n\tsrand((unsigned)time(NULL));\n\
    \tint N = 1e7;\n\n\tvector<int> qs,qs2,qs3;\n\tint T = 1e7;\n\trep(i,T){\n\t\t\
    qs.pb(rand()%(N));\n\t}\n\trep(i,T){\n\t\tqs2.pb(rand()%N);\n\t}\n\trep(i,T){\n\
    \t\tqs3.pb(rand()%N);\n\t}\n\n\tvector<int> ans,ans2;\n\t{\n\t\tTimer tm;\n\t\t\
    tm.start();\n\t\tFastSet st(N);\n\t\trep(i,T){\n\t\t\tst.insert(qs[i]);\n\t\t\t\
    int v = st.geq(qs2[i]);\n\t\t\tans.pb(v);\n\t\t\tv = st.leq(qs2[i]);\n\t\t\tans.pb(v);\n\
    \t\t\tst.erase(qs3[i]);\n\t\t}\n\t\tprintf(\"fastset %d[ms]\\n\",tm.ms());\n\t\
    }\n\t{\n\t\tTimer tm;\n\t\ttm.start();\n\t\tset<int> st;\n\t\tst.insert(-1);\n\
    \t\tst.insert(N);\n\t\trep(i,T){\n\t\t\tst.insert(qs[i]);\n\t\t\tint v = *st.lower_bound(qs2[i]);\n\
    \t\t\tans2.pb(v);\n\t\t\tauto it = st.upper_bound(qs2[i]);\n\t\t\tit--;\n\t\t\t\
    ans2.pb(*it);\n\t\t\tst.erase(qs3[i]);\n\t\t}\n\t\tprintf(\"set %d[ms]\\n\",tm.ms());\n\
    \t}\n\tassert(ans == ans2);\n}\nint main(){\n\tint N; cin >> N;\n\tFastSet st(N);\n\
    \twhile(true){\n\t\tstring s; cin >> s;\n\t\tint x; cin >> x;\n\t\tif(s == \"\
    insert\"){\n\t\t\tst.insert(x);\n\t\t}else if(s == \"erase\"){\n\t\t\tst.erase(x);\n\
    \t\t}else if(s == \"leq\"){\n\t\t\tshow(st.leq(x));\n\t\t}else if(s == \"geq\"\
    ){\n\t\t\tshow(st.geq(x));\n\t\t}else if(s == \"has\"){\n\t\t\tshow(st.has(x));\n\
    \t\t}else{\n\t\t\tcerr << \"waf\" << endl;\n\t\t}\n\t}\n\tunittest();\n}"
  dependsOn: []
  isVerificationFile: false
  path: data structure/fastset.cpp
  requiredBy: []
  timestamp: '2019-11-14 14:24:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/fastset.cpp
layout: document
redirect_from:
- /library/data structure/fastset.cpp
- /library/data structure/fastset.cpp.html
title: data structure/fastset.cpp
---
