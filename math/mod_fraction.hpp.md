---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/mod_fraction.hpp\"\n/*\n\t\u6574\u6570\u3092\u304B\u3051\
    \u305F\u308A\u5272\u3063\u305F\u308A\u3057\u3066\u6700\u7D42\u7684\u306A\u5024\
    \ mod M \u3092\u6C42\u3081\u308B\u30E9\u30A4\u30D6\u30E9\u30EA\n\t\u4F8B\u3048\
    \u3070 1e9 choose 100 mod M \u3068\u304B\u306B\u4F7F\u3048\u308B\n\n\tModFraction::set_mod(mod)\
    \ \u3092\u3057\u3066\u304B\u3089\u4F7F\u3046\n\t\tmint \u306E mod \u3068\u540C\
    \u3058\u5024\u3067\u3042\u308B\u3088\u3046\u306B\u3059\u308B\u3053\u3068\n\tval()\
    \ \u3067 mint \u3068\u3057\u3066\u306E\u5024\u3092\u8FD4\u3059\n\t\t\u6574\u6570\
    \u3067\u306A\u304B\u3063\u305F\u5834\u5408assert\u3092\u3057\u3066\u3044\u308B\
    \u304C\u3001\u72B6\u6CC1\u306B\u5FDC\u3058\u3066\u5909\u3048\u308B\n\n\t*= ll\
    \ \u3068 /= ll \u3057\u304B\u5B9F\u88C5\u3057\u3066\u306A\u3044\u3051\u3069\u3001\
    ModFraction \u3069\u3046\u3057\u306E\u4E57\u9664\u3082\u5F53\u7136\u51FA\u6765\
    \u308B\n*/\nstruct ModFraction{\n\tstatic inline ll mod;\n\tstatic inline vector<ll>\
    \ ps;\n\n\tstatic void set_mod(ll mod_){\n\t\tmod = mod_;\n\t\tps.clear();\n\t\
    \t{\t//factorize\n\t\t\tll x = mod;\n\t\t\tfor(ll i=2;i*i<=x;i++) if(x%i==0){\n\
    \t\t\t\tps.pb(i);\n\t\t\t\twhile(x%i==0) x/=i;\n\t\t\t}\n\t\t\tif(x>1) ps.pb(x);\n\
    \t\t}\n\t}\n\n\t// val = x * \\prod p^e\n\t// x \u306F Z/modZ\n\tvector<int> es;\n\
    \tmint x;\n\n\tmint val(){\n\t\tif(x == 0) return 0;\n\t\trep(i,si(ps)) if(es[i]\
    \ < 0){\n\t\t\t// not an integer\n\t\t\tassert(false);\n\t\t}\n\t\tmint res =\
    \ x;\n\t\trep(i,si(ps)){\n\t\t\t// TODO: \u9AD8\u901F\u5316\n\t\t\tres *= mint(ps[i]).pow(es[i]);\n\
    \t\t}\n\t\treturn res;\n\t}\n\n\tModFraction(ll v){\n\t\trep(i,si(ps)){\n\t\t\t\
    int e = 0;\n\t\t\twhile(v%ps[i] == 0){\n\t\t\t\tv /= ps[i];\n\t\t\t\te++;\n\t\t\
    \t}\n\t\t\tes.eb(e);\n\t\t}\n\t\tx = v;\n\t}\n\tModFraction& operator*=(ll v){\n\
    \t\trep(i,si(ps)){\n\t\t\tint e = 0;\n\t\t\twhile(v%ps[i] == 0){\n\t\t\t\tv /=\
    \ ps[i];\n\t\t\t\te++;\n\t\t\t}\n\t\t\tes[i] += e;\n\t\t}\n\t\tx *= v;\n\t\treturn\
    \ *this;\n\t}\n\tModFraction& operator/=(ll v){\n\t\tassert(v);\t// div by 0\n\
    \t\trep(i,si(ps)){\n\t\t\tint e = 0;\n\t\t\twhile(v%ps[i] == 0){\n\t\t\t\tv /=\
    \ ps[i];\n\t\t\t\te++;\n\t\t\t}\n\t\t\tes[i] -= e;\n\t\t}\n\t\tx /= v;\n\t\treturn\
    \ *this;\n\t}\n};\nusing mfrac = ModFraction;\n"
  code: "/*\n\t\u6574\u6570\u3092\u304B\u3051\u305F\u308A\u5272\u3063\u305F\u308A\u3057\
    \u3066\u6700\u7D42\u7684\u306A\u5024 mod M \u3092\u6C42\u3081\u308B\u30E9\u30A4\
    \u30D6\u30E9\u30EA\n\t\u4F8B\u3048\u3070 1e9 choose 100 mod M \u3068\u304B\u306B\
    \u4F7F\u3048\u308B\n\n\tModFraction::set_mod(mod) \u3092\u3057\u3066\u304B\u3089\
    \u4F7F\u3046\n\t\tmint \u306E mod \u3068\u540C\u3058\u5024\u3067\u3042\u308B\u3088\
    \u3046\u306B\u3059\u308B\u3053\u3068\n\tval() \u3067 mint \u3068\u3057\u3066\u306E\
    \u5024\u3092\u8FD4\u3059\n\t\t\u6574\u6570\u3067\u306A\u304B\u3063\u305F\u5834\
    \u5408assert\u3092\u3057\u3066\u3044\u308B\u304C\u3001\u72B6\u6CC1\u306B\u5FDC\
    \u3058\u3066\u5909\u3048\u308B\n\n\t*= ll \u3068 /= ll \u3057\u304B\u5B9F\u88C5\
    \u3057\u3066\u306A\u3044\u3051\u3069\u3001ModFraction \u3069\u3046\u3057\u306E\
    \u4E57\u9664\u3082\u5F53\u7136\u51FA\u6765\u308B\n*/\nstruct ModFraction{\n\t\
    static inline ll mod;\n\tstatic inline vector<ll> ps;\n\n\tstatic void set_mod(ll\
    \ mod_){\n\t\tmod = mod_;\n\t\tps.clear();\n\t\t{\t//factorize\n\t\t\tll x = mod;\n\
    \t\t\tfor(ll i=2;i*i<=x;i++) if(x%i==0){\n\t\t\t\tps.pb(i);\n\t\t\t\twhile(x%i==0)\
    \ x/=i;\n\t\t\t}\n\t\t\tif(x>1) ps.pb(x);\n\t\t}\n\t}\n\n\t// val = x * \\prod\
    \ p^e\n\t// x \u306F Z/modZ\n\tvector<int> es;\n\tmint x;\n\n\tmint val(){\n\t\
    \tif(x == 0) return 0;\n\t\trep(i,si(ps)) if(es[i] < 0){\n\t\t\t// not an integer\n\
    \t\t\tassert(false);\n\t\t}\n\t\tmint res = x;\n\t\trep(i,si(ps)){\n\t\t\t// TODO:\
    \ \u9AD8\u901F\u5316\n\t\t\tres *= mint(ps[i]).pow(es[i]);\n\t\t}\n\t\treturn\
    \ res;\n\t}\n\n\tModFraction(ll v){\n\t\trep(i,si(ps)){\n\t\t\tint e = 0;\n\t\t\
    \twhile(v%ps[i] == 0){\n\t\t\t\tv /= ps[i];\n\t\t\t\te++;\n\t\t\t}\n\t\t\tes.eb(e);\n\
    \t\t}\n\t\tx = v;\n\t}\n\tModFraction& operator*=(ll v){\n\t\trep(i,si(ps)){\n\
    \t\t\tint e = 0;\n\t\t\twhile(v%ps[i] == 0){\n\t\t\t\tv /= ps[i];\n\t\t\t\te++;\n\
    \t\t\t}\n\t\t\tes[i] += e;\n\t\t}\n\t\tx *= v;\n\t\treturn *this;\n\t}\n\tModFraction&\
    \ operator/=(ll v){\n\t\tassert(v);\t// div by 0\n\t\trep(i,si(ps)){\n\t\t\tint\
    \ e = 0;\n\t\t\twhile(v%ps[i] == 0){\n\t\t\t\tv /= ps[i];\n\t\t\t\te++;\n\t\t\t\
    }\n\t\t\tes[i] -= e;\n\t\t}\n\t\tx /= v;\n\t\treturn *this;\n\t}\n};\nusing mfrac\
    \ = ModFraction;"
  dependsOn: []
  isVerificationFile: false
  path: math/mod_fraction.hpp
  requiredBy: []
  timestamp: '2024-09-09 05:31:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod_fraction.hpp
layout: document
redirect_from:
- /library/math/mod_fraction.hpp
- /library/math/mod_fraction.hpp.html
title: math/mod_fraction.hpp
---
