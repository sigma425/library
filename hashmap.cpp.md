---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - http://xorshift.di.unimi.it/splitmix64.c
    - https://codeforces.com/blog/entry/62393
    - https://codeforces.com/gym/102361/submission/61948583
  bundledCode: "#line 1 \"hashmap.cpp\"\n/*\n\thttps://codeforces.com/blog/entry/62393\n\
    */\nstruct custom_hash {\n\tstatic uint64_t splitmix64(uint64_t x) {\n\t\t// http://xorshift.di.unimi.it/splitmix64.c\n\
    \t\tx += 0x9e3779b97f4a7c15;\n\t\tx = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\t\
    \tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\t\treturn x ^ (x >> 31);\n\t}\n\
    \ \n\tsize_t operator()(uint64_t x) const {\n\t\tstatic const uint64_t FIXED_RANDOM\
    \ = chrono::steady_clock::now().time_since_epoch().count();\n\t\treturn splitmix64(x\
    \ + FIXED_RANDOM);\n\t}\n};\n \ntemplate<class t,class u>\nusing hashmap = gp_hash_table<t,u,custom_hash>;\n\
    \n\n/*\n    https://codeforces.com/gym/102361/submission/61948583\n\t\u9AD8\u901F\
    \u3060\u3051\u3069\u3001mod S \u3067\u308F\u3051\u308B\u304B\u306A\u308A\u30E1\
    \u30C1\u30E3\u30AF\u30C1\u30E3\u306A\u30CF\u30C3\u30B7\u30E5\u306A\u306E\u3067\
    \u3069\u3046\u3057\u3066\u3082\u3063\u3066\u3068\u304D\u4EE5\u5916\u306F\u4F7F\
    \u308F\u306A\u3044\n\tS \u306F \u6700\u5927mapsize \u3088\u308A\u5927\u304D\u304F\
    \u8A2D\u5B9A\n*/\nstruct HashMap{\n\tconst int S = ;\n    int N=0,fst[S];\n\t\
    ll va[S]; int nxt[S],vb[S];\n\tvoid clear(){\n\t\tmemset(fst,0,sizeof fst); N=0;\n\
    \t}\n\tvoid add(ll x){\n\t\tint c=x%S; if(c<0) c=-c;\n\t\tfor(int e=fst[c];e;e=nxt[e])\n\
    \t\t\tif(va[e]==x) {++vb[e]; return;}\n\t\t++N; va[N]=x; vb[N]=1;\n\t\tnxt[N]=fst[c];\
    \ fst[c]=N;\n\t}\n\tint operator [] (ll x){\n\t\tint c=x%S; if(c<0) c=-c;\n\t\t\
    for(int e=fst[c];e;e=nxt[e])\n\t\t\tif(va[e]==x) return vb[e];\n\t\treturn 0;\n\
    \t}\n};\n"
  code: "/*\n\thttps://codeforces.com/blog/entry/62393\n*/\nstruct custom_hash {\n\
    \tstatic uint64_t splitmix64(uint64_t x) {\n\t\t// http://xorshift.di.unimi.it/splitmix64.c\n\
    \t\tx += 0x9e3779b97f4a7c15;\n\t\tx = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\t\
    \tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\t\treturn x ^ (x >> 31);\n\t}\n\
    \ \n\tsize_t operator()(uint64_t x) const {\n\t\tstatic const uint64_t FIXED_RANDOM\
    \ = chrono::steady_clock::now().time_since_epoch().count();\n\t\treturn splitmix64(x\
    \ + FIXED_RANDOM);\n\t}\n};\n \ntemplate<class t,class u>\nusing hashmap = gp_hash_table<t,u,custom_hash>;\n\
    \n\n/*\n    https://codeforces.com/gym/102361/submission/61948583\n\t\u9AD8\u901F\
    \u3060\u3051\u3069\u3001mod S \u3067\u308F\u3051\u308B\u304B\u306A\u308A\u30E1\
    \u30C1\u30E3\u30AF\u30C1\u30E3\u306A\u30CF\u30C3\u30B7\u30E5\u306A\u306E\u3067\
    \u3069\u3046\u3057\u3066\u3082\u3063\u3066\u3068\u304D\u4EE5\u5916\u306F\u4F7F\
    \u308F\u306A\u3044\n\tS \u306F \u6700\u5927mapsize \u3088\u308A\u5927\u304D\u304F\
    \u8A2D\u5B9A\n*/\nstruct HashMap{\n\tconst int S = ;\n    int N=0,fst[S];\n\t\
    ll va[S]; int nxt[S],vb[S];\n\tvoid clear(){\n\t\tmemset(fst,0,sizeof fst); N=0;\n\
    \t}\n\tvoid add(ll x){\n\t\tint c=x%S; if(c<0) c=-c;\n\t\tfor(int e=fst[c];e;e=nxt[e])\n\
    \t\t\tif(va[e]==x) {++vb[e]; return;}\n\t\t++N; va[N]=x; vb[N]=1;\n\t\tnxt[N]=fst[c];\
    \ fst[c]=N;\n\t}\n\tint operator [] (ll x){\n\t\tint c=x%S; if(c<0) c=-c;\n\t\t\
    for(int e=fst[c];e;e=nxt[e])\n\t\t\tif(va[e]==x) return vb[e];\n\t\treturn 0;\n\
    \t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: hashmap.cpp
  requiredBy: []
  timestamp: '2020-02-15 12:18:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: hashmap.cpp
layout: document
redirect_from:
- /library/hashmap.cpp
- /library/hashmap.cpp.html
title: hashmap.cpp
---
