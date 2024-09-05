---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: ds/persistent_meldable_heap.hpp
    title: ds/persistent_meldable_heap.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/atc002/tasks/atc002_c
    - https://web.archive.org/web/20220802104424/https://math.mit.edu/~shor/PAM/hu-tucker_algorithm.html
  bundledCode: "#line 1 \"DP/hu_tucker.hpp\"\n/*\n\t\u6700\u9069\u4E8C\u5206\u63A2\
    \u7D22\u6728\u306B\u5BFE\u3059\u308B Hu-Tucker algorithm O(NlogN)\n\t!! meldable\
    \ heap \u3092\u30E1\u30E2\u30EA\u30D7\u30FC\u30EB\u306E\u95A2\u4FC2\u4E0A\u30B0\
    \u30ED\u30FC\u30D0\u30EB\u306B\u7F6E\u3044\u3066\u308B\u306E\u3067\u3001\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\u578B\u3092\u76F4\u63A5\u5909\u3048\u308B\u3053\
    \u3068 !!\n\n\t\u5FA9\u5143\u306F\u30DE\u30FC\u30B8\u4EEE\u5B9A\u306E\u6728 (invalid)\
    \ \u304B\u3089\u6DF1\u3055\u3092\u8A08\u7B97\u3057\u3001\u305D\u3053\u304B\u3089\
    \u6B63\u3057\u3044\u6728\u3092\u8A08\u7B97\u3059\u308B\u5FC5\u8981\u304C\u3042\
    \u308A\u3001\u3084\u3084\u5927\u5909\u305D\u3046\n\tverify:\n\t\thttps://atcoder.jp/contests/atc002/tasks/atc002_c\n\
    \treference:\n\t\thttps://web.archive.org/web/20220802104424/https://math.mit.edu/~shor/PAM/hu-tucker_algorithm.html\n\
    */\n\n#line 1 \"ds/persistent_meldable_heap.hpp\"\n/*\n\t\u6C38\u7D9A meldable\
    \ heap\n\t\u3072\u3068\u3064\u306E NP (=Node*) \u304C\u3072\u3068\u3064\u306E\
    \ heap \u3092\u8868\u3059 \u5916\u5074\u306E\u578B\u81EA\u4F53\u306F\u30A4\u30F3\
    \u30BF\u30FC\u30D5\u30A7\u30FC\u30B9\u307F\u305F\u3044\u306A\u611F\u3058\u3067\
    \u30B0\u30ED\u30FC\u30D0\u30EB\u306B\u4E00\u3064\u7F6E\u304F\n\t\tPersistentMeldableHeapWithOffset<ll>\
    \ heap;\n\t\tusing NP = decltype(heap)::NP;\n\t\u3058\u3083\u3042\u5916\u5074\u3044\
    \u308B\uFF1F\u3068\u3044\u3046\u8A71\u3060\u304C\u3001Node \u3092 pool \u3057\u305F\
    \u308A\u3059\u308B\u306E\u306B\u3053\u3046\u3059\u308B\u3068\u4FBF\u5229\u3068\
    \u3044\u3046\u3053\u3068\u3067 (\u3042\u3068 nullptr->push \u3068\u304B\u3092\u907F\
    \u3051\u308C\u308B)\n\t\u6C38\u7D9A\u306A\u306E\u3067\u3069\u306E\u64CD\u4F5C\u3082\
    \u7834\u58CA\u7684\u3067\u306A\u3044\u3053\u3068\u3001\u7279\u306B heap.pop(a)\
    \ \u3068\u66F8\u3044\u3066\u3082 a \u306F\u5909\u308F\u3089\u306A\u3044\u3053\u3068\
    \u306B\u6CE8\u610F (a = ~ \u3068\u3059\u3079\u304D)\n\n\t- T top(a): heap a \u306E\
    \ top \u3092\u8FD4\u3059 O(1)\n\t- NP pop(a): heap a \u304B\u3089 pop \u3057\u305F\
    \ heap \u3092\u8FD4\u3059 O(log)\n\t- NP push(a,v): heap a \u306B v \u3092 push\
    \ \u3057\u305F heap \u3092\u8FD4\u3059 O(log)\n\t- NP merge(a,b): heap a,b \u3092\
    \u30DE\u30FC\u30B8\u3057\u305F heap \u3092\u8FD4\u3059 O(log)\n\t- bool empty(a):\
    \ heap a \u304C empty \u304B\u3069\u3046\u304B\u8FD4\u3059 O(1)\n\n\t- NP newnode():\
    \ \u7A7A\u306E heap \u3092\u8FD4\u3059\n\t- NP newnode(v): {v} \u304B\u3089\u306A\
    \u308B heap \u3092\u8FD4\u3059\n\n\t- vector<T> enumerate(NP a): heap a \u306E\
    \u4E2D\u8EAB\u3092\u5168\u3066\u8FD4\u3059 O(size)\n\n\tverify: hu_tucker\n*/\n\
    \ntemplate<class T, class F = less<T>>\nstruct PersistentMeldableHeap{\n\tstruct\
    \ Node{\n\t\tT val;\n\t\tNode *l, *r;\n\t\tint s;\n\t};\n\tusing NP = Node*;\n\
    \tstatic constexpr int pool_size = 900'000'000 / sizeof(Node);\t// 0.9GB \u3068\
    \u308B\n\tNode pool[pool_size];\n\tint I;\t// currently used\n\tF comp = F();\n\
    \n\tT top(NP a){\n\t\tassert(a);\t// a: empty\n\t\treturn a->val;\n\t}\n\tNP pop(NP\
    \ a){\n\t\tassert(a);\n\t\treturn merge(a->l, a->r);\n\t}\n\tNP push(NP a, T v){\n\
    \t\treturn merge(a,newnode(v));\n\t}\n\tNP merge(NP a, NP b){\n\t\tif(!a && !b)\
    \ return nullptr;\n\t\tif(!a) return clone(b);\n\t\tif(!b) return clone(a);\n\t\
    \t// F \u304C\u30C7\u30D5\u30A9\u30EB\u30C8\u306E less \u306E\u5834\u5408: a \u5074\
    \u304C\u5C0F\u3055\u3044\u3068\u304D\u306F\u3001swap \u3059\u3079\u304D (a \u304C\
    \u4E0A\u306B\u306A\u308B\u306E\u3067\u3001\u5927\u304D\u3044\u65B9\u304C\u4E0A\
    )\n\t\tif(comp(a->val, b->val)) swap(a,b);\n\t\treturn newnode(a->val, a->l, merge(a->r,b));\n\
    \t}\n\tbool empty(NP a){\n\t\treturn !a;\n\t}\n\tNP newnode(){\n\t\treturn nullptr;\n\
    \t}\n\tNP newnode(T v){\n\t\tassert(I < pool_size);\n\t\tpool[I] = {v, nullptr,\
    \ nullptr, 1};\n\t\treturn &pool[I++];\n\t}\n\tNP newnode(T v, NP l, NP r){\n\t\
    \tassert(I < pool_size);\n\t\tif(depth(l) < depth(r)) swap(l,r);\n\t\tpool[I]\
    \ = {v, l, r, depth(r)+1};\n\t\treturn &pool[I++];\n\t}\n\tNP clone(NP a){\n\t\
    \tassert(I < pool_size);\n\t\tpool[I] = *a;\n\t\treturn &pool[I++];\n\t}\n\tint\
    \ depth(NP a){\n\t\treturn a ? a->s : 0;\n\t}\n\tvector<T> enumerate(NP a){\n\t\
    \tif(!a) return {};\n\t\tvector<T> res = {a->val};\n\t\tauto vl = enumerate(a->l);\n\
    \t\tauto vr = enumerate(a->r);\n\t\tres.insert(res.end(),all(vl));\n\t\tres.insert(res.end(),all(vr));\n\
    \t\treturn res;\n\t}\n};\n// PersistentMeldableHeapWithOffset<ll> heap;\n// using\
    \ NP = decltype(heap)::NP;\n#line 13 \"DP/hu_tucker.hpp\"\n\nPersistentMeldableHeap<ll>\
    \ heap;\nusing NP = decltype(heap)::NP;\n\ntemplate<class T>\nT hu_tucker(vector<T>\
    \ A){\n\tconstexpr T inf = numeric_limits<T>::max()/2;\n\tint N = A.size();\n\t\
    vector<NP> hs(N-1, nullptr);\n\tvector<int> ls(N),rs(N);\n\tvector<T> cs(N-1);\n\
    \tusing P = pair<T,int>;\n\tpriority_queue<P,vector<P>,greater<P>> q;\n\trep(i,N-1){\n\
    \t\tls[i] = i-1, rs[i] = i+1, cs[i] = A[i]+A[i+1];\n\t\tq.emplace(cs[i],i);\n\t\
    }\n\tT res = 0;\n\trep(_,N-1){\n\t\tT cost; int i;\n\t\twhile(true){\n\t\t\ttie(cost,i)\
    \ = q.top(); q.pop();\n\t\t\tif(rs[i] >= 0 && cs[i] == cost) break;\n\t\t}\n\t\
    \tbool ml = false, mr = false;\n\t\tif(hs[i] && A[i] + heap.top(hs[i]) == cost){\n\
    \t\t\ths[i] = heap.pop(hs[i]);\n\t\t\tml = true;\n\t\t}else if(A[i] + A[rs[i]]\
    \ == cost){\n\t\t\tml = mr = true;\n\t\t}else{\n\t\t\tauto mn = heap.top(hs[i]);\
    \ hs[i] = heap.pop(hs[i]);\n\t\t\tif(hs[i] && heap.top(hs[i]) + mn == cost){\n\
    \t\t\t\ths[i] = heap.pop(hs[i]);\n\t\t\t}else{\n\t\t\t\tmr = true;\n\t\t\t}\n\t\
    \t}\n\t\tres += cost;\n\t\ths[i] = heap.push(hs[i],cost);\n\t\tif(ml) A[i] = inf;\n\
    \t\tif(mr) A[rs[i]] = inf;\n\n\t\tif(ml && i > 0){\n\t\t\tint j = ls[i];\n\t\t\
    \ths[j] = heap.merge(hs[j], hs[i]);\n\t\t\trs[j] = rs[i]; rs[i] = -1; ls[rs[j]]\
    \ = j;\n\t\t\ti = j;\n\t\t}\n\t\tif(mr && rs[i] < N-1){\n\t\t\tint j = rs[i];\n\
    \t\t\ths[i] = heap.merge(hs[i], hs[j]);\n\t\t\trs[i] = rs[j]; rs[j] = -1; ls[rs[i]]\
    \ = i;\n\t\t}\n\t\tcs[i] = A[i] + A[rs[i]];\n\t\tif(hs[i]){\n\t\t\tauto mn = heap.top(hs[i]);\n\
    \t\t\tchmin(cs[i], min(A[i],A[rs[i]])+mn);\n\t\t\tNP tmp = heap.pop(hs[i]);\n\t\
    \t\tif(tmp) chmin(cs[i], mn+heap.top(tmp));\n\t\t}\n\t\tq.emplace(cs[i],i);\n\t\
    }\n\treturn res;\n}\n"
  code: "/*\n\t\u6700\u9069\u4E8C\u5206\u63A2\u7D22\u6728\u306B\u5BFE\u3059\u308B\
    \ Hu-Tucker algorithm O(NlogN)\n\t!! meldable heap \u3092\u30E1\u30E2\u30EA\u30D7\
    \u30FC\u30EB\u306E\u95A2\u4FC2\u4E0A\u30B0\u30ED\u30FC\u30D0\u30EB\u306B\u7F6E\
    \u3044\u3066\u308B\u306E\u3067\u3001\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u578B\
    \u3092\u76F4\u63A5\u5909\u3048\u308B\u3053\u3068 !!\n\n\t\u5FA9\u5143\u306F\u30DE\
    \u30FC\u30B8\u4EEE\u5B9A\u306E\u6728 (invalid) \u304B\u3089\u6DF1\u3055\u3092\u8A08\
    \u7B97\u3057\u3001\u305D\u3053\u304B\u3089\u6B63\u3057\u3044\u6728\u3092\u8A08\
    \u7B97\u3059\u308B\u5FC5\u8981\u304C\u3042\u308A\u3001\u3084\u3084\u5927\u5909\
    \u305D\u3046\n\tverify:\n\t\thttps://atcoder.jp/contests/atc002/tasks/atc002_c\n\
    \treference:\n\t\thttps://web.archive.org/web/20220802104424/https://math.mit.edu/~shor/PAM/hu-tucker_algorithm.html\n\
    */\n\n#include \"ds/persistent_meldable_heap.hpp\"\n\nPersistentMeldableHeap<ll>\
    \ heap;\nusing NP = decltype(heap)::NP;\n\ntemplate<class T>\nT hu_tucker(vector<T>\
    \ A){\n\tconstexpr T inf = numeric_limits<T>::max()/2;\n\tint N = A.size();\n\t\
    vector<NP> hs(N-1, nullptr);\n\tvector<int> ls(N),rs(N);\n\tvector<T> cs(N-1);\n\
    \tusing P = pair<T,int>;\n\tpriority_queue<P,vector<P>,greater<P>> q;\n\trep(i,N-1){\n\
    \t\tls[i] = i-1, rs[i] = i+1, cs[i] = A[i]+A[i+1];\n\t\tq.emplace(cs[i],i);\n\t\
    }\n\tT res = 0;\n\trep(_,N-1){\n\t\tT cost; int i;\n\t\twhile(true){\n\t\t\ttie(cost,i)\
    \ = q.top(); q.pop();\n\t\t\tif(rs[i] >= 0 && cs[i] == cost) break;\n\t\t}\n\t\
    \tbool ml = false, mr = false;\n\t\tif(hs[i] && A[i] + heap.top(hs[i]) == cost){\n\
    \t\t\ths[i] = heap.pop(hs[i]);\n\t\t\tml = true;\n\t\t}else if(A[i] + A[rs[i]]\
    \ == cost){\n\t\t\tml = mr = true;\n\t\t}else{\n\t\t\tauto mn = heap.top(hs[i]);\
    \ hs[i] = heap.pop(hs[i]);\n\t\t\tif(hs[i] && heap.top(hs[i]) + mn == cost){\n\
    \t\t\t\ths[i] = heap.pop(hs[i]);\n\t\t\t}else{\n\t\t\t\tmr = true;\n\t\t\t}\n\t\
    \t}\n\t\tres += cost;\n\t\ths[i] = heap.push(hs[i],cost);\n\t\tif(ml) A[i] = inf;\n\
    \t\tif(mr) A[rs[i]] = inf;\n\n\t\tif(ml && i > 0){\n\t\t\tint j = ls[i];\n\t\t\
    \ths[j] = heap.merge(hs[j], hs[i]);\n\t\t\trs[j] = rs[i]; rs[i] = -1; ls[rs[j]]\
    \ = j;\n\t\t\ti = j;\n\t\t}\n\t\tif(mr && rs[i] < N-1){\n\t\t\tint j = rs[i];\n\
    \t\t\ths[i] = heap.merge(hs[i], hs[j]);\n\t\t\trs[i] = rs[j]; rs[j] = -1; ls[rs[i]]\
    \ = i;\n\t\t}\n\t\tcs[i] = A[i] + A[rs[i]];\n\t\tif(hs[i]){\n\t\t\tauto mn = heap.top(hs[i]);\n\
    \t\t\tchmin(cs[i], min(A[i],A[rs[i]])+mn);\n\t\t\tNP tmp = heap.pop(hs[i]);\n\t\
    \t\tif(tmp) chmin(cs[i], mn+heap.top(tmp));\n\t\t}\n\t\tq.emplace(cs[i],i);\n\t\
    }\n\treturn res;\n}\n"
  dependsOn:
  - ds/persistent_meldable_heap.hpp
  isVerificationFile: false
  path: DP/hu_tucker.hpp
  requiredBy: []
  timestamp: '2024-09-05 20:45:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/hu_tucker.hpp
layout: document
redirect_from:
- /library/DP/hu_tucker.hpp
- /library/DP/hu_tucker.hpp.html
title: DP/hu_tucker.hpp
---
