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
    - https://atcoder.jp/contests/abc223/submissions/64445206,
    - https://atcoder.jp/contests/abc399/submissions/64444473,
    - https://noshi91.hatenablog.com/entry/2023/12/06/002723
  bundledCode: "#line 1 \"math/suffix_linear_basis.hpp\"\n\n/*\n\tD \u6B21\u5143 Z/pZ\
    \ \u30D9\u30AF\u30C8\u30EB a_0, a_1, ... \u3092\u8FFD\u52A0\u3057\u3066\u3044\u304D\
    \u3001\u305D\u306E\u72B6\u614B\u3067 suffix \u306E\u57FA\u5E95\u304C\u3069\u3046\
    \u306A\u3063\u3066\u3044\u308B\u304B\u3092\u6271\u3046\u30E9\u30A4\u30D6\u30E9\
    \u30EA\n\t\t- add(a): \u672B\u5C3E\u306B\u30D9\u30AF\u30C8\u30EB a \u3092\u8FFD\
    \u52A0\n\t\t- get_l(v): v \\in span(a_l, ... , a_{n-1}) \u3068\u306A\u308B\u6700\
    \u5927\u306E l, \u306A\u3051\u308C\u3070 -1, v \u304C 0 \u30D9\u30AF\u30C8\u30EB\
    \u306A\u3089 n \u3092\u8FD4\u3059\n\t\t- get_index(): a[n-1] \u304B\u3089\u9806\
    \u756A\u306B suffix \u3092\u5DE6\u306B\u4F38\u3070\u3057\u3066\u3044\u3063\u3066\
    \u3001span \u304C\u5909\u5316\u3059\u308B index \u306E\u5217\u6319 (\u964D\u9806\
    )\n\t\n\t\u3088\u3046\u306F\u57FA\u5E95\u306B\u95A2\u3059\u308B\u533A\u9593\u30AF\
    \u30A8\u30EA\u3067\u4F7F\u3048\u308B\u3002 a_r \u307E\u3067\u8FFD\u52A0\u3057\u305F\
    \u3042\u3068\u306B get_l(v) >= l \u304B\u3069\u3046\u304B\u3092\u307F\u308C\u3070\
    \ v \\in span([l,r]) \u304B\u3069\u3046\u304B\u308F\u304B\u308B\n\t\u7DDA\u5F62\
    \u7D50\u5408\u306E\u4FC2\u6570\u306E\u5FA9\u5143\u306F\u8A08\u7B97\u91CF\u304C\
    \u60AA\u304F\u306A\u308B\u3068\u601D\u3046\u306E\u3067\u3084\u3063\u3066\u306A\
    \u3044\n\n\t\u8A08\u7B97\u91CF\u306F\u73FE\u5728\u306E rank \u3092 r \u3068\u3057\
    \u3066 O(rD). xor \u306A\u3089 D \u304C\u7B97\u8853\u64CD\u4F5C\u306B\u5438\u53CE\
    \u3055\u308C\u3066\u6D88\u3048\u308B\u3001\u4E0B\u306B\u3042\u308B SuffixXorBasis\
    \ \u53C2\u7167\n\n\t\u53C2\u8003: https://noshi91.hatenablog.com/entry/2023/12/06/002723\n\
    \tverify: ABC399-G https://atcoder.jp/contests/abc399/submissions/64444473, get_index\n\
    */\ntemplate<class Mint>\nstruct SuffixLinearBasis{\n\tint n;\n\tvector<pair<int,\
    \ vector<Mint>>> b;\n\n\tSuffixLinearBasis() : n(0) {}\n\n\t/*\n\t\t\u672B\u5C3E\
    \u306B\u30D9\u30AF\u30C8\u30EB a \u3092\u8FFD\u52A0\n\t\tO(rD)\n\t*/\n\tvoid add(const\
    \ vector<Mint>& a){\n\t\tint D = a.size();\n\t\tpair<int, vector<Mint>> p = {n,\
    \ a};\n\t\tn++;\n\t\tbool added = false;\n\t\tfor(auto it = b.begin(); it != b.end();\
    \ it++){\n\t\t\tint pl = lsb(p.sc), il = lsb(it->sc);\n\t\t\tif(pl < il){\n\t\t\
    \t\tb.insert(it, p);\n\t\t\t\tadded = true;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\tif(p.sc[il]\
    \ == 0) continue;\n\t\t\tif(p.fs > it->fs){\n\t\t\t\tswap(p, *it);\n\t\t\t}\n\t\
    \t\t// p.sc -= it->sc * (p.sc[il] / it->sc[il]);\n\t\t\tMint c = p.sc[il] / it->sc[il];\n\
    \t\t\tfor(int d=il;d<D;d++) p.sc[d] -= it->sc[d] * c;\n\t\t}\n\t\tif(!added &&\
    \ lsb(p.sc) != D) b.push_back(p);\n\t}\n\n\t/*\n\t\tv \\in span(a_l, .., a_{n-1})\
    \ \u3068\u306A\u308B\u6700\u5927\u306E l, \u306A\u3051\u308C\u3070 -1, v \u304C\
    \ 0 \u30D9\u30AF\u30C8\u30EB\u306A\u3089 n \u3092\u8FD4\u3059\n\t\tO(rD)\n\t*/\n\
    \tint get_l(vector<Mint> v){\n\t\tint D = v.size();\n\t\tint h = lsb(v);\n\t\t\
    if(h == D) return n;\n\t\tint l = n;\n\t\tfor(const auto& [i, a] : b){\n\t\t\t\
    int hh = lsb(a);\n\t\t\tif(h < hh) return -1;\n\t\t\tif(h > hh) continue;\n\t\t\
    \tMint c = v[hh] / a[hh];\n\t\t\tfor(int d=hh;d<D;d++) v[d] -= a[d] * c;\n\t\t\
    \th = lsb(v);\n\t\t\tchmin(l, i);\n\t\t}\n\t\tif(h != D) return -1;\n\t\treturn\
    \ l;\n\t}\n\n\t/*\n\t\ta[n-1] \u304B\u3089\u9806\u756A\u306B suffix \u3092\u5DE6\
    \u306B\u4F38\u3070\u3057\u3066\u3044\u3063\u3066\u3001span \u304C\u5909\u5316\u3059\
    \u308B index \u306E\u5217\u6319 (\u964D\u9806)\n\t\tres[i] = (rank = i+1 \u306B\
    \u306A\u308B\u305F\u3081\u306B\u8FFD\u52A0\u3059\u308B suffix \u306E index)\n\t\
    \tO(r log r)\n\t*/\n\tvector<int> get_index(){\n\t\tvector<int> res; for(const\
    \ auto& [i, a] : b) res.emplace_back(i);\n\t\tsort(all(res), greater<int>());\n\
    \t\treturn res;\n\t}\n\n\t/*\n\t\t\u6700\u521D\u306E non0\n\t\tO(D)\n\t*/\n\t\
    int lsb(const vector<Mint>& v){\n\t\treturn find_if(v.begin(), v.end(), [](Mint\
    \ x){ return x != 0; }) - v.begin();\n\t};\n};\n\n\n/*\n\txor \u7248\n\tT = int,\
    \ ull \u306A\u3069\n\tverify: ABC223-H https://atcoder.jp/contests/abc223/submissions/64445206,\
    \ get_l\n*/\ntemplate<class T>\nstruct SuffixXorBasis{\n\tint n;\n\tvector<pair<int,\
    \ T>> b;\n\n\tSuffixXorBasis() : n(0) {}\n\n\t/*\n\t\t\u672B\u5C3E\u306B\u30D9\
    \u30AF\u30C8\u30EB a \u3092\u8FFD\u52A0\n\t\tO(r)\n\t*/\n\tvoid add(T a){\n\t\t\
    pair<int, T> p = {n, a};\n\t\tn++;\n\t\tbool added = false;\n\t\tfor(auto it =\
    \ b.begin(); it != b.end(); it++){\n\t\t\tif((p.sc & ~it->sc) > it->sc){\n\t\t\
    \t\tb.insert(it, p);\n\t\t\t\tadded = true;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\tif(p.sc\
    \ <= (p.sc ^ it->sc)) continue;\n\t\t\tif(p.fs > it->fs){\n\t\t\t\tswap(p, *it);\n\
    \t\t\t}\n\t\t\tp.sc ^= it->sc;\n\t\t}\n\t\tif(!added && p.sc) b.push_back(p);\n\
    \t}\n\n\t/*\n\t\tv \\in span(a_l, .., a_{n-1}) \u3068\u306A\u308B\u6700\u5927\u306E\
    \ l, \u306A\u3051\u308C\u3070 -1, v \u304C 0 \u30D9\u30AF\u30C8\u30EB\u306A\u3089\
    \ n \u3092\u8FD4\u3059\n\t\tO(r)\n\t*/\n\tint get_l(T v){\n\t\tif(v == 0) return\
    \ n;\n\t\tint l = n;\n\t\tfor(const auto& [i, a] : b){\n\t\t\tif(v > (v ^ a)){\n\
    \t\t\t\tv = v ^ a;\n\t\t\t\tchmin(l, i);\n\t\t\t}\n\t\t}\n\t\tif(v) return -1;\n\
    \t\treturn l;\n\t}\n\n\t/*\n\t\ta[n-1] \u304B\u3089\u9806\u756A\u306B suffix \u3092\
    \u5DE6\u306B\u4F38\u3070\u3057\u3066\u3044\u3063\u3066\u3001span \u304C\u5909\u5316\
    \u3059\u308B index \u306E\u5217\u6319 (\u964D\u9806)\n\t\tres[i] = (rank = i+1\
    \ \u306B\u306A\u308B\u305F\u3081\u306B\u8FFD\u52A0\u3059\u308B suffix \u306E index)\n\
    \t\tO(r log r)\n\t*/\n\tvector<int> get_index(){\n\t\tvector<int> res; for(const\
    \ auto& [i, a] : b) res.emplace_back(i);\n\t\tsort(all(res), greater<int>());\n\
    \t\treturn res;\n\t}\n};\n"
  code: "\n/*\n\tD \u6B21\u5143 Z/pZ \u30D9\u30AF\u30C8\u30EB a_0, a_1, ... \u3092\
    \u8FFD\u52A0\u3057\u3066\u3044\u304D\u3001\u305D\u306E\u72B6\u614B\u3067 suffix\
    \ \u306E\u57FA\u5E95\u304C\u3069\u3046\u306A\u3063\u3066\u3044\u308B\u304B\u3092\
    \u6271\u3046\u30E9\u30A4\u30D6\u30E9\u30EA\n\t\t- add(a): \u672B\u5C3E\u306B\u30D9\
    \u30AF\u30C8\u30EB a \u3092\u8FFD\u52A0\n\t\t- get_l(v): v \\in span(a_l, ...\
    \ , a_{n-1}) \u3068\u306A\u308B\u6700\u5927\u306E l, \u306A\u3051\u308C\u3070\
    \ -1, v \u304C 0 \u30D9\u30AF\u30C8\u30EB\u306A\u3089 n \u3092\u8FD4\u3059\n\t\
    \t- get_index(): a[n-1] \u304B\u3089\u9806\u756A\u306B suffix \u3092\u5DE6\u306B\
    \u4F38\u3070\u3057\u3066\u3044\u3063\u3066\u3001span \u304C\u5909\u5316\u3059\u308B\
    \ index \u306E\u5217\u6319 (\u964D\u9806)\n\t\n\t\u3088\u3046\u306F\u57FA\u5E95\
    \u306B\u95A2\u3059\u308B\u533A\u9593\u30AF\u30A8\u30EA\u3067\u4F7F\u3048\u308B\
    \u3002 a_r \u307E\u3067\u8FFD\u52A0\u3057\u305F\u3042\u3068\u306B get_l(v) >=\
    \ l \u304B\u3069\u3046\u304B\u3092\u307F\u308C\u3070 v \\in span([l,r]) \u304B\
    \u3069\u3046\u304B\u308F\u304B\u308B\n\t\u7DDA\u5F62\u7D50\u5408\u306E\u4FC2\u6570\
    \u306E\u5FA9\u5143\u306F\u8A08\u7B97\u91CF\u304C\u60AA\u304F\u306A\u308B\u3068\
    \u601D\u3046\u306E\u3067\u3084\u3063\u3066\u306A\u3044\n\n\t\u8A08\u7B97\u91CF\
    \u306F\u73FE\u5728\u306E rank \u3092 r \u3068\u3057\u3066 O(rD). xor \u306A\u3089\
    \ D \u304C\u7B97\u8853\u64CD\u4F5C\u306B\u5438\u53CE\u3055\u308C\u3066\u6D88\u3048\
    \u308B\u3001\u4E0B\u306B\u3042\u308B SuffixXorBasis \u53C2\u7167\n\n\t\u53C2\u8003\
    : https://noshi91.hatenablog.com/entry/2023/12/06/002723\n\tverify: ABC399-G https://atcoder.jp/contests/abc399/submissions/64444473,\
    \ get_index\n*/\ntemplate<class Mint>\nstruct SuffixLinearBasis{\n\tint n;\n\t\
    vector<pair<int, vector<Mint>>> b;\n\n\tSuffixLinearBasis() : n(0) {}\n\n\t/*\n\
    \t\t\u672B\u5C3E\u306B\u30D9\u30AF\u30C8\u30EB a \u3092\u8FFD\u52A0\n\t\tO(rD)\n\
    \t*/\n\tvoid add(const vector<Mint>& a){\n\t\tint D = a.size();\n\t\tpair<int,\
    \ vector<Mint>> p = {n, a};\n\t\tn++;\n\t\tbool added = false;\n\t\tfor(auto it\
    \ = b.begin(); it != b.end(); it++){\n\t\t\tint pl = lsb(p.sc), il = lsb(it->sc);\n\
    \t\t\tif(pl < il){\n\t\t\t\tb.insert(it, p);\n\t\t\t\tadded = true;\n\t\t\t\t\
    break;\n\t\t\t}\n\t\t\tif(p.sc[il] == 0) continue;\n\t\t\tif(p.fs > it->fs){\n\
    \t\t\t\tswap(p, *it);\n\t\t\t}\n\t\t\t// p.sc -= it->sc * (p.sc[il] / it->sc[il]);\n\
    \t\t\tMint c = p.sc[il] / it->sc[il];\n\t\t\tfor(int d=il;d<D;d++) p.sc[d] -=\
    \ it->sc[d] * c;\n\t\t}\n\t\tif(!added && lsb(p.sc) != D) b.push_back(p);\n\t\
    }\n\n\t/*\n\t\tv \\in span(a_l, .., a_{n-1}) \u3068\u306A\u308B\u6700\u5927\u306E\
    \ l, \u306A\u3051\u308C\u3070 -1, v \u304C 0 \u30D9\u30AF\u30C8\u30EB\u306A\u3089\
    \ n \u3092\u8FD4\u3059\n\t\tO(rD)\n\t*/\n\tint get_l(vector<Mint> v){\n\t\tint\
    \ D = v.size();\n\t\tint h = lsb(v);\n\t\tif(h == D) return n;\n\t\tint l = n;\n\
    \t\tfor(const auto& [i, a] : b){\n\t\t\tint hh = lsb(a);\n\t\t\tif(h < hh) return\
    \ -1;\n\t\t\tif(h > hh) continue;\n\t\t\tMint c = v[hh] / a[hh];\n\t\t\tfor(int\
    \ d=hh;d<D;d++) v[d] -= a[d] * c;\n\t\t\th = lsb(v);\n\t\t\tchmin(l, i);\n\t\t\
    }\n\t\tif(h != D) return -1;\n\t\treturn l;\n\t}\n\n\t/*\n\t\ta[n-1] \u304B\u3089\
    \u9806\u756A\u306B suffix \u3092\u5DE6\u306B\u4F38\u3070\u3057\u3066\u3044\u3063\
    \u3066\u3001span \u304C\u5909\u5316\u3059\u308B index \u306E\u5217\u6319 (\u964D\
    \u9806)\n\t\tres[i] = (rank = i+1 \u306B\u306A\u308B\u305F\u3081\u306B\u8FFD\u52A0\
    \u3059\u308B suffix \u306E index)\n\t\tO(r log r)\n\t*/\n\tvector<int> get_index(){\n\
    \t\tvector<int> res; for(const auto& [i, a] : b) res.emplace_back(i);\n\t\tsort(all(res),\
    \ greater<int>());\n\t\treturn res;\n\t}\n\n\t/*\n\t\t\u6700\u521D\u306E non0\n\
    \t\tO(D)\n\t*/\n\tint lsb(const vector<Mint>& v){\n\t\treturn find_if(v.begin(),\
    \ v.end(), [](Mint x){ return x != 0; }) - v.begin();\n\t};\n};\n\n\n/*\n\txor\
    \ \u7248\n\tT = int, ull \u306A\u3069\n\tverify: ABC223-H https://atcoder.jp/contests/abc223/submissions/64445206,\
    \ get_l\n*/\ntemplate<class T>\nstruct SuffixXorBasis{\n\tint n;\n\tvector<pair<int,\
    \ T>> b;\n\n\tSuffixXorBasis() : n(0) {}\n\n\t/*\n\t\t\u672B\u5C3E\u306B\u30D9\
    \u30AF\u30C8\u30EB a \u3092\u8FFD\u52A0\n\t\tO(r)\n\t*/\n\tvoid add(T a){\n\t\t\
    pair<int, T> p = {n, a};\n\t\tn++;\n\t\tbool added = false;\n\t\tfor(auto it =\
    \ b.begin(); it != b.end(); it++){\n\t\t\tif((p.sc & ~it->sc) > it->sc){\n\t\t\
    \t\tb.insert(it, p);\n\t\t\t\tadded = true;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\tif(p.sc\
    \ <= (p.sc ^ it->sc)) continue;\n\t\t\tif(p.fs > it->fs){\n\t\t\t\tswap(p, *it);\n\
    \t\t\t}\n\t\t\tp.sc ^= it->sc;\n\t\t}\n\t\tif(!added && p.sc) b.push_back(p);\n\
    \t}\n\n\t/*\n\t\tv \\in span(a_l, .., a_{n-1}) \u3068\u306A\u308B\u6700\u5927\u306E\
    \ l, \u306A\u3051\u308C\u3070 -1, v \u304C 0 \u30D9\u30AF\u30C8\u30EB\u306A\u3089\
    \ n \u3092\u8FD4\u3059\n\t\tO(r)\n\t*/\n\tint get_l(T v){\n\t\tif(v == 0) return\
    \ n;\n\t\tint l = n;\n\t\tfor(const auto& [i, a] : b){\n\t\t\tif(v > (v ^ a)){\n\
    \t\t\t\tv = v ^ a;\n\t\t\t\tchmin(l, i);\n\t\t\t}\n\t\t}\n\t\tif(v) return -1;\n\
    \t\treturn l;\n\t}\n\n\t/*\n\t\ta[n-1] \u304B\u3089\u9806\u756A\u306B suffix \u3092\
    \u5DE6\u306B\u4F38\u3070\u3057\u3066\u3044\u3063\u3066\u3001span \u304C\u5909\u5316\
    \u3059\u308B index \u306E\u5217\u6319 (\u964D\u9806)\n\t\tres[i] = (rank = i+1\
    \ \u306B\u306A\u308B\u305F\u3081\u306B\u8FFD\u52A0\u3059\u308B suffix \u306E index)\n\
    \t\tO(r log r)\n\t*/\n\tvector<int> get_index(){\n\t\tvector<int> res; for(const\
    \ auto& [i, a] : b) res.emplace_back(i);\n\t\tsort(all(res), greater<int>());\n\
    \t\treturn res;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/suffix_linear_basis.hpp
  requiredBy: []
  timestamp: '2025-04-03 01:53:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/suffix_linear_basis.hpp
layout: document
redirect_from:
- /library/math/suffix_linear_basis.hpp
- /library/math/suffix_linear_basis.hpp.html
title: math/suffix_linear_basis.hpp
---
