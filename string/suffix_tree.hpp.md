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
    - https://contest.ucup.ac/submission/563208
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/cartesian_tree.hpp:\
    \ line -1: no such header\n"
  code: "/*\n\tsuffix tree\n\n\tS = aabbabbaa\n\n\tsuffix array\n\t---------\n\ta--------\n\
    \taa-------\n\taabbabbaa\n\tabbaa----\n\tabbabbaa-\n\tbaa------\n\tbabbaa---\n\
    \tbbaa-----\n\tbbabbaa--\n\n\tsuffix tree \u306E node \u306F\u3053\u306E\u9577\
    \u65B9\u5F62\u9818\u57DF\u3092\u8868\u3059 index \u306F preorder (\u3060\u3057\
    \u3001\u8F9E\u66F8\u9806\u3067\u65E9\u3044\u307B\u3046\u304C\u5148)\n\t---------\n\
    \t1--------\n\t12-------\n\t123333333\n\t14445----\n\t14446666-\n\t789------\n\
    \t78AAAA---\n\t7BBC-----\n\t7BBDDDD--\n\n\t\u4F8B\u3048\u3070 node 4 \u306F\u3001\
    \ ud[4,6) * lr[1,4) = bba\n\n\tsuffix_tree.png \u3082\u53C2\u7167\n\n\t\u521D\u671F\
    \u5316:\n\t\tSuffixTree(SuffixArray) \u3067\u8AF8\u3005\u3092\u8A08\u7B97\n\t\
    dat:\n\t\t\u4E0A\u8FF0\u306E\u9577\u65B9\u5F62\u306E {u, d, l, r}\t\t0 <= u <\
    \ d <= sLen+1, 0 <= l <= r <= sLen\n\t\tv = 0 \u3067\u3060\u3051 l = r \u306B\u306A\
    \u308B\u306E\u3067\u6CE8\u610F (iff)\n\t\t\u4F8B\u3048\u3070\u3001dat[4] = {4,\
    \ 6, 1, 4}, dat[0] = {0, sLen+1, 0, 0}\n\tG:\n\t\tsuffix tree \u3068\u3057\u3066\
    \u306E(\u6709\u5411)\u8FBA\n\t\t\u4F8B\u3048\u3070 G[4] = {5,6}, G[0] = {1,7}\n\
    \tendpos:\n\t\t\u9802\u70B9 v \u304C s[i,N) \u306B\u5BFE\u5FDC\u3059\u308B\u306A\
    \u3089\u3070\u3001endpos[v] = i. \u306A\u3044\u306A\u3089 -1\n\t\t\u4F8B\u3048\
    \u3070 endpos[4] = -1, endpos[2] = 7, endpos[0] = sLen\n\n\tdebug(string s):\n\
    \t\t\u5143\u306E\u6587\u5B57\u5217\u3092\u6E21\u3057\u3066\u2191\u306E\u60C5\u5831\
    \u3092\u308F\u304B\u308A\u3084\u3059\u304F\u51FA\u529B\n\t\n\tverify: ucup-3-9\
    \ C https://contest.ucup.ac/submission/563208\n*/\n\n#include \"ds/cartesian_tree.hpp\"\
    \n\ntemplate<class SuffixArray>\nstruct SuffixTree {\n\tstruct Node {\n\t\tint\
    \ u, d, l, r;\n\t\tfriend ostream& operator<<(ostream &o, const Node& x){\n\t\t\
    \treturn o << \"ud[\" << x.u << \",\" << x.d << \") * lr[\" << x.l << \",\" <<\
    \ x.r << \")\";\n\t\t}\n\t};\n\n\tconst SuffixArray& SA;\n\n\tvector<Node> dat;\n\
    \tvector<vector<int>> G;\n\tV<int> endpos;\n\n\tSuffixTree(const SuffixArray&\
    \ SA_):SA(SA_){\n\t\tconst auto& sa = SA.sa;\n\t\tconst auto& lcp = SA.lcp;\n\t\
    \tint sLen = lcp.size();\n\t\tCartesianTree<int, true> CT(SA.lcp);\n\n\t\tauto\
    \ dfs = [&](auto&& self, int idx, int par, int baseh) -> void {\n\t\t\tint L =\
    \ CT.range[idx].first;\n\t\t\tint R = CT.range[idx].second + 1;\n\t\t\tint h =\
    \ lcp[idx];\n\t\t\tif(par == -1 || baseh < h){\n\t\t\t\tif(par != -1) G[par].eb(dat.size());\n\
    \t\t\t\tpar = dat.size();\n\t\t\t\tdat.eb(L, R, baseh, h); G.pb({}); endpos.pb(-1);\n\
    \t\t\t}\n\t\t\tif(CT.lch[idx] == -1){\n\t\t\t\tint len = sLen - sa[idx];\n\t\t\
    \t\tif(h < len){\n\t\t\t\t\tG[par].eb(dat.size());\n\t\t\t\t\tdat.eb(idx, idx+1,\
    \ h, len); G.pb({}); endpos.pb(sa[idx]);\n\t\t\t\t}else{\n\t\t\t\t\tendpos.back()\
    \ = sa[idx];\n\t\t\t\t}\n\t\t\t}else{\n\t\t\t\tself(self, CT.lch[idx], par, h);\n\
    \t\t\t}\n\t\t\tif(CT.rch[idx] == -1){\n\t\t\t\tint len = sLen - sa[idx+1];\n\t\
    \t\t\tG[par].eb(dat.size());\n\t\t\t\tdat.eb(idx+1, idx+2, h, len); G.pb({});\
    \ endpos.pb(sa[idx+1]);\n\t\t\t}else{\n\t\t\t\tself(self, CT.rch[idx], par, h);\n\
    \t\t\t}\n\t\t};\n\t\tdfs(dfs, 0, -1, 0);\n\t}\n\n\tvoid debug(string s){\n\t\t\
    int M = dat.size();\n\t\tcerr << \"--------- suffix tree debug start ---------\"\
    \ << endl;\n\n\t\trep(i,s.size()+1) cerr << s.substr(SA.sa[i]) << endl; \n\t\t\
    cerr << endl;\n\n\t\trep(v,M){\n\t\t\tint off = SA.sa[dat[v].u];\n\t\t\tcerr <<\
    \ \"id = \" << v << \" : \" << dat[v] << \" = \" << s.substr(off + dat[v].l, dat[v].r-dat[v].l)\
    \ << endl;\n\t\t}\n\t\tcerr << endl;\n\n\t\trep(v,M){\n\t\t\tcerr << \"children\
    \ of \" << v << \" : \";\n\t\t\tfor(int u: G[v]) cerr << u << \", \";\n\t\t\t\
    cerr << endl;\n\t\t}\n\t\tcerr << endl;\n\t\tcerr << \"endpos \" << endpos <<\
    \ endl;\n\t\tcerr << endl;\n\t\tcerr << \"--------- suffix tree debug end ---------\"\
    \ << endl;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix_tree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/suffix_tree.hpp
layout: document
redirect_from:
- /library/string/suffix_tree.hpp
- /library/string/suffix_tree.hpp.html
title: string/suffix_tree.hpp
---
