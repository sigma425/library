---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/twosat.cpp\"\n/*\n\t2-SAT\n\ttrue,false\u3068\u3044\
    \u3046\u3088\u308A\u304B\u306F a0 xor a1 (\u6392\u53CD) \u307F\u305F\u3044\u306A\
    \u6C17\u6301\u3061\n\tscc\u306B\u4F9D\u5B58\n\tO(N+M)\n\tverify : ARC069 F\n*/\n\
    struct twosat{\n\tstruct E{int to;};\n\tint N;\n\tVV<E> G;\n\n\ttwosat(int varnum):N(varnum),G(N+N){}\n\
    \n\tvoid OR(int x,int xtype,int y,int ytype){\n\t\t// cerr << \"add \" << x <<\
    \ \":\" << xtype << \" or \" << y << \":\" << ytype << endl;\n\t\tx = x*2 + xtype,\
    \ y = y*2 + ytype;\n\t\tG[x^1].push_back({y});\n\t\tG[y^1].push_back({x});\n\t\
    }\n\tvoid THEN(int x,int xtype,int y,int ytype){\n\t\tOR(x,1-xtype,y,ytype);\n\
    \t}\n\tvoid EQ(int x,int xtype,int y,int ytype){\n\t\tTHEN(x,xtype,y,ytype);\n\
    \t\tTHEN(y,ytype,x,xtype);\n\t}\n\t/*\n\t\t\u3053\u3063\u3061\u306F 0_1 / 2_3\
    \ / .. N+N-2_N+N-1 \u304C\u30DA\u30A2\n\t*/\n\tvoid OR(int x, int y){\n\t\tG[x^1].push_back({y});\n\
    \t\tG[y^1].push_back({x});\n\t}\n\tvoid THEN(int x,int y){\n\t\t// cerr << \"\
    THEN:\" << x << \" -> \" << y << endl;\n\t\tOR(x^1,y);\n\t}\n\tvoid EQ(int x,int\
    \ y){\n\t\tTHEN(x,y);\n\t\tTHEN(y,x);\n\t}\n\tV<int> solve(){\t\t// select which\
    \ type\n\t\tSCC<E> scc(G);\n\t\trep(i,N) if(scc.id[i*2] == scc.id[i*2+1]) return\
    \ {};\n\t\tV<int> res(N,-1);\n\t\tper(k,scc.groups.size()){\n\t\t\tfor(int v:\
    \ scc.groups[k]){\n\t\t\t\tif(res[v/2] == -1) res[v/2] = v%2;\n\t\t\t}\n\t\t}\n\
    \t\treturn res;\n\t}\n};\n"
  code: "/*\n\t2-SAT\n\ttrue,false\u3068\u3044\u3046\u3088\u308A\u304B\u306F a0 xor\
    \ a1 (\u6392\u53CD) \u307F\u305F\u3044\u306A\u6C17\u6301\u3061\n\tscc\u306B\u4F9D\
    \u5B58\n\tO(N+M)\n\tverify : ARC069 F\n*/\nstruct twosat{\n\tstruct E{int to;};\n\
    \tint N;\n\tVV<E> G;\n\n\ttwosat(int varnum):N(varnum),G(N+N){}\n\n\tvoid OR(int\
    \ x,int xtype,int y,int ytype){\n\t\t// cerr << \"add \" << x << \":\" << xtype\
    \ << \" or \" << y << \":\" << ytype << endl;\n\t\tx = x*2 + xtype, y = y*2 +\
    \ ytype;\n\t\tG[x^1].push_back({y});\n\t\tG[y^1].push_back({x});\n\t}\n\tvoid\
    \ THEN(int x,int xtype,int y,int ytype){\n\t\tOR(x,1-xtype,y,ytype);\n\t}\n\t\
    void EQ(int x,int xtype,int y,int ytype){\n\t\tTHEN(x,xtype,y,ytype);\n\t\tTHEN(y,ytype,x,xtype);\n\
    \t}\n\t/*\n\t\t\u3053\u3063\u3061\u306F 0_1 / 2_3 / .. N+N-2_N+N-1 \u304C\u30DA\
    \u30A2\n\t*/\n\tvoid OR(int x, int y){\n\t\tG[x^1].push_back({y});\n\t\tG[y^1].push_back({x});\n\
    \t}\n\tvoid THEN(int x,int y){\n\t\t// cerr << \"THEN:\" << x << \" -> \" << y\
    \ << endl;\n\t\tOR(x^1,y);\n\t}\n\tvoid EQ(int x,int y){\n\t\tTHEN(x,y);\n\t\t\
    THEN(y,x);\n\t}\n\tV<int> solve(){\t\t// select which type\n\t\tSCC<E> scc(G);\n\
    \t\trep(i,N) if(scc.id[i*2] == scc.id[i*2+1]) return {};\n\t\tV<int> res(N,-1);\n\
    \t\tper(k,scc.groups.size()){\n\t\t\tfor(int v: scc.groups[k]){\n\t\t\t\tif(res[v/2]\
    \ == -1) res[v/2] = v%2;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/twosat.cpp
  requiredBy: []
  timestamp: '2020-09-20 08:08:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/twosat.cpp
layout: document
redirect_from:
- /library/graph/twosat.cpp
- /library/graph/twosat.cpp.html
title: graph/twosat.cpp
---
