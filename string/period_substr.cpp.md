---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/period_substr.cpp\"\n/*\n\t\u6587\u5B57\u5217s\u304C\
    \u4E0E\u3048\u3089\u308C\u308B. \u30AF\u30A8\u30EA\u3068\u3057\u3066[l,r) \u304C\
    \u6765\u308B\u306E\u3067\u3001 s[l,r) \u306E\u6700\u5C0F\u5468\u671F\u3092\u6C42\
    \u3081\u308B\n\n\t\u6700\u5C0F\u5468\u671F\u3060\u3051\u3058\u3083\u306A\u304F\
    \u3066\u5468\u671F\u306E\u96C6\u5408\u3092\u6C42\u3081\u308B\u3053\u3068\u3082\
    \u3067\u304D\u308B(log\u500B\u7A0B\u5EA6\u306E\u7B49\u5DEE\u6570\u5217\u3067\u8868\
    \u305B\u308B)\n\n\t\u69CB\u7BC9O(NlogN), \u30AF\u30A8\u30EAO(log^2 N)\n*/\n\n\
    const bool submit = 0;\n#include <bits/stdc++.h>\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define all(c) c.begin(),c.end()\n\
    #define pb push_back\n#define fs first\n#define sc second\n#define show(x) if(!submit)\
    \ cout << #x << \" = \" << x << endl\n#define chmin(x,y) x=min(x,y)\n#define chmax(x,y)\
    \ x=max(x,y)\nusing namespace std;\ntemplate<class S,class T> ostream& operator<<(ostream&\
    \ o,const pair<S,T> &p){return o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class\
    \ T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"\
    [\";for(const T& v:vc) o<<v<<\",\";o<<\"]\";return o;}\n\n/*\nx       0  1  2\
    \  3  4  5  6  7  8  9\nbsr(x) -1  0  1  1  2  2  2  2  3  3\n\u6700\u4E0A\u4F4D\
    bit\n*/\nint bsr(int x){\n\tif(x==0) return -1;\n\treturn 31 ^ __builtin_clz(x);\n\
    }\nint bsf(int x){return __builtin_ctz(x);}\nint gcd(int a, int b){\n\ta = abs(a),\
    \ b = abs(b);\n\tif(a==0) return b;\n\tif(b==0) return a;\n\tint shift = bsf(a|b);\n\
    \ta >>= bsf(a);\n\tdo{\n\t\tb >>= bsf(b);\n\t\tif(a>b) swap(a,b);\n\t\tb -= a;\n\
    \t}while(b);\n\treturn a<<shift;\n}\n\nstruct Period_Substr{\n\n\t/*\n\t\tArithmetic\
    \ Progression\n\t\ta, a+d, .., a+d(n-1)\n\n\t\tn may be 0 (empty)\n\t\t!!! if\
    \ n>=2 , then d MUST be POSITIVE !!!\n\t*/\n\tstruct Arith{\n\t\tint a,d,n;\n\t\
    \tArith(int a,int d,int n):a(a),d(d),n(n){}\n\t\tint getmax(){\n\t\t\tif(n==0)\
    \ return -1;\n\t\t\treturn a+d*(n-1);\n\t\t}\n\t\tbool hasx(int x){\n\t\t\tif(n==0)\
    \ return 0;\n\t\t\tif(n==1) return a == x;\n\t\t\treturn a<=x && x<=getmax() &&\
    \ (x-a)%d == 0;\n\t\t}\n\t\tfriend ostream& operator<<(ostream &o,const Arith&\
    \ x){\n\t\t\to << \"[ \";\n\t\t\trep(i,x.n) o << x.a+i*x.d << \" \";\n\t\t\to<<\"\
    ]\";\n\t\t\treturn o;\n\t\t}\n\t};\n\tArith Add(int x, Arith f){\t// x + f\n\t\
    \treturn Arith(f.a+x,f.d,f.n);\n\t}\n\tArith Sub(int x, Arith f){\t// x - f\n\t\
    \tint a = x - f.getmax();\n\t\treturn Arith(a,f.d,f.n);\n\t}\n\n\t/*\n\t\tAssumption:\
    \ f.n , g.n >= 3\n\t\t\t\t\tf.d == g.d\n\t*/\n\tArith Inter(Arith f, Arith g){\n\
    \t\t\n\t\tassert(f.d == g.d);\n\n\t\tint d = f.d;\n\n\t\tif((f.a-g.a)%d != 0){\n\
    \t\t\treturn Arith(0,0,0);\n\t\t}\n\n\t\tint a = max(f.a,g.a);\n\t\tint e = min(f.getmax(),g.getmax());\n\
    \t\tint n = (e-a)/d + 1;\n\n\t\tif(n <= 0){\n\t\t\treturn Arith(0,0,0);\n\t\t\
    }\n\n\t\treturn Arith(a,d,n);\n\n\t\t//brute\n\t\t// map<int,int> cnt;\n\t\t//\
    \ rep(i,f.n) cnt[f.a+i*f.d]++;\n\t\t// rep(i,g.n) cnt[g.a+i*g.d]++;\n\n\t\t//\
    \ int a = 0;\n\t\t// int d = 0;\n\t\t// int n = 0;\n\t\t// for(auto it:cnt) if(it.sc==2){\n\
    \t\t// \tif(n==0) a = it.fs;\n\t\t// \tif(n==1) d = it.fs - a;\n\t\t// \tn++;\n\
    \t\t// }\n\t\t// return Arith(a,d,n);\n\t}\n\n\tstring s;\n\tint N;\n\tvector<vector<int>>\
    \ type;\n\tvector<vector<vector<int>>> kt2xs;\n\n\tPeriod_Substr(string s):s(s),N(s.size()){\n\
    \t\tint K = bsr(N) + 1;\n\t\ttype.resize(K);\n\t\tkt2xs.resize(K);\n\n\t\t/*\n\
    \t\t\tTODO\n\t\t\tconstruct kt2xs\n\t\t\twith SA-IS + LCP !!\n\t\t*/\n\n\n\t\t\
    /*\n\t\t\tby hash (2^64) <- ha?\n\t\t*/\n\t\tusing ull = unsigned long long;\n\
    \t\tconst ull base = 1e9+7;\n\t\tull bex = base;\n\t\trep(k,K){\n\t\t\tmap<ull,vector<int>>\
    \ mp;\n\t\t\tull h = 0;\n\t\t\tint len = 1<<k;\n\t\t\t\n\t\t\trep(i,N){\n\t\t\t\
    \th = h*base + s[i];\n\t\t\t\tif(i-len >= 0) h -= bex * s[i-len];\n\n\t\t\t\t\
    if(i >= len-1){\n\t\t\t\t\tmp[h].pb(i-(len-1));\n\t\t\t\t}\n\t\t\t}\n\t\t\tint\
    \ T = mp.size();\n\n\t\t\ttype[k].resize(N-len+1);\n\t\t\tkt2xs[k].resize(T);\n\
    \n\t\t\tint t = 0;\n\t\t\tfor(const auto& it:mp){\n\t\t\t\tfor(int v: it.sc){\n\
    \t\t\t\t\ttype[k][v] = t;\n\t\t\t\t\tkt2xs[k][t].pb(v);\n\t\t\t\t}\n\t\t\t\tt++;\n\
    \t\t\t}\n\t\t\tbex = bex * bex;\n\t\t}\n\n\t}\n\n\t/*\n\t\tmin period of s[l,r)\n\
    \t*/\n\tint period_min(int l,int r){\n\t\tint n = r-l;\n\t\tint K = bsr(n);\n\t\
    \tint res = n;\n\n\t\trep(k,K+1){\n\t\t\tArith f = LargePS(k,l,r-(1<<k));\n\t\t\
    \tint p = f.getmax();\n\t\t\tif(p == n){\n\t\t\t\tif(f.n <=1) continue;\n\t\t\t\
    \tp -= f.d;\n\t\t\t}\n\t\t\tchmin(res,n-p);\n\t\t}\n\n//\t\tArith f = BordersLarger(l,r);\n\
    \t\tArith f = PeriodsSmaller(l,r);\n\t\tif(f.n != 0){\n\t\t\tchmin(res,f.a);\n\
    \t\t}\n\n\t\treturn res;\n\t}\n\n\t/*\n\t\tall period of s[l,r)\n\t\tas a DISJOINT\
    \ union of arithmetic progression\n\t\tINCREASING order\n\t*/\n\tvector<Arith>\
    \ period_all(int l,int r){\n\t\tvector<Arith> res;\n\n\t\tint n = r-l;\n\t\tint\
    \ K = bsr(n);\n\n\t\tArith f = PeriodsSmaller(l,r);\n\t\tif(f.n != 0){\n\t\t\t\
    res.pb(f);\n\t\t}\n\n\t\tfor(int k=K;k>=0;k--){\n\t\t\tArith f = LargePS(k,l,r-(1<<k));\n\
    \t\t\tif(f.n == 0) continue;\n\n\t\t\tint p = f.getmax();\n\t\t\tif(p == n){\n\
    \t\t\t\tif(f.n <=1) continue;\n\t\t\t\tf.n--;\n\t\t\t}\n\t\t\tf = Sub(n,f);\n\t\
    \t\tres.pb(f);\n\t\t}\n\t\tres.pb(Arith(n,0,1));\n\n\t\treturn res;\n\t}\n\n\t\
    int period_min_brute(int l,int r){\n\t\trep1(t,r-l){\n\t\t\tbool ok = 1;\n\t\t\
    \trep(j,r-l-t){\n\t\t\t\tif(s[l+j]!=s[l+j+t]) ok = 0;\n\t\t\t}\n\t\t\tif(ok) return\
    \ t;\n\t\t}\n\t\treturn -1;\n\t}\n\n\tvector<int> period_all_brute(int l,int r){\n\
    \t\tvector<int> res;\n\t\trep1(t,r-l){\n\t\t\tbool ok = 1;\n\t\t\trep(j,r-l-t){\n\
    \t\t\t\tif(s[l+j]!=s[l+j+t]) ok = 0;\n\t\t\t}\n\t\t\tif(ok) res.pb(t);\n\t\t}\n\
    \t\treturn res;\n\t}\n\n\t/*\n\t\treturn the set of length of LARGE prefix-suffix\
    \ of (X,Y)\n\t\tX = [x,x+1<<k) , Y = [y,y+1<<k)\n\t\tLARGE means length > X.size()/2\n\
    \t*/\n\tArith LargePS(int k,int x,int y){\n\t\tif(k==0){\n\t\t\tif(s[x]==s[y]){\n\
    \t\t\t\treturn Arith(1,0,1);\n\t\t\t}else{\n\t\t\t\treturn Arith(0,0,0);\n\t\t\
    \t}\n\t\t}\n\t\tint d = 1<<(k-1);\n\t\tArith S1 = Sub(2*d,Occ(x,y,k-1));\n\t\t\
    Arith S2 = Add(d  ,Occ(y+d,x,k-1));\n\n\t\tArith S(0,0,0);\n\n\t\tif(S1.n > S2.n)\
    \ swap(S1,S2);\n\t\tif(S1.n < 3){\n\t\t\tif(S1.n == 0){\n\t\t\t}else if(S1.n ==\
    \ 1){\n\t\t\t\tint a = S1.a;\n\t\t\t\tif(S2.hasx(a)){\n\t\t\t\t\tS = Arith(a,0,1);\n\
    \t\t\t\t}else{\n\t\t\t\t}\n\t\t\t}else if(S1.n == 2){\n\t\t\t\tint a = S1.a;\n\
    \t\t\t\tint b = S1.a + S1.d;\n\n\t\t\t\tbool A = S2.hasx(a) , B = S2.hasx(b);\n\
    \n\t\t\t\tif(A && B){\n\t\t\t\t\tS = S1;\n\t\t\t\t}else if(A){\n\t\t\t\t\tS =\
    \ Arith(a,0,1);\n\t\t\t\t}else if(B){\n\t\t\t\t\tS = Arith(b,0,1);\n\t\t\t\t}else{\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}else{\n\t\t\tS = Inter(S1,S2);\n\t\t}\n\n\t\tif(S.n!=0\
    \ && S.a == d){\t// elim d\n\t\t\tS.a += S.d, S.n--;\n\t\t}\n\t\treturn S;\n\t\
    }\n\n\t/*\n\t\tBordersLarger:\n\t\treturn the set of length of borders of s[l,r)\
    \ whose length is greater than K\n\n\t\tPeriodsSmaller:\n\t\treturn (r-l) - BordersLarger\n\
    \t*/\n\tArith PeriodsSmaller(int l,int r){\n\t\tint K = bsr(r-l);\n\t\tint M =\
    \ 1<<K;\n\t\tint len = r-l;\n\n\t\tint nl = Succ(K,l,l+1);\n\t\tif(nl == -1 ||\
    \ nl+M > r){\n\t\t\treturn Arith(0,0,0);\n\t\t}\n\t\tint dl = nl - l;\n\n\t\t\
    int nr = Pred(K,r-M,r-M-1);\n\t\tif(nr == -1 || nr<l){\n\t\t\treturn Arith(0,0,0);\n\
    \t\t}\n\t\tint dr = r - M - nr;\n\n\t\tif(dl != dr) return Arith(0,0,0);\n\n\n\
    \t\tint d = dl;\t//period: d,2d,3d,..,nd (border: len-d, .., len-nd>M)\n\n\t\t\
    int n = (len-M-1)/d;\n\n\t\treturn Arith(d,d,n);\n\t}\n\n\t/*\n\t\toccurence of\
    \ [x,x+1<<k) in [y,y+1<<(k+1))\n\t\t0-indexed\n\t*/\n\tArith Occ(int x,int y,int\
    \ k){\n\t\tint a = Succ(k,x,y);\n\t\tif(a == -1 || a > y+(1<<k)){\n\t\t\treturn\
    \ Arith(0,0,0);\n\t\t}\n\t\tint b = Succ(k,x,a+1);\n\t\tif(b == -1 || b > y+(1<<k)){\n\
    \t\t\treturn Arith(a-y,0,1);\n\t\t}\n\t\tint e = Pred(k,x,y+(1<<k));\n\t\tassert(e\
    \ != -1);\n\n\t\tint d = b-a;\n\t\tint n = (e-a)/d + 1;\n\n\t\treturn Arith(a-y,d,n);\n\
    \t}\n\n\t/*\n\t\treturn min j s.t. s[j,j+1<<k) = s[x,x+1<<k) and j>=i\n\t\tif\
    \ no, return -1\n\t*/\n\tint Succ(int k,int x,int i){\n\t\tint t = type[k][x];\n\
    \t\tconst auto& vc = kt2xs[k][t];\n\t\tint id = lower_bound(all(vc),i) - vc.begin();\n\
    \t\tif(id == (int)vc.size()) return -1;\n\t\treturn vc[id];\n\t}\n\n\t/*\n\t\t\
    return max j s.t. s[j,j+1<<k) = s[x,x+1<<k) and j<=i\n\t\tif no, return -1\n\t\
    */\n\tint Pred(int k,int x,int i){\n\t\tint t = type[k][x];\n\t\tconst auto& vc\
    \ = kt2xs[k][t];\n\t\tint id = upper_bound(all(vc),i) - vc.begin();\n\t\tif(id\
    \ == 0) return -1;\n\t\treturn vc[id-1];\n\t}\n\n};\n\nvoid validate(string s){\n\
    \tint N = s.size();\n\tPeriod_Substr PS(s);\n\tfor(int l=0;l<N;l++) for(int r=l+1;r<=N;r++){\t\
    \t//min\n\t\tint a = PS.period_min(l,r);\n\t\tint b = PS.period_min_brute(l,r);\n\
    \t\tif(a!=b){\n\t\t\tprintf(\"s[%d,%d) = \",l,r);\n\t\t\tcout<<s.substr(l,r-l)<<endl;\n\
    \t\t\tshow(a);\n\t\t\tshow(b);\n\t\t\tassert(0);\n\t\t}\n\t}\n\n\tfor(int l=0;l<N;l++)\
    \ for(int r=l+1;r<=N;r++){\t\t//all\n\t\tauto a_ = PS.period_all(l,r);\n\t\tvector<int>\
    \ a;\n\t\tfor(auto x:a_){\n\t\t\trep(i,x.n) a.pb(x.a+i*x.d);\n\t\t}\n\t\tvector<int>\
    \ b = PS.period_all_brute(l,r);\n\t\tif(a!=b){\n\t\t\tprintf(\"s[%d,%d) = \",l,r);\n\
    \t\t\tcout<<s.substr(l,r-l)<<endl;\n\t\t\tshow(a);\n\t\t\tshow(b);\n\t\t\tassert(0);\n\
    \t\t}\n\t}\n//\tshow(PS.period_all(0,3));\n}\n\nint main(){\n\tsrand(unsigned(time(NULL)));\n\
    \trep(t,1000){\n\t\tcout<<\"t=\"<<t<<endl;\n\t\tint N = rand()%100 + 1;\n\t\t\
    string s(N,'.');\n\t\trep(i,N) s[i] = 'a' + rand()%26;\n\t\t// string s;\n\t\t\
    // cin>>s;\n\t\tvalidate(s);\n\t}\n//\tvalidate(string(\"aba\"));\n}\n"
  code: "/*\n\t\u6587\u5B57\u5217s\u304C\u4E0E\u3048\u3089\u308C\u308B. \u30AF\u30A8\
    \u30EA\u3068\u3057\u3066[l,r) \u304C\u6765\u308B\u306E\u3067\u3001 s[l,r) \u306E\
    \u6700\u5C0F\u5468\u671F\u3092\u6C42\u3081\u308B\n\n\t\u6700\u5C0F\u5468\u671F\
    \u3060\u3051\u3058\u3083\u306A\u304F\u3066\u5468\u671F\u306E\u96C6\u5408\u3092\
    \u6C42\u3081\u308B\u3053\u3068\u3082\u3067\u304D\u308B(log\u500B\u7A0B\u5EA6\u306E\
    \u7B49\u5DEE\u6570\u5217\u3067\u8868\u305B\u308B)\n\n\t\u69CB\u7BC9O(NlogN), \u30AF\
    \u30A8\u30EAO(log^2 N)\n*/\n\nconst bool submit = 0;\n#include <bits/stdc++.h>\n\
    #define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define all(c) c.begin(),c.end()\n#define pb push_back\n#define fs first\n#define\
    \ sc second\n#define show(x) if(!submit) cout << #x << \" = \" << x << endl\n\
    #define chmin(x,y) x=min(x,y)\n#define chmax(x,y) x=max(x,y)\nusing namespace\
    \ std;\ntemplate<class S,class T> ostream& operator<<(ostream& o,const pair<S,T>\
    \ &p){return o<<\"(\"<<p.fs<<\",\"<<p.sc<<\")\";}\ntemplate<class T> ostream&\
    \ operator<<(ostream& o,const vector<T> &vc){o<<\"sz = \"<<vc.size()<<endl<<\"\
    [\";for(const T& v:vc) o<<v<<\",\";o<<\"]\";return o;}\n\n/*\nx       0  1  2\
    \  3  4  5  6  7  8  9\nbsr(x) -1  0  1  1  2  2  2  2  3  3\n\u6700\u4E0A\u4F4D\
    bit\n*/\nint bsr(int x){\n\tif(x==0) return -1;\n\treturn 31 ^ __builtin_clz(x);\n\
    }\nint bsf(int x){return __builtin_ctz(x);}\nint gcd(int a, int b){\n\ta = abs(a),\
    \ b = abs(b);\n\tif(a==0) return b;\n\tif(b==0) return a;\n\tint shift = bsf(a|b);\n\
    \ta >>= bsf(a);\n\tdo{\n\t\tb >>= bsf(b);\n\t\tif(a>b) swap(a,b);\n\t\tb -= a;\n\
    \t}while(b);\n\treturn a<<shift;\n}\n\nstruct Period_Substr{\n\n\t/*\n\t\tArithmetic\
    \ Progression\n\t\ta, a+d, .., a+d(n-1)\n\n\t\tn may be 0 (empty)\n\t\t!!! if\
    \ n>=2 , then d MUST be POSITIVE !!!\n\t*/\n\tstruct Arith{\n\t\tint a,d,n;\n\t\
    \tArith(int a,int d,int n):a(a),d(d),n(n){}\n\t\tint getmax(){\n\t\t\tif(n==0)\
    \ return -1;\n\t\t\treturn a+d*(n-1);\n\t\t}\n\t\tbool hasx(int x){\n\t\t\tif(n==0)\
    \ return 0;\n\t\t\tif(n==1) return a == x;\n\t\t\treturn a<=x && x<=getmax() &&\
    \ (x-a)%d == 0;\n\t\t}\n\t\tfriend ostream& operator<<(ostream &o,const Arith&\
    \ x){\n\t\t\to << \"[ \";\n\t\t\trep(i,x.n) o << x.a+i*x.d << \" \";\n\t\t\to<<\"\
    ]\";\n\t\t\treturn o;\n\t\t}\n\t};\n\tArith Add(int x, Arith f){\t// x + f\n\t\
    \treturn Arith(f.a+x,f.d,f.n);\n\t}\n\tArith Sub(int x, Arith f){\t// x - f\n\t\
    \tint a = x - f.getmax();\n\t\treturn Arith(a,f.d,f.n);\n\t}\n\n\t/*\n\t\tAssumption:\
    \ f.n , g.n >= 3\n\t\t\t\t\tf.d == g.d\n\t*/\n\tArith Inter(Arith f, Arith g){\n\
    \t\t\n\t\tassert(f.d == g.d);\n\n\t\tint d = f.d;\n\n\t\tif((f.a-g.a)%d != 0){\n\
    \t\t\treturn Arith(0,0,0);\n\t\t}\n\n\t\tint a = max(f.a,g.a);\n\t\tint e = min(f.getmax(),g.getmax());\n\
    \t\tint n = (e-a)/d + 1;\n\n\t\tif(n <= 0){\n\t\t\treturn Arith(0,0,0);\n\t\t\
    }\n\n\t\treturn Arith(a,d,n);\n\n\t\t//brute\n\t\t// map<int,int> cnt;\n\t\t//\
    \ rep(i,f.n) cnt[f.a+i*f.d]++;\n\t\t// rep(i,g.n) cnt[g.a+i*g.d]++;\n\n\t\t//\
    \ int a = 0;\n\t\t// int d = 0;\n\t\t// int n = 0;\n\t\t// for(auto it:cnt) if(it.sc==2){\n\
    \t\t// \tif(n==0) a = it.fs;\n\t\t// \tif(n==1) d = it.fs - a;\n\t\t// \tn++;\n\
    \t\t// }\n\t\t// return Arith(a,d,n);\n\t}\n\n\tstring s;\n\tint N;\n\tvector<vector<int>>\
    \ type;\n\tvector<vector<vector<int>>> kt2xs;\n\n\tPeriod_Substr(string s):s(s),N(s.size()){\n\
    \t\tint K = bsr(N) + 1;\n\t\ttype.resize(K);\n\t\tkt2xs.resize(K);\n\n\t\t/*\n\
    \t\t\tTODO\n\t\t\tconstruct kt2xs\n\t\t\twith SA-IS + LCP !!\n\t\t*/\n\n\n\t\t\
    /*\n\t\t\tby hash (2^64) <- ha?\n\t\t*/\n\t\tusing ull = unsigned long long;\n\
    \t\tconst ull base = 1e9+7;\n\t\tull bex = base;\n\t\trep(k,K){\n\t\t\tmap<ull,vector<int>>\
    \ mp;\n\t\t\tull h = 0;\n\t\t\tint len = 1<<k;\n\t\t\t\n\t\t\trep(i,N){\n\t\t\t\
    \th = h*base + s[i];\n\t\t\t\tif(i-len >= 0) h -= bex * s[i-len];\n\n\t\t\t\t\
    if(i >= len-1){\n\t\t\t\t\tmp[h].pb(i-(len-1));\n\t\t\t\t}\n\t\t\t}\n\t\t\tint\
    \ T = mp.size();\n\n\t\t\ttype[k].resize(N-len+1);\n\t\t\tkt2xs[k].resize(T);\n\
    \n\t\t\tint t = 0;\n\t\t\tfor(const auto& it:mp){\n\t\t\t\tfor(int v: it.sc){\n\
    \t\t\t\t\ttype[k][v] = t;\n\t\t\t\t\tkt2xs[k][t].pb(v);\n\t\t\t\t}\n\t\t\t\tt++;\n\
    \t\t\t}\n\t\t\tbex = bex * bex;\n\t\t}\n\n\t}\n\n\t/*\n\t\tmin period of s[l,r)\n\
    \t*/\n\tint period_min(int l,int r){\n\t\tint n = r-l;\n\t\tint K = bsr(n);\n\t\
    \tint res = n;\n\n\t\trep(k,K+1){\n\t\t\tArith f = LargePS(k,l,r-(1<<k));\n\t\t\
    \tint p = f.getmax();\n\t\t\tif(p == n){\n\t\t\t\tif(f.n <=1) continue;\n\t\t\t\
    \tp -= f.d;\n\t\t\t}\n\t\t\tchmin(res,n-p);\n\t\t}\n\n//\t\tArith f = BordersLarger(l,r);\n\
    \t\tArith f = PeriodsSmaller(l,r);\n\t\tif(f.n != 0){\n\t\t\tchmin(res,f.a);\n\
    \t\t}\n\n\t\treturn res;\n\t}\n\n\t/*\n\t\tall period of s[l,r)\n\t\tas a DISJOINT\
    \ union of arithmetic progression\n\t\tINCREASING order\n\t*/\n\tvector<Arith>\
    \ period_all(int l,int r){\n\t\tvector<Arith> res;\n\n\t\tint n = r-l;\n\t\tint\
    \ K = bsr(n);\n\n\t\tArith f = PeriodsSmaller(l,r);\n\t\tif(f.n != 0){\n\t\t\t\
    res.pb(f);\n\t\t}\n\n\t\tfor(int k=K;k>=0;k--){\n\t\t\tArith f = LargePS(k,l,r-(1<<k));\n\
    \t\t\tif(f.n == 0) continue;\n\n\t\t\tint p = f.getmax();\n\t\t\tif(p == n){\n\
    \t\t\t\tif(f.n <=1) continue;\n\t\t\t\tf.n--;\n\t\t\t}\n\t\t\tf = Sub(n,f);\n\t\
    \t\tres.pb(f);\n\t\t}\n\t\tres.pb(Arith(n,0,1));\n\n\t\treturn res;\n\t}\n\n\t\
    int period_min_brute(int l,int r){\n\t\trep1(t,r-l){\n\t\t\tbool ok = 1;\n\t\t\
    \trep(j,r-l-t){\n\t\t\t\tif(s[l+j]!=s[l+j+t]) ok = 0;\n\t\t\t}\n\t\t\tif(ok) return\
    \ t;\n\t\t}\n\t\treturn -1;\n\t}\n\n\tvector<int> period_all_brute(int l,int r){\n\
    \t\tvector<int> res;\n\t\trep1(t,r-l){\n\t\t\tbool ok = 1;\n\t\t\trep(j,r-l-t){\n\
    \t\t\t\tif(s[l+j]!=s[l+j+t]) ok = 0;\n\t\t\t}\n\t\t\tif(ok) res.pb(t);\n\t\t}\n\
    \t\treturn res;\n\t}\n\n\t/*\n\t\treturn the set of length of LARGE prefix-suffix\
    \ of (X,Y)\n\t\tX = [x,x+1<<k) , Y = [y,y+1<<k)\n\t\tLARGE means length > X.size()/2\n\
    \t*/\n\tArith LargePS(int k,int x,int y){\n\t\tif(k==0){\n\t\t\tif(s[x]==s[y]){\n\
    \t\t\t\treturn Arith(1,0,1);\n\t\t\t}else{\n\t\t\t\treturn Arith(0,0,0);\n\t\t\
    \t}\n\t\t}\n\t\tint d = 1<<(k-1);\n\t\tArith S1 = Sub(2*d,Occ(x,y,k-1));\n\t\t\
    Arith S2 = Add(d  ,Occ(y+d,x,k-1));\n\n\t\tArith S(0,0,0);\n\n\t\tif(S1.n > S2.n)\
    \ swap(S1,S2);\n\t\tif(S1.n < 3){\n\t\t\tif(S1.n == 0){\n\t\t\t}else if(S1.n ==\
    \ 1){\n\t\t\t\tint a = S1.a;\n\t\t\t\tif(S2.hasx(a)){\n\t\t\t\t\tS = Arith(a,0,1);\n\
    \t\t\t\t}else{\n\t\t\t\t}\n\t\t\t}else if(S1.n == 2){\n\t\t\t\tint a = S1.a;\n\
    \t\t\t\tint b = S1.a + S1.d;\n\n\t\t\t\tbool A = S2.hasx(a) , B = S2.hasx(b);\n\
    \n\t\t\t\tif(A && B){\n\t\t\t\t\tS = S1;\n\t\t\t\t}else if(A){\n\t\t\t\t\tS =\
    \ Arith(a,0,1);\n\t\t\t\t}else if(B){\n\t\t\t\t\tS = Arith(b,0,1);\n\t\t\t\t}else{\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}else{\n\t\t\tS = Inter(S1,S2);\n\t\t}\n\n\t\tif(S.n!=0\
    \ && S.a == d){\t// elim d\n\t\t\tS.a += S.d, S.n--;\n\t\t}\n\t\treturn S;\n\t\
    }\n\n\t/*\n\t\tBordersLarger:\n\t\treturn the set of length of borders of s[l,r)\
    \ whose length is greater than K\n\n\t\tPeriodsSmaller:\n\t\treturn (r-l) - BordersLarger\n\
    \t*/\n\tArith PeriodsSmaller(int l,int r){\n\t\tint K = bsr(r-l);\n\t\tint M =\
    \ 1<<K;\n\t\tint len = r-l;\n\n\t\tint nl = Succ(K,l,l+1);\n\t\tif(nl == -1 ||\
    \ nl+M > r){\n\t\t\treturn Arith(0,0,0);\n\t\t}\n\t\tint dl = nl - l;\n\n\t\t\
    int nr = Pred(K,r-M,r-M-1);\n\t\tif(nr == -1 || nr<l){\n\t\t\treturn Arith(0,0,0);\n\
    \t\t}\n\t\tint dr = r - M - nr;\n\n\t\tif(dl != dr) return Arith(0,0,0);\n\n\n\
    \t\tint d = dl;\t//period: d,2d,3d,..,nd (border: len-d, .., len-nd>M)\n\n\t\t\
    int n = (len-M-1)/d;\n\n\t\treturn Arith(d,d,n);\n\t}\n\n\t/*\n\t\toccurence of\
    \ [x,x+1<<k) in [y,y+1<<(k+1))\n\t\t0-indexed\n\t*/\n\tArith Occ(int x,int y,int\
    \ k){\n\t\tint a = Succ(k,x,y);\n\t\tif(a == -1 || a > y+(1<<k)){\n\t\t\treturn\
    \ Arith(0,0,0);\n\t\t}\n\t\tint b = Succ(k,x,a+1);\n\t\tif(b == -1 || b > y+(1<<k)){\n\
    \t\t\treturn Arith(a-y,0,1);\n\t\t}\n\t\tint e = Pred(k,x,y+(1<<k));\n\t\tassert(e\
    \ != -1);\n\n\t\tint d = b-a;\n\t\tint n = (e-a)/d + 1;\n\n\t\treturn Arith(a-y,d,n);\n\
    \t}\n\n\t/*\n\t\treturn min j s.t. s[j,j+1<<k) = s[x,x+1<<k) and j>=i\n\t\tif\
    \ no, return -1\n\t*/\n\tint Succ(int k,int x,int i){\n\t\tint t = type[k][x];\n\
    \t\tconst auto& vc = kt2xs[k][t];\n\t\tint id = lower_bound(all(vc),i) - vc.begin();\n\
    \t\tif(id == (int)vc.size()) return -1;\n\t\treturn vc[id];\n\t}\n\n\t/*\n\t\t\
    return max j s.t. s[j,j+1<<k) = s[x,x+1<<k) and j<=i\n\t\tif no, return -1\n\t\
    */\n\tint Pred(int k,int x,int i){\n\t\tint t = type[k][x];\n\t\tconst auto& vc\
    \ = kt2xs[k][t];\n\t\tint id = upper_bound(all(vc),i) - vc.begin();\n\t\tif(id\
    \ == 0) return -1;\n\t\treturn vc[id-1];\n\t}\n\n};\n\nvoid validate(string s){\n\
    \tint N = s.size();\n\tPeriod_Substr PS(s);\n\tfor(int l=0;l<N;l++) for(int r=l+1;r<=N;r++){\t\
    \t//min\n\t\tint a = PS.period_min(l,r);\n\t\tint b = PS.period_min_brute(l,r);\n\
    \t\tif(a!=b){\n\t\t\tprintf(\"s[%d,%d) = \",l,r);\n\t\t\tcout<<s.substr(l,r-l)<<endl;\n\
    \t\t\tshow(a);\n\t\t\tshow(b);\n\t\t\tassert(0);\n\t\t}\n\t}\n\n\tfor(int l=0;l<N;l++)\
    \ for(int r=l+1;r<=N;r++){\t\t//all\n\t\tauto a_ = PS.period_all(l,r);\n\t\tvector<int>\
    \ a;\n\t\tfor(auto x:a_){\n\t\t\trep(i,x.n) a.pb(x.a+i*x.d);\n\t\t}\n\t\tvector<int>\
    \ b = PS.period_all_brute(l,r);\n\t\tif(a!=b){\n\t\t\tprintf(\"s[%d,%d) = \",l,r);\n\
    \t\t\tcout<<s.substr(l,r-l)<<endl;\n\t\t\tshow(a);\n\t\t\tshow(b);\n\t\t\tassert(0);\n\
    \t\t}\n\t}\n//\tshow(PS.period_all(0,3));\n}\n\nint main(){\n\tsrand(unsigned(time(NULL)));\n\
    \trep(t,1000){\n\t\tcout<<\"t=\"<<t<<endl;\n\t\tint N = rand()%100 + 1;\n\t\t\
    string s(N,'.');\n\t\trep(i,N) s[i] = 'a' + rand()%26;\n\t\t// string s;\n\t\t\
    // cin>>s;\n\t\tvalidate(s);\n\t}\n//\tvalidate(string(\"aba\"));\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/period_substr.cpp
  requiredBy: []
  timestamp: '2018-09-18 03:14:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/period_substr.cpp
layout: document
redirect_from:
- /library/string/period_substr.cpp
- /library/string/period_substr.cpp.html
title: string/period_substr.cpp
---
