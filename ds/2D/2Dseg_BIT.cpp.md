---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://sigma425.hatenablog.com/entry/2016/03/13/180106
  bundledCode: "#line 1 \"ds/2D/2Dseg_BIT.cpp\"\n/*\r\n\tpoint add range sum in 2D\
    \ (N*N grid)\r\n\t!!!!!\u8FFD\u52A0\u3084\u524A\u9664\u3055\u308C\u308B\u70B9\u306E\
    \u96C6\u5408\u304C\u5148\u306B\u308F\u304B\u3063\u3066\u3044\u308B\u5834\u5408\
    !!!!! \u3057\u304B\u4F7F\u3048\u306A\u3044 \u70B9\u66F4\u65B0\u306F\u3042\u3063\
    \u3066\u3082\u3044\u3044 \u70B9\u66F4\u65B0\u304C\u306A\u3044\u306A\u3089 time\
    \ sweep \u3067 1D \u3067\u3044\u3051\u308B\r\n\t\u5225\u306B\u70B9\u96C6\u5408\
    \u304C permutation \u307F\u305F\u3044\u306B\u306A\u3063\u3066\u308B\u5FC5\u8981\
    \u3068\u304B\u306F\u306A\u3044\r\n\thttp://sigma425.hatenablog.com/entry/2016/03/13/180106\
    \ \u306EBIT\u306E\u3068\u3053\u306B\u66F8\u3044\u3066\u3042\u308B\u3084\u3064\r\
    \n\t\u5148\u306B\u5168\u90E8\u3042\u308B\u3068\u3057\u3066\u304B\u3089\u30DE\u30FC\
    \u30B8\u30BD\u30FC\u30C8\u3063\u307D\u3044\u5217\u3092\u6301\u3064segtree\u3092\
    \u4F5C\u3063\u3066\u304A\u3044\u3066\u3001\u5404\u30CE\u30FC\u30C9\u304CBIT\u3092\
    \u6301\u3064\r\n\tO(log^2N) per query \u3067 splay tree \u3092segtree\u306B\u8F09\
    \u305B\u3066\u308B\u306E\u3068\u540C\u3058\u8A08\u7B97\u91CF\u3060\u3051\u3069\
    \u3001\u5B9A\u6570\u500D\u304C\u304B\u306A\u308A\u3044\u3044\u3068\u601D\u3046\
    \ 4\u500D\u304F\u3089\u3044\u3060\u3063\u305F N = 10^5 \u3067 0.5sec \u304F\u3089\
    \u3044\r\n\r\n\t\u3057\u304B\u3082\u70B9\u306B\u91CD\u307F\u3064\u3051\u308B\u306E\
    \u3082\u7C21\u5358!\r\n\r\n\tusage:\r\n\t\tsegtree seg( size of grid, candidate\
    \ points );\r\n\t\tint count(x,y) //return sum of [0,x) * [0,y)\r\n\t\tvoid add(int\
    \ x,int y)\r\n\r\n\tverified at atcoder/snuke/J (Drink Bar)\r\n\r\n\t\u3044\u3058\
    \u3063\u305F\u3001\u3042\u3068\u3067verify\u3059\u308B\r\n*/\r\n\r\ntemplate<class\
    \ D>\r\nstruct BIT{\r\n\tint N;\r\n\tvector<D> bit;\r\n\r\n\tBIT(int n){\t\t//n\u306F\
    \u533A\u9593\u5E45!!!\r\n\t\tN=n;\r\n\t\tbit.assign(n+1,0);\r\n\t}\r\n\tBIT(){}\r\
    \n\r\n\tD sum(int i){\t\t//i\u500B\u306E\u548Ca[0]+..a[i-1]\r\n\t\tD s=0;\r\n\t\
    \twhile(i>0){\r\n\t\t\ts+=bit[i];\r\n\t\t\ti-=(i&-i);\r\n\t\t}\r\n\t\treturn s;\r\
    \n\t}\r\n\tvoid add(int i,D x){\t//a[i]+=x (0-indexed)\r\n\t\ti++;\r\n\t\twhile(i<=N){\r\
    \n\t\t\tbit[i]+=x;\r\n\t\t\ti+=(i&-i);\r\n\t\t}\r\n\t}\r\n};\r\n\r\ntemplate<class\
    \ D>\r\nstruct segtree2D{\r\n\tint N;\t//[0,N) * [0,N)\r\n\tvector<BIT<D>> bit;\r\
    \n\tvector<vector<int>> vals;\r\n\r\n\t//build with candidate points\r\n\tsegtree2D(int\
    \ n, vector<pair<int,int>> ps){\r\n\t\tint p2=1;\r\n\t\twhile(p2<n) p2*=2;\r\n\
    \t\tN=p2;\r\n\t\tbit.resize(N*2);\r\n\t\tvals.resize(N*2);\r\n\r\n\t\tint K =\
    \ ps.size();\r\n\r\n\t\trep(i,K){\r\n\t\t\tint x = ps[i].fs, y = ps[i].sc;\r\n\
    \t\t\tvals[x+N].pb(y);\r\n\t\t}\r\n\t\tfor(int i=N;i<2*N;i++){\r\n\t\t\tsort(all(vals[i]));\r\
    \n\t\t\tvals[i].erase(unique(vals[i].begin(),vals[i].end()),vals[i].end());\r\n\
    \t\t}\r\n\t\tfor(int i=N-1;i>0;i--){\r\n\t\t\tvals[i].resize(vals[i*2].size()+vals[i*2+1].size());\r\
    \n\t\t\tmerge(all(vals[i*2]),all(vals[i*2+1]),vals[i].begin());\r\n\t\t\tvals[i].erase(unique(vals[i].begin(),vals[i].end()),vals[i].end());\r\
    \n\t\t}\r\n\t\tfor(int i=1;i<2*N;i++){\r\n\t\t\tbit[i] = BIT(vals[i].size());\r\
    \n\t\t}\r\n\t}\r\n\r\n\tvoid add(int x,int y,D v){\t\t\t//add P(x,y)\r\n\t\tx+=N;\r\
    \n\t\twhile(x){\r\n\t\t\tint yid = lower_bound(all(vals[x]),y) - vals[x].begin();\r\
    \n\t\t\tbit[x].add(yid,v);\r\n\t\t\tx/=2;\r\n\t\t}\r\n\t}\r\n\tD count(int a,int\
    \ b,int ya,int yb,int l,int r,int k){\t\t//[a,b) * [ya,yb)\r\n\t\tif(b<=l||r<=a)\
    \ return 0;\r\n\t\tif(a<=l&&r<=b){\r\n\t\t\tint yaid = lower_bound(all(vals[k]),ya)\
    \ - vals[k].begin();\r\n\t\t\tint ybid = lower_bound(all(vals[k]),yb) - vals[k].begin();\r\
    \n\t\t\treturn bit[k].sum(ybid) - bit[k].sum(yaid);\r\n\t\t}\r\n\t\treturn count(a,b,ya,yb,l,(l+r)/2,k*2)+count(a,b,ya,yb,(l+r)/2,r,k*2+1);\r\
    \n\t}\r\n\tD count_00(int b,int yb,int l,int r,int k){\t\t//[0,b) * [0,yb)\r\n\
    \t\tif(b<=l||r<=0) return 0;\r\n\t\tif(0<=l&&r<=b){\r\n\t\t\tint ybid = lower_bound(all(vals[k]),yb)\
    \ - vals[k].begin();\r\n\t\t\treturn bit[k].sum(ybid);\r\n\t\t}\r\n\t\treturn\
    \ count_00(b,yb,l,(l+r)/2,k*2)+count_00(b,yb,(l+r)/2,r,k*2+1);\r\n\t}\r\n\r\n\t\
    D count(int x,int y){\r\n//\t\tprintf(\"count [0,%d)*[0,%d)\\n\",x,y);\r\n\t\t\
    return count_00(x,y,0,N,1);\r\n\t}\r\n\tD count(int xa,int xb,int ya,int yb){\r\
    \n//\t\tprintf(\"count [%d,%d)*[%d,%d)\\n\",xa,xb,ya,yb);\r\n\t\treturn count(xa,xb,ya,yb,0,N,1);\r\
    \n\t}\r\n};\n"
  code: "/*\r\n\tpoint add range sum in 2D (N*N grid)\r\n\t!!!!!\u8FFD\u52A0\u3084\
    \u524A\u9664\u3055\u308C\u308B\u70B9\u306E\u96C6\u5408\u304C\u5148\u306B\u308F\
    \u304B\u3063\u3066\u3044\u308B\u5834\u5408!!!!! \u3057\u304B\u4F7F\u3048\u306A\
    \u3044 \u70B9\u66F4\u65B0\u306F\u3042\u3063\u3066\u3082\u3044\u3044 \u70B9\u66F4\
    \u65B0\u304C\u306A\u3044\u306A\u3089 time sweep \u3067 1D \u3067\u3044\u3051\u308B\
    \r\n\t\u5225\u306B\u70B9\u96C6\u5408\u304C permutation \u307F\u305F\u3044\u306B\
    \u306A\u3063\u3066\u308B\u5FC5\u8981\u3068\u304B\u306F\u306A\u3044\r\n\thttp://sigma425.hatenablog.com/entry/2016/03/13/180106\
    \ \u306EBIT\u306E\u3068\u3053\u306B\u66F8\u3044\u3066\u3042\u308B\u3084\u3064\r\
    \n\t\u5148\u306B\u5168\u90E8\u3042\u308B\u3068\u3057\u3066\u304B\u3089\u30DE\u30FC\
    \u30B8\u30BD\u30FC\u30C8\u3063\u307D\u3044\u5217\u3092\u6301\u3064segtree\u3092\
    \u4F5C\u3063\u3066\u304A\u3044\u3066\u3001\u5404\u30CE\u30FC\u30C9\u304CBIT\u3092\
    \u6301\u3064\r\n\tO(log^2N) per query \u3067 splay tree \u3092segtree\u306B\u8F09\
    \u305B\u3066\u308B\u306E\u3068\u540C\u3058\u8A08\u7B97\u91CF\u3060\u3051\u3069\
    \u3001\u5B9A\u6570\u500D\u304C\u304B\u306A\u308A\u3044\u3044\u3068\u601D\u3046\
    \ 4\u500D\u304F\u3089\u3044\u3060\u3063\u305F N = 10^5 \u3067 0.5sec \u304F\u3089\
    \u3044\r\n\r\n\t\u3057\u304B\u3082\u70B9\u306B\u91CD\u307F\u3064\u3051\u308B\u306E\
    \u3082\u7C21\u5358!\r\n\r\n\tusage:\r\n\t\tsegtree seg( size of grid, candidate\
    \ points );\r\n\t\tint count(x,y) //return sum of [0,x) * [0,y)\r\n\t\tvoid add(int\
    \ x,int y)\r\n\r\n\tverified at atcoder/snuke/J (Drink Bar)\r\n\r\n\t\u3044\u3058\
    \u3063\u305F\u3001\u3042\u3068\u3067verify\u3059\u308B\r\n*/\r\n\r\ntemplate<class\
    \ D>\r\nstruct BIT{\r\n\tint N;\r\n\tvector<D> bit;\r\n\r\n\tBIT(int n){\t\t//n\u306F\
    \u533A\u9593\u5E45!!!\r\n\t\tN=n;\r\n\t\tbit.assign(n+1,0);\r\n\t}\r\n\tBIT(){}\r\
    \n\r\n\tD sum(int i){\t\t//i\u500B\u306E\u548Ca[0]+..a[i-1]\r\n\t\tD s=0;\r\n\t\
    \twhile(i>0){\r\n\t\t\ts+=bit[i];\r\n\t\t\ti-=(i&-i);\r\n\t\t}\r\n\t\treturn s;\r\
    \n\t}\r\n\tvoid add(int i,D x){\t//a[i]+=x (0-indexed)\r\n\t\ti++;\r\n\t\twhile(i<=N){\r\
    \n\t\t\tbit[i]+=x;\r\n\t\t\ti+=(i&-i);\r\n\t\t}\r\n\t}\r\n};\r\n\r\ntemplate<class\
    \ D>\r\nstruct segtree2D{\r\n\tint N;\t//[0,N) * [0,N)\r\n\tvector<BIT<D>> bit;\r\
    \n\tvector<vector<int>> vals;\r\n\r\n\t//build with candidate points\r\n\tsegtree2D(int\
    \ n, vector<pair<int,int>> ps){\r\n\t\tint p2=1;\r\n\t\twhile(p2<n) p2*=2;\r\n\
    \t\tN=p2;\r\n\t\tbit.resize(N*2);\r\n\t\tvals.resize(N*2);\r\n\r\n\t\tint K =\
    \ ps.size();\r\n\r\n\t\trep(i,K){\r\n\t\t\tint x = ps[i].fs, y = ps[i].sc;\r\n\
    \t\t\tvals[x+N].pb(y);\r\n\t\t}\r\n\t\tfor(int i=N;i<2*N;i++){\r\n\t\t\tsort(all(vals[i]));\r\
    \n\t\t\tvals[i].erase(unique(vals[i].begin(),vals[i].end()),vals[i].end());\r\n\
    \t\t}\r\n\t\tfor(int i=N-1;i>0;i--){\r\n\t\t\tvals[i].resize(vals[i*2].size()+vals[i*2+1].size());\r\
    \n\t\t\tmerge(all(vals[i*2]),all(vals[i*2+1]),vals[i].begin());\r\n\t\t\tvals[i].erase(unique(vals[i].begin(),vals[i].end()),vals[i].end());\r\
    \n\t\t}\r\n\t\tfor(int i=1;i<2*N;i++){\r\n\t\t\tbit[i] = BIT(vals[i].size());\r\
    \n\t\t}\r\n\t}\r\n\r\n\tvoid add(int x,int y,D v){\t\t\t//add P(x,y)\r\n\t\tx+=N;\r\
    \n\t\twhile(x){\r\n\t\t\tint yid = lower_bound(all(vals[x]),y) - vals[x].begin();\r\
    \n\t\t\tbit[x].add(yid,v);\r\n\t\t\tx/=2;\r\n\t\t}\r\n\t}\r\n\tD count(int a,int\
    \ b,int ya,int yb,int l,int r,int k){\t\t//[a,b) * [ya,yb)\r\n\t\tif(b<=l||r<=a)\
    \ return 0;\r\n\t\tif(a<=l&&r<=b){\r\n\t\t\tint yaid = lower_bound(all(vals[k]),ya)\
    \ - vals[k].begin();\r\n\t\t\tint ybid = lower_bound(all(vals[k]),yb) - vals[k].begin();\r\
    \n\t\t\treturn bit[k].sum(ybid) - bit[k].sum(yaid);\r\n\t\t}\r\n\t\treturn count(a,b,ya,yb,l,(l+r)/2,k*2)+count(a,b,ya,yb,(l+r)/2,r,k*2+1);\r\
    \n\t}\r\n\tD count_00(int b,int yb,int l,int r,int k){\t\t//[0,b) * [0,yb)\r\n\
    \t\tif(b<=l||r<=0) return 0;\r\n\t\tif(0<=l&&r<=b){\r\n\t\t\tint ybid = lower_bound(all(vals[k]),yb)\
    \ - vals[k].begin();\r\n\t\t\treturn bit[k].sum(ybid);\r\n\t\t}\r\n\t\treturn\
    \ count_00(b,yb,l,(l+r)/2,k*2)+count_00(b,yb,(l+r)/2,r,k*2+1);\r\n\t}\r\n\r\n\t\
    D count(int x,int y){\r\n//\t\tprintf(\"count [0,%d)*[0,%d)\\n\",x,y);\r\n\t\t\
    return count_00(x,y,0,N,1);\r\n\t}\r\n\tD count(int xa,int xb,int ya,int yb){\r\
    \n//\t\tprintf(\"count [%d,%d)*[%d,%d)\\n\",xa,xb,ya,yb);\r\n\t\treturn count(xa,xb,ya,yb,0,N,1);\r\
    \n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/2D/2Dseg_BIT.cpp
  requiredBy: []
  timestamp: '2024-01-03 19:12:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/2D/2Dseg_BIT.cpp
layout: document
redirect_from:
- /library/ds/2D/2Dseg_BIT.cpp
- /library/ds/2D/2Dseg_BIT.cpp.html
title: ds/2D/2Dseg_BIT.cpp
---
