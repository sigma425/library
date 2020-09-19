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
  bundledCode: "#line 1 \"DP/Helvetic_O.cpp\"\n/*\nN\u500B\u306E\u5217\u3092K\u500B\
    \u306E\u9023\u7D9A\u5217\u306B\u5206\u89E3\u3059\u308B\u5834\u5408,\u611A\u76F4\
    DP\u3060\u3068O(N^2K)\u306B\u306A\u308B\nCHT\u3068\u304B\u3092\u4F7F\u3063\u3066\
    \u8CB0\u3046DP\u306E\u9077\u79FB\u3092O(NK)\u306B\u3067\u304D\u308B\n\n\u533A\u9593\
    K\u500B\u306B\u5206\u5272\u3059\u308B\u6642,\u300CK\u500B\u300D\u306E\u6761\u4EF6\
    \u3092\u306A\u304F\u3057\u305F\u5F8C, \u5404\u533A\u9593\u306E\u30B3\u30B9\u30C8\
    \u306B + c \u3057\u3066\u89E3\u304F\n\u6C42\u3081\u305F\u3044\u3082\u306E\u304C\
    K\u306B\u95A2\u3057\u3066\u51F8\u306A\u3089\u3001+c\u3092\u306B\u3076\u305F\u3093\
    \u3057\u3066\u3061\u3087\u3046\u3069K\u500B\u306B\u306A\u308B\u3068\u3053\u308D\
    \u3092\u7B54\u3048\u3068\u3059\u308B\n*/\n\n#include <bits/stdc++.h>\n#define\
    \ rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmax(x,y)\
    \ x=max(x,y)\nusing namespace std;\ntemplate<class S,class T> ostream& operator<<(ostream&\
    \ o,const pair<S,T> &p){return o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class\
    \ T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"\
    [\";for(const T& v:vc) o<<v<<\",\";o<<\"]\";return o;}\ntypedef long long ll;\n\
    int N,K;\nconst int MN = 500000;\nll a[MN],b[MN];\nll ans;\nint agmn(ll off){\n\
    \tpriority_queue<ll> usea;\n\tpriority_queue<ll,vector<ll>,greater<ll>> leftb;\n\
    \tll sum = 0;\n\tfor(int i=N-1;i>=0;i--){\n\t\tleftb.push(b[i]);\n\t\tll X = 0;\t\
    //dont use\n\t\tll Y = a[i]-off + leftb.top();\t//make pair\n\t\tll Z = usea.empty()\
    \ ? 1e10 : a[i]-usea.top();\t//reconnect\n\t\tif(X<=Y&&X<=Z){\n\t\t\tsum+=X;\n\
    \t\t}else if(Y<=X&&Y<=Z){\n\t\t\tsum+=Y;\n\t\t\tusea.push(a[i]);\n\t\t\tleftb.pop();\n\
    \t\t}else{\n\t\t\tsum+=Z;\n\t\t\tusea.pop();\n\t\t\tusea.push(a[i]);\n\t\t}\n\t\
    }\n\tint agmn = usea.size();\n\tif(agmn<=K){\n\t\tans = sum + off*agmn;\n\t}\n\
    \treturn agmn;\n}\nint main(){\n\tcin>>N>>K;\n\trep(i,N) cin>>a[i];\n\trep(i,N)\
    \ cin>>b[i];\n\tll ub = 2e9, lb = 0;\n\twhile(ub-lb>1){\n\t\tll m = (ub+lb)/2;\n\
    \t\tif(agmn(m)<=K) lb = m;\n\t\telse ub = m;\n\t}\n\tcout<<ans<<endl;\n}\n"
  code: "/*\nN\u500B\u306E\u5217\u3092K\u500B\u306E\u9023\u7D9A\u5217\u306B\u5206\u89E3\
    \u3059\u308B\u5834\u5408,\u611A\u76F4DP\u3060\u3068O(N^2K)\u306B\u306A\u308B\n\
    CHT\u3068\u304B\u3092\u4F7F\u3063\u3066\u8CB0\u3046DP\u306E\u9077\u79FB\u3092\
    O(NK)\u306B\u3067\u304D\u308B\n\n\u533A\u9593K\u500B\u306B\u5206\u5272\u3059\u308B\
    \u6642,\u300CK\u500B\u300D\u306E\u6761\u4EF6\u3092\u306A\u304F\u3057\u305F\u5F8C\
    , \u5404\u533A\u9593\u306E\u30B3\u30B9\u30C8\u306B + c \u3057\u3066\u89E3\u304F\
    \n\u6C42\u3081\u305F\u3044\u3082\u306E\u304CK\u306B\u95A2\u3057\u3066\u51F8\u306A\
    \u3089\u3001+c\u3092\u306B\u3076\u305F\u3093\u3057\u3066\u3061\u3087\u3046\u3069\
    K\u500B\u306B\u306A\u308B\u3068\u3053\u308D\u3092\u7B54\u3048\u3068\u3059\u308B\
    \n*/\n\n#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define show(x) cout\
    \ << #x << \" = \" << x << endl\n#define chmax(x,y) x=max(x,y)\nusing namespace\
    \ std;\ntemplate<class S,class T> ostream& operator<<(ostream& o,const pair<S,T>\
    \ &p){return o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class T> ostream&\
    \ operator<<(ostream& o,const vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"\
    [\";for(const T& v:vc) o<<v<<\",\";o<<\"]\";return o;}\ntypedef long long ll;\n\
    int N,K;\nconst int MN = 500000;\nll a[MN],b[MN];\nll ans;\nint agmn(ll off){\n\
    \tpriority_queue<ll> usea;\n\tpriority_queue<ll,vector<ll>,greater<ll>> leftb;\n\
    \tll sum = 0;\n\tfor(int i=N-1;i>=0;i--){\n\t\tleftb.push(b[i]);\n\t\tll X = 0;\t\
    //dont use\n\t\tll Y = a[i]-off + leftb.top();\t//make pair\n\t\tll Z = usea.empty()\
    \ ? 1e10 : a[i]-usea.top();\t//reconnect\n\t\tif(X<=Y&&X<=Z){\n\t\t\tsum+=X;\n\
    \t\t}else if(Y<=X&&Y<=Z){\n\t\t\tsum+=Y;\n\t\t\tusea.push(a[i]);\n\t\t\tleftb.pop();\n\
    \t\t}else{\n\t\t\tsum+=Z;\n\t\t\tusea.pop();\n\t\t\tusea.push(a[i]);\n\t\t}\n\t\
    }\n\tint agmn = usea.size();\n\tif(agmn<=K){\n\t\tans = sum + off*agmn;\n\t}\n\
    \treturn agmn;\n}\nint main(){\n\tcin>>N>>K;\n\trep(i,N) cin>>a[i];\n\trep(i,N)\
    \ cin>>b[i];\n\tll ub = 2e9, lb = 0;\n\twhile(ub-lb>1){\n\t\tll m = (ub+lb)/2;\n\
    \t\tif(agmn(m)<=K) lb = m;\n\t\telse ub = m;\n\t}\n\tcout<<ans<<endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: DP/Helvetic_O.cpp
  requiredBy: []
  timestamp: '2017-09-14 22:43:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/Helvetic_O.cpp
layout: document
redirect_from:
- /library/DP/Helvetic_O.cpp
- /library/DP/Helvetic_O.cpp.html
title: DP/Helvetic_O.cpp
---
