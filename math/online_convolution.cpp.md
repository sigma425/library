---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_oj/online_conv/online_conv.test.cpp
    title: test_oj/online_conv/online_conv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_oj/online_conv/online_div.test.cpp
    title: test_oj/online_conv/online_div.test.cpp
  - icon: ':x:'
    path: test_oj/online_conv/online_pow.test.cpp
    title: test_oj/online_conv/online_pow.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/online_convolution.cpp\"\n/*\n\tquery(i): f_i, g_i\
    \ \u3092\u53D7\u3051\u53D6\u3063\u3066 fg_i \u3092\u8FD4\u3059\n\tO(n log^2)\n\
    \t2^18: 300ms\n\t2^19: 700ms\n\t2^20: 1500ms\n\n\t[0] [12] [3456] [7..14] .. \u3068\
    \u308F\u3051\u3066\u3046\u307E\u304F\u3084\u308B\n*/\ntemplate<class mint>\nstruct\
    \ Online_Convolution{\n\tconst int thresh = 3;\n\tV<mint> f,g,h;\n\tVV<mint> fft_f,fft_g;\n\
    \n\tpair<V<mint>,V<mint>> calc_fft(int k){\n\t\t// \u9577\u3055 2^k \u306E suffix\
    \ \u3092 fft \u3057\u305F\u3082\u306E\u3092\u8FD4\u3059\n\t\tint L = 1<<k;\n\t\
    \tV<mint> f_suf(2*L), g_suf(2*L);\n\t\trep(i,L){\n\t\t\tf_suf[i] = f[si(f)-L+i];\n\
    \t\t\tg_suf[i] = g[si(g)-L+i];\n\t\t}\n\t\tif(k > thresh){\n\t\t\tfft(f_suf);\
    \ fft(g_suf);\n\t\t}\n\t\treturn {f_suf, g_suf};\n\t}\n\tvoid calc(int k){\n\t\
    \tint L = 1<<k;\n\t\tauto [zf,zg] = calc_fft(k);\n\t\tV<mint> zh(L*2);\n\t\tbool\
    \ fst = (k >= si(fft_f));\n\t\tif(fst){\n\t\t\tfft_f.eb(zf);\n\t\t\tfft_g.eb(zg);\n\
    \t\t}\n\t\tif(k > thresh){\n\t\t\tif(fst){\n\t\t\t\trep(i,L*2) zh[i] += zf[i]\
    \ * zg[i];\n\t\t\t\tinvfft(zh);\n\t\t\t}else{\n\t\t\t\trep(i,L*2){\n\t\t\t\t\t\
    zh[i] += zf[i] * fft_g[k][i];\n\t\t\t\t\tzh[i] += zg[i] * fft_f[k][i];\n\t\t\t\
    \t}\n\t\t\t\tinvfft(zh);\n\t\t\t}\n\t\t}else{\n\t\t\tif(fst){\n\t\t\t\trep(i,L)\
    \ rep(j,L) zh[i+j] += zf[i] * zg[j];\n\t\t\t}else{\n\t\t\t\trep(i,L) rep(j,L)\
    \ zh[i+j] += zf[i] * fft_g[k][j];\n\t\t\t\trep(i,L) rep(j,L) zh[i+j] += zg[i]\
    \ * fft_f[k][j];\n\t\t\t}\n\t\t}\n\t\tint off = si(f)-1;\n\t\trep(i,L*2-1){\n\t\
    \t\tif(si(h) <= off+i) h.eb(0);\n\t\t\th[off + i] += zh[i];\n\t\t}\n\t}\n\n\t\
    mint query(int i, mint f_i, mint g_i){\n\t\tassert(i == si(f));\n\t\tf.eb(f_i);\n\
    \t\tg.eb(g_i);\n\t\tint K = __builtin_ctz(i+2) + (__builtin_popcount(i+2) > 1\
    \ ? 1 : 0);\n\t\trep(k,K) calc(k);\n\t\treturn h[i];\n\t}\n};\n\n/*\n\tquery(i):\
    \ f_i, g_i \u3092\u53D7\u3051\u53D6\u3063\u3066 (f/g)_i \u3092\u8FD4\u3059\n\t\
    g_0 != 0 \u3092\u4EEE\u5B9A\n\tO(n log^2)\n*/\ntemplate<class mint>\nstruct Online_Division{\n\
    \tV<mint> f,g,h;\n\tOnline_Convolution<mint> X;\n\tmint ig0;\n\n\tmint query(int\
    \ i, mint f_i, mint g_i){\n\t\tassert(i == si(f));\n\t\tf.eb(f_i);\n\t\tg.eb(g_i);\n\
    \t\tif(i == 0){\n\t\t\tassert(g_i);\n\t\t\tig0 = g_i.inv();\n\t\t\th.eb(f_i *\
    \ ig0);\n\t\t}else{\n\t\t\th.eb( (f_i - X.query(i-1,g[i],h[i-1])) * ig0);\n\t\t\
    }\n\t\treturn h[i];\n\t}\n};\n\n/*\n\tquery(i): f_i \u3092\u53D7\u3051\u53D6\u3063\
    \u3066 (f^K)_i \u3092\u8FD4\u3059\n\tf_0 != 0 \u3092\u4EEE\u5B9A (\u9811\u5F35\
    \u308C\u3070\u5916\u305B\u308B)\n\tO(n log^2)\n\tg := f^K\n\tg'f = Kgf'\n\t\t\
    f_0 g_1\t\tf_0 2g_2 + f_1 g_1\t\tf_0 3g_3 + f_1 2g_2 + f_2 g_1\n\t= K(f_1 g_0\t\
    \t2f_2 g_0 + f_1 g_1\t\t3f_3 g_0 + 2f_2 g_1 + f_1 g_2\n*/\ntemplate<class mint>\n\
    struct Online_Pow{\n\tOnline_Pow(ll K_):K(K_){}\n\n\tV<mint> f,g;\n\tll K;\n\t\
    Online_Convolution<mint> X;\t\t// (f-f0)/x * g'\n\tOnline_Convolution<mint> Y;\t\
    \t// f' * g\n\tmint if0;\n\n\tmint query(int i, mint f_i){\n\t\tassert(i == si(f));\n\
    \t\tf.eb(f_i);\n\t\tif(i == 0){\n\t\t\tassert(f_i);\n\t\t\tif0 = f_i.inv();\n\t\
    \t\tg.eb(f_i.pow(K));\n\t\t}else{\n\t\t\tmint Y_i = Y.query(i-1,f[i]*i,g[i-1]);\n\
    \t\t\tmint X_i = i == 1 ? 0 : X.query(i-2,f[i-1],g[i-1]*(i-1));\n\t\t\tassert(i\
    \ < si(invs));\n\t\t\tg.eb( (Y_i*K - X_i) * if0 * invs[i]);\n\t\t}\n\t\treturn\
    \ g[i];\n\t}\n};\n"
  code: "/*\n\tquery(i): f_i, g_i \u3092\u53D7\u3051\u53D6\u3063\u3066 fg_i \u3092\
    \u8FD4\u3059\n\tO(n log^2)\n\t2^18: 300ms\n\t2^19: 700ms\n\t2^20: 1500ms\n\n\t\
    [0] [12] [3456] [7..14] .. \u3068\u308F\u3051\u3066\u3046\u307E\u304F\u3084\u308B\
    \n*/\ntemplate<class mint>\nstruct Online_Convolution{\n\tconst int thresh = 3;\n\
    \tV<mint> f,g,h;\n\tVV<mint> fft_f,fft_g;\n\n\tpair<V<mint>,V<mint>> calc_fft(int\
    \ k){\n\t\t// \u9577\u3055 2^k \u306E suffix \u3092 fft \u3057\u305F\u3082\u306E\
    \u3092\u8FD4\u3059\n\t\tint L = 1<<k;\n\t\tV<mint> f_suf(2*L), g_suf(2*L);\n\t\
    \trep(i,L){\n\t\t\tf_suf[i] = f[si(f)-L+i];\n\t\t\tg_suf[i] = g[si(g)-L+i];\n\t\
    \t}\n\t\tif(k > thresh){\n\t\t\tfft(f_suf); fft(g_suf);\n\t\t}\n\t\treturn {f_suf,\
    \ g_suf};\n\t}\n\tvoid calc(int k){\n\t\tint L = 1<<k;\n\t\tauto [zf,zg] = calc_fft(k);\n\
    \t\tV<mint> zh(L*2);\n\t\tbool fst = (k >= si(fft_f));\n\t\tif(fst){\n\t\t\tfft_f.eb(zf);\n\
    \t\t\tfft_g.eb(zg);\n\t\t}\n\t\tif(k > thresh){\n\t\t\tif(fst){\n\t\t\t\trep(i,L*2)\
    \ zh[i] += zf[i] * zg[i];\n\t\t\t\tinvfft(zh);\n\t\t\t}else{\n\t\t\t\trep(i,L*2){\n\
    \t\t\t\t\tzh[i] += zf[i] * fft_g[k][i];\n\t\t\t\t\tzh[i] += zg[i] * fft_f[k][i];\n\
    \t\t\t\t}\n\t\t\t\tinvfft(zh);\n\t\t\t}\n\t\t}else{\n\t\t\tif(fst){\n\t\t\t\t\
    rep(i,L) rep(j,L) zh[i+j] += zf[i] * zg[j];\n\t\t\t}else{\n\t\t\t\trep(i,L) rep(j,L)\
    \ zh[i+j] += zf[i] * fft_g[k][j];\n\t\t\t\trep(i,L) rep(j,L) zh[i+j] += zg[i]\
    \ * fft_f[k][j];\n\t\t\t}\n\t\t}\n\t\tint off = si(f)-1;\n\t\trep(i,L*2-1){\n\t\
    \t\tif(si(h) <= off+i) h.eb(0);\n\t\t\th[off + i] += zh[i];\n\t\t}\n\t}\n\n\t\
    mint query(int i, mint f_i, mint g_i){\n\t\tassert(i == si(f));\n\t\tf.eb(f_i);\n\
    \t\tg.eb(g_i);\n\t\tint K = __builtin_ctz(i+2) + (__builtin_popcount(i+2) > 1\
    \ ? 1 : 0);\n\t\trep(k,K) calc(k);\n\t\treturn h[i];\n\t}\n};\n\n/*\n\tquery(i):\
    \ f_i, g_i \u3092\u53D7\u3051\u53D6\u3063\u3066 (f/g)_i \u3092\u8FD4\u3059\n\t\
    g_0 != 0 \u3092\u4EEE\u5B9A\n\tO(n log^2)\n*/\ntemplate<class mint>\nstruct Online_Division{\n\
    \tV<mint> f,g,h;\n\tOnline_Convolution<mint> X;\n\tmint ig0;\n\n\tmint query(int\
    \ i, mint f_i, mint g_i){\n\t\tassert(i == si(f));\n\t\tf.eb(f_i);\n\t\tg.eb(g_i);\n\
    \t\tif(i == 0){\n\t\t\tassert(g_i);\n\t\t\tig0 = g_i.inv();\n\t\t\th.eb(f_i *\
    \ ig0);\n\t\t}else{\n\t\t\th.eb( (f_i - X.query(i-1,g[i],h[i-1])) * ig0);\n\t\t\
    }\n\t\treturn h[i];\n\t}\n};\n\n/*\n\tquery(i): f_i \u3092\u53D7\u3051\u53D6\u3063\
    \u3066 (f^K)_i \u3092\u8FD4\u3059\n\tf_0 != 0 \u3092\u4EEE\u5B9A (\u9811\u5F35\
    \u308C\u3070\u5916\u305B\u308B)\n\tO(n log^2)\n\tg := f^K\n\tg'f = Kgf'\n\t\t\
    f_0 g_1\t\tf_0 2g_2 + f_1 g_1\t\tf_0 3g_3 + f_1 2g_2 + f_2 g_1\n\t= K(f_1 g_0\t\
    \t2f_2 g_0 + f_1 g_1\t\t3f_3 g_0 + 2f_2 g_1 + f_1 g_2\n*/\ntemplate<class mint>\n\
    struct Online_Pow{\n\tOnline_Pow(ll K_):K(K_){}\n\n\tV<mint> f,g;\n\tll K;\n\t\
    Online_Convolution<mint> X;\t\t// (f-f0)/x * g'\n\tOnline_Convolution<mint> Y;\t\
    \t// f' * g\n\tmint if0;\n\n\tmint query(int i, mint f_i){\n\t\tassert(i == si(f));\n\
    \t\tf.eb(f_i);\n\t\tif(i == 0){\n\t\t\tassert(f_i);\n\t\t\tif0 = f_i.inv();\n\t\
    \t\tg.eb(f_i.pow(K));\n\t\t}else{\n\t\t\tmint Y_i = Y.query(i-1,f[i]*i,g[i-1]);\n\
    \t\t\tmint X_i = i == 1 ? 0 : X.query(i-2,f[i-1],g[i-1]*(i-1));\n\t\t\tassert(i\
    \ < si(invs));\n\t\t\tg.eb( (Y_i*K - X_i) * if0 * invs[i]);\n\t\t}\n\t\treturn\
    \ g[i];\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/online_convolution.cpp
  requiredBy: []
  timestamp: '2022-11-20 04:11:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_oj/online_conv/online_pow.test.cpp
  - test_oj/online_conv/online_div.test.cpp
  - test_oj/online_conv/online_conv.test.cpp
documentation_of: math/online_convolution.cpp
layout: document
redirect_from:
- /library/math/online_convolution.cpp
- /library/math/online_convolution.cpp.html
title: math/online_convolution.cpp
---
