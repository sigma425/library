---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/45298
    - https://github.com/quasisphere/conv64/blob/master/conv64.cpp
  bundledCode: "#line 1 \"math/FFT64.cpp\"\n/*\r\n  mod 2^64 FFT\r\n  https://github.com/quasisphere/conv64/blob/master/conv64.cpp\r\
    \n  https://codeforces.com/blog/entry/45298\r\n  \u5B8C\u5168\u306B\u30D6\u30E9\
    \u30C3\u30AF\u30DC\u30C3\u30AF\u30B9 \u2191\u306B\u89E3\u8AAC\u304C\u3042\u308B\
    \r\n  OpenCup \u3067 N = 200000 \u3067 500 ms \u672A\u6E80\r\n  \u7B46\u7B97\u65B9\
    \u91DD\u3067fft * 5\u3067\u3084\u308C\u3070\u3044\u3044\u304B\u3089\u3044\u3089\
    \u306A\u3044\u6C17\u3082\u3059\u308B\u3051\u3069\r\n*/\r\n\r\n\r\nusing ull =\
    \ unsigned long long;\r\nstruct T {\r\n  ull a, b;\r\n\r\n  T() : a(0), b(0) {\
    \ }\r\n  T(ull x) : a(x), b(0) { }\r\n  T(ull a, ull b) : a(a), b(b) { }\r\n\r\
    \n  T conj() {\r\n    return T{a - b, -b};\r\n  }\r\n\r\n  T operator-() {\r\n\
    \    return T{-a, -b};\r\n  }\r\n};\r\n\r\nconst T OMEGA = {0, 1};\r\nconst T\
    \ OMEGA2 = {-1ull, -1ull};\r\nconst T INV3 = {12297829382473034411ull, 0};\r\n\
    \r\nT operator+(const T &u, const T &v) {\r\n  return {u.a + v.a, u.b + v.b};\r\
    \n}\r\n\r\nT operator-(const T &u, const T &v) {\r\n  return {u.a - v.a, u.b -\
    \ v.b};\r\n}\r\n\r\nT operator*(const T &u, const T &v) {\r\n  return {u.a*v.a\
    \ - u.b*v.b, u.b*v.a + u.a*v.b - u.b*v.b};\r\n}\r\n\r\nvoid operator+=(T &u, const\
    \ T &v) {\r\n  u.a += v.a;\r\n  u.b += v.b;\r\n}\r\n\r\nvoid operator-=(T &u,\
    \ const T &v) {\r\n  u.a -= v.a;\r\n  u.b -= v.b;\r\n}\r\n\r\nvoid operator*=(T\
    \ &u, const T &v) {\r\n  ull tmp=u.a;\r\n  u.a=u.a*v.a - u.b*v.b;\r\n  u.b=u.b*v.a\
    \ + tmp*v.b - u.b*v.b;\r\n}\r\n\r\nclass Conv64 {\r\n  public:\r\n\r\n  vector<ull>\
    \ multiply(const vector<ull> &p,\r\n                           const vector<ull>\
    \ &q) {\r\n    vector<ull> pp(p.size()), qq(q.size());\r\n    for (ull i = 0;\
    \ i < p.size(); ++i) {\r\n      pp[i] = p[i];\r\n    }\r\n    for (ull i = 0;\
    \ i < q.size(); ++i) {\r\n      qq[i] = q[i];\r\n    }\r\n    ull s = 1;\r\n \
    \   while (s < p.size() + q.size() - 1) {\r\n      s *= 3;\r\n    }\r\n    pp.resize(s);\r\
    \n    qq.resize(s);\r\n    vector<ull> res(s);\r\n    multiply_cyclic_raw(pp.data(),\
    \ qq.data(), pp.size(), (ull*)res.data());\r\n    res.resize(p.size() + q.size()\
    \ - 1);\r\n    return res;\r\n  }\r\n\r\n  private:\r\n\r\n  T *tmp;\r\n\r\n \
    \ void twiddle(T *p, ull m, ull t, T *to) {\r\n    if (t == 0 || t == 3*m) {\r\
    \n      for (ull j = 0; j < m; ++j) {\r\n        to[j] = p[j];\r\n      }\r\n\
    \      return;\r\n    }\r\n    ull tt;\r\n    T mult = 1;\r\n    if (t < m) {\r\
    \n      tt = t;\r\n    } else if (t < 2*m) {\r\n      tt = t - m;\r\n      mult\
    \ = OMEGA;\r\n    } else {\r\n      tt = t - 2*m;\r\n      mult = OMEGA2;\r\n\
    \    }\r\n    for (ull j=0;j<tt;j++) {\r\n      to[j] = p[m - tt + j]*OMEGA*mult;\r\
    \n    }\r\n    for (ull j=tt;j<m;j++) {\r\n      to[j] = p[j-tt]*mult;\r\n   \
    \ }\r\n  }\r\n\r\n  void fftdif(T *p, ull m, ull r) {\r\n    if (r == 1) return;\r\
    \n    ull rr = r/3;\r\n    ull pos1 = m*rr, pos2 = 2*m*rr;\r\n    for (ull i =\
    \ 0; i < rr; ++i) {\r\n      for (ull j = 0; j < m; ++j) {\r\n        tmp[j] =\
    \ p[i*m + j] + p[pos1 + i*m + j] + p[pos2 + i*m + j];\r\n        tmp[m + j] =\
    \ p[i*m + j] + OMEGA*p[pos1 + i*m + j] + OMEGA2*p[pos2 + i*m + j];\r\n       \
    \ tmp[2*m + j] = p[i*m + j] + OMEGA2*p[pos1 + i*m + j] + OMEGA*p[pos2 + i*m +\
    \ j];\r\n        p[i*m + j] = tmp[j];\r\n      }\r\n      twiddle(tmp + m, m,\
    \ 3*i*m/r, p + pos1 + i*m);\r\n      twiddle(tmp + 2*m, m, 6*i*m/r, p + pos2 +\
    \ i*m);\r\n    }\r\n    fftdif(p, m, rr);\r\n    fftdif(p + pos1, m, rr);\r\n\
    \    fftdif(p + pos2, m, rr);\r\n  }\r\n\r\n  void fftdit(T *p, ull m, ull r)\
    \ {\r\n    if (r == 1) return;\r\n    ull rr = r/3;\r\n    ull pos1 = m*rr, pos2\
    \ = 2*m*rr;\r\n    fftdit(p, m, rr);\r\n    fftdit(p + pos1, m, rr);\r\n    fftdit(p\
    \ + pos2, m, rr);\r\n    for (ull i = 0; i < rr; ++i) {\r\n      twiddle(p + pos1\
    \ + i*m, m, 3*m - 3*i*m/r, tmp + m);\r\n      twiddle(p + pos2 + i*m, m, 3*m -\
    \ 6*i*m/r, tmp + 2*m);\r\n      for(ull j = 0; j < m; ++j) {\r\n        tmp[j]\
    \ = p[i*m + j];\r\n        p[i*m + j] = tmp[j] + tmp[m + j] + tmp[2*m + j];\r\n\
    \        p[i*m + pos1 + j] = tmp[j] + OMEGA2*tmp[m + j] + OMEGA*tmp[2*m + j];\r\
    \n        p[i*m + pos2 + j] = tmp[j] + OMEGA*tmp[m + j] + OMEGA2*tmp[2*m + j];\r\
    \n      }\r\n    }\r\n  }\r\n\r\n  void mul(T *p, T *q, ull n, T *to) {\r\n  \
    \  if (n <= 27) {\r\n      for (ull i = 0; i < n; ++i) {\r\n        to[i]=0;\r\
    \n      }\r\n      for (ull i = 0; i < n; ++i) {\r\n        for (ull j = 0; j\
    \ < n - i; ++j) {\r\n          to[i + j] += p[i]*q[j];\r\n        }\r\n      \
    \  for (ull j = n - i; j < n; ++j) {\r\n          to[i + j - n] += p[i]*q[j]*OMEGA;\r\
    \n        }\r\n      }\r\n      return;\r\n    }\r\n\r\n    ull m = 1;\r\n   \
    \ while (m*m < n) {\r\n      m *= 3;\r\n    }\r\n    ull r = n/m;\r\n\r\n    T\
    \ inv = 1;\r\n    for (ull i = 1; i < r; i *= 3) {\r\n      inv *= INV3;\r\n \
    \   }\r\n\r\n    for (ull i = 0; i < r; ++i) {\r\n      twiddle(p + m*i, m, m/r*i,\
    \ to + m*i);\r\n      twiddle(q + m*i, m, m/r*i, to + n + m*i);\r\n    }\r\n\r\
    \n    fftdif(to, m, r);\r\n    fftdif(to + n, m, r);\r\n    for (ull i = 0; i\
    \ < r; ++i) {\r\n      mul(to + m*i, to + n + m*i, m, to +2*n + m*i);\r\n    }\r\
    \n    fftdit(to + 2*n, m, r);\r\n    for (ull i = 0; i < n; ++i) {\r\n      to[2*n\
    \ + i] *= inv;\r\n    }\r\n\r\n    for (ull i = 0; i < r; ++i) {\r\n      twiddle(to\
    \ + 2*n + m*i, m, 3*m - m/r*i, to + n + m*i);\r\n    }\r\n\r\n    for (ull i =\
    \ 0; i < r; ++i) {\r\n      for (ull j = 0; j < m; ++j) {\r\n        p[m*i + j]\
    \ = p[m*i + j].conj();\r\n        q[m*i + j] = q[m*i + j].conj();\r\n      }\r\
    \n      twiddle(p + m*i, m, 2*m/r*i, to + m*i);\r\n      twiddle(q + m*i, m, 2*m/r*i,\
    \ p + m*i);\r\n    }\r\n\r\n    fftdif(to, m, r);\r\n    fftdif(p, m, r);\r\n\
    \    for (ull i = 0; i < r; ++i) {\r\n      mul(to + m*i, p + m*i, m, to + 2*n\
    \ + m*i);\r\n    }\r\n    fftdit(to + 2*n, m, r);\r\n    for (ull i = 0; i < n;\
    \ ++i) {\r\n      to[2*n + i] *= inv;\r\n    }\r\n\r\n    for (ull i = 0; i <\
    \ r; ++i) {\r\n      twiddle(to + 2*n + m*i, m, 3*m - 2*m/r*i, q + m*i);\r\n \
    \   }\r\n\r\n    for (ull i = 0; i < n; ++i) {\r\n      to[i] = 0;\r\n    }\r\n\
    \    for (ull i = 0; i < r; ++i) {\r\n      for (ull j = 0; j < m; ++j) {\r\n\
    \        to[i*m + j] += (1 - OMEGA)*to[n + i*m + j] + (1 - OMEGA2)*q[i*m + j].conj();\r\
    \n        if (i*m + m + j < n) {\r\n          to[i*m + m + j] += (OMEGA2 - OMEGA)*(to[n\
    \ + i*m + j] - q[i*m + j].conj());\r\n        } else {\r\n          to[i*m + m\
    \ + j - n] += (1 - OMEGA2)*(to[n + i*m + j] - q[i*m + j].conj());\r\n        }\r\
    \n      }\r\n    }\r\n    for (ull i = 0; i < n; ++i) {\r\n      to[i] *= INV3;\r\
    \n    }\r\n  }\r\n\r\n  void multiply_cyclic_raw(ull *p, ull *q, ull n,\r\n  \
    \                                     ull *target) {\r\n    ull m = 1;\r\n   \
    \ while (m*m <= n) {\r\n      m *= 3;\r\n    }\r\n    m /= 3;\r\n    ull r = n/m;\r\
    \n\r\n    T inv = 1;\r\n    for (ull i = 1; i < r; i *= 3) {\r\n      inv *= INV3;\r\
    \n    }\r\n\r\n    T *buf = new T[3*n + 6*m];\r\n    T *pp = buf;\r\n    T *qq\
    \ = buf + n;\r\n    T *to = buf + 2*n;\r\n    tmp = buf + 3*n + 3*m;\r\n\r\n \
    \   for (ull i = 0; i < n; ++i) {\r\n      pp[i] = p[i];\r\n      qq[i] = q[i];\r\
    \n    }\r\n\r\n    fftdif(pp, m, r);\r\n    fftdif(qq, m, r);\r\n    for (ull\
    \ i = 0; i < r; ++i) {\r\n      mul(pp + i*m, qq + i*m, m, to + i*m);\r\n    }\r\
    \n    fftdit(to, m, r);\r\n    for (ull i = 0; i<n; ++i) {\r\n      pp[i] = to[i]*inv;\r\
    \n    }\r\n    \r\n    for (ull i = 0; i < n; ++i) to[i] = 0;\r\n    for (ull\
    \ i = 0; i < r; ++i) {\r\n      for (ull j = 0; j < m; ++j) {\r\n        to[i*m\
    \ + j] += (1 - OMEGA)*pp[i*m + j] + (1 - OMEGA2)*pp[i*m + j].conj();\r\n     \
    \   if (i*m + m + j < n) {\r\n          to[i*m + m + j] += (OMEGA2 - OMEGA)*(pp[i*m\
    \ + j] - pp[i*m + j].conj());\r\n        } else {\r\n          to[i*m + m + j\
    \ - n] += (OMEGA2 - OMEGA) * (pp[i*m + j] - pp[i*m + j].conj());\r\n        }\r\
    \n      }\r\n    }\r\n    for (ull i = 0; i < n; ++i) {\r\n      target[i] = (to[i]*INV3).a;\r\
    \n    }\r\n\r\n    delete[] buf;\r\n  }\r\n};\r\n\r\nV<ull> multiply(V<ull> a,V<ull>\
    \ b){\r\n\tConv64 c;\r\n\treturn c.multiply(a,b);\r\n}\r\n"
  code: "/*\r\n  mod 2^64 FFT\r\n  https://github.com/quasisphere/conv64/blob/master/conv64.cpp\r\
    \n  https://codeforces.com/blog/entry/45298\r\n  \u5B8C\u5168\u306B\u30D6\u30E9\
    \u30C3\u30AF\u30DC\u30C3\u30AF\u30B9 \u2191\u306B\u89E3\u8AAC\u304C\u3042\u308B\
    \r\n  OpenCup \u3067 N = 200000 \u3067 500 ms \u672A\u6E80\r\n  \u7B46\u7B97\u65B9\
    \u91DD\u3067fft * 5\u3067\u3084\u308C\u3070\u3044\u3044\u304B\u3089\u3044\u3089\
    \u306A\u3044\u6C17\u3082\u3059\u308B\u3051\u3069\r\n*/\r\n\r\n\r\nusing ull =\
    \ unsigned long long;\r\nstruct T {\r\n  ull a, b;\r\n\r\n  T() : a(0), b(0) {\
    \ }\r\n  T(ull x) : a(x), b(0) { }\r\n  T(ull a, ull b) : a(a), b(b) { }\r\n\r\
    \n  T conj() {\r\n    return T{a - b, -b};\r\n  }\r\n\r\n  T operator-() {\r\n\
    \    return T{-a, -b};\r\n  }\r\n};\r\n\r\nconst T OMEGA = {0, 1};\r\nconst T\
    \ OMEGA2 = {-1ull, -1ull};\r\nconst T INV3 = {12297829382473034411ull, 0};\r\n\
    \r\nT operator+(const T &u, const T &v) {\r\n  return {u.a + v.a, u.b + v.b};\r\
    \n}\r\n\r\nT operator-(const T &u, const T &v) {\r\n  return {u.a - v.a, u.b -\
    \ v.b};\r\n}\r\n\r\nT operator*(const T &u, const T &v) {\r\n  return {u.a*v.a\
    \ - u.b*v.b, u.b*v.a + u.a*v.b - u.b*v.b};\r\n}\r\n\r\nvoid operator+=(T &u, const\
    \ T &v) {\r\n  u.a += v.a;\r\n  u.b += v.b;\r\n}\r\n\r\nvoid operator-=(T &u,\
    \ const T &v) {\r\n  u.a -= v.a;\r\n  u.b -= v.b;\r\n}\r\n\r\nvoid operator*=(T\
    \ &u, const T &v) {\r\n  ull tmp=u.a;\r\n  u.a=u.a*v.a - u.b*v.b;\r\n  u.b=u.b*v.a\
    \ + tmp*v.b - u.b*v.b;\r\n}\r\n\r\nclass Conv64 {\r\n  public:\r\n\r\n  vector<ull>\
    \ multiply(const vector<ull> &p,\r\n                           const vector<ull>\
    \ &q) {\r\n    vector<ull> pp(p.size()), qq(q.size());\r\n    for (ull i = 0;\
    \ i < p.size(); ++i) {\r\n      pp[i] = p[i];\r\n    }\r\n    for (ull i = 0;\
    \ i < q.size(); ++i) {\r\n      qq[i] = q[i];\r\n    }\r\n    ull s = 1;\r\n \
    \   while (s < p.size() + q.size() - 1) {\r\n      s *= 3;\r\n    }\r\n    pp.resize(s);\r\
    \n    qq.resize(s);\r\n    vector<ull> res(s);\r\n    multiply_cyclic_raw(pp.data(),\
    \ qq.data(), pp.size(), (ull*)res.data());\r\n    res.resize(p.size() + q.size()\
    \ - 1);\r\n    return res;\r\n  }\r\n\r\n  private:\r\n\r\n  T *tmp;\r\n\r\n \
    \ void twiddle(T *p, ull m, ull t, T *to) {\r\n    if (t == 0 || t == 3*m) {\r\
    \n      for (ull j = 0; j < m; ++j) {\r\n        to[j] = p[j];\r\n      }\r\n\
    \      return;\r\n    }\r\n    ull tt;\r\n    T mult = 1;\r\n    if (t < m) {\r\
    \n      tt = t;\r\n    } else if (t < 2*m) {\r\n      tt = t - m;\r\n      mult\
    \ = OMEGA;\r\n    } else {\r\n      tt = t - 2*m;\r\n      mult = OMEGA2;\r\n\
    \    }\r\n    for (ull j=0;j<tt;j++) {\r\n      to[j] = p[m - tt + j]*OMEGA*mult;\r\
    \n    }\r\n    for (ull j=tt;j<m;j++) {\r\n      to[j] = p[j-tt]*mult;\r\n   \
    \ }\r\n  }\r\n\r\n  void fftdif(T *p, ull m, ull r) {\r\n    if (r == 1) return;\r\
    \n    ull rr = r/3;\r\n    ull pos1 = m*rr, pos2 = 2*m*rr;\r\n    for (ull i =\
    \ 0; i < rr; ++i) {\r\n      for (ull j = 0; j < m; ++j) {\r\n        tmp[j] =\
    \ p[i*m + j] + p[pos1 + i*m + j] + p[pos2 + i*m + j];\r\n        tmp[m + j] =\
    \ p[i*m + j] + OMEGA*p[pos1 + i*m + j] + OMEGA2*p[pos2 + i*m + j];\r\n       \
    \ tmp[2*m + j] = p[i*m + j] + OMEGA2*p[pos1 + i*m + j] + OMEGA*p[pos2 + i*m +\
    \ j];\r\n        p[i*m + j] = tmp[j];\r\n      }\r\n      twiddle(tmp + m, m,\
    \ 3*i*m/r, p + pos1 + i*m);\r\n      twiddle(tmp + 2*m, m, 6*i*m/r, p + pos2 +\
    \ i*m);\r\n    }\r\n    fftdif(p, m, rr);\r\n    fftdif(p + pos1, m, rr);\r\n\
    \    fftdif(p + pos2, m, rr);\r\n  }\r\n\r\n  void fftdit(T *p, ull m, ull r)\
    \ {\r\n    if (r == 1) return;\r\n    ull rr = r/3;\r\n    ull pos1 = m*rr, pos2\
    \ = 2*m*rr;\r\n    fftdit(p, m, rr);\r\n    fftdit(p + pos1, m, rr);\r\n    fftdit(p\
    \ + pos2, m, rr);\r\n    for (ull i = 0; i < rr; ++i) {\r\n      twiddle(p + pos1\
    \ + i*m, m, 3*m - 3*i*m/r, tmp + m);\r\n      twiddle(p + pos2 + i*m, m, 3*m -\
    \ 6*i*m/r, tmp + 2*m);\r\n      for(ull j = 0; j < m; ++j) {\r\n        tmp[j]\
    \ = p[i*m + j];\r\n        p[i*m + j] = tmp[j] + tmp[m + j] + tmp[2*m + j];\r\n\
    \        p[i*m + pos1 + j] = tmp[j] + OMEGA2*tmp[m + j] + OMEGA*tmp[2*m + j];\r\
    \n        p[i*m + pos2 + j] = tmp[j] + OMEGA*tmp[m + j] + OMEGA2*tmp[2*m + j];\r\
    \n      }\r\n    }\r\n  }\r\n\r\n  void mul(T *p, T *q, ull n, T *to) {\r\n  \
    \  if (n <= 27) {\r\n      for (ull i = 0; i < n; ++i) {\r\n        to[i]=0;\r\
    \n      }\r\n      for (ull i = 0; i < n; ++i) {\r\n        for (ull j = 0; j\
    \ < n - i; ++j) {\r\n          to[i + j] += p[i]*q[j];\r\n        }\r\n      \
    \  for (ull j = n - i; j < n; ++j) {\r\n          to[i + j - n] += p[i]*q[j]*OMEGA;\r\
    \n        }\r\n      }\r\n      return;\r\n    }\r\n\r\n    ull m = 1;\r\n   \
    \ while (m*m < n) {\r\n      m *= 3;\r\n    }\r\n    ull r = n/m;\r\n\r\n    T\
    \ inv = 1;\r\n    for (ull i = 1; i < r; i *= 3) {\r\n      inv *= INV3;\r\n \
    \   }\r\n\r\n    for (ull i = 0; i < r; ++i) {\r\n      twiddle(p + m*i, m, m/r*i,\
    \ to + m*i);\r\n      twiddle(q + m*i, m, m/r*i, to + n + m*i);\r\n    }\r\n\r\
    \n    fftdif(to, m, r);\r\n    fftdif(to + n, m, r);\r\n    for (ull i = 0; i\
    \ < r; ++i) {\r\n      mul(to + m*i, to + n + m*i, m, to +2*n + m*i);\r\n    }\r\
    \n    fftdit(to + 2*n, m, r);\r\n    for (ull i = 0; i < n; ++i) {\r\n      to[2*n\
    \ + i] *= inv;\r\n    }\r\n\r\n    for (ull i = 0; i < r; ++i) {\r\n      twiddle(to\
    \ + 2*n + m*i, m, 3*m - m/r*i, to + n + m*i);\r\n    }\r\n\r\n    for (ull i =\
    \ 0; i < r; ++i) {\r\n      for (ull j = 0; j < m; ++j) {\r\n        p[m*i + j]\
    \ = p[m*i + j].conj();\r\n        q[m*i + j] = q[m*i + j].conj();\r\n      }\r\
    \n      twiddle(p + m*i, m, 2*m/r*i, to + m*i);\r\n      twiddle(q + m*i, m, 2*m/r*i,\
    \ p + m*i);\r\n    }\r\n\r\n    fftdif(to, m, r);\r\n    fftdif(p, m, r);\r\n\
    \    for (ull i = 0; i < r; ++i) {\r\n      mul(to + m*i, p + m*i, m, to + 2*n\
    \ + m*i);\r\n    }\r\n    fftdit(to + 2*n, m, r);\r\n    for (ull i = 0; i < n;\
    \ ++i) {\r\n      to[2*n + i] *= inv;\r\n    }\r\n\r\n    for (ull i = 0; i <\
    \ r; ++i) {\r\n      twiddle(to + 2*n + m*i, m, 3*m - 2*m/r*i, q + m*i);\r\n \
    \   }\r\n\r\n    for (ull i = 0; i < n; ++i) {\r\n      to[i] = 0;\r\n    }\r\n\
    \    for (ull i = 0; i < r; ++i) {\r\n      for (ull j = 0; j < m; ++j) {\r\n\
    \        to[i*m + j] += (1 - OMEGA)*to[n + i*m + j] + (1 - OMEGA2)*q[i*m + j].conj();\r\
    \n        if (i*m + m + j < n) {\r\n          to[i*m + m + j] += (OMEGA2 - OMEGA)*(to[n\
    \ + i*m + j] - q[i*m + j].conj());\r\n        } else {\r\n          to[i*m + m\
    \ + j - n] += (1 - OMEGA2)*(to[n + i*m + j] - q[i*m + j].conj());\r\n        }\r\
    \n      }\r\n    }\r\n    for (ull i = 0; i < n; ++i) {\r\n      to[i] *= INV3;\r\
    \n    }\r\n  }\r\n\r\n  void multiply_cyclic_raw(ull *p, ull *q, ull n,\r\n  \
    \                                     ull *target) {\r\n    ull m = 1;\r\n   \
    \ while (m*m <= n) {\r\n      m *= 3;\r\n    }\r\n    m /= 3;\r\n    ull r = n/m;\r\
    \n\r\n    T inv = 1;\r\n    for (ull i = 1; i < r; i *= 3) {\r\n      inv *= INV3;\r\
    \n    }\r\n\r\n    T *buf = new T[3*n + 6*m];\r\n    T *pp = buf;\r\n    T *qq\
    \ = buf + n;\r\n    T *to = buf + 2*n;\r\n    tmp = buf + 3*n + 3*m;\r\n\r\n \
    \   for (ull i = 0; i < n; ++i) {\r\n      pp[i] = p[i];\r\n      qq[i] = q[i];\r\
    \n    }\r\n\r\n    fftdif(pp, m, r);\r\n    fftdif(qq, m, r);\r\n    for (ull\
    \ i = 0; i < r; ++i) {\r\n      mul(pp + i*m, qq + i*m, m, to + i*m);\r\n    }\r\
    \n    fftdit(to, m, r);\r\n    for (ull i = 0; i<n; ++i) {\r\n      pp[i] = to[i]*inv;\r\
    \n    }\r\n    \r\n    for (ull i = 0; i < n; ++i) to[i] = 0;\r\n    for (ull\
    \ i = 0; i < r; ++i) {\r\n      for (ull j = 0; j < m; ++j) {\r\n        to[i*m\
    \ + j] += (1 - OMEGA)*pp[i*m + j] + (1 - OMEGA2)*pp[i*m + j].conj();\r\n     \
    \   if (i*m + m + j < n) {\r\n          to[i*m + m + j] += (OMEGA2 - OMEGA)*(pp[i*m\
    \ + j] - pp[i*m + j].conj());\r\n        } else {\r\n          to[i*m + m + j\
    \ - n] += (OMEGA2 - OMEGA) * (pp[i*m + j] - pp[i*m + j].conj());\r\n        }\r\
    \n      }\r\n    }\r\n    for (ull i = 0; i < n; ++i) {\r\n      target[i] = (to[i]*INV3).a;\r\
    \n    }\r\n\r\n    delete[] buf;\r\n  }\r\n};\r\n\r\nV<ull> multiply(V<ull> a,V<ull>\
    \ b){\r\n\tConv64 c;\r\n\treturn c.multiply(a,b);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/FFT64.cpp
  requiredBy: []
  timestamp: '2019-01-11 10:58:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/FFT64.cpp
layout: document
redirect_from:
- /library/math/FFT64.cpp
- /library/math/FFT64.cpp.html
title: math/FFT64.cpp
---
