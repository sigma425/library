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
  bundledCode: "#line 1 \"misc/BigInt.cpp\"\n/*\n\tsunset's BigInt\n*/\n\n// base\
    \ and base_digits must be consistent\nconst int base = 1000000000;\nconst int\
    \ base_digits = 9;\n\nstruct Int {\n\tvector<int> z;\n\tint sign;\n\n\tInt() :\
    \ sign(1) {}\n\n\tInt(long long v) {\n\t\t*this = v;\n\t}\n\n\tInt(const string\
    \ &s) {\n\t\tread(s);\n\t}\n\n\tvoid operator=(const Int &v) {\n\t\tsign = v.sign;\n\
    \t\tz = v.z;\n\t}\n\n\tvoid operator=(long long v) {\n\t\tsign = 1;\n\t\tif (v\
    \ < 0) {\n\t\t\tsign = -1, v = -v;\n\t\t}\n\t\tz.clear();\n\t\tfor (; v > 0; v\
    \ = v / base) {\n\t\t\tz.push_back(v % base);\n\t\t}\n\t}\n\n\tInt operator+(const\
    \ Int &v) const {\n\t\tif (sign == v.sign) {\n\t\t\tInt res = v;\n\t\t\tfor (int\
    \ i = 0, carry = 0; i < (int) max(z.size(), v.z.size()) || carry; ++i) {\n\t\t\
    \t\tif (i == (int) res.z.size()) {\n\t\t\t\t\tres.z.push_back(0);\n\t\t\t\t}\n\
    \t\t\t\tres.z[i] += carry + (i < (int) z.size() ? z[i] : 0);\n\t\t\t\tcarry =\
    \ res.z[i] >= base;\n\t\t\t\tif (carry) {\n\t\t\t\t\tres.z[i] -= base;\n\t\t\t\
    \t}\n\t\t\t}\n\t\t\treturn res;\n\t\t} else {\n\t\t\treturn *this - (-v);\n\t\t\
    }\n\t}\n\n\tInt operator-(const Int &v) const {\n\t\tif (sign == v.sign) {\n\t\
    \t\tif (abs() >= v.abs()) {\n\t\t\t\tInt res = *this;\n\t\t\t\tfor (int i = 0,\
    \ carry = 0; i < (int) v.z.size() || carry; ++i) {\n\t\t\t\t\tres.z[i] -= carry\
    \ + (i < (int) v.z.size() ? v.z[i] : 0);\n\t\t\t\t\tcarry = res.z[i] < 0;\n\t\t\
    \t\t\tif (carry) {\n\t\t\t\t\t\tres.z[i] += base;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\
    \t\tres.trim();\n\t\t\t\treturn res;\n\t\t\t} else {\n\t\t\t\treturn -(v - *this);\n\
    \t\t\t}\n\t\t} else {\n\t\t\treturn *this + (-v);\n\t\t}\n\t}\n\n\tvoid operator*=(int\
    \ v) {\n\t\tif (v < 0) {\n\t\t\tsign = -sign, v = -v;\n\t\t}\n\t\tfor (int i =\
    \ 0, carry = 0; i < (int) z.size() || carry; ++i) {\n\t\t\tif (i == (int) z.size())\
    \ {\n\t\t\t\tz.push_back(0);\n\t\t\t}\n\t\t\tlong long cur = (long long) z[i]\
    \ * v + carry;\n\t\t\tcarry = cur / base;\n\t\t\tz[i] = cur % base;\n\t\t\t//\
    \ asm(\"divl %%ecx\" : \"=a\"(carry), \"=d\"(a[i]) : \"A\"(cur), \"c\"(base));\n\
    \t\t}\n\t\ttrim();\n\t}\n\n\tInt operator*(int v) const {\n\t\tInt res = *this;\n\
    \t\tres *= v;\n\t\treturn res;\n\t}\n\n\tfriend pair<Int, Int> divmod(const Int\
    \ &a1, const Int &b1) {\n\t\tint norm = base / (b1.z.back() + 1);\n\t\tInt a =\
    \ a1.abs() * norm;\n\t\tInt b = b1.abs() * norm;\n\t\tInt q, r;\n\t\tq.z.resize(a.z.size());\n\
    \t\tfor (int i = a.z.size() - 1; i >= 0; i--) {\n\t\t\tr *= base;\n\t\t\tr +=\
    \ a.z[i];\n\t\t\tint s1 = b.z.size() < r.z.size() ? r.z[b.z.size()] : 0;\n\t\t\
    \tint s2 = b.z.size() - 1 < r.z.size() ? r.z[b.z.size() - 1] : 0;\n\t\t\tint d\
    \ = ((long long) s1 * base + s2) / b.z.back();\n\t\t\tr -= b * d;\n\t\t\twhile\
    \ (r < 0) {\n\t\t\t\tr += b, --d;\n\t\t\t}\n\t\t\tq.z[i] = d;\n\t\t}\n\t\tq.sign\
    \ = a1.sign * b1.sign;\n\t\tr.sign = a1.sign;\n\t\tq.trim();\n\t\tr.trim();\n\t\
    \treturn make_pair(q, r / norm);\n\t}\n\n\tfriend Int sqrt(const Int &a1) {\n\t\
    \tInt a = a1;\n\t\twhile (a.z.empty() || (int) a.z.size() % 2 == 1) {\n\t\t\t\
    a.z.push_back(0);\n\t\t}\n\t\tint n = a.z.size();\n\t\tint firstDigit = sqrt((long\
    \ long) a.z[n - 1] * base + a.z[n - 2]);\n\t\tint norm = base / (firstDigit +\
    \ 1);\n\t\ta *= norm;\n\t\ta *= norm;\n\t\twhile (a.z.empty() || (int) a.z.size()\
    \ % 2 == 1) {\n\t\t\ta.z.push_back(0);\n\t\t}\n\t\tInt r = (long long) a.z[n -\
    \ 1] * base + a.z[n - 2];\n\t\tfirstDigit = sqrt((long long) a.z[n - 1] * base\
    \ + a.z[n - 2]);\n\t\tint q = firstDigit;\n\t\tInt res;\n\t\tfor (int j = n /\
    \ 2 - 1; j >= 0; j--) {\n\t\t\tfor (;; --q) {\n\t\t\t\tInt r1 =\n\t\t\t\t\t(r\
    \ - (res * 2 * base + q) * q) * base * base +\n\t\t\t\t\t(j > 0 ? (long long)\
    \ a.z[2 * j - 1] * base + a.z[2 * j - 2] : 0);\n\t\t\t\tif (r1 >= 0) {\n\t\t\t\
    \t\tr = r1;\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\tres *= base;\n\t\t\t\
    res += q;\n\t\t\tif (j > 0) {\n\t\t\t\tint d1 = res.z.size() + 2 < r.z.size()\
    \ ? r.z[res.z.size() + 2] : 0;\n\t\t\t\tint d2 = res.z.size() + 1 < r.z.size()\
    \ ? r.z[res.z.size() + 1] : 0;\n\t\t\t\tint d3 = res.z.size() < r.z.size() ? r.z[res.z.size()]\
    \ : 0;\n\t\t\t\tq = ((long long) d1 * base * base + (long long) d2 * base + d3)\
    \ /\n\t\t\t\t\t\t(firstDigit * 2);\n\t\t\t}\n\t\t}\n\t\tres.trim();\n\t\treturn\
    \ res / norm;\n\t}\n\n\tInt operator/(const Int &v) const {\n\t\treturn divmod(*this,\
    \ v).first;\n\t}\n\n\tInt operator%(const Int &v) const {\n\t\treturn divmod(*this,\
    \ v).second;\n\t}\n\n\tvoid operator/=(int v) {\n\t\tif (v < 0) {\n\t\t\tsign\
    \ = -sign, v = -v;\n\t\t}\n\t\tfor (int i = z.size() - 1, rem = 0; i >= 0; --i)\
    \ {\n\t\t\tlong long cur = z[i] + (long long) rem * base;\n\t\t\tz[i] = cur /\
    \ v;\n\t\t\trem = cur % v;\n\t\t}\n\t\ttrim();\n\t}\n\n\tInt operator/(int v)\
    \ const {\n\t\tInt res = *this;\n\t\tres /= v;\n\t\treturn res;\n\t}\n\n\tint\
    \ operator%(int v) const {\n\t\tif (v < 0) {\n\t\t\tv = -v;\n\t\t}\n\t\tint m\
    \ = 0;\n\t\tfor (int i = z.size() - 1; i >= 0; --i) {\n\t\t\tm = ((long long)\
    \ m * base + z[i]) % v;\n\t\t}\n\t\treturn m * sign;\n\t}\n\n\tvoid operator+=(const\
    \ Int &v) {\n\t\t*this = *this + v;\n\t}\n\tvoid operator-=(const Int &v) {\n\t\
    \t*this = *this - v;\n\t}\n\tvoid operator*=(const Int &v) {\n\t\t*this = *this\
    \ * v;\n\t}\n\tvoid operator/=(const Int &v) {\n\t\t*this = *this / v;\n\t}\n\n\
    \tbool operator<(const Int &v) const {\n\t\tif (sign != v.sign) {\n\t\t\treturn\
    \ sign < v.sign;\n\t\t}\n\t\tif (z.size() != v.z.size()) {\n\t\t\treturn z.size()\
    \ * sign < v.z.size() * v.sign;\n\t\t}\n\t\tfor (int i = z.size() - 1; i >= 0;\
    \ i--) {\n\t\t\tif (z[i] != v.z[i]) {\n\t\t\t\treturn z[i] * sign < v.z[i] * sign;\n\
    \t\t\t}\n\t\t}\n\t\treturn false;\n\t}\n\n\tbool operator>(const Int &v) const\
    \ {\n\t\treturn v < *this;\n\t}\n\tbool operator<=(const Int &v) const {\n\t\t\
    return !(v < *this);\n\t}\n\tbool operator>=(const Int &v) const {\n\t\treturn\
    \ !(*this < v);\n\t}\n\tbool operator==(const Int &v) const {\n\t\treturn !(*this\
    \ < v) && !(v < *this);\n\t}\n\tbool operator!=(const Int &v) const {\n\t\treturn\
    \ *this < v || v < *this;\n\t}\n\n\tvoid trim() {\n\t\twhile (!z.empty() && z.back()\
    \ == 0) {\n\t\t\tz.pop_back();\n\t\t}\n\t\tif (z.empty()) {\n\t\t\tsign = 1;\n\
    \t\t}\n\t}\n\n\tbool isZero() const {\n\t\treturn z.empty() || ((int) z.size()\
    \ == 1 && !z[0]);\n\t}\n\n\tInt operator-() const {\n\t\tInt res = *this;\n\t\t\
    res.sign = -sign;\n\t\treturn res;\n\t}\n\n\tInt abs() const {\n\t\tInt res =\
    \ *this;\n\t\tres.sign *= res.sign;\n\t\treturn res;\n\t}\n\n\tlong long longValue()\
    \ const {\n\t\tlong long res = 0;\n\t\tfor (int i = z.size() - 1; i >= 0; i--)\
    \ {\n\t\t\tres = res * base + z[i];\n\t\t}\n\t\treturn res * sign;\n\t}\n\n\t\
    friend Int gcd(const Int &a, const Int &b) {\n\t\treturn b.isZero() ? a : gcd(b,\
    \ a % b);\n\t}\n\tfriend Int lcm(const Int &a, const Int &b) {\n\t\treturn a /\
    \ gcd(a, b) * b;\n\t}\n\n\tvoid read(const string &s) {\n\t\tsign = 1;\n\t\tz.clear();\n\
    \t\tint pos = 0;\n\t\twhile (pos < (int) s.size() && (s[pos] == '-' || s[pos]\
    \ == '+')) {\n\t\t\tif (s[pos] == '-') {\n\t\t\t\tsign = -sign;\n\t\t\t}\n\t\t\
    \t++pos;\n\t\t}\n\t\tfor (int i = s.size() - 1; i >= pos; i -= base_digits) {\n\
    \t\t\tint x = 0;\n\t\t\tfor (int j = max(pos, i - base_digits + 1); j <= i; j++)\
    \ {\n\t\t\t\tx = x * 10 + s[j] - '0';\n\t\t\t}\n\t\t\tz.push_back(x);\n\t\t}\n\
    \t\ttrim();\n\t}\n\n\tfriend istream &operator>>(istream &stream, Int &v) {\n\t\
    \tstring s;\n\t\tstream >> s;\n\t\tv.read(s);\n\t\treturn stream;\n\t}\n\n\tfriend\
    \ ostream &operator<<(ostream &stream, const Int &v) {\n\t\tif (v.sign == -1)\
    \ {\n\t\t\tstream << '-';\n\t\t}\n\t\tstream << (v.z.empty() ? 0 : v.z.back());\n\
    \t\tfor (int i = v.z.size() - 2; i >= 0; --i) {\n\t\t\tstream << setw(base_digits)\
    \ << setfill('0') << v.z[i];\n\t\t}\n\t\treturn stream;\n\t}\n\n\tstatic vector<int>\
    \ convert_base(const vector<int> &a, int old_digits, int new_digits) {\n\t\tvector<long\
    \ long> p(max(old_digits, new_digits) + 1);\n\t\tp[0] = 1;\n\t\tfor (int i = 1;\
    \ i < (int) p.size(); i++) {\n\t\t\tp[i] = p[i - 1] * 10;\n\t\t}\n\t\tvector<int>\
    \ res;\n\t\tlong long cur = 0;\n\t\tint cur_digits = 0;\n\t\tfor (int i = 0; i\
    \ < (int) a.size(); i++) {\n\t\t\tcur += a[i] * p[cur_digits];\n\t\t\tcur_digits\
    \ += old_digits;\n\t\t\twhile (cur_digits >= new_digits) {\n\t\t\t\tres.push_back(cur\
    \ % p[new_digits]);\n\t\t\t\tcur /= p[new_digits];\n\t\t\t\tcur_digits -= new_digits;\n\
    \t\t\t}\n\t\t}\n\t\tres.push_back(cur);\n\t\twhile (!res.empty() && res.back()\
    \ == 0) {\n\t\t\tres.pop_back();\n\t\t}\n\t\treturn res;\n\t}\n\n\ttypedef vector<long\
    \ long> vll;\n\n\tstatic vll karatsubaMultiply(const vll &a, const vll &b) {\n\
    \t\tint n = a.size();\n\t\tvll res(n + n);\n\t\tif (n <= 32) {\n\t\t\tfor (int\
    \ i = 0; i < n; i++) {\n\t\t\t\tfor (int j = 0; j < n; j++) {\n\t\t\t\t\tres[i\
    \ + j] += a[i] * b[j];\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n\t\tint\
    \ k = n >> 1;\n\t\tvll a1(a.begin(), a.begin() + k);\n\t\tvll a2(a.begin() + k,\
    \ a.end());\n\t\tvll b1(b.begin(), b.begin() + k);\n\t\tvll b2(b.begin() + k,\
    \ b.end());\n\t\tvll a1b1 = karatsubaMultiply(a1, b1);\n\t\tvll a2b2 = karatsubaMultiply(a2,\
    \ b2);\n\t\tfor (int i = 0; i < k; i++) {\n\t\t\ta2[i] += a1[i];\n\t\t}\n\t\t\
    for (int i = 0; i < k; i++) {\n\t\t\tb2[i] += b1[i];\n\t\t}\n\t\tvll r = karatsubaMultiply(a2,\
    \ b2);\n\t\tfor (int i = 0; i < (int) a1b1.size(); i++) {\n\t\t\tr[i] -= a1b1[i];\n\
    \t\t}\n\t\tfor (int i = 0; i < (int) a2b2.size(); i++) {\n\t\t\tr[i] -= a2b2[i];\n\
    \t\t}\n\t\tfor (int i = 0; i < (int) r.size(); i++) {\n\t\t\tres[i + k] += r[i];\n\
    \t\t}\n\t\tfor (int i = 0; i < (int) a1b1.size(); i++) {\n\t\t\tres[i] += a1b1[i];\n\
    \t\t}\n\t\tfor (int i = 0; i < (int) a2b2.size(); i++) {\n\t\t\tres[i + n] +=\
    \ a2b2[i];\n\t\t}\n\t\treturn res;\n\t}\n\n\tInt operator*(const Int &v) const\
    \ {\n\t\tvector<int> a6 = convert_base(this->z, base_digits, 6);\n\t\tvector<int>\
    \ b6 = convert_base(v.z, base_digits, 6);\n\t\tvll a(a6.begin(), a6.end());\n\t\
    \tvll b(b6.begin(), b6.end());\n\t\twhile (a.size() < b.size()) {\n\t\t\ta.push_back(0);\n\
    \t\t}\n\t\twhile (b.size() < a.size()) {\n\t\t\tb.push_back(0);\n\t\t}\n\t\twhile\
    \ (a.size() & (a.size() - 1)) {\n\t\t\ta.push_back(0);\n\t\t\tb.push_back(0);\n\
    \t\t}\n\t\tvll c = karatsubaMultiply(a, b);\n\t\tInt res;\n\t\tres.sign = sign\
    \ * v.sign;\n\t\tfor (int i = 0, carry = 0; i < (int) c.size(); i++) {\n\t\t\t\
    long long cur = c[i] + carry;\n\t\t\tres.z.push_back(cur % 1000000);\n\t\t\tcarry\
    \ = cur / 1000000;\n\t\t}\n\t\tres.z = convert_base(res.z, 6, base_digits);\n\t\
    \tres.trim();\n\t\treturn res;\n\t}\n};\n"
  code: "/*\n\tsunset's BigInt\n*/\n\n// base and base_digits must be consistent\n\
    const int base = 1000000000;\nconst int base_digits = 9;\n\nstruct Int {\n\tvector<int>\
    \ z;\n\tint sign;\n\n\tInt() : sign(1) {}\n\n\tInt(long long v) {\n\t\t*this =\
    \ v;\n\t}\n\n\tInt(const string &s) {\n\t\tread(s);\n\t}\n\n\tvoid operator=(const\
    \ Int &v) {\n\t\tsign = v.sign;\n\t\tz = v.z;\n\t}\n\n\tvoid operator=(long long\
    \ v) {\n\t\tsign = 1;\n\t\tif (v < 0) {\n\t\t\tsign = -1, v = -v;\n\t\t}\n\t\t\
    z.clear();\n\t\tfor (; v > 0; v = v / base) {\n\t\t\tz.push_back(v % base);\n\t\
    \t}\n\t}\n\n\tInt operator+(const Int &v) const {\n\t\tif (sign == v.sign) {\n\
    \t\t\tInt res = v;\n\t\t\tfor (int i = 0, carry = 0; i < (int) max(z.size(), v.z.size())\
    \ || carry; ++i) {\n\t\t\t\tif (i == (int) res.z.size()) {\n\t\t\t\t\tres.z.push_back(0);\n\
    \t\t\t\t}\n\t\t\t\tres.z[i] += carry + (i < (int) z.size() ? z[i] : 0);\n\t\t\t\
    \tcarry = res.z[i] >= base;\n\t\t\t\tif (carry) {\n\t\t\t\t\tres.z[i] -= base;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\treturn res;\n\t\t} else {\n\t\t\treturn *this - (-v);\n\
    \t\t}\n\t}\n\n\tInt operator-(const Int &v) const {\n\t\tif (sign == v.sign) {\n\
    \t\t\tif (abs() >= v.abs()) {\n\t\t\t\tInt res = *this;\n\t\t\t\tfor (int i =\
    \ 0, carry = 0; i < (int) v.z.size() || carry; ++i) {\n\t\t\t\t\tres.z[i] -= carry\
    \ + (i < (int) v.z.size() ? v.z[i] : 0);\n\t\t\t\t\tcarry = res.z[i] < 0;\n\t\t\
    \t\t\tif (carry) {\n\t\t\t\t\t\tres.z[i] += base;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\
    \t\tres.trim();\n\t\t\t\treturn res;\n\t\t\t} else {\n\t\t\t\treturn -(v - *this);\n\
    \t\t\t}\n\t\t} else {\n\t\t\treturn *this + (-v);\n\t\t}\n\t}\n\n\tvoid operator*=(int\
    \ v) {\n\t\tif (v < 0) {\n\t\t\tsign = -sign, v = -v;\n\t\t}\n\t\tfor (int i =\
    \ 0, carry = 0; i < (int) z.size() || carry; ++i) {\n\t\t\tif (i == (int) z.size())\
    \ {\n\t\t\t\tz.push_back(0);\n\t\t\t}\n\t\t\tlong long cur = (long long) z[i]\
    \ * v + carry;\n\t\t\tcarry = cur / base;\n\t\t\tz[i] = cur % base;\n\t\t\t//\
    \ asm(\"divl %%ecx\" : \"=a\"(carry), \"=d\"(a[i]) : \"A\"(cur), \"c\"(base));\n\
    \t\t}\n\t\ttrim();\n\t}\n\n\tInt operator*(int v) const {\n\t\tInt res = *this;\n\
    \t\tres *= v;\n\t\treturn res;\n\t}\n\n\tfriend pair<Int, Int> divmod(const Int\
    \ &a1, const Int &b1) {\n\t\tint norm = base / (b1.z.back() + 1);\n\t\tInt a =\
    \ a1.abs() * norm;\n\t\tInt b = b1.abs() * norm;\n\t\tInt q, r;\n\t\tq.z.resize(a.z.size());\n\
    \t\tfor (int i = a.z.size() - 1; i >= 0; i--) {\n\t\t\tr *= base;\n\t\t\tr +=\
    \ a.z[i];\n\t\t\tint s1 = b.z.size() < r.z.size() ? r.z[b.z.size()] : 0;\n\t\t\
    \tint s2 = b.z.size() - 1 < r.z.size() ? r.z[b.z.size() - 1] : 0;\n\t\t\tint d\
    \ = ((long long) s1 * base + s2) / b.z.back();\n\t\t\tr -= b * d;\n\t\t\twhile\
    \ (r < 0) {\n\t\t\t\tr += b, --d;\n\t\t\t}\n\t\t\tq.z[i] = d;\n\t\t}\n\t\tq.sign\
    \ = a1.sign * b1.sign;\n\t\tr.sign = a1.sign;\n\t\tq.trim();\n\t\tr.trim();\n\t\
    \treturn make_pair(q, r / norm);\n\t}\n\n\tfriend Int sqrt(const Int &a1) {\n\t\
    \tInt a = a1;\n\t\twhile (a.z.empty() || (int) a.z.size() % 2 == 1) {\n\t\t\t\
    a.z.push_back(0);\n\t\t}\n\t\tint n = a.z.size();\n\t\tint firstDigit = sqrt((long\
    \ long) a.z[n - 1] * base + a.z[n - 2]);\n\t\tint norm = base / (firstDigit +\
    \ 1);\n\t\ta *= norm;\n\t\ta *= norm;\n\t\twhile (a.z.empty() || (int) a.z.size()\
    \ % 2 == 1) {\n\t\t\ta.z.push_back(0);\n\t\t}\n\t\tInt r = (long long) a.z[n -\
    \ 1] * base + a.z[n - 2];\n\t\tfirstDigit = sqrt((long long) a.z[n - 1] * base\
    \ + a.z[n - 2]);\n\t\tint q = firstDigit;\n\t\tInt res;\n\t\tfor (int j = n /\
    \ 2 - 1; j >= 0; j--) {\n\t\t\tfor (;; --q) {\n\t\t\t\tInt r1 =\n\t\t\t\t\t(r\
    \ - (res * 2 * base + q) * q) * base * base +\n\t\t\t\t\t(j > 0 ? (long long)\
    \ a.z[2 * j - 1] * base + a.z[2 * j - 2] : 0);\n\t\t\t\tif (r1 >= 0) {\n\t\t\t\
    \t\tr = r1;\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\tres *= base;\n\t\t\t\
    res += q;\n\t\t\tif (j > 0) {\n\t\t\t\tint d1 = res.z.size() + 2 < r.z.size()\
    \ ? r.z[res.z.size() + 2] : 0;\n\t\t\t\tint d2 = res.z.size() + 1 < r.z.size()\
    \ ? r.z[res.z.size() + 1] : 0;\n\t\t\t\tint d3 = res.z.size() < r.z.size() ? r.z[res.z.size()]\
    \ : 0;\n\t\t\t\tq = ((long long) d1 * base * base + (long long) d2 * base + d3)\
    \ /\n\t\t\t\t\t\t(firstDigit * 2);\n\t\t\t}\n\t\t}\n\t\tres.trim();\n\t\treturn\
    \ res / norm;\n\t}\n\n\tInt operator/(const Int &v) const {\n\t\treturn divmod(*this,\
    \ v).first;\n\t}\n\n\tInt operator%(const Int &v) const {\n\t\treturn divmod(*this,\
    \ v).second;\n\t}\n\n\tvoid operator/=(int v) {\n\t\tif (v < 0) {\n\t\t\tsign\
    \ = -sign, v = -v;\n\t\t}\n\t\tfor (int i = z.size() - 1, rem = 0; i >= 0; --i)\
    \ {\n\t\t\tlong long cur = z[i] + (long long) rem * base;\n\t\t\tz[i] = cur /\
    \ v;\n\t\t\trem = cur % v;\n\t\t}\n\t\ttrim();\n\t}\n\n\tInt operator/(int v)\
    \ const {\n\t\tInt res = *this;\n\t\tres /= v;\n\t\treturn res;\n\t}\n\n\tint\
    \ operator%(int v) const {\n\t\tif (v < 0) {\n\t\t\tv = -v;\n\t\t}\n\t\tint m\
    \ = 0;\n\t\tfor (int i = z.size() - 1; i >= 0; --i) {\n\t\t\tm = ((long long)\
    \ m * base + z[i]) % v;\n\t\t}\n\t\treturn m * sign;\n\t}\n\n\tvoid operator+=(const\
    \ Int &v) {\n\t\t*this = *this + v;\n\t}\n\tvoid operator-=(const Int &v) {\n\t\
    \t*this = *this - v;\n\t}\n\tvoid operator*=(const Int &v) {\n\t\t*this = *this\
    \ * v;\n\t}\n\tvoid operator/=(const Int &v) {\n\t\t*this = *this / v;\n\t}\n\n\
    \tbool operator<(const Int &v) const {\n\t\tif (sign != v.sign) {\n\t\t\treturn\
    \ sign < v.sign;\n\t\t}\n\t\tif (z.size() != v.z.size()) {\n\t\t\treturn z.size()\
    \ * sign < v.z.size() * v.sign;\n\t\t}\n\t\tfor (int i = z.size() - 1; i >= 0;\
    \ i--) {\n\t\t\tif (z[i] != v.z[i]) {\n\t\t\t\treturn z[i] * sign < v.z[i] * sign;\n\
    \t\t\t}\n\t\t}\n\t\treturn false;\n\t}\n\n\tbool operator>(const Int &v) const\
    \ {\n\t\treturn v < *this;\n\t}\n\tbool operator<=(const Int &v) const {\n\t\t\
    return !(v < *this);\n\t}\n\tbool operator>=(const Int &v) const {\n\t\treturn\
    \ !(*this < v);\n\t}\n\tbool operator==(const Int &v) const {\n\t\treturn !(*this\
    \ < v) && !(v < *this);\n\t}\n\tbool operator!=(const Int &v) const {\n\t\treturn\
    \ *this < v || v < *this;\n\t}\n\n\tvoid trim() {\n\t\twhile (!z.empty() && z.back()\
    \ == 0) {\n\t\t\tz.pop_back();\n\t\t}\n\t\tif (z.empty()) {\n\t\t\tsign = 1;\n\
    \t\t}\n\t}\n\n\tbool isZero() const {\n\t\treturn z.empty() || ((int) z.size()\
    \ == 1 && !z[0]);\n\t}\n\n\tInt operator-() const {\n\t\tInt res = *this;\n\t\t\
    res.sign = -sign;\n\t\treturn res;\n\t}\n\n\tInt abs() const {\n\t\tInt res =\
    \ *this;\n\t\tres.sign *= res.sign;\n\t\treturn res;\n\t}\n\n\tlong long longValue()\
    \ const {\n\t\tlong long res = 0;\n\t\tfor (int i = z.size() - 1; i >= 0; i--)\
    \ {\n\t\t\tres = res * base + z[i];\n\t\t}\n\t\treturn res * sign;\n\t}\n\n\t\
    friend Int gcd(const Int &a, const Int &b) {\n\t\treturn b.isZero() ? a : gcd(b,\
    \ a % b);\n\t}\n\tfriend Int lcm(const Int &a, const Int &b) {\n\t\treturn a /\
    \ gcd(a, b) * b;\n\t}\n\n\tvoid read(const string &s) {\n\t\tsign = 1;\n\t\tz.clear();\n\
    \t\tint pos = 0;\n\t\twhile (pos < (int) s.size() && (s[pos] == '-' || s[pos]\
    \ == '+')) {\n\t\t\tif (s[pos] == '-') {\n\t\t\t\tsign = -sign;\n\t\t\t}\n\t\t\
    \t++pos;\n\t\t}\n\t\tfor (int i = s.size() - 1; i >= pos; i -= base_digits) {\n\
    \t\t\tint x = 0;\n\t\t\tfor (int j = max(pos, i - base_digits + 1); j <= i; j++)\
    \ {\n\t\t\t\tx = x * 10 + s[j] - '0';\n\t\t\t}\n\t\t\tz.push_back(x);\n\t\t}\n\
    \t\ttrim();\n\t}\n\n\tfriend istream &operator>>(istream &stream, Int &v) {\n\t\
    \tstring s;\n\t\tstream >> s;\n\t\tv.read(s);\n\t\treturn stream;\n\t}\n\n\tfriend\
    \ ostream &operator<<(ostream &stream, const Int &v) {\n\t\tif (v.sign == -1)\
    \ {\n\t\t\tstream << '-';\n\t\t}\n\t\tstream << (v.z.empty() ? 0 : v.z.back());\n\
    \t\tfor (int i = v.z.size() - 2; i >= 0; --i) {\n\t\t\tstream << setw(base_digits)\
    \ << setfill('0') << v.z[i];\n\t\t}\n\t\treturn stream;\n\t}\n\n\tstatic vector<int>\
    \ convert_base(const vector<int> &a, int old_digits, int new_digits) {\n\t\tvector<long\
    \ long> p(max(old_digits, new_digits) + 1);\n\t\tp[0] = 1;\n\t\tfor (int i = 1;\
    \ i < (int) p.size(); i++) {\n\t\t\tp[i] = p[i - 1] * 10;\n\t\t}\n\t\tvector<int>\
    \ res;\n\t\tlong long cur = 0;\n\t\tint cur_digits = 0;\n\t\tfor (int i = 0; i\
    \ < (int) a.size(); i++) {\n\t\t\tcur += a[i] * p[cur_digits];\n\t\t\tcur_digits\
    \ += old_digits;\n\t\t\twhile (cur_digits >= new_digits) {\n\t\t\t\tres.push_back(cur\
    \ % p[new_digits]);\n\t\t\t\tcur /= p[new_digits];\n\t\t\t\tcur_digits -= new_digits;\n\
    \t\t\t}\n\t\t}\n\t\tres.push_back(cur);\n\t\twhile (!res.empty() && res.back()\
    \ == 0) {\n\t\t\tres.pop_back();\n\t\t}\n\t\treturn res;\n\t}\n\n\ttypedef vector<long\
    \ long> vll;\n\n\tstatic vll karatsubaMultiply(const vll &a, const vll &b) {\n\
    \t\tint n = a.size();\n\t\tvll res(n + n);\n\t\tif (n <= 32) {\n\t\t\tfor (int\
    \ i = 0; i < n; i++) {\n\t\t\t\tfor (int j = 0; j < n; j++) {\n\t\t\t\t\tres[i\
    \ + j] += a[i] * b[j];\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n\t\tint\
    \ k = n >> 1;\n\t\tvll a1(a.begin(), a.begin() + k);\n\t\tvll a2(a.begin() + k,\
    \ a.end());\n\t\tvll b1(b.begin(), b.begin() + k);\n\t\tvll b2(b.begin() + k,\
    \ b.end());\n\t\tvll a1b1 = karatsubaMultiply(a1, b1);\n\t\tvll a2b2 = karatsubaMultiply(a2,\
    \ b2);\n\t\tfor (int i = 0; i < k; i++) {\n\t\t\ta2[i] += a1[i];\n\t\t}\n\t\t\
    for (int i = 0; i < k; i++) {\n\t\t\tb2[i] += b1[i];\n\t\t}\n\t\tvll r = karatsubaMultiply(a2,\
    \ b2);\n\t\tfor (int i = 0; i < (int) a1b1.size(); i++) {\n\t\t\tr[i] -= a1b1[i];\n\
    \t\t}\n\t\tfor (int i = 0; i < (int) a2b2.size(); i++) {\n\t\t\tr[i] -= a2b2[i];\n\
    \t\t}\n\t\tfor (int i = 0; i < (int) r.size(); i++) {\n\t\t\tres[i + k] += r[i];\n\
    \t\t}\n\t\tfor (int i = 0; i < (int) a1b1.size(); i++) {\n\t\t\tres[i] += a1b1[i];\n\
    \t\t}\n\t\tfor (int i = 0; i < (int) a2b2.size(); i++) {\n\t\t\tres[i + n] +=\
    \ a2b2[i];\n\t\t}\n\t\treturn res;\n\t}\n\n\tInt operator*(const Int &v) const\
    \ {\n\t\tvector<int> a6 = convert_base(this->z, base_digits, 6);\n\t\tvector<int>\
    \ b6 = convert_base(v.z, base_digits, 6);\n\t\tvll a(a6.begin(), a6.end());\n\t\
    \tvll b(b6.begin(), b6.end());\n\t\twhile (a.size() < b.size()) {\n\t\t\ta.push_back(0);\n\
    \t\t}\n\t\twhile (b.size() < a.size()) {\n\t\t\tb.push_back(0);\n\t\t}\n\t\twhile\
    \ (a.size() & (a.size() - 1)) {\n\t\t\ta.push_back(0);\n\t\t\tb.push_back(0);\n\
    \t\t}\n\t\tvll c = karatsubaMultiply(a, b);\n\t\tInt res;\n\t\tres.sign = sign\
    \ * v.sign;\n\t\tfor (int i = 0, carry = 0; i < (int) c.size(); i++) {\n\t\t\t\
    long long cur = c[i] + carry;\n\t\t\tres.z.push_back(cur % 1000000);\n\t\t\tcarry\
    \ = cur / 1000000;\n\t\t}\n\t\tres.z = convert_base(res.z, 6, base_digits);\n\t\
    \tres.trim();\n\t\treturn res;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/BigInt.cpp
  requiredBy: []
  timestamp: '2024-01-04 00:07:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/BigInt.cpp
layout: document
redirect_from:
- /library/misc/BigInt.cpp
- /library/misc/BigInt.cpp.html
title: misc/BigInt.cpp
---
