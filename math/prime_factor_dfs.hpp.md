---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime.hpp
    title: math/prime.hpp
  - icon: ':heavy_check_mark:'
    path: math/prime_sum.hpp
    title: math/prime_sum.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/xmascon19/submissions/60620907
    - https://contest.ucup.ac/submission/807529
  bundledCode: "#line 1 \"math/prime_sum.hpp\"\n/*\n\tf: \u5B8C\u5168\u4E57\u6CD5\u7684\
    \ \u306B\u5BFE\u3057\u3001G(n) = \\sum_{p <= n} f(p) \u3092\u307F\u305F\u3059\
    \ G \u3092\u6C42\u3081\u308B\n\tF \u304C\u6C42\u307E\u3063\u3066\u3044\u308B\u5FC5\
    \u8981\u304C\u3042\u308B\n\n\t\u305F\u3060\u3057\u5927\u6587\u5B57\u306F\u5BFE\
    \u5FDC\u3059\u308B\u7D2F\u7A4D\u548C\u3092\u6307\u3059\u3002\n\t\u307E\u305F\u3001\
    \"A \u304C\u6C42\u307E\u3063\u3066\u3044\u308B\" \u3068\u306F\u3001O(sqrt(N))\
    \ \u500B\u306E n \\in {[N/i}} \u306B\u5BFE\u3057\u3066 A(n) = a(1) + .. + a(n)\
    \ \u304C\u6C42\u307E\u3063\u3066\u3044\u308B\u3053\u3068\u3092\u3044\u3046\n\n\
    \t\u4F7F\u3044\u65B9:\n\t\t\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306B N\
    \ \u3068 F \u3092\u6E21\u3059\n\t\tF \u306F n \\in {[N/i]} \u306B F(n) \u3067\u30A2\
    \u30AF\u30BB\u30B9\u3057\u305F\u3068\u304D\u306B\u6B63\u3057\u3044\u5024\u3092\
    \u8FD4\u3059\u5FC5\u8981\u304C\u3042\u308B\n\t\t\u30E9\u30E0\u30C0\u5F0F\u3092\
    \u6E21\u3057\u305F\u308A\u3001\u4ED6\u306E\u7D2F\u7A4D\u548C\u304C \"\u6C42\u307E\
    \u3063\u3066\u3044\u308B\" \u3088\u3046\u306A struct \u3092\u6E21\u3057\u305F\u308A\
    \n\n\t\u5177\u4F53\u4F8B:\n\t- \u7D20\u6570\u30AB\u30A6\u30F3\u30C8: f(n) = 1,\
    \ \u3064\u307E\u308A F(n) = n \u3092\u6E21\u3059\n\t- \u7D20\u6570sum: f(n) =\
    \ n, \u3064\u307E\u308A F(n) = n(n+1)/2 \u3092\u6E21\u3059\n\t- mod 6 \u3067 5\
    \ \u306B\u306A\u308B\u7D20\u6570\u30AB\u30A6\u30F3\u30C8: f(n) = (n%6 == 5) \u3067\
    \u306F\u4E57\u6CD5\u7684\u3067\u3059\u3089\u306A\u3044\u306E\u3067\u30C0\u30E1\
    \n\t\tf \u306F\u5B8C\u5168\u4E57\u6CD5\u7684\u3067\u306A\u3051\u308C\u3070\u306A\
    \u3089\u306A\u3044\u306E\u3067 f(p) \u3092\u6C7A\u3081\u308C\u3070\u6C7A\u307E\
    \u308B\n\t\tf(p) = 0 if p = 2,3\n\t\tf(p) = 1 if p mod 6 = 1\n\t\tf(p) = -1 if\
    \ p mod 6 = 5\n\t\t\u3068\u5B9A\u7FA9\u3059\u308C\u3070\u3001f(n) \u304C n mod\
    \ 6 = 1 \u306A\u3089 1, n mod 6 = 5 \u306A\u3089 -1, \u305D\u308C\u4EE5\u5916\u306A\
    \u3089 0 \u306B\u306A\u308B\u306E\u3067\u3001F \u3092\u7C21\u5358\u306B\u6C42\u3081\
    \u3089\u308C\u308B\n\t\t\u3053\u308C\u3067 (mod6 \u3067 1 \u306E\u500B\u6570)\
    \ - (mod6 \u3067 5 \u306E\u500B\u6570) \u304C\u6C42\u307E\u308B\u306E\u3067\u3001\
    + \u304C\u666E\u901A\u306E\u7D20\u6570\u30AB\u30A6\u30F3\u30C8\u306A\u306E\u3068\
    \u5408\u308F\u305B\u308B\u3068\u6C42\u307E\u308B\n\t- \u540C\u69D8\u306B mod m\
    \ \u3067 r \u3082\u9811\u5F35\u308C\u3070\u3067\u304D\u308B\u3001Z/mZ \u306E\u4E57\
    \u6CD5\u7FA4\u304C Z/p^kZ \u306E\u4E57\u6CD5\u7FA4\u306E\u76F4\u7A4D\u307F\u305F\
    \u3044\u306B\u306A\u3063\u3066\u3001\u305D\u308C\u305E\u308C\u3067 Lagrange resolvent\
    \ \u307F\u305F\u3044\u306A\u306E\u3092\u53D6\u3063\u3066\u76F4\u7A4D\u307F\u305F\
    \u3044\u306A\u306E\u3092\u3084\u308C\u3070\u3044\u3051\u308B \u3081\u3093\u3069\
    \u305D\u3046\n\n\t\u8A08\u7B97\u91CF: O(N^{3/4}/logN) time, O(N^{1/2}) space\n\
    \tN = 10^11: 0.4s, N = 10^12: 2s \u304F\u3089\u3044 (prime count, -O3)\n*/\n\n\
    #line 1 \"math/prime.hpp\"\nV<bool> isp;\nV<int> pr;\nV<int> sf; //smallest factor,\
    \ sf[9*5*11] = 3\nV<int> mu;\t//[1,-1,0,0,...]\nV<int> tot;\t//[1,p-1,(p-1)p,(p-1)p^2,..]\n\
    V<int> sig;\t// [1,1+p,1+p+p^2,...]\nvoid linear_sieve(int X){\t\t// <= X\n\t\
    isp = V<bool>(X+1,true); isp[0] = isp[1] = false;\n\tsf = V<int>(X+1);\n\tpr.clear();\n\
    \tfor(int i=2;i<=X;i++){\n\t\tif(isp[i]){\n\t\t\tpr.pb(i);\n\t\t\tsf[i] = i;\n\
    \t\t}\n\t\tfor(int j=0;i*pr[j]<=X;j++){\n\t\t\tisp[i*pr[j]] = false;\n\t\t\tsf[i*pr[j]]\
    \ = pr[j];\n\t\t\tif(i%pr[j] == 0) break;\n\t\t}\n\t}\n\t// mu = V<int>(X+1);\n\
    \t// mu[1] = 1;\n\t// for(int i=2;i<=X;i++){\n\t// \tint p = sf[i];\n\t// \tif(i/p%p\
    \ == 0) mu[i] = 0;\n\t// \telse mu[i] = -mu[i/p];\n\t// }\n\t// tot = V<int>(X+1);\n\
    \t// tot[1] = 1;\n\t// for(int i=2;i<=X;i++){\n\t// \tint p = sf[i];\n\t// \t\
    if(i/p%p == 0) tot[i] = tot[i/p] * p;\n\t// \telse tot[i] = tot[i/p] * (p-1);\n\
    \t// }\n\t// sig = V<int>(X+1);\n\t// sig[1] = 1;\n\t// for(int i=2;i<=X;i++){\n\
    \t// \tint p = sf[i];\n\t// \tint x = i;\n\t// \tint w = 1;\n\t// \twhile(x%p\
    \ == 0){\n\t// \t\tx /= p; w = w*p+1;\n\t// \t}\n\t// \tsig[i] = sig[x] * w;\n\
    \t// }\n}\n#line 30 \"math/prime_sum.hpp\"\n\ntemplate <class T>\nstruct PrimeSum\
    \ {\n\tll N,sq;\n\tvector<T> small,large;\n\n\ttemplate <class Func>\n\tPrimeSum(ll\
    \ N_, const Func F) : N(N_), sq(sqrtl(N_)) {\n\t\tlinear_sieve(sq);\n\t\tsmall.resize(sq+1);\
    \ large.resize(sq+1);\n\t\trep1(n,sq) small[n] = F(n) - 1;\n\t\trep1(n,sq) large[n]\
    \ = F(N/n) - 1;\n\t\tfor(ll p: pr){\n\t\t\tint R = min(sq, N/(p*p));\n\t\t\tint\
    \ M = sq/p;\n\t\t\tT x = small[p-1];\n\t\t\tT fp = small[p] - small[p-1];\n\t\t\
    \trep1(n,M) large[n] -= fp * (large[n*p] - x);\n\t\t\tfor(int n=M+1;n<=R;n++)\
    \ large[n] -= fp * (small[N/(n*p)] - x);\n\t\t\tfor(int n=sq;n>=p*p;n--) small[n]\
    \ -= fp * (small[n/p] - x);\n\t\t}\n\t}\n\n\tT& operator()(ll n){\n\t\treturn\
    \ (n <= sq ? small[n] : large[N/n]);\n\t}\n};\n#line 2 \"math/prime_factor_dfs.hpp\"\
    \n\n/*\n\t1,..,N \u3092\u9802\u70B9\u3068\u3059\u308B\u30011 \u3092\u6839\u3068\
    \u3059\u308B\u4EE5\u4E0B\u306E\u3088\u3046\u306A\u6839\u4ED8\u304D\u6728\u3092\
    \u8003\u3048\u308B\n\tpar[v] = v / (greatest factor of v) \u9006\u306B 1 \u304B\
    \u3089\u898B\u308B\u3068 \u6700\u5C0F\u306E\u7D20\u56E0\u6570\u3092\u304B\u3051\
    \u3066\u3044\u304F\u3053\u3068\u3067 v \u3092\u4F5C\u308B\n\t - \u4F8B\u3048\u3070\
    \ 12 \u307E\u3067\u306E path \u306F\u3001 1 -> 2 -> 4 -> 12\n\n\t\u3053\u306E\u6728\
    \u3092\u63A2\u7D22\u3059\u308B\u3002\u305F\u3060\u3057\u8449\u306B\u306F\u76F4\
    \u63A5\u30A2\u30AF\u30BB\u30B9\u3057\u306A\u3044(\u305D\u306E\u89AA\u3067\u305D\
    \u3044\u3064\u3089\u3092\u51E6\u7406\u3059\u308B)\n\t - \u4F8B\u3048\u3070\u3001\
    v = 2*2*3*7 \u306E\u5B50\u306F v*7, v*11, v*13, .. v * ([N/v] \u4EE5\u4E0B\u306E\
    \u6700\u5927\u306E\u7D20\u6570)\n\t - v * p^2 > N \u306A\u3089\u3070\u3001v *\
    \ p \u306F\u8449\u306B\u306A\u308B\u306E\u3067\u3001v \u3067\u51E6\u7406\u3059\
    \u3079\u304D\u8449\u306F\u3001v * ( [sqrt(N/v)]+1 \u4EE5\u4E0A\u306E\u6700\u5C0F\
    \u306E\u7D20\u6570), v * prime, .. , v * ([N/v] \u4EE5\u4E0B\u306E\u6700\u5927\
    \u306E\u7D20\u6570)\n\t - \u3061\u3087\u3063\u3068\u5618\u3067\u3001\u4F8B\u3048\
    \u3070\u3053\u306E\u5217\u6319\u306E\u4E2D\u306B v*5 \u3068\u304B\u5165\u3063\u3066\
    \u305F\u3089\u3001\u305D\u308C\u306F\u898B\u3061\u3083\u30C0\u30E1\u306A\u306E\
    \u3067\u3046\u307E\u304F\u3084\u308B\n\t\u7D50\u5C40\u3001v \u3067\u51E6\u7406\
    \u3059\u3079\u304D\u5024\u306F\n\t - v \u81EA\u8EAB\n\t - v * { prime in (L,R]\
    \ }\n\t - \u305F\u3060\u3057 L = max([sqrt(N/v)], pr[l-1]) R = [N/v]\n\t - L \u3082\
    \ R \u3082 \u96C6\u5408 {[N/i]} \u306B\u542B\u307E\u308C\u308B\u306E\u3067\u3001\
    \u5404 x \\in {[N/i]} \u306B\u3064\u3044\u3066 { v * p | p: prime <= x} \u306B\
    \u3064\u3044\u3066\u4E00\u6C17\u306B\u51E6\u7406\u3067\u304D\u308B\u3088\u3046\
    \u3067\u306A\u3051\u308C\u3070\u3044\u3051\u306A\u3044\n\t\t(L \u306B\u95A2\u3057\
    \u3066\u306F\u3001L <= sqrt(N) \u306A\u306E\u3067\u542B\u307E\u308C\u308B\u3053\
    \u3068\u304C\u308F\u304B\u308B)\n\n\t\u554F\u984C\u306B\u3088\u3063\u3066dfs\u306E\
    \u4E2D\u3067\u3084\u308B\u3053\u3068\u304C\u307E\u3061\u307E\u3061\u306A\u306E\
    \u3067\u3001\u5177\u4F53\u4F8B\u3092\u3044\u304F\u3064\u304B\u7F6E\u3044\u3066\
    \u304A\u3044\u3066\u76F4\u63A5\u3044\u3058\u308B\u3068\u3044\u3046\u5F62\u306B\
    \u3057\u305F\u3044\u3068\u601D\u3044\u307E\u3059\n*/\n\n/*\n\t\u4F8B1: \u6307\u6570\
    \u5217 (2 * 5^2 * 7 -> [1,2,1]) \u3054\u3068\u306B\u4F55\u304B\u3092\u3059\u308B\
    \n\n\tdfs \u3067 es \u3092\u7BA1\u7406\u3059\u308B\n\t\t\u76F4\u524D\u306B\u8FFD\
    \u52A0\u3057\u305F\u5024\u3068\u6BD4\u8F03\u3057\u305F\u308A\u3067\u3084\u3084\
    \u9762\u5012\n\n\tdoit(es, num) \u3067 es \u3092 num \u500B\u51E6\u7406\n\n\t\
    verify: ucup-3-20 F https://contest.ucup.ac/submission/807529\n\t10^9: 0.3s, 10^10:\
    \ 2s\n*/\n\nvoid prime_factor_dfs(ll N){\n\tPrimeSum<ll> A(N, [](ll n){return\
    \ n;});\t// prime count\n\n\tvector<ll> cnt(20);\n\tauto doit = [&](vector<int>\
    \ es, ll num){\n\t\tcnt[si(es)] += num;\n\t};\n\n\t/*\n\t\t\u4ECA v, \u6B21 p[l]\
    \ \u4EE5\u4E0A\u3092\u8FFD\u52A0\u53EF\u80FD\n\t*/\n\tauto dfs = [&](auto& self,\
    \ ll v, int l, vector<int>& es) -> void {\n\t\t// TODO: v \u306B\u3064\u3044\u3066\
    \u51E6\u7406\n\t\tdoit(es, 1);\n\t\t\n\t\t// TODO: v * {prime in (L,R]} \u306B\
    \u3064\u3044\u3066\u51E6\u7406\n\t\tll L = sqrtl(N/v), R = N/v;\n\t\tchmax(L,\
    \ l == 0 ? 0 : pr[l-1]);\n\t\tll pnum = A(R) - A(L);\n\t\tif(pnum){\n\t\t\tif(v\
    \ != 1 && L < pr[l]){\n\t\t\t\t// \u6700\u5F8C\u306E\u7D20\u56E0\u6570\u304C\u3082\
    \u3046\u4E00\u500B\u5897\u3048\u308B\n\t\t\t\tes.back()++;\n\t\t\t\tdoit(es, 1);\n\
    \t\t\t\tpnum--;\n\t\t\t\tes.back()--;\n\t\t\t}\n\t\t\tes.emplace_back(1);\n\t\t\
    \tdoit(es, pnum);\n\t\t\tes.pop_back();\n\t\t}\n\n\t\tfor(int i=l;i<si(pr);i++){\n\
    \t\t\tll p = pr[i];\n\t\t\tif(p > L) break;\n\t\t\t// v * p \\in [pr[l], L] \u306B\
    \u9077\u79FB\n\t\t\tif(v != 1 && i == l){\n\t\t\t\t// \u6700\u5F8C\u306E\u7D20\
    \u56E0\u6570\u304C\u3082\u3046\u4E00\u500B\u5897\u3048\u308B\n\t\t\t\tes.back()++;\n\
    \t\t\t\tself(self, v*p, i, es);\n\t\t\t\tes.back()--;\n\t\t\t}else{\n\t\t\t\t\
    es.emplace_back(1);\n\t\t\t\tself(self, v*p, i, es);\n\t\t\t\tes.pop_back();\n\
    \t\t\t}\n\t\t}\n\t};\n\tvector<int> es;\n\tdfs(dfs, 1, 0, es);\n\n\tmint ans =\
    \ 1;\n\trep1(i,si(cnt)-1) ans *= mint(i).pow(cnt[i]);\n\tcout << ans << endl;\n\
    }\n\n/*\n\t\u4F8B2: \u7D20\u56E0\u6570\u306E\u500B\u6570(2^3 * 3^10 -> 13) \u306E\
    \u5206\u5E03\n\n\tdfs \u3067\u306F ecnt \u3092\u6301\u3064\u3060\u3051\n\n\tverify:\
    \ Xmas Contest 2019 D,E https://atcoder.jp/contests/xmascon19/submissions/60620907\n\
    */\n\nvoid prime_factor_dfs(ll N){\n\tPrimeSum<ll> A(N, [](ll n){return n;});\t\
    // prime count\n\n\tvector<ll> cnt(40);\n\tauto doit = [&](int ecnt, ll num){\n\
    \t\tcnt[ecnt] += num;\n\t};\n\n\t/*\n\t\t\u4ECA v, \u6B21 p[l] \u4EE5\u4E0A\u3092\
    \u8FFD\u52A0\u53EF\u80FD\n\t*/\n\tauto dfs = [&](auto& self, ll v, int l, int\
    \ ecnt) -> void {\n\t\t// TODO: v \u306B\u3064\u3044\u3066\u51E6\u7406\n\t\tdoit(ecnt,\
    \ 1);\n\t\t\n\t\t// TODO: v * {prime in (L,R]} \u306B\u3064\u3044\u3066\u51E6\u7406\
    \n\t\tll L = sqrtl(N/v), R = N/v;\n\t\tchmax(L, l == 0 ? 0 : pr[l-1]);\n\t\tll\
    \ pnum = A(R) - A(L);\n\t\tdoit(ecnt+1, pnum);\n\n\t\tfor(int i=l;i<si(pr);i++){\n\
    \t\t\tll p = pr[i];\n\t\t\tif(p > L) break;\n\t\t\t// v * p \\in [pr[l], L] \u306B\
    \u9077\u79FB\n\t\t\tself(self, v*p, i, ecnt+1);\n\t\t}\n\t};\n\tdfs(dfs, 1, 0,\
    \ 0);\n\n\tll ans = 0;\n\trep(i,si(cnt)) ans += i * cnt[i];\n\tcout << ans <<\
    \ endl;\n}\n\n/*\n\t\u4F8B3: N \u4EE5\u4E0B\u306E\u6B63\u6574\u6570\u306E\u548C\
    \ (\u306F?)\n\tN = 10^10: 0.3s, N = 10^11: 1.3s, N = 10^12: 7s\n*/\n\nvoid prime_factor_dfs(ll\
    \ N){\n\tPrimeSum<mint> A(N, [](ll n){return (n+1)*n/2;});\t// prime sum\n\n\t\
    /*\n\t\t\u4ECA v, \u6B21 p[l] \u4EE5\u4E0A\u3092\u8FFD\u52A0\u53EF\u80FD\n\t*/\n\
    \tmint ans = 0;\n\tauto dfs = [&](auto& self, ll v, int l) -> void {\n\t\t// TODO:\
    \ v \u306B\u3064\u3044\u3066\u51E6\u7406\n\t\tans += v;\n\t\t\n\t\t// TODO: v\
    \ * {prime in (L,R]} \u306B\u3064\u3044\u3066\u51E6\u7406\n\t\tll L = sqrtl(N/v),\
    \ R = N/v;\n\t\tchmax(L, l == 0 ? 0 : pr[l-1]);\n\t\tmint sum = A(R) - A(L);\n\
    \t\tans += v * sum;\n\n\t\tfor(int i=l;i<si(pr);i++){\n\t\t\tll p = pr[i];\n\t\
    \t\tif(p > L) break;\n\t\t\t// v * p \\in [pr[l], L] \u306B\u9077\u79FB\n\t\t\t\
    self(self, v*p, i);\n\t\t}\n\t};\n\tdfs(dfs, 1, 0);\n\tcout << ans << endl;\n\
    }\n"
  code: "#include \"math/prime_sum.hpp\"\n\n/*\n\t1,..,N \u3092\u9802\u70B9\u3068\u3059\
    \u308B\u30011 \u3092\u6839\u3068\u3059\u308B\u4EE5\u4E0B\u306E\u3088\u3046\u306A\
    \u6839\u4ED8\u304D\u6728\u3092\u8003\u3048\u308B\n\tpar[v] = v / (greatest factor\
    \ of v) \u9006\u306B 1 \u304B\u3089\u898B\u308B\u3068 \u6700\u5C0F\u306E\u7D20\
    \u56E0\u6570\u3092\u304B\u3051\u3066\u3044\u304F\u3053\u3068\u3067 v \u3092\u4F5C\
    \u308B\n\t - \u4F8B\u3048\u3070 12 \u307E\u3067\u306E path \u306F\u3001 1 -> 2\
    \ -> 4 -> 12\n\n\t\u3053\u306E\u6728\u3092\u63A2\u7D22\u3059\u308B\u3002\u305F\
    \u3060\u3057\u8449\u306B\u306F\u76F4\u63A5\u30A2\u30AF\u30BB\u30B9\u3057\u306A\
    \u3044(\u305D\u306E\u89AA\u3067\u305D\u3044\u3064\u3089\u3092\u51E6\u7406\u3059\
    \u308B)\n\t - \u4F8B\u3048\u3070\u3001v = 2*2*3*7 \u306E\u5B50\u306F v*7, v*11,\
    \ v*13, .. v * ([N/v] \u4EE5\u4E0B\u306E\u6700\u5927\u306E\u7D20\u6570)\n\t -\
    \ v * p^2 > N \u306A\u3089\u3070\u3001v * p \u306F\u8449\u306B\u306A\u308B\u306E\
    \u3067\u3001v \u3067\u51E6\u7406\u3059\u3079\u304D\u8449\u306F\u3001v * ( [sqrt(N/v)]+1\
    \ \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u7D20\u6570), v * prime, .. , v * ([N/v]\
    \ \u4EE5\u4E0B\u306E\u6700\u5927\u306E\u7D20\u6570)\n\t - \u3061\u3087\u3063\u3068\
    \u5618\u3067\u3001\u4F8B\u3048\u3070\u3053\u306E\u5217\u6319\u306E\u4E2D\u306B\
    \ v*5 \u3068\u304B\u5165\u3063\u3066\u305F\u3089\u3001\u305D\u308C\u306F\u898B\
    \u3061\u3083\u30C0\u30E1\u306A\u306E\u3067\u3046\u307E\u304F\u3084\u308B\n\t\u7D50\
    \u5C40\u3001v \u3067\u51E6\u7406\u3059\u3079\u304D\u5024\u306F\n\t - v \u81EA\u8EAB\
    \n\t - v * { prime in (L,R] }\n\t - \u305F\u3060\u3057 L = max([sqrt(N/v)], pr[l-1])\
    \ R = [N/v]\n\t - L \u3082 R \u3082 \u96C6\u5408 {[N/i]} \u306B\u542B\u307E\u308C\
    \u308B\u306E\u3067\u3001\u5404 x \\in {[N/i]} \u306B\u3064\u3044\u3066 { v * p\
    \ | p: prime <= x} \u306B\u3064\u3044\u3066\u4E00\u6C17\u306B\u51E6\u7406\u3067\
    \u304D\u308B\u3088\u3046\u3067\u306A\u3051\u308C\u3070\u3044\u3051\u306A\u3044\
    \n\t\t(L \u306B\u95A2\u3057\u3066\u306F\u3001L <= sqrt(N) \u306A\u306E\u3067\u542B\
    \u307E\u308C\u308B\u3053\u3068\u304C\u308F\u304B\u308B)\n\n\t\u554F\u984C\u306B\
    \u3088\u3063\u3066dfs\u306E\u4E2D\u3067\u3084\u308B\u3053\u3068\u304C\u307E\u3061\
    \u307E\u3061\u306A\u306E\u3067\u3001\u5177\u4F53\u4F8B\u3092\u3044\u304F\u3064\
    \u304B\u7F6E\u3044\u3066\u304A\u3044\u3066\u76F4\u63A5\u3044\u3058\u308B\u3068\
    \u3044\u3046\u5F62\u306B\u3057\u305F\u3044\u3068\u601D\u3044\u307E\u3059\n*/\n\
    \n/*\n\t\u4F8B1: \u6307\u6570\u5217 (2 * 5^2 * 7 -> [1,2,1]) \u3054\u3068\u306B\
    \u4F55\u304B\u3092\u3059\u308B\n\n\tdfs \u3067 es \u3092\u7BA1\u7406\u3059\u308B\
    \n\t\t\u76F4\u524D\u306B\u8FFD\u52A0\u3057\u305F\u5024\u3068\u6BD4\u8F03\u3057\
    \u305F\u308A\u3067\u3084\u3084\u9762\u5012\n\n\tdoit(es, num) \u3067 es \u3092\
    \ num \u500B\u51E6\u7406\n\n\tverify: ucup-3-20 F https://contest.ucup.ac/submission/807529\n\
    \t10^9: 0.3s, 10^10: 2s\n*/\n\nvoid prime_factor_dfs(ll N){\n\tPrimeSum<ll> A(N,\
    \ [](ll n){return n;});\t// prime count\n\n\tvector<ll> cnt(20);\n\tauto doit\
    \ = [&](vector<int> es, ll num){\n\t\tcnt[si(es)] += num;\n\t};\n\n\t/*\n\t\t\u4ECA\
    \ v, \u6B21 p[l] \u4EE5\u4E0A\u3092\u8FFD\u52A0\u53EF\u80FD\n\t*/\n\tauto dfs\
    \ = [&](auto& self, ll v, int l, vector<int>& es) -> void {\n\t\t// TODO: v \u306B\
    \u3064\u3044\u3066\u51E6\u7406\n\t\tdoit(es, 1);\n\t\t\n\t\t// TODO: v * {prime\
    \ in (L,R]} \u306B\u3064\u3044\u3066\u51E6\u7406\n\t\tll L = sqrtl(N/v), R = N/v;\n\
    \t\tchmax(L, l == 0 ? 0 : pr[l-1]);\n\t\tll pnum = A(R) - A(L);\n\t\tif(pnum){\n\
    \t\t\tif(v != 1 && L < pr[l]){\n\t\t\t\t// \u6700\u5F8C\u306E\u7D20\u56E0\u6570\
    \u304C\u3082\u3046\u4E00\u500B\u5897\u3048\u308B\n\t\t\t\tes.back()++;\n\t\t\t\
    \tdoit(es, 1);\n\t\t\t\tpnum--;\n\t\t\t\tes.back()--;\n\t\t\t}\n\t\t\tes.emplace_back(1);\n\
    \t\t\tdoit(es, pnum);\n\t\t\tes.pop_back();\n\t\t}\n\n\t\tfor(int i=l;i<si(pr);i++){\n\
    \t\t\tll p = pr[i];\n\t\t\tif(p > L) break;\n\t\t\t// v * p \\in [pr[l], L] \u306B\
    \u9077\u79FB\n\t\t\tif(v != 1 && i == l){\n\t\t\t\t// \u6700\u5F8C\u306E\u7D20\
    \u56E0\u6570\u304C\u3082\u3046\u4E00\u500B\u5897\u3048\u308B\n\t\t\t\tes.back()++;\n\
    \t\t\t\tself(self, v*p, i, es);\n\t\t\t\tes.back()--;\n\t\t\t}else{\n\t\t\t\t\
    es.emplace_back(1);\n\t\t\t\tself(self, v*p, i, es);\n\t\t\t\tes.pop_back();\n\
    \t\t\t}\n\t\t}\n\t};\n\tvector<int> es;\n\tdfs(dfs, 1, 0, es);\n\n\tmint ans =\
    \ 1;\n\trep1(i,si(cnt)-1) ans *= mint(i).pow(cnt[i]);\n\tcout << ans << endl;\n\
    }\n\n/*\n\t\u4F8B2: \u7D20\u56E0\u6570\u306E\u500B\u6570(2^3 * 3^10 -> 13) \u306E\
    \u5206\u5E03\n\n\tdfs \u3067\u306F ecnt \u3092\u6301\u3064\u3060\u3051\n\n\tverify:\
    \ Xmas Contest 2019 D,E https://atcoder.jp/contests/xmascon19/submissions/60620907\n\
    */\n\nvoid prime_factor_dfs(ll N){\n\tPrimeSum<ll> A(N, [](ll n){return n;});\t\
    // prime count\n\n\tvector<ll> cnt(40);\n\tauto doit = [&](int ecnt, ll num){\n\
    \t\tcnt[ecnt] += num;\n\t};\n\n\t/*\n\t\t\u4ECA v, \u6B21 p[l] \u4EE5\u4E0A\u3092\
    \u8FFD\u52A0\u53EF\u80FD\n\t*/\n\tauto dfs = [&](auto& self, ll v, int l, int\
    \ ecnt) -> void {\n\t\t// TODO: v \u306B\u3064\u3044\u3066\u51E6\u7406\n\t\tdoit(ecnt,\
    \ 1);\n\t\t\n\t\t// TODO: v * {prime in (L,R]} \u306B\u3064\u3044\u3066\u51E6\u7406\
    \n\t\tll L = sqrtl(N/v), R = N/v;\n\t\tchmax(L, l == 0 ? 0 : pr[l-1]);\n\t\tll\
    \ pnum = A(R) - A(L);\n\t\tdoit(ecnt+1, pnum);\n\n\t\tfor(int i=l;i<si(pr);i++){\n\
    \t\t\tll p = pr[i];\n\t\t\tif(p > L) break;\n\t\t\t// v * p \\in [pr[l], L] \u306B\
    \u9077\u79FB\n\t\t\tself(self, v*p, i, ecnt+1);\n\t\t}\n\t};\n\tdfs(dfs, 1, 0,\
    \ 0);\n\n\tll ans = 0;\n\trep(i,si(cnt)) ans += i * cnt[i];\n\tcout << ans <<\
    \ endl;\n}\n\n/*\n\t\u4F8B3: N \u4EE5\u4E0B\u306E\u6B63\u6574\u6570\u306E\u548C\
    \ (\u306F?)\n\tN = 10^10: 0.3s, N = 10^11: 1.3s, N = 10^12: 7s\n*/\n\nvoid prime_factor_dfs(ll\
    \ N){\n\tPrimeSum<mint> A(N, [](ll n){return (n+1)*n/2;});\t// prime sum\n\n\t\
    /*\n\t\t\u4ECA v, \u6B21 p[l] \u4EE5\u4E0A\u3092\u8FFD\u52A0\u53EF\u80FD\n\t*/\n\
    \tmint ans = 0;\n\tauto dfs = [&](auto& self, ll v, int l) -> void {\n\t\t// TODO:\
    \ v \u306B\u3064\u3044\u3066\u51E6\u7406\n\t\tans += v;\n\t\t\n\t\t// TODO: v\
    \ * {prime in (L,R]} \u306B\u3064\u3044\u3066\u51E6\u7406\n\t\tll L = sqrtl(N/v),\
    \ R = N/v;\n\t\tchmax(L, l == 0 ? 0 : pr[l-1]);\n\t\tmint sum = A(R) - A(L);\n\
    \t\tans += v * sum;\n\n\t\tfor(int i=l;i<si(pr);i++){\n\t\t\tll p = pr[i];\n\t\
    \t\tif(p > L) break;\n\t\t\t// v * p \\in [pr[l], L] \u306B\u9077\u79FB\n\t\t\t\
    self(self, v*p, i);\n\t\t}\n\t};\n\tdfs(dfs, 1, 0);\n\tcout << ans << endl;\n\
    }\n"
  dependsOn:
  - math/prime_sum.hpp
  - math/prime.hpp
  isVerificationFile: false
  path: math/prime_factor_dfs.hpp
  requiredBy: []
  timestamp: '2024-12-10 06:10:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime_factor_dfs.hpp
layout: document
redirect_from:
- /library/math/prime_factor_dfs.hpp
- /library/math/prime_factor_dfs.hpp.html
title: math/prime_factor_dfs.hpp
---
