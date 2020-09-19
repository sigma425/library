---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_oj/sa-is.test.cpp
    title: test_oj/sa-is.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"string/sa-is.cpp\"\n/*\n\tSA-IS + LCP\n\n\tSuffixArray SA(V<int,ll>)\
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
    \t\t\tint l=v[i-1],r=v[i];\n\t\t\t\twhile(true){\n\t\t\t\t\tif(s[l]!=s[r]){\n\t\
    \t\t\t\t\tc++;\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\t\tl++,r++;\n\t\t\t\t\t\
    if(lms[l]>=0||lms[r]>=0){\n\t\t\t\t\t\tif(lms[l]<0||lms[r]<0) c++;\n\t\t\t\t\t\
    \tbreak;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\ts2[lms[v[i]]]=c;\n\t\t\t}\n\t\t\tSA(v.size(),s2,sa2,c);\n\
    \t\t\trep1(i,v.size()) v[i-1]=v2[sa2[i]];\n\t\t}\n\t\tint it[K+1];\n\t\tcopy_n(sbase,K+1,it);\n\
    \t\tfill_n(sa,N+1,-1);\n\t\tsa[0]=N;\n\t\trep(i,v.size()){\n\t\t\tint c=s[v[i]];\n\
    \t\t\tsa[it[c]++]=v[i];\n\t\t}\n\t\tinduce(N,s,is,sa,lbase,K);\n\t}\n\ttemplate<class\
    \ T>\n\tvoid LCP(int N,const T s[],const int sa[],int lcp[]){\n\t\tint isa[N+1];\n\
    \t\trep(i,N+1) isa[sa[i]]=i;\n\t\tint h=0;\n\t\trep(i,N){\n\t\t\tint j=sa[isa[i]-1];\n\
    \t\t\tif(h>0) h--;\n\t\t\tfor(;j+h<N&&i+h<N;h++){\n\t\t\t\tif(s[j+h]!=s[i+h])\
    \ break;\n\t\t\t}\n\t\t\tlcp[isa[i]-1]=h;\n\t\t}\n\t}\n};\n"
  code: "/*\n\tSA-IS + LCP\n\n\tSuffixArray SA(V<int,ll>) \u3082\u3057\u304F\u306F\
    \ SA(string)\n\t\u3067SA.sa,isa,lcp\u306B\u5165\u308B\n\n\t[0,N]   sa[i] = i\u756A\
    \u76EE\u306B\u5C0F\u3055\u3044\u3082\u306E\u306F s[ sa[i],N ) \u306A\u306E\u3067\
    \ sa[0] = N\n\t[0,N]   isa[i] = s[i,N) \u304C\u4F55\u756A\u76EE\u306B\u3044\u308B\
    \u304B\n\t[0,N-1] lcp[i] = s[ sa[i],N ) \u3068 s[ sa[i+1],N ) \u306Elcp lcp[0]\
    \ = 0\n\t\u4EFB\u610F\u306Eprefix\u540C\u58EB\u306Elcp\u304Csegtree_min\u3067\u6C42\
    \u307E\u308B\n\t\u3042\u308Bsubstring\u304C\u4F55\u56DE\u51FA\u3066\u304F\u308B\
    \u304B? \u3068\u304B\n\n\ts = abcabac\n\n\t\t(eps)\n\t\tabac\n\t\tabcabac\n\t\t\
    ac\n\t\tbac\n\t\tbcabac\n\t\tc\n\t\tcabac\n*/\n\nstruct SuffixArray{\n\tV<int>\
    \ sa;\n\tV<int> isa;\n\tV<int> lcp;\n\n\ttemplate<class T>\n\tSuffixArray(const\
    \ vector<T>& s){\t//int,ll\n\t\tint N = s.size();\n\t\tT s_arr[N];\n\t\trep(i,N)\
    \ s_arr[i] = s[i];\n\t\tint sa_arr[N+1];\n\t\tint lcp_arr[N];\n\t\t{\t//zaatsu\n\
    \t\t\tV<T> vs = s;\n\t\t\tsort(all(vs));\n\t\t\tvs.erase(unique(all(vs)),vs.end());\n\
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
    \t\t\tint l=v[i-1],r=v[i];\n\t\t\t\twhile(true){\n\t\t\t\t\tif(s[l]!=s[r]){\n\t\
    \t\t\t\t\tc++;\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\t\tl++,r++;\n\t\t\t\t\t\
    if(lms[l]>=0||lms[r]>=0){\n\t\t\t\t\t\tif(lms[l]<0||lms[r]<0) c++;\n\t\t\t\t\t\
    \tbreak;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\ts2[lms[v[i]]]=c;\n\t\t\t}\n\t\t\tSA(v.size(),s2,sa2,c);\n\
    \t\t\trep1(i,v.size()) v[i-1]=v2[sa2[i]];\n\t\t}\n\t\tint it[K+1];\n\t\tcopy_n(sbase,K+1,it);\n\
    \t\tfill_n(sa,N+1,-1);\n\t\tsa[0]=N;\n\t\trep(i,v.size()){\n\t\t\tint c=s[v[i]];\n\
    \t\t\tsa[it[c]++]=v[i];\n\t\t}\n\t\tinduce(N,s,is,sa,lbase,K);\n\t}\n\ttemplate<class\
    \ T>\n\tvoid LCP(int N,const T s[],const int sa[],int lcp[]){\n\t\tint isa[N+1];\n\
    \t\trep(i,N+1) isa[sa[i]]=i;\n\t\tint h=0;\n\t\trep(i,N){\n\t\t\tint j=sa[isa[i]-1];\n\
    \t\t\tif(h>0) h--;\n\t\t\tfor(;j+h<N&&i+h<N;h++){\n\t\t\t\tif(s[j+h]!=s[i+h])\
    \ break;\n\t\t\t}\n\t\t\tlcp[isa[i]-1]=h;\n\t\t}\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/sa-is.cpp
  requiredBy: []
  timestamp: '2019-01-11 10:51:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_oj/sa-is.test.cpp
documentation_of: string/sa-is.cpp
layout: document
redirect_from:
- /library/string/sa-is.cpp
- /library/string/sa-is.cpp.html
title: string/sa-is.cpp
---
