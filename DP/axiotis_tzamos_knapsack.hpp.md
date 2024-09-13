---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DP/maxplus_convolution_b_concave.hpp
    title: DP/maxplus_convolution_b_concave.hpp
  - icon: ':heavy_check_mark:'
    path: DP/smawk.hpp
    title: DP/smawk.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://contest.ucup.ac/submission/487402
  bundledCode: "#line 1 \"DP/axiotis_tzamos_knapsack.hpp\"\n/*\n\t(w_i,v_i) \u3068\
    \ W \u304C\u4E0E\u3048\u3089\u308C\u308B\u306E\u3067 sum = w \u3067\u306E\u4FA1\
    \u5024\u306E\u6700\u5927 dp[w] \u3092 w \\in [0,W] \u306B\u3064\u3044\u3066\u6C42\
    \u3081\u308B\n\t\u4E0D\u53EF\u80FD\u306A\u3089 dp[w] = -inf. T (v\u306Etype) \u306B\
    \u3088\u3063\u3066 inf \u3092\u66F8\u304D\u63DB\u3048\u308B\u3053\u3068\n\tv \u304C\
    \u8CA0\u306B\u306A\u308B\u5834\u5408\u3082\u52D5\u304F. \u305D\u306E\u5834\u5408\
    \u306F -inf + v \u304C\u30A2\u30F3\u30C0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\
    \u3088\u3046\u306B\u6CE8\u610F\n\n\tO(W * (w_i\u306E\u7A2E\u985E\u6570))\n\n\t\
    knapsack \u3059\u308B\u3068\u304D\u306B\u3001w \u304C\u540C\u3058\u3084\u3064\u3092\
    \u96C6\u3081\u3066\u540C\u6642\u306B\u9077\u79FB\u3059\u308B\u3068\u3001mod w\
    \ \u3054\u3068\u306B (max,+) convolution \u306B\u306A\u308B\n\t\u8FFD\u52A0\u3059\
    \u308B\u5074\u306F v \u3067\u30BD\u30FC\u30C8\u3059\u308C\u3070 concave \u306B\
    \u3067\u304D\u308B\u306E\u3067\u3001\u3053\u308C\u306F\u7DDA\u5F62\u3067\u51FA\
    \u6765\u308B\n\t\u3053\u308C\u3092\u4F7F\u3046\u305F\u3081\u306B\u3001\u300C\u540C\
    \u3058w\u306E\u3046\u3061v\u304C\u5927\u304D\u3044\u65B9W/w\u500B\u300D\u307F\u305F\
    \u3044\u306A\u306E\u3092\u5916\u5074\u3067\u5217\u6319\u3059\u308B\u3053\u3068\
    \u3082\u3042\u308B\n\n\tverify: https://contest.ucup.ac/submission/487402\n*/\n\
    \n#line 1 \"DP/maxplus_convolution_b_concave.hpp\"\n/*\n\t\u6570\u5217 A, B \u304C\
    \u4E0E\u3048\u3089\u308C\u308B\n\t!!!! B !!!! \u306F concave (\u4E0A\u306B\u51F8\
    )\n\tC_k = max_{k=i+j} A_i + B_j \u3092\u51FA\u529B\n\tO(|A|+|B|)\n\n\t\u4F8B\u3048\
    \u3070 knapsack \u3067\u540C\u3058 w \u306B\u3064\u3044\u3066\u307E\u3068\u3081\
    \u305F\u3082\u306E\u3092 B \u3068\u3059\u308B\u3068 mod w \u3054\u3068\u306B\u3053\
    \u308C\u3092\u547C\u3076\u3053\u3068\u306B\u306A\u308B\n\tB \u304C convex (\u4E0B\
    \u306B\u51F8) \u306E minplus_convolution \u306F select \u306E\u4E2D\u8EAB\u3060\
    \u3051\u5909\u3048\u308C\u3070\u3088\u3044\n\n\thttps://codeforces.com/blog/entry/98663\n\
    \n\tverify:\n\t\thttps://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary\n\
    */\n\n#line 1 \"DP/smawk.hpp\"\n/*\n\ttotally monotone \u306A H*W \u884C\u5217\
    \ A \u306B\u5BFE\u3057\u3001\u5404\u884C\u306Eargmax\u306E\u4F4D\u7F6E\u3092\u8A08\
    \u7B97\u3059\u308B\n\t\tmonotone: argmax\u304C\u4E0B\u306E\u884C\u307B\u3069\u53F3\
    \u306B\u3042\u308B\n\t\ttotally monotone: \u5404 2x2 submatrix \u304C monotone\n\
    \t\tmonotone \u306A\u3060\u3051\u306A\u3089 monotone_minima \u3092\u4F7F\u3046\
    \n\t\tmonge => totally monotone \u306A\u306E\u3067 \u6700\u9069\u5316DP \u306A\
    \u3089\u6210\u308A\u7ACB\u3063\u3066\u308B\u3053\u3068\u304C\u591A\u3044?\n\n\t\
    A \u306B\u30E9\u30F3\u30C0\u30E0\u306A\u9806\u3067\u30A2\u30AF\u30BB\u30B9\u30AF\
    \u30A8\u30EA\u304C\u98DB\u3093\u3067\u304F\u308B\u306E\u3067\u3001DP\u3067\u4E0A\
    \u306E\u884C\u304B\u3089\u9806\u306B\u57CB\u307E\u308B \u3068\u304B\u3060\u3068\
    \u7121\u7406\n\thttps://noshi91.hatenablog.com/entry/2023/02/18/005856 \u3067\u3044\
    \u3046 \u30AA\u30F3\u30E9\u30A4\u30F3 / \u30E9\u30F3\u30C0\u30E0\n\n\tin:\n\t\t\
    H,W: size\n\t\tselect(i, j1, j2) := A[i][j1] \u3068 A[i][j2] \u306E\u3046\u3061\
    \u5DE6\u304C \"\u826F\u3044\" \u304B? (j1 < j2)\n\t\t\tleftmost argmax \u304C\u6761\
    \u4EF6\u3092\u6E80\u305F\u3059\u306A\u3089\n\t\t\t\t[&](int i, int j1, int j2){return\
    \ A[i][j1] >= A[i][j2];}\n\t\t\trightmost argmax \u304C\u6761\u4EF6\u3092\u6E80\
    \u305F\u3059\u306A\u3089\n\t\t\t\t[&](int i, int j1, int j2){return A[i][j1] >\
    \ A[i][j2];}\n\t\t\t\u3082\u3057\u304F\u306F -A \u304C totally monotone \u307F\
    \u305F\u3044\u306A\u30B1\u30FC\u30B9\u3067\u3082 select \u3092\u5909\u3048\u308B\
    \u3060\u3051\u3067\u826F\u3044\n\n\tO(H+W)\n*/\n\n#line 2 \"template.hpp\"\n\r\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\nusing ll = long long;\r\n\
    using uint = unsigned int;\r\nusing ull = unsigned long long;\r\n#define rep(i,n)\
    \ for(int i=0;i<int(n);i++)\r\n#define rep1(i,n) for(int i=1;i<=int(n);i++)\r\n\
    #define per(i,n) for(int i=int(n)-1;i>=0;i--)\r\n#define per1(i,n) for(int i=int(n);i>0;i--)\r\
    \n#define all(c) c.begin(),c.end()\r\n#define si(x) int(x.size())\r\n#define pb\
    \ push_back\r\n#define eb emplace_back\r\n#define fs first\r\n#define sc second\r\
    \ntemplate<class T> using V = vector<T>;\r\ntemplate<class T> using VV = vector<vector<T>>;\r\
    \ntemplate<class T,class U> bool chmax(T& x, U y){\r\n\tif(x<y){ x=y; return true;\
    \ }\r\n\treturn false;\r\n}\r\ntemplate<class T,class U> bool chmin(T& x, U y){\r\
    \n\tif(y<x){ x=y; return true; }\r\n\treturn false;\r\n}\r\ntemplate<class T>\
    \ void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}\r\ntemplate<class\
    \ T> int lwb(const V<T>& v, const T& a){return lower_bound(all(v),a) - v.begin();}\r\
    \ntemplate<class T>\r\nV<T> Vec(size_t a) {\r\n    return V<T>(a);\r\n}\r\ntemplate<class\
    \ T, class... Ts>\r\nauto Vec(size_t a, Ts... ts) {\r\n  return V<decltype(Vec<T>(ts...))>(a,\
    \ Vec<T>(ts...));\r\n}\r\ntemplate<class S,class T> ostream& operator<<(ostream&\
    \ o,const pair<S,T> &p){\r\n\treturn o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";\r\n}\r\
    \ntemplate<class T> ostream& operator<<(ostream& o,const vector<T> &vc){\r\n\t\
    o<<\"{\";\r\n\tfor(const T& v:vc) o<<v<<\",\";\r\n\to<<\"}\";\r\n\treturn o;\r\
    \n}\r\nconstexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }\r\n\r\n\
    #ifdef LOCAL\r\n#define show(x) cerr << \"LINE\" << __LINE__ << \" : \" << #x\
    \ << \" = \" << (x) << endl\r\nvoid dmpr(ostream& os){os<<endl;}\r\ntemplate<class\
    \ T,class... Args>\r\nvoid dmpr(ostream&os,const T&t,const Args&... args){\r\n\
    \tos<<t<<\" ~ \";\r\n\tdmpr(os,args...);\r\n}\r\n#define shows(...) cerr << \"\
    LINE\" << __LINE__ << \" : \";dmpr(cerr,##__VA_ARGS__)\r\n#define dump(x) cerr\
    \ << \"LINE\" << __LINE__ << \" : \" << #x << \" = {\";  \\\r\n\tfor(auto v: x)\
    \ cerr << v << \",\"; cerr << \"}\" << endl;\r\n#else\r\n#define show(x) void(0)\r\
    \n#define dump(x) void(0)\r\n#define shows(...) void(0)\r\n#endif\r\n\r\ntemplate<class\
    \ D> D divFloor(D a, D b){\r\n\treturn a / b - (((a ^ b) < 0 && a % b != 0) ?\
    \ 1 : 0);\r\n}\r\ntemplate<class D> D divCeil(D a, D b) {\r\n\treturn a / b +\
    \ (((a ^ b) > 0 && a % b != 0) ? 1 : 0);\r\n}\r\n#line 24 \"DP/smawk.hpp\"\ntemplate<class\
    \ Select>\nvector<int> smawk(int H, int W, Select select){\n\tauto rec = [&](auto&&\
    \ self, const vector<int>& hs, const vector<int>& ws) -> vector<int> {\n\t\tint\
    \ N = hs.size();\n\t\tif(N == 0) return {};\n\n\t\tvector<int> h2;\n\t\tfor(int\
    \ i=1;i<N;i+=2) h2.push_back(hs[i]);\n\n\t\tvector<int> w2;\n\t\tfor(int w: ws){\n\
    \t\t\twhile(!w2.empty() && select(hs[w2.size()-1], w2.back(), w)){\n\t\t\t\tw2.pop_back();\n\
    \t\t\t}\n\t\t\tif(w2.size() < N) w2.push_back(w);\n\t\t}\n\n\t\tvector<int> a2\
    \ = self(self, h2, w2);\n\t\tvector<int> ans(N);\n\t\trep(i,si(a2)) ans[i*2+1]\
    \ = a2[i];\n\t\tint j = 0;\n\t\tfor(int i=0;i<N;i+=2){\n\t\t\tans[i] = w2[j];\n\
    \t\t\tint end = i == N-1 ? w2.back() : ans[i+1];\n\t\t\twhile(w2[j] != end){\n\
    \t\t\t\tj++;\n\t\t\t\tif(select(hs[i], ans[i], w2[j])){\n\t\t\t\t\tans[i] = w2[j];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn ans;\n\t};\n\tvector<int> hs(H); iota(all(hs),0);\n\
    \tvector<int> ws(W); iota(all(ws),0);\n\treturn rec(rec,hs,ws);\n}\n#line 17 \"\
    DP/maxplus_convolution_b_concave.hpp\"\n\ntemplate<class T, bool is_max>\nvector<T>\
    \ maxplus_conv(const vector<T>& a, const vector<T>& b){\n\tint A = a.size(), B\
    \ = b.size();\n\tauto f = [&](int i, int j){\n\t\treturn a[j] + b[i-j];\n\t};\n\
    \tauto select = [&](int i, int j1, int j2){\n\t\tif(i < j2) return false;\n\t\t\
    if(i-j1 >= B) return true;\n\t\t// max plus convolution, b: concave\n\t\tif(is_max)\
    \ return f(i,j1) <= f(i,j2);\n\t\t// min plus convolution, b: convex\n\t\telse\
    \ return f(i,j1) >= f(i,j2);\n\t};\n\tvector<int> amax = smawk(A+B-1, A, select);\n\
    \tvector<T> c(A+B-1);\n\trep(i,A+B-1) c[i] = f(i, amax[i]);\n\treturn c;\n}\n\
    #line 16 \"DP/axiotis_tzamos_knapsack.hpp\"\n\ntemplate<class T>\nvector<T> knapsack(vector<pair<int,T>>\
    \ items, int W){\n\tvector<vector<T>> w2vs(W+1);\n\tfor(auto [w,v]: items){\n\t\
    \tif(w > W) continue;\n\t\tw2vs[w].push_back(v);\n\t}\n\tconst T inf = 1e18;\n\
    \tvector<T> dp(W+1, -inf); dp[0] = 0;\n\trep1(w,W) if(!w2vs[w].empty()){\n\t\t\
    auto& vs = w2vs[w];\n\t\tsort(all(vs),greater<T>());\n\t\tint K = min(W/w, si(vs));\n\
    \t\tV<T> b(K+1); rep(i,K) b[i+1] = b[i] + vs[i];\n\t\trep(r,w){\n\t\t\tint n =\
    \ (W-r)/w;\n\t\t\tV<T> a(n+1); rep(i,n+1) a[i] = dp[i*w+r];\n\t\t\tauto c = maxplus_conv<T,true>(a,b);\n\
    \t\t\trep(i,n+1) dp[i*w+r] = c[i];\n\t\t}\n\t}\n\treturn dp;\n}\n"
  code: "/*\n\t(w_i,v_i) \u3068 W \u304C\u4E0E\u3048\u3089\u308C\u308B\u306E\u3067\
    \ sum = w \u3067\u306E\u4FA1\u5024\u306E\u6700\u5927 dp[w] \u3092 w \\in [0,W]\
    \ \u306B\u3064\u3044\u3066\u6C42\u3081\u308B\n\t\u4E0D\u53EF\u80FD\u306A\u3089\
    \ dp[w] = -inf. T (v\u306Etype) \u306B\u3088\u3063\u3066 inf \u3092\u66F8\u304D\
    \u63DB\u3048\u308B\u3053\u3068\n\tv \u304C\u8CA0\u306B\u306A\u308B\u5834\u5408\
    \u3082\u52D5\u304F. \u305D\u306E\u5834\u5408\u306F -inf + v \u304C\u30A2\u30F3\
    \u30C0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u3088\u3046\u306B\u6CE8\u610F\
    \n\n\tO(W * (w_i\u306E\u7A2E\u985E\u6570))\n\n\tknapsack \u3059\u308B\u3068\u304D\
    \u306B\u3001w \u304C\u540C\u3058\u3084\u3064\u3092\u96C6\u3081\u3066\u540C\u6642\
    \u306B\u9077\u79FB\u3059\u308B\u3068\u3001mod w \u3054\u3068\u306B (max,+) convolution\
    \ \u306B\u306A\u308B\n\t\u8FFD\u52A0\u3059\u308B\u5074\u306F v \u3067\u30BD\u30FC\
    \u30C8\u3059\u308C\u3070 concave \u306B\u3067\u304D\u308B\u306E\u3067\u3001\u3053\
    \u308C\u306F\u7DDA\u5F62\u3067\u51FA\u6765\u308B\n\t\u3053\u308C\u3092\u4F7F\u3046\
    \u305F\u3081\u306B\u3001\u300C\u540C\u3058w\u306E\u3046\u3061v\u304C\u5927\u304D\
    \u3044\u65B9W/w\u500B\u300D\u307F\u305F\u3044\u306A\u306E\u3092\u5916\u5074\u3067\
    \u5217\u6319\u3059\u308B\u3053\u3068\u3082\u3042\u308B\n\n\tverify: https://contest.ucup.ac/submission/487402\n\
    */\n\n#include \"maxplus_convolution_b_concave.hpp\"\n\ntemplate<class T>\nvector<T>\
    \ knapsack(vector<pair<int,T>> items, int W){\n\tvector<vector<T>> w2vs(W+1);\n\
    \tfor(auto [w,v]: items){\n\t\tif(w > W) continue;\n\t\tw2vs[w].push_back(v);\n\
    \t}\n\tconst T inf = 1e18;\n\tvector<T> dp(W+1, -inf); dp[0] = 0;\n\trep1(w,W)\
    \ if(!w2vs[w].empty()){\n\t\tauto& vs = w2vs[w];\n\t\tsort(all(vs),greater<T>());\n\
    \t\tint K = min(W/w, si(vs));\n\t\tV<T> b(K+1); rep(i,K) b[i+1] = b[i] + vs[i];\n\
    \t\trep(r,w){\n\t\t\tint n = (W-r)/w;\n\t\t\tV<T> a(n+1); rep(i,n+1) a[i] = dp[i*w+r];\n\
    \t\t\tauto c = maxplus_conv<T,true>(a,b);\n\t\t\trep(i,n+1) dp[i*w+r] = c[i];\n\
    \t\t}\n\t}\n\treturn dp;\n}"
  dependsOn:
  - DP/maxplus_convolution_b_concave.hpp
  - DP/smawk.hpp
  - template.hpp
  isVerificationFile: false
  path: DP/axiotis_tzamos_knapsack.hpp
  requiredBy: []
  timestamp: '2024-09-05 20:28:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/axiotis_tzamos_knapsack.hpp
layout: document
redirect_from:
- /library/DP/axiotis_tzamos_knapsack.hpp
- /library/DP/axiotis_tzamos_knapsack.hpp.html
title: DP/axiotis_tzamos_knapsack.hpp
---
