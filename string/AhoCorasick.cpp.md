---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"string/AhoCorasick.cpp\"\n/*\n\tAho-Corasick\n\t\u8907\u6570\
    \u6587\u5B57\u5217\u306E trie + failure link\n\n\tbuild(p) : O(|p0| + |p1| + ..)\n\
    \n\tmatch(s,op) : O(|s| + \u30DE\u30C3\u30C1\u56DE\u6570 * op\u306E\u30B3\u30B9\
    \u30C8)\n\n\t\t\u30DE\u30C3\u30C1\u56DE\u6570 :\n\t\t\t\u30D1\u30BF\u30FC\u30F3\
    \u6587\u5B57\u5217\u304C\n\t\t\t\tsuffix free(\u8449\u306B\u3057\u304Bmatched\u304C\
    \u306A\u3044) : 1\n\t\t\t\tdistinct : O(sqrt(|s|))\n\t\t\t\t\"a\" \u304C\u3044\
    \u3063\u3071\u3044 \u2192 \u30AF\u30D3\n\n\t\t\t\u30DE\u30C3\u30C1\u56DE\u6570\
    \u304B\u3051\u305F\u304F\u306A\u3044\u306A\u3089\u3001\u300C\u3053\u306E\u30CE\
    \u30FC\u30C9\u306B\u6765\u305F\u3068\u304D\u306B\u30DE\u30C3\u30C1\u3059\u308B\
    \u96C6\u5408\u300D ( <=> skip\u3067\u8FBF\u308C\u308B\u30CE\u30FC\u30C9)\n\t\t\
    \t\u306B\u5BFE\u3059\u308B\u7B54\u3048\u306E\u548C\u3068\u304B\u3092\u6301\u3066\
    \u3070\u3044\u3044\u3001\u7DCF\u51FA\u73FE\u56DE\u6570\u3068\u304B\u306A\u3089\
    \u3067\u304D\u308B\u3001\u5404\u30D1\u30BF\u30FC\u30F3\u3054\u3068\u306B\u30FB\
    \u30FB\u30FB\u3060\u3068\u304D\u3064\u3044\n\n\t\tr\u6607\u9806 (r\u4E00\u7DD2\
    \u306A\u3089length\u964D\u9806) \u306B op(string_id,r) \u304C\u547C\u3070\u308C\
    \u308B\n\n\tV<string> p(N);\n\tauto AC = Aho::build(p);\n\n\tV<mint> dp(s.size()+1);\n\
    \tdp[0] = 1;\n\tAC -> match(s,[&](int id,int r){\n\t\tint l = r - (int)p[id].size();\n\
    \t\tdp[r] += dp[l];\n\t});\n\n\tverified at: RUPC2018-day3 G\n\t\t\t\t JSC2019-final\
    \ E\n\n*/\nstruct Aho{\n\tusing NP = Aho*;\n\tmap<char,NP> nx;\n\tNP fail = nullptr,\
    \ skip = nullptr;\n\tV<int> matched;\t\t//string ids for this node\n\n\tvoid add(const\
    \ string& s, int id, int i = 0){\n\t\tif(i == (int)s.size()){\n\t\t\tmatched.pb(id);\n\
    \t\t\treturn;\n\t\t}\n\t\tif(nx[s[i]] == nullptr){\n\t\t\tnx[s[i]] = new Aho();\n\
    \t\t}\n\t\tnx[s[i]] -> add(s,id,i+1);\n\t}\n\ttemplate<class OP> NP count(OP op,\
    \ int r){\n\t\tif(fail == nullptr) return this;\t//root now\n\t\tfor(int id: matched){\n\
    \t\t\top(id,r);\n\t\t}\n\t\tif(skip){\n\t\t\tskip -> count(op,r);\n\t\t}else{\n\
    \t\t\tskip = fail -> count(op,r);\n\t\t}\n\t\treturn matched.empty() ? skip :\
    \ this;\n\t}\n\n\ttemplate<class OP> void match(const string& s, OP op, int i\
    \ = 0){\n\t\tif(i == (int)s.size()) return;\n\t\tif(nx.count(s[i]) && nx[s[i]]\
    \ != nullptr){\n\t\t\tnx[s[i]] -> count(op,i+1);\n\t\t\tnx[s[i]] -> match(s,op,i+1);\n\
    \t\t}else{\n\t\t\tif(fail == nullptr){\t//root now\n\t\t\t\tmatch(s,op,i+1);\n\
    \t\t\t}else{\n\t\t\t\tfail -> match(s,op,i);\n\t\t\t}\n\t\t}\n\t}\n\n\tstatic\
    \ NP build(V<string> ss){\n\t\tNP r = new Aho();\n\t\trep(i,ss.size()){\n\t\t\t\
    r -> add(ss[i],i);\n\t\t}\n\t\tqueue<NP> que;\n\t\tque.push(r);\n\t\tassert(r\
    \ -> fail == nullptr);\n\t\twhile(!que.empty()){\n\t\t\tNP v = que.front(); que.pop();\n\
    \t\t\tfor(auto e: v->nx){\n\t\t\t\tauto c = e.fs;\n\t\t\t\tNP u = e.sc;\n\t\t\t\
    \tNP fail = v -> fail;\n\t\t\t\twhile(fail != nullptr && !fail->nx.count(c)){\n\
    \t\t\t\t\tfail = fail -> fail;\n\t\t\t\t}\n\t\t\t\tu -> fail = (fail == nullptr)\
    \ ? r : fail -> nx[c];\n\t\t\t\tque.push(u);\n\t\t\t}\n\t\t}\n\t\treturn r;\n\t\
    }\n};\n"
  code: "/*\n\tAho-Corasick\n\t\u8907\u6570\u6587\u5B57\u5217\u306E trie + failure\
    \ link\n\n\tbuild(p) : O(|p0| + |p1| + ..)\n\n\tmatch(s,op) : O(|s| + \u30DE\u30C3\
    \u30C1\u56DE\u6570 * op\u306E\u30B3\u30B9\u30C8)\n\n\t\t\u30DE\u30C3\u30C1\u56DE\
    \u6570 :\n\t\t\t\u30D1\u30BF\u30FC\u30F3\u6587\u5B57\u5217\u304C\n\t\t\t\tsuffix\
    \ free(\u8449\u306B\u3057\u304Bmatched\u304C\u306A\u3044) : 1\n\t\t\t\tdistinct\
    \ : O(sqrt(|s|))\n\t\t\t\t\"a\" \u304C\u3044\u3063\u3071\u3044 \u2192 \u30AF\u30D3\
    \n\n\t\t\t\u30DE\u30C3\u30C1\u56DE\u6570\u304B\u3051\u305F\u304F\u306A\u3044\u306A\
    \u3089\u3001\u300C\u3053\u306E\u30CE\u30FC\u30C9\u306B\u6765\u305F\u3068\u304D\
    \u306B\u30DE\u30C3\u30C1\u3059\u308B\u96C6\u5408\u300D ( <=> skip\u3067\u8FBF\u308C\
    \u308B\u30CE\u30FC\u30C9)\n\t\t\t\u306B\u5BFE\u3059\u308B\u7B54\u3048\u306E\u548C\
    \u3068\u304B\u3092\u6301\u3066\u3070\u3044\u3044\u3001\u7DCF\u51FA\u73FE\u56DE\
    \u6570\u3068\u304B\u306A\u3089\u3067\u304D\u308B\u3001\u5404\u30D1\u30BF\u30FC\
    \u30F3\u3054\u3068\u306B\u30FB\u30FB\u30FB\u3060\u3068\u304D\u3064\u3044\n\n\t\
    \tr\u6607\u9806 (r\u4E00\u7DD2\u306A\u3089length\u964D\u9806) \u306B op(string_id,r)\
    \ \u304C\u547C\u3070\u308C\u308B\n\n\tV<string> p(N);\n\tauto AC = Aho::build(p);\n\
    \n\tV<mint> dp(s.size()+1);\n\tdp[0] = 1;\n\tAC -> match(s,[&](int id,int r){\n\
    \t\tint l = r - (int)p[id].size();\n\t\tdp[r] += dp[l];\n\t});\n\n\tverified at:\
    \ RUPC2018-day3 G\n\t\t\t\t JSC2019-final E\n\n*/\nstruct Aho{\n\tusing NP = Aho*;\n\
    \tmap<char,NP> nx;\n\tNP fail = nullptr, skip = nullptr;\n\tV<int> matched;\t\t\
    //string ids for this node\n\n\tvoid add(const string& s, int id, int i = 0){\n\
    \t\tif(i == (int)s.size()){\n\t\t\tmatched.pb(id);\n\t\t\treturn;\n\t\t}\n\t\t\
    if(nx[s[i]] == nullptr){\n\t\t\tnx[s[i]] = new Aho();\n\t\t}\n\t\tnx[s[i]] ->\
    \ add(s,id,i+1);\n\t}\n\ttemplate<class OP> NP count(OP op, int r){\n\t\tif(fail\
    \ == nullptr) return this;\t//root now\n\t\tfor(int id: matched){\n\t\t\top(id,r);\n\
    \t\t}\n\t\tif(skip){\n\t\t\tskip -> count(op,r);\n\t\t}else{\n\t\t\tskip = fail\
    \ -> count(op,r);\n\t\t}\n\t\treturn matched.empty() ? skip : this;\n\t}\n\n\t\
    template<class OP> void match(const string& s, OP op, int i = 0){\n\t\tif(i ==\
    \ (int)s.size()) return;\n\t\tif(nx.count(s[i]) && nx[s[i]] != nullptr){\n\t\t\
    \tnx[s[i]] -> count(op,i+1);\n\t\t\tnx[s[i]] -> match(s,op,i+1);\n\t\t}else{\n\
    \t\t\tif(fail == nullptr){\t//root now\n\t\t\t\tmatch(s,op,i+1);\n\t\t\t}else{\n\
    \t\t\t\tfail -> match(s,op,i);\n\t\t\t}\n\t\t}\n\t}\n\n\tstatic NP build(V<string>\
    \ ss){\n\t\tNP r = new Aho();\n\t\trep(i,ss.size()){\n\t\t\tr -> add(ss[i],i);\n\
    \t\t}\n\t\tqueue<NP> que;\n\t\tque.push(r);\n\t\tassert(r -> fail == nullptr);\n\
    \t\twhile(!que.empty()){\n\t\t\tNP v = que.front(); que.pop();\n\t\t\tfor(auto\
    \ e: v->nx){\n\t\t\t\tauto c = e.fs;\n\t\t\t\tNP u = e.sc;\n\t\t\t\tNP fail =\
    \ v -> fail;\n\t\t\t\twhile(fail != nullptr && !fail->nx.count(c)){\n\t\t\t\t\t\
    fail = fail -> fail;\n\t\t\t\t}\n\t\t\t\tu -> fail = (fail == nullptr) ? r : fail\
    \ -> nx[c];\n\t\t\t\tque.push(u);\n\t\t\t}\n\t\t}\n\t\treturn r;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/AhoCorasick.cpp
  requiredBy: []
  timestamp: '2019-10-01 15:15:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/AhoCorasick.cpp
layout: document
redirect_from:
- /library/string/AhoCorasick.cpp
- /library/string/AhoCorasick.cpp.html
title: string/AhoCorasick.cpp
---
