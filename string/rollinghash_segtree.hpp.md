---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://contest.ucup.ac/submission/825668
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/rollinghash_segtree.hpp: line 8: #pragma once found in a non-first line\n"
  code: "/*\n\tsegtree \u306B\u4E57\u305B\u308B\u7528\u306E rolling hash\n\tquery(l,r)\
    \ = s[l] + s[l+1] * base + .. + s[r-1] * base^(r-l-1)\n\n\tverify: ucup 3-21 M\
    \ https://contest.ucup.ac/submission/825668\n*/\n\n#pragma once\n\n#include \"\
    math/mint61.hpp\"\n#include \"misc/rand.hpp\"\n#include \"atcoder/segtree\"\n\n\
    using mint = ModInt61;\nusing Hash = pair<mint, int>;\nconst mint base = rng(mint::mod);\n\
    vector<mint> pw = {1};\n\nHash op(Hash a, Hash b){\n\twhile(a.sc >= (int)pw.size())\
    \ pw.emplace_back(pw.back() * base);\n\treturn {a.fs + b.fs * pw[a.sc], a.sc +\
    \ b.sc};\n}\nHash e() {return {0,0};}\n\ntemplate<class Str>\nstruct RollingHashSegtree\
    \ {\n\tint n;\n\tatcoder::segtree<Hash, op, e> seg;\n\n\tRollingHashSegtree()\
    \ : n(0) {}\n\tRollingHashSegtree(const Str& s) : n(s.size()) {\n\t\tvector<Hash>\
    \ init(n);\n\t\tfor(int i=0;i<n;i++) init[i] = {s[i], 1};\n\t\tseg = atcoder::segtree<Hash,\
    \ op, e>(init);\n\t}\n\t\n\ttemplate<class Value>\n\tvoid update(int i, const\
    \ Value& x){\n\t\tseg.set(i, {x, 1});\n\t}\n\n\tHash query(int l, int r){\n\t\t\
    return seg.prod(l, r);\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/rollinghash_segtree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rollinghash_segtree.hpp
layout: document
redirect_from:
- /library/string/rollinghash_segtree.hpp
- /library/string/rollinghash_segtree.hpp.html
title: string/rollinghash_segtree.hpp
---
