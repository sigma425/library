---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - "http://code-festival-2015-final-open.contest.atcoder.jp/tasks/codefestival_2015_final_d(\u8DB3\
      \u30B2\u30FC\u30E0II)"
  bundledCode: "#line 1 \"data structure/segtree/starryskytree.cpp\"\n/*\n\trange\
    \ add,range min\n//\tverified by http://code-festival-2015-final-open.contest.atcoder.jp/tasks/codefestival_2015_final_d(\u8DB3\
    \u30B2\u30FC\u30E0II)\n\tStarry Sky\n\n\tleftmostnegativeid()\u3068\u304B\u4F7F\
    \u3044\u305F\u3044\u308F\u3051\u3067\u306F\u306A\u3044\u9650\u308A\u3042\u307E\
    \u308A\u3053\u308C\u4F7F\u3044\u305F\u304F\u306A\u3044\u306A\u3042\n*/\nstruct\
    \ starryskytree{\n\tint N;\n\tusing D = ll;\n\tD id_ = 1e17;\t\t//initialize\t\
    !!\u3053\u306E\u3042\u3068add\u30AF\u30A8\u30EA\u304C\u304D\u3066\u3082id\u3092\
    \u8D85\u3048\u306A\u3044\u3088\u3046\u306B\u3059\u308B!!\n\tD id  = 1e18;\t\t\
    //id\n\tvector<D> mn,ad;\n\tstarryskytree(){}\n\tstarryskytree(int n){\n\t\tN=1;\n\
    \t\twhile(N<n) N*=2;\n\t\tmn.assign(N*2,id_);\n\t\tad.assign(N*2,0);\n\t}\n\t\
    starryskytree(vector<D>& vc){\n\t\tint n = vc.size();\n\t\tN=1;\n\t\twhile(N<n)\
    \ N*=2;\n\t\tmn.assign(N*2,id_);\n\t\tad.assign(N*2,0);\n\t\trep(i,n) mn[i+N]=vc[i];\n\
    \t\tfor(int i=N-1;i>0;i--) mn[i]=min(mn[i*2],mn[i*2+1]);\n\t}\n\tvoid add(int\
    \ a,int b,D v){\n\t\tadd(a,b,0,N,1,v);\n\t}\n\tvoid add(int a,int b,int l,int\
    \ r,int k,D v){\n\t\tif(b<=l||r<=a) return;\n\t\tif(a<=l&&r<=b){\n\t\t\tad[k]+=v;\n\
    \t\t\treturn;\n\t\t}\n\t\tadd(a,b,l,(l+r)/2,k*2,v);\n\t\tadd(a,b,(l+r)/2,r,k*2+1,v);\n\
    \t\tmn[k]=min(mn[k*2]+ad[k*2],mn[k*2+1]+ad[k*2+1]);\n\t}\n\tD getmin(int a,int\
    \ b){\n\t\treturn getmin(a,b,0,N,1);\n\t}\n\tD getmin(int a,int b,int l,int r,int\
    \ k){\n\t\tif(b<=l||r<=a) return id;\n\t\tif(a<=l&&r<=b) return mn[k]+ad[k];\n\
    \t\treturn ad[k]+min(getmin(a,b,l,(l+r)/2,k*2),getmin(a,b,(l+r)/2,r,k*2+1));\n\
    \t}\n\tvoid assign(int x,ll v){\n\t\tadd(x,x+1,v-getmin(x,x+1));\n\t}\n\tvoid\
    \ changemin(int x,ll v){\n\t\tD dif = v - getmin(x,x+1);\n\t\tif(dif<0) add(x,x+1,dif);\n\
    \t}\n\n\tbool hasnegative(int k,D acm){return acm+mn[k]+ad[k]<0;}\n\tint leftmostnegativeid(){\n\
    \t\tD acm = 0;\n\t\tif(!hasnegative(1,acm)) return N;\n\t\tint k = 1;\n\t\twhile(k<N){\n\
    \t\t\tacm += ad[k];\n\t\t\tif(hasnegative(k*2,acm)) k=k*2;\n\t\t\telse k=k*2+1;\n\
    \t\t}\n\t\treturn k-N;\n\t}\n\n};\n"
  code: "/*\n\trange add,range min\n//\tverified by http://code-festival-2015-final-open.contest.atcoder.jp/tasks/codefestival_2015_final_d(\u8DB3\
    \u30B2\u30FC\u30E0II)\n\tStarry Sky\n\n\tleftmostnegativeid()\u3068\u304B\u4F7F\
    \u3044\u305F\u3044\u308F\u3051\u3067\u306F\u306A\u3044\u9650\u308A\u3042\u307E\
    \u308A\u3053\u308C\u4F7F\u3044\u305F\u304F\u306A\u3044\u306A\u3042\n*/\nstruct\
    \ starryskytree{\n\tint N;\n\tusing D = ll;\n\tD id_ = 1e17;\t\t//initialize\t\
    !!\u3053\u306E\u3042\u3068add\u30AF\u30A8\u30EA\u304C\u304D\u3066\u3082id\u3092\
    \u8D85\u3048\u306A\u3044\u3088\u3046\u306B\u3059\u308B!!\n\tD id  = 1e18;\t\t\
    //id\n\tvector<D> mn,ad;\n\tstarryskytree(){}\n\tstarryskytree(int n){\n\t\tN=1;\n\
    \t\twhile(N<n) N*=2;\n\t\tmn.assign(N*2,id_);\n\t\tad.assign(N*2,0);\n\t}\n\t\
    starryskytree(vector<D>& vc){\n\t\tint n = vc.size();\n\t\tN=1;\n\t\twhile(N<n)\
    \ N*=2;\n\t\tmn.assign(N*2,id_);\n\t\tad.assign(N*2,0);\n\t\trep(i,n) mn[i+N]=vc[i];\n\
    \t\tfor(int i=N-1;i>0;i--) mn[i]=min(mn[i*2],mn[i*2+1]);\n\t}\n\tvoid add(int\
    \ a,int b,D v){\n\t\tadd(a,b,0,N,1,v);\n\t}\n\tvoid add(int a,int b,int l,int\
    \ r,int k,D v){\n\t\tif(b<=l||r<=a) return;\n\t\tif(a<=l&&r<=b){\n\t\t\tad[k]+=v;\n\
    \t\t\treturn;\n\t\t}\n\t\tadd(a,b,l,(l+r)/2,k*2,v);\n\t\tadd(a,b,(l+r)/2,r,k*2+1,v);\n\
    \t\tmn[k]=min(mn[k*2]+ad[k*2],mn[k*2+1]+ad[k*2+1]);\n\t}\n\tD getmin(int a,int\
    \ b){\n\t\treturn getmin(a,b,0,N,1);\n\t}\n\tD getmin(int a,int b,int l,int r,int\
    \ k){\n\t\tif(b<=l||r<=a) return id;\n\t\tif(a<=l&&r<=b) return mn[k]+ad[k];\n\
    \t\treturn ad[k]+min(getmin(a,b,l,(l+r)/2,k*2),getmin(a,b,(l+r)/2,r,k*2+1));\n\
    \t}\n\tvoid assign(int x,ll v){\n\t\tadd(x,x+1,v-getmin(x,x+1));\n\t}\n\tvoid\
    \ changemin(int x,ll v){\n\t\tD dif = v - getmin(x,x+1);\n\t\tif(dif<0) add(x,x+1,dif);\n\
    \t}\n\n\tbool hasnegative(int k,D acm){return acm+mn[k]+ad[k]<0;}\n\tint leftmostnegativeid(){\n\
    \t\tD acm = 0;\n\t\tif(!hasnegative(1,acm)) return N;\n\t\tint k = 1;\n\t\twhile(k<N){\n\
    \t\t\tacm += ad[k];\n\t\t\tif(hasnegative(k*2,acm)) k=k*2;\n\t\t\telse k=k*2+1;\n\
    \t\t}\n\t\treturn k-N;\n\t}\n\n};"
  dependsOn: []
  isVerificationFile: false
  path: data structure/segtree/starryskytree.cpp
  requiredBy: []
  timestamp: '2017-05-02 18:49:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/segtree/starryskytree.cpp
layout: document
redirect_from:
- /library/data structure/segtree/starryskytree.cpp
- /library/data structure/segtree/starryskytree.cpp.html
title: data structure/segtree/starryskytree.cpp
---
