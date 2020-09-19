---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/scc.cpp
    title: graph/scc.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test_oj/scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n\n#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define\
    \ rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n#define\
    \ pb push_back\n#define fs first\n#define sc second\n#define chmin(x,y) x=min(x,y)\n\
    #define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class S,class T>\
    \ ostream& operator<<(ostream& o,const pair<S,T> &p){\n\treturn o<<\"(\"<<p.fs<<\"\
    ,\"<<p.sc<<\")\";\n}\ntemplate<class T> ostream& operator<<(ostream& o,const vector<T>\
    \ &vc){\n\to<<\"{\";\n\tfor(const T& v:vc) o<<v<<\",\";\n\to<<\"}\";\n\treturn\
    \ o;\n}\nusing ll = long long;\ntemplate<class T> using V = vector<T>;\ntemplate<class\
    \ T> using VV = vector<vector<T>>;\nconstexpr ll TEN(int n) { return (n == 0)\
    \ ? 1 : 10 * TEN(n-1); }\n\n#ifdef LOCAL\n#define show(x) cerr << \"LINE\" <<\
    \ __LINE__ << \" : \" << #x << \" = \" << (x) << endl\n#else\n#define show(x)\
    \ true\n#endif\n\n#line 1 \"graph/scc.cpp\"\n/*\r\n    SCC O(M+N)\r\n    id[v]\
    \ = v \u306E \u9023\u7D50\u6210\u5206\u306E id\r\n    groups[i] : i\u756A\u76EE\
    \u306E\u9023\u7D50\u6210\u5206, \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\r\n\
    */\r\ntemplate <class E>\r\nstruct SCC{\r\n\tV<int> id;\r\n\tVV<int> groups;\r\
    \n\r\n\tint N;\r\n\tVV<E> G;\r\n\tV<int> ord,low;\r\n\tV<bool> inS;\r\n\tV<int>\
    \ st;\r\n    int I=0;\r\n\r\n\tvoid dfs(int v){\r\n\t\tord[v] = low[v] = I++;\r\
    \n\t\tst.pb(v); inS[v] = true;\r\n\t\tfor(auto e: G[v]){\r\n\t\t\tint u = e.to;\r\
    \n\t\t\tif(ord[u] == -1){\r\n\t\t\t\tdfs(u);\r\n\t\t\t\tchmin(low[v],low[u]);\r\
    \n\t\t\t}else if(inS[u]){\r\n\t\t\t\tchmin(low[v],ord[u]);\r\n\t\t\t}\r\n\t\t\
    }\r\n\t\tif(low[v] == ord[v]){\r\n\t\t\tV<int> group;\r\n\t\t\twhile(true){\r\n\
    \t\t\t\tint w = st.back(); st.pop_back();\r\n\t\t\t\tinS[w] = false;\r\n\t\t\t\
    \tgroup.pb(w);\r\n\t\t\t\tif(w == v) break;\r\n\t\t\t}\r\n\t\t\tgroups.pb(group);\r\
    \n\t\t}\r\n\t}\r\n\tSCC(const VV<E>& G_) : N(G_.size()), G(G_), ord(N,-1), low(N),\
    \ inS(N){\r\n        id = V<int>(N);\r\n\t\trep(i,N) if(ord[i] == -1) dfs(i);\r\
    \n\t\treverse(all(groups));\r\n\t\trep(i,groups.size()){\r\n\t\t\tfor(int v: groups[i])\
    \ id[v] = i;\r\n\t\t}\r\n\t}\r\n};\n#line 34 \"test_oj/scc.test.cpp\"\n\nint main(){\n\
    \tcin.tie(0);\n\tios::sync_with_stdio(false);\t\t//DON'T USE scanf/printf/puts\
    \ !!\n\tcout << fixed << setprecision(20);\n\t\n   int N,M;\n   cin >> N >> M;\n\
    \   struct E{int to;};\n   VV<E> G(N);\n   rep(i,M){\n       int x,y;\n      \
    \ cin >> x >> y;\n       G[x].pb({y});\n   }\n   auto scc = SCC<E>(G);\n   auto&\
    \ groups = scc.groups;\n   cout << groups.size() << endl;\n   for(auto g: groups){\n\
    \       cout << g.size();\n       for(int v: g) cout << \" \" << v;\n       cout\
    \ << endl;\n   }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <bits/stdc++.h>\n\
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
    \ << endl\n#else\n#define show(x) true\n#endif\n\n#include \"../graph/scc.cpp\"\
    \n\nint main(){\n\tcin.tie(0);\n\tios::sync_with_stdio(false);\t\t//DON'T USE\
    \ scanf/printf/puts !!\n\tcout << fixed << setprecision(20);\n\t\n   int N,M;\n\
    \   cin >> N >> M;\n   struct E{int to;};\n   VV<E> G(N);\n   rep(i,M){\n    \
    \   int x,y;\n       cin >> x >> y;\n       G[x].pb({y});\n   }\n   auto scc =\
    \ SCC<E>(G);\n   auto& groups = scc.groups;\n   cout << groups.size() << endl;\n\
    \   for(auto g: groups){\n       cout << g.size();\n       for(int v: g) cout\
    \ << \" \" << v;\n       cout << endl;\n   }\n}\n"
  dependsOn:
  - graph/scc.cpp
  isVerificationFile: true
  path: test_oj/scc.test.cpp
  requiredBy: []
  timestamp: '2020-02-10 02:28:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test_oj/scc.test.cpp
layout: document
redirect_from:
- /verify/test_oj/scc.test.cpp
- /verify/test_oj/scc.test.cpp.html
title: test_oj/scc.test.cpp
---
