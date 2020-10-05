---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DP/CHT.cpp\"\n/*\n\tconvex hull trick\n\t\u76F4\u7DDA\u96C6\
    \u5408 S={y=ax+b}\u306B\u5BFE\u3057,\u6B21\u306E\u64CD\u4F5C\u304C\u3067\u304D\
    \u308B\n\t- S\u306B\u76F4\u7DDA\u3092\u52A0\u3048\u308B,\u305F\u3060\u3057,\u300C\
    S\u306E\u4E2D\u3067\u6700\u3082a\u304C\u5C0F\u3055\u3044\u3082\u306E\u300D\u3092\
    \u52A0\u3048\u306A\u304D\u3083\u3044\u3051\u306A\u3044(\u3064\u307E\u308A\u8FFD\
    \u52A0\u30AF\u30A8\u30EA\u306Ea\u306F\u5358\u8ABF\u6E1B\u5C11)\n\t- \"\u4E0E\u3048\
    \u3089\u308C\u305Fx\"\u306B\u5BFE\u3057,min{a_i*x+b_i | i} \u3092\u6C42\u3081\u308B\
    \n\n\t\u30AF\u30A8\u30EAx\u304C\u5358\u8ABF\u5897\u52A0\u306E\u5834\u5408,incremental\u306B\
    \u3084\u308C\u3070\u5168\u4F53\u3067O(N)\n\t\u305D\u3046\u3067\u306A\u3044\u306A\
    \u3089,\u666E\u901A\u306BS\u306B\u5BFE\u3057\u306B\u3076\u305F\u3093\u3059\u308C\
    \u3070\u3044\u3044\n\n\t\u8FFD\u52A0\u30AF\u30A8\u30EA\u304C\u5358\u8ABF\u6E1B\
    \u5C11\u3067\u306A\u3044\u5834\u5408,S\u3092set\u3067\u3082\u3063\u3066,\u3069\
    \u306E\u7BC4\u56F2\u3092\u524A\u308B\u304B\u9811\u5F35\u308B\u5FC5\u8981\u304C\
    \u3042\u308B\n\t\u3053\u3063\u3061\u306F\u3084\u308B\u3053\u3068\u306F\u308F\u304B\
    \u308B\u3093\u3060\u3051\u3069\u66F8\u304F\u306E\u304C\u9762\u5012 CHT2.cpp\u3092\
    \u53C2\u8003\n\n\n\n\t\u2191\u306F\u76F4\u7DDA\u96C6\u5408 \u306By\u8EF8\u306B\
    \u5E73\u884C\u306A\u76F4\u7DDA\u3092\u5F15\u3044\u3066\u4EA4\u308F\u308B\u90E8\
    \u5206\u306E\u6700\u5927\u3092\u6C42\u3081\u308B\u5F62.\n\t\u2193\u306F\u70B9\u96C6\
    \u5408\u306B\u3001\u3042\u308B\u50BE\u304D\u306E\u76F4\u7DDA\u3092\u4E0A\u304B\
    \u3089\u304A\u308D\u3057\u3066\u3044\u304F\u30A4\u30E1\u30FC\u30B8\n\n\t\u70B9\
    \u96C6\u5408S={(a,b)}\u304C\u4E0E\u3048\u3089\u308C\u308B.\u6B21\u306E\u64CD\u4F5C\
    \u304C\u3067\u304D\u308B.\n\t- S\u306B\u70B9\u3092\u52A0\u3048\u308B,\u305F\u3060\
    \u3057,\u300CS\u306E\u4E2D\u3067\u6700\u3082a\u304C\u5927\u304D\u3044\u3082\u306E\
    \u300D\u3092\u52A0\u3048\u308B\n\t- \u4E0E\u3048\u3089\u308C\u305F\u50BE\u304D\
    t\u306B\u5BFE\u3057\u3001\u305D\u306E\u76F4\u7DDA\u3092\u3069\u3053\u307E\u3067\
    \u4E0B\u3052\u3089\u308C\u308B\u304B(\u3059\u306A\u308F\u3061\u3001max b-ta)\n\
    \n\n\t\u3053\u306E\u5BFE\u5FDC\u306F\u3001\u70B9\u3068\u76F4\u7DDA\u306E\u53CC\
    \u5BFE((a,b) <-> y=ax-b)\u3092\u53D6\u308A\u3001\u305D\u306E\u5F8C\u7B26\u53F7\
    \u3092\u53CD\u8EE2\u3057\u305F\u5F62\u306B\u306A\u3063\u3066\u3044\u308B.(\u3064\
    \u307E\u308Ay=-ax+b\u3068\u3059\u308B\u3068\u5B8C\u5168\u306B\u305F\u3060\u306E\
    \u53CC\u5BFE)\n\n\n\t\u3060\u304B\u3089max\u3092\u6C42\u3081\u308B\u5F62\u306E\
    \u3068\u304D\u306F\u3001a->-a,b->-b\u3068\u3057\u3066\u3053\u306E\u30B3\u30FC\u30C9\
    \u306B\u7A81\u3063\u8FBC\u3081\u3070\u826F\u304F\u3066\u3001\n\t\u6CE8\u610F\u3059\
    \u3079\u304D\u3053\u3068\u3068\u3057\u3066\u306F,\u8FFD\u52A0\u30AF\u30A8\u30EA\
    \u306Ea\u304C\u5143\u306Ea\u304C\u5C0F\u3055\u3044\u9806\u306B\u306A\u308B\n\n\
    \n\t\u3066\u3044\u3046\u304B\u3001\u3069\u3063\u3061\u3082\u51F8\u5305\u306E\u4E0A\
    \u5074\u3092\u6C42\u3081\u308B\u3068\u304D\u306E\u9014\u4E2D\u7D4C\u904E\u304C\
    \u3069\u3046\u306A\u3063\u3066\u308B\u304B\u8003\u3048\u308B\u3068\u308F\u304B\
    \u308B\u3088\u306D?\n\t\u4E0B\u5074\u3092\u3084\u308D\u3046\u3068\u3059\u308B\u3068\
    min\u3068max\u3067\u6C42\u3081\u3089\u308C\u308B\u3082\u306E\u304C\u5909\u308F\
    \u308B\u306E\u3068\u3001\u3042\u3068\u8FFD\u52A0\u30AF\u30A8\u30EA\u306E\u50BE\
    \u304D\u306E\u5927\u5C0F\u95A2\u4FC2\u306E\u9806\u756A\u304C\u5909\u308F\u308B\
    ?(isright\u3068\u304B\u3082isleft\u306B\u5909\u308F\u308B\u6C17\u304C\u3059\u308B\
    \u3057\u3061\u3087\u3063\u3068\u3053\u308F\u3044)\n\n\n*/\n#include <bits/stdc++.h>\n\
    #define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<\"(\"\
    <<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class T> ostream& operator<<(ostream& o,const\
    \ vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"[\";for(const T& v:vc) o<<v<<\"\
    ,\";o<<\"]\";return o;}\n\nstruct CHT{\n\tusing D = ll;\n\ttypedef pair<D,D> P;\n\
    \tvector<P> deq;\n\tint s,sd,t;\n\n\tCHT():s(0),sd(0),t(0){}\n\tvoid add(D a,D\
    \ b){\t\t//add ax+b     a:(\u5E83\u7FA9)\u5358\u8ABF\u6E1B\u5C11!!!\n\t\tP p(a,b);\n\
    \t\twhile(s+1<t&&check(deq[t-2],deq[t-1],p)) t--;\n\t\tif(t == (int)deq.size())\
    \ deq.pb(p);\n\t\tdeq[t++]=p;\n\t}\n\tD incr_query(D x){\t\t//x:\u5358\u8ABF\u5897\
    \u52A0\u306E\u6642,\u3053\u308C\u3092\u7E70\u308A\u8FD4\u3057\u547C\u3076(\u9593\
    \u306Badd\u304C\u631F\u307E\u308B\u306E\u306FOK)\n\t\twhile(s+1<t&&f(deq[s],x)>=f(deq[s+1],x))\
    \ s++;\n\t\treturn f(deq[s],x);\n\t}\n\tD decr_query(D x){\t\t//x:\u5358\u8ABF\
    \u6E1B\u5C11\u306E\u6642,\u3053\u308C\u3092\u7E70\u308A\u8FD4\u3057\u547C\u3076\
    (\u9593\u306Badd\u304C\u631F\u307E\u308B\u306E\u306FOK)\n\t\tif(sd>=t) sd=t-1;\n\
    \t\twhile(sd+1<t&&f(deq[sd],x)>=f(deq[sd+1],x)) sd++;\n\t\twhile(sd>0&&f(deq[sd],x)<f(deq[sd-1],x))\
    \ sd--;\n\t\treturn f(deq[sd],x);\n\t}\n\tD query(D x){\n\t\tint lb=s-1,ub=t-1;\n\
    \t\twhile(ub-lb>1){\n\t\t\tint m=(lb+ub)/2;\n\t\t\tif(isright(deq[m],deq[m+1],x))\
    \ lb=m;\n\t\t\telse ub=m;\n\t\t}\n\t\treturn f(deq[ub],x);\n\t}\n\n\tbool isright(P&\
    \ a,P& b,D x){\n\t\treturn f(a,x)>=f(b,x);\n\t}\n\tbool check(P& a,P& b,P& c){\n\
    \t\treturn (b.fs-a.fs)*(c.sc-b.sc)>=(b.sc-a.sc)*(c.fs-b.fs);\n\t}\n\tD f(P &p,int\
    \ x){\n\t\treturn p.fs*x+p.sc;\n\t}\n};\n\nint main(){\n\tcht.init(3);\n\tcht.add(2,3);\n\
    \tcht.add(-1,4);\n\tshow(cht.query(1));\n}\n"
  code: "/*\n\tconvex hull trick\n\t\u76F4\u7DDA\u96C6\u5408 S={y=ax+b}\u306B\u5BFE\
    \u3057,\u6B21\u306E\u64CD\u4F5C\u304C\u3067\u304D\u308B\n\t- S\u306B\u76F4\u7DDA\
    \u3092\u52A0\u3048\u308B,\u305F\u3060\u3057,\u300CS\u306E\u4E2D\u3067\u6700\u3082\
    a\u304C\u5C0F\u3055\u3044\u3082\u306E\u300D\u3092\u52A0\u3048\u306A\u304D\u3083\
    \u3044\u3051\u306A\u3044(\u3064\u307E\u308A\u8FFD\u52A0\u30AF\u30A8\u30EA\u306E\
    a\u306F\u5358\u8ABF\u6E1B\u5C11)\n\t- \"\u4E0E\u3048\u3089\u308C\u305Fx\"\u306B\
    \u5BFE\u3057,min{a_i*x+b_i | i} \u3092\u6C42\u3081\u308B\n\n\t\u30AF\u30A8\u30EA\
    x\u304C\u5358\u8ABF\u5897\u52A0\u306E\u5834\u5408,incremental\u306B\u3084\u308C\
    \u3070\u5168\u4F53\u3067O(N)\n\t\u305D\u3046\u3067\u306A\u3044\u306A\u3089,\u666E\
    \u901A\u306BS\u306B\u5BFE\u3057\u306B\u3076\u305F\u3093\u3059\u308C\u3070\u3044\
    \u3044\n\n\t\u8FFD\u52A0\u30AF\u30A8\u30EA\u304C\u5358\u8ABF\u6E1B\u5C11\u3067\
    \u306A\u3044\u5834\u5408,S\u3092set\u3067\u3082\u3063\u3066,\u3069\u306E\u7BC4\
    \u56F2\u3092\u524A\u308B\u304B\u9811\u5F35\u308B\u5FC5\u8981\u304C\u3042\u308B\
    \n\t\u3053\u3063\u3061\u306F\u3084\u308B\u3053\u3068\u306F\u308F\u304B\u308B\u3093\
    \u3060\u3051\u3069\u66F8\u304F\u306E\u304C\u9762\u5012 CHT2.cpp\u3092\u53C2\u8003\
    \n\n\n\n\t\u2191\u306F\u76F4\u7DDA\u96C6\u5408 \u306By\u8EF8\u306B\u5E73\u884C\
    \u306A\u76F4\u7DDA\u3092\u5F15\u3044\u3066\u4EA4\u308F\u308B\u90E8\u5206\u306E\
    \u6700\u5927\u3092\u6C42\u3081\u308B\u5F62.\n\t\u2193\u306F\u70B9\u96C6\u5408\u306B\
    \u3001\u3042\u308B\u50BE\u304D\u306E\u76F4\u7DDA\u3092\u4E0A\u304B\u3089\u304A\
    \u308D\u3057\u3066\u3044\u304F\u30A4\u30E1\u30FC\u30B8\n\n\t\u70B9\u96C6\u5408\
    S={(a,b)}\u304C\u4E0E\u3048\u3089\u308C\u308B.\u6B21\u306E\u64CD\u4F5C\u304C\u3067\
    \u304D\u308B.\n\t- S\u306B\u70B9\u3092\u52A0\u3048\u308B,\u305F\u3060\u3057,\u300C\
    S\u306E\u4E2D\u3067\u6700\u3082a\u304C\u5927\u304D\u3044\u3082\u306E\u300D\u3092\
    \u52A0\u3048\u308B\n\t- \u4E0E\u3048\u3089\u308C\u305F\u50BE\u304Dt\u306B\u5BFE\
    \u3057\u3001\u305D\u306E\u76F4\u7DDA\u3092\u3069\u3053\u307E\u3067\u4E0B\u3052\
    \u3089\u308C\u308B\u304B(\u3059\u306A\u308F\u3061\u3001max b-ta)\n\n\n\t\u3053\
    \u306E\u5BFE\u5FDC\u306F\u3001\u70B9\u3068\u76F4\u7DDA\u306E\u53CC\u5BFE((a,b)\
    \ <-> y=ax-b)\u3092\u53D6\u308A\u3001\u305D\u306E\u5F8C\u7B26\u53F7\u3092\u53CD\
    \u8EE2\u3057\u305F\u5F62\u306B\u306A\u3063\u3066\u3044\u308B.(\u3064\u307E\u308A\
    y=-ax+b\u3068\u3059\u308B\u3068\u5B8C\u5168\u306B\u305F\u3060\u306E\u53CC\u5BFE\
    )\n\n\n\t\u3060\u304B\u3089max\u3092\u6C42\u3081\u308B\u5F62\u306E\u3068\u304D\
    \u306F\u3001a->-a,b->-b\u3068\u3057\u3066\u3053\u306E\u30B3\u30FC\u30C9\u306B\u7A81\
    \u3063\u8FBC\u3081\u3070\u826F\u304F\u3066\u3001\n\t\u6CE8\u610F\u3059\u3079\u304D\
    \u3053\u3068\u3068\u3057\u3066\u306F,\u8FFD\u52A0\u30AF\u30A8\u30EA\u306Ea\u304C\
    \u5143\u306Ea\u304C\u5C0F\u3055\u3044\u9806\u306B\u306A\u308B\n\n\n\t\u3066\u3044\
    \u3046\u304B\u3001\u3069\u3063\u3061\u3082\u51F8\u5305\u306E\u4E0A\u5074\u3092\
    \u6C42\u3081\u308B\u3068\u304D\u306E\u9014\u4E2D\u7D4C\u904E\u304C\u3069\u3046\
    \u306A\u3063\u3066\u308B\u304B\u8003\u3048\u308B\u3068\u308F\u304B\u308B\u3088\
    \u306D?\n\t\u4E0B\u5074\u3092\u3084\u308D\u3046\u3068\u3059\u308B\u3068min\u3068\
    max\u3067\u6C42\u3081\u3089\u308C\u308B\u3082\u306E\u304C\u5909\u308F\u308B\u306E\
    \u3068\u3001\u3042\u3068\u8FFD\u52A0\u30AF\u30A8\u30EA\u306E\u50BE\u304D\u306E\
    \u5927\u5C0F\u95A2\u4FC2\u306E\u9806\u756A\u304C\u5909\u308F\u308B?(isright\u3068\
    \u304B\u3082isleft\u306B\u5909\u308F\u308B\u6C17\u304C\u3059\u308B\u3057\u3061\
    \u3087\u3063\u3068\u3053\u308F\u3044)\n\n\n*/\n#include <bits/stdc++.h>\n#define\
    \ rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<\"(\"\
    <<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class T> ostream& operator<<(ostream& o,const\
    \ vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"[\";for(const T& v:vc) o<<v<<\"\
    ,\";o<<\"]\";return o;}\n\nstruct CHT{\n\tusing D = ll;\n\ttypedef pair<D,D> P;\n\
    \tvector<P> deq;\n\tint s,sd,t;\n\n\tCHT():s(0),sd(0),t(0){}\n\tvoid add(D a,D\
    \ b){\t\t//add ax+b     a:(\u5E83\u7FA9)\u5358\u8ABF\u6E1B\u5C11!!!\n\t\tP p(a,b);\n\
    \t\twhile(s+1<t&&check(deq[t-2],deq[t-1],p)) t--;\n\t\tif(t == (int)deq.size())\
    \ deq.pb(p);\n\t\tdeq[t++]=p;\n\t}\n\tD incr_query(D x){\t\t//x:\u5358\u8ABF\u5897\
    \u52A0\u306E\u6642,\u3053\u308C\u3092\u7E70\u308A\u8FD4\u3057\u547C\u3076(\u9593\
    \u306Badd\u304C\u631F\u307E\u308B\u306E\u306FOK)\n\t\twhile(s+1<t&&f(deq[s],x)>=f(deq[s+1],x))\
    \ s++;\n\t\treturn f(deq[s],x);\n\t}\n\tD decr_query(D x){\t\t//x:\u5358\u8ABF\
    \u6E1B\u5C11\u306E\u6642,\u3053\u308C\u3092\u7E70\u308A\u8FD4\u3057\u547C\u3076\
    (\u9593\u306Badd\u304C\u631F\u307E\u308B\u306E\u306FOK)\n\t\tif(sd>=t) sd=t-1;\n\
    \t\twhile(sd+1<t&&f(deq[sd],x)>=f(deq[sd+1],x)) sd++;\n\t\twhile(sd>0&&f(deq[sd],x)<f(deq[sd-1],x))\
    \ sd--;\n\t\treturn f(deq[sd],x);\n\t}\n\tD query(D x){\n\t\tint lb=s-1,ub=t-1;\n\
    \t\twhile(ub-lb>1){\n\t\t\tint m=(lb+ub)/2;\n\t\t\tif(isright(deq[m],deq[m+1],x))\
    \ lb=m;\n\t\t\telse ub=m;\n\t\t}\n\t\treturn f(deq[ub],x);\n\t}\n\n\tbool isright(P&\
    \ a,P& b,D x){\n\t\treturn f(a,x)>=f(b,x);\n\t}\n\tbool check(P& a,P& b,P& c){\n\
    \t\treturn (b.fs-a.fs)*(c.sc-b.sc)>=(b.sc-a.sc)*(c.fs-b.fs);\n\t}\n\tD f(P &p,int\
    \ x){\n\t\treturn p.fs*x+p.sc;\n\t}\n};\n\nint main(){\n\tcht.init(3);\n\tcht.add(2,3);\n\
    \tcht.add(-1,4);\n\tshow(cht.query(1));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/CHT.cpp
  requiredBy: []
  timestamp: '2019-04-30 09:07:58+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/CHT.cpp
layout: document
redirect_from:
- /library/DP/CHT.cpp
- /library/DP/CHT.cpp.html
title: DP/CHT.cpp
---
