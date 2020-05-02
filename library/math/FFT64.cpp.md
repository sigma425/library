---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: math/FFT64.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/FFT64.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-11 10:58:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
  mod 2^64 FFT
  https://github.com/quasisphere/conv64/blob/master/conv64.cpp
  https://codeforces.com/blog/entry/45298
  完全にブラックボックス ↑に解説がある
  OpenCup で N = 200000 で 500 ms 未満
  筆算方針でfft * 5でやればいいからいらない気もするけど
*/


using ull = unsigned long long;
struct T {
  ull a, b;

  T() : a(0), b(0) { }
  T(ull x) : a(x), b(0) { }
  T(ull a, ull b) : a(a), b(b) { }

  T conj() {
    return T{a - b, -b};
  }

  T operator-() {
    return T{-a, -b};
  }
};

const T OMEGA = {0, 1};
const T OMEGA2 = {-1ull, -1ull};
const T INV3 = {12297829382473034411ull, 0};

T operator+(const T &u, const T &v) {
  return {u.a + v.a, u.b + v.b};
}

T operator-(const T &u, const T &v) {
  return {u.a - v.a, u.b - v.b};
}

T operator*(const T &u, const T &v) {
  return {u.a*v.a - u.b*v.b, u.b*v.a + u.a*v.b - u.b*v.b};
}

void operator+=(T &u, const T &v) {
  u.a += v.a;
  u.b += v.b;
}

void operator-=(T &u, const T &v) {
  u.a -= v.a;
  u.b -= v.b;
}

void operator*=(T &u, const T &v) {
  ull tmp=u.a;
  u.a=u.a*v.a - u.b*v.b;
  u.b=u.b*v.a + tmp*v.b - u.b*v.b;
}

class Conv64 {
  public:

  vector<ull> multiply(const vector<ull> &p,
                           const vector<ull> &q) {
    vector<ull> pp(p.size()), qq(q.size());
    for (ull i = 0; i < p.size(); ++i) {
      pp[i] = p[i];
    }
    for (ull i = 0; i < q.size(); ++i) {
      qq[i] = q[i];
    }
    ull s = 1;
    while (s < p.size() + q.size() - 1) {
      s *= 3;
    }
    pp.resize(s);
    qq.resize(s);
    vector<ull> res(s);
    multiply_cyclic_raw(pp.data(), qq.data(), pp.size(), (ull*)res.data());
    res.resize(p.size() + q.size() - 1);
    return res;
  }

  private:

  T *tmp;

  void twiddle(T *p, ull m, ull t, T *to) {
    if (t == 0 || t == 3*m) {
      for (ull j = 0; j < m; ++j) {
        to[j] = p[j];
      }
      return;
    }
    ull tt;
    T mult = 1;
    if (t < m) {
      tt = t;
    } else if (t < 2*m) {
      tt = t - m;
      mult = OMEGA;
    } else {
      tt = t - 2*m;
      mult = OMEGA2;
    }
    for (ull j=0;j<tt;j++) {
      to[j] = p[m - tt + j]*OMEGA*mult;
    }
    for (ull j=tt;j<m;j++) {
      to[j] = p[j-tt]*mult;
    }
  }

  void fftdif(T *p, ull m, ull r) {
    if (r == 1) return;
    ull rr = r/3;
    ull pos1 = m*rr, pos2 = 2*m*rr;
    for (ull i = 0; i < rr; ++i) {
      for (ull j = 0; j < m; ++j) {
        tmp[j] = p[i*m + j] + p[pos1 + i*m + j] + p[pos2 + i*m + j];
        tmp[m + j] = p[i*m + j] + OMEGA*p[pos1 + i*m + j] + OMEGA2*p[pos2 + i*m + j];
        tmp[2*m + j] = p[i*m + j] + OMEGA2*p[pos1 + i*m + j] + OMEGA*p[pos2 + i*m + j];
        p[i*m + j] = tmp[j];
      }
      twiddle(tmp + m, m, 3*i*m/r, p + pos1 + i*m);
      twiddle(tmp + 2*m, m, 6*i*m/r, p + pos2 + i*m);
    }
    fftdif(p, m, rr);
    fftdif(p + pos1, m, rr);
    fftdif(p + pos2, m, rr);
  }

