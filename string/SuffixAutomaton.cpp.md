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
    - http://e-maxx.ru/algo/suffix_automata
    - https://codeforces.com/blog/entry/20861
    - https://codeforces.com/contest/316/problem/G3
    - https://codeforces.com/problemset/problem/235/C
    - https://www.spoj.com/problems/LCS/
    - https://www.spoj.com/problems/SUBLEX/
    - https://www37.atwiki.jp/uwicoder/pages/2842.html
  bundledCode: "#line 1 \"string/SuffixAutomaton.cpp\"\n/*\r\n\tSuffix Automaton\r\
    \n\t\thttps://www37.atwiki.jp/uwicoder/pages/2842.html\r\n\t\thttp://e-maxx.ru/algo/suffix_automata\r\
    \n\t\thttps://codeforces.com/blog/entry/20861\r\n\ts \u306E substring \u306B\u3064\
    \u3044\u3066 t \u306B\u4F55\u56DE\u73FE\u308C\u308B\u304B\u3001\u3068\u304B\u304C\
    \u5F97\u610F\r\n\tapplication \u53C2\u7167\r\n\r\n\tTODO: run enumeration\r\n\r\
    \n*/\r\n\r\nstruct SuffixAutomaton{\r\n\tSuffixAutomaton(int N){\r\n\t\tinit(N);\r\
    \n\t}\r\n\tSuffixAutomaton(string s){\r\n\t\tinit(s.size());\r\n\t\tNP last =\
    \ nodes[0];\r\n\t\tfor(char c: s){\r\n\t\t\tlast = AddChar(last, c);\r\n\t\t}\r\
    \n\t\tTopologicalSort();\r\n\t}\r\n\tvoid init(int N){\r\n\t\tassert(N>0);\r\n\
    \t\tsz = 0;\r\n\t\tnodes = V<Node*>(2*N,nullptr);\r\n\t\tnodes[0] = MakeNode(0,false);\r\
    \n\t}\r\n\r\n\t/*\r\n\t\tNode information\r\n\r\n\t\t\u69CB\u7BC9\u6642\u306B\u4F5C\
    \u308B\u60C5\u5831\u3092\u5897\u3084\u3057\u305F\u3044\u306A\u3089\u3001\r\n\t\
    \t\t- Node \u306E\u5B9A\u7FA9\r\n\t\t\t- MakeNode() \u3067\u306E\u521D\u671F\u5316\
    \r\n\t\t\t- clone \u306E\u3068\u304D\u306E deep copy\r\n\t\t\u3092\u5909\u66F4\
    \u3059\u308B\r\n\r\n\t\t\u4F8B\u3048\u3070 Node v \u306B\u30DE\u30C3\u30C1\u3059\
    \u308Bsubstr \u3092 S(v) = {abb,aabb,caabb} \u3068\u3059\u308B\r\n\t\t\u3053\u306E\
    \u3088\u3046\u306B\u4E00\u6587\u5B57\u305A\u3064\u524D\u306B\u8FFD\u52A0\u3057\
    \u305F\u5F62\u306B\u306A\u308B\r\n\r\n\t\tlen :\r\n\t\t\t\u30DE\u30C3\u30C1\u3059\
    \u308Bsubstr\u306E\u3046\u3061longest (4)\r\n\t\tlink:\r\n\t\t\tshortest \u304B\
    \u3089\u66F4\u306B\u524A\u3063\u305F\u3068\u304D(bb) \u3069\u3053\u306B\u30DE\u30C3\
    \u30C1\u3059\u308B\u304B\r\n\t\t\treverse(s) \u306E suffix tree \u306B\u306A\u308B\
    \ (0\u304Croot)\r\n\r\n\t\t\u306A\u306E\u3067 shortest \u306F v -> link -> len\
    \ + 1\r\n\t*/\r\n\tstruct Node{\r\n\t\tusing NP = Node*;\r\n\r\n\t\tint id;\r\n\
    \t\tint len;\r\n\t\tNP link;\r\n\t\tbool isCloned;\r\n\t\tmap<char,NP> next;\r\
    \n\r\n\t\tNode(){}\r\n\r\n\t\tint getLongest(){\r\n\t\t\treturn len;\r\n\t\t}\r\
    \n\t\tint getShortest(){\r\n\t\t\treturn link == nullptr ? 0 : link->len+1;\r\n\
    \t\t}\r\n\r\n\t\t/*\r\n\t\t\tnext\u306E\u69CB\u9020\u5909\u3048\u305F\u3044\u306A\
    \u3089\u3053\u3053\u3092\u5909\u3048\u308B\r\n\t\t\t\u4ECA\u306F map<char,NP>\r\
    \n\t\t\tarray<NP,(K := const alphabet size)> \u306F\u30A2\u30EA\r\n\t\t\thasNext\u306F\
    ull\u4F7F\u3046\u3068\u304B\r\n\t\t\tull nextbit \u3068\u304B\u5897\u3084\u3057\
    \u305F\u3089\u4E0A\u8FF0\u306E3\u3064\u3092\u5909\u3048\u308B\u306E\u3092\u5FD8\
    \u308C\u306A\u3044\u3053\u3068\r\n\t\t*/\r\n\t\tvoid putNext(char c, NP to){\r\
    \n\t\t\tnext[c] = to;\r\n\t\t}\r\n\t\tbool hasNext(char c){\r\n\t\t\treturn next.count(c);\r\
    \n\t\t}\r\n\t\tNP getNext(char c){\r\n\t\t\treturn hasNext(c) ? next[c] : nullptr;\r\
    \n\t\t}\r\n\t\tV<pair<char,NP>> getAllTransitions(){\r\n\t\t\tV<pair<char,NP>>\
    \ res;\r\n\t\t\tfor(auto it: next) res.pb(it);\r\n\t\t\treturn res;\r\n\t\t}\r\
    \n\t};\r\n\tusing NP = Node*;\r\n\r\n\tint sz;\t\t\t// the number of nodes\r\n\
    \tV<NP> nodes;\r\n\r\n\tNP MakeNode(int len, bool isCloned){\r\n\t\tnodes[sz]\
    \ = new Node();\r\n\t\tnodes[sz] -> id = sz;\r\n\t\tnodes[sz] -> len = len;\r\n\
    \t\tnodes[sz] -> link = nullptr;\r\n\t\tnodes[sz] -> isCloned = isCloned;\r\n\t\
    \treturn nodes[sz++];\r\n\t}\r\n\t/*\r\n\t\tAdd c to nodes[last]\r\n\t\treturn\
    \ the new node id\r\n\t*/\r\n\tNP AddChar(NP last, char c){\r\n\t\tNP cur = MakeNode(last->len+1,\
    \ false);\r\n\t\tNP p;\r\n\t\tfor(p = last; p && !p->hasNext(c); p = p->link){\r\
    \n\t\t\tp -> putNext(c,cur);\r\n\t\t}\r\n\t\tif(p == nullptr){\r\n\t\t\tcur ->\
    \ link = nodes[0];\r\n\t\t}else{\r\n\t\t\tNP q = p -> getNext(c);\r\n\t\t\tif(p->len+1\
    \ == q->len){\r\n\t\t\t\tcur -> link = q;\r\n\t\t\t}else{\t//clone!\r\n\t\t\t\t\
    NP clone = MakeNode(p->len+1, true);\r\n\t\t\t\t/*\r\n\t\t\t\t\tdeep copy !\r\n\
    \t\t\t\t*/\r\n\t\t\t\tclone -> next = q -> next;\r\n\t\t\t\tclone -> link = q\
    \ -> link;\r\n\t\t\t\tfor(;p!=nullptr && p->getNext(c) == q; p = p->link){\r\n\
    \t\t\t\t\tp -> putNext(c,clone);\r\n\t\t\t\t}\r\n\t\t\t\tq -> link = cur -> link\
    \ = clone;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn cur;\r\n\t}\r\n\r\n\tint where(string\
    \ t){\r\n\t\tNP now = nodes[0];\r\n\t\tfor(char c: t){\r\n\t\t\tnow = now -> getNext(c);\r\
    \n\t\t\tif(now == nullptr) return -1;\r\n\t\t}\r\n\t\treturn now -> id;\r\n\t\
    }\r\n\r\n\tvoid debug(){\r\n\t\tcerr << \"======= DEBUG !! ========\" << endl;\r\
    \n\t\trep(v,sz){\r\n\t\t\tNP n = nodes[v];\r\n\t\t\tcerr << \"---- Node \" <<\
    \ v << \" ----\" << endl;\r\n\t\t\tfor(auto p: n->next){\r\n\t\t\t\tchar c = p.fs;\r\
    \n\t\t\t\tint to = p.sc->id;\r\n\t\t\t\tcerr << \"  --(\" << c << \")--> \" <<\
    \ to << endl;\r\n\t\t\t}\r\n\t\t\tcerr << \"  suf link : \" << (n->link == nullptr\
    \ ? -1 : n->link->id) << endl;\r\n\t\t\tcerr << \"  shortest : \" << n -> getShortest()\
    \ << endl;\r\n\t\t\tcerr << \"  longest  : \" << n -> getLongest() << endl;\r\n\
    \t\t\tcerr << endl;\r\n\t\t}\r\n\t\tcerr << \"======= DEBUG END ========\" <<\
    \ endl;\r\n\t}\r\n\r\n\t/*\r\n\t\t\u666E\u901A\u306BSA\u4F5C\u308B\u3060\u3051\
    \u3060\u3068clone\u306E\u305B\u3044\u3067topological\u9806\u306B\u306A\u3063\u3066\
    \u3044\u306A\u3044\u306E\u3067\u30BD\u30FC\u30C8\r\n\t\t\u5F53\u7136 v -> u \u306A\
    \u3089 v < u \u3092\u6E80\u305F\u3059\u304C\u3001\u66F4\u306B\r\n\t\tp <--(suffix\
    \ link)-- v \u306A\u3089 p < v \u3082\u6E80\u305F\u3059\r\n\t\t\u3053\u308C\u306F\
    \u30C8\u30DD\u30BD\u306E\u3084\u308A\u65B9\u7684\u306B\u518D\u9577\u8DDD\u96E2\
    \u304C\u77ED\u3044\u9806\u306B\u8FFD\u52A0\u3057\u3066\u3044\u308B\u3053\u3068\
    \u304B\u3089\u308F\u304B\u308B(suf link\u3092\u305F\u3069\u308B\u3068\u518D\u9577\
    \u8DDD\u96E2\u306F\u77ED\u304F\u306A\u308B\u306E\u3067)\r\n\t*/\r\n\tvoid TopologicalSort(){\r\
    \n\t\tV<int> indeg(sz);\r\n\t\tV<NP> sorted(sz);\r\n\t\trep(v,sz){\r\n\t\t\tauto\
    \ trans = nodes[v] -> getAllTransitions();\r\n\t\t\tfor(auto it: trans){\r\n\t\
    \t\t\tindeg[it.sc->id]++;\r\n\t\t\t}\r\n\t\t}\r\n\t\tsorted[0] = nodes[0];\r\n\
    \t\tint idx = 1;\r\n\t\trep(i,sz){\r\n\t\t\tNP n = sorted[i];\r\n\t\t\tauto trans\
    \ = nodes[n->id] -> getAllTransitions();\r\n\t\t\tfor(auto it: trans){\r\n\t\t\
    \t\tif(--indeg[it.sc->id] == 0){\r\n\t\t\t\t\tsorted[idx++] = it.sc;\r\n\t\t\t\
    \t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tnodes = sorted;\r\n\t\trep(i,sz) nodes[i]->id =\
    \ i;\r\n\t}\r\n\r\n\r\n\r\n\t/*\r\n\t\tapplications\r\n\t*/\r\n\r\n\tll getNumberOfSubstr(){\r\
    \n\t\tll res = 0;\r\n\t\trep(v,sz){\r\n\t\t\tres += nodes[v]->len - (nodes[v]->link\
    \ == nullptr ? 0 : nodes[v]->link->len);\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\
    \r\n\t/*\r\n\t\thttps://www.spoj.com/problems/SUBLEX/\r\n\t\t\u8F9E\u66F8\u9806\
    K\u756A\u76EE \u306Esubstring\r\n\t*/\r\n\tstring GetKthSubstr(ll K){\r\n\t\t\
    V<ll> dp(sz);\r\n\t\tfor(int v=sz-1;v>=0;v--){\r\n\t\t\tdp[v] = 1;\r\n\t\t\tauto\
    \ trans = nodes[v] -> getAllTransitions();\r\n\t\t\tfor(auto it: trans){\r\n\t\
    \t\t\tint u = it.sc->id;\r\n\t\t\t\tdp[v] += dp[u];\r\n\t\t\t}\r\n\t\t}\r\n//\t\
    \tdebug();\r\n//\t\tshow(dp);\r\n\r\n\t\tK++;\t\t//eps\r\n\t\tif(dp[0]<K) return\
    \ \"Eel\";\r\n\t\tNP now = nodes[0];\r\n\t\tstring res;\r\n\t\twhile(K>1){\r\n\
    \t\t\tK--;\r\n\t\t\tauto trans = now -> getAllTransitions();\r\n\t\t\tfor(auto\
    \ it: trans){\r\n\t\t\t\tint u = it.sc->id;\r\n\t\t\t\tif(K<=dp[u]){\r\n\t\t\t\
    \t\tres += it.fs;\r\n\t\t\t\t\tnow = it.sc;\r\n\t\t\t\t\tbreak;\r\n\t\t\t\t}else{\r\
    \n\t\t\t\t\tK -= dp[u];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\
    \t}\r\n\r\n\t/*\r\n\t\thttps://codeforces.com/problemset/problem/235/C\r\n\t\t\
    s\u306Esubstr s[i,j] \u3067\u3042\u3063\u3066 t \u3092 cyclic \u306B\u307E\u308F\
    \u3057\u305F\u3082\u306E\u3068\u4E00\u81F4\u3059\u308B\u3082\u306E\u306F\u3044\
    \u304F\u3064\u3042\u308B\u304B?\r\n\r\n\t\tt\u304C\u3044\u304F\u3064\u3042\u308B\
    \u304B? \u306A\u3089 #{v -> terminal} \u306E DP\r\n\t\t\u4ECA\u56DE\u306F\u305D\
    \u308C\u3092\u3084\u3063\u305F\u3042\u3068 s \u4E0A\u3067 substr \u3092\u3050\u306B\
    \u3087\u3050\u306B\u3087\u30B9\u30E9\u30A4\u30C9\u3055\u305B\u3066\u3044\u304F\
    \r\n\t\tr++ \u306F \u7C21\u5358\u3067\u3001 l++ \u3082\u305D\u306E\u307E\u307E\
    \u304B link \u304B\u3060\u3051\u3069\u9577\u3055\u3092\u4FDD\u3063\u305F\u307E\
    \u307E\u3084\u308B\u306E\u304C\u3061\u3087\u3063\u3068\u96E3\u3057\u3044\r\n\t\
    \t\u3057\u3083\u304F\u3068\u308A\u3063\u307D\u304F l,r \u3067\u3084\u308B\u3088\
    \u308A \u4ECA\u8FFD\u52A0\u3057\u305F\u3044 i \u3068 \u4ECA\u306E\u6587\u5B57\u5217\
    \u306E\u9577\u3055 len \u3092\u6301\u3063\u305F\u307B\u3046\u304C\u304B\u306A\u308A\
    \u308F\u304B\u308A\u3084\u3059\u3044\r\n\t*/\r\n\tvoid solveCF253C(){\r\n\t\t\
    V<ll> dp(sz);\r\n\t\tNP last = nodes[sz-1];\r\n\t\twhile(last){\r\n\t\t\tdp[last->id]++;\r\
    \n\t\t\tlast = last -> link;\r\n\t\t}\r\n\t\tfor(int v=sz-1;v>=0;v--){\r\n\t\t\
    \tauto trans = nodes[v] -> getAllTransitions();\r\n\t\t\tfor(auto it: trans){\r\
    \n\t\t\t\tint u = it.sc->id;\r\n\t\t\t\tdp[v] += dp[u];\r\n\t\t\t}\r\n\t\t}\r\n\
    \r\n\t\tint Q;\r\n\t\tcin >> Q;\r\n\t\trep(_,Q){\r\n\t\t\tstring t;\r\n\t\t\t\
    cin >> t;\r\n\t\t\tint n = t.size();\r\n\t\t\tint len = 0;\r\n\t\t\tNP now = nodes[0];\r\
    \n\t\t\tV<NP> visited;\r\n\r\n\t\t\trep(i,n+n-1){\r\n\t\t\t\tchar c = t[i%n];\r\
    \n\t\t\t\twhile(now && !now->hasNext(c)){\r\n\t\t\t\t\tnow = now -> link;\r\n\t\
    \t\t\t\tlen = now ? now->getLongest() : 0; \r\n\t\t\t\t}\r\n\t\t\t\tif(!now){\r\
    \n\t\t\t\t\tnow = nodes[0];\r\n\t\t\t\t\tlen = 0;\r\n\t\t\t\t}else{\r\n\t\t\t\t\
    \tnow = now -> getNext(c);\r\n\t\t\t\t\tlen++;\r\n\t\t\t\t}\r\n\t\t\t\tif(len\
    \ > n){\r\n\t\t\t\t\tif(now -> getShortest() == len){\r\n\t\t\t\t\t\tnow = now\
    \ -> link;\r\n\t\t\t\t\t}\r\n\t\t\t\t\tlen--;\r\n\t\t\t\t\tassert(len == n);\r\
    \n\t\t\t\t}\r\n\t\t\t\tif(len == n){\r\n\t\t\t\t\tvisited.pb(now);\r\n\t\t\t\t\
    }\r\n\t\t\t}\r\n\t\t\tsort(all(visited));\r\n\t\t\tvisited.erase(unique(all(visited)),visited.end());\r\
    \n\t\t\tll ans = 0;\r\n\t\t\tfor(NP np : visited){\r\n\t\t\t\tans += dp[np->id];\r\
    \n\t\t\t}\r\n\t\t\tcout << ans << endl;\r\n\t\t}\r\n\t}\r\n\r\n\t/*\r\n\t\thttps://codeforces.com/contest/316/problem/G3\r\
    \n\r\n\t\t(t_i \u306B [l_i,r_i] \u56DE\u51FA\u73FE\u3059\u308B) \u3092\u3059\u3079\
    \u3066\u6E80\u305F\u3059 s \u306E substr \u306F\u4F55\u901A\u308A?\r\n\t\ta \u304C\
    \ t_i \u306B\u4F55\u56DE\u51FA\u73FE\u3059\u308B\u304B? \u306F #{where(a) -> t_i.terminal}\
    \ \u3092\u8003\u3048\u308C\u3070\u3088\u304B\u3063\u305F\r\n\r\n\t\t\u5B9F\u306F\
    \ str := s + '0' + t_1 + '1' + .. + t_Q + 'Q' \u3068\u3044\u3046\u6587\u5B57\u5217\
    \u3092 SA \u306B\u304B\u3051\u308B\u3068\u89E3\u3051\u308B\r\n\t\t\u5404\u30CE\
    \u30FC\u30C9\u5185\u3067\u306F\u3001t_i \u304C\u4F55\u56DE\u51FA\u3066\u304F\u308B\
    \u304B\u306F(\u305D\u306E\u30CE\u30FC\u30C9\u3078\u306E\u5230\u9054\u65B9\u6CD5\
    \u306B\u3088\u3089\u305A) \u4E00\u5B9A\r\n\t\t\u3053\u3046\u3084\u3063\u3066 str\
    \ \u3092\u4F5C\u308B\u3068\u3001 v -> '1' \u3078\u306E path \u304C\u4F55\u901A\
    \u308A\u3042\u308B\u304B? \u307F\u305F\u3044\u306A\u3082\u306E\u306B\u306A\u3063\
    \u3066\u307B\u3057\u3044\u304C\u3001\r\n\t\t\u5F53\u7136 '0' \u306E\u3042\u3068\
    \u306E\u3082\u306E\u3092\u6570\u3048\u305F\u308A substr -> '0' -> '1' \u307F\u305F\
    \u3044\u306B s \u306E\u5185\u5074\u306B\u53CE\u307E\u3063\u3066\u306A\u3044\u3082\
    \u306E\u3092\u6570\u3048\u3066\u3082\u3057\u3087\u3046\u304C\u306A\u3044\r\n\t\
    \t\u306A\u306E\u3067\u7B54\u3048\u306B\u5024\u3092\u8DB3\u3057\u8FBC\u3080\u306E\
    \u306F '0' \u306E\u524D (v -> '0' path exists) \u3067\u3001\r\n\t\tdp \u306E\u9077\
    \u79FB\u306F\u533A\u5207\u308A\u6587\u5B57\u306E\u3068\u304D\u306F\u3084\u3089\
    \u306A\u3044\u3088\u3046\u306B\u3059\u308B \u3068\u9054\u6210\u3067\u304D\u308B\
    \r\n\r\n\t\t\u533A\u5207\u308A\u6587\u5B57\u3067\u6587\u5B57\u5217\u305F\u3061\
    \u3092\u3064\u306A\u304E\u3001\u533A\u5207\u308A\u6587\u5B57\u306E\u3068\u3053\
    \u3067\u306F dp \u306E\u9077\u79FB\u3092\u3057\u306A\u3044\u3088\u3046\u306B\u3059\
    \u308B\u3068\u3001\r\n\t\t\u5404\u6587\u5B57\u5217\u306E\u5185\u5074\u3060\u3051\
    \u306E\u4F55\u3089\u304B\u306B\u6CE8\u76EE\u3067\u304D\u308B\u3001\u3068\u3044\
    \u3046\u306E\u306F\u5178\u578B\u3063\u307D\u3044\r\n\r\n\t\tdebug() \u306E\u3057\
    \u3084\u3059\u3055\u3092\u8003\u3048\u308B\u3068\u3001dp\u3068\u304B\u306F Node\
    \ \u5185\u90E8\u306B\u6301\u3064\u307B\u3046\u304C\u3044\u3044\u6C17\u304C\u3059\
    \u308B\u306A\u3042\r\n\t\t\u3068\u3044\u3046\u308F\u3051\u3067\u305D\u3046\u3044\
    \u3046\u5B9F\u88C5\u306B\u3057\u305F\u3001 Node \u306E\u4E2D\u8EAB\u3084 debug()\
    \ \u3092\u9069\u5B9C\u66F8\u304D\u63DB\u3048\u308B\r\n\t*/\r\n\r\n\tll solveCF316G(int\
    \ Q, V<int> L, V<int> R){\r\n\t\tstring special;\r\n\t\trep(i,Q+1) special +=\
    \ (char)('z'+1+i);\r\n\r\n\t\tll res = 0;\r\n\t\tfor(int v = sz-1; v>=0; v--){\r\
    \n\t\t\tNP n = nodes[v];\r\n            n -> dp = V<int>(Q+1,0);\r\n\t\t\trep(t,Q+1){\r\
    \n\t\t\t\tif(n -> hasNext(special[t])){\r\n\t\t\t\t\tn -> dp[t]++;\t\t\t\t\t//\
    \ #{v->terminal} ( = the # of appearance of this node in t)\r\n\t\t\t\t}\r\n\t\
    \t\t}\r\n\t\t\tauto trans = n -> getAllTransitions();\r\n\t\t\tfor(auto it: trans){\r\
    \n                if(!islower(it.fs)) continue;\r\n\t\t\t\trep(t,Q+1) n->dp[t]\
    \ += it.sc->dp[t];\r\n\t\t\t}\r\n\t\t\tif(v != 0 && n->dp[0]){\r\n\t\t\t\tbool\
    \ valid = true;\r\n\t\t\t\trep(t,Q){\r\n\t\t\t\t\tif( !(L[t]<=n->dp[t+1] && n->dp[t+1]<=R[t])\
    \ ) valid = false;\r\n\t\t\t\t}\r\n\t\t\t\tif(valid) res += n->getLongest() -\
    \ n->getShortest() + 1;\r\n\t\t\t}\r\n\t\t}\r\n//        debug();\r\n\t\treturn\
    \ res;\r\n\t}\r\n\r\n\t/*\r\n\t\thttps://www.spoj.com/problems/LCS/\r\n\t\tlongest\
    \ common substring\r\n\t\t\u3053\u308C\u3082\u533A\u5207\u308A\u6587\u5B57\u7CFB\
    \r\n\t*/\r\n\tint getLongestLCS(){\r\n\t\tint res = 0;\r\n//\t\tdebug();\r\n\t\
    \tfor(int v = sz-1; v>=0; v--){\r\n\t\t\tNP n = nodes[v];\r\n\t\t\tn -> reach\
    \ = V<bool>(2,false);\r\n\t\t\trep(t,2){\r\n\t\t\t\tif(n -> hasNext('0'+t)){\r\
    \n\t\t\t\t\tn -> reach[t] = true;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tauto trans\
    \ = n -> getAllTransitions();\r\n\t\t\tfor(auto it: trans){\r\n\t\t\t\tif(!islower(it.fs))\
    \ continue;\r\n\t\t\t\trep(t,2){\r\n\t\t\t\t\tif(it.sc->reach[t]) n->reach[t]\
    \ = true;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tif(n->reach[0] && n->reach[1]){\r\n\
    \t\t\t\tchmax(res,n->getLongest());\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\
    \t}\r\n\t\r\n};\r\n\r\nstruct Timer{\r\n\tclock_t st;\r\n\tvoid start(){\r\n\t\
    \tst = clock();\r\n\t}\r\n\tint ms(){\r\n\t\treturn (clock()-st)*1000 / CLOCKS_PER_SEC;\r\
    \n\t}\r\n};\r\n\r\nvoid test(string s){\r\n\tTimer timer;\r\n\ttimer.start();\r\
    \n\r\n\tSuffixAutomaton SA(s);\r\n\r\n\tV<string> substrs;\r\n\tint N = s.size();\r\
    \n\trep(i,N) for(int j=i;j<=N;j++){\r\n\t\tsubstrs.pb(s.substr(i,j-i));\r\n\t\
    }\r\n\tsort(all(substrs));\r\n\tsubstrs.erase(unique(all(substrs)),substrs.end());\r\
    \n\tint sz = SA.sz;\r\n\tVV<string> node2strs(sz);\r\n\tshow(sz);\r\n\tSA.TopologicalSort();\r\
    \n\tSA.debug();\r\n\r\n\tfor(string t: substrs){\r\n\t\tint v = SA.where(t);\r\
    \n\t\tassert(v != -1);\r\n\t\tnode2strs[v].pb(t);\r\n\t}\r\n\trep(v,sz){\r\n\t\
    \tcerr << \"-- v = \" << v << \" ----\" << endl;\r\n\t\tfor(string t: node2strs[v])\
    \ cerr << t << endl;\r\n\t}\r\n\r\n\tshow(timer.ms());\r\n}\r\n\r\nint main(){\r\
    \n\t// srand((unsigned)time(NULL));\r\n\t// for(int N: {1,10,100,1000,10000,100000,200000,500000,1000000}){\r\
    \n\t// \tstring s(N,'.');\r\n\t// \trep(i,N) s[i] = 'a' + rand()%26;\r\n\t// \t\
    test(s);\r\n\t// }\r\n\r\n\t// while(true){\r\n\t// \tstring s;\r\n\t// \tcin>>s;\r\
    \n\t// \ttest(s);\r\n\t// }\r\n\r\n\tstring s;\r\n\tint Q;\r\n\tcin>>s>>Q;\r\n\
    \tV<string> t(Q);\r\n\tV<int> L(Q),R(Q);\r\n\trep(i,Q){\r\n\t\tcin>>t[i];\r\n\t\
    \tcin>>L[i]>>R[i];\r\n\t}\r\n\tstring str = s;\r\n\tstr += char('z'+1);\r\n\t\
    rep(i,Q){\r\n\t\tstr += t[i];\r\n\t\tstr += char('z'+1+i);\r\n\t}\r\n\tSuffixAutomaton\
    \ SA(str);\r\n\tcout << SA.solve(Q,L,R) << endl;\r\n}\n"
  code: "/*\r\n\tSuffix Automaton\r\n\t\thttps://www37.atwiki.jp/uwicoder/pages/2842.html\r\
    \n\t\thttp://e-maxx.ru/algo/suffix_automata\r\n\t\thttps://codeforces.com/blog/entry/20861\r\
    \n\ts \u306E substring \u306B\u3064\u3044\u3066 t \u306B\u4F55\u56DE\u73FE\u308C\
    \u308B\u304B\u3001\u3068\u304B\u304C\u5F97\u610F\r\n\tapplication \u53C2\u7167\
    \r\n\r\n\tTODO: run enumeration\r\n\r\n*/\r\n\r\nstruct SuffixAutomaton{\r\n\t\
    SuffixAutomaton(int N){\r\n\t\tinit(N);\r\n\t}\r\n\tSuffixAutomaton(string s){\r\
    \n\t\tinit(s.size());\r\n\t\tNP last = nodes[0];\r\n\t\tfor(char c: s){\r\n\t\t\
    \tlast = AddChar(last, c);\r\n\t\t}\r\n\t\tTopologicalSort();\r\n\t}\r\n\tvoid\
    \ init(int N){\r\n\t\tassert(N>0);\r\n\t\tsz = 0;\r\n\t\tnodes = V<Node*>(2*N,nullptr);\r\
    \n\t\tnodes[0] = MakeNode(0,false);\r\n\t}\r\n\r\n\t/*\r\n\t\tNode information\r\
    \n\r\n\t\t\u69CB\u7BC9\u6642\u306B\u4F5C\u308B\u60C5\u5831\u3092\u5897\u3084\u3057\
    \u305F\u3044\u306A\u3089\u3001\r\n\t\t\t- Node \u306E\u5B9A\u7FA9\r\n\t\t\t- MakeNode()\
    \ \u3067\u306E\u521D\u671F\u5316\r\n\t\t\t- clone \u306E\u3068\u304D\u306E deep\
    \ copy\r\n\t\t\u3092\u5909\u66F4\u3059\u308B\r\n\r\n\t\t\u4F8B\u3048\u3070 Node\
    \ v \u306B\u30DE\u30C3\u30C1\u3059\u308Bsubstr \u3092 S(v) = {abb,aabb,caabb}\
    \ \u3068\u3059\u308B\r\n\t\t\u3053\u306E\u3088\u3046\u306B\u4E00\u6587\u5B57\u305A\
    \u3064\u524D\u306B\u8FFD\u52A0\u3057\u305F\u5F62\u306B\u306A\u308B\r\n\r\n\t\t\
    len :\r\n\t\t\t\u30DE\u30C3\u30C1\u3059\u308Bsubstr\u306E\u3046\u3061longest (4)\r\
    \n\t\tlink:\r\n\t\t\tshortest \u304B\u3089\u66F4\u306B\u524A\u3063\u305F\u3068\
    \u304D(bb) \u3069\u3053\u306B\u30DE\u30C3\u30C1\u3059\u308B\u304B\r\n\t\t\treverse(s)\
    \ \u306E suffix tree \u306B\u306A\u308B (0\u304Croot)\r\n\r\n\t\t\u306A\u306E\u3067\
    \ shortest \u306F v -> link -> len + 1\r\n\t*/\r\n\tstruct Node{\r\n\t\tusing\
    \ NP = Node*;\r\n\r\n\t\tint id;\r\n\t\tint len;\r\n\t\tNP link;\r\n\t\tbool isCloned;\r\
    \n\t\tmap<char,NP> next;\r\n\r\n\t\tNode(){}\r\n\r\n\t\tint getLongest(){\r\n\t\
    \t\treturn len;\r\n\t\t}\r\n\t\tint getShortest(){\r\n\t\t\treturn link == nullptr\
    \ ? 0 : link->len+1;\r\n\t\t}\r\n\r\n\t\t/*\r\n\t\t\tnext\u306E\u69CB\u9020\u5909\
    \u3048\u305F\u3044\u306A\u3089\u3053\u3053\u3092\u5909\u3048\u308B\r\n\t\t\t\u4ECA\
    \u306F map<char,NP>\r\n\t\t\tarray<NP,(K := const alphabet size)> \u306F\u30A2\
    \u30EA\r\n\t\t\thasNext\u306Full\u4F7F\u3046\u3068\u304B\r\n\t\t\tull nextbit\
    \ \u3068\u304B\u5897\u3084\u3057\u305F\u3089\u4E0A\u8FF0\u306E3\u3064\u3092\u5909\
    \u3048\u308B\u306E\u3092\u5FD8\u308C\u306A\u3044\u3053\u3068\r\n\t\t*/\r\n\t\t\
    void putNext(char c, NP to){\r\n\t\t\tnext[c] = to;\r\n\t\t}\r\n\t\tbool hasNext(char\
    \ c){\r\n\t\t\treturn next.count(c);\r\n\t\t}\r\n\t\tNP getNext(char c){\r\n\t\
    \t\treturn hasNext(c) ? next[c] : nullptr;\r\n\t\t}\r\n\t\tV<pair<char,NP>> getAllTransitions(){\r\
    \n\t\t\tV<pair<char,NP>> res;\r\n\t\t\tfor(auto it: next) res.pb(it);\r\n\t\t\t\
    return res;\r\n\t\t}\r\n\t};\r\n\tusing NP = Node*;\r\n\r\n\tint sz;\t\t\t// the\
    \ number of nodes\r\n\tV<NP> nodes;\r\n\r\n\tNP MakeNode(int len, bool isCloned){\r\
    \n\t\tnodes[sz] = new Node();\r\n\t\tnodes[sz] -> id = sz;\r\n\t\tnodes[sz] ->\
    \ len = len;\r\n\t\tnodes[sz] -> link = nullptr;\r\n\t\tnodes[sz] -> isCloned\
    \ = isCloned;\r\n\t\treturn nodes[sz++];\r\n\t}\r\n\t/*\r\n\t\tAdd c to nodes[last]\r\
    \n\t\treturn the new node id\r\n\t*/\r\n\tNP AddChar(NP last, char c){\r\n\t\t\
    NP cur = MakeNode(last->len+1, false);\r\n\t\tNP p;\r\n\t\tfor(p = last; p &&\
    \ !p->hasNext(c); p = p->link){\r\n\t\t\tp -> putNext(c,cur);\r\n\t\t}\r\n\t\t\
    if(p == nullptr){\r\n\t\t\tcur -> link = nodes[0];\r\n\t\t}else{\r\n\t\t\tNP q\
    \ = p -> getNext(c);\r\n\t\t\tif(p->len+1 == q->len){\r\n\t\t\t\tcur -> link =\
    \ q;\r\n\t\t\t}else{\t//clone!\r\n\t\t\t\tNP clone = MakeNode(p->len+1, true);\r\
    \n\t\t\t\t/*\r\n\t\t\t\t\tdeep copy !\r\n\t\t\t\t*/\r\n\t\t\t\tclone -> next =\
    \ q -> next;\r\n\t\t\t\tclone -> link = q -> link;\r\n\t\t\t\tfor(;p!=nullptr\
    \ && p->getNext(c) == q; p = p->link){\r\n\t\t\t\t\tp -> putNext(c,clone);\r\n\
    \t\t\t\t}\r\n\t\t\t\tq -> link = cur -> link = clone;\r\n\t\t\t}\r\n\t\t}\r\n\t\
    \treturn cur;\r\n\t}\r\n\r\n\tint where(string t){\r\n\t\tNP now = nodes[0];\r\
    \n\t\tfor(char c: t){\r\n\t\t\tnow = now -> getNext(c);\r\n\t\t\tif(now == nullptr)\
    \ return -1;\r\n\t\t}\r\n\t\treturn now -> id;\r\n\t}\r\n\r\n\tvoid debug(){\r\
    \n\t\tcerr << \"======= DEBUG !! ========\" << endl;\r\n\t\trep(v,sz){\r\n\t\t\
    \tNP n = nodes[v];\r\n\t\t\tcerr << \"---- Node \" << v << \" ----\" << endl;\r\
    \n\t\t\tfor(auto p: n->next){\r\n\t\t\t\tchar c = p.fs;\r\n\t\t\t\tint to = p.sc->id;\r\
    \n\t\t\t\tcerr << \"  --(\" << c << \")--> \" << to << endl;\r\n\t\t\t}\r\n\t\t\
    \tcerr << \"  suf link : \" << (n->link == nullptr ? -1 : n->link->id) << endl;\r\
    \n\t\t\tcerr << \"  shortest : \" << n -> getShortest() << endl;\r\n\t\t\tcerr\
    \ << \"  longest  : \" << n -> getLongest() << endl;\r\n\t\t\tcerr << endl;\r\n\
    \t\t}\r\n\t\tcerr << \"======= DEBUG END ========\" << endl;\r\n\t}\r\n\r\n\t\
    /*\r\n\t\t\u666E\u901A\u306BSA\u4F5C\u308B\u3060\u3051\u3060\u3068clone\u306E\u305B\
    \u3044\u3067topological\u9806\u306B\u306A\u3063\u3066\u3044\u306A\u3044\u306E\u3067\
    \u30BD\u30FC\u30C8\r\n\t\t\u5F53\u7136 v -> u \u306A\u3089 v < u \u3092\u6E80\u305F\
    \u3059\u304C\u3001\u66F4\u306B\r\n\t\tp <--(suffix link)-- v \u306A\u3089 p <\
    \ v \u3082\u6E80\u305F\u3059\r\n\t\t\u3053\u308C\u306F\u30C8\u30DD\u30BD\u306E\
    \u3084\u308A\u65B9\u7684\u306B\u518D\u9577\u8DDD\u96E2\u304C\u77ED\u3044\u9806\
    \u306B\u8FFD\u52A0\u3057\u3066\u3044\u308B\u3053\u3068\u304B\u3089\u308F\u304B\
    \u308B(suf link\u3092\u305F\u3069\u308B\u3068\u518D\u9577\u8DDD\u96E2\u306F\u77ED\
    \u304F\u306A\u308B\u306E\u3067)\r\n\t*/\r\n\tvoid TopologicalSort(){\r\n\t\tV<int>\
    \ indeg(sz);\r\n\t\tV<NP> sorted(sz);\r\n\t\trep(v,sz){\r\n\t\t\tauto trans =\
    \ nodes[v] -> getAllTransitions();\r\n\t\t\tfor(auto it: trans){\r\n\t\t\t\tindeg[it.sc->id]++;\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\tsorted[0] = nodes[0];\r\n\t\tint idx = 1;\r\n\t\trep(i,sz){\r\
    \n\t\t\tNP n = sorted[i];\r\n\t\t\tauto trans = nodes[n->id] -> getAllTransitions();\r\
    \n\t\t\tfor(auto it: trans){\r\n\t\t\t\tif(--indeg[it.sc->id] == 0){\r\n\t\t\t\
    \t\tsorted[idx++] = it.sc;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tnodes = sorted;\r\
    \n\t\trep(i,sz) nodes[i]->id = i;\r\n\t}\r\n\r\n\r\n\r\n\t/*\r\n\t\tapplications\r\
    \n\t*/\r\n\r\n\tll getNumberOfSubstr(){\r\n\t\tll res = 0;\r\n\t\trep(v,sz){\r\
    \n\t\t\tres += nodes[v]->len - (nodes[v]->link == nullptr ? 0 : nodes[v]->link->len);\r\
    \n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\r\n\t/*\r\n\t\thttps://www.spoj.com/problems/SUBLEX/\r\
    \n\t\t\u8F9E\u66F8\u9806K\u756A\u76EE \u306Esubstring\r\n\t*/\r\n\tstring GetKthSubstr(ll\
    \ K){\r\n\t\tV<ll> dp(sz);\r\n\t\tfor(int v=sz-1;v>=0;v--){\r\n\t\t\tdp[v] = 1;\r\
    \n\t\t\tauto trans = nodes[v] -> getAllTransitions();\r\n\t\t\tfor(auto it: trans){\r\
    \n\t\t\t\tint u = it.sc->id;\r\n\t\t\t\tdp[v] += dp[u];\r\n\t\t\t}\r\n\t\t}\r\n\
    //\t\tdebug();\r\n//\t\tshow(dp);\r\n\r\n\t\tK++;\t\t//eps\r\n\t\tif(dp[0]<K)\
    \ return \"Eel\";\r\n\t\tNP now = nodes[0];\r\n\t\tstring res;\r\n\t\twhile(K>1){\r\
    \n\t\t\tK--;\r\n\t\t\tauto trans = now -> getAllTransitions();\r\n\t\t\tfor(auto\
    \ it: trans){\r\n\t\t\t\tint u = it.sc->id;\r\n\t\t\t\tif(K<=dp[u]){\r\n\t\t\t\
    \t\tres += it.fs;\r\n\t\t\t\t\tnow = it.sc;\r\n\t\t\t\t\tbreak;\r\n\t\t\t\t}else{\r\
    \n\t\t\t\t\tK -= dp[u];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\
    \t}\r\n\r\n\t/*\r\n\t\thttps://codeforces.com/problemset/problem/235/C\r\n\t\t\
    s\u306Esubstr s[i,j] \u3067\u3042\u3063\u3066 t \u3092 cyclic \u306B\u307E\u308F\
    \u3057\u305F\u3082\u306E\u3068\u4E00\u81F4\u3059\u308B\u3082\u306E\u306F\u3044\
    \u304F\u3064\u3042\u308B\u304B?\r\n\r\n\t\tt\u304C\u3044\u304F\u3064\u3042\u308B\
    \u304B? \u306A\u3089 #{v -> terminal} \u306E DP\r\n\t\t\u4ECA\u56DE\u306F\u305D\
    \u308C\u3092\u3084\u3063\u305F\u3042\u3068 s \u4E0A\u3067 substr \u3092\u3050\u306B\
    \u3087\u3050\u306B\u3087\u30B9\u30E9\u30A4\u30C9\u3055\u305B\u3066\u3044\u304F\
    \r\n\t\tr++ \u306F \u7C21\u5358\u3067\u3001 l++ \u3082\u305D\u306E\u307E\u307E\
    \u304B link \u304B\u3060\u3051\u3069\u9577\u3055\u3092\u4FDD\u3063\u305F\u307E\
    \u307E\u3084\u308B\u306E\u304C\u3061\u3087\u3063\u3068\u96E3\u3057\u3044\r\n\t\
    \t\u3057\u3083\u304F\u3068\u308A\u3063\u307D\u304F l,r \u3067\u3084\u308B\u3088\
    \u308A \u4ECA\u8FFD\u52A0\u3057\u305F\u3044 i \u3068 \u4ECA\u306E\u6587\u5B57\u5217\
    \u306E\u9577\u3055 len \u3092\u6301\u3063\u305F\u307B\u3046\u304C\u304B\u306A\u308A\
    \u308F\u304B\u308A\u3084\u3059\u3044\r\n\t*/\r\n\tvoid solveCF253C(){\r\n\t\t\
    V<ll> dp(sz);\r\n\t\tNP last = nodes[sz-1];\r\n\t\twhile(last){\r\n\t\t\tdp[last->id]++;\r\
    \n\t\t\tlast = last -> link;\r\n\t\t}\r\n\t\tfor(int v=sz-1;v>=0;v--){\r\n\t\t\
    \tauto trans = nodes[v] -> getAllTransitions();\r\n\t\t\tfor(auto it: trans){\r\
    \n\t\t\t\tint u = it.sc->id;\r\n\t\t\t\tdp[v] += dp[u];\r\n\t\t\t}\r\n\t\t}\r\n\
    \r\n\t\tint Q;\r\n\t\tcin >> Q;\r\n\t\trep(_,Q){\r\n\t\t\tstring t;\r\n\t\t\t\
    cin >> t;\r\n\t\t\tint n = t.size();\r\n\t\t\tint len = 0;\r\n\t\t\tNP now = nodes[0];\r\
    \n\t\t\tV<NP> visited;\r\n\r\n\t\t\trep(i,n+n-1){\r\n\t\t\t\tchar c = t[i%n];\r\
    \n\t\t\t\twhile(now && !now->hasNext(c)){\r\n\t\t\t\t\tnow = now -> link;\r\n\t\
    \t\t\t\tlen = now ? now->getLongest() : 0; \r\n\t\t\t\t}\r\n\t\t\t\tif(!now){\r\
    \n\t\t\t\t\tnow = nodes[0];\r\n\t\t\t\t\tlen = 0;\r\n\t\t\t\t}else{\r\n\t\t\t\t\
    \tnow = now -> getNext(c);\r\n\t\t\t\t\tlen++;\r\n\t\t\t\t}\r\n\t\t\t\tif(len\
    \ > n){\r\n\t\t\t\t\tif(now -> getShortest() == len){\r\n\t\t\t\t\t\tnow = now\
    \ -> link;\r\n\t\t\t\t\t}\r\n\t\t\t\t\tlen--;\r\n\t\t\t\t\tassert(len == n);\r\
    \n\t\t\t\t}\r\n\t\t\t\tif(len == n){\r\n\t\t\t\t\tvisited.pb(now);\r\n\t\t\t\t\
    }\r\n\t\t\t}\r\n\t\t\tsort(all(visited));\r\n\t\t\tvisited.erase(unique(all(visited)),visited.end());\r\
    \n\t\t\tll ans = 0;\r\n\t\t\tfor(NP np : visited){\r\n\t\t\t\tans += dp[np->id];\r\
    \n\t\t\t}\r\n\t\t\tcout << ans << endl;\r\n\t\t}\r\n\t}\r\n\r\n\t/*\r\n\t\thttps://codeforces.com/contest/316/problem/G3\r\
    \n\r\n\t\t(t_i \u306B [l_i,r_i] \u56DE\u51FA\u73FE\u3059\u308B) \u3092\u3059\u3079\
    \u3066\u6E80\u305F\u3059 s \u306E substr \u306F\u4F55\u901A\u308A?\r\n\t\ta \u304C\
    \ t_i \u306B\u4F55\u56DE\u51FA\u73FE\u3059\u308B\u304B? \u306F #{where(a) -> t_i.terminal}\
    \ \u3092\u8003\u3048\u308C\u3070\u3088\u304B\u3063\u305F\r\n\r\n\t\t\u5B9F\u306F\
    \ str := s + '0' + t_1 + '1' + .. + t_Q + 'Q' \u3068\u3044\u3046\u6587\u5B57\u5217\
    \u3092 SA \u306B\u304B\u3051\u308B\u3068\u89E3\u3051\u308B\r\n\t\t\u5404\u30CE\
    \u30FC\u30C9\u5185\u3067\u306F\u3001t_i \u304C\u4F55\u56DE\u51FA\u3066\u304F\u308B\
    \u304B\u306F(\u305D\u306E\u30CE\u30FC\u30C9\u3078\u306E\u5230\u9054\u65B9\u6CD5\
    \u306B\u3088\u3089\u305A) \u4E00\u5B9A\r\n\t\t\u3053\u3046\u3084\u3063\u3066 str\
    \ \u3092\u4F5C\u308B\u3068\u3001 v -> '1' \u3078\u306E path \u304C\u4F55\u901A\
    \u308A\u3042\u308B\u304B? \u307F\u305F\u3044\u306A\u3082\u306E\u306B\u306A\u3063\
    \u3066\u307B\u3057\u3044\u304C\u3001\r\n\t\t\u5F53\u7136 '0' \u306E\u3042\u3068\
    \u306E\u3082\u306E\u3092\u6570\u3048\u305F\u308A substr -> '0' -> '1' \u307F\u305F\
    \u3044\u306B s \u306E\u5185\u5074\u306B\u53CE\u307E\u3063\u3066\u306A\u3044\u3082\
    \u306E\u3092\u6570\u3048\u3066\u3082\u3057\u3087\u3046\u304C\u306A\u3044\r\n\t\
    \t\u306A\u306E\u3067\u7B54\u3048\u306B\u5024\u3092\u8DB3\u3057\u8FBC\u3080\u306E\
    \u306F '0' \u306E\u524D (v -> '0' path exists) \u3067\u3001\r\n\t\tdp \u306E\u9077\
    \u79FB\u306F\u533A\u5207\u308A\u6587\u5B57\u306E\u3068\u304D\u306F\u3084\u3089\
    \u306A\u3044\u3088\u3046\u306B\u3059\u308B \u3068\u9054\u6210\u3067\u304D\u308B\
    \r\n\r\n\t\t\u533A\u5207\u308A\u6587\u5B57\u3067\u6587\u5B57\u5217\u305F\u3061\
    \u3092\u3064\u306A\u304E\u3001\u533A\u5207\u308A\u6587\u5B57\u306E\u3068\u3053\
    \u3067\u306F dp \u306E\u9077\u79FB\u3092\u3057\u306A\u3044\u3088\u3046\u306B\u3059\
    \u308B\u3068\u3001\r\n\t\t\u5404\u6587\u5B57\u5217\u306E\u5185\u5074\u3060\u3051\
    \u306E\u4F55\u3089\u304B\u306B\u6CE8\u76EE\u3067\u304D\u308B\u3001\u3068\u3044\
    \u3046\u306E\u306F\u5178\u578B\u3063\u307D\u3044\r\n\r\n\t\tdebug() \u306E\u3057\
    \u3084\u3059\u3055\u3092\u8003\u3048\u308B\u3068\u3001dp\u3068\u304B\u306F Node\
    \ \u5185\u90E8\u306B\u6301\u3064\u307B\u3046\u304C\u3044\u3044\u6C17\u304C\u3059\
    \u308B\u306A\u3042\r\n\t\t\u3068\u3044\u3046\u308F\u3051\u3067\u305D\u3046\u3044\
    \u3046\u5B9F\u88C5\u306B\u3057\u305F\u3001 Node \u306E\u4E2D\u8EAB\u3084 debug()\
    \ \u3092\u9069\u5B9C\u66F8\u304D\u63DB\u3048\u308B\r\n\t*/\r\n\r\n\tll solveCF316G(int\
    \ Q, V<int> L, V<int> R){\r\n\t\tstring special;\r\n\t\trep(i,Q+1) special +=\
    \ (char)('z'+1+i);\r\n\r\n\t\tll res = 0;\r\n\t\tfor(int v = sz-1; v>=0; v--){\r\
    \n\t\t\tNP n = nodes[v];\r\n            n -> dp = V<int>(Q+1,0);\r\n\t\t\trep(t,Q+1){\r\
    \n\t\t\t\tif(n -> hasNext(special[t])){\r\n\t\t\t\t\tn -> dp[t]++;\t\t\t\t\t//\
    \ #{v->terminal} ( = the # of appearance of this node in t)\r\n\t\t\t\t}\r\n\t\
    \t\t}\r\n\t\t\tauto trans = n -> getAllTransitions();\r\n\t\t\tfor(auto it: trans){\r\
    \n                if(!islower(it.fs)) continue;\r\n\t\t\t\trep(t,Q+1) n->dp[t]\
    \ += it.sc->dp[t];\r\n\t\t\t}\r\n\t\t\tif(v != 0 && n->dp[0]){\r\n\t\t\t\tbool\
    \ valid = true;\r\n\t\t\t\trep(t,Q){\r\n\t\t\t\t\tif( !(L[t]<=n->dp[t+1] && n->dp[t+1]<=R[t])\
    \ ) valid = false;\r\n\t\t\t\t}\r\n\t\t\t\tif(valid) res += n->getLongest() -\
    \ n->getShortest() + 1;\r\n\t\t\t}\r\n\t\t}\r\n//        debug();\r\n\t\treturn\
    \ res;\r\n\t}\r\n\r\n\t/*\r\n\t\thttps://www.spoj.com/problems/LCS/\r\n\t\tlongest\
    \ common substring\r\n\t\t\u3053\u308C\u3082\u533A\u5207\u308A\u6587\u5B57\u7CFB\
    \r\n\t*/\r\n\tint getLongestLCS(){\r\n\t\tint res = 0;\r\n//\t\tdebug();\r\n\t\
    \tfor(int v = sz-1; v>=0; v--){\r\n\t\t\tNP n = nodes[v];\r\n\t\t\tn -> reach\
    \ = V<bool>(2,false);\r\n\t\t\trep(t,2){\r\n\t\t\t\tif(n -> hasNext('0'+t)){\r\
    \n\t\t\t\t\tn -> reach[t] = true;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tauto trans\
    \ = n -> getAllTransitions();\r\n\t\t\tfor(auto it: trans){\r\n\t\t\t\tif(!islower(it.fs))\
    \ continue;\r\n\t\t\t\trep(t,2){\r\n\t\t\t\t\tif(it.sc->reach[t]) n->reach[t]\
    \ = true;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tif(n->reach[0] && n->reach[1]){\r\n\
    \t\t\t\tchmax(res,n->getLongest());\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\
    \t}\r\n\t\r\n};\r\n\r\nstruct Timer{\r\n\tclock_t st;\r\n\tvoid start(){\r\n\t\
    \tst = clock();\r\n\t}\r\n\tint ms(){\r\n\t\treturn (clock()-st)*1000 / CLOCKS_PER_SEC;\r\
    \n\t}\r\n};\r\n\r\nvoid test(string s){\r\n\tTimer timer;\r\n\ttimer.start();\r\
    \n\r\n\tSuffixAutomaton SA(s);\r\n\r\n\tV<string> substrs;\r\n\tint N = s.size();\r\
    \n\trep(i,N) for(int j=i;j<=N;j++){\r\n\t\tsubstrs.pb(s.substr(i,j-i));\r\n\t\
    }\r\n\tsort(all(substrs));\r\n\tsubstrs.erase(unique(all(substrs)),substrs.end());\r\
    \n\tint sz = SA.sz;\r\n\tVV<string> node2strs(sz);\r\n\tshow(sz);\r\n\tSA.TopologicalSort();\r\
    \n\tSA.debug();\r\n\r\n\tfor(string t: substrs){\r\n\t\tint v = SA.where(t);\r\
    \n\t\tassert(v != -1);\r\n\t\tnode2strs[v].pb(t);\r\n\t}\r\n\trep(v,sz){\r\n\t\
    \tcerr << \"-- v = \" << v << \" ----\" << endl;\r\n\t\tfor(string t: node2strs[v])\
    \ cerr << t << endl;\r\n\t}\r\n\r\n\tshow(timer.ms());\r\n}\r\n\r\nint main(){\r\
    \n\t// srand((unsigned)time(NULL));\r\n\t// for(int N: {1,10,100,1000,10000,100000,200000,500000,1000000}){\r\
    \n\t// \tstring s(N,'.');\r\n\t// \trep(i,N) s[i] = 'a' + rand()%26;\r\n\t// \t\
    test(s);\r\n\t// }\r\n\r\n\t// while(true){\r\n\t// \tstring s;\r\n\t// \tcin>>s;\r\
    \n\t// \ttest(s);\r\n\t// }\r\n\r\n\tstring s;\r\n\tint Q;\r\n\tcin>>s>>Q;\r\n\
    \tV<string> t(Q);\r\n\tV<int> L(Q),R(Q);\r\n\trep(i,Q){\r\n\t\tcin>>t[i];\r\n\t\
    \tcin>>L[i]>>R[i];\r\n\t}\r\n\tstring str = s;\r\n\tstr += char('z'+1);\r\n\t\
    rep(i,Q){\r\n\t\tstr += t[i];\r\n\t\tstr += char('z'+1+i);\r\n\t}\r\n\tSuffixAutomaton\
    \ SA(str);\r\n\tcout << SA.solve(Q,L,R) << endl;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/SuffixAutomaton.cpp
  requiredBy: []
  timestamp: '2019-02-12 17:44:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/SuffixAutomaton.cpp
layout: document
redirect_from:
- /library/string/SuffixAutomaton.cpp
- /library/string/SuffixAutomaton.cpp.html
title: string/SuffixAutomaton.cpp
---
