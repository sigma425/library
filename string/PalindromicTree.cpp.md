---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/PalindromicTree.cpp\"\n#include <bits/stdc++.h>\n\
    #define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<\"(\"\
    <<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class T> ostream& operator<<(ostream& o,const\
    \ vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"[\";for(const T& v:vc) o<<v<<\"\
    ,\";o<<\"]\";return o;}\nstruct PalindromicTree{\n\tstatic const int Z = 26;\n\
    \tstruct Node{\n\t\tvector<int> next;\n\t\tint len;\n\t\tint suflink;\n\t\tstring\
    \ s;\n\t\tNode(vector<int> next,int len,int suflink):next(next),len(len),suflink(suflink){}\n\
    \t\t// have string for debug\n\t\tNode(vector<int> next,int len,int suflink,string\
    \ s):next(next),len(len),suflink(suflink),s(s){}\n\t};\n\tint V;\n\tvector<Node>\
    \ ns;\n\n\tPalindromicTree(){}\n\tPalindromicTree(string s){\n\t\tV = 2;\t// ns[0]:\
    \ len -1    ns[1]: len 0\n\t\tint suf = 1;\n\t\tns.pb( Node(vector<int>(Z,-1),-1,0,\"\
    -1\") );\n\t\tns.pb( Node(vector<int>(Z,-1), 0,0,\"\") );\n\n\t\tint N = s.size();\n\
    \t\trep(i,N){\n\t\t\tshow(i);\n\t\t\tint c = s[i] - 'a';\n\t\t\twhile(true){\n\
    \t\t\t\tint len = ns[suf].len;\n\t\t\t\tif(i-1-len>=0 && s[i-1-len] == s[i]){\n\
    \t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t\tsuf = ns[suf].suflink;\n\t\t\t}\n\n\t\t\t\
    if(ns[suf].next[c] == -1){\n\t\t\t\tV++;\n\t\t\t\tns[suf].next[c] = V-1;\n\t\t\
    \t\t\n\t\t\t\tvector<int> nnext(Z,-1);\n\t\t\t\tint nlen = ns[suf].len+2;\n\t\t\
    \t\tint nsuflink = -1;\n\t\t\t\tshow(suf);\n\t\t\t\tshow(nlen);\n\t\t\t\tif(nlen\
    \ == 1){\n\t\t\t\t\tnsuflink = 1;\n\t\t\t\t}else{\n\t\t\t\t\twhile(true){\n\t\t\
    \t\t\t\tsuf = ns[suf].suflink;\n\t\t\t\t\t\tint len = ns[suf].len;\n\t\t\t\t\t\
    \tif(i-1-len>=0 && s[i-1-len] == s[i]){\n\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t}\n\
    \t\t\t\t\t}\n\t\t\t\t\tnsuflink = ns[suf].next[c];\n\t\t\t\t}\n\n\t\t\t\tNode\
    \ n(nnext,nlen,nsuflink,s.substr(i+1-nlen,nlen));\n\t\t\t\tns.pb(n);\n\t\t\t\t\
    suf = V-1;\n\t\t\t}else{\n\t\t\t\tsuf = ns[suf].next[c];\n\t\t\t}\n\t\t}\n\n\t\
    }\n};\nint main(){\n\twhile(true){\n\t\tstring s;\n\t\tcin>>s;\n\t\tPalindromicTree\
    \ PTree(s);\n\t\tint V = PTree.V;\n\t\tshow(V);\n\t\trep(i,V){\n\t\t\tshow(PTree.ns[i].s);\n\
    \t\t}\n\t}\n}\n"
  code: "#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define show(x) cout\
    \ << #x << \" = \" << x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y)\
    \ x=max(x,y)\nusing namespace std;\ntemplate<class S,class T> ostream& operator<<(ostream&\
    \ o,const pair<S,T> &p){return o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class\
    \ T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"\
    [\";for(const T& v:vc) o<<v<<\",\";o<<\"]\";return o;}\nstruct PalindromicTree{\n\
    \tstatic const int Z = 26;\n\tstruct Node{\n\t\tvector<int> next;\n\t\tint len;\n\
    \t\tint suflink;\n\t\tstring s;\n\t\tNode(vector<int> next,int len,int suflink):next(next),len(len),suflink(suflink){}\n\
    \t\t// have string for debug\n\t\tNode(vector<int> next,int len,int suflink,string\
    \ s):next(next),len(len),suflink(suflink),s(s){}\n\t};\n\tint V;\n\tvector<Node>\
    \ ns;\n\n\tPalindromicTree(){}\n\tPalindromicTree(string s){\n\t\tV = 2;\t// ns[0]:\
    \ len -1    ns[1]: len 0\n\t\tint suf = 1;\n\t\tns.pb( Node(vector<int>(Z,-1),-1,0,\"\
    -1\") );\n\t\tns.pb( Node(vector<int>(Z,-1), 0,0,\"\") );\n\n\t\tint N = s.size();\n\
    \t\trep(i,N){\n\t\t\tshow(i);\n\t\t\tint c = s[i] - 'a';\n\t\t\twhile(true){\n\
    \t\t\t\tint len = ns[suf].len;\n\t\t\t\tif(i-1-len>=0 && s[i-1-len] == s[i]){\n\
    \t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t\tsuf = ns[suf].suflink;\n\t\t\t}\n\n\t\t\t\
    if(ns[suf].next[c] == -1){\n\t\t\t\tV++;\n\t\t\t\tns[suf].next[c] = V-1;\n\t\t\
    \t\t\n\t\t\t\tvector<int> nnext(Z,-1);\n\t\t\t\tint nlen = ns[suf].len+2;\n\t\t\
    \t\tint nsuflink = -1;\n\t\t\t\tshow(suf);\n\t\t\t\tshow(nlen);\n\t\t\t\tif(nlen\
    \ == 1){\n\t\t\t\t\tnsuflink = 1;\n\t\t\t\t}else{\n\t\t\t\t\twhile(true){\n\t\t\
    \t\t\t\tsuf = ns[suf].suflink;\n\t\t\t\t\t\tint len = ns[suf].len;\n\t\t\t\t\t\
    \tif(i-1-len>=0 && s[i-1-len] == s[i]){\n\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t}\n\
    \t\t\t\t\t}\n\t\t\t\t\tnsuflink = ns[suf].next[c];\n\t\t\t\t}\n\n\t\t\t\tNode\
    \ n(nnext,nlen,nsuflink,s.substr(i+1-nlen,nlen));\n\t\t\t\tns.pb(n);\n\t\t\t\t\
    suf = V-1;\n\t\t\t}else{\n\t\t\t\tsuf = ns[suf].next[c];\n\t\t\t}\n\t\t}\n\n\t\
    }\n};\nint main(){\n\twhile(true){\n\t\tstring s;\n\t\tcin>>s;\n\t\tPalindromicTree\
    \ PTree(s);\n\t\tint V = PTree.V;\n\t\tshow(V);\n\t\trep(i,V){\n\t\t\tshow(PTree.ns[i].s);\n\
    \t\t}\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/PalindromicTree.cpp
  requiredBy: []
  timestamp: '2018-09-18 03:14:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/PalindromicTree.cpp
layout: document
redirect_from:
- /library/string/PalindromicTree.cpp
- /library/string/PalindromicTree.cpp.html
title: string/PalindromicTree.cpp
---
