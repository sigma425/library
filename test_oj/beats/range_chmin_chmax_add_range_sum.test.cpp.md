---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data structure/segtree/segbeats.cpp
    title: data structure/segtree/segbeats.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE_IF_CLANG: ''
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"test_oj/beats/range_chmin_chmax_add_range_sum.test.cpp\"\
    \n/*\n\tsz=1 (1\u6557)\n\tmx2,mn2 \u66F4\u65B0\u5FD8\u308C (1\u6557)\n*/\n#ifdef\
    \ __clang__\n#define IGNORE\n#else\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#endif\n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\
    using uint = unsigned int;\n#define rep(i,n) for(int i=0;i<int(n);i++)\n#define\
    \ rep1(i,n) for(int i=1;i<=int(n);i++)\n#define per(i,n) for(int i=int(n)-1;i>=0;i--)\n\
    #define per1(i,n) for(int i=int(n);i>0;i--)\n#define all(c) c.begin(),c.end()\n\
    #define si(x) int(x.size())\n#define pb emplace_back\n#define fs first\n#define\
    \ sc second\ntemplate<class T> using V = vector<T>;\ntemplate<class T> using VV\
    \ = vector<vector<T>>;\ntemplate<class T,class U> void chmax(T& x, U y){if(x<y)\
    \ x=y;}\ntemplate<class T,class U> void chmin(T& x, U y){if(y<x) x=y;}\ntemplate<class\
    \ T> void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){\n\treturn o<<\"\
    (\"<<p.fs<<\",\"<<p.sc<<\")\";\n}\ntemplate<class T> ostream& operator<<(ostream&\
    \ o,const vector<T> &vc){\n\to<<\"{\";\n\tfor(const T& v:vc) o<<v<<\",\";\n\t\
    o<<\"}\";\n\treturn o;\n}\nconstexpr ll TEN(int n) { return (n == 0) ? 1 : 10\
    \ * TEN(n-1); }\n\n#ifdef LOCAL\n#define show(x) cerr << \"LINE\" << __LINE__\
    \ << \" : \" << #x << \" = \" << (x) << endl\nvoid dmpr(ostream& os){os<<endl;}\n\
    template<class T,class... Args>\nvoid dmpr(ostream&os,const T&t,const Args&...\
    \ args){\n\tos<<t<<\" ~ \";\n\tdmpr(os,args...);\n}\n#define shows(...) cerr <<\
    \ \"LINE\" << __LINE__ << \" : \";dmpr(cerr,##__VA_ARGS__)\n#define dump(x) cerr\
    \ << \"LINE\" << __LINE__ << \" : \" << #x << \" = {\";  \\\n\tfor(auto v: x)\
    \ cerr << v << \",\"; cerr << \"}\" << endl;\n#else\n#define show(x) void(0)\n\
    #define dump(x) void(0)\n#define shows(...) void(0)\n#endif\n\n#line 1 \"data\
    \ structure/segtree/segbeats.cpp\"\n/*\r\n\t\uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\
    \uFF01\uFF01\uFF01\uFF01\u96F0\u56F2\u6C17\u3067\u95A2\u6570\u3092\u66F8\u304F\
    \u306A\uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\r\n\tlazy\u306A\
    \u3089\u95A2\u6570\u306E\u5408\u6210\u3092\u3059\u308B\u3053\u3068\u306F\u7D76\
    \u5BFE\u5FC5\u8981 \u3061\u3083\u3093\u3068 \"\u30E2\u30CE\u30A4\u30C9\u3068\u4F5C\
    \u7528\u3092\u5206\u3051\u3066\" \"\u5404\u6F14\u7B97\u3092\u8003\u3048\u308B\"\
    \ \u3053\u3068\u306F\u5FC5\u305A\u5FC5\u8981\r\n\t\u3053\u306E\u30E9\u30A4\u30D6\
    \u30E9\u30EA\u3060\u3068\u76F4\u63A5\u305D\u3046\u3044\u3046\u578B\u3092\u6301\
    \u3063\u3066\u308B\u308F\u3051\u3058\u3083\u306A\u3044\u304B\u3089\u306A\u3093\
    \u304B\u3044\u3044\u611F\u3058\u306B\u304B\u3051\u3066\u3057\u307E\u3046\u3053\
    \u3068\u304C\u3042\u308B\u3051\u3069\u3001\u305D\u308C\u306F\u9593\u9055\u3063\
    \u3066\u308B\u304B\u3089\u3061\u3083\u3093\u3068\u9589\u3058\u305F\u6F14\u7B97\
    \u3092\u304B\u3051\r\n\t\u7279\u306B\u3001\u8907\u96D1\u306A\u5834\u5408\u306F\
    \u3082\u3046\u578B\u3092\u4F5C\u3063\u3066\u3057\u307E\u3046(segtree_lazy) \u65B9\
    \u304C\u3044\u3044\u30B1\u30FC\u30B9\u304C\u591A\u3005\u3042\u308B\r\n\r\n\t\u95A2\
    \u6570\u9069\u7528\u306E\u9589\u3058\u305F\u5F62\u3092\u4F5C\u3089\u306A\u304D\
    \u3083\u3044\u3051\u306A\u3044\u306E\u306F\u5927\u524D\u63D0\u3067\u3001\u305D\
    \u306E\u4E0A\u3067\u3044\u3061\u3044\u3061\uFF08\u547C\u3073\u51FA\u3057\u5074\
    \u304C\uFF09\u9069\u7528\u3057\u305F\u3044\u95A2\u6570\u3092\u305D\u306E\u578B\
    \u3067\u66F8\u304F\u306E\u304C\u9762\u5012\u3060\u304B\u3089\u3053\u3046\u3044\
    \u3046\u3075\u3046\u306B\u306A\u3063\u3066\u308B\u306E\u3067\u3042\u3063\u3066\
    \r\n\t\u5408\u6210\u3092\u8003\u3048\u305A\u306B(lz\u3092\u306A\u3093\u304B\u9069\
    \u7528\u3057\u305F\u7D50\u679C\u306E\u30E2\u30CE\u30A4\u30C9\u306E\u4E00\u90E8\
    \u307F\u305F\u3044\u306B)\u6271\u3063\u3066\u3044\u3044\u308F\u3051\u3067\u306F\
    \u306A\u3044\r\n\r\n\t\u3061\u306A\u307F\u306B\u70B9\u66F4\u65B0\u306E\u95A2\u6570\
    \u306F\u2191\u306E\u9589\u3058\u305F\u5F62\u306B\u306F\u542B\u3081\u306A\u304F\
    \u3066\u826F\u3044\u3001\u305D\u308C\u306Flz\u3067\u306F\u306A\u304F\u5024\u3092\
    \u76F4\u63A5\u3044\u3058\u308C\u3070\u3044\u3044\u304B\u3089\u3002\u7279\u306B\
    \ ch(i,i+1,&D::hoge) \u4F7F\u3063\u3066\u3044\u3044\r\n\r\n\t\u982D\u3092\u58CA\
    \u3057\u3066\u3057\u307E\u3063\u305F\u4F8B: https://atcoder.jp/contests/acl2/submissions/16994422\r\
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
    }\r\n};\r\n\r\n*/\n#line 58 \"test_oj/beats/range_chmin_chmax_add_range_sum.test.cpp\"\
    \n\nstruct D{\n\tstatic const ll inf = TEN(13);\n\tll sz=0,mx=-inf,mx2=-inf,mxn=0,mn=inf,mn2=inf,mnn=0,lz=0,sm=0;\n\
    \tD(){}\n\tD(ll v){sz=1,mx=v,mxn=1,mn=v,mnn=1,sm=v;}\n\tstatic D merge(D l,D r){\n\
    \t\tD z;\n\t\tz.sz = l.sz+r.sz;\n\t\t{\n\t\t\tz.mx = max(l.mx,r.mx);\n\t\t\tif(z.mx\
    \ == l.mx) z.mxn += l.mxn;\n\t\t\tif(z.mx == r.mx) z.mxn += r.mxn;\n\t\t\tfor(ll\
    \ v:{l.mx,l.mx2,r.mx,r.mx2}){\n\t\t\t\tif(z.mx != v) chmax(z.mx2,v);\n\t\t\t}\n\
    \t\t}\n\t\t{\n\t\t\tz.mn = min(l.mn,r.mn);\n\t\t\tif(z.mn == l.mn) z.mnn += l.mnn;\n\
    \t\t\tif(z.mn == r.mn) z.mnn += r.mnn;\n\t\t\tfor(ll v:{l.mn,l.mn2,r.mn,r.mn2}){\n\
    \t\t\t\tif(z.mn != v) chmin(z.mn2,v);\n\t\t\t}\n\t\t}\n\t\tz.sm = l.sm+r.sm;\n\
    \t\treturn z;\n\t}\n\tvoid push(D& x,D& y){\n\t\tll oldmx = max(x.mx,y.mx);\n\t\
    \tll oldmn = min(x.mn,y.mn);\n\t\trep(_,2){\n\t\t\tD& z = (_ == 0 ? x : y);\n\t\
    \t\tif(z.mn == z.mx){\t\t\t//1\n\t\t\t\tif(z.mx == oldmx){\n\t\t\t\t\tz.sm +=\
    \ (mx-z.mx)*z.sz;\n\t\t\t\t\tz.mn = z.mx = mx;\n\t\t\t\t}else if(z.mn == oldmn){\n\
    \t\t\t\t\tz.sm += (mn-z.mn)*z.sz;\n\t\t\t\t\tz.mn = z.mx = mn;\n\t\t\t\t}else{\n\
    \t\t\t\t\tz.sm += lz*z.sz;\n\t\t\t\t\tz.mn = z.mx = z.mn+lz;\n\t\t\t\t}\n\t\t\t\
    }else{\n\t\t\t\tif(z.mx == oldmx){\n\t\t\t\t\tz.sm += (mx-z.mx)*z.mxn;\n\t\t\t\
    \t\tz.mx = mx;\n\t\t\t\t}else{\n\t\t\t\t\tz.sm += lz*z.mxn;\n\t\t\t\t\tz.mx +=\
    \ lz;\n\t\t\t\t}\n\t\t\t\tif(z.mn == oldmn){\n\t\t\t\t\tz.sm += (mn-z.mn)*z.mnn;\n\
    \t\t\t\t\tz.mn = mn;\n\t\t\t\t}else{\n\t\t\t\t\tz.sm += lz*z.mnn;\n\t\t\t\t\t\
    z.mn += lz;\n\t\t\t\t}\n\t\t\t\tll others = z.sz - z.mxn - z.mnn;\n\t\t\t\tif(others){\t\
    \t\t\t// 3\n\t\t\t\t\tz.sm += lz * others;\n\t\t\t\t\tz.mx2 += lz; z.mn2 += lz;\n\
    \t\t\t\t}else{\t\t\t\t\t// 2\n\t\t\t\t\tz.mn2 = z.mx;\n\t\t\t\t\tz.mx2 = z.mn;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\tz.lz += lz;\n\t\t}\n\t\tlz = 0;\n\t}\n\tbool changemin(ll\
    \ v){\n\t\tif(v >= mx) return true;\n\t\tif(v > mx2){\t//mx -> v\n\t\t\tll oldmx\
    \ = mx;\n\t\t\tsm += mxn * (v-mx);\n\t\t\tmx = v;\n\t\t\tif(oldmx == mn) mn =\
    \ v;\n\t\t\tif(oldmx == mn2) mn2 = v;\n\t\t\treturn true;\n\t\t}\n\t\treturn false;\n\
    \t}\n\tbool changemax(ll v){\n\t\tif(v <= mn) return true;\n\t\tif(v < mn2){\t\
    //mn -> v\n\t\t\tll oldmn = mn;\n\t\t\tsm += mnn * (v-mn);\n\t\t\tmn = v;\n\t\t\
    \tif(oldmn == mx) mx = v;\n\t\t\tif(oldmn == mx2) mx2 = v;\n\t\t\treturn true;\n\
    \t\t}\n\t\treturn false;\n\t}\n\tbool add(ll v){\n\t\tmx += v;\n\t\tif(mx2 !=\
    \ -inf) mx2 += v;\n\t\tmn += v;\n\t\tif(mn2 != inf) mn2 += v;\n\t\tsm += v * sz;\n\
    \t\tlz += v;\n\t\treturn true;\n\t}\n\tll getsum(){\n\t\treturn sm;\n\t}\n};\n\
    \n\nint main(){\n\tcin.tie(0);\n\tios::sync_with_stdio(false);\t\t//DON'T USE\
    \ scanf/printf/puts !!\n\tcout << fixed << setprecision(20);\n\n\tint N,Q; cin\
    \ >> N >> Q;\n\tV<ll> a(N); rep(i,N) cin >> a[i];\n\tsegbeats<D> seg(a);\n\twhile(Q--){\n\
    \t\tint t; cin >> t;\n\t\tif(t == 0){\n\t\t\tint l,r; ll v; cin >> l >> r >> v;\n\
    \t\t\tseg.ch(l,r,&D::changemin,v);\n\t\t}\n\t\tif(t == 1){\n\t\t\tint l,r; ll\
    \ v; cin >> l >> r >> v;\n\t\t\tseg.ch(l,r,&D::changemax,v);\n\t\t}\n\t\tif(t\
    \ == 2){\n\t\t\tint l,r; ll v; cin >> l >> r >> v;\n\t\t\tseg.ch(l,r,&D::add,v);\n\
    \t\t}\n\t\tif(t == 3){\n\t\t\tint l,r; cin >> l >> r;\n\t\t\tcout << seg.get(l,r,&D::getsum,[&](ll\
    \ x,ll y){return x+y;},0LL) << endl;\n\t\t}\n\t\t// if(false){\n\t\t// \tcout\
    \ << \"seg: \";\n\t\t// \trep(i,N){\n\t\t// \t\tauto v = seg.getNode(i,i+1);\n\
    \t\t// \t\tshows(v.sm,v.mn,v.mn2,v.mnn,\"---\",v.mx,v.mx2,v.mxn,v.lz);\n\t\t//\
    \ \t\tcout << seg.get(i,i+1,&D::getsum,[&](ll x,ll y){return x+y;},0LL) << \"\
    \ \";\n\t\t// \t}\n\t\t// \tcout << endl;\n\t\t// }\n\t}\n}\n"
  code: "/*\n\tsz=1 (1\u6557)\n\tmx2,mn2 \u66F4\u65B0\u5FD8\u308C (1\u6557)\n*/\n\
    #ifdef __clang__\n#define IGNORE\n#else\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#endif\n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\
    using uint = unsigned int;\n#define rep(i,n) for(int i=0;i<int(n);i++)\n#define\
    \ rep1(i,n) for(int i=1;i<=int(n);i++)\n#define per(i,n) for(int i=int(n)-1;i>=0;i--)\n\
    #define per1(i,n) for(int i=int(n);i>0;i--)\n#define all(c) c.begin(),c.end()\n\
    #define si(x) int(x.size())\n#define pb emplace_back\n#define fs first\n#define\
    \ sc second\ntemplate<class T> using V = vector<T>;\ntemplate<class T> using VV\
    \ = vector<vector<T>>;\ntemplate<class T,class U> void chmax(T& x, U y){if(x<y)\
    \ x=y;}\ntemplate<class T,class U> void chmin(T& x, U y){if(y<x) x=y;}\ntemplate<class\
    \ T> void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}\ntemplate<class\
    \ S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){\n\treturn o<<\"\
    (\"<<p.fs<<\",\"<<p.sc<<\")\";\n}\ntemplate<class T> ostream& operator<<(ostream&\
    \ o,const vector<T> &vc){\n\to<<\"{\";\n\tfor(const T& v:vc) o<<v<<\",\";\n\t\
    o<<\"}\";\n\treturn o;\n}\nconstexpr ll TEN(int n) { return (n == 0) ? 1 : 10\
    \ * TEN(n-1); }\n\n#ifdef LOCAL\n#define show(x) cerr << \"LINE\" << __LINE__\
    \ << \" : \" << #x << \" = \" << (x) << endl\nvoid dmpr(ostream& os){os<<endl;}\n\
    template<class T,class... Args>\nvoid dmpr(ostream&os,const T&t,const Args&...\
    \ args){\n\tos<<t<<\" ~ \";\n\tdmpr(os,args...);\n}\n#define shows(...) cerr <<\
    \ \"LINE\" << __LINE__ << \" : \";dmpr(cerr,##__VA_ARGS__)\n#define dump(x) cerr\
    \ << \"LINE\" << __LINE__ << \" : \" << #x << \" = {\";  \\\n\tfor(auto v: x)\
    \ cerr << v << \",\"; cerr << \"}\" << endl;\n#else\n#define show(x) void(0)\n\
    #define dump(x) void(0)\n#define shows(...) void(0)\n#endif\n\n#include \"../../data\
    \ structure/segtree/segbeats.cpp\"\n\nstruct D{\n\tstatic const ll inf = TEN(13);\n\
    \tll sz=0,mx=-inf,mx2=-inf,mxn=0,mn=inf,mn2=inf,mnn=0,lz=0,sm=0;\n\tD(){}\n\t\
    D(ll v){sz=1,mx=v,mxn=1,mn=v,mnn=1,sm=v;}\n\tstatic D merge(D l,D r){\n\t\tD z;\n\
    \t\tz.sz = l.sz+r.sz;\n\t\t{\n\t\t\tz.mx = max(l.mx,r.mx);\n\t\t\tif(z.mx == l.mx)\
    \ z.mxn += l.mxn;\n\t\t\tif(z.mx == r.mx) z.mxn += r.mxn;\n\t\t\tfor(ll v:{l.mx,l.mx2,r.mx,r.mx2}){\n\
    \t\t\t\tif(z.mx != v) chmax(z.mx2,v);\n\t\t\t}\n\t\t}\n\t\t{\n\t\t\tz.mn = min(l.mn,r.mn);\n\
    \t\t\tif(z.mn == l.mn) z.mnn += l.mnn;\n\t\t\tif(z.mn == r.mn) z.mnn += r.mnn;\n\
    \t\t\tfor(ll v:{l.mn,l.mn2,r.mn,r.mn2}){\n\t\t\t\tif(z.mn != v) chmin(z.mn2,v);\n\
    \t\t\t}\n\t\t}\n\t\tz.sm = l.sm+r.sm;\n\t\treturn z;\n\t}\n\tvoid push(D& x,D&\
    \ y){\n\t\tll oldmx = max(x.mx,y.mx);\n\t\tll oldmn = min(x.mn,y.mn);\n\t\trep(_,2){\n\
    \t\t\tD& z = (_ == 0 ? x : y);\n\t\t\tif(z.mn == z.mx){\t\t\t//1\n\t\t\t\tif(z.mx\
    \ == oldmx){\n\t\t\t\t\tz.sm += (mx-z.mx)*z.sz;\n\t\t\t\t\tz.mn = z.mx = mx;\n\
    \t\t\t\t}else if(z.mn == oldmn){\n\t\t\t\t\tz.sm += (mn-z.mn)*z.sz;\n\t\t\t\t\t\
    z.mn = z.mx = mn;\n\t\t\t\t}else{\n\t\t\t\t\tz.sm += lz*z.sz;\n\t\t\t\t\tz.mn\
    \ = z.mx = z.mn+lz;\n\t\t\t\t}\n\t\t\t}else{\n\t\t\t\tif(z.mx == oldmx){\n\t\t\
    \t\t\tz.sm += (mx-z.mx)*z.mxn;\n\t\t\t\t\tz.mx = mx;\n\t\t\t\t}else{\n\t\t\t\t\
    \tz.sm += lz*z.mxn;\n\t\t\t\t\tz.mx += lz;\n\t\t\t\t}\n\t\t\t\tif(z.mn == oldmn){\n\
    \t\t\t\t\tz.sm += (mn-z.mn)*z.mnn;\n\t\t\t\t\tz.mn = mn;\n\t\t\t\t}else{\n\t\t\
    \t\t\tz.sm += lz*z.mnn;\n\t\t\t\t\tz.mn += lz;\n\t\t\t\t}\n\t\t\t\tll others =\
    \ z.sz - z.mxn - z.mnn;\n\t\t\t\tif(others){\t\t\t\t// 3\n\t\t\t\t\tz.sm += lz\
    \ * others;\n\t\t\t\t\tz.mx2 += lz; z.mn2 += lz;\n\t\t\t\t}else{\t\t\t\t\t// 2\n\
    \t\t\t\t\tz.mn2 = z.mx;\n\t\t\t\t\tz.mx2 = z.mn;\n\t\t\t\t}\n\t\t\t}\n\t\t\tz.lz\
    \ += lz;\n\t\t}\n\t\tlz = 0;\n\t}\n\tbool changemin(ll v){\n\t\tif(v >= mx) return\
    \ true;\n\t\tif(v > mx2){\t//mx -> v\n\t\t\tll oldmx = mx;\n\t\t\tsm += mxn *\
    \ (v-mx);\n\t\t\tmx = v;\n\t\t\tif(oldmx == mn) mn = v;\n\t\t\tif(oldmx == mn2)\
    \ mn2 = v;\n\t\t\treturn true;\n\t\t}\n\t\treturn false;\n\t}\n\tbool changemax(ll\
    \ v){\n\t\tif(v <= mn) return true;\n\t\tif(v < mn2){\t//mn -> v\n\t\t\tll oldmn\
    \ = mn;\n\t\t\tsm += mnn * (v-mn);\n\t\t\tmn = v;\n\t\t\tif(oldmn == mx) mx =\
    \ v;\n\t\t\tif(oldmn == mx2) mx2 = v;\n\t\t\treturn true;\n\t\t}\n\t\treturn false;\n\
    \t}\n\tbool add(ll v){\n\t\tmx += v;\n\t\tif(mx2 != -inf) mx2 += v;\n\t\tmn +=\
    \ v;\n\t\tif(mn2 != inf) mn2 += v;\n\t\tsm += v * sz;\n\t\tlz += v;\n\t\treturn\
    \ true;\n\t}\n\tll getsum(){\n\t\treturn sm;\n\t}\n};\n\n\nint main(){\n\tcin.tie(0);\n\
    \tios::sync_with_stdio(false);\t\t//DON'T USE scanf/printf/puts !!\n\tcout <<\
    \ fixed << setprecision(20);\n\n\tint N,Q; cin >> N >> Q;\n\tV<ll> a(N); rep(i,N)\
    \ cin >> a[i];\n\tsegbeats<D> seg(a);\n\twhile(Q--){\n\t\tint t; cin >> t;\n\t\
    \tif(t == 0){\n\t\t\tint l,r; ll v; cin >> l >> r >> v;\n\t\t\tseg.ch(l,r,&D::changemin,v);\n\
    \t\t}\n\t\tif(t == 1){\n\t\t\tint l,r; ll v; cin >> l >> r >> v;\n\t\t\tseg.ch(l,r,&D::changemax,v);\n\
    \t\t}\n\t\tif(t == 2){\n\t\t\tint l,r; ll v; cin >> l >> r >> v;\n\t\t\tseg.ch(l,r,&D::add,v);\n\
    \t\t}\n\t\tif(t == 3){\n\t\t\tint l,r; cin >> l >> r;\n\t\t\tcout << seg.get(l,r,&D::getsum,[&](ll\
    \ x,ll y){return x+y;},0LL) << endl;\n\t\t}\n\t\t// if(false){\n\t\t// \tcout\
    \ << \"seg: \";\n\t\t// \trep(i,N){\n\t\t// \t\tauto v = seg.getNode(i,i+1);\n\
    \t\t// \t\tshows(v.sm,v.mn,v.mn2,v.mnn,\"---\",v.mx,v.mx2,v.mxn,v.lz);\n\t\t//\
    \ \t\tcout << seg.get(i,i+1,&D::getsum,[&](ll x,ll y){return x+y;},0LL) << \"\
    \ \";\n\t\t// \t}\n\t\t// \tcout << endl;\n\t\t// }\n\t}\n}\n"
  dependsOn:
  - data structure/segtree/segbeats.cpp
  isVerificationFile: true
  path: test_oj/beats/range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2020-12-16 01:37:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test_oj/beats/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test_oj/beats/range_chmin_chmax_add_range_sum.test.cpp
- /verify/test_oj/beats/range_chmin_chmax_add_range_sum.test.cpp.html
title: test_oj/beats/range_chmin_chmax_add_range_sum.test.cpp
---