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
  bundledCode: "#line 1 \"math/unrooted_tree.cpp\"\n/*\n\t\u30E9\u30D9\u30EB\u306A\
    \u3057\u6839\u306A\u3057\u306E\u6728\u306E\u6570\u3048\u4E0A\u3052\n\tO(N^2logN)\n\
    \tR + H(R,2) = U + R^2\n\tverify: OEIS\n*/\nint main(){\n\tint N; cin >> N;\n\t\
    V<mint> dp(N+1),ndp(N+1);\n\tdp[1] = 1;\n\n\t// O(N^2 log N)\n\trep1(d,N){\t\t\
    \t// use subtree size\n\t\t// now, dp[d] equals to the number of rooted tree with\
    \ size d\n\t\t// use subtree with size d\n\t\trep(s,N+1){\t\t// now size\n\t\t\
    \tmint h = 1;\n\t\t\tmint num = dp[d];\n\t\t\trep(i,N+1){\t// use i subtrees (with\
    \ size d)\n\t\t\t\tint ns = s + d * i;\n\t\t\t\tif(ns > N) break;\n//\t\t\t\t\
    ndp[ns] += dp[s] * H(dp[d],i);\n\t\t\t\tndp[ns] += dp[s] * h;\n\t\t\t\th *= num+i;\n\
    \t\t\t\th /= i+1;\n\t\t\t}\n\t\t}\n\t\trep(s,N+1){\n\t\t\tdp[s] = ndp[s];\n\t\t\
    \tndp[s] = 0;\n\t\t}\n\t}\n\tshows(\"rooted:\",dp);\n\n\t// R + H(R,2) = U + R^2\n\
    \n\tV<mint> R = dp;\n\tV<mint> U(N+1);\n\trep1(n,N){\n\t\tU[n] = R[n];\t//R\n\t\
    \trep1(x,n/2){\t//H(R,2)\n\t\t\tif(x+x == n){\n\t\t\t\tU[n] += (R[x]+1)*R[x] /\
    \ 2;\n\t\t\t}else{\n\t\t\t\tU[n] += R[x] * R[n-x];\n\t\t\t}\n\t\t}\n\t\trep1(x,n-1){\t\
    // - R^2\n\t\t\tU[n] -= R[x] * R[n-x];\n\t\t}\n\t}\n\tshows(\"unrooted:\",U);\n\
    }\n"
  code: "/*\n\t\u30E9\u30D9\u30EB\u306A\u3057\u6839\u306A\u3057\u306E\u6728\u306E\u6570\
    \u3048\u4E0A\u3052\n\tO(N^2logN)\n\tR + H(R,2) = U + R^2\n\tverify: OEIS\n*/\n\
    int main(){\n\tint N; cin >> N;\n\tV<mint> dp(N+1),ndp(N+1);\n\tdp[1] = 1;\n\n\
    \t// O(N^2 log N)\n\trep1(d,N){\t\t\t// use subtree size\n\t\t// now, dp[d] equals\
    \ to the number of rooted tree with size d\n\t\t// use subtree with size d\n\t\
    \trep(s,N+1){\t\t// now size\n\t\t\tmint h = 1;\n\t\t\tmint num = dp[d];\n\t\t\
    \trep(i,N+1){\t// use i subtrees (with size d)\n\t\t\t\tint ns = s + d * i;\n\t\
    \t\t\tif(ns > N) break;\n//\t\t\t\tndp[ns] += dp[s] * H(dp[d],i);\n\t\t\t\tndp[ns]\
    \ += dp[s] * h;\n\t\t\t\th *= num+i;\n\t\t\t\th /= i+1;\n\t\t\t}\n\t\t}\n\t\t\
    rep(s,N+1){\n\t\t\tdp[s] = ndp[s];\n\t\t\tndp[s] = 0;\n\t\t}\n\t}\n\tshows(\"\
    rooted:\",dp);\n\n\t// R + H(R,2) = U + R^2\n\n\tV<mint> R = dp;\n\tV<mint> U(N+1);\n\
    \trep1(n,N){\n\t\tU[n] = R[n];\t//R\n\t\trep1(x,n/2){\t//H(R,2)\n\t\t\tif(x+x\
    \ == n){\n\t\t\t\tU[n] += (R[x]+1)*R[x] / 2;\n\t\t\t}else{\n\t\t\t\tU[n] += R[x]\
    \ * R[n-x];\n\t\t\t}\n\t\t}\n\t\trep1(x,n-1){\t// - R^2\n\t\t\tU[n] -= R[x] *\
    \ R[n-x];\n\t\t}\n\t}\n\tshows(\"unrooted:\",U);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/unrooted_tree.cpp
  requiredBy: []
  timestamp: '2020-02-29 03:37:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/unrooted_tree.cpp
layout: document
redirect_from:
- /library/math/unrooted_tree.cpp
- /library/math/unrooted_tree.cpp.html
title: math/unrooted_tree.cpp
---
