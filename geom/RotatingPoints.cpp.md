---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc344/submissions/51711191
  bundledCode: "#line 2 \"template.hpp\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace\
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
    \ b) {\r\n\treturn a / b + (((a ^ b) > 0 && a % b != 0) ? 1 : 0);\r\n}\r\n\r\n\
    /*\r\nx       0  1  2  3  4  5  6  7  8  9\r\nbsr(x) -1  0  1  1  2  2  2  2 \
    \ 3  3\r\n\u6700\u4E0A\u4F4Dbit\r\n*/\r\nint bsr(int x){\r\n\treturn x == 0 ?\
    \ -1 : 31 ^ __builtin_clz(x);\r\n}\r\nint bsr(uint x){\r\n\treturn x == 0 ? -1\
    \ : 31 ^ __builtin_clz(x);\r\n}\r\nint bsr(ll x){\r\n\treturn x == 0 ? -1 : 63\
    \ ^ __builtin_clzll(x);\r\n}\r\nint bsr(ull x){\r\n\treturn x == 0 ? -1 : 63 ^\
    \ __builtin_clzll(x);\r\n}\r\n\r\n/*\r\nx       0  1  2  3  4  5  6  7  8  9\r\
    \nbsl(x) -1  0  1  0  2  0  1  0  3  0\r\n\u6700\u4E0B\u4F4Dbit\r\n*/\r\nint bsl(int\
    \ x){\r\n\tif(x==0) return -1;\r\n\treturn __builtin_ctz(x);\r\n}\r\nint bsl(uint\
    \ x){\r\n\tif(x==0) return -1;\r\n\treturn __builtin_ctz(x);\r\n}\r\nint bsl(ll\
    \ x){\r\n\tif(x==0) return -1;\r\n\treturn __builtin_ctzll(x);\r\n}\r\nint bsl(ull\
    \ x){\r\n\tif(x==0) return -1;\r\n\treturn __builtin_ctzll(x);\r\n}\r\n#line 2\
    \ \"geom/RotatingPoints.cpp\"\n\n/*\n\t\u6982\u8981:\n\t\t\u4E8C\u6B21\u5143\u5E73\
    \u9762\u306E\u70B9\u96C6\u5408\u3092 ax + by \u306E\u9806\u306B\u30BD\u30FC\u30C8\
    \u3059\u308B\n\t\t\u3068\u3044\u3046\u306E\u3092\u3044\u308D\u3093\u306A (a,b)\
    \ \u306B\u3064\u3044\u3066\u3084\u308A\u305F\u3044\n\t\t\u3053\u308C\u306F\u3050\
    \u308B\u3063\u3068\u4E00\u5468\u3055\u305B\u308C\u3070 O(N^2 log) \u3067\u3067\
    \u304D\u308B\n\t\t\u5B9F\u969B\u306F a,b \u3092\u6307\u5B9A\u3057\u305F\u4E0A\u3067\
    \u8272\u3005\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B\u306E\u3067\u305D\u306E\
    \u60C5\u5831\u3092 Point / Query \u306B\u4E57\u305B\u308B\n\t\t\u304B\u306A\u308A\
    \u5B9A\u6570\u500D\u304C\u60AA\u3044\u3068\u3044\u3046\u5642\u304C\u3042\u308A\
    \u307E\u3059\n\t\n\tPoint:\n\t\tx,y,id \u306F\u5FC5\u9808\n\t\t(x,y) \u306F distinct\
    \ \u3058\u3083\u306A\u3044\u3068\u52D5\u304B\u306A\u3044\n\tQuery:\n\t\ta,b \u306F\
    \u5FC5\u9808\n\t\t(a,b) != (0,0) \u3067\u306A\u3044\u3068\u3044\u3051\u306A\u3044\
    \n\n\tRotatingPoints<Point,Query> RP(ps,qs) \u3067\u547C\u3093\u3067\u3001\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3092\u76F4\u63A5\u66F8\u304D\u63DB\u3048\
    \u3066\u5168\u3066\u3092\u3084\u308B\n\tEDIT \u3063\u3066\u66F8\u3044\u3066\u3042\
    \u308B\u5834\u6240\u3092\u554F\u984C\u3054\u3068\u306B\u5909\u3048\u308B\n\n\t\
    verify:\n\t\tABC344G https://atcoder.jp/contests/abc344/submissions/51711191\n\
    */\n\nstruct Point{\n\tll x,y;\n\tint id;\n\tPoint(ll x_,ll y_,int id_):x(x_),y(y_),id(id_){}\n\
    };\nstruct Query{\n\t// ax+by+c >= 0 \u306A (x,y) \u3092\u30AB\u30A6\u30F3\u30C8\
    \n\tll a,b,c;\n\tQuery(ll a_,ll b_,ll c_):a(a_),b(b_),c(c_){}\n};\n\n\ntemplate<class\
    \ Point, class Query, class T = long long>\nstruct RotatingPoints{\n\tusing P\
    \ = pair<T,T>;\n\tusing Pii = pair<int,int>;\n\n\tRotatingPoints(vector<Point>\
    \ points, vector<Query> queries){\n\t\tint N = points.size();\n\t\t// 1 * x -\
    \ eps * y \u306E\u6607\u9806\n\t\tsort(all(points),[&](Point& p, Point& q){\n\t\
    \t\tif(p.x != q.x) return p.x < q.x;\n\t\t\treturn p.y > q.y;\n\t\t});\n\t\tV<int>\
    \ where(N);\t// where[index] = current pos at points\n\t\trep(i,N) where[points[i].id]\
    \ = i;\n\t\tvector<Pii> events;\n\t\trep(i,N) rep(j,N) if(i != j) events.eb(i,\
    \ j);\n\t\tsort(all(events),[&](Pii l, Pii r){\n\t\t\tP lv,rv;\n\t\t\tPii lswap,rswap;\n\
    \t\t\t{\n\t\t\t\tint i = where[l.fs], j = where[l.sc];\n\t\t\t\tauto& pi = points[i],\
    \ pj = points[j];\n\t\t\t\tlv = P(pi.y-pj.y, pj.x-pi.x);\n\t\t\t\tlswap = Pii(i,j);\n\
    \t\t\t}\n\t\t\t{\n\t\t\t\tint i = where[r.fs], j = where[r.sc];\n\t\t\t\tauto&\
    \ pi = points[i], pj = points[j];\n\t\t\t\trv = P(pi.y-pj.y, pj.x-pi.x);\n\t\t\
    \t\trswap = Pii(i,j);\n\t\t\t}\n\t\t\tint cmp = compP(lv,rv);\n\t\t\tif(cmp !=\
    \ 0) return cmp < 0;\n\t\t\treturn lswap < rswap;\n\t\t});\n\n\t\t/*\n\t\t\t(\u5143\
    \u306E\u70B9\u96C6\u5408\u3067\u306E)index i,j \u306E\u70B9 \u304C i,j \u306E\u9806\
    \u3067\u4E26\u3093\u3067\u3044\u308B\u3068\u3053\u308D\u304C j,i \u306B\u5909\u308F\
    \u308B\n\t\t\t\u3053\u306E\u6642\u70B9\u3067 points[ii], points[jj] \u304C\u3053\
    \u308C\u3089\u306E\u70B9\u3092\u6307\u3057\u3066\u3044\u3066\u3001ii+1 == jj \u304C\
    \u4FDD\u8A3C\u3055\u308C\u308B\n\t\t*/\n\t\tauto Swap = [&](int i, int j){\n\t\
    \t\tint ii = where[i], jj = where[j];\n\t\t\t// debug \u7528\n\t\t\t// cerr <<\
    \ \"current points: \" << points << endl;\n\t\t\t// cerr << \"swap points[\" <<\
    \ ii << \"] and points[\" << jj << \"]\" << endl;\n\t\t\tassert(ii+1 == jj);\n\
    \t\t\t/*\n\t\t\t\tEDIT\n\t\t\t\tswap \u306B\u3088\u308A\u306A\u306B\u304B\u3092\
    \u518D\u8A08\u7B97\u3059\u308B\u5834\u5408\u306F\u3053\u3053\u306B\u66F8\u304F\
    \n\t\t\t*/\n\t\t\tswap(points[ii],points[jj]); swap(where[i],where[j]);\n\t\t\
    };\n\n\t\t/*\n\t\t\t\u30AF\u30A8\u30EA (a,b) \u3092\u30BD\u30FC\u30C8\n\t\t*/\n\
    \t\tsort(all(queries),[&](Query& l, Query& r){\n\t\t\treturn compP(P(l.a,l.b),\
    \ P(r.a,r.b)) < 0;\n\t\t});\n\t\tauto should = [&](Pii e, P ab){\n\t\t\tPoint&\
    \ pi = points[where[e.fs]], pj = points[where[e.sc]];\n\t\t\tP v(pi.y-pj.y, pj.x-pi.x);\n\
    \t\t\treturn compP(v,ab) <= 0;\n\t\t};\n\t\t\n\t\tll ans = 0;\n\n\t\tint e = 0;\n\
    \t\tfor(auto& q: queries){\n\t\t\twhile(e < si(events) && should(events[e],P(q.a,q.b))){\n\
    \t\t\t\tauto [i,j] = events[e];\n\t\t\t\tSwap(i,j);\n\t\t\t\te++;\n\t\t\t}\n\t\
    \t\t/*\n\t\t\t\tEDIT\n\t\t\t\t\u3053\u3053\u3067 \u30AF\u30A8\u30EA q \u306B\u7B54\
    \u3048\u308B\n\t\t\t\tpoints \u304C q.a * x + q.b * y \u306E\u9806\u306B\u30BD\
    \u30FC\u30C8\u3055\u308C\u3066\u3044\u308B\u3053\u3068\u304C\u4FDD\u8A3C\u3055\
    \u308C\u3066\u3044\u308B\n\t\t\t\t\u2193 \u4F8B: ax+by+c >= 0 \u306A (x,y) \u306E\
    \u500B\u6570\u3092\u30AB\u30A6\u30F3\u30C8\n\t\t\t*/\n\t\t\tint lb = -1, ub =\
    \ N;\n\t\t\twhile(ub-lb>1){\n\t\t\t\tint m = (lb+ub)/2;\n\t\t\t\tauto& p = points[m];\n\
    \t\t\t\tif(q.a*p.x + q.b*p.y + q.c >= 0) ub = m;\n\t\t\t\telse lb = m;\n\t\t\t\
    }\n\t\t\tans += N-ub;\n\t\t}\n\n\t\tcout << ans << endl;\n\t}\n\n\tint quad(P\
    \ p){\n\t\tif(p.fs >  0 && p.sc >= 0) return 0;\t// [0,pi/2)\n\t\tif(p.fs <= 0\
    \ && p.sc >  0) return 1;\t// [pi/2,pi)\n\t\tif(p.fs <  0 && p.sc <= 0) return\
    \ 2;\t// [pi,3pi/2)\n\t\tif(p.fs >= 0 && p.sc <  0) return 3;\t// [3pi/2,2pi)\n\
    \t\tassert(false); // p shouldn't be (0,0)\n\t}\n\t// -1: left small, 1: right\
    \ small, 0: equal\n\tint compP(P p, P q){\n\t\tint s=quad(p), t=quad(q);\n\t\t\
    if(s!=t) return s<t ? -1 : 1;\n\t\t// \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\
    \u306B\u6CE8\u610F\n\t\tT le = p.sc * q.fs, ri = p.fs * q.sc;\n\t\tif(le == ri)\
    \ return 0;\n\t\treturn (le < ri ? -1 : 1);\n\t}\n};\n"
  code: "#include \"template.hpp\"\n\n/*\n\t\u6982\u8981:\n\t\t\u4E8C\u6B21\u5143\u5E73\
    \u9762\u306E\u70B9\u96C6\u5408\u3092 ax + by \u306E\u9806\u306B\u30BD\u30FC\u30C8\
    \u3059\u308B\n\t\t\u3068\u3044\u3046\u306E\u3092\u3044\u308D\u3093\u306A (a,b)\
    \ \u306B\u3064\u3044\u3066\u3084\u308A\u305F\u3044\n\t\t\u3053\u308C\u306F\u3050\
    \u308B\u3063\u3068\u4E00\u5468\u3055\u305B\u308C\u3070 O(N^2 log) \u3067\u3067\
    \u304D\u308B\n\t\t\u5B9F\u969B\u306F a,b \u3092\u6307\u5B9A\u3057\u305F\u4E0A\u3067\
    \u8272\u3005\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B\u306E\u3067\u305D\u306E\
    \u60C5\u5831\u3092 Point / Query \u306B\u4E57\u305B\u308B\n\t\t\u304B\u306A\u308A\
    \u5B9A\u6570\u500D\u304C\u60AA\u3044\u3068\u3044\u3046\u5642\u304C\u3042\u308A\
    \u307E\u3059\n\t\n\tPoint:\n\t\tx,y,id \u306F\u5FC5\u9808\n\t\t(x,y) \u306F distinct\
    \ \u3058\u3083\u306A\u3044\u3068\u52D5\u304B\u306A\u3044\n\tQuery:\n\t\ta,b \u306F\
    \u5FC5\u9808\n\t\t(a,b) != (0,0) \u3067\u306A\u3044\u3068\u3044\u3051\u306A\u3044\
    \n\n\tRotatingPoints<Point,Query> RP(ps,qs) \u3067\u547C\u3093\u3067\u3001\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3092\u76F4\u63A5\u66F8\u304D\u63DB\u3048\
    \u3066\u5168\u3066\u3092\u3084\u308B\n\tEDIT \u3063\u3066\u66F8\u3044\u3066\u3042\
    \u308B\u5834\u6240\u3092\u554F\u984C\u3054\u3068\u306B\u5909\u3048\u308B\n\n\t\
    verify:\n\t\tABC344G https://atcoder.jp/contests/abc344/submissions/51711191\n\
    */\n\nstruct Point{\n\tll x,y;\n\tint id;\n\tPoint(ll x_,ll y_,int id_):x(x_),y(y_),id(id_){}\n\
    };\nstruct Query{\n\t// ax+by+c >= 0 \u306A (x,y) \u3092\u30AB\u30A6\u30F3\u30C8\
    \n\tll a,b,c;\n\tQuery(ll a_,ll b_,ll c_):a(a_),b(b_),c(c_){}\n};\n\n\ntemplate<class\
    \ Point, class Query, class T = long long>\nstruct RotatingPoints{\n\tusing P\
    \ = pair<T,T>;\n\tusing Pii = pair<int,int>;\n\n\tRotatingPoints(vector<Point>\
    \ points, vector<Query> queries){\n\t\tint N = points.size();\n\t\t// 1 * x -\
    \ eps * y \u306E\u6607\u9806\n\t\tsort(all(points),[&](Point& p, Point& q){\n\t\
    \t\tif(p.x != q.x) return p.x < q.x;\n\t\t\treturn p.y > q.y;\n\t\t});\n\t\tV<int>\
    \ where(N);\t// where[index] = current pos at points\n\t\trep(i,N) where[points[i].id]\
    \ = i;\n\t\tvector<Pii> events;\n\t\trep(i,N) rep(j,N) if(i != j) events.eb(i,\
    \ j);\n\t\tsort(all(events),[&](Pii l, Pii r){\n\t\t\tP lv,rv;\n\t\t\tPii lswap,rswap;\n\
    \t\t\t{\n\t\t\t\tint i = where[l.fs], j = where[l.sc];\n\t\t\t\tauto& pi = points[i],\
    \ pj = points[j];\n\t\t\t\tlv = P(pi.y-pj.y, pj.x-pi.x);\n\t\t\t\tlswap = Pii(i,j);\n\
    \t\t\t}\n\t\t\t{\n\t\t\t\tint i = where[r.fs], j = where[r.sc];\n\t\t\t\tauto&\
    \ pi = points[i], pj = points[j];\n\t\t\t\trv = P(pi.y-pj.y, pj.x-pi.x);\n\t\t\
    \t\trswap = Pii(i,j);\n\t\t\t}\n\t\t\tint cmp = compP(lv,rv);\n\t\t\tif(cmp !=\
    \ 0) return cmp < 0;\n\t\t\treturn lswap < rswap;\n\t\t});\n\n\t\t/*\n\t\t\t(\u5143\
    \u306E\u70B9\u96C6\u5408\u3067\u306E)index i,j \u306E\u70B9 \u304C i,j \u306E\u9806\
    \u3067\u4E26\u3093\u3067\u3044\u308B\u3068\u3053\u308D\u304C j,i \u306B\u5909\u308F\
    \u308B\n\t\t\t\u3053\u306E\u6642\u70B9\u3067 points[ii], points[jj] \u304C\u3053\
    \u308C\u3089\u306E\u70B9\u3092\u6307\u3057\u3066\u3044\u3066\u3001ii+1 == jj \u304C\
    \u4FDD\u8A3C\u3055\u308C\u308B\n\t\t*/\n\t\tauto Swap = [&](int i, int j){\n\t\
    \t\tint ii = where[i], jj = where[j];\n\t\t\t// debug \u7528\n\t\t\t// cerr <<\
    \ \"current points: \" << points << endl;\n\t\t\t// cerr << \"swap points[\" <<\
    \ ii << \"] and points[\" << jj << \"]\" << endl;\n\t\t\tassert(ii+1 == jj);\n\
    \t\t\t/*\n\t\t\t\tEDIT\n\t\t\t\tswap \u306B\u3088\u308A\u306A\u306B\u304B\u3092\
    \u518D\u8A08\u7B97\u3059\u308B\u5834\u5408\u306F\u3053\u3053\u306B\u66F8\u304F\
    \n\t\t\t*/\n\t\t\tswap(points[ii],points[jj]); swap(where[i],where[j]);\n\t\t\
    };\n\n\t\t/*\n\t\t\t\u30AF\u30A8\u30EA (a,b) \u3092\u30BD\u30FC\u30C8\n\t\t*/\n\
    \t\tsort(all(queries),[&](Query& l, Query& r){\n\t\t\treturn compP(P(l.a,l.b),\
    \ P(r.a,r.b)) < 0;\n\t\t});\n\t\tauto should = [&](Pii e, P ab){\n\t\t\tPoint&\
    \ pi = points[where[e.fs]], pj = points[where[e.sc]];\n\t\t\tP v(pi.y-pj.y, pj.x-pi.x);\n\
    \t\t\treturn compP(v,ab) <= 0;\n\t\t};\n\t\t\n\t\tll ans = 0;\n\n\t\tint e = 0;\n\
    \t\tfor(auto& q: queries){\n\t\t\twhile(e < si(events) && should(events[e],P(q.a,q.b))){\n\
    \t\t\t\tauto [i,j] = events[e];\n\t\t\t\tSwap(i,j);\n\t\t\t\te++;\n\t\t\t}\n\t\
    \t\t/*\n\t\t\t\tEDIT\n\t\t\t\t\u3053\u3053\u3067 \u30AF\u30A8\u30EA q \u306B\u7B54\
    \u3048\u308B\n\t\t\t\tpoints \u304C q.a * x + q.b * y \u306E\u9806\u306B\u30BD\
    \u30FC\u30C8\u3055\u308C\u3066\u3044\u308B\u3053\u3068\u304C\u4FDD\u8A3C\u3055\
    \u308C\u3066\u3044\u308B\n\t\t\t\t\u2193 \u4F8B: ax+by+c >= 0 \u306A (x,y) \u306E\
    \u500B\u6570\u3092\u30AB\u30A6\u30F3\u30C8\n\t\t\t*/\n\t\t\tint lb = -1, ub =\
    \ N;\n\t\t\twhile(ub-lb>1){\n\t\t\t\tint m = (lb+ub)/2;\n\t\t\t\tauto& p = points[m];\n\
    \t\t\t\tif(q.a*p.x + q.b*p.y + q.c >= 0) ub = m;\n\t\t\t\telse lb = m;\n\t\t\t\
    }\n\t\t\tans += N-ub;\n\t\t}\n\n\t\tcout << ans << endl;\n\t}\n\n\tint quad(P\
    \ p){\n\t\tif(p.fs >  0 && p.sc >= 0) return 0;\t// [0,pi/2)\n\t\tif(p.fs <= 0\
    \ && p.sc >  0) return 1;\t// [pi/2,pi)\n\t\tif(p.fs <  0 && p.sc <= 0) return\
    \ 2;\t// [pi,3pi/2)\n\t\tif(p.fs >= 0 && p.sc <  0) return 3;\t// [3pi/2,2pi)\n\
    \t\tassert(false); // p shouldn't be (0,0)\n\t}\n\t// -1: left small, 1: right\
    \ small, 0: equal\n\tint compP(P p, P q){\n\t\tint s=quad(p), t=quad(q);\n\t\t\
    if(s!=t) return s<t ? -1 : 1;\n\t\t// \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\
    \u306B\u6CE8\u610F\n\t\tT le = p.sc * q.fs, ri = p.fs * q.sc;\n\t\tif(le == ri)\
    \ return 0;\n\t\treturn (le < ri ? -1 : 1);\n\t}\n};"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: geom/RotatingPoints.cpp
  requiredBy: []
  timestamp: '2024-07-25 10:58:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geom/RotatingPoints.cpp
layout: document
redirect_from:
- /library/geom/RotatingPoints.cpp
- /library/geom/RotatingPoints.cpp.html
title: geom/RotatingPoints.cpp
---
