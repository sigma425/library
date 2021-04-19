---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/891/problem/C
  bundledCode: "#line 1 \"data structure/unionfind/unionfind_rollback.cpp\"\n/*\t\n\
    \tint w = snapshot() O(1) \u3092\u3068\u3063\u3068\u304F\u3068\u3001rollback(w)\
    \ \u3067\u305D\u306E\u6642\u70B9\u306B\u623B\u308B\n\tweighted union rule O(log\
    \ N) \u306A\u306E\u3067\u306A\u3089\u3057\u8A08\u7B97\u91CF\u3058\u3083\u306A\u3044\
    \u3001\u304B\u3089\u3001\u5927\u4E08\u592B\n\n\tp: par (root \u3067\u306F -1)\n\
    \ts: sz\n\tc: # component\n\n\tdouble mn \u3068\u304B\u6301\u3061\u305F\u304B\u3063\
    \u305F\u3089\u30FB\u30FB\u30FB\u3000\u3069\u3046\u3057\u3088\u3046\u306D\n\tany\
    \ \u306F\u9762\u5012\u305D\u3046\u306A\u306E\u3067\n\tbuf \u306F pair<int*,int>\
    \ \u306A\u306E\u3067\u3001\n\t\u3082\u3046\u3044\u3063\u305D\u306E\u3053\u3068\
    \u3059\u3079\u3066\u3092double\u3067\u7BA1\u7406\u3068\u304B\u304B\u306A\n\t\n\
    \tverify: https://codeforces.com/contest/891/problem/C\n*/\n\nstruct UnionFindRollback{\n\
    \tV<int> p,s;\n\tint c;\n\tUnionFindRollback(int n):p(n,-1),s(n,1),c(n){}\n\t\
    int find(int a){\n\t\treturn p[a]==-1?a:find(p[a]);\n\t}\n\tV<pair<int*,int>>\
    \ buf;\n\tvoid save(int& a){\n\t\tbuf.emplace_back(&a,a);\n\t}\n\tint snapshot(){\n\
    \t\treturn si(buf);\n\t}\n\tvoid rollback(int w){\n\t\twhile(si(buf)>w){\n\t\t\
    \tint*a,b;tie(a,b)=buf.back();buf.pop_back();\n\t\t\t*a=b;\n\t\t}\n\t}\n\t//set\
    \ b to a child of a\n\tbool unite(int a,int b){\n\t\ta=find(a);\n\t\tb=find(b);\n\
    \t\tif(a==b)return false;\n\t\tif(s[a]<s[b])swap(a,b);\n\t\tsave(p[b]);\n\t\t\
    save(s[a]);\n\t\tsave(c);\n\t\tp[b]=a;\n\t\ts[a]+=s[b];\n\t\tc--;\n\t\treturn\
    \ true;\n\t}\n\tbool same(int a,int b){\n\t\treturn find(a)==find(b);\n\t}\n\t\
    int sz(int a){\n\t\treturn s[find(a)];\n\t}\n};\n"
  code: "/*\t\n\tint w = snapshot() O(1) \u3092\u3068\u3063\u3068\u304F\u3068\u3001\
    rollback(w) \u3067\u305D\u306E\u6642\u70B9\u306B\u623B\u308B\n\tweighted union\
    \ rule O(log N) \u306A\u306E\u3067\u306A\u3089\u3057\u8A08\u7B97\u91CF\u3058\u3083\
    \u306A\u3044\u3001\u304B\u3089\u3001\u5927\u4E08\u592B\n\n\tp: par (root \u3067\
    \u306F -1)\n\ts: sz\n\tc: # component\n\n\tdouble mn \u3068\u304B\u6301\u3061\u305F\
    \u304B\u3063\u305F\u3089\u30FB\u30FB\u30FB\u3000\u3069\u3046\u3057\u3088\u3046\
    \u306D\n\tany \u306F\u9762\u5012\u305D\u3046\u306A\u306E\u3067\n\tbuf \u306F pair<int*,int>\
    \ \u306A\u306E\u3067\u3001\n\t\u3082\u3046\u3044\u3063\u305D\u306E\u3053\u3068\
    \u3059\u3079\u3066\u3092double\u3067\u7BA1\u7406\u3068\u304B\u304B\u306A\n\t\n\
    \tverify: https://codeforces.com/contest/891/problem/C\n*/\n\nstruct UnionFindRollback{\n\
    \tV<int> p,s;\n\tint c;\n\tUnionFindRollback(int n):p(n,-1),s(n,1),c(n){}\n\t\
    int find(int a){\n\t\treturn p[a]==-1?a:find(p[a]);\n\t}\n\tV<pair<int*,int>>\
    \ buf;\n\tvoid save(int& a){\n\t\tbuf.emplace_back(&a,a);\n\t}\n\tint snapshot(){\n\
    \t\treturn si(buf);\n\t}\n\tvoid rollback(int w){\n\t\twhile(si(buf)>w){\n\t\t\
    \tint*a,b;tie(a,b)=buf.back();buf.pop_back();\n\t\t\t*a=b;\n\t\t}\n\t}\n\t//set\
    \ b to a child of a\n\tbool unite(int a,int b){\n\t\ta=find(a);\n\t\tb=find(b);\n\
    \t\tif(a==b)return false;\n\t\tif(s[a]<s[b])swap(a,b);\n\t\tsave(p[b]);\n\t\t\
    save(s[a]);\n\t\tsave(c);\n\t\tp[b]=a;\n\t\ts[a]+=s[b];\n\t\tc--;\n\t\treturn\
    \ true;\n\t}\n\tbool same(int a,int b){\n\t\treturn find(a)==find(b);\n\t}\n\t\
    int sz(int a){\n\t\treturn s[find(a)];\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data structure/unionfind/unionfind_rollback.cpp
  requiredBy: []
  timestamp: '2020-12-16 01:54:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/unionfind/unionfind_rollback.cpp
layout: document
redirect_from:
- /library/data structure/unionfind/unionfind_rollback.cpp
- /library/data structure/unionfind/unionfind_rollback.cpp.html
title: data structure/unionfind/unionfind_rollback.cpp
---
