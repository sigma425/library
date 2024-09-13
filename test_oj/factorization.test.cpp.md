---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/factorization.hpp
    title: math/factorization.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test_oj/factorization.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n#line 2 \"template.hpp\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\
    \nusing ll = long long;\r\nusing uint = unsigned int;\r\nusing ull = unsigned\
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
    \ b) {\r\n\treturn a / b + (((a ^ b) > 0 && a % b != 0) ? 1 : 0);\r\n}\r\n#line\
    \ 1 \"math/factorization.hpp\"\n/*\r\n\t\u7D20\u56E0\u6570\u5206\u89E3 1 <= n\
    \ <= 10^18\r\n\tpollard_rho's algorithm\r\n\tO(n^0.25 polylog(n)) \u304F\u3089\
    \u3044\u3089\u3057\u3044\r\n*/\r\n\r\ntemplate<class T>\r\nT gcd(T a,T b){\r\n\
    \ta = abs(a), b = abs(b);\r\n\tif(b==0) return a;\r\n\treturn gcd(b,a%b);\r\n\
    }\r\ntemplate<class T, class U>\r\nT pow_mod(T x, U p, T mod){\r\n\tassert(p>=0);\r\
    \n\tx %= mod;\r\n\tT a = 1 % mod;\r\n\twhile(p){\r\n\t\tif(p&1) a = a*x%mod;\r\
    \n\t\tx = x*x%mod;\r\n\t\tp >>= 1;\r\n\t}\r\n\treturn a;\r\n}\r\nusing ll = long\
    \ long;\r\nbool isprime(ll n){\r\n\tif(n<=1) return 0;\r\n\tif(n==2) return 1;\r\
    \n\tif(n%2==0) return 0;\r\n\tll d = n-1;\r\n\twhile(d%2==0) d/=2;\r\n\tstatic\
    \ const vector<ll> alist{2,3,5,7,11,13,17,19,23,29,31,37};\r\n\tfor(ll a: alist){\r\
    \n\t\tif(n<=a) break;\r\n\t\tll t = d;\r\n\t\tll y = pow_mod<__int128>(a,t,n);\r\
    \n\t\twhile(t!=n-1 && y!=1 && y!=n-1){\r\n\t\t\ty = __int128(y)*y%n;\r\n\t\t\t\
    t<<=1;\r\n\t\t}\r\n\t\tif(y!=n-1 && t%2==0) return 0;\r\n\t}\r\n\treturn 1;\r\n\
    }\r\n\r\nll pollard_single(ll n){\r\n\tif(isprime(n)) return n;\r\n\tif(!(n&1))\
    \ return 2;\r\n\tll ph,x,y,p;\r\n\tauto f = [&](ll x, ll n){ return (__int128(x)*x+ph)%n;\
    \ };\r\n\tfor(ph=1;;ph++){\r\n\t\tx=ph; y=f(x,n); p=gcd(y-x,n);\r\n\t\twhile(p==1){\r\
    \n\t\t\tx=f(x,n); y=f(f(y,n),n); p=gcd((y-x+n)%n,n)%n;\r\n\t\t}\r\n\t\tif(p==0\
    \ || p==n) continue;\r\n\t\treturn p;\r\n\t}\r\n\tassert(0);\r\n}\r\n\r\nvector<ll>\
    \ pollard(ll n){\r\n\tif(n==1) return {};\r\n\tll x = pollard_single(n);\r\n\t\
    if(x==n) return {x};\r\n\tvector<ll> le = pollard(x);\r\n\tvector<ll> ri = pollard(n/x);\r\
    \n\tfor(ll d: ri) le.push_back(d);\r\n\tsort(all(le));\r\n\treturn le;\r\n}\r\n\
    \r\nll totient(ll n){\r\n\tauto v = pollard(n);\r\n\tmap<ll,int> mp; for(ll p:\
    \ v) mp[p]++;\r\n\tll phi = 1;\r\n\tfor(auto [p,r]: mp){\r\n\t\tfor(int _=0;_<r-1;_++)\
    \ phi *= p;\r\n\t\tphi *= p-1;\r\n\t}\r\n\treturn phi;\r\n}\r\n#line 4 \"test_oj/factorization.test.cpp\"\
    \n\nint main(){\n\tint Q; cin >> Q;\n\twhile(Q--){\n\t\tll a; cin >> a;\n\t\t\
    auto ps = pollard(a);\n\t\tcout << si(ps);\n\t\tfor(ll p: ps) cout << \" \" <<\
    \ p;\n\t\tcout << endl;\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n#include \"\
    template.hpp\"\n#include \"math/factorization.hpp\"\n\nint main(){\n\tint Q; cin\
    \ >> Q;\n\twhile(Q--){\n\t\tll a; cin >> a;\n\t\tauto ps = pollard(a);\n\t\tcout\
    \ << si(ps);\n\t\tfor(ll p: ps) cout << \" \" << p;\n\t\tcout << endl;\n\t}\n}"
  dependsOn:
  - template.hpp
  - math/factorization.hpp
  isVerificationFile: true
  path: test_oj/factorization.test.cpp
  requiredBy: []
  timestamp: '2024-09-05 20:28:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test_oj/factorization.test.cpp
layout: document
redirect_from:
- /verify/test_oj/factorization.test.cpp
- /verify/test_oj/factorization.test.cpp.html
title: test_oj/factorization.test.cpp
---
