---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/Precursive.cpp\"\n/*\r\n\tP-recursive (holonomic) sequence\
    \ \u306E\u6F38\u5316\u5F0F\u3092\u6C42\u3081\u308B\r\n\tn\u9805\u76EE\u3092\u6C42\
    \u3081\u308B\u306E\u306F\u611A\u76F4\u306B\u3084\u3063\u3066\u3044\u308B\u306E\
    \u3067\u3053\u308C\u306F\u8ABF\u3079\u308B\u5FC5\u8981\u3042\u308B\u304B\u3082\
    ? ( \u305F\u3060\u3001\u305D\u3053\u307E\u3067\u9045\u304F\u306F\u306A\u3044 O(N\
    \ * order * degree) )\r\n\r\n\tP-recursive:\r\n\t\tBerlekamp-Massey \u3068\u304B\
    \u3067\u6271\u3046\u6F38\u5316\u5F0F\u306F a_n = 3a_{n-1} - 10a_{n-2} \u3068\u304B\
    \u3060\u3063\u305F\u3051\u3069\u3001P-recursive \u3067\u306F\u3001\r\n\t\t(5n-3)a_n\
    \ = (3n+4)a_{n-1} + (n^5)a_{n-2} \u307F\u305F\u3044\u306A\u306E\u304C\u6271\u3048\
    \u308B\r\n\r\n\t\t\u3064\u307E\u308A\u4FC2\u6570\u306Bn\u306E\u591A\u9805\u5F0F\
    \u3092\u5165\u308C\u3089\u308C\u308B\r\n\r\n\t\t\u3053\u3053\u3067\u3001\r\n\t\
    \td := degree \u3068\u306F \u3053\u306E\u591A\u9805\u5F0F\u306E\u6B21\u6570\u306E\
    max\u306E\u3053\u3068\u3067\u3001 \r\n\t\tk := order  \u3068\u306F (\u4F55\u9805\
    \u9593\u6F38\u5316\u5F0F\u304B)-1 \u3092\u8868\u3059\r\n\r\n\t\tn\u3092\u56FA\u5B9A\
    \u3057\u305F\u4E00\u3064\u306E\u5F0F\u306B\u73FE\u308C\u308B\u5909\u6570\u306E\
    \u500B\u6570\u306F (d+1)(k+1) \u306A\u306E\u3067\u3001\u5F0F\u3092\u3053\u308C\
    \u3060\u3051\u7528\u610F\u3059\u308C\u3070\u4E00\u610F\u306B\u5B9A\u307E\u308B\
    \r\n\t\t\u305D\u306E\u305F\u3081\u306B\u306F \u306F\u3058\u3081\u306E (d+1)(k+1)\
    \ + k \u9805 \u304C\u5FC5\u8981 \u306A\u6C17\u304C\u3059\u308B\u3051\u3069\u5F0F\
    \u5168\u4F53\u306Bx\u500D\u307F\u305F\u3044\u306A\u306E\u306E\u81EA\u7531\u5EA6\
    \u304C\u3042\u308B\u304B\u3089\r\n\t\t\u7D50\u5C40 (d+1)(k+1) + k - 1 \u9805\u3042\
    \u308C\u3070\u5341\u5206\r\n\r\n\t\u4F7F\u3044\u65B9:\r\n\t\t- \u3068\u308A\u3042\
    \u3048\u305A\u6570\u5217\u306E deg \u3068 ord \u3092\u77E5\u308A\u305F\u3044\u5834\
    \u5408:\r\n\t\t\t\u3053\u306E\u5B9F\u88C5\u3060\u3068deg\u306F\u56FA\u5B9A\u306A\
    \u306E\u3067\u3001\r\n\t\t\tfind_recurrence_relation(vector<mint> terms, int deg)\
    \ \u3092 deg = 0~ \u8A66\u3057\u3066\u3044\u304F\r\n\t\t\t\u8A08\u7B97\u91CF O(n^2\
    \ * deg * ord)\r\n\t\t\t\u898B\u3064\u3051\u3089\u308C\u306A\u304B\u3063\u305F\
    \u3089assert(0),\r\n\t\t\t\u898B\u3064\u304B\u3063\u305F\u3089\u30B3\u30E1\u30F3\
    \u30C8\u4ED8\u304D\u3067\u3044\u308D\u3044\u308D\u6559\u3048\u3066\u304F\u308C\
    \u308B\r\n\r\n\t\t\t!! \u306A\u3093\u304Bdeg\u304C\u7121\u99C4\u306B\u3067\u304B\
    \u3044\u3068\u5909\u306A\u89E3\u3069\u3053\u308D\u304B\u898B\u3064\u3051\u3066\
    \u304F\u308C\u306A\u304F\u306A\u308B\u3053\u3068\u304C\u3042\u308B\u3063\u307D\
    \u3044\u306E\u3067\u3001\u3061\u3083\u3093\u30680\u304B\u3089\u9806\u306B\u8A66\
    \u3059 !!\r\n\t\t\r\n\t\t- reccurence relation \u304C\u898B\u3064\u304B\u3063\u305F\
    \u3089\r\n\t\t\tn\u9805\u76EE\u307E\u3067\u6C42\u3081\u305F\u3044\u306A\u3089\
    \ extended_terms(n,coefs,terms)\r\n\r\n\t\t- degree \u3082 order \u3082\u308F\u304B\
    \u3063\u3066\u308B\u5834\u5408\r\n\t\t\tcoeff\u57CB\u3081\u8FBC\u307F\u3068\u304B\
    \u304C\u3067\u304D\u306A\u304F\u3066\u3057\u304B\u3082\u9045\u3044\u5834\u5408\
    \r\n\t\t\tV<mint> get_extended_sequence(int n, const vector<mint>& terms, int\
    \ degree, int order) \u3067\u547C\u3079\u3070\u6700\u9069\r\n\r\n\t\r\n\tverified\
    \ at\r\n\t\tdwacon 2019 final E\r\n*/\r\n\r\n\r\nvector<mint> extended(int n,\
    \ const vector< vector<mint> >& coeffs, const vector<mint>& terms) {\r\n\r\n\t\
    vector<mint> ret(max<int>(n + 1, terms.size()));\r\n\tcopy(terms.begin(), terms.end(),\
    \ ret.begin());\r\n\tconst int order = coeffs.size() - 1;\r\n\tconst int deg =\
    \ coeffs[0].size() - 1;\r\n\tassert((int) terms.size() >= order);\r\n\tfor (int\
    \ m = terms.size(); m <= n; ++m) {\r\n\t\tmint s = 0;\r\n\t\tfor (int i = 1; i\
    \ <= order; ++i) {\r\n\t\t\tint k = m - i;\r\n\t\t\tmint t = ret[k];\r\n\t\t\t\
    for (int d = 0; d <= deg; ++d) {\r\n\t\t\t\ts += t * coeffs[i][d];\r\n\t\t\t\t\
    t *= k;\r\n\t\t\t}\r\n\t\t}\r\n\t\tmint denom = 0, mpow = 1;\r\n\t\tfor (int d\
    \ = 0; d <= deg; ++d) {\r\n\t\t\tdenom += mpow * coeffs[0][d];\r\n\t\t\tmpow *=\
    \ m;\r\n\t\t}\r\n\t\tret[m] = -s/denom;\r\n\t}\r\n\treturn ret;\r\n}\r\n\r\nvector<\
    \ vector<mint> > find_recurrence_relation(vector<mint> terms, int deg, int ord\
    \ = -1, bool verify=true) {\r\n\r\n\tif(ord != -1){\t\t//given order\r\n\t\tint\
    \ n = (deg+1)*(ord+1)+ord-1;\r\n\t\twhile((int)terms.size()>n) terms.pop_back();\r\
    \n\t}\r\n\r\n\tconst int n = terms.size();\r\n\tconst int B = (n + 2) / (deg +\
    \ 2); // number of blocks\r\n\tconst int C = B * (deg + 1); // number of columns\r\
    \n\tconst int R = n - (B - 1); // number of rows\r\n\tassert(B >= 2); assert(R\
    \ >= C - 1);\r\n\r\n\tauto error = [] (int order, int deg) {\r\n\t\tfprintf(stderr,\
    \ \r\n\t\t\t\"Error: Could not find a recurrence relation \"\r\n\t\t\t\"of order\
    \ <= %d and degree <= %d.\\n\\n\", \r\n\t\t\torder, deg);\r\n\t\tassert(0);\r\n\
    \t};\r\n\r\n\tvector< vector<mint> > mat(R, vector<mint>(C));\r\n\tfor (int y\
    \ = 0; y < R; ++y) {\r\n\t\tfor (int b = 0; b < B; ++b) {\r\n\t\t\tmint v = terms[y+b];\r\
    \n\t\t\tfor (int d = 0; d <= deg; ++d) {\r\n\t\t\t\tmat[y][b * (deg + 1) + d]\
    \ = v;\r\n\t\t\t\tv *= y+b;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tint rank = 0;\r\
    \n\tfor (int x = 0; x < C; ++x) {\r\n\t\tint pivot = -1;\r\n\t\tfor (int y = rank;\
    \ y < R; ++y) if (mat[y][x] != 0) {\r\n\t\t\tpivot = y; break;\r\n\t\t}\r\n\t\t\
    if (pivot < 0) break;\r\n\t\tif (pivot != rank) swap(mat[rank], mat[pivot]);\r\
    \n\t\tmint inv = mat[rank][x].inv();\r\n\t\tfor (int x2 = x; x2 < C; ++x2) mat[rank][x2]\
    \ *= inv;\r\n\t\tfor (int y = rank + 1; y < R; ++y) if (mat[y][x]) {\r\n\t\t\t\
    mint c = -mat[y][x];\r\n\t\t\tfor (int x2 = x; x2 < C; ++x2) {\r\n\t\t\t\tmat[y][x2]\
    \ += c * mat[rank][x2];\r\n\t\t\t}\r\n\t\t}\r\n\t\t++rank;\r\n\t}\r\n\r\n\tif\
    \ (rank == C) error(B - 1, deg);\r\n\r\n\tfor (int y = rank - 1; y >= 0; --y)\
    \ if (mat[y][rank]) {\r\n\t\tassert(mat[y][y] == 1);\r\n\t\tmint c = -mat[y][rank];\r\
    \n\t\tfor (int y2 = 0; y2 < y; ++y2) {\r\n\t\t\tmat[y2][rank] += c * mat[y2][y];\r\
    \n\t\t}\r\n\t}\r\n\r\n\tint order = rank / (deg + 1);\r\n\r\n\tvector< vector<mint>\
    \ > ret(order + 1, vector<mint>(deg + 1));\r\n\tret[0][rank % (deg + 1)] = 1;\r\
    \n\tfor (int y = rank - 1; y >= 0; --y) {\r\n\t\tint k = order - y / (deg + 1),\
    \ d = y % (deg + 1);\r\n\t\tret[k][d] = -mat[y][rank];\r\n\t}\r\n\r\n\tif (verify)\
    \ {\r\n\t\tauto extended_terms = extended(n - 1, ret, \r\n\t\t\t\tvector<mint>(terms.begin(),\
    \ terms.begin() + order));\r\n\t\tfor (int i = 0; i < (int) terms.size(); ++i)\
    \ {\r\n\t\t\tif (terms[i] != extended_terms[i]) error(B - 1, deg);\r\n\t\t}\r\n\
    \t}\r\n\r\n\tauto verbose = [&] {\r\n\t\tint last = verify ? n - 1 : order + R\
    \ - 1;\r\n\t\tfprintf(stderr, \r\n\t\t\t\"[ Found a recurrence relation ]\\n\"\
    \r\n\t\t\t\"- order %d\\n\"\r\n\t\t\t\"- degree %d\\n\"\r\n\t\t\t\"- verified\
    \ up to a(%d) (number of non-trivial terms: %d)\\n\",\r\n\t\t\torder, deg, last,\
    \ (last + 1) - ((deg + 2) * (order + 1) - 2)\r\n\t\t);\r\n\t\tfprintf(stderr,\
    \ \"{\\n\");\r\n\t\tfor (int k = 0; k <= order; ++k) {\r\n\t\t\tfprintf(stderr,\
    \ \"  {\");\r\n\t\t\tfor (int d = 0; d <= deg; ++d) {\r\n\t\t\t\tif (d) fprintf(stderr,\
    \ \", \");\r\n\t\t\t\tfprintf(stderr, \"%d\", ret[k][d].v);\r\n\t\t\t}\r\n\t\t\
    \tfprintf(stderr, \"}%s\\n\", k == order ? \"\" : \",\");\r\n\t\t}\r\n\t\tfprintf(stderr,\
    \ \"}\\n\\n\");\r\n\t};\r\n\tverbose();\r\n\r\n\treturn ret;\r\n}\r\n\r\nvoid\
    \ show_extended_sequence(int n, const vector<mint>& terms, int degree, int order\
    \ = -1) {\r\n\tauto coeffs = find_recurrence_relation(terms, degree, order);\r\
    \n\tauto extended_terms = extended(n, coeffs, terms);\r\n\tfor (int i = 0; i <\
    \ (int) extended_terms.size(); ++i) {\r\n\t\tprintf(\"%d %d\\n\", i, extended_terms[i].v);\r\
    \n\t}\r\n\tputs(\"\");\r\n}\r\nV<mint> get_extended_sequence(int n, const vector<mint>&\
    \ terms, int degree, int order = -1) {\r\n\tauto coeffs = find_recurrence_relation(terms,\
    \ degree, order);\r\n\treturn extended(n, coeffs, terms);\r\n}\r\n\r\n\r\nint\
    \ main() {\r\n\twhile(false){\r\n\t\tint N,deg;\r\n\t\tcin>>N>>deg;\r\n\t\tV<mint>\
    \ a(N);\r\n\t\trep(i,N) cin>>a[i];\r\n\t\tshow_extended_sequence(20,a,deg);\r\n\
    \t}\r\n\t// dwacon 19 final D\r\n\tshow_extended_sequence(200, {995554369,437065882,760163028,604374775,563201461,722533179,891029331,243207660,517900337,579351792,820966411,119983157,717013427,453585633,642921619,803562198,779547643,549466610,225987801,511146434,513208445,937519099,288901505,88889178,788877404,953101410,995286120,988949539,550614281,869514524,29874402,86888538,619021685,846782616,869986923,16005998,183318597,739787663,83435752,852566188,271885639,81969631,757364796,31757138,531970110,572889410,964895603,897876970,470735163,782448002,635946194,801119695,654617887,966330726,539188919,472170286,864176479,905095779,405308744,679701093,355096251,165180243,584499701,353630130,697278226,253747285,421059884,567078966,590283273,818044204,350177344,407191480,567551365,886451608,448116350,441779769,483964479,648188485,348176704,148164377,499546790,923857444,925919455,211078081,887599279,657518246,633503691,794144270,983480256,720052462,317082725,616099478,857714097,919165552,193858222,546036558,714532710,873864428,832691114,676902861},\r\
    \n\t2);\r\n\r\n\t// Ones\r\n\tshow_extended_sequence(10, {1, 1, 1, 1, 1}, 0);\r\
    \n\r\n\t// Factorials\r\n\tshow_extended_sequence(10, {1, 1, 2, 6, 24, 120}, 1);\r\
    \n\r\n\t// Catalan numbers\r\n\tshow_extended_sequence(10, {1, 1, 2, 5, 14, 42},\
    \ 1);\r\n\r\n\t// Subfactorials\r\n\tshow_extended_sequence(10, {1, 0, 1, 2, 9,\
    \ 44, 265}, 1);\r\n\r\n\t// Motzkin numbers\r\n\tshow_extended_sequence(10, {1,\
    \ 1, 2, 4, 9, 21, 51}, 1);\r\n\r\n\t// Large Schr\xF6der numbers\r\n\tshow_extended_sequence(10,\
    \ {1, 2, 6, 22, 90, 394, 1806}, 1);\r\n\r\n\t// Error: (n + 1) a_n \\equiv 0 (mod\
    \ 2)\r\n\tshow_extended_sequence(10, {0, 1, 0, 1, 0, 1, 0, 1, 0, 1}, 1);\r\n\r\
    \n\t// Hertzsprung's problem: order 4, degree 1\r\n\tshow_extended_sequence(20,\
    \ {\r\n\t\t1, 1, 0, 0, 2, \r\n\t\t14, 90, 646, 5242, 47622, \r\n\t\t479306, 5296790,\
    \ 63779034, 831283558, 661506141\r\n\t}, 1);\r\n\r\n\t// yukicoder No.93: order\
    \ 13, degree 2\r\n\tshow_extended_sequence(100, {\r\n\t\t1, 1, 2, 2, 8, \r\n\t\
    \t28, 152, 952, 7208, 62296, \r\n\t\t605864, 6522952, 76951496, 986411272, 647501133,\
    \ \r\n\t\t653303042, 170637030, 248109503, 700583494, 619914523, \r\n\t\t682935856,\
    \ 443753916, 423068688, 507501942, 315541972, \r\n\t\t110825117, 848156395, 798418282,\
    \ 920964362, 23823302, \r\n\t\t114894774, 279365223, 992413784, 833179437, 785518302,\
    \ \r\n\t\t524368220, 42214454, 140345871, 188150268, 808714798, \r\n\t\t718376249,\
    \ 732000901, 955005007, 139255097, 484615744, \r\n\t\t615066955, 726914809, 856989248,\
    \ 460819998, 321277105, \r\n\t\t536397091, 555447300, 597473569, 217709372, 24981477,\
    \ \r\n\t\t143561526, 171000806, 137649694, 749333590, 700935246, \r\n\t\t916763337,\
    \ 762367836, 296796066, 236278263, 398507715, \r\n\t}, 2,14);\r\n\r\n\t// binom(3\
    \ * i, i) ** 2 + binom(2 * i, i + 1): order 8, degree 5\r\n\tshow_extended_sequence(128,\
    \ {\r\n\t\t1, 10, 229, 7071, 245081, \r\n\t\t9018219, 344622888, 521041312, 917599501,\
    \ 328470621, \r\n\t\t920199271, 726809819, 712906773, 531692419, 688496750, \r\
    \n\t\t140388924, 514070772, 712606107, 333670208, 549905369, \r\n\t\t504023887,\
    \ 34217948, 890190161, 703909490, 6403597, \r\n\t\t623962638, 685637246, 126160387,\
    \ 956873888, 9766247, \r\n\t\t864866393, 563563889, 613532405, 710746029, 182520210,\
    \ \r\n\t\t914377932, 648461424, 715143730, 918800735, 503145605, \r\n\t\t27402642,\
    \ 282029583, 635728688, 91880493, 896737996, \r\n\t\t773282006, 625726102, 992524580,\
    \ 494071629, 82874383, \r\n\t\t536460288, 218839718, 406647024, 248185000, 360613817,\r\
    \n\t\t546217158, 925224608, 482921337, 928327434, 372559325, \r\n\t\t614987117,\
    \ 601351833, 765504201, 230666863, 98348380, \r\n\t}, 5);\r\n\treturn 0;\r\n}\n"
  code: "/*\r\n\tP-recursive (holonomic) sequence \u306E\u6F38\u5316\u5F0F\u3092\u6C42\
    \u3081\u308B\r\n\tn\u9805\u76EE\u3092\u6C42\u3081\u308B\u306E\u306F\u611A\u76F4\
    \u306B\u3084\u3063\u3066\u3044\u308B\u306E\u3067\u3053\u308C\u306F\u8ABF\u3079\
    \u308B\u5FC5\u8981\u3042\u308B\u304B\u3082? ( \u305F\u3060\u3001\u305D\u3053\u307E\
    \u3067\u9045\u304F\u306F\u306A\u3044 O(N * order * degree) )\r\n\r\n\tP-recursive:\r\
    \n\t\tBerlekamp-Massey \u3068\u304B\u3067\u6271\u3046\u6F38\u5316\u5F0F\u306F\
    \ a_n = 3a_{n-1} - 10a_{n-2} \u3068\u304B\u3060\u3063\u305F\u3051\u3069\u3001\
    P-recursive \u3067\u306F\u3001\r\n\t\t(5n-3)a_n = (3n+4)a_{n-1} + (n^5)a_{n-2}\
    \ \u307F\u305F\u3044\u306A\u306E\u304C\u6271\u3048\u308B\r\n\r\n\t\t\u3064\u307E\
    \u308A\u4FC2\u6570\u306Bn\u306E\u591A\u9805\u5F0F\u3092\u5165\u308C\u3089\u308C\
    \u308B\r\n\r\n\t\t\u3053\u3053\u3067\u3001\r\n\t\td := degree \u3068\u306F \u3053\
    \u306E\u591A\u9805\u5F0F\u306E\u6B21\u6570\u306Emax\u306E\u3053\u3068\u3067\u3001\
    \ \r\n\t\tk := order  \u3068\u306F (\u4F55\u9805\u9593\u6F38\u5316\u5F0F\u304B\
    )-1 \u3092\u8868\u3059\r\n\r\n\t\tn\u3092\u56FA\u5B9A\u3057\u305F\u4E00\u3064\u306E\
    \u5F0F\u306B\u73FE\u308C\u308B\u5909\u6570\u306E\u500B\u6570\u306F (d+1)(k+1)\
    \ \u306A\u306E\u3067\u3001\u5F0F\u3092\u3053\u308C\u3060\u3051\u7528\u610F\u3059\
    \u308C\u3070\u4E00\u610F\u306B\u5B9A\u307E\u308B\r\n\t\t\u305D\u306E\u305F\u3081\
    \u306B\u306F \u306F\u3058\u3081\u306E (d+1)(k+1) + k \u9805 \u304C\u5FC5\u8981\
    \ \u306A\u6C17\u304C\u3059\u308B\u3051\u3069\u5F0F\u5168\u4F53\u306Bx\u500D\u307F\
    \u305F\u3044\u306A\u306E\u306E\u81EA\u7531\u5EA6\u304C\u3042\u308B\u304B\u3089\
    \r\n\t\t\u7D50\u5C40 (d+1)(k+1) + k - 1 \u9805\u3042\u308C\u3070\u5341\u5206\r\
    \n\r\n\t\u4F7F\u3044\u65B9:\r\n\t\t- \u3068\u308A\u3042\u3048\u305A\u6570\u5217\
    \u306E deg \u3068 ord \u3092\u77E5\u308A\u305F\u3044\u5834\u5408:\r\n\t\t\t\u3053\
    \u306E\u5B9F\u88C5\u3060\u3068deg\u306F\u56FA\u5B9A\u306A\u306E\u3067\u3001\r\n\
    \t\t\tfind_recurrence_relation(vector<mint> terms, int deg) \u3092 deg = 0~ \u8A66\
    \u3057\u3066\u3044\u304F\r\n\t\t\t\u8A08\u7B97\u91CF O(n^2 * deg * ord)\r\n\t\t\
    \t\u898B\u3064\u3051\u3089\u308C\u306A\u304B\u3063\u305F\u3089assert(0),\r\n\t\
    \t\t\u898B\u3064\u304B\u3063\u305F\u3089\u30B3\u30E1\u30F3\u30C8\u4ED8\u304D\u3067\
    \u3044\u308D\u3044\u308D\u6559\u3048\u3066\u304F\u308C\u308B\r\n\r\n\t\t\t!! \u306A\
    \u3093\u304Bdeg\u304C\u7121\u99C4\u306B\u3067\u304B\u3044\u3068\u5909\u306A\u89E3\
    \u3069\u3053\u308D\u304B\u898B\u3064\u3051\u3066\u304F\u308C\u306A\u304F\u306A\
    \u308B\u3053\u3068\u304C\u3042\u308B\u3063\u307D\u3044\u306E\u3067\u3001\u3061\
    \u3083\u3093\u30680\u304B\u3089\u9806\u306B\u8A66\u3059 !!\r\n\t\t\r\n\t\t- reccurence\
    \ relation \u304C\u898B\u3064\u304B\u3063\u305F\u3089\r\n\t\t\tn\u9805\u76EE\u307E\
    \u3067\u6C42\u3081\u305F\u3044\u306A\u3089 extended_terms(n,coefs,terms)\r\n\r\
    \n\t\t- degree \u3082 order \u3082\u308F\u304B\u3063\u3066\u308B\u5834\u5408\r\
    \n\t\t\tcoeff\u57CB\u3081\u8FBC\u307F\u3068\u304B\u304C\u3067\u304D\u306A\u304F\
    \u3066\u3057\u304B\u3082\u9045\u3044\u5834\u5408\r\n\t\t\tV<mint> get_extended_sequence(int\
    \ n, const vector<mint>& terms, int degree, int order) \u3067\u547C\u3079\u3070\
    \u6700\u9069\r\n\r\n\t\r\n\tverified at\r\n\t\tdwacon 2019 final E\r\n*/\r\n\r\
    \n\r\nvector<mint> extended(int n, const vector< vector<mint> >& coeffs, const\
    \ vector<mint>& terms) {\r\n\r\n\tvector<mint> ret(max<int>(n + 1, terms.size()));\r\
    \n\tcopy(terms.begin(), terms.end(), ret.begin());\r\n\tconst int order = coeffs.size()\
    \ - 1;\r\n\tconst int deg = coeffs[0].size() - 1;\r\n\tassert((int) terms.size()\
    \ >= order);\r\n\tfor (int m = terms.size(); m <= n; ++m) {\r\n\t\tmint s = 0;\r\
    \n\t\tfor (int i = 1; i <= order; ++i) {\r\n\t\t\tint k = m - i;\r\n\t\t\tmint\
    \ t = ret[k];\r\n\t\t\tfor (int d = 0; d <= deg; ++d) {\r\n\t\t\t\ts += t * coeffs[i][d];\r\
    \n\t\t\t\tt *= k;\r\n\t\t\t}\r\n\t\t}\r\n\t\tmint denom = 0, mpow = 1;\r\n\t\t\
    for (int d = 0; d <= deg; ++d) {\r\n\t\t\tdenom += mpow * coeffs[0][d];\r\n\t\t\
    \tmpow *= m;\r\n\t\t}\r\n\t\tret[m] = -s/denom;\r\n\t}\r\n\treturn ret;\r\n}\r\
    \n\r\nvector< vector<mint> > find_recurrence_relation(vector<mint> terms, int\
    \ deg, int ord = -1, bool verify=true) {\r\n\r\n\tif(ord != -1){\t\t//given order\r\
    \n\t\tint n = (deg+1)*(ord+1)+ord-1;\r\n\t\twhile((int)terms.size()>n) terms.pop_back();\r\
    \n\t}\r\n\r\n\tconst int n = terms.size();\r\n\tconst int B = (n + 2) / (deg +\
    \ 2); // number of blocks\r\n\tconst int C = B * (deg + 1); // number of columns\r\
    \n\tconst int R = n - (B - 1); // number of rows\r\n\tassert(B >= 2); assert(R\
    \ >= C - 1);\r\n\r\n\tauto error = [] (int order, int deg) {\r\n\t\tfprintf(stderr,\
    \ \r\n\t\t\t\"Error: Could not find a recurrence relation \"\r\n\t\t\t\"of order\
    \ <= %d and degree <= %d.\\n\\n\", \r\n\t\t\torder, deg);\r\n\t\tassert(0);\r\n\
    \t};\r\n\r\n\tvector< vector<mint> > mat(R, vector<mint>(C));\r\n\tfor (int y\
    \ = 0; y < R; ++y) {\r\n\t\tfor (int b = 0; b < B; ++b) {\r\n\t\t\tmint v = terms[y+b];\r\
    \n\t\t\tfor (int d = 0; d <= deg; ++d) {\r\n\t\t\t\tmat[y][b * (deg + 1) + d]\
    \ = v;\r\n\t\t\t\tv *= y+b;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tint rank = 0;\r\
    \n\tfor (int x = 0; x < C; ++x) {\r\n\t\tint pivot = -1;\r\n\t\tfor (int y = rank;\
    \ y < R; ++y) if (mat[y][x] != 0) {\r\n\t\t\tpivot = y; break;\r\n\t\t}\r\n\t\t\
    if (pivot < 0) break;\r\n\t\tif (pivot != rank) swap(mat[rank], mat[pivot]);\r\
    \n\t\tmint inv = mat[rank][x].inv();\r\n\t\tfor (int x2 = x; x2 < C; ++x2) mat[rank][x2]\
    \ *= inv;\r\n\t\tfor (int y = rank + 1; y < R; ++y) if (mat[y][x]) {\r\n\t\t\t\
    mint c = -mat[y][x];\r\n\t\t\tfor (int x2 = x; x2 < C; ++x2) {\r\n\t\t\t\tmat[y][x2]\
    \ += c * mat[rank][x2];\r\n\t\t\t}\r\n\t\t}\r\n\t\t++rank;\r\n\t}\r\n\r\n\tif\
    \ (rank == C) error(B - 1, deg);\r\n\r\n\tfor (int y = rank - 1; y >= 0; --y)\
    \ if (mat[y][rank]) {\r\n\t\tassert(mat[y][y] == 1);\r\n\t\tmint c = -mat[y][rank];\r\
    \n\t\tfor (int y2 = 0; y2 < y; ++y2) {\r\n\t\t\tmat[y2][rank] += c * mat[y2][y];\r\
    \n\t\t}\r\n\t}\r\n\r\n\tint order = rank / (deg + 1);\r\n\r\n\tvector< vector<mint>\
    \ > ret(order + 1, vector<mint>(deg + 1));\r\n\tret[0][rank % (deg + 1)] = 1;\r\
    \n\tfor (int y = rank - 1; y >= 0; --y) {\r\n\t\tint k = order - y / (deg + 1),\
    \ d = y % (deg + 1);\r\n\t\tret[k][d] = -mat[y][rank];\r\n\t}\r\n\r\n\tif (verify)\
    \ {\r\n\t\tauto extended_terms = extended(n - 1, ret, \r\n\t\t\t\tvector<mint>(terms.begin(),\
    \ terms.begin() + order));\r\n\t\tfor (int i = 0; i < (int) terms.size(); ++i)\
    \ {\r\n\t\t\tif (terms[i] != extended_terms[i]) error(B - 1, deg);\r\n\t\t}\r\n\
    \t}\r\n\r\n\tauto verbose = [&] {\r\n\t\tint last = verify ? n - 1 : order + R\
    \ - 1;\r\n\t\tfprintf(stderr, \r\n\t\t\t\"[ Found a recurrence relation ]\\n\"\
    \r\n\t\t\t\"- order %d\\n\"\r\n\t\t\t\"- degree %d\\n\"\r\n\t\t\t\"- verified\
    \ up to a(%d) (number of non-trivial terms: %d)\\n\",\r\n\t\t\torder, deg, last,\
    \ (last + 1) - ((deg + 2) * (order + 1) - 2)\r\n\t\t);\r\n\t\tfprintf(stderr,\
    \ \"{\\n\");\r\n\t\tfor (int k = 0; k <= order; ++k) {\r\n\t\t\tfprintf(stderr,\
    \ \"  {\");\r\n\t\t\tfor (int d = 0; d <= deg; ++d) {\r\n\t\t\t\tif (d) fprintf(stderr,\
    \ \", \");\r\n\t\t\t\tfprintf(stderr, \"%d\", ret[k][d].v);\r\n\t\t\t}\r\n\t\t\
    \tfprintf(stderr, \"}%s\\n\", k == order ? \"\" : \",\");\r\n\t\t}\r\n\t\tfprintf(stderr,\
    \ \"}\\n\\n\");\r\n\t};\r\n\tverbose();\r\n\r\n\treturn ret;\r\n}\r\n\r\nvoid\
    \ show_extended_sequence(int n, const vector<mint>& terms, int degree, int order\
    \ = -1) {\r\n\tauto coeffs = find_recurrence_relation(terms, degree, order);\r\
    \n\tauto extended_terms = extended(n, coeffs, terms);\r\n\tfor (int i = 0; i <\
    \ (int) extended_terms.size(); ++i) {\r\n\t\tprintf(\"%d %d\\n\", i, extended_terms[i].v);\r\
    \n\t}\r\n\tputs(\"\");\r\n}\r\nV<mint> get_extended_sequence(int n, const vector<mint>&\
    \ terms, int degree, int order = -1) {\r\n\tauto coeffs = find_recurrence_relation(terms,\
    \ degree, order);\r\n\treturn extended(n, coeffs, terms);\r\n}\r\n\r\n\r\nint\
    \ main() {\r\n\twhile(false){\r\n\t\tint N,deg;\r\n\t\tcin>>N>>deg;\r\n\t\tV<mint>\
    \ a(N);\r\n\t\trep(i,N) cin>>a[i];\r\n\t\tshow_extended_sequence(20,a,deg);\r\n\
    \t}\r\n\t// dwacon 19 final D\r\n\tshow_extended_sequence(200, {995554369,437065882,760163028,604374775,563201461,722533179,891029331,243207660,517900337,579351792,820966411,119983157,717013427,453585633,642921619,803562198,779547643,549466610,225987801,511146434,513208445,937519099,288901505,88889178,788877404,953101410,995286120,988949539,550614281,869514524,29874402,86888538,619021685,846782616,869986923,16005998,183318597,739787663,83435752,852566188,271885639,81969631,757364796,31757138,531970110,572889410,964895603,897876970,470735163,782448002,635946194,801119695,654617887,966330726,539188919,472170286,864176479,905095779,405308744,679701093,355096251,165180243,584499701,353630130,697278226,253747285,421059884,567078966,590283273,818044204,350177344,407191480,567551365,886451608,448116350,441779769,483964479,648188485,348176704,148164377,499546790,923857444,925919455,211078081,887599279,657518246,633503691,794144270,983480256,720052462,317082725,616099478,857714097,919165552,193858222,546036558,714532710,873864428,832691114,676902861},\r\
    \n\t2);\r\n\r\n\t// Ones\r\n\tshow_extended_sequence(10, {1, 1, 1, 1, 1}, 0);\r\
    \n\r\n\t// Factorials\r\n\tshow_extended_sequence(10, {1, 1, 2, 6, 24, 120}, 1);\r\
    \n\r\n\t// Catalan numbers\r\n\tshow_extended_sequence(10, {1, 1, 2, 5, 14, 42},\
    \ 1);\r\n\r\n\t// Subfactorials\r\n\tshow_extended_sequence(10, {1, 0, 1, 2, 9,\
    \ 44, 265}, 1);\r\n\r\n\t// Motzkin numbers\r\n\tshow_extended_sequence(10, {1,\
    \ 1, 2, 4, 9, 21, 51}, 1);\r\n\r\n\t// Large Schr\xF6der numbers\r\n\tshow_extended_sequence(10,\
    \ {1, 2, 6, 22, 90, 394, 1806}, 1);\r\n\r\n\t// Error: (n + 1) a_n \\equiv 0 (mod\
    \ 2)\r\n\tshow_extended_sequence(10, {0, 1, 0, 1, 0, 1, 0, 1, 0, 1}, 1);\r\n\r\
    \n\t// Hertzsprung's problem: order 4, degree 1\r\n\tshow_extended_sequence(20,\
    \ {\r\n\t\t1, 1, 0, 0, 2, \r\n\t\t14, 90, 646, 5242, 47622, \r\n\t\t479306, 5296790,\
    \ 63779034, 831283558, 661506141\r\n\t}, 1);\r\n\r\n\t// yukicoder No.93: order\
    \ 13, degree 2\r\n\tshow_extended_sequence(100, {\r\n\t\t1, 1, 2, 2, 8, \r\n\t\
    \t28, 152, 952, 7208, 62296, \r\n\t\t605864, 6522952, 76951496, 986411272, 647501133,\
    \ \r\n\t\t653303042, 170637030, 248109503, 700583494, 619914523, \r\n\t\t682935856,\
    \ 443753916, 423068688, 507501942, 315541972, \r\n\t\t110825117, 848156395, 798418282,\
    \ 920964362, 23823302, \r\n\t\t114894774, 279365223, 992413784, 833179437, 785518302,\
    \ \r\n\t\t524368220, 42214454, 140345871, 188150268, 808714798, \r\n\t\t718376249,\
    \ 732000901, 955005007, 139255097, 484615744, \r\n\t\t615066955, 726914809, 856989248,\
    \ 460819998, 321277105, \r\n\t\t536397091, 555447300, 597473569, 217709372, 24981477,\
    \ \r\n\t\t143561526, 171000806, 137649694, 749333590, 700935246, \r\n\t\t916763337,\
    \ 762367836, 296796066, 236278263, 398507715, \r\n\t}, 2,14);\r\n\r\n\t// binom(3\
    \ * i, i) ** 2 + binom(2 * i, i + 1): order 8, degree 5\r\n\tshow_extended_sequence(128,\
    \ {\r\n\t\t1, 10, 229, 7071, 245081, \r\n\t\t9018219, 344622888, 521041312, 917599501,\
    \ 328470621, \r\n\t\t920199271, 726809819, 712906773, 531692419, 688496750, \r\
    \n\t\t140388924, 514070772, 712606107, 333670208, 549905369, \r\n\t\t504023887,\
    \ 34217948, 890190161, 703909490, 6403597, \r\n\t\t623962638, 685637246, 126160387,\
    \ 956873888, 9766247, \r\n\t\t864866393, 563563889, 613532405, 710746029, 182520210,\
    \ \r\n\t\t914377932, 648461424, 715143730, 918800735, 503145605, \r\n\t\t27402642,\
    \ 282029583, 635728688, 91880493, 896737996, \r\n\t\t773282006, 625726102, 992524580,\
    \ 494071629, 82874383, \r\n\t\t536460288, 218839718, 406647024, 248185000, 360613817,\r\
    \n\t\t546217158, 925224608, 482921337, 928327434, 372559325, \r\n\t\t614987117,\
    \ 601351833, 765504201, 230666863, 98348380, \r\n\t}, 5);\r\n\treturn 0;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/Precursive.cpp
  requiredBy: []
  timestamp: '2020-12-16 01:41:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Precursive.cpp
layout: document
redirect_from:
- /library/math/Precursive.cpp
- /library/math/Precursive.cpp.html
title: math/Precursive.cpp
---
