---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/kth-competitive-programming/kactl/blob/master/content/data-structures/LineContainer.h
  bundledCode: "#line 1 \"DP/CHT_set.cpp\"\n/*\n    add(k,m): add kx + m\n    query(x)\
    \ MAX kx + m\n    https://github.com/kth-competitive-programming/kactl/blob/master/content/data-structures/LineContainer.h\n\
    */\n\n// MAX\nstruct Line {\n\tmutable ll k, m, p;\n\tbool operator<(const Line&\
    \ o) const { return k < o.k; }\n\tbool operator<(ll x) const { return p < x; }\n\
    };\n\nstruct LineContainer : multiset<Line, less<>> {\n\t// (for doubles, use\
    \ inf = 1/.0, div(a,b) = a/b)\n\tconst ll inf = LLONG_MAX;\n\tll div(ll a, ll\
    \ b) { // floored division\n\t\treturn a / b - ((a ^ b) < 0 && a % b); }\n\tbool\
    \ isect(iterator x, iterator y) {\n\t\tif (y == end()) { x->p = inf; return false;\
    \ }\n\t\tif (x->k == y->k) x->p = x->m > y->m ? inf : -inf;\n\t\telse x->p = div(y->m\
    \ - x->m, x->k - y->k);\n\t\treturn x->p >= y->p;\n\t}\n\tvoid add(ll k, ll m)\
    \ {\n\t\tauto z = insert({k, m, 0}), y = z++, x = y;\n\t\twhile (isect(y, z))\
    \ z = erase(z);\n\t\tif (x != begin() && isect(--x, y)) isect(x, y = erase(y));\n\
    \t\twhile ((y = x) != begin() && (--x)->p >= y->p)\n\t\t\tisect(x, erase(y));\n\
    \t}\n\tll query(ll x) {\n\t\tassert(!empty());\n\t\tauto l = *lower_bound(x);\n\
    \t\treturn l.k * x + l.m;\n\t}\n};\n\n// MIN\nstruct Line {\n\tmutable ll k, m,\
    \ p;\n\tbool operator<(const Line& o) const { return k < o.k; }\n\tbool operator<(ll\
    \ x) const { return p < x; }\n};\n\nstruct LineContainer : multiset<Line, less<>>\
    \ {\n\t// (for doubles, use inf = 1/.0, div(a,b) = a/b)\n\tconst ll inf = LLONG_MAX;\n\
    \tll div(ll a, ll b) { // floored division\n\t\treturn a / b - ((a ^ b) < 0 &&\
    \ a % b); }\n\tbool isect(iterator x, iterator y) {\n\t\tif (y == end()) { x->p\
    \ = inf; return false; }\n\t\tif (x->k == y->k) x->p = x->m > y->m ? inf : -inf;\n\
    \t\telse x->p = div(y->m - x->m, x->k - y->k);\n\t\treturn x->p >= y->p;\n\t}\n\
    \tvoid add(ll k, ll m) {\n        k = -k, m = -m;\n\t\tauto z = insert({k, m,\
    \ 0}), y = z++, x = y;\n\t\twhile (isect(y, z)) z = erase(z);\n\t\tif (x != begin()\
    \ && isect(--x, y)) isect(x, y = erase(y));\n\t\twhile ((y = x) != begin() &&\
    \ (--x)->p >= y->p)\n\t\t\tisect(x, erase(y));\n\t}\n\tll query(ll x) {\n\t\t\
    assert(!empty());\n\t\tauto l = *lower_bound(x);\n\t\treturn -(l.k * x + l.m);\n\
    \t}\n};\n"
  code: "/*\n    add(k,m): add kx + m\n    query(x) MAX kx + m\n    https://github.com/kth-competitive-programming/kactl/blob/master/content/data-structures/LineContainer.h\n\
    */\n\n// MAX\nstruct Line {\n\tmutable ll k, m, p;\n\tbool operator<(const Line&\
    \ o) const { return k < o.k; }\n\tbool operator<(ll x) const { return p < x; }\n\
    };\n\nstruct LineContainer : multiset<Line, less<>> {\n\t// (for doubles, use\
    \ inf = 1/.0, div(a,b) = a/b)\n\tconst ll inf = LLONG_MAX;\n\tll div(ll a, ll\
    \ b) { // floored division\n\t\treturn a / b - ((a ^ b) < 0 && a % b); }\n\tbool\
    \ isect(iterator x, iterator y) {\n\t\tif (y == end()) { x->p = inf; return false;\
    \ }\n\t\tif (x->k == y->k) x->p = x->m > y->m ? inf : -inf;\n\t\telse x->p = div(y->m\
    \ - x->m, x->k - y->k);\n\t\treturn x->p >= y->p;\n\t}\n\tvoid add(ll k, ll m)\
    \ {\n\t\tauto z = insert({k, m, 0}), y = z++, x = y;\n\t\twhile (isect(y, z))\
    \ z = erase(z);\n\t\tif (x != begin() && isect(--x, y)) isect(x, y = erase(y));\n\
    \t\twhile ((y = x) != begin() && (--x)->p >= y->p)\n\t\t\tisect(x, erase(y));\n\
    \t}\n\tll query(ll x) {\n\t\tassert(!empty());\n\t\tauto l = *lower_bound(x);\n\
    \t\treturn l.k * x + l.m;\n\t}\n};\n\n// MIN\nstruct Line {\n\tmutable ll k, m,\
    \ p;\n\tbool operator<(const Line& o) const { return k < o.k; }\n\tbool operator<(ll\
    \ x) const { return p < x; }\n};\n\nstruct LineContainer : multiset<Line, less<>>\
    \ {\n\t// (for doubles, use inf = 1/.0, div(a,b) = a/b)\n\tconst ll inf = LLONG_MAX;\n\
    \tll div(ll a, ll b) { // floored division\n\t\treturn a / b - ((a ^ b) < 0 &&\
    \ a % b); }\n\tbool isect(iterator x, iterator y) {\n\t\tif (y == end()) { x->p\
    \ = inf; return false; }\n\t\tif (x->k == y->k) x->p = x->m > y->m ? inf : -inf;\n\
    \t\telse x->p = div(y->m - x->m, x->k - y->k);\n\t\treturn x->p >= y->p;\n\t}\n\
    \tvoid add(ll k, ll m) {\n        k = -k, m = -m;\n\t\tauto z = insert({k, m,\
    \ 0}), y = z++, x = y;\n\t\twhile (isect(y, z)) z = erase(z);\n\t\tif (x != begin()\
    \ && isect(--x, y)) isect(x, y = erase(y));\n\t\twhile ((y = x) != begin() &&\
    \ (--x)->p >= y->p)\n\t\t\tisect(x, erase(y));\n\t}\n\tll query(ll x) {\n\t\t\
    assert(!empty());\n\t\tauto l = *lower_bound(x);\n\t\treturn -(l.k * x + l.m);\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/CHT_set.cpp
  requiredBy: []
  timestamp: '2020-02-01 13:44:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/CHT_set.cpp
layout: document
redirect_from:
- /library/DP/CHT_set.cpp
- /library/DP/CHT_set.cpp.html
title: DP/CHT_set.cpp
---
