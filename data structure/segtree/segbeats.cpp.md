---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_oj/beats/point_add_range_sum.test.cpp
    title: test_oj/beats/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_oj/beats/point_set_range_composite.test.cpp
    title: test_oj/beats/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_oj/beats/range_affine_range_sum.test.cpp
    title: test_oj/beats/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_oj/beats/range_chmin_chmax_add_range_sum.test.cpp
    title: test_oj/beats/range_chmin_chmax_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_oj/beats/simple_min.test.cpp
    title: test_oj/beats/simple_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_oj/beats/simple_sum.test.cpp
    title: test_oj/beats/simple_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/acl2/submissions/16994422
    - https://codeforces.com/contest/1037/submission/61831108
    - https://sigma425.github.io/library/data%20structure/segtree/segbeats.cpp
    - https://sigma425.github.io/library/test_oj/beats/range_affine_range_sum.test.cpp
    - https://yukicoder.me/submissions/386293
  bundledCode: "#line 1 \"data structure/segtree/segbeats.cpp\"\n/*\r\n\t\uFF01\uFF01\
    \uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\u96F0\u56F2\u6C17\u3067\u95A2\
    \u6570\u3092\u66F8\u304F\u306A\uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\
    \uFF01\uFF01\r\n\tlazy\u306A\u3089\u95A2\u6570\u306E\u5408\u6210\u3092\u3059\u308B\
    \u3053\u3068\u306F\u7D76\u5BFE\u5FC5\u8981 \u3061\u3083\u3093\u3068 \"\u30E2\u30CE\
    \u30A4\u30C9\u3068\u4F5C\u7528\u3092\u5206\u3051\u3066\" \"\u5404\u6F14\u7B97\u3092\
    \u8003\u3048\u308B\" \u3053\u3068\u306F\u5FC5\u305A\u5FC5\u8981\r\n\t\u3053\u306E\
    \u30E9\u30A4\u30D6\u30E9\u30EA\u3060\u3068\u76F4\u63A5\u305D\u3046\u3044\u3046\
    \u578B\u3092\u6301\u3063\u3066\u308B\u308F\u3051\u3058\u3083\u306A\u3044\u304B\
    \u3089\u306A\u3093\u304B\u3044\u3044\u611F\u3058\u306B\u304B\u3051\u3066\u3057\
    \u307E\u3046\u3053\u3068\u304C\u3042\u308B\u3051\u3069\u3001\u305D\u308C\u306F\
    \u9593\u9055\u3063\u3066\u308B\u304B\u3089\u3061\u3083\u3093\u3068\u9589\u3058\
    \u305F\u6F14\u7B97\u3092\u304B\u3051\r\n\t\u7279\u306B\u3001\u8907\u96D1\u306A\
    \u5834\u5408\u306F\u3082\u3046\u578B\u3092\u4F5C\u3063\u3066\u3057\u307E\u3046\
    (segtree_lazy) \u65B9\u304C\u3044\u3044\u30B1\u30FC\u30B9\u304C\u591A\u3005\u3042\
    \u308B\r\n\r\n\t\u95A2\u6570\u9069\u7528\u306E\u9589\u3058\u305F\u5F62\u3092\u4F5C\
    \u3089\u306A\u304D\u3083\u3044\u3051\u306A\u3044\u306E\u306F\u5927\u524D\u63D0\
    \u3067\u3001\u305D\u306E\u4E0A\u3067\u3044\u3061\u3044\u3061\uFF08\u547C\u3073\
    \u51FA\u3057\u5074\u304C\uFF09\u9069\u7528\u3057\u305F\u3044\u95A2\u6570\u3092\
    \u305D\u306E\u578B\u3067\u66F8\u304F\u306E\u304C\u9762\u5012\u3060\u304B\u3089\
    \u3053\u3046\u3044\u3046\u3075\u3046\u306B\u306A\u3063\u3066\u308B\u306E\u3067\
    \u3042\u3063\u3066\r\n\t\u5408\u6210\u3092\u8003\u3048\u305A\u306B(lz\u3092\u306A\
    \u3093\u304B\u9069\u7528\u3057\u305F\u7D50\u679C\u306E\u30E2\u30CE\u30A4\u30C9\
    \u306E\u4E00\u90E8\u307F\u305F\u3044\u306B)\u6271\u3063\u3066\u3044\u3044\u308F\
    \u3051\u3067\u306F\u306A\u3044\r\n\r\n\t\u3061\u306A\u307F\u306B\u70B9\u66F4\u65B0\
    \u306E\u95A2\u6570\u306F\u2191\u306E\u9589\u3058\u305F\u5F62\u306B\u306F\u542B\
    \u3081\u306A\u304F\u3066\u826F\u3044\u3001\u305D\u308C\u306Flz\u3067\u306F\u306A\
    \u304F\u5024\u3092\u76F4\u63A5\u3044\u3058\u308C\u3070\u3044\u3044\u304B\u3089\
    \u3002\u7279\u306B ch(i,i+1,&D::hoge) \u4F7F\u3063\u3066\u3044\u3044\r\n\r\n\t\
    \u982D\u3092\u58CA\u3057\u3066\u3057\u307E\u3063\u305F\u4F8B: https://atcoder.jp/contests/acl2/submissions/16994422\r\
    \n\r\n\tverify: https://sigma425.github.io/library/data%20structure/segtree/segbeats.cpp\r\
    \n\r\n\t\u305F\u3060\u306Elazy\u3067\u4F7F\u3044\u65B9\u5FD8\u308C\u304C\u3061\
    \ \u2192 https://sigma425.github.io/library/test_oj/beats/range_affine_range_sum.test.cpp\r\
    \n*/\r\n\r\n/*\r\n\tsimple,lazy,beats \u3069\u308C\u3082\u3053\u308C\u3067\u66F8\
    \u3051\u308B\r\n\r\n\t\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF:\r\n\t\tsegbeats(n)\r\
    \n\t\tsegbeats(vec) \u578B\u304C\u9055\u3063\u3066\u3082\u30AD\u30E3\u30B9\u30C8\
    \u3067\u304D\u308C\u3070OK\r\n\r\n\tchange \u30AF\u30A8\u30EA:\r\n\t\tseg.ch(l,r,&D::set,x)\r\
    \n\r\n\tget \u30AF\u30A8\u30EA:\r\n\t\tseg.get(l,r,&D::getsum,[](ll x,ll y){return\
    \ x+y;},0LL)\r\n\t\t\u578B\u3057\u3063\u304B\u308A\u304B\u304B\u306A\u3044\u3068\
    \u6012\u3089\u308C\u308B\u306E\u3067\u6CE8\u610F\r\n\r\n\tfindl \u30AF\u30A8\u30EA\
    :\r\n\r\n\r\n\t\u6CE8\u610F:\r\n\t\tpoint \u30AF\u30A8\u30EA\u3082 range \u3068\
    \u5168\u304F\u540C\u3058\u3088\u3046\u306B\u66F8\u3044\u3066\u3044\u3044\u3001\
    \u3069\u3046\u305B\u5916\u304B\u3089 (i,i+1) \u3067\u3057\u304B\u547C\u3070\u306A\
    \u3044\u306A\u3089\u95A2\u6570\u304C\u9069\u7528\u3055\u308C\u308B\u306E\u3082\
    \u30B5\u30A4\u30BA1\u306E\u30CE\u30FC\u30C9\u3060\u3051\u3060\u304B\u3089\u3001\
    \u597D\u304D\u52DD\u624B\u3084\u3063\u3066\u3044\u3044\r\n\r\n\r\n\tstruct D{\r\
    \n\t\t\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF:\r\n\t\t\tD() \u304C\u5358\u4F4D\
    \u5143\u306B\u306A\u308B\u5FC5\u8981\u304C\u3042\u308B\r\n\r\n\t\tmerge(l,r):\r\
    \n\t\t\tl,r\u306Elazy\u7CFB\u306Fid\u3060\u3068\u4EEE\u5B9A\u3057\u3066\u826F\u3044\
    \r\n\t\t\r\n\t\tpush(x,y):\r\n\t\t\tthis -> x\r\n\t\t\tthis -> y\r\n\t\t\tthis_lazy.clear()\r\
    \n\t\t\tlazy\u3092\u304B\u3051\u305F\u30BF\u30A4\u30DF\u30F3\u30B0\u3067val\u3092\
    \u6B63\u3057\u3044\u5024\u306B\u5909\u3048\u308B\r\n\r\n\t\tch\u7CFB:\r\n\t\t\t\
    bool set(int x) \u3068\u304B\r\n\t\t\tearly return \u3057\u3066\u3044\u3044\u306A\
    \u3089 true\r\n\t\t\t\u3064\u307E\u308Abeats\u3058\u3083\u306A\u3051\u308C\u3070\
    \u5168\u90E8true\r\n\t\t\r\n\t\tget\u7CFB:\r\n\t\t\t\u53D6\u308A\u51FA\u3057\u305F\
    \u3044\u60C5\u5831\u3092\u53D6\u308A\u51FA\u3059\u3060\u3051\r\n\r\n\t\tfind\u7CFB\
    :\r\n\t\t\t\u3053\u306E\u30CE\u30FC\u30C9\u5185\u306B\u3042\u308B \u2192 true\r\
    \n\t}\r\n\r\n\tbeats: https://yukicoder.me/submissions/386293\r\n\tfindl: https://codeforces.com/contest/1037/submission/61831108\r\
    \n*/\r\n\r\ntemplate<class N>\r\nstruct segbeats{\r\n\tV<N> x;\r\n\tint s;\r\n\
    \r\n\tsegbeats(int n){\r\n\t\ts = 1;\r\n\t\twhile(s<n) s *= 2;\r\n\t\tx.resize(s*2);\r\
    \n\t\tfor(int i=s-1;i>0;i--) upd(i);\r\n\t}\r\n\ttemplate<class T>\r\n\tsegbeats(const\
    \ V<T>& a){\r\n\t\tint n = a.size();\r\n\t\ts = 1;\r\n\t\twhile(s<n) s *= 2;\r\
    \n\t\tx.resize(s*2);\r\n\t\trep(i,n) x[s+i] = N(a[i]);\r\n\t\tfor(int i=s-1;i>0;i--)\
    \ upd(i);\r\n\t}\r\n\r\n\ttemplate<class F,class... Args>\r\n\tvoid ch(int a,int\
    \ b,F f,Args... args){\r\n\t\tch_(a,b,0,s,1,f,args...);\r\n\t}\r\n\r\n\ttemplate<class\
    \ F,class G,class H>\r\n\tauto get(int a,int b,F f,G g,H h){\r\n\t\treturn get_(a,b,0,s,1,f,g,h);\r\
    \n\t}\r\n\r\n\tN getNode(int a,int b){\r\n\t\treturn getNode_(a,b,0,s,1);\r\n\t\
    }\r\n\r\n\ttemplate<class F,class... Args>\r\n\tpair<int,N> findl(int a,int b,F\
    \ f,Args&... args){\r\n\t\treturn findl_(a,b,0,s,1,f,args...);\r\n\t}\r\n\r\n\t\
    private:\r\n\r\n\tvoid push(int i){\r\n\t\tx[i].push(x[i*2],x[i*2+1]);\r\n\t}\r\
    \n\tvoid upd(int i){\r\n\t\tx[i] = N::merge(x[i*2],x[i*2+1]);\r\n\t}\r\n\r\n\t\
    template<class F,class... Args>\r\n\tvoid ch_(int a,int b,int l,int r,int i,F\
    \ f,Args... args){\r\n\t\tif(b<=l || r<=a){\r\n\t\t\treturn;\r\n\t\t}\r\n\t\t\
    if(a<=l && r<=b && (x[i].*f)(args...)){    //f : put_tag, early_break\r\n\t\t\t\
    return;\r\n\t\t}\r\n\t\tpush(i);\r\n\t\tint m = (l+r)/2;\r\n\t\tch_(a,b,l,m,i*2\
    \  ,f,args...);\r\n\t\tch_(a,b,m,r,i*2+1,f,args...);\r\n\t\tupd(i);\r\n\t}\r\n\
    \ttemplate<class F,class G,class H>\r\n\tauto get_(int a,int b,int l,int r,int\
    \ i,F f,G g,H h){\r\n\t\tif(b<=l || r<=a){\r\n\t\t\treturn h;\r\n\t\t}\r\n\t\t\
    if(a<=l && r<=b){\r\n\t\t\treturn (x[i].*f)();\r\n\t\t}\r\n\t\tpush(i);\r\n\t\t\
    int m = (l+r)/2;\r\n\t\treturn g(get_(a,b,l,m,i*2,f,g,h),get_(a,b,m,r,i*2+1,f,g,h));\r\
    \n\t}\r\n\tN getNode_(int a,int b,int l,int r,int i){\r\n\t\tif(b<=l || r<=a){\r\
    \n\t\t\treturn N();\r\n\t\t}\r\n\t\tif(a<=l && r<=b){\r\n\t\t\treturn x[i];\r\n\
    \t\t}\r\n\t\tpush(i);\r\n\t\tint m = (l+r)/2;\r\n\t\treturn N::merge(getNode_(a,b,l,m,i*2),getNode_(a,b,m,r,i*2+1));\r\
    \n\t}\r\n\ttemplate<class F,class... Args>\r\n\tpair<int,N> findl_(int a,int b,int\
    \ l,int r,int i,F f,Args&... args){\r\n\t\tif(b<=l || r<=a){\r\n\t\t\treturn {b,N()};\r\
    \n\t\t}\r\n\t\tif(a<=l && r<=b){\r\n\t\t\tif(!(x[i].*f)(args...)) return {b,N()};\r\
    \n\t\t\tif(r-l == 1) return {l,x[i]};\r\n\t\t}\r\n\t\tpush(i);\r\n\t\tint m =\
    \ (l+r)/2;\r\n\t\tauto res = findl_(a,b,l,m,i*2,f,args...);\r\n\t\tif(res.fs <\
    \ b) return res;\r\n\t\treturn findl_(a,b,m,r,i*2+1,f,args...);\r\n\t}\r\n\t//\
    \ template<class F,class... Args>\r\n\t// pair<int,N> findr_(int a,int b,int l,int\
    \ r,int i,F f,Args&... args){\r\n\t// \tif(b<=l || r<=a){\r\n\t// \t\treturn {a-1,N()};\r\
    \n\t// \t}\r\n\t// \tif(a<=l && r<=b){\r\n\t// \t\tif(!(x[i].*f)(args...)) return\
    \ {a-1,N()};\r\n\t// \t\tif(r-l == 1) return {l,x[i]};\r\n\t// \t}\r\n\t// \t\
    push(i);\r\n\t// \tint m = (l+r)/2;\r\n\t// \tauto y = findr_(a,b,m,r,i*2+1,f,args...);\r\
    \n\t// \tif(y.fs >= a) return y;\r\n\t// \treturn findr_(a,b,l,m,i*2,f,args...);\r\
    \n\t// }\r\n\r\n};\r\n\r\n/*\r\n    yukicoder 880\r\n    range x_i = a\r\n   \
    \ range x_i = gcd(x_i,a)\r\n    range max\r\n    range sum\r\n\r\nstruct D{\r\n\
    \tint sz=1;\r\n\tll sm=0,mx=-1;\r\n\tll L=0;\r\n\tD(ll v=1){sm=mx=L=v;}\r\n\t\
    static D merge(D l,D r){\r\n\t\tD z;\r\n\t\tz.sz = l.sz + r.sz;\r\n\t\tz.sm =\
    \ l.sm + r.sm;\r\n\t\tz.mx = max(l.mx,r.mx);\r\n\t\tz.L = lcm(l.L,r.L);\r\n\t\t\
    return z;\r\n\t}\r\n\tvoid push(D& x,D& y){\r\n\t\tif(mx * sz == sm){\r\n\t\t\t\
    x.set(mx);\r\n\t\t\ty.set(mx);\r\n\t\t}\r\n\t}\r\n\tbool set(ll x){\r\n\t\tsm\
    \ = x * sz;\r\n\t\tmx = L = x;\r\n\t\treturn true;\r\n\t}\r\n\tbool gcd(ll x){\r\
    \n\t\tif(x % L == 0) return true;\t// break_condition\r\n\t\tif(mx * sz == sm){\t\
    \t// put_tag_condition\r\n\t\t\tset(__gcd(mx,x));\r\n\t\t\treturn true;\r\n\t\t\
    }\r\n\t\treturn false;\r\n\t}\r\n\tll getmax(){\r\n\t\treturn mx;\r\n\t}\r\n\t\
    ll getsum(){\r\n\t\treturn sm;\r\n\t}\r\n};\r\n\r\n\r\nCF 1037 (Manthan 18) H\r\
    \nstruct D{\r\n\tint x,y,z;\t// min sa, min lcp, min sa+lcp\r\n\tD(int l=inf):x(inf),y(l),z(inf){}\r\
    \n\tstatic D merge(D l,D r){\r\n\t\tD m;\r\n\t\tm.x = min(l.x,r.x);\r\n\t\tm.y\
    \ = min(l.y,r.y);\r\n\t\tm.z = min({l.z,r.z,l.y+r.x});\r\n\t\treturn m;\r\n\t\
    }\r\n\tvoid push(D& x,D& y){\r\n\t}\r\n\tbool set(int v){\r\n\t\tx = v;\r\n\t\t\
    return true;\r\n\t}\r\n\tbool find(int& mn, int r){\r\n\t\tif(z < r) return true;\r\
    \n\t\tif(mn+x < r) return true;\r\n\t\tchmin(mn,y);\r\n\t\treturn false;\r\n\t\
    }\r\n};\r\n\r\n*/\n"
  code: "/*\r\n\t\uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\u96F0\
    \u56F2\u6C17\u3067\u95A2\u6570\u3092\u66F8\u304F\u306A\uFF01\uFF01\uFF01\uFF01\
    \uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\r\n\tlazy\u306A\u3089\u95A2\u6570\u306E\u5408\
    \u6210\u3092\u3059\u308B\u3053\u3068\u306F\u7D76\u5BFE\u5FC5\u8981 \u3061\u3083\
    \u3093\u3068 \"\u30E2\u30CE\u30A4\u30C9\u3068\u4F5C\u7528\u3092\u5206\u3051\u3066\
    \" \"\u5404\u6F14\u7B97\u3092\u8003\u3048\u308B\" \u3053\u3068\u306F\u5FC5\u305A\
    \u5FC5\u8981\r\n\t\u3053\u306E\u30E9\u30A4\u30D6\u30E9\u30EA\u3060\u3068\u76F4\
    \u63A5\u305D\u3046\u3044\u3046\u578B\u3092\u6301\u3063\u3066\u308B\u308F\u3051\
    \u3058\u3083\u306A\u3044\u304B\u3089\u306A\u3093\u304B\u3044\u3044\u611F\u3058\
    \u306B\u304B\u3051\u3066\u3057\u307E\u3046\u3053\u3068\u304C\u3042\u308B\u3051\
    \u3069\u3001\u305D\u308C\u306F\u9593\u9055\u3063\u3066\u308B\u304B\u3089\u3061\
    \u3083\u3093\u3068\u9589\u3058\u305F\u6F14\u7B97\u3092\u304B\u3051\r\n\t\u7279\
    \u306B\u3001\u8907\u96D1\u306A\u5834\u5408\u306F\u3082\u3046\u578B\u3092\u4F5C\
    \u3063\u3066\u3057\u307E\u3046(segtree_lazy) \u65B9\u304C\u3044\u3044\u30B1\u30FC\
    \u30B9\u304C\u591A\u3005\u3042\u308B\r\n\r\n\t\u95A2\u6570\u9069\u7528\u306E\u9589\
    \u3058\u305F\u5F62\u3092\u4F5C\u3089\u306A\u304D\u3083\u3044\u3051\u306A\u3044\
    \u306E\u306F\u5927\u524D\u63D0\u3067\u3001\u305D\u306E\u4E0A\u3067\u3044\u3061\
    \u3044\u3061\uFF08\u547C\u3073\u51FA\u3057\u5074\u304C\uFF09\u9069\u7528\u3057\
    \u305F\u3044\u95A2\u6570\u3092\u305D\u306E\u578B\u3067\u66F8\u304F\u306E\u304C\
    \u9762\u5012\u3060\u304B\u3089\u3053\u3046\u3044\u3046\u3075\u3046\u306B\u306A\
    \u3063\u3066\u308B\u306E\u3067\u3042\u3063\u3066\r\n\t\u5408\u6210\u3092\u8003\
    \u3048\u305A\u306B(lz\u3092\u306A\u3093\u304B\u9069\u7528\u3057\u305F\u7D50\u679C\
    \u306E\u30E2\u30CE\u30A4\u30C9\u306E\u4E00\u90E8\u307F\u305F\u3044\u306B)\u6271\
    \u3063\u3066\u3044\u3044\u308F\u3051\u3067\u306F\u306A\u3044\r\n\r\n\t\u3061\u306A\
    \u307F\u306B\u70B9\u66F4\u65B0\u306E\u95A2\u6570\u306F\u2191\u306E\u9589\u3058\
    \u305F\u5F62\u306B\u306F\u542B\u3081\u306A\u304F\u3066\u826F\u3044\u3001\u305D\
    \u308C\u306Flz\u3067\u306F\u306A\u304F\u5024\u3092\u76F4\u63A5\u3044\u3058\u308C\
    \u3070\u3044\u3044\u304B\u3089\u3002\u7279\u306B ch(i,i+1,&D::hoge) \u4F7F\u3063\
    \u3066\u3044\u3044\r\n\r\n\t\u982D\u3092\u58CA\u3057\u3066\u3057\u307E\u3063\u305F\
    \u4F8B: https://atcoder.jp/contests/acl2/submissions/16994422\r\n\r\n\tverify:\
    \ https://sigma425.github.io/library/data%20structure/segtree/segbeats.cpp\r\n\
    \r\n\t\u305F\u3060\u306Elazy\u3067\u4F7F\u3044\u65B9\u5FD8\u308C\u304C\u3061 \u2192\
    \ https://sigma425.github.io/library/test_oj/beats/range_affine_range_sum.test.cpp\r\
    \n*/\r\n\r\n/*\r\n\tsimple,lazy,beats \u3069\u308C\u3082\u3053\u308C\u3067\u66F8\
    \u3051\u308B\r\n\r\n\t\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF:\r\n\t\tsegbeats(n)\r\
    \n\t\tsegbeats(vec) \u578B\u304C\u9055\u3063\u3066\u3082\u30AD\u30E3\u30B9\u30C8\
    \u3067\u304D\u308C\u3070OK\r\n\r\n\tchange \u30AF\u30A8\u30EA:\r\n\t\tseg.ch(l,r,&D::set,x)\r\
    \n\r\n\tget \u30AF\u30A8\u30EA:\r\n\t\tseg.get(l,r,&D::getsum,[](ll x,ll y){return\
    \ x+y;},0LL)\r\n\t\t\u578B\u3057\u3063\u304B\u308A\u304B\u304B\u306A\u3044\u3068\
    \u6012\u3089\u308C\u308B\u306E\u3067\u6CE8\u610F\r\n\r\n\tfindl \u30AF\u30A8\u30EA\
    :\r\n\r\n\r\n\t\u6CE8\u610F:\r\n\t\tpoint \u30AF\u30A8\u30EA\u3082 range \u3068\
    \u5168\u304F\u540C\u3058\u3088\u3046\u306B\u66F8\u3044\u3066\u3044\u3044\u3001\
    \u3069\u3046\u305B\u5916\u304B\u3089 (i,i+1) \u3067\u3057\u304B\u547C\u3070\u306A\
    \u3044\u306A\u3089\u95A2\u6570\u304C\u9069\u7528\u3055\u308C\u308B\u306E\u3082\
    \u30B5\u30A4\u30BA1\u306E\u30CE\u30FC\u30C9\u3060\u3051\u3060\u304B\u3089\u3001\
    \u597D\u304D\u52DD\u624B\u3084\u3063\u3066\u3044\u3044\r\n\r\n\r\n\tstruct D{\r\
    \n\t\t\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF:\r\n\t\t\tD() \u304C\u5358\u4F4D\
    \u5143\u306B\u306A\u308B\u5FC5\u8981\u304C\u3042\u308B\r\n\r\n\t\tmerge(l,r):\r\
    \n\t\t\tl,r\u306Elazy\u7CFB\u306Fid\u3060\u3068\u4EEE\u5B9A\u3057\u3066\u826F\u3044\
    \r\n\t\t\r\n\t\tpush(x,y):\r\n\t\t\tthis -> x\r\n\t\t\tthis -> y\r\n\t\t\tthis_lazy.clear()\r\
    \n\t\t\tlazy\u3092\u304B\u3051\u305F\u30BF\u30A4\u30DF\u30F3\u30B0\u3067val\u3092\
    \u6B63\u3057\u3044\u5024\u306B\u5909\u3048\u308B\r\n\r\n\t\tch\u7CFB:\r\n\t\t\t\
    bool set(int x) \u3068\u304B\r\n\t\t\tearly return \u3057\u3066\u3044\u3044\u306A\
    \u3089 true\r\n\t\t\t\u3064\u307E\u308Abeats\u3058\u3083\u306A\u3051\u308C\u3070\
    \u5168\u90E8true\r\n\t\t\r\n\t\tget\u7CFB:\r\n\t\t\t\u53D6\u308A\u51FA\u3057\u305F\
    \u3044\u60C5\u5831\u3092\u53D6\u308A\u51FA\u3059\u3060\u3051\r\n\r\n\t\tfind\u7CFB\
    :\r\n\t\t\t\u3053\u306E\u30CE\u30FC\u30C9\u5185\u306B\u3042\u308B \u2192 true\r\
    \n\t}\r\n\r\n\tbeats: https://yukicoder.me/submissions/386293\r\n\tfindl: https://codeforces.com/contest/1037/submission/61831108\r\
    \n*/\r\n\r\ntemplate<class N>\r\nstruct segbeats{\r\n\tV<N> x;\r\n\tint s;\r\n\
    \r\n\tsegbeats(int n){\r\n\t\ts = 1;\r\n\t\twhile(s<n) s *= 2;\r\n\t\tx.resize(s*2);\r\
    \n\t\tfor(int i=s-1;i>0;i--) upd(i);\r\n\t}\r\n\ttemplate<class T>\r\n\tsegbeats(const\
    \ V<T>& a){\r\n\t\tint n = a.size();\r\n\t\ts = 1;\r\n\t\twhile(s<n) s *= 2;\r\
    \n\t\tx.resize(s*2);\r\n\t\trep(i,n) x[s+i] = N(a[i]);\r\n\t\tfor(int i=s-1;i>0;i--)\
    \ upd(i);\r\n\t}\r\n\r\n\ttemplate<class F,class... Args>\r\n\tvoid ch(int a,int\
    \ b,F f,Args... args){\r\n\t\tch_(a,b,0,s,1,f,args...);\r\n\t}\r\n\r\n\ttemplate<class\
    \ F,class G,class H>\r\n\tauto get(int a,int b,F f,G g,H h){\r\n\t\treturn get_(a,b,0,s,1,f,g,h);\r\
    \n\t}\r\n\r\n\tN getNode(int a,int b){\r\n\t\treturn getNode_(a,b,0,s,1);\r\n\t\
    }\r\n\r\n\ttemplate<class F,class... Args>\r\n\tpair<int,N> findl(int a,int b,F\
    \ f,Args&... args){\r\n\t\treturn findl_(a,b,0,s,1,f,args...);\r\n\t}\r\n\r\n\t\
    private:\r\n\r\n\tvoid push(int i){\r\n\t\tx[i].push(x[i*2],x[i*2+1]);\r\n\t}\r\
    \n\tvoid upd(int i){\r\n\t\tx[i] = N::merge(x[i*2],x[i*2+1]);\r\n\t}\r\n\r\n\t\
    template<class F,class... Args>\r\n\tvoid ch_(int a,int b,int l,int r,int i,F\
    \ f,Args... args){\r\n\t\tif(b<=l || r<=a){\r\n\t\t\treturn;\r\n\t\t}\r\n\t\t\
    if(a<=l && r<=b && (x[i].*f)(args...)){    //f : put_tag, early_break\r\n\t\t\t\
    return;\r\n\t\t}\r\n\t\tpush(i);\r\n\t\tint m = (l+r)/2;\r\n\t\tch_(a,b,l,m,i*2\
    \  ,f,args...);\r\n\t\tch_(a,b,m,r,i*2+1,f,args...);\r\n\t\tupd(i);\r\n\t}\r\n\
    \ttemplate<class F,class G,class H>\r\n\tauto get_(int a,int b,int l,int r,int\
    \ i,F f,G g,H h){\r\n\t\tif(b<=l || r<=a){\r\n\t\t\treturn h;\r\n\t\t}\r\n\t\t\
    if(a<=l && r<=b){\r\n\t\t\treturn (x[i].*f)();\r\n\t\t}\r\n\t\tpush(i);\r\n\t\t\
    int m = (l+r)/2;\r\n\t\treturn g(get_(a,b,l,m,i*2,f,g,h),get_(a,b,m,r,i*2+1,f,g,h));\r\
    \n\t}\r\n\tN getNode_(int a,int b,int l,int r,int i){\r\n\t\tif(b<=l || r<=a){\r\
    \n\t\t\treturn N();\r\n\t\t}\r\n\t\tif(a<=l && r<=b){\r\n\t\t\treturn x[i];\r\n\
    \t\t}\r\n\t\tpush(i);\r\n\t\tint m = (l+r)/2;\r\n\t\treturn N::merge(getNode_(a,b,l,m,i*2),getNode_(a,b,m,r,i*2+1));\r\
    \n\t}\r\n\ttemplate<class F,class... Args>\r\n\tpair<int,N> findl_(int a,int b,int\
    \ l,int r,int i,F f,Args&... args){\r\n\t\tif(b<=l || r<=a){\r\n\t\t\treturn {b,N()};\r\
    \n\t\t}\r\n\t\tif(a<=l && r<=b){\r\n\t\t\tif(!(x[i].*f)(args...)) return {b,N()};\r\
    \n\t\t\tif(r-l == 1) return {l,x[i]};\r\n\t\t}\r\n\t\tpush(i);\r\n\t\tint m =\
    \ (l+r)/2;\r\n\t\tauto res = findl_(a,b,l,m,i*2,f,args...);\r\n\t\tif(res.fs <\
    \ b) return res;\r\n\t\treturn findl_(a,b,m,r,i*2+1,f,args...);\r\n\t}\r\n\t//\
    \ template<class F,class... Args>\r\n\t// pair<int,N> findr_(int a,int b,int l,int\
    \ r,int i,F f,Args&... args){\r\n\t// \tif(b<=l || r<=a){\r\n\t// \t\treturn {a-1,N()};\r\
    \n\t// \t}\r\n\t// \tif(a<=l && r<=b){\r\n\t// \t\tif(!(x[i].*f)(args...)) return\
    \ {a-1,N()};\r\n\t// \t\tif(r-l == 1) return {l,x[i]};\r\n\t// \t}\r\n\t// \t\
    push(i);\r\n\t// \tint m = (l+r)/2;\r\n\t// \tauto y = findr_(a,b,m,r,i*2+1,f,args...);\r\
    \n\t// \tif(y.fs >= a) return y;\r\n\t// \treturn findr_(a,b,l,m,i*2,f,args...);\r\
    \n\t// }\r\n\r\n};\r\n\r\n/*\r\n    yukicoder 880\r\n    range x_i = a\r\n   \
    \ range x_i = gcd(x_i,a)\r\n    range max\r\n    range sum\r\n\r\nstruct D{\r\n\
    \tint sz=1;\r\n\tll sm=0,mx=-1;\r\n\tll L=0;\r\n\tD(ll v=1){sm=mx=L=v;}\r\n\t\
    static D merge(D l,D r){\r\n\t\tD z;\r\n\t\tz.sz = l.sz + r.sz;\r\n\t\tz.sm =\
    \ l.sm + r.sm;\r\n\t\tz.mx = max(l.mx,r.mx);\r\n\t\tz.L = lcm(l.L,r.L);\r\n\t\t\
    return z;\r\n\t}\r\n\tvoid push(D& x,D& y){\r\n\t\tif(mx * sz == sm){\r\n\t\t\t\
    x.set(mx);\r\n\t\t\ty.set(mx);\r\n\t\t}\r\n\t}\r\n\tbool set(ll x){\r\n\t\tsm\
    \ = x * sz;\r\n\t\tmx = L = x;\r\n\t\treturn true;\r\n\t}\r\n\tbool gcd(ll x){\r\
    \n\t\tif(x % L == 0) return true;\t// break_condition\r\n\t\tif(mx * sz == sm){\t\
    \t// put_tag_condition\r\n\t\t\tset(__gcd(mx,x));\r\n\t\t\treturn true;\r\n\t\t\
    }\r\n\t\treturn false;\r\n\t}\r\n\tll getmax(){\r\n\t\treturn mx;\r\n\t}\r\n\t\
    ll getsum(){\r\n\t\treturn sm;\r\n\t}\r\n};\r\n\r\n\r\nCF 1037 (Manthan 18) H\r\
    \nstruct D{\r\n\tint x,y,z;\t// min sa, min lcp, min sa+lcp\r\n\tD(int l=inf):x(inf),y(l),z(inf){}\r\
    \n\tstatic D merge(D l,D r){\r\n\t\tD m;\r\n\t\tm.x = min(l.x,r.x);\r\n\t\tm.y\
    \ = min(l.y,r.y);\r\n\t\tm.z = min({l.z,r.z,l.y+r.x});\r\n\t\treturn m;\r\n\t\
    }\r\n\tvoid push(D& x,D& y){\r\n\t}\r\n\tbool set(int v){\r\n\t\tx = v;\r\n\t\t\
    return true;\r\n\t}\r\n\tbool find(int& mn, int r){\r\n\t\tif(z < r) return true;\r\
    \n\t\tif(mn+x < r) return true;\r\n\t\tchmin(mn,y);\r\n\t\treturn false;\r\n\t\
    }\r\n};\r\n\r\n*/"
  dependsOn: []
  isVerificationFile: false
  path: data structure/segtree/segbeats.cpp
  requiredBy: []
  timestamp: '2021-09-22 00:44:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_oj/beats/simple_sum.test.cpp
  - test_oj/beats/simple_min.test.cpp
  - test_oj/beats/point_set_range_composite.test.cpp
  - test_oj/beats/point_add_range_sum.test.cpp
  - test_oj/beats/range_chmin_chmax_add_range_sum.test.cpp
  - test_oj/beats/range_affine_range_sum.test.cpp
documentation_of: data structure/segtree/segbeats.cpp
layout: document
redirect_from:
- /library/data structure/segtree/segbeats.cpp
- /library/data structure/segtree/segbeats.cpp.html
title: data structure/segtree/segbeats.cpp
---