  void fftdit(T *p, ull m, ull r) {
    if (r == 1) return;
    ull rr = r/3;
    ull pos1 = m*rr, pos2 = 2*m*rr;
    fftdit(p, m, rr);
    fftdit(p + pos1, m, rr);
    fftdit(p + pos2, m, rr);
    for (ull i = 0; i < rr; ++i) {
      twiddle(p + pos1 + i*m, m, 3*m - 3*i*m/r, tmp + m);
      twiddle(p + pos2 + i*m, m, 3*m - 6*i*m/r, tmp + 2*m);
      for(ull j = 0; j < m; ++j) {
        tmp[j] = p[i*m + j];
        p[i*m + j] = tmp[j] + tmp[m + j] + tmp[2*m + j];
        p[i*m + pos1 + j] = tmp[j] + OMEGA2*tmp[m + j] + OMEGA*tmp[2*m + j];
        p[i*m + pos2 + j] = tmp[j] + OMEGA*tmp[m + j] + OMEGA2*tmp[2*m + j];
      }
    }
  }

  void mul(T *p, T *q, ull n, T *to) {
    if (n <= 27) {
      for (ull i = 0; i < n; ++i) {
        to[i]=0;
      }
      for (ull i = 0; i < n; ++i) {
        for (ull j = 0; j < n - i; ++j) {
          to[i + j] += p[i]*q[j];
        }
        for (ull j = n - i; j < n; ++j) {
          to[i + j - n] += p[i]*q[j]*OMEGA;
        }
      }
      return;
    }

    ull m = 1;
    while (m*m < n) {
      m *= 3;
    }
    ull r = n/m;

    T inv = 1;
    for (ull i = 1; i < r; i *= 3) {
      inv *= INV3;
    }

    for (ull i = 0; i < r; ++i) {
      twiddle(p + m*i, m, m/r*i, to + m*i);
      twiddle(q + m*i, m, m/r*i, to + n + m*i);
    }

    fftdif(to, m, r);
    fftdif(to + n, m, r);
    for (ull i = 0; i < r; ++i) {
      mul(to + m*i, to + n + m*i, m, to +2*n + m*i);
    }
    fftdit(to + 2*n, m, r);
    for (ull i = 0; i < n; ++i) {
      to[2*n + i] *= inv;
    }

    for (ull i = 0; i < r; ++i) {
      twiddle(to + 2*n + m*i, m, 3*m - m/r*i, to + n + m*i);
    }

    for (ull i = 0; i < r; ++i) {
      for (ull j = 0; j < m; ++j) {
        p[m*i + j] = p[m*i + j].conj();
        q[m*i + j] = q[m*i + j].conj();
      }
      twiddle(p + m*i, m, 2*m/r*i, to + m*i);
      twiddle(q + m*i, m, 2*m/r*i, p + m*i);
    }

    fftdif(to, m, r);
    fftdif(p, m, r);
    for (ull i = 0; i < r; ++i) {
      mul(to + m*i, p + m*i, m, to + 2*n + m*i);
    }
    fftdit(to + 2*n, m, r);
    for (ull i = 0; i < n; ++i) {
      to[2*n + i] *= inv;
    }

    for (ull i = 0; i < r; ++i) {
      twiddle(to + 2*n + m*i, m, 3*m - 2*m/r*i, q + m*i);
    }

    for (ull i = 0; i < n; ++i) {
      to[i] = 0;
    }
    for (ull i = 0; i < r; ++i) {
      for (ull j = 0; j < m; ++j) {
        to[i*m + j] += (1 - OMEGA)*to[n + i*m + j] + (1 - OMEGA2)*q[i*m + j].conj();
        if (i*m + m + j < n) {
          to[i*m + m + j] += (OMEGA2 - OMEGA)*(to[n + i*m + j] - q[i*m + j].conj());
        } else {
          to[i*m + m + j - n] += (1 - OMEGA2)*(to[n + i*m + j] - q[i*m + j].conj());
        }
      }
    }
    for (ull i = 0; i < n; ++i) {
      to[i] *= INV3;
    }
  }

