---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"BigInt.cpp\"\n/*\n\t\u56FA\u5B9A\u9577\u591A\u500D\u9577\
    \n\t0 <= x < 10^N_\n\n\t\u4E00\u684110^6 (\u639B\u3051\u7B97\u3057\u305F\u6642\
    \u306B\u7E70\u308A\u4E0A\u304C\u308A\u3092\u5F8C\u56DE\u3057\u306B\u3057\u3066\
    \u3082ll\u306B\u53CE\u307E\u308B\u3088\u3046\u306B)\n\n\tadd / compare : O(N)\n\
    \tprod : O(AB) (\u6841\u6570\u3067\u6291\u3048\u3066\u3044\u308B)\n\n\tTODO :\n\
    \t\t\u5F15\u304D\u7B97/\u8CA0\u6570\n\t\tFFT\u639B\u3051\u7B97\n\t\t\u5272\u308A\
    \u7B97\n\t\t\u53EF\u5909\u9577\n\t\tbase 2\u51AA?\n\n*/\n\ntypedef long long ll;\n\
    constexpr ll TEN(int n) {return (n==0)?1:10*TEN(n-1);};\n\ntemplate<int N_>\n\
    struct BigInt{\n\tusing ll = long long;\n\n\tconstexpr static int B = TEN(6);\n\
    \n\tconstexpr static int N = (N_+5)/6;\n\tarray<ll,N> v;\n\n\tBigInt(){\n\t\t\
    fill(all(v),0);\n\t}\n\tBigInt(ll x){\n\t\tfill(all(v),0);\n\t\tfor(int i=0;x>0;i++){\n\
    \t\t\tassert(i<N);\n\t\t\tv[i] = x%B;\n\t\t\tx /= B;\n\t\t}\n\t}\n\tBigInt(array<ll,N>\
    \ v):v(v){}\n\n\tBigInt(string s){\n\t\tfill(all(v),0);\n\t\tint L = s.size();\n\
    \t\trep(i,L/6){\n\t\t\tv[i] = stoi(s.substr(L-(i+1)*6,6));\n\t\t}\n\t\tif(L%6){\n\
    \t\t\tv[L/6] = stoi(s.substr(0,L%6));\n\t\t}\n\t}\n\n\tint sz() const {\n\t\t\
    for(int i = N-1;i>=0;i--){\n\t\t\tif(v[i]!=0) return i+1;\n\t\t}\n\t\treturn 0;\n\
    \t}\n\n\texplicit operator bool() const {\n\t\trep(i,N) if(v[i]!=0) return true;\n\
    \t\treturn false;\n\t}\n\n\tBigInt& operator+=(const BigInt& r){\n\t\trep(i,N){\n\
    \t\t\tv[i] += r.v[i];\n\t\t\tif(v[i] >= B){\n\t\t\t\tv[i] -= B;\n\t\t\t\tv[i+1]++;\n\
    \t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\tBigInt operator+(const BigInt& r) const\
    \ {return BigInt(*this)+=r;}\n\n\tBigInt operator*(const BigInt& r) const {\n\t\
    \tarray<ll,N> res;\n\t\tfill(all(res),0);\n\n\t\tint X = sz();\n\t\tint Y = r.sz();\n\
    \t\tassert(X+Y-2 < N);\n\n\t\trep(i,X){\n\t\t\trep(j,Y){\n\t\t\t\tres[i+j] +=\
    \ v[i] * r.v[j];\n\t\t\t}\n\t\t}\n\t\trep(i,N){\n\t\t\tres[i+1] += res[i]/B;\n\
    \t\t\tres[i] %= B;\n\t\t}\n\t\treturn BigInt(res);\n\t}\n\tBigInt& operator*=(const\
    \ BigInt& r){ return *this=*this*r;}\n\n\tbool operator==(const BigInt& r) const\
    \ { return v==r.v;}\n\tbool operator!=(const BigInt& r) const { return v!=r.v;}\n\
    \tbool operator<(const BigInt& r) const {\n\t\tfor(int i=N-1;i>=0;i--) if(v[i]\
    \ != r.v[i]) return v[i] < r.v[i];\n\t\treturn 0;\n\t}\n\tbool operator>(const\
    \ BigInt& r) const {\n\t\tfor(int i=N-1;i>=0;i--) if(v[i] != r.v[i]) return v[i]\
    \ > r.v[i];\n\t\treturn 0;\n\t}\n\tbool operator<=(const BigInt& r) const {\n\t\
    \tfor(int i=N-1;i>=0;i--) if(v[i] != r.v[i]) return v[i] < r.v[i];\n\t\treturn\
    \ 1;\n\t}\n\tbool operator>=(const BigInt& r) const {\n\t\tfor(int i=N-1;i>=0;i--)\
    \ if(v[i] != r.v[i]) return v[i] > r.v[i];\n\t\treturn 1;\n\t}\n\n\n\tstring to_str()\
    \ const {\n\t\tstring s;\n\t\tbool is = 0;\n\t\tfor(int i=N-1;i>=0;i--){\n\t\t\
    \tif(!is && v[i]==0) continue;\n\t\t\telse if(!is){\n\t\t\t\tis = 1;\n\t\t\t\t\
    s += to_string(v[i]);\n\t\t\t}else{\n\t\t\t\tstring t = to_string(v[i]);\n\t\t\
    \t\ts += string(6-(int)t.size(),'0') + t;\n\t\t\t}\n\t\t}\n\t\tif(s==\"\") s =\
    \ \"0\";\n\t\treturn s;\n\t}\n\t\n\tfriend istream& operator>>(istream &i,BigInt&\
    \ x){\n\t\tstring s;\n\t\ti>>s;\n\t\tx = BigInt(s);\n\t\treturn i;\n\t}\n\tfriend\
    \ ostream& operator<<(ostream &o,const BigInt& x){\n\t\treturn o<<x.to_str();\n\
    \t}\n\n};\n\nusing Int = BigInt<1010>;\n"
  code: "/*\n\t\u56FA\u5B9A\u9577\u591A\u500D\u9577\n\t0 <= x < 10^N_\n\n\t\u4E00\u6841\
    10^6 (\u639B\u3051\u7B97\u3057\u305F\u6642\u306B\u7E70\u308A\u4E0A\u304C\u308A\
    \u3092\u5F8C\u56DE\u3057\u306B\u3057\u3066\u3082ll\u306B\u53CE\u307E\u308B\u3088\
    \u3046\u306B)\n\n\tadd / compare : O(N)\n\tprod : O(AB) (\u6841\u6570\u3067\u6291\
    \u3048\u3066\u3044\u308B)\n\n\tTODO :\n\t\t\u5F15\u304D\u7B97/\u8CA0\u6570\n\t\
    \tFFT\u639B\u3051\u7B97\n\t\t\u5272\u308A\u7B97\n\t\t\u53EF\u5909\u9577\n\t\t\
    base 2\u51AA?\n\n*/\n\ntypedef long long ll;\nconstexpr ll TEN(int n) {return\
    \ (n==0)?1:10*TEN(n-1);};\n\ntemplate<int N_>\nstruct BigInt{\n\tusing ll = long\
    \ long;\n\n\tconstexpr static int B = TEN(6);\n\n\tconstexpr static int N = (N_+5)/6;\n\
    \tarray<ll,N> v;\n\n\tBigInt(){\n\t\tfill(all(v),0);\n\t}\n\tBigInt(ll x){\n\t\
    \tfill(all(v),0);\n\t\tfor(int i=0;x>0;i++){\n\t\t\tassert(i<N);\n\t\t\tv[i] =\
    \ x%B;\n\t\t\tx /= B;\n\t\t}\n\t}\n\tBigInt(array<ll,N> v):v(v){}\n\n\tBigInt(string\
    \ s){\n\t\tfill(all(v),0);\n\t\tint L = s.size();\n\t\trep(i,L/6){\n\t\t\tv[i]\
    \ = stoi(s.substr(L-(i+1)*6,6));\n\t\t}\n\t\tif(L%6){\n\t\t\tv[L/6] = stoi(s.substr(0,L%6));\n\
    \t\t}\n\t}\n\n\tint sz() const {\n\t\tfor(int i = N-1;i>=0;i--){\n\t\t\tif(v[i]!=0)\
    \ return i+1;\n\t\t}\n\t\treturn 0;\n\t}\n\n\texplicit operator bool() const {\n\
    \t\trep(i,N) if(v[i]!=0) return true;\n\t\treturn false;\n\t}\n\n\tBigInt& operator+=(const\
    \ BigInt& r){\n\t\trep(i,N){\n\t\t\tv[i] += r.v[i];\n\t\t\tif(v[i] >= B){\n\t\t\
    \t\tv[i] -= B;\n\t\t\t\tv[i+1]++;\n\t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\t\
    BigInt operator+(const BigInt& r) const {return BigInt(*this)+=r;}\n\n\tBigInt\
    \ operator*(const BigInt& r) const {\n\t\tarray<ll,N> res;\n\t\tfill(all(res),0);\n\
    \n\t\tint X = sz();\n\t\tint Y = r.sz();\n\t\tassert(X+Y-2 < N);\n\n\t\trep(i,X){\n\
    \t\t\trep(j,Y){\n\t\t\t\tres[i+j] += v[i] * r.v[j];\n\t\t\t}\n\t\t}\n\t\trep(i,N){\n\
    \t\t\tres[i+1] += res[i]/B;\n\t\t\tres[i] %= B;\n\t\t}\n\t\treturn BigInt(res);\n\
    \t}\n\tBigInt& operator*=(const BigInt& r){ return *this=*this*r;}\n\n\tbool operator==(const\
    \ BigInt& r) const { return v==r.v;}\n\tbool operator!=(const BigInt& r) const\
    \ { return v!=r.v;}\n\tbool operator<(const BigInt& r) const {\n\t\tfor(int i=N-1;i>=0;i--)\
    \ if(v[i] != r.v[i]) return v[i] < r.v[i];\n\t\treturn 0;\n\t}\n\tbool operator>(const\
    \ BigInt& r) const {\n\t\tfor(int i=N-1;i>=0;i--) if(v[i] != r.v[i]) return v[i]\
    \ > r.v[i];\n\t\treturn 0;\n\t}\n\tbool operator<=(const BigInt& r) const {\n\t\
    \tfor(int i=N-1;i>=0;i--) if(v[i] != r.v[i]) return v[i] < r.v[i];\n\t\treturn\
    \ 1;\n\t}\n\tbool operator>=(const BigInt& r) const {\n\t\tfor(int i=N-1;i>=0;i--)\
    \ if(v[i] != r.v[i]) return v[i] > r.v[i];\n\t\treturn 1;\n\t}\n\n\n\tstring to_str()\
    \ const {\n\t\tstring s;\n\t\tbool is = 0;\n\t\tfor(int i=N-1;i>=0;i--){\n\t\t\
    \tif(!is && v[i]==0) continue;\n\t\t\telse if(!is){\n\t\t\t\tis = 1;\n\t\t\t\t\
    s += to_string(v[i]);\n\t\t\t}else{\n\t\t\t\tstring t = to_string(v[i]);\n\t\t\
    \t\ts += string(6-(int)t.size(),'0') + t;\n\t\t\t}\n\t\t}\n\t\tif(s==\"\") s =\
    \ \"0\";\n\t\treturn s;\n\t}\n\t\n\tfriend istream& operator>>(istream &i,BigInt&\
    \ x){\n\t\tstring s;\n\t\ti>>s;\n\t\tx = BigInt(s);\n\t\treturn i;\n\t}\n\tfriend\
    \ ostream& operator<<(ostream &o,const BigInt& x){\n\t\treturn o<<x.to_str();\n\
    \t}\n\n};\n\nusing Int = BigInt<1010>;\n"
  dependsOn: []
  isVerificationFile: false
  path: BigInt.cpp
  requiredBy: []
  timestamp: '2017-10-19 00:06:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: BigInt.cpp
layout: document
redirect_from:
- /library/BigInt.cpp
- /library/BigInt.cpp.html
title: BigInt.cpp
---
