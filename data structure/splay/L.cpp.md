---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data structure/splay/L.cpp\"\n/*\n\t\u3053\u308C\u306A\u3093\
    \u3060\u3063\u3051?\n*/\n#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define show(x) cout\
    \ << #x << \" = \" << x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y)\
    \ x=max(x,y)\nusing namespace std;\n\nnamespace SuffixArray{\n\ttemplate<class\
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
    \t\t\tsa[it[c]++]=v[i];\n\t\t}\n\t\tinduce(N,s,is,sa,lbase,K);\n\t}\n}\n\n\ntemplate<class\
    \ T>\nstruct SplayTree{\n\tstruct Node;\n\ttypedef Node* NP;\n\tstatic NP nil;\n\
    \tstruct Node{\n\t\tNP p,l,r;\t\t\t//parent,left child,right child\n\t\tint sz;\n\
    \t\tint v;\n\t\tNode(int v) :p(nullptr),l(nil),r(nil),sz(1),v(v){}\n\t\tNode()\
    \ : p(nullptr),l(nullptr),r(nullptr),sz(0),v(0){}\t\t\t\t\t\t//\u5358\u4F4D\u5143\
    !!\n\t\tint pos(){\t\t\t//\u89AA\u306E\u5DE6\u306E\u5B50\u304B,\u53F3\u306E\u5B50\
    \u304B,\u305D\u308C\u3068\u3082\u6839(or null)\u304B\n\t\t\tif(p&&p->l == this)\
    \ return -1;\n\t\t\tif(p&&p->r == this) return 1;\n\t\t\treturn 0;\n\t\t}\n\t\t\
    void rot(){\t\t\t\t//root\u3067\u547C\u3076\u3068\u6B7B\n\t\t\tNP pp=p->p;\t\t\
    \t//\u89AA\u306E\u89AA\n\t\t\tint pps=p->pos();\t//pp\u304B\u3089\u307F\u305F\
    p\u306E\u5DE6\u53F3\n\t\t\tif(p->l==this){\t\t//pos()==-1\n\t\t\t\tp->l=r,r->p=p,r=p,p->p=this;\n\
    \t\t\t}else{\n\t\t\t\tp->r=l,l->p=p,l=p,p->p=this;\n\t\t\t}\n\t\t\t//\u65B0\u3057\
    \u3044\u6728\u3067\u4E0B\u304B\u3089update\n\t\t\tp->update();\n\t\t\tupdate();\n\
    \t\t\tp=pp;\n\t\t\tif(pps==0) return;\n\t\t\tif(pps==-1) pp->l=this;\n\t\t\telse\
    \ pp->r=this;\n\t\t\tpp->update();\n\t\t}\n\t\tvoid splay(){\t\t\t//this\u3092\
    root\u306B\u3082\u3063\u3066\u304F\u308B\n\t\t\twhile(true){\n\t\t\t\tint ps=pos();\n\
    \t\t\t\tif(ps==0) break;\n\t\t\t\tint pps=p->pos();\n\t\t\t\tif(pps==0){\t\t//zig\n\
    \t\t\t\t\trot();\n\t\t\t\t}else if(ps==pps){\t\t//zigzig\n\t\t\t\t\tp->rot();rot();\n\
    \t\t\t\t}else{\t\t\t\t\t//zigzag\n\t\t\t\t\trot();rot();\n\t\t\t\t}\n\t\t\t}\n\
    \t\t}\n\t\tNP splay(int k){\t\t\t//\u3053\u306E\u533A\u9593\u306E\u5DE6\u304B\u3089\
    kth(0-indexed)\u3092root\u306B\u3082\u3063\u3066\u304D\u3066\u305D\u306E\u30DD\
    \u30A4\u30F3\u30BF\u3092\u8FD4\u3059(sz\u304C\u5FC5\u8981)\n\t\t\t//assert(0<=k&&k<sz);\n\
    \t\t\tif(k<l->sz){\n\t\t\t\treturn l->splay(k);\n\t\t\t}else if(k==l->sz){\n\t\
    \t\t\tsplay();\n\t\t\t\treturn this;\n\t\t\t}else{\n\t\t\t\treturn r->splay(k-(l->sz+1));\n\
    \t\t\t}\n\t\t}\n\t\tNP update(){\t\t//\u60C5\u5831\u66F4\u65B0(\u5B50\u304C\u6B63\
    \u3057\u3044\u6642\u306B\u547C\u3070\u306A\u3044\u3068\u30C0\u30E1) (\u6700\u5F8C\
    \u306Bupdate\u3057\u3066return\u3059\u308B\u306E\u306B\u697D\u306A\u306E\u3067\
    NP\u3092\u8FD4\u3059)\n\t\t\tsz=1+l->sz+r->sz;\n\t\t\treturn this;\n\t\t}\n\n\t\
    };\n\tNP n;\n\tstatic NP merge(NP l,NP r){\t\t\t//merge\u3057\u305F\u6839\n\t\t\
    if(r==nil) return l;\n\t\tr=r->splay(0);\n\t\tr->l=l;\n\t\tl->p=r;\n\t\treturn\
    \ r->update();\n\t}\n\t/*\n\t\tkth\u3067split(k=0\u306A\u3089fs=null)\n\t\tl\u306F\
    \u5B8C\u5168\u306B\u5207\u308A\u96E2\u3055\u308C\u3066\u308B\u3051\u308C\u3069\
    \n\t\tr\u306F\u4E0A\u3068\u3064\u306A\u304C\u3063\u3066\u3044\u308B?\n\t\t\u307E\
    \u3042\u3067\u3082\u57FA\u672C\u7684\u306Bsplit\u306E\u7B2C\u4E00\u5F15\u6570\u306F\
    root\u306A\u306E\u3067\u5927\u4E08\u592B\n\t*/\n\tstatic pair<NP,NP> split(NP\
    \ x,int k){\n\t\t//assert(0<=k&&k<=x->sz);\n\t\tif(k==x->sz) return {x,nil};\n\
    \t\tx=x->splay(k);\n\t\tNP l=x->l;\n\t\tl->p = nullptr;\n\t\tx->l = nil;\n\t\t\
    return {l,x->update()};\n\t}\n\tstatic NP built(int sz,int vs[]){\t\t\t\t//init\n\
    \t\tif(!sz) return nil;\n\t\tint md=sz/2;\n\t\tNP x= new Node(vs[md]);\n\t\tx->l\
    \ = built(md,vs);\n\t\tx->l->p=x;\n\t\tx->r=built(sz-(md+1),vs+md+1);\n\t\tx->r->p=x;\n\
    \t\treturn x->update();\n\t}\n\tSplayTree() : n(nil){}\n\tSplayTree(NP n) : n(n){}\n\
    \tSplayTree(int sz,int vs[]){\n\t\tn=built(sz,vs);\n\t}\n\tvoid insert(int k,int\
    \ v){\n\t\tauto u=split(n,k);\n\t\tn=merge(merge(u.fs,new Node(v)),u.sc);\n\t\
    }\n\tvoid insert(int v){\n\t\tint k=lower_bound(v);\n\t\tinsert(k,v);\n\t}\n\t\
    void erase(int k){\n\t\tauto u=split(n,k);\n\t\tn=merge(u.fs,split(u.sc,1).sc);\n\
    \t}\n\tvoid merge(SplayTree t){\n\t\tn=merge(n,t.n);\n\t}\n\tint sz(){\n\t\treturn\
    \ n->sz;\n\t}\n\tint get(int k){\t\t\t//kth info\n\t\tauto a=split(n,k);\n\t\t\
    auto b=split(a.sc,1);\n\t\tint ret=b.fs->v;\n\t\tn=merge(merge(a.fs,b.fs),b.sc);\n\
    \t\treturn ret;\n\t}\n\t/*\n\t\tsearch\n\t\t\u5E73\u8861\u4E8C\u5206\u6728\u3068\
    \u3057\u3066\u306E\u5F79\u76EE\u3092\u601D\u3044\u51FA\u305B\n\t\t\u306A\u3093\
    \u304B\u5217\u3092\u304F\u3063\u3064\u3051\u305F\u308A\u308F\u3051\u305F\u308A\
    \u3067\u304D\u308B\u3068\u3060\u3051\u601D\u3063\u3068\u3051\u3070\u57FA\u672C\
    \u3044\u3044\u3051\u3069\n\t\t\u6301\u3063\u3066\u308B\u30C7\u30FC\u30BF\u306B\
    \u9806\u5E8F\u4ED8\u3044\u3066\u308B\u3068\u304D\u306B\u306F\u3061\u3083\u3093\
    \u3068\u4E8C\u5206\u6728\u3068\u3057\u3066\u4F7F\u3048\u308B\n\t*/\n\tint lower_bound(int\
    \ x){\t\t//x\u4EE5\u4E0A\u3067\u4E00\u756A\u5C0F\u3055\u3044\u3068\u3053\u306E\
    id\u3092\u8FD4\u3059\n\t\tNP p=n;\n\t\tint ret=0;\n\t\twhile(p!=nil){\n\t\t\t\
    if(x<=p->v) p=p->l;\n\t\t\telse ret+=(p->l->sz)+1,p=p->r;\n\t\t}\n\t\treturn ret;\n\
    \t}\n\tint upper_bound(int x){\t\t//x\u3088\u308A\u5927\u3067\u4E00\u756A\u5C0F\
    \u3055\u3044\u3068\u3053\u306Eid\u3092\u8FD4\u3059\n\t\tNP p=n;\n\t\tint ret=0;\n\
    \t\twhile(p!=nil){\n\t\t\tif(x<p->v) p=p->l;\n\t\t\telse ret+=(p->l->sz)+1,p=p->r;\n\
    \t\t}\n\t\treturn ret;\n\t}\n};\ntemplate<class T>\ntypename SplayTree<T>::NP\
    \ SplayTree<T>::nil = new SplayTree<T>::Node();\nstruct segtree{\n\tint N;\n\t\
    SplayTree<int> seg[1<<17];\n\tsegtree(int n){\n\t\tint p2=1;\n\t\twhile(p2<n)\
    \ p2*=2;\n\t\tN=p2;\n\t}\n\tvoid add(int x,int y){\t\t\t//add P(x,y)\n\t\tx+=N;\n\
    \t\twhile(x){\n\t\t\tseg[x].insert(y);\n\t\t\tx/=2;\n\t\t}\n\t}\n\tint count(int\
    \ a,int b,int ya,int yb,int l,int r,int k){\t\t//[a,b) * [ya,yb)\n\t\tif(b<=l||r<=a)\
    \ return 0;\n\t\tif(a<=l&&r<=b) return seg[k].lower_bound(yb)-seg[k].lower_bound(ya);\n\
    \t\treturn count(a,b,ya,yb,l,(l+r)/2,k*2)+count(a,b,ya,yb,(l+r)/2,r,k*2+1);\n\t\
    }\n\tint count(int a,int b,int ya,int yb){\n//\t\tprintf(\"[%d,%d)*[%d,%d)\\n\"\
    ,a,b,ya,yb);\n\t\treturn count(a,b,ya,yb,0,N,1);\n\t}\n};\n\nint lo(int *sa,string&\
    \ s,string& t){\n\tint N=s.size()+1;\n\tint l=-1,r=N+1;\n\twhile(r-l>1){\n\t\t\
    int m=(r+l)/2;\n\t\tif(s.compare(sa[m],t.length(),t)<0) l=m;\n\t\telse r=m;\n\t\
    }\n\treturn r;\n}\nint hi(int *sa,string& s,string& t){\n\tint N=s.size()+1;\n\
    \tint l=-1,r=N+1;\n\twhile(r-l>1){\n\t\tint m=(r+l)/2;\n\t\tif(s.compare(sa[m],t.length(),t)<=0)\
    \ l=m;\n\t\telse r=m;\n\t}\n\treturn r;\n}\nint main(){\n\tint N,Q,sa[100001];\n\
    \tstring s;\n\tcin>>s>>Q;\n\tN=s.size();\n\tSuffixArray::SA(N,s.c_str(),sa,256);\n\
    \tsegtree seg(N+1);\n\trep(i,N+1){\n\t\tseg.add(sa[i],i);\n\t}\n\trep(tt,Q){\n\
    \t\tint l,r;\n\t\tstring t;\n\t\tcin>>l>>r>>t;\n\t\tr++;\n\t\tint K=t.size();\n\
    \t\tif(r-l<K){\n\t\t\tputs(\"0\");\n\t\t\tcontinue;\n\t\t}\n\t\tint ya=lo(sa,s,t);\n\
    \t\tint yb=hi(sa,s,t);\n\t\tif(ya>=yb){\n\t\t\tputs(\"0\");\n\t\t\tcontinue;\n\
    \t\t}\n\t\tcout<<seg.count(l,r-K+1,ya,yb)<<endl;\n\t}\n}\n"
  code: "/*\n\t\u3053\u308C\u306A\u3093\u3060\u3063\u3051?\n*/\n#include <bits/stdc++.h>\n\
    #define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) cout << #x << \" = \" << x << endl\n#define chmin(x,y)\
    \ x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace std;\n\nnamespace\
    \ SuffixArray{\n\ttemplate<class T>\n\tvoid induce(int N,const T s[],bool is[],int\
    \ sa[],int lbase[],int K){\n\t\tint it[K+1];\n\t\tcopy_n(lbase,K+1,it);\n\t\t\
    rep(i,N+1){\n\t\t\tif(sa[i]>=1&&!is[sa[i]-1]){\n\t\t\t\tint c=s[sa[i]-1];\n\t\t\
    \t\tsa[it[c]++]=sa[i]-1;\n\t\t\t}\n\t\t}\n\t\tcopy_n(lbase,K+1,it);\n\t\tfor(int\
    \ i=N;i>0;i--){\n\t\t\tif(sa[i]>=1&&is[sa[i]-1]){\n\t\t\t\tint c=s[sa[i]-1];\n\
    \t\t\t\tsa[--it[c+1]]=sa[i]-1;\n\t\t\t}\n\t\t}\n\t}\n\ttemplate<class T>\n\tvoid\
    \ SA(int N,const T s[],int sa[],int K){\n\t\tbool is[N+1];\t\t//stype?\n\t\tint\
    \ lcnt[K+1]={},scnt[K+1]={};\n\t\tis[N]=1;\n\t\tfor(int i=N-1;i>=0;i--){\n\t\t\
    \tif(i==N-1||s[i]>s[i+1]) is[i]=0;\n\t\t\telse if(s[i]<s[i+1]) is[i]=1;\n\t\t\t\
    else is[i]=is[i+1];\n\t\t\tif(!is[i]) lcnt[(int)s[i]]++;\n\t\t\telse scnt[(int)s[i]]++;\n\
    \t\t}\n\t\tvector<int> v;\t\t//LMSs\n\t\tint lms[N+1];\n\t\tfill_n(lms,N+1,-1);\n\
    \t\tint c=0;\n\t\trep1(i,N-1){\n\t\t\tif(!is[i-1]&&is[i]){\n\t\t\t\tlms[i]=c++;\n\
    \t\t\t\tv.pb(i);\n\t\t\t}\n\t\t}\n\t\tint lbase[K+1],sbase[K+1];\n\t\tlbase[0]=1,sbase[0]=1+lcnt[0];\n\
    \t\trep1(i,K){\n\t\t\tlbase[i]=sbase[i-1]+scnt[i-1];\n\t\t\tsbase[i]=lbase[i]+lcnt[i];\n\
    \t\t}\n\t\tif(!v.empty()){\n\t\t\tvector<int> v2=v;\n\t\t\tint it[K+1];\t\t\t\
    //iterate\n\t\t\tcopy_n(sbase,K+1,it);\n\t\t\tfill_n(sa,N+1,-1);\n\t\t\tsa[0]=N;\n\
    \t\t\trep(i,v.size()){\n\t\t\t\tint c=s[v[i]];\n\t\t\t\tsa[it[c]++]=v[i];\n\t\t\
    \t}\n\t\t\tinduce(N,s,is,sa,lbase,K);\n\t\t\tint c=0;\n\t\t\trep1(i,N) if(lms[sa[i]]>=0)\
    \ v[c++]=sa[i];\n\t\t\tint s2[v.size()],sa2[v.size()+1];\n\t\t\tc=0;\n\t\t\ts2[lms[v[0]]]=0;\n\
    \t\t\tfor(int i=1;i<(int)v.size();i++){\n\t\t\t\tint l=v[i-1],r=v[i];\n\t\t\t\t\
    while(true){\n\t\t\t\t\tif(s[l]!=s[r]){\n\t\t\t\t\t\tc++;\n\t\t\t\t\t\tbreak;\n\
    \t\t\t\t\t}\n\t\t\t\t\tl++,r++;\n\t\t\t\t\tif(lms[l]>=0||lms[r]>=0){\n\t\t\t\t\
    \t\tif(lms[l]<0||lms[r]<0) c++;\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\
    \t\t\ts2[lms[v[i]]]=c;\n\t\t\t}\n\t\t\tSA(v.size(),s2,sa2,c);\n\t\t\trep1(i,v.size())\
    \ v[i-1]=v2[sa2[i]];\n\t\t}\n\t\tint it[K+1];\n\t\tcopy_n(sbase,K+1,it);\n\t\t\
    fill_n(sa,N+1,-1);\n\t\tsa[0]=N;\n\t\trep(i,v.size()){\n\t\t\tint c=s[v[i]];\n\
    \t\t\tsa[it[c]++]=v[i];\n\t\t}\n\t\tinduce(N,s,is,sa,lbase,K);\n\t}\n}\n\n\ntemplate<class\
    \ T>\nstruct SplayTree{\n\tstruct Node;\n\ttypedef Node* NP;\n\tstatic NP nil;\n\
    \tstruct Node{\n\t\tNP p,l,r;\t\t\t//parent,left child,right child\n\t\tint sz;\n\
    \t\tint v;\n\t\tNode(int v) :p(nullptr),l(nil),r(nil),sz(1),v(v){}\n\t\tNode()\
    \ : p(nullptr),l(nullptr),r(nullptr),sz(0),v(0){}\t\t\t\t\t\t//\u5358\u4F4D\u5143\
    !!\n\t\tint pos(){\t\t\t//\u89AA\u306E\u5DE6\u306E\u5B50\u304B,\u53F3\u306E\u5B50\
    \u304B,\u305D\u308C\u3068\u3082\u6839(or null)\u304B\n\t\t\tif(p&&p->l == this)\
    \ return -1;\n\t\t\tif(p&&p->r == this) return 1;\n\t\t\treturn 0;\n\t\t}\n\t\t\
    void rot(){\t\t\t\t//root\u3067\u547C\u3076\u3068\u6B7B\n\t\t\tNP pp=p->p;\t\t\
    \t//\u89AA\u306E\u89AA\n\t\t\tint pps=p->pos();\t//pp\u304B\u3089\u307F\u305F\
    p\u306E\u5DE6\u53F3\n\t\t\tif(p->l==this){\t\t//pos()==-1\n\t\t\t\tp->l=r,r->p=p,r=p,p->p=this;\n\
    \t\t\t}else{\n\t\t\t\tp->r=l,l->p=p,l=p,p->p=this;\n\t\t\t}\n\t\t\t//\u65B0\u3057\
    \u3044\u6728\u3067\u4E0B\u304B\u3089update\n\t\t\tp->update();\n\t\t\tupdate();\n\
    \t\t\tp=pp;\n\t\t\tif(pps==0) return;\n\t\t\tif(pps==-1) pp->l=this;\n\t\t\telse\
    \ pp->r=this;\n\t\t\tpp->update();\n\t\t}\n\t\tvoid splay(){\t\t\t//this\u3092\
    root\u306B\u3082\u3063\u3066\u304F\u308B\n\t\t\twhile(true){\n\t\t\t\tint ps=pos();\n\
    \t\t\t\tif(ps==0) break;\n\t\t\t\tint pps=p->pos();\n\t\t\t\tif(pps==0){\t\t//zig\n\
    \t\t\t\t\trot();\n\t\t\t\t}else if(ps==pps){\t\t//zigzig\n\t\t\t\t\tp->rot();rot();\n\
    \t\t\t\t}else{\t\t\t\t\t//zigzag\n\t\t\t\t\trot();rot();\n\t\t\t\t}\n\t\t\t}\n\
    \t\t}\n\t\tNP splay(int k){\t\t\t//\u3053\u306E\u533A\u9593\u306E\u5DE6\u304B\u3089\
    kth(0-indexed)\u3092root\u306B\u3082\u3063\u3066\u304D\u3066\u305D\u306E\u30DD\
    \u30A4\u30F3\u30BF\u3092\u8FD4\u3059(sz\u304C\u5FC5\u8981)\n\t\t\t//assert(0<=k&&k<sz);\n\
    \t\t\tif(k<l->sz){\n\t\t\t\treturn l->splay(k);\n\t\t\t}else if(k==l->sz){\n\t\
    \t\t\tsplay();\n\t\t\t\treturn this;\n\t\t\t}else{\n\t\t\t\treturn r->splay(k-(l->sz+1));\n\
    \t\t\t}\n\t\t}\n\t\tNP update(){\t\t//\u60C5\u5831\u66F4\u65B0(\u5B50\u304C\u6B63\
    \u3057\u3044\u6642\u306B\u547C\u3070\u306A\u3044\u3068\u30C0\u30E1) (\u6700\u5F8C\
    \u306Bupdate\u3057\u3066return\u3059\u308B\u306E\u306B\u697D\u306A\u306E\u3067\
    NP\u3092\u8FD4\u3059)\n\t\t\tsz=1+l->sz+r->sz;\n\t\t\treturn this;\n\t\t}\n\n\t\
    };\n\tNP n;\n\tstatic NP merge(NP l,NP r){\t\t\t//merge\u3057\u305F\u6839\n\t\t\
    if(r==nil) return l;\n\t\tr=r->splay(0);\n\t\tr->l=l;\n\t\tl->p=r;\n\t\treturn\
    \ r->update();\n\t}\n\t/*\n\t\tkth\u3067split(k=0\u306A\u3089fs=null)\n\t\tl\u306F\
    \u5B8C\u5168\u306B\u5207\u308A\u96E2\u3055\u308C\u3066\u308B\u3051\u308C\u3069\
    \n\t\tr\u306F\u4E0A\u3068\u3064\u306A\u304C\u3063\u3066\u3044\u308B?\n\t\t\u307E\
    \u3042\u3067\u3082\u57FA\u672C\u7684\u306Bsplit\u306E\u7B2C\u4E00\u5F15\u6570\u306F\
    root\u306A\u306E\u3067\u5927\u4E08\u592B\n\t*/\n\tstatic pair<NP,NP> split(NP\
    \ x,int k){\n\t\t//assert(0<=k&&k<=x->sz);\n\t\tif(k==x->sz) return {x,nil};\n\
    \t\tx=x->splay(k);\n\t\tNP l=x->l;\n\t\tl->p = nullptr;\n\t\tx->l = nil;\n\t\t\
    return {l,x->update()};\n\t}\n\tstatic NP built(int sz,int vs[]){\t\t\t\t//init\n\
    \t\tif(!sz) return nil;\n\t\tint md=sz/2;\n\t\tNP x= new Node(vs[md]);\n\t\tx->l\
    \ = built(md,vs);\n\t\tx->l->p=x;\n\t\tx->r=built(sz-(md+1),vs+md+1);\n\t\tx->r->p=x;\n\
    \t\treturn x->update();\n\t}\n\tSplayTree() : n(nil){}\n\tSplayTree(NP n) : n(n){}\n\
    \tSplayTree(int sz,int vs[]){\n\t\tn=built(sz,vs);\n\t}\n\tvoid insert(int k,int\
    \ v){\n\t\tauto u=split(n,k);\n\t\tn=merge(merge(u.fs,new Node(v)),u.sc);\n\t\
    }\n\tvoid insert(int v){\n\t\tint k=lower_bound(v);\n\t\tinsert(k,v);\n\t}\n\t\
    void erase(int k){\n\t\tauto u=split(n,k);\n\t\tn=merge(u.fs,split(u.sc,1).sc);\n\
    \t}\n\tvoid merge(SplayTree t){\n\t\tn=merge(n,t.n);\n\t}\n\tint sz(){\n\t\treturn\
    \ n->sz;\n\t}\n\tint get(int k){\t\t\t//kth info\n\t\tauto a=split(n,k);\n\t\t\
    auto b=split(a.sc,1);\n\t\tint ret=b.fs->v;\n\t\tn=merge(merge(a.fs,b.fs),b.sc);\n\
    \t\treturn ret;\n\t}\n\t/*\n\t\tsearch\n\t\t\u5E73\u8861\u4E8C\u5206\u6728\u3068\
    \u3057\u3066\u306E\u5F79\u76EE\u3092\u601D\u3044\u51FA\u305B\n\t\t\u306A\u3093\
    \u304B\u5217\u3092\u304F\u3063\u3064\u3051\u305F\u308A\u308F\u3051\u305F\u308A\
    \u3067\u304D\u308B\u3068\u3060\u3051\u601D\u3063\u3068\u3051\u3070\u57FA\u672C\
    \u3044\u3044\u3051\u3069\n\t\t\u6301\u3063\u3066\u308B\u30C7\u30FC\u30BF\u306B\
    \u9806\u5E8F\u4ED8\u3044\u3066\u308B\u3068\u304D\u306B\u306F\u3061\u3083\u3093\
    \u3068\u4E8C\u5206\u6728\u3068\u3057\u3066\u4F7F\u3048\u308B\n\t*/\n\tint lower_bound(int\
    \ x){\t\t//x\u4EE5\u4E0A\u3067\u4E00\u756A\u5C0F\u3055\u3044\u3068\u3053\u306E\
    id\u3092\u8FD4\u3059\n\t\tNP p=n;\n\t\tint ret=0;\n\t\twhile(p!=nil){\n\t\t\t\
    if(x<=p->v) p=p->l;\n\t\t\telse ret+=(p->l->sz)+1,p=p->r;\n\t\t}\n\t\treturn ret;\n\
    \t}\n\tint upper_bound(int x){\t\t//x\u3088\u308A\u5927\u3067\u4E00\u756A\u5C0F\
    \u3055\u3044\u3068\u3053\u306Eid\u3092\u8FD4\u3059\n\t\tNP p=n;\n\t\tint ret=0;\n\
    \t\twhile(p!=nil){\n\t\t\tif(x<p->v) p=p->l;\n\t\t\telse ret+=(p->l->sz)+1,p=p->r;\n\
    \t\t}\n\t\treturn ret;\n\t}\n};\ntemplate<class T>\ntypename SplayTree<T>::NP\
    \ SplayTree<T>::nil = new SplayTree<T>::Node();\nstruct segtree{\n\tint N;\n\t\
    SplayTree<int> seg[1<<17];\n\tsegtree(int n){\n\t\tint p2=1;\n\t\twhile(p2<n)\
    \ p2*=2;\n\t\tN=p2;\n\t}\n\tvoid add(int x,int y){\t\t\t//add P(x,y)\n\t\tx+=N;\n\
    \t\twhile(x){\n\t\t\tseg[x].insert(y);\n\t\t\tx/=2;\n\t\t}\n\t}\n\tint count(int\
    \ a,int b,int ya,int yb,int l,int r,int k){\t\t//[a,b) * [ya,yb)\n\t\tif(b<=l||r<=a)\
    \ return 0;\n\t\tif(a<=l&&r<=b) return seg[k].lower_bound(yb)-seg[k].lower_bound(ya);\n\
    \t\treturn count(a,b,ya,yb,l,(l+r)/2,k*2)+count(a,b,ya,yb,(l+r)/2,r,k*2+1);\n\t\
    }\n\tint count(int a,int b,int ya,int yb){\n//\t\tprintf(\"[%d,%d)*[%d,%d)\\n\"\
    ,a,b,ya,yb);\n\t\treturn count(a,b,ya,yb,0,N,1);\n\t}\n};\n\nint lo(int *sa,string&\
    \ s,string& t){\n\tint N=s.size()+1;\n\tint l=-1,r=N+1;\n\twhile(r-l>1){\n\t\t\
    int m=(r+l)/2;\n\t\tif(s.compare(sa[m],t.length(),t)<0) l=m;\n\t\telse r=m;\n\t\
    }\n\treturn r;\n}\nint hi(int *sa,string& s,string& t){\n\tint N=s.size()+1;\n\
    \tint l=-1,r=N+1;\n\twhile(r-l>1){\n\t\tint m=(r+l)/2;\n\t\tif(s.compare(sa[m],t.length(),t)<=0)\
    \ l=m;\n\t\telse r=m;\n\t}\n\treturn r;\n}\nint main(){\n\tint N,Q,sa[100001];\n\
    \tstring s;\n\tcin>>s>>Q;\n\tN=s.size();\n\tSuffixArray::SA(N,s.c_str(),sa,256);\n\
    \tsegtree seg(N+1);\n\trep(i,N+1){\n\t\tseg.add(sa[i],i);\n\t}\n\trep(tt,Q){\n\
    \t\tint l,r;\n\t\tstring t;\n\t\tcin>>l>>r>>t;\n\t\tr++;\n\t\tint K=t.size();\n\
    \t\tif(r-l<K){\n\t\t\tputs(\"0\");\n\t\t\tcontinue;\n\t\t}\n\t\tint ya=lo(sa,s,t);\n\
    \t\tint yb=hi(sa,s,t);\n\t\tif(ya>=yb){\n\t\t\tputs(\"0\");\n\t\t\tcontinue;\n\
    \t\t}\n\t\tcout<<seg.count(l,r-K+1,ya,yb)<<endl;\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: data structure/splay/L.cpp
  requiredBy: []
  timestamp: '2017-05-17 18:25:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/splay/L.cpp
layout: document
redirect_from:
- /library/data structure/splay/L.cpp
- /library/data structure/splay/L.cpp.html
title: data structure/splay/L.cpp
---
