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
  bundledCode: "#line 1 \"math/babygiant.cpp\"\n//g in group G, x in set X\n//G,X\u3092\
    class\u3067\u306A\u304Ftypedef\u306B\u3059\u308B\u3068\u304D\u306F==\u306E\u6761\
    \u4EF6\u3068\u304B\u306B\u6CE8\u610F\nconst int BN,GN;\nX act(G g,X x){\n\n}\n\
    G pro(G f,G g){\n\n}\nG ex(G g,int N){\n\tG e=;\n\twhile(N){\n\t\tif(N%2) e=pro(g,e);\n\
    \t\tg=pro(g,g);\n\t\tN>>=1;\n\t}\n\treturn e;\n}\nll solve2(G g,X s,X t){\t\t\
    //calc min k s.t.{g^n(s)=t}\t\tif no ans, -1\n\tif(s==t) return 0;\n\tpair<X,int>\
    \ babies[BN];\n\trep(i,BN){\t//0~BN-1\n\t\tbabies[i]=mp(t,i);\n\t\tt=act(g,t);\n\
    \t}\n\tsort(babies,babies+BN);\n\tg=ex(g,BN);\t//g->g^BN\n\trep1(i,GN){\t\t//1~GN\n\
    \t\ts=act(g,s);\n\t\tint pos=upper_bound(babies,babies+BN,mp(s,BN))-babies-1;\n\
    \t\tif(pos>=0&&babies[pos].fs==s) return i*BN-babies[pos].sc;\n\t}\n\treturn -1;\n\
    }\nll solve(G g,X s,X t){\t\t//calc next some times\n\tif(s==t) return 0;\n\t\
    rep1(i,){\n\t\ts=act(g,s);\n\t\tif(s==t) return i;\n\t}\n\t//\u51E6\u7406\n\t\
    ll tmp=solve2();\n\tif(tmp>=0) return tmp+;\n\treturn -1;\n}\nll brute(G g,X s,X\
    \ t){\n\tif(s==t) return 0;\n\trep(i,1000000){\n\t\ts=act(g,s);\n\t\tif(s==t)\
    \ return i+1;\n\t}\n\treturn -1;\n}\nint main(){\n\t\n}\n"
  code: "//g in group G, x in set X\n//G,X\u3092class\u3067\u306A\u304Ftypedef\u306B\
    \u3059\u308B\u3068\u304D\u306F==\u306E\u6761\u4EF6\u3068\u304B\u306B\u6CE8\u610F\
    \nconst int BN,GN;\nX act(G g,X x){\n\n}\nG pro(G f,G g){\n\n}\nG ex(G g,int N){\n\
    \tG e=;\n\twhile(N){\n\t\tif(N%2) e=pro(g,e);\n\t\tg=pro(g,g);\n\t\tN>>=1;\n\t\
    }\n\treturn e;\n}\nll solve2(G g,X s,X t){\t\t//calc min k s.t.{g^n(s)=t}\t\t\
    if no ans, -1\n\tif(s==t) return 0;\n\tpair<X,int> babies[BN];\n\trep(i,BN){\t\
    //0~BN-1\n\t\tbabies[i]=mp(t,i);\n\t\tt=act(g,t);\n\t}\n\tsort(babies,babies+BN);\n\
    \tg=ex(g,BN);\t//g->g^BN\n\trep1(i,GN){\t\t//1~GN\n\t\ts=act(g,s);\n\t\tint pos=upper_bound(babies,babies+BN,mp(s,BN))-babies-1;\n\
    \t\tif(pos>=0&&babies[pos].fs==s) return i*BN-babies[pos].sc;\n\t}\n\treturn -1;\n\
    }\nll solve(G g,X s,X t){\t\t//calc next some times\n\tif(s==t) return 0;\n\t\
    rep1(i,){\n\t\ts=act(g,s);\n\t\tif(s==t) return i;\n\t}\n\t//\u51E6\u7406\n\t\
    ll tmp=solve2();\n\tif(tmp>=0) return tmp+;\n\treturn -1;\n}\nll brute(G g,X s,X\
    \ t){\n\tif(s==t) return 0;\n\trep(i,1000000){\n\t\ts=act(g,s);\n\t\tif(s==t)\
    \ return i+1;\n\t}\n\treturn -1;\n}\nint main(){\n\t\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/babygiant.cpp
  requiredBy: []
  timestamp: '2018-09-18 03:14:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/babygiant.cpp
layout: document
redirect_from:
- /library/math/babygiant.cpp
- /library/math/babygiant.cpp.html
title: math/babygiant.cpp
---
