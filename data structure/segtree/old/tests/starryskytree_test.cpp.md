---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - http://code-festival-2015-final-open.contest.atcoder.jp/tasks/codefestival_2015_final_d
  bundledCode: "#line 1 \"data structure/segtree/old/tests/starryskytree_test.cpp\"\
    \n#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define\
    \ rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n#define\
    \ pb push_back\n#define fs first\n#define sc second\n#define show(x) cout << #x\
    \ << \" = \" << x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y) x=max(x,y)\n\
    using namespace std;\n/*\n\trange add,range min\n\thttp://code-festival-2015-final-open.contest.atcoder.jp/tasks/codefestival_2015_final_d\n\
    */\nint inf=1e9;\nstruct starryskytree{\n\tstatic const int N=1<<17;\n\tint mx[N*2],ad[N*2];\n\
    \tstarryskytree(){\n\t\trep(i,N*2) mx[i]=0,ad[i]=0;\n\t}\n\tvoid add(int a,int\
    \ b,int v,int l=0,int r=N,int k=1){\n\t\tif(b<=l||r<=a) return;\n\t\tif(a<=l&&r<=b){\n\
    \t\t\tad[k]+=v;\n\t\t\treturn;\n\t\t}\n\t\tadd(a,b,v,l,(l+r)/2,k*2);\n\t\tadd(a,b,v,(l+r)/2,r,k*2+1);\n\
    \t\tmx[k]=max(mx[k*2]+ad[k*2],mx[k*2+1]+ad[k*2+1]);\n\t}\n\tint getmax(int a,int\
    \ b,int l=0,int r=N,int k=1){\n\t\tif(b<=l||r<=a) return 0;\n\t\tif(a<=l&&r<=b)\
    \ return mx[k]+ad[k];\n\t\treturn ad[k]+max(getmax(a,b,l,(l+r)/2,k*2),getmax(a,b,(l+r)/2,r,k*2+1));\n\
    \t}\n}seg;\nint a[100000],b[100000];\nint main(){\n\tint N;\n\tcin>>N;\n\trep(i,N){\n\
    \t\tcin>>a[i]>>b[i];\n\t\tseg.add(a[i],b[i],1);\n\t}\n\tint ans=N-1;\n\trep(i,N){\n\
    \t\tseg.add(a[i],b[i],-1);\n\t\tint tmp=seg.getmax(0,seg.N);\n\t\tchmin(ans,tmp);\n\
    \t\tseg.add(a[i],b[i],1);\n\t}\n\tcout<<ans<<endl;\n}\n"
  code: "#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define show(x) cout\
    \ << #x << \" = \" << x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y)\
    \ x=max(x,y)\nusing namespace std;\n/*\n\trange add,range min\n\thttp://code-festival-2015-final-open.contest.atcoder.jp/tasks/codefestival_2015_final_d\n\
    */\nint inf=1e9;\nstruct starryskytree{\n\tstatic const int N=1<<17;\n\tint mx[N*2],ad[N*2];\n\
    \tstarryskytree(){\n\t\trep(i,N*2) mx[i]=0,ad[i]=0;\n\t}\n\tvoid add(int a,int\
    \ b,int v,int l=0,int r=N,int k=1){\n\t\tif(b<=l||r<=a) return;\n\t\tif(a<=l&&r<=b){\n\
    \t\t\tad[k]+=v;\n\t\t\treturn;\n\t\t}\n\t\tadd(a,b,v,l,(l+r)/2,k*2);\n\t\tadd(a,b,v,(l+r)/2,r,k*2+1);\n\
    \t\tmx[k]=max(mx[k*2]+ad[k*2],mx[k*2+1]+ad[k*2+1]);\n\t}\n\tint getmax(int a,int\
    \ b,int l=0,int r=N,int k=1){\n\t\tif(b<=l||r<=a) return 0;\n\t\tif(a<=l&&r<=b)\
    \ return mx[k]+ad[k];\n\t\treturn ad[k]+max(getmax(a,b,l,(l+r)/2,k*2),getmax(a,b,(l+r)/2,r,k*2+1));\n\
    \t}\n}seg;\nint a[100000],b[100000];\nint main(){\n\tint N;\n\tcin>>N;\n\trep(i,N){\n\
    \t\tcin>>a[i]>>b[i];\n\t\tseg.add(a[i],b[i],1);\n\t}\n\tint ans=N-1;\n\trep(i,N){\n\
    \t\tseg.add(a[i],b[i],-1);\n\t\tint tmp=seg.getmax(0,seg.N);\n\t\tchmin(ans,tmp);\n\
    \t\tseg.add(a[i],b[i],1);\n\t}\n\tcout<<ans<<endl;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: data structure/segtree/old/tests/starryskytree_test.cpp
  requiredBy: []
  timestamp: '2017-04-22 20:47:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data structure/segtree/old/tests/starryskytree_test.cpp
layout: document
redirect_from:
- /library/data structure/segtree/old/tests/starryskytree_test.cpp
- /library/data structure/segtree/old/tests/starryskytree_test.cpp.html
title: data structure/segtree/old/tests/starryskytree_test.cpp
---
