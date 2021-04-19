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
  bundledCode: "#line 1 \"data structure/mo.cpp\"\n/*\r\n\tmo-algorithm\r\n\t\u533A\
    \u9593\u30AF\u30A8\u30EA\u304C\u3044\u3063\u3071\u3044\u6765\u308B\u3068\u304D\
    \u306B\u3001\u533A\u9593\u306E1\u3072\u304D\u306E\u3070\u3057\u30681\u3051\u305A\
    \u308A\u304C\u901F\u304F\u3067\u304D\u308B\u306A\u3089\u5168\u4F53\u3067(Q+N)sqrt(N)\
    \ * \u305D\u306E\u8A08\u7B97\u91CF \u3067\u30AF\u30A8\u30EA\u3092\u56DE\u305B\u308B\
    \r\n\t\u524A\u308C\u306A\u3044\u3068\u304D\u306F \u2192 snapshot (snuke\u30D6\u30ED\
    \u30B0\u53C2\u7167)\r\n\t\u533A\u9593\u540C\u58EB\u306Emerge\u304C\u3067\u304D\
    \u308B\u306A\u3089\u666E\u901A\u306Bsegtree\u3060\u3051\u3069\u3001\u51FA\u6765\
    \u306A\u3044\u3068\u304D(\u30BD\u30FC\u30C8\u7CFB\u304C\u5165\u308B\u3068\u3060\
    \u3044\u305F\u3044\u305D\u3046)\u306F\u3053\u308C.\r\n*/\r\n#include <bits/stdc++.h>\r\
    \n#define rep(i,n) for(int i=0;i<(int)(n);i++)\r\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\r\
    \n#define all(c) c.begin(),c.end()\r\n#define pb push_back\r\n#define fs first\r\
    \n#define sc second\r\n#define show(x) cout << #x << \" = \" << x << endl\r\n\
    #define chmin(x,y) x=min(x,y)\r\n#define chmax(x,y) x=max(x,y)\r\nusing namespace\
    \ std;\r\ntemplate<class S,class T> ostream& operator<<(ostream& o,const pair<S,T>\
    \ &p){return o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";}\r\ntemplate<class T> ostream&\
    \ operator<<(ostream& o,const vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"\
    [\";for(const T& v:vc) o<<v<<\",\";o<<\"]\";return o;}\r\ntypedef pair<int,int>\
    \ P;\r\ntypedef pair<P,int> PP;\r\nPP qs[100000];\r\nconst int B = 320;\r\nbool\
    \ cmp(const PP& a,const PP& b){\r\n\tif(a.fs.fs/B != b.fs.fs/B) return a.fs.fs/B\
    \ < b.fs.fs/B;\r\n\treturn a.fs.sc < b.fs.sc;\r\n}\r\n\r\ntypedef long long ll;\r\
    \nstruct BIT{\r\n\tint N;\r\n\tvector<ll> bit;\r\n\tvoid init(int n){\r\n\t\t\
    N=n;\r\n\t\tbit.resize(n+1);\r\n\t}\r\n\tll sum(int i){\t\t//i\u500B\u306E\u548C\
    a[0]+..a[i-1]\r\n\t\tll s=0;\r\n\t\twhile(i>0){\r\n\t\t\ts+=bit[i];\r\n\t\t\t\
    i-=(i&-i);\r\n\t\t}\r\n\t\treturn s;\r\n\t}\r\n\tvoid add(int i,int x){\t//a[i]+=x\
    \ (0-indexed)\r\n\t\ti++;\r\n\t\twhile(i<=N){\r\n\t\t\tbit[i]+=x;\r\n\t\t\ti+=(i&-i);\r\
    \n\t\t}\r\n\t}\r\n}bit,sbit;\r\n\r\n\r\nll sum = 0;\r\nll ssum = 0;\r\nconst int\
    \ MX = 100000;\r\nvoid add(int v){\r\n\tint id=bit.sum(v);\r\n\tsum += (ll)(id*2+1)\
    \ * v;\r\n\tsum += (ssum-sbit.sum(v))* 2;\r\n\tbit.add(v,1);\r\n\tsbit.add(v,v);\r\
    \n\tssum+=v;\r\n\t// show(v);\r\n\t// show(id);\r\n\t// show(sum);\r\n}\r\nvoid\
    \ erase(int v){\r\n\tint id=bit.sum(v);\r\n\tbit.add(v,-1);\r\n\tsbit.add(v,-v);\r\
    \n\tssum-=v;\r\n\tsum -= (ll)(id*2+1) * v;\r\n\tsum -= (ssum-sbit.sum(v))* 2;\r\
    \n\t// show(v);\r\n\t// show(id);\r\n\t// show(sum);\r\n}\r\n\r\nint N,Q,a[100000];\r\
    \ndouble ans[100000];\r\nint main(){\r\n\tbit.init(100010);\r\n\tsbit.init(100010);\r\
    \n\tcin>>N>>Q;\r\n\trep(i,N) cin>>a[i];\r\n\trep(i,Q){\r\n\t\tint l,r;\r\n\t\t\
    cin>>l>>r;\r\n\t\tqs[i]=PP(P(l-1,r),i);\r\n\t}\r\n\tsort(qs,qs+Q,cmp);\r\n\tint\
    \ L=0,R=0;\r\n\trep(t,Q){\r\n\t\tint l=qs[t].fs.fs,r=qs[t].fs.sc,id=qs[t].sc;\r\
    \n\t\tfor(;l<L;) add(a[--L]);\r\n\t\tfor(;r>R;) add(a[R++]);\r\n\t\tfor(;l>L;)\
    \ erase(a[L++]);\r\n\t\tfor(;r<R;) erase(a[--R]);\r\n\t\t// printf(\"[%d,%d)\\\
    n\",L,R);\r\n\t\t// show(sum);\r\n\t\tans[id]= (double)sum/(R-L)/(R-L);\r\n\t\
    }\r\n\trep(i,Q) printf(\"%.12f\\n\",ans[i]);\r\n}\r\n"
  code: "/*\r\n\tmo-algorithm\r\n\t\u533A\u9593\u30AF\u30A8\u30EA\u304C\u3044\u3063\
    \u3071\u3044\u6765\u308B\u3068\u304D\u306B\u3001\u533A\u9593\u306E1\u3072\u304D\
    \u306E\u3070\u3057\u30681\u3051\u305A\u308A\u304C\u901F\u304F\u3067\u304D\u308B\
    \u306A\u3089\u5168\u4F53\u3067(Q+N)sqrt(N) * \u305D\u306E\u8A08\u7B97\u91CF \u3067\
    \u30AF\u30A8\u30EA\u3092\u56DE\u305B\u308B\r\n\t\u524A\u308C\u306A\u3044\u3068\
    \u304D\u306F \u2192 snapshot (snuke\u30D6\u30ED\u30B0\u53C2\u7167)\r\n\t\u533A\
    \u9593\u540C\u58EB\u306Emerge\u304C\u3067\u304D\u308B\u306A\u3089\u666E\u901A\u306B\
    segtree\u3060\u3051\u3069\u3001\u51FA\u6765\u306A\u3044\u3068\u304D(\u30BD\u30FC\
    \u30C8\u7CFB\u304C\u5165\u308B\u3068\u3060\u3044\u305F\u3044\u305D\u3046)\u306F\
    \u3053\u308C.\r\n*/\r\n#include <bits/stdc++.h>\r\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\r\
    \n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\r\n#define all(c) c.begin(),c.end()\r\
    \n#define pb push_back\r\n#define fs first\r\n#define sc second\r\n#define show(x)\
    \ cout << #x << \" = \" << x << endl\r\n#define chmin(x,y) x=min(x,y)\r\n#define\
    \ chmax(x,y) x=max(x,y)\r\nusing namespace std;\r\ntemplate<class S,class T> ostream&\
    \ operator<<(ostream& o,const pair<S,T> &p){return o<<\"(\"<<p.fs<<\",\"<<p.sc<<\"\
    )\";}\r\ntemplate<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<\"\
    sz = \"<<vc.size()<<endl<<\"[\";for(const T& v:vc) o<<v<<\",\";o<<\"]\";return\
    \ o;}\r\ntypedef pair<int,int> P;\r\ntypedef pair<P,int> PP;\r\nPP qs[100000];\r\
    \nconst int B = 320;\r\nbool cmp(const PP& a,const PP& b){\r\n\tif(a.fs.fs/B !=\
    \ b.fs.fs/B) return a.fs.fs/B < b.fs.fs/B;\r\n\treturn a.fs.sc < b.fs.sc;\r\n\
    }\r\n\r\ntypedef long long ll;\r\nstruct BIT{\r\n\tint N;\r\n\tvector<ll> bit;\r\
    \n\tvoid init(int n){\r\n\t\tN=n;\r\n\t\tbit.resize(n+1);\r\n\t}\r\n\tll sum(int\
    \ i){\t\t//i\u500B\u306E\u548Ca[0]+..a[i-1]\r\n\t\tll s=0;\r\n\t\twhile(i>0){\r\
    \n\t\t\ts+=bit[i];\r\n\t\t\ti-=(i&-i);\r\n\t\t}\r\n\t\treturn s;\r\n\t}\r\n\t\
    void add(int i,int x){\t//a[i]+=x (0-indexed)\r\n\t\ti++;\r\n\t\twhile(i<=N){\r\
    \n\t\t\tbit[i]+=x;\r\n\t\t\ti+=(i&-i);\r\n\t\t}\r\n\t}\r\n}bit,sbit;\r\n\r\n\r\
    \nll sum = 0;\r\nll ssum = 0;\r\nconst int MX = 100000;\r\nvoid add(int v){\r\n\
    \tint id=bit.sum(v);\r\n\tsum += (ll)(id*2+1) * v;\r\n\tsum += (ssum-sbit.sum(v))*\
    \ 2;\r\n\tbit.add(v,1);\r\n\tsbit.add(v,v);\r\n\tssum+=v;\r\n\t// show(v);\r\n\
    \t// show(id);\r\n\t// show(sum);\r\n}\r\nvoid erase(int v){\r\n\tint id=bit.sum(v);\r\
    \n\tbit.add(v,-1);\r\n\tsbit.add(v,-v);\r\n\tssum-=v;\r\n\tsum -= (ll)(id*2+1)\
    \ * v;\r\n\tsum -= (ssum-sbit.sum(v))* 2;\r\n\t// show(v);\r\n\t// show(id);\r\
    \n\t// show(sum);\r\n}\r\n\r\nint N,Q,a[100000];\r\ndouble ans[100000];\r\nint\
    \ main(){\r\n\tbit.init(100010);\r\n\tsbit.init(100010);\r\n\tcin>>N>>Q;\r\n\t\
    rep(i,N) cin>>a[i];\r\n\trep(i,Q){\r\n\t\tint l,r;\r\n\t\tcin>>l>>r;\r\n\t\tqs[i]=PP(P(l-1,r),i);\r\
    \n\t}\r\n\tsort(qs,qs+Q,cmp);\r\n\tint L=0,R=0;\r\n\trep(t,Q){\r\n\t\tint l=qs[t].fs.fs,r=qs[t].fs.sc,id=qs[t].sc;\r\
    \n\t\tfor(;l<L;) add(a[--L]);\r\n\t\tfor(;r>R;) add(a[R++]);\r\n\t\tfor(;l>L;)\
    \ erase(a[L++]);\r\n\t\tfor(;r<R;) erase(a[--R]);\r\n\t\t// printf(\"[%d,%d)\\\
    n\",L,R);\r\n\t\t// show(sum);\r\n\t\tans[id]= (double)sum/(R-L)/(R-L);\r\n\t\
    }\r\n\trep(i,Q) printf(\"%.12f\\n\",ans[i]);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data structure/mo.cpp
  requiredBy: []
  timestamp: '2018-05-18 18:37:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/mo.cpp
layout: document
redirect_from:
- /library/data structure/mo.cpp
- /library/data structure/mo.cpp.html
title: data structure/mo.cpp
---
