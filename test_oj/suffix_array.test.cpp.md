---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/suffix_array.hpp
    title: string/suffix_array.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"test_oj/suffix_array.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\
    \n\n#line 2 \"template.hpp\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\nusing ll = long long;\r\nusing uint = unsigned int;\r\nusing ull = unsigned\
    \ long long;\r\n#define rep(i,n) for(int i=0;i<int(n);i++)\r\n#define rep1(i,n)\
    \ for(int i=1;i<=int(n);i++)\r\n#define per(i,n) for(int i=int(n)-1;i>=0;i--)\r\
    \n#define per1(i,n) for(int i=int(n);i>0;i--)\r\n#define all(c) c.begin(),c.end()\r\
    \n#define si(x) int(x.size())\r\n#define pb push_back\r\n#define eb emplace_back\r\
    \n#define fs first\r\n#define sc second\r\ntemplate<class T> using V = vector<T>;\r\
    \ntemplate<class T> using VV = vector<vector<T>>;\r\ntemplate<class T,class U>\
    \ bool chmax(T& x, U y){\r\n\tif(x<y){ x=y; return true; }\r\n\treturn false;\r\
    \n}\r\ntemplate<class T,class U> bool chmin(T& x, U y){\r\n\tif(y<x){ x=y; return\
    \ true; }\r\n\treturn false;\r\n}\r\ntemplate<class T> void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}\r\
    \ntemplate<class T> int lwb(const V<T>& v, const T& a){return lower_bound(all(v),a)\
    \ - v.begin();}\r\ntemplate<class T>\r\nV<T> Vec(size_t a) {\r\n    return V<T>(a);\r\
    \n}\r\ntemplate<class T, class... Ts>\r\nauto Vec(size_t a, Ts... ts) {\r\n  return\
    \ V<decltype(Vec<T>(ts...))>(a, Vec<T>(ts...));\r\n}\r\ntemplate<class S,class\
    \ T> ostream& operator<<(ostream& o,const pair<S,T> &p){\r\n\treturn o<<\"(\"\
    <<p.fs<<\",\"<<p.sc<<\")\";\r\n}\r\ntemplate<class T> ostream& operator<<(ostream&\
    \ o,const vector<T> &vc){\r\n\to<<\"{\";\r\n\tfor(const T& v:vc) o<<v<<\",\";\r\
    \n\to<<\"}\";\r\n\treturn o;\r\n}\r\nconstexpr ll TEN(int n) { return (n == 0)\
    \ ? 1 : 10 * TEN(n-1); }\r\n\r\n#ifdef LOCAL\r\n#define show(x) cerr << \"LINE\"\
    \ << __LINE__ << \" : \" << #x << \" = \" << (x) << endl\r\nvoid dmpr(ostream&\
    \ os){os<<endl;}\r\ntemplate<class T,class... Args>\r\nvoid dmpr(ostream&os,const\
    \ T&t,const Args&... args){\r\n\tos<<t<<\" ~ \";\r\n\tdmpr(os,args...);\r\n}\r\
    \n#define shows(...) cerr << \"LINE\" << __LINE__ << \" : \";dmpr(cerr,##__VA_ARGS__)\r\
    \n#define dump(x) cerr << \"LINE\" << __LINE__ << \" : \" << #x << \" = {\"; \
    \ \\\r\n\tfor(auto v: x) cerr << v << \",\"; cerr << \"}\" << endl;\r\n#else\r\
    \n#define show(x) void(0)\r\n#define dump(x) void(0)\r\n#define shows(...) void(0)\r\
    \n#endif\r\n\r\ntemplate<class D> D divFloor(D a, D b){\r\n\treturn a / b - (((a\
    \ ^ b) < 0 && a % b != 0) ? 1 : 0);\r\n}\r\ntemplate<class D> D divCeil(D a, D\
    \ b) {\r\n\treturn a / b + (((a ^ b) > 0 && a % b != 0) ? 1 : 0);\r\n}\r\n#line\
    \ 1 \"string/suffix_array.hpp\"\n/*\n\tSA-IS + LCP\n\n\tSuffixArray SA(V<int,ll>)\
    \ \u3082\u3057\u304F\u306F SA(string)\n\t\u3067SA.sa,isa,lcp\u306B\u5165\u308B\
    \n\n\t[0,N]   sa[i] = i\u756A\u76EE\u306B\u5C0F\u3055\u3044\u3082\u306E\u306F\
    \ s[ sa[i],N ) \u306A\u306E\u3067 sa[0] = N\n\t[0,N]   isa[i] = s[i,N) \u304C\u4F55\
    \u756A\u76EE\u306B\u3044\u308B\u304B\n\t[0,N-1] lcp[i] = s[ sa[i],N ) \u3068 s[\
    \ sa[i+1],N ) \u306Elcp lcp[0] = 0\n\t\u4EFB\u610F\u306Eprefix\u540C\u58EB\u306E\
    lcp\u304Csegtree_min\u3067\u6C42\u307E\u308B\n\t\u3042\u308Bsubstring\u304C\u4F55\
    \u56DE\u51FA\u3066\u304F\u308B\u304B? \u3068\u304B\n\n\ts = abcabac\n\n\t\t(eps)\n\
    \t\tabac\n\t\tabcabac\n\t\tac\n\t\tbac\n\t\tbcabac\n\t\tc\n\t\tcabac\n*/\n\nstruct\
    \ SuffixArray{\n\tV<int> sa;\n\tV<int> isa;\n\tV<int> lcp;\n\n\ttemplate<class\
    \ T>\n\tSuffixArray(const vector<T>& s){\t//int,ll\n\t\tint N = s.size();\n\t\t\
    T s_arr[N];\n\t\trep(i,N) s_arr[i] = s[i];\n\t\tint sa_arr[N+1];\n\t\tint lcp_arr[N];\n\
    \t\t{\t//zaatsu\n\t\t\tV<T> vs = s;\n\t\t\tsort(all(vs));\n\t\t\tvs.erase(unique(all(vs)),vs.end());\n\
    \t\t\trep(i,N) s_arr[i] = lower_bound(all(vs),s[i]) - vs.begin();\n\t\t}\n\t\t\
    int K = N;\n\t\tSA(N,s_arr,sa_arr,K);\n\t\tLCP(N,s_arr,sa_arr,lcp_arr);\n\t\t\
    sa = V<int>(sa_arr,sa_arr+(N+1));\n\t\tisa.resize(N+1);\n\t\trep(i,N+1) isa[sa[i]]\
    \ = i;\n\t\tlcp = V<int>(lcp_arr,lcp_arr+N);\n\t}\n\tSuffixArray(const string&\
    \ s){\n\t\tint N = s.size();\n\t\tchar s_arr[N];\n\t\trep(i,N) s_arr[i] = s[i];\n\
    \t\tint sa_arr[N+1];\n\t\tint lcp_arr[N];\n\t\tSA(N,s_arr,sa_arr,256);\n\t\tLCP(N,s_arr,sa_arr,lcp_arr);\n\
    \t\tsa = V<int>(sa_arr,sa_arr+(N+1));\n\t\tisa.resize(N+1);\n\t\trep(i,N+1) isa[sa[i]]\
    \ = i;\n\t\tlcp = V<int>(lcp_arr,lcp_arr+N);\n\t}\n\n\tprivate:\n\n\ttemplate<class\
    \ T>\n\tvoid induce(int N,const T s[],bool is[],int sa[],int lbase[],int K){\n\
    \t\tint it[K+1];\n\t\tcopy_n(lbase,K+1,it);\n\t\trep(i,N+1){\n\t\t\tif(sa[i]>=1&&!is[sa[i]-1]){\n\
    \t\t\t\tint c=s[sa[i]-1];\n\t\t\t\tsa[it[c]++]=sa[i]-1;\n\t\t\t}\n\t\t}\n\t\t\
    copy_n(lbase,K+1,it);\n\t\tfor(int i=N;i>0;i--){\n\t\t\tif(sa[i]>=1&&is[sa[i]-1]){\n\
    \t\t\t\tint c=s[sa[i]-1];\n\t\t\t\tsa[--it[c+1]]=sa[i]-1;\n\t\t\t}\n\t\t}\n\t\
    }\n\ttemplate<class T>\n\tvoid SA(int N,const T s[],int sa[],int K){\n\t\tbool\
    \ is[N+1];\t\t//stype?\n\t\tint lcnt[K+1]={},scnt[K+1]={};\n\t\tis[N]=1;\n\t\t\
    for(int i=N-1;i>=0;i--){\n\t\t\tif(i==N-1||s[i]>s[i+1]) is[i]=0;\n\t\t\telse if(s[i]<s[i+1])\
    \ is[i]=1;\n\t\t\telse is[i]=is[i+1];\n\t\t\tif(!is[i]) lcnt[(int)s[i]]++;\n\t\
    \t\telse scnt[(int)s[i]]++;\n\t\t}\n\t\tvector<int> v;\t\t//LMSs\n\t\tint lms[N+1];\n\
    \t\tfill_n(lms,N+1,-1);\n\t\tint c=0;\n\t\trep1(i,N-1){\n\t\t\tif(!is[i-1]&&is[i]){\n\
    \t\t\t\tlms[i]=c++;\n\t\t\t\tv.pb(i);\n\t\t\t}\n\t\t}\n\t\tint lbase[K+1],sbase[K+1];\n\
    \t\tlbase[0]=1,sbase[0]=1+lcnt[0];\n\t\trep1(i,K){\n\t\t\tlbase[i]=sbase[i-1]+scnt[i-1];\n\
    \t\t\tsbase[i]=lbase[i]+lcnt[i];\n\t\t}\n\t\tif(!v.empty()){\n\t\t\tvector<int>\
    \ v2=v;\n\t\t\tint it[K+1];\t\t\t//iterate\n\t\t\tcopy_n(sbase,K+1,it);\n\t\t\t\
    fill_n(sa,N+1,-1);\n\t\t\tsa[0]=N;\n\t\t\trep(i,v.size()){\n\t\t\t\tint c=s[v[i]];\n\
    \t\t\t\tsa[it[c]++]=v[i];\n\t\t\t}\n\t\t\tinduce(N,s,is,sa,lbase,K);\n\t\t\tint\
    \ c=0;\n\t\t\trep1(i,N) if(lms[sa[i]]>=0) v[c++]=sa[i];\n\t\t\tint s2[v.size()],sa2[v.size()+1];\n\
    \t\t\tc=0;\n\t\t\ts2[lms[v[0]]]=0;\n\t\t\tfor(int i=1;i<(int)v.size();i++){\n\t\
    \t\t\tint l=v[i-1],r=v[i];\n\t\t\t\twhile(true){\n\t\t\t\t\tif(l == N || r ==\
    \ N || s[l] != s[r]){\n\t\t\t\t\t\tc++;\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\
    \t\t\tl++,r++;\n\t\t\t\t\tif(lms[l]>=0||lms[r]>=0){\n\t\t\t\t\t\tif(lms[l]<0||lms[r]<0)\
    \ c++;\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\ts2[lms[v[i]]]=c;\n\
    \t\t\t}\n\t\t\tSA(v.size(),s2,sa2,c);\n\t\t\trep1(i,v.size()) v[i-1]=v2[sa2[i]];\n\
    \t\t}\n\t\tint it[K+1];\n\t\tcopy_n(sbase,K+1,it);\n\t\tfill_n(sa,N+1,-1);\n\t\
    \tsa[0]=N;\n\t\trep(i,v.size()){\n\t\t\tint c=s[v[i]];\n\t\t\tsa[it[c]++]=v[i];\n\
    \t\t}\n\t\tinduce(N,s,is,sa,lbase,K);\n\t}\n\ttemplate<class T>\n\tvoid LCP(int\
    \ N,const T s[],const int sa[],int lcp[]){\n\t\tint isa[N+1];\n\t\trep(i,N+1)\
    \ isa[sa[i]]=i;\n\t\tint h=0;\n\t\trep(i,N){\n\t\t\tint j=sa[isa[i]-1];\n\t\t\t\
    if(h>0) h--;\n\t\t\tfor(;j+h<N&&i+h<N;h++){\n\t\t\t\tif(s[j+h]!=s[i+h]) break;\n\
    \t\t\t}\n\t\t\tlcp[isa[i]-1]=h;\n\t\t}\n\t}\n};\n#line 5 \"test_oj/suffix_array.test.cpp\"\
    \n\nint main(){\n\tcin.tie(0);\n\tios::sync_with_stdio(false);\t\t//DON'T USE\
    \ scanf/printf/puts !!\n\tcout << fixed << setprecision(20);\n\t\n    string s;\n\
    \    cin >> s;\n    int n = s.size();\n    SuffixArray sa(s);\n\n    for (int\
    \ i = 1; i <= n; i++) {\n        cout << sa.sa[i] << \" \";\n    }\n    cout <<\
    \ endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#include\
    \ \"template.hpp\"\n#include \"string/suffix_array.hpp\"\n\nint main(){\n\tcin.tie(0);\n\
    \tios::sync_with_stdio(false);\t\t//DON'T USE scanf/printf/puts !!\n\tcout <<\
    \ fixed << setprecision(20);\n\t\n    string s;\n    cin >> s;\n    int n = s.size();\n\
    \    SuffixArray sa(s);\n\n    for (int i = 1; i <= n; i++) {\n        cout <<\
    \ sa.sa[i] << \" \";\n    }\n    cout << endl;\n}\n"
  dependsOn:
  - template.hpp
  - string/suffix_array.hpp
  isVerificationFile: true
  path: test_oj/suffix_array.test.cpp
  requiredBy: []
  timestamp: '2024-09-14 08:42:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_oj/suffix_array.test.cpp
layout: document
redirect_from:
- /verify/test_oj/suffix_array.test.cpp
- /verify/test_oj/suffix_array.test.cpp.html
title: test_oj/suffix_array.test.cpp
---