  void multiply_cyclic_raw(ull *p, ull *q, ull n,
                                       ull *target) {
    ull m = 1;
    while (m*m <= n) {
      m *= 3;
    }
    m /= 3;
    ull r = n/m;

    T inv = 1;
    for (ull i = 1; i < r; i *= 3) {
      inv *= INV3;
    }

    T *buf = new T[3*n + 6*m];
    T *pp = buf;
    T *qq = buf + n;
    T *to = buf + 2*n;
    tmp = buf + 3*n + 3*m;

    for (ull i = 0; i < n; ++i) {
      pp[i] = p[i];
      qq[i] = q[i];
    }

    fftdif(pp, m, r);
    fftdif(qq, m, r);
    for (ull i = 0; i < r; ++i) {
      mul(pp + i*m, qq + i*m, m, to + i*m);
    }
    fftdit(to, m, r);
    for (ull i = 0; i<n; ++i) {
      pp[i] = to[i]*inv;
    }
    
    for (ull i = 0; i < n; ++i) to[i] = 0;
    for (ull i = 0; i < r; ++i) {
      for (ull j = 0; j < m; ++j) {
        to[i*m + j] += (1 - OMEGA)*pp[i*m + j] + (1 - OMEGA2)*pp[i*m + j].conj();
        if (i*m + m + j < n) {
          to[i*m + m + j] += (OMEGA2 - OMEGA)*(pp[i*m + j] - pp[i*m + j].conj());
        } else {
          to[i*m + m + j - n] += (OMEGA2 - OMEGA) * (pp[i*m + j] - pp[i*m + j].conj());
        }
      }
    }
    for (ull i = 0; i < n; ++i) {
      target[i] = (to[i]*INV3).a;
    }

    delete[] buf;
  }
};

