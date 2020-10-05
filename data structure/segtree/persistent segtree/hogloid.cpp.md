---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data structure/segtree/persistent segtree/hogloid.cpp\"\n\
    #include<iostream>\n#include<cstdio>\n#define REP(i,m) for(int i=0;i<(m);++i)\n\
    #define REPN(i,m,in) for(int i=(in);i<(m);++i)\n#define ALL(t) (t).begin(),(t).end()\n\
    #define CLR(a) memset((a),0,sizeof(a))\n#define pb push_back\n#define mp make_pair\n\
    #define fr first\n#define sc second\n\nusing namespace std;\n\n\n#ifdef DEB\n\
    #define dump(x)  cerr << #x << \" = \" << (x) << endl\n#define prl cerr<<\"called:\"\
    << __LINE__<<endl\ntemplate<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<'\
    \ ';cerr<<endl;}\n#else\n#define dump(x) ;\n#define prl ;\ntemplate<class T> void\
    \ debug(T a,T b){ ;}\n#endif\n\ntemplate<class T> void chmin(T& a,const T& b)\
    \ { if(a>b) a=b; }\ntemplate<class T> void chmax(T& a,const T& b) { if(a<b) a=b;\
    \ }\n\ntypedef long long int lint;\ntypedef pair<int,int> pi;\n\nnamespace std{\n\
    \ttemplate<class S,class T>\n\tostream &operator <<(ostream& out,const pair<S,T>&\
    \ a){\n\t\tout<<'('<<a.fr<<','<<a.sc<<')';\n\t\treturn out;\n\t}\n}\n\nint root[200005];\n\
    struct segtree{\n\tint lch_[4000000],rch_[4000000];\n\tint val_[4000000];\n\n\t\
    int *lch,*rch,*val;\n\tint cnt;\n\t\n\tvoid init(){\n\t\tlch=&lch_[1];\n\t\trch=&rch_[1];\n\
    \t\tval=&val_[1];\n\n\t\tlch[-1]=rch[-1]=-1;\n\t\tval[-1]=0;\n\t\tcnt=0;\n\t}\n\
    \tint query(int a,int b,int i,int l,int r){\n\t\tif(i==-1) return 0;\n\n\t\tif(a<=l\
    \ && r<=b){\n\t\t\treturn val[i];\n\t\t}\n\t\tif(b<=l || r<=a) return 0;\n\n\t\
    \tint md=(l+r)>>1;\n\t\treturn query(a,b,lch[i],l,md)+query(a,b,rch[i],md,r);\n\
    \t}\n\tint set(int p,int i,int l,int r){\n\t\tif(r-l==1){\n\t\t\tint v=cnt;++cnt;\n\
    \t\t\tlch[v]=rch[v]=-1;\n\t\t\tval[v]=1+val[i];\n\n\t\t\treturn v;\n\t\t}\n\t\t\
    int md=(l+r)>>1;\n\t\tint v=cnt;++cnt;\n\t\tif(p<md){\n\t\t\tlch[v]=set(p,lch[i],l,md);\n\
    \t\t\trch[v]=rch[i];\n\t\t}else{\n\t\t\trch[v]=set(p,rch[i],md,r);\n\t\t\tlch[v]=lch[i];\n\
    \t\t}\n\t\tval[v]=val[lch[v]]+val[rch[v]];\n\t\treturn v;\n\t}\n};\n\n\nsegtree\
    \ seg;\n\t\nint n;\n\npi range[200005];\n//const int INF=5e8;\nint main(){\n\t\
    root[0]=-1;\n\tcin>>n;\n\tREP(i,n) cin>>range[i].fr;\n\tREP(i,n) cin>>range[i].sc;\n\
    \t\n\tseg.init();\n\tint x=0;\n\tREP(i,n){\n\t\troot[i+1]=seg.set(x,root[i],0,n);\n\
    \t\tint cnt=seg.query(range[i].fr,range[i].sc,root[x+1],0,n);\n\t\tx=(cnt*(lint)range[i].fr+range[i].sc)%(i+2);\n\
    \t}\n\tcout<<x<<endl;\n\n\n\treturn 0;\n}\n"
  code: "#include<iostream>\n#include<cstdio>\n#define REP(i,m) for(int i=0;i<(m);++i)\n\
    #define REPN(i,m,in) for(int i=(in);i<(m);++i)\n#define ALL(t) (t).begin(),(t).end()\n\
    #define CLR(a) memset((a),0,sizeof(a))\n#define pb push_back\n#define mp make_pair\n\
    #define fr first\n#define sc second\n\nusing namespace std;\n\n\n#ifdef DEB\n\
    #define dump(x)  cerr << #x << \" = \" << (x) << endl\n#define prl cerr<<\"called:\"\
    << __LINE__<<endl\ntemplate<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<'\
    \ ';cerr<<endl;}\n#else\n#define dump(x) ;\n#define prl ;\ntemplate<class T> void\
    \ debug(T a,T b){ ;}\n#endif\n\ntemplate<class T> void chmin(T& a,const T& b)\
    \ { if(a>b) a=b; }\ntemplate<class T> void chmax(T& a,const T& b) { if(a<b) a=b;\
    \ }\n\ntypedef long long int lint;\ntypedef pair<int,int> pi;\n\nnamespace std{\n\
    \ttemplate<class S,class T>\n\tostream &operator <<(ostream& out,const pair<S,T>&\
    \ a){\n\t\tout<<'('<<a.fr<<','<<a.sc<<')';\n\t\treturn out;\n\t}\n}\n\nint root[200005];\n\
    struct segtree{\n\tint lch_[4000000],rch_[4000000];\n\tint val_[4000000];\n\n\t\
    int *lch,*rch,*val;\n\tint cnt;\n\t\n\tvoid init(){\n\t\tlch=&lch_[1];\n\t\trch=&rch_[1];\n\
    \t\tval=&val_[1];\n\n\t\tlch[-1]=rch[-1]=-1;\n\t\tval[-1]=0;\n\t\tcnt=0;\n\t}\n\
    \tint query(int a,int b,int i,int l,int r){\n\t\tif(i==-1) return 0;\n\n\t\tif(a<=l\
    \ && r<=b){\n\t\t\treturn val[i];\n\t\t}\n\t\tif(b<=l || r<=a) return 0;\n\n\t\
    \tint md=(l+r)>>1;\n\t\treturn query(a,b,lch[i],l,md)+query(a,b,rch[i],md,r);\n\
    \t}\n\tint set(int p,int i,int l,int r){\n\t\tif(r-l==1){\n\t\t\tint v=cnt;++cnt;\n\
    \t\t\tlch[v]=rch[v]=-1;\n\t\t\tval[v]=1+val[i];\n\n\t\t\treturn v;\n\t\t}\n\t\t\
    int md=(l+r)>>1;\n\t\tint v=cnt;++cnt;\n\t\tif(p<md){\n\t\t\tlch[v]=set(p,lch[i],l,md);\n\
    \t\t\trch[v]=rch[i];\n\t\t}else{\n\t\t\trch[v]=set(p,rch[i],md,r);\n\t\t\tlch[v]=lch[i];\n\
    \t\t}\n\t\tval[v]=val[lch[v]]+val[rch[v]];\n\t\treturn v;\n\t}\n};\n\n\nsegtree\
    \ seg;\n\t\nint n;\n\npi range[200005];\n//const int INF=5e8;\nint main(){\n\t\
    root[0]=-1;\n\tcin>>n;\n\tREP(i,n) cin>>range[i].fr;\n\tREP(i,n) cin>>range[i].sc;\n\
    \t\n\tseg.init();\n\tint x=0;\n\tREP(i,n){\n\t\troot[i+1]=seg.set(x,root[i],0,n);\n\
    \t\tint cnt=seg.query(range[i].fr,range[i].sc,root[x+1],0,n);\n\t\tx=(cnt*(lint)range[i].fr+range[i].sc)%(i+2);\n\
    \t}\n\tcout<<x<<endl;\n\n\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: data structure/segtree/persistent segtree/hogloid.cpp
  requiredBy: []
  timestamp: '2017-02-02 01:38:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/segtree/persistent segtree/hogloid.cpp
layout: document
redirect_from:
- /library/data structure/segtree/persistent segtree/hogloid.cpp
- /library/data structure/segtree/persistent segtree/hogloid.cpp.html
title: data structure/segtree/persistent segtree/hogloid.cpp
---