V<ull> multiply(V<ull> a,V<ull> b){
	Conv64 c;
	return c.multiply(a,b);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/FFT64.cpp"
/*
  mod 2^64 FFT
  https://github.com/quasisphere/conv64/blob/master/conv64.cpp
  https://codeforces.com/blog/entry/45298
  完全にブラックボックス ↑に解説がある
  OpenCup で N = 200000 で 500 ms 未満
  筆算方針でfft * 5でやればいいからいらない気もするけど
*/


using ull = unsigned long long;
struct T {
  ull a, b;

  T() : a(0), b(0) { }
  T(ull x) : a(x), b(0) { }
  T(ull a, ull b) : a(a), b(b) { }

  T conj() {
    return T{a - b, -b};
  }

  T operator-() {
    return T{-a, -b};
  }
};

const T OMEGA = {0, 1};
const T OMEGA2 = {-1ull, -1ull};
const T INV3 = {12297829382473034411ull, 0};

T operator+(const T &u, const T &v) {
  return {u.a + v.a, u.b + v.b};
}

T operator-(const T &u, const T &v) {
  return {u.a - v.a, u.b - v.b};
}

T operator*(const T &u, const T &v) {
  return {u.a*v.a - u.b*v.b, u.b*v.a + u.a*v.b - u.b*v.b};
}

void operator+=(T &u, const T &v) {
  u.a += v.a;
  u.b += v.b;
}

void operator-=(T &u, const T &v) {
  u.a -= v.a;
  u.b -= v.b;
}

void operator*=(T &u, const T &v) {
  ull tmp=u.a;
  u.a=u.a*v.a - u.b*v.b;
  u.b=u.b*v.a + tmp*v.b - u.b*v.b;
}

class Conv64 {
  public:

  vector<ull> multiply(const vector<ull> &p,
                           const vector<ull> &q) {
    vector<ull> pp(p.size()), qq(q.size());
    for (ull i = 0; i < p.size(); ++i) {
      pp[i] = p[i];
    }
    for (ull i = 0; i < q.size(); ++i) {
      qq[i] = q[i];
    }
    ull s = 1;
    while (s < p.size() + q.size() - 1) {
      s *= 3;
    }
    pp.resize(s);
    qq.resize(s);
    vector<ull> res(s);
    multiply_cyclic_raw(pp.data(), qq.data(), pp.size(), (ull*)res.data());
    res.resize(p.size() + q.size() - 1);
    return res;
  }

  private:

  T *tmp;

  void twiddle(T *p, ull m, ull t, T *to) {
    if (t == 0 || t == 3*m) {
      for (ull j = 0; j < m; ++j) {
        to[j] = p[j];
      }
      return;
    }
    ull tt;
    T mult = 1;
    if (t < m) {
      tt = t;
    } else if (t < 2*m) {
      tt = t - m;
      mult = OMEGA;
    } else {
      tt = t - 2*m;
      mult = OMEGA2;
    }
    for (ull j=0;j<tt;j++) {
      to[j] = p[m - tt + j]*OMEGA*mult;
    }
    for (ull j=tt;j<m;j++) {
      to[j] = p[j-tt]*mult;
    }
  }

  void fftdif(T *p, ull m, ull r) {
    if (r == 1) return;
    ull rr = r/3;
    ull pos1 = m*rr, pos2 = 2*m*rr;
    for (ull i = 0; i < rr; ++i) {
      for (ull j = 0; j < m; ++j) {
        tmp[j] = p[i*m + j] + p[pos1 + i*m + j] + p[pos2 + i*m + j];
        tmp[m + j] = p[i*m + j] + OMEGA*p[pos1 + i*m + j] + OMEGA2*p[pos2 + i*m + j];
        tmp[2*m + j] = p[i*m + j] + OMEGA2*p[pos1 + i*m + j] + OMEGA*p[pos2 + i*m + j];
        p[i*m + j] = tmp[j];
      }
      twiddle(tmp + m, m, 3*i*m/r, p + pos1 + i*m);
      twiddle(tmp + 2*m, m, 6*i*m/r, p + pos2 + i*m);
    }
    fftdif(p, m, rr);
    fftdif(p + pos1, m, rr);
    fftdif(p + pos2, m, rr);
  }

  void fftdit(T *p, ull m, ull r) {
    if (r == 1) return;
    ull rr = r/3;
    ull pos1 = m*rr, pos2 = 2*m*rr;
    fftdit(p, m, rr);
    fftdit(p + pos1, m, rr);
    fftdit(p + pos2, m, rr);
    for (ull i = 0; i < rr; ++i) {
      twiddle(p + pos1 + i*m, m, 3*m - 3*i*m/r, tmp + m);
      twiddle(p + pos2 + i*m, m, 3*m - 6*i*m/r, tmp + 2*m);
      for(ull j = 0; j < m; ++j) {
        tmp[j] = p[i*m + j];
        p[i*m + j] = tmp[j] + tmp[m + j] + tmp[2*m + j];
        p[i*m + pos1 + j] = tmp[j] + OMEGA2*tmp[m + j] + OMEGA*tmp[2*m + j];
        p[i*m + pos2 + j] = tmp[j] + OMEGA*tmp[m + j] + OMEGA2*tmp[2*m + j];
      }
    }
  }

  void mul(T *p, T *q, ull n, T *to) {
    if (n <= 27) {
      for (ull i = 0; i < n; ++i) {
        to[i]=0;
      }
      for (ull i = 0; i < n; ++i) {
        for (ull j = 0; j < n - i; ++j) {
          to[i + j] += p[i]*q[j];
        }
        for (ull j = n - i; j < n; ++j) {
          to[i + j - n] += p[i]*q[j]*OMEGA;
        }
      }
      return;
    }

    ull m = 1;
    while (m*m < n) {
      m *= 3;
    }
    ull r = n/m;

    T inv = 1;
    for (ull i = 1; i < r; i *= 3) {
      inv *= INV3;
    }

    for (ull i = 0; i < r; ++i) {
      twiddle(p + m*i, m, m/r*i, to + m*i);
      twiddle(q + m*i, m, m/r*i, to + n + m*i);
    }

    fftdif(to, m, r);
    fftdif(to + n, m, r);
    for (ull i = 0; i < r; ++i) {
      mul(to + m*i, to + n + m*i, m, to +2*n + m*i);
    }
    fftdit(to + 2*n, m, r);
    for (ull i = 0; i < n; ++i) {
      to[2*n + i] *= inv;
    }

    for (ull i = 0; i < r; ++i) {
      twiddle(to + 2*n + m*i, m, 3*m - m/r*i, to + n + m*i);
    }

    for (ull i = 0; i < r; ++i) {
      for (ull j = 0; j < m; ++j) {
        p[m*i + j] = p[m*i + j].conj();
        q[m*i + j] = q[m*i + j].conj();
      }
      twiddle(p + m*i, m, 2*m/r*i, to + m*i);
      twiddle(q + m*i, m, 2*m/r*i, p + m*i);
    }

    fftdif(to, m, r);
    fftdif(p, m, r);
    for (ull i = 0; i < r; ++i) {
      mul(to + m*i, p + m*i, m, to + 2*n + m*i);
    }
    fftdit(to + 2*n, m, r);
    for (ull i = 0; i < n; ++i) {
      to[2*n + i] *= inv;
    }

    for (ull i = 0; i < r; ++i) {
      twiddle(to + 2*n + m*i, m, 3*m - 2*m/r*i, q + m*i);
    }

    for (ull i = 0; i < n; ++i) {
      to[i] = 0;
    }
    for (ull i = 0; i < r; ++i) {
      for (ull j = 0; j < m; ++j) {
        to[i*m + j] += (1 - OMEGA)*to[n + i*m + j] + (1 - OMEGA2)*q[i*m + j].conj();
        if (i*m + m + j < n) {
          to[i*m + m + j] += (OMEGA2 - OMEGA)*(to[n + i*m + j] - q[i*m + j].conj());
        } else {
          to[i*m + m + j - n] += (1 - OMEGA2)*(to[n + i*m + j] - q[i*m + j].conj());
        }
      }
    }
    for (ull i = 0; i < n; ++i) {
      to[i] *= INV3;
    }
  }

  void multiply_cyclic_raw(ull *p, ull *q, ull n,
                                       ull *target) {
    ull m = 1;
    while (m*m <= n) {
      m *= 3;
    }
    m /= 3;
    ull r = n/m;

    T inv = 1;
    for (ull i = 1; i < r; i *= 3) {
      inv *= INV3;
    }

    T *buf = new T[3*n + 6*m];
    T *pp = buf;
    T *qq = buf + n;
    T *to = buf + 2*n;
    tmp = buf + 3*n + 3*m;

    for (ull i = 0; i < n; ++i) {
      pp[i] = p[i];
      qq[i] = q[i];
    }

    fftdif(pp, m, r);
    fftdif(qq, m, r);
    for (ull i = 0; i < r; ++i) {
      mul(pp + i*m, qq + i*m, m, to + i*m);
    }
    fftdit(to, m, r);
    for (ull i = 0; i<n; ++i) {
      pp[i] = to[i]*inv;
    }
    
    for (ull i = 0; i < n; ++i) to[i] = 0;
    for (ull i = 0; i < r; ++i) {
      for (ull j = 0; j < m; ++j) {
        to[i*m + j] += (1 - OMEGA)*pp[i*m + j] + (1 - OMEGA2)*pp[i*m + j].conj();
        if (i*m + m + j < n) {
          to[i*m + m + j] += (OMEGA2 - OMEGA)*(pp[i*m + j] - pp[i*m + j].conj());
        } else {
          to[i*m + m + j - n] += (OMEGA2 - OMEGA) * (pp[i*m + j] - pp[i*m + j].conj());
        }
      }
    }
    for (ull i = 0; i < n; ++i) {
      target[i] = (to[i]*INV3).a;
    }

    delete[] buf;
  }
};

V<ull> multiply(V<ull> a,V<ull> b){
	Conv64 c;
	return c.multiply(a,b);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

